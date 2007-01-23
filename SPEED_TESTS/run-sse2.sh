#!/bin/sh

for f in *_sse2.sh
do
  echo $f
  ./$f
done
