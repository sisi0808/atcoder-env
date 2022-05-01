import os
import glob
import re


def remove_glob(pathname, regex, recursive=True):
    for p in glob.glob(pathname, recursive=recursive):
        if os.path.isfile(p) and re.search(regex, p):
            os.remove(p)


if __name__ == "__main__":
    # If you want to add target dir,
    # you should add contest_name
    contest_dir = ["abc", "typical90", "dp"]
    regex = r"^[^\.]+$"
    for pathname in contest_dir:
        remove_glob(pathname + "/**", regex)
