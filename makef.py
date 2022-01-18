import os, sys
import shutil

"""
テンプレ(template.cpp)をベースにして、コンテスト毎のフォルダを作成
実行時引数にdelを渡すと、フォルダの削除も可能
"""

# 入力として受け取ったコンテスト番号のフォルダを作成
def make_con_dir(con_cat, con_num):

    # 成功フラグ
    message = False

    tgt_dir = os.path.join(con_cat, con_num)
    # コンテスト種別のフォルダを作成
    if not os.path.exists(con_cat):
        os.makedirs(con_cat)

    # その回のフォルダを作成
    if not os.path.exists(tgt_dir):
        os.makedirs(tgt_dir)
        message = True

        for l in 'abcde':
            shutil.copy("template.cpp", os.path.join(tgt_dir, l+'.cpp'))

    if not (message): print("既に存在するフォルダです")

# 誤って作ってしまったコンテスト番号のフォルダを削除
def del_con_dir(con_cat, con_num):

    tgt_dir = os.path.join(con_cat, con_num)

    # 指定されたコンテスト番号のフォルダを削除
    if os.path.exists(tgt_dir):
        shutil.rmtree(tgt_dir)
    else:
        print("そのフォルダは存在しません")

    # もしそのコンテスト種別のフォルダが空なら、コンテスト種別のフォルダを削除
    if len(os.listdir(con_cat)) == 0:
        shutil.rmtree(con_cat)


# 入力の引数に'del'を指定したらフォルダを削除、指定しなければフォルダ作成
if __name__ == '__main__':

    # コンテスト種別、コンテスト番号
    #con_cat, con_num = input("以下の用に入力（abc 222）：").split()
    con_cat = 'abc'
    con_num = input('コンテスト番号を入力：')

    if len(sys.argv) >= 2 and sys.argv[1] == 'del':
        del_con_dir(con_cat, con_num)
    else:
        make_con_dir(con_cat, con_num)

