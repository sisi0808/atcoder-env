import os
import glob


def remove_glob(pathname, recursive=True):
    for p in glob.glob(pathname, recursive=recursive):
        if os.path.isfile(p):
            os.remove(p)


if __name__ == "__main__":
    pathname = "./**/?"
    remove_glob(pathname)
