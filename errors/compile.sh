#!/bin/bash

if [[ -z $1 ]]; then
		echo "Usage: ./compile.sh NUMBER"
		exit 1
fi

re='^[0-9]+$'
if ! [[ $1 =~ $re ]] ; then
		echo "error: Not a number" >&2; exit 1
fi

# Copy the sample into a temporary file

cp sample.cpp tmp_$1.cpp

# Replace the <+++> in the temporary file to #include "$1.cpp"

sed -i 's|<+++>|#include "'$1'.cpp"|g' tmp_$1.cpp

# Compile it

g++ tmp_$1.cpp -o $1

# Run it

./$1

# Delete the trash

rm $1 tmp_$1.cpp
