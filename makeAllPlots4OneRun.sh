#!/bin/sh
# enter the root filename
export FILE=$1
export RUN=$2
export TYPE=run_$RUN
#root -b -l -q plotResidualsOrder.cxx\(\"$FILE\"\)
#root -b -l -q plotResidualsOrderGBLWithErrors.cxx\(\"$FILE\"\)
#root -b -l -q plotResidualsOrderScatter.cxx\(\"$FILE\"\)
#root -b -l -q plotXY.cxx\(\"$FILE\"\)
#root -b -l -q plotXY_neg.cxx\(\"$FILE\"\)
#root -b -l -q plotXY_pos.cxx\(\"$FILE\"\)
#root -b -l -q plotPredXY.cxx\(\"$FILE\"\)
root -b -l -q plotResidualsInitial.C\(\"$FILE\"\)
root -b -l -q plotResidualsOrderGBLWithErrors.C\(\"$FILE\"\)
root -b -l -q plotResidualsVSPos_new.C\(\"$FILE\"\)
root -b -l -q plotResidualsVSPosProfile_new.C\(\"$FILE\"\)
root -b -l -q plotResidualsUVSPosV_new.C\(\"$FILE\"\)
root -b -l -q plotResidualsUVSPosVProfile_new.C\(\"$FILE\"\)
root -b -l -q plotXY.C\(\"$FILE\"\)
root -b -l -q plotXY_neg.C\(\"$FILE\"\)
root -b -l -q plotXY_pos.C\(\"$FILE\"\)
root -b -l -q plotXY_negPos.C\(\"$FILE\"\)
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
root -b -l -q survey_d0z0p.C\(\"$FILE\"\)

mkdir $TYPE
mv -fv *__* $TYPE/.
mv -fv *$RUN\*.* $TYPE/.
mv -fv *Kink*.txt $TYPE
mv -vf *sensor_*.gif $TYPE/.
mv -fv *_tb.gif  $TYPE/. $TYPE/.
mv -fv survey*.gif  $TYPE/. $TYPE/.
