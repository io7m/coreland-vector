#!/bin/sh

printf "%12s %12s %12s\n" "test" "sse2" "pure"
for f in *_sse2.sh
do
  ./$f
done
