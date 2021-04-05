#!/bin/bash

at now + 1 minutes -f ./1st.sh
tail -n 0 -f ~/report.log
