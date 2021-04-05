#!/bin/bash
ParamsAmountError()
{
echo -e "\e[31mWrong parameters amount!\e[0m"
}

WrongCommand()
{
echo -e "\e[31mCommand $1 does not exist!\e[0m"
echo -e "\e[36mWould you like to get a help list? (y/n)\e[0m"
read ans
if [[ $ans = "y" ]]
then	
sh ./help.sh
exit 0
else if [[ $ans = "n" ]]
then
echo -e "\e[36mOkay, goodbye!\e[0m"
exit 0
else
echo -e "\e[36mI don't understand you, dude! Try again...\e[0m"
exit 0
fi
fi
}

CheckParamsAmount()
{
if [[ $1 -ne $2 ]]
then ParamsAmountError
echo "You entered $1 parameter(s) but need $2."
exit 1
fi
}

NoAccess()
{
echo -e "\e[31mCannot access script!\e[0m"
exit 1
}

SearchFunc()
{
if ! [[ -e ./search.sh ]]
then
NoAccess
fi
if [[ $# -ne 2 ]]
then
ParamsAmountError
exit 1
fi
sh ./search.sh $1 $2
}
StrlenFunc()
{
if ! [[ -e ./strlen.sh ]]
then
NoAccess
fi
shift
sh ./strlen.sh "$@"
}
ReverseFunc()
{
if ! [[ -e ./reverse.sh ]]
then
NoAccess
fi
sh ./reverse.sh $1 $2
}
ExitFunc()
{
if ! [[ -e ./exit.sh ]]
then
NoAccess
fi
if ! [[ $2 =~ ^[0-9]+?$ ]]
then
echo -e "\e[31mArgument $2 is not an integer number!\e[0m"
exit 1
fi
if [[ $1 -ne 1 ]] && [[ $1 -ne 2 ]]
then
ParamsAmountError
exit 1
fi
exec sh ./exit.sh $2
echo -e "\e[32mProgram finished with exit code $?.\e[0m"
}
#__________________________________________________________________________________________________________
if [[ $# -lt 1 ]]
then ParamsAmountError
else
case  "$1"  in
"calc" )
CheckParamsAmount $# 4
if ! [[ -e ./calculator.sh ]]
then
NoAccess
fi
sh ./calculator.sh $2 $3 $4
;;
"search" )
CheckParamsAmount $# 3
SearchFunc $2 $3
;;
"reverse" )
CheckParamsAmount $# 3
ReverseFunc $2 $3
;;
"strlen" )
StrlenFunc "$@"
;;
"log" )
if ! [[ -e ./log.sh ]]
then
NoAccess
fi
sh ./log.sh
;;
"exit" )
ExitFunc $# $2
;;
"help" )
if ! [[ -e ./exit.sh ]]
then
NoAccess
fi
sh ./help.sh
;;
"interactive" )
if ! [[ -e ./interactive.sh ]]
then
NoAccess
fi
exec sh ./interactive.sh
;;
* )
WrongCommand $1
esac
fi
exit 0
