#!/bin/bash

ps -A -o pid | awk '{file="/proc/"$1"/statm"; getline f < file; close(file); split(f, a); print $1,":", a[2] - a[3]}' | sort -r -n -k3 > script4file.log

4th.sh (END)
