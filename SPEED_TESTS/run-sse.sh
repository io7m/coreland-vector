#!/bin/sh

printf "%12s %12s %12s\n" "test" "sse" "pure"
for f in *_sse.sh
do
  ./$f
done
