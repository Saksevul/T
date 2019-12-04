void EnergyQuotient() {

  //Abrimos el archivo que nos interesa y el árbol que queremos leer.
  TFile *FJFile = new TFile("/home/saksevul/T/PYTHIA/FastJet/ak5FJ.root");
  TFile *JetFile = new TFile("/home/saksevul/T/OpenData/Jet_20000/ak5PF.root");
  TFile *BTagFile = new TFile("/home/saksevul/T/OpenData/BTag_20000/ak5PF.root");
  TFile *MinBiasFile = new TFile("/home/saksevul/T/OpenData/MinBias_20000/ak5PF.root");
  TFile *MultiJetFile = new TFile("/home/saksevul/T/OpenData/MultiJet_20000/ak5PF.root");



  TH1F *Energy_Quot__Muon_FJ =(TH1F*)FJFile->Get("Jets_Energy_Quotient__Muon-Jet"); Energy_Quot__Muon_FJ->Scale(1.0/Energy_Quot__Muon_FJ->Integral()); Energy_Quot__Muon_FJ->Rebin();
  TH1F *Energy_Quot__Muon_Jet =(TH1F*)JetFile->Get("Jets_Energy_Quotient__Muon-Jet"); Energy_Quot__Muon_Jet->Scale(1.0/Energy_Quot__Muon_Jet->Integral()); Energy_Quot__Muon_Jet->Rebin();
  TH1F *Energy_Quot__Muon_BTag =(TH1F*)BTagFile->Get("Jets_Energy_Quotient__Muon-Jet"); Energy_Quot__Muon_BTag->Scale(1.0/Energy_Quot__Muon_BTag->Integral()); Energy_Quot__Muon_BTag->Rebin();
  TH1F *Energy_Quot__Muon_MinBias =(TH1F*)MinBiasFile->Get("Jets_Energy_Quotient__Muon-Jet"); Energy_Quot__Muon_MinBias->Scale(1.0/Energy_Quot__Muon_MinBias->Integral()); Energy_Quot__Muon_MinBias->Rebin();
  TH1F *Energy_Quot__Muon_MultiJet =(TH1F*)MultiJetFile->Get("Jets_Energy_Quotient__Muon-Jet"); Energy_Quot__Muon_MultiJet->Scale(1.0/Energy_Quot__Muon_MultiJet->Integral()); Energy_Quot__Muon_MultiJet->Rebin();

  TH1F *CLONE_E_Q__Muon_FJ =(TH1F*)Energy_Quot__Muon_FJ->Clone(); CLONE_E_Q__Muon_FJ->SetMarkerSize(6); CLONE_E_Q__Muon_FJ->SetMarkerStyle(21); CLONE_E_Q__Muon_FJ->SetMarkerColor(14);
  TH1F *CLONE_E_Q__Muon_Jet =(TH1F*)Energy_Quot__Muon_Jet->Clone(); CLONE_E_Q__Muon_Jet->SetMarkerSize(6); CLONE_E_Q__Muon_Jet->SetMarkerStyle(23); CLONE_E_Q__Muon_Jet->SetMarkerColor(42);
  TH1F *CLONE_E_Q__Muon_BTag =(TH1F*)Energy_Quot__Muon_BTag->Clone(); CLONE_E_Q__Muon_BTag->SetMarkerSize(6); CLONE_E_Q__Muon_BTag->SetMarkerStyle(22); CLONE_E_Q__Muon_BTag->SetMarkerColor(33);
  TH1F *CLONE_E_Q__Muon_MinBias =(TH1F*)Energy_Quot__Muon_MinBias->Clone(); CLONE_E_Q__Muon_MinBias->SetMarkerSize(6); CLONE_E_Q__Muon_MinBias->SetMarkerStyle(20); CLONE_E_Q__Muon_MinBias->SetMarkerColor(5);
  TH1F *CLONE_E_Q__Muon_MultiJet =(TH1F*)Energy_Quot__Muon_MultiJet->Clone(); CLONE_E_Q__Muon_MultiJet->SetMarkerSize(6); CLONE_E_Q__Muon_MultiJet->SetMarkerStyle(34); CLONE_E_Q__Muon_MultiJet->SetMarkerColor(8);



  auto   Leg = new TLegend(0.74,0.76,1,1);    Leg->SetTextSize(0.04); Leg->SetFillStyle(0); Leg->SetBorderSize(0);
  Leg->AddEntry(CLONE_E_Q__Muon_FJ, "MC FastJet", "p");
  Leg->AddEntry(CLONE_E_Q__Muon_Jet, "Open-Data PF Jet", "p");
  Leg->AddEntry(CLONE_E_Q__Muon_BTag, "Open-Data PF BTag", "p");
  Leg->AddEntry(CLONE_E_Q__Muon_MinBias, "Open-Data PF MinBias", "p");
  Leg->AddEntry(CLONE_E_Q__Muon_MultiJet, "Open-Data PF MultiJet", "p");

  auto   Legend = new TLegend(0.74,0.76,1,1);    Legend->SetTextSize(0.04); Legend->SetFillStyle(0); Legend->SetBorderSize(0);
  Legend->AddEntry(Energy_Quot__Muon_FJ, "MC FastJet", "lep");
  Legend->AddEntry(Energy_Quot__Muon_Jet, "Open-Data PF Jet", "lep");
  Legend->AddEntry(Energy_Quot__Muon_BTag, "Open-Data PF BTag", "lep");
  Legend->AddEntry(Energy_Quot__Muon_MinBias, "Open-Data PF MinBias", "lep");
  Legend->AddEntry(Energy_Quot__Muon_MultiJet, "Open-Data PF MultiJet", "lep");



  TF1 *Cero = new TF1("Cero","0",0,1.08); Cero->GetYaxis()->SetRangeUser(-2,2); Cero->SetLineColor(14); Cero->SetLineStyle(2); Cero->SetLineWidth(2);
  Cero->SetTitle("Tit;Energ#acute{i}a^{Muon} / Energ#acute{i}a^{Jet}; Error Relativo"); Cero->Draw();
  Cero->GetXaxis()->SetTitleSize(0.15); Cero->GetYaxis()->SetTitleSize(0.12);
  Cero->GetXaxis()->SetLabelSize(0.15); Cero->GetYaxis()->SetLabelSize(0.1); Cero->GetYaxis()->SetTitleOffset(0.4);

  TH1F *Energy_Quot__Error = new TH1F("", "", 100, 0, 2); Energy_Quot__Error->Reset("ICES"); Energy_Quot__Error->Rebin();
  Energy_Quot__Error->SetMarkerSize(4); Energy_Quot__Error->SetLineWidth(2);



  TCanvas* Energy_Quotient__Muon_Jet = new TCanvas("Energy_Quotient__Muon_Jet","Energy_Quotient__Muon_Jet",0,0,3240,2160);
  Energy_Quotient__Muon_Jet -> Divide(1,2,0,0,0);
  TPad *Hist=(TPad*)(Energy_Quotient__Muon_Jet->cd(1));Hist->SetPad(0, 0.25, 1, 1);Hist->SetLeftMargin(0.11);Hist->SetLogy();
  Energy_Quot__Muon_FJ->SetTitle("Cociente Energ#acute{i}a  Mu#acute{o}n/Jet; ; #frac{1}{N_{Tot}} #frac{dN}{dE}");
  Energy_Quot__Muon_FJ->GetXaxis()->SetTitleSize(0.05); Energy_Quot__Muon_FJ->GetYaxis()->SetTitleSize(0.05);
  Energy_Quot__Muon_FJ->GetXaxis()->SetTitleOffset(0.8);Energy_Quot__Muon_FJ->GetYaxis()->SetTitleOffset(1.0);
  Energy_Quot__Muon_FJ->GetXaxis()->SetLabelSize(0.05); Energy_Quot__Muon_FJ->GetYaxis()->SetLabelSize(0.05);
  Energy_Quot__Muon_FJ->SetAxisRange(0.0, 1.04, "X");
  Energy_Quot__Muon_FJ->SetMarkerSize(6); Energy_Quot__Muon_FJ->SetMarkerColor(14); Energy_Quot__Muon_FJ->SetMarkerStyle(21);
  Energy_Quot__Muon_FJ->DrawCopy("P");    Energy_Quot__Muon_FJ->SetMarkerColor(1);  Energy_Quot__Muon_FJ->SetMarkerStyle(25);
  Energy_Quot__Muon_FJ->SetLineWidth(2);  Energy_Quot__Muon_FJ->SetLineColor(1);    Energy_Quot__Muon_FJ->DrawCopy("Esame");
  Energy_Quot__Muon_Jet->SetMarkerSize(6);  Energy_Quot__Muon_Jet->SetMarkerColor(42);Energy_Quot__Muon_Jet->SetMarkerStyle(23);
  Energy_Quot__Muon_Jet->DrawCopy("Psame"); Energy_Quot__Muon_Jet->SetMarkerColor(2); Energy_Quot__Muon_Jet->SetMarkerStyle(32);
  Energy_Quot__Muon_Jet->SetLineWidth(2);   Energy_Quot__Muon_Jet->SetLineColor(2);   Energy_Quot__Muon_Jet->DrawCopy("Esame");
  Energy_Quot__Muon_BTag->SetMarkerSize(6);  Energy_Quot__Muon_BTag->SetMarkerColor(33);Energy_Quot__Muon_BTag->SetMarkerStyle(22);
  Energy_Quot__Muon_BTag->DrawCopy("Psame"); Energy_Quot__Muon_BTag->SetMarkerColor(4); Energy_Quot__Muon_BTag->SetMarkerStyle(26);
  Energy_Quot__Muon_BTag->SetLineWidth(2);   Energy_Quot__Muon_BTag->SetLineColor(4);   Energy_Quot__Muon_BTag->DrawCopy("Esame");
  Energy_Quot__Muon_MinBias->SetMarkerSize(6);  Energy_Quot__Muon_MinBias->SetMarkerColor(5); Energy_Quot__Muon_MinBias->SetMarkerStyle(20);
  Energy_Quot__Muon_MinBias->DrawCopy("Psame"); Energy_Quot__Muon_MinBias->SetMarkerColor(41);Energy_Quot__Muon_MinBias->SetMarkerStyle(24);
  Energy_Quot__Muon_MinBias->SetLineWidth(2);   Energy_Quot__Muon_MinBias->SetLineColor(41);  Energy_Quot__Muon_MinBias->DrawCopy("Esame");
  Energy_Quot__Muon_MultiJet->SetMarkerSize(6);  Energy_Quot__Muon_MultiJet->SetMarkerColor(8); Energy_Quot__Muon_MultiJet->SetMarkerStyle(34);
  Energy_Quot__Muon_MultiJet->DrawCopy("Psame"); Energy_Quot__Muon_MultiJet->SetMarkerColor(32);Energy_Quot__Muon_MultiJet->SetMarkerStyle(28);
  Energy_Quot__Muon_MultiJet->SetLineWidth(2);   Energy_Quot__Muon_MultiJet->SetLineColor(32);  Energy_Quot__Muon_MultiJet->DrawCopy("Esame");
  Leg->Draw(); Legend->Draw();
  TPad *Error=(TPad*)(Energy_Quotient__Muon_Jet->cd(2)); Error->SetPad(0, 0, 1, 0.25); Error->SetLeftMargin(0.11); Error->SetBottomMargin(0.33); Cero->Draw();
  Energy_Quot__Error->Add(Energy_Quot__Muon_FJ,-1); Energy_Quot__Error->Add(Energy_Quot__Muon_Jet,1); Energy_Quot__Error->Divide(Energy_Quot__Muon_Jet);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(23);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(2); Energy_Quot__Error->SetMarkerStyle(32);
  Energy_Quot__Error->SetLineColor(2);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Muon_FJ,-1); Energy_Quot__Error->Add(Energy_Quot__Muon_BTag,1); Energy_Quot__Error->Divide(Energy_Quot__Muon_BTag);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(22);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(4); Energy_Quot__Error->SetMarkerStyle(26);
  Energy_Quot__Error->SetLineColor(4);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Muon_FJ,-1); Energy_Quot__Error->Add(Energy_Quot__Muon_MinBias,1); Energy_Quot__Error->Divide(Energy_Quot__Muon_MinBias);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(20);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(5); Energy_Quot__Error->SetMarkerStyle(24);
  Energy_Quot__Error->SetLineColor(5);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Muon_FJ,-1); Energy_Quot__Error->Add(Energy_Quot__Muon_MultiJet,1); Energy_Quot__Error->Divide(Energy_Quot__Muon_MultiJet);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(34);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(8); Energy_Quot__Error->SetMarkerStyle(28);
  Energy_Quot__Error->SetLineColor(8);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quotient__Muon_Jet->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__Muon-Jet.pdf"); Energy_Quotient__Muon_Jet->Close();

}

void ComPlot(){

  // Le damos algo de personalización al las gráficas..
  // gROOT->ForceStyle();
  // gStyle->SetPadBorderMode(0);    gStyle->SetPadBorderSize(0);
  // gStyle->SetPadTopMargin(0.082);  gStyle->SetPadBottomMargin(0.12);
  // gStyle->SetPadLeftMargin(0.11); gStyle->SetPadRightMargin(0.02);
  gStyle->SetOptStat(0);          //gStyle->SetOptTitle(1);

  // Corremos los macros que nos interesan.
  EnergyQuotient();
}
