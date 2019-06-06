void DistanciaAngular() {
  //Abrimos el archivo que nos interesa y el árbol que queremos leer.
  TFile *FJFile = new TFile("/home/saksevul/T/PYTHIA/FastJet/ak5FJ.root");
  TFile *JetFile = new TFile("/home/saksevul/T/OpenData/Jet_20000/ak5PF.root");
  TFile *BTagFile = new TFile("/home/saksevul/T/OpenData/BTag_20000/ak5PF.root");
  TFile *MultiJetFile = new TFile("/home/saksevul/T/OpenData/MultiJet_20000/ak5PF.root");

  TH1F *D__Muon_ak5FJ, *D__Electron_ak5FJ, *ak5FastJet__D_Jet_Jet,
       *D__Muon_ak5PFJet, *D__gsfElectron_ak5PFJet, *ak5PFBTag__D_Jet_Jet;

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
  ak5FastJet__D_Jet_Jet -> Draw("E1same"); ak5FastJet__D_Jet_Jet->SetLineColor(9);
  ak5FastJet__D_Jet_Jet->SetMarkerStyle(21); ak5FastJet__D_Jet_Jet->SetMarkerColor(9);
  legend -> Draw();

  ak5PFJet__D_Jet_Jet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/D_Jet_Jet FastJet y PFJets.png"); ak5PFJet__D_Jet_Jet -> Close();

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


  TH1F  *MuonsFJ_pt_,  *MuonsJet_pt_,  *MuonsBTag_pt_,  *MuonsMinBias_pt_,  *MuonsMultiJet_pt_,    *ak5FJ_pt_,  *ak5PFJet_pt_,  *ak5PFBTag_pt_,  *ak5PFMinBias_pt_,   *ak5PFMultiJet_pt_,
        *MuonsFJ_eta_, *MuonsJet_eta_, *MuonsBTag_eta_, *MuonsMinBias_eta_, *MuonsMultiJet_eta_,   *ak5FJ_eta_, *ak5PFJet_eta_, *ak5PFBTag_eta_, *ak5PFMinBias_eta_,  *ak5PFMultiJet_eta_,
        *ElectronsFJ_pt_,  *gsfElectronsJet_pt_,  *gsfElectronsBTag_pt_,  *gsfElectronsMinBias_pt_,  *gsfElectronsMultiJet_pt_,
        *ElectronsFJ_eta_, *gsfElectronsJet_eta_, *gsfElectronsBTag_eta_, *gsfElectronsMinBias_eta_, *gsfElectronsMultiJet_eta_;


  MuonsFJ_pt_ =(TH1F*)FJFile->Get("Muons_pt_"); MuonsFJ_pt_->Scale(1.0/MuonsFJ_pt_->Integral());
  MuonsJet_pt_ =(TH1F*)JetFile->Get("Muons_pt_"); MuonsJet_pt_->Scale(1.0/MuonsJet_pt_->Integral());
  MuonsBTag_pt_ =(TH1F*)BTagFile->Get("Muons_pt_"); MuonsBTag_pt_->Scale(1.0/MuonsBTag_pt_->Integral());
  MuonsMinBias_pt_ =(TH1F*)MinBiasFile->Get("Muons_pt_"); MuonsMinBias_pt_->Scale(1.0/MuonsMinBias_pt_->Integral());
  MuonsMultiJet_pt_ =(TH1F*)MultiJetFile->Get("Muons_pt_"); MuonsMultiJet_pt_->Scale(1.0/MuonsMultiJet_pt_->Integral());

  MuonsFJ_eta_ =(TH1F*)FJFile->Get("Muons_eta_"); MuonsFJ_eta_->Scale(1.0/MuonsFJ_eta_->Integral());
  MuonsJet_eta_ =(TH1F*)JetFile->Get("Muons_eta_"); MuonsJet_eta_->Scale(1.0/MuonsJet_eta_->Integral());
  MuonsBTag_eta_ =(TH1F*)BTagFile->Get("Muons_eta_"); MuonsBTag_eta_->Scale(1.0/MuonsBTag_eta_->Integral());
  MuonsMinBias_eta_ =(TH1F*)MinBiasFile->Get("Muons_eta_"); MuonsMinBias_eta_->Scale(1.0/MuonsMinBias_eta_->Integral());
  MuonsMultiJet_eta_ =(TH1F*)MultiJetFile->Get("Muons_eta_"); MuonsMultiJet_eta_->Scale(1.0/MuonsMultiJet_eta_->Integral());


  ElectronsFJ_pt_ =(TH1F*)FJFile->Get("Electrons_pt_"); ElectronsFJ_pt_->Scale(1.0/ElectronsFJ_pt_->Integral());
  gsfElectronsJet_pt_ =(TH1F*)JetFile->Get("gsfElectrons_pt_"); gsfElectronsJet_pt_->Scale(1.0/gsfElectronsJet_pt_->Integral());
  gsfElectronsBTag_pt_ =(TH1F*)BTagFile->Get("gsfElectrons_pt_"); gsfElectronsBTag_pt_->Scale(1.0/gsfElectronsBTag_pt_->Integral());
  gsfElectronsMinBias_pt_ =(TH1F*)MinBiasFile->Get("gsfElectrons_pt_"); gsfElectronsMinBias_pt_->Scale(1.0/gsfElectronsMinBias_pt_->Integral());
  gsfElectronsMultiJet_pt_ =(TH1F*)MultiJetFile->Get("gsfElectrons_pt_"); gsfElectronsMultiJet_pt_->Scale(1.0/gsfElectronsMultiJet_pt_->Integral());

  ElectronsFJ_eta_ =(TH1F*)FJFile->Get("Electrons_eta_"); ElectronsFJ_eta_->Scale(1.0/ElectronsFJ_eta_->Integral());
  gsfElectronsJet_eta_ =(TH1F*)JetFile->Get("gsfElectrons_eta_"); gsfElectronsJet_eta_->Scale(1.0/gsfElectronsJet_eta_->Integral());
  gsfElectronsBTag_eta_ =(TH1F*)BTagFile->Get("gsfElectrons_eta_"); gsfElectronsBTag_eta_->Scale(1.0/gsfElectronsBTag_eta_->Integral());
  gsfElectronsMinBias_eta_ =(TH1F*)MinBiasFile->Get("gsfElectrons_eta_"); gsfElectronsMinBias_eta_->Scale(1.0/gsfElectronsMinBias_eta_->Integral());
  gsfElectronsMultiJet_eta_ =(TH1F*)MultiJetFile->Get("gsfElectrons_eta_"); gsfElectronsMultiJet_eta_->Scale(1.0/gsfElectronsMultiJet_eta_->Integral());


  ak5FJ_pt_ =(TH1F*)FJFile->Get("ak5FastJet_pt_"); ak5FJ_pt_->Scale(1.0/ak5FJ_pt_->Integral());
  ak5PFJet_pt_ =(TH1F*)JetFile->Get("ak5PFJets_pt_"); ak5PFJet_pt_->Scale(1.0/ak5PFJet_pt_->Integral());
  ak5PFBTag_pt_ =(TH1F*)BTagFile->Get("ak5PFJets_pt_"); ak5PFBTag_pt_->Scale(1.0/ak5PFBTag_pt_->Integral());
  ak5PFMinBias_pt_ =(TH1F*)MinBiasFile->Get("ak5PFJets_pt_"); ak5PFMinBias_pt_->Scale(1.0/ak5PFMinBias_pt_->Integral());
  ak5PFMultiJet_pt_ =(TH1F*)MultiJetFile->Get("ak5PFJets_pt_"); ak5PFMultiJet_pt_->Scale(1.0/ak5PFMultiJet_pt_->Integral());

  ak5FJ_eta_ =(TH1F*)FJFile->Get("ak5FastJet_eta_"); ak5FJ_eta_->Scale(1.0/ak5FJ_eta_->Integral());
  ak5PFJet_eta_ =(TH1F*)JetFile->Get("ak5PFJets_eta_"); ak5PFJet_eta_->Scale(1.0/ak5PFJet_eta_->Integral());
  ak5PFBTag_eta_ =(TH1F*)BTagFile->Get("ak5PFJets_eta_"); ak5PFBTag_eta_->Scale(1.0/ak5PFBTag_eta_->Integral());
  ak5PFMinBias_eta_ =(TH1F*)MinBiasFile->Get("ak5PFJets_eta_"); ak5PFMinBias_eta_->Scale(1.0/ak5PFMinBias_eta_->Integral());
  ak5PFMultiJet_eta_ =(TH1F*)MultiJetFile->Get("ak5PFJets_eta_"); ak5PFMultiJet_eta_->Scale(1.0/ak5PFMultiJet_eta_->Integral());



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
  MuonsMinBias_pt_ -> Draw("HISTsame"); MuonsMinBias_pt_->SetLineColor(30); MuonsMinBias_pt_->SetLineWidth(2);
  MuonsMinBias_pt_->SetMarkerStyle(23); MuonsMinBias_pt_->SetMarkerColor(30); MuonsMinBias_pt_->SetMarkerSize(2);
  MuonsMultiJet_pt_ -> Draw("HISTsame"); MuonsMultiJet_pt_->SetLineColor(8); MuonsMultiJet_pt_->SetLineWidth(2);
  MuonsMultiJet_pt_->SetMarkerStyle(23); MuonsMultiJet_pt_->SetMarkerColor(8); MuonsMultiJet_pt_->SetMarkerSize(2);
  legend -> Draw(); Limite_Muones_pT -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Limite_Muon_pT.png"); Limite_Muones_pT -> Close();


  TCanvas* Limite_Muones_eta = new TCanvas("Limite eta Muones","Limite de #eta para Muones",10,10,1920,1080);
  Limite_Muones_pT->SetFillColor(0);  Limite_Muones_pT->SetFrameBorderMode(0);  gPad->SetLogy();
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
  MuonsMinBias_eta_ -> Draw("HISTsame"); MuonsMinBias_eta_->SetLineColor(30); MuonsMinBias_eta_->SetLineWidth(2);
  MuonsMinBias_eta_->SetMarkerStyle(23); MuonsMinBias_eta_->SetMarkerColor(30); MuonsMinBias_eta_->SetMarkerSize(2);
  MuonsMultiJet_eta_ -> Draw("HISTsame"); MuonsMultiJet_eta_->SetLineColor(8); MuonsMultiJet_eta_->SetLineWidth(2);
  MuonsMultiJet_eta_->SetMarkerStyle(23); MuonsMultiJet_eta_->SetMarkerColor(8); MuonsMultiJet_eta_->SetMarkerSize(2);
  legend -> Draw(); Limite_Muones_pT -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Limite_Muon_eta.png"); Limite_Muones_pT -> Close();


  TCanvas* Limite_gsfElectrones_pT = new TCanvas("Limite pT gsfElectrones","Limite de pT para gsfElectrones",10,10,1920,1080);
  Limite_gsfElectrones_pT->SetFillColor(0);  Limite_gsfElectrones_pT->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  ElectronsFJ_pt_->SetTitle("Espectro de p_{T} para Electrones; p_{T} [GeV]; U. A.");
  ElectronsFJ_pt_->GetXaxis()->SetLabelSize(0.05); ElectronsFJ_pt_->GetYaxis()->SetLabelSize(0.05);
  ElectronsFJ_pt_->GetXaxis()->SetTitleSize(0.05); ElectronsFJ_pt_->GetYaxis()->SetTitleSize(0.05);
  ElectronsFJ_pt_->GetXaxis()->SetTitleOffset(1.0);ElectronsFJ_pt_->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  ElectronsFJ_pt_ -> Draw("HIST"); ElectronsFJ_pt_->SetLineColor(1); ElectronsFJ_pt_->SetLineWidth(2);
  ElectronsFJ_pt_->SetMarkerStyle(20); ElectronsFJ_pt_->SetMarkerColor(1); ElectronsFJ_pt_->SetMarkerSize(2);
  gsfElectronsJet_pt_ -> Draw("HISTsame"); gsfElectronsJet_pt_->SetLineColor(2); gsfElectronsJet_pt_->SetLineWidth(2);
  gsfElectronsJet_pt_->SetMarkerStyle(20); gsfElectronsJet_pt_->SetMarkerColor(2); gsfElectronsJet_pt_->SetMarkerSize(2);
  gsfElectronsBTag_pt_ -> Draw("HISTsame"); gsfElectronsBTag_pt_->SetLineColor(4); gsfElectronsBTag_pt_->SetLineWidth(2);
  gsfElectronsBTag_pt_->SetMarkerStyle(23); gsfElectronsBTag_pt_->SetMarkerColor(4); gsfElectronsBTag_pt_->SetMarkerSize(2);
  gsfElectronsMinBias_pt_ -> Draw("HISTsame"); gsfElectronsMinBias_pt_->SetLineColor(30); gsfElectronsMinBias_pt_->SetLineWidth(2);
  gsfElectronsMinBias_pt_->SetMarkerStyle(23); gsfElectronsMinBias_pt_->SetMarkerColor(30); gsfElectronsMinBias_pt_->SetMarkerSize(2);
  gsfElectronsMultiJet_pt_ -> Draw("HISTsame"); gsfElectronsMultiJet_pt_->SetLineColor(8); gsfElectronsMultiJet_pt_->SetLineWidth(2);
  gsfElectronsMultiJet_pt_->SetMarkerStyle(23); gsfElectronsMultiJet_pt_->SetMarkerColor(8); gsfElectronsMultiJet_pt_->SetMarkerSize(2);
  legend -> Draw(); Limite_gsfElectrones_pT -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Limite_gsfElectrons_pT.png"); Limite_gsfElectrones_pT -> Close();


  TCanvas* Limite_gsfElectrones_eta = new TCanvas("Limite eta gsfElectrones","Limite de #eta para gsfElectrones",10,10,1920,1080);
  Limite_gsfElectrones_pT->SetFillColor(0);  Limite_gsfElectrones_pT->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  ElectronsFJ_eta_->SetTitle("Espectro de #eta para Electrones; p_{T} [GeV]; U. A.");
  ElectronsFJ_eta_->GetXaxis()->SetLabelSize(0.05); ElectronsFJ_eta_->GetYaxis()->SetLabelSize(0.05);
  ElectronsFJ_eta_->GetXaxis()->SetTitleSize(0.05); ElectronsFJ_eta_->GetYaxis()->SetTitleSize(0.05);
  ElectronsFJ_eta_->GetXaxis()->SetTitleOffset(1.0);ElectronsFJ_eta_->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  ElectronsFJ_eta_ -> Draw("HIST"); ElectronsFJ_eta_->SetLineColor(1); ElectronsFJ_eta_->SetLineWidth(2);
  ElectronsFJ_eta_->SetMarkerStyle(20); ElectronsFJ_eta_->SetMarkerColor(1); ElectronsFJ_eta_->SetMarkerSize(2);
  gsfElectronsJet_eta_ -> Draw("HISTsame"); gsfElectronsJet_eta_->SetLineColor(2); gsfElectronsJet_eta_->SetLineWidth(2);
  gsfElectronsJet_eta_->SetMarkerStyle(20); gsfElectronsJet_eta_->SetMarkerColor(2); gsfElectronsJet_eta_->SetMarkerSize(2);
  gsfElectronsBTag_eta_ -> Draw("HISTsame"); gsfElectronsBTag_eta_->SetLineColor(4); gsfElectronsBTag_eta_->SetLineWidth(2);
  gsfElectronsBTag_eta_->SetMarkerStyle(23); gsfElectronsBTag_eta_->SetMarkerColor(4); gsfElectronsBTag_eta_->SetMarkerSize(2);
  gsfElectronsMinBias_eta_ -> Draw("HISTsame"); gsfElectronsMinBias_eta_->SetLineColor(30); gsfElectronsMinBias_eta_->SetLineWidth(2);
  gsfElectronsMinBias_eta_->SetMarkerStyle(23); gsfElectronsMinBias_eta_->SetMarkerColor(30); gsfElectronsMinBias_eta_->SetMarkerSize(2);
  gsfElectronsMultiJet_eta_ -> Draw("HISTsame"); gsfElectronsMultiJet_eta_->SetLineColor(8); gsfElectronsMultiJet_eta_->SetLineWidth(2);
  gsfElectronsMultiJet_eta_->SetMarkerStyle(23); gsfElectronsMultiJet_eta_->SetMarkerColor(8); gsfElectronsMultiJet_eta_->SetMarkerSize(2);
  legend -> Draw(); Limite_gsfElectrones_pT -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Limite_gsfElectrons_eta.png"); Limite_gsfElectrones_pT -> Close();


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
  ak5PFMinBias_pt_ -> Draw("HISTsame"); ak5PFMinBias_pt_->SetLineColor(30); ak5PFMinBias_pt_->SetLineWidth(2);
  ak5PFMinBias_pt_->SetMarkerStyle(23); ak5PFMinBias_pt_->SetMarkerColor(30); ak5PFMinBias_pt_->SetMarkerSize(2);
  ak5PFMultiJet_pt_ -> Draw("HISTsame"); ak5PFMultiJet_pt_->SetLineColor(8); ak5PFMultiJet_pt_->SetLineWidth(2);
  ak5PFMultiJet_pt_->SetMarkerStyle(23); ak5PFMultiJet_pt_->SetMarkerColor(8); ak5PFMultiJet_pt_->SetMarkerSize(2);
  legend -> Draw(); Limite_Jets_pT -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Limite_Jets_pT.png"); Limite_Jets_pT -> Close();


  TCanvas* Limite_Jets_eta = new TCanvas("Limite eta Jets","Limite de #eta para Jets",10,10,1920,1080);
  Limite_Jets_pT->SetFillColor(0);  Limite_Jets_pT->SetFrameBorderMode(0);  gPad->SetLogy();
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
  ak5PFMinBias_eta_ -> Draw("HISTsame"); ak5PFMinBias_eta_->SetLineColor(30); ak5PFMinBias_eta_->SetLineWidth(2);
  ak5PFMinBias_eta_->SetMarkerStyle(23); ak5PFMinBias_eta_->SetMarkerColor(30); ak5PFMinBias_eta_->SetMarkerSize(2);
  ak5PFMultiJet_eta_ -> Draw("HISTsame"); ak5PFMultiJet_eta_->SetLineColor(8); ak5PFMultiJet_eta_->SetLineWidth(2);
  ak5PFMultiJet_eta_->SetMarkerStyle(23); ak5PFMultiJet_eta_->SetMarkerColor(8); ak5PFMultiJet_eta_->SetMarkerSize(2);
  legend -> Draw(); Limite_Jets_pT -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Limite_Jets_eta.png"); Limite_Jets_pT -> Close();
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
    ak5PFJet__Multiplicidad -> Draw("E1same"); ak5PFJet__Multiplicidad->SetLineColor(2);
    ak5PFJet__Multiplicidad->SetMarkerStyle(23); ak5PFJet__Multiplicidad->SetMarkerColor(2);
    ak5PFBTag__Multiplicidad -> Draw("E1same"); ak5PFBTag__Multiplicidad->SetLineColor(9);
    ak5PFBTag__Multiplicidad->SetMarkerStyle(22); ak5PFBTag__Multiplicidad->SetMarkerColor(9);
    ak5PFMultiJet__Multiplicidad -> Draw("E1same"); ak5PFMultiJet__Multiplicidad->SetLineColor(8);
    ak5PFMultiJet__Multiplicidad->SetMarkerStyle(21); ak5PFMultiJet__Multiplicidad->SetMarkerColor(8);
    legend -> Draw();

  Espectro_Multiplicidad__Jets -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Multiplicidad__FastJet_PFJets.png"); Espectro_Multiplicidad__Jets -> Close();

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

  TH1F *Muons_pt_, *Electrons_pt_, *ak5FastJet__pT,
       *MuonsJet_pt_, *gsfElectronsJet_pt_, *ak5PFJet_pt_,
       *MuonsBTag_pt_, *gsfElectronsBTag_pt_, *ak5PFBTag_pt_,
       *MuonsMinBias_pt_, *gsfElectronsMinBias_pt_, *ak5PFMinBias_pt_,
       *MuonsMultiJet_pt_, *gsfElectronsMultiJet_pt_, *ak5PFMultiJet_pt_,

       *Cociente_pT__Electron_ak5FJ, *Cociente_pT__Muon_ak5FJ,
       *Cociente_pT__gsfElectron_ak5PFJet, *Cociente_pT__Muon_ak5PFJet,
       *Cociente_pT__gsfElectron_ak5PFBTag, *Cociente_pT__Muon_ak5PFBTag,
       *Cociente_pT__gsfElectron_ak5PFMinBias, *Cociente_pT__Muon_ak5PFMinBias,
       *Cociente_pT__gsfElectron_ak5PFMultiJet, *Cociente_pT__Muon_ak5PFMultiJet,

       *Cociente_pT__Electron01_ak5FJ, *Cociente_pT__Muon01_ak5FJ,
       *Cociente_pT__Electron02_ak5FJ, *Cociente_pT__Muon02_ak5FJ,
       *Cociente_pT__Electron03_ak5FJ, *Cociente_pT__Muon03_ak5FJ,
       *Cociente_pT__Electron04_ak5FJ, *Cociente_pT__Muon04_ak5FJ,
       *Cociente_pT__Electron05_ak5FJ, *Cociente_pT__Muon05_ak5FJ,
       *Cociente_pT__Electron21_ak5FJ, *Cociente_pT__Muon21_ak5FJ,

       *Cociente_pT100__1Electron_ak5FJ, *Cociente_pT100__1Muon_ak5FJ,
       *Cociente_pT100__1gsfElectron_ak5PFJet, *Cociente_pT100__1Muon_ak5PFJet,
       *Cociente_pT100__1gsfElectron_ak5PFBTag, *Cociente_pT100__1Muon_ak5PFBTag,
       *Cociente_pT100__1gsfElectron_ak5PFMinBias, *Cociente_pT100__1Muon_ak5PFMinBias,
       *Cociente_pT100__1gsfElectron_ak5PFMultiJet, *Cociente_pT100__1Muon_ak5PFMultiJet,

       *Cociente_100pT__1Electron_ak5FJ, *Cociente_100pT__1Muon_ak5FJ,
       *Cociente_100pT__1gsfElectron_ak5PFJet, *Cociente_100pT__1Muon_ak5PFJet,
       *Cociente_100pT__1gsfElectron_ak5PFBTag, *Cociente_100pT__1Muon_ak5PFBTag,
       *Cociente_100pT__1gsfElectron_ak5PFMinBias, *Cociente_100pT__1Muon_ak5PFMinBias,
       *Cociente_100pT__1gsfElectron_ak5PFMultiJet, *Cociente_100pT__1Muon_ak5PFMultiJet;

/*
  ak5FastJet__pT =(TH1F*)FJFile->Get("ak5FastJet__pT"); ak5FastJet__pT->Scale(1.0/ak5FastJet__pT->Integral());
  ak5PFJet_pt_ =(TH1F*)JetFile->Get("ak5PFJets_pt_"); ak5PFJet_pt_->Scale(1.0/ak5PFJet_pt_->Integral());
  ak5PFBTag_pt_ =(TH1F*)BTagFile->Get("ak5PFJets_pt_"); ak5PFBTag_pt_->Scale(1.0/ak5PFBTag_pt_->Integral());
  ak5PFMultiJet_pt_ =(TH1F*)MultiJetFile->Get("ak5PFJets_pt_"); ak5PFMultiJet_pt_->Scale(1.0/ak5PFMultiJet_pt_->Integral());

  Muons_pt_ =(TH1F*)FJFile->Get("Muons_pt_"); Muons_pt_->Scale(1.0/Muons_pt_->Integral());
  MuonsJet_pt_ =(TH1F*)JetFile->Get("Muons_pt_"); MuonsJet_pt_->Scale(1.0/MuonsJet_pt_->Integral());
  MuonsBTag_pt_ =(TH1F*)BTagFile->Get("Muons_pt_"); MuonsBTag_pt_->Scale(1.0/MuonsBTag_pt_->Integral());
  MuonsMultiJet_pt_ =(TH1F*)MultiJetFile->Get("Muons_pt_"); MuonsMultiJet_pt_->Scale(1.0/MuonsMultiJet_pt_->Integral());

  Electrons_pt_ =(TH1F*)FJFile->Get("Electrons_pt_"); Electrons_pt_->Scale(1.0/Electrons_pt_->Integral());
  gsfElectronsJet_pt_ =(TH1F*)JetFile->Get("gsfElectrons_pt_"); gsfElectronsJet_pt_->Scale(1.0/gsfElectronsJet_pt_->Integral());
  gsfElectronsBTag_pt_ =(TH1F*)BTagFile->Get("gsfElectrons_pt_"); gsfElectronsBTag_pt_->Scale(1.0/gsfElectronsBTag_pt_->Integral());
  gsfElectronsMultiJet_pt_ =(TH1F*)MultiJetFile->Get("gsfElectrons_pt_"); gsfElectronsMultiJet_pt_->Scale(1.0/gsfElectronsMultiJet_pt_->Integral());
*/
  Cociente_pT__Electron_ak5FJ =(TH1F*)FJFile->Get("Cociente_pT__Electron-ak5FastJet");  Cociente_pT__Electron_ak5FJ->Scale(1.0/Cociente_pT__Electron_ak5FJ->Integral());
    Cociente_pT__Electron01_ak5FJ = (TH1F*)FJFile->Get("Cociente01_pT__Electron-ak5FastJet");Cociente_pT__Electron01_ak5FJ->Scale(1.0/Cociente_pT__Electron01_ak5FJ->Integral());
    Cociente_pT__Electron02_ak5FJ = (TH1F*)FJFile->Get("Cociente02_pT__Electron-ak5FastJet");Cociente_pT__Electron02_ak5FJ->Scale(1.0/Cociente_pT__Electron02_ak5FJ->Integral());
    Cociente_pT__Electron03_ak5FJ = (TH1F*)FJFile->Get("Cociente03_pT__Electron-ak5FastJet");Cociente_pT__Electron03_ak5FJ->Scale(1.0/Cociente_pT__Electron03_ak5FJ->Integral());
    Cociente_pT__Electron04_ak5FJ = (TH1F*)FJFile->Get("Cociente04_pT__Electron-ak5FastJet");Cociente_pT__Electron04_ak5FJ->Scale(1.0/Cociente_pT__Electron04_ak5FJ->Integral());
    Cociente_pT__Electron05_ak5FJ = (TH1F*)FJFile->Get("Cociente05_pT__Electron-ak5FastJet");Cociente_pT__Electron05_ak5FJ->Scale(1.0/Cociente_pT__Electron05_ak5FJ->Integral());
    Cociente_pT__Electron21_ak5FJ = (TH1F*)FJFile->Get("Cociente21_pT__Electron-ak5FastJet");Cociente_pT__Electron21_ak5FJ->Scale(1.0/Cociente_pT__Electron21_ak5FJ->Integral());
  Cociente_pT__gsfElectron_ak5PFJet =(TH1F*)JetFile->Get("Cociente_pT__gsfElectron-ak5PFJet");   Cociente_pT__gsfElectron_ak5PFJet->Scale(1.0/Cociente_pT__gsfElectron_ak5PFJet->Integral());
  Cociente_pT__gsfElectron_ak5PFBTag =(TH1F*)BTagFile->Get("Cociente_pT__gsfElectron-ak5PFJet");   Cociente_pT__gsfElectron_ak5PFBTag->Scale(1.0/Cociente_pT__gsfElectron_ak5PFBTag->Integral());
  Cociente_pT__gsfElectron_ak5PFMinBias =(TH1F*)MinBiasFile->Get("Cociente_pT__gsfElectron-ak5PFJet");   Cociente_pT__gsfElectron_ak5PFMinBias->Scale(1.0/Cociente_pT__gsfElectron_ak5PFMinBias->Integral());
  Cociente_pT__gsfElectron_ak5PFMultiJet =(TH1F*)MultiJetFile->Get("Cociente_pT__gsfElectron-ak5PFJet");   Cociente_pT__gsfElectron_ak5PFMultiJet->Scale(1.0/Cociente_pT__gsfElectron_ak5PFMultiJet->Integral());

  Cociente_pT100__1Electron_ak5FJ =(TH1F*)FJFile->Get("Cociente_pT<100__1Electron-ak5FastJet");  Cociente_pT100__1Electron_ak5FJ->Scale(1.0/Cociente_pT100__1Electron_ak5FJ->Integral());
  Cociente_pT100__1gsfElectron_ak5PFJet =(TH1F*)JetFile->Get("Cociente_pT<100__1gsfElectron-ak5PFJet");   Cociente_pT100__1gsfElectron_ak5PFJet->Scale(1.0/Cociente_pT100__1gsfElectron_ak5PFJet->Integral());
  Cociente_pT100__1gsfElectron_ak5PFBTag =(TH1F*)BTagFile->Get("Cociente_pT<100__1gsfElectron-ak5PFJet");   Cociente_pT100__1gsfElectron_ak5PFBTag->Scale(1.0/Cociente_pT100__1gsfElectron_ak5PFBTag->Integral());
  Cociente_pT100__1gsfElectron_ak5PFMinBias =(TH1F*)MinBiasFile->Get("Cociente_pT<100__1gsfElectron-ak5PFJet");   Cociente_pT100__1gsfElectron_ak5PFMinBias->Scale(1.0/Cociente_pT100__1gsfElectron_ak5PFMinBias->Integral());
  Cociente_pT100__1gsfElectron_ak5PFMultiJet =(TH1F*)MultiJetFile->Get("Cociente_pT<100__1gsfElectron-ak5PFJet");   Cociente_pT100__1gsfElectron_ak5PFMultiJet->Scale(1.0/Cociente_pT100__1gsfElectron_ak5PFMultiJet->Integral());

  Cociente_100pT__1Electron_ak5FJ =(TH1F*)FJFile->Get("Cociente_pT>100__1Electron-ak5FastJet");  Cociente_100pT__1Electron_ak5FJ->Scale(1.0/Cociente_100pT__1Electron_ak5FJ->Integral());
  Cociente_100pT__1gsfElectron_ak5PFJet =(TH1F*)JetFile->Get("Cociente_pT>100__1gsfElectron-ak5PFJet");   Cociente_100pT__1gsfElectron_ak5PFJet->Scale(1.0/Cociente_100pT__1gsfElectron_ak5PFJet->Integral());
  Cociente_100pT__1gsfElectron_ak5PFBTag =(TH1F*)BTagFile->Get("Cociente_pT>100__1gsfElectron-ak5PFJet");   Cociente_100pT__1gsfElectron_ak5PFBTag->Scale(1.0/Cociente_100pT__1gsfElectron_ak5PFBTag->Integral());
  Cociente_100pT__1gsfElectron_ak5PFMinBias =(TH1F*)MinBiasFile->Get("Cociente_pT>100__1gsfElectron-ak5PFJet");   Cociente_100pT__1gsfElectron_ak5PFMinBias->Scale(1.0/Cociente_100pT__1gsfElectron_ak5PFMinBias->Integral());
  Cociente_100pT__1gsfElectron_ak5PFMultiJet =(TH1F*)MultiJetFile->Get("Cociente_pT>100__1gsfElectron-ak5PFJet");   Cociente_100pT__1gsfElectron_ak5PFMultiJet->Scale(1.0/Cociente_100pT__1gsfElectron_ak5PFMultiJet->Integral());

  Cociente_pT__Muon_ak5FJ =(TH1F*)FJFile->Get("Cociente_pT__Muon-ak5FastJet"); Cociente_pT__Muon_ak5FJ->Scale(1.0/Cociente_pT__Muon_ak5FJ->Integral());
    Cociente_pT__Muon01_ak5FJ = (TH1F*)FJFile->Get("Cociente01_pT__Muon-ak5FastJet");Cociente_pT__Muon01_ak5FJ->Scale(1.0/Cociente_pT__Muon01_ak5FJ->Integral());
    Cociente_pT__Muon02_ak5FJ = (TH1F*)FJFile->Get("Cociente02_pT__Muon-ak5FastJet");Cociente_pT__Muon02_ak5FJ->Scale(1.0/Cociente_pT__Muon02_ak5FJ->Integral());
    Cociente_pT__Muon03_ak5FJ = (TH1F*)FJFile->Get("Cociente03_pT__Muon-ak5FastJet");Cociente_pT__Muon03_ak5FJ->Scale(1.0/Cociente_pT__Muon03_ak5FJ->Integral());
    Cociente_pT__Muon04_ak5FJ = (TH1F*)FJFile->Get("Cociente04_pT__Muon-ak5FastJet");Cociente_pT__Muon04_ak5FJ->Scale(1.0/Cociente_pT__Muon04_ak5FJ->Integral());
    Cociente_pT__Muon05_ak5FJ = (TH1F*)FJFile->Get("Cociente05_pT__Muon-ak5FastJet");Cociente_pT__Muon05_ak5FJ->Scale(1.0/Cociente_pT__Muon05_ak5FJ->Integral());
    Cociente_pT__Muon21_ak5FJ = (TH1F*)FJFile->Get("Cociente21_pT__Muon-ak5FastJet");Cociente_pT__Muon21_ak5FJ->Scale(1.0/Cociente_pT__Muon21_ak5FJ->Integral());
  Cociente_pT__Muon_ak5PFJet =(TH1F*)JetFile->Get("Cociente_pT__Muon-ak5PFJet"); Cociente_pT__Muon_ak5PFJet->Scale(1.0/Cociente_pT__Muon_ak5PFJet->Integral());
  Cociente_pT__Muon_ak5PFBTag =(TH1F*)BTagFile->Get("Cociente_pT__Muon-ak5PFJet"); Cociente_pT__Muon_ak5PFBTag->Scale(1.0/Cociente_pT__Muon_ak5PFBTag->Integral());
  Cociente_pT__Muon_ak5PFMinBias =(TH1F*)MinBiasFile->Get("Cociente_pT__Muon-ak5PFJet"); Cociente_pT__Muon_ak5PFMinBias->Scale(1.0/Cociente_pT__Muon_ak5PFMinBias->Integral());
  Cociente_pT__Muon_ak5PFMultiJet =(TH1F*)MultiJetFile->Get("Cociente_pT__Muon-ak5PFJet"); Cociente_pT__Muon_ak5PFMultiJet->Scale(1.0/Cociente_pT__Muon_ak5PFMultiJet->Integral());

  Cociente_pT100__1Muon_ak5FJ =(TH1F*)FJFile->Get("Cociente_pT<100__1Muon-ak5FastJet");  Cociente_pT100__1Muon_ak5FJ->Scale(1.0/Cociente_pT100__1Muon_ak5FJ->Integral());
  Cociente_pT100__1Muon_ak5PFJet =(TH1F*)JetFile->Get("Cociente_pT<100__1Muon-ak5PFJet");   Cociente_pT100__1Muon_ak5PFJet->Scale(1.0/Cociente_pT100__1Muon_ak5PFJet->Integral());
  Cociente_pT100__1Muon_ak5PFBTag =(TH1F*)BTagFile->Get("Cociente_pT<100__1Muon-ak5PFJet");   Cociente_pT100__1Muon_ak5PFBTag->Scale(1.0/Cociente_pT100__1Muon_ak5PFBTag->Integral());
  Cociente_pT100__1Muon_ak5PFMinBias =(TH1F*)MinBiasFile->Get("Cociente_pT<100__1Muon-ak5PFJet");   Cociente_pT100__1Muon_ak5PFMinBias->Scale(1.0/Cociente_pT100__1Muon_ak5PFMinBias->Integral());
  Cociente_pT100__1Muon_ak5PFMultiJet =(TH1F*)MultiJetFile->Get("Cociente_pT<100__1Muon-ak5PFJet");   Cociente_pT100__1Muon_ak5PFMultiJet->Scale(1.0/Cociente_pT100__1Muon_ak5PFMultiJet->Integral());

  Cociente_100pT__1Muon_ak5FJ =(TH1F*)FJFile->Get("Cociente_pT>100__1Muon-ak5FastJet");  Cociente_100pT__1Muon_ak5FJ->Scale(1.0/Cociente_100pT__1Muon_ak5FJ->Integral());
  Cociente_100pT__1Muon_ak5PFJet =(TH1F*)JetFile->Get("Cociente_pT>100__1Muon-ak5PFJet");   Cociente_100pT__1Muon_ak5PFJet->Scale(1.0/Cociente_100pT__1Muon_ak5PFJet->Integral());
  Cociente_100pT__1Muon_ak5PFBTag =(TH1F*)BTagFile->Get("Cociente_pT>100__1Muon-ak5PFJet");   Cociente_100pT__1Muon_ak5PFBTag->Scale(1.0/Cociente_100pT__1Muon_ak5PFBTag->Integral());
  Cociente_100pT__1Muon_ak5PFMinBias =(TH1F*)MinBiasFile->Get("Cociente_pT>100__1Muon-ak5PFJet");   Cociente_100pT__1Muon_ak5PFMinBias->Scale(1.0/Cociente_100pT__1Muon_ak5PFMinBias->Integral());
  Cociente_100pT__1Muon_ak5PFMultiJet =(TH1F*)MultiJetFile->Get("Cociente_pT>100__1Muon-ak5PFJet");   Cociente_100pT__1Muon_ak5PFMultiJet->Scale(1.0/Cociente_100pT__1Muon_ak5PFMultiJet->Integral());



  auto   legend = new TLegend(0.62,0.70,0.90,0.92);    legend->SetTextSize(0.04);
    legend->AddEntry(Cociente_pT__Muon_ak5FJ, "MC FastJet", "lp");
    legend->AddEntry(Cociente_pT__Muon_ak5PFJet, "Open-Data PF Jet", "lp");
    legend->AddEntry(Cociente_pT__Muon_ak5PFBTag, "Open-Data PF BTag", "lp");
    legend->AddEntry(Cociente_pT__Muon_ak5PFMinBias, "Open-Data PF MinBias", "lp");
    legend->AddEntry(Cociente_pT__Muon_ak5PFMultiJet, "Open-Data PF MultiJet", "lp");

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
  ak5PFJet_pt_ -> Draw("E1same"); ak5PFJet_pt_->SetLineColor(2); ak5PFJet_pt_->SetLineWidth(2);
  ak5PFJet_pt_->SetMarkerStyle(23); ak5PFJet_pt_->SetMarkerColor(2); ak5PFJet_pt_->SetMarkerSize(2);
  ak5PFBTag_pt_ -> Draw("E1same"); ak5PFBTag_pt_->SetLineColor(9); ak5PFBTag_pt_->SetLineWidth(2);
  ak5PFBTag_pt_->SetMarkerStyle(22); ak5PFBTag_pt_->SetMarkerColor(9); ak5PFBTag_pt_->SetMarkerSize(2);
  ak5PFMultiJet_pt_ -> Draw("E1same"); ak5PFMultiJet_pt_->SetLineColor(8); ak5PFMultiJet_pt_->SetLineWidth(2);
  ak5PFMultiJet_pt_->SetMarkerStyle(34); ak5PFMultiJet_pt_->SetMarkerColor(8); ak5PFMultiJet_pt_->SetMarkerSize(2);
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
  MuonsJet_pt_ -> Draw("E1same"); MuonsJet_pt_->SetLineColor(2); MuonsJet_pt_->SetLineWidth(2);
  MuonsJet_pt_->SetMarkerStyle(23); MuonsJet_pt_->SetMarkerColor(2); MuonsJet_pt_->SetMarkerSize(2);
  MuonsBTag_pt_ -> Draw("E1same"); MuonsBTag_pt_->SetLineColor(9); MuonsBTag_pt_->SetLineWidth(2);
  MuonsBTag_pt_->SetMarkerStyle(22); MuonsBTag_pt_->SetMarkerColor(9); MuonsBTag_pt_->SetMarkerSize(2);
  MuonsMultiJet_pt_ -> Draw("E1same"); MuonsMultiJet_pt_->SetLineColor(8); MuonsMultiJet_pt_->SetLineWidth(2);
  MuonsMultiJet_pt_->SetMarkerStyle(34); MuonsMultiJet_pt_->SetMarkerColor(8); MuonsMultiJet_pt_->SetMarkerSize(2);
  legend -> Draw();  Espectro_pT__Muons -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/pT__Muons.png"); Espectro_pT__Muons -> Close();


  TCanvas* Espectro_pT__Electrons = new TCanvas("pT Electrones","Espectro de pT de Electrones y gsfElectrones",10,10,1920,1080);
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
  gsfElectronsJet_pt_ -> Draw("E1same"); gsfElectronsJet_pt_->SetLineColor(2); gsfElectronsJet_pt_->SetLineWidth(2);
  gsfElectronsJet_pt_->SetMarkerStyle(23); gsfElectronsJet_pt_->SetMarkerColor(2); gsfElectronsJet_pt_->SetMarkerSize(2);
  gsfElectronsBTag_pt_ -> Draw("E1same"); gsfElectronsBTag_pt_->SetLineColor(9); gsfElectronsBTag_pt_->SetLineWidth(2);
  gsfElectronsBTag_pt_->SetMarkerStyle(22); gsfElectronsBTag_pt_->SetMarkerColor(9); gsfElectronsBTag_pt_->SetMarkerSize(2);
  gsfElectronsMultiJet_pt_ -> Draw("E1same"); gsfElectronsMultiJet_pt_->SetLineColor(8); gsfElectronsMultiJet_pt_->SetLineWidth(2);
  gsfElectronsMultiJet_pt_->SetMarkerStyle(34); gsfElectronsMultiJet_pt_->SetMarkerColor(8); gsfElectronsMultiJet_pt_->SetMarkerSize(2);
  legend -> Draw();  Espectro_pT__Electrons -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/pT__Electrons.png"); Espectro_pT__Electrons -> Close();
*/

  TCanvas* Cociente_pT__Muon_Jet = new TCanvas("Cociente_pT__Muon_Jet","Cociente pT FastJet y PFJets para muones",10,10,1920,1080);
  Cociente_pT__Muon_Jet->SetFillColor(0);  Cociente_pT__Muon_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  Cociente_pT__Muon_ak5FJ->SetTitle("Cociente p_{T} para muones; p_{T}^{Muon} / p_{T}^{Jet}; U. A.");
  Cociente_pT__Muon_ak5FJ->GetXaxis()->SetLabelSize(0.05); Cociente_pT__Muon_ak5FJ->GetYaxis()->SetLabelSize(0.05);
  Cociente_pT__Muon_ak5FJ->GetXaxis()->SetTitleSize(0.05); Cociente_pT__Muon_ak5FJ->GetYaxis()->SetTitleSize(0.05);
  Cociente_pT__Muon_ak5FJ->GetXaxis()->SetTitleOffset(1.0);Cociente_pT__Muon_ak5FJ->GetYaxis()->SetTitleOffset(1.0);
  // Cociente_pT__Muon_ak5FJ->SetAxisRange(0.0, 1.2, "X");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Cociente_pT__Muon_ak5FJ -> Draw("E1"); Cociente_pT__Muon_ak5FJ->SetLineColor(1); Cociente_pT__Muon_ak5FJ->SetLineWidth(2);
  Cociente_pT__Muon_ak5FJ->SetMarkerStyle(20); Cociente_pT__Muon_ak5FJ->SetMarkerColor(1); Cociente_pT__Muon_ak5FJ->SetMarkerSize(2);
  Cociente_pT__Muon_ak5PFJet -> Draw("E1same"); Cociente_pT__Muon_ak5PFJet->SetLineColor(2); Cociente_pT__Muon_ak5PFJet->SetLineWidth(2);
  Cociente_pT__Muon_ak5PFJet->SetMarkerStyle(23); Cociente_pT__Muon_ak5PFJet->SetMarkerColor(2); Cociente_pT__Muon_ak5PFJet->SetMarkerSize(2);
  Cociente_pT__Muon_ak5PFBTag -> Draw("E1same"); Cociente_pT__Muon_ak5PFBTag->SetLineColor(4); Cociente_pT__Muon_ak5PFBTag->SetLineWidth(2);
  Cociente_pT__Muon_ak5PFBTag->SetMarkerStyle(22); Cociente_pT__Muon_ak5PFBTag->SetMarkerColor(4); Cociente_pT__Muon_ak5PFBTag->SetMarkerSize(2);
  Cociente_pT__Muon_ak5PFMinBias -> Draw("E1same"); Cociente_pT__Muon_ak5PFMinBias->SetLineColor(30); Cociente_pT__Muon_ak5PFMinBias->SetLineWidth(2);
  Cociente_pT__Muon_ak5PFMinBias->SetMarkerStyle(29); Cociente_pT__Muon_ak5PFMinBias->SetMarkerColor(30); Cociente_pT__Muon_ak5PFMinBias->SetMarkerSize(2);
  Cociente_pT__Muon_ak5PFMultiJet -> Draw("E1same"); Cociente_pT__Muon_ak5PFMultiJet->SetLineColor(8); Cociente_pT__Muon_ak5PFMultiJet->SetLineWidth(2);
  Cociente_pT__Muon_ak5PFMultiJet->SetMarkerStyle(34); Cociente_pT__Muon_ak5PFMultiJet->SetMarkerColor(8); Cociente_pT__Muon_ak5PFMultiJet->SetMarkerSize(2);
  legend -> Draw();  Cociente_pT__Muon_Jet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT__Muon_Jet.png"); Cociente_pT__Muon_Jet -> Close();


      TCanvas* Cociente_pT__MuonQuark_Jet = new TCanvas("Cociente_pT__MuonQuark_Jet","Cociente pT FastJet y PFJets para electrones",10,10,1920,1080);
      Cociente_pT__MuonQuark_Jet->SetFillColor(0);  Cociente_pT__MuonQuark_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
      // Esto es para modificar las etiquetas del canvas.
      Cociente_pT__Muon_ak5FJ->SetTitle("Cociente p_{T} para muones considerando el Parton madre; p_{T}^{Electron} / p_{T}^{Jet}; U. A.");
      Cociente_pT__Muon_ak5FJ->GetXaxis()->SetLabelSize(0.05); Cociente_pT__Muon_ak5FJ->GetYaxis()->SetLabelSize(0.05);
      Cociente_pT__Muon_ak5FJ->GetXaxis()->SetTitleSize(0.05); Cociente_pT__Muon_ak5FJ->GetYaxis()->SetTitleSize(0.05);
      Cociente_pT__Muon_ak5FJ->GetXaxis()->SetTitleOffset(1.0);Cociente_pT__Muon_ak5FJ->GetYaxis()->SetTitleOffset(1.0);
      // Cociente_pT__Muon_ak5FJ->SetAxisRange(0.0, 2, "X");
      // Aqui ponemos todas las gráficas que necesitamos en el canvas.
      Cociente_pT__Muon_ak5FJ -> Draw("E1"); Cociente_pT__Muon_ak5FJ->SetLineColor(1); Cociente_pT__Muon_ak5FJ->SetLineWidth(2);
      Cociente_pT__Muon_ak5FJ->SetMarkerStyle(20); Cociente_pT__Muon_ak5FJ->SetMarkerColor(1); Cociente_pT__Muon_ak5FJ->SetMarkerSize(2);
      Cociente_pT__Muon01_ak5FJ -> Draw("E1same"); Cociente_pT__Muon01_ak5FJ->SetLineColor(30); Cociente_pT__Muon01_ak5FJ->SetLineWidth(2);
      Cociente_pT__Muon01_ak5FJ->SetMarkerStyle(22); Cociente_pT__Muon01_ak5FJ->SetMarkerColor(30); Cociente_pT__Muon01_ak5FJ->SetMarkerSize(2);
      Cociente_pT__Muon02_ak5FJ -> Draw("E1same"); Cociente_pT__Muon02_ak5FJ->SetLineColor(38); Cociente_pT__Muon02_ak5FJ->SetLineWidth(2);
      Cociente_pT__Muon02_ak5FJ->SetMarkerStyle(23); Cociente_pT__Muon02_ak5FJ->SetMarkerColor(38); Cociente_pT__Muon02_ak5FJ->SetMarkerSize(2);
      Cociente_pT__Muon03_ak5FJ -> Draw("E1same"); Cociente_pT__Muon03_ak5FJ->SetLineColor(40); Cociente_pT__Muon03_ak5FJ->SetLineWidth(2);
      Cociente_pT__Muon03_ak5FJ->SetMarkerStyle(22); Cociente_pT__Muon03_ak5FJ->SetMarkerColor(40); Cociente_pT__Muon03_ak5FJ->SetMarkerSize(2);
      Cociente_pT__Muon04_ak5FJ -> Draw("E1same"); Cociente_pT__Muon04_ak5FJ->SetLineColor(30); Cociente_pT__Muon04_ak5FJ->SetLineWidth(2);
      Cociente_pT__Muon04_ak5FJ->SetMarkerStyle(23); Cociente_pT__Muon04_ak5FJ->SetMarkerColor(30); Cociente_pT__Muon04_ak5FJ->SetMarkerSize(2);
      Cociente_pT__Muon05_ak5FJ -> Draw("E1same"); Cociente_pT__Muon05_ak5FJ->SetLineColor(42); Cociente_pT__Muon05_ak5FJ->SetLineWidth(2);
      Cociente_pT__Muon05_ak5FJ->SetMarkerStyle(22); Cociente_pT__Muon05_ak5FJ->SetMarkerColor(42); Cociente_pT__Muon05_ak5FJ->SetMarkerSize(2);
      Cociente_pT__Muon21_ak5FJ -> Draw("E1same"); Cociente_pT__Muon21_ak5FJ->SetLineColor(45); Cociente_pT__Muon21_ak5FJ->SetLineWidth(2);
      Cociente_pT__Muon21_ak5FJ->SetMarkerStyle(23); Cociente_pT__Muon21_ak5FJ->SetMarkerColor(45); Cociente_pT__Muon21_ak5FJ->SetMarkerSize(2);
      QuarkLegend -> Draw();  Cociente_pT__MuonQuark_Jet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT__MuonQuark_Jet.png"); Cociente_pT__MuonQuark_Jet -> Close();


      TCanvas* Cociente_pT__ODMuonQuark_Jet = new TCanvas("Cociente_pT__ODMuonQuark_Jet","Cociente pT FastJet y PFJets para electrones",10,10,1920,1080);
      Cociente_pT__ODMuonQuark_Jet->SetFillColor(0);  Cociente_pT__ODMuonQuark_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
      // Esto es para modificar las etiquetas del canvas.
      Cociente_pT__Muon_ak5PFJet->SetTitle("Cociente p_{T} para muones considerando el Parton madre; p_{T}^{Electron} / p_{T}^{Jet}; U. A.");
      Cociente_pT__Muon_ak5PFJet->GetXaxis()->SetLabelSize(0.05); Cociente_pT__Muon_ak5PFJet->GetYaxis()->SetLabelSize(0.05);
      Cociente_pT__Muon_ak5PFJet->GetXaxis()->SetTitleSize(0.05); Cociente_pT__Muon_ak5PFJet->GetYaxis()->SetTitleSize(0.05);
      Cociente_pT__Muon_ak5PFJet->GetXaxis()->SetTitleOffset(1.0);Cociente_pT__Muon_ak5PFJet->GetYaxis()->SetTitleOffset(1.0);
      // Cociente_pT__Muon_ak5PFJet->SetAxisRange(0.0, 1.2, "X");
      // Aqui ponemos todas las gráficas que necesitamos en el canvas.
      Cociente_pT__Muon_ak5PFJet -> Draw("E1"); Cociente_pT__Muon_ak5PFJet->SetLineColor(2); Cociente_pT__Muon_ak5PFJet->SetLineWidth(2);
      Cociente_pT__Muon_ak5PFJet->SetMarkerStyle(20); Cociente_pT__Muon_ak5PFJet->SetMarkerColor(2); Cociente_pT__Muon_ak5PFJet->SetMarkerSize(2);
      Cociente_pT__Muon01_ak5FJ -> Draw("E1same"); Cociente_pT__Muon01_ak5FJ->SetLineColor(30); Cociente_pT__Muon01_ak5FJ->SetLineWidth(2);
      Cociente_pT__Muon01_ak5FJ->SetMarkerStyle(22); Cociente_pT__Muon01_ak5FJ->SetMarkerColor(30); Cociente_pT__Muon01_ak5FJ->SetMarkerSize(2);
      Cociente_pT__Muon02_ak5FJ -> Draw("E1same"); Cociente_pT__Muon02_ak5FJ->SetLineColor(38); Cociente_pT__Muon02_ak5FJ->SetLineWidth(2);
      Cociente_pT__Muon02_ak5FJ->SetMarkerStyle(23); Cociente_pT__Muon02_ak5FJ->SetMarkerColor(38); Cociente_pT__Muon02_ak5FJ->SetMarkerSize(2);
      Cociente_pT__Muon03_ak5FJ -> Draw("E1same"); Cociente_pT__Muon03_ak5FJ->SetLineColor(40); Cociente_pT__Muon03_ak5FJ->SetLineWidth(2);
      Cociente_pT__Muon03_ak5FJ->SetMarkerStyle(22); Cociente_pT__Muon03_ak5FJ->SetMarkerColor(40); Cociente_pT__Muon03_ak5FJ->SetMarkerSize(2);
      Cociente_pT__Muon04_ak5FJ -> Draw("E1same"); Cociente_pT__Muon04_ak5FJ->SetLineColor(30); Cociente_pT__Muon04_ak5FJ->SetLineWidth(2);
      Cociente_pT__Muon04_ak5FJ->SetMarkerStyle(23); Cociente_pT__Muon04_ak5FJ->SetMarkerColor(30); Cociente_pT__Muon04_ak5FJ->SetMarkerSize(2);
      Cociente_pT__Muon05_ak5FJ -> Draw("E1same"); Cociente_pT__Muon05_ak5FJ->SetLineColor(42); Cociente_pT__Muon05_ak5FJ->SetLineWidth(2);
      Cociente_pT__Muon05_ak5FJ->SetMarkerStyle(22); Cociente_pT__Muon05_ak5FJ->SetMarkerColor(42); Cociente_pT__Muon05_ak5FJ->SetMarkerSize(2);
      Cociente_pT__Muon21_ak5FJ -> Draw("E1same"); Cociente_pT__Muon21_ak5FJ->SetLineColor(45); Cociente_pT__Muon21_ak5FJ->SetLineWidth(2);
      Cociente_pT__Muon21_ak5FJ->SetMarkerStyle(23); Cociente_pT__Muon21_ak5FJ->SetMarkerColor(45); Cociente_pT__Muon21_ak5FJ->SetMarkerSize(2);
      ODQuarkLegend -> Draw();  Cociente_pT__ODMuonQuark_Jet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT__ODMuonQuark_Jet.png"); Cociente_pT__ODMuonQuark_Jet -> Close();


  TCanvas* Cociente_pT100__1Muon_Jet = new TCanvas("Cociente_pT100__1Muon_Jet","Cociente pT<100 FastJet y PFJets para muones",10,10,1920,1080);
  Cociente_pT100__1Muon_Jet->SetFillColor(0);  Cociente_pT100__1Muon_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  Cociente_pT100__1Muon_ak5FJ->SetTitle("Cociente p_{T} para el mu#acute{o}n m#acute{a}s energ#acute{e}tico en cada Jet (p_{T}^{Jet} < 100); p_{T}^{Muon} / p_{T}^{Jet}; U. A.");
  Cociente_pT100__1Muon_ak5FJ->GetXaxis()->SetLabelSize(0.05); Cociente_pT100__1Muon_ak5FJ->GetYaxis()->SetLabelSize(0.05);
  Cociente_pT100__1Muon_ak5FJ->GetXaxis()->SetTitleSize(0.05); Cociente_pT100__1Muon_ak5FJ->GetYaxis()->SetTitleSize(0.05);
  Cociente_pT100__1Muon_ak5FJ->GetXaxis()->SetTitleOffset(1.0);Cociente_pT100__1Muon_ak5FJ->GetYaxis()->SetTitleOffset(1.0);
  // Cociente_pT100__1Muon_ak5FJ->SetAxisRange(0.0, 1.2, "X");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Cociente_pT100__1Muon_ak5FJ -> Draw("E1"); Cociente_pT100__1Muon_ak5FJ->SetLineColor(1); Cociente_pT100__1Muon_ak5FJ->SetLineWidth(2);
  Cociente_pT100__1Muon_ak5FJ->SetMarkerStyle(20); Cociente_pT100__1Muon_ak5FJ->SetMarkerColor(1); Cociente_pT100__1Muon_ak5FJ->SetMarkerSize(2);
  Cociente_pT100__1Muon_ak5PFJet -> Draw("E1same"); Cociente_pT100__1Muon_ak5PFJet->SetLineColor(2); Cociente_pT100__1Muon_ak5PFJet->SetLineWidth(2);
  Cociente_pT100__1Muon_ak5PFJet->SetMarkerStyle(23); Cociente_pT100__1Muon_ak5PFJet->SetMarkerColor(2); Cociente_pT100__1Muon_ak5PFJet->SetMarkerSize(2);
  Cociente_pT100__1Muon_ak5PFBTag -> Draw("E1same"); Cociente_pT100__1Muon_ak5PFBTag->SetLineColor(4); Cociente_pT100__1Muon_ak5PFBTag->SetLineWidth(2);
  Cociente_pT100__1Muon_ak5PFBTag->SetMarkerStyle(22); Cociente_pT100__1Muon_ak5PFBTag->SetMarkerColor(4); Cociente_pT100__1Muon_ak5PFBTag->SetMarkerSize(2);
  Cociente_pT100__1Muon_ak5PFMinBias -> Draw("E1same"); Cociente_pT100__1Muon_ak5PFMinBias->SetLineColor(30); Cociente_pT100__1Muon_ak5PFMinBias->SetLineWidth(2);
  Cociente_pT100__1Muon_ak5PFMinBias->SetMarkerStyle(29); Cociente_pT100__1Muon_ak5PFMinBias->SetMarkerColor(30); Cociente_pT100__1Muon_ak5PFMinBias->SetMarkerSize(2);
  Cociente_pT100__1Muon_ak5PFMultiJet -> Draw("E1same"); Cociente_pT100__1Muon_ak5PFMultiJet->SetLineColor(8); Cociente_pT100__1Muon_ak5PFMultiJet->SetLineWidth(2);
  Cociente_pT100__1Muon_ak5PFMultiJet->SetMarkerStyle(34); Cociente_pT100__1Muon_ak5PFMultiJet->SetMarkerColor(8); Cociente_pT100__1Muon_ak5PFMultiJet->SetMarkerSize(2);
  legend -> Draw();  Cociente_pT100__1Muon_Jet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT<100__1Muon_Jet.png"); Cociente_pT100__1Muon_Jet -> Close();


  TCanvas* Cociente_100pT__1Muon_Jet = new TCanvas("Cociente_100pT__1Muon_Jet","Cociente pT>100 FastJet y PFJets para muones",10,10,1920,1080);
  Cociente_100pT__1Muon_Jet->SetFillColor(0);  Cociente_100pT__1Muon_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  Cociente_100pT__1Muon_ak5FJ->SetTitle("Cociente p_{T} para el mu#acute{o}n m#acute{a}s energ#acute{e}tico en cada Jet (p_{T}^{Jet} > 100); p_{T}^{Muon} / p_{T}^{Jet}; U. A.");
  Cociente_100pT__1Muon_ak5FJ->GetXaxis()->SetLabelSize(0.05); Cociente_100pT__1Muon_ak5FJ->GetYaxis()->SetLabelSize(0.05);
  Cociente_100pT__1Muon_ak5FJ->GetXaxis()->SetTitleSize(0.05); Cociente_100pT__1Muon_ak5FJ->GetYaxis()->SetTitleSize(0.05);
  Cociente_100pT__1Muon_ak5FJ->GetXaxis()->SetTitleOffset(1.0);Cociente_100pT__1Muon_ak5FJ->GetYaxis()->SetTitleOffset(1.0);
  // Cociente_100pT__1Muon_ak5FJ->SetAxisRange(0.0, 1.2, "X");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Cociente_100pT__1Muon_ak5FJ -> Draw("E1"); Cociente_100pT__1Muon_ak5FJ->SetLineColor(1); Cociente_100pT__1Muon_ak5FJ->SetLineWidth(2);
  Cociente_100pT__1Muon_ak5FJ->SetMarkerStyle(20); Cociente_100pT__1Muon_ak5FJ->SetMarkerColor(1); Cociente_100pT__1Muon_ak5FJ->SetMarkerSize(2);
  Cociente_100pT__1Muon_ak5PFJet -> Draw("E1same"); Cociente_100pT__1Muon_ak5PFJet->SetLineColor(2); Cociente_100pT__1Muon_ak5PFJet->SetLineWidth(2);
  Cociente_100pT__1Muon_ak5PFJet->SetMarkerStyle(23); Cociente_100pT__1Muon_ak5PFJet->SetMarkerColor(2); Cociente_100pT__1Muon_ak5PFJet->SetMarkerSize(2);
  Cociente_100pT__1Muon_ak5PFBTag -> Draw("E1same"); Cociente_100pT__1Muon_ak5PFBTag->SetLineColor(4); Cociente_100pT__1Muon_ak5PFBTag->SetLineWidth(2);
  Cociente_100pT__1Muon_ak5PFBTag->SetMarkerStyle(22); Cociente_100pT__1Muon_ak5PFBTag->SetMarkerColor(4); Cociente_100pT__1Muon_ak5PFBTag->SetMarkerSize(2);
  Cociente_100pT__1Muon_ak5PFMinBias -> Draw("E1same"); Cociente_100pT__1Muon_ak5PFMinBias->SetLineColor(30); Cociente_100pT__1Muon_ak5PFMinBias->SetLineWidth(2);
  Cociente_100pT__1Muon_ak5PFMinBias->SetMarkerStyle(29); Cociente_100pT__1Muon_ak5PFMinBias->SetMarkerColor(30); Cociente_100pT__1Muon_ak5PFMinBias->SetMarkerSize(2);
  Cociente_100pT__1Muon_ak5PFMultiJet -> Draw("E1same"); Cociente_100pT__1Muon_ak5PFMultiJet->SetLineColor(8); Cociente_100pT__1Muon_ak5PFMultiJet->SetLineWidth(2);
  Cociente_100pT__1Muon_ak5PFMultiJet->SetMarkerStyle(34); Cociente_100pT__1Muon_ak5PFMultiJet->SetMarkerColor(8); Cociente_100pT__1Muon_ak5PFMultiJet->SetMarkerSize(2);
  legend -> Draw();  Cociente_100pT__1Muon_Jet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT>100__1Muon_Jet.png"); Cociente_100pT__1Muon_Jet -> Close();


  TCanvas* Cociente_pT__Electron_Jet = new TCanvas("Cociente_pT__Electron_Jet","Cociente pT FastJet y PFJets para electrones",10,10,1920,1080);
  Cociente_pT__Electron_Jet->SetFillColor(0);  Cociente_pT__Electron_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  Cociente_pT__Electron_ak5FJ->SetTitle("Cociente p_{T} para electrones; p_{T}^{Electron} / p_{T}^{Jet}; U. A.");
  Cociente_pT__Electron_ak5FJ->GetXaxis()->SetLabelSize(0.05); Cociente_pT__Electron_ak5FJ->GetYaxis()->SetLabelSize(0.05);
  Cociente_pT__Electron_ak5FJ->GetXaxis()->SetTitleSize(0.05); Cociente_pT__Electron_ak5FJ->GetYaxis()->SetTitleSize(0.05);
  Cociente_pT__Electron_ak5FJ->GetXaxis()->SetTitleOffset(1.0);Cociente_pT__Electron_ak5FJ->GetYaxis()->SetTitleOffset(1.0);
  // Cociente_pT__Electron_ak5FJ->SetAxisRange(0.0, 1.2, "X");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Cociente_pT__Electron_ak5FJ -> Draw("E1"); Cociente_pT__Electron_ak5FJ->SetLineColor(1); Cociente_pT__Electron_ak5FJ->SetLineWidth(2);
  Cociente_pT__Electron_ak5FJ->SetMarkerStyle(20); Cociente_pT__Electron_ak5FJ->SetMarkerColor(1); Cociente_pT__Electron_ak5FJ->SetMarkerSize(2);
  Cociente_pT__gsfElectron_ak5PFJet -> Draw("E1same"); Cociente_pT__gsfElectron_ak5PFJet->SetLineColor(2); Cociente_pT__gsfElectron_ak5PFJet->SetLineWidth(2);
  Cociente_pT__gsfElectron_ak5PFJet->SetMarkerStyle(23); Cociente_pT__gsfElectron_ak5PFJet->SetMarkerColor(2); Cociente_pT__gsfElectron_ak5PFJet->SetMarkerSize(2);
  Cociente_pT__gsfElectron_ak5PFBTag -> Draw("E1same"); Cociente_pT__gsfElectron_ak5PFBTag->SetLineColor(4); Cociente_pT__gsfElectron_ak5PFBTag->SetLineWidth(2);
  Cociente_pT__gsfElectron_ak5PFBTag->SetMarkerStyle(22); Cociente_pT__gsfElectron_ak5PFBTag->SetMarkerColor(4); Cociente_pT__gsfElectron_ak5PFBTag->SetMarkerSize(2);
  Cociente_pT__gsfElectron_ak5PFMinBias -> Draw("E1same"); Cociente_pT__gsfElectron_ak5PFMinBias->SetLineColor(30); Cociente_pT__gsfElectron_ak5PFMinBias->SetLineWidth(2);
  Cociente_pT__gsfElectron_ak5PFMinBias->SetMarkerStyle(29); Cociente_pT__gsfElectron_ak5PFMinBias->SetMarkerColor(30); Cociente_pT__gsfElectron_ak5PFMinBias->SetMarkerSize(2);
  Cociente_pT__gsfElectron_ak5PFMultiJet -> Draw("E1same"); Cociente_pT__gsfElectron_ak5PFMultiJet->SetLineColor(8); Cociente_pT__gsfElectron_ak5PFMultiJet->SetLineWidth(2);
  Cociente_pT__gsfElectron_ak5PFMultiJet->SetMarkerStyle(34); Cociente_pT__gsfElectron_ak5PFMultiJet->SetMarkerColor(8); Cociente_pT__gsfElectron_ak5PFMultiJet->SetMarkerSize(2);
  legend -> Draw();  Cociente_pT__Electron_Jet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT__Electron_Jet.png"); Cociente_pT__Electron_Jet -> Close();


    TCanvas* Cociente_pT__ElecQuark_Jet = new TCanvas("Cociente_pT__ElecQuark_Jet","Cociente pT FastJet y PFJets para electrones",10,10,1920,1080);
    Cociente_pT__ElecQuark_Jet->SetFillColor(0);  Cociente_pT__ElecQuark_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
    // Esto es para modificar las etiquetas del canvas.
    Cociente_pT__Electron_ak5FJ->SetTitle("Cociente p_{T} para electrones considerando el Parton madre; p_{T}^{Electron} / p_{T}^{Jet}; U. A.");
    Cociente_pT__Electron_ak5FJ->GetXaxis()->SetLabelSize(0.05); Cociente_pT__Electron_ak5FJ->GetYaxis()->SetLabelSize(0.05);
    Cociente_pT__Electron_ak5FJ->GetXaxis()->SetTitleSize(0.05); Cociente_pT__Electron_ak5FJ->GetYaxis()->SetTitleSize(0.05);
    Cociente_pT__Electron_ak5FJ->GetXaxis()->SetTitleOffset(1.0);Cociente_pT__Electron_ak5FJ->GetYaxis()->SetTitleOffset(1.0);
    // Cociente_pT__Electron_ak5FJ->SetAxisRange(0.0, 1.2, "X");
    // Aqui ponemos todas las gráficas que necesitamos en el canvas.
    Cociente_pT__Electron_ak5FJ -> Draw("E1"); Cociente_pT__Electron_ak5FJ->SetLineColor(1); Cociente_pT__Electron_ak5FJ->SetLineWidth(2);
    Cociente_pT__Electron_ak5FJ->SetMarkerStyle(20); Cociente_pT__Electron_ak5FJ->SetMarkerColor(1); Cociente_pT__Electron_ak5FJ->SetMarkerSize(2);
    Cociente_pT__Electron01_ak5FJ -> Draw("E1same"); Cociente_pT__Electron01_ak5FJ->SetLineColor(30); Cociente_pT__Electron01_ak5FJ->SetLineWidth(2);
    Cociente_pT__Electron01_ak5FJ->SetMarkerStyle(22); Cociente_pT__Electron01_ak5FJ->SetMarkerColor(30); Cociente_pT__Electron01_ak5FJ->SetMarkerSize(2);
    Cociente_pT__Electron02_ak5FJ -> Draw("E1same"); Cociente_pT__Electron02_ak5FJ->SetLineColor(38); Cociente_pT__Electron02_ak5FJ->SetLineWidth(2);
    Cociente_pT__Electron02_ak5FJ->SetMarkerStyle(23); Cociente_pT__Electron02_ak5FJ->SetMarkerColor(38); Cociente_pT__Electron02_ak5FJ->SetMarkerSize(2);
    Cociente_pT__Electron03_ak5FJ -> Draw("E1same"); Cociente_pT__Electron03_ak5FJ->SetLineColor(40); Cociente_pT__Electron03_ak5FJ->SetLineWidth(2);
    Cociente_pT__Electron03_ak5FJ->SetMarkerStyle(22); Cociente_pT__Electron03_ak5FJ->SetMarkerColor(40); Cociente_pT__Electron03_ak5FJ->SetMarkerSize(2);
    Cociente_pT__Electron04_ak5FJ -> Draw("E1same"); Cociente_pT__Electron04_ak5FJ->SetLineColor(30); Cociente_pT__Electron04_ak5FJ->SetLineWidth(2);
    Cociente_pT__Electron04_ak5FJ->SetMarkerStyle(23); Cociente_pT__Electron04_ak5FJ->SetMarkerColor(30); Cociente_pT__Electron04_ak5FJ->SetMarkerSize(2);
    Cociente_pT__Electron05_ak5FJ -> Draw("E1same"); Cociente_pT__Electron05_ak5FJ->SetLineColor(42); Cociente_pT__Electron05_ak5FJ->SetLineWidth(2);
    Cociente_pT__Electron05_ak5FJ->SetMarkerStyle(22); Cociente_pT__Electron05_ak5FJ->SetMarkerColor(42); Cociente_pT__Electron05_ak5FJ->SetMarkerSize(2);
    Cociente_pT__Electron21_ak5FJ -> Draw("E1same"); Cociente_pT__Electron21_ak5FJ->SetLineColor(45); Cociente_pT__Electron21_ak5FJ->SetLineWidth(2);
    Cociente_pT__Electron21_ak5FJ->SetMarkerStyle(23); Cociente_pT__Electron21_ak5FJ->SetMarkerColor(45); Cociente_pT__Electron21_ak5FJ->SetMarkerSize(2);
    QuarkLegend -> Draw();  Cociente_pT__ElecQuark_Jet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT__ElecQuark_Jet.png"); Cociente_pT__ElecQuark_Jet -> Close();


    TCanvas* Cociente_pT__gsfElecQuark_Jet = new TCanvas("Cociente_pT__gsfElecQuark_Jet","Cociente pT FastJet y PFJets para electrones",10,10,1920,1080);
    Cociente_pT__ElecQuark_Jet->SetFillColor(0);  Cociente_pT__ElecQuark_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
    // Esto es para modificar las etiquetas del canvas.
    Cociente_pT__gsfElectron_ak5PFJet->SetTitle("Cociente p_{T} para electrones considerando el Parton madre; p_{T}^{Electron} / p_{T}^{Jet}; U. A.");
    Cociente_pT__gsfElectron_ak5PFJet->GetXaxis()->SetLabelSize(0.05); Cociente_pT__gsfElectron_ak5PFJet->GetYaxis()->SetLabelSize(0.05);
    Cociente_pT__gsfElectron_ak5PFJet->GetXaxis()->SetTitleSize(0.05); Cociente_pT__gsfElectron_ak5PFJet->GetYaxis()->SetTitleSize(0.05);
    Cociente_pT__gsfElectron_ak5PFJet->GetXaxis()->SetTitleOffset(1.0);Cociente_pT__gsfElectron_ak5PFJet->GetYaxis()->SetTitleOffset(1.0);
    // Cociente_pT__gsfElectron_ak5PFJet->SetAxisRange(0.0, 1.2, "X");
    // Aqui ponemos todas las gráficas que necesitamos en el canvas.
    Cociente_pT__gsfElectron_ak5PFJet -> Draw("E1"); Cociente_pT__gsfElectron_ak5PFJet->SetLineColor(2); Cociente_pT__gsfElectron_ak5PFJet->SetLineWidth(2);
    Cociente_pT__gsfElectron_ak5PFJet->SetMarkerStyle(20); Cociente_pT__gsfElectron_ak5PFJet->SetMarkerColor(2); Cociente_pT__gsfElectron_ak5PFJet->SetMarkerSize(2);
    Cociente_pT__Electron01_ak5FJ -> Draw("E1same"); Cociente_pT__Electron01_ak5FJ->SetLineColor(30); Cociente_pT__Electron01_ak5FJ->SetLineWidth(2);
    Cociente_pT__Electron01_ak5FJ->SetMarkerStyle(22); Cociente_pT__Electron01_ak5FJ->SetMarkerColor(30); Cociente_pT__Electron01_ak5FJ->SetMarkerSize(2);
    Cociente_pT__Electron02_ak5FJ -> Draw("E1same"); Cociente_pT__Electron02_ak5FJ->SetLineColor(38); Cociente_pT__Electron02_ak5FJ->SetLineWidth(2);
    Cociente_pT__Electron02_ak5FJ->SetMarkerStyle(23); Cociente_pT__Electron02_ak5FJ->SetMarkerColor(38); Cociente_pT__Electron02_ak5FJ->SetMarkerSize(2);
    Cociente_pT__Electron03_ak5FJ -> Draw("E1same"); Cociente_pT__Electron03_ak5FJ->SetLineColor(40); Cociente_pT__Electron03_ak5FJ->SetLineWidth(2);
    Cociente_pT__Electron03_ak5FJ->SetMarkerStyle(22); Cociente_pT__Electron03_ak5FJ->SetMarkerColor(40); Cociente_pT__Electron03_ak5FJ->SetMarkerSize(2);
    Cociente_pT__Electron04_ak5FJ -> Draw("E1same"); Cociente_pT__Electron04_ak5FJ->SetLineColor(30); Cociente_pT__Electron04_ak5FJ->SetLineWidth(2);
    Cociente_pT__Electron04_ak5FJ->SetMarkerStyle(23); Cociente_pT__Electron04_ak5FJ->SetMarkerColor(30); Cociente_pT__Electron04_ak5FJ->SetMarkerSize(2);
    Cociente_pT__Electron05_ak5FJ -> Draw("E1same"); Cociente_pT__Electron05_ak5FJ->SetLineColor(42); Cociente_pT__Electron05_ak5FJ->SetLineWidth(2);
    Cociente_pT__Electron05_ak5FJ->SetMarkerStyle(22); Cociente_pT__Electron05_ak5FJ->SetMarkerColor(42); Cociente_pT__Electron05_ak5FJ->SetMarkerSize(2);
    Cociente_pT__Electron21_ak5FJ -> Draw("E1same"); Cociente_pT__Electron21_ak5FJ->SetLineColor(45); Cociente_pT__Electron21_ak5FJ->SetLineWidth(2);
    Cociente_pT__Electron21_ak5FJ->SetMarkerStyle(23); Cociente_pT__Electron21_ak5FJ->SetMarkerColor(45); Cociente_pT__Electron21_ak5FJ->SetMarkerSize(2);
    ODQuarkLegend -> Draw();  Cociente_pT__gsfElecQuark_Jet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT__gsfElecQuark_Jet.png"); Cociente_pT__gsfElecQuark_Jet -> Close();


  TCanvas* Cociente_pT100__1Electron_Jet = new TCanvas("Cociente_pT100__1Electron_Jet","Cociente pT<100 FastJet y PFJets para electrones",10,10,1920,1080);
  Cociente_pT100__1Electron_Jet->SetFillColor(0);  Cociente_pT100__1Electron_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  Cociente_pT100__1Electron_ak5FJ->SetTitle("Cociente p_{T} para el electrones m#acute{a}s energ#acute{e}tico en cada Jet (p_{T}^{Jet} < 100); p_{T}^{Electron} / p_{T}^{Jet}; U. A.");
  Cociente_pT100__1Electron_ak5FJ->GetXaxis()->SetLabelSize(0.05); Cociente_pT100__1Electron_ak5FJ->GetYaxis()->SetLabelSize(0.05);
  Cociente_pT100__1Electron_ak5FJ->GetXaxis()->SetTitleSize(0.05); Cociente_pT100__1Electron_ak5FJ->GetYaxis()->SetTitleSize(0.05);
  Cociente_pT100__1Electron_ak5FJ->GetXaxis()->SetTitleOffset(1.0);Cociente_pT100__1Electron_ak5FJ->GetYaxis()->SetTitleOffset(1.0);
  // Cociente_pT100__1Electron_ak5FJ->SetAxisRange(0.0, 1.2, "X");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Cociente_pT100__1Electron_ak5FJ -> Draw("E1"); Cociente_pT100__1Electron_ak5FJ->SetLineColor(1); Cociente_pT100__1Electron_ak5FJ->SetLineWidth(2);
  Cociente_pT100__1Electron_ak5FJ->SetMarkerStyle(20); Cociente_pT100__1Electron_ak5FJ->SetMarkerColor(1); Cociente_pT100__1Electron_ak5FJ->SetMarkerSize(2);
  Cociente_pT100__1gsfElectron_ak5PFJet -> Draw("E1same"); Cociente_pT100__1gsfElectron_ak5PFJet->SetLineColor(2); Cociente_pT100__1gsfElectron_ak5PFJet->SetLineWidth(2);
  Cociente_pT100__1gsfElectron_ak5PFJet->SetMarkerStyle(23); Cociente_pT100__1gsfElectron_ak5PFJet->SetMarkerColor(2); Cociente_pT100__1gsfElectron_ak5PFJet->SetMarkerSize(2);
  Cociente_pT100__1gsfElectron_ak5PFBTag -> Draw("E1same"); Cociente_pT100__1gsfElectron_ak5PFBTag->SetLineColor(4); Cociente_pT100__1gsfElectron_ak5PFBTag->SetLineWidth(2);
  Cociente_pT100__1gsfElectron_ak5PFBTag->SetMarkerStyle(22); Cociente_pT100__1gsfElectron_ak5PFBTag->SetMarkerColor(4); Cociente_pT100__1gsfElectron_ak5PFBTag->SetMarkerSize(2);
  Cociente_pT100__1gsfElectron_ak5PFMinBias -> Draw("E1same"); Cociente_pT100__1gsfElectron_ak5PFMinBias->SetLineColor(30); Cociente_pT100__1gsfElectron_ak5PFMinBias->SetLineWidth(2);
  Cociente_pT100__1gsfElectron_ak5PFMinBias->SetMarkerStyle(29); Cociente_pT100__1gsfElectron_ak5PFMinBias->SetMarkerColor(30); Cociente_pT100__1gsfElectron_ak5PFMinBias->SetMarkerSize(2);
  Cociente_pT100__1gsfElectron_ak5PFMultiJet -> Draw("E1same"); Cociente_pT100__1gsfElectron_ak5PFMultiJet->SetLineColor(8); Cociente_pT100__1gsfElectron_ak5PFMultiJet->SetLineWidth(2);
  Cociente_pT100__1gsfElectron_ak5PFMultiJet->SetMarkerStyle(34); Cociente_pT100__1gsfElectron_ak5PFMultiJet->SetMarkerColor(8); Cociente_pT100__1gsfElectron_ak5PFMultiJet->SetMarkerSize(2);
  legend -> Draw();  Cociente_pT100__1Electron_Jet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT<100__1Electron_Jet.png"); Cociente_pT100__1Electron_Jet -> Close();


  TCanvas* Cociente_100pT__1Electron_Jet = new TCanvas("Cociente_100pT__1Electron_Jet","Cociente pT>100 FastJet y PFJets para electrones",10,10,1920,1080);
  Cociente_100pT__1Electron_Jet->SetFillColor(0);  Cociente_100pT__1Electron_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  Cociente_100pT__1Electron_ak5FJ->SetTitle("Cociente p_{T} para el electron m#acute{a}s energ#acute{e}tico en cada Jet (p_{T}^{Jet} > 100); p_{T}^{Electron} / p_{T}^{Jet}; U. A.");
  Cociente_100pT__1Electron_ak5FJ->GetXaxis()->SetLabelSize(0.05); Cociente_100pT__1Electron_ak5FJ->GetYaxis()->SetLabelSize(0.05);
  Cociente_100pT__1Electron_ak5FJ->GetXaxis()->SetTitleSize(0.05); Cociente_100pT__1Electron_ak5FJ->GetYaxis()->SetTitleSize(0.05);
  Cociente_100pT__1Electron_ak5FJ->GetXaxis()->SetTitleOffset(1.0);Cociente_100pT__1Electron_ak5FJ->GetYaxis()->SetTitleOffset(1.0);
  // Cociente_100pT__1Electron_ak5FJ->SetAxisRange(0.0, 1.2, "X");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Cociente_100pT__1Electron_ak5FJ -> Draw("E1"); Cociente_100pT__1Electron_ak5FJ->SetLineColor(1); Cociente_100pT__1Electron_ak5FJ->SetLineWidth(2);
  Cociente_100pT__1Electron_ak5FJ->SetMarkerStyle(20); Cociente_100pT__1Electron_ak5FJ->SetMarkerColor(1); Cociente_100pT__1Electron_ak5FJ->SetMarkerSize(2);
  Cociente_100pT__1gsfElectron_ak5PFJet -> Draw("E1same"); Cociente_100pT__1gsfElectron_ak5PFJet->SetLineColor(2); Cociente_100pT__1gsfElectron_ak5PFJet->SetLineWidth(2);
  Cociente_100pT__1gsfElectron_ak5PFJet->SetMarkerStyle(23); Cociente_100pT__1gsfElectron_ak5PFJet->SetMarkerColor(2); Cociente_100pT__1gsfElectron_ak5PFJet->SetMarkerSize(2);
  Cociente_100pT__1gsfElectron_ak5PFBTag -> Draw("E1same"); Cociente_100pT__1gsfElectron_ak5PFBTag->SetLineColor(4); Cociente_100pT__1gsfElectron_ak5PFBTag->SetLineWidth(2);
  Cociente_100pT__1gsfElectron_ak5PFBTag->SetMarkerStyle(22); Cociente_100pT__1gsfElectron_ak5PFBTag->SetMarkerColor(4); Cociente_100pT__1gsfElectron_ak5PFBTag->SetMarkerSize(2);
  Cociente_100pT__1gsfElectron_ak5PFMinBias -> Draw("E1same"); Cociente_100pT__1gsfElectron_ak5PFMinBias->SetLineColor(30); Cociente_100pT__1gsfElectron_ak5PFMinBias->SetLineWidth(2);
  Cociente_100pT__1gsfElectron_ak5PFMinBias->SetMarkerStyle(29); Cociente_100pT__1gsfElectron_ak5PFMinBias->SetMarkerColor(30); Cociente_100pT__1gsfElectron_ak5PFMinBias->SetMarkerSize(2);
  Cociente_100pT__1gsfElectron_ak5PFMultiJet -> Draw("E1same"); Cociente_100pT__1gsfElectron_ak5PFMultiJet->SetLineColor(8); Cociente_100pT__1gsfElectron_ak5PFMultiJet->SetLineWidth(2);
  Cociente_100pT__1gsfElectron_ak5PFMultiJet->SetMarkerStyle(34); Cociente_100pT__1gsfElectron_ak5PFMultiJet->SetMarkerColor(8); Cociente_100pT__1gsfElectron_ak5PFMultiJet->SetMarkerSize(2);
  legend -> Draw();  Cociente_100pT__1Electron_Jet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT>100__1Electron_Jet.png"); Cociente_100pT__1Electron_Jet -> Close();

}


//###################################################################################################################################################################################

void Vertice() {
  //Abrimos el archivo que nos interesa y el árbol que queremos leer.
  TFile *FJFile = new TFile("/home/saksevul/T/PYTHIA/FastJet/ak5FJ.root");
  TFile *JetFile = new TFile("/home/saksevul/T/OpenData/Jet_20000/ak5PF.root");
  TFile *BTagFile = new TFile("/home/saksevul/T/OpenData/BTag_20000/ak5PF.root");
  TFile *MultiJetFile = new TFile("/home/saksevul/T/OpenData/MultiJet_20000/ak5PF.root");

  TH1F  *Muons__fX, *Muons__fY, *Muons__fZ,
        *MuonsJet_fX_, *MuonsJet_fY_, *MuonsJet_fZ_,
        *MuonsBTag_fX_, *MuonsBTag_fY_, *MuonsBTag_fZ_,
        *MuonsMultiJet_fX_, *MuonsMultiJet_fY_, *MuonsMultiJet_fZ_,
        *Electrons__fX, *Electrons__fY, *Electrons__fZ,
        *gsfElectronsJet_fX_, *gsfElectronsJet_fY_, *gsfElectronsJet_fZ_,
        *gsfElectronsBTag_fX_, *gsfElectronsBTag_fY_, *gsfElectronsBTag_fZ_,
        *gsfElectronsMultiJet_fX_, *gsfElectronsMultiJet_fY_, *gsfElectronsMultiJet_fZ_;

  Muons__fX =(TH1F*)FJFile->Get("Muons__fX"); Muons__fX->Scale(1.0/Muons__fX->Integral());
  MuonsJet_fX_ =(TH1F*)JetFile->Get("Muons_fX_"); MuonsJet_fX_->Scale(1.0/MuonsJet_fX_->Integral());
  MuonsBTag_fX_ =(TH1F*)BTagFile->Get("Muons_fX_"); MuonsBTag_fX_->Scale(1.0/MuonsBTag_fX_->Integral());
  MuonsMultiJet_fX_ =(TH1F*)MultiJetFile->Get("Muons_fX_"); MuonsMultiJet_fX_->Scale(1.0/MuonsMultiJet_fX_->Integral());
  Muons__fY =(TH1F*)FJFile->Get("Muons__fY"); Muons__fY->Scale(1.0/Muons__fY->Integral());
  MuonsJet_fY_ =(TH1F*)JetFile->Get("Muons_fY_"); MuonsJet_fY_->Scale(1.0/MuonsJet_fY_->Integral());
  MuonsBTag_fY_ =(TH1F*)BTagFile->Get("Muons_fY_"); MuonsBTag_fY_->Scale(1.0/MuonsBTag_fY_->Integral());
  MuonsMultiJet_fY_ =(TH1F*)MultiJetFile->Get("Muons_fY_"); MuonsMultiJet_fY_->Scale(1.0/MuonsMultiJet_fY_->Integral());
  Muons__fZ =(TH1F*)FJFile->Get("Muons__fZ"); Muons__fZ->Scale(1.0/Muons__fZ->Integral());
  MuonsJet_fZ_ =(TH1F*)JetFile->Get("Muons_fZ_"); MuonsJet_fZ_->Scale(1.0/MuonsJet_fZ_->Integral());
  MuonsBTag_fZ_ =(TH1F*)BTagFile->Get("Muons_fZ_"); MuonsBTag_fZ_->Scale(1.0/MuonsBTag_fZ_->Integral());
  MuonsMultiJet_fZ_ =(TH1F*)MultiJetFile->Get("Muons_fZ_"); MuonsMultiJet_fZ_->Scale(1.0/MuonsMultiJet_fZ_->Integral());

  Electrons__fX =(TH1F*)FJFile->Get("Electrons__fX"); Electrons__fX->Scale(1.0/Electrons__fX->Integral());
  gsfElectronsJet_fX_ =(TH1F*)JetFile->Get("gsfElectrons_fX_"); gsfElectronsJet_fX_->Scale(1.0/gsfElectronsJet_fX_->Integral());
  gsfElectronsBTag_fX_ =(TH1F*)BTagFile->Get("gsfElectrons_fX_"); gsfElectronsBTag_fX_->Scale(1.0/gsfElectronsBTag_fX_->Integral());
  gsfElectronsMultiJet_fX_ =(TH1F*)MultiJetFile->Get("gsfElectrons_fX_"); gsfElectronsMultiJet_fX_->Scale(1.0/gsfElectronsMultiJet_fX_->Integral());
  Electrons__fY =(TH1F*)FJFile->Get("Electrons__fY"); Electrons__fY->Scale(1.0/Electrons__fY->Integral());
  gsfElectronsJet_fY_ =(TH1F*)JetFile->Get("gsfElectrons_fY_"); gsfElectronsJet_fY_->Scale(1.0/gsfElectronsJet_fY_->Integral());
  gsfElectronsBTag_fY_ =(TH1F*)BTagFile->Get("gsfElectrons_fY_"); gsfElectronsBTag_fY_->Scale(1.0/gsfElectronsBTag_fY_->Integral());
  gsfElectronsMultiJet_fY_ =(TH1F*)MultiJetFile->Get("gsfElectrons_fY_"); gsfElectronsMultiJet_fY_->Scale(1.0/gsfElectronsMultiJet_fY_->Integral());
  Electrons__fZ =(TH1F*)FJFile->Get("Electrons__fZ"); Electrons__fZ->Scale(1.0/Electrons__fZ->Integral());
  gsfElectronsJet_fZ_ =(TH1F*)JetFile->Get("gsfElectrons_fZ_"); gsfElectronsJet_fZ_->Scale(1.0/gsfElectronsJet_fZ_->Integral());
  gsfElectronsBTag_fZ_ =(TH1F*)BTagFile->Get("gsfElectrons_fZ_"); gsfElectronsBTag_fZ_->Scale(1.0/gsfElectronsBTag_fZ_->Integral());
  gsfElectronsMultiJet_fZ_ =(TH1F*)MultiJetFile->Get("gsfElectrons_fZ_"); gsfElectronsMultiJet_fZ_->Scale(1.0/gsfElectronsMultiJet_fZ_->Integral());



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
    MuonsJet_fX_ -> Draw("E1same"); MuonsJet_fX_->SetLineColor(2);
    MuonsJet_fX_->SetMarkerStyle(23); MuonsJet_fX_->SetMarkerColor(2);
    MuonsBTag_fX_ -> Draw("E1same"); MuonsBTag_fX_->SetLineColor(9);
    MuonsBTag_fX_->SetMarkerStyle(22); MuonsBTag_fX_->SetMarkerColor(9);
    MuonsMultiJet_fX_ -> Draw("E1same"); MuonsMultiJet_fX_->SetLineColor(8);
    MuonsMultiJet_fX_->SetMarkerStyle(21); MuonsMultiJet_fX_->SetMarkerColor(8);
    legend -> Draw();


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
    MuonsJet_fY_ -> Draw("E1same"); MuonsJet_fY_->SetLineColor(2);
    MuonsJet_fY_->SetMarkerStyle(23); MuonsJet_fY_->SetMarkerColor(2);
    MuonsBTag_fY_ -> Draw("E1same"); MuonsBTag_fY_->SetLineColor(9);
    MuonsBTag_fY_->SetMarkerStyle(22); MuonsBTag_fY_->SetMarkerColor(9);
    MuonsMultiJet_fY_ -> Draw("E1same"); MuonsMultiJet_fY_->SetLineColor(8);
    MuonsMultiJet_fY_->SetMarkerStyle(21); MuonsMultiJet_fY_->SetMarkerColor(8);
    legend -> Draw();


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
    MuonsJet_fZ_ -> Draw("E1same"); MuonsJet_fZ_->SetLineColor(2);
    MuonsJet_fZ_->SetMarkerStyle(23); MuonsJet_fZ_->SetMarkerColor(2);
    MuonsBTag_fZ_ -> Draw("E1same"); MuonsBTag_fZ_->SetLineColor(9);
    MuonsBTag_fZ_->SetMarkerStyle(22); MuonsBTag_fZ_->SetMarkerColor(9);
    MuonsMultiJet_fZ_ -> Draw("E1same"); MuonsMultiJet_fZ_->SetLineColor(8);
    MuonsMultiJet_fZ_->SetMarkerStyle(21); MuonsMultiJet_fZ_->SetMarkerColor(8);
    legend -> Draw();


  fX_Muons -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/fX_Muones__FastJet-PFJets.png"); fX_Muons -> Close();
  fY_Muons -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/fY_Muones__FastJet-PFJets.png"); fY_Muons -> Close();
  fZ_Muons -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/fZ_Muones__FastJet-PFJets.png"); fZ_Muons -> Close();



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
    gsfElectronsJet_fX_ -> Draw("E1same"); gsfElectronsJet_fX_->SetLineColor(2);
    gsfElectronsJet_fX_->SetMarkerStyle(23); gsfElectronsJet_fX_->SetMarkerColor(2);
    gsfElectronsBTag_fX_ -> Draw("E1same"); gsfElectronsBTag_fX_->SetLineColor(9);
    gsfElectronsBTag_fX_->SetMarkerStyle(22); gsfElectronsBTag_fX_->SetMarkerColor(9);
    gsfElectronsMultiJet_fX_ -> Draw("E1same"); gsfElectronsMultiJet_fX_->SetLineColor(8);
    gsfElectronsMultiJet_fX_->SetMarkerStyle(21); gsfElectronsMultiJet_fX_->SetMarkerColor(8);
    legend -> Draw();


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
    gsfElectronsJet_fY_ -> Draw("E1same"); gsfElectronsJet_fY_->SetLineColor(2);
    gsfElectronsJet_fY_->SetMarkerStyle(23); gsfElectronsJet_fY_->SetMarkerColor(2);
    gsfElectronsBTag_fY_ -> Draw("E1same"); gsfElectronsBTag_fY_->SetLineColor(9);
    gsfElectronsBTag_fY_->SetMarkerStyle(22); gsfElectronsBTag_fY_->SetMarkerColor(9);
    gsfElectronsMultiJet_fY_ -> Draw("E1same"); gsfElectronsMultiJet_fY_->SetLineColor(8);
    gsfElectronsMultiJet_fY_->SetMarkerStyle(21); gsfElectronsMultiJet_fY_->SetMarkerColor(8);
    legend -> Draw();


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
    gsfElectronsJet_fZ_ -> Draw("E1same"); gsfElectronsJet_fZ_->SetLineColor(2);
    gsfElectronsJet_fZ_->SetMarkerStyle(23); gsfElectronsJet_fZ_->SetMarkerColor(2);
    gsfElectronsBTag_fZ_ -> Draw("E1same"); gsfElectronsBTag_fZ_->SetLineColor(9);
    gsfElectronsBTag_fZ_->SetMarkerStyle(22); gsfElectronsBTag_fZ_->SetMarkerColor(9);
    gsfElectronsMultiJet_fZ_ -> Draw("E1same"); gsfElectronsMultiJet_fZ_->SetLineColor(8);
    gsfElectronsMultiJet_fZ_->SetMarkerStyle(21); gsfElectronsMultiJet_fZ_->SetMarkerColor(8);
    legend -> Draw();

  fX_Electrons -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/fX_Electrones__FastJe-PFJets.png"); fX_Electrons -> Close();
  fY_Electrons -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/fY_Electrones__FastJe-PFJets.png"); fY_Electrons -> Close();
  fZ_Electrons -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/fZ_Electrones__FastJe-PFJets.png"); fZ_Electrons -> Close();
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
