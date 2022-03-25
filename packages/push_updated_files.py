import re
import filecmp
import subprocess
from collections import defaultdict


# Push updated files to Github
# The command to excecute are
# [git add -A, git commit -m "xxx-a-c and yyy-b", git push origin master]
class PushUpdatedFiles():

    git_stat_msg = ""
    updated_dict = {}
    commit_message = ""

    def __init__(self):
        self.execute_git_status()

    # Get output of 'git status -s'.
    def execute_git_status(self):
        cmd = 'git status -s'
        self.git_stat_msg = (subprocess.Popen(cmd, stdout=subprocess.PIPE,
                                              shell=True).communicate()[0]).decode('utf-8')

    # Make commit message.
    def make_commit_message(self, created=False, modified=False):

        if created:
            self.merge_dict(self.make_created_file_dict())
        if modified:
            self.merge_dict(self.make_modified_file_dict())

        updated_file_list = sorted(self.updated_dict.items())

        commit_message = ""

        for i, (dkey, dvalues) in enumerate(updated_file_list):

            if i != 0:
                commit_message += ' and '

            commit_message += f'{dkey}_{dvalues[0]}'

            # If updated multiple files in one directry
            # For example, '217_a-c,e and 218_a,c'
            is_serise = False
            for j in range(1, len(dvalues)):
                if ord(dvalues[j-1]) + 1 == ord(dvalues[j]):
                    is_serise = True
                    if j == len(dvalues) - 1:
                        commit_message += f'-{dvalues[j]}'
                else:
                    if is_serise:
                        commit_message += f'-{dvalues[j-1]}'
                    commit_message += f',{dvalues[j]}'
                    is_serise = False

        self.commit_message = commit_message

    # Make new_created file dict.
    def make_created_file_dict(self):

        regex = r'\?\?\s(.*)'
        created_dict = defaultdict(list)

        for m in re.finditer(regex,  self.git_stat_msg, re.MULTILINE):
            s = m.groups()[0].split('/')
            # If it's contest file
            if len(s) >= 2:
                for rank in "abcde":
                    if not filecmp.cmp(f'{s[0]}/{s[1]}/{rank}.cpp',  './template.cpp'):
                        created_dict[s[-2]].append(rank)

        return created_dict

    # Make modified file dict.
    def make_modified_file_dict(self):

        regex = r'M\s(.*)$'
        modified_dict = defaultdict(list)

        for m in re.finditer(regex,  self.git_stat_msg, re.MULTILINE):
            s = m.groups()[0].split('/')
            # If it's contest file
            if len(s) >= 2:
                modified_dict[s[-2]].append(s[-1][0])

        return modified_dict

    # Merge dict to self.updated_dict.
    def merge_dict(self, a):

        b = self.updated_dict
        c = {}
        for key in list(set(list(a.keys())+list(b.keys()))):
            value_a = a[key] if key in a else []
            value_b = b[key] if key in b else []
            c[key] = sorted(list(set(value_a + value_b)))

        self.updated_dict = c

    # Get path list of the updated files.
    def get_updated_file_path_list(self):

        updated_file_dict = self.updated_dict

        updated_file_path_list = []
        for key, values in updated_file_dict.items():
            updated_file_path_list += [f'abc/{key}/{v}.cpp' for v in values]

        return updated_file_path_list

    # Execute git command.
    def execute_command(self):

        # execute the command.
        add_file_list = ['git add ' + path for path in self.get_updated_file_path_list()]
        com_list = add_file_list + [f'git commit -m "{self.commit_message}"', 'git push origin master']
        for com in com_list:
            subprocess.run(com, shell=True)
            # print(com)
