#!/bin/bash

# QUESTE DUE RIGHE SOLO AL PRIMO LANCIO
mkdir lib
ldd BINARIO | grep "=> /" | awk '{print $3}' | xargs -I '{}' cp -v '{}' $PWD/lib

for filename in lib/*; do
	echo $filename
	ldd $filename | grep "=> /" | awk '{print $3}' | xargs -I '{}' cp -v '{}' lib/
done
