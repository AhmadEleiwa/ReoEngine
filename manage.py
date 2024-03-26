from os import path, listdir, chdir
import subprocess
from sys import argv
import json
from shutil import copytree, copyfile

help ="""manage.py 
        usage: manage.py [build|run|-h]
        manage.py build : build the project, copying the important files
        manage.py run -c [--cache] : run existence build
        manage.py run : compile andrun the project, without copying the files
        manage.py -h : help
          """
args = json.load(open("setup.json"))["args"]
# chdir(workspace_folder)
def run():
    print("running...")
    subprocess.run(["g++.exe "]+args)
    target_file = args[-1].split("/")
    chdir(target_file[0])
    subprocess.run([target_file[1]]) 
    

def build():
    print("building...")
    subprocess.run(["g++.exe "]+args)
    filtered_idlls = list(filter(lambda x: x.endswith(".dll"),  listdir(f".")))
    filtered_files2 = list(filter(lambda x: not (x.endswith(".cpp") or x.endswith(".h") or x.endswith(".c")),  listdir(f"src")))
    
    print("copying dlls...",filtered_idlls)
    for i in filtered_idlls:
        copyfile(f"{i}", f"build/{i}")
    print("copying files...",filtered_files2)
    for i in filtered_files2:
        if path.isdir(f"src/{i}"):
            copytree(f"src/{i}", f"build/{i}", dirs_exist_ok=True)
        elif path.isfile(f"src/{i}"):
            copyfile(f"src/{i}", f"build/{i}")
        else:
            print("File not found: " + i)
    print("Done!")
    target_file = args[-1].split("/")
    chdir(target_file[0])
    subprocess.run([target_file[1]]) 

if len(argv) <= 1 :
    print(help)  
elif argv[1] == 'run':
    if len(argv) > 2 and (argv[2] == '-c' or argv[2] == '--cache'):
        target_file = args[-1].split("/")
        chdir(target_file[0])
        subprocess.run([target_file[1]]) 
    else:
        run()
elif argv[1] == 'build':
    build()
elif argv[1] == '-h':
    print(help)
else:
    print(help)



