#!/usr/bin/env bash

# deps
yum install -y centos-release-scl-rh epel-release
yum install -y devtoolset-9-gcc devtoolset-9-gcc-c++
yum install wget gcc-c++ make git perl-IPC-Cmd gperf -y
/opt/python/cp313-cp313/bin/python -m pip install cmake

# openssl from source
git clone --depth 1 --branch OpenSSL_1_1_1 https://github.com/openssl/openssl
cd openssl
./config
make -j$(($(nproc) + 2)) || exit 1
make install
ldconfig
cd .. && rm -rf openssl

# zlib from source
git clone --depth 1 https://github.com/madler/zlib
cd zlib
./configure --static
make install || exit 1
ldconfig
cd .. && rm -rf zlib

#Build TDLib
git clone --depth 1 https://github.com/tdlib/td.git
cd td
rm -rf build
mkdir build
cd build
CC=/opt/rh/devtoolset-9/root/usr/bin/gcc CXX=/opt/rh/devtoolset-9/root/usr/bin/g++ cmake -DOPENSSL_USE_STATIC_LIBS=TRUE -DZLIB_USE_STATIC_LIBS=TRUE -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX:PATH=/usr/local ..
cmake --build . --target install -j$(($(nproc) + 1)) || exit 1
ls -l /usr/local
cd .. && rm -rf td
ldconfig
