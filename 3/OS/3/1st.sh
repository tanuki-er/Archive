#!/bin/bash

d=$(date '+%d.%m.%y_%H:%M:%S')

mkdir ~/test && echo "catalog test was create succesfully" >> ~/report.log && touch ~/test/$d.log
ping www.net_nikogo.ru || echo "$(date '+%d.%m.%y_%H:%M:%S') host is unbreachable" >> ~/report.log
