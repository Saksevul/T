void DistanciaAngular() {
  //Abrimos el archivo que nos interesa y el árbol que queremos leer.
  TFile *FJFile = new TFile("/home/saksevul/T/PYTHIA/FastJet/ak5FJ.root");
  TFile *JetFile = new TFile("/home/saksevul/T/OpenData/Jet_20000/ak5PF.root");
  TFile *BTagFile = new TFile("/home/saksevul/T/OpenData/BTag_20000/ak5PF.root");
  TFile *MultiJetFile = new TFile("/home/saksevul/T/OpenData/MultiJet_20000/ak5PF.root");

  TH1F *D__Muon_ak5FJ, *D__Electron_ak5FJ, *ak5FastJet__D_Jet_Jet,
       *D__Muon_ak5PFJet, *D__Electron_ak5PFJet, *ak5PFBTag__D_Jet_Jet;

  ak5FastJet__D_Jet_Jet =(TH1F*)FJFile->Get("ak5FastJet__D__Jet_Jet"); ak5PFBTag__D_Jet_Jet->Scale(1.0/ak5PFBTag__D_Jet_Jet->Integral());
  ak5PFBTag__D_Jet_Jet =(TH1F*)BTagFile->Get("ak5PFJets__D__Jet_Jet"); ak5PFBTag__D_Jet_Jet->Scale(1.0/ak5PFBTag__D_Jet_Jet->Integral());


    auto   legend = new TLegend(0.61,0.74,0.90,0.92);
      legend->SetTextSize(0.04);
      legend->AddEntry(ak5PFBTag__D_Jet_Jet, "Open-Data PFJets", "lp");
      legend->AddEntry(ak5FastJet__D_Jet_Jet, "MC FastJet", "lp");


  //Creamos un liezo en el cual dibujarémos los histogramas sin modificar.
  TCanvas* ak5PFJet__D_Jet_Jet = new TCanvas("DistanciaAngular","Distancia Angular de FastJet y PFJets por Evento",10,10,1920,1080);
  ak5PFJet__D_Jet_Jet->SetFillColor(0);  ak5PFJet__D_Jet_Jet->SetFrameBorderMode(0);  gPad->SetLogy();

  // Esto es para modificar las etiquetas del canvas.
  ak5PFBTag__D_Jet_Jet->SetTitle("Distancia Angular entre los Jets de cada Evento; Distancia Angular; U. A.");
  ak5PFBTag__D_Jet_Jet->GetXaxis()->SetLabelSize(0.05); ak5PFBTag__D_Jet_Jet->GetYaxis()->SetLabelSize(0.05);
  ak5PFBTag__D_Jet_Jet->GetXaxis()->SetTitleSize(0.05); ak5PFBTag__D_Jet_Jet->GetYaxis()->SetTitleSize(0.05);
  ak5PFBTag__D_Jet_Jet->GetXaxis()->SetTitleOffset(1.0);ak5PFBTag__D_Jet_Jet->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  ak5PFBTag__D_Jet_Jet -> Draw("E1"); ak5PFBTag__D_Jet_Jet->SetLineColor(2);
  ak5PFBTag__D_Jet_Jet->SetMarkerStyle(20); ak5PFBTag__D_Jet_Jet->SetMarkerColor(2);
  ak5FastJet__D_Jet_Jet -> Draw("Esame"); ak5FastJet__D_Jet_Jet->SetLineColor(9);
  ak5FastJet__D_Jet_Jet->SetMarkerStyle(21); ak5FastJet__D_Jet_Jet->SetMarkerColor(9);
  legend -> Draw();

  ak5PFJet__D_Jet_Jet -> SaveAs("/home/saksevul/T/Parallelism/ak5Jets/D_Jet-Jet FastJet y PFJets.png"); ak5PFJet__D_Jet_Jet -> Close();

}

//###################################################################################################################################################################################

void Limits() {
  // Le damos algo de personalización al las gráficas.
  gROOT->ForceStyle();
  gStyle->SetPadBorderMode(0);    gStyle->SetPadBorderSize(0);
  gStyle->SetPadTopMargin(0.08);  gStyle->SetPadBottomMargin(0.12);
  gStyle->SetPadLeftMargin(0.10); gStyle->SetPadRightMargin(0.10);
  gStyle->SetOptStat(0);          gStyle->SetOptTitle(1);

  //Abrimos el archivo que nos interesa y el árbol que queremos leer.
  TFile *FJFile = new TFile("/home/saksevul/T/PYTHIA/FastJet/ak5FJ.root");
  TFile *JetFile = new TFile("/home/saksevul/T/OpenData/Jet_20000/ak5PF_Limits.root");
  TFile *BTagFile = new TFile("/home/saksevul/T/OpenData/BTag_20000/ak5PF_Limits.root");
  TFile *MinBiasFile = new TFile("/home/saksevul/T/OpenData/MinBias_20000/ak5PF_Limits.root");
  TFile *MultiJetFile = new TFile("/home/saksevul/T/OpenData/MultiJet_20000/ak5PF_Limits.root");


  TH1F *MuonsFJ_pt_ =(TH1F*)FJFile->Get("Muons_pt_"); MuonsFJ_pt_->Scale(1.0/MuonsFJ_pt_->Integral());
  TH1F *MuonsJet_pt_ =(TH1F*)JetFile->Get("Muons_pt_"); MuonsJet_pt_->Scale(1.0/MuonsJet_pt_->Integral());
  TH1F *MuonsBTag_pt_ =(TH1F*)BTagFile->Get("Muons_pt_"); MuonsBTag_pt_->Scale(1.0/MuonsBTag_pt_->Integral());
  TH1F *MuonsMinBias_pt_ =(TH1F*)MinBiasFile->Get("Muons_pt_"); MuonsMinBias_pt_->Scale(1.0/MuonsMinBias_pt_->Integral());
  TH1F *MuonsMultiJet_pt_ =(TH1F*)MultiJetFile->Get("Muons_pt_"); MuonsMultiJet_pt_->Scale(1.0/MuonsMultiJet_pt_->Integral());

  TH1F *PhotonsFJ_pt_ =(TH1F*)FJFile->Get("Photons_pt_"); PhotonsFJ_pt_->Scale(1.0/PhotonsFJ_pt_->Integral());
  TH1F *PhotonsJet_pt_ =(TH1F*)JetFile->Get("Photons_pt_"); PhotonsJet_pt_->Scale(1.0/PhotonsJet_pt_->Integral());
  TH1F *PhotonsBTag_pt_ =(TH1F*)BTagFile->Get("Photons_pt_"); PhotonsBTag_pt_->Scale(1.0/PhotonsBTag_pt_->Integral());
  TH1F *PhotonsMinBias_pt_ =(TH1F*)MinBiasFile->Get("Photons_pt_"); PhotonsMinBias_pt_->Scale(1.0/PhotonsMinBias_pt_->Integral());
  TH1F *PhotonsMultiJet_pt_ =(TH1F*)MultiJetFile->Get("Photons_pt_"); PhotonsMultiJet_pt_->Scale(1.0/PhotonsMultiJet_pt_->Integral());

  TH1F *ElectronsFJ_pt_ =(TH1F*)FJFile->Get("Electrons_pt_"); ElectronsFJ_pt_->Scale(1.0/ElectronsFJ_pt_->Integral());
  TH1F *ElectronsJet_pt_ =(TH1F*)JetFile->Get("Electrons_pt_"); ElectronsJet_pt_->Scale(1.0/ElectronsJet_pt_->Integral());
  TH1F *ElectronsBTag_pt_ =(TH1F*)BTagFile->Get("Electrons_pt_"); ElectronsBTag_pt_->Scale(1.0/ElectronsBTag_pt_->Integral());
  TH1F *ElectronsMinBias_pt_ =(TH1F*)MinBiasFile->Get("Electrons_pt_"); ElectronsMinBias_pt_->Scale(1.0/ElectronsMinBias_pt_->Integral());
  TH1F *ElectronsMultiJet_pt_ =(TH1F*)MultiJetFile->Get("Electrons_pt_"); ElectronsMultiJet_pt_->Scale(1.0/ElectronsMultiJet_pt_->Integral());

  TH1F *ak5FJ_pt_ =(TH1F*)FJFile->Get("Jets_pt_"); ak5FJ_pt_->Scale(1.0/ak5FJ_pt_->Integral());
  TH1F *ak5PFJet_pt_ =(TH1F*)JetFile->Get("Jets_pt_"); ak5PFJet_pt_->Scale(1.0/ak5PFJet_pt_->Integral());
  TH1F *ak5PFBTag_pt_ =(TH1F*)BTagFile->Get("Jets_pt_"); ak5PFBTag_pt_->Scale(1.0/ak5PFBTag_pt_->Integral());
  TH1F *ak5PFMinBias_pt_ =(TH1F*)MinBiasFile->Get("Jets_pt_"); ak5PFMinBias_pt_->Scale(1.0/ak5PFMinBias_pt_->Integral());
  TH1F *ak5PFMultiJet_pt_ =(TH1F*)MultiJetFile->Get("Jets_pt_"); ak5PFMultiJet_pt_->Scale(1.0/ak5PFMultiJet_pt_->Integral());


  TH1F *MuonsFJ_eta_ =(TH1F*)FJFile->Get("Muons_eta_"); MuonsFJ_eta_->Scale(1.0/MuonsFJ_eta_->Integral());
  TH1F *MuonsJet_eta_ =(TH1F*)JetFile->Get("Muons_eta_"); MuonsJet_eta_->Scale(1.0/MuonsJet_eta_->Integral());
  TH1F *MuonsBTag_eta_ =(TH1F*)BTagFile->Get("Muons_eta_"); MuonsBTag_eta_->Scale(1.0/MuonsBTag_eta_->Integral());
  TH1F *MuonsMinBias_eta_ =(TH1F*)MinBiasFile->Get("Muons_eta_"); MuonsMinBias_eta_->Scale(1.0/MuonsMinBias_eta_->Integral());
  TH1F *MuonsMultiJet_eta_ =(TH1F*)MultiJetFile->Get("Muons_eta_"); MuonsMultiJet_eta_->Scale(1.0/MuonsMultiJet_eta_->Integral());

  TH1F *PhotonsFJ_eta_ =(TH1F*)FJFile->Get("Photons_eta_"); PhotonsFJ_eta_->Scale(1.0/PhotonsFJ_eta_->Integral());
  TH1F *PhotonsJet_eta_ =(TH1F*)JetFile->Get("Photons_eta_"); PhotonsJet_eta_->Scale(1.0/PhotonsJet_eta_->Integral());
  TH1F *PhotonsBTag_eta_ =(TH1F*)BTagFile->Get("Photons_eta_"); PhotonsBTag_eta_->Scale(1.0/PhotonsBTag_eta_->Integral());
  TH1F *PhotonsMinBias_eta_ =(TH1F*)MinBiasFile->Get("Photons_eta_"); PhotonsMinBias_eta_->Scale(1.0/PhotonsMinBias_eta_->Integral());
  TH1F *PhotonsMultiJet_eta_ =(TH1F*)MultiJetFile->Get("Photons_eta_"); PhotonsMultiJet_eta_->Scale(1.0/PhotonsMultiJet_eta_->Integral());

  TH1F *ElectronsFJ_eta_ =(TH1F*)FJFile->Get("Electrons_eta_"); ElectronsFJ_eta_->Scale(1.0/ElectronsFJ_eta_->Integral());
  TH1F *ElectronsJet_eta_ =(TH1F*)JetFile->Get("Electrons_eta_"); ElectronsJet_eta_->Scale(1.0/ElectronsJet_eta_->Integral());
  TH1F *ElectronsBTag_eta_ =(TH1F*)BTagFile->Get("Electrons_eta_"); ElectronsBTag_eta_->Scale(1.0/ElectronsBTag_eta_->Integral());
  TH1F *ElectronsMinBias_eta_ =(TH1F*)MinBiasFile->Get("Electrons_eta_"); ElectronsMinBias_eta_->Scale(1.0/ElectronsMinBias_eta_->Integral());
  TH1F *ElectronsMultiJet_eta_ =(TH1F*)MultiJetFile->Get("Electrons_eta_"); ElectronsMultiJet_eta_->Scale(1.0/ElectronsMultiJet_eta_->Integral());

  TH1F *ak5FJ_eta_ =(TH1F*)FJFile->Get("Jets_eta_"); ak5FJ_eta_->Scale(1.0/ak5FJ_eta_->Integral());
  TH1F *ak5PFJet_eta_ =(TH1F*)JetFile->Get("Jets_eta_"); ak5PFJet_eta_->Scale(1.0/ak5PFJet_eta_->Integral());
  TH1F *ak5PFBTag_eta_ =(TH1F*)BTagFile->Get("Jets_eta_"); ak5PFBTag_eta_->Scale(1.0/ak5PFBTag_eta_->Integral());
  TH1F *ak5PFMinBias_eta_ =(TH1F*)MinBiasFile->Get("Jets_eta_"); ak5PFMinBias_eta_->Scale(1.0/ak5PFMinBias_eta_->Integral());
  TH1F *ak5PFMultiJet_eta_ =(TH1F*)MultiJetFile->Get("Jets_eta_"); ak5PFMultiJet_eta_->Scale(1.0/ak5PFMultiJet_eta_->Integral());


  // TH1F *FJ_MuonEnergy =(TH1F*)FJFile->Get("Jets_MuonEnergy"); FJ_MuonEnergy->Scale(1.0/FJ_MuonEnergy->Integral());
  TH1F *Jet_MuonEnergy =(TH1F*)JetFile->Get("Jets_1MuonEnergy"); Jet_MuonEnergy->Scale(1.0/Jet_MuonEnergy->Integral());
  TH1F *BTag_MuonEnergy =(TH1F*)BTagFile->Get("Jets_1MuonEnergy"); BTag_MuonEnergy->Scale(1.0/BTag_MuonEnergy->Integral());
  TH1F *MinBias_MuonEnergy =(TH1F*)MinBiasFile->Get("Jets_1MuonEnergy"); MinBias_MuonEnergy->Scale(1.0/MinBias_MuonEnergy->Integral());
  TH1F *MultiJet_MuonEnergy =(TH1F*)MultiJetFile->Get("Jets_1MuonEnergy"); MultiJet_MuonEnergy->Scale(1.0/MultiJet_MuonEnergy->Integral());

  // TH1F *FJ_PhotonEnergy =(TH1F*)FJFile->Get("Jets_PhotonEnergy"); FJ_PhotonEnergy->Scale(1.0/FJ_PhotonEnergy->Integral());
  TH1F *Jet_PhotonEnergy =(TH1F*)JetFile->Get("Jets_1PhotonEnergy"); Jet_PhotonEnergy->Scale(1.0/Jet_PhotonEnergy->Integral());
  TH1F *BTag_PhotonEnergy =(TH1F*)BTagFile->Get("Jets_1PhotonEnergy"); BTag_PhotonEnergy->Scale(1.0/BTag_PhotonEnergy->Integral());
  TH1F *MinBias_PhotonEnergy =(TH1F*)MinBiasFile->Get("Jets_1PhotonEnergy"); MinBias_PhotonEnergy->Scale(1.0/MinBias_PhotonEnergy->Integral());
  TH1F *MultiJet_PhotonEnergy =(TH1F*)MultiJetFile->Get("Jets_1PhotonEnergy"); MultiJet_PhotonEnergy->Scale(1.0/MultiJet_PhotonEnergy->Integral());

  // TH1F *FJ_ElectronEnergy =(TH1F*)FJFile->Get("Jets_ElectronEnergy"); FJ_ElectronEnergy->Scale(1.0/FJ_ElectronEnergy->Integral());
  TH1F *Jet_ElectronEnergy =(TH1F*)JetFile->Get("Jets_1ElectronEnergy"); Jet_ElectronEnergy->Scale(1.0/Jet_ElectronEnergy->Integral());
  TH1F *BTag_ElectronEnergy =(TH1F*)BTagFile->Get("Jets_1ElectronEnergy"); BTag_ElectronEnergy->Scale(1.0/BTag_ElectronEnergy->Integral());
  TH1F *MinBias_ElectronEnergy =(TH1F*)MinBiasFile->Get("Jets_1ElectronEnergy"); MinBias_ElectronEnergy->Scale(1.0/MinBias_ElectronEnergy->Integral());
  TH1F *MultiJet_ElectronEnergy =(TH1F*)MultiJetFile->Get("Jets_1ElectronEnergy"); MultiJet_ElectronEnergy->Scale(1.0/MultiJet_ElectronEnergy->Integral());

  // TH1F *FJ_NeuHadEnergy =(TH1F*)FJFile->Get("Jets_NeutralHadronEnergy"); FJ_NeuHadEnergy->Scale(1.0/FJ_NeuHadEnergy->Integral());
  TH1F *Jet_NeuHadEnergy =(TH1F*)JetFile->Get("Jets_1NeutralHadronEnergy"); Jet_NeuHadEnergy->Scale(1.0/Jet_NeuHadEnergy->Integral());
  TH1F *BTag_NeuHadEnergy =(TH1F*)BTagFile->Get("Jets_1NeutralHadronEnergy"); BTag_NeuHadEnergy->Scale(1.0/BTag_NeuHadEnergy->Integral());
  TH1F *MinBias_NeuHadEnergy =(TH1F*)MinBiasFile->Get("Jets_1NeutralHadronEnergy"); MinBias_NeuHadEnergy->Scale(1.0/MinBias_NeuHadEnergy->Integral());
  TH1F *MultiJet_NeuHadEnergy =(TH1F*)MultiJetFile->Get("Jets_1NeutralHadronEnergy"); MultiJet_NeuHadEnergy->Scale(1.0/MultiJet_NeuHadEnergy->Integral());

  // TH1F *FJ_CharHadEnergy =(TH1F*)FJFile->Get("Jets_ChargedHadronEnergy"); FJ_CharHadEnergy->Scale(1.0/FJ_CharHadEnergy->Integral());
  TH1F *Jet_CharHadEnergy =(TH1F*)JetFile->Get("Jets_1ChargedHadronEnergy"); Jet_CharHadEnergy->Scale(1.0/Jet_CharHadEnergy->Integral());
  TH1F *BTag_CharHadEnergy =(TH1F*)BTagFile->Get("Jets_1ChargedHadronEnergy"); BTag_CharHadEnergy->Scale(1.0/BTag_CharHadEnergy->Integral());
  TH1F *MinBias_CharHadEnergy =(TH1F*)MinBiasFile->Get("Jets_1ChargedHadronEnergy"); MinBias_CharHadEnergy->Scale(1.0/MinBias_CharHadEnergy->Integral());
  TH1F *MultiJet_CharHadEnergy =(TH1F*)MultiJetFile->Get("Jets_1ChargedHadronEnergy"); MultiJet_CharHadEnergy->Scale(1.0/MultiJet_CharHadEnergy->Integral());



  auto   legend = new TLegend(0.63,0.18,0.90,0.42);    legend->SetTextSize(0.04); legend->SetFillStyle(0); legend->SetBorderSize(0);
    // legend->AddEntry(MuonsFJ_pt_, "MC Simulaci#acute{o}n", "l");
    legend->AddEntry(MuonsJet_pt_, "Open-Data PF Jet", "l");
    legend->AddEntry(MuonsBTag_pt_, "Open-Data PF BTag", "l");
    legend->AddEntry(MuonsMinBias_pt_, "Open-Data PF MinBias", "l");
    legend->AddEntry(MuonsMultiJet_pt_, "Open-Data PF MultiJet", "l");



  TCanvas* Limite_pT_Muones = new TCanvas("Limite_pT_Muones","Limite de pT para Muones",10,10,1920,1080);
  Limite_pT_Muones->SetFillColor(0);  Limite_pT_Muones->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  MuonsFJ_pt_->SetTitle("Espectro de p_{T} para Muones; p_{T} [GeV]; U. A.");
  MuonsFJ_pt_->GetXaxis()->SetLabelSize(0.05); MuonsFJ_pt_->GetYaxis()->SetLabelSize(0.05);
  MuonsFJ_pt_->GetXaxis()->SetTitleSize(0.05); MuonsFJ_pt_->GetYaxis()->SetTitleSize(0.05);
  MuonsFJ_pt_->GetXaxis()->SetTitleOffset(1.0);MuonsFJ_pt_->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  MuonsFJ_pt_ -> Draw("HIST"); MuonsFJ_pt_->SetLineColor(1); MuonsFJ_pt_->SetLineWidth(4);
  MuonsFJ_pt_->SetMarkerStyle(20); MuonsFJ_pt_->SetMarkerColor(1); MuonsFJ_pt_->SetMarkerSize(2);
  MuonsJet_pt_ -> Draw("HISTsame"); MuonsJet_pt_->SetLineColor(2); MuonsJet_pt_->SetLineWidth(4);
  MuonsJet_pt_->SetMarkerStyle(20); MuonsJet_pt_->SetMarkerColor(2); MuonsJet_pt_->SetMarkerSize(2);
  MuonsBTag_pt_ -> Draw("HISTsame"); MuonsBTag_pt_->SetLineColor(4); MuonsBTag_pt_->SetLineWidth(4);
  MuonsBTag_pt_->SetMarkerStyle(23); MuonsBTag_pt_->SetMarkerColor(4); MuonsBTag_pt_->SetMarkerSize(2);
  MuonsMinBias_pt_ -> Draw("HISTsame"); MuonsMinBias_pt_->SetLineColor(41); MuonsMinBias_pt_->SetLineWidth(4);
  MuonsMinBias_pt_->SetMarkerStyle(23); MuonsMinBias_pt_->SetMarkerColor(41); MuonsMinBias_pt_->SetMarkerSize(2);
  MuonsMultiJet_pt_ -> Draw("HISTsame"); MuonsMultiJet_pt_->SetLineColor(32); MuonsMultiJet_pt_->SetLineWidth(4);
  MuonsMultiJet_pt_->SetMarkerStyle(23); MuonsMultiJet_pt_->SetMarkerColor(32); MuonsMultiJet_pt_->SetMarkerSize(2);
  legend->Draw(); Limite_pT_Muones->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Limite_pT_Muones.png"); Limite_pT_Muones->Close();

  TCanvas* Limite_pT_Fotones = new TCanvas("Limite_pT_Fotones","Limite de pT para Fotones",10,10,1920,1080);
  Limite_pT_Fotones->SetFillColor(0);  Limite_pT_Fotones->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  PhotonsFJ_pt_->SetTitle("Espectro de p_{T} para Fotones; p_{T} [GeV]; U. A.");
  PhotonsFJ_pt_->GetXaxis()->SetLabelSize(0.05); PhotonsFJ_pt_->GetYaxis()->SetLabelSize(0.05);
  PhotonsFJ_pt_->GetXaxis()->SetTitleSize(0.05); PhotonsFJ_pt_->GetYaxis()->SetTitleSize(0.05);
  PhotonsFJ_pt_->GetXaxis()->SetTitleOffset(1.0);PhotonsFJ_pt_->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  PhotonsFJ_pt_ -> Draw("HIST"); PhotonsFJ_pt_->SetLineColor(1); PhotonsFJ_pt_->SetLineWidth(2);
  PhotonsFJ_pt_->SetMarkerStyle(20); PhotonsFJ_pt_->SetMarkerColor(1); PhotonsFJ_pt_->SetMarkerSize(2);
  PhotonsJet_pt_ -> Draw("HISTsame"); PhotonsJet_pt_->SetLineColor(2); PhotonsJet_pt_->SetLineWidth(2);
  PhotonsJet_pt_->SetMarkerStyle(20); PhotonsJet_pt_->SetMarkerColor(2); PhotonsJet_pt_->SetMarkerSize(2);
  PhotonsBTag_pt_ -> Draw("HISTsame"); PhotonsBTag_pt_->SetLineColor(4); PhotonsBTag_pt_->SetLineWidth(2);
  PhotonsBTag_pt_->SetMarkerStyle(23); PhotonsBTag_pt_->SetMarkerColor(4); PhotonsBTag_pt_->SetMarkerSize(2);
  PhotonsMinBias_pt_ -> Draw("HISTsame"); PhotonsMinBias_pt_->SetLineColor(41); PhotonsMinBias_pt_->SetLineWidth(2);
  PhotonsMinBias_pt_->SetMarkerStyle(23); PhotonsMinBias_pt_->SetMarkerColor(41); PhotonsMinBias_pt_->SetMarkerSize(2);
  PhotonsMultiJet_pt_ -> Draw("HISTsame"); PhotonsMultiJet_pt_->SetLineColor(32); PhotonsMultiJet_pt_->SetLineWidth(2);
  PhotonsMultiJet_pt_->SetMarkerStyle(23); PhotonsMultiJet_pt_->SetMarkerColor(32); PhotonsMultiJet_pt_->SetMarkerSize(2);
  legend->Draw(); Limite_pT_Fotones->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Limite_pT_Fotones.png"); Limite_pT_Fotones->Close();

  TCanvas* Limite_pT_Electrones = new TCanvas("Limite_pT_Electrones","Limite de pT para Electrones",10,10,1920,1080);
  Limite_pT_Electrones->SetFillColor(0);  Limite_pT_Electrones->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  ElectronsFJ_pt_->SetTitle("Espectro de p_{T} para Electrones; p_{T} [GeV]; U. A.");
  ElectronsFJ_pt_->GetXaxis()->SetLabelSize(0.05); ElectronsFJ_pt_->GetYaxis()->SetLabelSize(0.05);
  ElectronsFJ_pt_->GetXaxis()->SetTitleSize(0.05); ElectronsFJ_pt_->GetYaxis()->SetTitleSize(0.05);
  ElectronsFJ_pt_->GetXaxis()->SetTitleOffset(1.0);ElectronsFJ_pt_->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  ElectronsFJ_pt_ -> Draw("HIST"); ElectronsFJ_pt_->SetLineColor(1); ElectronsFJ_pt_->SetLineWidth(2);
  ElectronsFJ_pt_->SetMarkerStyle(20); ElectronsFJ_pt_->SetMarkerColor(1); ElectronsFJ_pt_->SetMarkerSize(2);
  ElectronsJet_pt_ -> Draw("HISTsame"); ElectronsJet_pt_->SetLineColor(2); ElectronsJet_pt_->SetLineWidth(2);
  ElectronsJet_pt_->SetMarkerStyle(20); ElectronsJet_pt_->SetMarkerColor(2); ElectronsJet_pt_->SetMarkerSize(2);
  ElectronsBTag_pt_ -> Draw("HISTsame"); ElectronsBTag_pt_->SetLineColor(4); ElectronsBTag_pt_->SetLineWidth(2);
  ElectronsBTag_pt_->SetMarkerStyle(23); ElectronsBTag_pt_->SetMarkerColor(4); ElectronsBTag_pt_->SetMarkerSize(2);
  ElectronsMinBias_pt_ -> Draw("HISTsame"); ElectronsMinBias_pt_->SetLineColor(41); ElectronsMinBias_pt_->SetLineWidth(2);
  ElectronsMinBias_pt_->SetMarkerStyle(23); ElectronsMinBias_pt_->SetMarkerColor(41); ElectronsMinBias_pt_->SetMarkerSize(2);
  ElectronsMultiJet_pt_ -> Draw("HISTsame"); ElectronsMultiJet_pt_->SetLineColor(32); ElectronsMultiJet_pt_->SetLineWidth(2);
  ElectronsMultiJet_pt_->SetMarkerStyle(23); ElectronsMultiJet_pt_->SetMarkerColor(32); ElectronsMultiJet_pt_->SetMarkerSize(2);
  legend->Draw(); Limite_pT_Electrones->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Limite_pT_Electrones.png"); Limite_pT_Electrones->Close();

  TCanvas* Limite_pT_ak5PFJets = new TCanvas("Limite_pT_ak5PFJets","Limite de pT para Jets",10,10,1920,1080);  Limite_pT_ak5PFJets->SetRightMargin(0.01);
  Limite_pT_ak5PFJets->SetFillColor(0);  Limite_pT_ak5PFJets->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  ak5FJ_pt_->SetTitle("Espectro de p_{T} para Jets; p_{T} [GeV]; U. A.");
  ak5FJ_pt_->GetXaxis()->SetLabelSize(0.05); ak5FJ_pt_->GetYaxis()->SetLabelSize(0.05);
  ak5FJ_pt_->GetXaxis()->SetTitleSize(0.05); ak5FJ_pt_->GetYaxis()->SetTitleSize(0.05);
  ak5FJ_pt_->GetXaxis()->SetTitleOffset(1.0);ak5FJ_pt_->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  ak5FJ_pt_ -> Draw("HIST"); ak5FJ_pt_->SetLineColor(1); ak5FJ_pt_->SetLineWidth(2);
  ak5FJ_pt_->SetMarkerStyle(20); ak5FJ_pt_->SetMarkerColor(1); ak5FJ_pt_->SetMarkerSize(2);
  ak5PFJet_pt_ -> Draw("HISTsame"); ak5PFJet_pt_->SetLineColor(2); ak5PFJet_pt_->SetLineWidth(2);
  ak5PFJet_pt_->SetMarkerStyle(20); ak5PFJet_pt_->SetMarkerColor(2); ak5PFJet_pt_->SetMarkerSize(2);
  ak5PFBTag_pt_ -> Draw("HISTsame"); ak5PFBTag_pt_->SetLineColor(4); ak5PFBTag_pt_->SetLineWidth(2);
  ak5PFBTag_pt_->SetMarkerStyle(23); ak5PFBTag_pt_->SetMarkerColor(4); ak5PFBTag_pt_->SetMarkerSize(2);
  ak5PFMinBias_pt_ -> Draw("HISTsame"); ak5PFMinBias_pt_->SetLineColor(41); ak5PFMinBias_pt_->SetLineWidth(2);
  ak5PFMinBias_pt_->SetMarkerStyle(23); ak5PFMinBias_pt_->SetMarkerColor(41); ak5PFMinBias_pt_->SetMarkerSize(2);
  ak5PFMultiJet_pt_ -> Draw("HISTsame"); ak5PFMultiJet_pt_->SetLineColor(32); ak5PFMultiJet_pt_->SetLineWidth(2);
  ak5PFMultiJet_pt_->SetMarkerStyle(23); ak5PFMultiJet_pt_->SetMarkerColor(32); ak5PFMultiJet_pt_->SetMarkerSize(2);
  legend->Draw(); Limite_pT_ak5PFJets->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Limite_pT_ak5PFJets.png"); Limite_pT_ak5PFJets->Close();



  TCanvas* Limite_eta_Muones = new TCanvas("Limite_eta_Muones","Limite de #eta para Muones",10,10,1920,1080);
  Limite_eta_Muones->SetFillColor(0);  Limite_eta_Muones->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  MuonsFJ_eta_->SetTitle("Espectro de #eta para Muones; p_{T} [GeV]; U. A.");
  MuonsFJ_eta_->GetXaxis()->SetLabelSize(0.05); MuonsFJ_eta_->GetYaxis()->SetLabelSize(0.05);
  MuonsFJ_eta_->GetXaxis()->SetTitleSize(0.05); MuonsFJ_eta_->GetYaxis()->SetTitleSize(0.05);
  MuonsFJ_eta_->GetXaxis()->SetTitleOffset(1.0);MuonsFJ_eta_->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  MuonsFJ_eta_ -> Draw("HIST"); MuonsFJ_eta_->SetLineColor(1); MuonsFJ_eta_->SetLineWidth(2);
  MuonsFJ_eta_->SetMarkerStyle(20); MuonsFJ_eta_->SetMarkerColor(1); MuonsFJ_eta_->SetMarkerSize(2);
  MuonsJet_eta_ -> Draw("HISTsame"); MuonsJet_eta_->SetLineColor(2); MuonsJet_eta_->SetLineWidth(2);
  MuonsJet_eta_->SetMarkerStyle(20); MuonsJet_eta_->SetMarkerColor(2); MuonsJet_eta_->SetMarkerSize(2);
  MuonsBTag_eta_ -> Draw("HISTsame"); MuonsBTag_eta_->SetLineColor(4); MuonsBTag_eta_->SetLineWidth(2);
  MuonsBTag_eta_->SetMarkerStyle(23); MuonsBTag_eta_->SetMarkerColor(4); MuonsBTag_eta_->SetMarkerSize(2);
  MuonsMinBias_eta_ -> Draw("HISTsame"); MuonsMinBias_eta_->SetLineColor(41); MuonsMinBias_eta_->SetLineWidth(2);
  MuonsMinBias_eta_->SetMarkerStyle(23); MuonsMinBias_eta_->SetMarkerColor(41); MuonsMinBias_eta_->SetMarkerSize(2);
  MuonsMultiJet_eta_ -> Draw("HISTsame"); MuonsMultiJet_eta_->SetLineColor(32); MuonsMultiJet_eta_->SetLineWidth(2);
  MuonsMultiJet_eta_->SetMarkerStyle(23); MuonsMultiJet_eta_->SetMarkerColor(32); MuonsMultiJet_eta_->SetMarkerSize(2);
  legend->Draw(); Limite_eta_Muones->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Limite_eta_Muones.png"); Limite_eta_Muones->Close();

  TCanvas* Limite_eta_Fotones = new TCanvas("Limite_eta_Fotones","Limite de #eta para Fotones",10,10,1920,1080);
  Limite_eta_Fotones->SetFillColor(0);  Limite_eta_Fotones->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  PhotonsFJ_eta_->SetTitle("Espectro de #eta para Fotones; p_{T} [GeV]; U. A.");
  PhotonsFJ_eta_->GetXaxis()->SetLabelSize(0.05); PhotonsFJ_eta_->GetYaxis()->SetLabelSize(0.05);
  PhotonsFJ_eta_->GetXaxis()->SetTitleSize(0.05); PhotonsFJ_eta_->GetYaxis()->SetTitleSize(0.05);
  PhotonsFJ_eta_->GetXaxis()->SetTitleOffset(1.0);PhotonsFJ_eta_->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  PhotonsFJ_eta_ -> Draw("HIST"); PhotonsFJ_eta_->SetLineColor(1); PhotonsFJ_eta_->SetLineWidth(2);
  PhotonsFJ_eta_->SetMarkerStyle(20); PhotonsFJ_eta_->SetMarkerColor(1); PhotonsFJ_eta_->SetMarkerSize(2);
  PhotonsJet_eta_ -> Draw("HISTsame"); PhotonsJet_eta_->SetLineColor(2); PhotonsJet_eta_->SetLineWidth(2);
  PhotonsJet_eta_->SetMarkerStyle(20); PhotonsJet_eta_->SetMarkerColor(2); PhotonsJet_eta_->SetMarkerSize(2);
  PhotonsBTag_eta_ -> Draw("HISTsame"); PhotonsBTag_eta_->SetLineColor(4); PhotonsBTag_eta_->SetLineWidth(2);
  PhotonsBTag_eta_->SetMarkerStyle(23); PhotonsBTag_eta_->SetMarkerColor(4); PhotonsBTag_eta_->SetMarkerSize(2);
  PhotonsMinBias_eta_ -> Draw("HISTsame"); PhotonsMinBias_eta_->SetLineColor(41); PhotonsMinBias_eta_->SetLineWidth(2);
  PhotonsMinBias_eta_->SetMarkerStyle(23); PhotonsMinBias_eta_->SetMarkerColor(41); PhotonsMinBias_eta_->SetMarkerSize(2);
  PhotonsMultiJet_eta_ -> Draw("HISTsame"); PhotonsMultiJet_eta_->SetLineColor(32); PhotonsMultiJet_eta_->SetLineWidth(2);
  PhotonsMultiJet_eta_->SetMarkerStyle(23); PhotonsMultiJet_eta_->SetMarkerColor(32); PhotonsMultiJet_eta_->SetMarkerSize(2);
  legend->Draw(); Limite_eta_Fotones->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Limite_eta_Fotones.png"); Limite_eta_Fotones->Close();

  TCanvas* Limite_eta_Electrones = new TCanvas("Limite_eta_Electrones","Limite de #eta para Electrones",10,10,1920,1080);
  Limite_eta_Electrones->SetFillColor(0);  Limite_eta_Electrones->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  ElectronsFJ_eta_->SetTitle("Espectro de #eta para Electrones; p_{T} [GeV]; U. A.");
  ElectronsFJ_eta_->GetXaxis()->SetLabelSize(0.05); ElectronsFJ_eta_->GetYaxis()->SetLabelSize(0.05);
  ElectronsFJ_eta_->GetXaxis()->SetTitleSize(0.05); ElectronsFJ_eta_->GetYaxis()->SetTitleSize(0.05);
  ElectronsFJ_eta_->GetXaxis()->SetTitleOffset(1.0);ElectronsFJ_eta_->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  ElectronsFJ_eta_ -> Draw("HIST"); ElectronsFJ_eta_->SetLineColor(1); ElectronsFJ_eta_->SetLineWidth(2);
  ElectronsFJ_eta_->SetMarkerStyle(20); ElectronsFJ_eta_->SetMarkerColor(1); ElectronsFJ_eta_->SetMarkerSize(2);
  ElectronsJet_eta_ -> Draw("HISTsame"); ElectronsJet_eta_->SetLineColor(2); ElectronsJet_eta_->SetLineWidth(2);
  ElectronsJet_eta_->SetMarkerStyle(20); ElectronsJet_eta_->SetMarkerColor(2); ElectronsJet_eta_->SetMarkerSize(2);
  ElectronsBTag_eta_ -> Draw("HISTsame"); ElectronsBTag_eta_->SetLineColor(4); ElectronsBTag_eta_->SetLineWidth(2);
  ElectronsBTag_eta_->SetMarkerStyle(23); ElectronsBTag_eta_->SetMarkerColor(4); ElectronsBTag_eta_->SetMarkerSize(2);
  ElectronsMinBias_eta_ -> Draw("HISTsame"); ElectronsMinBias_eta_->SetLineColor(41); ElectronsMinBias_eta_->SetLineWidth(2);
  ElectronsMinBias_eta_->SetMarkerStyle(23); ElectronsMinBias_eta_->SetMarkerColor(41); ElectronsMinBias_eta_->SetMarkerSize(2);
  ElectronsMultiJet_eta_ -> Draw("HISTsame"); ElectronsMultiJet_eta_->SetLineColor(32); ElectronsMultiJet_eta_->SetLineWidth(2);
  ElectronsMultiJet_eta_->SetMarkerStyle(23); ElectronsMultiJet_eta_->SetMarkerColor(32); ElectronsMultiJet_eta_->SetMarkerSize(2);
  legend->Draw(); Limite_eta_Electrones->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Limite_eta_Electrones.png"); Limite_eta_Electrones->Close();

  TCanvas* Limite_eta_Jets = new TCanvas("Limite_eta_Jets","Limite de #eta para Jets",10,10,1920,1080);
  Limite_eta_Jets->SetFillColor(0);  Limite_eta_Jets->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  ak5FJ_eta_->SetTitle("Espectro de #eta para Jets; p_{T} [GeV]; U. A.");
  ak5FJ_eta_->GetXaxis()->SetLabelSize(0.05); ak5FJ_eta_->GetYaxis()->SetLabelSize(0.05);
  ak5FJ_eta_->GetXaxis()->SetTitleSize(0.05); ak5FJ_eta_->GetYaxis()->SetTitleSize(0.05);
  ak5FJ_eta_->GetXaxis()->SetTitleOffset(1.0);ak5FJ_eta_->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  ak5FJ_eta_ -> Draw("HIST"); ak5FJ_eta_->SetLineColor(1); ak5FJ_eta_->SetLineWidth(2);
  ak5FJ_eta_->SetMarkerStyle(20); ak5FJ_eta_->SetMarkerColor(1); ak5FJ_eta_->SetMarkerSize(2);
  ak5PFJet_eta_ -> Draw("HISTsame"); ak5PFJet_eta_->SetLineColor(2); ak5PFJet_eta_->SetLineWidth(2);
  ak5PFJet_eta_->SetMarkerStyle(20); ak5PFJet_eta_->SetMarkerColor(2); ak5PFJet_eta_->SetMarkerSize(2);
  ak5PFBTag_eta_ -> Draw("HISTsame"); ak5PFBTag_eta_->SetLineColor(4); ak5PFBTag_eta_->SetLineWidth(2);
  ak5PFBTag_eta_->SetMarkerStyle(23); ak5PFBTag_eta_->SetMarkerColor(4); ak5PFBTag_eta_->SetMarkerSize(2);
  ak5PFMinBias_eta_ -> Draw("HISTsame"); ak5PFMinBias_eta_->SetLineColor(41); ak5PFMinBias_eta_->SetLineWidth(2);
  ak5PFMinBias_eta_->SetMarkerStyle(23); ak5PFMinBias_eta_->SetMarkerColor(41); ak5PFMinBias_eta_->SetMarkerSize(2);
  ak5PFMultiJet_eta_ -> Draw("HISTsame"); ak5PFMultiJet_eta_->SetLineColor(32); ak5PFMultiJet_eta_->SetLineWidth(2);
  ak5PFMultiJet_eta_->SetMarkerStyle(23); ak5PFMultiJet_eta_->SetMarkerColor(32); ak5PFMultiJet_eta_->SetMarkerSize(2);
  legend->Draw(); Limite_eta_Jets->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Limite_eta_Jets.png"); Limite_eta_Jets->Close();



  TCanvas* Limite_Energia_Muones = new TCanvas("Limite_Energia_Muones","Limite de Energ#acute{i}a para Muones",10,10,1920,1080);
  Limite_Energia_Muones->SetFillColor(0);  Limite_Energia_Muones->SetFrameBorderMode(0);  gPad->SetLogy(); gPad->SetGrid(1,1);
  // Esto es para modificar las etiquetas del canvas.
  Jet_MuonEnergy->SetTitle("Espectro de Energ#acute{i}a para Muones en ak5PFJets; E [GeV]; U. A.");
  Jet_MuonEnergy->GetXaxis()->SetLabelSize(0.05); Jet_MuonEnergy->GetYaxis()->SetLabelSize(0.05);
  Jet_MuonEnergy->GetXaxis()->SetTitleSize(0.05); Jet_MuonEnergy->GetYaxis()->SetTitleSize(0.05);
  Jet_MuonEnergy->GetXaxis()->SetTitleOffset(1.0);Jet_MuonEnergy->GetYaxis()->SetTitleOffset(1.0);
  Jet_MuonEnergy->SetAxisRange(0.0, 8.0, "X");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Jet_MuonEnergy -> Draw("HIST"); Jet_MuonEnergy->SetLineColor(2); Jet_MuonEnergy->SetLineWidth(2);
  Jet_MuonEnergy->SetMarkerStyle(20); Jet_MuonEnergy->SetMarkerColor(2); Jet_MuonEnergy->SetMarkerSize(2);
  BTag_MuonEnergy -> Draw("HISTsame"); BTag_MuonEnergy->SetLineColor(4); BTag_MuonEnergy->SetLineWidth(2);
  BTag_MuonEnergy->SetMarkerStyle(23); BTag_MuonEnergy->SetMarkerColor(4); BTag_MuonEnergy->SetMarkerSize(2);
  MinBias_MuonEnergy -> Draw("HISTsame"); MinBias_MuonEnergy->SetLineColor(41); MinBias_MuonEnergy->SetLineWidth(2);
  MinBias_MuonEnergy->SetMarkerStyle(23); MinBias_MuonEnergy->SetMarkerColor(41); MinBias_MuonEnergy->SetMarkerSize(2);
  MultiJet_MuonEnergy -> Draw("HISTsame"); MultiJet_MuonEnergy->SetLineColor(32); MultiJet_MuonEnergy->SetLineWidth(2);
  MultiJet_MuonEnergy->SetMarkerStyle(23); MultiJet_MuonEnergy->SetMarkerColor(32); MultiJet_MuonEnergy->SetMarkerSize(2);
  legend->Draw(); Limite_Energia_Muones->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Limite_Energia_Muones.png"); Limite_Energia_Muones->Close();

  TCanvas* Limite_Energia_Fotones = new TCanvas("Limite_Energia_Fotones","Limite de Energ#acute{i}a para Fotones",10,10,1920,1080);
  Limite_Energia_Fotones->SetFillColor(0);  Limite_Energia_Fotones->SetFrameBorderMode(0);  gPad->SetLogy(); gPad->SetGrid(1,1);
  // Esto es para modificar las etiquetas del canvas.
  Jet_PhotonEnergy->SetTitle("Espectro de Energ#acute{i}a para Fotones en ak5PFJets; E [GeV]; U. A.");
  Jet_PhotonEnergy->GetXaxis()->SetLabelSize(0.05); Jet_PhotonEnergy->GetYaxis()->SetLabelSize(0.05);
  Jet_PhotonEnergy->GetXaxis()->SetTitleSize(0.05); Jet_PhotonEnergy->GetYaxis()->SetTitleSize(0.05);
  Jet_PhotonEnergy->GetXaxis()->SetTitleOffset(1.0);Jet_PhotonEnergy->GetYaxis()->SetTitleOffset(1.0);
  Jet_PhotonEnergy->SetAxisRange(0.0, 2.0, "X");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Jet_PhotonEnergy -> Draw("HIST"); Jet_PhotonEnergy->SetLineColor(2); Jet_PhotonEnergy->SetLineWidth(2);
  Jet_PhotonEnergy->SetMarkerStyle(20); Jet_PhotonEnergy->SetMarkerColor(2); Jet_PhotonEnergy->SetMarkerSize(2);
  BTag_PhotonEnergy -> Draw("HISTsame"); BTag_PhotonEnergy->SetLineColor(4); BTag_PhotonEnergy->SetLineWidth(2);
  BTag_PhotonEnergy->SetMarkerStyle(23); BTag_PhotonEnergy->SetMarkerColor(4); BTag_PhotonEnergy->SetMarkerSize(2);
  MinBias_PhotonEnergy -> Draw("HISTsame"); MinBias_PhotonEnergy->SetLineColor(41); MinBias_PhotonEnergy->SetLineWidth(2);
  MinBias_PhotonEnergy->SetMarkerStyle(23); MinBias_PhotonEnergy->SetMarkerColor(41); MinBias_PhotonEnergy->SetMarkerSize(2);
  MultiJet_PhotonEnergy -> Draw("HISTsame"); MultiJet_PhotonEnergy->SetLineColor(32); MultiJet_PhotonEnergy->SetLineWidth(2);
  MultiJet_PhotonEnergy->SetMarkerStyle(23); MultiJet_PhotonEnergy->SetMarkerColor(32); MultiJet_PhotonEnergy->SetMarkerSize(2);
  legend->Draw(); Limite_Energia_Fotones->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Limite_Energia_Fotones.png"); Limite_Energia_Fotones->Close();

  TCanvas* Limite_Energia_Electrones = new TCanvas("Limite_Energia_Electrones","Limite Energ#acute{i}a para Electrones",10,10,1920,1080);
  Limite_Energia_Electrones->SetFillColor(0);  Limite_Energia_Electrones->SetFrameBorderMode(0);  gPad->SetLogy(); gPad->SetGrid(1,1);  Limite_Energia_Electrones->SetRightMargin(0.01);
  // Esto es para modificar las etiquetas del canvas.
  Jet_ElectronEnergy->SetTitle("Espectro de Energ#acute{i}a para Electrones en ak5PFJets; E [GeV]; U. A.");
  Jet_ElectronEnergy->GetXaxis()->SetLabelSize(0.05); Jet_ElectronEnergy->GetYaxis()->SetLabelSize(0.05);
  Jet_ElectronEnergy->GetXaxis()->SetTitleSize(0.05); Jet_ElectronEnergy->GetYaxis()->SetTitleSize(0.05);
  Jet_ElectronEnergy->GetXaxis()->SetTitleOffset(1.0);Jet_ElectronEnergy->GetYaxis()->SetTitleOffset(1.0);
  Jet_ElectronEnergy->SetAxisRange(0.0, 5.0, "X");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Jet_ElectronEnergy -> Draw("HIST"); Jet_ElectronEnergy->SetLineColor(2); Jet_ElectronEnergy->SetLineWidth(4);
  Jet_ElectronEnergy->SetMarkerStyle(20); Jet_ElectronEnergy->SetMarkerColor(2); Jet_ElectronEnergy->SetMarkerSize(2);
  BTag_ElectronEnergy -> Draw("HISTsame"); BTag_ElectronEnergy->SetLineColor(4); BTag_ElectronEnergy->SetLineWidth(4);
  BTag_ElectronEnergy->SetMarkerStyle(23); BTag_ElectronEnergy->SetMarkerColor(4); BTag_ElectronEnergy->SetMarkerSize(2);
  MinBias_ElectronEnergy -> Draw("HISTsame"); MinBias_ElectronEnergy->SetLineColor(41); MinBias_ElectronEnergy->SetLineWidth(4);
  MinBias_ElectronEnergy->SetMarkerStyle(23); MinBias_ElectronEnergy->SetMarkerColor(41); MinBias_ElectronEnergy->SetMarkerSize(2);
  MultiJet_ElectronEnergy -> Draw("HISTsame"); MultiJet_ElectronEnergy->SetLineColor(32); MultiJet_ElectronEnergy->SetLineWidth(4);
  MultiJet_ElectronEnergy->SetMarkerStyle(23); MultiJet_ElectronEnergy->SetMarkerColor(32); MultiJet_ElectronEnergy->SetMarkerSize(2);
  legend->Draw(); Limite_Energia_Electrones->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Limite_Energia_Electrones.png");
  legend->Draw(); Limite_Energia_Electrones->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Limite_Energia_Electrones.pdf"); Limite_Energia_Electrones->Close();

  TCanvas* Limite_Energia_HadNeutros = new TCanvas("Limite_Energia_HadNeutros","Limite Energ#acute{i}a para HadNeutros",10,10,1920,1080);
  Limite_Energia_HadNeutros->SetFillColor(0);  Limite_Energia_HadNeutros->SetFrameBorderMode(0);  gPad->SetLogy(); gPad->SetGrid(1,1);
  // Esto es para modificar las etiquetas del canvas.
  Jet_NeuHadEnergy->SetTitle("Espectro de Energ#acute{i}a para HadNeutros en ak5PFJets; E [GeV]; U. A.");
  Jet_NeuHadEnergy->GetXaxis()->SetLabelSize(0.05); Jet_NeuHadEnergy->GetYaxis()->SetLabelSize(0.05);
  Jet_NeuHadEnergy->GetXaxis()->SetTitleSize(0.05); Jet_NeuHadEnergy->GetYaxis()->SetTitleSize(0.05);
  Jet_NeuHadEnergy->GetXaxis()->SetTitleOffset(1.0);Jet_NeuHadEnergy->GetYaxis()->SetTitleOffset(1.0);
  Jet_NeuHadEnergy->SetAxisRange(0.0, 5.0, "X");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Jet_NeuHadEnergy -> Draw("HIST"); Jet_NeuHadEnergy->SetLineColor(2); Jet_NeuHadEnergy->SetLineWidth(2);
  Jet_NeuHadEnergy->SetMarkerStyle(20); Jet_NeuHadEnergy->SetMarkerColor(2); Jet_NeuHadEnergy->SetMarkerSize(2);
  BTag_NeuHadEnergy -> Draw("HISTsame"); BTag_NeuHadEnergy->SetLineColor(4); BTag_NeuHadEnergy->SetLineWidth(2);
  BTag_NeuHadEnergy->SetMarkerStyle(23); BTag_NeuHadEnergy->SetMarkerColor(4); BTag_NeuHadEnergy->SetMarkerSize(2);
  MinBias_NeuHadEnergy -> Draw("HISTsame"); MinBias_NeuHadEnergy->SetLineColor(41); MinBias_NeuHadEnergy->SetLineWidth(2);
  MinBias_NeuHadEnergy->SetMarkerStyle(23); MinBias_NeuHadEnergy->SetMarkerColor(41); MinBias_NeuHadEnergy->SetMarkerSize(2);
  MultiJet_NeuHadEnergy -> Draw("HISTsame"); MultiJet_NeuHadEnergy->SetLineColor(32); MultiJet_NeuHadEnergy->SetLineWidth(2);
  MultiJet_NeuHadEnergy->SetMarkerStyle(23); MultiJet_NeuHadEnergy->SetMarkerColor(32); MultiJet_NeuHadEnergy->SetMarkerSize(2);
  legend->Draw(); Limite_Energia_HadNeutros->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Limite_Energia_HadNeutros.png"); Limite_Energia_HadNeutros->Close();

  TCanvas* Limite_Energia_HadCargados = new TCanvas("Limite_Energia_HadCargados","Limite Energ#acute{i}a para HadCargados",10,10,1920,1080);
  Limite_Energia_HadCargados->SetFillColor(0);  Limite_Energia_HadCargados->SetFrameBorderMode(0);  gPad->SetLogy(); gPad->SetGrid(1,1);
  // Esto es para modificar las etiquetas del canvas.
  Jet_CharHadEnergy->SetTitle("Espectro de Energ#acute{i}a para HadCargados en ak5PFJets; E [GeV]; U. A.");
  Jet_CharHadEnergy->GetXaxis()->SetLabelSize(0.05); Jet_CharHadEnergy->GetYaxis()->SetLabelSize(0.05);
  Jet_CharHadEnergy->GetXaxis()->SetTitleSize(0.05); Jet_CharHadEnergy->GetYaxis()->SetTitleSize(0.05);
  Jet_CharHadEnergy->GetXaxis()->SetTitleOffset(1.0);Jet_CharHadEnergy->GetYaxis()->SetTitleOffset(1.0);
  Jet_CharHadEnergy->SetAxisRange(0.0, 5.0, "X");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Jet_CharHadEnergy -> Draw("HIST"); Jet_CharHadEnergy->SetLineColor(2); Jet_CharHadEnergy->SetLineWidth(2);
  Jet_CharHadEnergy->SetMarkerStyle(20); Jet_CharHadEnergy->SetMarkerColor(2); Jet_CharHadEnergy->SetMarkerSize(2);
  BTag_CharHadEnergy -> Draw("HISTsame"); BTag_CharHadEnergy->SetLineColor(4); BTag_CharHadEnergy->SetLineWidth(2);
  BTag_CharHadEnergy->SetMarkerStyle(23); BTag_CharHadEnergy->SetMarkerColor(4); BTag_CharHadEnergy->SetMarkerSize(2);
  MinBias_CharHadEnergy -> Draw("HISTsame"); MinBias_CharHadEnergy->SetLineColor(41); MinBias_CharHadEnergy->SetLineWidth(2);
  MinBias_CharHadEnergy->SetMarkerStyle(23); MinBias_CharHadEnergy->SetMarkerColor(41); MinBias_CharHadEnergy->SetMarkerSize(2);
  MultiJet_CharHadEnergy -> Draw("HISTsame"); MultiJet_CharHadEnergy->SetLineColor(32); MultiJet_CharHadEnergy->SetLineWidth(2);
  MultiJet_CharHadEnergy->SetMarkerStyle(23); MultiJet_CharHadEnergy->SetMarkerColor(32); MultiJet_CharHadEnergy->SetMarkerSize(2);
  legend->Draw(); Limite_Energia_HadCargados->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Limite_Energia_HadCargados.png"); Limite_Energia_HadCargados->Close();
/*
  TCanvas* Limite_Energia_Jets = new TCanvas("Limite_Energia_Jets","Limite de #eta para Jets",10,10,1920,1080);
  Limite_Energia_Jets->SetFillColor(0);  Limite_Energia_Jets->SetFrameBorderMode(0);  gPad->SetLogy(); gPad->SetGrid(1,1);
  // Esto es para modificar las etiquetas del canvas.
  Jet_JetEnergy->SetTitle("Espectro de Energ#acute{i}a para Jets; E [GeV]; U. A.");
  Jet_JetEnergy->GetXaxis()->SetLabelSize(0.05); Jet_JetEnergy->GetYaxis()->SetLabelSize(0.05);
  Jet_JetEnergy->GetXaxis()->SetTitleSize(0.05); Jet_JetEnergy->GetYaxis()->SetTitleSize(0.05);
  Jet_JetEnergy->GetXaxis()->SetTitleOffset(1.0);Jet_JetEnergy->GetYaxis()->SetTitleOffset(1.0);
  Jet_JetEnergy->SetAxisRange(0.01, 5.0, "X");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Jet_JetEnergy -> Draw("HIST"); Jet_JetEnergy->SetLineColor(2); Jet_JetEnergy->SetLineWidth(2);
  Jet_JetEnergy->SetMarkerStyle(20); Jet_JetEnergy->SetMarkerColor(2); Jet_JetEnergy->SetMarkerSize(2);
  BTag_JetEnergy -> Draw("HISTsame"); BTag_JetEnergy->SetLineColor(4); BTag_JetEnergy->SetLineWidth(2);
  BTag_JetEnergy->SetMarkerStyle(23); BTag_JetEnergy->SetMarkerColor(4); BTag_JetEnergy->SetMarkerSize(2);
  MinBias_JetEnergy -> Draw("HISTsame"); MinBias_JetEnergy->SetLineColor(41); MinBias_JetEnergy->SetLineWidth(2);
  MinBias_JetEnergy->SetMarkerStyle(23); MinBias_JetEnergy->SetMarkerColor(41); MinBias_JetEnergy->SetMarkerSize(2);
  MultiJet_JetEnergy -> Draw("HISTsame"); MultiJet_JetEnergy->SetLineColor(32); MultiJet_JetEnergy->SetLineWidth(2);
  MultiJet_JetEnergy->SetMarkerStyle(23); MultiJet_JetEnergy->SetMarkerColor(32); MultiJet_JetEnergy->SetMarkerSize(2);
  legend->Draw(); Limite_Energia_Jets->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Limite_Energia_Jets.png"); Limite_Energia_Jets->Close();
*/


}

//###################################################################################################################################################################################

void Multiplicidad() {
  //Abrimos el archivo que nos interesa y el árbol que queremos leer.
  TFile *FJFile = new TFile("/home/saksevul/T/PYTHIA/FastJet/ak5FJ.root");
  TFile *JetFile = new TFile("/home/saksevul/T/OpenData/Jet_20000/ak5PF.root");
  TFile *BTagFile = new TFile("/home/saksevul/T/OpenData/BTag_20000/ak5PF.root");
  TFile *MultiJetFile = new TFile("/home/saksevul/T/OpenData/MultiJet_20000/ak5PF.root");

  TH1F *ak5FastJet__Multiplicidad, *ak5PFJet__Multiplicidad, *ak5PFBTag__Multiplicidad, *ak5PFMultiJet__Multiplicidad;

  ak5FastJet__Multiplicidad =(TH1F*)FJFile->Get("ak5FastJet__Multiplicidad"); ak5FastJet__Multiplicidad->Scale(1.0/ak5FastJet__Multiplicidad->Integral());
  ak5PFJet__Multiplicidad =(TH1F*)JetFile->Get("ak5PFJet__Multiplicidad"); ak5PFJet__Multiplicidad->Scale(1.0/ak5PFJet__Multiplicidad->Integral());
  ak5PFBTag__Multiplicidad =(TH1F*)BTagFile->Get("ak5PFJet__Multiplicidad"); ak5PFBTag__Multiplicidad->Scale(1.0/ak5PFBTag__Multiplicidad->Integral());
  ak5PFMultiJet__Multiplicidad =(TH1F*)MultiJetFile->Get("ak5PFJet__Multiplicidad"); ak5PFMultiJet__Multiplicidad->Scale(1.0/ak5PFMultiJet__Multiplicidad->Integral());


  auto   legend = new TLegend(0.61,0.74,0.90,0.92);    legend->SetTextSize(0.04);
    legend->AddEntry(ak5FastJet__Multiplicidad, "MC FastJet", "lp");
    legend->AddEntry(ak5PFJet__Multiplicidad, "Open-Data PF Jet", "lp");
    legend->AddEntry(ak5PFBTag__Multiplicidad, "Open-Data PF BTag", "lp");
    legend->AddEntry(ak5PFMultiJet__Multiplicidad, "Open-Data PF MultiJet", "lp");


  //Creamos un liezo en el cual dibujarémos los histogramas sin modificar.
  TCanvas* Espectro_Multiplicidad__Jets = new TCanvas("Multiplicidad de Jets","Multiplicidad de FastJet y PFJets por Evento",10,10,1920,1080);
  Espectro_Multiplicidad__Jets->SetFillColor(0);  Espectro_Multiplicidad__Jets->SetFrameBorderMode(0);  gPad->SetLogy();

    // Esto es para modificar las etiquetas del canvas.
    ak5FastJet__Multiplicidad->SetTitle("Multiplicidad de Jets por Evento; Numero de Jets; U. A.");
    ak5FastJet__Multiplicidad->GetXaxis()->SetLabelSize(0.05); ak5FastJet__Multiplicidad->GetYaxis()->SetLabelSize(0.05);
    ak5FastJet__Multiplicidad->GetXaxis()->SetTitleSize(0.05); ak5FastJet__Multiplicidad->GetYaxis()->SetTitleSize(0.05);
    ak5FastJet__Multiplicidad->GetXaxis()->SetTitleOffset(1.0);ak5FastJet__Multiplicidad->GetYaxis()->SetTitleOffset(1.0);
    // Aqui ponemos todas las gráficas que necesitamos en el canvas.
    ak5FastJet__Multiplicidad -> Draw("E1"); ak5FastJet__Multiplicidad->SetLineColor(1);
    ak5FastJet__Multiplicidad->SetMarkerStyle(20); ak5FastJet__Multiplicidad->SetMarkerColor(1);
    ak5PFJet__Multiplicidad -> Draw("Esame"); ak5PFJet__Multiplicidad->SetLineColor(2);
    ak5PFJet__Multiplicidad->SetMarkerStyle(23); ak5PFJet__Multiplicidad->SetMarkerColor(2);
    ak5PFBTag__Multiplicidad -> Draw("Esame"); ak5PFBTag__Multiplicidad->SetLineColor(9);
    ak5PFBTag__Multiplicidad->SetMarkerStyle(22); ak5PFBTag__Multiplicidad->SetMarkerColor(9);
    ak5PFMultiJet__Multiplicidad -> Draw("Esame"); ak5PFMultiJet__Multiplicidad->SetLineColor(32);
    ak5PFMultiJet__Multiplicidad->SetMarkerStyle(21); ak5PFMultiJet__Multiplicidad->SetMarkerColor(32);
    legend -> Draw();

  Espectro_Multiplicidad__Jets -> SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Multiplicidad__FastJet-PFJets.png"); Espectro_Multiplicidad__Jets -> Close();

}

//###################################################################################################################################################################################

void EnergyQuotient() {
    // Le damos algo de personalización al las gráficas.
    gROOT->ForceStyle();
    gStyle->SetPadBorderMode(0);    gStyle->SetPadBorderSize(0);
    gStyle->SetPadTopMargin(0.08);  gStyle->SetPadBottomMargin(0.12);
    gStyle->SetPadLeftMargin(0.10); gStyle->SetPadRightMargin(0.10);
    gStyle->SetOptStat(0);          gStyle->SetOptTitle(1);

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

    TH1F *CLONE_E_Q__Muon_FJ =(TH1F*)Energy_Quot__Muon_FJ->Clone();
    TH1F *CLONE_E_Q__Muon_Jet =(TH1F*)Energy_Quot__Muon_Jet->Clone();
    TH1F *CLONE_E_Q__Muon_BTag =(TH1F*)Energy_Quot__Muon_BTag->Clone();
    TH1F *CLONE_E_Q__Muon_MinBias =(TH1F*)Energy_Quot__Muon_MinBias->Clone();
    TH1F *CLONE_E_Q__Muon_MultiJet =(TH1F*)Energy_Quot__Muon_MultiJet->Clone();

  TH1F *Energy_Quot__Muon_FJ200 =(TH1F*)FJFile->Get("Jets_Energy_Quotient__Muon-Jet<200"); Energy_Quot__Muon_FJ200->Scale(1.0/Energy_Quot__Muon_FJ200->Integral());
  TH1F *Energy_Quot__Muon_Jet200 =(TH1F*)JetFile->Get("Jets_Energy_Quotient__Muon-Jet<200"); Energy_Quot__Muon_Jet200->Scale(1.0/Energy_Quot__Muon_Jet200->Integral());
  TH1F *Energy_Quot__Muon_BTag200 =(TH1F*)BTagFile->Get("Jets_Energy_Quotient__Muon-Jet<200"); Energy_Quot__Muon_BTag200->Scale(1.0/Energy_Quot__Muon_BTag200->Integral());
  TH1F *Energy_Quot__Muon_MinBias200 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quotient__Muon-Jet<200"); Energy_Quot__Muon_MinBias200->Scale(1.0/Energy_Quot__Muon_MinBias200->Integral());
  TH1F *Energy_Quot__Muon_MultiJet200 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quotient__Muon-Jet<200"); Energy_Quot__Muon_MultiJet200->Scale(1.0/Energy_Quot__Muon_MultiJet200->Integral());

  TH1F *Energy_Quot__Muon_200FJ =(TH1F*)FJFile->Get("Jets_Energy_Quotient__Muon-Jet>200"); Energy_Quot__Muon_200FJ->Scale(1.0/Energy_Quot__Muon_200FJ->Integral());
  TH1F *Energy_Quot__Muon_200Jet =(TH1F*)JetFile->Get("Jets_Energy_Quotient__Muon-Jet>200"); Energy_Quot__Muon_200Jet->Scale(1.0/Energy_Quot__Muon_200Jet->Integral());
  TH1F *Energy_Quot__Muon_200BTag =(TH1F*)BTagFile->Get("Jets_Energy_Quotient__Muon-Jet>200"); Energy_Quot__Muon_200BTag->Scale(1.0/Energy_Quot__Muon_200BTag->Integral());
  TH1F *Energy_Quot__Muon_200MinBias =(TH1F*)MinBiasFile->Get("Jets_Energy_Quotient__Muon-Jet>200"); Energy_Quot__Muon_200MinBias->Scale(1.0/Energy_Quot__Muon_200MinBias->Integral());
  TH1F *Energy_Quot__Muon_200MultiJet =(TH1F*)MultiJetFile->Get("Jets_Energy_Quotient__Muon-Jet>200"); Energy_Quot__Muon_200MultiJet->Scale(1.0/Energy_Quot__Muon_200MultiJet->Integral());

  TH1F *Energy_Quot__Photon_FJ =(TH1F*)FJFile->Get("Jets_Energy_Quotient__Photon-Jet"); Energy_Quot__Photon_FJ->Scale(1.0/Energy_Quot__Photon_FJ->Integral());
  TH1F *Energy_Quot__Photon_Jet =(TH1F*)JetFile->Get("Jets_Energy_Quotient__Photon-Jet"); Energy_Quot__Photon_Jet->Scale(1.0/Energy_Quot__Photon_Jet->Integral());
  TH1F *Energy_Quot__Photon_BTag =(TH1F*)BTagFile->Get("Jets_Energy_Quotient__Photon-Jet"); Energy_Quot__Photon_BTag->Scale(1.0/Energy_Quot__Photon_BTag->Integral());
  TH1F *Energy_Quot__Photon_MinBias =(TH1F*)MinBiasFile->Get("Jets_Energy_Quotient__Photon-Jet"); Energy_Quot__Photon_MinBias->Scale(1.0/Energy_Quot__Photon_MinBias->Integral());
  TH1F *Energy_Quot__Photon_MultiJet =(TH1F*)MultiJetFile->Get("Jets_Energy_Quotient__Photon-Jet"); Energy_Quot__Photon_MultiJet->Scale(1.0/Energy_Quot__Photon_MultiJet->Integral());

  TH1F *Energy_Quot__Photon_FJ200 =(TH1F*)FJFile->Get("Jets_Energy_Quotient__Photon-Jet<200"); Energy_Quot__Photon_FJ200->Scale(1.0/Energy_Quot__Photon_FJ200->Integral());
  TH1F *Energy_Quot__Photon_Jet200 =(TH1F*)JetFile->Get("Jets_Energy_Quotient__Photon-Jet<200"); Energy_Quot__Photon_Jet200->Scale(1.0/Energy_Quot__Photon_Jet200->Integral());
  TH1F *Energy_Quot__Photon_BTag200 =(TH1F*)BTagFile->Get("Jets_Energy_Quotient__Photon-Jet<200"); Energy_Quot__Photon_BTag200->Scale(1.0/Energy_Quot__Photon_BTag200->Integral());
  TH1F *Energy_Quot__Photon_MinBias200 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quotient__Photon-Jet<200"); Energy_Quot__Photon_MinBias200->Scale(1.0/Energy_Quot__Photon_MinBias200->Integral());
  TH1F *Energy_Quot__Photon_MultiJet200 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quotient__Photon-Jet<200"); Energy_Quot__Photon_MultiJet200->Scale(1.0/Energy_Quot__Photon_MultiJet200->Integral());

  TH1F *Energy_Quot__Photon_200FJ =(TH1F*)FJFile->Get("Jets_Energy_Quotient__Photon-Jet>200"); Energy_Quot__Photon_200FJ->Scale(1.0/Energy_Quot__Photon_200FJ->Integral());
  TH1F *Energy_Quot__Photon_200Jet =(TH1F*)JetFile->Get("Jets_Energy_Quotient__Photon-Jet>200"); Energy_Quot__Photon_200Jet->Scale(1.0/Energy_Quot__Photon_200Jet->Integral());
  TH1F *Energy_Quot__Photon_200BTag =(TH1F*)BTagFile->Get("Jets_Energy_Quotient__Photon-Jet>200"); Energy_Quot__Photon_200BTag->Scale(1.0/Energy_Quot__Photon_200BTag->Integral());
  TH1F *Energy_Quot__Photon_200MinBias =(TH1F*)MinBiasFile->Get("Jets_Energy_Quotient__Photon-Jet>200"); Energy_Quot__Photon_200MinBias->Scale(1.0/Energy_Quot__Photon_200MinBias->Integral());
  TH1F *Energy_Quot__Photon_200MultiJet =(TH1F*)MultiJetFile->Get("Jets_Energy_Quotient__Photon-Jet>200"); Energy_Quot__Photon_200MultiJet->Scale(1.0/Energy_Quot__Photon_200MultiJet->Integral());

  TH1F *Energy_Quot__Electron_FJ =(TH1F*)FJFile->Get("Jets_Energy_Quotient__Electron-Jet"); Energy_Quot__Electron_FJ->Scale(1.0/Energy_Quot__Electron_FJ->Integral());
  TH1F *Energy_Quot__Electron_Jet =(TH1F*)JetFile->Get("Jets_Energy_Quotient__Electron-Jet"); Energy_Quot__Electron_Jet->Scale(1.0/Energy_Quot__Electron_Jet->Integral());
  TH1F *Energy_Quot__Electron_BTag =(TH1F*)BTagFile->Get("Jets_Energy_Quotient__Electron-Jet"); Energy_Quot__Electron_BTag->Scale(1.0/Energy_Quot__Electron_BTag->Integral());
  TH1F *Energy_Quot__Electron_MinBias =(TH1F*)MinBiasFile->Get("Jets_Energy_Quotient__Electron-Jet"); Energy_Quot__Electron_MinBias->Scale(1.0/Energy_Quot__Electron_MinBias->Integral());
  TH1F *Energy_Quot__Electron_MultiJet =(TH1F*)MultiJetFile->Get("Jets_Energy_Quotient__Electron-Jet"); Energy_Quot__Electron_MultiJet->Scale(1.0/Energy_Quot__Electron_MultiJet->Integral());

  TH1F *Energy_Quot__Electron_FJ200 =(TH1F*)FJFile->Get("Jets_Energy_Quotient__Electron-Jet<200"); Energy_Quot__Electron_FJ200->Scale(1.0/Energy_Quot__Electron_FJ200->Integral());
  TH1F *Energy_Quot__Electron_Jet200 =(TH1F*)JetFile->Get("Jets_Energy_Quotient__Electron-Jet<200"); Energy_Quot__Electron_Jet200->Scale(1.0/Energy_Quot__Electron_Jet200->Integral());
  TH1F *Energy_Quot__Electron_BTag200 =(TH1F*)BTagFile->Get("Jets_Energy_Quotient__Electron-Jet<200"); Energy_Quot__Electron_BTag200->Scale(1.0/Energy_Quot__Electron_BTag200->Integral());
  TH1F *Energy_Quot__Electron_MinBias200 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quotient__Electron-Jet<200"); Energy_Quot__Electron_MinBias200->Scale(1.0/Energy_Quot__Electron_MinBias200->Integral());
  TH1F *Energy_Quot__Electron_MultiJet200 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quotient__Electron-Jet<200"); Energy_Quot__Electron_MultiJet200->Scale(1.0/Energy_Quot__Electron_MultiJet200->Integral());

  TH1F *Energy_Quot__Electron_200FJ =(TH1F*)FJFile->Get("Jets_Energy_Quotient__Electron-Jet>200"); Energy_Quot__Electron_200FJ->Scale(1.0/Energy_Quot__Electron_200FJ->Integral());
  TH1F *Energy_Quot__Electron_200Jet =(TH1F*)JetFile->Get("Jets_Energy_Quotient__Electron-Jet>200"); Energy_Quot__Electron_200Jet->Scale(1.0/Energy_Quot__Electron_200Jet->Integral());
  TH1F *Energy_Quot__Electron_200BTag =(TH1F*)BTagFile->Get("Jets_Energy_Quotient__Electron-Jet>200"); Energy_Quot__Electron_200BTag->Scale(1.0/Energy_Quot__Electron_200BTag->Integral());
  TH1F *Energy_Quot__Electron_200MinBias =(TH1F*)MinBiasFile->Get("Jets_Energy_Quotient__Electron-Jet>200"); Energy_Quot__Electron_200MinBias->Scale(1.0/Energy_Quot__Electron_200MinBias->Integral());
  TH1F *Energy_Quot__Electron_200MultiJet =(TH1F*)MultiJetFile->Get("Jets_Energy_Quotient__Electron-Jet>200"); Energy_Quot__Electron_200MultiJet->Scale(1.0/Energy_Quot__Electron_200MultiJet->Integral());

  TH1F *Energy_Quot__NeutralHad_FJ =(TH1F*)FJFile->Get("Jets_Energy_Quotient__NeutralHad-Jet"); Energy_Quot__NeutralHad_FJ->Scale(1.0/Energy_Quot__NeutralHad_FJ->Integral());
  TH1F *Energy_Quot__NeutralHad_Jet =(TH1F*)JetFile->Get("Jets_Energy_Quotient__NeutralHad-Jet"); Energy_Quot__NeutralHad_Jet->Scale(1.0/Energy_Quot__NeutralHad_Jet->Integral());
  TH1F *Energy_Quot__NeutralHad_BTag =(TH1F*)BTagFile->Get("Jets_Energy_Quotient__NeutralHad-Jet"); Energy_Quot__NeutralHad_BTag->Scale(1.0/Energy_Quot__NeutralHad_BTag->Integral());
  TH1F *Energy_Quot__NeutralHad_MinBias =(TH1F*)MinBiasFile->Get("Jets_Energy_Quotient__NeutralHad-Jet"); Energy_Quot__NeutralHad_MinBias->Scale(1.0/Energy_Quot__NeutralHad_MinBias->Integral());
  TH1F *Energy_Quot__NeutralHad_MultiJet =(TH1F*)MultiJetFile->Get("Jets_Energy_Quotient__NeutralHad-Jet"); Energy_Quot__NeutralHad_MultiJet->Scale(1.0/Energy_Quot__NeutralHad_MultiJet->Integral());

  TH1F *Energy_Quot__NeutralHad_FJ200 =(TH1F*)FJFile->Get("Jets_Energy_Quotient__NeutralHad-Jet<200"); Energy_Quot__NeutralHad_FJ200->Scale(1.0/Energy_Quot__NeutralHad_FJ200->Integral());
  TH1F *Energy_Quot__NeutralHad_Jet200 =(TH1F*)JetFile->Get("Jets_Energy_Quotient__NeutralHad-Jet<200"); Energy_Quot__NeutralHad_Jet200->Scale(1.0/Energy_Quot__NeutralHad_Jet200->Integral());
  TH1F *Energy_Quot__NeutralHad_BTag200 =(TH1F*)BTagFile->Get("Jets_Energy_Quotient__NeutralHad-Jet<200"); Energy_Quot__NeutralHad_BTag200->Scale(1.0/Energy_Quot__NeutralHad_BTag200->Integral());
  TH1F *Energy_Quot__NeutralHad_MinBias200 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quotient__NeutralHad-Jet<200"); Energy_Quot__NeutralHad_MinBias200->Scale(1.0/Energy_Quot__NeutralHad_MinBias200->Integral());
  TH1F *Energy_Quot__NeutralHad_MultiJet200 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quotient__NeutralHad-Jet<200"); Energy_Quot__NeutralHad_MultiJet200->Scale(1.0/Energy_Quot__NeutralHad_MultiJet200->Integral());

  TH1F *Energy_Quot__NeutralHad_200FJ =(TH1F*)FJFile->Get("Jets_Energy_Quotient__NeutralHad-Jet>200"); Energy_Quot__NeutralHad_200FJ->Scale(1.0/Energy_Quot__NeutralHad_200FJ->Integral());
  TH1F *Energy_Quot__NeutralHad_200Jet =(TH1F*)JetFile->Get("Jets_Energy_Quotient__NeutralHad-Jet>200"); Energy_Quot__NeutralHad_200Jet->Scale(1.0/Energy_Quot__NeutralHad_200Jet->Integral());
  TH1F *Energy_Quot__NeutralHad_200BTag =(TH1F*)BTagFile->Get("Jets_Energy_Quotient__NeutralHad-Jet>200"); Energy_Quot__NeutralHad_200BTag->Scale(1.0/Energy_Quot__NeutralHad_200BTag->Integral());
  TH1F *Energy_Quot__NeutralHad_200MinBias =(TH1F*)MinBiasFile->Get("Jets_Energy_Quotient__NeutralHad-Jet>200"); Energy_Quot__NeutralHad_200MinBias->Scale(1.0/Energy_Quot__NeutralHad_200MinBias->Integral());
  TH1F *Energy_Quot__NeutralHad_200MultiJet =(TH1F*)MultiJetFile->Get("Jets_Energy_Quotient__NeutralHad-Jet>200"); Energy_Quot__NeutralHad_200MultiJet->Scale(1.0/Energy_Quot__NeutralHad_200MultiJet->Integral());

  TH1F *Energy_Quot__ChargedHad_FJ =(TH1F*)FJFile->Get("Jets_Energy_Quotient__ChargedHad-Jet"); Energy_Quot__ChargedHad_FJ->Scale(1.0/Energy_Quot__ChargedHad_FJ->Integral());
  TH1F *Energy_Quot__ChargedHad_Jet =(TH1F*)JetFile->Get("Jets_Energy_Quotient__ChargedHad-Jet"); Energy_Quot__ChargedHad_Jet->Scale(1.0/Energy_Quot__ChargedHad_Jet->Integral());
  TH1F *Energy_Quot__ChargedHad_BTag =(TH1F*)BTagFile->Get("Jets_Energy_Quotient__ChargedHad-Jet"); Energy_Quot__ChargedHad_BTag->Scale(1.0/Energy_Quot__ChargedHad_BTag->Integral());
  TH1F *Energy_Quot__ChargedHad_MinBias =(TH1F*)MinBiasFile->Get("Jets_Energy_Quotient__ChargedHad-Jet"); Energy_Quot__ChargedHad_MinBias->Scale(1.0/Energy_Quot__ChargedHad_MinBias->Integral());
  TH1F *Energy_Quot__ChargedHad_MultiJet =(TH1F*)MultiJetFile->Get("Jets_Energy_Quotient__ChargedHad-Jet"); Energy_Quot__ChargedHad_MultiJet->Scale(1.0/Energy_Quot__ChargedHad_MultiJet->Integral());

  TH1F *Energy_Quot__ChargedHad_FJ200 =(TH1F*)FJFile->Get("Jets_Energy_Quotient__ChargedHad-Jet<200"); Energy_Quot__ChargedHad_FJ200->Scale(1.0/Energy_Quot__ChargedHad_FJ200->Integral());
  TH1F *Energy_Quot__ChargedHad_Jet200 =(TH1F*)JetFile->Get("Jets_Energy_Quotient__ChargedHad-Jet<200"); Energy_Quot__ChargedHad_Jet200->Scale(1.0/Energy_Quot__ChargedHad_Jet200->Integral());
  TH1F *Energy_Quot__ChargedHad_BTag200 =(TH1F*)BTagFile->Get("Jets_Energy_Quotient__ChargedHad-Jet<200"); Energy_Quot__ChargedHad_BTag200->Scale(1.0/Energy_Quot__ChargedHad_BTag200->Integral());
  TH1F *Energy_Quot__ChargedHad_MinBias200 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quotient__ChargedHad-Jet<200"); Energy_Quot__ChargedHad_MinBias200->Scale(1.0/Energy_Quot__ChargedHad_MinBias200->Integral());
  TH1F *Energy_Quot__ChargedHad_MultiJet200 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quotient__ChargedHad-Jet<200"); Energy_Quot__ChargedHad_MultiJet200->Scale(1.0/Energy_Quot__ChargedHad_MultiJet200->Integral());

  TH1F *Energy_Quot__ChargedHad_200FJ =(TH1F*)FJFile->Get("Jets_Energy_Quotient__ChargedHad-Jet>200"); Energy_Quot__ChargedHad_200FJ->Scale(1.0/Energy_Quot__ChargedHad_200FJ->Integral());
  TH1F *Energy_Quot__ChargedHad_200Jet =(TH1F*)JetFile->Get("Jets_Energy_Quotient__ChargedHad-Jet>200"); Energy_Quot__ChargedHad_200Jet->Scale(1.0/Energy_Quot__ChargedHad_200Jet->Integral());
  TH1F *Energy_Quot__ChargedHad_200BTag =(TH1F*)BTagFile->Get("Jets_Energy_Quotient__ChargedHad-Jet>200"); Energy_Quot__ChargedHad_200BTag->Scale(1.0/Energy_Quot__ChargedHad_200BTag->Integral());
  TH1F *Energy_Quot__ChargedHad_200MinBias =(TH1F*)MinBiasFile->Get("Jets_Energy_Quotient__ChargedHad-Jet>200"); Energy_Quot__ChargedHad_200MinBias->Scale(1.0/Energy_Quot__ChargedHad_200MinBias->Integral());
  TH1F *Energy_Quot__ChargedHad_200MultiJet =(TH1F*)MultiJetFile->Get("Jets_Energy_Quotient__ChargedHad-Jet>200"); Energy_Quot__ChargedHad_200MultiJet->Scale(1.0/Energy_Quot__ChargedHad_200MultiJet->Integral());



  auto   Leg = new TLegend(0.62,0.70,0.90,0.92);    Leg->SetTextSize(0.04); Leg->SetFillStyle(0); Leg->SetBorderSize(0);
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


  auto   legend = new TLegend(0.62,0.70,0.90,0.92);    legend->SetTextSize(0.04); legend->SetFillStyle(0); legend->SetBorderSize(0);
    legend->AddEntry(Energy_Quot__Muon_FJ, "MC FastJet", "lep");
    legend->AddEntry(Energy_Quot__Muon_Jet, "Open-Data PF Jet", "lep");
    legend->AddEntry(Energy_Quot__Muon_BTag, "Open-Data PF BTag", "lep");
    legend->AddEntry(Energy_Quot__Muon_MinBias, "Open-Data PF MinBias", "lep");
    legend->AddEntry(Energy_Quot__Muon_MultiJet, "Open-Data PF MultiJet", "lep");

  // auto   QuarkLegend = new TLegend(0.75,0.60,0.90,0.92);    QuarkLegend->SetTextSize(0.04);
  //   QuarkLegend->AddEntry(Cociente_pT__Muon_ak5FJ, "MC FastJet", "lp");
  //   QuarkLegend->AddEntry(Cociente_pT__Muon01_ak5FJ, "MC, Down", "lp");
  //   QuarkLegend->AddEntry(Cociente_pT__Muon02_ak5FJ, "MC, Up", "lp");
  //   QuarkLegend->AddEntry(Cociente_pT__Muon03_ak5FJ, "MC, Strange", "lp");
  //   QuarkLegend->AddEntry(Cociente_pT__Muon04_ak5FJ, "MC, Charm", "lp");
  //   QuarkLegend->AddEntry(Cociente_pT__Muon05_ak5FJ, "MC, Bottom", "lp");
  //   QuarkLegend->AddEntry(Cociente_pT__Muon21_ak5FJ, "MC, Gluon", "lp");
  //
  // auto   ODQuarkLegend = new TLegend(0.68,0.60,0.90,0.92);    ODQuarkLegend->SetTextSize(0.04);
  //   ODQuarkLegend->AddEntry(Cociente_pT__Muon_ak5PFJet, "Open-Data PF Jet", "lp");
  //   ODQuarkLegend->AddEntry(Cociente_pT__Muon01_ak5FJ, "MC, Down", "lp");
  //   ODQuarkLegend->AddEntry(Cociente_pT__Muon02_ak5FJ, "MC, Up", "lp");
  //   ODQuarkLegend->AddEntry(Cociente_pT__Muon03_ak5FJ, "MC, Strange", "lp");
  //   ODQuarkLegend->AddEntry(Cociente_pT__Muon04_ak5FJ, "MC, Charm", "lp");
  //   ODQuarkLegend->AddEntry(Cociente_pT__Muon05_ak5FJ, "MC, Bottom", "lp");
  //   ODQuarkLegend->AddEntry(Cociente_pT__Muon21_ak5FJ, "MC, Gluon", "lp");


  TCanvas* Energy_Quotient__Muon_Jet = new TCanvas("Energy_Quotient__Muon_Jet","Energy_Quotient__Muon_Jet",10,10,1920,1080);
  Energy_Quotient__Muon_Jet->SetFillColor(0);  Energy_Quotient__Muon_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  Energy_Quot__Muon_FJ->SetTitle("Cociente Energ#acute{i}a  Mu#acute{o}n/Jet; Energ#acute{i}a^{Muon} / Energ#acute{i}a^{Jet}; U. A.");
  Energy_Quot__Muon_FJ->GetXaxis()->SetLabelSize(0.05); Energy_Quot__Muon_FJ->GetYaxis()->SetLabelSize(0.05);
  Energy_Quot__Muon_FJ->GetXaxis()->SetTitleSize(0.05); Energy_Quot__Muon_FJ->GetYaxis()->SetTitleSize(0.05);
  Energy_Quot__Muon_FJ->GetXaxis()->SetTitleOffset(1.0);Energy_Quot__Muon_FJ->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Energy_Quot__Muon_FJ->Rebin(); Energy_Quot__Muon_FJ->SetAxisRange(0.0, 1.09, "X");
  Energy_Quot__Muon_FJ->SetMarkerSize(4);Energy_Quot__Muon_FJ->SetMarkerStyle(21); Energy_Quot__Muon_FJ->SetMarkerColor(14);
  Energy_Quot__Muon_FJ->DrawCopy("P");   Energy_Quot__Muon_FJ->SetMarkerStyle(25); Energy_Quot__Muon_FJ->SetMarkerColor(1);
  Energy_Quot__Muon_FJ->SetLineWidth(4); Energy_Quot__Muon_FJ->Draw("Esame");      Energy_Quot__Muon_FJ->SetLineColor(1);
  Energy_Quot__Muon_Jet->Rebin();
  Energy_Quot__Muon_Jet->SetMarkerSize(4); Energy_Quot__Muon_Jet->SetMarkerStyle(23); Energy_Quot__Muon_Jet->SetMarkerColor(42);
  Energy_Quot__Muon_Jet->DrawCopy("Psame");Energy_Quot__Muon_Jet->SetMarkerStyle(32); Energy_Quot__Muon_Jet->SetMarkerColor(2);
  Energy_Quot__Muon_Jet->SetLineWidth(4);  Energy_Quot__Muon_Jet->Draw("Esame");      Energy_Quot__Muon_Jet->SetLineColor(2);
  Energy_Quot__Muon_BTag->Rebin();
  Energy_Quot__Muon_BTag->SetMarkerSize(4); Energy_Quot__Muon_BTag->SetMarkerStyle(22); Energy_Quot__Muon_BTag->SetMarkerColor(33);
  Energy_Quot__Muon_BTag->DrawCopy("Psame");Energy_Quot__Muon_BTag->SetMarkerStyle(26); Energy_Quot__Muon_BTag->SetMarkerColor(4);
  Energy_Quot__Muon_BTag->SetLineWidth(4);  Energy_Quot__Muon_BTag->Draw("Esame");      Energy_Quot__Muon_BTag->SetLineColor(4);
  Energy_Quot__Muon_MinBias->Rebin();
  Energy_Quot__Muon_MinBias->SetMarkerSize(4); Energy_Quot__Muon_MinBias->SetMarkerStyle(20); Energy_Quot__Muon_MinBias->SetMarkerColor(5);
  Energy_Quot__Muon_MinBias->DrawCopy("Psame");Energy_Quot__Muon_MinBias->SetMarkerStyle(24); Energy_Quot__Muon_MinBias->SetMarkerColor(41);
  Energy_Quot__Muon_MinBias->SetLineWidth(4);  Energy_Quot__Muon_MinBias->Draw("Esame");      Energy_Quot__Muon_MinBias->SetLineColor(41);
  Energy_Quot__Muon_MultiJet->Rebin();
  Energy_Quot__Muon_MultiJet->SetMarkerSize(4); Energy_Quot__Muon_MultiJet->SetMarkerStyle(34); Energy_Quot__Muon_MultiJet->SetMarkerColor(8);
  Energy_Quot__Muon_MultiJet->DrawCopy("Psame");Energy_Quot__Muon_MultiJet->SetMarkerStyle(28); Energy_Quot__Muon_MultiJet->SetMarkerColor(32);
  Energy_Quot__Muon_MultiJet->SetLineWidth(4);  Energy_Quot__Muon_MultiJet->Draw("Esame");      Energy_Quot__Muon_MultiJet->SetLineColor(32);
  Leg->Draw(); legend->Draw();  Energy_Quotient__Muon_Jet->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__Muon-Jet.png"); Energy_Quotient__Muon_Jet->Close();

  TCanvas* Energy_Quotient__Muon_Jet200 = new TCanvas("Energy_Quotient__Muon_Jet200","Energy_Quotient__Muon_Jet200",10,10,1920,1080);
  Energy_Quotient__Muon_Jet200->SetFillColor(0);  Energy_Quotient__Muon_Jet200->SetFrameBorderMode(0);  gPad->SetLogy();
  Energy_Quot__Muon_FJ200->SetTitle("Cociente Energ#acute{i}a  Mu#acute{o}n/Jet  (Energ#acute{i}a^{Jet} < 200); Energ#acute{i}a^{Muon} / Energ#acute{i}a^{Jet}; U. A.");
  Energy_Quot__Muon_FJ200->GetXaxis()->SetLabelSize(0.05); Energy_Quot__Muon_FJ200->GetYaxis()->SetLabelSize(0.05);
  Energy_Quot__Muon_FJ200->GetXaxis()->SetTitleSize(0.05); Energy_Quot__Muon_FJ200->GetYaxis()->SetTitleSize(0.05);
  Energy_Quot__Muon_FJ200->GetXaxis()->SetTitleOffset(1.0);Energy_Quot__Muon_FJ200->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Energy_Quot__Muon_FJ200->Rebin(); Energy_Quot__Muon_FJ200->SetAxisRange(0.0, 1.09, "X");
  Energy_Quot__Muon_FJ200->SetMarkerSize(4);Energy_Quot__Muon_FJ200->SetMarkerStyle(21); Energy_Quot__Muon_FJ200->SetMarkerColor(14);
  Energy_Quot__Muon_FJ200->DrawCopy("P");   Energy_Quot__Muon_FJ200->SetMarkerStyle(25); Energy_Quot__Muon_FJ200->SetMarkerColor(1);
  Energy_Quot__Muon_FJ200->SetLineWidth(4); Energy_Quot__Muon_FJ200->Draw("Esame");      Energy_Quot__Muon_FJ200->SetLineColor(1);
  Energy_Quot__Muon_Jet200->Rebin();
  Energy_Quot__Muon_Jet200->SetMarkerSize(4); Energy_Quot__Muon_Jet200->SetMarkerStyle(23); Energy_Quot__Muon_Jet200->SetMarkerColor(42);
  Energy_Quot__Muon_Jet200->DrawCopy("Psame");Energy_Quot__Muon_Jet200->SetMarkerStyle(32); Energy_Quot__Muon_Jet200->SetMarkerColor(2);
  Energy_Quot__Muon_Jet200->SetLineWidth(4);  Energy_Quot__Muon_Jet200->Draw("Esame");      Energy_Quot__Muon_Jet200->SetLineColor(2);
  Energy_Quot__Muon_BTag200->Rebin();
  Energy_Quot__Muon_BTag200->SetMarkerSize(4); Energy_Quot__Muon_BTag200->SetMarkerStyle(22); Energy_Quot__Muon_BTag200->SetMarkerColor(33);
  Energy_Quot__Muon_BTag200->DrawCopy("Psame");Energy_Quot__Muon_BTag200->SetMarkerStyle(26); Energy_Quot__Muon_BTag200->SetMarkerColor(4);
  Energy_Quot__Muon_BTag200->SetLineWidth(4);  Energy_Quot__Muon_BTag200->Draw("Esame");      Energy_Quot__Muon_BTag200->SetLineColor(4);
  Energy_Quot__Muon_MinBias200->Rebin();
  Energy_Quot__Muon_MinBias200->SetMarkerSize(4); Energy_Quot__Muon_MinBias200->SetMarkerStyle(20); Energy_Quot__Muon_MinBias200->SetMarkerColor(5);
  Energy_Quot__Muon_MinBias200->DrawCopy("Psame");Energy_Quot__Muon_MinBias200->SetMarkerStyle(24); Energy_Quot__Muon_MinBias200->SetMarkerColor(41);
  Energy_Quot__Muon_MinBias200->SetLineWidth(4);  Energy_Quot__Muon_MinBias200->Draw("Esame");      Energy_Quot__Muon_MinBias200->SetLineColor(41);
  Energy_Quot__Muon_MultiJet200->Rebin();
  Energy_Quot__Muon_MultiJet200->SetMarkerSize(4); Energy_Quot__Muon_MultiJet200->SetMarkerStyle(34); Energy_Quot__Muon_MultiJet200->SetMarkerColor(8);
  Energy_Quot__Muon_MultiJet200->DrawCopy("Psame");Energy_Quot__Muon_MultiJet200->SetMarkerStyle(28); Energy_Quot__Muon_MultiJet200->SetMarkerColor(32);
  Energy_Quot__Muon_MultiJet200->SetLineWidth(4);  Energy_Quot__Muon_MultiJet200->Draw("Esame");      Energy_Quot__Muon_MultiJet200->SetLineColor(32);
  Leg->Draw(); legend->Draw();  Energy_Quotient__Muon_Jet200->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__Muon-Jet200.png"); Energy_Quotient__Muon_Jet200->Close();

  TCanvas* Energy_Quotient__Muon_200Jet = new TCanvas("Energy_Quotient__Muon_200Jet","Energy_Quotient__Muon_200Jet",10,10,1920,1080);
  Energy_Quotient__Muon_200Jet->SetFillColor(0);  Energy_Quotient__Muon_200Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  Energy_Quot__Muon_200FJ->SetTitle("Cociente Energ#acute{i}a  Mu#acute{o}n/Jet  (Energ#acute{i}a^{Jet} > 200); Energ#acute{i}a^{Muon} / Energ#acute{i}a^{Jet}; U. A.");
  Energy_Quot__Muon_200FJ->GetXaxis()->SetLabelSize(0.05); Energy_Quot__Muon_200FJ->GetYaxis()->SetLabelSize(0.05);
  Energy_Quot__Muon_200FJ->GetXaxis()->SetTitleSize(0.05); Energy_Quot__Muon_200FJ->GetYaxis()->SetTitleSize(0.05);
  Energy_Quot__Muon_200FJ->GetXaxis()->SetTitleOffset(1.0);Energy_Quot__Muon_200FJ->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Energy_Quot__Muon_200FJ->Rebin(); Energy_Quot__Muon_200FJ->SetAxisRange(0.0, 1.09, "X");
  Energy_Quot__Muon_200FJ->SetMarkerSize(4);Energy_Quot__Muon_200FJ->SetMarkerStyle(21); Energy_Quot__Muon_200FJ->SetMarkerColor(14);
  Energy_Quot__Muon_200FJ->DrawCopy("P");   Energy_Quot__Muon_200FJ->SetMarkerStyle(25); Energy_Quot__Muon_200FJ->SetMarkerColor(1);
  Energy_Quot__Muon_200FJ->SetLineWidth(4); Energy_Quot__Muon_200FJ->Draw("Esame");      Energy_Quot__Muon_200FJ->SetLineColor(1);
  Energy_Quot__Muon_200Jet->Rebin();
  Energy_Quot__Muon_200Jet->SetMarkerSize(4); Energy_Quot__Muon_200Jet->SetMarkerStyle(23); Energy_Quot__Muon_200Jet->SetMarkerColor(42);
  Energy_Quot__Muon_200Jet->DrawCopy("Psame");Energy_Quot__Muon_200Jet->SetMarkerStyle(32); Energy_Quot__Muon_200Jet->SetMarkerColor(2);
  Energy_Quot__Muon_200Jet->SetLineWidth(4);  Energy_Quot__Muon_200Jet->Draw("Esame");      Energy_Quot__Muon_200Jet->SetLineColor(2);
  Energy_Quot__Muon_200BTag->Rebin();
  Energy_Quot__Muon_200BTag->SetMarkerSize(4); Energy_Quot__Muon_200BTag->SetMarkerStyle(22); Energy_Quot__Muon_200BTag->SetMarkerColor(33);
  Energy_Quot__Muon_200BTag->DrawCopy("Psame");Energy_Quot__Muon_200BTag->SetMarkerStyle(26); Energy_Quot__Muon_200BTag->SetMarkerColor(4);
  Energy_Quot__Muon_200BTag->SetLineWidth(4);  Energy_Quot__Muon_200BTag->Draw("Esame");      Energy_Quot__Muon_200BTag->SetLineColor(4);
  Energy_Quot__Muon_200MinBias->Rebin();
  Energy_Quot__Muon_200MinBias->SetMarkerSize(4); Energy_Quot__Muon_200MinBias->SetMarkerStyle(20); Energy_Quot__Muon_200MinBias->SetMarkerColor(5);
  Energy_Quot__Muon_200MinBias->DrawCopy("Psame");Energy_Quot__Muon_200MinBias->SetMarkerStyle(24); Energy_Quot__Muon_200MinBias->SetMarkerColor(41);
  Energy_Quot__Muon_200MinBias->SetLineWidth(4);  Energy_Quot__Muon_200MinBias->Draw("Esame");      Energy_Quot__Muon_200MinBias->SetLineColor(41);
  Energy_Quot__Muon_200MultiJet->Rebin();
  Energy_Quot__Muon_200MultiJet->SetMarkerSize(4); Energy_Quot__Muon_200MultiJet->SetMarkerStyle(34); Energy_Quot__Muon_200MultiJet->SetMarkerColor(8);
  Energy_Quot__Muon_200MultiJet->DrawCopy("Psame");Energy_Quot__Muon_200MultiJet->SetMarkerStyle(28); Energy_Quot__Muon_200MultiJet->SetMarkerColor(32);
  Energy_Quot__Muon_200MultiJet->SetLineWidth(4);  Energy_Quot__Muon_200MultiJet->Draw("Esame");      Energy_Quot__Muon_200MultiJet->SetLineColor(32);
  Leg->Draw(); legend->Draw();  Energy_Quotient__Muon_200Jet->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__Muon-200Jet.png"); Energy_Quotient__Muon_200Jet->Close();


  TCanvas* Energy_Quotient__Photon_Jet = new TCanvas("Energy_Quotient__Photon_Jet","Energy_Quotient__Photon_Jet",10,10,1920,1080);
  Energy_Quotient__Photon_Jet->SetFillColor(0);  Energy_Quotient__Photon_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  Energy_Quot__Photon_FJ->SetTitle("Cociente Energ#acute{i}a  Fot#acute{o}n/Jet; Energ#acute{i}a^{Photon} / Energ#acute{i}a^{Jet}; U. A.");
  Energy_Quot__Photon_FJ->GetXaxis()->SetLabelSize(0.05); Energy_Quot__Photon_FJ->GetYaxis()->SetLabelSize(0.05);
  Energy_Quot__Photon_FJ->GetXaxis()->SetTitleSize(0.05); Energy_Quot__Photon_FJ->GetYaxis()->SetTitleSize(0.05);
  Energy_Quot__Photon_FJ->GetXaxis()->SetTitleOffset(1.0);Energy_Quot__Photon_FJ->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Energy_Quot__Photon_FJ->Rebin(); Energy_Quot__Photon_FJ->SetAxisRange(0.0, 1.09, "X");
  Energy_Quot__Photon_FJ->SetMarkerSize(4);Energy_Quot__Photon_FJ->SetMarkerStyle(21); Energy_Quot__Photon_FJ->SetMarkerColor(14);
  Energy_Quot__Photon_FJ->DrawCopy("P");   Energy_Quot__Photon_FJ->SetMarkerStyle(25); Energy_Quot__Photon_FJ->SetMarkerColor(1);
  Energy_Quot__Photon_FJ->SetLineWidth(4); Energy_Quot__Photon_FJ->Draw("Esame");      Energy_Quot__Photon_FJ->SetLineColor(1);
  Energy_Quot__Photon_Jet->Rebin();
  Energy_Quot__Photon_Jet->SetMarkerSize(4); Energy_Quot__Photon_Jet->SetMarkerStyle(23); Energy_Quot__Photon_Jet->SetMarkerColor(42);
  Energy_Quot__Photon_Jet->DrawCopy("Psame");Energy_Quot__Photon_Jet->SetMarkerStyle(32); Energy_Quot__Photon_Jet->SetMarkerColor(2);
  Energy_Quot__Photon_Jet->SetLineWidth(4);  Energy_Quot__Photon_Jet->Draw("Esame");      Energy_Quot__Photon_Jet->SetLineColor(2);
  Energy_Quot__Photon_BTag->Rebin();
  Energy_Quot__Photon_BTag->SetMarkerSize(4); Energy_Quot__Photon_BTag->SetMarkerStyle(22); Energy_Quot__Photon_BTag->SetMarkerColor(33);
  Energy_Quot__Photon_BTag->DrawCopy("Psame");Energy_Quot__Photon_BTag->SetMarkerStyle(26); Energy_Quot__Photon_BTag->SetMarkerColor(4);
  Energy_Quot__Photon_BTag->SetLineWidth(4);  Energy_Quot__Photon_BTag->Draw("Esame");      Energy_Quot__Photon_BTag->SetLineColor(4);
  Energy_Quot__Photon_MinBias->Rebin();
  Energy_Quot__Photon_MinBias->SetMarkerSize(4); Energy_Quot__Photon_MinBias->SetMarkerStyle(20); Energy_Quot__Photon_MinBias->SetMarkerColor(5);
  Energy_Quot__Photon_MinBias->DrawCopy("Psame");Energy_Quot__Photon_MinBias->SetMarkerStyle(24); Energy_Quot__Photon_MinBias->SetMarkerColor(41);
  Energy_Quot__Photon_MinBias->SetLineWidth(4);  Energy_Quot__Photon_MinBias->Draw("Esame");      Energy_Quot__Photon_MinBias->SetLineColor(41);
  Energy_Quot__Photon_MultiJet->Rebin();
  Energy_Quot__Photon_MultiJet->SetMarkerSize(4); Energy_Quot__Photon_MultiJet->SetMarkerStyle(34); Energy_Quot__Photon_MultiJet->SetMarkerColor(8);
  Energy_Quot__Photon_MultiJet->DrawCopy("Psame");Energy_Quot__Photon_MultiJet->SetMarkerStyle(28); Energy_Quot__Photon_MultiJet->SetMarkerColor(32);
  Energy_Quot__Photon_MultiJet->SetLineWidth(4);  Energy_Quot__Photon_MultiJet->Draw("Esame");      Energy_Quot__Photon_MultiJet->SetLineColor(32);
  Leg->Draw(); legend->Draw();  Energy_Quotient__Photon_Jet->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__Photon-Jet.png"); Energy_Quotient__Photon_Jet->Close();

  TCanvas* Energy_Quotient__Photon_Jet200 = new TCanvas("Energy_Quotient__Photon_Jet200","Energy_Quotient__Photon_Jet200",10,10,1920,1080);
  Energy_Quotient__Photon_Jet200->SetFillColor(0);  Energy_Quotient__Photon_Jet200->SetFrameBorderMode(0);  gPad->SetLogy();
  Energy_Quot__Photon_FJ200->SetTitle("Cociente Energ#acute{i}a  Fot#acute{o}n/Jet  (Energ#acute{i}a^{Jet} < 200); Energ#acute{i}a^{Photon} / Energ#acute{i}a^{Jet}; U. A.");
  Energy_Quot__Photon_FJ200->GetXaxis()->SetLabelSize(0.05); Energy_Quot__Photon_FJ200->GetYaxis()->SetLabelSize(0.05);
  Energy_Quot__Photon_FJ200->GetXaxis()->SetTitleSize(0.05); Energy_Quot__Photon_FJ200->GetYaxis()->SetTitleSize(0.05);
  Energy_Quot__Photon_FJ200->GetXaxis()->SetTitleOffset(1.0);Energy_Quot__Photon_FJ200->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Energy_Quot__Photon_FJ200->Rebin(); Energy_Quot__Photon_FJ200->SetAxisRange(0.0, 1.09, "X");
  Energy_Quot__Photon_FJ200->SetMarkerSize(4);Energy_Quot__Photon_FJ200->SetMarkerStyle(21); Energy_Quot__Photon_FJ200->SetMarkerColor(14);
  Energy_Quot__Photon_FJ200->DrawCopy("P");   Energy_Quot__Photon_FJ200->SetMarkerStyle(25); Energy_Quot__Photon_FJ200->SetMarkerColor(1);
  Energy_Quot__Photon_FJ200->SetLineWidth(4); Energy_Quot__Photon_FJ200->Draw("Esame");      Energy_Quot__Photon_FJ200->SetLineColor(1);
  Energy_Quot__Photon_Jet200->Rebin();
  Energy_Quot__Photon_Jet200->SetMarkerSize(4); Energy_Quot__Photon_Jet200->SetMarkerStyle(23); Energy_Quot__Photon_Jet200->SetMarkerColor(42);
  Energy_Quot__Photon_Jet200->DrawCopy("Psame");Energy_Quot__Photon_Jet200->SetMarkerStyle(32); Energy_Quot__Photon_Jet200->SetMarkerColor(2);
  Energy_Quot__Photon_Jet200->SetLineWidth(4);  Energy_Quot__Photon_Jet200->Draw("Esame");      Energy_Quot__Photon_Jet200->SetLineColor(2);
  Energy_Quot__Photon_BTag200->Rebin();
  Energy_Quot__Photon_BTag200->SetMarkerSize(4); Energy_Quot__Photon_BTag200->SetMarkerStyle(22); Energy_Quot__Photon_BTag200->SetMarkerColor(33);
  Energy_Quot__Photon_BTag200->DrawCopy("Psame");Energy_Quot__Photon_BTag200->SetMarkerStyle(26); Energy_Quot__Photon_BTag200->SetMarkerColor(4);
  Energy_Quot__Photon_BTag200->SetLineWidth(4);  Energy_Quot__Photon_BTag200->Draw("Esame");      Energy_Quot__Photon_BTag200->SetLineColor(4);
  Energy_Quot__Photon_MinBias200->Rebin();
  Energy_Quot__Photon_MinBias200->SetMarkerSize(4); Energy_Quot__Photon_MinBias200->SetMarkerStyle(20); Energy_Quot__Photon_MinBias200->SetMarkerColor(5);
  Energy_Quot__Photon_MinBias200->DrawCopy("Psame");Energy_Quot__Photon_MinBias200->SetMarkerStyle(24); Energy_Quot__Photon_MinBias200->SetMarkerColor(41);
  Energy_Quot__Photon_MinBias200->SetLineWidth(4);  Energy_Quot__Photon_MinBias200->Draw("Esame");      Energy_Quot__Photon_MinBias200->SetLineColor(41);
  Energy_Quot__Photon_MultiJet200->Rebin();
  Energy_Quot__Photon_MultiJet200->SetMarkerSize(4); Energy_Quot__Photon_MultiJet200->SetMarkerStyle(34); Energy_Quot__Photon_MultiJet200->SetMarkerColor(8);
  Energy_Quot__Photon_MultiJet200->DrawCopy("Psame");Energy_Quot__Photon_MultiJet200->SetMarkerStyle(28); Energy_Quot__Photon_MultiJet200->SetMarkerColor(32);
  Energy_Quot__Photon_MultiJet200->SetLineWidth(4);  Energy_Quot__Photon_MultiJet200->Draw("Esame");      Energy_Quot__Photon_MultiJet200->SetLineColor(32);
  Leg->Draw(); legend->Draw();  Energy_Quotient__Photon_Jet200->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__Photon-Jet200.png"); Energy_Quotient__Photon_Jet200->Close();

  TCanvas* Energy_Quotient__Photon_200Jet = new TCanvas("Energy_Quotient__Photon_200Jet","Energy_Quotient__Photon_200Jet",10,10,1920,1080);
  Energy_Quotient__Photon_200Jet->SetFillColor(0);  Energy_Quotient__Photon_200Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  Energy_Quot__Photon_200FJ->SetTitle("Cociente Energ#acute{i}a  Fot#acute{o}n/Jet  (Energ#acute{i}a^{Jet} > 200); Energ#acute{i}a^{Photon} / Energ#acute{i}a^{Jet}; U. A.");
  Energy_Quot__Photon_200FJ->GetXaxis()->SetLabelSize(0.05); Energy_Quot__Photon_200FJ->GetYaxis()->SetLabelSize(0.05);
  Energy_Quot__Photon_200FJ->GetXaxis()->SetTitleSize(0.05); Energy_Quot__Photon_200FJ->GetYaxis()->SetTitleSize(0.05);
  Energy_Quot__Photon_200FJ->GetXaxis()->SetTitleOffset(1.0);Energy_Quot__Photon_200FJ->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Energy_Quot__Photon_200FJ->Rebin(); Energy_Quot__Photon_200FJ->SetAxisRange(0.0, 1.09, "X");
  Energy_Quot__Photon_200FJ->SetMarkerSize(4);Energy_Quot__Photon_200FJ->SetMarkerStyle(21); Energy_Quot__Photon_200FJ->SetMarkerColor(14);
  Energy_Quot__Photon_200FJ->DrawCopy("P");   Energy_Quot__Photon_200FJ->SetMarkerStyle(25); Energy_Quot__Photon_200FJ->SetMarkerColor(1);
  Energy_Quot__Photon_200FJ->SetLineWidth(4); Energy_Quot__Photon_200FJ->Draw("Esame");      Energy_Quot__Photon_200FJ->SetLineColor(1);
  Energy_Quot__Photon_200Jet->Rebin();
  Energy_Quot__Photon_200Jet->SetMarkerSize(4); Energy_Quot__Photon_200Jet->SetMarkerStyle(23); Energy_Quot__Photon_200Jet->SetMarkerColor(42);
  Energy_Quot__Photon_200Jet->DrawCopy("Psame");Energy_Quot__Photon_200Jet->SetMarkerStyle(32); Energy_Quot__Photon_200Jet->SetMarkerColor(2);
  Energy_Quot__Photon_200Jet->SetLineWidth(4);  Energy_Quot__Photon_200Jet->Draw("Esame");      Energy_Quot__Photon_200Jet->SetLineColor(2);
  Energy_Quot__Photon_200BTag->Rebin();
  Energy_Quot__Photon_200BTag->SetMarkerSize(4); Energy_Quot__Photon_200BTag->SetMarkerStyle(22); Energy_Quot__Photon_200BTag->SetMarkerColor(33);
  Energy_Quot__Photon_200BTag->DrawCopy("Psame");Energy_Quot__Photon_200BTag->SetMarkerStyle(26); Energy_Quot__Photon_200BTag->SetMarkerColor(4);
  Energy_Quot__Photon_200BTag->SetLineWidth(4);  Energy_Quot__Photon_200BTag->Draw("Esame");      Energy_Quot__Photon_200BTag->SetLineColor(4);
  Energy_Quot__Photon_200MinBias->Rebin();
  Energy_Quot__Photon_200MinBias->SetMarkerSize(4); Energy_Quot__Photon_200MinBias->SetMarkerStyle(20); Energy_Quot__Photon_200MinBias->SetMarkerColor(5);
  Energy_Quot__Photon_200MinBias->DrawCopy("Psame");Energy_Quot__Photon_200MinBias->SetMarkerStyle(24); Energy_Quot__Photon_200MinBias->SetMarkerColor(41);
  Energy_Quot__Photon_200MinBias->SetLineWidth(4);  Energy_Quot__Photon_200MinBias->Draw("Esame");      Energy_Quot__Photon_200MinBias->SetLineColor(41);
  Energy_Quot__Photon_200MultiJet->Rebin();
  Energy_Quot__Photon_200MultiJet->SetMarkerSize(4); Energy_Quot__Photon_200MultiJet->SetMarkerStyle(34); Energy_Quot__Photon_200MultiJet->SetMarkerColor(8);
  Energy_Quot__Photon_200MultiJet->DrawCopy("Psame");Energy_Quot__Photon_200MultiJet->SetMarkerStyle(28); Energy_Quot__Photon_200MultiJet->SetMarkerColor(32);
  Energy_Quot__Photon_200MultiJet->SetLineWidth(4);  Energy_Quot__Photon_200MultiJet->Draw("Esame");      Energy_Quot__Photon_200MultiJet->SetLineColor(32);
  Leg->Draw(); legend->Draw();  Energy_Quotient__Photon_200Jet->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__Photon-200Jet.png"); Energy_Quotient__Photon_200Jet->Close();


  TCanvas* Energy_Quotient__Electron_Jet = new TCanvas("Energy_Quotient__Electron_Jet","Energy_Quotient__Electron_Jet",10,10,1920,1080);
  Energy_Quotient__Electron_Jet->SetFillColor(0);  Energy_Quotient__Electron_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  Energy_Quot__Electron_FJ->SetTitle("Cociente Energ#acute{i}a  Electr#acute{o}n / Jet; Energ#acute{i}a^{Electron} / Energ#acute{i}a^{Jet}; U. A.");
  Energy_Quot__Electron_FJ->GetXaxis()->SetLabelSize(0.05); Energy_Quot__Electron_FJ->GetYaxis()->SetLabelSize(0.05);
  Energy_Quot__Electron_FJ->GetXaxis()->SetTitleSize(0.05); Energy_Quot__Electron_FJ->GetYaxis()->SetTitleSize(0.05);
  Energy_Quot__Electron_FJ->GetXaxis()->SetTitleOffset(1.0);Energy_Quot__Electron_FJ->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Energy_Quot__Electron_FJ->Rebin(); Energy_Quot__Electron_FJ->SetAxisRange(0.0, 1.09, "X");
  Energy_Quot__Electron_FJ->SetMarkerSize(4);Energy_Quot__Electron_FJ->SetMarkerStyle(21); Energy_Quot__Electron_FJ->SetMarkerColor(14);
  Energy_Quot__Electron_FJ->DrawCopy("P");   Energy_Quot__Electron_FJ->SetMarkerStyle(25); Energy_Quot__Electron_FJ->SetMarkerColor(1);
  Energy_Quot__Electron_FJ->SetLineWidth(4); Energy_Quot__Electron_FJ->Draw("Esame");      Energy_Quot__Electron_FJ->SetLineColor(1);
  Energy_Quot__Electron_Jet->Rebin();
  Energy_Quot__Electron_Jet->SetMarkerSize(4); Energy_Quot__Electron_Jet->SetMarkerStyle(23); Energy_Quot__Electron_Jet->SetMarkerColor(42);
  Energy_Quot__Electron_Jet->DrawCopy("Psame");Energy_Quot__Electron_Jet->SetMarkerStyle(32); Energy_Quot__Electron_Jet->SetMarkerColor(2);
  Energy_Quot__Electron_Jet->SetLineWidth(4);  Energy_Quot__Electron_Jet->Draw("Esame");      Energy_Quot__Electron_Jet->SetLineColor(2);
  Energy_Quot__Electron_BTag->Rebin();
  Energy_Quot__Electron_BTag->SetMarkerSize(4); Energy_Quot__Electron_BTag->SetMarkerStyle(22); Energy_Quot__Electron_BTag->SetMarkerColor(33);
  Energy_Quot__Electron_BTag->DrawCopy("Psame");Energy_Quot__Electron_BTag->SetMarkerStyle(26); Energy_Quot__Electron_BTag->SetMarkerColor(4);
  Energy_Quot__Electron_BTag->SetLineWidth(4);  Energy_Quot__Electron_BTag->Draw("Esame");      Energy_Quot__Electron_BTag->SetLineColor(4);
  Energy_Quot__Electron_MinBias->Rebin();
  Energy_Quot__Electron_MinBias->SetMarkerSize(4); Energy_Quot__Electron_MinBias->SetMarkerStyle(20); Energy_Quot__Electron_MinBias->SetMarkerColor(5);
  Energy_Quot__Electron_MinBias->DrawCopy("Psame");Energy_Quot__Electron_MinBias->SetMarkerStyle(24); Energy_Quot__Electron_MinBias->SetMarkerColor(41);
  Energy_Quot__Electron_MinBias->SetLineWidth(4);  Energy_Quot__Electron_MinBias->Draw("Esame");      Energy_Quot__Electron_MinBias->SetLineColor(41);
  Energy_Quot__Electron_MultiJet->Rebin();
  Energy_Quot__Electron_MultiJet->SetMarkerSize(4); Energy_Quot__Electron_MultiJet->SetMarkerStyle(34); Energy_Quot__Electron_MultiJet->SetMarkerColor(8);
  Energy_Quot__Electron_MultiJet->DrawCopy("Psame");Energy_Quot__Electron_MultiJet->SetMarkerStyle(28); Energy_Quot__Electron_MultiJet->SetMarkerColor(32);
  Energy_Quot__Electron_MultiJet->SetLineWidth(4);  Energy_Quot__Electron_MultiJet->Draw("Esame");      Energy_Quot__Electron_MultiJet->SetLineColor(32);
  Leg->Draw(); legend->Draw();  Energy_Quotient__Electron_Jet->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__Electron-Jet.png"); Energy_Quotient__Electron_Jet->Close();

  TCanvas* Energy_Quotient__Electron_Jet200 = new TCanvas("Energy_Quotient__Electron_Jet200","Energy_Quotient__Electron_Jet200",10,10,1920,1080);
  Energy_Quotient__Electron_Jet200->SetFillColor(0);  Energy_Quotient__Electron_Jet200->SetFrameBorderMode(0);  gPad->SetLogy();
  Energy_Quot__Electron_FJ200->SetTitle("Cociente Energ#acute{i}a  Electr#acute{o}n/Jet  (Energ#acute{i}a^{Jet} < 200); Energ#acute{i}a^{Electron} / Energ#acute{i}a^{Jet}; U. A.");
  Energy_Quot__Electron_FJ200->GetXaxis()->SetLabelSize(0.05); Energy_Quot__Electron_FJ200->GetYaxis()->SetLabelSize(0.05);
  Energy_Quot__Electron_FJ200->GetXaxis()->SetTitleSize(0.05); Energy_Quot__Electron_FJ200->GetYaxis()->SetTitleSize(0.05);
  Energy_Quot__Electron_FJ200->GetXaxis()->SetTitleOffset(1.0);Energy_Quot__Electron_FJ200->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Energy_Quot__Electron_FJ200->Rebin(); Energy_Quot__Electron_FJ200->SetAxisRange(0.0, 1.09, "X");
  Energy_Quot__Electron_FJ200->SetMarkerSize(4);Energy_Quot__Electron_FJ200->SetMarkerStyle(21); Energy_Quot__Electron_FJ200->SetMarkerColor(14);
  Energy_Quot__Electron_FJ200->DrawCopy("P");   Energy_Quot__Electron_FJ200->SetMarkerStyle(25); Energy_Quot__Electron_FJ200->SetMarkerColor(1);
  Energy_Quot__Electron_FJ200->SetLineWidth(4); Energy_Quot__Electron_FJ200->Draw("Esame");      Energy_Quot__Electron_FJ200->SetLineColor(1);
  Energy_Quot__Electron_Jet200->Rebin();
  Energy_Quot__Electron_Jet200->SetMarkerSize(4); Energy_Quot__Electron_Jet200->SetMarkerStyle(23); Energy_Quot__Electron_Jet200->SetMarkerColor(42);
  Energy_Quot__Electron_Jet200->DrawCopy("Psame");Energy_Quot__Electron_Jet200->SetMarkerStyle(32); Energy_Quot__Electron_Jet200->SetMarkerColor(2);
  Energy_Quot__Electron_Jet200->SetLineWidth(4);  Energy_Quot__Electron_Jet200->Draw("Esame");      Energy_Quot__Electron_Jet200->SetLineColor(2);
  Energy_Quot__Electron_BTag200->Rebin();
  Energy_Quot__Electron_BTag200->SetMarkerSize(4); Energy_Quot__Electron_BTag200->SetMarkerStyle(22); Energy_Quot__Electron_BTag200->SetMarkerColor(33);
  Energy_Quot__Electron_BTag200->DrawCopy("Psame");Energy_Quot__Electron_BTag200->SetMarkerStyle(26); Energy_Quot__Electron_BTag200->SetMarkerColor(4);
  Energy_Quot__Electron_BTag200->SetLineWidth(4);  Energy_Quot__Electron_BTag200->Draw("Esame");      Energy_Quot__Electron_BTag200->SetLineColor(4);
  Energy_Quot__Electron_MinBias200->Rebin();
  Energy_Quot__Electron_MinBias200->SetMarkerSize(4); Energy_Quot__Electron_MinBias200->SetMarkerStyle(20); Energy_Quot__Electron_MinBias200->SetMarkerColor(5);
  Energy_Quot__Electron_MinBias200->DrawCopy("Psame");Energy_Quot__Electron_MinBias200->SetMarkerStyle(24); Energy_Quot__Electron_MinBias200->SetMarkerColor(41);
  Energy_Quot__Electron_MinBias200->SetLineWidth(4);  Energy_Quot__Electron_MinBias200->Draw("Esame");      Energy_Quot__Electron_MinBias200->SetLineColor(41);
  Energy_Quot__Electron_MultiJet200->Rebin();
  Energy_Quot__Electron_MultiJet200->SetMarkerSize(4); Energy_Quot__Electron_MultiJet200->SetMarkerStyle(34); Energy_Quot__Electron_MultiJet200->SetMarkerColor(8);
  Energy_Quot__Electron_MultiJet200->DrawCopy("Psame");Energy_Quot__Electron_MultiJet200->SetMarkerStyle(28); Energy_Quot__Electron_MultiJet200->SetMarkerColor(32);
  Energy_Quot__Electron_MultiJet200->SetLineWidth(4);  Energy_Quot__Electron_MultiJet200->Draw("Esame");      Energy_Quot__Electron_MultiJet200->SetLineColor(32);
  Leg->Draw(); legend->Draw();  Energy_Quotient__Electron_Jet200->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__Electron-Jet200.png"); Energy_Quotient__Electron_Jet200->Close();

  TCanvas* Energy_Quotient__Electron_200Jet = new TCanvas("Energy_Quotient__Electron_200Jet","Energy_Quotient__Electron_200Jet",10,10,1920,1080);
  Energy_Quotient__Electron_200Jet->SetFillColor(0);  Energy_Quotient__Electron_200Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  Energy_Quot__Electron_200FJ->SetTitle("Cociente Energ#acute{i}a  Electr#acute{o}n/Jet  (Energ#acute{i}a^{Jet} > 200); Energ#acute{i}a^{Electron} / Energ#acute{i}a^{Jet}; U. A.");
  Energy_Quot__Electron_200FJ->GetXaxis()->SetLabelSize(0.05); Energy_Quot__Electron_200FJ->GetYaxis()->SetLabelSize(0.05);
  Energy_Quot__Electron_200FJ->GetXaxis()->SetTitleSize(0.05); Energy_Quot__Electron_200FJ->GetYaxis()->SetTitleSize(0.05);
  Energy_Quot__Electron_200FJ->GetXaxis()->SetTitleOffset(1.0);Energy_Quot__Electron_200FJ->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Energy_Quot__Electron_200FJ->Rebin(); Energy_Quot__Electron_200FJ->SetAxisRange(0.0, 1.09, "X");
  Energy_Quot__Electron_200FJ->SetMarkerSize(4);Energy_Quot__Electron_200FJ->SetMarkerStyle(21); Energy_Quot__Electron_200FJ->SetMarkerColor(14);
  Energy_Quot__Electron_200FJ->DrawCopy("P");   Energy_Quot__Electron_200FJ->SetMarkerStyle(25); Energy_Quot__Electron_200FJ->SetMarkerColor(1);
  Energy_Quot__Electron_200FJ->SetLineWidth(4); Energy_Quot__Electron_200FJ->Draw("Esame");      Energy_Quot__Electron_200FJ->SetLineColor(1);
  Energy_Quot__Electron_200Jet->Rebin();
  Energy_Quot__Electron_200Jet->SetMarkerSize(4); Energy_Quot__Electron_200Jet->SetMarkerStyle(23); Energy_Quot__Electron_200Jet->SetMarkerColor(42);
  Energy_Quot__Electron_200Jet->DrawCopy("Psame");Energy_Quot__Electron_200Jet->SetMarkerStyle(32); Energy_Quot__Electron_200Jet->SetMarkerColor(2);
  Energy_Quot__Electron_200Jet->SetLineWidth(4);  Energy_Quot__Electron_200Jet->Draw("Esame");      Energy_Quot__Electron_200Jet->SetLineColor(2);
  Energy_Quot__Electron_200BTag->Rebin();
  Energy_Quot__Electron_200BTag->SetMarkerSize(4); Energy_Quot__Electron_200BTag->SetMarkerStyle(22); Energy_Quot__Electron_200BTag->SetMarkerColor(33);
  Energy_Quot__Electron_200BTag->DrawCopy("Psame");Energy_Quot__Electron_200BTag->SetMarkerStyle(26); Energy_Quot__Electron_200BTag->SetMarkerColor(4);
  Energy_Quot__Electron_200BTag->SetLineWidth(4);  Energy_Quot__Electron_200BTag->Draw("Esame");      Energy_Quot__Electron_200BTag->SetLineColor(4);
  Energy_Quot__Electron_200MinBias->Rebin();
  Energy_Quot__Electron_200MinBias->SetMarkerSize(4); Energy_Quot__Electron_200MinBias->SetMarkerStyle(20); Energy_Quot__Electron_200MinBias->SetMarkerColor(5);
  Energy_Quot__Electron_200MinBias->DrawCopy("Psame");Energy_Quot__Electron_200MinBias->SetMarkerStyle(24); Energy_Quot__Electron_200MinBias->SetMarkerColor(41);
  Energy_Quot__Electron_200MinBias->SetLineWidth(4);  Energy_Quot__Electron_200MinBias->Draw("Esame");      Energy_Quot__Electron_200MinBias->SetLineColor(41);
  Energy_Quot__Electron_200MultiJet->Rebin();
  Energy_Quot__Electron_200MultiJet->SetMarkerSize(4); Energy_Quot__Electron_200MultiJet->SetMarkerStyle(34); Energy_Quot__Electron_200MultiJet->SetMarkerColor(8);
  Energy_Quot__Electron_200MultiJet->DrawCopy("Psame");Energy_Quot__Electron_200MultiJet->SetMarkerStyle(28); Energy_Quot__Electron_200MultiJet->SetMarkerColor(32);
  Energy_Quot__Electron_200MultiJet->SetLineWidth(4);  Energy_Quot__Electron_200MultiJet->Draw("Esame");      Energy_Quot__Electron_200MultiJet->SetLineColor(32);
  Leg->Draw(); legend->Draw();  Energy_Quotient__Electron_200Jet->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__Electron-200Jet.png"); Energy_Quotient__Electron_200Jet->Close();


  TCanvas* Energy_Quotient__NeutralHad_Jet = new TCanvas("Energy_Quotient__NeutralHad_Jet","Energy_Quotient__NeutralHad_Jet",10,10,1920,1080);
  Energy_Quotient__NeutralHad_Jet->SetFillColor(0);  Energy_Quotient__NeutralHad_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  Energy_Quot__NeutralHad_FJ->SetTitle("Cociente Energ#acute{i}a  Hadr#acute{o}nNeutro/Jet; Energ#acute{i}a^{NeutralHad} / Energ#acute{i}a^{Jet}; U. A.");
  Energy_Quot__NeutralHad_FJ->GetXaxis()->SetLabelSize(0.05); Energy_Quot__NeutralHad_FJ->GetYaxis()->SetLabelSize(0.05);
  Energy_Quot__NeutralHad_FJ->GetXaxis()->SetTitleSize(0.05); Energy_Quot__NeutralHad_FJ->GetYaxis()->SetTitleSize(0.05);
  Energy_Quot__NeutralHad_FJ->GetXaxis()->SetTitleOffset(1.0);Energy_Quot__NeutralHad_FJ->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Energy_Quot__NeutralHad_FJ->Rebin(); Energy_Quot__NeutralHad_FJ->SetAxisRange(0.0, 1.09, "X");
  Energy_Quot__NeutralHad_FJ->SetMarkerSize(4);Energy_Quot__NeutralHad_FJ->SetMarkerStyle(21); Energy_Quot__NeutralHad_FJ->SetMarkerColor(14);
  Energy_Quot__NeutralHad_FJ->DrawCopy("P");   Energy_Quot__NeutralHad_FJ->SetMarkerStyle(25); Energy_Quot__NeutralHad_FJ->SetMarkerColor(1);
  Energy_Quot__NeutralHad_FJ->SetLineWidth(4); Energy_Quot__NeutralHad_FJ->Draw("Esame");      Energy_Quot__NeutralHad_FJ->SetLineColor(1);
  Energy_Quot__NeutralHad_Jet->Rebin();
  Energy_Quot__NeutralHad_Jet->SetMarkerSize(4); Energy_Quot__NeutralHad_Jet->SetMarkerStyle(23); Energy_Quot__NeutralHad_Jet->SetMarkerColor(42);
  Energy_Quot__NeutralHad_Jet->DrawCopy("Psame");Energy_Quot__NeutralHad_Jet->SetMarkerStyle(32); Energy_Quot__NeutralHad_Jet->SetMarkerColor(2);
  Energy_Quot__NeutralHad_Jet->SetLineWidth(4);  Energy_Quot__NeutralHad_Jet->Draw("Esame");      Energy_Quot__NeutralHad_Jet->SetLineColor(2);
  Energy_Quot__NeutralHad_BTag->Rebin();
  Energy_Quot__NeutralHad_BTag->SetMarkerSize(4); Energy_Quot__NeutralHad_BTag->SetMarkerStyle(22); Energy_Quot__NeutralHad_BTag->SetMarkerColor(33);
  Energy_Quot__NeutralHad_BTag->DrawCopy("Psame");Energy_Quot__NeutralHad_BTag->SetMarkerStyle(26); Energy_Quot__NeutralHad_BTag->SetMarkerColor(4);
  Energy_Quot__NeutralHad_BTag->SetLineWidth(4);  Energy_Quot__NeutralHad_BTag->Draw("Esame");      Energy_Quot__NeutralHad_BTag->SetLineColor(4);
  Energy_Quot__NeutralHad_MinBias->Rebin();
  Energy_Quot__NeutralHad_MinBias->SetMarkerSize(4); Energy_Quot__NeutralHad_MinBias->SetMarkerStyle(20); Energy_Quot__NeutralHad_MinBias->SetMarkerColor(5);
  Energy_Quot__NeutralHad_MinBias->DrawCopy("Psame");Energy_Quot__NeutralHad_MinBias->SetMarkerStyle(24); Energy_Quot__NeutralHad_MinBias->SetMarkerColor(41);
  Energy_Quot__NeutralHad_MinBias->SetLineWidth(4);  Energy_Quot__NeutralHad_MinBias->Draw("Esame");      Energy_Quot__NeutralHad_MinBias->SetLineColor(41);
  Energy_Quot__NeutralHad_MultiJet->Rebin();
  Energy_Quot__NeutralHad_MultiJet->SetMarkerSize(4); Energy_Quot__NeutralHad_MultiJet->SetMarkerStyle(34); Energy_Quot__NeutralHad_MultiJet->SetMarkerColor(8);
  Energy_Quot__NeutralHad_MultiJet->DrawCopy("Psame");Energy_Quot__NeutralHad_MultiJet->SetMarkerStyle(28); Energy_Quot__NeutralHad_MultiJet->SetMarkerColor(32);
  Energy_Quot__NeutralHad_MultiJet->SetLineWidth(4);  Energy_Quot__NeutralHad_MultiJet->Draw("Esame");      Energy_Quot__NeutralHad_MultiJet->SetLineColor(32);
  Leg->Draw(); legend->Draw();  Energy_Quotient__NeutralHad_Jet->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__NeutralHad-Jet.png"); Energy_Quotient__NeutralHad_Jet->Close();

  TCanvas* Energy_Quotient__NeutralHad_Jet200 = new TCanvas("Energy_Quotient__NeutralHad_Jet200","Energy_Quotient__NeutralHad_Jet200",10,10,1920,1080);
  Energy_Quotient__NeutralHad_Jet200->SetFillColor(0);  Energy_Quotient__NeutralHad_Jet200->SetFrameBorderMode(0);  gPad->SetLogy();
  Energy_Quot__NeutralHad_FJ200->SetTitle("Cociente Energ#acute{i}a  Hadr#acute{o}nNeutro/Jet  (Energ#acute{i}a^{Jet} < 200); Energ#acute{i}a^{NeutralHad} / Energ#acute{i}a^{Jet}; U. A.");
  Energy_Quot__NeutralHad_FJ200->GetXaxis()->SetLabelSize(0.05); Energy_Quot__NeutralHad_FJ200->GetYaxis()->SetLabelSize(0.05);
  Energy_Quot__NeutralHad_FJ200->GetXaxis()->SetTitleSize(0.05); Energy_Quot__NeutralHad_FJ200->GetYaxis()->SetTitleSize(0.05);
  Energy_Quot__NeutralHad_FJ200->GetXaxis()->SetTitleOffset(1.0);Energy_Quot__NeutralHad_FJ200->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Energy_Quot__NeutralHad_FJ200->Rebin(); Energy_Quot__NeutralHad_FJ200->SetAxisRange(0.0, 1.09, "X");
  Energy_Quot__NeutralHad_FJ200->SetMarkerSize(4);Energy_Quot__NeutralHad_FJ200->SetMarkerStyle(21); Energy_Quot__NeutralHad_FJ200->SetMarkerColor(14);
  Energy_Quot__NeutralHad_FJ200->DrawCopy("P");   Energy_Quot__NeutralHad_FJ200->SetMarkerStyle(25); Energy_Quot__NeutralHad_FJ200->SetMarkerColor(1);
  Energy_Quot__NeutralHad_FJ200->SetLineWidth(4); Energy_Quot__NeutralHad_FJ200->Draw("Esame");      Energy_Quot__NeutralHad_FJ200->SetLineColor(1);
  Energy_Quot__NeutralHad_Jet200->Rebin();
  Energy_Quot__NeutralHad_Jet200->SetMarkerSize(4); Energy_Quot__NeutralHad_Jet200->SetMarkerStyle(23); Energy_Quot__NeutralHad_Jet200->SetMarkerColor(42);
  Energy_Quot__NeutralHad_Jet200->DrawCopy("Psame");Energy_Quot__NeutralHad_Jet200->SetMarkerStyle(32); Energy_Quot__NeutralHad_Jet200->SetMarkerColor(2);
  Energy_Quot__NeutralHad_Jet200->SetLineWidth(4);  Energy_Quot__NeutralHad_Jet200->Draw("Esame");      Energy_Quot__NeutralHad_Jet200->SetLineColor(2);
  Energy_Quot__NeutralHad_BTag200->Rebin();
  Energy_Quot__NeutralHad_BTag200->SetMarkerSize(4); Energy_Quot__NeutralHad_BTag200->SetMarkerStyle(22); Energy_Quot__NeutralHad_BTag200->SetMarkerColor(33);
  Energy_Quot__NeutralHad_BTag200->DrawCopy("Psame");Energy_Quot__NeutralHad_BTag200->SetMarkerStyle(26); Energy_Quot__NeutralHad_BTag200->SetMarkerColor(4);
  Energy_Quot__NeutralHad_BTag200->SetLineWidth(4);  Energy_Quot__NeutralHad_BTag200->Draw("Esame");      Energy_Quot__NeutralHad_BTag200->SetLineColor(4);
  Energy_Quot__NeutralHad_MinBias200->Rebin();
  Energy_Quot__NeutralHad_MinBias200->SetMarkerSize(4); Energy_Quot__NeutralHad_MinBias200->SetMarkerStyle(20); Energy_Quot__NeutralHad_MinBias200->SetMarkerColor(5);
  Energy_Quot__NeutralHad_MinBias200->DrawCopy("Psame");Energy_Quot__NeutralHad_MinBias200->SetMarkerStyle(24); Energy_Quot__NeutralHad_MinBias200->SetMarkerColor(41);
  Energy_Quot__NeutralHad_MinBias200->SetLineWidth(4);  Energy_Quot__NeutralHad_MinBias200->Draw("Esame");      Energy_Quot__NeutralHad_MinBias200->SetLineColor(41);
  Energy_Quot__NeutralHad_MultiJet200->Rebin();
  Energy_Quot__NeutralHad_MultiJet200->SetMarkerSize(4); Energy_Quot__NeutralHad_MultiJet200->SetMarkerStyle(34); Energy_Quot__NeutralHad_MultiJet200->SetMarkerColor(8);
  Energy_Quot__NeutralHad_MultiJet200->DrawCopy("Psame");Energy_Quot__NeutralHad_MultiJet200->SetMarkerStyle(28); Energy_Quot__NeutralHad_MultiJet200->SetMarkerColor(32);
  Energy_Quot__NeutralHad_MultiJet200->SetLineWidth(4);  Energy_Quot__NeutralHad_MultiJet200->Draw("Esame");      Energy_Quot__NeutralHad_MultiJet200->SetLineColor(32);
  Leg->Draw(); legend->Draw();  Energy_Quotient__NeutralHad_Jet200->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__NeutralHad-Jet200.png"); Energy_Quotient__NeutralHad_Jet200->Close();

  TCanvas* Energy_Quotient__NeutralHad_200Jet = new TCanvas("Energy_Quotient__NeutralHad_200Jet","Energy_Quotient__NeutralHad_200Jet",10,10,1920,1080);
  Energy_Quotient__NeutralHad_200Jet->SetFillColor(0);  Energy_Quotient__NeutralHad_200Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  Energy_Quot__NeutralHad_200FJ->SetTitle("Cociente Energ#acute{i}a  Hadr#acute{o}nNeutro/Jet  (Energ#acute{i}a^{Jet} > 200); Energ#acute{i}a^{NeutralHad} / Energ#acute{i}a^{Jet}; U. A.");
  Energy_Quot__NeutralHad_200FJ->GetXaxis()->SetLabelSize(0.05); Energy_Quot__NeutralHad_200FJ->GetYaxis()->SetLabelSize(0.05);
  Energy_Quot__NeutralHad_200FJ->GetXaxis()->SetTitleSize(0.05); Energy_Quot__NeutralHad_200FJ->GetYaxis()->SetTitleSize(0.05);
  Energy_Quot__NeutralHad_200FJ->GetXaxis()->SetTitleOffset(1.0);Energy_Quot__NeutralHad_200FJ->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Energy_Quot__NeutralHad_200FJ->Rebin(); Energy_Quot__NeutralHad_200FJ->SetAxisRange(0.0, 1.09, "X");
  Energy_Quot__NeutralHad_200FJ->SetMarkerSize(4);Energy_Quot__NeutralHad_200FJ->SetMarkerStyle(21); Energy_Quot__NeutralHad_200FJ->SetMarkerColor(14);
  Energy_Quot__NeutralHad_200FJ->DrawCopy("P");   Energy_Quot__NeutralHad_200FJ->SetMarkerStyle(25); Energy_Quot__NeutralHad_200FJ->SetMarkerColor(1);
  Energy_Quot__NeutralHad_200FJ->SetLineWidth(4); Energy_Quot__NeutralHad_200FJ->Draw("Esame");      Energy_Quot__NeutralHad_200FJ->SetLineColor(1);
  Energy_Quot__NeutralHad_200Jet->Rebin();
  Energy_Quot__NeutralHad_200Jet->SetMarkerSize(4); Energy_Quot__NeutralHad_200Jet->SetMarkerStyle(23); Energy_Quot__NeutralHad_200Jet->SetMarkerColor(42);
  Energy_Quot__NeutralHad_200Jet->DrawCopy("Psame");Energy_Quot__NeutralHad_200Jet->SetMarkerStyle(32); Energy_Quot__NeutralHad_200Jet->SetMarkerColor(2);
  Energy_Quot__NeutralHad_200Jet->SetLineWidth(4);  Energy_Quot__NeutralHad_200Jet->Draw("Esame");      Energy_Quot__NeutralHad_200Jet->SetLineColor(2);
  Energy_Quot__NeutralHad_200BTag->Rebin();
  Energy_Quot__NeutralHad_200BTag->SetMarkerSize(4); Energy_Quot__NeutralHad_200BTag->SetMarkerStyle(22); Energy_Quot__NeutralHad_200BTag->SetMarkerColor(33);
  Energy_Quot__NeutralHad_200BTag->DrawCopy("Psame");Energy_Quot__NeutralHad_200BTag->SetMarkerStyle(26); Energy_Quot__NeutralHad_200BTag->SetMarkerColor(4);
  Energy_Quot__NeutralHad_200BTag->SetLineWidth(4);  Energy_Quot__NeutralHad_200BTag->Draw("Esame");      Energy_Quot__NeutralHad_200BTag->SetLineColor(4);
  Energy_Quot__NeutralHad_200MinBias->Rebin();
  Energy_Quot__NeutralHad_200MinBias->SetMarkerSize(4); Energy_Quot__NeutralHad_200MinBias->SetMarkerStyle(20); Energy_Quot__NeutralHad_200MinBias->SetMarkerColor(5);
  Energy_Quot__NeutralHad_200MinBias->DrawCopy("Psame");Energy_Quot__NeutralHad_200MinBias->SetMarkerStyle(24); Energy_Quot__NeutralHad_200MinBias->SetMarkerColor(41);
  Energy_Quot__NeutralHad_200MinBias->SetLineWidth(4);  Energy_Quot__NeutralHad_200MinBias->Draw("Esame");      Energy_Quot__NeutralHad_200MinBias->SetLineColor(41);
  Energy_Quot__NeutralHad_200MultiJet->Rebin();
  Energy_Quot__NeutralHad_200MultiJet->SetMarkerSize(4); Energy_Quot__NeutralHad_200MultiJet->SetMarkerStyle(34); Energy_Quot__NeutralHad_200MultiJet->SetMarkerColor(8);
  Energy_Quot__NeutralHad_200MultiJet->DrawCopy("Psame");Energy_Quot__NeutralHad_200MultiJet->SetMarkerStyle(28); Energy_Quot__NeutralHad_200MultiJet->SetMarkerColor(32);
  Energy_Quot__NeutralHad_200MultiJet->SetLineWidth(4);  Energy_Quot__NeutralHad_200MultiJet->Draw("Esame");      Energy_Quot__NeutralHad_200MultiJet->SetLineColor(32);
  Leg->Draw(); legend->Draw();  Energy_Quotient__NeutralHad_200Jet->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__NeutralHad-200Jet.png"); Energy_Quotient__NeutralHad_200Jet->Close();


  TCanvas* Energy_Quotient__ChargedHad_Jet = new TCanvas("Energy_Quotient__ChargedHad_Jet","Energy_Quotient__ChargedHad_Jet",10,10,1920,1080);
  Energy_Quotient__ChargedHad_Jet->SetFillColor(0);  Energy_Quotient__ChargedHad_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  Energy_Quot__ChargedHad_FJ->SetTitle("Cociente Energ#acute{i}a  Hadr#acute{o}nCargado/Jet; Energ#acute{i}a^{ChargedHad} / Energ#acute{i}a^{Jet}; U. A.");
  Energy_Quot__ChargedHad_FJ->GetXaxis()->SetLabelSize(0.05); Energy_Quot__ChargedHad_FJ->GetYaxis()->SetLabelSize(0.05);
  Energy_Quot__ChargedHad_FJ->GetXaxis()->SetTitleSize(0.05); Energy_Quot__ChargedHad_FJ->GetYaxis()->SetTitleSize(0.05);
  Energy_Quot__ChargedHad_FJ->GetXaxis()->SetTitleOffset(1.0);Energy_Quot__ChargedHad_FJ->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Energy_Quot__ChargedHad_FJ->Rebin(); Energy_Quot__ChargedHad_FJ->SetAxisRange(0.0, 1.09, "X");
  Energy_Quot__ChargedHad_FJ->SetMarkerSize(4);Energy_Quot__ChargedHad_FJ->SetMarkerStyle(21); Energy_Quot__ChargedHad_FJ->SetMarkerColor(14);
  Energy_Quot__ChargedHad_FJ->DrawCopy("P");   Energy_Quot__ChargedHad_FJ->SetMarkerStyle(25); Energy_Quot__ChargedHad_FJ->SetMarkerColor(1);
  Energy_Quot__ChargedHad_FJ->SetLineWidth(4); Energy_Quot__ChargedHad_FJ->Draw("Esame");      Energy_Quot__ChargedHad_FJ->SetLineColor(1);
  Energy_Quot__ChargedHad_Jet->Rebin();
  Energy_Quot__ChargedHad_Jet->SetMarkerSize(4); Energy_Quot__ChargedHad_Jet->SetMarkerStyle(23); Energy_Quot__ChargedHad_Jet->SetMarkerColor(42);
  Energy_Quot__ChargedHad_Jet->DrawCopy("Psame");Energy_Quot__ChargedHad_Jet->SetMarkerStyle(32); Energy_Quot__ChargedHad_Jet->SetMarkerColor(2);
  Energy_Quot__ChargedHad_Jet->SetLineWidth(4);  Energy_Quot__ChargedHad_Jet->Draw("Esame");      Energy_Quot__ChargedHad_Jet->SetLineColor(2);
  Energy_Quot__ChargedHad_BTag->Rebin();
  Energy_Quot__ChargedHad_BTag->SetMarkerSize(4); Energy_Quot__ChargedHad_BTag->SetMarkerStyle(22); Energy_Quot__ChargedHad_BTag->SetMarkerColor(33);
  Energy_Quot__ChargedHad_BTag->DrawCopy("Psame");Energy_Quot__ChargedHad_BTag->SetMarkerStyle(26); Energy_Quot__ChargedHad_BTag->SetMarkerColor(4);
  Energy_Quot__ChargedHad_BTag->SetLineWidth(4);  Energy_Quot__ChargedHad_BTag->Draw("Esame");      Energy_Quot__ChargedHad_BTag->SetLineColor(4);
  Energy_Quot__ChargedHad_MinBias->Rebin();
  Energy_Quot__ChargedHad_MinBias->SetMarkerSize(4); Energy_Quot__ChargedHad_MinBias->SetMarkerStyle(20); Energy_Quot__ChargedHad_MinBias->SetMarkerColor(5);
  Energy_Quot__ChargedHad_MinBias->DrawCopy("Psame");Energy_Quot__ChargedHad_MinBias->SetMarkerStyle(24); Energy_Quot__ChargedHad_MinBias->SetMarkerColor(41);
  Energy_Quot__ChargedHad_MinBias->SetLineWidth(4);  Energy_Quot__ChargedHad_MinBias->Draw("Esame");      Energy_Quot__ChargedHad_MinBias->SetLineColor(41);
  Energy_Quot__ChargedHad_MultiJet->Rebin();
  Energy_Quot__ChargedHad_MultiJet->SetMarkerSize(4); Energy_Quot__ChargedHad_MultiJet->SetMarkerStyle(34); Energy_Quot__ChargedHad_MultiJet->SetMarkerColor(8);
  Energy_Quot__ChargedHad_MultiJet->DrawCopy("Psame");Energy_Quot__ChargedHad_MultiJet->SetMarkerStyle(28); Energy_Quot__ChargedHad_MultiJet->SetMarkerColor(32);
  Energy_Quot__ChargedHad_MultiJet->SetLineWidth(4);  Energy_Quot__ChargedHad_MultiJet->Draw("Esame");      Energy_Quot__ChargedHad_MultiJet->SetLineColor(32);
  Leg->Draw(); legend->Draw();  Energy_Quotient__ChargedHad_Jet->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__ChargedHad-Jet.png"); Energy_Quotient__ChargedHad_Jet->Close();

  TCanvas* Energy_Quotient__ChargedHad_Jet200 = new TCanvas("Energy_Quotient__ChargedHad_Jet200","Energy_Quotient__ChargedHad_Jet200",10,10,1920,1080);
  Energy_Quotient__ChargedHad_Jet200->SetFillColor(0);  Energy_Quotient__ChargedHad_Jet200->SetFrameBorderMode(0);  gPad->SetLogy();
  Energy_Quot__ChargedHad_FJ200->SetTitle("Cociente Energ#acute{i}a  Hadr#acute{o}nCargado/Jet  (Energ#acute{i}a^{Jet} < 200); Energ#acute{i}a^{ChargedHad} / Energ#acute{i}a^{Jet}; U. A.");
  Energy_Quot__ChargedHad_FJ200->GetXaxis()->SetLabelSize(0.05); Energy_Quot__ChargedHad_FJ200->GetYaxis()->SetLabelSize(0.05);
  Energy_Quot__ChargedHad_FJ200->GetXaxis()->SetTitleSize(0.05); Energy_Quot__ChargedHad_FJ200->GetYaxis()->SetTitleSize(0.05);
  Energy_Quot__ChargedHad_FJ200->GetXaxis()->SetTitleOffset(1.0);Energy_Quot__ChargedHad_FJ200->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Energy_Quot__ChargedHad_FJ200->Rebin(); Energy_Quot__ChargedHad_FJ200->SetAxisRange(0.0, 1.09, "X");
  Energy_Quot__ChargedHad_FJ200->SetMarkerSize(4);Energy_Quot__ChargedHad_FJ200->SetMarkerStyle(21); Energy_Quot__ChargedHad_FJ200->SetMarkerColor(14);
  Energy_Quot__ChargedHad_FJ200->DrawCopy("P");   Energy_Quot__ChargedHad_FJ200->SetMarkerStyle(25); Energy_Quot__ChargedHad_FJ200->SetMarkerColor(1);
  Energy_Quot__ChargedHad_FJ200->SetLineWidth(4); Energy_Quot__ChargedHad_FJ200->Draw("Esame");      Energy_Quot__ChargedHad_FJ200->SetLineColor(1);
  Energy_Quot__ChargedHad_Jet200->Rebin();
  Energy_Quot__ChargedHad_Jet200->SetMarkerSize(4); Energy_Quot__ChargedHad_Jet200->SetMarkerStyle(23); Energy_Quot__ChargedHad_Jet200->SetMarkerColor(42);
  Energy_Quot__ChargedHad_Jet200->DrawCopy("Psame");Energy_Quot__ChargedHad_Jet200->SetMarkerStyle(32); Energy_Quot__ChargedHad_Jet200->SetMarkerColor(2);
  Energy_Quot__ChargedHad_Jet200->SetLineWidth(4);  Energy_Quot__ChargedHad_Jet200->Draw("Esame");      Energy_Quot__ChargedHad_Jet200->SetLineColor(2);
  Energy_Quot__ChargedHad_BTag200->Rebin();
  Energy_Quot__ChargedHad_BTag200->SetMarkerSize(4); Energy_Quot__ChargedHad_BTag200->SetMarkerStyle(22); Energy_Quot__ChargedHad_BTag200->SetMarkerColor(33);
  Energy_Quot__ChargedHad_BTag200->DrawCopy("Psame");Energy_Quot__ChargedHad_BTag200->SetMarkerStyle(26); Energy_Quot__ChargedHad_BTag200->SetMarkerColor(4);
  Energy_Quot__ChargedHad_BTag200->SetLineWidth(4);  Energy_Quot__ChargedHad_BTag200->Draw("Esame");      Energy_Quot__ChargedHad_BTag200->SetLineColor(4);
  Energy_Quot__ChargedHad_MinBias200->Rebin();
  Energy_Quot__ChargedHad_MinBias200->SetMarkerSize(4); Energy_Quot__ChargedHad_MinBias200->SetMarkerStyle(20); Energy_Quot__ChargedHad_MinBias200->SetMarkerColor(5);
  Energy_Quot__ChargedHad_MinBias200->DrawCopy("Psame");Energy_Quot__ChargedHad_MinBias200->SetMarkerStyle(24); Energy_Quot__ChargedHad_MinBias200->SetMarkerColor(41);
  Energy_Quot__ChargedHad_MinBias200->SetLineWidth(4);  Energy_Quot__ChargedHad_MinBias200->Draw("Esame");      Energy_Quot__ChargedHad_MinBias200->SetLineColor(41);
  Energy_Quot__ChargedHad_MultiJet200->Rebin();
  Energy_Quot__ChargedHad_MultiJet200->SetMarkerSize(4); Energy_Quot__ChargedHad_MultiJet200->SetMarkerStyle(34); Energy_Quot__ChargedHad_MultiJet200->SetMarkerColor(8);
  Energy_Quot__ChargedHad_MultiJet200->DrawCopy("Psame");Energy_Quot__ChargedHad_MultiJet200->SetMarkerStyle(28); Energy_Quot__ChargedHad_MultiJet200->SetMarkerColor(32);
  Energy_Quot__ChargedHad_MultiJet200->SetLineWidth(4);  Energy_Quot__ChargedHad_MultiJet200->Draw("Esame");      Energy_Quot__ChargedHad_MultiJet200->SetLineColor(32);
  Leg->Draw(); legend->Draw();  Energy_Quotient__ChargedHad_Jet200->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__ChargedHad-Jet200.png"); Energy_Quotient__ChargedHad_Jet200->Close();

  TCanvas* Energy_Quotient__ChargedHad_200Jet = new TCanvas("Energy_Quotient__ChargedHad_200Jet","Energy_Quotient__ChargedHad_200Jet",10,10,1920,1080);
  Energy_Quotient__ChargedHad_200Jet->SetFillColor(0);  Energy_Quotient__ChargedHad_200Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  Energy_Quot__ChargedHad_200FJ->SetTitle("Cociente Energ#acute{i}a  Hadr#acute{o}nCargado/Jet  (Energ#acute{i}a^{Jet} > 200); Energ#acute{i}a^{ChargedHad} / Energ#acute{i}a^{Jet}; U. A.");
  Energy_Quot__ChargedHad_200FJ->GetXaxis()->SetLabelSize(0.05); Energy_Quot__ChargedHad_200FJ->GetYaxis()->SetLabelSize(0.05);
  Energy_Quot__ChargedHad_200FJ->GetXaxis()->SetTitleSize(0.05); Energy_Quot__ChargedHad_200FJ->GetYaxis()->SetTitleSize(0.05);
  Energy_Quot__ChargedHad_200FJ->GetXaxis()->SetTitleOffset(1.0);Energy_Quot__ChargedHad_200FJ->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Energy_Quot__ChargedHad_200FJ->Rebin(); Energy_Quot__ChargedHad_200FJ->SetAxisRange(0.0, 1.09, "X");
  Energy_Quot__ChargedHad_200FJ->SetMarkerSize(4);Energy_Quot__ChargedHad_200FJ->SetMarkerStyle(21); Energy_Quot__ChargedHad_200FJ->SetMarkerColor(14);
  Energy_Quot__ChargedHad_200FJ->DrawCopy("P");   Energy_Quot__ChargedHad_200FJ->SetMarkerStyle(25); Energy_Quot__ChargedHad_200FJ->SetMarkerColor(1);
  Energy_Quot__ChargedHad_200FJ->SetLineWidth(4); Energy_Quot__ChargedHad_200FJ->Draw("Esame");      Energy_Quot__ChargedHad_200FJ->SetLineColor(1);
  Energy_Quot__ChargedHad_200Jet->Rebin();
  Energy_Quot__ChargedHad_200Jet->SetMarkerSize(4); Energy_Quot__ChargedHad_200Jet->SetMarkerStyle(23); Energy_Quot__ChargedHad_200Jet->SetMarkerColor(42);
  Energy_Quot__ChargedHad_200Jet->DrawCopy("Psame");Energy_Quot__ChargedHad_200Jet->SetMarkerStyle(32); Energy_Quot__ChargedHad_200Jet->SetMarkerColor(2);
  Energy_Quot__ChargedHad_200Jet->SetLineWidth(4);  Energy_Quot__ChargedHad_200Jet->Draw("Esame");      Energy_Quot__ChargedHad_200Jet->SetLineColor(2);
  Energy_Quot__ChargedHad_200BTag->Rebin();
  Energy_Quot__ChargedHad_200BTag->SetMarkerSize(4); Energy_Quot__ChargedHad_200BTag->SetMarkerStyle(22); Energy_Quot__ChargedHad_200BTag->SetMarkerColor(33);
  Energy_Quot__ChargedHad_200BTag->DrawCopy("Psame");Energy_Quot__ChargedHad_200BTag->SetMarkerStyle(26); Energy_Quot__ChargedHad_200BTag->SetMarkerColor(4);
  Energy_Quot__ChargedHad_200BTag->SetLineWidth(4);  Energy_Quot__ChargedHad_200BTag->Draw("Esame");      Energy_Quot__ChargedHad_200BTag->SetLineColor(4);
  Energy_Quot__ChargedHad_200MinBias->Rebin();
  Energy_Quot__ChargedHad_200MinBias->SetMarkerSize(4); Energy_Quot__ChargedHad_200MinBias->SetMarkerStyle(20); Energy_Quot__ChargedHad_200MinBias->SetMarkerColor(5);
  Energy_Quot__ChargedHad_200MinBias->DrawCopy("Psame");Energy_Quot__ChargedHad_200MinBias->SetMarkerStyle(24); Energy_Quot__ChargedHad_200MinBias->SetMarkerColor(41);
  Energy_Quot__ChargedHad_200MinBias->SetLineWidth(4);  Energy_Quot__ChargedHad_200MinBias->Draw("Esame");      Energy_Quot__ChargedHad_200MinBias->SetLineColor(41);
  Energy_Quot__ChargedHad_200MultiJet->Rebin();
  Energy_Quot__ChargedHad_200MultiJet->SetMarkerSize(4); Energy_Quot__ChargedHad_200MultiJet->SetMarkerStyle(34); Energy_Quot__ChargedHad_200MultiJet->SetMarkerColor(8);
  Energy_Quot__ChargedHad_200MultiJet->DrawCopy("Psame");Energy_Quot__ChargedHad_200MultiJet->SetMarkerStyle(28); Energy_Quot__ChargedHad_200MultiJet->SetMarkerColor(32);
  Energy_Quot__ChargedHad_200MultiJet->SetLineWidth(4);  Energy_Quot__ChargedHad_200MultiJet->Draw("Esame");      Energy_Quot__ChargedHad_200MultiJet->SetLineColor(32);
  Leg->Draw(); legend->Draw();  Energy_Quotient__ChargedHad_200Jet->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__ChargedHad-200Jet.png"); Energy_Quotient__ChargedHad_200Jet->Close();

}



//###################################################################################################################################################################################

void pTQuotient(){
  // Le damos algo de personalización al las gráficas.
  gROOT->ForceStyle();
  gStyle->SetPadBorderMode(0);    gStyle->SetPadBorderSize(0);
  gStyle->SetPadTopMargin(0.08);  gStyle->SetPadBottomMargin(0.12);
  gStyle->SetPadLeftMargin(0.10); gStyle->SetPadRightMargin(0.10);
  gStyle->SetOptStat(0);          gStyle->SetOptTitle(1);


  //Abrimos el archivo que nos interesa y el árbol que queremos leer.
  TFile *FJFile = new TFile("/home/saksevul/T/PYTHIA/FastJet/ak5FJ.root");
  TFile *JetFile = new TFile("/home/saksevul/T/OpenData/Jet_20000/ak5PF.root");
  TFile *BTagFile = new TFile("/home/saksevul/T/OpenData/BTag_20000/ak5PF.root");
  TFile *MinBiasFile = new TFile("/home/saksevul/T/OpenData/MinBias_20000/ak5PF.root");
  TFile *MultiJetFile = new TFile("/home/saksevul/T/OpenData/MultiJet_20000/ak5PF.root");


  TH1F *Cociente_pT__Muon_ak5FJ =(TH1F*)FJFile->Get("pT_Quotient__Muon-Jet"); Cociente_pT__Muon_ak5FJ->Scale(1.0/Cociente_pT__Muon_ak5FJ->Integral());
  TH1F *Cociente_pT__Muon_ak5PFJet =(TH1F*)JetFile->Get("pT_Quotient__Muon-Jet"); Cociente_pT__Muon_ak5PFJet->Scale(1.0/Cociente_pT__Muon_ak5PFJet->Integral());
  TH1F *Cociente_pT__Muon_ak5PFBTag =(TH1F*)BTagFile->Get("pT_Quotient__Muon-Jet"); Cociente_pT__Muon_ak5PFBTag->Scale(1.0/Cociente_pT__Muon_ak5PFBTag->Integral());
  TH1F *Cociente_pT__Muon_ak5PFMinBias =(TH1F*)MinBiasFile->Get("pT_Quotient__Muon-Jet"); Cociente_pT__Muon_ak5PFMinBias->Scale(1.0/Cociente_pT__Muon_ak5PFMinBias->Integral());
  TH1F *Cociente_pT__Muon_ak5PFMultiJet =(TH1F*)MultiJetFile->Get("pT_Quotient__Muon-Jet"); Cociente_pT__Muon_ak5PFMultiJet->Scale(1.0/Cociente_pT__Muon_ak5PFMultiJet->Integral());

  TH1F *CLON_C_pT__Muon_ak5FJ =(TH1F*)Cociente_pT__Muon_ak5FJ->Clone();
  TH1F *CLON_C_pT__Muon_ak5PFJet =(TH1F*)Cociente_pT__Muon_ak5PFJet->Clone();
  TH1F *CLON_C_pT__Muon_ak5PFBTag =(TH1F*)Cociente_pT__Muon_ak5PFBTag->Clone();
  TH1F *CLON_C_pT__Muon_ak5PFMinBias =(TH1F*)Cociente_pT__Muon_ak5PFMinBias->Clone();
  TH1F *CLON_C_pT__Muon_ak5PFMultiJet =(TH1F*)Cociente_pT__Muon_ak5PFMultiJet->Clone();

  TH1F *Cociente_pT100__1Muon_ak5FJ =(TH1F*)FJFile->Get("pT_Quotient__1Muon-Jet<100");  Cociente_pT100__1Muon_ak5FJ->Scale(1.0/Cociente_pT100__1Muon_ak5FJ->Integral());
  TH1F *Cociente_pT100__1Muon_ak5PFJet =(TH1F*)JetFile->Get("pT_Quotient__1Muon-Jet<100");   Cociente_pT100__1Muon_ak5PFJet->Scale(1.0/Cociente_pT100__1Muon_ak5PFJet->Integral());
  TH1F *Cociente_pT100__1Muon_ak5PFBTag =(TH1F*)BTagFile->Get("pT_Quotient__1Muon-Jet<100");   Cociente_pT100__1Muon_ak5PFBTag->Scale(1.0/Cociente_pT100__1Muon_ak5PFBTag->Integral());
  TH1F *Cociente_pT100__1Muon_ak5PFMinBias =(TH1F*)MinBiasFile->Get("pT_Quotient__1Muon-Jet<100");   Cociente_pT100__1Muon_ak5PFMinBias->Scale(1.0/Cociente_pT100__1Muon_ak5PFMinBias->Integral());
  TH1F *Cociente_pT100__1Muon_ak5PFMultiJet =(TH1F*)MultiJetFile->Get("pT_Quotient__1Muon-Jet<100");   Cociente_pT100__1Muon_ak5PFMultiJet->Scale(1.0/Cociente_pT100__1Muon_ak5PFMultiJet->Integral());

  TH1F *Cociente_100pT__1Muon_ak5FJ =(TH1F*)FJFile->Get("pT_Quotient__1Muon-Jet>100");  Cociente_100pT__1Muon_ak5FJ->Scale(1.0/Cociente_100pT__1Muon_ak5FJ->Integral());
  TH1F *Cociente_100pT__1Muon_ak5PFJet =(TH1F*)JetFile->Get("pT_Quotient__1Muon-Jet>100");   Cociente_100pT__1Muon_ak5PFJet->Scale(1.0/Cociente_100pT__1Muon_ak5PFJet->Integral());
  TH1F *Cociente_100pT__1Muon_ak5PFBTag =(TH1F*)BTagFile->Get("pT_Quotient__1Muon-Jet>100");   Cociente_100pT__1Muon_ak5PFBTag->Scale(1.0/Cociente_100pT__1Muon_ak5PFBTag->Integral());
  TH1F *Cociente_100pT__1Muon_ak5PFMinBias =(TH1F*)MinBiasFile->Get("pT_Quotient__1Muon-Jet>100");   Cociente_100pT__1Muon_ak5PFMinBias->Scale(1.0/Cociente_100pT__1Muon_ak5PFMinBias->Integral());
  TH1F *Cociente_100pT__1Muon_ak5PFMultiJet =(TH1F*)MultiJetFile->Get("pT_Quotient__1Muon-Jet>100");   Cociente_100pT__1Muon_ak5PFMultiJet->Scale(1.0/Cociente_100pT__1Muon_ak5PFMultiJet->Integral());

  // TH1F *Cociente_pT__Muon01_ak5FJ = (TH1F*)FJFile->Get("pT__Quotient01__Muon-Jet");Cociente_pT__Muon01_ak5FJ->Scale(1.0/Cociente_pT__Muon01_ak5FJ->Integral());
  // TH1F *Cociente_pT__Muon02_ak5FJ = (TH1F*)FJFile->Get("pT__Quotient02__Muon-Jet");Cociente_pT__Muon02_ak5FJ->Scale(1.0/Cociente_pT__Muon02_ak5FJ->Integral());
  // TH1F *Cociente_pT__Muon03_ak5FJ = (TH1F*)FJFile->Get("pT__Quotient03__Muon-Jet");Cociente_pT__Muon03_ak5FJ->Scale(1.0/Cociente_pT__Muon03_ak5FJ->Integral());
  // TH1F *Cociente_pT__Muon04_ak5FJ = (TH1F*)FJFile->Get("pT__Quotient04__Muon-Jet");Cociente_pT__Muon04_ak5FJ->Scale(1.0/Cociente_pT__Muon04_ak5FJ->Integral());
  // TH1F *Cociente_pT__Muon05_ak5FJ = (TH1F*)FJFile->Get("pT__Quotient05__Muon-Jet");Cociente_pT__Muon05_ak5FJ->Scale(1.0/Cociente_pT__Muon05_ak5FJ->Integral());
  // TH1F *Cociente_pT__Muon21_ak5FJ = (TH1F*)FJFile->Get("pT__Quotient21__Muon-Jet");Cociente_pT__Muon21_ak5FJ->Scale(1.0/Cociente_pT__Muon21_ak5FJ->Integral());

  TH1F *Cociente_pT__Electron_ak5FJ =(TH1F*)FJFile->Get("pT_Quotient__Electron-Jet");  Cociente_pT__Electron_ak5FJ->Scale(1.0/Cociente_pT__Electron_ak5FJ->Integral());
  TH1F *Cociente_pT__Electron_ak5PFJet =(TH1F*)JetFile->Get("pT_Quotient__Electron-Jet");   Cociente_pT__Electron_ak5PFJet->Scale(1.0/Cociente_pT__Electron_ak5PFJet->Integral());
  TH1F *Cociente_pT__Electron_ak5PFBTag =(TH1F*)BTagFile->Get("pT_Quotient__Electron-Jet");   Cociente_pT__Electron_ak5PFBTag->Scale(1.0/Cociente_pT__Electron_ak5PFBTag->Integral());
  TH1F *Cociente_pT__Electron_ak5PFMinBias =(TH1F*)MinBiasFile->Get("pT_Quotient__Electron-Jet");   Cociente_pT__Electron_ak5PFMinBias->Scale(1.0/Cociente_pT__Electron_ak5PFMinBias->Integral());
  TH1F *Cociente_pT__Electron_ak5PFMultiJet =(TH1F*)MultiJetFile->Get("pT_Quotient__Electron-Jet");   Cociente_pT__Electron_ak5PFMultiJet->Scale(1.0/Cociente_pT__Electron_ak5PFMultiJet->Integral());

  TH1F *Cociente_pT100__1Electron_ak5FJ =(TH1F*)FJFile->Get("pT_Quotient__1Electron-Jet<100");  Cociente_pT100__1Electron_ak5FJ->Scale(1.0/Cociente_pT100__1Electron_ak5FJ->Integral());
  TH1F *Cociente_pT100__1Electron_ak5PFJet =(TH1F*)JetFile->Get("pT_Quotient__1Electron-Jet<100");   Cociente_pT100__1Electron_ak5PFJet->Scale(1.0/Cociente_pT100__1Electron_ak5PFJet->Integral());
  TH1F *Cociente_pT100__1Electron_ak5PFBTag =(TH1F*)BTagFile->Get("pT_Quotient__1Electron-Jet<100");   Cociente_pT100__1Electron_ak5PFBTag->Scale(1.0/Cociente_pT100__1Electron_ak5PFBTag->Integral());
  TH1F *Cociente_pT100__1Electron_ak5PFMinBias =(TH1F*)MinBiasFile->Get("pT_Quotient__1Electron-Jet<100");   Cociente_pT100__1Electron_ak5PFMinBias->Scale(1.0/Cociente_pT100__1Electron_ak5PFMinBias->Integral());
  TH1F *Cociente_pT100__1Electron_ak5PFMultiJet =(TH1F*)MultiJetFile->Get("pT_Quotient__1Electron-Jet<100");   Cociente_pT100__1Electron_ak5PFMultiJet->Scale(1.0/Cociente_pT100__1Electron_ak5PFMultiJet->Integral());

  TH1F *Cociente_100pT__1Electron_ak5FJ =(TH1F*)FJFile->Get("pT_Quotient__1Electron-Jet>100");  Cociente_100pT__1Electron_ak5FJ->Scale(1.0/Cociente_100pT__1Electron_ak5FJ->Integral());
  TH1F *Cociente_100pT__1Electron_ak5PFJet =(TH1F*)JetFile->Get("pT_Quotient__1Electron-Jet>100");   Cociente_100pT__1Electron_ak5PFJet->Scale(1.0/Cociente_100pT__1Electron_ak5PFJet->Integral());
  TH1F *Cociente_100pT__1Electron_ak5PFBTag =(TH1F*)BTagFile->Get("pT_Quotient__1Electron-Jet>100");   Cociente_100pT__1Electron_ak5PFBTag->Scale(1.0/Cociente_100pT__1Electron_ak5PFBTag->Integral());
  TH1F *Cociente_100pT__1Electron_ak5PFMinBias =(TH1F*)MinBiasFile->Get("pT_Quotient__1Electron-Jet>100");   Cociente_100pT__1Electron_ak5PFMinBias->Scale(1.0/Cociente_100pT__1Electron_ak5PFMinBias->Integral());
  TH1F *Cociente_100pT__1Electron_ak5PFMultiJet =(TH1F*)MultiJetFile->Get("pT_Quotient__1Electron-Jet>100");   Cociente_100pT__1Electron_ak5PFMultiJet->Scale(1.0/Cociente_100pT__1Electron_ak5PFMultiJet->Integral());

  // TH1F *Cociente_pT__Electron01_ak5FJ = (TH1F*)FJFile->Get("pT__Quotient01__Electron-Jet");Cociente_pT__Electron01_ak5FJ->Scale(1.0/Cociente_pT__Electron01_ak5FJ->Integral());
  // TH1F *Cociente_pT__Electron02_ak5FJ = (TH1F*)FJFile->Get("pT__Quotient02__Electron-Jet");Cociente_pT__Electron02_ak5FJ->Scale(1.0/Cociente_pT__Electron02_ak5FJ->Integral());
  // TH1F *Cociente_pT__Electron03_ak5FJ = (TH1F*)FJFile->Get("pT__Quotient03__Electron-Jet");Cociente_pT__Electron03_ak5FJ->Scale(1.0/Cociente_pT__Electron03_ak5FJ->Integral());
  // TH1F *Cociente_pT__Electron04_ak5FJ = (TH1F*)FJFile->Get("pT__Quotient04__Electron-Jet");Cociente_pT__Electron04_ak5FJ->Scale(1.0/Cociente_pT__Electron04_ak5FJ->Integral());
  // TH1F *Cociente_pT__Electron05_ak5FJ = (TH1F*)FJFile->Get("pT__Quotient05__Electron-Jet");Cociente_pT__Electron05_ak5FJ->Scale(1.0/Cociente_pT__Electron05_ak5FJ->Integral());
  // TH1F *Cociente_pT__Electron21_ak5FJ = (TH1F*)FJFile->Get("pT__Quotient21__Electron-Jet");Cociente_pT__Electron21_ak5FJ->Scale(1.0/Cociente_pT__Electron21_ak5FJ->Integral());



  auto   Leg = new TLegend(0.62,0.70,0.90,0.92);    Leg->SetTextSize(0.04); Leg->SetFillStyle(0); Leg->SetBorderSize(0);
    Leg->AddEntry(CLON_C_pT__Muon_ak5FJ, "MC FastJet", "p");
    Leg->AddEntry(CLON_C_pT__Muon_ak5PFJet, "Open-Data PF Jet", "p");
    Leg->AddEntry(CLON_C_pT__Muon_ak5PFBTag, "Open-Data PF BTag", "p");
    Leg->AddEntry(CLON_C_pT__Muon_ak5PFMinBias, "Open-Data PF MinBias", "p");
    Leg->AddEntry(CLON_C_pT__Muon_ak5PFMultiJet, "Open-Data PF MultiJet", "p");

  auto   legend = new TLegend(0.62,0.70,0.90,0.92);    legend->SetTextSize(0.04); legend->SetFillStyle(0); legend->SetBorderSize(0);
    legend->AddEntry(Cociente_pT__Muon_ak5FJ, "MC FastJet", "lep");
    legend->AddEntry(Cociente_pT__Muon_ak5PFJet, "Open-Data PF Jet", "lep");
    legend->AddEntry(Cociente_pT__Muon_ak5PFBTag, "Open-Data PF BTag", "lep");
    legend->AddEntry(Cociente_pT__Muon_ak5PFMinBias, "Open-Data PF MinBias", "lep");
    legend->AddEntry(Cociente_pT__Muon_ak5PFMultiJet, "Open-Data PF MultiJet", "lep");

  // auto   QuarkLegend = new TLegend(0.75,0.60,0.90,0.92);    QuarkLegend->SetTextSize(0.04);
  //   QuarkLegend->AddEntry(Cociente_pT__Muon_ak5FJ, "MC FastJet", "lp");
  //   QuarkLegend->AddEntry(Cociente_pT__Muon01_ak5FJ, "MC, Down", "lp");
  //   QuarkLegend->AddEntry(Cociente_pT__Muon02_ak5FJ, "MC, Up", "lp");
  //   QuarkLegend->AddEntry(Cociente_pT__Muon03_ak5FJ, "MC, Strange", "lp");
  //   QuarkLegend->AddEntry(Cociente_pT__Muon04_ak5FJ, "MC, Charm", "lp");
  //   QuarkLegend->AddEntry(Cociente_pT__Muon05_ak5FJ, "MC, Bottom", "lp");
  //   QuarkLegend->AddEntry(Cociente_pT__Muon21_ak5FJ, "MC, Gluon", "lp");
  //
  // auto   ODQuarkLegend = new TLegend(0.68,0.60,0.90,0.92);    ODQuarkLegend->SetTextSize(0.04);
  //   ODQuarkLegend->AddEntry(Cociente_pT__Muon_ak5PFJet, "Open-Data PF Jet", "lp");
  //   ODQuarkLegend->AddEntry(Cociente_pT__Muon01_ak5FJ, "MC, Down", "lp");
  //   ODQuarkLegend->AddEntry(Cociente_pT__Muon02_ak5FJ, "MC, Up", "lp");
  //   ODQuarkLegend->AddEntry(Cociente_pT__Muon03_ak5FJ, "MC, Strange", "lp");
  //   ODQuarkLegend->AddEntry(Cociente_pT__Muon04_ak5FJ, "MC, Charm", "lp");
  //   ODQuarkLegend->AddEntry(Cociente_pT__Muon05_ak5FJ, "MC, Bottom", "lp");
  //   ODQuarkLegend->AddEntry(Cociente_pT__Muon21_ak5FJ, "MC, Gluon", "lp");



  TCanvas* Cociente_pT__Muon_Jet = new TCanvas("Cociente_pT__Muon_Jet","Cociente pT FastJet y PFJets para muones",10,10,1920,1080);
  Cociente_pT__Muon_Jet->SetFillColor(0);  Cociente_pT__Muon_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  CLON_C_pT__Muon_ak5FJ->SetTitle("Cociente p_{T} para MUONES; p_{T}^{Muon} / p_{T}^{Jet}; U. A.");
  CLON_C_pT__Muon_ak5FJ->GetXaxis()->SetLabelSize(0.05); CLON_C_pT__Muon_ak5FJ->GetYaxis()->SetLabelSize(0.05);
  CLON_C_pT__Muon_ak5FJ->GetXaxis()->SetTitleSize(0.05); CLON_C_pT__Muon_ak5FJ->GetYaxis()->SetTitleSize(0.05);
  CLON_C_pT__Muon_ak5FJ->GetXaxis()->SetTitleOffset(1.0);CLON_C_pT__Muon_ak5FJ->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  CLON_C_pT__Muon_ak5FJ->Draw("P"); CLON_C_pT__Muon_ak5FJ->Rebin(); Cociente_pT__Muon_ak5FJ->Rebin(); CLON_C_pT__Muon_ak5FJ->SetAxisRange(0.0, 1.2, "X");
  CLON_C_pT__Muon_ak5FJ->SetMarkerStyle(21); CLON_C_pT__Muon_ak5FJ->SetMarkerColor(14); CLON_C_pT__Muon_ak5FJ->SetMarkerSize(4);
  Cociente_pT__Muon_ak5FJ -> Draw("Esame"); Cociente_pT__Muon_ak5FJ->SetLineColor(1); Cociente_pT__Muon_ak5FJ->SetLineWidth(4);
  Cociente_pT__Muon_ak5FJ->SetMarkerStyle(25); Cociente_pT__Muon_ak5FJ->SetMarkerColor(1); Cociente_pT__Muon_ak5FJ->SetMarkerSize(4);
  CLON_C_pT__Muon_ak5PFJet->Draw("Psame"); CLON_C_pT__Muon_ak5PFJet->Rebin(); Cociente_pT__Muon_ak5PFJet->Rebin();
  CLON_C_pT__Muon_ak5PFJet->SetMarkerStyle(23); CLON_C_pT__Muon_ak5PFJet->SetMarkerColor(42); CLON_C_pT__Muon_ak5PFJet->SetMarkerSize(4);
  Cociente_pT__Muon_ak5PFJet -> Draw("Esame"); Cociente_pT__Muon_ak5PFJet->SetLineColor(2); Cociente_pT__Muon_ak5PFJet->SetLineWidth(4);
  Cociente_pT__Muon_ak5PFJet->SetMarkerStyle(32); Cociente_pT__Muon_ak5PFJet->SetMarkerColor(2); Cociente_pT__Muon_ak5PFJet->SetMarkerSize(4);
  CLON_C_pT__Muon_ak5PFBTag->Draw("Psame"); CLON_C_pT__Muon_ak5PFBTag->Rebin(); Cociente_pT__Muon_ak5PFBTag->Rebin();
  CLON_C_pT__Muon_ak5PFBTag->SetMarkerStyle(22); CLON_C_pT__Muon_ak5PFBTag->SetMarkerColor(33); CLON_C_pT__Muon_ak5PFBTag->SetMarkerSize(4);
  Cociente_pT__Muon_ak5PFBTag -> Draw("Esame"); Cociente_pT__Muon_ak5PFBTag->SetLineColor(4); Cociente_pT__Muon_ak5PFBTag->SetLineWidth(4);
  Cociente_pT__Muon_ak5PFBTag->SetMarkerStyle(26); Cociente_pT__Muon_ak5PFBTag->SetMarkerColor(4); Cociente_pT__Muon_ak5PFBTag->SetMarkerSize(4);
  CLON_C_pT__Muon_ak5PFMinBias->Draw("Psame"); CLON_C_pT__Muon_ak5PFMinBias->Rebin(); Cociente_pT__Muon_ak5PFMinBias->Rebin();
  CLON_C_pT__Muon_ak5PFMinBias->SetMarkerStyle(20); CLON_C_pT__Muon_ak5PFMinBias->SetMarkerColor(5); CLON_C_pT__Muon_ak5PFMinBias->SetMarkerSize(4);
  Cociente_pT__Muon_ak5PFMinBias -> Draw("Esame"); Cociente_pT__Muon_ak5PFMinBias->SetLineColor(41); Cociente_pT__Muon_ak5PFMinBias->SetLineWidth(4);
  Cociente_pT__Muon_ak5PFMinBias->SetMarkerStyle(24); Cociente_pT__Muon_ak5PFMinBias->SetMarkerColor(41); Cociente_pT__Muon_ak5PFMinBias->SetMarkerSize(4);
  CLON_C_pT__Muon_ak5PFMultiJet->Draw("Psame"); CLON_C_pT__Muon_ak5PFMultiJet->Rebin(); Cociente_pT__Muon_ak5PFMultiJet->Rebin();
  CLON_C_pT__Muon_ak5PFMultiJet->SetMarkerStyle(34); CLON_C_pT__Muon_ak5PFMultiJet->SetMarkerColor(8); CLON_C_pT__Muon_ak5PFMultiJet->SetMarkerSize(4);
  Cociente_pT__Muon_ak5PFMultiJet -> Draw("Esame"); Cociente_pT__Muon_ak5PFMultiJet->SetLineColor(32); Cociente_pT__Muon_ak5PFMultiJet->SetLineWidth(4);
  Cociente_pT__Muon_ak5PFMultiJet->SetMarkerStyle(28); Cociente_pT__Muon_ak5PFMultiJet->SetMarkerColor(32); Cociente_pT__Muon_ak5PFMultiJet->SetMarkerSize(4);
  Leg->Draw(); legend->Draw();  Cociente_pT__Muon_Jet->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Cociente_pT__Muon-Jet.png"); Cociente_pT__Muon_Jet->Close();


  /*    TCanvas* Cociente_pT__MuonQuark_Jet = new TCanvas("Cociente_pT__MuonQuark_Jet","Cociente pT FastJet y PFJets para electrones",10,10,1920,1080);
      Cociente_pT__MuonQuark_Jet->SetFillColor(0);  Cociente_pT__MuonQuark_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
      // Esto es para modificar las etiquetas del canvas.
      Cociente_pT__Muon_ak5FJ->SetTitle("Cociente p_{T} para muones considerando el Parton madre; p_{T}^{Electron} / p_{T}^{Jet}; U. A.");
      Cociente_pT__Muon_ak5FJ->GetXaxis()->SetLabelSize(0.05); Cociente_pT__Muon_ak5FJ->GetYaxis()->SetLabelSize(0.05);
      Cociente_pT__Muon_ak5FJ->GetXaxis()->SetTitleSize(0.05); Cociente_pT__Muon_ak5FJ->GetYaxis()->SetTitleSize(0.05);
      Cociente_pT__Muon_ak5FJ->GetXaxis()->SetTitleOffset(1.0);Cociente_pT__Muon_ak5FJ->GetYaxis()->SetTitleOffset(1.0);
      // Cociente_pT__Muon_ak5FJ->SetAxisRange(0.0, 2, "X");
      // Aqui ponemos todas las gráficas que necesitamos en el canvas.
      Cociente_pT__Muon_ak5FJ -> Draw("E1"); Cociente_pT__Muon_ak5FJ->SetLineColor(1); Cociente_pT__Muon_ak5FJ->SetLineWidth(4);
      Cociente_pT__Muon_ak5FJ->SetMarkerStyle(20); Cociente_pT__Muon_ak5FJ->SetMarkerColor(1); Cociente_pT__Muon_ak5FJ->SetMarkerSize(2);
      Cociente_pT__Muon01_ak5FJ -> Draw("Esame"); Cociente_pT__Muon01_ak5FJ->SetLineColor(30); Cociente_pT__Muon01_ak5FJ->SetLineWidth(4);
      Cociente_pT__Muon01_ak5FJ->SetMarkerStyle(22); Cociente_pT__Muon01_ak5FJ->SetMarkerColor(30); Cociente_pT__Muon01_ak5FJ->SetMarkerSize(2);
      Cociente_pT__Muon02_ak5FJ -> Draw("Esame"); Cociente_pT__Muon02_ak5FJ->SetLineColor(38); Cociente_pT__Muon02_ak5FJ->SetLineWidth(4);
      Cociente_pT__Muon02_ak5FJ->SetMarkerStyle(23); Cociente_pT__Muon02_ak5FJ->SetMarkerColor(38); Cociente_pT__Muon02_ak5FJ->SetMarkerSize(2);
      Cociente_pT__Muon03_ak5FJ -> Draw("Esame"); Cociente_pT__Muon03_ak5FJ->SetLineColor(40); Cociente_pT__Muon03_ak5FJ->SetLineWidth(4);
      Cociente_pT__Muon03_ak5FJ->SetMarkerStyle(22); Cociente_pT__Muon03_ak5FJ->SetMarkerColor(40); Cociente_pT__Muon03_ak5FJ->SetMarkerSize(2);
      Cociente_pT__Muon04_ak5FJ -> Draw("Esame"); Cociente_pT__Muon04_ak5FJ->SetLineColor(41); Cociente_pT__Muon04_ak5FJ->SetLineWidth(4);
      Cociente_pT__Muon04_ak5FJ->SetMarkerStyle(23); Cociente_pT__Muon04_ak5FJ->SetMarkerColor(41); Cociente_pT__Muon04_ak5FJ->SetMarkerSize(2);
      Cociente_pT__Muon05_ak5FJ -> Draw("Esame"); Cociente_pT__Muon05_ak5FJ->SetLineColor(42); Cociente_pT__Muon05_ak5FJ->SetLineWidth(4);
      Cociente_pT__Muon05_ak5FJ->SetMarkerStyle(22); Cociente_pT__Muon05_ak5FJ->SetMarkerColor(42); Cociente_pT__Muon05_ak5FJ->SetMarkerSize(2);
      Cociente_pT__Muon21_ak5FJ -> Draw("Esame"); Cociente_pT__Muon21_ak5FJ->SetLineColor(45); Cociente_pT__Muon21_ak5FJ->SetLineWidth(4);
      Cociente_pT__Muon21_ak5FJ->SetMarkerStyle(23); Cociente_pT__Muon21_ak5FJ->SetMarkerColor(45); Cociente_pT__Muon21_ak5FJ->SetMarkerSize(2);
      QuarkLegend -> Draw();  Cociente_pT__MuonQuark_Jet -> SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Cociente_pT__MuonQuark-Jet.png"); Cociente_pT__MuonQuark_Jet -> Close();


      TCanvas* Cociente_pT__ODMuonQuark_Jet = new TCanvas("Cociente_pT__ODMuonQuark_Jet","Cociente pT FastJet y PFJets para electrones",10,10,1920,1080);
      Cociente_pT__ODMuonQuark_Jet->SetFillColor(0);  Cociente_pT__ODMuonQuark_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
      // Esto es para modificar las etiquetas del canvas.
      Cociente_pT__Muon_ak5PFJet->SetTitle("Cociente p_{T} para muones considerando el Parton madre; p_{T}^{Electron} / p_{T}^{Jet}; U. A.");
      Cociente_pT__Muon_ak5PFJet->GetXaxis()->SetLabelSize(0.05); Cociente_pT__Muon_ak5PFJet->GetYaxis()->SetLabelSize(0.05);
      Cociente_pT__Muon_ak5PFJet->GetXaxis()->SetTitleSize(0.05); Cociente_pT__Muon_ak5PFJet->GetYaxis()->SetTitleSize(0.05);
      Cociente_pT__Muon_ak5PFJet->GetXaxis()->SetTitleOffset(1.0);Cociente_pT__Muon_ak5PFJet->GetYaxis()->SetTitleOffset(1.0);
      // Cociente_pT__Muon_ak5PFJet->SetAxisRange(0.0, 1.2, "X");
      // Aqui ponemos todas las gráficas que necesitamos en el canvas.
      Cociente_pT__Muon_ak5PFJet -> Draw("E1"); Cociente_pT__Muon_ak5PFJet->SetLineColor(2); Cociente_pT__Muon_ak5PFJet->SetLineWidth(4);
      Cociente_pT__Muon_ak5PFJet->SetMarkerStyle(20); Cociente_pT__Muon_ak5PFJet->SetMarkerColor(2); Cociente_pT__Muon_ak5PFJet->SetMarkerSize(2);
      Cociente_pT__Muon01_ak5FJ -> Draw("Esame"); Cociente_pT__Muon01_ak5FJ->SetLineColor(30); Cociente_pT__Muon01_ak5FJ->SetLineWidth(4);
      Cociente_pT__Muon01_ak5FJ->SetMarkerStyle(22); Cociente_pT__Muon01_ak5FJ->SetMarkerColor(30); Cociente_pT__Muon01_ak5FJ->SetMarkerSize(2);
      Cociente_pT__Muon02_ak5FJ -> Draw("Esame"); Cociente_pT__Muon02_ak5FJ->SetLineColor(38); Cociente_pT__Muon02_ak5FJ->SetLineWidth(4);
      Cociente_pT__Muon02_ak5FJ->SetMarkerStyle(23); Cociente_pT__Muon02_ak5FJ->SetMarkerColor(38); Cociente_pT__Muon02_ak5FJ->SetMarkerSize(2);
      Cociente_pT__Muon03_ak5FJ -> Draw("Esame"); Cociente_pT__Muon03_ak5FJ->SetLineColor(40); Cociente_pT__Muon03_ak5FJ->SetLineWidth(4);
      Cociente_pT__Muon03_ak5FJ->SetMarkerStyle(22); Cociente_pT__Muon03_ak5FJ->SetMarkerColor(40); Cociente_pT__Muon03_ak5FJ->SetMarkerSize(2);
      Cociente_pT__Muon04_ak5FJ -> Draw("Esame"); Cociente_pT__Muon04_ak5FJ->SetLineColor(41); Cociente_pT__Muon04_ak5FJ->SetLineWidth(4);
      Cociente_pT__Muon04_ak5FJ->SetMarkerStyle(23); Cociente_pT__Muon04_ak5FJ->SetMarkerColor(41); Cociente_pT__Muon04_ak5FJ->SetMarkerSize(2);
      Cociente_pT__Muon05_ak5FJ -> Draw("Esame"); Cociente_pT__Muon05_ak5FJ->SetLineColor(42); Cociente_pT__Muon05_ak5FJ->SetLineWidth(4);
      Cociente_pT__Muon05_ak5FJ->SetMarkerStyle(22); Cociente_pT__Muon05_ak5FJ->SetMarkerColor(42); Cociente_pT__Muon05_ak5FJ->SetMarkerSize(2);
      Cociente_pT__Muon21_ak5FJ -> Draw("Esame"); Cociente_pT__Muon21_ak5FJ->SetLineColor(45); Cociente_pT__Muon21_ak5FJ->SetLineWidth(4);
      Cociente_pT__Muon21_ak5FJ->SetMarkerStyle(23); Cociente_pT__Muon21_ak5FJ->SetMarkerColor(45); Cociente_pT__Muon21_ak5FJ->SetMarkerSize(2);
      ODQuarkLegend -> Draw();  Cociente_pT__ODMuonQuark_Jet -> SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Cociente_pT__MuonODQuark-Jet.png"); Cociente_pT__ODMuonQuark_Jet -> Close();*/


  TCanvas* Cociente_pT100__1Muon_Jet = new TCanvas("Cociente_pT100__1Muon_Jet","Cociente pT<100 FastJet y PFJets para muones",10,10,1920,1080);
  Cociente_pT100__1Muon_Jet->SetFillColor(0);  Cociente_pT100__1Muon_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  Cociente_pT100__1Muon_ak5FJ->SetTitle("Cociente p_{T} para MUONES  (p_{T}^{Jet} < 100);  p_{T}^{Muon} / p_{T}^{Jet}; U. A.");
  Cociente_pT100__1Muon_ak5FJ->GetXaxis()->SetLabelSize(0.05); Cociente_pT100__1Muon_ak5FJ->GetYaxis()->SetLabelSize(0.05);
  Cociente_pT100__1Muon_ak5FJ->GetXaxis()->SetTitleSize(0.05); Cociente_pT100__1Muon_ak5FJ->GetYaxis()->SetTitleSize(0.05);
  Cociente_pT100__1Muon_ak5FJ->GetXaxis()->SetTitleOffset(1.0);Cociente_pT100__1Muon_ak5FJ->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Cociente_pT100__1Muon_ak5FJ->Rebin(); Cociente_pT100__1Muon_ak5FJ->SetAxisRange(0.0, 1.2, "X");
  Cociente_pT100__1Muon_ak5FJ->SetMarkerSize(4);Cociente_pT100__1Muon_ak5FJ->SetMarkerStyle(21); Cociente_pT100__1Muon_ak5FJ->SetMarkerColor(14);
  Cociente_pT100__1Muon_ak5FJ->DrawCopy("P");   Cociente_pT100__1Muon_ak5FJ->SetMarkerStyle(25); Cociente_pT100__1Muon_ak5FJ->SetMarkerColor(1);
  Cociente_pT100__1Muon_ak5FJ->SetLineWidth(4); Cociente_pT100__1Muon_ak5FJ -> Draw("Esame");    Cociente_pT100__1Muon_ak5FJ->SetLineColor(1);
  Cociente_pT100__1Muon_ak5PFJet->Rebin();
  Cociente_pT100__1Muon_ak5PFJet->SetMarkerSize(4); Cociente_pT100__1Muon_ak5PFJet->SetMarkerStyle(23); Cociente_pT100__1Muon_ak5PFJet->SetMarkerColor(42);
  Cociente_pT100__1Muon_ak5PFJet->DrawCopy("Psame");Cociente_pT100__1Muon_ak5PFJet->SetMarkerStyle(32); Cociente_pT100__1Muon_ak5PFJet->SetMarkerColor(2);
  Cociente_pT100__1Muon_ak5PFJet->SetLineWidth(4);  Cociente_pT100__1Muon_ak5PFJet -> Draw("Esame");    Cociente_pT100__1Muon_ak5PFJet->SetLineColor(2);
  Cociente_pT100__1Muon_ak5PFBTag->Rebin();
  Cociente_pT100__1Muon_ak5PFBTag->SetMarkerSize(4); Cociente_pT100__1Muon_ak5PFBTag->SetMarkerStyle(22); Cociente_pT100__1Muon_ak5PFBTag->SetMarkerColor(33);
  Cociente_pT100__1Muon_ak5PFBTag->DrawCopy("Psame");Cociente_pT100__1Muon_ak5PFBTag->SetMarkerStyle(26); Cociente_pT100__1Muon_ak5PFBTag->SetMarkerColor(4);
  Cociente_pT100__1Muon_ak5PFBTag->SetLineWidth(4);  Cociente_pT100__1Muon_ak5PFBTag -> Draw("Esame");    Cociente_pT100__1Muon_ak5PFBTag->SetLineColor(4);
  Cociente_pT100__1Muon_ak5PFMinBias->Rebin();
  Cociente_pT100__1Muon_ak5PFMinBias->SetMarkerSize(4); Cociente_pT100__1Muon_ak5PFMinBias->SetMarkerStyle(20); Cociente_pT100__1Muon_ak5PFMinBias->SetMarkerColor(5);
  Cociente_pT100__1Muon_ak5PFMinBias->DrawCopy("Psame");Cociente_pT100__1Muon_ak5PFMinBias->SetMarkerStyle(24); Cociente_pT100__1Muon_ak5PFMinBias->SetMarkerColor(kYellow+1);
  Cociente_pT100__1Muon_ak5PFMinBias->SetLineWidth(4);  Cociente_pT100__1Muon_ak5PFMinBias -> Draw("Esame");    Cociente_pT100__1Muon_ak5PFMinBias->SetLineColor(kYellow+1);
  Cociente_pT100__1Muon_ak5PFMultiJet->Rebin();
  Cociente_pT100__1Muon_ak5PFMultiJet->SetMarkerSize(4); Cociente_pT100__1Muon_ak5PFMultiJet->SetMarkerStyle(34); Cociente_pT100__1Muon_ak5PFMultiJet->SetMarkerColor(8);
  Cociente_pT100__1Muon_ak5PFMultiJet->DrawCopy("Psame");Cociente_pT100__1Muon_ak5PFMultiJet->SetMarkerStyle(28); Cociente_pT100__1Muon_ak5PFMultiJet->SetMarkerColor(32);
  Cociente_pT100__1Muon_ak5PFMultiJet->SetLineWidth(4);  Cociente_pT100__1Muon_ak5PFMultiJet -> Draw("Esame");    Cociente_pT100__1Muon_ak5PFMultiJet->SetLineColor(32);
  Leg->Draw(); legend->Draw();  Cociente_pT100__1Muon_Jet->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Cociente_pT__Muon1-Jet<100.png"); Cociente_pT100__1Muon_Jet->Close();


  TCanvas* Cociente_100pT__1Muon_Jet = new TCanvas("Cociente_100pT__1Muon_Jet","Cociente pT>100 FastJet y PFJets para muones",10,10,1920,1080);
  Cociente_100pT__1Muon_Jet->SetFillColor(0);  Cociente_100pT__1Muon_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  Cociente_100pT__1Muon_ak5FJ->SetTitle("Cociente p_{T} para MUONES  (p_{T}^{Jet} > 100); p_{T}^{Muon} / p_{T}^{Jet}; U. A.");
  Cociente_100pT__1Muon_ak5FJ->GetXaxis()->SetLabelSize(0.05); Cociente_100pT__1Muon_ak5FJ->GetYaxis()->SetLabelSize(0.05);
  Cociente_100pT__1Muon_ak5FJ->GetXaxis()->SetTitleSize(0.05); Cociente_100pT__1Muon_ak5FJ->GetYaxis()->SetTitleSize(0.05);
  Cociente_100pT__1Muon_ak5FJ->GetXaxis()->SetTitleOffset(1.0);Cociente_100pT__1Muon_ak5FJ->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Cociente_100pT__1Muon_ak5FJ->Rebin(); Cociente_100pT__1Muon_ak5FJ->SetAxisRange(0.0, 1.2, "X");
  Cociente_100pT__1Muon_ak5FJ->SetMarkerSize(4);Cociente_100pT__1Muon_ak5FJ->SetMarkerStyle(21); Cociente_100pT__1Muon_ak5FJ->SetMarkerColor(14);
  Cociente_100pT__1Muon_ak5FJ->DrawCopy("P");   Cociente_100pT__1Muon_ak5FJ->SetMarkerStyle(25); Cociente_100pT__1Muon_ak5FJ->SetMarkerColor(1);
  Cociente_100pT__1Muon_ak5FJ->SetLineWidth(4); Cociente_100pT__1Muon_ak5FJ -> Draw("Esame");    Cociente_100pT__1Muon_ak5FJ->SetLineColor(1);
  Cociente_100pT__1Muon_ak5PFJet->Rebin();
  Cociente_100pT__1Muon_ak5PFJet->SetMarkerSize(4); Cociente_100pT__1Muon_ak5PFJet->SetMarkerStyle(23); Cociente_100pT__1Muon_ak5PFJet->SetMarkerColor(42);
  Cociente_100pT__1Muon_ak5PFJet->DrawCopy("Psame");Cociente_100pT__1Muon_ak5PFJet->SetMarkerStyle(32); Cociente_100pT__1Muon_ak5PFJet->SetMarkerColor(2);
  Cociente_100pT__1Muon_ak5PFJet->SetLineWidth(4);  Cociente_100pT__1Muon_ak5PFJet -> Draw("Esame");    Cociente_100pT__1Muon_ak5PFJet->SetLineColor(2);
  Cociente_100pT__1Muon_ak5PFBTag->Rebin();
  Cociente_100pT__1Muon_ak5PFBTag->SetMarkerSize(4); Cociente_100pT__1Muon_ak5PFBTag->SetMarkerStyle(22); Cociente_100pT__1Muon_ak5PFBTag->SetMarkerColor(33);
  Cociente_100pT__1Muon_ak5PFBTag->DrawCopy("Psame");Cociente_100pT__1Muon_ak5PFBTag->SetMarkerStyle(26); Cociente_100pT__1Muon_ak5PFBTag->SetMarkerColor(4);
  Cociente_100pT__1Muon_ak5PFBTag->SetLineWidth(4);  Cociente_100pT__1Muon_ak5PFBTag -> Draw("Esame");    Cociente_100pT__1Muon_ak5PFBTag->SetLineColor(4);
  Cociente_100pT__1Muon_ak5PFMinBias->Rebin();
  Cociente_100pT__1Muon_ak5PFMinBias->SetMarkerSize(4); Cociente_100pT__1Muon_ak5PFMinBias->SetMarkerStyle(20); Cociente_100pT__1Muon_ak5PFMinBias->SetMarkerColor(5);
  Cociente_100pT__1Muon_ak5PFMinBias->DrawCopy("Psame");Cociente_100pT__1Muon_ak5PFMinBias->SetMarkerStyle(24); Cociente_100pT__1Muon_ak5PFMinBias->SetMarkerColor(kYellow+1);
  Cociente_100pT__1Muon_ak5PFMinBias->SetLineWidth(4);  Cociente_100pT__1Muon_ak5PFMinBias -> Draw("Esame");    Cociente_100pT__1Muon_ak5PFMinBias->SetLineColor(kYellow+1);
  Cociente_100pT__1Muon_ak5PFMultiJet->Rebin();
  Cociente_100pT__1Muon_ak5PFMultiJet->SetMarkerSize(4); Cociente_100pT__1Muon_ak5PFMultiJet->SetMarkerStyle(34); Cociente_100pT__1Muon_ak5PFMultiJet->SetMarkerColor(kSpring-9);
  Cociente_100pT__1Muon_ak5PFMultiJet->DrawCopy("Psame");Cociente_100pT__1Muon_ak5PFMultiJet->SetMarkerStyle(28); Cociente_100pT__1Muon_ak5PFMultiJet->SetMarkerColor(8);
  Cociente_100pT__1Muon_ak5PFMultiJet->SetLineWidth(4);  Cociente_100pT__1Muon_ak5PFMultiJet -> Draw("Esame");    Cociente_100pT__1Muon_ak5PFMultiJet->SetLineColor(8);
  Leg->Draw(); legend->Draw();  Cociente_100pT__1Muon_Jet->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Cociente_pT__Muon1-Jet>100.png"); Cociente_100pT__1Muon_Jet->Close();


  TCanvas* Cociente_pT__Electron_Jet = new TCanvas("Cociente_pT__Electron_Jet","Cociente pT FastJet y PFJets para electrones",10,10,1920,1080);
  Cociente_pT__Electron_Jet->SetFillColor(0);  Cociente_pT__Electron_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  Cociente_pT__Electron_ak5FJ->SetTitle("Cociente p_{T} para ELECTRONES; p_{T}^{Electron} / p_{T}^{Jet}; U. A.");
  Cociente_pT__Electron_ak5FJ->GetXaxis()->SetLabelSize(0.05); Cociente_pT__Electron_ak5FJ->GetYaxis()->SetLabelSize(0.05);
  Cociente_pT__Electron_ak5FJ->GetXaxis()->SetTitleSize(0.05); Cociente_pT__Electron_ak5FJ->GetYaxis()->SetTitleSize(0.05);
  Cociente_pT__Electron_ak5FJ->GetXaxis()->SetTitleOffset(1.0);Cociente_pT__Electron_ak5FJ->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Cociente_pT__Electron_ak5FJ->Rebin(); Cociente_pT__Electron_ak5FJ->SetAxisRange(0.0, 1.2, "X");
  Cociente_pT__Electron_ak5FJ->SetMarkerSize(4);Cociente_pT__Electron_ak5FJ->SetMarkerStyle(21); Cociente_pT__Electron_ak5FJ->SetMarkerColor(14);
  Cociente_pT__Electron_ak5FJ->DrawCopy("P");   Cociente_pT__Electron_ak5FJ->SetMarkerStyle(25); Cociente_pT__Electron_ak5FJ->SetMarkerColor(1);
  Cociente_pT__Electron_ak5FJ->SetLineWidth(4); Cociente_pT__Electron_ak5FJ->Draw("Esame");      Cociente_pT__Electron_ak5FJ->SetLineColor(1);
  Cociente_pT__Electron_ak5PFJet->Rebin();
  Cociente_pT__Electron_ak5PFJet->SetMarkerSize(4); Cociente_pT__Electron_ak5PFJet->SetMarkerStyle(23); Cociente_pT__Electron_ak5PFJet->SetMarkerColor(42);
  Cociente_pT__Electron_ak5PFJet->DrawCopy("Psame");Cociente_pT__Electron_ak5PFJet->SetMarkerStyle(32); Cociente_pT__Electron_ak5PFJet->SetMarkerColor(2);
  Cociente_pT__Electron_ak5PFJet->SetLineWidth(4);  Cociente_pT__Electron_ak5PFJet->Draw("Esame");      Cociente_pT__Electron_ak5PFJet->SetLineColor(2);
  Cociente_pT__Electron_ak5PFBTag->Rebin();
  Cociente_pT__Electron_ak5PFBTag->SetMarkerSize(4); Cociente_pT__Electron_ak5PFBTag->SetMarkerStyle(22); Cociente_pT__Electron_ak5PFBTag->SetMarkerColor(33);
  Cociente_pT__Electron_ak5PFBTag->DrawCopy("Psame");Cociente_pT__Electron_ak5PFBTag->SetMarkerStyle(26); Cociente_pT__Electron_ak5PFBTag->SetMarkerColor(4);
  Cociente_pT__Electron_ak5PFBTag->SetLineWidth(4);  Cociente_pT__Electron_ak5PFBTag->Draw("Esame");      Cociente_pT__Electron_ak5PFBTag->SetLineColor(4);
  Cociente_pT__Electron_ak5PFMinBias->Rebin();
  Cociente_pT__Electron_ak5PFMinBias->SetMarkerSize(4); Cociente_pT__Electron_ak5PFMinBias->SetMarkerStyle(20); Cociente_pT__Electron_ak5PFMinBias->SetMarkerColor(5);
  Cociente_pT__Electron_ak5PFMinBias->DrawCopy("Psame");Cociente_pT__Electron_ak5PFMinBias->SetMarkerStyle(24); Cociente_pT__Electron_ak5PFMinBias->SetMarkerColor(41);
  Cociente_pT__Electron_ak5PFMinBias->SetLineWidth(4);  Cociente_pT__Electron_ak5PFMinBias->Draw("Esame");      Cociente_pT__Electron_ak5PFMinBias->SetLineColor(41);
  Cociente_pT__Electron_ak5PFMultiJet->Rebin();
  Cociente_pT__Electron_ak5PFMultiJet->SetMarkerSize(4); Cociente_pT__Electron_ak5PFMultiJet->SetMarkerStyle(34); Cociente_pT__Electron_ak5PFMultiJet->SetMarkerColor(8);
  Cociente_pT__Electron_ak5PFMultiJet->DrawCopy("Psame");Cociente_pT__Electron_ak5PFMultiJet->SetMarkerStyle(28); Cociente_pT__Electron_ak5PFMultiJet->SetMarkerColor(32);
  Cociente_pT__Electron_ak5PFMultiJet->SetLineWidth(4);  Cociente_pT__Electron_ak5PFMultiJet->Draw("Esame");      Cociente_pT__Electron_ak5PFMultiJet->SetLineColor(32);
  Leg->Draw(); legend->Draw();  Cociente_pT__Electron_Jet->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Cociente_pT__Electron-Jet.png"); Cociente_pT__Electron_Jet->Close();

/*
    TCanvas* Cociente_pT__ElecQuark_Jet = new TCanvas("Cociente_pT__ElecQuark_Jet","Cociente pT FastJet y PFJets para electrones",10,10,1920,1080);
    Cociente_pT__ElecQuark_Jet->SetFillColor(0);  Cociente_pT__ElecQuark_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
    // Esto es para modificar las etiquetas del canvas.
    Cociente_pT__Electron_ak5FJ->SetTitle("Cociente p_{T} para electrones considerando el Parton madre; p_{T}^{Electron} / p_{T}^{Jet}; U. A.");
    Cociente_pT__Electron_ak5FJ->GetXaxis()->SetLabelSize(0.05); Cociente_pT__Electron_ak5FJ->GetYaxis()->SetLabelSize(0.05);
    Cociente_pT__Electron_ak5FJ->GetXaxis()->SetTitleSize(0.05); Cociente_pT__Electron_ak5FJ->GetYaxis()->SetTitleSize(0.05);
    Cociente_pT__Electron_ak5FJ->GetXaxis()->SetTitleOffset(1.0);Cociente_pT__Electron_ak5FJ->GetYaxis()->SetTitleOffset(1.0);
    // Cociente_pT__Electron_ak5FJ->SetAxisRange(0.0, 1.2, "X");
    // Aqui ponemos todas las gráficas que necesitamos en el canvas.
    Cociente_pT__Electron_ak5FJ -> Draw("E1"); Cociente_pT__Electron_ak5FJ->SetLineColor(1); Cociente_pT__Electron_ak5FJ->SetLineWidth(4);
    Cociente_pT__Electron_ak5FJ->SetMarkerStyle(20); Cociente_pT__Electron_ak5FJ->SetMarkerColor(1); Cociente_pT__Electron_ak5FJ->SetMarkerSize(2);
    Cociente_pT__Electron01_ak5FJ -> Draw("Esame"); Cociente_pT__Electron01_ak5FJ->SetLineColor(30); Cociente_pT__Electron01_ak5FJ->SetLineWidth(4);
    Cociente_pT__Electron01_ak5FJ->SetMarkerStyle(22); Cociente_pT__Electron01_ak5FJ->SetMarkerColor(30); Cociente_pT__Electron01_ak5FJ->SetMarkerSize(2);
    Cociente_pT__Electron02_ak5FJ -> Draw("Esame"); Cociente_pT__Electron02_ak5FJ->SetLineColor(38); Cociente_pT__Electron02_ak5FJ->SetLineWidth(4);
    Cociente_pT__Electron02_ak5FJ->SetMarkerStyle(23); Cociente_pT__Electron02_ak5FJ->SetMarkerColor(38); Cociente_pT__Electron02_ak5FJ->SetMarkerSize(2);
    Cociente_pT__Electron03_ak5FJ -> Draw("Esame"); Cociente_pT__Electron03_ak5FJ->SetLineColor(40); Cociente_pT__Electron03_ak5FJ->SetLineWidth(4);
    Cociente_pT__Electron03_ak5FJ->SetMarkerStyle(22); Cociente_pT__Electron03_ak5FJ->SetMarkerColor(40); Cociente_pT__Electron03_ak5FJ->SetMarkerSize(2);
    Cociente_pT__Electron04_ak5FJ -> Draw("Esame"); Cociente_pT__Electron04_ak5FJ->SetLineColor(41); Cociente_pT__Electron04_ak5FJ->SetLineWidth(4);
    Cociente_pT__Electron04_ak5FJ->SetMarkerStyle(23); Cociente_pT__Electron04_ak5FJ->SetMarkerColor(41); Cociente_pT__Electron04_ak5FJ->SetMarkerSize(2);
    Cociente_pT__Electron05_ak5FJ -> Draw("Esame"); Cociente_pT__Electron05_ak5FJ->SetLineColor(42); Cociente_pT__Electron05_ak5FJ->SetLineWidth(4);
    Cociente_pT__Electron05_ak5FJ->SetMarkerStyle(22); Cociente_pT__Electron05_ak5FJ->SetMarkerColor(42); Cociente_pT__Electron05_ak5FJ->SetMarkerSize(2);
    Cociente_pT__Electron21_ak5FJ -> Draw("Esame"); Cociente_pT__Electron21_ak5FJ->SetLineColor(45); Cociente_pT__Electron21_ak5FJ->SetLineWidth(4);
    Cociente_pT__Electron21_ak5FJ->SetMarkerStyle(23); Cociente_pT__Electron21_ak5FJ->SetMarkerColor(45); Cociente_pT__Electron21_ak5FJ->SetMarkerSize(2);
    QuarkLegend -> Draw();  Cociente_pT__ElecQuark_Jet -> SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Cociente_pT__ElectronQuark-Jet.png"); Cociente_pT__ElecQuark_Jet -> Close();


    TCanvas* Cociente_pT__ElecQuark_Jet = new TCanvas("Cociente_pT__ElecQuark_Jet","Cociente pT FastJet y PFJets para electrones",10,10,1920,1080);
    Cociente_pT__ElecQuark_Jet->SetFillColor(0);  Cociente_pT__ElecQuark_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
    // Esto es para modificar las etiquetas del canvas.
    Cociente_pT__Electron_ak5PFJet->SetTitle("Cociente p_{T} para electrones considerando el Parton madre; p_{T}^{Electron} / p_{T}^{Jet}; U. A.");
    Cociente_pT__Electron_ak5PFJet->GetXaxis()->SetLabelSize(0.05); Cociente_pT__Electron_ak5PFJet->GetYaxis()->SetLabelSize(0.05);
    Cociente_pT__Electron_ak5PFJet->GetXaxis()->SetTitleSize(0.05); Cociente_pT__Electron_ak5PFJet->GetYaxis()->SetTitleSize(0.05);
    Cociente_pT__Electron_ak5PFJet->GetXaxis()->SetTitleOffset(1.0);Cociente_pT__Electron_ak5PFJet->GetYaxis()->SetTitleOffset(1.0);
    // Cociente_pT__Electron_ak5PFJet->SetAxisRange(0.0, 1.2, "X");
    // Aqui ponemos todas las gráficas que necesitamos en el canvas.
    Cociente_pT__Electron_ak5PFJet -> Draw("E1"); Cociente_pT__Electron_ak5PFJet->SetLineColor(2); Cociente_pT__Electron_ak5PFJet->SetLineWidth(4);
    Cociente_pT__Electron_ak5PFJet->SetMarkerStyle(20); Cociente_pT__Electron_ak5PFJet->SetMarkerColor(2); Cociente_pT__Electron_ak5PFJet->SetMarkerSize(2);
    Cociente_pT__Electron01_ak5FJ -> Draw("Esame"); Cociente_pT__Electron01_ak5FJ->SetLineColor(30); Cociente_pT__Electron01_ak5FJ->SetLineWidth(4);
    Cociente_pT__Electron01_ak5FJ->SetMarkerStyle(22); Cociente_pT__Electron01_ak5FJ->SetMarkerColor(30); Cociente_pT__Electron01_ak5FJ->SetMarkerSize(2);
    Cociente_pT__Electron02_ak5FJ -> Draw("Esame"); Cociente_pT__Electron02_ak5FJ->SetLineColor(38); Cociente_pT__Electron02_ak5FJ->SetLineWidth(4);
    Cociente_pT__Electron02_ak5FJ->SetMarkerStyle(23); Cociente_pT__Electron02_ak5FJ->SetMarkerColor(38); Cociente_pT__Electron02_ak5FJ->SetMarkerSize(2);
    Cociente_pT__Electron03_ak5FJ -> Draw("Esame"); Cociente_pT__Electron03_ak5FJ->SetLineColor(40); Cociente_pT__Electron03_ak5FJ->SetLineWidth(4);
    Cociente_pT__Electron03_ak5FJ->SetMarkerStyle(22); Cociente_pT__Electron03_ak5FJ->SetMarkerColor(40); Cociente_pT__Electron03_ak5FJ->SetMarkerSize(2);
    Cociente_pT__Electron04_ak5FJ -> Draw("Esame"); Cociente_pT__Electron04_ak5FJ->SetLineColor(41); Cociente_pT__Electron04_ak5FJ->SetLineWidth(4);
    Cociente_pT__Electron04_ak5FJ->SetMarkerStyle(23); Cociente_pT__Electron04_ak5FJ->SetMarkerColor(41); Cociente_pT__Electron04_ak5FJ->SetMarkerSize(2);
    Cociente_pT__Electron05_ak5FJ -> Draw("Esame"); Cociente_pT__Electron05_ak5FJ->SetLineColor(42); Cociente_pT__Electron05_ak5FJ->SetLineWidth(4);
    Cociente_pT__Electron05_ak5FJ->SetMarkerStyle(22); Cociente_pT__Electron05_ak5FJ->SetMarkerColor(42); Cociente_pT__Electron05_ak5FJ->SetMarkerSize(2);
    Cociente_pT__Electron21_ak5FJ -> Draw("Esame"); Cociente_pT__Electron21_ak5FJ->SetLineColor(45); Cociente_pT__Electron21_ak5FJ->SetLineWidth(4);
    Cociente_pT__Electron21_ak5FJ->SetMarkerStyle(23); Cociente_pT__Electron21_ak5FJ->SetMarkerColor(45); Cociente_pT__Electron21_ak5FJ->SetMarkerSize(2);
    ODQuarkLegend -> Draw();  Cociente_pT__ElecQuark_Jet -> SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Cociente_pT__ElectronODQuark-Jet.png"); Cociente_pT__ElecQuark_Jet -> Close();
*/

  TCanvas* Cociente_pT100__1Electron_Jet = new TCanvas("Cociente_pT100__1Electron_Jet","Cociente pT<100 FastJet y PFJets para electrones",10,10,1920,1080);
  Cociente_pT100__1Electron_Jet->SetFillColor(0);  Cociente_pT100__1Electron_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  Cociente_pT100__1Electron_ak5FJ->SetTitle("Cociente p_{T} para ELECTRONES  (p_{T}^{Jet} < 100); p_{T}^{Electron} / p_{T}^{Jet}; U. A.");
  Cociente_pT100__1Electron_ak5FJ->GetXaxis()->SetLabelSize(0.05); Cociente_pT100__1Electron_ak5FJ->GetYaxis()->SetLabelSize(0.05);
  Cociente_pT100__1Electron_ak5FJ->GetXaxis()->SetTitleSize(0.05); Cociente_pT100__1Electron_ak5FJ->GetYaxis()->SetTitleSize(0.05);
  Cociente_pT100__1Electron_ak5FJ->GetXaxis()->SetTitleOffset(1.0);Cociente_pT100__1Electron_ak5FJ->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Cociente_pT100__1Electron_ak5FJ->Rebin(); Cociente_pT100__1Electron_ak5FJ->SetAxisRange(0.0, 1.2, "X");
  Cociente_pT100__1Electron_ak5FJ->SetMarkerSize(4);Cociente_pT100__1Electron_ak5FJ->SetMarkerStyle(21); Cociente_pT100__1Electron_ak5FJ->SetMarkerColor(14);
  Cociente_pT100__1Electron_ak5FJ->DrawCopy("P");   Cociente_pT100__1Electron_ak5FJ->SetMarkerStyle(25); Cociente_pT100__1Electron_ak5FJ->SetMarkerColor(1);
  Cociente_pT100__1Electron_ak5FJ->SetLineWidth(4); Cociente_pT100__1Electron_ak5FJ -> Draw("Esame");    Cociente_pT100__1Electron_ak5FJ->SetLineColor(1);
  Cociente_pT100__1Electron_ak5PFJet->Rebin();
  Cociente_pT100__1Electron_ak5PFJet->SetMarkerSize(4); Cociente_pT100__1Electron_ak5PFJet->SetMarkerStyle(23); Cociente_pT100__1Electron_ak5PFJet->SetMarkerColor(42);
  Cociente_pT100__1Electron_ak5PFJet->DrawCopy("Psame");Cociente_pT100__1Electron_ak5PFJet->SetMarkerStyle(32); Cociente_pT100__1Electron_ak5PFJet->SetMarkerColor(2);
  Cociente_pT100__1Electron_ak5PFJet->SetLineWidth(4);  Cociente_pT100__1Electron_ak5PFJet -> Draw("Esame");    Cociente_pT100__1Electron_ak5PFJet->SetLineColor(2);
  Cociente_pT100__1Electron_ak5PFBTag->Rebin();
  Cociente_pT100__1Electron_ak5PFBTag->SetMarkerSize(4); Cociente_pT100__1Electron_ak5PFBTag->SetMarkerStyle(22); Cociente_pT100__1Electron_ak5PFBTag->SetMarkerColor(33);
  Cociente_pT100__1Electron_ak5PFBTag->DrawCopy("Psame");Cociente_pT100__1Electron_ak5PFBTag->SetMarkerStyle(26); Cociente_pT100__1Electron_ak5PFBTag->SetMarkerColor(4);
  Cociente_pT100__1Electron_ak5PFBTag->SetLineWidth(4);  Cociente_pT100__1Electron_ak5PFBTag -> Draw("Esame");    Cociente_pT100__1Electron_ak5PFBTag->SetLineColor(4);
  Cociente_pT100__1Electron_ak5PFMinBias->Rebin();
  Cociente_pT100__1Electron_ak5PFMinBias->SetMarkerSize(4); Cociente_pT100__1Electron_ak5PFMinBias->SetMarkerStyle(20); Cociente_pT100__1Electron_ak5PFMinBias->SetMarkerColor(5);
  Cociente_pT100__1Electron_ak5PFMinBias->DrawCopy("Psame");Cociente_pT100__1Electron_ak5PFMinBias->SetMarkerStyle(24); Cociente_pT100__1Electron_ak5PFMinBias->SetMarkerColor(41);
  Cociente_pT100__1Electron_ak5PFMinBias->SetLineWidth(4);  Cociente_pT100__1Electron_ak5PFMinBias -> Draw("Esame");    Cociente_pT100__1Electron_ak5PFMinBias->SetLineColor(41);
  Cociente_pT100__1Electron_ak5PFMultiJet->Rebin();
  Cociente_pT100__1Electron_ak5PFMultiJet->SetMarkerSize(4); Cociente_pT100__1Electron_ak5PFMultiJet->SetMarkerStyle(34); Cociente_pT100__1Electron_ak5PFMultiJet->SetMarkerColor(8);
  Cociente_pT100__1Electron_ak5PFMultiJet->DrawCopy("Psame");Cociente_pT100__1Electron_ak5PFMultiJet->SetMarkerStyle(28); Cociente_pT100__1Electron_ak5PFMultiJet->SetMarkerColor(32);
  Cociente_pT100__1Electron_ak5PFMultiJet->SetLineWidth(4);  Cociente_pT100__1Electron_ak5PFMultiJet -> Draw("Esame");    Cociente_pT100__1Electron_ak5PFMultiJet->SetLineColor(32);
  Leg->Draw(); legend->Draw();  Cociente_pT100__1Electron_Jet->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Cociente_pT__Electron1-Jet<100.png"); Cociente_pT100__1Electron_Jet->Close();


  TCanvas* Cociente_100pT__1Electron_Jet = new TCanvas("Cociente_100pT__1Electron_Jet","Cociente pT>100 FastJet y PFJets para electrones",10,10,1920,1080);
  Cociente_100pT__1Electron_Jet->SetFillColor(0);  Cociente_100pT__1Electron_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  Cociente_100pT__1Electron_ak5FJ->SetTitle("Cociente p_{T} para ELECTRONES  (p_{T}^{Jet} > 100); p_{T}^{Electron} / p_{T}^{Jet}; U. A.");
  Cociente_100pT__1Electron_ak5FJ->GetXaxis()->SetLabelSize(0.05); Cociente_100pT__1Electron_ak5FJ->GetYaxis()->SetLabelSize(0.05);
  Cociente_100pT__1Electron_ak5FJ->GetXaxis()->SetTitleSize(0.05); Cociente_100pT__1Electron_ak5FJ->GetYaxis()->SetTitleSize(0.05);
  Cociente_100pT__1Electron_ak5FJ->GetXaxis()->SetTitleOffset(1.0);Cociente_100pT__1Electron_ak5FJ->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Cociente_100pT__1Electron_ak5FJ->Rebin(); Cociente_100pT__1Electron_ak5FJ->SetAxisRange(0.0, 1.2, "X");
  Cociente_100pT__1Electron_ak5FJ->SetMarkerSize(4);Cociente_100pT__1Electron_ak5FJ->SetMarkerStyle(21); Cociente_100pT__1Electron_ak5FJ->SetMarkerColor(14);
  Cociente_100pT__1Electron_ak5FJ->DrawCopy("P");   Cociente_100pT__1Electron_ak5FJ->SetMarkerStyle(25); Cociente_100pT__1Electron_ak5FJ->SetMarkerColor(1);
  Cociente_100pT__1Electron_ak5FJ->SetLineWidth(4); Cociente_100pT__1Electron_ak5FJ->Draw("Esame");      Cociente_100pT__1Electron_ak5FJ->SetLineColor(1);
  Cociente_100pT__1Electron_ak5PFJet->Rebin();
  Cociente_100pT__1Electron_ak5PFJet->SetMarkerSize(4); Cociente_100pT__1Electron_ak5PFJet->SetMarkerStyle(23); Cociente_100pT__1Electron_ak5PFJet->SetMarkerColor(42);
  Cociente_100pT__1Electron_ak5PFJet->DrawCopy("Psame");Cociente_100pT__1Electron_ak5PFJet->SetMarkerStyle(32); Cociente_100pT__1Electron_ak5PFJet->SetMarkerColor(2);
  Cociente_100pT__1Electron_ak5PFJet->SetLineWidth(4);  Cociente_100pT__1Electron_ak5PFJet->Draw("Esame");      Cociente_100pT__1Electron_ak5PFJet->SetLineColor(2);
  Cociente_100pT__1Electron_ak5PFBTag->Rebin();
  Cociente_100pT__1Electron_ak5PFBTag->SetMarkerSize(4); Cociente_100pT__1Electron_ak5PFBTag->SetMarkerStyle(22); Cociente_100pT__1Electron_ak5PFBTag->SetMarkerColor(33);
  Cociente_100pT__1Electron_ak5PFBTag->DrawCopy("Psame");Cociente_100pT__1Electron_ak5PFBTag->SetMarkerStyle(26); Cociente_100pT__1Electron_ak5PFBTag->SetMarkerColor(4);
  Cociente_100pT__1Electron_ak5PFBTag->SetLineWidth(4);  Cociente_100pT__1Electron_ak5PFBTag->Draw("Esame");      Cociente_100pT__1Electron_ak5PFBTag->SetLineColor(4);
  Cociente_100pT__1Electron_ak5PFMinBias->Rebin();
  Cociente_100pT__1Electron_ak5PFMinBias->SetMarkerSize(4); Cociente_100pT__1Electron_ak5PFMinBias->SetMarkerStyle(20); Cociente_100pT__1Electron_ak5PFMinBias->SetMarkerColor(5);
  Cociente_100pT__1Electron_ak5PFMinBias->DrawCopy("Psame");Cociente_100pT__1Electron_ak5PFMinBias->SetMarkerStyle(24); Cociente_100pT__1Electron_ak5PFMinBias->SetMarkerColor(41);
  Cociente_100pT__1Electron_ak5PFMinBias->SetLineWidth(4);  Cociente_100pT__1Electron_ak5PFMinBias->Draw("Esame");      Cociente_100pT__1Electron_ak5PFMinBias->SetLineColor(41);
  Cociente_100pT__1Electron_ak5PFMultiJet->Rebin();
  Cociente_100pT__1Electron_ak5PFMultiJet->SetMarkerSize(4); Cociente_100pT__1Electron_ak5PFMultiJet->SetMarkerStyle(34); Cociente_100pT__1Electron_ak5PFMultiJet->SetMarkerColor(8);
  Cociente_100pT__1Electron_ak5PFMultiJet->DrawCopy("Psame");Cociente_100pT__1Electron_ak5PFMultiJet->SetMarkerStyle(28); Cociente_100pT__1Electron_ak5PFMultiJet->SetMarkerColor(32);
  Cociente_100pT__1Electron_ak5PFMultiJet->SetLineWidth(4);  Cociente_100pT__1Electron_ak5PFMultiJet->Draw("Esame");      Cociente_pT__Electron_ak5PFMultiJet->SetLineColor(32);
  Leg->Draw(); legend->Draw();  Cociente_100pT__1Electron_Jet->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Cociente_pT__Electron1-Jet>100.png"); Cociente_100pT__1Electron_Jet->Close();

}


//###################################################################################################################################################################################

void Vertice() {
  //Abrimos el archivo que nos interesa y el árbol que queremos leer.
  TFile *FJFile = new TFile("/home/saksevul/T/PYTHIA/FastJet/ak5FJ.root");
  TFile *JetFile = new TFile("/home/saksevul/T/OpenData/Jet_20000/ak5PF.root");
  TFile *BTagFile = new TFile("/home/saksevul/T/OpenData/BTag_20000/ak5PF.root");
  TFile *MultiJetFile = new TFile("/home/saksevul/T/OpenData/MultiJet_20000/ak5PF.root");


  TH1F *Muons__fX =(TH1F*)FJFile->Get("Muons__fX"); Muons__fX->Scale(1.0/Muons__fX->Integral());
  TH1F *MuonsJet_fX_ =(TH1F*)JetFile->Get("Muons_fX_"); MuonsJet_fX_->Scale(1.0/MuonsJet_fX_->Integral());
  TH1F *MuonsBTag_fX_ =(TH1F*)BTagFile->Get("Muons_fX_"); MuonsBTag_fX_->Scale(1.0/MuonsBTag_fX_->Integral());
  TH1F *MuonsMultiJet_fX_ =(TH1F*)MultiJetFile->Get("Muons_fX_"); MuonsMultiJet_fX_->Scale(1.0/MuonsMultiJet_fX_->Integral());
  TH1F *Muons__fY =(TH1F*)FJFile->Get("Muons__fY"); Muons__fY->Scale(1.0/Muons__fY->Integral());
  TH1F *MuonsJet_fY_ =(TH1F*)JetFile->Get("Muons_fY_"); MuonsJet_fY_->Scale(1.0/MuonsJet_fY_->Integral());
  TH1F *MuonsBTag_fY_ =(TH1F*)BTagFile->Get("Muons_fY_"); MuonsBTag_fY_->Scale(1.0/MuonsBTag_fY_->Integral());
  TH1F *MuonsMultiJet_fY_ =(TH1F*)MultiJetFile->Get("Muons_fY_"); MuonsMultiJet_fY_->Scale(1.0/MuonsMultiJet_fY_->Integral());
  TH1F *Muons__fZ =(TH1F*)FJFile->Get("Muons__fZ"); Muons__fZ->Scale(1.0/Muons__fZ->Integral());
  TH1F *MuonsJet_fZ_ =(TH1F*)JetFile->Get("Muons_fZ_"); MuonsJet_fZ_->Scale(1.0/MuonsJet_fZ_->Integral());
  TH1F *MuonsBTag_fZ_ =(TH1F*)BTagFile->Get("Muons_fZ_"); MuonsBTag_fZ_->Scale(1.0/MuonsBTag_fZ_->Integral());
  TH1F *MuonsMultiJet_fZ_ =(TH1F*)MultiJetFile->Get("Muons_fZ_"); MuonsMultiJet_fZ_->Scale(1.0/MuonsMultiJet_fZ_->Integral());

  TH1F *Electrons__fX =(TH1F*)FJFile->Get("Electrons__fX"); Electrons__fX->Scale(1.0/Electrons__fX->Integral());
  TH1F *ElectronsJet_fX_ =(TH1F*)JetFile->Get("Electrons_fX_"); ElectronsJet_fX_->Scale(1.0/ElectronsJet_fX_->Integral());
  TH1F *ElectronsBTag_fX_ =(TH1F*)BTagFile->Get("Electrons_fX_"); ElectronsBTag_fX_->Scale(1.0/ElectronsBTag_fX_->Integral());
  TH1F *ElectronsMultiJet_fX_ =(TH1F*)MultiJetFile->Get("Electrons_fX_"); ElectronsMultiJet_fX_->Scale(1.0/ElectronsMultiJet_fX_->Integral());
  TH1F *Electrons__fY =(TH1F*)FJFile->Get("Electrons__fY"); Electrons__fY->Scale(1.0/Electrons__fY->Integral());
  TH1F *ElectronsJet_fY_ =(TH1F*)JetFile->Get("Electrons_fY_"); ElectronsJet_fY_->Scale(1.0/ElectronsJet_fY_->Integral());
  TH1F *ElectronsBTag_fY_ =(TH1F*)BTagFile->Get("Electrons_fY_"); ElectronsBTag_fY_->Scale(1.0/ElectronsBTag_fY_->Integral());
  TH1F *ElectronsMultiJet_fY_ =(TH1F*)MultiJetFile->Get("Electrons_fY_"); ElectronsMultiJet_fY_->Scale(1.0/ElectronsMultiJet_fY_->Integral());
  TH1F *Electrons__fZ =(TH1F*)FJFile->Get("Electrons__fZ"); Electrons__fZ->Scale(1.0/Electrons__fZ->Integral());
  TH1F *ElectronsJet_fZ_ =(TH1F*)JetFile->Get("Electrons_fZ_"); ElectronsJet_fZ_->Scale(1.0/ElectronsJet_fZ_->Integral());
  TH1F *ElectronsBTag_fZ_ =(TH1F*)BTagFile->Get("Electrons_fZ_"); ElectronsBTag_fZ_->Scale(1.0/ElectronsBTag_fZ_->Integral());
  TH1F *ElectronsMultiJet_fZ_ =(TH1F*)MultiJetFile->Get("Electrons_fZ_"); ElectronsMultiJet_fZ_->Scale(1.0/ElectronsMultiJet_fZ_->Integral());



  auto   legend = new TLegend(0.61,0.74,0.90,0.92);    legend->SetTextSize(0.04);
    legend->AddEntry(Muons__fX, "MC FastJet", "lp");
    legend->AddEntry(MuonsJet_fX_, "Open-Data PF Jet", "lp");
    legend->AddEntry(MuonsBTag_fX_, "Open-Data PF BTag", "lp");
    legend->AddEntry(MuonsMultiJet_fX_, "Open-Data PF MultiJet", "lp");



  TCanvas* fX_Muons = new TCanvas("fX_Muons","X vertice de FastJet y PFJets para muones",10,10,1920,1080);
  fX_Muons->SetFillColor(0);  fX_Muons->SetFrameBorderMode(0);  gPad->SetLogy();

    // Esto es para modificar las etiquetas del canvas.
    Muons__fX->SetTitle("Vertice en el eje X para muones; Posicion [cm]; U. A.");
    Muons__fX->GetXaxis()->SetLabelSize(0.05); Muons__fX->GetYaxis()->SetLabelSize(0.05);
    Muons__fX->GetXaxis()->SetTitleSize(0.05); Muons__fX->GetYaxis()->SetTitleSize(0.05);
    Muons__fX->GetXaxis()->SetTitleOffset(1.0);Muons__fX->GetYaxis()->SetTitleOffset(1.0);
    Muons__fX->SetAxisRange(-2, 2, "X");  Muons__fX->SetAxisRange(0.00001, 3, "Y");
    // Aqui ponemos todas las gráficas que necesitamos en el canvas.
    Muons__fX -> Draw("E1"); Muons__fX->SetLineColor(1);
    Muons__fX->SetMarkerStyle(20); Muons__fX->SetMarkerColor(1);
    MuonsJet_fX_ -> Draw("Esame"); MuonsJet_fX_->SetLineColor(2);
    MuonsJet_fX_->SetMarkerStyle(23); MuonsJet_fX_->SetMarkerColor(2);
    MuonsBTag_fX_ -> Draw("Esame"); MuonsBTag_fX_->SetLineColor(9);
    MuonsBTag_fX_->SetMarkerStyle(22); MuonsBTag_fX_->SetMarkerColor(9);
    MuonsMultiJet_fX_ -> Draw("Esame"); MuonsMultiJet_fX_->SetLineColor(32);
    MuonsMultiJet_fX_->SetMarkerStyle(21); MuonsMultiJet_fX_->SetMarkerColor(32);
    legend -> Draw(); fX_Muons -> SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Vertice_Muones_X__FastJet-PFJets.png"); fX_Muons -> Close();


  TCanvas* fY_Muons = new TCanvas("fY_Muons","Y vertice de FastJet y PFJets para muones",10,10,1920,1080);
  fY_Muons->SetFillColor(0);  fY_Muons->SetFrameBorderMode(0);  gPad->SetLogy();

    // Esto es para modificar las etiquetas del canvas.
    Muons__fY->SetTitle("Vertice en el eje Y para muones; Posicion [cm]; U. A.");
    Muons__fY->GetXaxis()->SetLabelSize(0.05); Muons__fY->GetYaxis()->SetLabelSize(0.05);
    Muons__fY->GetXaxis()->SetTitleSize(0.05); Muons__fY->GetYaxis()->SetTitleSize(0.05);
    Muons__fY->GetXaxis()->SetTitleOffset(1.0);Muons__fY->GetYaxis()->SetTitleOffset(1.0);
    Muons__fY->SetAxisRange(-2, 2, "X");  Muons__fY->SetAxisRange(0.00001, 3, "Y");
    // Aqui ponemos todas las gráficas que necesitamos en el canvas.
    Muons__fY -> Draw("E1"); Muons__fY->SetLineColor(1);
    Muons__fY->SetMarkerStyle(20); Muons__fY->SetMarkerColor(1);
    MuonsJet_fY_ -> Draw("Esame"); MuonsJet_fY_->SetLineColor(2);
    MuonsJet_fY_->SetMarkerStyle(23); MuonsJet_fY_->SetMarkerColor(2);
    MuonsBTag_fY_ -> Draw("Esame"); MuonsBTag_fY_->SetLineColor(9);
    MuonsBTag_fY_->SetMarkerStyle(22); MuonsBTag_fY_->SetMarkerColor(9);
    MuonsMultiJet_fY_ -> Draw("Esame"); MuonsMultiJet_fY_->SetLineColor(32);
    MuonsMultiJet_fY_->SetMarkerStyle(21); MuonsMultiJet_fY_->SetMarkerColor(32);
    legend -> Draw(); fY_Muons -> SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Vertice_Muones_Y__FastJet-PFJets.png"); fY_Muons -> Close();


  TCanvas* fZ_Muons = new TCanvas("fZ_Muons","X vertice de FastJet y PFJets para muones",10,10,1920,1080);
  fZ_Muons->SetFillColor(0);  fZ_Muons->SetFrameBorderMode(0);  gPad->SetLogy();

    // Esto es para modificar las etiquetas del canvas.
    Muons__fZ->SetTitle("Vertice en el eje Z para muones; Posicion [cm]; U. A.");
    Muons__fZ->GetXaxis()->SetLabelSize(0.05); Muons__fZ->GetYaxis()->SetLabelSize(0.05);
    Muons__fZ->GetXaxis()->SetTitleSize(0.05); Muons__fZ->GetYaxis()->SetTitleSize(0.05);
    Muons__fZ->GetXaxis()->SetTitleOffset(1.0);Muons__fZ->GetYaxis()->SetTitleOffset(1.0);
    Muons__fZ->SetAxisRange(-2, 2, "X");  Muons__fZ->SetAxisRange(0.00001, 3, "Y");
    // Aqui ponemos todas las gráficas que necesitamos en el canvas.
    Muons__fZ -> Draw("E1"); Muons__fZ->SetLineColor(1);
    Muons__fZ->SetMarkerStyle(20); Muons__fZ->SetMarkerColor(1);
    MuonsJet_fZ_ -> Draw("Esame"); MuonsJet_fZ_->SetLineColor(2);
    MuonsJet_fZ_->SetMarkerStyle(23); MuonsJet_fZ_->SetMarkerColor(2);
    MuonsBTag_fZ_ -> Draw("Esame"); MuonsBTag_fZ_->SetLineColor(9);
    MuonsBTag_fZ_->SetMarkerStyle(22); MuonsBTag_fZ_->SetMarkerColor(9);
    MuonsMultiJet_fZ_ -> Draw("Esame"); MuonsMultiJet_fZ_->SetLineColor(32);
    MuonsMultiJet_fZ_->SetMarkerStyle(21); MuonsMultiJet_fZ_->SetMarkerColor(32);
    legend -> Draw(); fZ_Muons -> SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Vertice_Muones_Z__FastJet-PFJets.png"); fZ_Muons -> Close();



  TCanvas* fX_Electrons = new TCanvas("fX_Electrons","X vertice de FastJet y PFJets para electrones",10,10,1920,1080);
  fX_Electrons->SetFillColor(0);  fX_Electrons->SetFrameBorderMode(0);  gPad->SetLogy();

    // Esto es para modificar las etiquetas del canvas.
    Electrons__fX->SetTitle("Vertice en el eje X para electrones; Posicion [cm]; U. A.");
    Electrons__fX->GetXaxis()->SetLabelSize(0.05); Electrons__fX->GetYaxis()->SetLabelSize(0.05);
    Electrons__fX->GetXaxis()->SetTitleSize(0.05); Electrons__fX->GetYaxis()->SetTitleSize(0.05);
    Electrons__fX->GetXaxis()->SetTitleOffset(1.0);Electrons__fX->GetYaxis()->SetTitleOffset(1.0);
    Electrons__fX->SetAxisRange(-2, 2, "X");  Electrons__fX->SetAxisRange(0.00001, 3, "Y");
    // Aqui ponemos todas las gráficas que necesitamos en el canvas.
    Electrons__fX -> Draw("E1"); Electrons__fX->SetLineColor(1);
    Electrons__fX->SetMarkerStyle(20); Electrons__fX->SetMarkerColor(1);
    ElectronsJet_fX_ -> Draw("Esame"); ElectronsJet_fX_->SetLineColor(2);
    ElectronsJet_fX_->SetMarkerStyle(23); ElectronsJet_fX_->SetMarkerColor(2);
    ElectronsBTag_fX_ -> Draw("Esame"); ElectronsBTag_fX_->SetLineColor(9);
    ElectronsBTag_fX_->SetMarkerStyle(22); ElectronsBTag_fX_->SetMarkerColor(9);
    ElectronsMultiJet_fX_ -> Draw("Esame"); ElectronsMultiJet_fX_->SetLineColor(32);
    ElectronsMultiJet_fX_->SetMarkerStyle(21); ElectronsMultiJet_fX_->SetMarkerColor(32);
    legend -> Draw(); fX_Electrons -> SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Vertice_Electrones_X__FastJet-PFJets.png"); fX_Electrons -> Close();


  TCanvas* fY_Electrons = new TCanvas("fY_Electrons","Y vertice de FastJet y PFJets para electrones",10,10,1920,1080);
  fY_Electrons->SetFillColor(0);  fY_Electrons->SetFrameBorderMode(0);  gPad->SetLogy();

    // Esto es para modificar las etiquetas del canvas.
    Electrons__fY->SetTitle("Vertice en el eje Y para electrones; Posicion [cm]; U. A.");
    Electrons__fY->GetXaxis()->SetLabelSize(0.05); Electrons__fY->GetYaxis()->SetLabelSize(0.05);
    Electrons__fY->GetXaxis()->SetTitleSize(0.05); Electrons__fY->GetYaxis()->SetTitleSize(0.05);
    Electrons__fY->GetXaxis()->SetTitleOffset(1.0);Electrons__fY->GetYaxis()->SetTitleOffset(1.0);
    Electrons__fY->SetAxisRange(-2, 2, "X");  Electrons__fY->SetAxisRange(0.00001, 3, "Y");
    // Aqui ponemos todas las gráficas que necesitamos en el canvas.
    Electrons__fY -> Draw("E1"); Electrons__fY->SetLineColor(1);
    Electrons__fY->SetMarkerStyle(20); Electrons__fY->SetMarkerColor(1);
    ElectronsJet_fY_ -> Draw("Esame"); ElectronsJet_fY_->SetLineColor(2);
    ElectronsJet_fY_->SetMarkerStyle(23); ElectronsJet_fY_->SetMarkerColor(2);
    ElectronsBTag_fY_ -> Draw("Esame"); ElectronsBTag_fY_->SetLineColor(9);
    ElectronsBTag_fY_->SetMarkerStyle(22); ElectronsBTag_fY_->SetMarkerColor(9);
    ElectronsMultiJet_fY_ -> Draw("Esame"); ElectronsMultiJet_fY_->SetLineColor(32);
    ElectronsMultiJet_fY_->SetMarkerStyle(21); ElectronsMultiJet_fY_->SetMarkerColor(32);
    legend -> Draw(); fY_Electrons -> SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Vertice_Electrones_Y__FastJet-PFJets.png"); fY_Electrons -> Close();


  TCanvas* fZ_Electrons = new TCanvas("fZ_Electrons","X vertice de FastJet y PFJets para electrones",10,10,1920,1080);
  fZ_Electrons->SetFillColor(0);  fZ_Electrons->SetFrameBorderMode(0);  gPad->SetLogy();

    // Esto es para modificar las etiquetas del canvas.
    Electrons__fZ->SetTitle("Vertice en el eje Z para electrones; Posicion [cm]; U. A.");
    Electrons__fZ->GetXaxis()->SetLabelSize(0.05); Electrons__fZ->GetYaxis()->SetLabelSize(0.05);
    Electrons__fZ->GetXaxis()->SetTitleSize(0.05); Electrons__fZ->GetYaxis()->SetTitleSize(0.05);
    Electrons__fZ->GetXaxis()->SetTitleOffset(1.0);Electrons__fZ->GetYaxis()->SetTitleOffset(1.0);
    Electrons__fZ->SetAxisRange(-2, 2, "X");  Electrons__fZ->SetAxisRange(0.00001, 3, "Y");
    // Aqui ponemos todas las gráficas que necesitamos en el canvas.
    Electrons__fZ -> Draw("E1"); Electrons__fZ->SetLineColor(1);
    Electrons__fZ->SetMarkerStyle(20); Electrons__fZ->SetMarkerColor(1);
    ElectronsJet_fZ_ -> Draw("Esame"); ElectronsJet_fZ_->SetLineColor(2);
    ElectronsJet_fZ_->SetMarkerStyle(23); ElectronsJet_fZ_->SetMarkerColor(2);
    ElectronsBTag_fZ_ -> Draw("Esame"); ElectronsBTag_fZ_->SetLineColor(9);
    ElectronsBTag_fZ_->SetMarkerStyle(22); ElectronsBTag_fZ_->SetMarkerColor(9);
    ElectronsMultiJet_fZ_ -> Draw("Esame"); ElectronsMultiJet_fZ_->SetLineColor(32);
    ElectronsMultiJet_fZ_->SetMarkerStyle(21); ElectronsMultiJet_fZ_->SetMarkerColor(32);
    legend -> Draw(); fZ_Electrons -> SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Vertice_Electrones_Z__FastJet-PFJets.png"); fZ_Electrons -> Close();

}

//###################################################################################################################################################################################

void rootMacro(){
  // // Le damos algo de personalización al las gráficas.
  // gROOT->ForceStyle();
  // gStyle->SetPadBorderMode(0);    gStyle->SetPadBorderSize(0);
  // gStyle->SetPadTopMargin(0.08);  gStyle->SetPadBottomMargin(0.12);
  // gStyle->SetPadLeftMargin(0.10); gStyle->SetPadRightMargin(0.10);
  // gStyle->SetOptStat(0);          gStyle->SetOptTitle(1);


  // Corremos los macros que nos interesan.
  // DistanciaAngular();
  // EnergyQuotient();
  Limits();
  // pTQuotient();
  // Multiplicidad();
  // Vertice();

}
