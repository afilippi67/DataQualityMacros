#!/bin/sh
# input:
# $1: .root file full path
# $2: output directory name (without run_)
#
export INP=$1
export NAME=$2
export YR=$3
./makeAllPlots4OneRun.sh $INP $NAME $YR
okular run_$NAME/*.pdf
