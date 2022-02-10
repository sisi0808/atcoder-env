from email.policy import default
import re
import sys
import subprocess
from collections import defaultdict

# automate the following comand.
# [git add -A, git commit -m "xxx-a-c", git push origin master]

def find_modified_file():

    # get modified file list from 'git status' output.
    cmd = 'git status'
    out_message = (subprocess.Popen(cmd, stdout=subprocess.PIPE,
                            shell=True).communicate()[0]).decode('utf-8')

    regex = r'modified:\s\s\s(.*)$'
    modified_dic = defaultdict(list)

    for m in re.finditer(regex,  out_message, re.MULTILINE):
        s = m.groups()[0].split('/')
        if len(s) >= 2:
            modified_dic[s[-2]].append(s[-1][0])

    return modified_dic


def get_commit_message():

    # example:223_a-e and dp_c-d
    modified_dic = find_modified_file()

    commit_message = ''
    for i, (dkey,dvalues) in enumerate(modified_dic.items()):
        if i != 0: commit_message += ' and '
        commit_message += f'{dkey}_{dvalues[0]}-{dvalues[-1]}'

    return commit_message


def execute_command(commit_message):

    # Execute the command.
    com_list =  ['git add -A', f'git commit -m "{commit_message}"', 'git push origin master']
    for com in com_list:
        subprocess.run(com, shell=True)


if __name__ == '__main__':

    commit_message = get_commit_message()
    execute_command(commit_message)
    print("Done")
