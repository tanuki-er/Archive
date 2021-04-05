#!/bin/bash

WrongCommand()
{
echo -e "\e[32mCommand $1 does not exist!\e[0m"
}

DivisionByZeroError()
{
echo -e "\e[31mDivision by zero is not possible!\e[0m"
exit 1
}

BothInteger()
{
if [[ $1 =~ ^[+-]?[0-9]+?$ ]] && [[ $2 =~ ^[+-]?[0-9]+?$ ]]
then
return 0
else
return 1
fi
}

SumFunc()
{
if BothInteger $1 $2
then
res=$(( $1 + $2 ))
echo $res
return 0
else
res=$( echo "$1 + $2" | bc -l )
echo $res
return 0
fi
return 1
}

SubFunc()
{
if BothInteger $1 $2
then
res=$(( $1 - $2 ))
echo $res
return 0
else
res=$( echo "$1 - $2" | bc -l )
echo $res
return 0
fi
return 1
}

MulFunc()
{
if BothInteger $1 $2
then
res=$(( $1 * $2 ))
echo $res
return 0
else
res=$( echo "$1 * $2" | bc -l )
echo $res
return 0
fi
return 1
}

DivFunc()
{
if [[ $2 =~ ^[+-]?[0]+([.][0]+)?$ ]]
then
DivisionByZeroError
fi
if BothInteger $1 $2
then
div=$(( $1 / $2 ))
echo $div
return 0
else
div=$( echo "$1 / $2" | bc -l )
echo $div
return 0
fi
return 1
}

if [[ $# -ne 3 ]]
then
echo -e "\e[31mWrong parameters amount!\e[0m\nYou entered $# parameter(s) but need 3.\e[0m"
exit 1
fi

if ! [[ $2 =~ ^[+-]?[0-9]+$ ]] || ! [[ $3 =~ ^[+-]?[0-9]+$ ]]
then
if ! [[ $2 =~ ^[+-]?[0-9]+([.][0-9]+)?$ ]] || ! [[ $3 =~ ^[+-]?[0-9]+([.][0-9]+)?$ ]]
then
echo -e "\e[31mWrong arguments! They should be two numbers!\e[0m"
exit 1
fi
fi

case "$1" in
"sum" )
SumFunc $2 $3
;;
"sub" )
SubFunc $2 $3
;;
"mul" )
MulFunc $2 $3
;;
"div" )
DivFunc $2 $3
;;
* )
WrongCommand $1
;;
esac
exit 0
