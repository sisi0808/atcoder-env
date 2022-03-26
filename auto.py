from packages import *

if __name__ == '__main__':

    puf = Puf.PushUpdatedFiles()

    # If you don't want to include created or modified files to commit message,
    # You can change those flags to False.
    puf.make_commit_message(created=True, modified=True)

    # If there are some updated codes.
    if puf.commit_message != "":
        try:
            print(puf.commit_message)
            puf.execute_command()
        except Exception as e:
            print(e)
        else:
            print("Done")
    else:
        print('There are no contest codes with updated')