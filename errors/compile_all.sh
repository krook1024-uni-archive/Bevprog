#!/bin/bash

for i in `seq 1 25` ;
do
		echo ""$i".cpp: "
		./compile.sh $i
done
