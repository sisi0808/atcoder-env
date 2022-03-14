from email.policy import default
from gc import DEBUG_SAVEALL
import re
import sys
import filecmp
import subprocess
from collections import defaultdict

# Automate the following comand.
# [git add -A, git commit -m "xxx-a-c and yyy-b", git push origin master]
class MangeCommitMessage():

    dif_stat_message = ""
    updated_dic = {}
    commit_message = ""

    def __init__(self):
        self.execute_git_status()

    # Get output of 'git status -s'.
    def execute_git_status(self):
        cmd = 'git status -s'
        self.dif_stat_message = (subprocess.Popen(cmd, stdout=subprocess.PIPE,
                                shell=True).communicate()[0]).decode('utf-8')

    # Make new_created files dic.
    def make_created_files_dic(self):

        regex = r'\?\?\s(.*)'
        created_dic = defaultdict(list)

        for m in re.finditer(regex,  self.dif_stat_message, re.MULTILINE):
            s = m.groups()[0].split('/')
            if len(s) >= 2:
                for rank in  "abcde":
                    if not filecmp.cmp(f'{s[0]}/{s[1]}/{rank}.cpp',  './template.cpp'):
                        created_dic[s[-2]].append(rank)

        return created_dic

    # Make modified files dic.
    def make_modified_files_dic(self):

        regex = r'M\s(.*)$'
        modified_dic = defaultdict(list)

        for m in re.finditer(regex,  self.dif_stat_message, re.MULTILINE):
            s = m.groups()[0].split('/')
            if len(s) >= 2:
                modified_dic[s[-2]].append(s[-1][0])

        return modified_dic

    # Merge dict to self.updated_dic.
    def merge_dic(self, a):

        b = self.updated_dic
        c={}
        for key in list(set(list(a.keys())+list(b.keys()))):
            value_a = a[key] if key in a else []
            value_b = b[key] if key in b else []
            c[key] = sorted(list(set(value_a + value_b)))

        self.updated_dic = c

    # Make commit message.
    def make_commit_message(self):
        commit_message = ""

        for i, (dkey,dvalues) in enumerate(self.updated_dic.items()):

            if i != 0: commit_message += ' and '
            commit_message += f'{dkey}_{dvalues[0]}'

            # If modified multiple files in one directry
            # For example, '217_a-c,e and 218_a,c'
            is_serise = False
            for j in range(1, len(dvalues)):
                if ord(dvalues[j-1]) + 1 == ord(dvalues[j]):
                    is_serise = True
                    if j == len(dvalues) - 1:
                        commit_message +=  f'-{dvalues[j]}'
                else:
                    if is_serise:
                        commit_message +=  f'-{dvalues[j-1]}'
                    commit_message +=  f',{dvalues[j]}'
                    is_serise = False

        self.commit_message = commit_message

    # Make path list of the modified files.
    def make_modified_files_path_list(self):
        created_dic = self.make_created_files_dic()
        created_file_path_list = []
        for key, values in created_dic.items():
            created_file_path_list += [f'abc/{key}/{v}.cpp' for v in values]

        return created_file_path_list

    # Execute git command.
    def execute_command(self):

        # execute the command.
        add_file_list = ['git add '+ path for path in self.make_modified_files_path_list()]
        com_list =  add_file_list + [f'git commit -m "{self.commit_message}"', 'git push origin master']
        for com in com_list:
            subprocess.run(com, shell=True)
            # print(com)


if __name__ == '__main__':

    mcm = MangeCommitMessage()

    mcm.merge_dic(mcm.make_created_files_dic())
    mcm.merge_dic(mcm.make_modified_files_dic())

    mcm.make_commit_message()

    # If there are some updated codes.
    if mcm.commit_message != "":
        try:
            print(mcm.commit_message)
            mcm.execute_command()
        except Exception as e:
            print(e)
        else:
            print("Done")
    else:
        print('There are no contest codes with updated')
