import re
import subprocess


class AtcoderAutoTest:

    # ex) (contest_name, problem_name) = (abc210, a)
    # ex) (contest_name, problem_name) = (typical90, ab)
    def __init__(self, contest_name, problem_name, extension):
        self.contest_name = contest_name
        self.problem_name = problem_name
        self.extension = extension

        # source_code_path ex) abc/210/a.cpp, arc/10/a.cpp, typical90/ab.cpp
        if res := re.search(r"^(a[a-z]c)(?=\d+)", self.contest_name):
            res = res.group()
            self.source_code_path = f"{res}/{self.contest_name[3:]}/{self.problem_name}.{self.extension}"
        else:
            self.source_code_path = f"{self.contest_name}/{self.problem_name}.{self.extension}"

    # ex) https://abc210.contest.atcoder.jp/tasks/abc210_a
    # ex) https://typical90.contest.atcoder.jp/tasks/typical90_a
    def download_test_cases(self):
        execute_command = (
            f'oj dl "https://{self.contest_name}.contest.atcoder.jp/tasks/{self.contest_name}_{self.problem_name}"'
        )
        subprocess.run(execute_command, shell=True)

    def execute_test_cases(self):

        execute_command_list = []

        if self.extension == "cpp":
            execute_command_list.append(f'g++ -Wfatal-errors -std=c++14 "{self.source_code_path}" -I .')
            execute_command_list.append(f"cp {self.source_code_path} main.{self.extension}")
            execute_command_list.append("oj test --ignore-spaces")
            execute_command_list.append("rm -rf a.out test")
        elif self.extension == "py":
            execute_command_list.append(f"cp {self.source_code_path} main.{self.extension}")
            execute_command_list.append("oj test --ignore-spaces")
            execute_command_list.append('oj test --ignore-spaces -c "python3 main.py"')
            execute_command_list.append("rm -rf test")
        else:
            raise Exception

        for execute_command in execute_command_list:
            subprocess.run(execute_command, shell=True)
