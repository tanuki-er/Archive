#!/bin/bash
if [[ $# -ne 2 ]]
then
echo -e "\e[31mNot enough arguments!\e[0m"
exit 1
fi
if ! [[ -e $1 ]]
then
echo -e "\e[31mSource file $1 does not exist!\e[0m"
exit 1
fi
if ! [[ -e $2 ]]
then
echo -e "\e[31mFile $2 does not exist!\e[0m"
echo -e "\e[36mFile $2 will be created.\e[0m"
touch $2 &> /dev/null
if [[ -e $2 ]]
then
echo -e "\e[32mFile $2 was created successfully!\e[0m"
else
echo -e "\e[31mAn error occurred while creating $2.\e[0m"
exit 1
fi
fi
tac $1 > $2
if [[ $? -eq 0 ]]
then
echo -e "\e[32mSource file $1 was reversed successfully and written to $2.\e[0m"
echo -e "\e[36mWould you like to view $2 file? (y/n)\e[0m"
read ans
if [[ $ans = "y" ]]
then
cat $2
else if [[ $ans = "n" ]]
then
echo -e "\e[36mOkay, bye\e[0m"
exit 0
else
echo -e "\e[36mI don't understand you, try again...\e[0m"
exit 1
fi
fi
fi
exit 0
