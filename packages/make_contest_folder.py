import re
import os
import shutil

"""
テンプレ(template.cpp)をベースにして、コンテスト毎のフォルダを作成
実行時引数にdelを渡すと、フォルダの削除も可能
"""


class MakeContestFolder:

    contest_name = ""
    contest_category = ""
    contest_num = ""

    contest_category_dict = {"abc": 6, "typical90": 90, "dp": 26}

    def __init__(self, contest_name):
        self.contest_name = contest_name
        self.make_contest_name_and_contest_num()

    # Get problem_name_list
    # Like ['a', 'b', 'c', 'd', 'e']
    def get_problem_name_list(self):

        problem_name_list = []
        for i in range(self.contest_category_dict[self.contest_category]):
            problem_name = chr(ord("a") + i % 26)
            if i >= 26:
                problem_name = chr(ord("a") + int(i // 26) - 1) + problem_name
            problem_name_list.append(problem_name)

        return problem_name_list

    # contest_nameからcontest_category, contest_numを生成する
    def make_contest_name_and_contest_num(self):

        # もしcontest名をcotnest_categoryとcontest_numに分けることが可能ならば
        if res := re.search(r"^(a[a-z]c)(?=\d+)", self.contest_name):
            self.contest_category = res.group()
            self.contest_num = self.contest_name[3:]
        else:
            self.contest_category = self.contest_name

    # 指定したコンテスト名のフォルダを作成
    def make_contest_dir(self):

        tgt_dir = self.contest_category
        if self.contest_num != "":
            tgt_dir = os.path.join(tgt_dir, self.contest_num)

        # もしそのコンテストが登録されていれば
        if self.contest_category in self.contest_category_dict:
            # コンテスト種別のフォルダを作成
            if self.contest_category != "" and not os.path.exists(self.contest_category):
                os.makedirs(self.contest_category)

            # その回のフォルダを作成
            if self.contest_num != "" and not os.path.exists(tgt_dir):
                os.makedirs(tgt_dir)

            for l in self.get_problem_name_list():
                tgt_file = os.path.join(tgt_dir, l + ".cpp")
                if not os.path.exists(tgt_file):
                    shutil.copy("template.cpp", tgt_file)
                    # print(tgt_file, self.contest_num, self.contest_category)
                    print(tgt_file)
                else:
                    print("既に存在するファイルです")
        else:
            print("そのコンテストは存在しません")

    # 指定したコンテスト名のフォルダを削除
    def del_contest_dir(self):

        tgt_dir = self.contest_category
        if self.contest_num != "":
            tgt_dir = os.path.join(tgt_dir, self.contest_num)

        # 指定されたコンテスト番号内の未編集のフォルダを削除
        if os.path.exists(tgt_dir):
            for tgt_file in os.listdir(tgt_dir):
                os.remove(os.path.join(tgt_dir, tgt_file))

            if len(os.listdir(tgt_dir)) == 0:
                shutil.rmtree(tgt_dir)
        else:
            print("そのフォルダは存在しません")

        # もしそのコンテスト種別のフォルダが空なら、コンテスト種別のフォルダを削除
        if len(os.listdir(self.contest_category)) == 0:
            shutil.rmtree(self.contest_category)
