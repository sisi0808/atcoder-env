from email.policy import default
import re
import sys
import subprocess
from collections import defaultdict

"""
以下の場合を考慮
* 変更がなかった場合
* xxx_a-eとついたファイルが変更されていなかった場合
* ファイルが追加のみされた場合
"""

# Automate the following comand.
# [git add -A, git commit -m "xxx-a-c", git push origin master]

def find_modified_file():

    # Get modified file list from 'git status' output.
    cmd = 'git status'
    out_message = (subprocess.Popen(cmd, stdout=subprocess.PIPE,
                            shell=True).communicate()[0]).decode('utf-8')

    regex = r'modified:\s\s\s(.*)$'
    modified_dic = defaultdict(list)

    for m in re.finditer(regex,  out_message, re.MULTILINE):
        s = m.groups()[0].split('/')
        if len(s) >= 2:
            modified_dic[s[-2]].append(s[-1][0])

    # If there are no files with modified.
    if not modified_dic:
        return False

    return modified_dic

def get_commit_message(modified_dic):

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

    if modified_dic := find_modified_file():
        commit_message = get_commit_message(modified_dic)
        try:
            execute_command(commit_message)
        except Exception as e:
            print(e)
        else:
            print("Done")

    print('There are no files with modified')
