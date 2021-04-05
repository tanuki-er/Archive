#!/bin/bash
if [[ $# -ne 2 ]]
then
echo -e "\e[31mWrong parameters amount!\e[0m\nYou entered $# parameter(s) but need 2."
exit 1
fi
if ! [[ -e $1 ]] || ! [[ -d $1 ]]
then
echo -e "\e[31mDirectory $1 doesnt exist!\e[0m"
exit 1
fi
if [[ -z $2 ]]
then
echo -e "\e[31mInvalid parameter!\e[0m"
echo -e "\e[36mWhere is your regex, dude?\e[0m"
exit 1
fi
grep -r $2 $1 2> /dev/null 1>&1
exit 0
