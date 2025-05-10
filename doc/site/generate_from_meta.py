import shutil
import os
import sys

meta_files_path = sys.argv[0]
temp_md_path = sys.argv[1]
output_path = sys.argv[2]


def hugoify(dir: str):
    try:
        shutil.rmtree(output_path)
    except:
        pass

    os.makedirs(output_path, exist_ok=True)
    for path, folders, files in os.walk(dir):
        for filename in files:
            if (not filename.endswith(".md")):  # skip non-md files
                continue

            if filename.find("index") != -1:  # move index files wholesale
                with open(os.path.join(path, filename)) as src:
                    with open(os.path.join(output_path, "_index.md"), "w") as dest:
                        dest.write(src.read())
                        dest.close()
                    src.close()

                continue

            name_pieces = filename.split(".")[:-1]
            #name = name_pieces[-1]
            directory = os.path.join(output_path, *name_pieces)
            full_path = os.path.join(directory, "_index.md")
            original_path = os.path.join(path, filename)

            os.makedirs(directory, exist_ok=True)
            with open(full_path, "w") as dest:
                with open(original_path, "r") as src:
                    dest.write(src.read())
                    src.close()
                dest.close()

        for folder in folders:
            hugoify(folder)


def execute():
    hugoify(temp_md_path)


if __name__ == "__main__":
    execute()
