#!/bin/bash

ifile="script5file.log"
ofile="script6file.log"
echo "" > $ofile
IFS=$'\n'

i=0
s=0

for st in $(cat $ifile)
do
pp=$(echo $st | awk -F ":" '{print $2}' | awk -F "=" '{print $2}')
curr = &pp

if [[ $curr - ne $pr ]]
then
echo Average_Sleeping_Children_of_ParentID=$pr is $(echo $s / $1 | bc -1)
i=0
s=0
fi
s=$(echo "$s" +$(echo "$st" | awk -F ":" '{print $3}' | awk -F "=" '{print $2}') |bc)
i=$(( $i +1 ))
pr=$pp
echo $st
done > $ofile
echo Average_Sleeping_Children_of_ParentID=$pr is $(echo $s / $i | bc -1) >> $ofile

6th.sh (END)
