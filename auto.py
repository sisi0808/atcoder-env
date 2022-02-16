from email.policy import default
import re
import filecmp
import subprocess
from collections import defaultdict

"""
以下の場合を考慮
* 変更がなかった場合
* xxx_a-eとついたファイルが変更されていなかった場合
* ファイルが追加のみされた場合

* ファイルの追加もコミットメッセージに含める
"""

# Automate the following comand.
# [git add -A, git commit -m "xxx-a-c and yyy-b", git push origin master]

def get_git_status():

    cmd = 'git status -s'
    out_message = (subprocess.Popen(cmd, stdout=subprocess.PIPE,
                            shell=True).communicate()[0]).decode('utf-8')
    return out_message

# Get new_created file list from 'git status' output.
def find_created_file():

    out_message = get_git_status()
    regex = r'\?\?\s(.*)'
    created_dic = defaultdict(list)

    for m in re.finditer(regex,  out_message, re.MULTILINE):
        s = m.groups()[0].split('/')
        if len(s) >= 2:
            for rank in  "abcde":
                if not filecmp.cmp(f'{s[0]}/{s[1]}/{rank}.cpp',  './template.cpp'):
                    created_dic[s[-2]].append(rank)

    return created_dic

# Get modified file list from 'git status' output.
def find_modified_file():

    out_message = get_git_status()
    regex = r'M\s(.*)$'
    modified_dic = defaultdict(list)

    for m in re.finditer(regex,  out_message, re.MULTILINE):
        s = m.groups()[0].split('/')
        if len(s) >= 2:
            modified_dic[s[-2]].append(s[-1][0])

    return modified_dic

# Merge two dict.
def merge_dict(a, b):

    c={}
    for key in list(set(list(a.keys())+list(b.keys()))):
        value_a=a[key] if key in a else []
        value_b=b[key] if key in b else []
        c[key]=sorted(list(set(value_a+value_b)))

    return c

# Check if any files have been updated.
def updated_file():

    # merge modified_file_dic and created_file_dic
    modified_dic = find_modified_file()
    created_dic  = find_created_file()

    # If there are no change with files.
    if  modified_dic == created_dic == {}:
        return False

    return merge_dict(modified_dic, created_dic)

# Make commit message from output of created or modified file names.
def make_commit_message(modified_dic):

    commit_message = ''
    for i, (dkey,dvalues) in enumerate(modified_dic.items()):

        if i != 0: commit_message += ' and '
        commit_message += f'{dkey}_{dvalues[0]}'

        # If modified multiple files in one directry
        if dvalues[0] != dvalues[-1]:
            commit_message +=  f'-{dvalues[-1]}'

    return commit_message

# Execute git command.
def execute_command(commit_message):

    # Execute the command.
    com_list =  ['git add -A', f'git commit -m "{commit_message}"', 'git push origin master']
    for com in com_list:
        subprocess.run(com, shell=True)

if __name__ == '__main__':

    if updated_dic := updated_file():
        commit_message = make_commit_message(updated_dic)
        try:
            execute_command(commit_message)
        except Exception as e:
            print(e)
        else:
            print("Done")

    else:
        print('There are no files with updated')
