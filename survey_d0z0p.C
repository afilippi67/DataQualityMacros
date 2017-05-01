#include "TFile.h"
#include "TString.h"
#include "TF1.h"
#include "TH1.h"
#include "TCanvas.h"
#include "Riostream.h"
#include "TStyle.h"
#include "TPad.h"
#include "TPaveStats.h"
#include "TList.h"
#include "TText.h"
#include "TLatex.h"

void survey_d0z0p(const Char_t* filename){
  TString file=filename;
  TFile *f = new TFile(file.Data());
  gStyle->SetStatH(0.5);  gStyle->SetStatW(0.5);  
  TCanvas *c = new TCanvas("c","c",800,1000);
  TH1F *his1 = (TH1F*)f->Get("h_d0_gbl_top");
  TH1F *his2 = (TH1F*)f->Get("h_d0_gbl_bot");
  TH1F *his3 = (TH1F*)f->Get("h_z0_gbl_top");
  TH1F *his4 = (TH1F*)f->Get("h_z0_gbl_bot");
  TH1F *his5 = (TH1F*)f->Get("h_p_gbl_top");
  TH1F *his6 = (TH1F*)f->Get("h_p_gbl_bot");
  TH1F *his7 = (TH1F*)f->Get("h_clParGBL_res_xT_top");
  TH1F *his8 = (TH1F*)f->Get("h_clParGBL_res_xT_bot");
  TH1F *his9 = (TH1F*)f->Get("h_clParGBL_res_yT_top");
  TH1F *his10 = (TH1F*)f->Get("h_clParGBL_res_yT_bot");

  his1->SetStats(kTRUE);
  his7->SetStats(kTRUE);
  his8->SetStats(kTRUE);
  his9->SetStats(kTRUE);
  his10->SetStats(kTRUE);

  his2->SetFillStyle(3004);
  his2->SetLineColor(kRed);
  his2->SetFillColor(kRed);
  his1->SetFillStyle(3005);
  his1->SetLineColor(kBlack);
  his1->SetFillColor(kBlack);
  his4->SetFillStyle(3004);
  his4->SetLineColor(kRed);
  his4->SetFillColor(kRed);
  his3->SetFillStyle(3005);
  his3->SetLineColor(kBlack);
  his3->SetFillColor(kBlack);
  his6->SetFillStyle(3004);
  his6->SetLineColor(kRed);
  his6->SetFillColor(kRed);
  his5->SetFillStyle(3005);
  his5->SetLineColor(kBlack);
  his5->SetFillColor(kBlack);
  his8->SetFillStyle(3004);
  his8->SetLineColor(kRed);
  his8->SetFillColor(kRed);
  his7->SetFillStyle(3005);
  his7->SetLineColor(kBlack);
  his7->SetFillColor(kBlack);
  his10->SetFillStyle(3004);
  his10->SetLineColor(kRed);
  his10->SetFillColor(kRed);
  his9->SetFillStyle(3005);
  his9->SetLineColor(kBlack);
  his9->SetFillColor(kBlack);

  his1->GetYaxis()->SetTitle("entries/(80 #mum)");
  his2->GetYaxis()->SetTitle("entries/(80 #mum)");
  his3->GetYaxis()->SetTitle("entries/(52 #mum)");
  his4->GetYaxis()->SetTitle("entries/(52 #mum)");
  his5->GetXaxis()->SetTitle("track momentum [GeV/c]");
  his5->GetYaxis()->SetTitle("entries/(20 MeV/c)");
  his6->GetXaxis()->SetTitle("track momentum, [GeV/c]");
  his6->GetYaxis()->SetTitle("entries/(20 MeV/c)");
  his7->GetXaxis()->SetTitle("x_{T} at z=0 [mm]");
  his7->GetYaxis()->SetTitle("entries/(120 #mum)");
  his8->GetXaxis()->SetTitle("x_{T} at z=0 [mm]");
  his8->GetYaxis()->SetTitle("entries/(120 #mum)");
  his9->GetXaxis()->SetTitle("y_{T} at z=0 [mm]");
  his9->GetYaxis()->SetTitle("entries/(120 #mum)");
  his10->GetXaxis()->SetTitle("y_{T} at z=0 [mm]");
  his10->GetYaxis()->SetTitle("entries/(120 #mum)");

  c->Divide(2,3);
  Int_t pad=1;
  c->cd(pad++); 
  his1->Fit("gaus",""); TF1 *fit = his1->GetFunction("gaus"); fit->SetLineColor(kBlack);
  TPaveStats *st = (TPaveStats*)his1->FindObject("stats");
  st->SetOptFit(1111); st->SetY1NDC(0.53); st->SetX1NDC(0.53); 
  his1->Draw();
  Double_t mean_top = fit->GetParameter(1);
  c->cd(pad++); his2->Fit("gaus"); fit = his2->GetFunction("gaus"); fit->SetLineColor(kRed);
  st = (TPaveStats*)his2->FindObject("stats");
  st->SetOptFit(1111); st->SetY1NDC(0.53); st->SetX1NDC(0.53); 
  his2->Draw();
  Double_t mean_bot = fit->GetParameter(1);
  Double_t meanD0 = mean_top - mean_bot;
  cout<< " delta d0 " << meanD0 << " mm" << endl;
  cout << "----------" << endl; 
  c->cd(pad++); his3->Fit("gaus"); fit = his3->GetFunction("gaus"); fit->SetLineColor(kBlack);
  st = (TPaveStats*)his3->FindObject("stats");
  st->SetOptFit(1111); st->SetY1NDC(0.55); st->SetX1NDC(0.55); 
  his3->Draw();
  mean_top = fit->GetParameter(1);
  c->cd(pad++); his4->Fit("gaus"); fit = his4->GetFunction("gaus"); fit->SetLineColor(kRed);
  st = (TPaveStats*)his4->FindObject("stats");
  st->SetOptFit(1111); st->SetY1NDC(0.55); st->SetX1NDC(0.55); 
  his4->Draw();
  mean_bot = fit->GetParameter(1);
  Double_t meanZ0 = mean_top - mean_bot;
  cout<< " delta z0 " << meanZ0 << " mm" << endl;
  cout << "----------" << endl; 

  c->cd(pad++);
  Float_t binc = -1;
  // find the first bin with zero content, this is the final bin
  // start form 500 MeV
  Int_t start = his5->FindBin(0.5);
  Int_t i;
  for (i=start;i<his5->GetNbinsX();i++){
    binc = his5->GetBinContent(i);
    if(binc == 0.) break;
  }
  Int_t limit = i;
  his5->GetXaxis()->SetRangeUser(his5->GetXaxis()->GetBinCenter(limit/2.), his5->GetXaxis()->GetBinCenter(limit)); 
  Int_t maxPeak = his5->GetMaximumBin();
  cout << limit << " " << his5->GetXaxis()->GetBinCenter(maxPeak) << endl;
  Double_t wid;
  if((his5->GetXaxis()->GetBinCenter(maxPeak))>2.){
    wid=0.25;
  }else{
    //    wid=0.15;
    wid=0.17;
  }
  Float_t low = his5->GetXaxis()->GetBinCenter(maxPeak) - wid;
  Float_t up = his5->GetXaxis()->GetBinCenter(maxPeak) + wid;
  his5->GetXaxis()->UnZoom();
  his5->Fit("gaus","","",low,up); fit = his5->GetFunction("gaus"); fit->SetLineColor(kBlack);
  st = (TPaveStats*)his5->FindObject("stats");
  st->SetOptFit(1111); st->SetY1NDC(0.53); st->SetX1NDC(0.53); 
  his5->Draw();
  mean_top = fit->GetParameter(1);

  his6->GetXaxis()->SetRangeUser(his6->GetXaxis()->GetBinCenter(limit/2.), his6->GetXaxis()->GetBinCenter(limit)); 
  maxPeak = his6->GetMaximumBin();
  low = his6->GetXaxis()->GetBinCenter(maxPeak) - wid;
  up = his6->GetXaxis()->GetBinCenter(maxPeak) + wid;
  his6->GetXaxis()->UnZoom();
  c->cd(pad++); his6->Fit("gaus","","",low,up); fit = his6->GetFunction("gaus"); fit->SetLineColor(kRed);
  st = (TPaveStats*)his6->FindObject("stats");
  st->SetOptFit(1111); st->SetY1NDC(0.53); st->SetX1NDC(0.53); 
  his6->Draw();
  mean_bot = fit->GetParameter(1);
  Double_t meanP = mean_top - mean_bot;
  cout<< " delta p " << meanP << " GeV/c" << endl;
  cout << "----------" << endl; 

  c->SaveAs("survey_d0z0p.gif");

  //////////////////////////////////////

  TCanvas *aux = new TCanvas();
  his7->Fit("gaus",""); fit = his7->GetFunction("gaus"); fit->SetLineColor(kBlack);
  st = (TPaveStats*)his7->FindObject("stats");
  st->SetOptFit(1111); gPad->Update(); 
  his8->Fit("gaus",""); fit = his8->GetFunction("gaus"); fit->SetLineColor(kRed);
  st = (TPaveStats*)his8->FindObject("stats");
  st->SetOptFit(1111); gPad->Update();
  Double_t diffXT = his7->GetFunction("gaus")->GetParameter(1) - his8->GetFunction("gaus")->GetParameter(1); 
 
  his9->Fit("gaus",""); fit = his9->GetFunction("gaus"); fit->SetLineColor(kBlack);
  st = (TPaveStats*)his9->FindObject("stats");
  st->SetOptFit(1111); gPad->Update();
  his10->Fit("gaus",""); fit = his10->GetFunction("gaus"); fit->SetLineColor(kRed);
  st = (TPaveStats*)his10->FindObject("stats");
  st->SetOptFit(1111); gPad->Update();
  Double_t diffYT = his9->GetFunction("gaus")->GetParameter(1) - his10->GetFunction("gaus")->GetParameter(1); 

  delete aux;

  ///////////////////////////////////////////


  TCanvas *d0 = new TCanvas();
  TCanvas *z0 = new TCanvas();
  TCanvas *pmom = new TCanvas();
  TCanvas *xT = new TCanvas();
  TCanvas *yT = new TCanvas();

  TH1F *his1c = (TH1F*) his1->Clone();
  TPaveStats *stc1 = (TPaveStats*)his1c->FindObject("stats");
  stc1->SetOptFit(1); 
  TList *listOfLines1 = stc1->GetListOfLines();
  TText *tconst1 = stc1->GetLineWith("Mean"); listOfLines1->Remove(tconst1);
  tconst1 = stc1->GetLineWith("RMS");         listOfLines1->Remove(tconst1);
  tconst1 = stc1->GetLineWith("Underflow");   listOfLines1->Remove(tconst1);
  tconst1 = stc1->GetLineWith("Overflow");    listOfLines1->Remove(tconst1);
  tconst1 = stc1->GetLineWith("ndf");         listOfLines1->Remove(tconst1);
  tconst1 = stc1->GetLineWith("Prob");        listOfLines1->Remove(tconst1);
  tconst1 = stc1->GetLineWith("Constant");    listOfLines1->Remove(tconst1);
  stc1->SetY1NDC(0.75); stc1->SetX1NDC(0.55); 
  gPad->Update();
  
  TH1F *his2c = (TH1F*) his2->Clone();
  TPaveStats *stc2 = (TPaveStats*)his2c->FindObject("stats");
  stc2->SetOptFit(1); 
  TList *listOfLines2 = stc2->GetListOfLines();
  TText *tconst2 = stc2->GetLineWith("Mean"); listOfLines2->Remove(tconst2);
  tconst2 = stc2->GetLineWith("RMS");         listOfLines2->Remove(tconst2);
  tconst2 = stc2->GetLineWith("Underflow");   listOfLines2->Remove(tconst2);
  tconst2 = stc2->GetLineWith("Overflow");    listOfLines2->Remove(tconst2);
  tconst2 = stc2->GetLineWith("ndf");         listOfLines2->Remove(tconst2);
  tconst2 = stc2->GetLineWith("Prob");        listOfLines2->Remove(tconst2);
  tconst2 = stc2->GetLineWith("Constant");    listOfLines2->Remove(tconst2);
  stc2->SetY1NDC(0.55);  stc2->SetX1NDC(0.55);
  stc2->SetY2NDC(0.735); stc2->SetX2NDC(0.98);
  stc2->SetTextColor(kRed);
  gPad->Update();

  if(his1c->GetMaximum() < his2c->GetMaximum()){ 
    d0->cd(); 
    TH1F *his2cc = (TH1F*) his2c->Clone();
    his2cc->Draw(); his2c->Draw("same");
    his1c->Draw("same");
  }else{
    d0->cd(); 
    TH1F *his1cc = (TH1F*) his1c->Clone();
    his1cc->Draw(); his1c->Draw("same");
    his2c->Draw("same");
  }
  TString num = "#Deltad_{0} = "; 
  TString n = TString::Format("%1.3f", meanD0);
  num += n; num += " mm";
  TLatex *lab1 = new TLatex(
			    0.6*(his1c->GetXaxis()->GetXmax()-his1c->GetXaxis()->GetXmin())+his1c->GetXaxis()->GetXmin(), 
			    0.4*1.2*his1c->GetMaximum(), num.Data());
  lab1->SetTextColor(kViolet);
  lab1->Draw("same");
  

  TH1F *his3c = (TH1F*) his3->Clone();
  TPaveStats *stc3 = (TPaveStats*)his3c->FindObject("stats");
  stc3->SetOptFit(1); 
  TList *listOfLines3 = stc3->GetListOfLines();
  TText *tconst3 = stc3->GetLineWith("Mean"); listOfLines3->Remove(tconst3);
  tconst3 = stc3->GetLineWith("RMS");         listOfLines3->Remove(tconst3);
  tconst3 = stc3->GetLineWith("Underflow");   listOfLines3->Remove(tconst3);
  tconst3 = stc3->GetLineWith("Overflow");    listOfLines3->Remove(tconst3);
  tconst3 = stc3->GetLineWith("ndf");         listOfLines3->Remove(tconst3);
  tconst3 = stc3->GetLineWith("Prob");        listOfLines3->Remove(tconst3);
  tconst3 = stc3->GetLineWith("Constant");    listOfLines3->Remove(tconst3);
  stc3->SetY1NDC(0.75); stc3->SetX1NDC(0.55); 
  gPad->Update();
  
  TH1F *his4c = (TH1F*) his4->Clone();
  TPaveStats *stc4 = (TPaveStats*)his4c->FindObject("stats");
  stc4->SetOptFit(1); 
  TList *listOfLines4 = stc4->GetListOfLines();
  TText *tconst4 = stc4->GetLineWith("Mean"); listOfLines4->Remove(tconst4);
  tconst4 = stc4->GetLineWith("RMS");         listOfLines4->Remove(tconst4);
  tconst4 = stc4->GetLineWith("Underflow");   listOfLines4->Remove(tconst4);
  tconst4 = stc4->GetLineWith("Overflow");    listOfLines4->Remove(tconst4);
  tconst4 = stc4->GetLineWith("ndf");         listOfLines4->Remove(tconst4);
  tconst4 = stc4->GetLineWith("Prob");        listOfLines4->Remove(tconst4);
  tconst4 = stc4->GetLineWith("Constant");    listOfLines4->Remove(tconst4);
  stc4->SetY1NDC(0.55);  stc4->SetX1NDC(0.55);
  stc4->SetY2NDC(0.735); stc4->SetX2NDC(0.98);
  stc4->SetTextColor(kRed);
  gPad->Update();

  if(his3c->GetMaximum() < his4c->GetMaximum()){ 
    z0->cd(); 
    TH1F *his4cc = (TH1F*) his4c->Clone();
    his4cc->Draw(); his4c->Draw("same");
    his3c->Draw("same");
  }else{
    z0->cd(); 
    TH1F *his3cc = (TH1F*) his3c->Clone();
    his3cc->Draw(); his3c->Draw("same");
    his4c->Draw("same");
  }
  num = "#Deltaz_{0} = "; 
  n = TString::Format("%1.3f", meanZ0);
  num += n; num += " mm";
  TLatex *lab2 = new TLatex(
			    0.6*(his3c->GetXaxis()->GetXmax()-his3c->GetXaxis()->GetXmin())+his3c->GetXaxis()->GetXmin(), 
			    0.4*1.2*his3c->GetMaximum(), num.Data());
  lab2->SetTextColor(kViolet);
  lab2->Draw("same");


  TH1F *his5c = (TH1F*) his5->Clone();
  TPaveStats *stc5 = (TPaveStats*)his5c->FindObject("stats");
  stc5->SetOptFit(1); 
  TList *listOfLines5 = stc5->GetListOfLines();
  TText *tconst5 = stc5->GetLineWith("Mean"); listOfLines5->Remove(tconst5);
  tconst5 = stc5->GetLineWith("RMS");         listOfLines5->Remove(tconst5);
  tconst5 = stc5->GetLineWith("Underflow");   listOfLines5->Remove(tconst5);
  tconst5 = stc5->GetLineWith("Overflow");    listOfLines5->Remove(tconst5);
  tconst5 = stc5->GetLineWith("ndf");         listOfLines5->Remove(tconst5);
  tconst5 = stc5->GetLineWith("Prob");        listOfLines5->Remove(tconst5);
  tconst5 = stc5->GetLineWith("Constant");    listOfLines5->Remove(tconst5);
  stc5->SetY1NDC(0.75); stc5->SetX1NDC(0.55); 
  gPad->Update();
  
  TH1F *his6c = (TH1F*) his6->Clone();
  TPaveStats *stc6 = (TPaveStats*)his6c->FindObject("stats");
  stc6->SetOptFit(11); 
  TList *listOfLines6 = stc6->GetListOfLines();
  TText *tconst6 = stc6->GetLineWith("Mean"); listOfLines6->Remove(tconst6);
  tconst6 = stc6->GetLineWith("RMS");         listOfLines6->Remove(tconst6);
  tconst6 = stc6->GetLineWith("Underflow");   listOfLines6->Remove(tconst6);
  tconst6 = stc6->GetLineWith("Overflow");    listOfLines6->Remove(tconst6);
  tconst6 = stc6->GetLineWith("ndf");         listOfLines6->Remove(tconst6);
  tconst6 = stc6->GetLineWith("Prob");        listOfLines6->Remove(tconst6);
  tconst6 = stc6->GetLineWith("Constant");    listOfLines6->Remove(tconst6);
  stc6->SetY1NDC(0.55); stc6->SetX1NDC(0.55);
  stc6->SetY2NDC(0.735); stc6->SetX2NDC(0.98);
  stc6->SetTextColor(kRed);
  gPad->Update();
  
  if(his5c->GetMaximum() < his6c->GetMaximum()){
    pmom->cd(); 
    TH1F *his6cc = (TH1F*) his6c->Clone();
    his6cc->Draw(); his6c->Draw("same"); 
    his5c->Draw("same"); 
  }else{
    pmom->cd();
    TH1F *his5cc = (TH1F*) his5c->Clone();
    his5cc->Draw(); his5c->Draw("same");
    his6c->Draw("same");
  }
  num = "#Deltap_{el} = "; 
  n = TString::Format("%1.3f", meanP);
  num += n; num += " GeV/c";
  Double_t x1 = 0.2*(his5c->GetXaxis()->GetXmax()-his5c->GetXaxis()->GetXmin())+his5c->GetXaxis()->GetXmin();
  Double_t y1 = 0.1*1.2*his5c->GetMaximum();
  TLatex *lab3 = new TLatex(x1, y1, num.Data());
  lab3->SetTextColor(kViolet);

  cout << x1 << " " << y1 << endl;
  TBox *box = new TBox(x1-0.08, 
		       y1-0.6*his1c->GetMaximum()/30.,
		       x1+1.1, 
		       y1+his1c->GetMaximum()/30.);
  box->Draw("same");
  lab3->Draw("same");


  TH1F *his7c = (TH1F*) his7->Clone();
  TPaveStats *stc7 = (TPaveStats*)his7c->FindObject("stats");
  stc7->SetOptFit(1); 
  TList *listOfLines7 = stc7->GetListOfLines();
  TText *tconst7 = stc7->GetLineWith("Mean"); listOfLines7->Remove(tconst7);
  tconst7 = stc7->GetLineWith("RMS");         listOfLines7->Remove(tconst7);
  tconst7 = stc7->GetLineWith("Underflow");   listOfLines7->Remove(tconst7);
  tconst7 = stc7->GetLineWith("Overflow");    listOfLines7->Remove(tconst7);
  tconst7 = stc7->GetLineWith("ndf");         listOfLines7->Remove(tconst7);
  tconst7 = stc7->GetLineWith("Prob");        listOfLines7->Remove(tconst7);
  tconst7 = stc7->GetLineWith("Constant");    listOfLines7->Remove(tconst7);
  stc7->SetY1NDC(0.75); stc7->SetX1NDC(0.55); 
  gPad->Update();
  
  TH1F *his8c = (TH1F*) his8->Clone();
  TPaveStats *stc8 = (TPaveStats*)his8c->FindObject("stats");
  stc8->SetOptFit(1); 
  TList *listOfLines8 = stc8->GetListOfLines();
  TText *tconst8 = stc8->GetLineWith("Mean"); listOfLines8->Remove(tconst8);
  tconst8 = stc8->GetLineWith("RMS");         listOfLines8->Remove(tconst8);
  tconst8 = stc8->GetLineWith("Underflow");   listOfLines8->Remove(tconst8);
  tconst8 = stc8->GetLineWith("Overflow");    listOfLines8->Remove(tconst8);
  tconst8 = stc8->GetLineWith("ndf");         listOfLines8->Remove(tconst8);
  tconst8 = stc8->GetLineWith("Prob");        listOfLines8->Remove(tconst8);
  tconst8 = stc8->GetLineWith("Constant");    listOfLines8->Remove(tconst8);
  stc8->SetY1NDC(0.55);  stc8->SetX1NDC(0.55);
  stc8->SetY2NDC(0.735); stc8->SetX2NDC(0.98);
  stc8->SetTextColor(kRed);
  gPad->Update();

  if(his7c->GetMaximum() < his8c->GetMaximum()){ 
    xT->cd(); 
    TH1F *his8cc = (TH1F*) his8c->Clone();
    his8cc->Draw(); his8c->Draw("same");
    his7c->Draw("same");
  }else{
    xT->cd(); 
    TH1F *his7cc = (TH1F*) his7c->Clone();
    his7cc->Draw(); his7c->Draw("same");
    his8c->Draw("same");
  }
  num = "#Deltax_{T} = "; 
  n = TString::Format("%1.3f", diffXT);
  num += n; num += " mm";
  TLatex *lab4 = new TLatex(
			    0.6*(his7c->GetXaxis()->GetXmax()-his7c->GetXaxis()->GetXmin())+his7c->GetXaxis()->GetXmin(), 
			    0.4*1.2*his7c->GetMaximum(), num.Data());
  lab4->SetTextColor(kViolet);
  lab4->Draw("same");

  TH1F *his9c = (TH1F*) his9->Clone();
  TPaveStats *stc9 = (TPaveStats*)his9c->FindObject("stats");
  stc9->SetOptFit(1); 
  TList *listOfLines9 = stc9->GetListOfLines();
  TText *tconst9 = stc9->GetLineWith("Mean"); listOfLines9->Remove(tconst9);
  tconst9 = stc9->GetLineWith("RMS");         listOfLines9->Remove(tconst9);
  tconst9 = stc9->GetLineWith("Underflow");   listOfLines9->Remove(tconst9);
  tconst9 = stc9->GetLineWith("Overflow");    listOfLines9->Remove(tconst9);
  tconst9 = stc9->GetLineWith("ndf");         listOfLines9->Remove(tconst9);
  tconst9 = stc9->GetLineWith("Prob");        listOfLines9->Remove(tconst9);
  tconst9 = stc9->GetLineWith("Constant");    listOfLines9->Remove(tconst9);
  stc9->SetY1NDC(0.75); stc9->SetX1NDC(0.55); 
  gPad->Update();
  
  TH1F *his10c = (TH1F*) his10->Clone();
  TPaveStats *stc10 = (TPaveStats*)his10c->FindObject("stats");
  stc10->SetOptFit(1); 
  TList *listOfLines10 = stc10->GetListOfLines();
  TText *tconst10 = stc10->GetLineWith("Mean"); listOfLines10->Remove(tconst10);
  tconst10 = stc10->GetLineWith("RMS");         listOfLines10->Remove(tconst10);
  tconst10 = stc10->GetLineWith("Underflow");   listOfLines10->Remove(tconst10);
  tconst10 = stc10->GetLineWith("Overflow");    listOfLines10->Remove(tconst10);
  tconst10 = stc10->GetLineWith("ndf");         listOfLines10->Remove(tconst10);
  tconst10 = stc10->GetLineWith("Prob");        listOfLines10->Remove(tconst10);
  tconst10 = stc10->GetLineWith("Constant");    listOfLines10->Remove(tconst10);
  stc10->SetY1NDC(0.55);  stc10->SetX1NDC(0.55);
  stc10->SetY2NDC(0.735); stc10->SetX2NDC(0.98);
  stc10->SetTextColor(kRed);
  gPad->Update();

  if(his9c->GetMaximum() < his10c->GetMaximum()){ 
    yT->cd(); 
    TH1F *his10cc = (TH1F*) his10c->Clone();
    his10cc->Draw(); his10c->Draw("same");
    his9c->Draw("same");
  }else{
    yT->cd(); 
    TH1F *his9cc = (TH1F*) his9c->Clone();
    his9cc->Draw(); his9c->Draw("same");
    his10c->Draw("same");
  }
  num = "#Deltay_{T} = "; 
  n = TString::Format("%1.3f", diffYT);
  num += n; num += " mm";
  TLatex *lab5 = new TLatex(
			    0.6*(his9c->GetXaxis()->GetXmax()-his9c->GetXaxis()->GetXmin())+his9c->GetXaxis()->GetXmin(), 
			    0.4*1.2*his9c->GetMaximum(), num.Data());
  lab5->SetTextColor(kViolet);
  lab5->Draw("same");


  d0->SaveAs("d0_tb.gif");
  z0->SaveAs("z0_tb.gif");
  pmom->SaveAs("pmom_tb.gif");
  xT->SaveAs("xT_tb.gif");
  yT->SaveAs("yT_tb.gif");

}
