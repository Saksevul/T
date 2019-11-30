void EnergyQuotient() {

  //Abrimos el archivo que nos interesa y el árbol que queremos leer.
  TFile *FJFile = new TFile("/home/saksevul/T/PYTHIA/FastJet/ak5FJ.root");
  TFile *JetFile = new TFile("/home/saksevul/T/OpenData/Jet_20000/ak5PF.root");
  TFile *BTagFile = new TFile("/home/saksevul/T/OpenData/BTag_20000/ak5PF.root");
  TFile *MinBiasFile = new TFile("/home/saksevul/T/OpenData/MinBias_20000/ak5PF.root");
  TFile *MultiJetFile = new TFile("/home/saksevul/T/OpenData/MultiJet_20000/ak5PF.root");



  TH1F *Energy_Quot__Muon_FJ =(TH1F*)FJFile->Get("Jets_Energy_Quotient__Muon-Jet"); Energy_Quot__Muon_FJ->Scale(1.0/Energy_Quot__Muon_FJ->Integral());
  TH1F *Energy_Quot__Muon_Jet =(TH1F*)JetFile->Get("Jets_Energy_Quotient__Muon-Jet"); Energy_Quot__Muon_Jet->Scale(1.0/Energy_Quot__Muon_Jet->Integral());
  TH1F *Energy_Quot__Muon_BTag =(TH1F*)BTagFile->Get("Jets_Energy_Quotient__Muon-Jet"); Energy_Quot__Muon_BTag->Scale(1.0/Energy_Quot__Muon_BTag->Integral());
  TH1F *Energy_Quot__Muon_MinBias =(TH1F*)MinBiasFile->Get("Jets_Energy_Quotient__Muon-Jet"); Energy_Quot__Muon_MinBias->Scale(1.0/Energy_Quot__Muon_MinBias->Integral());
  TH1F *Energy_Quot__Muon_MultiJet =(TH1F*)MultiJetFile->Get("Jets_Energy_Quotient__Muon-Jet"); Energy_Quot__Muon_MultiJet->Scale(1.0/Energy_Quot__Muon_MultiJet->Integral());

    TH1F *CLONE_E_Q__Muon_FJ =(TH1F*)Energy_Quot__Muon_FJ->Clone(); CLONE_E_Q__Muon_FJ->Rebin();
    TH1F *CLONE_E_Q__Muon_Jet =(TH1F*)Energy_Quot__Muon_Jet->Clone();
    TH1F *CLONE_E_Q__Muon_BTag =(TH1F*)Energy_Quot__Muon_BTag->Clone();
    TH1F *CLONE_E_Q__Muon_MinBias =(TH1F*)Energy_Quot__Muon_MinBias->Clone();
    TH1F *CLONE_E_Q__Muon_MultiJet =(TH1F*)Energy_Quot__Muon_MultiJet->Clone();


  auto   Leg = new TLegend(0.8,0.70,1,1);    Leg->SetTextSize(0.04); Leg->SetFillStyle(0); Leg->SetBorderSize(0);
    Leg->AddEntry(CLONE_E_Q__Muon_FJ, "MC FastJet", "p");
    Leg->AddEntry(CLONE_E_Q__Muon_Jet, "Open-Data PF Jet", "p");
    Leg->AddEntry(CLONE_E_Q__Muon_BTag, "Open-Data PF BTag", "p");
    Leg->AddEntry(CLONE_E_Q__Muon_MinBias, "Open-Data PF MinBias", "p");
    Leg->AddEntry(CLONE_E_Q__Muon_MultiJet, "Open-Data PF MultiJet", "p");

    CLONE_E_Q__Muon_FJ->SetMarkerSize(4); CLONE_E_Q__Muon_FJ->SetMarkerStyle(21); CLONE_E_Q__Muon_FJ->SetMarkerColor(14);
    CLONE_E_Q__Muon_Jet->SetMarkerSize(4); CLONE_E_Q__Muon_Jet->SetMarkerStyle(23); CLONE_E_Q__Muon_Jet->SetMarkerColor(42);
    CLONE_E_Q__Muon_BTag->SetMarkerSize(4); CLONE_E_Q__Muon_BTag->SetMarkerStyle(22); CLONE_E_Q__Muon_BTag->SetMarkerColor(33);
    CLONE_E_Q__Muon_MinBias->SetMarkerSize(4); CLONE_E_Q__Muon_MinBias->SetMarkerStyle(20); CLONE_E_Q__Muon_MinBias->SetMarkerColor(5);
    CLONE_E_Q__Muon_MultiJet->SetMarkerSize(4); CLONE_E_Q__Muon_MultiJet->SetMarkerStyle(34); CLONE_E_Q__Muon_MultiJet->SetMarkerColor(8);


  auto   legend = new TLegend(0.8,0.70,1,1);    legend->SetTextSize(0.04); legend->SetFillStyle(0); legend->SetBorderSize(0);
    legend->AddEntry(Energy_Quot__Muon_FJ, "MC FastJet", "lep");
    legend->AddEntry(Energy_Quot__Muon_Jet, "Open-Data PF Jet", "lep");
    legend->AddEntry(Energy_Quot__Muon_BTag, "Open-Data PF BTag", "lep");
    legend->AddEntry(Energy_Quot__Muon_MinBias, "Open-Data PF MinBias", "lep");
    legend->AddEntry(Energy_Quot__Muon_MultiJet, "Open-Data PF MultiJet", "lep");



  TCanvas* Energy_Quotient__Muon_Jet = new TCanvas("Energy_Quotient__Muon_Jet","Energy_Quotient__Muon_Jet",10,10,2160,2160);
  Energy_Quotient__Muon_Jet -> Divide(1,2,0,0); Energy_Quotient__Muon_Jet -> cd(1);

  TPad *Pad1=(TPad*)(Energy_Quotient__Muon_Jet->cd(1));
  Pad1->SetLogy();  Pad1->SetPad(0, 0.2, 1, 1);  Pad1->SetRightMargin(0.001);  Pad1->SetLeftMargin(0.1);

  Energy_Quotient__Muon_Jet->SetFillColor(0);  Energy_Quotient__Muon_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  Energy_Quot__Muon_FJ->SetTitle("Cociente Energ#acute{i}a  Mu#acute{o}n/Jet; Energ#acute{i}a^{Muon} / Energ#acute{i}a^{Jet}; #frac{1}{N_{Tot}} #frac{dN}{dE}");
  Energy_Quot__Muon_FJ->GetXaxis()->SetLabelSize(0.05); Energy_Quot__Muon_FJ->GetYaxis()->SetLabelSize(0.05);
  Energy_Quot__Muon_FJ->GetXaxis()->SetTitleSize(0.05); Energy_Quot__Muon_FJ->GetYaxis()->SetTitleSize(0.05);
  Energy_Quot__Muon_FJ->GetXaxis()->SetTitleOffset(0.8);Energy_Quot__Muon_FJ->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Energy_Quot__Muon_FJ->Rebin(); Energy_Quot__Muon_FJ->SetAxisRange(0.0, 1.09, "X");
  Energy_Quot__Muon_FJ->SetMarkerSize(4); Energy_Quot__Muon_FJ->SetMarkerColor(14); Energy_Quot__Muon_FJ->SetMarkerStyle(21);
  Energy_Quot__Muon_FJ->DrawCopy("P");    Energy_Quot__Muon_FJ->SetMarkerColor(1);  Energy_Quot__Muon_FJ->SetMarkerStyle(25);
  Energy_Quot__Muon_FJ->SetLineWidth(4);  Energy_Quot__Muon_FJ->SetLineColor(1);    Energy_Quot__Muon_FJ->DrawCopy("Esame");
  Energy_Quot__Muon_Jet->Rebin();
  Energy_Quot__Muon_Jet->SetMarkerSize(4);  Energy_Quot__Muon_Jet->SetMarkerColor(42);Energy_Quot__Muon_Jet->SetMarkerStyle(23);
  Energy_Quot__Muon_Jet->DrawCopy("Psame"); Energy_Quot__Muon_Jet->SetMarkerColor(2); Energy_Quot__Muon_Jet->SetMarkerStyle(32);
  Energy_Quot__Muon_Jet->SetLineWidth(4);   Energy_Quot__Muon_Jet->SetLineColor(2);   Energy_Quot__Muon_Jet->DrawCopy("Esame");
  Energy_Quot__Muon_BTag->Rebin();
  Energy_Quot__Muon_BTag->SetMarkerSize(4);  Energy_Quot__Muon_BTag->SetMarkerColor(33);Energy_Quot__Muon_BTag->SetMarkerStyle(22);
  Energy_Quot__Muon_BTag->DrawCopy("Psame"); Energy_Quot__Muon_BTag->SetMarkerColor(4); Energy_Quot__Muon_BTag->SetMarkerStyle(26);
  Energy_Quot__Muon_BTag->SetLineWidth(4);   Energy_Quot__Muon_BTag->SetLineColor(4);   Energy_Quot__Muon_BTag->DrawCopy("Esame");
  Energy_Quot__Muon_MinBias->Rebin();
  Energy_Quot__Muon_MinBias->SetMarkerSize(4);  Energy_Quot__Muon_MinBias->SetMarkerColor(5); Energy_Quot__Muon_MinBias->SetMarkerStyle(20);
  Energy_Quot__Muon_MinBias->DrawCopy("Psame"); Energy_Quot__Muon_MinBias->SetMarkerColor(41);Energy_Quot__Muon_MinBias->SetMarkerStyle(24);
  Energy_Quot__Muon_MinBias->SetLineWidth(4);   Energy_Quot__Muon_MinBias->SetLineColor(41);  Energy_Quot__Muon_MinBias->DrawCopy("Esame");
  Energy_Quot__Muon_MultiJet->Rebin();
  Energy_Quot__Muon_MultiJet->SetMarkerSize(4);  Energy_Quot__Muon_MultiJet->SetMarkerColor(8); Energy_Quot__Muon_MultiJet->SetMarkerStyle(34);
  Energy_Quot__Muon_MultiJet->DrawCopy("Psame"); Energy_Quot__Muon_MultiJet->SetMarkerColor(32);Energy_Quot__Muon_MultiJet->SetMarkerStyle(28);
  Energy_Quot__Muon_MultiJet->SetLineWidth(4);   Energy_Quot__Muon_MultiJet->SetLineColor(32);  Energy_Quot__Muon_MultiJet->DrawCopy("Esame");
  Leg->Draw(); legend->Draw();

  Energy_Quotient__Muon_Jet->cd(2);
  TPad *Pad2=(TPad*)(Energy_Quotient__Muon_Jet->cd(2));  Pad2->SetGridy();
  //Pad2->SetLogy();  //Pad2->SetGridy();
  Pad2->SetPad(0, 0, 1, 0.2);  Pad2->SetRightMargin(0.001);  Pad2->SetLeftMargin(0.1);  Pad2->SetBottomMargin(0.4);

  Energy_Quot__Muon_FJ->SetTitle("; Energ#acute{i}a^{Muon} / Energ#acute{i}a^{Jet}; Error Relativo");
  Energy_Quot__Muon_FJ->GetXaxis()->SetTitleSize(0.2); Energy_Quot__Muon_FJ->GetYaxis()->SetTitleSize(0.2);
  Energy_Quot__Muon_FJ->GetXaxis()->SetLabelSize(0.2); Energy_Quot__Muon_FJ->GetYaxis()->SetLabelSize(0.05);
  Energy_Quot__Muon_FJ->Reset("ICES"); Energy_Quot__Muon_FJ->Add(CLONE_E_Q__Muon_FJ,-1);
  Energy_Quot__Muon_FJ->Add(Energy_Quot__Muon_Jet,1); Energy_Quot__Muon_FJ->Divide(Energy_Quot__Muon_Jet);
  Energy_Quot__Muon_FJ->SetAxisRange(0.0, 1.09, "X"); Energy_Quot__Muon_FJ->SetAxisRange(-2.0, 2.0, "Y");
  Energy_Quot__Muon_FJ->SetMarkerSize(2);Energy_Quot__Muon_FJ->SetMarkerColor(42);Energy_Quot__Muon_FJ->SetMarkerStyle(23);
  Energy_Quot__Muon_FJ->DrawCopy("P");   Energy_Quot__Muon_FJ->SetMarkerColor(1); Energy_Quot__Muon_FJ->SetMarkerStyle(32);
  Energy_Quot__Muon_FJ->SetLineWidth(2); Energy_Quot__Muon_FJ->SetLineColor(1);   Energy_Quot__Muon_FJ->DrawCopy("Esame");
  Energy_Quot__Muon_FJ->Reset("ICES"); Energy_Quot__Muon_FJ->Add(CLONE_E_Q__Muon_FJ,-1);
  Energy_Quot__Muon_FJ->Add(Energy_Quot__Muon_BTag,1); Energy_Quot__Muon_FJ->Divide(Energy_Quot__Muon_BTag);
  Energy_Quot__Muon_FJ->SetMarkerSize(2); Energy_Quot__Muon_FJ->SetMarkerColor(33);Energy_Quot__Muon_FJ->SetMarkerStyle(22);
  Energy_Quot__Muon_FJ->DrawCopy("Psame");Energy_Quot__Muon_FJ->SetMarkerColor(1); Energy_Quot__Muon_FJ->SetMarkerStyle(26);
  Energy_Quot__Muon_FJ->SetLineWidth(2);  Energy_Quot__Muon_FJ->SetLineColor(1);   Energy_Quot__Muon_FJ->DrawCopy("Esame");
  Energy_Quot__Muon_FJ->Reset("ICES"); Energy_Quot__Muon_FJ->Add(CLONE_E_Q__Muon_FJ,-1);
  Energy_Quot__Muon_FJ->Add(Energy_Quot__Muon_MinBias,1); Energy_Quot__Muon_FJ->Divide(Energy_Quot__Muon_MinBias);
  Energy_Quot__Muon_FJ->SetMarkerSize(2); Energy_Quot__Muon_FJ->SetMarkerColor(5); Energy_Quot__Muon_FJ->SetMarkerStyle(20);
  Energy_Quot__Muon_FJ->DrawCopy("Psame");Energy_Quot__Muon_FJ->SetMarkerColor(1);Energy_Quot__Muon_FJ->SetMarkerStyle(24);
  Energy_Quot__Muon_FJ->SetLineWidth(2);  Energy_Quot__Muon_FJ->SetLineColor(1);  Energy_Quot__Muon_FJ->DrawCopy("Esame");
  Energy_Quot__Muon_FJ->Reset("ICES"); Energy_Quot__Muon_FJ->Add(CLONE_E_Q__Muon_FJ,-1);
  Energy_Quot__Muon_FJ->Add(Energy_Quot__Muon_MultiJet,1); Energy_Quot__Muon_FJ->Divide(Energy_Quot__Muon_MultiJet);
  Energy_Quot__Muon_FJ->SetMarkerSize(2); Energy_Quot__Muon_FJ->SetMarkerColor(8); Energy_Quot__Muon_FJ->SetMarkerStyle(34);
  Energy_Quot__Muon_FJ->DrawCopy("Psame");Energy_Quot__Muon_FJ->SetMarkerColor(1);Energy_Quot__Muon_FJ->SetMarkerStyle(28);
  Energy_Quot__Muon_FJ->SetLineWidth(2);  Energy_Quot__Muon_FJ->SetLineColor(1);  Energy_Quot__Muon_FJ->DrawCopy("Esame");
  Energy_Quot__Muon_MultiJet->Divide(Energy_Quot__Muon_FJ);


  Energy_Quotient__Muon_Jet->SaveAs("/home/saksevul/T/Parallelism/Energy_Quotient__Muon-Jet.png"); Energy_Quotient__Muon_Jet->Close();

}

void ComPlot(){

  // Le damos algo de personalización al las gráficas..
  gROOT->ForceStyle();
  gStyle->SetPadBorderMode(0);    gStyle->SetPadBorderSize(0);
  gStyle->SetPadTopMargin(0.082);  gStyle->SetPadBottomMargin(0.12);
  gStyle->SetPadLeftMargin(0.11); gStyle->SetPadRightMargin(0.02);
  gStyle->SetOptStat(0);          gStyle->SetOptTitle(1);

  // Corremos los macros que nos interesan.
  EnergyQuotient();
}
