#include <TString.h>
#include <TH1D.h>
#include <TF1.h>
#include <Riostream.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TGraphErrors.h>
#include <TFile.h>
#include <TLatex.h>
#include <TLegend.h>
#include <TMultiGraph.h>
#include <TLine.h>
#include <TPad.h>

void plotResidualsInitial(char* fname){

  // input: root filename (out of ini)

  gStyle->SetOptStat(0);
  Double_t w = 1.2; // number of RMS for gaussian fit
  TString filename = fname;
  cout << filename.Data() << endl;
  TGraphErrors *mean1Top = new TGraphErrors();
  TGraphErrors *mean2Top = new TGraphErrors();
  TGraphErrors *mean3Top = new TGraphErrors();
  TGraphErrors *meanTop = new TGraphErrors();
  TGraphErrors *mean1Bot = new TGraphErrors();
  TGraphErrors *mean2Bot = new TGraphErrors();
  TGraphErrors *mean3Bot = new TGraphErrors();
  TGraphErrors *meanBot = new TGraphErrors();
  Double_t x[18] = {0.9,1.1, 1.9,2.1, 2.9,3.1, 
                    3.9,4.1, 4.9,5.1, 5.9,6.1,
		    3.95,4.15, 4.95,5.15, 5.95,6.15}; 
  TCanvas *cTop = new TCanvas("cTop","Residuals in lab frame before GBL, TOP", 800, 1000);
  TCanvas *cBot = new TCanvas("cBot","Residuals in lab frame before GBL, BOTTOM",800, 1000);
  cTop->SetFillColor(kBlue-10); cTop->SetFillStyle(3002);
  cBot->SetFillColor(kMagenta-10); cBot->SetFillStyle(3002);
  Int_t ic=0;
  Int_t np=1, npp=1;
  TFile *f = new TFile(filename.Data());
  // extract string 
  Int_t idx2 = filename.Index("/");
  Int_t idx1 = filename.Index("_");
  TString outn = filename(idx1+1,idx2-(idx1+1));
  TString outname ="residuals_"; outname += outn.Data(); outname += "_ini.txt";
  TString topName ="residuals_"; topName += outn.Data(); topName += "_top_ini.gif";
  TString botName ="residuals_"; botName += outn.Data(); botName += "_bot_ini.gif";
  ofstream outf(outname.Data());
  // top
  cout << " TOP " << endl;
  Int_t nrow = 13;
  Double_t space = 0.007;
  Double_t space1 = 0.03;
  Double_t y2 = 1./13*nrow-space1;
  Double_t y1 = 1./13*(--nrow)-space1;
  TPad *tp1 = new TPad("tp1","tp1",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  TPad *tp2 = new TPad("tp2","tp2",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  TPad *tp3 = new TPad("tp3","tp3",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  TPad *tp4 = new TPad("tp4","tp4",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  TPad *tp5 = new TPad("tp5","tp5",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  TPad *tp6 = new TPad("tp6","tp6",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  Double_t off = 0.12;
  y1 -= space1; y2 -= space1;
  space1 *= 2;
  TPad *tp7 = new TPad("tp7","tp7",0.+off,y1,0.33+off,y2);
  TPad *tp8 = new TPad("tp8","tp8",0.66-off,y1,1.-off,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  TPad *tp9 = new TPad("tp9","tp9",0.+off,y1,0.33+off,y2);
  TPad *tp10 = new TPad("tp10","tp10",0.66-off,y1,1.-off,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  TPad *tp11 = new TPad("tp11","tp11",0.+off,y1,0.33+off,y2);
  TPad *tp12 = new TPad("tp12","tp12",0.66-off,y1,1.-off,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  TPad *tp13 = new TPad("tp13","tp13",0.+off,y1,0.33+off,y2);
  TPad *tp14 = new TPad("tp14","tp14",0.66-off,y1,1.-off,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  TPad *tp15 = new TPad("tp15","tp15",0.+off,y1,0.33+off,y2);
  TPad *tp16 = new TPad("tp16","tp16",0.66-off,y1,1.-off,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  TPad *tp17 = new TPad("tp17","tp17",0.+off,y1,0.33+off,y2);
  TPad *tp18 = new TPad("tp18","tp18",0.66-off,y1,1.-off,y2);
  TLatex* hole  = new TLatex(0.05,0.48,"hole");
  TLatex* slot  = new TLatex(0.85,0.48,"slot");
  hole->SetTextColor(kCyan);
  slot->SetTextColor(kMagenta);

  cTop->cd();
  hole->Draw();
  slot->Draw();
  tp1->Draw();
  tp2->Draw();
  tp3->Draw();
  tp4->Draw();
  tp5->Draw();
  tp6->Draw();
  tp7->Draw();
  tp8->Draw();
  tp9->Draw();
  tp10->Draw();
  tp11->Draw();
  tp12->Draw();
  tp13->Draw();
  tp14->Draw();
  tp15->Draw();
  tp16->Draw();
  tp17->Draw();
  tp18->Draw();

  ic = 2;
  Int_t ipad=0;
  for(Int_t i=1; i<4; i++){
    TString hisname = "residual_before_GBL_module_L"; hisname  += i;
    hisname += "t_halfmodule_axial_sensor0";
    TString layer = "L"; layer+=i; layer+= "TA"; 
    TH1D *his = (TH1D*) f->Get(hisname.Data());
    TString hisnameIni = "residual_before_GBL_module_L"; hisnameIni  += i;
    hisnameIni += "t_halfmodule_axial_sensor0";
    TH1D *hisIni = (TH1D*) f->Get(hisnameIni.Data());
    Double_t lo = hisIni->GetXaxis()->GetXmin();
    Double_t hi = hisIni->GetXaxis()->GetXmax();
    if(layer.Contains("1")){his->SetFillColor(kRed);}
    else if(layer.Contains("2")){his->SetFillColor(kOrange);}
    else if(layer.Contains("3")){his->SetFillColor(kYellow);}
    else if(layer.Contains("4")){his->SetFillColor(kGreen);}
    else if(layer.Contains("5")){his->SetFillColor(kCyan);}
    else if(layer.Contains("6")){his->SetFillColor(kBlue);}
    if(layer.Contains("A")){his->SetFillStyle(3007);}
    else if(layer.Contains("S")){his->SetFillStyle(3004);}
    //    cTop->cd(ic); ic += 3;
    ipad++;
    TString pd = "tp"; pd+=ipad;
    TPad *pad = (TPad*) cTop->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    Double_t low = his->GetMean()-w*his->GetRMS();
    Double_t up = his->GetMean()+w*his->GetRMS();    
    Bool_t isFit = his->Fit("gaus","Q","",low,up);
    if(!isFit){
      TF1 *fit = his->GetFunction("gaus");
      
      cout << "sensor " << i << " axial mean :  " << his->GetMean()*1000. << " - RMS : " << his->GetRMS()*1000. << " (um) " << " " << his->GetEntries() << endl;
      cout << "sensor " << i << " axial mu :  " << fit->GetParameter(1)*1000. << " - sigma : " << fit->GetParameter(2)*1000. << " (um) " << endl;
      outf << layer.Data() << " " 
	   << fit->GetParameter(1)*1000. << " " 
	   << fit->GetParError(1)*1000. << " " 
	   << fit->GetParameter(2)*1000. << " " 
	   << fit->GetParError(2)*1000. << " " 
	   << his->GetEntries() << endl;
      mean1Top->SetPoint(np, x[npp-1], fit->GetParameter(1)*1000.);
      mean1Top->SetPointError(np, 0., fit->GetParameter(2)*1000.); np++;
      meanTop->SetPoint(npp, x[npp-1], fit->GetParameter(1)*1000.);
      meanTop->SetPointError(npp, 0., fit->GetParameter(2)*1000.); npp++;
    }else{
      mean1Top->SetPoint(np, x[npp-1], -9999.);
      mean1Top->SetPointError(np, 0., 0.); np++;
      meanTop->SetPoint(npp, x[npp-1], -9999.);
      meanTop->SetPointError(npp, 0., 0.); npp++;
    }

    hisname = "residual_before_GBL_module_L"; hisname  += i;
    hisname += "t_halfmodule_stereo_sensor0";
    layer = "L"; layer+=i; layer+= "TS"; 
    his = (TH1D*) f->Get(hisname.Data());
    hisnameIni = "residual_before_GBL_module_L"; hisnameIni  += i;
    hisnameIni += "t_halfmodule_stereo_sensor0";
    hisIni = (TH1D*) f->Get(hisnameIni.Data());
    lo = hisIni->GetXaxis()->GetXmin();
    hi = hisIni->GetXaxis()->GetXmax();
//    his->GetXaxis()->SetRangeUser(lo,hi);
    cout << " histogram " << hisname.Data() << endl;
    if(layer.Contains("1")){his->SetFillColor(kRed);}
    else if(layer.Contains("2")){his->SetFillColor(kOrange);}
    else if(layer.Contains("3")){his->SetFillColor(kYellow);}
    else if(layer.Contains("4")){his->SetFillColor(kGreen);}
    else if(layer.Contains("5")){his->SetFillColor(kCyan);}
    else if(layer.Contains("6")){his->SetFillColor(kBlue);}
    if(layer.Contains("A")){his->SetFillStyle(3007);}
    else if(layer.Contains("S")){his->SetFillStyle(3004);}
    //    cTop->cd(ic); ic += 3;
    ipad++;
    pd = "tp"; pd+=ipad;
    pad = (TPad*) cTop->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    low = his->GetMean()-w*his->GetRMS();
    up = his->GetMean()+w*his->GetRMS();    
    isFit = his->Fit("gaus","Q","",low,up);
    if(!isFit){
      TF1 *fit = his->GetFunction("gaus");

      cout << "sensor " << i << " stereo mean :  " << his->GetMean()*1000. << " - RMS : " << his->GetRMS()*1000. << " (um) " << " " << his->GetEntries() << endl;
      cout << "sensor " << i << " stereo mu :  " << fit->GetParameter(1)*1000. << " - sigma : " << fit->GetParameter(2)*1000. << " (um) " << endl;
      outf << layer.Data() << " " 
	   << fit->GetParameter(1)*1000. << " " 
	   << fit->GetParError(1)*1000. << " " 
	   << fit->GetParameter(2)*1000. << " " 
	   << fit->GetParError(2)*1000. << " " 
	   << his->GetEntries() << endl;
      mean1Top->SetPoint(np, x[npp-1], fit->GetParameter(1)*1000.);
      mean1Top->SetPointError(np, 0., fit->GetParameter(2)*1000.); np++;
      meanTop->SetPoint(npp, x[npp-1], fit->GetParameter(1)*1000.);
      meanTop->SetPointError(npp, 0., fit->GetParameter(2)*1000.); npp++;
    }else{
      mean1Top->SetPoint(np, x[npp-1], -9999.);
      mean1Top->SetPointError(np, 0., 0.); np++;
      meanTop->SetPoint(npp, x[npp-1], -9999.);
      meanTop->SetPointError(npp, 0., 0.); npp++;
    }
  }
  Int_t np1=1, np2=1;
  for(Int_t i=4; i<7; i++){
    TString hisname = "residual_before_GBL_module_L"; hisname  += i;
    hisname += "t_halfmodule_axial_hole_sensor0";
    TString layer = "L"; layer+=i; layer+= "TAHo"; 
    TH1D *his = (TH1D*) f->Get(hisname.Data());
    TString hisnameIni = "residual_before_GBL_module_L"; hisnameIni  += i;
    hisnameIni += "t_halfmodule_axial_hole_sensor0";
    TH1D *hisIni = (TH1D*) f->Get(hisnameIni.Data());
    Double_t lo = hisIni->GetXaxis()->GetXmin();
    Double_t hi = hisIni->GetXaxis()->GetXmax();
//    his->GetXaxis()->SetRangeUser(lo,hi);
    if(layer.Contains("1")){his->SetFillColor(kRed);}
    else if(layer.Contains("2")){his->SetFillColor(kOrange);}
    else if(layer.Contains("3")){his->SetFillColor(kYellow);}
    else if(layer.Contains("4")){his->SetFillColor(kGreen);}
    else if(layer.Contains("5")){his->SetFillColor(kCyan);}
    else if(layer.Contains("6")){his->SetFillColor(kBlue);}
    if(layer.Contains("A")){his->SetFillStyle(3007);}
    else if(layer.Contains("S")){his->SetFillStyle(3004);}
    ipad++;
    TString pd = "tp"; pd+=ipad;
    TPad *pad = (TPad*) cTop->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    Double_t low = his->GetMean()-w*his->GetRMS();
    Double_t up = his->GetMean()+w*his->GetRMS();    
    Bool_t isFit = his->Fit("gaus","Q","",low,up);
    if(!isFit){
      TF1 *fit = his->GetFunction("gaus");
      
      cout << "sensor " << i << " axial hole mean :  " << his->GetMean()*1000. << " - RMS : " << his->GetRMS()*1000. << " (um) " << " " << his->GetEntries() << endl;
      cout << "sensor " << i << " axial hole mu :  " << fit->GetParameter(1)*1000. << " - sigma : " << fit->GetParameter(2)*1000. << " (um) " << endl;
      outf << layer.Data() << " " 
	   << fit->GetParameter(1)*1000. << " " 
	   << fit->GetParError(1)*1000. << " " 
	   << fit->GetParameter(2)*1000. << " " 
	   << fit->GetParError(2)*1000. << " " 
	   << his->GetEntries() << endl;
      cout << np1 << " " << npp << " " << x[npp-1] << " " <<  fit->GetParameter(1)*1000. << endl;
      mean2Top->SetPoint(np1, x[npp-1], fit->GetParameter(1)*1000.0); 
      mean2Top->SetPointError(np1, 0., fit->GetParameter(2)*1000.); np1++;
      meanTop->SetPoint(npp, x[npp-1], fit->GetParameter(1)*1000.);
      meanTop->SetPointError(npp, 0., fit->GetParameter(2)*1000.); npp++;
    }else{
      mean2Top->SetPoint(np1, x[npp-1], -9999.); 
      mean2Top->SetPointError(np1, 0., 0.); np1++;
      meanTop->SetPoint(npp, x[npp-1], -9999.);
      meanTop->SetPointError(npp, 0., 0.); npp++;
    }

    hisname = "residual_before_GBL_module_L"; hisname  += i;
    hisname += "t_halfmodule_stereo_hole_sensor0";
    layer = "L"; layer+=i; layer+= "TSHo"; 
    his = (TH1D*) f->Get(hisname.Data());
    hisnameIni = "residual_before_GBL_module_L"; hisnameIni  += i;
    hisnameIni += "t_halfmodule_stereo_hole_sensor0";
    hisIni = (TH1D*) f->Get(hisnameIni.Data());
    lo = hisIni->GetXaxis()->GetXmin();
    hi = hisIni->GetXaxis()->GetXmax();
    if(layer.Contains("1")){his->SetFillColor(kRed);}
    else if(layer.Contains("2")){his->SetFillColor(kOrange);}
    else if(layer.Contains("3")){his->SetFillColor(kYellow);}
    else if(layer.Contains("4")){his->SetFillColor(kGreen);}
    else if(layer.Contains("5")){his->SetFillColor(kCyan);}
    else if(layer.Contains("6")){his->SetFillColor(kBlue);}
    if(layer.Contains("A")){his->SetFillStyle(3007);}
    else if(layer.Contains("S")){his->SetFillStyle(3004);}
    //    cTop->cd(ic); ic-=1;
    ipad++; ipad++;
    pd = "tp"; pd+=ipad;
    pad = (TPad*) cTop->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    low = his->GetMean()-w*his->GetRMS();
    up = his->GetMean()+w*his->GetRMS();    
    isFit = his->Fit("gaus","Q","",low,up);
    if(!isFit){
      TF1* fit = his->GetFunction("gaus");
      
      cout << "sensor " << i << " stereo hole mean :  " << his->GetMean()*1000. << " - RMS : " << his->GetRMS()*1000. << " (um) " << " " << his->GetEntries() << endl;
      cout << "sensor " << i << " stereo hole mu :  " << fit->GetParameter(1)*1000. << " - sigma : " << fit->GetParameter(2)*1000. << " (um) " << endl;
      outf << layer.Data() << " " 
	   << fit->GetParameter(1)*1000. << " " 
	   << fit->GetParError(1)*1000. << " " 
	   << fit->GetParameter(2)*1000. << " " 
	   << fit->GetParError(2)*1000. << " " 
	   << his->GetEntries() << endl;
      cout << np1 << " " << npp << " " << x[npp-1] << " " <<  fit->GetParameter(1)*1000. << endl;
      mean2Top->SetPoint(np1, x[npp-1], fit->GetParameter(1)*1000.);
      mean2Top->SetPointError(np1, 0., fit->GetParameter(2)*1000.); np1++;
      meanTop->SetPoint(npp, x[npp-1], fit->GetParameter(1)*1000.);
      meanTop->SetPointError(npp, 0., fit->GetParameter(2)*1000.); npp++;
    }else{
      mean2Top->SetPoint(np1, x[npp-1], -9999.);
      mean2Top->SetPointError(np1, 0., 0.); np1++;
      meanTop->SetPoint(npp, x[npp-1], -9999.);
      meanTop->SetPointError(npp, 0., 0.); npp++;
    }

    hisname = "residual_before_GBL_module_L"; hisname  += i;
    hisname += "t_halfmodule_axial_slot_sensor0";
    layer = "L"; layer+=i; layer+= "TASl";     
    his = (TH1D*) f->Get(hisname.Data());
    hisnameIni = "residual_before_GBL_module_L"; hisnameIni  += i;
    hisnameIni += "t_halfmodule_axial_slot_sensor0";
    hisIni = (TH1D*) f->Get(hisnameIni.Data());
    lo = hisIni->GetXaxis()->GetXmin();
    hi = hisIni->GetXaxis()->GetXmax();

    if(layer.Contains("1")){his->SetFillColor(kRed);}
    else if(layer.Contains("2")){his->SetFillColor(kOrange);}
    else if(layer.Contains("3")){his->SetFillColor(kYellow);}
    else if(layer.Contains("4")){his->SetFillColor(kGreen);}
    else if(layer.Contains("5")){his->SetFillColor(kCyan);}
    else if(layer.Contains("6")){his->SetFillColor(kBlue);}
    if(layer.Contains("A")){his->SetFillStyle(3007);}
    else if(layer.Contains("S")){his->SetFillStyle(3004);}
    ipad--;
    pd = "tp"; pd+=ipad;
    pad = (TPad*) cTop->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    low = his->GetMean()-w*his->GetRMS();
    up = his->GetMean()+w*his->GetRMS();    
    isFit = his->Fit("gaus","Q","",low,up);
    if(!isFit){
      TF1 *fit = his->GetFunction("gaus");
      
      cout << "sensor " << i << " axial slot mean :  " << his->GetMean()*1000. << " - RMS : " << his->GetRMS()*1000. << " (um) " << " " << his->GetEntries() << endl;
      cout << "sensor " << i << " axial slot mu :  " << fit->GetParameter(1)*1000. << " - sigma : " << fit->GetParameter(2)*1000. << " (um) " << endl;    
      outf << layer.Data() << " " 
	   << fit->GetParameter(1)*1000. << " " 
	   << fit->GetParError(1)*1000. << " " 
	   << fit->GetParameter(2)*1000. << " " 
	   << fit->GetParError(2)*1000. << " " 
	   << his->GetEntries() << endl;
      npp += 4;
      cout << np2 << " " << npp << " " << x[npp-1] << " " <<  fit->GetParameter(1)*1000. << endl;
      mean3Top->SetPoint(np2, x[npp-1], fit->GetParameter(1)*1000.);
      mean3Top->SetPointError(np2, 0., fit->GetParameter(2)*1000.); np2++;
      meanTop->SetPoint(npp, x[npp-1], fit->GetParameter(1)*1000.); 
      meanTop->SetPointError(npp, 0., fit->GetParameter(2)*1000.); npp++;
    }else{
      npp += 4;
      mean3Top->SetPoint(np2, x[npp-1], -9999.);
      mean3Top->SetPointError(np2, 0., 0.); np2++;
      meanTop->SetPoint(npp, x[npp-1], -9999.); 
      meanTop->SetPointError(npp, 0., 0.); npp++;
    }


    hisname = "residual_before_GBL_module_L"; hisname  += i;
    hisname += "t_halfmodule_stereo_slot_sensor0";
    layer = "L"; layer+=i; layer+= "TSSl"; 
    his = (TH1D*) f->Get(hisname.Data());
    hisnameIni = "residual_before_GBL_module_L"; hisnameIni  += i;
    hisnameIni += "t_halfmodule_stereo_slot_sensor0";
    hisIni = (TH1D*) f->Get(hisnameIni.Data());
    lo = hisIni->GetXaxis()->GetXmin();
    hi = hisIni->GetXaxis()->GetXmax();

    if(layer.Contains("1")){his->SetFillColor(kRed);}
    else if(layer.Contains("2")){his->SetFillColor(kOrange);}
    else if(layer.Contains("3")){his->SetFillColor(kYellow);}
    else if(layer.Contains("4")){his->SetFillColor(kGreen);}
    else if(layer.Contains("5")){his->SetFillColor(kCyan);}
    else if(layer.Contains("6")){his->SetFillColor(kBlue);}
    if(layer.Contains("A")){his->SetFillStyle(3007);}
    else if(layer.Contains("S")){his->SetFillStyle(3004);}
    //    cTop->cd(ic); ic+=1;
    ipad++; ipad++;
    pd = "tp"; pd+=ipad;
    pad = (TPad*) cTop->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    low = his->GetMean()-w*his->GetRMS();
    up = his->GetMean()+w*his->GetRMS();    
    isFit = his->Fit("gaus","Q","",low,up);
    if(!isFit){
      TF1* fit = his->GetFunction("gaus");

      cout << "sensor " << i << " stereo slot mean :  " << his->GetMean()*1000. << " - RMS : " << his->GetRMS()*1000. << " (um) " << " " << his->GetEntries() << endl;
      cout << "sensor " << i << " stereo slot mu :  " << fit->GetParameter(1)*1000. << " - sigma : " << fit->GetParameter(2)*1000. << " (um) " << endl;
      outf << layer.Data() << " " 
	   << fit->GetParameter(1)*1000. << " " 
	   << fit->GetParError(1)*1000. << " " 
	   << fit->GetParameter(2)*1000. << " " 
	   << fit->GetParError(2)*1000. << " " 
	   << his->GetEntries() << endl;
      cout << np2 << " " << npp << " " << x[npp-1] << " " <<  fit->GetParameter(1)*1000. << endl;
      mean3Top->SetPoint(np2, x[npp-1], fit->GetParameter(1)*1000.); 
      mean3Top->SetPointError(np2, 0., fit->GetParameter(2)*1000.); np2++;
      meanTop->SetPoint(npp, x[npp-1], fit->GetParameter(1)*1000.);
      meanTop->SetPointError(npp, 0., fit->GetParameter(2)*1000.); npp -= 5;
    }else{
      mean3Top->SetPoint(np2, x[npp-1], -9999.); 
      mean3Top->SetPointError(np2, 0., 0.); np2++;
      meanTop->SetPoint(npp, x[npp-1], -9999.);
      meanTop->SetPointError(npp, 0., 0.); npp -= 5;
    }
  }
  cout << endl;
  cout << "------------------------" << endl;
  cout << endl;
  cout << " BOTTOM " << endl;
  nrow = 13;
  space = 0.007;
  space1 = 0.03;
  y2 = 1./13*nrow-space1;
  y1 = 1./13*(--nrow)-space1;
  TPad *bp1 = new TPad("bp1","bp1",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  TPad *bp2 = new TPad("bp2","bp2",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  TPad *bp3 = new TPad("bp3","bp3",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  TPad *bp4 = new TPad("bp4","bp4",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  TPad *bp5 = new TPad("bp5","bp5",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  TPad *bp6 = new TPad("bp6","bp6",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  off = 0.12;
  y1 -= space1; y2 -= space1;
  space1 *= 2;
  TPad *bp7 = new TPad("bp7","bp7",0.+off,y1,0.33+off,y2);
  TPad *bp8 = new TPad("bp8","bp8",0.66-off,y1,1.-off,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  TPad *bp9 = new TPad("bp9","bp9",0.+off,y1,0.33+off,y2);
  TPad *bp10 = new TPad("bp10","bp10",0.66-off,y1,1.-off,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  TPad *bp11 = new TPad("bp11","bp11",0.+off,y1,0.33+off,y2);
  TPad *bp12 = new TPad("bp12","bp12",0.66-off,y1,1.-off,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  TPad *bp13 = new TPad("bp13","bp13",0.+off,y1,0.33+off,y2);
  TPad *bp14 = new TPad("bp14","bp14",0.66-off,y1,1.-off,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  TPad *bp15 = new TPad("bp15","bp15",0.+off,y1,0.33+off,y2);
  TPad *bp16 = new TPad("bp16","bp16",0.66-off,y1,1.-off,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  TPad *bp17 = new TPad("bp17","bp17",0.+off,y1,0.33+off,y2);
  TPad *bp18 = new TPad("bp18","bp18",0.66-off,y1,1.-off,y2);
  //  TLatex* hole  = new TLatex(0.5,0.5,"hole");
  //  TLatex* slot  = new TLatex(0.95,0.5,"slot");
  hole->SetTextColor(kCyan);
  slot->SetTextColor(kMagenta);

  cBot->cd();
  hole->Draw();
  slot->Draw();
  bp1->Draw();
  bp2->Draw();
  bp3->Draw();
  bp4->Draw();
  bp5->Draw();
  bp6->Draw();
  bp7->Draw();
  bp8->Draw();
  bp9->Draw();
  bp10->Draw();
  bp11->Draw();
  bp12->Draw();
  bp13->Draw();
  bp14->Draw();
  bp15->Draw();
  bp16->Draw();
  bp17->Draw();
  bp18->Draw();

  ic=0;
  ipad = 0;
  np = np1 = np2 = npp = 1;
  for(Int_t i=1; i<4; i++){
    TString hisname = "residual_before_GBL_module_L"; hisname  += i;
    hisname += "b_halfmodule_stereo_sensor0";
    TString layer = "L"; layer+=i; layer+= "BS"; 
    TH1D *his = (TH1D*) f->Get(hisname.Data());
    if(layer.Contains("1")){his->SetFillColor(kRed);}
    else if(layer.Contains("2")){his->SetFillColor(kOrange);}
    else if(layer.Contains("3")){his->SetFillColor(kYellow);}
    else if(layer.Contains("4")){his->SetFillColor(kGreen);}
    else if(layer.Contains("5")){his->SetFillColor(kCyan);}
    else if(layer.Contains("6")){his->SetFillColor(kBlue);}
    if(layer.Contains("A")){his->SetFillStyle(3007);}
    else if(layer.Contains("S")){his->SetFillStyle(3004);}
    //    cBot->cd(++ic);
    ipad++;
    TString pd = "bp"; pd+=ipad;
    TPad *pad = (TPad*) cBot->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    Double_t low = his->GetMean()-w*his->GetRMS();
    Double_t up = his->GetMean()+w*his->GetRMS();    
    Bool_t isFit = his->Fit("gaus","Q","",low,up);
    if(!isFit){
      TF1 *fit = his->GetFunction("gaus");
    
      cout << "sensor " << i << " stereo mean :  " << his->GetMean()*1000. << " - RMS : " << his->GetRMS()*1000. << " (um) " << " " << his->GetEntries() << endl;
      cout << "sensor " << i << " stereo mu :  " << fit->GetParameter(1)*1000. << " - sigma : " << fit->GetParameter(2)*1000. << " (um) " << endl;
      outf << layer.Data() << " " 
	   << fit->GetParameter(1)*1000. << " " 
	   << fit->GetParError(1)*1000. << " " 
	   << fit->GetParameter(2)*1000. << " " 
	   << fit->GetParError(2)*1000. << " " 
	   << his->GetEntries() << endl;
      mean1Bot->SetPoint(np, x[npp-1], fit->GetParameter(1)*1000.);
      mean1Bot->SetPointError(np, 0., fit->GetParameter(2)*1000.); np++;
      meanBot->SetPoint(npp, x[npp-1], fit->GetParameter(1)*1000.); 
      meanBot->SetPointError(npp, 0., fit->GetParameter(2)*1000.); npp++;
    }else{
      mean1Bot->SetPoint(np, x[npp-1], -9999.);
      mean1Bot->SetPointError(np, 0., 0.); np++;
      meanBot->SetPoint(npp, x[npp-1], -9999.); 
      meanBot->SetPointError(npp, 0., 0.); npp++;
    }
    hisname = "residual_before_GBL_module_L"; hisname  += i;
    hisname += "b_halfmodule_axial_sensor0";
    layer = "L"; layer+=i; layer+= "BA"; 
    his = (TH1D*) f->Get(hisname.Data());
    if(layer.Contains("1")){his->SetFillColor(kRed);}
    else if(layer.Contains("2")){his->SetFillColor(kOrange);}
    else if(layer.Contains("3")){his->SetFillColor(kYellow);}
    else if(layer.Contains("4")){his->SetFillColor(kGreen);}
    else if(layer.Contains("5")){his->SetFillColor(kCyan);}
    else if(layer.Contains("6")){his->SetFillColor(kBlue);}
    if(layer.Contains("A")){his->SetFillStyle(3007);}
    else if(layer.Contains("S")){his->SetFillStyle(3004);}
    //    cBot->cd(++ic);
    ipad++;
    pd = "bp"; pd+=ipad;
    pad = (TPad*) cBot->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    low = his->GetMean()-w*his->GetRMS();
    up = his->GetMean()+w*his->GetRMS();    
    isFit = his->Fit("gaus","Q","",low,up);
    if(!isFit){
      TF1* fit = his->GetFunction("gaus");

      cout << "sensor " << i << " axial mean :  " << his->GetMean()*1000. << " - RMS : " << his->GetRMS()*1000. << " (um) " << " " << his->GetEntries() << endl;
      cout << "sensor " << i << " axial mu :  " << fit->GetParameter(1)*1000. << " - sigma : " << fit->GetParameter(2)*1000. << " (um) " << endl;
      outf << layer.Data() << " " 
	   << fit->GetParameter(1)*1000. << " " 
	   << fit->GetParError(1)*1000. << " " 
	   << fit->GetParameter(2)*1000. << " " 
	   << fit->GetParError(2)*1000. << " " 
	   << his->GetEntries() << endl;
      mean1Bot->SetPoint(np, x[npp-1], fit->GetParameter(1)*1000.);
      mean1Bot->SetPointError(np, 0., fit->GetParameter(2)*1000.); np++;
      meanBot->SetPoint(npp, x[npp-1], fit->GetParameter(1)*1000.); 
      meanBot->SetPointError(npp, 0., fit->GetParameter(2)*1000.); npp++;
    }else{
      mean1Bot->SetPoint(np, x[npp-1], -9999.);
      mean1Bot->SetPointError(np, 0., 0.); np++;
      meanBot->SetPoint(npp, x[npp-1], -9999.); 
      meanBot->SetPointError(npp, 0., 0.); npp++;
    }
  }
  for(Int_t i=4; i<7; i++){
    TString hisname = "residual_before_GBL_module_L"; hisname  += i;
    hisname += "b_halfmodule_stereo_hole_sensor0";
    TString layer = "L"; layer+=i; layer+= "BSHo"; 
    TH1D *his = (TH1D*) f->Get(hisname.Data());
    if(layer.Contains("1")){his->SetFillColor(kRed);}
    else if(layer.Contains("2")){his->SetFillColor(kOrange);}
    else if(layer.Contains("3")){his->SetFillColor(kYellow);}
    else if(layer.Contains("4")){his->SetFillColor(kGreen);}
    else if(layer.Contains("5")){his->SetFillColor(kCyan);}
    else if(layer.Contains("6")){his->SetFillColor(kBlue);}
    if(layer.Contains("A")){his->SetFillStyle(3007);}
    else if(layer.Contains("S")){his->SetFillStyle(3004);}
    //    cBot->cd(++ic);
    ipad++; 
    TString pd = "bp"; pd+=ipad;
    TPad *pad = (TPad*) cBot->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    Double_t low = his->GetMean()-w*his->GetRMS();
    Double_t up = his->GetMean()+w*his->GetRMS();    
    Bool_t isFit = his->Fit("gaus","Q","",low,up);
    if(!isFit){
      TF1 *fit = his->GetFunction("gaus");
      cout << "sensor " << i << " stereo hole mean :  " << his->GetMean()*1000. << " - RMS : " << his->GetRMS()*1000. << " (um) " << " " << his->GetEntries() << endl;
      cout << "sensor " << i << " stereo hole mu :  " << fit->GetParameter(1)*1000. << " - sigma : " << fit->GetParameter(2)*1000. << " (um) " << endl;
      outf << layer.Data() << " " 
	   << fit->GetParameter(1)*1000. << " " 
	   << fit->GetParError(1)*1000. << " " 
	   << fit->GetParameter(2)*1000. << " " 
	   << fit->GetParError(2)*1000. << " " 
	   << his->GetEntries() << endl;
      //    mean1Top->SetPoint(np, x[npp-1], fit->GetParameter(1)*1000.);
      cout << np1 << " " << npp << " " << x[npp-1] << " " <<  fit->GetParameter(1)*1000. << endl;
      mean2Bot->SetPoint(np1, x[npp-1], fit->GetParameter(1)*1000.);
      mean2Bot->SetPointError(np1, 0., fit->GetParameter(2)*1000.); np1++;
      meanBot->SetPoint(npp, x[npp-1], fit->GetParameter(1)*1000.); 
      meanBot->SetPointError(npp, 0., fit->GetParameter(2)*1000.); npp++;
    }else{
      mean2Bot->SetPoint(np1, x[npp-1], -9999.);
      mean2Bot->SetPointError(np1, 0., 0.); np1++;
      meanBot->SetPoint(npp, x[npp-1], -9999.); 
      meanBot->SetPointError(npp, 0., 0.); npp++;
    }
    hisname = "residual_before_GBL_module_L"; hisname  += i;
    hisname += "b_halfmodule_axial_hole_sensor0";
    layer = "L"; layer+=i; layer+= "BAHo"; 
    his = (TH1D*) f->Get(hisname.Data());
    if(layer.Contains("1")){his->SetFillColor(kRed);}
    else if(layer.Contains("2")){his->SetFillColor(kOrange);}
    else if(layer.Contains("3")){his->SetFillColor(kYellow);}
    else if(layer.Contains("4")){his->SetFillColor(kGreen);}
    else if(layer.Contains("5")){his->SetFillColor(kCyan);}
    else if(layer.Contains("6")){his->SetFillColor(kBlue);}
    if(layer.Contains("A")){his->SetFillStyle(3007);}
    else if(layer.Contains("S")){his->SetFillStyle(3004);}
    //    cBot->cd(++ic);
    ipad++; ipad++;
    pd = "bp"; pd+=ipad;
    pad = (TPad*) cBot->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    low = his->GetMean()-w*his->GetRMS();
    up = his->GetMean()+w*his->GetRMS();    
    isFit = his->Fit("gaus","Q","",low,up);
    if(!isFit){
      TF1* fit = his->GetFunction("gaus");

      cout << "sensor " << i << " axial hole mean :  " << his->GetMean()*1000. << " - RMS : " << his->GetRMS()*1000. << " (um) " << " " << his->GetEntries() << endl;
      cout << "sensor " << i << " axial hole mu :  " << fit->GetParameter(1)*1000. << " - sigma : " << fit->GetParameter(2)*1000. << " (um) " << endl;
      outf << layer.Data() << " " 
	   << fit->GetParameter(1)*1000. << " " 
	   << fit->GetParError(1)*1000. << " " 
	   << fit->GetParameter(2)*1000. << " " 
	   << fit->GetParError(2)*1000. << " " 
	   << his->GetEntries() << endl;
      cout << np1 << " " << npp << " " << x[npp-1] << " " <<  fit->GetParameter(1)*1000. << endl;
      mean2Bot->SetPoint(np1, x[npp-1], fit->GetParameter(1)*1000.);
      mean2Bot->SetPointError(np1, 0., fit->GetParameter(2)*1000.); np1++;
      meanBot->SetPoint(npp, x[npp-1], fit->GetParameter(1)*1000.); 
      meanBot->SetPointError(npp, 0., fit->GetParameter(2)*1000.); npp++;
    }else{
      mean2Bot->SetPoint(np1, x[npp-1], -9999.);
      mean2Bot->SetPointError(np1, 0., 0.); np1++;
      meanBot->SetPoint(npp, x[npp-1], -9999.); 
      meanBot->SetPointError(npp, 0., 0.); npp++;
    }
    hisname = "residual_before_GBL_module_L"; hisname  += i;
    hisname += "b_halfmodule_stereo_slot_sensor0";
    layer = "L"; layer+=i; layer+= "BSSl"; 
    his = (TH1D*) f->Get(hisname.Data());
    if(layer.Contains("1")){his->SetFillColor(kRed);}
    else if(layer.Contains("2")){his->SetFillColor(kOrange);}
    else if(layer.Contains("3")){his->SetFillColor(kYellow);}
    else if(layer.Contains("4")){his->SetFillColor(kGreen);}
    else if(layer.Contains("5")){his->SetFillColor(kCyan);}
    else if(layer.Contains("6")){his->SetFillColor(kBlue);}
    if(layer.Contains("A")){his->SetFillStyle(3007);}
    else if(layer.Contains("S")){his->SetFillStyle(3004);}
    //    cBot->cd(++ic);
    ipad--;
    pd = "bp"; pd+=ipad;
    pad = (TPad*) cBot->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    low = his->GetMean()-w*his->GetRMS();
    up = his->GetMean()+w*his->GetRMS();    
    isFit = his->Fit("gaus","Q","",low,up);
    if(!isFit){
      TF1* fit = his->GetFunction("gaus");

      cout << "sensor " << i << " stereo slot mean :  " << his->GetMean()*1000. << " - RMS : " << his->GetRMS()*1000. << " (um) " << " " << his->GetEntries() << endl;
      cout << "sensor " << i << " stereo slot mu :  " << fit->GetParameter(1)*1000. << " - sigma : " << fit->GetParameter(2)*1000. << " (um) " << endl;
      outf << layer.Data() << " " 
	   << fit->GetParameter(1)*1000. << " " 
	   << fit->GetParError(1)*1000. << " " 
	   << fit->GetParameter(2)*1000. << " " 
	   << fit->GetParError(2)*1000. << " " 
	   << his->GetEntries() << endl;
      npp += 4;
      cout << np2 << " " << npp << " " << x[npp-1] << " " <<  fit->GetParameter(1)*1000. << endl;
      mean3Bot->SetPoint(np2, x[npp-1], fit->GetParameter(1)*1000.);
      mean3Bot->SetPointError(np2, 0., fit->GetParameter(2)*1000.); np2++;
      meanBot->SetPoint(npp, x[npp-1], fit->GetParameter(1)*1000.); 
      meanBot->SetPointError(npp, 0., fit->GetParameter(2)*1000.); npp++;
    }else{
      mean3Bot->SetPoint(np2, x[npp-1], -9999.);
      mean3Bot->SetPointError(np2, 0., 0.); np2++;
      meanBot->SetPoint(npp, x[npp-1], -9999.); 
      meanBot->SetPointError(npp, 0., 0.); npp++;
    }
    hisname = "residual_before_GBL_module_L"; hisname  += i;
    hisname += "b_halfmodule_axial_slot_sensor0";
    layer = "L"; layer+=i; layer+= "BASl"; 
    his = (TH1D*) f->Get(hisname.Data());
    if(layer.Contains("1")){his->SetFillColor(kRed);}
    else if(layer.Contains("2")){his->SetFillColor(kOrange);}
    else if(layer.Contains("3")){his->SetFillColor(kYellow);}
    else if(layer.Contains("4")){his->SetFillColor(kGreen);}
    else if(layer.Contains("5")){his->SetFillColor(kCyan);}
    else if(layer.Contains("6")){his->SetFillColor(kBlue);}
    if(layer.Contains("A")){his->SetFillStyle(3007);}
    else if(layer.Contains("S")){his->SetFillStyle(3004);}
    //    cBot->cd(++ic);
    ipad++; ipad++;
    pd = "bp"; pd+=ipad;
    pad = (TPad*) cBot->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    low = his->GetMean()-w*his->GetRMS();
    up = his->GetMean()+w*his->GetRMS();
    isFit = his->Fit("gaus","Q","",low,up);    
    if(!isFit){
      TF1* fit = his->GetFunction("gaus");
      
      cout << "sensor " << i << " axial slot mean :  " << his->GetMean()*1000. << " - RMS : " << his->GetRMS()*1000. << " (um) " << " " << his->GetEntries() << endl;
      cout << "sensor " << i << " axial slot mu :  " << fit->GetParameter(1)*1000. << " - sigma : " << fit->GetParameter(2)*1000. << " (um) " << endl;
      outf << layer.Data() << " " 
	   << fit->GetParameter(1)*1000. << " " 
	   << fit->GetParError(1)*1000. << " " 
	   << fit->GetParameter(2)*1000. << " " 
	   << fit->GetParError(2)*1000. << " " 
	   << his->GetEntries() << endl;
      cout << np2 << " " << npp << " " << x[npp-1] << " " <<  fit->GetParameter(1)*1000. << endl;
      mean3Bot->SetPoint(np2, x[npp-1], fit->GetParameter(1)*1000.);
      mean3Bot->SetPointError(np2, 0., fit->GetParameter(2)*1000.); np2++;
      meanBot->SetPoint(npp, x[npp-1], fit->GetParameter(1)*1000.); 
      meanBot->SetPointError(npp, 0., fit->GetParameter(2)*1000.); npp -=5;
    }else{
      mean3Bot->SetPoint(np2, x[npp-1], -9999.);
      mean3Bot->SetPointError(np2, 0., 0.); np2++;
      meanBot->SetPoint(npp, x[npp-1], -9999.); 
      meanBot->SetPointError(npp, 0., 0.); npp -=5;
    }
  }


  TCanvas *cmeanAll = new TCanvas("cmeanAll","Mean Residuals, TOP&BOT", 800, 1000);
  cmeanAll->Divide(1,2);
  cmeanAll->cd(1);
  mean1Top->SetMarkerStyle(20);
  mean2Top->SetMarkerStyle(20);
  mean3Top->SetMarkerStyle(20);
  mean1Top->SetMarkerColor(kBlack);
  mean2Top->SetMarkerColor(kCyan);
  mean3Top->SetMarkerColor(kMagenta);
  meanTop->SetMarkerStyle(20);
  meanTop->SetMarkerColor(kBlue);

  TMultiGraph *mgTop = new TMultiGraph();
  TLegend *topLeg = new TLegend(0.1,0.7,0.3,0.9);
  TLine *zero = new TLine(0.5, 0., 6.5, 0.);
  zero->SetLineStyle(2);
  mgTop->Add(mean1Top);
  mgTop->Add(mean2Top);
  mgTop->Add(mean3Top);
  topLeg->AddEntry(mean1Top,"1-2-3","p");
  topLeg->AddEntry(mean2Top,"4-5-6 hole","p");
  topLeg->AddEntry(mean3Top, "4-5-6 slot","p");

  mgTop->Draw("AP");
  mgTop->GetXaxis()->SetRangeUser(0.5,6.5);
  //  mgTop->GetYaxis()->SetRangeUser(-12,12);
  mgTop->GetYaxis()->SetRangeUser(-500,500);
  mgTop->GetXaxis()->SetTitle("layer");
  mgTop->GetYaxis()->SetTitle("residual [#mum]");
  mgTop->Draw("AP");
  cmeanAll->Update();
  topLeg->Draw("same");
  zero->Draw("same");

  mean1Bot->SetMarkerStyle(20);
  mean2Bot->SetMarkerStyle(20);
  mean3Bot->SetMarkerStyle(20);
  mean1Bot->SetMarkerColor(kBlack);
  mean2Bot->SetMarkerColor(kCyan);
  mean3Bot->SetMarkerColor(kMagenta);
  meanBot->SetMarkerStyle(20);
  meanBot->SetMarkerColor(kBlue);

  TMultiGraph *mgBot = new TMultiGraph();
  TLegend *botLeg = new TLegend(0.1,0.7,0.3,0.9);
  botLeg->AddEntry(mean1Bot,"1-2-3", "p");
  botLeg->AddEntry(mean2Bot,"4-5-6 hole","p");
  botLeg->AddEntry(mean3Bot, "4-5-6 slot","p");
  //  mgBot->Add(meanBot);
  mgBot->Add(mean1Bot);
  mgBot->Add(mean2Bot);
  mgBot->Add(mean3Bot);
  cmeanAll->cd(2);
  mgBot->Draw("AP");
  mgBot->GetXaxis()->SetRangeUser(0.5,6.5);
  //  mgBot->GetYaxis()->SetRangeUser(-12,12);
  mgBot->GetYaxis()->SetRangeUser(-500,500);
  mgBot->GetXaxis()->SetTitle("layer");
  mgBot->GetYaxis()->SetTitle("residual [#mum]");
  mgBot->Draw("AP");
  cmeanAll->Update();
  botLeg->Draw("same");
  zero->Draw("same");

  outf.close();
  cTop->SaveAs(topName.Data());
  cBot->SaveAs(botName.Data());
  TString mean = "mean_"; mean += outn.Data(); mean += "_TopBot_INI.gif";
  cmeanAll->SaveAs(mean.Data());
				
  TFile *g = new TFile("plotResidualsINI__graphs.root","RECREATE");
  g->cd();
  mgBot->SetName("mgBot");
  mgTop->SetName("mgTop");
  mgTop->Write();
  mgBot->Write();
  meanBot->SetName("meanBot");
  meanTop->SetName("meanTop");
  meanTop->Write();
  meanBot->Write();

  g->Close();


}
