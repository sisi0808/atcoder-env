import os
import glob
import re
import shutil


def remove_globed_file(pathname, regex, recursive=True):
    for p in glob.glob(pathname, recursive=recursive):
        if os.path.isfile(p) and re.search(regex, p):
            os.remove(p)


def remove_globed_dir(pathname, regex, recursive=True):
    for p in glob.glob(pathname, recursive=recursive):
        if os.path.isdir(p) and re.search(regex, p):
            shutil.rmtree(p)


if __name__ == "__main__":
    # If you want to add target dir,
    # you should add contest_name
    contest_dir = ["abc", "arc", "typical90", "dp"]
    regex1 = r"^[^\.]+$"
    regex2 = r"^.*dSYM$"
    for pathname in contest_dir:
        remove_globed_file(pathname + "/**", regex1)
        remove_globed_dir(pathname + "/**", regex2)
