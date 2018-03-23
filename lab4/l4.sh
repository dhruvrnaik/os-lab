#!/bin/bash
case $1 in
  "-linecount")
    echo $(wc -l $2)
    ;;
  "-wordcount")
    echo $(wc -w $2)
    ;;
  "-charcount")
    echo $(wc -c $2)
    ;;        
esac
