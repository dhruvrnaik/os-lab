#!/bin/bash
read a b
x=`find * -maxdepth 0 -name "*.$a"`
for i in $x
  do
    mv $i ./$j
  done
