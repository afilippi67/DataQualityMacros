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

// mod value: 4 5 6

void compareProfilesTwoFiles_456(const Char_t *type, Int_t mod, const Char_t *fname, const Char_t *fname1){

  gStyle->SetOptStat(0);
  TLine *zerol = new TLine(-20.,0.,20., 0.);
  zerol->SetLineColor(kRed);
  zerol->SetLineStyle(3);

  TString filename = fname;
  TString filename1 = fname1;
  TFile *f = new TFile(filename.Data());

  TString ttyp = type;
  Int_t colorRef=0, colorFile=0;
  Int_t end = 0;

  if(mod<4){
    cout << "mod = " << mod << " , wrong module number, use the other macro file" << endl;
    gApplication->Terminate();
  }

  if(ttyp.Contains("C")){
    colorRef = kBlue;  // first file
    colorFile = kRed;  // second file
    cout << "curved tracks selected" << endl;
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
  
  TString ini = "h_res_gbl_vs_u_module_L"; ini += mod; ini += "b_halfmodule_axial_slot_sensor0_bot"; 
  his1b = (TH2F*) f->Get(ini.Data());
  ini = "h_res_gbl_vs_u_module_L"; ini += mod; ini += "b_halfmodule_axial_hole_sensor0_bot"; 
  his2b = (TH2F*) f->Get(ini.Data());
  ini = "h_res_gbl_vs_u_module_L"; ini += mod; ini += "b_halfmodule_stereo_slot_sensor0_bot"; 
  his3b = (TH2F*) f->Get(ini.Data());
  ini = "h_res_gbl_vs_u_module_L"; ini += mod; ini += "b_halfmodule_stereo_hole_sensor0_bot"; 
  his4b = (TH2F*) f->Get(ini.Data());
  TProfile *hrev = (TProfile*) his1b->ProfileX();
  TProfile *hpf4botaslb = (TProfile*) ReverseXAxis(hrev);
  //  TProfile *hpf4botaslb = (TProfile*) his1b->ProfileX();
  TProfile *hpf4botahob = (TProfile*) his2b->ProfileX();
  TProfile *hpf4botsslb = (TProfile*) his3b->ProfileX();
  hrev = (TProfile*) his4b->ProfileX();
  TProfile *hpf4botshob = (TProfile*) ReverseXAxis(hrev);
  //  TProfile *hpf4botshob = (TProfile*) his4b->ProfileX();
  hpf4botaslb->SetLineColor(colorRef);
  hpf4botahob->SetLineColor(colorRef);
  hpf4botsslb->SetLineColor(colorRef);
  hpf4botshob->SetLineColor(colorRef);
  hpf4botaslb->SetMarkerColor(colorRef);
  hpf4botahob->SetMarkerColor(colorRef);
  hpf4botsslb->SetMarkerColor(colorRef);
  hpf4botshob->SetMarkerColor(colorRef);
  hpf4botaslb->SetMarkerStyle(22);
  hpf4botahob->SetMarkerStyle(22);
  hpf4botsslb->SetMarkerStyle(22);
  hpf4botshob->SetMarkerStyle(22);
  hpf4botaslb->SetMarkerSize(1.2);
  hpf4botahob->SetMarkerSize(1.2);
  hpf4botsslb->SetMarkerSize(1.2);
  hpf4botshob->SetMarkerSize(1.2);

  ////////////////////////////////////////////////

  TFile *g = new TFile(filename1.Data());

  TString ini2 = "h_res_gbl_vs_u_module_L"; ini2 += mod; ini2 += "b_halfmodule_axial_slot_sensor0_bot"; 
  his1db = (TH2F*) g->Get(ini2.Data());
  ini2 = "h_res_gbl_vs_u_module_L"; ini2 += mod; ini2 += "b_halfmodule_axial_hole_sensor0_bot"; 
  his2db = (TH2F*) g->Get(ini2.Data());
  ini2 = "h_res_gbl_vs_u_module_L"; ini2 += mod; ini2 += "b_halfmodule_stereo_slot_sensor0_bot"; 
  his3db = (TH2F*) g->Get(ini2.Data());
  ini2 = "h_res_gbl_vs_u_module_L"; ini2 += mod; ini2 += "b_halfmodule_stereo_hole_sensor0_bot"; 
  his4db = (TH2F*) g->Get(ini2.Data());
  hrev = (TProfile*) his1db->ProfileX();
  TProfile *hpf4botasldb = (TProfile*) ReverseXAxis(hrev);
  //  TProfile *hpf4botasldb = (TProfile*) his1db->ProfileX();
  TProfile *hpf4botahodb = (TProfile*) his2db->ProfileX();
  TProfile *hpf4botssldb = (TProfile*) his3db->ProfileX();
  hrev = (TProfile*) his4db->ProfileX();
  TProfile *hpf4botshodb = (TProfile*) ReverseXAxis(hrev);
  //  TProfile *hpf4botshodb = (TProfile*) his4db->ProfileX();
  hpf4botasldb->SetLineColor(colorFile);
  hpf4botahodb->SetLineColor(colorFile);
  hpf4botssldb->SetLineColor(colorFile);
  hpf4botshodb->SetLineColor(colorFile);
  hpf4botasldb->SetMarkerColor(colorFile);
  hpf4botahodb->SetMarkerColor(colorFile);
  hpf4botssldb->SetMarkerColor(colorFile);
  hpf4botshodb->SetMarkerColor(colorFile);
  hpf4botasldb->SetMarkerStyle(20);
  hpf4botahodb->SetMarkerStyle(20);
  hpf4botssldb->SetMarkerStyle(20);
  hpf4botshodb->SetMarkerStyle(20);
  hpf4botasldb->GetYaxis()->SetTitle("mm");
  hpf4botahodb->GetYaxis()->SetTitle("mm");
  hpf4botssldb->GetYaxis()->SetTitle("mm");
  hpf4botshodb->GetYaxis()->SetTitle("mm");
  hpf4botasldb->GetYaxis()->SetRangeUser(-0.01,0.01);
  hpf4botahodb->GetYaxis()->SetRangeUser(-0.01,0.01);
  hpf4botssldb->GetYaxis()->SetRangeUser(-0.01,0.01);
  hpf4botshodb->GetYaxis()->SetRangeUser(-0.01,0.01);


  
  TCanvas *cb = new TCanvas("cb","bottom",1000,500);
  cb->Divide(2,2);
  Int_t i=0;
  cb->cd(++i);
  hpf4botasldb->SetStats(kFALSE);
  hpf4botaslb-> SetStats(kFALSE);
  hpf4botasldb->GetXaxis()->SetTitle("Meas u (mm)");
  hpf4botaslb-> GetXaxis()->SetTitle("Meas u (mm)");
  hpf4botasldb->Draw();
  hpf4botaslb->Draw("same");
  zerol->Draw("same");
  cb->cd(++i);
  hpf4botahodb->GetXaxis()->SetTitle("Meas u (mm)");
  hpf4botahob-> GetXaxis()->SetTitle("Meas u (mm)");
  hpf4botahodb->SetStats(kFALSE);
  hpf4botahob-> SetStats(kFALSE);
  hpf4botahodb->Draw();
  hpf4botahob->Draw("same");
  zerol->Draw("same");

  cb->cd(++i);
  hpf4botssldb->GetXaxis()->SetTitle("Meas u (mm)");
  hpf4botsslb-> GetXaxis()->SetTitle("Meas u (mm)");
  hpf4botssldb->SetStats(kFALSE);
  hpf4botsslb-> SetStats(kFALSE);
  hpf4botssldb->Draw();
  hpf4botsslb->Draw("same");
  zerol->Draw("same");
  cb->cd(++i);
  hpf4botshodb->GetXaxis()->SetTitle("Meas u (mm)");
  hpf4botshob-> GetXaxis()->SetTitle("Meas u (mm)");
  hpf4botshodb->SetStats(kFALSE);
  hpf4botshob-> SetStats(kFALSE);
  hpf4botshodb->Draw();
  hpf4botshob->Draw("same");
  zerol->Draw("same");
  TString titb = "profUResVsU_mod"; titb += mod; titb += "_"; titb += ttyp.Data(); titb += "_bot.gif";
  cb->SaveAs(titb.Data());
  
  // `````````````````````````````````````````````````````````````````

  f->cd();

  // top
  ini = "h_res_gbl_vs_u_module_L"; ini += mod; ini += "t_halfmodule_axial_slot_sensor0_top"; 
  TH2F *his1 = (TH2F*) f->Get(ini.Data());
  ini = "h_res_gbl_vs_u_module_L"; ini += mod; ini += "t_halfmodule_axial_hole_sensor0_top"; 
  TH2F *his2 = (TH2F*) f->Get(ini.Data());
  ini = "h_res_gbl_vs_u_module_L"; ini += mod; ini += "t_halfmodule_stereo_slot_sensor0_top"; 
  TH2F *his3 = (TH2F*) f->Get(ini.Data());
  ini = "h_res_gbl_vs_u_module_L"; ini += mod; ini += "t_halfmodule_stereo_hole_sensor0_top"; 
  TH2F *his4 = (TH2F*) f->Get(ini.Data());
  hrev = (TProfile*) his1->ProfileX();
  TProfile *hpf4topasl = (TProfile*) ReverseXAxis(hrev);
  //  TProfile *hpf4topasl = his1->ProfileX();
  TProfile *hpf4topaho = his2->ProfileX();
  TProfile *hpf4topssl = his3->ProfileX();
  hrev = (TProfile*) his4->ProfileX();
  TProfile *hpf4topsho = (TProfile*) ReverseXAxis(hrev);
  //  TProfile *hpf4topsho = his4->ProfileX();
  hpf4topasl->SetLineColor(colorRef);
  hpf4topaho->SetLineColor(colorRef);
  hpf4topssl->SetLineColor(colorRef);
  hpf4topsho->SetLineColor(colorRef);
  hpf4topasl->SetMarkerColor(colorRef);
  hpf4topaho->SetMarkerColor(colorRef);
  hpf4topssl->SetMarkerColor(colorRef);
  hpf4topsho->SetMarkerColor(colorRef);
  hpf4topasl->SetMarkerStyle(22);
  hpf4topaho->SetMarkerStyle(22);
  hpf4topssl->SetMarkerStyle(22);
  hpf4topsho->SetMarkerStyle(22);
  hpf4topasl->SetMarkerSize(1.2);
  hpf4topaho->SetMarkerSize(1.2);
  hpf4topssl->SetMarkerSize(1.2);
  hpf4topsho->SetMarkerSize(1.2);

  ////////////////////////////////////////////////////////////

  g->cd();

  ini = "h_res_gbl_vs_u_module_L"; ini += mod; ini += "t_halfmodule_axial_slot_sensor0_top"; 
  TH2F *his1d = (TH2F*) g->Get(ini.Data());
  ini = "h_res_gbl_vs_u_module_L"; ini += mod; ini += "t_halfmodule_axial_hole_sensor0_top"; 
  TH2F *his2d = (TH2F*) g->Get(ini.Data());
  ini = "h_res_gbl_vs_u_module_L"; ini += mod; ini += "t_halfmodule_stereo_slot_sensor0_top"; 
  TH2F *his3d = (TH2F*) g->Get(ini.Data());
  ini = "h_res_gbl_vs_u_module_L"; ini += mod; ini += "t_halfmodule_stereo_hole_sensor0_top"; 
  TH2F *his4d = (TH2F*) g->Get(ini.Data());
  hrev = (TProfile*) his1d->ProfileX();
  TProfile *hpf4topasld = (TProfile*) ReverseXAxis(hrev);
  //  TProfile *hpf4topasld = his1d->ProfileX();
  TProfile *hpf4topahod = his2d->ProfileX();
  TProfile *hpf4topssld = his3d->ProfileX();
  hrev = (TProfile*) his4d->ProfileX();
  TProfile *hpf4topshod = (TProfile*) ReverseXAxis(hrev);
  //  TProfile *hpf4topshod = his4d->ProfileX();
  hpf4topasld->SetLineColor(colorFile);
  hpf4topahod->SetLineColor(colorFile);
  hpf4topssld->SetLineColor(colorFile);
  hpf4topshod->SetLineColor(colorFile);
  hpf4topasld->SetMarkerColor(colorFile);
  hpf4topahod->SetMarkerColor(colorFile);
  hpf4topssld->SetMarkerColor(colorFile);
  hpf4topshod->SetMarkerColor(colorFile);
  hpf4topasld->SetMarkerStyle(20);
  hpf4topahod->SetMarkerStyle(20);
  hpf4topssld->SetMarkerStyle(20);
  hpf4topshod->SetMarkerStyle(20);

  hpf4topasld->GetYaxis()->SetTitle("mm");
  hpf4topahod->GetYaxis()->SetTitle("mm");
  hpf4topssld->GetYaxis()->SetTitle("mm");
  hpf4topshod->GetYaxis()->SetTitle("mm");
  hpf4topasld->GetYaxis()->SetRangeUser(-0.01,0.01);
  hpf4topahod->GetYaxis()->SetRangeUser(-0.01,0.01);
  hpf4topssld->GetYaxis()->SetRangeUser(-0.01,0.01);
  hpf4topshod->GetYaxis()->SetRangeUser(-0.01,0.01);



  TCanvas *ct = new TCanvas("ct","top",1000,500);
  ct->Divide(2,2);
  i=0;
  ct->cd(++i);
  hpf4topasld->GetXaxis()->SetTitle("Meas u (mm)");
  hpf4topasl-> GetXaxis()->SetTitle("Meas u (mm)");
  hpf4topasld->SetStats(kFALSE);
  hpf4topasl-> SetStats(kFALSE);
  hpf4topasld->Draw();
  hpf4topasl->Draw("same");
  zerol->Draw("same");
  ct->cd(++i);
  hpf4topahod->GetXaxis()->SetTitle("Meas u (mm)");
  hpf4topaho-> GetXaxis()->SetTitle("Meas u (mm)");
  hpf4topahod->SetStats(kFALSE);
  hpf4topaho-> SetStats(kFALSE);
  hpf4topahod->Draw();
  hpf4topaho->Draw("same");
  zerol->Draw("same");
  ct->cd(++i);
  hpf4topssld->GetXaxis()->SetTitle("Meas u (mm)");
  hpf4topssl-> GetXaxis()->SetTitle("Meas u (mm)");
  hpf4topssld->SetStats(kFALSE);
  hpf4topssl-> SetStats(kFALSE);
  hpf4topssld->Draw();
  hpf4topssl->Draw("same");
  zerol->Draw("same");
  ct->cd(++i);
  hpf4topshod->GetXaxis()->SetTitle("Meas u (mm)");
  hpf4topsho-> GetXaxis()->SetTitle("Meas u (mm)");
  hpf4topshod->SetStats(kFALSE);
  hpf4topsho ->SetStats(kFALSE);
  hpf4topshod->Draw();
  hpf4topsho->Draw("same");
  zerol->Draw("same");
  TString titd = "profUResVsU_mod"; titd += mod; titd += "_"; titd += ttyp.Data(); titd += "_top.gif";
  ct->SaveAs(titd.Data());
  



}
