#!/usr/bin/bash

PROBLEM_ID=$1
FILE_PATH=./problems/"$PROBLEM_ID.cpp"

cp ./template.cpp $FILE_PATH
ln -sf $FILE_PATH ./main.cpp

echo "Enter testcase: "

TESTCASE=$(cat)
echo $TESTCASE > test.txt
