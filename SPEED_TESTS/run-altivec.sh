#!/bin/sh

printf "%12s %12s %12s\n" "test" "alti" "pure"
for f in *_alti.sh
do
  ./$f
done
