#! /bin/bash

cp ../codes/Data\ structures/persistent\ array.cc persistent_array.cc
g++ test_persistent_array.cc -o test_pa
./test_pa
rm test_pa
