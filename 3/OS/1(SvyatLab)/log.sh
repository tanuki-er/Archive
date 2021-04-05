#!/bin/bash

source="/var/log/anaconda/X.log"

if ! [[ -e $source ]]
then
echo -e "\e[31mFile $source does not exist!\e[0m" 
exit 1
fi

WARNING=$(cat $source | awk '/\[/ && /WW/') &> /dev/null
INFO=$(cat $source | awk '/\[/ && /II/') &> /dev/null

echo -e "${WARNING//"(WW)"/"\e[33mWarning:\e[0m"}"
echo -e "${INFO//"(II)"/"\e[34mInformation:\e[0m"}"

exit 0
