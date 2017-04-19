# DataQualityMacros
macros for alignment

*** plot a series of residual plots: makeQualityPlots.sh - usage:

   ./makeQualityPlots.sh PathToRootFile/inputRootFile.root GeometryType
   
   the gif files are moved to the directory run_GeometryFile and all of them are opened for inspection with gthumb once all     macros  have been run
   The .sh is a wrapper for the makeAllPlots4OneRun.sh script, which calls the following root macros:
   1) plotResidualsInitial.C(filename) - plots of the initial residuals
   2) plotResidualsOrderGBLWithErrors.C(filename) - plots the GBL residual distrubutions for the u coordinate and the graph of the mean value per sensor (in pairs), whose errors correspond to the sigmas of the distributions
   3) plotResidualsVSPos_new.C(filename) - scatter plot of the U residual vs U coordinate
   4) plotResidualsVSPosProfile_new.C(filename) - profile plot of the U residual vs U coordinate distribution
   5) plotResidualsUVSPosV_new.C(filename) - scatter plot of the U residual vs V coordinate
   6) plotResidualsVSPosVProfile_new.C(filename) - profile plot of the U residual vs V coordinate distribution
   7) plotXY.C(filename) - plots of V vs U coordinates of the hit in the sensor
   8) plotXY_neg.C(filename) - plots of V vs U coordinates of the hit in the sensor for positive tracks (attention: the sign is reversed)
   9) plotXY_pos.C(filename) - plots of V vs U coordinates of the hit in the sensor for negative tracks (attention: the sign is reversed)
   10) plotPredXY.C(filename) - plots of predicted XY coordinates of the hit
   11) plotKinkLambda.C(filename) - plot of the lambda angle kink
   12) plotKinkPhi.C(filename) - plot of the phi angle kink
   13) plotSingleSensor.C("sensor",filename) - several distributions per sensor. Sensor name: (1-3),(4-6)(S-H)
   14) survey_d0z0p.C(filename) - plots of z0, d0 impact parameters, xT, yT target position, momentum spectra
   All distributions are made for top and bottom sensors
