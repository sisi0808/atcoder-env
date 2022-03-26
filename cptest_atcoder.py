from packages import *
import sys

# ex) abc210_a
# ex) typical90_a
if __name__ == '__main__':

    if len(sys.argv) >= 2:
        if len(sys.argv) >= 3 and sys.argv[2] == 'py':
            extension = 'py'
        else:
            extension = 'cpp'
        try:
            #print(sys.argv[1].split('_'))
            autotest = Aat.AtcoderAutoTest(*sys.argv[1].split('_'), extension)
            autotest.download_test_cases()
            autotest.execute_test_cases()

        except Exception as e:
            print(e)
    else:
        print("Input contest name and problem_name")
