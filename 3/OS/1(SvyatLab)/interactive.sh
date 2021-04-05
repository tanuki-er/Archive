#!/bin/bash

Menu()
{
echo -e "Choose one command.\e[0m"
echo
echo -e "\e[35ma. calc"
echo -e "b. search"
echo -e "c. reverse"
echo -e "d. strlen"
echo -e "e. log"
echo -e "f. exit"
echo -e "g. help"
echo -e "h. interactive"
echo -e "q for quit.\e[0m"
}
#
NoAccess()
{
echo -e "\e[31mCannot access script!\e[0m"
exit 1
}
#
Calc()
{
if ! [[ -e ./calculator.sh ]]
then
NoAccess
fi
echo -e "\e[36mEnter 3 arguments:"
echo -e "1. sum/sub/mul/div option"
echo -e "2. value 1"	
echo -e "3. value 2"
echo -e "in format: option value1 value2\e[0m"
read option val1 val2
sh ./calculator.sh $option $val1 $val2
}
#
Search()
{
if ! [[ -e ./search.sh ]]
then
NoAccess
fi
echo -e "\e[36mEnter 2 arguments:"
echo -e "1. directory"
echo -e "2. regex"
echo -e "int format: directory regex\e[0m"
read dir regex
sh ./search.sh $dir $regex
}
#
Reverse()
{
if ! [[ -e ./reverse.sh ]]
then
NoAccess
fi
echo -e "\e[36mEnter 2 arguments:"
echo -e "1. source file"
echo -e "2. end file"
echo -e "in format: sourcefile endfile\e[0m"
read sfile efile
sh ./reverse.sh $sfile $efile
}
#
Strlen()
{
if ! [[ -e ./strlen.sh ]]
then
NoAccess
fi
echo -e "\e[36mEnter 1 argument:"
echo -e "1. string"
echo -e "in format: string\e[0m"
read str
eval "string=($str)"
if [[ -z $str ]]
then
sh ./strlen.sh
else
sh ./strlen.sh "${string[0]}"
fi
}

Exit()
{
if ! [[ -e ./exit.sh ]]
then
NoAccess
fi
echo -e "\e[36mEnter an exit code (default = 0)\e[0m"
read ecode
if [[ -n $ecode ]]
then
if ! [[ $ecode =~ ^[-]?[0-9]+?$ ]]
then
echo -e "\e[31mArgument $ecode is not an integer number!\e[0m"
exit 1
else
exec sh ./exit.sh $ecode
fi
else
exec sh ./exit.sh 0
fi
}
#######
while true
do
Menu
read command
if [[ $command = "a" ]] || [[ $command = "calc" ]]
then
Calc
else if [[ $command = "b" ]] || [[ $command = "search" ]]
then
Search
else if [[ $command = "c" ]] || [[ $command = "reverse" ]]
then
Reverse
else if [[ $command = "d" ]] || [[ $command = "strlen" ]]
then
Strlen
else if [[ $command = "e" ]] || [[ $command = "log" ]]
then
if ! [[ -e ./log.sh ]]
then
NoAccess
fi
sh ./log.sh
else if [[ $command = "f" ]] || [[ $command = "exit" ]]
then
Exit
else if [[ $command = "g" ]] || [[ $command = "help" ]]
then
if ! [[ -e ./help.sh ]]
then
NoAccess
fi
sh ./help.sh
else if [[ $command = "h" ]] || [[ $command = "interactive" ]]
then
if ! [[ -e ./interactive.sh ]]
then
NoAccess
fi
sh ./interactive.sh
else if [[ $command = "q" ]] || [[ $command = "quit" ]]
then
exit 0
else
echo -e "\e[35mSorry, I don't understand..."
echo -e "Get menu? (y/n)"
echo -e "If N, program will finish.\e[0m"
read ans
if ! [[ $ans = "y" ]]
then
exit 0
fi
fi
fi
fi
fi
fi
fi
fi
fi
fi
done
exit 0
