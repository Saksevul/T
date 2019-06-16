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

  ak5PFJet__D_Jet_Jet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/D_Jet-Jet FastJet y PFJets.png"); ak5PFJet__D_Jet_Jet -> Close();

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

  TH1F *MuonsFJ_eta_ =(TH1F*)FJFile->Get("Muons_eta_"); MuonsFJ_eta_->Scale(1.0/MuonsFJ_eta_->Integral());
  TH1F *MuonsJet_eta_ =(TH1F*)JetFile->Get("Muons_eta_"); MuonsJet_eta_->Scale(1.0/MuonsJet_eta_->Integral());
  TH1F *MuonsBTag_eta_ =(TH1F*)BTagFile->Get("Muons_eta_"); MuonsBTag_eta_->Scale(1.0/MuonsBTag_eta_->Integral());
  TH1F *MuonsMinBias_eta_ =(TH1F*)MinBiasFile->Get("Muons_eta_"); MuonsMinBias_eta_->Scale(1.0/MuonsMinBias_eta_->Integral());
  TH1F *MuonsMultiJet_eta_ =(TH1F*)MultiJetFile->Get("Muons_eta_"); MuonsMultiJet_eta_->Scale(1.0/MuonsMultiJet_eta_->Integral());


  TH1F *PhotonsFJ_pt_ =(TH1F*)FJFile->Get("Photons_pt_"); PhotonsFJ_pt_->Scale(1.0/PhotonsFJ_pt_->Integral());
  TH1F *PhotonsJet_pt_ =(TH1F*)JetFile->Get("Photons_pt_"); PhotonsJet_pt_->Scale(1.0/PhotonsJet_pt_->Integral());
  TH1F *PhotonsBTag_pt_ =(TH1F*)BTagFile->Get("Photons_pt_"); PhotonsBTag_pt_->Scale(1.0/PhotonsBTag_pt_->Integral());
  TH1F *PhotonsMinBias_pt_ =(TH1F*)MinBiasFile->Get("Photons_pt_"); PhotonsMinBias_pt_->Scale(1.0/PhotonsMinBias_pt_->Integral());
  TH1F *PhotonsMultiJet_pt_ =(TH1F*)MultiJetFile->Get("Photons_pt_"); PhotonsMultiJet_pt_->Scale(1.0/PhotonsMultiJet_pt_->Integral());

  TH1F *PhotonsFJ_eta_ =(TH1F*)FJFile->Get("Photons_eta_"); PhotonsFJ_eta_->Scale(1.0/PhotonsFJ_eta_->Integral());
  TH1F *PhotonsJet_eta_ =(TH1F*)JetFile->Get("Photons_eta_"); PhotonsJet_eta_->Scale(1.0/PhotonsJet_eta_->Integral());
  TH1F *PhotonsBTag_eta_ =(TH1F*)BTagFile->Get("Photons_eta_"); PhotonsBTag_eta_->Scale(1.0/PhotonsBTag_eta_->Integral());
  TH1F *PhotonsMinBias_eta_ =(TH1F*)MinBiasFile->Get("Photons_eta_"); PhotonsMinBias_eta_->Scale(1.0/PhotonsMinBias_eta_->Integral());
  TH1F *PhotonsMultiJet_eta_ =(TH1F*)MultiJetFile->Get("Photons_eta_"); PhotonsMultiJet_eta_->Scale(1.0/PhotonsMultiJet_eta_->Integral());


  TH1F *ElectronsFJ_pt_ =(TH1F*)FJFile->Get("Electrons_pt_"); ElectronsFJ_pt_->Scale(1.0/ElectronsFJ_pt_->Integral());
  TH1F *ElectronsJet_pt_ =(TH1F*)JetFile->Get("Electrons_pt_"); ElectronsJet_pt_->Scale(1.0/ElectronsJet_pt_->Integral());
  TH1F *ElectronsBTag_pt_ =(TH1F*)BTagFile->Get("Electrons_pt_"); ElectronsBTag_pt_->Scale(1.0/ElectronsBTag_pt_->Integral());
  TH1F *ElectronsMinBias_pt_ =(TH1F*)MinBiasFile->Get("Electrons_pt_"); ElectronsMinBias_pt_->Scale(1.0/ElectronsMinBias_pt_->Integral());
  TH1F *ElectronsMultiJet_pt_ =(TH1F*)MultiJetFile->Get("Electrons_pt_"); ElectronsMultiJet_pt_->Scale(1.0/ElectronsMultiJet_pt_->Integral());

  TH1F *ElectronsFJ_eta_ =(TH1F*)FJFile->Get("Electrons_eta_"); ElectronsFJ_eta_->Scale(1.0/ElectronsFJ_eta_->Integral());
  TH1F *ElectronsJet_eta_ =(TH1F*)JetFile->Get("Electrons_eta_"); ElectronsJet_eta_->Scale(1.0/ElectronsJet_eta_->Integral());
  TH1F *ElectronsBTag_eta_ =(TH1F*)BTagFile->Get("Electrons_eta_"); ElectronsBTag_eta_->Scale(1.0/ElectronsBTag_eta_->Integral());
  TH1F *ElectronsMinBias_eta_ =(TH1F*)MinBiasFile->Get("Electrons_eta_"); ElectronsMinBias_eta_->Scale(1.0/ElectronsMinBias_eta_->Integral());
  TH1F *ElectronsMultiJet_eta_ =(TH1F*)MultiJetFile->Get("Electrons_eta_"); ElectronsMultiJet_eta_->Scale(1.0/ElectronsMultiJet_eta_->Integral());


  TH1F *ak5FJ_pt_ =(TH1F*)FJFile->Get("ak5FastJet_pt_"); ak5FJ_pt_->Scale(1.0/ak5FJ_pt_->Integral());
  TH1F *ak5PFJet_pt_ =(TH1F*)JetFile->Get("ak5PFJets_pt_"); ak5PFJet_pt_->Scale(1.0/ak5PFJet_pt_->Integral());
  TH1F *ak5PFBTag_pt_ =(TH1F*)BTagFile->Get("ak5PFJets_pt_"); ak5PFBTag_pt_->Scale(1.0/ak5PFBTag_pt_->Integral());
  TH1F *ak5PFMinBias_pt_ =(TH1F*)MinBiasFile->Get("ak5PFJets_pt_"); ak5PFMinBias_pt_->Scale(1.0/ak5PFMinBias_pt_->Integral());
  TH1F *ak5PFMultiJet_pt_ =(TH1F*)MultiJetFile->Get("ak5PFJets_pt_"); ak5PFMultiJet_pt_->Scale(1.0/ak5PFMultiJet_pt_->Integral());

  TH1F *ak5FJ_eta_ =(TH1F*)FJFile->Get("ak5FastJet_eta_"); ak5FJ_eta_->Scale(1.0/ak5FJ_eta_->Integral());
  TH1F *ak5PFJet_eta_ =(TH1F*)JetFile->Get("ak5PFJets_eta_"); ak5PFJet_eta_->Scale(1.0/ak5PFJet_eta_->Integral());
  TH1F *ak5PFBTag_eta_ =(TH1F*)BTagFile->Get("ak5PFJets_eta_"); ak5PFBTag_eta_->Scale(1.0/ak5PFBTag_eta_->Integral());
  TH1F *ak5PFMinBias_eta_ =(TH1F*)MinBiasFile->Get("ak5PFJets_eta_"); ak5PFMinBias_eta_->Scale(1.0/ak5PFMinBias_eta_->Integral());
  TH1F *ak5PFMultiJet_eta_ =(TH1F*)MultiJetFile->Get("ak5PFJets_eta_"); ak5PFMultiJet_eta_->Scale(1.0/ak5PFMultiJet_eta_->Integral());



  auto   legend = new TLegend(0.63,0.68,0.90,0.92);    legend->SetTextSize(0.04);
    legend->AddEntry(MuonsFJ_pt_, "MC Simulaci#acute{o}n", "l");
    legend->AddEntry(MuonsJet_pt_, "Open-Data PF Jet", "l");
    legend->AddEntry(MuonsBTag_pt_, "Open-Data PF BTag", "l");
    legend->AddEntry(MuonsMinBias_pt_, "Open-Data PF MinBias", "l");
    legend->AddEntry(MuonsMultiJet_pt_, "Open-Data PF MultiJet", "l");



  TCanvas* Limite_Muones_pT = new TCanvas("Limite pT Muones","Limite de pT para Muones",10,10,1920,1080);
  Limite_Muones_pT->SetFillColor(0);  Limite_Muones_pT->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  MuonsFJ_pt_->SetTitle("Espectro de p_{T} para Muones; p_{T} [GeV]; U. A.");
  MuonsFJ_pt_->GetXaxis()->SetLabelSize(0.05); MuonsFJ_pt_->GetYaxis()->SetLabelSize(0.05);
  MuonsFJ_pt_->GetXaxis()->SetTitleSize(0.05); MuonsFJ_pt_->GetYaxis()->SetTitleSize(0.05);
  MuonsFJ_pt_->GetXaxis()->SetTitleOffset(1.0);MuonsFJ_pt_->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  MuonsFJ_pt_ -> Draw("HIST"); MuonsFJ_pt_->SetLineColor(1); MuonsFJ_pt_->SetLineWidth(2);
  MuonsFJ_pt_->SetMarkerStyle(20); MuonsFJ_pt_->SetMarkerColor(1); MuonsFJ_pt_->SetMarkerSize(2);
  MuonsJet_pt_ -> Draw("HISTsame"); MuonsJet_pt_->SetLineColor(2); MuonsJet_pt_->SetLineWidth(2);
  MuonsJet_pt_->SetMarkerStyle(20); MuonsJet_pt_->SetMarkerColor(2); MuonsJet_pt_->SetMarkerSize(2);
  MuonsBTag_pt_ -> Draw("HISTsame"); MuonsBTag_pt_->SetLineColor(4); MuonsBTag_pt_->SetLineWidth(2);
  MuonsBTag_pt_->SetMarkerStyle(23); MuonsBTag_pt_->SetMarkerColor(4); MuonsBTag_pt_->SetMarkerSize(2);
  MuonsMinBias_pt_ -> Draw("HISTsame"); MuonsMinBias_pt_->SetLineColor(41); MuonsMinBias_pt_->SetLineWidth(2);
  MuonsMinBias_pt_->SetMarkerStyle(23); MuonsMinBias_pt_->SetMarkerColor(41); MuonsMinBias_pt_->SetMarkerSize(2);
  MuonsMultiJet_pt_ -> Draw("HISTsame"); MuonsMultiJet_pt_->SetLineColor(32); MuonsMultiJet_pt_->SetLineWidth(2);
  MuonsMultiJet_pt_->SetMarkerStyle(23); MuonsMultiJet_pt_->SetMarkerColor(32); MuonsMultiJet_pt_->SetMarkerSize(2);
  legend -> Draw(); Limite_Muones_pT -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Limite_Muon_pT.png"); Limite_Muones_pT -> Close();

  TCanvas* Limite_Muones_eta = new TCanvas("Limite eta Muones","Limite de #eta para Muones",10,10,1920,1080);
  Limite_Muones_eta->SetFillColor(0);  Limite_Muones_eta->SetFrameBorderMode(0);  gPad->SetLogy();
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
  legend -> Draw(); Limite_Muones_eta -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Limite_Muon_eta.png"); Limite_Muones_eta -> Close();


  TCanvas* Limite_Fotones_pT = new TCanvas("Limite pT Fotones","Limite de pT para Fotones",10,10,1920,1080);
  Limite_Fotones_pT->SetFillColor(0);  Limite_Fotones_pT->SetFrameBorderMode(0);  gPad->SetLogy();
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
  legend -> Draw(); Limite_Fotones_pT -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Limite_Foton_pT.png"); Limite_Fotones_pT -> Close();

  TCanvas* Limite_Fotones_eta = new TCanvas("Limite eta Fotones","Limite de #eta para Fotones",10,10,1920,1080);
  Limite_Fotones_eta->SetFillColor(0);  Limite_Fotones_eta->SetFrameBorderMode(0);  gPad->SetLogy();
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
  legend -> Draw(); Limite_Fotones_eta -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Limite_Foton_eta.png"); Limite_Fotones_eta -> Close();


  TCanvas* Limite_Electrones_pT = new TCanvas("Limite pT Electrones","Limite de pT para Electrones",10,10,1920,1080);
  Limite_Electrones_pT->SetFillColor(0);  Limite_Electrones_pT->SetFrameBorderMode(0);  gPad->SetLogy();
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
  legend -> Draw(); Limite_Electrones_pT -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Limite_Electrons_pT.png"); Limite_Electrones_pT -> Close();

  TCanvas* Limite_Electrones_eta = new TCanvas("Limite eta Electrones","Limite de #eta para Electrones",10,10,1920,1080);
  Limite_Electrones_eta->SetFillColor(0);  Limite_Electrones_eta->SetFrameBorderMode(0);  gPad->SetLogy();
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
  legend -> Draw(); Limite_Electrones_eta -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Limite_Electrons_eta.png"); Limite_Electrones_eta -> Close();


  TCanvas* Limite_Jets_pT = new TCanvas("Limite pT Jets","Limite de pT para Jets",10,10,1920,1080);
  Limite_Jets_pT->SetFillColor(0);  Limite_Jets_pT->SetFrameBorderMode(0);  gPad->SetLogy();
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
  legend -> Draw(); Limite_Jets_pT -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Limite_Jets_pT.png"); Limite_Jets_pT -> Close();

  TCanvas* Limite_Jets_eta = new TCanvas("Limite eta Jets","Limite de #eta para Jets",10,10,1920,1080);
  Limite_Jets_eta->SetFillColor(0);  Limite_Jets_eta->SetFrameBorderMode(0);  gPad->SetLogy();
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
  legend -> Draw(); Limite_Jets_eta -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Limite_Jets_eta.png"); Limite_Jets_eta -> Close();
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

  Espectro_Multiplicidad__Jets -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Multiplicidad__FastJet-PFJets.png"); Espectro_Multiplicidad__Jets -> Close();

}

//###################################################################################################################################################################################

void pT() {
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


/*
  TH1F *ak5FastJet__pT =(TH1F*)FJFile->Get("ak5FastJet__pT"); ak5FastJet__pT->Scale(1.0/ak5FastJet__pT->Integral());
  TH1F *ak5PFJet_pt_ =(TH1F*)JetFile->Get("ak5PFJets_pt_"); ak5PFJet_pt_->Scale(1.0/ak5PFJet_pt_->Integral());
  TH1F *ak5PFBTag_pt_ =(TH1F*)BTagFile->Get("ak5PFJets_pt_"); ak5PFBTag_pt_->Scale(1.0/ak5PFBTag_pt_->Integral());
  TH1F *ak5PFMultiJet_pt_ =(TH1F*)MultiJetFile->Get("ak5PFJets_pt_"); ak5PFMultiJet_pt_->Scale(1.0/ak5PFMultiJet_pt_->Integral());

  TH1F *Muons_pt_ =(TH1F*)FJFile->Get("Muons_pt_"); Muons_pt_->Scale(1.0/Muons_pt_->Integral());
  TH1F *MuonsJet_pt_ =(TH1F*)JetFile->Get("Muons_pt_"); MuonsJet_pt_->Scale(1.0/MuonsJet_pt_->Integral());
  TH1F *MuonsBTag_pt_ =(TH1F*)BTagFile->Get("Muons_pt_"); MuonsBTag_pt_->Scale(1.0/MuonsBTag_pt_->Integral());
  TH1F *MuonsMultiJet_pt_ =(TH1F*)MultiJetFile->Get("Muons_pt_"); MuonsMultiJet_pt_->Scale(1.0/MuonsMultiJet_pt_->Integral());

  TH1F *Electrons_pt_ =(TH1F*)FJFile->Get("Electrons_pt_"); Electrons_pt_->Scale(1.0/Electrons_pt_->Integral());
  TH1F *ElectronsJet_pt_ =(TH1F*)JetFile->Get("Electrons_pt_"); ElectronsJet_pt_->Scale(1.0/ElectronsJet_pt_->Integral());
  TH1F *ElectronsBTag_pt_ =(TH1F*)BTagFile->Get("Electrons_pt_"); ElectronsBTag_pt_->Scale(1.0/ElectronsBTag_pt_->Integral());
  TH1F *ElectronsMultiJet_pt_ =(TH1F*)MultiJetFile->Get("Electrons_pt_"); ElectronsMultiJet_pt_->Scale(1.0/ElectronsMultiJet_pt_->Integral());
*/


  TH1F *Cociente_pT__Muon_ak5FJ =(TH1F*)FJFile->Get("Cociente_pT__Muon-ak5FastJet"); Cociente_pT__Muon_ak5FJ->Scale(1.0/Cociente_pT__Muon_ak5FJ->Integral());
  TH1F *Cociente_pT__Muon_ak5PFJet =(TH1F*)JetFile->Get("Cociente_pT__Muon-ak5PFJet"); Cociente_pT__Muon_ak5PFJet->Scale(1.0/Cociente_pT__Muon_ak5PFJet->Integral());
  TH1F *Cociente_pT__Muon_ak5PFBTag =(TH1F*)BTagFile->Get("Cociente_pT__Muon-ak5PFJet"); Cociente_pT__Muon_ak5PFBTag->Scale(1.0/Cociente_pT__Muon_ak5PFBTag->Integral());
  TH1F *Cociente_pT__Muon_ak5PFMinBias =(TH1F*)MinBiasFile->Get("Cociente_pT__Muon-ak5PFJet"); Cociente_pT__Muon_ak5PFMinBias->Scale(1.0/Cociente_pT__Muon_ak5PFMinBias->Integral());
  TH1F *Cociente_pT__Muon_ak5PFMultiJet =(TH1F*)MultiJetFile->Get("Cociente_pT__Muon-ak5PFJet"); Cociente_pT__Muon_ak5PFMultiJet->Scale(1.0/Cociente_pT__Muon_ak5PFMultiJet->Integral());

  TH1F *CLON_C_pT__Muon_ak5FJ =(TH1F*)Cociente_pT__Muon_ak5FJ->Clone();
  TH1F *CLON_C_pT__Muon_ak5PFJet =(TH1F*)Cociente_pT__Muon_ak5PFJet->Clone();
  TH1F *CLON_C_pT__Muon_ak5PFBTag =(TH1F*)Cociente_pT__Muon_ak5PFBTag->Clone();
  TH1F *CLON_C_pT__Muon_ak5PFMinBias =(TH1F*)Cociente_pT__Muon_ak5PFMinBias->Clone();
  TH1F *CLON_C_pT__Muon_ak5PFMultiJet =(TH1F*)Cociente_pT__Muon_ak5PFMultiJet->Clone();

  TH1F *Cociente_pT__Muon01_ak5FJ = (TH1F*)FJFile->Get("Cociente01_pT__Muon-ak5FastJet");Cociente_pT__Muon01_ak5FJ->Scale(1.0/Cociente_pT__Muon01_ak5FJ->Integral());
  TH1F *Cociente_pT__Muon02_ak5FJ = (TH1F*)FJFile->Get("Cociente02_pT__Muon-ak5FastJet");Cociente_pT__Muon02_ak5FJ->Scale(1.0/Cociente_pT__Muon02_ak5FJ->Integral());
  TH1F *Cociente_pT__Muon03_ak5FJ = (TH1F*)FJFile->Get("Cociente03_pT__Muon-ak5FastJet");Cociente_pT__Muon03_ak5FJ->Scale(1.0/Cociente_pT__Muon03_ak5FJ->Integral());
  TH1F *Cociente_pT__Muon04_ak5FJ = (TH1F*)FJFile->Get("Cociente04_pT__Muon-ak5FastJet");Cociente_pT__Muon04_ak5FJ->Scale(1.0/Cociente_pT__Muon04_ak5FJ->Integral());
  TH1F *Cociente_pT__Muon05_ak5FJ = (TH1F*)FJFile->Get("Cociente05_pT__Muon-ak5FastJet");Cociente_pT__Muon05_ak5FJ->Scale(1.0/Cociente_pT__Muon05_ak5FJ->Integral());
  TH1F *Cociente_pT__Muon21_ak5FJ = (TH1F*)FJFile->Get("Cociente21_pT__Muon-ak5FastJet");Cociente_pT__Muon21_ak5FJ->Scale(1.0/Cociente_pT__Muon21_ak5FJ->Integral());

  TH1F *Cociente_pT100__1Muon_ak5FJ =(TH1F*)FJFile->Get("Cociente_pT<100__1Muon-ak5FastJet");  Cociente_pT100__1Muon_ak5FJ->Scale(1.0/Cociente_pT100__1Muon_ak5FJ->Integral());
  TH1F *Cociente_pT100__1Muon_ak5PFJet =(TH1F*)JetFile->Get("Cociente_pT<100__1Muon-ak5PFJet");   Cociente_pT100__1Muon_ak5PFJet->Scale(1.0/Cociente_pT100__1Muon_ak5PFJet->Integral());
  TH1F *Cociente_pT100__1Muon_ak5PFBTag =(TH1F*)BTagFile->Get("Cociente_pT<100__1Muon-ak5PFJet");   Cociente_pT100__1Muon_ak5PFBTag->Scale(1.0/Cociente_pT100__1Muon_ak5PFBTag->Integral());
  TH1F *Cociente_pT100__1Muon_ak5PFMinBias =(TH1F*)MinBiasFile->Get("Cociente_pT<100__1Muon-ak5PFJet");   Cociente_pT100__1Muon_ak5PFMinBias->Scale(1.0/Cociente_pT100__1Muon_ak5PFMinBias->Integral());
  TH1F *Cociente_pT100__1Muon_ak5PFMultiJet =(TH1F*)MultiJetFile->Get("Cociente_pT<100__1Muon-ak5PFJet");   Cociente_pT100__1Muon_ak5PFMultiJet->Scale(1.0/Cociente_pT100__1Muon_ak5PFMultiJet->Integral());

  TH1F *Cociente_100pT__1Muon_ak5FJ =(TH1F*)FJFile->Get("Cociente_pT>100__1Muon-ak5FastJet");  Cociente_100pT__1Muon_ak5FJ->Scale(1.0/Cociente_100pT__1Muon_ak5FJ->Integral());
  TH1F *Cociente_100pT__1Muon_ak5PFJet =(TH1F*)JetFile->Get("Cociente_pT>100__1Muon-ak5PFJet");   Cociente_100pT__1Muon_ak5PFJet->Scale(1.0/Cociente_100pT__1Muon_ak5PFJet->Integral());
  TH1F *Cociente_100pT__1Muon_ak5PFBTag =(TH1F*)BTagFile->Get("Cociente_pT>100__1Muon-ak5PFJet");   Cociente_100pT__1Muon_ak5PFBTag->Scale(1.0/Cociente_100pT__1Muon_ak5PFBTag->Integral());
  TH1F *Cociente_100pT__1Muon_ak5PFMinBias =(TH1F*)MinBiasFile->Get("Cociente_pT>100__1Muon-ak5PFJet");   Cociente_100pT__1Muon_ak5PFMinBias->Scale(1.0/Cociente_100pT__1Muon_ak5PFMinBias->Integral());
  TH1F *Cociente_100pT__1Muon_ak5PFMultiJet =(TH1F*)MultiJetFile->Get("Cociente_pT>100__1Muon-ak5PFJet");   Cociente_100pT__1Muon_ak5PFMultiJet->Scale(1.0/Cociente_100pT__1Muon_ak5PFMultiJet->Integral());

  TH1F *Cociente_pT__Electron_ak5FJ =(TH1F*)FJFile->Get("Cociente_pT__Electron-ak5FastJet");  Cociente_pT__Electron_ak5FJ->Scale(1.0/Cociente_pT__Electron_ak5FJ->Integral());
  TH1F *Cociente_pT__Electron_ak5PFJet =(TH1F*)JetFile->Get("Cociente_pT__Electron-ak5PFJet");   Cociente_pT__Electron_ak5PFJet->Scale(1.0/Cociente_pT__Electron_ak5PFJet->Integral());
  TH1F *Cociente_pT__Electron_ak5PFBTag =(TH1F*)BTagFile->Get("Cociente_pT__Electron-ak5PFJet");   Cociente_pT__Electron_ak5PFBTag->Scale(1.0/Cociente_pT__Electron_ak5PFBTag->Integral());
  TH1F *Cociente_pT__Electron_ak5PFMinBias =(TH1F*)MinBiasFile->Get("Cociente_pT__Electron-ak5PFJet");   Cociente_pT__Electron_ak5PFMinBias->Scale(1.0/Cociente_pT__Electron_ak5PFMinBias->Integral());
  TH1F *Cociente_pT__Electron_ak5PFMultiJet =(TH1F*)MultiJetFile->Get("Cociente_pT__Electron-ak5PFJet");   Cociente_pT__Electron_ak5PFMultiJet->Scale(1.0/Cociente_pT__Electron_ak5PFMultiJet->Integral());

  TH1F *Cociente_pT__Electron01_ak5FJ = (TH1F*)FJFile->Get("Cociente01_pT__Electron-ak5FastJet");Cociente_pT__Electron01_ak5FJ->Scale(1.0/Cociente_pT__Electron01_ak5FJ->Integral());
  TH1F *Cociente_pT__Electron02_ak5FJ = (TH1F*)FJFile->Get("Cociente02_pT__Electron-ak5FastJet");Cociente_pT__Electron02_ak5FJ->Scale(1.0/Cociente_pT__Electron02_ak5FJ->Integral());
  TH1F *Cociente_pT__Electron03_ak5FJ = (TH1F*)FJFile->Get("Cociente03_pT__Electron-ak5FastJet");Cociente_pT__Electron03_ak5FJ->Scale(1.0/Cociente_pT__Electron03_ak5FJ->Integral());
  TH1F *Cociente_pT__Electron04_ak5FJ = (TH1F*)FJFile->Get("Cociente04_pT__Electron-ak5FastJet");Cociente_pT__Electron04_ak5FJ->Scale(1.0/Cociente_pT__Electron04_ak5FJ->Integral());
  TH1F *Cociente_pT__Electron05_ak5FJ = (TH1F*)FJFile->Get("Cociente05_pT__Electron-ak5FastJet");Cociente_pT__Electron05_ak5FJ->Scale(1.0/Cociente_pT__Electron05_ak5FJ->Integral());
  TH1F *Cociente_pT__Electron21_ak5FJ = (TH1F*)FJFile->Get("Cociente21_pT__Electron-ak5FastJet");Cociente_pT__Electron21_ak5FJ->Scale(1.0/Cociente_pT__Electron21_ak5FJ->Integral());

  TH1F *Cociente_pT100__1Electron_ak5FJ =(TH1F*)FJFile->Get("Cociente_pT<100__1Electron-ak5FastJet");  Cociente_pT100__1Electron_ak5FJ->Scale(1.0/Cociente_pT100__1Electron_ak5FJ->Integral());
  TH1F *Cociente_pT100__1Electron_ak5PFJet =(TH1F*)JetFile->Get("Cociente_pT<100__1Electron-ak5PFJet");   Cociente_pT100__1Electron_ak5PFJet->Scale(1.0/Cociente_pT100__1Electron_ak5PFJet->Integral());
  TH1F *Cociente_pT100__1Electron_ak5PFBTag =(TH1F*)BTagFile->Get("Cociente_pT<100__1Electron-ak5PFJet");   Cociente_pT100__1Electron_ak5PFBTag->Scale(1.0/Cociente_pT100__1Electron_ak5PFBTag->Integral());
  TH1F *Cociente_pT100__1Electron_ak5PFMinBias =(TH1F*)MinBiasFile->Get("Cociente_pT<100__1Electron-ak5PFJet");   Cociente_pT100__1Electron_ak5PFMinBias->Scale(1.0/Cociente_pT100__1Electron_ak5PFMinBias->Integral());
  TH1F *Cociente_pT100__1Electron_ak5PFMultiJet =(TH1F*)MultiJetFile->Get("Cociente_pT<100__1Electron-ak5PFJet");   Cociente_pT100__1Electron_ak5PFMultiJet->Scale(1.0/Cociente_pT100__1Electron_ak5PFMultiJet->Integral());

  TH1F *Cociente_100pT__1Electron_ak5FJ =(TH1F*)FJFile->Get("Cociente_pT>100__1Electron-ak5FastJet");  Cociente_100pT__1Electron_ak5FJ->Scale(1.0/Cociente_100pT__1Electron_ak5FJ->Integral());
  TH1F *Cociente_100pT__1Electron_ak5PFJet =(TH1F*)JetFile->Get("Cociente_pT>100__1Electron-ak5PFJet");   Cociente_100pT__1Electron_ak5PFJet->Scale(1.0/Cociente_100pT__1Electron_ak5PFJet->Integral());
  TH1F *Cociente_100pT__1Electron_ak5PFBTag =(TH1F*)BTagFile->Get("Cociente_pT>100__1Electron-ak5PFJet");   Cociente_100pT__1Electron_ak5PFBTag->Scale(1.0/Cociente_100pT__1Electron_ak5PFBTag->Integral());
  TH1F *Cociente_100pT__1Electron_ak5PFMinBias =(TH1F*)MinBiasFile->Get("Cociente_pT>100__1Electron-ak5PFJet");   Cociente_100pT__1Electron_ak5PFMinBias->Scale(1.0/Cociente_100pT__1Electron_ak5PFMinBias->Integral());
  TH1F *Cociente_100pT__1Electron_ak5PFMultiJet =(TH1F*)MultiJetFile->Get("Cociente_pT>100__1Electron-ak5PFJet");   Cociente_100pT__1Electron_ak5PFMultiJet->Scale(1.0/Cociente_100pT__1Electron_ak5PFMultiJet->Integral());


  auto   Leg = new TLegend(0.62,0.70,0.90,0.92);    Leg->SetTextSize(0.04);Leg->SetFillStyle(0); Leg->SetBorderSize(0);
    Leg->AddEntry(CLON_C_pT__Muon_ak5FJ, "MC FastJet", "p");
    Leg->AddEntry(CLON_C_pT__Muon_ak5PFJet, "Open-Data PF Jet", "p");
    Leg->AddEntry(CLON_C_pT__Muon_ak5PFBTag, "Open-Data PF BTag", "p");
    Leg->AddEntry(CLON_C_pT__Muon_ak5PFMinBias, "Open-Data PF MinBias", "p");
    Leg->AddEntry(CLON_C_pT__Muon_ak5PFMultiJet, "Open-Data PF MultiJet", "p");

  auto   legend = new TLegend(0.62,0.70,0.90,0.92);    legend->SetTextSize(0.04);legend->SetFillStyle(0); legend->SetBorderSize(0);
    legend->AddEntry(Cociente_pT__Muon_ak5FJ, "MC FastJet", "lep");
    legend->AddEntry(Cociente_pT__Muon_ak5PFJet, "Open-Data PF Jet", "lep");
    legend->AddEntry(Cociente_pT__Muon_ak5PFBTag, "Open-Data PF BTag", "lep");
    legend->AddEntry(Cociente_pT__Muon_ak5PFMinBias, "Open-Data PF MinBias", "lep");
    legend->AddEntry(Cociente_pT__Muon_ak5PFMultiJet, "Open-Data PF MultiJet", "lep");

  auto   QuarkLegend = new TLegend(0.75,0.60,0.90,0.92);    QuarkLegend->SetTextSize(0.04);
    QuarkLegend->AddEntry(Cociente_pT__Muon_ak5FJ, "MC FastJet", "lp");
    QuarkLegend->AddEntry(Cociente_pT__Muon01_ak5FJ, "MC, Down", "lp");
    QuarkLegend->AddEntry(Cociente_pT__Muon02_ak5FJ, "MC, Up", "lp");
    QuarkLegend->AddEntry(Cociente_pT__Muon03_ak5FJ, "MC, Strange", "lp");
    QuarkLegend->AddEntry(Cociente_pT__Muon04_ak5FJ, "MC, Charm", "lp");
    QuarkLegend->AddEntry(Cociente_pT__Muon05_ak5FJ, "MC, Bottom", "lp");
    QuarkLegend->AddEntry(Cociente_pT__Muon21_ak5FJ, "MC, Gluon", "lp");

  auto   ODQuarkLegend = new TLegend(0.68,0.60,0.90,0.92);    ODQuarkLegend->SetTextSize(0.04);
    ODQuarkLegend->AddEntry(Cociente_pT__Muon_ak5PFJet, "Open-Data PF Jet", "lp");
    ODQuarkLegend->AddEntry(Cociente_pT__Muon01_ak5FJ, "MC, Down", "lp");
    ODQuarkLegend->AddEntry(Cociente_pT__Muon02_ak5FJ, "MC, Up", "lp");
    ODQuarkLegend->AddEntry(Cociente_pT__Muon03_ak5FJ, "MC, Strange", "lp");
    ODQuarkLegend->AddEntry(Cociente_pT__Muon04_ak5FJ, "MC, Charm", "lp");
    ODQuarkLegend->AddEntry(Cociente_pT__Muon05_ak5FJ, "MC, Bottom", "lp");
    ODQuarkLegend->AddEntry(Cociente_pT__Muon21_ak5FJ, "MC, Gluon", "lp");


/*
  TCanvas* Espectro_pT__Jets = new TCanvas("pT Jets","Espectro de pT de FastJet y PFJets",10,10,1920,1080);
  Espectro_pT__Jets->SetFillColor(0);  Espectro_pT__Jets->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  ak5FastJet__pT->SetTitle("Espectro de p_{T} de Jets; p_{T} [GeV]; U. A.");
  ak5FastJet__pT->GetXaxis()->SetLabelSize(0.05); ak5FastJet__pT->GetYaxis()->SetLabelSize(0.05);
  ak5FastJet__pT->GetXaxis()->SetTitleSize(0.05); ak5FastJet__pT->GetYaxis()->SetTitleSize(0.05);
  ak5FastJet__pT->GetXaxis()->SetTitleOffset(1.0);ak5FastJet__pT->GetYaxis()->SetTitleOffset(1.0);
  ak5FastJet__pT->SetAxisRange(0.0, 600.0, "X");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  ak5FastJet__pT -> Draw("E1"); ak5FastJet__pT->SetLineColor(1); ak5FastJet__pT->SetLineWidth(2);
  ak5FastJet__pT->SetMarkerStyle(20); ak5FastJet__pT->SetMarkerColor(1); ak5FastJet__pT->SetMarkerSize(2);
  ak5PFJet_pt_ -> Draw("Esame"); ak5PFJet_pt_->SetLineColor(2); ak5PFJet_pt_->SetLineWidth(2);
  ak5PFJet_pt_->SetMarkerStyle(23); ak5PFJet_pt_->SetMarkerColor(2); ak5PFJet_pt_->SetMarkerSize(2);
  ak5PFBTag_pt_ -> Draw("Esame"); ak5PFBTag_pt_->SetLineColor(9); ak5PFBTag_pt_->SetLineWidth(2);
  ak5PFBTag_pt_->SetMarkerStyle(22); ak5PFBTag_pt_->SetMarkerColor(9); ak5PFBTag_pt_->SetMarkerSize(2);
  ak5PFMultiJet_pt_ -> Draw("Esame"); ak5PFMultiJet_pt_->SetLineColor(32); ak5PFMultiJet_pt_->SetLineWidth(2);
  ak5PFMultiJet_pt_->SetMarkerStyle(34); ak5PFMultiJet_pt_->SetMarkerColor(32); ak5PFMultiJet_pt_->SetMarkerSize(2);
  legend -> Draw();  Espectro_pT__Jets -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/pT__FastJet_PFJets.png"); Espectro_pT__Jets -> Close();


  TCanvas* Espectro_pT__Muons = new TCanvas("pT Muones","Espectro de pT de Muones y Muons",10,10,1920,1080);
  Espectro_pT__Muons->SetFillColor(0);  Espectro_pT__Muons->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  Muons_pt_->SetTitle("Espectro de p_{T} de Muones; p_{T} [GeV]; U. A.");
  Muons_pt_->GetXaxis()->SetLabelSize(0.05); Muons_pt_->GetYaxis()->SetLabelSize(0.05);
  Muons_pt_->GetXaxis()->SetTitleSize(0.05); Muons_pt_->GetYaxis()->SetTitleSize(0.05);
  Muons_pt_->GetXaxis()->SetTitleOffset(1.0);Muons_pt_->GetYaxis()->SetTitleOffset(1.0);
  Muons_pt_->SetAxisRange(0.0, 100.0, "X");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Muons_pt_ -> Draw("E1"); Muons_pt_->SetLineColor(1); Muons_pt_->SetLineWidth(2);
  Muons_pt_->SetMarkerStyle(20); Muons_pt_->SetMarkerColor(1); Muons_pt_->SetMarkerSize(2);
  MuonsJet_pt_ -> Draw("Esame"); MuonsJet_pt_->SetLineColor(2); MuonsJet_pt_->SetLineWidth(2);
  MuonsJet_pt_->SetMarkerStyle(23); MuonsJet_pt_->SetMarkerColor(2); MuonsJet_pt_->SetMarkerSize(2);
  MuonsBTag_pt_ -> Draw("Esame"); MuonsBTag_pt_->SetLineColor(9); MuonsBTag_pt_->SetLineWidth(2);
  MuonsBTag_pt_->SetMarkerStyle(22); MuonsBTag_pt_->SetMarkerColor(9); MuonsBTag_pt_->SetMarkerSize(2);
  MuonsMultiJet_pt_ -> Draw("Esame"); MuonsMultiJet_pt_->SetLineColor(32); MuonsMultiJet_pt_->SetLineWidth(2);
  MuonsMultiJet_pt_->SetMarkerStyle(34); MuonsMultiJet_pt_->SetMarkerColor(32); MuonsMultiJet_pt_->SetMarkerSize(2);
  legend -> Draw();  Espectro_pT__Muons -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/pT__Muons.png"); Espectro_pT__Muons -> Close();


  TCanvas* Espectro_pT__Electrons = new TCanvas("pT Electrones","Espectro de pT de Electrones y Electrones",10,10,1920,1080);
  Espectro_pT__Electrons->SetFillColor(0);  Espectro_pT__Electrons->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  Electrons_pt_->SetTitle("Espectro de p_{T} de Electrones; p_{T} [GeV]; U. A.");
  Electrons_pt_->GetXaxis()->SetLabelSize(0.05); Electrons_pt_->GetYaxis()->SetLabelSize(0.05);
  Electrons_pt_->GetXaxis()->SetTitleSize(0.05); Electrons_pt_->GetYaxis()->SetTitleSize(0.05);
  Electrons_pt_->GetXaxis()->SetTitleOffset(1.0);Electrons_pt_->GetYaxis()->SetTitleOffset(1.0);
  Electrons_pt_->SetAxisRange(0.0, 400.0, "X");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Electrons_pt_ -> Draw("E1"); Electrons_pt_->SetLineColor(1); Electrons_pt_->SetLineWidth(2);
  Electrons_pt_->SetMarkerStyle(20); Electrons_pt_->SetMarkerColor(1); Electrons_pt_->SetMarkerSize(2);
  ElectronsJet_pt_ -> Draw("Esame"); ElectronsJet_pt_->SetLineColor(2); ElectronsJet_pt_->SetLineWidth(2);
  ElectronsJet_pt_->SetMarkerStyle(23); ElectronsJet_pt_->SetMarkerColor(2); ElectronsJet_pt_->SetMarkerSize(2);
  ElectronsBTag_pt_ -> Draw("Esame"); ElectronsBTag_pt_->SetLineColor(9); ElectronsBTag_pt_->SetLineWidth(2);
  ElectronsBTag_pt_->SetMarkerStyle(22); ElectronsBTag_pt_->SetMarkerColor(9); ElectronsBTag_pt_->SetMarkerSize(2);
  ElectronsMultiJet_pt_ -> Draw("Esame"); ElectronsMultiJet_pt_->SetLineColor(32); ElectronsMultiJet_pt_->SetLineWidth(2);
  ElectronsMultiJet_pt_->SetMarkerStyle(34); ElectronsMultiJet_pt_->SetMarkerColor(32); ElectronsMultiJet_pt_->SetMarkerSize(2);
  legend -> Draw();  Espectro_pT__Electrons -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/pT__Electrons.png"); Espectro_pT__Electrons -> Close();
*/

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
  Leg->Draw(); legend->Draw();  Cociente_pT__Muon_Jet->SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT__Muon-Jet.png"); Cociente_pT__Muon_Jet->Close();


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
      QuarkLegend -> Draw();  Cociente_pT__MuonQuark_Jet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT__MuonQuark-Jet.png"); Cociente_pT__MuonQuark_Jet -> Close();


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
      ODQuarkLegend -> Draw();  Cociente_pT__ODMuonQuark_Jet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT__MuonODQuark-Jet.png"); Cociente_pT__ODMuonQuark_Jet -> Close();*/


  TCanvas* Cociente_pT100__1Muon_Jet = new TCanvas("Cociente_pT100__1Muon_Jet","Cociente pT<100 FastJet y PFJets para muones",10,10,1920,1080);
  Cociente_pT100__1Muon_Jet->SetFillColor(0);  Cociente_pT100__1Muon_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  Cociente_pT100__1Muon_ak5FJ->SetTitle("#mu^{#pm} m#acute{a}s energ#acute{e}tico  (p_{T}^{Jet} < 100); p_{T}^{Muon} / p_{T}^{Jet}; U. A.");
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
  Leg->Draw(); legend->Draw();  Cociente_pT100__1Muon_Jet->SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT__Muon1-Jet<100.png"); Cociente_pT100__1Muon_Jet->Close();


  TCanvas* Cociente_100pT__1Muon_Jet = new TCanvas("Cociente_100pT__1Muon_Jet","Cociente pT>100 FastJet y PFJets para muones",10,10,1920,1080);
  Cociente_100pT__1Muon_Jet->SetFillColor(0);  Cociente_100pT__1Muon_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  Cociente_100pT__1Muon_ak5FJ->SetTitle("#mu^{#pm} m#acute{a}s energ#acute{e}tico  (p_{T}^{Jet} > 100); p_{T}^{Muon} / p_{T}^{Jet}; U. A.");
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
  Leg->Draw(); legend->Draw();  Cociente_100pT__1Muon_Jet->SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT__Muon1-Jet>100.png"); Cociente_100pT__1Muon_Jet->Close();


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
  Leg->Draw(); legend->Draw();  Cociente_pT__Electron_Jet->SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT__Electron-Jet.png"); Cociente_pT__Electron_Jet->Close();

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
    QuarkLegend -> Draw();  Cociente_pT__ElecQuark_Jet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT__ElectronQuark-Jet.png"); Cociente_pT__ElecQuark_Jet -> Close();


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
    ODQuarkLegend -> Draw();  Cociente_pT__ElecQuark_Jet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT__ElectronODQuark-Jet.png"); Cociente_pT__ElecQuark_Jet -> Close();
*/

  TCanvas* Cociente_pT100__1Electron_Jet = new TCanvas("Cociente_pT100__1Electron_Jet","Cociente pT<100 FastJet y PFJets para electrones",10,10,1920,1080);
  Cociente_pT100__1Electron_Jet->SetFillColor(0);  Cociente_pT100__1Electron_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  Cociente_pT100__1Electron_ak5FJ->SetTitle("e^{#pm} m#acute{a}s energ#acute{e}tico  (p_{T}^{Jet} < 100); p_{T}^{Electron} / p_{T}^{Jet}; U. A.");
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
  Leg->Draw(); legend->Draw();  Cociente_pT100__1Electron_Jet->SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT__Electron1-Jet<100.png"); Cociente_pT100__1Electron_Jet->Close();


  TCanvas* Cociente_100pT__1Electron_Jet = new TCanvas("Cociente_100pT__1Electron_Jet","Cociente pT>100 FastJet y PFJets para electrones",10,10,1920,1080);
  Cociente_100pT__1Electron_Jet->SetFillColor(0);  Cociente_100pT__1Electron_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  Cociente_100pT__1Electron_ak5FJ->SetTitle("e^{#pm} m#acute{a}s energ#acute{e}tico  (p_{T}^{Jet} > 100); p_{T}^{Electron} / p_{T}^{Jet}; U. A.");
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
  Leg->Draw(); legend->Draw();  Cociente_100pT__1Electron_Jet->SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT__Electron1-Jet>100.png"); Cociente_100pT__1Electron_Jet->Close();

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
    legend -> Draw(); fX_Muons -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Vertice_Muones_X__FastJet-PFJets.png"); fX_Muons -> Close();


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
    legend -> Draw(); fY_Muons -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Vertice_Muones_Y__FastJet-PFJets.png"); fY_Muons -> Close();


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
    legend -> Draw(); fZ_Muons -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Vertice_Muones_Z__FastJet-PFJets.png"); fZ_Muons -> Close();



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
    legend -> Draw(); fX_Electrons -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Vertice_Electrones_X__FastJet-PFJets.png"); fX_Electrons -> Close();


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
    legend -> Draw(); fY_Electrons -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Vertice_Electrones_Y__FastJet-PFJets.png"); fY_Electrons -> Close();


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
    legend -> Draw(); fZ_Electrons -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Vertice_Electrones_Z__FastJet-PFJets.png"); fZ_Electrons -> Close();

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
  Limits();
  pT();
  // Multiplicidad();
  // Vertice();

}
