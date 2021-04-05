#!/bin/bash

if [[ $# -eq 1 ]]
then
echo -e "\e[32mProgram finished with exit code $1.\e[0m"
exit $1
else
echo -e "\e[32mProgram finished with exit code 0.\e[0m"
exit 0
fi
