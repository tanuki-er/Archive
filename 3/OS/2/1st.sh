#!/bin/bash

echo "" > script1file.log

pss -u root -o pid,command | sed -r "s/\s*([0-9]+)\s(.+)$/\1 : \2/" > script1file.log

1st.sh (END)

