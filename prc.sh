#!/bin/bash

total=$(ls src/*.c | wc -l | tr -d ' ')
count=$(($total - `cat file.count`))

printf "\r\033[2KCompiling [$((100 * $count / $total))%%]"
cat file.count > tmp.txt
rm -f file.count
echo $((`cat tmp.txt` - 1)) > file.count
rm -f tmp.txt