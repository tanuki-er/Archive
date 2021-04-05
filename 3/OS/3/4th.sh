#!/bin/bash

nice -n 17 ./4th_inf.sh & pid0=$!
nice -n 5 ./4th_inf.sh & pid1=$!
nice -n 5 ./4th_inf.sh & pid2=$!

echo "1th PID = $pid0"
echo "2nd PID = $pid1"
echo "3rd PID = $pid2"

top -p $pid0, $pid1, $pid2 | head -n +10 | tail -n +8 | awk '{ print "PID =",$2,", %CPU","=",$10}'

kill $pid0
kill $pid1
kill $pid2
