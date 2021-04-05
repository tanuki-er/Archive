#!/bin/bash

ps -A -o pid,command | grep '/sbin/' | awk '{print $1}' > script3file.log

3rd.sh (END)
