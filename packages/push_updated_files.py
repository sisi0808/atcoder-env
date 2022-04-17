import filecmp
import os
import re
import subprocess
from collections import defaultdict


# Push updated files to Github
# The command to excecute are
# [git add -A, git commit -m "xxx-a-c and yyy-b", git push origin master]
class PushUpdatedFiles:

    git_stat_msg = ""
    updated_dict = {}
    commit_message = ""

    contest_name_dict = {"abc": 5, "typical90": 90, "dp": 26}

    def __init__(self):
        self.execute_git_status()

    # Get output of 'git status -s'.
    def execute_git_status(self):
        cmd = "git status -s"
        self.git_stat_msg = (subprocess.Popen(cmd, stdout=subprocess.PIPE, shell=True).communicate()[0]).decode(
            "utf-8"
        )

    # Make new_created file dict.
    def make_created_file_dict(self):

        regex = r"\?\?\s(.*)"
        created_dict = defaultdict(list)

        for m in re.finditer(regex, self.git_stat_msg, re.MULTILINE):

            s = m.groups()[0].split("/")
            # If it's contest file
            if s[0] in self.contest_name_dict:
                contest_folder_path = "/".join(s[:-1])
                contest_name = "".join(s[:-1])
                contest_file_path = [s[-1]] if s[-1] != "" else os.listdir(contest_folder_path)
                for rank in contest_file_path:
                    if not filecmp.cmp(f"{contest_folder_path}/{rank}", "./template.cpp"):
                        created_dict[contest_name].append(rank.split(".")[0])
                        # print(f"{contest_folder_path}/{rank}")

        return created_dict

    # Make modified file dict.
    def make_modified_file_dict(self):

        regex = r"M\s(.*)$"
        modified_dict = defaultdict(list)

        for m in re.finditer(regex, self.git_stat_msg, re.MULTILINE):
            s = m.groups()[0].split("/")
            # If it's contest file
            if s[0] in self.contest_name_dict:
                contest_name = "".join(s[0:-1])
                modified_dict[contest_name].append(s[-1][0])

        return modified_dict

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
                commit_message += " and "

            commit_message += f"{dkey}_{dvalues[0]}"

            # If updated multiple files in one directry
            # For example, '217_a-c,e and 218_a,c'
            is_serise = False
            for j in range(1, len(dvalues)):
                if ord(dvalues[j - 1]) + 1 == ord(dvalues[j]):
                    is_serise = True
                    if j == len(dvalues) - 1:
                        commit_message += f"-{dvalues[j]}"
                else:
                    if is_serise:
                        commit_message += f"-{dvalues[j-1]}"
                    commit_message += f",{dvalues[j]}"
                    is_serise = False

        self.commit_message = commit_message

    # Merge dict to self.updated_dict.
    def merge_dict(self, a):

        b = self.updated_dict
        c = {}
        for key in list(set(list(a.keys()) + list(b.keys()))):
            value_a = a[key] if key in a else []
            value_b = b[key] if key in b else []
            c[key] = sorted(list(set(value_a + value_b)))

        self.updated_dict = c

    # Get problem_name_list
    # Like ['a', 'b', 'c', 'd', 'e']
    def get_problem_name_list(self, contest_name):

        problem_name_list = []
        for i in range(self.contest_name_dict[contest_name]):
            problem_name = chr(ord("a") + i % 26)
            if i >= 26:
                problem_name = chr(ord("a") + int(i // 26) - 1) + problem_name
            problem_name_list.append(problem_name)

        return problem_name_list

    # Get path list of the updated files.
    def get_updated_file_path_list(self):

        updated_file_dict = self.updated_dict

        updated_file_path_list = []
        # key = ['abc210', 'dp']
        for key, values in updated_file_dict.items():

            # 'abc210', 'arc54'
            if res := re.search(r"^(a[a-z]c)(?=\d+)", key):
                key = f"{res.group()}/{key[3:]}"

            updated_file_path_list += [f"{key}/{v}.cpp" for v in values]

        return updated_file_path_list

    # Execute git command.
    def execute_command(self):

        # execute the command.
        add_file_list = ["git add " + path for path in self.get_updated_file_path_list()]
        com_list = add_file_list + [
            f'git commit -m "{self.commit_message}"',
            "git push origin master",
        ]
        # print(add_file_list)
        for com in com_list:
            subprocess.run(com, shell=True)  # print(com)
