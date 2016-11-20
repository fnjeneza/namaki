Namaki Client
=============

Getting started
---------------
Those packages are required to build namaki library

    * build-essential
    * cmake
    * ninja-build (optional)
    * zmq
    * protocol buffer
    * sqlite3
    * virtualenv

On ubuntu you can install them with:
```
    $ apt install build-essential cmake ninja-build libzmqpp-dev \
    libsqlite3-dev virtualenv
```

For protobuf we use version 3.0.2 (libprotoc 3.0.2)
[see](https://github.com/google/protobuf#protocol-buffers---googles-data-interchange-format)

A script can be found [here](./install-protobuf.sh)

Python environment
------------------
Run the script setup-env.sh to initialize a virtual environment for the proxy
The script will install all dependecies for the proxy.

Proxy dependecies are:
    * zmq
    * yaml

Build
-----
After installing dependencies, if libprotobuf (version installed) can not be
found run:
```
    $cmake -DPROTOBUF_LIB=$PROTOBUF
```
with **$PROTOBUF** the path to your protobuf lib, default is
**/usr/local/lib/libprotobuf.so** if installed with the script.

