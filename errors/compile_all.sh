#!/bin/bash

for i in `seq 1 25` ;
do
		echo $'\n'""$i".cpp: "
		./compile.sh $i
done
