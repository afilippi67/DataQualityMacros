#!/bin/sh
# enter the root filename
export FILE=$1
export RUN=$2
export TYPE=run_$RUN
#
root -b -l -q plotResidualsInitial.C\(\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q plotResidualsOrderGBLWithErrors.C\(\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q plotResidualsVSPos_new.C\(\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q plotResidualsVSPosProfile_new.C\(\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q plotResidualsUVSPosV_new.C\(\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q plotResidualsVSPosVProfile_new.C\(\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q plotXY.C\(\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q plotXY_neg.C\(\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q plotXY_pos.C\(\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q plotXY_negPos.C\(\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q plotPredXY.C\(\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q plotKinkLambda.C\(\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q plotKinkPhi.C\(\"$FILE\"\)
#read -p "Press enter to continue"
#
root -b -l -q plotSingleSensor.C\(\"1\",\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q plotSingleSensor.C\(\"2\",\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q plotSingleSensor.C\(\"3\",\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q plotSingleSensor.C\(\"4H\",\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q plotSingleSensor.C\(\"4S\",\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q plotSingleSensor.C\(\"5H\",\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q plotSingleSensor.C\(\"5S\",\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q plotSingleSensor.C\(\"6H\",\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q plotSingleSensor.C\(\"6S\",\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q survey_d0z0p.C\(\"$FILE\"\)
#read -p "Press enter to continue"

mkdir $TYPE
mv -fv *__* $TYPE/.
mv -fv *$RUN\*.* $TYPE/.
mv -fv *Kink*.txt $TYPE
mv -vf *sensor_*.gif $TYPE/.
mv -fv *_tb.gif  $TYPE/. $TYPE/.
mv -fv survey*.gif  $TYPE/. $TYPE/.
