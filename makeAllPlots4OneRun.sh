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
root -b -l -q plotResidualsVSPos.C\(\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q plotResidualsVSPosProfile.C\(\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q plotResidualsUVSV.C\(\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q plotResidualsUVSVProfile.C\(\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q plotHitXY.C\(\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q plotPredXY.C\(\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q plotKinkLambda.C\(\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q plotKinkPhi.C\(\"$FILE\"\)
#read -p "Press enter to continue"
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
root -b -l -q plotSingleSensor.C\(\"7H\",\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q plotSingleSensor.C\(\"7S\",\"$FILE\"\)
#read -p "Press enter to continue"
root -b -l -q survey_d0z0.C\(\"$FILE\"\,$YR\)
#read -p "Press enter to continue"

mkdir $TYPE
mv -fv *__* $TYPE/.
mv -fv *$RUN\*.* $TYPE/.
mv -fv *Kink*.txt $TYPE
mv -vf *sensor_*.gif $TYPE/.
mv -fv *_tb.gif  $TYPE/. $TYPE/.
mv -fv survey*.gif  $TYPE/. $TYPE/.

#root -b -l -q extractGeoQualityFromResiduals.C\(\"$TYPE\"\)
