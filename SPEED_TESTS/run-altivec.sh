#!/bin/sh

for f in *_alti.sh
do
  echo $f
  ./$f
done
