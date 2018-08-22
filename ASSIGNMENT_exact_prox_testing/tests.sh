#!/bin/bash

echo "TEST 1, THRESHOLD DISTANCE: 2, KNOWN RESULT: 1"
./a.out 1 5.4 8.0 7890 &
./a.out 2 5.4 8.0 7890
echo "#######################################"


echo "TEST 2, THRESHOLD DISTANCE: 2, KNOWN RESULT: 0"
./a.out 1 5.4 12.8 7890 &
./a.out 2 5.4 8.0 7890
echo "#######################################"


echo "TEST 3, THRESHOLD DISTANCE: 2, KNOWN RESULT: 0"
./a.out 1 1.2 1.8 7890 &
./a.out 2 5.4 8.0 7890
echo "#######################################"


echo "TEST 4, THRESHOLD DISTANCE: 2, KNOWN RESULT: 1"
./a.out 1 1.2 1.8 7890 &
./a.out 2 1.8 3.0 7890
echo "#######################################"

