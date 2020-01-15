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
#include <TProfile.h>
#include <TGaxis.h>



TH1 *ReverseXAxis1D (TH1 *h)
{
   // Remove the current axis
   h->GetXaxis()->SetLabelOffset(999);
   h->GetXaxis()->SetTickLength(0);

   // Redraw the new axis 
   gPad->Update();
   TGaxis *newaxis = new TGaxis(gPad->GetUxmax(), 
                                gPad->GetUymin(),
                                gPad->GetUxmin(),
                                gPad->GetUymin(),
                                h->GetXaxis()->GetXmin(),
                                h->GetXaxis()->GetXmax(),
                                510,"-");
   newaxis->SetLabelOffset(-0.03);
   //   newaxis->Draw();
   Int_t totBins = h->GetXaxis()->GetNbins();
   
   TH1D *hrev = new TH1D("hrev","hrev", totBins, h->GetXaxis()->GetXmin(), h->GetXaxis()->GetXmax());
   
   for(Int_t i=1; i<totBins; i++){
     hrev->SetBinContent(totBins-i+1, h->GetBinContent(i));
     hrev->SetBinError(totBins-i+1, h->GetBinError(i));
   }
   hrev->Draw();
   return hrev;
}


void plotResidualsVSPosProfile(const char* fname){

  // input: root filename (out of gbl)

  TH1 *ReverseXAxis1D(TH1*); 
  TLine *zerol = new TLine(-20, 0., 20, 0.);
  zerol->SetLineColor(kRed);
  zerol->SetLineStyle(3);

  gStyle->SetOptStat(0);
  Double_t w = 1.2; // number of RMS for gaussian fit
  TString filename = fname;
  cout << filename.Data() << endl;
  TCanvas *cTop = new TCanvas("cTop","Residuals u vs u profile in lab frame, TOP", 800, 1200);
  TCanvas *cBot = new TCanvas("cBot","Residuals u vs u profile in lab frame, BOTTOM",800, 1200);
  cTop->SetFillColor(kBlue-10); cTop->SetFillStyle(3002);
  cBot->SetFillColor(kMagenta-10); cBot->SetFillStyle(3002);
  Int_t ic=0;
  Int_t np=1, npp=1;
  TFile *f = new TFile(filename.Data());
  // extract string 
  Int_t idx2 = filename.Index("/");
  Int_t idx1 = filename.Index("_");
  TString outn = filename(idx1+1,idx2-(idx1+1));
  TString outname ="residualsVSUhit"; outname += outn.Data(); outname += "_prof.txt";
  TString topName ="residualsVSUhit"; topName += outn.Data(); topName += "_prof_top.gif";
  TString botName ="residualsVSUhit"; botName += outn.Data(); botName += "_prof_bot.gif";
  ofstream outf(outname.Data());
  // top
  
  cout << " TOP " << endl;
  Int_t nrow = 14;
  Double_t space = 0.005;
  //  Double_t space1 = 0.03;
  Double_t space1 = 0.000;
  Double_t y2 = 1./14*nrow-space1;
  Double_t y1 = 1./14*(--nrow)-space1;
  TPad *tp1 = new TPad("tp1","tp1",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./14.*(--nrow)-space1;
  TPad *tp2 = new TPad("tp2","tp2",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./14.*(--nrow)-space1;
  TPad *tp3 = new TPad("tp3","tp3",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./14.*(--nrow)-space1;
  TPad *tp4 = new TPad("tp4","tp4",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./14.*(--nrow)-space1;
  TPad *tp5 = new TPad("tp5","tp5",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./14.*(--nrow)-space1;
  TPad *tp6 = new TPad("tp6","tp6",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./14.*(--nrow)-space1;
  TPad *tp7 = new TPad("tp7","tp7",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./14.*(--nrow)-space1;
  TPad *tp8 = new TPad("tp8","tp7",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./14.*(--nrow)-space1;
  Double_t off = 0.12;
  //  off = 0.;
  y1 -= space1; y2 -= space1;
  space1 *= 2;
  TPad *tp9 = new TPad("tp9","tp9",0.+off,y1,0.33+off,y2);  //5
  TPad *tp10 = new TPad("tp10","tp10",0.66-off,y1,0.99-off,y2);
  y2 = y1-space; y1 = 1./14.*(--nrow)-space1;
  TPad *tp11 = new TPad("tp11","tp11",0.+off,y1,0.33+off,y2);
  TPad *tp12 = new TPad("tp12","tp12",0.66-off,y1,0.99-off,y2);
  y2 = y1-space; y1 = 1./14.*(--nrow)-space1;
  TPad *tp13 = new TPad("tp13","tp13",0.+off,y1,0.33+off,y2); //6
  TPad *tp14 = new TPad("tp14","tp14",0.66-off,y1,0.99-off,y2);
  y2 = y1-space; y1 = 1./14.*(--nrow)-space1;
  TPad *tp15 = new TPad("tp15","tp15",0.+off,y1,0.33+off,y2);
  TPad *tp16 = new TPad("tp16","tp16",0.66-off,y1,0.99-off,y2);
  y2 = y1-space; y1 = 1./14.*(--nrow)-space1;
  TPad *tp17 = new TPad("tp17","tp17",0.+off,y1,0.33+off,y2); //7
  TPad *tp18 = new TPad("tp18","tp18",0.66-off,y1,0.99-off,y2);
  y2 = y1-space; y1 = 1./14.*(--nrow)-space1;
  TPad *tp19 = new TPad("tp19","tp19",0.+off,y1,0.33+off,y2);
  TPad *tp20 = new TPad("tp20","tp20",0.66-off,y1,0.99-off,y2);
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
  tp19->Draw();
  tp20->Draw();

  ic = 2;
  Int_t ipad=0;
  for(Int_t i=1; i<5; i++){
    TString hisname = "residual_after_GBL_vs_u_hit_module_L"; hisname += i;
    //    TString hisname = "h_res_gbl_module_L"; hisname  += i;
    hisname += "t_halfmodule_axial_sensor0";
    TString layer = "L"; layer+=i; layer+= "TA"; 
    TH2D *his = (TH2D*) f->Get(hisname.Data());
    TProfile *hpf = (TProfile*)his->ProfileX();
    TString hisnameIni = "residual_after_GBL_vs_u_hit_module_L"; hisnameIni += i;
    //    TString hisnameIni = "h_res_module_L"; hisnameIni  += i;
    hisnameIni += "t_halfmodule_axial_sensor0";
    TH2D *hisIni = (TH2D*) f->Get(hisnameIni.Data());
    ipad++;
    TString pd = "tp"; pd+=ipad;
    TPad *pad = (TPad*) cTop->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    //if(his) his->Draw("colz");
    hpf->Draw(); zerol->Draw("same");

    hisname = "residual_after_GBL_vs_u_hit_module_L"; hisname += i;
    //    hisname = "h_res_gbl_module_L"; hisname  += i;
    hisname += "t_halfmodule_stereo_sensor0";
    layer = "L"; layer+=i; layer+= "TS"; 
    his = (TH2D*) f->Get(hisname.Data());
    hpf = (TProfile*)his->ProfileX();
    hisnameIni = "residual_after_GBL_vs_u_hit_module_L"; hisnameIni += i;
    //    hisnameIni = "h_res_module_L"; hisnameIni  += i;
    hisnameIni += "t_halfmodule_stereo_sensor0";
    hisIni = (TH2D*) f->Get(hisnameIni.Data());
    ipad++;
    pd = "tp"; pd+=ipad;
    pad = (TPad*) cTop->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    if(his) {//ReverseXAxis(his); his->Draw("colz");
      TH1 *hpfr = (TH1*)ReverseXAxis1D((TH1D*)hpf);
      hpfr->Draw(); zerol->Draw("same");}
    cout << ipad << " " << his->GetName() << endl;
  }
  cout << " seconda serie " << endl;

  Int_t np1=1, np2=1;
  for(Int_t i=5; i<8; i++){
    TString hisname = "residual_after_GBL_vs_u_hit_module_L"; hisname += i;
    //    TString hisname = "h_res_gbl_module_L"; hisname  += i;
    hisname += "t_halfmodule_axial_hole_sensor0";
    TString layer = "L"; layer+=i; layer+= "TAHo"; 
    TH2D *his = (TH2D*) f->Get(hisname.Data());
    TProfile *hpf = (TProfile*)his->ProfileX();
    TString hisnameIni = "residual_after_GBL_vs_u_hit_module_L"; hisnameIni += i;
    //    TString hisnameIni = "h_res_module_L"; hisnameIni  += i;
    hisnameIni += "t_halfmodule_axial_hole_sensor0";
    cout << hisnameIni.Data() << endl;
    TH2D *hisIni = (TH2D*) f->Get(hisnameIni.Data());
    //ipad++;
    //if(his) his->Draw("colz");

    ipad++;
    TString pd = "tp"; pd+=ipad;
    TPad *pad = (TPad*) cTop->GetListOfPrimitives()->FindObject(pd.Data());
    cout << pd.Data() << " " << pad<< endl;
    pad->cd();
    if(his) {// his->Draw("colz");
      hpf->Draw(); zerol->Draw("same");}
    cout << ipad << " " << his->GetName() << endl;

    hisname = "residual_after_GBL_vs_u_hit_module_L"; hisname += i;
    //    hisname = "h_res_gbl_module_L"; hisname  += i;
    hisname += "t_halfmodule_stereo_hole_sensor0";
    layer = "L"; layer+=i; layer+= "TSHo"; 
    his = (TH2D*) f->Get(hisname.Data());
    hpf = (TProfile*)his->ProfileX();
    hisnameIni = "residual_after_GBL_vs_u_hit_module_L"; hisnameIni += i;
    //    hisnameIni = "h_res_module_L"; hisnameIni  += i;
    hisnameIni += "t_halfmodule_stereo_hole_sensor0";
    hisIni = (TH2D*) f->Get(hisnameIni.Data());

    ipad++; ipad++;
    pd = "tp"; pd+=ipad;
    //    cout << pd.Data() << " " << pad << " " << npp << endl;
    pad = (TPad*) cTop->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    if(his) {//ReverseXAxis(his); his->Draw("colz");}
      TH1 *hpfr = (TH1*)ReverseXAxis1D((TH1D*)hpf);
      hpfr->Draw(); zerol->Draw("same");}
    cout << ipad << " " << his->GetName() << endl;
    
    /////////////////////

    cout << "----------- " << ipad << endl;
    //    npp -= 2;
    hisname = "residual_after_GBL_vs_u_hit_module_L"; hisname += i;
    //hisname = "h_res_gbl_module_L"; hisname  += i;
    hisname += "t_halfmodule_axial_slot_sensor0";
    layer = "L"; layer+=i; layer+= "TASl"; 
    his = (TH2D*) f->Get(hisname.Data());
    hpf = (TProfile*)his->ProfileX();

    //    if(his) his->Draw("colz");
    //    cout << ipad << " " << his->GetName() << endl;

    ipad -= 1;
    pd = "tp"; pd+=ipad;
    cout << pd.Data() << endl;
    pad = (TPad*) cTop->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    if(his) {//his->Draw("colz");
      hpf->Draw(); zerol->Draw("same");
    }
    cout << ipad << " " << his->GetName() << endl;
    
    hisname = "residual_after_GBL_vs_u_hit_module_L"; hisname += i;
    //hisname = "h_res_gbl_module_L"; hisname  += i;
    hisname += "t_halfmodule_stereo_slot_sensor0";
    layer = "L"; layer+=i; layer+= "TSSl"; 
    his = (TH2D*) f->Get(hisname.Data());
    hpf = (TProfile*)his->ProfileX();

    hisnameIni = "residual_after_GBL_vs_u_hit_module_L"; hisnameIni += i;
    //hisnameIni = "h_res_module_L"; hisnameIni  += i;
    hisnameIni += "t_halfmodule_stereo_slot_sensor0";
    hisIni = (TH2D*) f->Get(hisnameIni.Data());
    //    cTop->cd(ic); ic+=1;
    ipad++; ipad++;
    pd = "tp"; pd+=ipad;
    pad = (TPad*) cTop->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    if(his) {//ReverseXAxis(his); his->Draw("colz");}
      TH1 *hpfr = (TH1*)ReverseXAxis1D((TH1D*)hpf);
      hpfr->Draw(); zerol->Draw("same");}
    cout << ipad << " " << his->GetName() << endl;
    
  }
  cout << endl;
  cout << "------------------------" << endl;
  cout << endl;

  ////////////////////////////////////////////////////////////   

  cout << " BOTTOM " << endl;
  
  nrow = 14;
  space = 0.005;
  //  Double_t space1 = 0.03;
  space1 = 0.000;
  y2 = 1./14*nrow-space1;
  y1 = 1./14*(--nrow)-space1;
  TPad *bp1 = new TPad("bp1","bp1",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./14.*(--nrow)-space1;
  TPad *bp2 = new TPad("bp2","bp2",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./14.*(--nrow)-space1;
  TPad *bp3 = new TPad("bp3","bp3",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./14.*(--nrow)-space1;
  TPad *bp4 = new TPad("bp4","bp4",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./14.*(--nrow)-space1;
  TPad *bp5 = new TPad("bp5","bp5",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./14.*(--nrow)-space1;
  TPad *bp6 = new TPad("bp6","bp6",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./14.*(--nrow)-space1;
  TPad *bp7 = new TPad("bp7","bp7",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./14.*(--nrow)-space1;
  TPad *bp8 = new TPad("bp8","bp7",0.33,y1,0.66,y2);
  y2 = y1-space; y1 = 1./14.*(--nrow)-space1;
  off = 0.12;
  //  off = 0.;
  y1 -= space1; y2 -= space1;
  space1 *= 2;
  TPad *bp9 = new TPad("bp9","bp9",0.+off,y1,0.33+off,y2);  //5
  TPad *bp10 = new TPad("bp10","bp10",0.66-off,y1,0.99-off,y2);
  y2 = y1-space; y1 = 1./14.*(--nrow)-space1;
  TPad *bp11 = new TPad("bp11","bp11",0.+off,y1,0.33+off,y2);
  TPad *bp12 = new TPad("bp12","bp12",0.66-off,y1,0.99-off,y2);
  y2 = y1-space; y1 = 1./14.*(--nrow)-space1;
  TPad *bp13 = new TPad("bp13","bp13",0.+off,y1,0.33+off,y2); //6
  TPad *bp14 = new TPad("bp14","bp14",0.66-off,y1,0.99-off,y2);
  y2 = y1-space; y1 = 1./14.*(--nrow)-space1;
  TPad *bp15 = new TPad("bp15","bp15",0.+off,y1,0.33+off,y2);
  TPad *bp16 = new TPad("bp16","bp16",0.66-off,y1,0.99-off,y2);
  y2 = y1-space; y1 = 1./14.*(--nrow)-space1;
  TPad *bp17 = new TPad("bp17","bp17",0.+off,y1,0.33+off,y2); //7
  TPad *bp18 = new TPad("bp18","bp18",0.66-off,y1,0.99-off,y2);
  y2 = y1-space; y1 = 1./14.*(--nrow)-space1;
  TPad *bp19 = new TPad("bp19","bp19",0.+off,y1,0.33+off,y2);
  TPad *bp20 = new TPad("bp20","bp20",0.66-off,y1,0.99-off,y2);
  //  cout << " fine bp 20 " << endl;
  //  TLatex* hole  = new TLatex(0.05,0.48,"hole");
  //  TLatex* slot  = new TLatex(0.85,0.48,"slot");
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
  bp19->Draw();
  bp20->Draw();

  ic = 2;
  ipad=0;
  ic=0;
  ipad = 0;
  np = np1 = np2 = npp = 1;

  //ic = 2;
  //Int_t ipad=0;
  for(Int_t i=1; i<5; i++){
    TString hisname = "residual_after_GBL_vs_u_hit_module_L"; hisname += i;
    //    TString hisname = "h_res_gbl_module_L"; hisname  += i;
    hisname += "b_halfmodule_axial_sensor0";
    TString layer = "L"; layer+=i; layer+= "BA"; 
    TH2D *his = (TH2D*) f->Get(hisname.Data());
    TProfile *hpf = (TProfile*)his->ProfileX();

    TString hisnameIni = "residual_after_GBL_vs_u_hit_module_L"; hisnameIni += i;
    //    TString hisnameIni = "h_res_module_L"; hisnameIni  += i;
    hisnameIni += "b_halfmodule_axial_sensor0";
    TH2D *hisIni = (TH2D*) f->Get(hisnameIni.Data());
    ipad++;
    TString pd = "bp"; pd+=ipad;
    TPad *pad = (TPad*) cBot->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    if(his) {//his->Draw("colz");
      hpf->Draw(); zerol->Draw("same");}
    
    hisname = "residual_after_GBL_vs_u_hit_module_L"; hisname += i;
    //    hisname = "h_res_gbl_module_L"; hisname  += i;
    hisname += "b_halfmodule_stereo_sensor0";
    layer = "L"; layer+=i; layer+= "TS"; 
    his = (TH2D*) f->Get(hisname.Data());
    hpf = (TProfile*)his->ProfileX();

    hisnameIni = "residual_after_GBL_vs_u_hit_module_L"; hisnameIni += i;
    //    hisnameIni = "h_res_module_L"; hisnameIni  += i;
    hisnameIni += "b_halfmodule_stereo_sensor0";
    hisIni = (TH2D*) f->Get(hisnameIni.Data());
    ipad++;
    pd = "bp"; pd+=ipad;
    pad = (TPad*) cBot->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    if(his) {//ReverseXAxis(his); his->Draw("colz");}
      TH1 *hpfr = (TH1*)ReverseXAxis1D((TH1D*)hpf);
      hpfr->Draw(); zerol->Draw("same");}
    cout << ipad << " " << his->GetName() << endl;
  }
  cout << " seconda serie " << endl;

  np1=1, np2=1;
  for(Int_t i=5; i<8; i++){
    TString hisname = "residual_after_GBL_vs_u_hit_module_L"; hisname += i;
    //    TString hisname = "h_res_gbl_module_L"; hisname  += i;
    hisname += "b_halfmodule_axial_hole_sensor0";
    TString layer = "L"; layer+=i; layer+= "TAHo"; 
    TH2D *his = (TH2D*) f->Get(hisname.Data());
    TProfile* hpf = (TProfile*)his->ProfileX();

    TString hisnameIni = "residual_after_GBL_vs_u_hit_module_L"; hisnameIni += i;
    //    TString hisnameIni = "h_res_module_L"; hisnameIni  += i;
    hisnameIni += "b_halfmodule_axial_hole_sensor0";
    cout << hisnameIni.Data() << endl;
    TH2D *hisIni = (TH2D*) f->Get(hisnameIni.Data());
    //ipad++;
    //if(his) his->Draw("colz");

    ipad++;
    TString pd = "bp"; pd+=ipad;
    TPad *pad = (TPad*) cBot->GetListOfPrimitives()->FindObject(pd.Data());
    cout << pd.Data() << " " << pad<< endl;
    pad->cd();
    if(his) {//his->Draw("colz");
      hpf->Draw(); zerol->Draw("same");}
    cout << ipad << " " << his->GetName() << endl;

    hisname = "residual_after_GBL_vs_u_hit_module_L"; hisname += i;
    //    hisname = "h_res_gbl_module_L"; hisname  += i;
    hisname += "b_halfmodule_stereo_hole_sensor0";
    layer = "L"; layer+=i; layer+= "TSHo"; 
    his = (TH2D*) f->Get(hisname.Data());
    hpf = (TProfile*)his->ProfileX();

    hisnameIni = "residual_after_GBL_vs_u_hit_module_L"; hisnameIni += i;
    //    hisnameIni = "h_res_module_L"; hisnameIni  += i;
    hisnameIni += "b_halfmodule_stereo_hole_sensor0";
    hisIni = (TH2D*) f->Get(hisnameIni.Data());

    ipad++; ipad++;
    pd = "bp"; pd+=ipad;
    //    cout << pd.Data() << " " << pad << " " << npp << endl;
    pad = (TPad*) cBot->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    if(his) {//ReverseXAxis(his); his->Draw("colz");}
      TH1 *hpfr = (TH1*)ReverseXAxis1D((TH1D*)hpf);
      hpfr->Draw(); zerol->Draw("same");}
    cout << ipad << " " << his->GetName() << endl;
    
    /////////////////////

    cout << "----------- " << ipad << endl;
    //    npp -= 2;
    hisname = "residual_after_GBL_vs_u_hit_module_L"; hisname += i;
    //hisname = "h_res_gbl_module_L"; hisname  += i;
    hisname += "b_halfmodule_axial_slot_sensor0";
    layer = "L"; layer+=i; layer+= "TASl"; 
    his = (TH2D*) f->Get(hisname.Data());
    hpf = (TProfile*)his->ProfileX();

    //    if(his) his->Draw("colz");
    //    cout << ipad << " " << his->GetName() << endl;

    ipad -= 1;
    pd = "bp"; pd+=ipad;
    cout << pd.Data() << endl;
    pad = (TPad*) cBot->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    if(his){//his->Draw("colz");
      hpf->Draw(); zerol->Draw("same");
    }
    cout << ipad << " " << his->GetName() << endl;
    
    hisname = "residual_after_GBL_vs_u_hit_module_L"; hisname += i;
    //hisname = "h_res_gbl_module_L"; hisname  += i;
    hisname += "b_halfmodule_stereo_slot_sensor0";
    layer = "L"; layer+=i; layer+= "TSSl"; 
    his = (TH2D*) f->Get(hisname.Data());
    hpf = (TProfile*)his->ProfileX();

    hisnameIni = "residual_after_GBL_vs_u_hit_module_L"; hisnameIni += i;
    //hisnameIni = "h_res_module_L"; hisnameIni  += i;
    hisnameIni += "b_halfmodule_stereo_slot_sensor0";
    hisIni = (TH2D*) f->Get(hisnameIni.Data());
    //    cBot->cd(ic); ic+=1;
    ipad++; ipad++;
    pd = "bp"; pd+=ipad;
    pad = (TPad*) cBot->GetListOfPrimitives()->FindObject(pd.Data());
    pad->cd();
    if(his) {//ReverseXAxis(his); his->Draw("colz");}
      TH1 *hpfr = (TH1*)ReverseXAxis1D((TH1D*)hpf);
      hpfr->Draw(); zerol->Draw("same");
    }
    cout << ipad << " " << his->GetName() << endl;
    
  }



  //  outf.close();
  cTop->SaveAs(topName.Data());
  cBot->SaveAs(botName.Data());


}
