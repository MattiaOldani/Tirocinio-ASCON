#!/bin/bash

for family in $(ls -d */); do
    cd $family
    for algorithm in $(ls -d */); do
        cd $algorithm
        for implementation in $(ls -d */); do
            cd $implementation
            gcc -march=native -O3 *.c -o test
            echo "$family $algorithm $implementation $(stat --format=%s test)"
            rm test
            cd ..
        done
        cd ..
    done
    cd ..
done

exit
