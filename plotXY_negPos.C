#include <TString.h>
#include <TH1D.h>
#include <TF1.h>
#include <Riostream.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TFile.h>
#include <TH2D.h>

void plotXY_negPos(const char* fname){

  gStyle->SetOptStat(0);
  Float_t w = 1.2; // number of RMS for gaussian fit
  TString filename = fname;
  cout << filename.Data() << endl;
  TCanvas *cTop = new TCanvas("cTop","Residuals in lab frame, TOP", 800, 1000);
  TCanvas *cBot = new TCanvas("cBot","Residuals in lab frame, BOTTOM",800, 1000);
  //  cTop->Divide(3,12);
  //  cBot->Divide(3,12);
  cTop->SetFillColor(kBlue-10); cTop->SetFillStyle(3001);
  cBot->SetFillColor(kMagenta-10); cBot->SetFillStyle(3001);
  Int_t ic=0;
  TFile *f = new TFile(filename.Data());
  // extract string 
  Int_t idx2 = filename.Index("/");
  Int_t idx1 = filename.Index("_");
  TString outn = filename(idx1+1,idx2-(idx1+1));
  TString outname ="predXY_NEGPOS_"; outname += outn.Data(); outname += ".txt";
  TString topName ="predXY_NEGPOS_"; topName += outn.Data(); topName += "_topO.gif";
  TString botName ="predXY_NEGPOS_"; botName += outn.Data(); botName += "_botO.gif";
  ofstream outf(outname.Data());
  // top
  cout << " TOP " << endl;
  Int_t nrow = 13;
  Double_t space = 0.007;
  Double_t space1 = 0.03;
  Double_t y2 = 1./13*nrow-space1;
  Double_t y1 = 1./13*(--nrow)-space1;
  TPad *tp1 = new TPad("tp1","tp1",0.33,y1,0.66,y2);
  y2 = y1; y1 = 1./13.*(--nrow)-space1;
  TPad *tp2 = new TPad("tp2","tp2",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  TPad *tp3 = new TPad("tp3","tp3",0.33,y1,0.66,y2);
  y2 = y1; y1 = 1./13.*(--nrow)-space1;
  TPad *tp4 = new TPad("tp4","tp4",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  TPad *tp5 = new TPad("tp5","tp5",0.33,y1,0.66,y2);
  y2 = y1; y1 = 1./13.*(--nrow)-space1;
  TPad *tp6 = new TPad("tp6","tp6",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  Double_t off = 0.12;
  off = 0.165;
  y1 -= space1; y2 -= space1;
  space1 *= 2;
  TPad *tp7 = new TPad("tp7","tp7",0.+off,y1,0.33+off,y2);
  TPad *tp8 = new TPad("tp8","tp8",0.66-off,y1,1.-off,y2);
  y2 = y1; y1 = 1./13.*(--nrow)-space1;
  TPad *tp9 = new TPad("tp9","tp9",0.+off,y1,0.33+off,y2);
  TPad *tp10 = new TPad("tp10","tp10",0.66-off,y1,1.-off,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  TPad *tp11 = new TPad("tp11","tp11",0.+off,y1,0.33+off,y2);
  TPad *tp12 = new TPad("tp12","tp12",0.66-off,y1,1.-off,y2);
  y2 = y1; y1 = 1./13.*(--nrow)-space1;
  TPad *tp13 = new TPad("tp13","tp13",0.+off,y1,0.33+off,y2);
  TPad *tp14 = new TPad("tp14","tp14",0.66-off,y1,1.-off,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  TPad *tp15 = new TPad("tp15","tp15",0.+off,y1,0.33+off,y2);
  TPad *tp16 = new TPad("tp16","tp16",0.66-off,y1,1.-off,y2);
  y2 = y1; y1 = 1./13.*(--nrow)-space1;
  TPad *tp17 = new TPad("tp17","tp17",0.+off,y1,0.33+off,y2);
  TPad *tp18 = new TPad("tp18","tp18",0.66-off,y1,1.-off,y2);


  cTop->cd();
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
    TString hisname = "h_xy_neg_module_L"; hisname  += i;
    TString hisname2 = "h_xy_pos_module_L"; hisname2  += i;
    hisname2 += "t_halfmodule_axial_sensor0";
    hisname += "t_halfmodule_axial_sensor0";
    TString layer = "L"; layer+=i; layer+= "TA"; 
    TH2D *his2 = (TH2D*) f->Get(hisname.Data());
    TH2D *his3 = (TH2D*) f->Get(hisname2.Data());
    TH1D *his;
    if(his2){
      his = (TH1D*)his2->ProjectionY();
    }else{
      his = 0;
    }
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
    Double_t low, up;
    his3->Draw("");
    his2->Draw("same");
    if(his){
      low = his->GetMean()-w*his->GetRMS();
      up = his->GetMean()+w*his->GetRMS();    
      his->Fit("gaus","Q0","",low,up);
      his2->SetMarkerColor(kMagenta);
      his3->SetMarkerColor(kAzure+10);
      his3->SetStats(kFALSE); his2->SetStats(kFALSE);
      TF1 *fit = his->GetFunction("gaus");
    }
    // cout << "sensor " << i << " axial mean :  " << his->GetMean()*1000. << " - RMS : " << his->GetRMS()*1000. << " (um) " << " " << his->GetEntries() << endl;
    // cout << "sensor " << i << " axial mu :  " << fit->GetParameter(1)*1000. << " - sigma : " << fit->GetParameter(2)*1000. << " (um) " << endl;
    // outf << layer.Data() << " " << fit->GetParameter(1)*1000. << " " << fit->GetParameter(2)*1000. << " " << his->GetEntries() << endl;

    hisname = "h_xy_neg_module_L"; hisname  += i;
    hisname += "t_halfmodule_stereo_sensor0";
    hisname2 = "h_xy_pos_module_L"; hisname2  += i;
    hisname2 += "t_halfmodule_stereo_sensor0";
    layer = "L"; layer+=i; layer+= "TS"; 
    his2 = (TH2D*) f->Get(hisname.Data());
    his3 = (TH2D*) f->Get(hisname2.Data());
    if(his2){
      his = (TH1D*)his2->ProjectionY();
      if(layer.Contains("1")){his->SetFillColor(kRed);}
      else if(layer.Contains("2")){his->SetFillColor(kOrange);}
      else if(layer.Contains("3")){his->SetFillColor(kYellow);}
      else if(layer.Contains("4")){his->SetFillColor(kGreen);}
      else if(layer.Contains("5")){his->SetFillColor(kCyan);}
      else if(layer.Contains("6")){his->SetFillColor(kBlue);}
      if(layer.Contains("A")){his->SetFillStyle(3007);}
      else if(layer.Contains("S")){his->SetFillStyle(3004);}
    }else{
      his = 0;
    }
    //    cTop->cd(ic); ic += 3;
    ipad++;
    pd = "tp"; pd+=ipad;
    pad = (TPad*) cTop->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    if(his){
      low = his->GetMean()-w*his->GetRMS();
      up = his->GetMean()+w*his->GetRMS();    
      his->Fit("gaus","Q","",low,up); 
      his2->SetMarkerColor(kMagenta);
      his3->SetMarkerColor(kAzure+10);
      his3->SetStats(kFALSE); his2->SetStats(kFALSE);
      his3->Draw("");
      his2->Draw("same");
      TF1 *fit = his->GetFunction("gaus");
    }
    // cout << "sensor " << i << " stereo mean :  " << his->GetMean()*1000. << " - RMS : " << his->GetRMS()*1000. << " (um) " << " " << his->GetEntries() << endl;
    // cout << "sensor " << i << " stereo mu :  " << fit->GetParameter(1)*1000. << " - sigma : " << fit->GetParameter(2)*1000. << " (um) " << endl;
    // outf << layer.Data() << " " << fit->GetParameter(1)*1000. << " " << fit->GetParameter(2)*1000. << " " << his->GetEntries() << endl;

  }
  //  ic = 19;
  for(Int_t i=4; i<7; i++){
    TString hisname = "h_xy_neg_module_L"; hisname  += i;
    TString hisname2 = hisname;
    hisname += "t_halfmodule_axial_hole_sensor0";
    hisname2 += "t_halfmodule_axial_slot_sensor0";
    TString hisname3 = "h_xy_pos_module_L"; hisname3  += i;
    hisname3 += "t_halfmodule_axial_hole_sensor0";
    TH2D *hisOther = (TH2D*) f->Get(hisname2.Data());
    Double_t norma;
    if(hisOther){
      norma=hisOther->GetMaximum();
    }else{
      norma = 1.;
    }
    TString layer = "L"; layer+=i; layer+= "TAHo"; 
    TH2D *his2 = (TH2D*) f->Get(hisname.Data());
    TH2D *his3 = (TH2D*) f->Get(hisname3.Data());
    if(his2) his2->SetMaximum(norma);
    TH1D *his;
    if(his2){
      his = (TH1D*)his2->ProjectionY();
      if(layer.Contains("1")){his->SetFillColor(kRed);}
      else if(layer.Contains("2")){his->SetFillColor(kOrange);}
      else if(layer.Contains("3")){his->SetFillColor(kYellow);}
      else if(layer.Contains("4")){his->SetFillColor(kGreen);}
      else if(layer.Contains("5")){his->SetFillColor(kCyan);}
      else if(layer.Contains("6")){his->SetFillColor(kBlue);}
      if(layer.Contains("A")){his->SetFillStyle(3007);}
      else if(layer.Contains("S")){his->SetFillStyle(3004);}
    }else{
      his = 0;
    }
    //    cTop->cd(ic); ic+=3;
    ipad++;
    TString pd = "tp"; pd+=ipad;
    TPad *pad = (TPad*) cTop->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    Double_t low, up;
    his3->SetMarkerColor(kAzure+10);
    his3->Draw("");
    //    cout << i << " " << his3 << endl;
    if(his){
      his2->SetMarkerColor(kMagenta);
      low = his->GetMean()-w*his->GetRMS();
      up = his->GetMean()+w*his->GetRMS();
      his2->Draw("same");    
      his->Fit("gaus","Q0","",low,up); 
      his3->SetStats(kFALSE); 
      his2->SetStats(kFALSE);
      TF1 *fit = his->GetFunction("gaus");
    }
    // cout << "sensor " << i << " axial hole mean :  " << his->GetMean()*1000. << " - RMS : " << his->GetRMS()*1000. << " (um) " << " " << his->GetEntries() << endl;
    // cout << "sensor " << i << " axial hole mu :  " << fit->GetParameter(1)*1000. << " - sigma : " << fit->GetParameter(2)*1000. << " (um) " << endl;
    // outf << layer.Data() << " " << fit->GetParameter(1)*1000. << " " << fit->GetParameter(2)*1000. << " " << his->GetEntries() << endl;

    //    cout << " xxxxxxxxxxxxxxxxx " << ipad << " " << his->GetName() << endl;

    hisname = "h_xy_neg_module_L"; hisname  += i;
    hisname += "t_halfmodule_stereo_hole_sensor0";
    hisname3 = "h_xy_pos_module_L"; hisname3  += i;
    hisname3 += "t_halfmodule_stereo_hole_sensor0";
    his3 = (TH2D*) f->Get(hisname3.Data());
    layer = "L"; layer+=i; layer+= "TSHo"; 
    his2 = (TH2D*) f->Get(hisname.Data());
    if(his2){
      his = (TH1D*)his2->ProjectionY();
      if(layer.Contains("1")){his->SetFillColor(kRed);}
      else if(layer.Contains("2")){his->SetFillColor(kOrange);}
      else if(layer.Contains("3")){his->SetFillColor(kYellow);}
      else if(layer.Contains("4")){his->SetFillColor(kGreen);}
      else if(layer.Contains("5")){his->SetFillColor(kCyan);}
      else if(layer.Contains("6")){his->SetFillColor(kBlue);}
      if(layer.Contains("A")){his->SetFillStyle(3007);}
      else if(layer.Contains("S")){his->SetFillStyle(3004);}
    }else{
      his = 0;
    }
    //    cTop->cd(ic); ic-=1;
    ipad++; ipad++;
    pd = "tp"; pd+=ipad;
    pad = (TPad*) cTop->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    his3->SetMarkerColor(kAzure+10);
    his3->Draw("");
    if(his){
      low = his->GetMean()-w*his->GetRMS();
      up = his->GetMean()+w*his->GetRMS();    
      his->Fit("gaus","Q0","",low,up); 
      his2->SetMarkerColor(kMagenta);
      //      his3->SetStats(kFALSE); his2->SetStats(kFALSE);
      his2->Draw("same");
      TF1 *fit = his->GetFunction("gaus");
    }
    // cout << "sensor " << i << " stereo hole mean :  " << his->GetMean()*1000. << " - RMS : " << his->GetRMS()*1000. << " (um) " << " " << his->GetEntries() << endl;
    // cout << "sensor " << i << " stereo hole mu :  " << fit->GetParameter(1)*1000. << " - sigma : " << fit->GetParameter(2)*1000. << " (um) " << endl;
    // outf << layer.Data() << " " << fit->GetParameter(1)*1000. << " " << fit->GetParameter(2)*1000. << " " << his->GetEntries() << endl;

    //    cout << " xxxxxxxxxxxxxxxxx " << ipad << " " << his->GetName() << endl;

    hisname = "h_xy_neg_module_L"; hisname  += i;
    hisname += "t_halfmodule_axial_slot_sensor0";
    hisname3 = "h_xy_pos_module_L"; hisname3  += i;
    hisname3 += "t_halfmodule_axial_slot_sensor0";
    his3 = (TH2D*) f->Get(hisname3.Data());
    layer = "L"; layer+=i; layer+= "TASl";
    his2 = (TH2D*) f->Get(hisname.Data());
    if(his2){
      his = (TH1D*)his2->ProjectionY();   
      if(layer.Contains("1")){his->SetFillColor(kRed);}
      else if(layer.Contains("2")){his->SetFillColor(kOrange);}
      else if(layer.Contains("3")){his->SetFillColor(kYellow);}
      else if(layer.Contains("4")){his->SetFillColor(kGreen);}
      else if(layer.Contains("5")){his->SetFillColor(kCyan);}
      else if(layer.Contains("6")){his->SetFillColor(kBlue);}
      if(layer.Contains("A")){his->SetFillStyle(3007);}
      else if(layer.Contains("S")){his->SetFillStyle(3004);}
    }else{
      his = 0;
    }
    //    cTop->cd(ic); ic+=3;
    ipad--;
    pd = "tp"; pd+=ipad;
    pad = (TPad*) cTop->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    his3->SetMarkerColor(kAzure+10);
    his3->Draw("");
    if(his){
      low = his->GetMean()-w*his->GetRMS();
      up = his->GetMean()+w*his->GetRMS();    
      his->Fit("gaus","Q0","",low,up); 
      his2->SetMarkerColor(kMagenta);
      his3->SetStats(kFALSE); his2->SetStats(kFALSE);
      if(his3){
	if(his2) his2->Draw("same");
      }
      //    TF1 *fit = his->GetFunction("gaus");
    }
    // cout << "sensor " << i << " axial slot mean :  " << his->GetMean()*1000. << " - RMS : " << his->GetRMS()*1000. << " (um) " << " " << his->GetEntries() << endl;
    // cout << "sensor " << i << " axial slot mu :  " << fit->GetParameter(1)*1000. << " - sigma : " << fit->GetParameter(2)*1000. << " (um) " << endl;
    // outf << layer.Data() << " " << fit->GetParameter(1)*1000. << " " << fit->GetParameter(2)*1000. << " " << his->GetEntries() << endl;

    // cout << " ----------------here " << endl;
    //    cout << " xxxxxxxxxxxxxxxxx " << ipad << " " << his->GetName() << endl;

    hisname = "h_xy_neg_module_L"; hisname  += i;
    hisname += "t_halfmodule_stereo_slot_sensor0";
    hisname3 = "h_xy_pos_module_L"; hisname3  += i;
    hisname3 += "t_halfmodule_stereo_slot_sensor0";
    his3 = (TH2D*) f->Get(hisname3.Data());
    layer = "L"; layer+=i; layer+= "TSSl"; 
    his2 = (TH2D*) f->Get(hisname.Data());
    if(his2){
      his = (TH1D*)his2->ProjectionY();    
      if(layer.Contains("1")){his->SetFillColor(kRed);}
      else if(layer.Contains("2")){his->SetFillColor(kOrange);}
      else if(layer.Contains("3")){his->SetFillColor(kYellow);}
      else if(layer.Contains("4")){his->SetFillColor(kGreen);}
      else if(layer.Contains("5")){his->SetFillColor(kCyan);}
      else if(layer.Contains("6")){his->SetFillColor(kBlue);}
      if(layer.Contains("A")){his->SetFillStyle(3007);}
      else if(layer.Contains("S")){his->SetFillStyle(3004);}
    }else{
      his = 0;
    }
    //    cTop->cd(ic); ic+=1;
    ipad++; ipad++;
    pd = "tp"; pd+=ipad;
    pad = (TPad*) cTop->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    //    cout << i << " " << his3 << " " << endl;
    if(his){
      low = his->GetMean()-w*his->GetRMS();
      up = his->GetMean()+w*his->GetRMS();    
      his->Fit("gaus","Q0","",low,up); 
      his2->SetMarkerColor(kMagenta);
      his3->SetMarkerColor(kAzure+10);
      his3->SetStats(kFALSE); his2->SetStats(kFALSE);
      his3->Draw("");
      his2->Draw("same");
      //    TF1 *fit = his->GetFunction("gaus");
    }
    // cout << "sensor " << i << " stereo slot mean :  " << his->GetMean()*1000. << " - RMS : " << his->GetRMS()*1000. << " (um) " << " " << his->GetEntries() << endl;
    // cout << "sensor " << i << " stereo slot mu :  " << fit->GetParameter(1)*1000. << " - sigma : " << fit->GetParameter(2)*1000. << " (um) " << endl;
    // outf << layer.Data() << " " << fit->GetParameter(1)*1000. << " " << fit->GetParameter(2)*1000. << " " << his->GetEntries()  << endl;

    //    cout << " xxxxxxxxxxxxxxxxx " << ipad << " " << his->GetName() << endl;
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
  y2 = y1; y1 = 1./13.*(--nrow)-space1;
  TPad *bp2 = new TPad("bp2","bp2",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  TPad *bp3 = new TPad("bp3","bp3",0.33,y1,0.66,y2);
  y2 = y1; y1 = 1./13.*(--nrow)-space1;
  TPad *bp4 = new TPad("bp4","bp4",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  TPad *bp5 = new TPad("bp5","bp5",0.33,y1,0.66,y2);
  y2 = y1; y1 = 1./13.*(--nrow)-space1;
  TPad *bp6 = new TPad("bp6","bp6",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  off = 0.165;
  y1 -= space1; y2 -= space1;
  space1 *= 2;
  TPad *bp7 = new TPad("bp7","bp7",0.+off,y1,0.33+off,y2);
  TPad *bp8 = new TPad("bp8","bp8",0.66-off,y1,1.-off,y2);
  y2 = y1; y1 = 1./13.*(--nrow)-space1;
  TPad *bp9 = new TPad("bp9","bp9",0.+off,y1,0.33+off,y2);
  TPad *bp10 = new TPad("bp10","bp10",0.66-off,y1,1.-off,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  TPad *bp11 = new TPad("bp11","bp11",0.+off,y1,0.33+off,y2);
  TPad *bp12 = new TPad("bp12","bp12",0.66-off,y1,1.-off,y2);
  y2 = y1; y1 = 1./13.*(--nrow)-space1;
  TPad *bp13 = new TPad("bp13","bp13",0.+off,y1,0.33+off,y2);
  TPad *bp14 = new TPad("bp14","bp14",0.66-off,y1,1.-off,y2);
  y2 = y1-space; y1 = 1./13.*(--nrow)-space1;
  TPad *bp15 = new TPad("bp15","bp15",0.+off,y1,0.33+off,y2);
  TPad *bp16 = new TPad("bp16","bp16",0.66-off,y1,1.-off,y2);
  y2 = y1; y1 = 1./13.*(--nrow)-space1;
  TPad *bp17 = new TPad("bp17","bp17",0.+off,y1,0.33+off,y2);
  TPad *bp18 = new TPad("bp18","bp18",0.66-off,y1,1.-off,y2);

  cBot->cd();
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
  for(Int_t i=1; i<4; i++){
    TString hisname = "h_xy_neg_module_L"; hisname  += i;
    hisname += "b_halfmodule_stereo_sensor0";
    TString hisname3 = "h_xy_pos_module_L"; hisname3  += i;
    hisname3 += "b_halfmodule_stereo_sensor0";
    TH2D *his3 = (TH2D*) f->Get(hisname3.Data());
    TString layer = "L"; layer+=i; layer+= "BS"; 
    TH2D *his2 = (TH2D*) f->Get(hisname.Data());
    TH1D *his;
    // cout << i << " " << his2 << endl;
    if(his2){
      TH1D *his = (TH1D*)his2->ProjectionY();
      if(layer.Contains("1")){his->SetFillColor(kRed);}
      else if(layer.Contains("2")){his->SetFillColor(kOrange);}
      else if(layer.Contains("3")){his->SetFillColor(kYellow);}
      else if(layer.Contains("4")){his->SetFillColor(kGreen);}
      else if(layer.Contains("5")){his->SetFillColor(kCyan);}
      else if(layer.Contains("6")){his->SetFillColor(kBlue);}
      if(layer.Contains("A")){his->SetFillStyle(3007);}
      else if(layer.Contains("S")){his->SetFillStyle(3004);}
    }else{
      his = 0;
    }     
    
    //    cBot->cd(++ic);
    ipad++;
    TString pd = "bp"; pd+=ipad;
    TPad *pad = (TPad*) cBot->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    his3->Draw(); 
    his3->SetMarkerColor(kAzure+10);      
    his3->SetStats(kFALSE); 
    if(his2) his2->Draw("same");
    if(his){
      //low = his->GetMean()-w*his->GetRMS();
      //up = his->GetMean()+w*his->GetRMS();    
      //    his->Fit("gaus","Q0","",low,up);
      his2->SetMarkerColor(kMagenta);
      his2->SetStats(kFALSE);
      //    TF1 *fit = his->GetFunction("gaus");
    }
      // cout << "sensor " << i << " stereo mean :  " << his->GetMean()*1000. << " - RMS : " << his->GetRMS()*1000. << " (um) " << " " << his->GetEntries() << endl;
    // cout << "sensor " << i << " stereo mu :  " << fit->GetParameter(1)*1000. << " - sigma : " << fit->GetParameter(2)*1000. << " (um) " << endl;
    // outf << layer.Data() << " " << fit->GetParameter(1)*1000. << " " << fit->GetParameter(2)*1000. << " " << his->GetEntries()  << endl;

    hisname = "h_xy_neg_module_L"; hisname  += i;
    hisname += "b_halfmodule_axial_sensor0";
    hisname3 = "h_xy_pos_module_L"; hisname3  += i;
    hisname3 += "b_halfmodule_axial_sensor0";
    his3 = (TH2D*) f->Get(hisname3.Data());
    layer = "L"; layer+=i; layer+= "BA"; 
    his2 = (TH2D*) f->Get(hisname.Data());
    if(his2){
      his = (TH1D*)his2->ProjectionY();
      if(layer.Contains("1")){his->SetFillColor(kRed);}
      else if(layer.Contains("2")){his->SetFillColor(kOrange);}
      else if(layer.Contains("3")){his->SetFillColor(kYellow);}
      else if(layer.Contains("4")){his->SetFillColor(kGreen);}
      else if(layer.Contains("5")){his->SetFillColor(kCyan);}
      else if(layer.Contains("6")){his->SetFillColor(kBlue);}
      if(layer.Contains("A")){his->SetFillStyle(3007);}
      else if(layer.Contains("S")){his->SetFillStyle(3004);}
    }else{
      his = 0;
    }
    
    //    cBot->cd(++ic);
    ipad++;
    pd = "bp"; pd+=ipad;
    pad = (TPad*) cBot->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    if(his){
      //low = his->GetMean()-w*his->GetRMS();
      //up = his->GetMean()+w*his->GetRMS();    
      //    his->Fit("gaus","Q0","",low,up);
      his2->SetMarkerColor(kMagenta);
      his3->SetMarkerColor(kAzure+10);
      his3->SetStats(kFALSE); his2->SetStats(kFALSE);
      his3->Draw();  
      if(his2) his2->Draw("same");
      //    TF1 *fit = his->GetFunction("gaus");
    }
    // cout << "sensor " << i << " stereo mean :  " << his->GetMean()*1000. << " - RMS : " << his->GetRMS()*1000. << " (um) " << " " << his->GetEntries() << endl;
    // cout << "sensor " << i << " stereo mu :  " << fit->GetParameter(1)*1000. << " - sigma : " << fit->GetParameter(2)*1000. << " (um) " << endl;
    // outf << layer.Data() << " " << fit->GetParameter(1)*1000. << " " << fit->GetParameter(2)*1000. << " " << his->GetEntries()  << endl;

  }
  for(Int_t i=4; i<7; i++){
    TString hisname = "h_xy_neg_module_L"; hisname  += i;
    hisname += "b_halfmodule_stereo_hole_sensor0";
    TString hisname3 = "h_xy_pos_module_L"; hisname3  += i;
    hisname3 += "b_halfmodule_stereo_hole_sensor0";
    TH2D *his3;
    if(f->Get(hisname3.Data())){
      his3 = (TH2D*) f->Get(hisname3.Data());
    }else{
      his3 = 0;
    }
    TString layer = "L"; layer+=i; layer+= "BSHo"; 
    // check: is there the histogram?
    //    cout << f->Get(hisname.Data()) << endl;
    TH2D *his2;
    TH1D *his;
    his2 = (TH2D*) f->Get(hisname.Data());
    if(his2){
      his = (TH1D*)his2->ProjectionY();
      if(layer.Contains("1")){his->SetFillColor(kRed);}
      else if(layer.Contains("2")){his->SetFillColor(kOrange);}
      else if(layer.Contains("3")){his->SetFillColor(kYellow);}
      else if(layer.Contains("4")){his->SetFillColor(kGreen);}
      else if(layer.Contains("5")){his->SetFillColor(kCyan);}
      else if(layer.Contains("6")){his->SetFillColor(kBlue);}
      if(layer.Contains("A")){his->SetFillStyle(3007);}
      else if(layer.Contains("S")){his->SetFillStyle(3004);}
    }else{
      his = 0;
    }     

    //    cBot->cd(++ic);
    ipad++; 
    TString pd = "bp"; pd+=ipad;
    TPad *pad = (TPad*) cBot->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    //    low = his->GetMean()-w*his->GetRMS();
    //    up = his->GetMean()+w*his->GetRMS();    
    //    his->Fit("gaus","Q0","",low,up);
    his3->SetMarkerColor(kAzure+10);
    his3->SetStats(kFALSE); 
    if(his3) his3->Draw(); 
    if(his2){
      his2->SetStats(kFALSE);
      his2->SetMarkerColor(kMagenta);
      //      cout << hisname.Data() << endl;
      his2->Draw("same");
    }
    //    TF1 *fit = his->GetFunction("gaus");
    // cout << "sensor " << i << " axial hole mean :  " << his->GetMean()*1000. << " - RMS : " << his->GetRMS()*1000. << " (um) " << " " << his->GetEntries() << endl;
    // cout << "sensor " << i << " axial hole mu :  " << fit->GetParameter(1)*1000. << " - sigma : " << fit->GetParameter(2)*1000. << " (um) " << endl;
    // outf << layer.Data() << " " << fit->GetParameter(1)*1000. << " " << fit->GetParameter(2)*1000. << " " << his->GetEntries()  << endl;

    hisname = "h_xy_neg_module_L"; hisname  += i;
    hisname += "b_halfmodule_axial_hole_sensor0";
    hisname3 = "h_xy_pos_module_L"; hisname3  += i;
    hisname3 += "b_halfmodule_axial_hole_sensor0";
    his3 = (TH2D*) f->Get(hisname3.Data());
    layer = "L"; layer+=i; layer+= "BAHo";
    if(f->Get(hisname.Data())){ 
      his2 = (TH2D*) f->Get(hisname.Data());
      if(his2){
	his = (TH1D*)his2->ProjectionY();
	if(layer.Contains("1")){his->SetFillColor(kRed);}
	else if(layer.Contains("2")){his->SetFillColor(kOrange);}
	else if(layer.Contains("3")){his->SetFillColor(kYellow);}
	else if(layer.Contains("4")){his->SetFillColor(kGreen);}
	else if(layer.Contains("5")){his->SetFillColor(kCyan);}
	else if(layer.Contains("6")){his->SetFillColor(kBlue);}
	if(layer.Contains("A")){his->SetFillStyle(3007);}
	else if(layer.Contains("S")){his->SetFillStyle(3004);}
      }else{
	his = 0;
      }
    }
    ipad++; ipad++;
    pd = "bp"; pd+=ipad;
    pad = (TPad*) cBot->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    //    low = his->GetMean()-w*his->GetRMS();
    //    up = his->GetMean()+w*his->GetRMS();    
    //    his->Fit("gaus","Q0","",low,up);
    his3->SetMarkerColor(kAzure+10);
    his3->SetStats(kFALSE); 
    if(his3) his3->Draw();  
    if(his2){
      his2->SetStats(kFALSE);
      his2->Draw("same");
      his2->SetMarkerColor(kMagenta);
    }
    //    TF1 *fit = his->GetFunction("gaus");

    // cout << "sensor " << i << " stereo hole mean :  " << his->GetMean()*1000. << " - RMS : " << his->GetRMS()*1000. << " (um) " << " " << his->GetEntries() << endl;
    // cout << "sensor " << i << " stereo hole mu :  " << fit->GetParameter(1)*1000. << " - sigma : " << fit->GetParameter(2)*1000. << " (um) " << endl;
    // outf << layer.Data() << " " << fit->GetParameter(1)*1000. << " " << fit->GetParameter(2)*1000. << " " << his->GetEntries()  << endl;

    hisname = "h_xy_neg_module_L"; hisname  += i;
    hisname += "b_halfmodule_stereo_slot_sensor0";
    hisname3 = "h_xy_pos_module_L"; hisname3  += i;
    hisname3 += "b_halfmodule_stereo_slot_sensor0";
    his3 = (TH2D*) f->Get(hisname3.Data());
    layer = "L"; layer+=i; layer+= "BSSl"; 
    his2 = (TH2D*) f->Get(hisname.Data());
    if(his2){
      TH1D *his = (TH1D*)his2->ProjectionY();
      if(layer.Contains("1")){his->SetFillColor(kRed);}
      else if(layer.Contains("2")){his->SetFillColor(kOrange);}
      else if(layer.Contains("3")){his->SetFillColor(kYellow);}
      else if(layer.Contains("4")){his->SetFillColor(kGreen);}
      else if(layer.Contains("5")){his->SetFillColor(kCyan);}
      else if(layer.Contains("6")){his->SetFillColor(kBlue);}
      if(layer.Contains("A")){his->SetFillStyle(3007);}
      else if(layer.Contains("S")){his->SetFillStyle(3004);}
    }else{
      his = 0;
    }
  
    ipad--;
    pd = "bp"; pd+=ipad;
    pad = (TPad*) cBot->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    //    low = his->GetMean()-w*his->GetRMS();
    //    up = his->GetMean()+w*his->GetRMS();    
    //    his->Fit("gaus","Q0","",low,up);
    his2->SetMarkerColor(kMagenta);
    his3->SetMarkerColor(kAzure+10);
    his3->SetStats(kFALSE); his2->SetStats(kFALSE);
    if(his3) his3->Draw();  
    if(his2) his2->Draw("same");
    //    TF1 *fit = his->GetFunction("gaus");

    // cout << "sensor " << i << " axial slot mean :  " << his->GetMean()*1000. << " - RMS : " << his->GetRMS()*1000. << " (um) " << " " << his->GetEntries() << endl;
    // cout << "sensor " << i << " axial slot mu :  " << fit->GetParameter(1)*1000. << " - sigma : " << fit->GetParameter(2)*1000. << " (um) " << endl;
    // outf << layer.Data() << " " << fit->GetParameter(1)*1000. << " " << fit->GetParameter(2)*1000. << " " << his->GetEntries()  << endl;

    hisname = "h_xy_neg_module_L"; hisname  += i;
    hisname += "b_halfmodule_axial_slot_sensor0";
    hisname3 = "h_xy_pos_module_L"; hisname3  += i;
    hisname3 += "b_halfmodule_axial_slot_sensor0";
    his3 = (TH2D*) f->Get(hisname3.Data());
    layer = "L"; layer+=i; layer+= "BASl"; 
    his2 = (TH2D*) f->Get(hisname.Data());
    if(his2){
      his = (TH1D*)his2->ProjectionY();
      if(layer.Contains("1")){his->SetFillColor(kRed);}
      else if(layer.Contains("2")){his->SetFillColor(kOrange);}
      else if(layer.Contains("3")){his->SetFillColor(kYellow);}
      else if(layer.Contains("4")){his->SetFillColor(kGreen);}
      else if(layer.Contains("5")){his->SetFillColor(kCyan);}
      else if(layer.Contains("6")){his->SetFillColor(kBlue);}
      if(layer.Contains("A")){his->SetFillStyle(3007);}
      else if(layer.Contains("S")){his->SetFillStyle(3004);}
    }else{
      his = 0;
    }

    ipad++; ipad++;
    pd = "bp"; pd+=ipad;
    pad = (TPad*) cBot->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    //    low = his->GetMean()-w*his->GetRMS();
    //    up = his->GetMean()+w*his->GetRMS();    
    //    his->Fit("gaus","Q0","",low,up); 
    his2->SetMarkerColor(kMagenta);
    his3->SetMarkerColor(kAzure+10);
    his3->SetStats(kFALSE); his2->SetStats(kFALSE);
    if(his3) his3->Draw(); 
    if(his2) his2->Draw("same");
    //    TF1 *fit = his->GetFunction("gaus");

    // cout << "sensor " << i << " stereo slot mean :  " << his->GetMean()*1000. << " - RMS : " << his->GetRMS()*1000. << " (um) " << " " << his->GetEntries() << endl;
    // cout << "sensor " << i << " stereo slot mu :  " << fit->GetParameter(1)*1000. << " - sigma : " << fit->GetParameter(2)*1000. << " (um) " << endl;
    // outf << layer.Data() << " " << fit->GetParameter(1)*1000. << " " << fit->GetParameter(2)*1000. << " " << his->GetEntries()  << endl;
    
  }

  //  outf.close();
  cTop->cd();
  cTop->SaveAs(topName.Data());
  cBot->cd();
  cBot->SaveAs(botName.Data());

}
