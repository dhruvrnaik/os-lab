#!/bin/bash

file=$1
n=$#
shift
arr=$*
for i in $arr
    do
        echo \"$i\"
        grep $i $file
    done

for i in $arr
    do
        sed -i "/^$i/d" $file
    done