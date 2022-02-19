import os

parent_dir_path = 'abc'

for sub_name in os.listdir(parent_dir_path):
    sub_dir_path = os.path.join(parent_dir_path, sub_name)
    for file_name in os.listdir(sub_dir_path):
        # If there is an compiles file.
        if len(file_name) == 1:
            file_path = os.path.join(sub_dir_path, file_name)
            try:
                os.remove(file_path)
            except Exception as e:
                print(e)
            else:
                print(f'Deleted {file_path}')

