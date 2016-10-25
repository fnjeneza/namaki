#!/bin/bash

# The script corresponds to the instruct given at
# https://github.com/google/protobuf/blob/master/src/README.md#protocol-buffers---googles-data-interchange-format
#
# Please make update if changes had been made on the original page (see above)
#
# The script had been tested on ubuntu 16.04
#

sudo apt install -y build-essential libtool

$PWD=`pwd`
cd /tmp/

#download protobuf release 3.1.0
echo "download protobuf release 3.0.2"
echo ""
wget https://github.com/google/protobuf/releases/download/v3.0.2/protobuf-cpp-3.0.2.tar.gz

echo ""
echo "Extracting protobuf archive"
echo ""
tar xzf protobuf-cpp-3.0.2.tar.gz

cd protobuf-3.0.2/

./configure
make
make check
sudo make install
sudo ldconfig

cd $PWD
