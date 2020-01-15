#!/bin/sh
# enter the root filename
export FILE=$1
export RUN=$2
export TYPE=run_$RUN
root -b -l -q plotResidualsInitial.C\(\"$FILE\"\)
root -b -l -q plotResidualsOrderGBLWithErrors.C\(\"$FILE\"\)
root -b -l -q plotResidualsVSPos_new.C\(\"$FILE\"\)
root -b -l -q plotResidualsVSPosProfile_new.C\(\"$FILE\"\)
root -b -l -q plotResidualsUVSPosV_new.C\(\"$FILE\"\)
root -b -l -q plotResidualsUVSPosVProfile_new.C\(\"$FILE\"\)
root -b -l -q plotXY.C\(\"$FILE\"\)
root -b -l -q plotPredXY.C\(\"$FILE\"\)
root -b -l -q plotKinkLambda.C\(\"$FILE\"\)
root -b -l -q plotKinkPhi.C\(\"$FILE\"\)
#
root -b -l -q plotSingleSensor.C\(\"1\",\"$FILE\"\)
root -b -l -q plotSingleSensor.C\(\"2\",\"$FILE\"\)
root -b -l -q plotSingleSensor.C\(\"3\",\"$FILE\"\)
root -b -l -q plotSingleSensor.C\(\"4H\",\"$FILE\"\)
root -b -l -q plotSingleSensor.C\(\"4S\",\"$FILE\"\)
root -b -l -q plotSingleSensor.C\(\"5H\",\"$FILE\"\)
root -b -l -q plotSingleSensor.C\(\"5S\",\"$FILE\"\)
root -b -l -q plotSingleSensor.C\(\"6H\",\"$FILE\"\)
root -b -l -q plotSingleSensor.C\(\"6S\",\"$FILE\"\)
root -b -l -q survey_d0z0.C\(\"$FILE\"\)

mkdir $TYPE
mv -fv *__* $TYPE/.
mv -fv *$RUN\*.* $TYPE/.
mv -fv *Kink*.txt $TYPE
mv -vf *sensor_*.gif $TYPE/.
mv -fv *_tb.gif  $TYPE/. $TYPE/.
mv -fv survey*.gif  $TYPE/. $TYPE/.
