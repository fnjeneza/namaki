#!/usr/bin/env python3

import venv
import os
import subprocess
import shlex

def create_and_change_env(path):
    print('*'*50)
    print("\t creating python virtualenv")
    print('*'*50)
    venv.create(path, with_pip=True)
    os.environ["VIRTUAL_ENV"] = path
    os.environ["PATH"] = path+"/bin:"+os.environ["PATH"]

def install(packages):
    cmd = "python -m pip install"
    for package in packages:
        cmd+= " %s " % package

    cmd = shlex.split(cmd)
    subprocess.run(cmd)

def install_yowsup():
    yowsup = os.path.join(os.getcwd(), "3rd-party", "yowsup")
    os.chdir(yowsup)
    cmd = "python setup.py install"
    cmd = shlex.split(cmd)
    subprocess.run(cmd)

if __name__ == "__main__":
    path = os.path.abspath("src/proxy")
    create_and_change_env(path)
    python = os.path.join(path, "bin","python")
    packages = ["pyzmq", "pyyaml"]
    install(packages)
    install_yowsup()
