void Limits() {

  //Abrimos el archivo que nos interesa y el árbol que queremos leer.
  TFile *JetFile = new TFile("/home/saksevul/T/OpenData/Jet_20000/ak5PF_Limits.root");
  TFile *BTagFile = new TFile("/home/saksevul/T/OpenData/BTag_20000/ak5PF_Limits.root");
  TFile *MinBiasFile = new TFile("/home/saksevul/T/OpenData/MinBias_20000/ak5PF_Limits.root");
  TFile *MultiJetFile = new TFile("/home/saksevul/T/OpenData/MultiJet_20000/ak5PF_Limits.root");


  TH1F *Jet_MuonEnergy =(TH1F*)JetFile->Get("Jets_nMuonEnergy"); Jet_MuonEnergy->Scale(1.0/Jet_MuonEnergy->Integral()); Jet_MuonEnergy->Rebin(25);
  TH1F *BTag_MuonEnergy =(TH1F*)BTagFile->Get("Jets_nMuonEnergy"); BTag_MuonEnergy->Scale(1.0/BTag_MuonEnergy->Integral()); BTag_MuonEnergy->Rebin(25);
  TH1F *MinBias_MuonEnergy =(TH1F*)MinBiasFile->Get("Jets_nMuonEnergy"); MinBias_MuonEnergy->Scale(1.0/MinBias_MuonEnergy->Integral()); MinBias_MuonEnergy->Rebin(25);
  TH1F *MultiJet_MuonEnergy =(TH1F*)MultiJetFile->Get("Jets_nMuonEnergy"); MultiJet_MuonEnergy->Scale(1.0/MultiJet_MuonEnergy->Integral()); MultiJet_MuonEnergy->Rebin(25);

  TH1F *Jet_PhotonEnergy =(TH1F*)JetFile->Get("Jets_nPhotonEnergy"); Jet_PhotonEnergy->Scale(1.0/Jet_PhotonEnergy->Integral()); Jet_PhotonEnergy->Rebin(10);
  TH1F *BTag_PhotonEnergy =(TH1F*)BTagFile->Get("Jets_nPhotonEnergy"); BTag_PhotonEnergy->Scale(1.0/BTag_PhotonEnergy->Integral()); BTag_PhotonEnergy->Rebin(10);
  TH1F *MinBias_PhotonEnergy =(TH1F*)MinBiasFile->Get("Jets_nPhotonEnergy"); MinBias_PhotonEnergy->Scale(1.0/MinBias_PhotonEnergy->Integral()); MinBias_PhotonEnergy->Rebin(10);
  TH1F *MultiJet_PhotonEnergy =(TH1F*)MultiJetFile->Get("Jets_nPhotonEnergy"); MultiJet_PhotonEnergy->Scale(1.0/MultiJet_PhotonEnergy->Integral()); MultiJet_PhotonEnergy->Rebin(10);

  TH1F *Jet_ElectronEnergy =(TH1F*)JetFile->Get("Jets_nElectronEnergy"); Jet_ElectronEnergy->Scale(1.0/Jet_ElectronEnergy->Integral()); Jet_ElectronEnergy->Rebin(20);
  TH1F *BTag_ElectronEnergy =(TH1F*)BTagFile->Get("Jets_nElectronEnergy"); BTag_ElectronEnergy->Scale(1.0/BTag_ElectronEnergy->Integral()); BTag_ElectronEnergy->Rebin(20);
  TH1F *MinBias_ElectronEnergy =(TH1F*)MinBiasFile->Get("Jets_nElectronEnergy"); MinBias_ElectronEnergy->Scale(1.0/MinBias_ElectronEnergy->Integral()); MinBias_ElectronEnergy->Rebin(20);
  TH1F *MultiJet_ElectronEnergy =(TH1F*)MultiJetFile->Get("Jets_nElectronEnergy"); MultiJet_ElectronEnergy->Scale(1.0/MultiJet_ElectronEnergy->Integral()); MultiJet_ElectronEnergy->Rebin(20);

  TH1F *Jet_NeuHadEnergy =(TH1F*)JetFile->Get("Jets_nNeutralHadronEnergy"); Jet_NeuHadEnergy->Scale(1.0/Jet_NeuHadEnergy->Integral()); Jet_NeuHadEnergy->Rebin(20);
  TH1F *BTag_NeuHadEnergy =(TH1F*)BTagFile->Get("Jets_nNeutralHadronEnergy"); BTag_NeuHadEnergy->Scale(1.0/BTag_NeuHadEnergy->Integral()); BTag_NeuHadEnergy->Rebin(20);
  TH1F *MinBias_NeuHadEnergy =(TH1F*)MinBiasFile->Get("Jets_nNeutralHadronEnergy"); MinBias_NeuHadEnergy->Scale(1.0/MinBias_NeuHadEnergy->Integral()); MinBias_NeuHadEnergy->Rebin(20);
  TH1F *MultiJet_NeuHadEnergy =(TH1F*)MultiJetFile->Get("Jets_nNeutralHadronEnergy"); MultiJet_NeuHadEnergy->Scale(1.0/MultiJet_NeuHadEnergy->Integral()); MultiJet_NeuHadEnergy->Rebin(20);

  TH1F *Jet_CharHadEnergy =(TH1F*)JetFile->Get("Jets_nChargedHadronEnergy"); Jet_CharHadEnergy->Scale(1.0/Jet_CharHadEnergy->Integral()); Jet_CharHadEnergy->Rebin(20);
  TH1F *BTag_CharHadEnergy =(TH1F*)BTagFile->Get("Jets_nChargedHadronEnergy"); BTag_CharHadEnergy->Scale(1.0/BTag_CharHadEnergy->Integral()); BTag_CharHadEnergy->Rebin(20);
  TH1F *MinBias_CharHadEnergy =(TH1F*)MinBiasFile->Get("Jets_nChargedHadronEnergy"); MinBias_CharHadEnergy->Scale(1.0/MinBias_CharHadEnergy->Integral()); MinBias_CharHadEnergy->Rebin(20);
  TH1F *MultiJet_CharHadEnergy =(TH1F*)MultiJetFile->Get("Jets_nChargedHadronEnergy"); MultiJet_CharHadEnergy->Scale(1.0/MultiJet_CharHadEnergy->Integral()); MultiJet_CharHadEnergy->Rebin(20);


  TH1F *CLONE_Jet_MuonEnergy =(TH1F*)Jet_MuonEnergy->Clone(); CLONE_Jet_MuonEnergy->SetMarkerSize(6); CLONE_Jet_MuonEnergy->SetMarkerStyle(23); CLONE_Jet_MuonEnergy->SetMarkerColor(42);
  TH1F *CLONE_BTag_MuonEnergy =(TH1F*)BTag_MuonEnergy->Clone(); CLONE_BTag_MuonEnergy->SetMarkerSize(6); CLONE_BTag_MuonEnergy->SetMarkerStyle(22); CLONE_BTag_MuonEnergy->SetMarkerColor(33);
  TH1F *CLONE_MinBias_MuonEnergy =(TH1F*)MinBias_MuonEnergy->Clone(); CLONE_MinBias_MuonEnergy->SetMarkerSize(6); CLONE_MinBias_MuonEnergy->SetMarkerStyle(20); CLONE_MinBias_MuonEnergy->SetMarkerColor(5);
  TH1F *CLONE_MultiJet_MuonEnergy =(TH1F*)MultiJet_MuonEnergy->Clone(); CLONE_MultiJet_MuonEnergy->SetMarkerSize(6); CLONE_MultiJet_MuonEnergy->SetMarkerStyle(34); CLONE_MultiJet_MuonEnergy->SetMarkerColor(8);

  auto   Leg = new TLegend(0.4,0.2,0.55,0.4);    Leg->SetTextSize(0.04); Leg->SetFillStyle(0); Leg->SetBorderSize(0);
  Leg->AddEntry(CLONE_Jet_MuonEnergy, "PF Jet", "p");
  Leg->AddEntry(CLONE_BTag_MuonEnergy, "PF BTag", "p");
  Leg->AddEntry(CLONE_MinBias_MuonEnergy, "PF MinBias", "p");
  Leg->AddEntry(CLONE_MultiJet_MuonEnergy, "PF MultiJet", "p");

  TH1F *CLON2_Jet_MuonEnergy =(TH1F*)Jet_MuonEnergy->Clone(); CLON2_Jet_MuonEnergy->SetMarkerSize(6); CLON2_Jet_MuonEnergy->SetMarkerStyle(32); CLON2_Jet_MuonEnergy->SetMarkerColor(2);
  CLON2_Jet_MuonEnergy->SetLineWidth(3);   CLON2_Jet_MuonEnergy->SetLineColor(2);
  TH1F *CLON2_BTag_MuonEnergy =(TH1F*)BTag_MuonEnergy->Clone(); CLON2_BTag_MuonEnergy->SetMarkerSize(6); CLON2_BTag_MuonEnergy->SetMarkerStyle(26); CLON2_BTag_MuonEnergy->SetMarkerColor(4);
  CLON2_BTag_MuonEnergy->SetLineWidth(3);   CLON2_BTag_MuonEnergy->SetLineColor(4);
  TH1F *CLON2_MinBias_MuonEnergy =(TH1F*)MinBias_MuonEnergy->Clone(); CLON2_MinBias_MuonEnergy->SetMarkerSize(6); CLON2_MinBias_MuonEnergy->SetMarkerStyle(24); CLON2_MinBias_MuonEnergy->SetMarkerColor(41);
  CLON2_MinBias_MuonEnergy->SetLineWidth(3);   CLON2_MinBias_MuonEnergy->SetLineColor(41);
  TH1F *CLON2_MultiJet_MuonEnergy =(TH1F*)MultiJet_MuonEnergy->Clone(); CLON2_MultiJet_MuonEnergy->SetMarkerSize(6); CLON2_MultiJet_MuonEnergy->SetMarkerStyle(28); CLON2_MultiJet_MuonEnergy->SetMarkerColor(32);
  CLON2_MultiJet_MuonEnergy->SetLineWidth(3);   CLON2_MultiJet_MuonEnergy->SetLineColor(32);

  auto   Legend = new TLegend(0.4,0.2,0.55,0.4);    Legend->SetTextSize(0.04); Legend->SetFillStyle(0); Legend->SetBorderSize(0);
  Legend->AddEntry(CLON2_Jet_MuonEnergy, "PF Jet", "lep");
  Legend->AddEntry(CLON2_BTag_MuonEnergy, "PF BTag", "lep");
  Legend->AddEntry(CLON2_MinBias_MuonEnergy, "PF MinBias", "lep");
  Legend->AddEntry(CLON2_MultiJet_MuonEnergy, "PF MultiJet", "lep");



  TCanvas* Limite_Energia_Muones = new TCanvas("Limite_Energia_Muones","Limite de E para Muones",0,0,3840,2160);
  Limite_Energia_Muones->SetLogy(); Limite_Energia_Muones->SetMargin(0.14,0.014,0.15,0); // Jet_MuonEnergy->SetAxisRange(0.0, 10.0, "X");
  Jet_MuonEnergy->SetTitle(" ; #frac{E^{Mu#acute{o}n}}{Mult^{Mu#acute{o}n}} [GeV]; #frac{1}{N_{Tot}} #frac{dN}{d #frac{E^{Mu#acute{o}n}}{Mult^{Mu#acute{o}n}}}");
  Jet_MuonEnergy->GetXaxis()->SetLabelSize(0.05); Jet_MuonEnergy->GetYaxis()->SetLabelSize(0.05);
  Jet_MuonEnergy->GetXaxis()->SetTitleSize(0.05); Jet_MuonEnergy->GetYaxis()->SetTitleSize(0.05);
  Jet_MuonEnergy->GetXaxis()->SetTitleOffset(1.2);Jet_MuonEnergy->GetYaxis()->SetTitleOffset(1.2);
  Jet_MuonEnergy->SetMarkerSize(4);  Jet_MuonEnergy->SetMarkerColor(42); Jet_MuonEnergy->SetMarkerStyle(23);
  Jet_MuonEnergy->DrawCopy("P");     Jet_MuonEnergy->SetMarkerColor(2);  Jet_MuonEnergy->SetMarkerStyle(32);
  Jet_MuonEnergy->SetLineWidth(2);   Jet_MuonEnergy->SetLineColor(2);    Jet_MuonEnergy->DrawCopy("Esame");
  BTag_MuonEnergy->SetMarkerSize(4);  BTag_MuonEnergy->SetMarkerColor(33); BTag_MuonEnergy->SetMarkerStyle(22);
  BTag_MuonEnergy->DrawCopy("Psame"); BTag_MuonEnergy->SetMarkerColor(4);  BTag_MuonEnergy->SetMarkerStyle(26);
  BTag_MuonEnergy->SetLineWidth(2);   BTag_MuonEnergy->SetLineColor(4);    BTag_MuonEnergy->DrawCopy("Esame");
  MinBias_MuonEnergy->SetMarkerSize(4);  MinBias_MuonEnergy->SetMarkerColor(5);  MinBias_MuonEnergy->SetMarkerStyle(20);
  MinBias_MuonEnergy->DrawCopy("Psame"); MinBias_MuonEnergy->SetMarkerColor(41); MinBias_MuonEnergy->SetMarkerStyle(24);
  MinBias_MuonEnergy->SetLineWidth(2);   MinBias_MuonEnergy->SetLineColor(41);   MinBias_MuonEnergy->DrawCopy("Esame");
  MultiJet_MuonEnergy->SetMarkerSize(4);  MultiJet_MuonEnergy->SetMarkerColor(8);  MultiJet_MuonEnergy->SetMarkerStyle(34);
  MultiJet_MuonEnergy->DrawCopy("Psame"); MultiJet_MuonEnergy->SetMarkerColor(32); MultiJet_MuonEnergy->SetMarkerStyle(28);
  MultiJet_MuonEnergy->SetLineWidth(2);   MultiJet_MuonEnergy->SetLineColor(32);   MultiJet_MuonEnergy->DrawCopy("Esame");
  Leg->Draw();Legend->Draw(); Limite_Energia_Muones->Print("/home/saksevul/T/Parallelism/Comparisons/Energy_Lim-ak5Jets.pdf(","pdf"); Limite_Energia_Muones->Close();

  TCanvas* Limite_Energia_Fotones = new TCanvas("Limite_Energia_Fotones","Limite de E para Fotones",0,0,3840,2160);
  Limite_Energia_Fotones->SetLogy(); Limite_Energia_Fotones->SetMargin(0.14,0.014,0.15,0); // Jet_PhotonEnergy->SetAxisRange(0.0, 10.0, "X");
  Jet_PhotonEnergy->SetTitle(" ; #frac{E^{Fot#acute{o}n}}{Mult^{Fot#acute{o}n}} [GeV]; #frac{1}{N_{Tot}} #frac{dN}{d #frac{E^{Fot#acute{o}n}}{Mult^{Fot#acute{o}n}}}");
  Jet_PhotonEnergy->GetXaxis()->SetLabelSize(0.05); Jet_PhotonEnergy->GetYaxis()->SetLabelSize(0.05);
  Jet_PhotonEnergy->GetXaxis()->SetTitleSize(0.05); Jet_PhotonEnergy->GetYaxis()->SetTitleSize(0.05);
  Jet_PhotonEnergy->GetXaxis()->SetTitleOffset(1.2);Jet_PhotonEnergy->GetYaxis()->SetTitleOffset(1.2);
  Jet_PhotonEnergy->SetMarkerSize(4);  Jet_PhotonEnergy->SetMarkerColor(42); Jet_PhotonEnergy->SetMarkerStyle(23);
  Jet_PhotonEnergy->DrawCopy("P");     Jet_PhotonEnergy->SetMarkerColor(2);  Jet_PhotonEnergy->SetMarkerStyle(32);
  Jet_PhotonEnergy->SetLineWidth(2);   Jet_PhotonEnergy->SetLineColor(2);    Jet_PhotonEnergy->DrawCopy("Esame");
  BTag_PhotonEnergy->SetMarkerSize(4);  BTag_PhotonEnergy->SetMarkerColor(33); BTag_PhotonEnergy->SetMarkerStyle(22);
  BTag_PhotonEnergy->DrawCopy("Psame"); BTag_PhotonEnergy->SetMarkerColor(4);  BTag_PhotonEnergy->SetMarkerStyle(26);
  BTag_PhotonEnergy->SetLineWidth(2);   BTag_PhotonEnergy->SetLineColor(4);    BTag_PhotonEnergy->DrawCopy("Esame");
  MinBias_PhotonEnergy->SetMarkerSize(4);  MinBias_PhotonEnergy->SetMarkerColor(5);  MinBias_PhotonEnergy->SetMarkerStyle(20);
  MinBias_PhotonEnergy->DrawCopy("Psame"); MinBias_PhotonEnergy->SetMarkerColor(41); MinBias_PhotonEnergy->SetMarkerStyle(24);
  MinBias_PhotonEnergy->SetLineWidth(2);   MinBias_PhotonEnergy->SetLineColor(41);   MinBias_PhotonEnergy->DrawCopy("Esame");
  MultiJet_PhotonEnergy->SetMarkerSize(4);  MultiJet_PhotonEnergy->SetMarkerColor(8);  MultiJet_PhotonEnergy->SetMarkerStyle(34);
  MultiJet_PhotonEnergy->DrawCopy("Psame"); MultiJet_PhotonEnergy->SetMarkerColor(32); MultiJet_PhotonEnergy->SetMarkerStyle(28);
  MultiJet_PhotonEnergy->SetLineWidth(2);   MultiJet_PhotonEnergy->SetLineColor(32);   MultiJet_PhotonEnergy->DrawCopy("Esame");
  Leg->Draw();Legend->Draw(); Limite_Energia_Fotones->Print("/home/saksevul/T/Parallelism/Comparisons/Energy_Lim-ak5Jets.pdf","pdf"); Limite_Energia_Fotones->Close();

  TCanvas* Limite_Energia_Electrones = new TCanvas("Limite_Energia_Electrones","Limite E para Electrones",0,0,3840,2160);
  Limite_Energia_Electrones->SetLogy(); Limite_Energia_Electrones->SetMargin(0.14,0.014,0.15,0); // Jet_ElectronEnergy->SetAxisRange(0.0, 10.0, "X");
  Jet_ElectronEnergy->SetTitle(" ; #frac{E^{Electr#acute{o}n}}{Mult^{Electr#acute{o}n}} [GeV]; #frac{1}{N_{Tot}} #frac{dN}{d #frac{E^{Electr#acute{o}n}}{Mult^{Electr#acute{o}n}}}");
  Jet_ElectronEnergy->GetXaxis()->SetLabelSize(0.05); Jet_ElectronEnergy->GetYaxis()->SetLabelSize(0.05);
  Jet_ElectronEnergy->GetXaxis()->SetTitleSize(0.05); Jet_ElectronEnergy->GetYaxis()->SetTitleSize(0.05);
  Jet_ElectronEnergy->GetXaxis()->SetTitleOffset(1.2);Jet_ElectronEnergy->GetYaxis()->SetTitleOffset(1.2);
  Jet_ElectronEnergy->SetMarkerSize(4);  Jet_ElectronEnergy->SetMarkerColor(42); Jet_ElectronEnergy->SetMarkerStyle(23);
  Jet_ElectronEnergy->DrawCopy("P");     Jet_ElectronEnergy->SetMarkerColor(2);  Jet_ElectronEnergy->SetMarkerStyle(32);
  Jet_ElectronEnergy->SetLineWidth(2);   Jet_ElectronEnergy->SetLineColor(2);    Jet_ElectronEnergy->DrawCopy("Esame");
  BTag_ElectronEnergy->SetMarkerSize(4);  BTag_ElectronEnergy->SetMarkerColor(33); BTag_ElectronEnergy->SetMarkerStyle(22);
  BTag_ElectronEnergy->DrawCopy("Psame"); BTag_ElectronEnergy->SetMarkerColor(4);  BTag_ElectronEnergy->SetMarkerStyle(26);
  BTag_ElectronEnergy->SetLineWidth(2);   BTag_ElectronEnergy->SetLineColor(4);    BTag_ElectronEnergy->DrawCopy("Esame");
  MinBias_ElectronEnergy->SetMarkerSize(4);  MinBias_ElectronEnergy->SetMarkerColor(5);  MinBias_ElectronEnergy->SetMarkerStyle(20);
  MinBias_ElectronEnergy->DrawCopy("Psame"); MinBias_ElectronEnergy->SetMarkerColor(41); MinBias_ElectronEnergy->SetMarkerStyle(24);
  MinBias_ElectronEnergy->SetLineWidth(2);   MinBias_ElectronEnergy->SetLineColor(41);   MinBias_ElectronEnergy->DrawCopy("Esame");
  MultiJet_ElectronEnergy->SetMarkerSize(4);  MultiJet_ElectronEnergy->SetMarkerColor(8);  MultiJet_ElectronEnergy->SetMarkerStyle(34);
  MultiJet_ElectronEnergy->DrawCopy("Psame"); MultiJet_ElectronEnergy->SetMarkerColor(32); MultiJet_ElectronEnergy->SetMarkerStyle(28);
  MultiJet_ElectronEnergy->SetLineWidth(2);   MultiJet_ElectronEnergy->SetLineColor(32);   MultiJet_ElectronEnergy->DrawCopy("Esame");
  Leg->Draw();Legend->Draw(); Limite_Energia_Electrones->Print("/home/saksevul/T/Parallelism/Comparisons/Energy_Lim-ak5Jets.pdf","pdf"); Limite_Energia_Electrones->Close();

  TCanvas* Limite_Energia_HadNeutros = new TCanvas("Limite_Energia_HadNeutros","Limite E para HadNeutros",0,0,3840,2160);
  Limite_Energia_HadNeutros->SetLogy(); Limite_Energia_HadNeutros->SetMargin(0.14,0.014,0.15,0); // Jet_NeuHadEnergy->SetAxisRange(0.0, 10.0, "X");
  Jet_NeuHadEnergy->SetTitle(" ; #frac{E^{HadNeutro}}{Mult^{HadNeutro}} [GeV]; #frac{1}{N_{Tot}} #frac{dN}{d #frac{E^{HadNeutro}}{Mult^{HadNeutro}}}");
  Jet_NeuHadEnergy->GetXaxis()->SetLabelSize(0.05); Jet_NeuHadEnergy->GetYaxis()->SetLabelSize(0.05);
  Jet_NeuHadEnergy->GetXaxis()->SetTitleSize(0.05); Jet_NeuHadEnergy->GetYaxis()->SetTitleSize(0.05);
  Jet_NeuHadEnergy->GetXaxis()->SetTitleOffset(1.2);Jet_NeuHadEnergy->GetYaxis()->SetTitleOffset(1.2);
  Jet_NeuHadEnergy->SetMarkerSize(4);  Jet_NeuHadEnergy->SetMarkerColor(42); Jet_NeuHadEnergy->SetMarkerStyle(23);
  Jet_NeuHadEnergy->DrawCopy("P");     Jet_NeuHadEnergy->SetMarkerColor(2);  Jet_NeuHadEnergy->SetMarkerStyle(32);
  Jet_NeuHadEnergy->SetLineWidth(2);   Jet_NeuHadEnergy->SetLineColor(2);    Jet_NeuHadEnergy->DrawCopy("Esame");
  BTag_NeuHadEnergy->SetMarkerSize(4);  BTag_NeuHadEnergy->SetMarkerColor(33); BTag_NeuHadEnergy->SetMarkerStyle(22);
  BTag_NeuHadEnergy->DrawCopy("Psame"); BTag_NeuHadEnergy->SetMarkerColor(4);  BTag_NeuHadEnergy->SetMarkerStyle(26);
  BTag_NeuHadEnergy->SetLineWidth(2);   BTag_NeuHadEnergy->SetLineColor(4);    BTag_NeuHadEnergy->DrawCopy("Esame");
  MinBias_NeuHadEnergy->SetMarkerSize(4);  MinBias_NeuHadEnergy->SetMarkerColor(5);  MinBias_NeuHadEnergy->SetMarkerStyle(20);
  MinBias_NeuHadEnergy->DrawCopy("Psame"); MinBias_NeuHadEnergy->SetMarkerColor(41); MinBias_NeuHadEnergy->SetMarkerStyle(24);
  MinBias_NeuHadEnergy->SetLineWidth(2);   MinBias_NeuHadEnergy->SetLineColor(41);   MinBias_NeuHadEnergy->DrawCopy("Esame");
  MultiJet_NeuHadEnergy->SetMarkerSize(4);  MultiJet_NeuHadEnergy->SetMarkerColor(8);  MultiJet_NeuHadEnergy->SetMarkerStyle(34);
  MultiJet_NeuHadEnergy->DrawCopy("Psame"); MultiJet_NeuHadEnergy->SetMarkerColor(32); MultiJet_NeuHadEnergy->SetMarkerStyle(28);
  MultiJet_NeuHadEnergy->SetLineWidth(2);   MultiJet_NeuHadEnergy->SetLineColor(32);   MultiJet_NeuHadEnergy->DrawCopy("Esame");
  Leg->Draw();Legend->Draw(); Limite_Energia_HadNeutros->Print("/home/saksevul/T/Parallelism/Comparisons/Energy_Lim-ak5Jets.pdf","pdf"); Limite_Energia_HadNeutros->Close();

  TCanvas* Limite_Energia_HadCargados = new TCanvas("Limite_Energia_HadCargados","Limite E para HadCargados",0,0,3840,2160);
  Limite_Energia_HadCargados->SetLogy(); Limite_Energia_HadCargados->SetMargin(0.14,0.014,0.15,0); // Jet_CharHadEnergy->SetAxisRange(0.0, 10.0, "X");
  Jet_CharHadEnergy->SetTitle(" ; #frac{E^{HadCargado}}{Mult^{HadCargado}} [GeV]; #frac{1}{N_{Tot}} #frac{dN}{d #frac{E^{HadCargado}}{Mult^{HadCargado}}}");
  Jet_CharHadEnergy->GetXaxis()->SetLabelSize(0.05); Jet_CharHadEnergy->GetYaxis()->SetLabelSize(0.05);
  Jet_CharHadEnergy->GetXaxis()->SetTitleSize(0.05); Jet_CharHadEnergy->GetYaxis()->SetTitleSize(0.05);
  Jet_CharHadEnergy->GetXaxis()->SetTitleOffset(1.2);Jet_CharHadEnergy->GetYaxis()->SetTitleOffset(1.2);
  Jet_CharHadEnergy->SetMarkerSize(4);  Jet_CharHadEnergy->SetMarkerColor(42); Jet_CharHadEnergy->SetMarkerStyle(23);
  Jet_CharHadEnergy->DrawCopy("P");     Jet_CharHadEnergy->SetMarkerColor(2);  Jet_CharHadEnergy->SetMarkerStyle(32);
  Jet_CharHadEnergy->SetLineWidth(2);   Jet_CharHadEnergy->SetLineColor(2);    Jet_CharHadEnergy->DrawCopy("Esame");
  BTag_CharHadEnergy->SetMarkerSize(4);  BTag_CharHadEnergy->SetMarkerColor(33); BTag_CharHadEnergy->SetMarkerStyle(22);
  BTag_CharHadEnergy->DrawCopy("Psame"); BTag_CharHadEnergy->SetMarkerColor(4);  BTag_CharHadEnergy->SetMarkerStyle(26);
  BTag_CharHadEnergy->SetLineWidth(2);   BTag_CharHadEnergy->SetLineColor(4);    BTag_CharHadEnergy->DrawCopy("Esame");
  MinBias_CharHadEnergy->SetMarkerSize(4);  MinBias_CharHadEnergy->SetMarkerColor(5);  MinBias_CharHadEnergy->SetMarkerStyle(20);
  MinBias_CharHadEnergy->DrawCopy("Psame"); MinBias_CharHadEnergy->SetMarkerColor(41); MinBias_CharHadEnergy->SetMarkerStyle(24);
  MinBias_CharHadEnergy->SetLineWidth(2);   MinBias_CharHadEnergy->SetLineColor(41);   MinBias_CharHadEnergy->DrawCopy("Esame");
  MultiJet_CharHadEnergy->SetMarkerSize(4);  MultiJet_CharHadEnergy->SetMarkerColor(8);  MultiJet_CharHadEnergy->SetMarkerStyle(34);
  MultiJet_CharHadEnergy->DrawCopy("Psame"); MultiJet_CharHadEnergy->SetMarkerColor(32); MultiJet_CharHadEnergy->SetMarkerStyle(28);
  MultiJet_CharHadEnergy->SetLineWidth(2);   MultiJet_CharHadEnergy->SetLineColor(32);   MultiJet_CharHadEnergy->DrawCopy("Esame");
  Leg->Draw();Legend->Draw(); Limite_Energia_HadCargados->Print("/home/saksevul/T/Parallelism/Comparisons/Energy_Lim-ak5Jets.pdf)","pdf"); Limite_Energia_HadCargados->Close();


}

//##########################################################################################################################################################

void Kinematics() {

  //Abrimos el archivo que nos interesa y el árbol que queremos leer.
  TFile *FJFile = new TFile("/home/saksevul/T/Pythia/FastJet/ak5FJ.root");
  TFile *JetFile = new TFile("/home/saksevul/T/OpenData/Jet_20000/ak5PF.root");
  TFile *BTagFile = new TFile("/home/saksevul/T/OpenData/BTag_20000/ak5PF.root");
  TFile *MinBiasFile = new TFile("/home/saksevul/T/OpenData/MinBias_20000/ak5PF.root");
  TFile *MultiJetFile = new TFile("/home/saksevul/T/OpenData/MultiJet_20000/ak5PF.root");


  TH1F *FJ_pT =(TH1F*)FJFile->Get("Jets_pt_"); FJ_pT->Scale(1.0/FJ_pT->Integral()); FJ_pT->Rebin(50);
  TH1F *Jet_pT =(TH1F*)JetFile->Get("Jets_pt_"); Jet_pT->Scale(1.0/Jet_pT->Integral()); Jet_pT->Rebin(50);
  TH1F *BTag_pT =(TH1F*)BTagFile->Get("Jets_pt_"); BTag_pT->Scale(1.0/BTag_pT->Integral()); BTag_pT->Rebin(50);
  TH1F *MinBias_pT =(TH1F*)MinBiasFile->Get("Jets_pt_"); MinBias_pT->Scale(1.0/MinBias_pT->Integral()); MinBias_pT->Rebin(50);
  TH1F *MultiJet_pT =(TH1F*)MultiJetFile->Get("Jets_pt_"); MultiJet_pT->Scale(1.0/MultiJet_pT->Integral()); MultiJet_pT->Rebin(50);

  TH1F *FJ_eta =(TH1F*)FJFile->Get("Jets_eta_"); FJ_eta->Scale(1.0/FJ_eta->Integral()); FJ_eta->Rebin(10);
  TH1F *Jet_eta =(TH1F*)JetFile->Get("Jets_eta_"); Jet_eta->Scale(1.0/Jet_eta->Integral()); Jet_eta->Rebin(10);
  TH1F *BTag_eta =(TH1F*)BTagFile->Get("Jets_eta_"); BTag_eta->Scale(1.0/BTag_eta->Integral()); BTag_eta->Rebin(10);
  TH1F *MinBias_eta =(TH1F*)MinBiasFile->Get("Jets_eta_"); MinBias_eta->Scale(1.0/MinBias_eta->Integral()); MinBias_eta->Rebin(10);
  TH1F *MultiJet_eta =(TH1F*)MultiJetFile->Get("Jets_eta_"); MultiJet_eta->Scale(1.0/MultiJet_eta->Integral()); MultiJet_eta->Rebin(10);


  TH1F *FJ_MuonEnergy =(TH1F*)FJFile->Get("Jets_MuonEnergy"); FJ_MuonEnergy->Scale(1.0/FJ_MuonEnergy->Integral()); FJ_MuonEnergy->Rebin(50);
  TH1F *Jet_MuonEnergy =(TH1F*)JetFile->Get("Jets_MuonEnergy"); Jet_MuonEnergy->Scale(1.0/Jet_MuonEnergy->Integral()); Jet_MuonEnergy->Rebin(50);
  TH1F *BTag_MuonEnergy =(TH1F*)BTagFile->Get("Jets_MuonEnergy"); BTag_MuonEnergy->Scale(1.0/BTag_MuonEnergy->Integral()); BTag_MuonEnergy->Rebin(50);
  TH1F *MinBias_MuonEnergy =(TH1F*)MinBiasFile->Get("Jets_MuonEnergy"); MinBias_MuonEnergy->Scale(1.0/MinBias_MuonEnergy->Integral()); MinBias_MuonEnergy->Rebin(50);
  TH1F *MultiJet_MuonEnergy =(TH1F*)MultiJetFile->Get("Jets_MuonEnergy"); MultiJet_MuonEnergy->Scale(1.0/MultiJet_MuonEnergy->Integral()); MultiJet_MuonEnergy->Rebin(50);

  TH1F *FJ_PhotonEnergy =(TH1F*)FJFile->Get("Jets_PhotonEnergy"); FJ_PhotonEnergy->Scale(1.0/FJ_PhotonEnergy->Integral()); FJ_PhotonEnergy->Rebin(50);
  TH1F *Jet_PhotonEnergy =(TH1F*)JetFile->Get("Jets_PhotonEnergy"); Jet_PhotonEnergy->Scale(1.0/Jet_PhotonEnergy->Integral()); Jet_PhotonEnergy->Rebin(50);
  TH1F *BTag_PhotonEnergy =(TH1F*)BTagFile->Get("Jets_PhotonEnergy"); BTag_PhotonEnergy->Scale(1.0/BTag_PhotonEnergy->Integral()); BTag_PhotonEnergy->Rebin(50);
  TH1F *MinBias_PhotonEnergy =(TH1F*)MinBiasFile->Get("Jets_PhotonEnergy"); MinBias_PhotonEnergy->Scale(1.0/MinBias_PhotonEnergy->Integral()); MinBias_PhotonEnergy->Rebin(50);
  TH1F *MultiJet_PhotonEnergy =(TH1F*)MultiJetFile->Get("Jets_PhotonEnergy"); MultiJet_PhotonEnergy->Scale(1.0/MultiJet_PhotonEnergy->Integral()); MultiJet_PhotonEnergy->Rebin(50);

  TH1F *FJ_ElectronEnergy =(TH1F*)FJFile->Get("Jets_ElectronEnergy"); FJ_ElectronEnergy->Scale(1.0/FJ_ElectronEnergy->Integral()); FJ_ElectronEnergy->Rebin(50);
  TH1F *Jet_ElectronEnergy =(TH1F*)JetFile->Get("Jets_ElectronEnergy"); Jet_ElectronEnergy->Scale(1.0/Jet_ElectronEnergy->Integral()); Jet_ElectronEnergy->Rebin(50);
  TH1F *BTag_ElectronEnergy =(TH1F*)BTagFile->Get("Jets_ElectronEnergy"); BTag_ElectronEnergy->Scale(1.0/BTag_ElectronEnergy->Integral()); BTag_ElectronEnergy->Rebin(50);
  TH1F *MinBias_ElectronEnergy =(TH1F*)MinBiasFile->Get("Jets_ElectronEnergy"); MinBias_ElectronEnergy->Scale(1.0/MinBias_ElectronEnergy->Integral()); MinBias_ElectronEnergy->Rebin(50);
  TH1F *MultiJet_ElectronEnergy =(TH1F*)MultiJetFile->Get("Jets_ElectronEnergy"); MultiJet_ElectronEnergy->Scale(1.0/MultiJet_ElectronEnergy->Integral()); MultiJet_ElectronEnergy->Rebin(50);

  TH1F *FJ_NeuHadEnergy =(TH1F*)FJFile->Get("Jets_NeutralHadEnergy"); FJ_NeuHadEnergy->Scale(1.0/FJ_NeuHadEnergy->Integral()); FJ_NeuHadEnergy->Rebin(50);
  TH1F *Jet_NeuHadEnergy =(TH1F*)JetFile->Get("Jets_NeutralHadronEnergy"); Jet_NeuHadEnergy->Scale(1.0/Jet_NeuHadEnergy->Integral()); Jet_NeuHadEnergy->Rebin(50);
  TH1F *BTag_NeuHadEnergy =(TH1F*)BTagFile->Get("Jets_NeutralHadronEnergy"); BTag_NeuHadEnergy->Scale(1.0/BTag_NeuHadEnergy->Integral()); BTag_NeuHadEnergy->Rebin(50);
  TH1F *MinBias_NeuHadEnergy =(TH1F*)MinBiasFile->Get("Jets_NeutralHadronEnergy"); MinBias_NeuHadEnergy->Scale(1.0/MinBias_NeuHadEnergy->Integral()); MinBias_NeuHadEnergy->Rebin(50);
  TH1F *MultiJet_NeuHadEnergy =(TH1F*)MultiJetFile->Get("Jets_NeutralHadronEnergy"); MultiJet_NeuHadEnergy->Scale(1.0/MultiJet_NeuHadEnergy->Integral()); MultiJet_NeuHadEnergy->Rebin(50);

  TH1F *FJ_CharHadEnergy =(TH1F*)FJFile->Get("Jets_ChargedHadEnergy"); FJ_CharHadEnergy->Scale(1.0/FJ_CharHadEnergy->Integral()); FJ_CharHadEnergy->Rebin(50);
  TH1F *Jet_CharHadEnergy =(TH1F*)JetFile->Get("Jets_ChargedHadronEnergy"); Jet_CharHadEnergy->Scale(1.0/Jet_CharHadEnergy->Integral()); Jet_CharHadEnergy->Rebin(50);
  TH1F *BTag_CharHadEnergy =(TH1F*)BTagFile->Get("Jets_ChargedHadronEnergy"); BTag_CharHadEnergy->Scale(1.0/BTag_CharHadEnergy->Integral()); BTag_CharHadEnergy->Rebin(50);
  TH1F *MinBias_CharHadEnergy =(TH1F*)MinBiasFile->Get("Jets_ChargedHadronEnergy"); MinBias_CharHadEnergy->Scale(1.0/MinBias_CharHadEnergy->Integral()); MinBias_CharHadEnergy->Rebin(50);
  TH1F *MultiJet_CharHadEnergy =(TH1F*)MultiJetFile->Get("Jets_ChargedHadronEnergy"); MultiJet_CharHadEnergy->Scale(1.0/MultiJet_CharHadEnergy->Integral()); MultiJet_CharHadEnergy->Rebin(50);



  auto   legend = new TLegend(0.63,0.18,0.90,0.42);    legend->SetTextSize(0.04); legend->SetFillStyle(0); legend->SetBorderSize(0);
    legend->AddEntry(FJ_pT, "MC FastJet", "l");
    legend->AddEntry(Jet_pT, "OD BTag", "l");
    legend->AddEntry(BTag_pT, "OD Jet", "l");
    legend->AddEntry(MinBias_pT, "OD MinBias", "l");
    legend->AddEntry(MultiJet_pT, "OD MultiJet", "l");



  TCanvas* pT_Jets  = new TCanvas("pT_Jets ","pT_Jets ",0,0,3840,2160);
  pT_Jets->SetLogy(); pT_Jets->SetMargin(0.11,0,0.11,0);
  FJ_pT->SetTitle(" ; p_{T} [GeV]; #frac{1}{N_{Tot}} #frac{dN}{dp_{T}}");
  FJ_pT->GetYaxis()->SetTitleSize(0.05); FJ_pT->GetYaxis()->SetTitleOffset(1.0);
  FJ_pT->GetYaxis()->SetLabelSize(0.05); FJ_pT->SetAxisRange(0.00000001, 2, "Y");
  FJ_pT->SetMarkerSize(6); FJ_pT->SetMarkerColor(14); FJ_pT->SetMarkerStyle(21);
  FJ_pT->DrawCopy("P");    FJ_pT->SetMarkerColor(1);  FJ_pT->SetMarkerStyle(25);
  FJ_pT->SetLineWidth(2);  FJ_pT->SetLineColor(1);    FJ_pT->DrawCopy("Esame");
  Jet_pT ->SetMarkerSize(6);  Jet_pT ->SetMarkerColor(42);Jet_pT ->SetMarkerStyle(23);
  Jet_pT ->DrawCopy("Psame"); Jet_pT ->SetMarkerColor(2); Jet_pT ->SetMarkerStyle(32);
  Jet_pT ->SetLineWidth(2);   Jet_pT ->SetLineColor(2);   Jet_pT ->DrawCopy("Esame");
  BTag_pT->SetMarkerSize(6);  BTag_pT->SetMarkerColor(33);BTag_pT->SetMarkerStyle(22);
  BTag_pT->DrawCopy("Psame"); BTag_pT->SetMarkerColor(4); BTag_pT->SetMarkerStyle(26);
  BTag_pT->SetLineWidth(2);   BTag_pT->SetLineColor(4);   BTag_pT->DrawCopy("Esame");
  MinBias_pT->SetMarkerSize(6);  MinBias_pT->SetMarkerColor(5); MinBias_pT->SetMarkerStyle(20);
  MinBias_pT->DrawCopy("Psame"); MinBias_pT->SetMarkerColor(41);MinBias_pT->SetMarkerStyle(24);
  MinBias_pT->SetLineWidth(2);   MinBias_pT->SetLineColor(41);  MinBias_pT->DrawCopy("Esame");
  MultiJet_pT->SetMarkerSize(6);  MultiJet_pT->SetMarkerColor(8); MultiJet_pT->SetMarkerStyle(34);
  MultiJet_pT->DrawCopy("Psame"); MultiJet_pT->SetMarkerColor(32);MultiJet_pT->SetMarkerStyle(28);
  MultiJet_pT->SetLineWidth(2);   MultiJet_pT->SetLineColor(32);  MultiJet_pT->DrawCopy("Esame");
  legend->Draw(); pT_Jets->Print("/home/saksevul/T/Parallelism/ak5Jets/Kinematics.pdf(","pdf"); pT_Jets->Close();

  TCanvas* eta_Jets  = new TCanvas("eta_Jets ","eta_Jets ",0,0,3840,2160);
  eta_Jets->SetLogy(); eta_Jets->SetMargin(0.11,0,0.11,0);
  FJ_eta->SetTitle(" ; #eta; #frac{1}{N_{Tot}} #frac{dN}{d#eta}");
  FJ_eta->GetYaxis()->SetTitleSize(0.05); FJ_eta->GetYaxis()->SetTitleOffset(1.0);
  FJ_eta->GetYaxis()->SetLabelSize(0.05); FJ_eta->SetAxisRange(-2.0, 2.0, "X");
  FJ_eta->SetMarkerSize(6); FJ_eta->SetMarkerColor(14); FJ_eta->SetMarkerStyle(21);
  FJ_eta->DrawCopy("P");    FJ_eta->SetMarkerColor(1);  FJ_eta->SetMarkerStyle(25);
  FJ_eta->SetLineWidth(2);  FJ_eta->SetLineColor(1);    FJ_eta->DrawCopy("Esame");
  Jet_eta ->SetMarkerSize(6);  Jet_eta ->SetMarkerColor(42);Jet_eta ->SetMarkerStyle(23);
  Jet_eta ->DrawCopy("Psame"); Jet_eta ->SetMarkerColor(2); Jet_eta ->SetMarkerStyle(32);
  Jet_eta ->SetLineWidth(2);   Jet_eta ->SetLineColor(2);   Jet_eta ->DrawCopy("Esame");
  BTag_eta->SetMarkerSize(6);  BTag_eta->SetMarkerColor(33);BTag_eta->SetMarkerStyle(22);
  BTag_eta->DrawCopy("Psame"); BTag_eta->SetMarkerColor(4); BTag_eta->SetMarkerStyle(26);
  BTag_eta->SetLineWidth(2);   BTag_eta->SetLineColor(4);   BTag_eta->DrawCopy("Esame");
  MinBias_eta->SetMarkerSize(6);  MinBias_eta->SetMarkerColor(5); MinBias_eta->SetMarkerStyle(20);
  MinBias_eta->DrawCopy("Psame"); MinBias_eta->SetMarkerColor(41);MinBias_eta->SetMarkerStyle(24);
  MinBias_eta->SetLineWidth(2);   MinBias_eta->SetLineColor(41);  MinBias_eta->DrawCopy("Esame");
  MultiJet_eta->SetMarkerSize(6);  MultiJet_eta->SetMarkerColor(8); MultiJet_eta->SetMarkerStyle(34);
  MultiJet_eta->DrawCopy("Psame"); MultiJet_eta->SetMarkerColor(32);MultiJet_eta->SetMarkerStyle(28);
  MultiJet_eta->SetLineWidth(2);   MultiJet_eta->SetLineColor(32);  MultiJet_eta->DrawCopy("Esame");
  legend->Draw(); eta_Jets->Print("/home/saksevul/T/Parallelism/ak5Jets/Kinematics.pdf","pdf"); eta_Jets->Close();


  TCanvas* MuonEnergy_Jets  = new TCanvas("MuonEnergy_Jets ","MuonEnergy_Jets ",0,0,3840,2160);
  MuonEnergy_Jets->SetLogy(); MuonEnergy_Jets->SetMargin(0.11,0,0.11,0);
  FJ_MuonEnergy->SetTitle(" ; E^{Muon} [GeV]; #frac{1}{N_{Tot}} #frac{dN}{dE^{Muon}}");
  FJ_MuonEnergy->GetYaxis()->SetTitleSize(0.05); FJ_MuonEnergy->GetYaxis()->SetTitleOffset(1.0);
  FJ_MuonEnergy->GetYaxis()->SetLabelSize(0.05); FJ_MuonEnergy->SetAxisRange(0.0000000001, 2, "Y");
  FJ_MuonEnergy->SetMarkerSize(6); FJ_MuonEnergy->SetMarkerColor(14); FJ_MuonEnergy->SetMarkerStyle(21);
  FJ_MuonEnergy->DrawCopy("P");    FJ_MuonEnergy->SetMarkerColor(1);  FJ_MuonEnergy->SetMarkerStyle(25);
  FJ_MuonEnergy->SetLineWidth(2);  FJ_MuonEnergy->SetLineColor(1);    FJ_MuonEnergy->DrawCopy("Esame");
  Jet_MuonEnergy ->SetMarkerSize(6);  Jet_MuonEnergy ->SetMarkerColor(42);Jet_MuonEnergy ->SetMarkerStyle(23);
  Jet_MuonEnergy ->DrawCopy("Psame"); Jet_MuonEnergy ->SetMarkerColor(2); Jet_MuonEnergy ->SetMarkerStyle(32);
  Jet_MuonEnergy ->SetLineWidth(2);   Jet_MuonEnergy ->SetLineColor(2);   Jet_MuonEnergy ->DrawCopy("Esame");
  BTag_MuonEnergy->SetMarkerSize(6);  BTag_MuonEnergy->SetMarkerColor(33);BTag_MuonEnergy->SetMarkerStyle(22);
  BTag_MuonEnergy->DrawCopy("Psame"); BTag_MuonEnergy->SetMarkerColor(4); BTag_MuonEnergy->SetMarkerStyle(26);
  BTag_MuonEnergy->SetLineWidth(2);   BTag_MuonEnergy->SetLineColor(4);   BTag_MuonEnergy->DrawCopy("Esame");
  MinBias_MuonEnergy->SetMarkerSize(6);  MinBias_MuonEnergy->SetMarkerColor(5); MinBias_MuonEnergy->SetMarkerStyle(20);
  MinBias_MuonEnergy->DrawCopy("Psame"); MinBias_MuonEnergy->SetMarkerColor(41);MinBias_MuonEnergy->SetMarkerStyle(24);
  MinBias_MuonEnergy->SetLineWidth(2);   MinBias_MuonEnergy->SetLineColor(41);  MinBias_MuonEnergy->DrawCopy("Esame");
  MultiJet_MuonEnergy->SetMarkerSize(6);  MultiJet_MuonEnergy->SetMarkerColor(8); MultiJet_MuonEnergy->SetMarkerStyle(34);
  MultiJet_MuonEnergy->DrawCopy("Psame"); MultiJet_MuonEnergy->SetMarkerColor(32);MultiJet_MuonEnergy->SetMarkerStyle(28);
  MultiJet_MuonEnergy->SetLineWidth(2);   MultiJet_MuonEnergy->SetLineColor(32);  MultiJet_MuonEnergy->DrawCopy("Esame");
  legend->Draw(); MuonEnergy_Jets->Print("/home/saksevul/T/Parallelism/ak5Jets/Kinematics.pdf","pdf"); MuonEnergy_Jets->Close();

  TCanvas* PhotonEnergy_Jets  = new TCanvas("PhotonEnergy_Jets ","PhotonEnergy_Jets ",0,0,3840,2160);
  PhotonEnergy_Jets->SetLogy(); PhotonEnergy_Jets->SetMargin(0.11,0,0.11,0);
  FJ_PhotonEnergy->SetTitle(" ; E^{Foton} [GeV]; #frac{1}{N_{Tot}} #frac{dN}{dE^{Foton}}");
  FJ_PhotonEnergy->GetYaxis()->SetTitleSize(0.05); FJ_PhotonEnergy->GetYaxis()->SetTitleOffset(1.0);
  FJ_PhotonEnergy->GetYaxis()->SetLabelSize(0.05); FJ_PhotonEnergy->SetAxisRange(0.0000000001, 2, "Y");
  FJ_PhotonEnergy->SetMarkerSize(6); FJ_PhotonEnergy->SetMarkerColor(14); FJ_PhotonEnergy->SetMarkerStyle(21);
  FJ_PhotonEnergy->DrawCopy("P");    FJ_PhotonEnergy->SetMarkerColor(1);  FJ_PhotonEnergy->SetMarkerStyle(25);
  FJ_PhotonEnergy->SetLineWidth(2);  FJ_PhotonEnergy->SetLineColor(1);    FJ_PhotonEnergy->DrawCopy("Esame");
  Jet_PhotonEnergy ->SetMarkerSize(6);  Jet_PhotonEnergy ->SetMarkerColor(42);Jet_PhotonEnergy ->SetMarkerStyle(23);
  Jet_PhotonEnergy ->DrawCopy("Psame"); Jet_PhotonEnergy ->SetMarkerColor(2); Jet_PhotonEnergy ->SetMarkerStyle(32);
  Jet_PhotonEnergy ->SetLineWidth(2);   Jet_PhotonEnergy ->SetLineColor(2);   Jet_PhotonEnergy ->DrawCopy("Esame");
  BTag_PhotonEnergy->SetMarkerSize(6);  BTag_PhotonEnergy->SetMarkerColor(33);BTag_PhotonEnergy->SetMarkerStyle(22);
  BTag_PhotonEnergy->DrawCopy("Psame"); BTag_PhotonEnergy->SetMarkerColor(4); BTag_PhotonEnergy->SetMarkerStyle(26);
  BTag_PhotonEnergy->SetLineWidth(2);   BTag_PhotonEnergy->SetLineColor(4);   BTag_PhotonEnergy->DrawCopy("Esame");
  MinBias_PhotonEnergy->SetMarkerSize(6);  MinBias_PhotonEnergy->SetMarkerColor(5); MinBias_PhotonEnergy->SetMarkerStyle(20);
  MinBias_PhotonEnergy->DrawCopy("Psame"); MinBias_PhotonEnergy->SetMarkerColor(41);MinBias_PhotonEnergy->SetMarkerStyle(24);
  MinBias_PhotonEnergy->SetLineWidth(2);   MinBias_PhotonEnergy->SetLineColor(41);  MinBias_PhotonEnergy->DrawCopy("Esame");
  MultiJet_PhotonEnergy->SetMarkerSize(6);  MultiJet_PhotonEnergy->SetMarkerColor(8); MultiJet_PhotonEnergy->SetMarkerStyle(34);
  MultiJet_PhotonEnergy->DrawCopy("Psame"); MultiJet_PhotonEnergy->SetMarkerColor(32);MultiJet_PhotonEnergy->SetMarkerStyle(28);
  MultiJet_PhotonEnergy->SetLineWidth(2);   MultiJet_PhotonEnergy->SetLineColor(32);  MultiJet_PhotonEnergy->DrawCopy("Esame");
  legend->Draw(); PhotonEnergy_Jets->Print("/home/saksevul/T/Parallelism/ak5Jets/Kinematics.pdf","pdf"); PhotonEnergy_Jets->Close();

  TCanvas* ElectronEnergy_Jets  = new TCanvas("ElectronEnergy_Jets ","ElectronEnergy_Jets ",0,0,3840,2160);
  ElectronEnergy_Jets->SetLogy(); ElectronEnergy_Jets->SetMargin(0.11,0,0.11,0);
  FJ_ElectronEnergy->SetTitle(" ; E^{Electron} [GeV]; #frac{1}{N_{Tot}} #frac{dN}{dE^{Electron}}");
  FJ_ElectronEnergy->GetYaxis()->SetTitleSize(0.05); FJ_ElectronEnergy->GetYaxis()->SetTitleOffset(1.0);
  FJ_ElectronEnergy->GetYaxis()->SetLabelSize(0.05); FJ_ElectronEnergy->SetAxisRange(0.0000000001, 2, "Y");
  FJ_ElectronEnergy->SetMarkerSize(6); FJ_ElectronEnergy->SetMarkerColor(14); FJ_ElectronEnergy->SetMarkerStyle(21);
  FJ_ElectronEnergy->DrawCopy("P");    FJ_ElectronEnergy->SetMarkerColor(1);  FJ_ElectronEnergy->SetMarkerStyle(25);
  FJ_ElectronEnergy->SetLineWidth(2);  FJ_ElectronEnergy->SetLineColor(1);    FJ_ElectronEnergy->DrawCopy("Esame");
  Jet_ElectronEnergy ->SetMarkerSize(6);  Jet_ElectronEnergy ->SetMarkerColor(42);Jet_ElectronEnergy ->SetMarkerStyle(23);
  Jet_ElectronEnergy ->DrawCopy("Psame"); Jet_ElectronEnergy ->SetMarkerColor(2); Jet_ElectronEnergy ->SetMarkerStyle(32);
  Jet_ElectronEnergy ->SetLineWidth(2);   Jet_ElectronEnergy ->SetLineColor(2);   Jet_ElectronEnergy ->DrawCopy("Esame");
  BTag_ElectronEnergy->SetMarkerSize(6);  BTag_ElectronEnergy->SetMarkerColor(33);BTag_ElectronEnergy->SetMarkerStyle(22);
  BTag_ElectronEnergy->DrawCopy("Psame"); BTag_ElectronEnergy->SetMarkerColor(4); BTag_ElectronEnergy->SetMarkerStyle(26);
  BTag_ElectronEnergy->SetLineWidth(2);   BTag_ElectronEnergy->SetLineColor(4);   BTag_ElectronEnergy->DrawCopy("Esame");
  MinBias_ElectronEnergy->SetMarkerSize(6);  MinBias_ElectronEnergy->SetMarkerColor(5); MinBias_ElectronEnergy->SetMarkerStyle(20);
  MinBias_ElectronEnergy->DrawCopy("Psame"); MinBias_ElectronEnergy->SetMarkerColor(41);MinBias_ElectronEnergy->SetMarkerStyle(24);
  MinBias_ElectronEnergy->SetLineWidth(2);   MinBias_ElectronEnergy->SetLineColor(41);  MinBias_ElectronEnergy->DrawCopy("Esame");
  MultiJet_ElectronEnergy->SetMarkerSize(6);  MultiJet_ElectronEnergy->SetMarkerColor(8); MultiJet_ElectronEnergy->SetMarkerStyle(34);
  MultiJet_ElectronEnergy->DrawCopy("Psame"); MultiJet_ElectronEnergy->SetMarkerColor(32);MultiJet_ElectronEnergy->SetMarkerStyle(28);
  MultiJet_ElectronEnergy->SetLineWidth(2);   MultiJet_ElectronEnergy->SetLineColor(32);  MultiJet_ElectronEnergy->DrawCopy("Esame");
  legend->Draw(); ElectronEnergy_Jets->Print("/home/saksevul/T/Parallelism/ak5Jets/Kinematics.pdf","pdf"); ElectronEnergy_Jets->Close();

  TCanvas* NeuHadEnergy_Jets  = new TCanvas("NeuHadEnergy_Jets ","NeuHadEnergy_Jets ",0,0,3840,2160);
  NeuHadEnergy_Jets->SetLogy(); NeuHadEnergy_Jets->SetMargin(0.11,0,0.11,0);
  FJ_NeuHadEnergy->SetTitle(" ; E^{HadNeutro} [GeV]; #frac{1}{N_{Tot}} #frac{dN}{dE^{HadNeutro}}");
  FJ_NeuHadEnergy->GetYaxis()->SetTitleSize(0.05); FJ_NeuHadEnergy->GetYaxis()->SetTitleOffset(1.0);
  FJ_NeuHadEnergy->GetYaxis()->SetLabelSize(0.05); FJ_NeuHadEnergy->SetAxisRange(0.0000000001, 2, "Y");
  FJ_NeuHadEnergy->SetMarkerSize(6); FJ_NeuHadEnergy->SetMarkerColor(14); FJ_NeuHadEnergy->SetMarkerStyle(21);
  FJ_NeuHadEnergy->DrawCopy("P");    FJ_NeuHadEnergy->SetMarkerColor(1);  FJ_NeuHadEnergy->SetMarkerStyle(25);
  FJ_NeuHadEnergy->SetLineWidth(2);  FJ_NeuHadEnergy->SetLineColor(1);    FJ_NeuHadEnergy->DrawCopy("Esame");
  Jet_NeuHadEnergy ->SetMarkerSize(6);  Jet_NeuHadEnergy ->SetMarkerColor(42);Jet_NeuHadEnergy ->SetMarkerStyle(23);
  Jet_NeuHadEnergy ->DrawCopy("Psame"); Jet_NeuHadEnergy ->SetMarkerColor(2); Jet_NeuHadEnergy ->SetMarkerStyle(32);
  Jet_NeuHadEnergy ->SetLineWidth(2);   Jet_NeuHadEnergy ->SetLineColor(2);   Jet_NeuHadEnergy ->DrawCopy("Esame");
  BTag_NeuHadEnergy->SetMarkerSize(6);  BTag_NeuHadEnergy->SetMarkerColor(33);BTag_NeuHadEnergy->SetMarkerStyle(22);
  BTag_NeuHadEnergy->DrawCopy("Psame"); BTag_NeuHadEnergy->SetMarkerColor(4); BTag_NeuHadEnergy->SetMarkerStyle(26);
  BTag_NeuHadEnergy->SetLineWidth(2);   BTag_NeuHadEnergy->SetLineColor(4);   BTag_NeuHadEnergy->DrawCopy("Esame");
  MinBias_NeuHadEnergy->SetMarkerSize(6);  MinBias_NeuHadEnergy->SetMarkerColor(5); MinBias_NeuHadEnergy->SetMarkerStyle(20);
  MinBias_NeuHadEnergy->DrawCopy("Psame"); MinBias_NeuHadEnergy->SetMarkerColor(41);MinBias_NeuHadEnergy->SetMarkerStyle(24);
  MinBias_NeuHadEnergy->SetLineWidth(2);   MinBias_NeuHadEnergy->SetLineColor(41);  MinBias_NeuHadEnergy->DrawCopy("Esame");
  MultiJet_NeuHadEnergy->SetMarkerSize(6);  MultiJet_NeuHadEnergy->SetMarkerColor(8); MultiJet_NeuHadEnergy->SetMarkerStyle(34);
  MultiJet_NeuHadEnergy->DrawCopy("Psame"); MultiJet_NeuHadEnergy->SetMarkerColor(32);MultiJet_NeuHadEnergy->SetMarkerStyle(28);
  MultiJet_NeuHadEnergy->SetLineWidth(2);   MultiJet_NeuHadEnergy->SetLineColor(32);  MultiJet_NeuHadEnergy->DrawCopy("Esame");
  legend->Draw(); NeuHadEnergy_Jets->Print("/home/saksevul/T/Parallelism/ak5Jets/Kinematics.pdf","pdf"); NeuHadEnergy_Jets->Close();

  TCanvas* CharHadEnergy_Jets  = new TCanvas("CharHadEnergy_Jets ","CharHadEnergy_Jets ",0,0,3840,2160);
  CharHadEnergy_Jets->SetLogy(); CharHadEnergy_Jets->SetMargin(0.11,0,0.11,0);
  FJ_CharHadEnergy->SetTitle(" ; E^{HadChargado} [GeV]; #frac{1}{N_{Tot}} #frac{dN}{dE^{HadChargado}}");
  FJ_CharHadEnergy->GetYaxis()->SetTitleSize(0.05); FJ_CharHadEnergy->GetYaxis()->SetTitleOffset(1.0);
  FJ_CharHadEnergy->GetYaxis()->SetLabelSize(0.05); FJ_CharHadEnergy->SetAxisRange(0.0000000001, 2, "Y");
  FJ_CharHadEnergy->SetMarkerSize(6); FJ_CharHadEnergy->SetMarkerColor(14); FJ_CharHadEnergy->SetMarkerStyle(21);
  FJ_CharHadEnergy->DrawCopy("P");    FJ_CharHadEnergy->SetMarkerColor(1);  FJ_CharHadEnergy->SetMarkerStyle(25);
  FJ_CharHadEnergy->SetLineWidth(2);  FJ_CharHadEnergy->SetLineColor(1);    FJ_CharHadEnergy->DrawCopy("Esame");
  Jet_CharHadEnergy ->SetMarkerSize(6);  Jet_CharHadEnergy ->SetMarkerColor(42);Jet_CharHadEnergy ->SetMarkerStyle(23);
  Jet_CharHadEnergy ->DrawCopy("Psame"); Jet_CharHadEnergy ->SetMarkerColor(2); Jet_CharHadEnergy ->SetMarkerStyle(32);
  Jet_CharHadEnergy ->SetLineWidth(2);   Jet_CharHadEnergy ->SetLineColor(2);   Jet_CharHadEnergy ->DrawCopy("Esame");
  BTag_CharHadEnergy->SetMarkerSize(6);  BTag_CharHadEnergy->SetMarkerColor(33);BTag_CharHadEnergy->SetMarkerStyle(22);
  BTag_CharHadEnergy->DrawCopy("Psame"); BTag_CharHadEnergy->SetMarkerColor(4); BTag_CharHadEnergy->SetMarkerStyle(26);
  BTag_CharHadEnergy->SetLineWidth(2);   BTag_CharHadEnergy->SetLineColor(4);   BTag_CharHadEnergy->DrawCopy("Esame");
  MinBias_CharHadEnergy->SetMarkerSize(6);  MinBias_CharHadEnergy->SetMarkerColor(5); MinBias_CharHadEnergy->SetMarkerStyle(20);
  MinBias_CharHadEnergy->DrawCopy("Psame"); MinBias_CharHadEnergy->SetMarkerColor(41);MinBias_CharHadEnergy->SetMarkerStyle(24);
  MinBias_CharHadEnergy->SetLineWidth(2);   MinBias_CharHadEnergy->SetLineColor(41);  MinBias_CharHadEnergy->DrawCopy("Esame");
  MultiJet_CharHadEnergy->SetMarkerSize(6);  MultiJet_CharHadEnergy->SetMarkerColor(8); MultiJet_CharHadEnergy->SetMarkerStyle(34);
  MultiJet_CharHadEnergy->DrawCopy("Psame"); MultiJet_CharHadEnergy->SetMarkerColor(32);MultiJet_CharHadEnergy->SetMarkerStyle(28);
  MultiJet_CharHadEnergy->SetLineWidth(2);   MultiJet_CharHadEnergy->SetLineColor(32);  MultiJet_CharHadEnergy->DrawCopy("Esame");
  legend->Draw(); CharHadEnergy_Jets->Print("/home/saksevul/T/Parallelism/ak5Jets/Kinematics.pdf)","pdf"); CharHadEnergy_Jets->Close();


}

//##########################################################################################################################################################

void Multiplicities() {

  //Abrimos el archivo que nos interesa y el árbol que queremos leer.
  TFile *FJFile = new TFile("/home/saksevul/T/Pythia/FastJet/ak5FJ.root");
  TFile *JetFile = new TFile("/home/saksevul/T/OpenData/Jet_20000/ak5PF.root");
  TFile *BTagFile = new TFile("/home/saksevul/T/OpenData/BTag_20000/ak5PF.root");
  TFile *MinBiasFile = new TFile("/home/saksevul/T/OpenData/MinBias_20000/ak5PF.root");
  TFile *MultiJetFile = new TFile("/home/saksevul/T/OpenData/MultiJet_20000/ak5PF.root");


  TH1F *FJ_MuonMultiplicity =(TH1F*)FJFile->Get("Jets_Multiplicity__Muon"); FJ_MuonMultiplicity->Scale(1.0/FJ_MuonMultiplicity->Integral()); FJ_MuonMultiplicity->Rebin(1);
  TH1F *Jet_MuonMultiplicity =(TH1F*)JetFile->Get("Jets_Multiplicity__Muon"); Jet_MuonMultiplicity->Scale(1.0/Jet_MuonMultiplicity->Integral()); Jet_MuonMultiplicity->Rebin(1);
  TH1F *BTag_MuonMultiplicity =(TH1F*)BTagFile->Get("Jets_Multiplicity__Muon"); BTag_MuonMultiplicity->Scale(1.0/BTag_MuonMultiplicity->Integral()); BTag_MuonMultiplicity->Rebin(1);
  TH1F *MinBias_MuonMultiplicity =(TH1F*)MinBiasFile->Get("Jets_Multiplicity__Muon"); MinBias_MuonMultiplicity->Scale(1.0/MinBias_MuonMultiplicity->Integral()); MinBias_MuonMultiplicity->Rebin(1);
  TH1F *MultiJet_MuonMultiplicity =(TH1F*)MultiJetFile->Get("Jets_Multiplicity__Muon"); MultiJet_MuonMultiplicity->Scale(1.0/MultiJet_MuonMultiplicity->Integral()); MultiJet_MuonMultiplicity->Rebin(1);

  TH1F *FJ_PhotonMultiplicity =(TH1F*)FJFile->Get("Jets_Multiplicity__Photon"); FJ_PhotonMultiplicity->Scale(1.0/FJ_PhotonMultiplicity->Integral()); FJ_PhotonMultiplicity->Rebin(1);
  TH1F *Jet_PhotonMultiplicity =(TH1F*)JetFile->Get("Jets_Multiplicity__Photon"); Jet_PhotonMultiplicity->Scale(1.0/Jet_PhotonMultiplicity->Integral()); Jet_PhotonMultiplicity->Rebin(1);
  TH1F *BTag_PhotonMultiplicity =(TH1F*)BTagFile->Get("Jets_Multiplicity__Photon"); BTag_PhotonMultiplicity->Scale(1.0/BTag_PhotonMultiplicity->Integral()); BTag_PhotonMultiplicity->Rebin(1);
  TH1F *MinBias_PhotonMultiplicity =(TH1F*)MinBiasFile->Get("Jets_Multiplicity__Photon"); MinBias_PhotonMultiplicity->Scale(1.0/MinBias_PhotonMultiplicity->Integral()); MinBias_PhotonMultiplicity->Rebin(1);
  TH1F *MultiJet_PhotonMultiplicity =(TH1F*)MultiJetFile->Get("Jets_Multiplicity__Photon"); MultiJet_PhotonMultiplicity->Scale(1.0/MultiJet_PhotonMultiplicity->Integral()); MultiJet_PhotonMultiplicity->Rebin(1);

  TH1F *FJ_ElectronMultiplicity =(TH1F*)FJFile->Get("Jets_Multiplicity__Electron"); FJ_ElectronMultiplicity->Scale(1.0/FJ_ElectronMultiplicity->Integral()); FJ_ElectronMultiplicity->Rebin(1);
  TH1F *Jet_ElectronMultiplicity =(TH1F*)JetFile->Get("Jets_Multiplicity__Electron"); Jet_ElectronMultiplicity->Scale(1.0/Jet_ElectronMultiplicity->Integral()); Jet_ElectronMultiplicity->Rebin(1);
  TH1F *BTag_ElectronMultiplicity =(TH1F*)BTagFile->Get("Jets_Multiplicity__Electron"); BTag_ElectronMultiplicity->Scale(1.0/BTag_ElectronMultiplicity->Integral()); BTag_ElectronMultiplicity->Rebin(1);
  TH1F *MinBias_ElectronMultiplicity =(TH1F*)MinBiasFile->Get("Jets_Multiplicity__Electron"); MinBias_ElectronMultiplicity->Scale(1.0/MinBias_ElectronMultiplicity->Integral()); MinBias_ElectronMultiplicity->Rebin(1);
  TH1F *MultiJet_ElectronMultiplicity =(TH1F*)MultiJetFile->Get("Jets_Multiplicity__Electron"); MultiJet_ElectronMultiplicity->Scale(1.0/MultiJet_ElectronMultiplicity->Integral()); MultiJet_ElectronMultiplicity->Rebin(1);

  TH1F *FJ_NeuHadMultiplicity =(TH1F*)FJFile->Get("Jets_Multiplicity__NeutralHad"); FJ_NeuHadMultiplicity->Scale(1.0/FJ_NeuHadMultiplicity->Integral()); FJ_NeuHadMultiplicity->Rebin(1);
  TH1F *Jet_NeuHadMultiplicity =(TH1F*)JetFile->Get("Jets_Multiplicity__NeutralHad"); Jet_NeuHadMultiplicity->Scale(1.0/Jet_NeuHadMultiplicity->Integral()); Jet_NeuHadMultiplicity->Rebin(1);
  TH1F *BTag_NeuHadMultiplicity =(TH1F*)BTagFile->Get("Jets_Multiplicity__NeutralHad"); BTag_NeuHadMultiplicity->Scale(1.0/BTag_NeuHadMultiplicity->Integral()); BTag_NeuHadMultiplicity->Rebin(1);
  TH1F *MinBias_NeuHadMultiplicity =(TH1F*)MinBiasFile->Get("Jets_Multiplicity__NeutralHad"); MinBias_NeuHadMultiplicity->Scale(1.0/MinBias_NeuHadMultiplicity->Integral()); MinBias_NeuHadMultiplicity->Rebin(1);
  TH1F *MultiJet_NeuHadMultiplicity =(TH1F*)MultiJetFile->Get("Jets_Multiplicity__NeutralHad"); MultiJet_NeuHadMultiplicity->Scale(1.0/MultiJet_NeuHadMultiplicity->Integral()); MultiJet_NeuHadMultiplicity->Rebin(1);

  TH1F *FJ_CharHadMultiplicity =(TH1F*)FJFile->Get("Jets_Multiplicity__ChargedHad"); FJ_CharHadMultiplicity->Scale(1.0/FJ_CharHadMultiplicity->Integral()); FJ_CharHadMultiplicity->Rebin(1);
  TH1F *Jet_CharHadMultiplicity =(TH1F*)JetFile->Get("Jets_Multiplicity__ChargedHad"); Jet_CharHadMultiplicity->Scale(1.0/Jet_CharHadMultiplicity->Integral()); Jet_CharHadMultiplicity->Rebin(1);
  TH1F *BTag_CharHadMultiplicity =(TH1F*)BTagFile->Get("Jets_Multiplicity__ChargedHad"); BTag_CharHadMultiplicity->Scale(1.0/BTag_CharHadMultiplicity->Integral()); BTag_CharHadMultiplicity->Rebin(1);
  TH1F *MinBias_CharHadMultiplicity =(TH1F*)MinBiasFile->Get("Jets_Multiplicity__ChargedHad"); MinBias_CharHadMultiplicity->Scale(1.0/MinBias_CharHadMultiplicity->Integral()); MinBias_CharHadMultiplicity->Rebin(1);
  TH1F *MultiJet_CharHadMultiplicity =(TH1F*)MultiJetFile->Get("Jets_Multiplicity__ChargedHad"); MultiJet_CharHadMultiplicity->Scale(1.0/MultiJet_CharHadMultiplicity->Integral()); MultiJet_CharHadMultiplicity->Rebin(1);



  auto   legend = new TLegend(0.85,0.8,1.0,1.0);    legend->SetTextSize(0.04); legend->SetFillStyle(0); legend->SetBorderSize(0);
    legend->AddEntry(FJ_MuonMultiplicity, "MC FastJet", "l");
    legend->AddEntry(Jet_MuonMultiplicity, "PF BTag", "l");
    legend->AddEntry(BTag_MuonMultiplicity, "PF Jet", "l");
    legend->AddEntry(MinBias_MuonMultiplicity, "PF MinBias", "l");
    legend->AddEntry(MultiJet_MuonMultiplicity, "PF MultiJet", "l");


  TCanvas* MuonMultiplicity_Jets  = new TCanvas("MuonMultiplicity_Jets ","MuonMultiplicity_Jets ",0,0,3840,2160);
  MuonMultiplicity_Jets->SetLogy(); MuonMultiplicity_Jets->SetMargin(0.11,0,0.11,0); FJ_MuonMultiplicity->SetAxisRange(0.0, 7, "X");
  FJ_MuonMultiplicity->SetTitle(" ; Mult^{Muon}; #frac{1}{N_{Tot}} #frac{dN}{dMult^{Muon}}");
  FJ_MuonMultiplicity->GetYaxis()->SetTitleSize(0.05); FJ_MuonMultiplicity->GetYaxis()->SetTitleOffset(1.0);
  FJ_MuonMultiplicity->GetYaxis()->SetLabelSize(0.05); FJ_MuonMultiplicity->SetAxisRange(0.00000001, 2, "Y");
  FJ_MuonMultiplicity->SetMarkerSize(6); FJ_MuonMultiplicity->SetMarkerColor(14); FJ_MuonMultiplicity->SetMarkerStyle(21);
  FJ_MuonMultiplicity->DrawCopy("P");    FJ_MuonMultiplicity->SetMarkerColor(1);  FJ_MuonMultiplicity->SetMarkerStyle(25);
  FJ_MuonMultiplicity->SetLineWidth(2);  FJ_MuonMultiplicity->SetLineColor(1);    FJ_MuonMultiplicity->DrawCopy("Esame");
  Jet_MuonMultiplicity ->SetMarkerSize(6);  Jet_MuonMultiplicity ->SetMarkerColor(42);Jet_MuonMultiplicity ->SetMarkerStyle(23);
  Jet_MuonMultiplicity ->DrawCopy("Psame"); Jet_MuonMultiplicity ->SetMarkerColor(2); Jet_MuonMultiplicity ->SetMarkerStyle(32);
  Jet_MuonMultiplicity ->SetLineWidth(2);   Jet_MuonMultiplicity ->SetLineColor(2);   Jet_MuonMultiplicity ->DrawCopy("Esame");
  BTag_MuonMultiplicity->SetMarkerSize(6);  BTag_MuonMultiplicity->SetMarkerColor(33);BTag_MuonMultiplicity->SetMarkerStyle(22);
  BTag_MuonMultiplicity->DrawCopy("Psame"); BTag_MuonMultiplicity->SetMarkerColor(4); BTag_MuonMultiplicity->SetMarkerStyle(26);
  BTag_MuonMultiplicity->SetLineWidth(2);   BTag_MuonMultiplicity->SetLineColor(4);   BTag_MuonMultiplicity->DrawCopy("Esame");
  MinBias_MuonMultiplicity->SetMarkerSize(6);  MinBias_MuonMultiplicity->SetMarkerColor(5); MinBias_MuonMultiplicity->SetMarkerStyle(20);
  MinBias_MuonMultiplicity->DrawCopy("Psame"); MinBias_MuonMultiplicity->SetMarkerColor(41);MinBias_MuonMultiplicity->SetMarkerStyle(24);
  MinBias_MuonMultiplicity->SetLineWidth(2);   MinBias_MuonMultiplicity->SetLineColor(41);  MinBias_MuonMultiplicity->DrawCopy("Esame");
  MultiJet_MuonMultiplicity->SetMarkerSize(6);  MultiJet_MuonMultiplicity->SetMarkerColor(8); MultiJet_MuonMultiplicity->SetMarkerStyle(34);
  MultiJet_MuonMultiplicity->DrawCopy("Psame"); MultiJet_MuonMultiplicity->SetMarkerColor(32);MultiJet_MuonMultiplicity->SetMarkerStyle(28);
  MultiJet_MuonMultiplicity->SetLineWidth(2);   MultiJet_MuonMultiplicity->SetLineColor(32);  MultiJet_MuonMultiplicity->DrawCopy("Esame");
  legend->Draw(); MuonMultiplicity_Jets->Print("/home/saksevul/T/Parallelism/ak5Jets/Multiplicities.pdf(","pdf"); MuonMultiplicity_Jets->Close();

  TCanvas* PhotonMultiplicity_Jets  = new TCanvas("PhotonMultiplicity_Jets ","PhotonMultiplicity_Jets ",0,0,3840,2160);
  PhotonMultiplicity_Jets->SetLogy(); PhotonMultiplicity_Jets->SetMargin(0.11,0,0.11,0);
  FJ_PhotonMultiplicity->SetTitle(" ; Mult^{Foton}; #frac{1}{N_{Tot}} #frac{dN}{dMult^{Foton}}");
  FJ_PhotonMultiplicity->GetYaxis()->SetTitleSize(0.05); FJ_PhotonMultiplicity->GetYaxis()->SetTitleOffset(1.0);
  FJ_PhotonMultiplicity->GetYaxis()->SetLabelSize(0.05); FJ_PhotonMultiplicity->SetAxisRange(0.000000001, 2, "Y");
  FJ_PhotonMultiplicity->SetMarkerSize(6); FJ_PhotonMultiplicity->SetMarkerColor(14); FJ_PhotonMultiplicity->SetMarkerStyle(21);
  FJ_PhotonMultiplicity->DrawCopy("P");    FJ_PhotonMultiplicity->SetMarkerColor(1);  FJ_PhotonMultiplicity->SetMarkerStyle(25);
  FJ_PhotonMultiplicity->SetLineWidth(2);  FJ_PhotonMultiplicity->SetLineColor(1);    FJ_PhotonMultiplicity->DrawCopy("Esame");
  Jet_PhotonMultiplicity ->SetMarkerSize(6);  Jet_PhotonMultiplicity ->SetMarkerColor(42);Jet_PhotonMultiplicity ->SetMarkerStyle(23);
  Jet_PhotonMultiplicity ->DrawCopy("Psame"); Jet_PhotonMultiplicity ->SetMarkerColor(2); Jet_PhotonMultiplicity ->SetMarkerStyle(32);
  Jet_PhotonMultiplicity ->SetLineWidth(2);   Jet_PhotonMultiplicity ->SetLineColor(2);   Jet_PhotonMultiplicity ->DrawCopy("Esame");
  BTag_PhotonMultiplicity->SetMarkerSize(6);  BTag_PhotonMultiplicity->SetMarkerColor(33);BTag_PhotonMultiplicity->SetMarkerStyle(22);
  BTag_PhotonMultiplicity->DrawCopy("Psame"); BTag_PhotonMultiplicity->SetMarkerColor(4); BTag_PhotonMultiplicity->SetMarkerStyle(26);
  BTag_PhotonMultiplicity->SetLineWidth(2);   BTag_PhotonMultiplicity->SetLineColor(4);   BTag_PhotonMultiplicity->DrawCopy("Esame");
  MinBias_PhotonMultiplicity->SetMarkerSize(6);  MinBias_PhotonMultiplicity->SetMarkerColor(5); MinBias_PhotonMultiplicity->SetMarkerStyle(20);
  MinBias_PhotonMultiplicity->DrawCopy("Psame"); MinBias_PhotonMultiplicity->SetMarkerColor(41);MinBias_PhotonMultiplicity->SetMarkerStyle(24);
  MinBias_PhotonMultiplicity->SetLineWidth(2);   MinBias_PhotonMultiplicity->SetLineColor(41);  MinBias_PhotonMultiplicity->DrawCopy("Esame");
  MultiJet_PhotonMultiplicity->SetMarkerSize(6);  MultiJet_PhotonMultiplicity->SetMarkerColor(8); MultiJet_PhotonMultiplicity->SetMarkerStyle(34);
  MultiJet_PhotonMultiplicity->DrawCopy("Psame"); MultiJet_PhotonMultiplicity->SetMarkerColor(32);MultiJet_PhotonMultiplicity->SetMarkerStyle(28);
  MultiJet_PhotonMultiplicity->SetLineWidth(2);   MultiJet_PhotonMultiplicity->SetLineColor(32);  MultiJet_PhotonMultiplicity->DrawCopy("Esame");
  legend->Draw(); PhotonMultiplicity_Jets->Print("/home/saksevul/T/Parallelism/ak5Jets/Multiplicities.pdf","pdf"); PhotonMultiplicity_Jets->Close();

  TCanvas* ElectronMultiplicity_Jets  = new TCanvas("ElectronMultiplicity_Jets ","ElectronMultiplicity_Jets ",0,0,3840,2160);
  ElectronMultiplicity_Jets->SetLogy(); ElectronMultiplicity_Jets->SetMargin(0.11,0,0.11,0); FJ_ElectronMultiplicity->SetAxisRange(0.0, 10, "X");
  FJ_ElectronMultiplicity->SetTitle(" ; Mult^{Electron}; #frac{1}{N_{Tot}} #frac{dN}{dMult^{Electron}}");
  FJ_ElectronMultiplicity->GetYaxis()->SetTitleSize(0.05); FJ_ElectronMultiplicity->GetYaxis()->SetTitleOffset(1.0);
  FJ_ElectronMultiplicity->GetYaxis()->SetLabelSize(0.05); FJ_ElectronMultiplicity->SetAxisRange(0.00000001, 2, "Y");
  FJ_ElectronMultiplicity->SetMarkerSize(6); FJ_ElectronMultiplicity->SetMarkerColor(14); FJ_ElectronMultiplicity->SetMarkerStyle(21);
  FJ_ElectronMultiplicity->DrawCopy("P");    FJ_ElectronMultiplicity->SetMarkerColor(1);  FJ_ElectronMultiplicity->SetMarkerStyle(25);
  FJ_ElectronMultiplicity->SetLineWidth(2);  FJ_ElectronMultiplicity->SetLineColor(1);    FJ_ElectronMultiplicity->DrawCopy("Esame");
  Jet_ElectronMultiplicity ->SetMarkerSize(6);  Jet_ElectronMultiplicity ->SetMarkerColor(42);Jet_ElectronMultiplicity ->SetMarkerStyle(23);
  Jet_ElectronMultiplicity ->DrawCopy("Psame"); Jet_ElectronMultiplicity ->SetMarkerColor(2); Jet_ElectronMultiplicity ->SetMarkerStyle(32);
  Jet_ElectronMultiplicity ->SetLineWidth(2);   Jet_ElectronMultiplicity ->SetLineColor(2);   Jet_ElectronMultiplicity ->DrawCopy("Esame");
  BTag_ElectronMultiplicity->SetMarkerSize(6);  BTag_ElectronMultiplicity->SetMarkerColor(33);BTag_ElectronMultiplicity->SetMarkerStyle(22);
  BTag_ElectronMultiplicity->DrawCopy("Psame"); BTag_ElectronMultiplicity->SetMarkerColor(4); BTag_ElectronMultiplicity->SetMarkerStyle(26);
  BTag_ElectronMultiplicity->SetLineWidth(2);   BTag_ElectronMultiplicity->SetLineColor(4);   BTag_ElectronMultiplicity->DrawCopy("Esame");
  MinBias_ElectronMultiplicity->SetMarkerSize(6);  MinBias_ElectronMultiplicity->SetMarkerColor(5); MinBias_ElectronMultiplicity->SetMarkerStyle(20);
  MinBias_ElectronMultiplicity->DrawCopy("Psame"); MinBias_ElectronMultiplicity->SetMarkerColor(41);MinBias_ElectronMultiplicity->SetMarkerStyle(24);
  MinBias_ElectronMultiplicity->SetLineWidth(2);   MinBias_ElectronMultiplicity->SetLineColor(41);  MinBias_ElectronMultiplicity->DrawCopy("Esame");
  MultiJet_ElectronMultiplicity->SetMarkerSize(6);  MultiJet_ElectronMultiplicity->SetMarkerColor(8); MultiJet_ElectronMultiplicity->SetMarkerStyle(34);
  MultiJet_ElectronMultiplicity->DrawCopy("Psame"); MultiJet_ElectronMultiplicity->SetMarkerColor(32);MultiJet_ElectronMultiplicity->SetMarkerStyle(28);
  MultiJet_ElectronMultiplicity->SetLineWidth(2);   MultiJet_ElectronMultiplicity->SetLineColor(32);  MultiJet_ElectronMultiplicity->DrawCopy("Esame");
  legend->Draw(); ElectronMultiplicity_Jets->Print("/home/saksevul/T/Parallelism/ak5Jets/Multiplicities.pdf","pdf"); ElectronMultiplicity_Jets->Close();

  TCanvas* NeuHadMultiplicity_Jets  = new TCanvas("NeuHadMultiplicity_Jets ","NeuHadMultiplicity_Jets ",0,0,3840,2160);
  NeuHadMultiplicity_Jets->SetLogy(); NeuHadMultiplicity_Jets->SetMargin(0.11,0,0.11,0); FJ_NeuHadMultiplicity->SetAxisRange(0.0, 26, "X");
  FJ_NeuHadMultiplicity->SetTitle(" ; Mult^{HadNeut}; #frac{1}{N_{Tot}} #frac{dN}{dMult^{HadNeut}}");
  FJ_NeuHadMultiplicity->GetYaxis()->SetTitleSize(0.05); FJ_NeuHadMultiplicity->GetYaxis()->SetTitleOffset(1.0);
  FJ_NeuHadMultiplicity->GetYaxis()->SetLabelSize(0.05); FJ_NeuHadMultiplicity->SetAxisRange(0.00000001, 2, "Y");
  FJ_NeuHadMultiplicity->SetMarkerSize(6); FJ_NeuHadMultiplicity->SetMarkerColor(14); FJ_NeuHadMultiplicity->SetMarkerStyle(21);
  FJ_NeuHadMultiplicity->DrawCopy("P");    FJ_NeuHadMultiplicity->SetMarkerColor(1);  FJ_NeuHadMultiplicity->SetMarkerStyle(25);
  FJ_NeuHadMultiplicity->SetLineWidth(2);  FJ_NeuHadMultiplicity->SetLineColor(1);    FJ_NeuHadMultiplicity->DrawCopy("Esame");
  Jet_NeuHadMultiplicity ->SetMarkerSize(6);  Jet_NeuHadMultiplicity ->SetMarkerColor(42);Jet_NeuHadMultiplicity ->SetMarkerStyle(23);
  Jet_NeuHadMultiplicity ->DrawCopy("Psame"); Jet_NeuHadMultiplicity ->SetMarkerColor(2); Jet_NeuHadMultiplicity ->SetMarkerStyle(32);
  Jet_NeuHadMultiplicity ->SetLineWidth(2);   Jet_NeuHadMultiplicity ->SetLineColor(2);   Jet_NeuHadMultiplicity ->DrawCopy("Esame");
  BTag_NeuHadMultiplicity->SetMarkerSize(6);  BTag_NeuHadMultiplicity->SetMarkerColor(33);BTag_NeuHadMultiplicity->SetMarkerStyle(22);
  BTag_NeuHadMultiplicity->DrawCopy("Psame"); BTag_NeuHadMultiplicity->SetMarkerColor(4); BTag_NeuHadMultiplicity->SetMarkerStyle(26);
  BTag_NeuHadMultiplicity->SetLineWidth(2);   BTag_NeuHadMultiplicity->SetLineColor(4);   BTag_NeuHadMultiplicity->DrawCopy("Esame");
  MinBias_NeuHadMultiplicity->SetMarkerSize(6);  MinBias_NeuHadMultiplicity->SetMarkerColor(5); MinBias_NeuHadMultiplicity->SetMarkerStyle(20);
  MinBias_NeuHadMultiplicity->DrawCopy("Psame"); MinBias_NeuHadMultiplicity->SetMarkerColor(41);MinBias_NeuHadMultiplicity->SetMarkerStyle(24);
  MinBias_NeuHadMultiplicity->SetLineWidth(2);   MinBias_NeuHadMultiplicity->SetLineColor(41);  MinBias_NeuHadMultiplicity->DrawCopy("Esame");
  MultiJet_NeuHadMultiplicity->SetMarkerSize(6);  MultiJet_NeuHadMultiplicity->SetMarkerColor(8); MultiJet_NeuHadMultiplicity->SetMarkerStyle(34);
  MultiJet_NeuHadMultiplicity->DrawCopy("Psame"); MultiJet_NeuHadMultiplicity->SetMarkerColor(32);MultiJet_NeuHadMultiplicity->SetMarkerStyle(28);
  MultiJet_NeuHadMultiplicity->SetLineWidth(2);   MultiJet_NeuHadMultiplicity->SetLineColor(32);  MultiJet_NeuHadMultiplicity->DrawCopy("Esame");
  legend->Draw(); NeuHadMultiplicity_Jets->Print("/home/saksevul/T/Parallelism/ak5Jets/Multiplicities.pdf","pdf"); NeuHadMultiplicity_Jets->Close();

  TCanvas* CharHadMultiplicity_Jets  = new TCanvas("CharHadMultiplicity_Jets ","CharHadMultiplicity_Jets ",0,0,3840,2160);
  CharHadMultiplicity_Jets->SetLogy(); CharHadMultiplicity_Jets->SetMargin(0.11,0,0.11,0);
  FJ_CharHadMultiplicity->SetTitle(" ; Mult^{HadCharg}; #frac{1}{N_{Tot}} #frac{dN}{dMult^{HadCharg}}");
  FJ_CharHadMultiplicity->GetYaxis()->SetTitleSize(0.05); FJ_CharHadMultiplicity->GetYaxis()->SetTitleOffset(1.0);
  FJ_CharHadMultiplicity->GetYaxis()->SetLabelSize(0.05); FJ_CharHadMultiplicity->SetAxisRange(0.00000001, 2, "Y");
  FJ_CharHadMultiplicity->SetMarkerSize(6); FJ_CharHadMultiplicity->SetMarkerColor(14); FJ_CharHadMultiplicity->SetMarkerStyle(21);
  FJ_CharHadMultiplicity->DrawCopy("P");    FJ_CharHadMultiplicity->SetMarkerColor(1);  FJ_CharHadMultiplicity->SetMarkerStyle(25);
  FJ_CharHadMultiplicity->SetLineWidth(2);  FJ_CharHadMultiplicity->SetLineColor(1);    FJ_CharHadMultiplicity->DrawCopy("Esame");
  Jet_CharHadMultiplicity ->SetMarkerSize(6);  Jet_CharHadMultiplicity ->SetMarkerColor(42);Jet_CharHadMultiplicity ->SetMarkerStyle(23);
  Jet_CharHadMultiplicity ->DrawCopy("Psame"); Jet_CharHadMultiplicity ->SetMarkerColor(2); Jet_CharHadMultiplicity ->SetMarkerStyle(32);
  Jet_CharHadMultiplicity ->SetLineWidth(2);   Jet_CharHadMultiplicity ->SetLineColor(2);   Jet_CharHadMultiplicity ->DrawCopy("Esame");
  BTag_CharHadMultiplicity->SetMarkerSize(6);  BTag_CharHadMultiplicity->SetMarkerColor(33);BTag_CharHadMultiplicity->SetMarkerStyle(22);
  BTag_CharHadMultiplicity->DrawCopy("Psame"); BTag_CharHadMultiplicity->SetMarkerColor(4); BTag_CharHadMultiplicity->SetMarkerStyle(26);
  BTag_CharHadMultiplicity->SetLineWidth(2);   BTag_CharHadMultiplicity->SetLineColor(4);   BTag_CharHadMultiplicity->DrawCopy("Esame");
  MinBias_CharHadMultiplicity->SetMarkerSize(6);  MinBias_CharHadMultiplicity->SetMarkerColor(5); MinBias_CharHadMultiplicity->SetMarkerStyle(20);
  MinBias_CharHadMultiplicity->DrawCopy("Psame"); MinBias_CharHadMultiplicity->SetMarkerColor(41);MinBias_CharHadMultiplicity->SetMarkerStyle(24);
  MinBias_CharHadMultiplicity->SetLineWidth(2);   MinBias_CharHadMultiplicity->SetLineColor(41);  MinBias_CharHadMultiplicity->DrawCopy("Esame");
  MultiJet_CharHadMultiplicity->SetMarkerSize(6);  MultiJet_CharHadMultiplicity->SetMarkerColor(8); MultiJet_CharHadMultiplicity->SetMarkerStyle(34);
  MultiJet_CharHadMultiplicity->DrawCopy("Psame"); MultiJet_CharHadMultiplicity->SetMarkerColor(32);MultiJet_CharHadMultiplicity->SetMarkerStyle(28);
  MultiJet_CharHadMultiplicity->SetLineWidth(2);   MultiJet_CharHadMultiplicity->SetLineColor(32);  MultiJet_CharHadMultiplicity->DrawCopy("Esame");
  legend->Draw(); CharHadMultiplicity_Jets->Print("/home/saksevul/T/Parallelism/ak5Jets/Multiplicities.pdf)","pdf"); CharHadMultiplicity_Jets->Close();

}

//##########################################################################################################################################################

void pTHatMin() {

  //Abrimos el archivo que nos interesa y el árbol que queremos leer.
  TFile *ExpFile = new TFile("/home/saksevul/T/Pythia/FastJet/ak5FJ(Exponencial).root");
  TFile *PotFile = new TFile("/home/saksevul/T/Pythia/FastJet/ak5FJ(Potencial).root");
  TFile *LinFile = new TFile("/home/saksevul/T/Pythia/FastJet/ak5FJ(Lineal).root");

  // Parámetro de Rebin.
  Int_t nRB = 5;

  TH1F *Exp_Jets__pt_              = (TH1F*)ExpFile->Get("Jets_pt_");   Exp_Jets__pt_->Scale(1.0/Exp_Jets__pt_->Integral());  Exp_Jets__pt_->Rebin(10);
  TH1F *Exp_Jets__eta_             = (TH1F*)ExpFile->Get("Jets_eta_");  Exp_Jets__eta_->Scale(1.0/Exp_Jets__eta_->Integral());  //Exp_Jets__eta_->Rebin(10);
  TH1F *Exp_Jets__Energy           = (TH1F*)ExpFile->Get("Jets_Energy");Exp_Jets__Energy->Scale(1.0/Exp_Jets__Energy->Integral());  Exp_Jets__Energy->Rebin(10);
  TH1F *Exp_Jets__MuonEnergy       = (TH1F*)ExpFile->Get("Jets_Energy_Quotient__Muon-Jet");      Exp_Jets__MuonEnergy->Scale(1.0/Exp_Jets__MuonEnergy->Integral());  Exp_Jets__MuonEnergy->Rebin(nRB);  Exp_Jets__MuonEnergy->GetXaxis()->SetLimits(-nRB/200.0,1.2-nRB/200.0);
  TH1F *Exp_Jets__PhotonEnergy     = (TH1F*)ExpFile->Get("Jets_Energy_Quotient__Photon-Jet");    Exp_Jets__PhotonEnergy->Scale(1.0/Exp_Jets__PhotonEnergy->Integral());  Exp_Jets__PhotonEnergy->Rebin(nRB);  Exp_Jets__PhotonEnergy->GetXaxis()->SetLimits(-nRB/200.0,1.2-nRB/200.0);
  TH1F *Exp_Jets__ElectronEnergy   = (TH1F*)ExpFile->Get("Jets_Energy_Quotient__Electron-Jet");  Exp_Jets__ElectronEnergy->Scale(1.0/Exp_Jets__ElectronEnergy->Integral());  Exp_Jets__ElectronEnergy->Rebin(nRB);  Exp_Jets__ElectronEnergy->GetXaxis()->SetLimits(-nRB/200.0,1.2-nRB/200.0);
  TH1F *Exp_Jets__NeutralHadEnergy = (TH1F*)ExpFile->Get("Jets_Energy_Quotient__NeutralHad-Jet");Exp_Jets__NeutralHadEnergy->Scale(1.0/Exp_Jets__NeutralHadEnergy->Integral());  Exp_Jets__NeutralHadEnergy->Rebin(nRB);  Exp_Jets__NeutralHadEnergy->GetXaxis()->SetLimits(-nRB/200.0,1.2-nRB/200.0);
  TH1F *Exp_Jets__ChargedHadEnergy = (TH1F*)ExpFile->Get("Jets_Energy_Quotient__ChargedHad-Jet");Exp_Jets__ChargedHadEnergy->Scale(1.0/Exp_Jets__ChargedHadEnergy->Integral());  Exp_Jets__ChargedHadEnergy->Rebin(nRB);  Exp_Jets__ChargedHadEnergy->GetXaxis()->SetLimits(-nRB/200.0,1.2-nRB/200.0);

  TH1F *Pot_Jets__pt_              = (TH1F*)PotFile->Get("Jets_pt_");   Pot_Jets__pt_->Scale(1.0/Pot_Jets__pt_->Integral());  Pot_Jets__pt_->Rebin(10);
  TH1F *Pot_Jets__eta_             = (TH1F*)PotFile->Get("Jets_eta_");  Pot_Jets__eta_->Scale(1.0/Pot_Jets__eta_->Integral());  //Pot_Jets__eta_->Rebin(10);
  TH1F *Pot_Jets__Energy           = (TH1F*)PotFile->Get("Jets_Energy");Pot_Jets__Energy->Scale(1.0/Pot_Jets__Energy->Integral());  Pot_Jets__Energy->Rebin(10);
  TH1F *Pot_Jets__MuonEnergy       = (TH1F*)PotFile->Get("Jets_Energy_Quotient__Muon-Jet");      Pot_Jets__MuonEnergy->Scale(1.0/Pot_Jets__MuonEnergy->Integral());  Pot_Jets__MuonEnergy->Rebin(nRB);  Pot_Jets__MuonEnergy->GetXaxis()->SetLimits(-nRB/200.0,1.2-nRB/200.0);
  TH1F *Pot_Jets__PhotonEnergy     = (TH1F*)PotFile->Get("Jets_Energy_Quotient__Photon-Jet");    Pot_Jets__PhotonEnergy->Scale(1.0/Pot_Jets__PhotonEnergy->Integral());  Pot_Jets__PhotonEnergy->Rebin(nRB);  Pot_Jets__PhotonEnergy->GetXaxis()->SetLimits(-nRB/200.0,1.2-nRB/200.0);
  TH1F *Pot_Jets__ElectronEnergy   = (TH1F*)PotFile->Get("Jets_Energy_Quotient__Electron-Jet");  Pot_Jets__ElectronEnergy->Scale(1.0/Pot_Jets__ElectronEnergy->Integral());  Pot_Jets__ElectronEnergy->Rebin(nRB);  Pot_Jets__ElectronEnergy->GetXaxis()->SetLimits(-nRB/200.0,1.2-nRB/200.0);
  TH1F *Pot_Jets__NeutralHadEnergy = (TH1F*)PotFile->Get("Jets_Energy_Quotient__NeutralHad-Jet");Pot_Jets__NeutralHadEnergy->Scale(1.0/Pot_Jets__NeutralHadEnergy->Integral());  Pot_Jets__NeutralHadEnergy->Rebin(nRB);  Pot_Jets__NeutralHadEnergy->GetXaxis()->SetLimits(-nRB/200.0,1.2-nRB/200.0);
  TH1F *Pot_Jets__ChargedHadEnergy = (TH1F*)PotFile->Get("Jets_Energy_Quotient__ChargedHad-Jet");Pot_Jets__ChargedHadEnergy->Scale(1.0/Pot_Jets__ChargedHadEnergy->Integral());  Pot_Jets__ChargedHadEnergy->Rebin(nRB);  Pot_Jets__ChargedHadEnergy->GetXaxis()->SetLimits(-nRB/200.0,1.2-nRB/200.0);

  TH1F *Lin_Jets__pt_              = (TH1F*)LinFile->Get("Jets_pt_");   Lin_Jets__pt_->Scale(1.0/Lin_Jets__pt_->Integral());  Lin_Jets__pt_->Rebin(10);
  TH1F *Lin_Jets__eta_             = (TH1F*)LinFile->Get("Jets_eta_");  Lin_Jets__eta_->Scale(1.0/Lin_Jets__eta_->Integral());  //Lin_Jets__eta_->Rebin(10);
  TH1F *Lin_Jets__Energy           = (TH1F*)LinFile->Get("Jets_Energy");Lin_Jets__Energy->Scale(1.0/Lin_Jets__Energy->Integral());  Lin_Jets__Energy->Rebin(10);
  TH1F *Lin_Jets__MuonEnergy       = (TH1F*)LinFile->Get("Jets_Energy_Quotient__Muon-Jet");      Lin_Jets__MuonEnergy->Scale(1.0/Lin_Jets__MuonEnergy->Integral());  Lin_Jets__MuonEnergy->Rebin(nRB);  Lin_Jets__MuonEnergy->GetXaxis()->SetLimits(-nRB/200.0,1.2-nRB/200.0);
  TH1F *Lin_Jets__PhotonEnergy     = (TH1F*)LinFile->Get("Jets_Energy_Quotient__Photon-Jet");    Lin_Jets__PhotonEnergy->Scale(1.0/Lin_Jets__PhotonEnergy->Integral());  Lin_Jets__PhotonEnergy->Rebin(nRB);  Lin_Jets__PhotonEnergy->GetXaxis()->SetLimits(-nRB/200.0,1.2-nRB/200.0);
  TH1F *Lin_Jets__ElectronEnergy   = (TH1F*)LinFile->Get("Jets_Energy_Quotient__Electron-Jet");  Lin_Jets__ElectronEnergy->Scale(1.0/Lin_Jets__ElectronEnergy->Integral());  Lin_Jets__ElectronEnergy->Rebin(nRB);  Lin_Jets__ElectronEnergy->GetXaxis()->SetLimits(-nRB/200.0,1.2-nRB/200.0);
  TH1F *Lin_Jets__NeutralHadEnergy = (TH1F*)LinFile->Get("Jets_Energy_Quotient__NeutralHad-Jet");Lin_Jets__NeutralHadEnergy->Scale(1.0/Lin_Jets__NeutralHadEnergy->Integral());  Lin_Jets__NeutralHadEnergy->Rebin(nRB);  Lin_Jets__NeutralHadEnergy->GetXaxis()->SetLimits(-nRB/200.0,1.2-nRB/200.0);
  TH1F *Lin_Jets__ChargedHadEnergy = (TH1F*)LinFile->Get("Jets_Energy_Quotient__ChargedHad-Jet");Lin_Jets__ChargedHadEnergy->Scale(1.0/Lin_Jets__ChargedHadEnergy->Integral());  Lin_Jets__ChargedHadEnergy->Rebin(nRB);  Lin_Jets__ChargedHadEnergy->GetXaxis()->SetLimits(-nRB/200.0,1.2-nRB/200.0);


  TH1F *CLONE_Exp_Jets__pt_ =(TH1F*)Exp_Jets__pt_->Clone(); CLONE_Exp_Jets__pt_->SetMarkerSize(16); CLONE_Exp_Jets__pt_->SetMarkerStyle(47); CLONE_Exp_Jets__pt_->SetMarkerColor(40);
  TH1F *CLONE_Pot_Jets__pt_ =(TH1F*)Pot_Jets__pt_->Clone(); CLONE_Pot_Jets__pt_->SetMarkerSize(16); CLONE_Pot_Jets__pt_->SetMarkerStyle(45); CLONE_Pot_Jets__pt_->SetMarkerColor(42);
  TH1F *CLONE_Lin_Jets__pt_ =(TH1F*)Lin_Jets__pt_->Clone(); CLONE_Lin_Jets__pt_->SetMarkerSize(16); CLONE_Lin_Jets__pt_->SetMarkerStyle(29); CLONE_Lin_Jets__pt_->SetMarkerColor(29);

  auto   Leg = new TLegend(0.82,0.8,1.0,0.999);    Leg->SetTextSize(0.06); Leg->SetFillStyle(0); Leg->SetBorderSize(0);
  Leg->AddEntry(CLONE_Exp_Jets__pt_, "Exponencial", "p");
  Leg->AddEntry(CLONE_Pot_Jets__pt_, "Potencial", "p");
  Leg->AddEntry(CLONE_Lin_Jets__pt_, "Lineal", "p");
  // Leg->SetLegendTextSize(0.06);


  TH1F *CLON2_Exp_Jets__pt_ =(TH1F*)Exp_Jets__pt_->Clone(); CLON2_Exp_Jets__pt_->SetMarkerSize(16); CLON2_Exp_Jets__pt_->SetMarkerStyle(46); CLON2_Exp_Jets__pt_->SetMarkerColor(9);
  CLON2_Exp_Jets__pt_->SetLineWidth(3);  CLON2_Exp_Jets__pt_->SetLineColor(9);
  TH1F *CLON2_Pot_Jets__pt_ =(TH1F*)Pot_Jets__pt_->Clone(); CLON2_Pot_Jets__pt_->SetMarkerSize(16); CLON2_Pot_Jets__pt_->SetMarkerStyle(44); CLON2_Pot_Jets__pt_->SetMarkerColor(46);
  CLON2_Pot_Jets__pt_->SetLineWidth(3);  CLON2_Pot_Jets__pt_->SetLineColor(46);
  TH1F *CLON2_Lin_Jets__pt_ =(TH1F*)Lin_Jets__pt_->Clone(); CLON2_Lin_Jets__pt_->SetMarkerSize(16); CLON2_Lin_Jets__pt_->SetMarkerStyle(30); CLON2_Lin_Jets__pt_->SetMarkerColor(8);
  CLON2_Lin_Jets__pt_->SetLineWidth(3);  CLON2_Lin_Jets__pt_->SetLineColor(8);

  auto   Legend = new TLegend(0.82,0.8,1.0,0.999);    Legend->SetTextSize(0.06); Legend->SetFillStyle(0); Legend->SetBorderSize(0);
  Legend->AddEntry(CLON2_Exp_Jets__pt_, "Exponencial", "lep");
  Legend->AddEntry(CLON2_Pot_Jets__pt_, "Potencial", "lep");
  Legend->AddEntry(CLON2_Lin_Jets__pt_, "Lineal", "lep");



  TCanvas* pTHatMin_pT_ = new TCanvas("pTHatMin_pT_ ","pTHatMin_pT_ ",0,0,5040,2160);
  pTHatMin_pT_->SetLogy(); pTHatMin_pT_->SetMargin(0.126,0,0.108,0);
  Exp_Jets__pt_->SetTitle("Espectro de p_{T} para Jets; p_{T} [GeV]; #frac{1}{N_{Tot}} #frac{dN}{dp_{T}}");
  Exp_Jets__pt_->SetMarkerSize(12); Exp_Jets__pt_->SetMarkerColor(40); Exp_Jets__pt_->SetMarkerStyle(47);
  Exp_Jets__pt_->DrawCopy("P");    Exp_Jets__pt_->SetMarkerColor(9);  Exp_Jets__pt_->SetMarkerStyle(46);
  Exp_Jets__pt_->SetLineWidth(2);  Exp_Jets__pt_->SetLineColor(9);    Exp_Jets__pt_->DrawCopy("E1same");
  Pot_Jets__pt_->SetMarkerSize(12); Pot_Jets__pt_->SetMarkerColor(42); Pot_Jets__pt_->SetMarkerStyle(45);
  Pot_Jets__pt_->DrawCopy("Psame");Pot_Jets__pt_->SetMarkerColor(46); Pot_Jets__pt_->SetMarkerStyle(44);
  Pot_Jets__pt_->SetLineWidth(2);  Pot_Jets__pt_->SetLineColor(46);   Pot_Jets__pt_->DrawCopy("E1same");
  Lin_Jets__pt_->SetMarkerSize(12); Lin_Jets__pt_->SetMarkerColor(29); Lin_Jets__pt_->SetMarkerStyle(29);
  Lin_Jets__pt_->DrawCopy("Psame");Lin_Jets__pt_->SetMarkerColor(8);  Lin_Jets__pt_->SetMarkerStyle(30);
  Lin_Jets__pt_->SetLineWidth(2);  Lin_Jets__pt_->SetLineColor(8);    Lin_Jets__pt_->DrawCopy("E1same");
  Leg->Draw(); Legend->Draw(); pTHatMin_pT_->Print("/home/saksevul/T/Parallelism/ak5Jets/pTHatMin.pdf(","pdf"); pTHatMin_pT_->Close();


  TCanvas* pTHatMin_Energy = new TCanvas("pTHatMin_Energy ","pTHatMin_Energy ",0,0,5040,2160);
  pTHatMin_Energy->SetLogy(); pTHatMin_Energy->SetMargin(0.126,0,0.108,0);
  Exp_Jets__Energy->SetTitle("Espectro de E para Jets; E [GeV]; #frac{1}{N_{Tot}} #frac{dN}{dE}");
  Exp_Jets__Energy->SetMarkerSize(12); Exp_Jets__Energy->SetMarkerColor(40); Exp_Jets__Energy->SetMarkerStyle(47);
  Exp_Jets__Energy->DrawCopy("P");    Exp_Jets__Energy->SetMarkerColor(9);  Exp_Jets__Energy->SetMarkerStyle(46);
  Exp_Jets__Energy->SetLineWidth(2);  Exp_Jets__Energy->SetLineColor(9);    Exp_Jets__Energy->DrawCopy("E1same");
  Pot_Jets__Energy->SetMarkerSize(12); Pot_Jets__Energy->SetMarkerColor(42); Pot_Jets__Energy->SetMarkerStyle(45);
  Pot_Jets__Energy->DrawCopy("Psame");Pot_Jets__Energy->SetMarkerColor(46); Pot_Jets__Energy->SetMarkerStyle(44);
  Pot_Jets__Energy->SetLineWidth(2);  Pot_Jets__Energy->SetLineColor(46);   Pot_Jets__Energy->DrawCopy("E1same");
  Lin_Jets__Energy->SetMarkerSize(12); Lin_Jets__Energy->SetMarkerColor(29); Lin_Jets__Energy->SetMarkerStyle(29);
  Lin_Jets__Energy->DrawCopy("Psame");Lin_Jets__Energy->SetMarkerColor(8);  Lin_Jets__Energy->SetMarkerStyle(30);
  Lin_Jets__Energy->SetLineWidth(2);  Lin_Jets__Energy->SetLineColor(8);    Lin_Jets__Energy->DrawCopy("E1same");
  Leg->Draw(); Legend->Draw(); pTHatMin_Energy->Print("/home/saksevul/T/Parallelism/ak5Jets/pTHatMin.pdf","pdf"); pTHatMin_Energy->Close();


  TCanvas* pTHatMin_MuonEnergy = new TCanvas("pTHatMin_MuonEnergy ","pTHatMin_MuonEnergy ",0,0,5040,2160);
  pTHatMin_MuonEnergy->SetLogy(); pTHatMin_MuonEnergy->SetMargin(0.126,0,0.108,0); Exp_Jets__MuonEnergy->SetAxisRange(0.0, 1.0, "X");
  Exp_Jets__MuonEnergy->SetTitle(" ; E^{Mu#acute{o}n}/E^{Jet}; #frac{1}{N_{Tot}} #frac{dN}{d#frac{E^{Mu#acute{o}n}}{E^{Jet}}}");
  Exp_Jets__MuonEnergy->GetXaxis()->SetLabelSize(0.06);  Exp_Jets__MuonEnergy->GetYaxis()->SetTitleSize(0.06);
  Exp_Jets__MuonEnergy->GetXaxis()->SetTitleSize(0.06);  Exp_Jets__MuonEnergy->GetYaxis()->SetLabelSize(0.06);
  Exp_Jets__MuonEnergy->GetXaxis()->SetTitleOffset(0.82);Exp_Jets__MuonEnergy->GetYaxis()->SetTitleOffset(0.91);
  Exp_Jets__MuonEnergy->SetMarkerSize(12); Exp_Jets__MuonEnergy->SetMarkerColor(40); Exp_Jets__MuonEnergy->SetMarkerStyle(47);
  Exp_Jets__MuonEnergy->DrawCopy("P");    Exp_Jets__MuonEnergy->SetMarkerColor(9);  Exp_Jets__MuonEnergy->SetMarkerStyle(46);
  Exp_Jets__MuonEnergy->SetLineWidth(2);  Exp_Jets__MuonEnergy->SetLineColor(9);    Exp_Jets__MuonEnergy->DrawCopy("E1same");
  Pot_Jets__MuonEnergy->SetMarkerSize(12); Pot_Jets__MuonEnergy->SetMarkerColor(42); Pot_Jets__MuonEnergy->SetMarkerStyle(45);
  Pot_Jets__MuonEnergy->DrawCopy("Psame");Pot_Jets__MuonEnergy->SetMarkerColor(46); Pot_Jets__MuonEnergy->SetMarkerStyle(44);
  Pot_Jets__MuonEnergy->SetLineWidth(2);  Pot_Jets__MuonEnergy->SetLineColor(46);   Pot_Jets__MuonEnergy->DrawCopy("E1same");
  Lin_Jets__MuonEnergy->SetMarkerSize(12); Lin_Jets__MuonEnergy->SetMarkerColor(29); Lin_Jets__MuonEnergy->SetMarkerStyle(29);
  Lin_Jets__MuonEnergy->DrawCopy("Psame");Lin_Jets__MuonEnergy->SetMarkerColor(8);  Lin_Jets__MuonEnergy->SetMarkerStyle(30);
  Lin_Jets__MuonEnergy->SetLineWidth(2);  Lin_Jets__MuonEnergy->SetLineColor(8);    Lin_Jets__MuonEnergy->DrawCopy("E1same");
  Leg->Draw(); Legend->Draw(); pTHatMin_MuonEnergy->Print("/home/saksevul/T/Parallelism/ak5Jets/pTHatMin.pdf","pdf"); pTHatMin_MuonEnergy->Close();


  TCanvas* pTHatMin_PhotonEnergy = new TCanvas("pTHatMin_PhotonEnergy ","pTHatMin_PhotonEnergy ",0,0,5040,2160);
  pTHatMin_PhotonEnergy->SetLogy(); pTHatMin_PhotonEnergy->SetMargin(0.126,0,0.108,0); Exp_Jets__PhotonEnergy->SetAxisRange(0.0, 1.0, "X");
  Exp_Jets__PhotonEnergy->SetTitle(" ; E^{Fot#acute{o}n}/E^{Jet}; #frac{1}{N_{Tot}} #frac{dN}{d#frac{E^{Fot#acute{o}n}}{E^{Jet}}}");
  Exp_Jets__PhotonEnergy->GetXaxis()->SetLabelSize(0.06);  Exp_Jets__PhotonEnergy->GetYaxis()->SetTitleSize(0.06);
  Exp_Jets__PhotonEnergy->GetXaxis()->SetTitleSize(0.06);  Exp_Jets__PhotonEnergy->GetYaxis()->SetLabelSize(0.06);
  Exp_Jets__PhotonEnergy->GetXaxis()->SetTitleOffset(0.82);Exp_Jets__PhotonEnergy->GetYaxis()->SetTitleOffset(0.91);
  Exp_Jets__PhotonEnergy->SetMarkerSize(12); Exp_Jets__PhotonEnergy->SetMarkerColor(40); Exp_Jets__PhotonEnergy->SetMarkerStyle(47);
  Exp_Jets__PhotonEnergy->DrawCopy("P");    Exp_Jets__PhotonEnergy->SetMarkerColor(9);  Exp_Jets__PhotonEnergy->SetMarkerStyle(46);
  Exp_Jets__PhotonEnergy->SetLineWidth(2);  Exp_Jets__PhotonEnergy->SetLineColor(9);    Exp_Jets__PhotonEnergy->DrawCopy("E1same");
  Pot_Jets__PhotonEnergy->SetMarkerSize(12); Pot_Jets__PhotonEnergy->SetMarkerColor(42); Pot_Jets__PhotonEnergy->SetMarkerStyle(45);
  Pot_Jets__PhotonEnergy->DrawCopy("Psame");Pot_Jets__PhotonEnergy->SetMarkerColor(46); Pot_Jets__PhotonEnergy->SetMarkerStyle(44);
  Pot_Jets__PhotonEnergy->SetLineWidth(2);  Pot_Jets__PhotonEnergy->SetLineColor(46);   Pot_Jets__PhotonEnergy->DrawCopy("E1same");
  Lin_Jets__PhotonEnergy->SetMarkerSize(12); Lin_Jets__PhotonEnergy->SetMarkerColor(29); Lin_Jets__PhotonEnergy->SetMarkerStyle(29);
  Lin_Jets__PhotonEnergy->DrawCopy("Psame");Lin_Jets__PhotonEnergy->SetMarkerColor(8);  Lin_Jets__PhotonEnergy->SetMarkerStyle(30);
  Lin_Jets__PhotonEnergy->SetLineWidth(2);  Lin_Jets__PhotonEnergy->SetLineColor(8);    Lin_Jets__PhotonEnergy->DrawCopy("E1same");
  Leg->Draw(); Legend->Draw(); pTHatMin_PhotonEnergy->Print("/home/saksevul/T/Parallelism/ak5Jets/pTHatMin.pdf","pdf"); pTHatMin_PhotonEnergy->Close();


  TCanvas* pTHatMin_ElectronEnergy = new TCanvas("pTHatMin_ElectronEnergy ","pTHatMin_ElectronEnergy ",0,0,5040,2160);
  pTHatMin_ElectronEnergy->SetLogy(); pTHatMin_ElectronEnergy->SetMargin(0.126,0,0.108,0); Exp_Jets__ElectronEnergy->SetAxisRange(0.0, 1.0, "X");
  Exp_Jets__ElectronEnergy->SetTitle(" ; E^{Electr#acute{o}n}/E^{Jet}; #frac{1}{N_{Tot}} #frac{dN}{d#frac{E^{Electr#acute{o}n}}{E^{Jet}}}");
  Exp_Jets__ElectronEnergy->GetXaxis()->SetLabelSize(0.06);  Exp_Jets__ElectronEnergy->GetYaxis()->SetTitleSize(0.06);
  Exp_Jets__ElectronEnergy->GetXaxis()->SetTitleSize(0.06);  Exp_Jets__ElectronEnergy->GetYaxis()->SetLabelSize(0.06);
  Exp_Jets__ElectronEnergy->GetXaxis()->SetTitleOffset(0.82);Exp_Jets__ElectronEnergy->GetYaxis()->SetTitleOffset(0.91);
  Exp_Jets__ElectronEnergy->SetMarkerSize(12); Exp_Jets__ElectronEnergy->SetMarkerColor(40); Exp_Jets__ElectronEnergy->SetMarkerStyle(47);
  Exp_Jets__ElectronEnergy->DrawCopy("P");    Exp_Jets__ElectronEnergy->SetMarkerColor(9);  Exp_Jets__ElectronEnergy->SetMarkerStyle(46);
  Exp_Jets__ElectronEnergy->SetLineWidth(2);  Exp_Jets__ElectronEnergy->SetLineColor(9);    Exp_Jets__ElectronEnergy->DrawCopy("E1same");
  Pot_Jets__ElectronEnergy->SetMarkerSize(12); Pot_Jets__ElectronEnergy->SetMarkerColor(42); Pot_Jets__ElectronEnergy->SetMarkerStyle(45);
  Pot_Jets__ElectronEnergy->DrawCopy("Psame");Pot_Jets__ElectronEnergy->SetMarkerColor(46); Pot_Jets__ElectronEnergy->SetMarkerStyle(44);
  Pot_Jets__ElectronEnergy->SetLineWidth(2);  Pot_Jets__ElectronEnergy->SetLineColor(46);   Pot_Jets__ElectronEnergy->DrawCopy("E1same");
  Lin_Jets__ElectronEnergy->SetMarkerSize(12); Lin_Jets__ElectronEnergy->SetMarkerColor(29); Lin_Jets__ElectronEnergy->SetMarkerStyle(29);
  Lin_Jets__ElectronEnergy->DrawCopy("Psame");Lin_Jets__ElectronEnergy->SetMarkerColor(8);  Lin_Jets__ElectronEnergy->SetMarkerStyle(30);
  Lin_Jets__ElectronEnergy->SetLineWidth(2);  Lin_Jets__ElectronEnergy->SetLineColor(8);    Lin_Jets__ElectronEnergy->DrawCopy("E1same");
  Leg->Draw(); Legend->Draw(); pTHatMin_ElectronEnergy->Print("/home/saksevul/T/Parallelism/ak5Jets/pTHatMin.pdf","pdf"); pTHatMin_ElectronEnergy->Close();


  TCanvas* pTHatMin_NeutralHadEnergy = new TCanvas("pTHatMin_NeutralHadEnergy ","pTHatMin_NeutralHadEnergy ",0,0,5040,2160);
  pTHatMin_NeutralHadEnergy->SetLogy(); pTHatMin_NeutralHadEnergy->SetMargin(0.126,0,0.108,0); Exp_Jets__NeutralHadEnergy->SetAxisRange(0.0, 1.0, "X");
  Exp_Jets__NeutralHadEnergy->GetXaxis()->SetLabelSize(0.06);  Exp_Jets__NeutralHadEnergy->GetYaxis()->SetTitleSize(0.06);
  Exp_Jets__NeutralHadEnergy->GetXaxis()->SetTitleSize(0.06);  Exp_Jets__NeutralHadEnergy->GetYaxis()->SetLabelSize(0.06);
  Exp_Jets__NeutralHadEnergy->GetXaxis()->SetTitleOffset(0.82);Exp_Jets__NeutralHadEnergy->GetYaxis()->SetTitleOffset(0.91);
  Exp_Jets__NeutralHadEnergy->SetTitle(" ; E^{HadNeutro}/E^{Jet}; #frac{1}{N_{Tot}} #frac{dN}{d#frac{E^{HadNeutro}}{E^{Jet}}}");
  Exp_Jets__NeutralHadEnergy->SetMarkerSize(12); Exp_Jets__NeutralHadEnergy->SetMarkerColor(40); Exp_Jets__NeutralHadEnergy->SetMarkerStyle(47);
  Exp_Jets__NeutralHadEnergy->DrawCopy("P");    Exp_Jets__NeutralHadEnergy->SetMarkerColor(9);  Exp_Jets__NeutralHadEnergy->SetMarkerStyle(46);
  Exp_Jets__NeutralHadEnergy->SetLineWidth(2);  Exp_Jets__NeutralHadEnergy->SetLineColor(9);    Exp_Jets__NeutralHadEnergy->DrawCopy("E1same");
  Pot_Jets__NeutralHadEnergy->SetMarkerSize(12); Pot_Jets__NeutralHadEnergy->SetMarkerColor(42); Pot_Jets__NeutralHadEnergy->SetMarkerStyle(45);
  Pot_Jets__NeutralHadEnergy->DrawCopy("Psame");Pot_Jets__NeutralHadEnergy->SetMarkerColor(46); Pot_Jets__NeutralHadEnergy->SetMarkerStyle(44);
  Pot_Jets__NeutralHadEnergy->SetLineWidth(2);  Pot_Jets__NeutralHadEnergy->SetLineColor(46);   Pot_Jets__NeutralHadEnergy->DrawCopy("E1same");
  Lin_Jets__NeutralHadEnergy->SetMarkerSize(12); Lin_Jets__NeutralHadEnergy->SetMarkerColor(29); Lin_Jets__NeutralHadEnergy->SetMarkerStyle(29);
  Lin_Jets__NeutralHadEnergy->DrawCopy("Psame");Lin_Jets__NeutralHadEnergy->SetMarkerColor(8);  Lin_Jets__NeutralHadEnergy->SetMarkerStyle(30);
  Lin_Jets__NeutralHadEnergy->SetLineWidth(2);  Lin_Jets__NeutralHadEnergy->SetLineColor(8);    Lin_Jets__NeutralHadEnergy->DrawCopy("E1same");
  Leg->Draw(); Legend->Draw(); pTHatMin_NeutralHadEnergy->Print("/home/saksevul/T/Parallelism/ak5Jets/pTHatMin.pdf","pdf"); pTHatMin_NeutralHadEnergy->Close();


  TCanvas* pTHatMin_ChargedHadEnergy = new TCanvas("pTHatMin_ChargedHadEnergy ","pTHatMin_ChargedHadEnergy ",0,0,5040,2160);
  pTHatMin_ChargedHadEnergy->SetLogy(); pTHatMin_ChargedHadEnergy->SetMargin(0.126,0,0.108,0); Exp_Jets__ChargedHadEnergy->SetAxisRange(0.0, 1.0, "X");
  Exp_Jets__ChargedHadEnergy->GetXaxis()->SetLabelSize(0.06);  Exp_Jets__ChargedHadEnergy->GetYaxis()->SetTitleSize(0.06);
  Exp_Jets__ChargedHadEnergy->GetXaxis()->SetTitleSize(0.06);  Exp_Jets__ChargedHadEnergy->GetYaxis()->SetLabelSize(0.06);
  Exp_Jets__ChargedHadEnergy->GetXaxis()->SetTitleOffset(0.82);Exp_Jets__ChargedHadEnergy->GetYaxis()->SetTitleOffset(0.91);
  Exp_Jets__ChargedHadEnergy->SetTitle(" ; E^{HadCargado}/E^{Jet}; #frac{1}{N_{Tot}} #frac{dN}{d#frac{E^{HadCargado}}{E^{Jet}}}");
  Exp_Jets__ChargedHadEnergy->SetMarkerSize(12); Exp_Jets__ChargedHadEnergy->SetMarkerColor(40); Exp_Jets__ChargedHadEnergy->SetMarkerStyle(47);
  Exp_Jets__ChargedHadEnergy->DrawCopy("P");    Exp_Jets__ChargedHadEnergy->SetMarkerColor(9);  Exp_Jets__ChargedHadEnergy->SetMarkerStyle(46);
  Exp_Jets__ChargedHadEnergy->SetLineWidth(2);  Exp_Jets__ChargedHadEnergy->SetLineColor(9);    Exp_Jets__ChargedHadEnergy->DrawCopy("E1same");
  Pot_Jets__ChargedHadEnergy->SetMarkerSize(12); Pot_Jets__ChargedHadEnergy->SetMarkerColor(42); Pot_Jets__ChargedHadEnergy->SetMarkerStyle(45);
  Pot_Jets__ChargedHadEnergy->DrawCopy("Psame");Pot_Jets__ChargedHadEnergy->SetMarkerColor(46); Pot_Jets__ChargedHadEnergy->SetMarkerStyle(44);
  Pot_Jets__ChargedHadEnergy->SetLineWidth(2);  Pot_Jets__ChargedHadEnergy->SetLineColor(46);   Pot_Jets__ChargedHadEnergy->DrawCopy("E1same");
  Lin_Jets__ChargedHadEnergy->SetMarkerSize(12); Lin_Jets__ChargedHadEnergy->SetMarkerColor(29); Lin_Jets__ChargedHadEnergy->SetMarkerStyle(29);
  Lin_Jets__ChargedHadEnergy->DrawCopy("Psame");Lin_Jets__ChargedHadEnergy->SetMarkerColor(8);  Lin_Jets__ChargedHadEnergy->SetMarkerStyle(30);
  Lin_Jets__ChargedHadEnergy->SetLineWidth(2);  Lin_Jets__ChargedHadEnergy->SetLineColor(8);    Lin_Jets__ChargedHadEnergy->DrawCopy("E1same");
  Leg->Draw(); Legend->Draw(); pTHatMin_ChargedHadEnergy->Print("/home/saksevul/T/Parallelism/ak5Jets/pTHatMin.pdf)","pdf"); pTHatMin_ChargedHadEnergy->Close();

}

//##########################################################################################################################################################
void rootMacro_Limits(){  gStyle->SetOptStat(0);

  Limits();
  // Kinematics();
  // Multiplicities();
  // pTHatMin();
}
