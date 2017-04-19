#include <TString.h>
#include <TFile.h>
#include <Riostream.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TProfile.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TF1.h>

void plotSingleSensor(const Char_t *sensor, const Char_t *file){

  gStyle->SetOptStat(0);
  TString filename = file;
  TFile *f1 = new TFile(filename.Data());
  TString sensName = sensor;
  Int_t is = atoi((sensName(0,1)).Data());
  //  cout << is << " " << sensName.Data() << endl;
  TString nam1T;
  TString nam1B;
  TString nam2T;
  TString nam2B;
  TString nam3T;
  TString nam3B;
  // x2	 
  TString nam4T;
  TString nam4B;
  TString nam5T;
  TString nam5B;
  TString nam6T;
  TString nam6B;
  TString nam7T;
  TString nam7B;
  TString nam8T;
  TString nam8B;
  
  TString nam1TS;
  TString nam1BS;
  TString nam2TS;
  TString nam2BS;
  TString nam3TS;
  TString nam3BS;
  TString nam4TS;
  TString nam4BS;
  TString nam5TS;
  TString nam5BS;
  TString nam6TS;
  TString nam6BS;
  TString nam7TS;
  TString nam7BS;
  TString nam8TS;
  TString nam8BS;
  
  // pick up interesting histograms
  if(is<4){
    nam1T = "h_res_module_L"; nam1T+=is; nam1T += "t_halfmodule_axial_sensor0";
    nam1B = "h_res_module_L"; nam1B+=is; nam1B += "b_halfmodule_axial_sensor0";
    nam2T = "h_res_gbl_module_L"; nam2T+=is; nam2T += "t_halfmodule_axial_sensor0";
    nam2B = "h_res_gbl_module_L"; nam2B+=is; nam2B += "b_halfmodule_axial_sensor0";
    nam3T = "h_res_gbl_vs_u_module_L"; nam3T+=is; nam3T += "t_halfmodule_axial_sensor0";
    nam3B = "h_res_gbl_vs_u_module_L"; nam3B+=is; nam3B += "b_halfmodule_axial_sensor0";
    nam4T = "h_res_gbl_vs_vpred_module_L"; nam4T+=is; nam4T += "t_halfmodule_axial_sensor0";
    nam4B = "h_res_gbl_vs_vpred_module_L"; nam4B+=is; nam4B += "b_halfmodule_axial_sensor0";
    nam5T = "h_xy_module_L"; nam5T+=is; nam5T += "t_halfmodule_axial_sensor0";
    nam5B = "h_xy_module_L"; nam5B+=is; nam5B += "b_halfmodule_axial_sensor0";
    nam6T = "h_pred_module_L"; nam6T+=is; nam6T += "t_halfmodule_axial_sensor0";
    nam6B = "h_pred_module_L"; nam6B+=is; nam6B += "b_halfmodule_axial_sensor0";
    nam7T = "h_corrdiff_lambda_module_L"; nam7T+=is; nam7T += "t_halfmodule_axial_sensor0";
    nam7B = "h_corrdiff_lambda_module_L"; nam7B+=is; nam7B += "b_halfmodule_axial_sensor0";
    nam8T = "h_corrdiff_phi_module_L"; nam8T+=is; nam8T += "t_halfmodule_axial_sensor0";
    nam8B = "h_corrdiff_phi_module_L"; nam8B+=is; nam8B += "b_halfmodule_axial_sensor0";

    nam1TS = "h_res_module_L"; nam1TS+=is; nam1TS += "t_halfmodule_stereo_sensor0";
    nam1BS = "h_res_module_L"; nam1BS+=is; nam1BS += "b_halfmodule_stereo_sensor0";
    nam2TS = "h_res_gbl_module_L"; nam2TS+=is; nam2TS += "t_halfmodule_stereo_sensor0";
    nam2BS = "h_res_gbl_module_L"; nam2BS+=is; nam2BS += "b_halfmodule_stereo_sensor0";
    nam3TS = "h_res_gbl_vs_u_module_L"; nam3TS+=is; nam3TS += "t_halfmodule_stereo_sensor0";
    nam3BS = "h_res_gbl_vs_u_module_L"; nam3BS+=is; nam3BS += "b_halfmodule_stereo_sensor0";
    	     	
    nam4TS = "h_res_gbl_vs_vpred_module_L"; nam4TS+=is; nam4TS += "t_halfmodule_stereo_sensor0";
    nam4BS = "h_res_gbl_vs_vpred_module_L"; nam4BS+=is; nam4BS += "b_halfmodule_stereo_sensor0";
    nam5TS = "h_xy_module_L"; nam5TS+=is; nam5TS += "t_halfmodule_stereo_sensor0";
    nam5BS = "h_xy_module_L"; nam5BS+=is; nam5BS += "b_halfmodule_stereo_sensor0";
    nam6TS = "h_pred_module_L"; nam6TS+=is; nam6TS += "t_halfmodule_stereo_sensor0";
    nam6BS = "h_pred_module_L"; nam6BS+=is; nam6BS += "b_halfmodule_stereo_sensor0";
    nam7TS = "h_corrdiff_lambda_module_L"; nam7TS+=is; nam7TS += "t_halfmodule_stereo_sensor0";
    nam7BS = "h_corrdiff_lambda_module_L"; nam7BS+=is; nam7BS += "b_halfmodule_stereo_sensor0";
    nam8TS = "h_corrdiff_phi_module_L"; nam8TS+=is; nam8TS += "t_halfmodule_stereo_sensor0";
    nam8BS = "h_corrdiff_phi_module_L"; nam8BS+=is; nam8BS += "b_halfmodule_stereo_sensor0";
	       

  }else{
    // is it slot or hole?
    if(sensName.Contains("H")){
      nam1T = "h_res_module_L"; nam1T+=is; nam1T += "t_halfmodule_axial_hole_sensor0";
      nam1B = "h_res_module_L"; nam1B+=is; nam1B += "b_halfmodule_axial_hole_sensor0";
      nam2T = "h_res_gbl_module_L"; nam2T+=is; nam2T += "t_halfmodule_axial_hole_sensor0";
      nam2B = "h_res_gbl_module_L"; nam2B+=is; nam2B += "b_halfmodule_axial_hole_sensor0";
      nam3T = "h_res_gbl_vs_u_module_L"; nam3T+=is; nam3T += "t_halfmodule_axial_hole_sensor0";
      nam3B = "h_res_gbl_vs_u_module_L"; nam3B+=is; nam3B += "b_halfmodule_axial_hole_sensor0";
      
      nam3T = "h_res_gbl_vs_u_module_L"; nam3T+=is; nam3T += "t_halfmodule_axial_hole_sensor0";
      nam3B = "h_res_gbl_vs_u_module_L"; nam3B+=is; nam3B += "b_halfmodule_axial_hole_sensor0";
      
      nam4T = "h_res_gbl_vs_vpred_module_L"; nam4T+=is; nam4T += "t_halfmodule_axial_hole_sensor0";
      nam4B = "h_res_gbl_vs_vpred_module_L"; nam4B+=is; nam4B += "b_halfmodule_axial_hole_sensor0";
      nam5T = "h_xy_module_L"; nam5T+=is; nam5T += "t_halfmodule_axial_hole_sensor0";
      nam5B = "h_xy_module_L"; nam5B+=is; nam5B += "b_halfmodule_axial_hole_sensor0";
      nam6T = "h_pred_module_L"; nam6T+=is; nam6T += "t_halfmodule_axial_hole_sensor0";
      nam6B = "h_pred_module_L"; nam6B+=is; nam6B += "b_halfmodule_axial_hole_sensor0";
      nam7T = "h_corrdiff_lambda_module_L"; nam7T+=is; nam7T += "t_halfmodule_axial_hole_sensor0";
      nam7B = "h_corrdiff_lambda_module_L"; nam7B+=is; nam7B += "b_halfmodule_axial_hole_sensor0";
      nam8T = "h_corrdiff_phi_module_L"; nam8T+=is; nam8T += "t_halfmodule_axial_hole_sensor0";
      nam8B = "h_corrdiff_phi_module_L"; nam8B+=is; nam8B += "b_halfmodule_axial_hole_sensor0";
      
      nam1TS = "h_res_module_L"; nam1TS+=is; nam1TS += "t_halfmodule_stereo_hole_sensor0";
      nam1BS = "h_res_module_L"; nam1BS+=is; nam1BS += "b_halfmodule_stereo_hole_sensor0";
      nam2TS = "h_res_gbl_module_L"; nam2TS+=is; nam2TS += "t_halfmodule_stereo_hole_sensor0";
      nam2BS = "h_res_gbl_module_L"; nam2BS+=is; nam2BS += "b_halfmodule_stereo_hole_sensor0";
      nam3TS = "h_res_gbl_vs_u_module_L"; nam3TS+=is; nam3TS += "t_halfmodule_stereo_hole_sensor0";
      nam3BS = "h_res_gbl_vs_u_module_L"; nam3BS+=is; nam3BS += "b_halfmodule_stereo_hole_sensor0";
      
      nam3TS = "h_res_gbl_vs_u_module_L"; nam3TS+=is; nam3TS += "t_halfmodule_stereo_hole_sensor0";
      nam3BS = "h_res_gbl_vs_u_module_L"; nam3BS+=is; nam3BS += "b_halfmodule_stereo_hole_sensor0";
      
      nam4TS = "h_res_gbl_vs_vpred_module_L"; nam4TS+=is; nam4TS += "t_halfmodule_stereo_hole_sensor0";
      nam4BS = "h_res_gbl_vs_vpred_module_L"; nam4BS+=is; nam4BS += "b_halfmodule_stereo_hole_sensor0";
      nam5TS = "h_xy_module_L"; nam5TS+=is; nam5TS += "t_halfmodule_stereo_hole_sensor0";
      nam5BS = "h_xy_module_L"; nam5BS+=is; nam5BS += "b_halfmodule_stereo_hole_sensor0";
      nam6TS = "h_pred_module_L"; nam6TS+=is; nam6TS += "t_halfmodule_stereo_hole_sensor0";
      nam6BS = "h_pred_module_L"; nam6BS+=is; nam6BS += "b_halfmodule_stereo_hole_sensor0";
      nam7TS = "h_corrdiff_lambda_module_L"; nam7TS+=is; nam7TS += "t_halfmodule_stereo_hole_sensor0";
      nam7BS = "h_corrdiff_lambda_module_L"; nam7BS+=is; nam7BS += "b_halfmodule_stereo_hole_sensor0";
      nam8TS = "h_corrdiff_phi_module_L"; nam8TS+=is; nam8TS += "t_halfmodule_stereo_hole_sensor0";
      nam8BS = "h_corrdiff_phi_module_L"; nam8BS+=is; nam8BS += "b_halfmodule_stereo_hole_sensor0";
      
    }else if(sensName.Contains("S")){
      //      cout << " here I am " << endl;
      nam1T = "h_res_module_L"; nam1T+=is; nam1T += "t_halfmodule_axial_slot_sensor0";
      nam1B = "h_res_module_L"; nam1B+=is; nam1B += "b_halfmodule_axial_slot_sensor0";
      nam2T = "h_res_gbl_module_L"; nam2T+=is; nam2T += "t_halfmodule_axial_slot_sensor0";
      nam2B = "h_res_gbl_module_L"; nam2B+=is; nam2B += "b_halfmodule_axial_slot_sensor0";
      nam3T = "h_res_gbl_vs_u_module_L"; nam3T+=is; nam3T += "t_halfmodule_axial_slot_sensor0";
      nam3B = "h_res_gbl_vs_u_module_L"; nam3B+=is; nam3B += "b_halfmodule_axial_slot_sensor0";
      
      nam3T = "h_res_gbl_vs_u_module_L"; nam3T+=is; nam3T += "t_halfmodule_axial_slot_sensor0";
      nam3B = "h_res_gbl_vs_u_module_L"; nam3B+=is; nam3B += "b_halfmodule_axial_slot_sensor0";
      
      nam4T = "h_res_gbl_vs_vpred_module_L"; nam4T+=is; nam4T += "t_halfmodule_axial_slot_sensor0";
      nam4B = "h_res_gbl_vs_vpred_module_L"; nam4B+=is; nam4B += "b_halfmodule_axial_slot_sensor0";
      nam5T = "h_xy_module_L"; nam5T+=is; nam5T += "t_halfmodule_axial_slot_sensor0";
      nam5B = "h_xy_module_L"; nam5B+=is; nam5B += "b_halfmodule_axial_slot_sensor0";
      nam6T = "h_pred_module_L"; nam6T+=is; nam6T += "t_halfmodule_axial_slot_sensor0";
      nam6B = "h_pred_module_L"; nam6B+=is; nam6B += "b_halfmodule_axial_slot_sensor0";
      nam7T = "h_corrdiff_lambda_module_L"; nam7T+=is; nam7T += "t_halfmodule_axial_slot_sensor0";
      nam7B = "h_corrdiff_lambda_module_L"; nam7B+=is; nam7B += "b_halfmodule_axial_slot_sensor0";
      nam8T = "h_corrdiff_phi_module_L"; nam8T+=is; nam8T += "t_halfmodule_axial_slot_sensor0";
      nam8B = "h_corrdiff_phi_module_L"; nam8B+=is; nam8B += "b_halfmodule_axial_slot_sensor0";
      
      nam1TS = "h_res_module_L"; nam1TS+=is; nam1TS += "t_halfmodule_stereo_slot_sensor0";
      nam1BS = "h_res_module_L"; nam1BS+=is; nam1BS += "b_halfmodule_stereo_slot_sensor0";
      nam2TS = "h_res_gbl_module_L"; nam2TS+=is; nam2TS += "t_halfmodule_stereo_slot_sensor0";
      nam2BS = "h_res_gbl_module_L"; nam2BS+=is; nam2BS += "b_halfmodule_stereo_slot_sensor0";
      nam3TS = "h_res_gbl_vs_u_module_L"; nam3TS+=is; nam3TS += "t_halfmodule_stereo_slot_sensor0";
      nam3BS = "h_res_gbl_vs_u_module_L"; nam3BS+=is; nam3BS += "b_halfmodule_stereo_slot_sensor0";
      
      nam3TS = "h_res_gbl_vs_u_module_L"; nam3TS+=is; nam3TS += "t_halfmodule_stereo_slot_sensor0";
      nam3BS = "h_res_gbl_vs_u_module_L"; nam3BS+=is; nam3BS += "b_halfmodule_stereo_slot_sensor0";
      
      nam4TS = "h_res_gbl_vs_vpred_module_L"; nam4TS+=is; nam4TS += "t_halfmodule_stereo_slot_sensor0";
      nam4BS = "h_res_gbl_vs_vpred_module_L"; nam4BS+=is; nam4BS += "b_halfmodule_stereo_slot_sensor0";
      nam5TS = "h_xy_module_L"; nam5TS+=is; nam5TS += "t_halfmodule_stereo_slot_sensor0";
      nam5BS = "h_xy_module_L"; nam5BS+=is; nam5BS += "b_halfmodule_stereo_slot_sensor0";
      nam6TS = "h_pred_module_L"; nam6TS+=is; nam6TS += "t_halfmodule_stereo_slot_sensor0";
      nam6BS = "h_pred_module_L"; nam6BS+=is; nam6BS += "b_halfmodule_stereo_slot_sensor0";
      nam7TS = "h_corrdiff_lambda_module_L"; nam7TS+=is; nam7TS += "t_halfmodule_stereo_slot_sensor0";
      nam7BS = "h_corrdiff_lambda_module_L"; nam7BS+=is; nam7BS += "b_halfmodule_stereo_slot_sensor0";
      nam8TS = "h_corrdiff_phi_module_L"; nam8TS+=is; nam8TS += "t_halfmodule_stereo_slot_sensor0";
      nam8BS = "h_corrdiff_phi_module_L"; nam8BS+=is; nam8BS += "b_halfmodule_stereo_slot_sensor0";
      
    }else{
      cout << "choose H or S for 4-6 sensors " << endl;
    }
  }
  // top
  TH1F* his1 = (TH1F*)f1->Get(nam1T.Data());
  TH1F* his2 = (TH1F*)f1->Get(nam2T.Data());
  TH2F* his3 = (TH2F*)f1->Get(nam3T.Data());
  TProfile* his3p = (TProfile*)his3->ProfileX();
  TH2F* his4 = (TH2F*)f1->Get(nam4T.Data());
  TProfile* his4p = (TProfile*)his4->ProfileX();
  TH2F* his5 = (TH2F*)f1->Get(nam5T.Data());
  TH2F* his6 = (TH2F*)f1->Get(nam6T.Data());
  TH1F* his7 = (TH1F*)f1->Get(nam7T.Data());
  TH1F* his8 = (TH1F*)f1->Get(nam8T.Data());
  // bot
  TH1F* his1b = (TH1F*)f1->Get(nam1B.Data());
  TH1F* his2b = (TH1F*)f1->Get(nam2B.Data());
  TH2F* his3b = (TH2F*)f1->Get(nam3B.Data());
  TProfile* his3pb = (TProfile*)his3b->ProfileX();
  TH2F* his4b = (TH2F*)f1->Get(nam4B.Data());
  TProfile* his4pb = (TProfile*)his4b->ProfileX();
  TH2F* his5b = (TH2F*)f1->Get(nam5B.Data());
  TH2F* his6b = (TH2F*)f1->Get(nam6B.Data());
  TH1F* his7b = (TH1F*)f1->Get(nam7B.Data());
  TH1F* his8b = (TH1F*)f1->Get(nam8B.Data());
  // top stereo
  TH1F* his1s = (TH1F*)f1->Get(nam1TS.Data());
  TH1F* his2s = (TH1F*)f1->Get(nam2TS.Data());
  TH2F* his3s = (TH2F*)f1->Get(nam3TS.Data());
  TProfile* his3ps = (TProfile*)his3s->ProfileX();
  TH2F* his4s = (TH2F*)f1->Get(nam4TS.Data());
  TProfile* his4ps = (TProfile*)his4s->ProfileX();
  TH2F* his5s = (TH2F*)f1->Get(nam5TS.Data());
  TH2F* his6s = (TH2F*)f1->Get(nam6TS.Data());
  TH1F* his7s = (TH1F*)f1->Get(nam7TS.Data());
  TH1F* his8s = (TH1F*)f1->Get(nam8TS.Data());
  // bot stereo
  TH1F* his1bs = (TH1F*)f1->Get(nam1BS.Data());
  TH1F* his2bs = (TH1F*)f1->Get(nam2BS.Data());
  TH2F* his3bs = (TH2F*)f1->Get(nam3BS.Data());
  TProfile* his3pbs = (TProfile*)his3bs->ProfileX();
  TH2F* his4bs = (TH2F*)f1->Get(nam4BS.Data());
  TProfile* his4pbs = (TProfile*)his4bs->ProfileX();
  TH2F* his5bs = (TH2F*)f1->Get(nam5BS.Data());
  TH2F* his6bs = (TH2F*)f1->Get(nam6BS.Data());
  TH1F* his7bs = (TH1F*)f1->Get(nam7B.Data());
  TH1F* his8bs = (TH1F*)f1->Get(nam8B.Data());
  
  ((TF1*)his1->GetFunction("gaus"))->SetBit(TF1::kNotDraw);
  ((TF1*)his1s->GetFunction("gaus"))->SetBit(TF1::kNotDraw);
  ((TF1*)his2->GetFunction("gaus"))->SetBit(TF1::kNotDraw);
  ((TF1*)his2s->GetFunction("gaus"))->SetBit(TF1::kNotDraw);
  ((TF1*)his7->GetFunction("gaus"))->SetBit(TF1::kNotDraw);
  ((TF1*)his7s->GetFunction("gaus"))->SetBit(TF1::kNotDraw);
  ((TF1*)his8->GetFunction("gaus"))->SetBit(TF1::kNotDraw);
  ((TF1*)his8s->GetFunction("gaus"))->SetBit(TF1::kNotDraw);
  ((TF1*)his1b->GetFunction("gaus"))->SetBit(TF1::kNotDraw);
  ((TF1*)his1bs->GetFunction("gaus"))->SetBit(TF1::kNotDraw);
  ((TF1*)his2b->GetFunction("gaus"))->SetBit(TF1::kNotDraw);
  ((TF1*)his2bs->GetFunction("gaus"))->SetBit(TF1::kNotDraw);
  ((TF1*)his7b->GetFunction("gaus"))->SetBit(TF1::kNotDraw);
  ((TF1*)his7bs->GetFunction("gaus"))->SetBit(TF1::kNotDraw);
  ((TF1*)his8b->GetFunction("gaus"))->SetBit(TF1::kNotDraw);
  ((TF1*)his8bs->GetFunction("gaus"))->SetBit(TF1::kNotDraw);
  
  TString title = "unbiased u residual sensor "; title += sensName.Data(); title += " axial top";
  his1->SetTitle(title.Data());
  title = "unbiased u residual sensor "; title += sensName.Data(); title += " stereo top";
  his1s->SetTitle(title.Data());
  title = "GBL u residual sensor "; title += sensName.Data(); title += " axial top";
  his2->SetTitle(title.Data());
  title = "GBL u residual sensor "; title += sensName.Data(); title += " stereo top";
  his2s->SetTitle(title.Data());
  title = "#lambda kink sensor "; title += sensName.Data(); title += " axial top";
  his7->SetTitle(title.Data());
  title = "#lambda kink sensor "; title += sensName.Data(); title += " stereo top";
  his7s->SetTitle(title.Data());
  title = "#phi kink sensor "; title += sensName.Data(); title += " axial top";
  his8->SetTitle(title.Data());
  title = "#phi kink sensor "; title += sensName.Data(); title += " stereo top";
  his8s->SetTitle(title.Data());
  title = "GBL u residual vs u sensor "; title += sensName.Data(); title += " axial top";
  his3->SetTitle(title.Data());
  title = "GBL residual vs u sensor "; title += sensName.Data(); title += " stereo top";
  his3s->SetTitle(title.Data());
  title = "GBL u residual vs v pred pos sensor "; title += sensName.Data(); title += " axial top";
  his4->SetTitle(title.Data());
  title = "GBL residual vs v pred pos sensor "; title += sensName.Data(); title += " stereo top";
  his4s->SetTitle(title.Data());
  title = "v pos vs u pos sensor "; title += sensName.Data(); title += " axial top";
  /*
  his5->SetTitle(title.Data());
  title = "v pos vs u pos sensor "; title += sensName.Data(); title += " stereo top";
  his5s->SetTitle(title.Data());
  */
  title = "u vs v predicted position sensor "; title += sensName.Data(); title += " axial top";
  his6->SetTitle(title.Data());
  title = "u vs v predicted position sensor "; title += sensName.Data(); title += " stereo top";
  his6s->SetTitle(title.Data());
  

  title = "unbiased u residual sensor "; title += sensName.Data(); title += " stereo bottom";
  his1b->SetTitle(title.Data());
  title = "unbiased u residual sensor "; title += sensName.Data(); title += " axial bottom";
  his1bs->SetTitle(title.Data());
  title = "GBL u residual sensor "; title += sensName.Data(); title += " stereo bottom";
  his2b->SetTitle(title.Data());
  title = "GBL u residual sensor "; title += sensName.Data(); title += " axial bottom";
  his2bs->SetTitle(title.Data());
  title = "#lambda kink sensor "; title += sensName.Data(); title += " stereo bottom";
  his7b->SetTitle(title.Data());
  title = "#lambda kink sensor "; title += sensName.Data(); title += " axial bottom";
  his7bs->SetTitle(title.Data());
  title = "#phi kink sensor "; title += sensName.Data(); title += " stereo bottom";
  his8b->SetTitle(title.Data());
  title = "#phi kink sensor "; title += sensName.Data(); title += " axial bottom";
  his8bs->SetTitle(title.Data());
  title = "GBL u residual vs u sensor "; title += sensName.Data(); title += " stereo bottom";
  his3b->SetTitle(title.Data());
  title = "GBL residual vs u sensor "; title += sensName.Data(); title += " axial bottom";
  his3bs->SetTitle(title.Data());
  title = "GBL u residual vs v pred pos sensor "; title += sensName.Data(); title += " stereo bottom";
  his4b->SetTitle(title.Data());
  title = "GBL residual vs v pred pos sensor "; title += sensName.Data(); title += " axial bottom";
  his4bs->SetTitle(title.Data());
  /*
  title = "v pos vs u pos sensor "; title += sensName.Data(); title += " stereo bottom";
  his5b->SetTitle(title.Data());
  title = "v pos vs u pos sensor "; title += sensName.Data(); title += " axial bottom";
  his5bs->SetTitle(title.Data());
  */
  title = "u vs v predicted position sensor "; title += sensName.Data(); title += " stereo bottom";
  his6b->SetTitle(title.Data());
  title = "u vs v predicted position sensor "; title += sensName.Data(); title += " axial bottom";
  his6bs->SetTitle(title.Data());
  

  his1->SetFillStyle(3001); 
  his1s->SetFillStyle(3001); 
  his2->SetFillStyle(3001); 
  his2s->SetFillStyle(3001); 
  his7->SetFillStyle(3001); 
  his7s->SetFillStyle(3001); 
  his8->SetFillStyle(3001); 
  his8s->SetFillStyle(3001); 
  his1b->SetFillStyle(3001); 
  his1bs->SetFillStyle(3001); 
  his2b->SetFillStyle(3001); 
  his2bs->SetFillStyle(3001); 
  his7b->SetFillStyle(3001); 
  his7bs->SetFillStyle(3001); 
  his8b->SetFillStyle(3001); 
  his8bs->SetFillStyle(3001); 

  his1->SetFillColor(kRed); 
  his1s->SetFillColor(kRed); 
  his2->SetFillColor(kYellow); 
  his2s->SetFillColor(kYellow); 
  his7->SetFillColor(kBlue); 
  his7s->SetFillColor(kBlue); 
  his8->SetFillColor(kGreen); 
  his8s->SetFillColor(kGreen); 
  his1b->SetFillColor(kRed); 
  his1bs->SetFillColor(kRed); 
  his2b->SetFillColor(kYellow); 
  his2bs->SetFillColor(kYellow); 
  his7b->SetFillColor(kBlue); 
  his7bs->SetFillColor(kBlue); 
  his8b->SetFillColor(kGreen); 
  his8bs->SetFillColor(kGreen); 

  TString canName = "sensor "; canName += is;
  TString side = (sensName(0,1)).Data();
  if(sensName.Contains("H")) {canName += " Hole"; side += "_Hole";};
  if(sensName.Contains("S")) {canName += " Slot"; side += "_Slot";};
  TCanvas *cTop = new TCanvas("cTop", (canName+ " top").Data(), 1800,1000);
  TCanvas *cBot = new TCanvas("cBot", (canName+ " bottom").Data(), 1800,1000);
  cTop->Divide(5,4);
  Int_t win=1; cTop->cd(win);
  his1->Draw(); win++; cTop->cd(win);
  his1s->Draw(); win++; cTop->cd(win);
  his2->Draw(); win++; cTop->cd(win);
  his2s->Draw(); win++; cTop->cd(win);
  his7->Draw(); win++; cTop->cd(win);
  his7s->Draw(); win++; cTop->cd(win);
  his8->Draw(); win++; cTop->cd(win);
  his8s->Draw(); win++; cTop->cd(win);
  his3->Draw("colz"); win++; cTop->cd(win);
  his3s->Draw("colz"); win++; cTop->cd(win);
  his3p->Draw(); win++; cTop->cd(win);
  his3ps->Draw(); win++; cTop->cd(win);
  his4->Draw("colz"); win++; cTop->cd(win);
  his4s->Draw("colz"); win++; cTop->cd(win);
  his4p->Draw(); win++; cTop->cd(win);
  his4ps->Draw(); win++; cTop->cd(win);
  /*
    his5->Draw("colz"); win++; cTop->cd(win);
    his5s->Draw("colz"); win++; cTop->cd(win);
  */
  his6->Draw("colz"); win++; cTop->cd(win);
  his6s->Draw("colz");  
  
  cBot->Divide(5,4);
  win=1; cBot->cd(win);
  his1bs->Draw(); win++; cBot->cd(win);
  his1b->Draw(); win++; cBot->cd(win);
  his2bs->Draw(); win++; cBot->cd(win);
  his2b->Draw(); win++; cBot->cd(win);
  his7bs->Draw(); win++; cBot->cd(win);
  his7b->Draw(); win++; cBot->cd(win);
  his8bs->Draw(); win++; cBot->cd(win);
  his8b->Draw(); win++; cBot->cd(win);
  his3bs->Draw("colz"); win++; cBot->cd(win);
  his3b->Draw("colz"); win++; cBot->cd(win);
  his3pbs->Draw("colz"); win++; cBot->cd(win);
  his3pb->Draw("colz"); win++; cBot->cd(win);
  his4bs->Draw("colz"); win++; cBot->cd(win);
  his4b->Draw("colz"); win++; cBot->cd(win);
  his4pbs->Draw(); win++; cBot->cd(win);
  his4pb->Draw(); win++; cBot->cd(win);
  /*
    his5b->Draw("colz"); win++; cBot->cd(win);
    his5bs->Draw("colz"); win++; cBot->cd(win);
  */
  his6b->Draw("colz"); win++; cBot->cd(win);
  his6bs->Draw("colz");
  
  cout << side.Data() << endl;
  TString out = "sensor_"; out+=side; out+="_top_Plots.gif";
  cTop->SaveAs(out.Data());
  out = "sensor_"; out+=side; out+="_bot_Plots.gif";
  cBot->SaveAs(out.Data());

}
