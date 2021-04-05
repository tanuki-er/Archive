#!/bin/bash

for pid in $(ps -A -o pid)
do
file1="/proc/"$pid"/status"
file2="/proc/"$pid"/sched"

ppid=$(grep -E "PPid" $file1 | grep -E -s -o "[0-9]+")
sleepavg=$(grep -E "avg_atom" $file2 | grep -E -s -o "[0-9.]+")

if [[ -z $sleepavg ]]
then
sleepavg=0
fi

if [[ -n $ppid ]]
then
echo "ProcessID=$pid : Parent_ProcessIP=$ppid : Average_Time=$sleepavg"
fi
done | sort -n -t "=" -k3 > script5file.log
5th.sh (END)
