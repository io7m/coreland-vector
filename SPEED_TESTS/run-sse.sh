#!/bin/sh

for f in *_sse.sh
do
  echo $f
  ./$f
done
