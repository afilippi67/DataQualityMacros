#include <TString.h>
#include <TH1D.h>
#include <TF1.h>
#include <TH2F.h>
#include <Riostream.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TString.h>
#include <TLine.h>
#include <TPad.h>
#include <TFile.h>
#include <TProfile.h>
#include "ReverseXAxis.C"
#include <TLine.h>
#include <TApplication.h>
#include <TColor.h>

// mod 1 2 3

void compareProfilesTwoFiles_123(const Char_t *type, Int_t mod, const Char_t *fname, const Char_t *fname1){

  gStyle->SetOptStat(0);
  gStyle->SetLineWidth(1);
  gStyle->SetLineStyle(2);
  TLine *zerol = new TLine(-20,0.,5.,0);
  zerol->SetLineColor(kRed);
  zerol->SetLineStyle(3);
  TString filename = fname;
  TString filename1 = fname1;
  TFile *f = new TFile(filename.Data());

  TString ttyp = type;
  Int_t colorRef=0, colorFile=0;
  Int_t end = 0;

  if(mod>3){
    cout << "mod = " << mod << " , wrong module number, use the other macro file" << endl;
    gApplication->Terminate();
  }
  if(ttyp.Contains("C")){
    cout << "curved tracks selected" << endl;
    colorRef = kBlue;  // first file : blue
    colorFile = kRed;  // second file : red
    if((!filename1.Contains("5772")) && (!filename1.Contains("7800")) && 
       (!filename.Contains("5772")) && (!filename.Contains("7800"))){
    cout << "**** are you sure you are analysing curved track files? check !!" << endl;
    gApplication->Terminate();
    }
  }else if(ttyp.Contains("S")){
    colorRef = kBlue-7;
    colorFile = kRed-7;
    if((!filename.Contains("8100")) && (!filename.Contains("straight")) && (!filename.Contains("NoField")) &&
       (!filename.Contains("8100")) && (!filename.Contains("straight")) && (!filename.Contains("NoField"))){
      cout << "**** are you sure you are analysing a straight tracks file? check !!" << endl;
      gApplication->Terminate();
    }
  }else{
    cout << "choose either S or C for straight or curved type tracks" << endl;
    cout << "straight tracks selected" << endl;
    gApplication->Terminate();
  }




  // bot
  TH2F *his1b;
  TH2F *his2b;
  TH2F *his3b;
  TH2F *his4b;
  TH2F *his1db;
  TH2F *his2db;
  TH2F *his3db;
  TH2F *his4db;

  TString ini = "h_res_gbl_vs_u_module_L"; ini += mod; ini += "b_halfmodule_axial_sensor0_bot"; 
  his1b = (TH2F*) f->Get(ini.Data());
  ini = "h_res_gbl_vs_u_module_L"; ini += mod; ini += "b_halfmodule_stereo_sensor0_bot"; 
  his3b = (TH2F*) f->Get(ini.Data());
  TProfile *hpf4botaslb = (TProfile*) his1b->ProfileX();
  TProfile *hrev = (TProfile*) his3b->ProfileX();
  TProfile *hpf4botsslb = (TProfile*) ReverseXAxis(hrev);
  //  TProfile *hpf4botsslb = (TProfile*) his3b->ProfileX();
  hpf4botaslb->Fit("pol2","0Q");
  TF1 *fi = (TF1*)hpf4botaslb->GetListOfFunctions()->FindObject("pol2");
  fi->SetLineWidth(2);
  fi->SetLineStyle(3);
  hpf4botsslb->Fit("pol2","0Q");
  TF1 *fi2 = (TF1*)hpf4botsslb->GetListOfFunctions()->FindObject("pol2");
  fi2->SetLineWidth(2);
  fi2->SetLineStyle(3);
  hpf4botaslb->SetLineColor(colorRef);
  hpf4botsslb->SetLineColor(colorRef);
  hpf4botaslb->SetMarkerColor(colorRef);
  hpf4botsslb->SetMarkerColor(colorRef);
  hpf4botaslb->SetMarkerStyle(22);
  hpf4botsslb->SetMarkerStyle(22);
  hpf4botaslb->SetMarkerSize(1.2);
  hpf4botsslb->SetMarkerSize(1.2);
  hpf4botsslb->SetStats(kFALSE);
  hpf4botsslb->SetStats(kFALSE);

  /////////////////////////////////////////////////

  TFile *g = new TFile(filename1.Data());

  // TFile *g = new TFile("/disk2/hps_alignment/hps-gbl-output/mixedSamples/2015/HPS-EngRun2015-Nominal-v5-1/gbltst-hps-plots-hps_005772.evio.all.root");

  TString ini2 = "h_res_gbl_vs_u_module_L"; ini2 += mod; ini2 += "b_halfmodule_axial_sensor0_bot"; 
  his1db = (TH2F*) g->Get(ini2.Data());
  ini2 = "h_res_gbl_vs_u_module_L"; ini2 += mod; ini2 += "b_halfmodule_stereo_sensor0_bot"; 
  his3db = (TH2F*) g->Get(ini2.Data());
  TProfile *hpf4botasldb = (TProfile*) his1db->ProfileX();
  hrev = (TProfile*) his3db->ProfileX();
  TProfile *hpf4botssldb = (TProfile*) ReverseXAxis(hrev);
  hpf4botasldb->SetLineColor(colorFile);
  hpf4botssldb->SetLineColor(colorFile);
  hpf4botasldb->SetMarkerColor(colorFile);
  hpf4botssldb->SetMarkerColor(colorFile);
  hpf4botasldb->SetMarkerStyle(20);
  hpf4botssldb->SetMarkerStyle(20);
  hpf4botasldb->GetYaxis()->SetTitle("mm");
  hpf4botssldb->GetYaxis()->SetTitle("mm");
  hpf4botasldb->GetXaxis()->SetTitle("Meas u (mm)");
  hpf4botssldb->GetXaxis()->SetTitle("Meas u (mm)");
  hpf4botaslb->GetXaxis()->SetTitle("Meas u (mm)");
  hpf4botsslb->GetXaxis()->SetTitle("Meas u (mm)");
  hpf4botasldb->GetXaxis()->SetRangeUser(-20,5);
  hpf4botssldb->GetXaxis()->SetRangeUser(-20,5);
  hpf4botaslb->GetXaxis()->SetRangeUser(-20,5);
  hpf4botsslb->GetXaxis()->SetRangeUser(-20,5);
  Double_t lim = 0.01;
  hpf4botssldb->GetYaxis()->SetRangeUser(-lim,lim);
  hpf4botssldb->GetYaxis()->SetRangeUser(-lim,lim);
  hpf4botsslb->GetYaxis()->SetRangeUser(-lim,lim);
  hpf4botsslb->GetYaxis()->SetRangeUser(-lim,lim);
  hpf4botasldb->GetYaxis()->SetRangeUser(-lim,lim);
  hpf4botasldb->GetYaxis()->SetRangeUser(-lim,lim);
  hpf4botaslb->GetYaxis()->SetRangeUser(-lim,lim);
  hpf4botaslb->GetYaxis()->SetRangeUser(-lim,lim);
  hpf4botasldb->SetStats(kFALSE);
  hpf4botssldb->SetStats(kFALSE);

  ////////////////////////////////////////////////

  TCanvas *cb = new TCanvas("cb","bottom",1000,500);
  cb->Divide(2,2);
  Int_t i=2;
  cb->cd(++i);
  hpf4botaslb->SetStats(kFALSE);
  hpf4botasldb->SetStats(kFALSE);
  if(mod == 1){
    hpf4botaslb ->GetYaxis()->SetRangeUser(-0.01,0.01);
    hpf4botasldb->GetYaxis()->SetRangeUser(-0.01,0.01);
    hpf4botssldb->GetYaxis()->SetRangeUser(-0.01,0.01);
    hpf4botsslb-> GetYaxis()->SetRangeUser(-0.01,0.01);
  }
  hpf4botaslb->Draw();
  hpf4botasldb->Draw("same");
  zerol->Draw("same");
  cb->cd(++i);
  hpf4botssldb->SetStats(kFALSE);
  hpf4botsslb-> SetStats(kFALSE);
  hpf4botsslb->Draw();
  hpf4botssldb->Draw("same");
  zerol->Draw("same");

  TString titb = "profUResVsU_cmp_"; titb += ttyp.Data(); titb += "_mod"; titb += mod; titb += ".gif";

  ///////////////////////////////////////////////////
  ///////////////////////////////////////////////////

  f->cd();

  // top
  ini = "h_res_gbl_vs_u_module_L"; ini += mod; ini += "t_halfmodule_axial_sensor0_top"; 
  TH2F *his1 = (TH2F*) f->Get(ini.Data());
  ini = "h_res_gbl_vs_u_module_L"; ini += mod; ini += "t_halfmodule_stereo_sensor0_top"; 
  TH2F *his3 = (TH2F*) f->Get(ini.Data());
  TProfile *hpf4topasl = his1->ProfileX();
  hrev = (TProfile*) his3->ProfileX();
  TProfile *hpf4topssl = (TProfile*) ReverseXAxis(hrev);
  hpf4topasl->Fit("pol2","0Q");
  TF1 *fi7 = (TF1*)hpf4topasl->GetListOfFunctions()->FindObject("pol2");
  fi7->SetLineWidth(2);
  fi7->SetLineStyle(3);
  hpf4topssl->Fit("pol2","0Q");
  TF1 *fi8 = (TF1*)hpf4topssl->GetListOfFunctions()->FindObject("pol2");
  fi8->SetLineWidth(2);
  fi8->SetLineStyle(3);

  hpf4topasl->SetLineColor(colorRef);
  hpf4topssl->SetLineColor(colorRef);
  hpf4topasl->SetMarkerColor(colorRef);
  hpf4topssl->SetMarkerColor(colorRef);
  hpf4topasl->SetMarkerStyle(22);
  hpf4topssl->SetMarkerStyle(22);
  hpf4topasl->SetMarkerSize(1.2);
  hpf4topssl->SetMarkerSize(1.2);
  hpf4topssl->SetStats(kFALSE);

  g->cd();

  ini = "h_res_gbl_vs_u_module_L"; ini += mod; ini += "t_halfmodule_axial_sensor0_top"; 
  TH2F *his1d = (TH2F*) g->Get(ini.Data());
  ini = "h_res_gbl_vs_u_module_L"; ini += mod; ini += "t_halfmodule_stereo_sensor0_top"; 
  TH2F *his3d = (TH2F*) g->Get(ini.Data());
  TProfile *hpf4topasld = his1d->ProfileX();
  hrev = (TProfile*) his3d->ProfileX();
  TProfile *hpf4topssld = (TProfile*) ReverseXAxis(hrev);

  hpf4topasld->SetLineColor(colorFile);
  hpf4topssld->SetLineColor(colorFile);
  hpf4topasld->SetMarkerColor(colorFile);
  hpf4topssld->SetMarkerColor(colorFile);
  hpf4topasld->SetMarkerStyle(20);
  hpf4topssld->SetMarkerStyle(20);

  hpf4topasld->GetYaxis()->SetTitle("mm");
  hpf4topssld->GetYaxis()->SetTitle("mm");
  hpf4topasld->GetXaxis()->SetTitle("Meas u (mm)");
  hpf4topssld->GetXaxis()->SetTitle("Meas u (mm)");
  hpf4topasld->GetXaxis()->SetRangeUser(-20,5);
  hpf4topssld->GetXaxis()->SetRangeUser(-20,5);
  hpf4topasld->GetYaxis()->SetRangeUser(-lim,lim);
  hpf4topssld->GetYaxis()->SetRangeUser(-lim,lim);

  //////////////////////////////////////////////////

  /////////////////////////////////////////

  i=0;
  cb->cd(++i);
  hpf4topasld->SetStats(kFALSE);
  hpf4topasl-> SetStats(kFALSE);
  hpf4topasld->Draw();
  hpf4topasl->Draw("same");
  zerol->Draw("same");

 
  cb->cd(++i);
  hpf4topssld->SetStats(kFALSE);
  hpf4topssl-> SetStats(kFALSE);
  hpf4topssld->Draw();
  hpf4topssl->Draw("same");
  zerol->Draw("same");

  cb->SaveAs(titb.Data());
  



}
