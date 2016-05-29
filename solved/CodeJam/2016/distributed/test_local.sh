#! /bin/bash

g++ --std=c++11 template.cc -D MANUEL -lpthread -lzmqpp -lzmq -o peer &&
g++ --std=c++11 router.cc -D MANUEL -lpthread -lzmqpp -lzmq -o router &&

echo Compiled !
./router "ipc:///tmp/pin3da"
