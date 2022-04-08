from packages import *
import sys

# 入力の引数に'del'を指定したらフォルダを削除
# 指定しなければフォルダ作成
if __name__ == '__main__':

    if len(sys.argv) >= 2 and sys.argv[1] == 'del':
        # コンテスト名(abc210, typical90, dp)
        con_name = input('削除するコンテスト名を入力(abc210など)：')

        mcf = Mcf.MakeContestFolder(con_name)
        mcf.del_contest_dir()
    else:
        # コンテスト名(abc210, typical90, dp)
        con_name = input('コンテスト名を入力(abc210など)：')

        mcf = Mcf.MakeContestFolder(con_name)
        mcf.make_contest_dir()