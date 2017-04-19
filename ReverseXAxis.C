#include <TH1.h>
#include <TGaxis.h>
#include <TPad.h>
#include <Riostream.h>

TH1 *ReverseXAxis (TH1 *h)
{
  /*
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
   */
   Int_t totBins = h->GetXaxis()->GetNbins();
   
   TH1D *hrev = new TH1D("hrev",h->GetTitle(), totBins, h->GetXaxis()->GetXmin(), h->GetXaxis()->GetXmax());

   for(Int_t i=1; i<totBins; i++){
     hrev->SetBinContent(totBins-i+1, h->GetBinContent(i));
     hrev->SetBinError(totBins-i+1, h->GetBinError(i));
   }
   //   hrev->Draw();
   return hrev;
}
