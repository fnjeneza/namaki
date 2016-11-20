Namaki
===========
Getting started
---------------
Dependencies
    * Yowsup
    * zmq

Installing depedencies
```
pip3 install zmq
pip3 install pyyaml
git clone  git@github.com:fnjeneza/yowsup.git
cd yowsup
python setup.py install
```
In order to generate message serialization module run:
```
protoc --python_out=. messages.proto
```
