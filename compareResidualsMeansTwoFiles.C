#include <TFile.h>
#include <TGraph.h>
#include <TCanvas.h>
#include <Riostream.h>
#include <TMath.h>
#include <TAxis.h>
#include <TLine.h>
#include <TLegend.h>
#include <TString.h>
#include <TColor.h>
#include <TGraphErrors.h>

void compareResidualsMeansTwoFiles(const Char_t* type, const Char_t *fname1, const Char_t *fname2){

  // input: plotResiduals.root files!
  TString file1 = fname1;
  TString file2 = fname2;
  TFile *f = new TFile(file1.Data());
  TFile *g = new TFile(file2.Data());
  // curved or straight tracks?
  TString ttyp = type;
  Int_t color1=2, color2=3;
  Double_t limy = 0;
  if(ttyp.Contains("C")){
    color1 = kBlue;
    color2 = kRed;
    limy = 5;
  }else if(ttyp.Contains("S")){
    color1 = kBlue-7;
    color2 = kRed-7;
    limy = 10;
  }else{
    cout << "wrong kind of track, choose C or S" << endl;
  }
  
  TLine *zero = new TLine(0.5, 0., 6.5, 0.);
  zero->SetLineColor(kRed);
  zero->SetLineStyle(3);

  TGraph *top1 = (TGraph*) f->Get("meanTop");
  TGraph *bot1 = (TGraph*) f->Get("meanBot");
  TGraph *top2 = (TGraph*) g->Get("meanTop");
  TGraph *bot2 = (TGraph*) g->Get("meanBot");
  TGraph *top2sh = (TGraph*) g->Get("meanTop");
  Float_t dx1 = 0.0, dx2 = 0.0;
  Double_t x, y;
  Int_t np = top2sh->GetN();
  for(Int_t i=0; i<np ; i++){
    //    top1->GetPoint(i,x,y);
    //    if(i==7 || i==11 || i==15){top1->SetPoint(i, x-dx1, y);}
    //    if(i==10 || i==14 || i==18){top1->SetPoint(i, x+dx1, y);}   
    top2sh->GetPoint(i, x, y);
    top2sh->SetPoint(i, x+dx2, y);
  }
  TLegend *legTop = new TLegend(0.1,0.75,0.3,0.9);
  TLegend *legBot = new TLegend(0.1,0.75,0.3,0.9);

  TCanvas *c = new TCanvas("c","u residual mean", 800,1000);
  c->Divide(1,2);
  c->cd(1);

  top1->GetXaxis()->SetRangeUser(0.5,6.5);
  top1->GetYaxis()->SetRangeUser(-limy,limy);
  top1->GetXaxis()->SetTitle("layer");
  top1->GetYaxis()->SetTitle("u residual mean value [#mum]");
  top1->SetMarkerStyle(20);
  top1->SetMarkerColor(color1);
  top1->SetMarkerSize(0.9);
  top2sh->GetXaxis()->SetRangeUser(0.5,6.5);
  top2sh->GetYaxis()->SetRangeUser(-limy,limy);
  top2sh->GetXaxis()->SetTitle("layer");
  top2sh->GetYaxis()->SetTitle("u residual mean value [#mum]");
  top2sh->SetMarkerStyle(21);
  top2sh->SetMarkerColor(color2);
  legTop->AddEntry(top1,"current geo", "p");
  legTop->AddEntry(top2sh,"new geo", "p");

  top1->Draw("AP");
  zero->Draw("same");
  top2sh->Draw("Psame");
  top1->Draw("Psame");
  legTop->Draw("same");

  c->cd(2);

  bot1->GetXaxis()->SetRangeUser(0.5,6.5);
  bot1->GetYaxis()->SetRangeUser(-limy,limy);
  bot1->GetXaxis()->SetTitle("layer");
  bot1->GetYaxis()->SetTitle("u residual mean value [#mum]");
  bot1->SetMarkerStyle(20);
  bot1->SetMarkerColor(color1);
  bot1->SetMarkerSize(0.9);
  bot2->GetXaxis()->SetRangeUser(0.5,6.5);
  bot2->GetYaxis()->SetRangeUser(-limy,limy);
  bot2->GetXaxis()->SetTitle("layer");
  bot2->GetYaxis()->SetTitle("u residual mean value [#mum]");
  bot2->SetMarkerStyle(21);
  bot2->SetMarkerColor(color2);
  legBot->AddEntry(bot1,"current geo", "p");
  legBot->AddEntry(bot2,"new geo", "p");

  bot1->Draw("AP");
  zero->Draw("same");
  bot2->Draw("Psame");
  bot1->Draw("Psame");
  legBot->Draw("same");

  TString outf = "compareResidualsGBL_"; outf += ttyp; outf += ".gif";
  c->SaveAs(outf.Data());


}
