#!/bin/bash

for family in *;
do
    if [[ -d $family ]];
    then
        cd $family
        for algo in *;
        do
            cd $algo
            for implementation in *;
            do
                cd $implementation
                gcc -march=native -O3 *.c -o test
                ./test $implementation.csv
                cd ..
            done
            cd ..
        done
        cd ..
    fi
done
