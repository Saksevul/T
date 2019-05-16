void DistanciaAngular() {
  //Abrimos el archivo que nos interesa y el árbol que queremos leer.
  TFile *FastJetFile = new TFile("/home/saksevul/T/PYTHIA/FastJet/ak5FJ.SoftHard.root");
  TFile *JetFile = new TFile("/home/saksevul/T/OpenData/Jet_20000/ak5PF.Vertex.root");
  TFile *BTagFile = new TFile("/home/saksevul/T/OpenData/BTag_20000/ak5PF.Vertex.root");
  TFile *MultiJetFile = new TFile("/home/saksevul/T/OpenData/MultiJet_20000/ak5PF.Vertex.root");

  TH1F *D__Muon_ak5FastJet, *D__Electron_ak5FastJet, *ak5FastJet__D_Jet_Jet,
       *D__Muon_ak5PFJet, *D__gsfElectron_ak5PFJet, *ak5PFBTag__D_Jet_Jet;

  ak5FastJet__D_Jet_Jet =(TH1F*)FastJetFile->Get("ak5FastJet__D__Jet_Jet"); ak5PFBTag__D_Jet_Jet->Scale(1.0/ak5PFBTag__D_Jet_Jet->Integral());
  ak5PFBTag__D_Jet_Jet =(TH1F*)BTagFile->Get("ak5PFJets__D__Jet_Jet"); ak5PFBTag__D_Jet_Jet->Scale(1.0/ak5PFBTag__D_Jet_Jet->Integral());


    auto   legend = new TLegend(0.61,0.74,0.90,0.92);
      legend->SetTextSize(0.04);
      legend->AddEntry(ak5PFBTag__D_Jet_Jet, "Open-Data PFJets", "lp");
      legend->AddEntry(ak5FastJet__D_Jet_Jet, "MC FastJet", "lp");


  //Creamos un liezo en el cual dibujarémos los histogramas sin modificar.
  TCanvas* ak5PFJet__D_Jet_Jet = new TCanvas("DistanciaAngular","Distancia Angular de FastJet y PFJets por Evento",10,10,1920,1080);
  ak5PFJet__D_Jet_Jet->SetFillColor(0);  ak5PFJet__D_Jet_Jet->SetFrameBorderMode(0);  gPad->SetLogy();

  // Esto es para modificar las etiquetas del canvas.
  ak5PFBTag__D_Jet_Jet->SetTitle("Distancia Angular entre los Jets de cada Evento; Distancia Angular; Probabilidad");
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

//################################################################################################################

void Multiplicidad() {
  //Abrimos el archivo que nos interesa y el árbol que queremos leer.
  TFile *FastJetFile = new TFile("/home/saksevul/T/PYTHIA/FastJet/ak5FJ.SoftHard.root");
  TFile *JetFile = new TFile("/home/saksevul/T/OpenData/Jet_20000/ak5PF.Vertex.root");
  TFile *BTagFile = new TFile("/home/saksevul/T/OpenData/BTag_20000/ak5PF.Vertex.root");
  TFile *MultiJetFile = new TFile("/home/saksevul/T/OpenData/MultiJet_20000/ak5PF.Vertex.root");

  TH1F *ak5FastJet__Multiplicidad, *ak5PFJet__Multiplicidad, *ak5PFBTag__Multiplicidad, *ak5PFMultiJet__Multiplicidad;

  ak5FastJet__Multiplicidad =(TH1F*)FastJetFile->Get("ak5FastJet__Multiplicidad"); ak5FastJet__Multiplicidad->Scale(1.0/ak5FastJet__Multiplicidad->Integral());
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
    ak5FastJet__Multiplicidad->SetTitle("Multiplicidad de Jets por Evento; Numero de Jets; Probabilidad");
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

//################################################################################################################

void pT() {
  // Le damos algo de personalización al las gráficas.
  gROOT->ForceStyle();
  gStyle->SetPadBorderMode(0);    gStyle->SetPadBorderSize(0);
  gStyle->SetPadTopMargin(0.08);  gStyle->SetPadBottomMargin(0.12);
  gStyle->SetPadLeftMargin(0.10); gStyle->SetPadRightMargin(0.10);
  gStyle->SetOptStat(0);          gStyle->SetOptTitle(1);

  //Abrimos el archivo que nos interesa y el árbol que queremos leer.
  TFile *FastJetFile = new TFile("/home/saksevul/T/PYTHIA/FastJet/ak5FJ.SoftHard.root");
  TFile *JetFile = new TFile("/home/saksevul/T/OpenData/Jet_20000/ak5PF.Vertex.root");
  TFile *BTagFile = new TFile("/home/saksevul/T/OpenData/BTag_20000/ak5PF.Vertex.root");
  TFile *MultiJetFile = new TFile("/home/saksevul/T/OpenData/MultiJet_20000/ak5PF.Vertex.root");
  TFile *JetFileCx = new TFile("/home/saksevul/T/OpenData/Jet_20000/Coord-ak5PF.root");
  TFile *BTagFileCx = new TFile("/home/saksevul/T/OpenData/BTag_20000/Coord-ak5PF.root");
  TFile *MultiJetFileCx = new TFile("/home/saksevul/T/OpenData/MultiJet_20000/Coord-ak5PF.root");

  TH1F *Muons_pt_, *Electrons_pt_, *ak5FastJet__pT,
       *MuonsJet_pt_, *gsfElectronsJet_pt_, *ak5PFJet_pt_,    *MuonsJetCoord_pt_, *gsfElectronsJetCoord_pt_,
       *MuonsBTag_pt_, *gsfElectronsBTag_pt_, *ak5PFBTag_pt_,   *MuonsBTagCoord_pt_, *gsfElectronsBTagCoord_pt_,
       *MuonsMultiJet_pt_, *gsfElectronsMultiJet_pt_, *ak5PFMultiJet_pt_,   *MuonsMultiJetCoord_pt_, *gsfElectronsMultiJetCoord_pt_,
       *Cociente_pT__Electron_ak5FastJet, *Cociente_pT__Muon_ak5FastJet,
       *Cociente_pT__gsfElectron_ak5PFJet, *Cociente_pT__Muon_ak5PFJet,   *CocCoord_pT__gsfElectron_ak5PFJet, *CocCoord_pT__Muon_ak5PFJet,
       *Cociente_pT__gsfElectron_ak5PFBTag, *Cociente_pT__Muon_ak5PFBTag,   *CocCoord_pT__gsfElectron_ak5PFBTag, *CocCoord_pT__Muon_ak5PFBTag,
       *Cociente_pT__gsfElectron_ak5PFMultiJet, *Cociente_pT__Muon_ak5PFMultiJet,   *CocCoord_pT__gsfElectron_ak5PFMultiJet, *CocCoord_pT__Muon_ak5PFMultiJet,

       *Cociente_pT100__1Electron_ak5FastJet, *Cociente_pT100__1Muon_ak5FastJet,
       *Cociente_pT100__1gsfElectron_ak5PFJet, *Cociente_pT100__1Muon_ak5PFJet,
       *Cociente_pT100__1gsfElectron_ak5PFBTag, *Cociente_pT100__1Muon_ak5PFBTag,
       *Cociente_pT100__1gsfElectron_ak5PFMultiJet, *Cociente_pT100__1Muon_ak5PFMultiJet,

       *Cociente_100pT__1Electron_ak5FastJet, *Cociente_100pT__1Muon_ak5FastJet,
       *Cociente_100pT__1gsfElectron_ak5PFJet, *Cociente_100pT__1Muon_ak5PFJet,
       *Cociente_100pT__1gsfElectron_ak5PFBTag, *Cociente_100pT__1Muon_ak5PFBTag,
       *Cociente_100pT__1gsfElectron_ak5PFMultiJet, *Cociente_100pT__1Muon_ak5PFMultiJet;

  ak5FastJet__pT =(TH1F*)FastJetFile->Get("ak5FastJet__pT"); ak5FastJet__pT->Scale(1.0/ak5FastJet__pT->Integral());
  ak5PFJet_pt_ =(TH1F*)JetFile->Get("ak5PFJets_pt_"); ak5PFJet_pt_->Scale(1.0/ak5PFJet_pt_->Integral());
  ak5PFBTag_pt_ =(TH1F*)BTagFile->Get("ak5PFJets_pt_"); ak5PFBTag_pt_->Scale(1.0/ak5PFBTag_pt_->Integral());
  ak5PFMultiJet_pt_ =(TH1F*)MultiJetFile->Get("ak5PFJets_pt_"); ak5PFMultiJet_pt_->Scale(1.0/ak5PFMultiJet_pt_->Integral());

  Muons_pt_ =(TH1F*)FastJetFile->Get("Muons_pt_"); Muons_pt_->Scale(1.0/Muons_pt_->Integral());
  MuonsJet_pt_ =(TH1F*)JetFile->Get("Muons_pt_"); MuonsJet_pt_->Scale(1.0/MuonsJet_pt_->Integral());
  MuonsBTag_pt_ =(TH1F*)BTagFile->Get("Muons_pt_"); MuonsBTag_pt_->Scale(1.0/MuonsBTag_pt_->Integral());
  MuonsMultiJet_pt_ =(TH1F*)MultiJetFile->Get("Muons_pt_"); MuonsMultiJet_pt_->Scale(1.0/MuonsMultiJet_pt_->Integral());

  Electrons_pt_ =(TH1F*)FastJetFile->Get("Electrons_pt_"); Electrons_pt_->Scale(1.0/Electrons_pt_->Integral());
  gsfElectronsJet_pt_ =(TH1F*)JetFile->Get("gsfElectrons_pt_"); gsfElectronsJet_pt_->Scale(1.0/gsfElectronsJet_pt_->Integral());
  gsfElectronsBTag_pt_ =(TH1F*)BTagFile->Get("gsfElectrons_pt_"); gsfElectronsBTag_pt_->Scale(1.0/gsfElectronsBTag_pt_->Integral());
  gsfElectronsMultiJet_pt_ =(TH1F*)MultiJetFile->Get("gsfElectrons_pt_"); gsfElectronsMultiJet_pt_->Scale(1.0/gsfElectronsMultiJet_pt_->Integral());

  Cociente_pT__Electron_ak5FastJet =(TH1F*)FastJetFile->Get("Cociente_pT__Electron-ak5FastJet");  Cociente_pT__Electron_ak5FastJet->Scale(1.0/Cociente_pT__Electron_ak5FastJet->Integral());
  Cociente_pT__gsfElectron_ak5PFJet =(TH1F*)JetFile->Get("Cociente_pT__gsfElectron-ak5PFJet");   Cociente_pT__gsfElectron_ak5PFJet->Scale(1.0/Cociente_pT__gsfElectron_ak5PFJet->Integral());
  Cociente_pT__gsfElectron_ak5PFBTag =(TH1F*)BTagFile->Get("Cociente_pT__gsfElectron-ak5PFJet");   Cociente_pT__gsfElectron_ak5PFBTag->Scale(1.0/Cociente_pT__gsfElectron_ak5PFBTag->Integral());
  Cociente_pT__gsfElectron_ak5PFMultiJet =(TH1F*)MultiJetFile->Get("Cociente_pT__gsfElectron-ak5PFJet");   Cociente_pT__gsfElectron_ak5PFMultiJet->Scale(1.0/Cociente_pT__gsfElectron_ak5PFMultiJet->Integral());

    CocCoord_pT__gsfElectron_ak5PFJet =(TH1F*)JetFileCx->Get("Cociente_pT__gsfElectron-ak5PFJet");   CocCoord_pT__gsfElectron_ak5PFJet->Scale(1.0/CocCoord_pT__gsfElectron_ak5PFJet->Integral());
    CocCoord_pT__gsfElectron_ak5PFBTag =(TH1F*)BTagFileCx->Get("Cociente_pT__gsfElectron-ak5PFJet");   CocCoord_pT__gsfElectron_ak5PFBTag->Scale(1.0/CocCoord_pT__gsfElectron_ak5PFBTag->Integral());
    CocCoord_pT__gsfElectron_ak5PFMultiJet =(TH1F*)MultiJetFileCx->Get("Cociente_pT__gsfElectron-ak5PFJet");   CocCoord_pT__gsfElectron_ak5PFMultiJet->Scale(1.0/CocCoord_pT__gsfElectron_ak5PFMultiJet->Integral());

  Cociente_pT100__1Electron_ak5FastJet =(TH1F*)FastJetFile->Get("Cociente_pT<100__1Electron-ak5FastJet");  Cociente_pT100__1Electron_ak5FastJet->Scale(1.0/Cociente_pT100__1Electron_ak5FastJet->Integral());
  Cociente_pT100__1gsfElectron_ak5PFJet =(TH1F*)JetFile->Get("Cociente_pT<100__1gsfElectron-ak5PFJet");   Cociente_pT100__1gsfElectron_ak5PFJet->Scale(1.0/Cociente_pT100__1gsfElectron_ak5PFJet->Integral());
  Cociente_pT100__1gsfElectron_ak5PFBTag =(TH1F*)BTagFile->Get("Cociente_pT<100__1gsfElectron-ak5PFJet");   Cociente_pT100__1gsfElectron_ak5PFBTag->Scale(1.0/Cociente_pT100__1gsfElectron_ak5PFBTag->Integral());
  Cociente_pT100__1gsfElectron_ak5PFMultiJet =(TH1F*)MultiJetFile->Get("Cociente_pT<100__1gsfElectron-ak5PFJet");   Cociente_pT100__1gsfElectron_ak5PFMultiJet->Scale(1.0/Cociente_pT100__1gsfElectron_ak5PFMultiJet->Integral());

  Cociente_100pT__1Electron_ak5FastJet =(TH1F*)FastJetFile->Get("Cociente_pT>100__1Electron-ak5FastJet");  Cociente_100pT__1Electron_ak5FastJet->Scale(1.0/Cociente_100pT__1Electron_ak5FastJet->Integral());
  Cociente_100pT__1gsfElectron_ak5PFJet =(TH1F*)JetFile->Get("Cociente_pT>100__1gsfElectron-ak5PFJet");   Cociente_100pT__1gsfElectron_ak5PFJet->Scale(1.0/Cociente_100pT__1gsfElectron_ak5PFJet->Integral());
  Cociente_100pT__1gsfElectron_ak5PFBTag =(TH1F*)BTagFile->Get("Cociente_pT>100__1gsfElectron-ak5PFJet");   Cociente_100pT__1gsfElectron_ak5PFBTag->Scale(1.0/Cociente_100pT__1gsfElectron_ak5PFBTag->Integral());
  Cociente_100pT__1gsfElectron_ak5PFMultiJet =(TH1F*)MultiJetFile->Get("Cociente_pT>100__1gsfElectron-ak5PFJet");   Cociente_100pT__1gsfElectron_ak5PFMultiJet->Scale(1.0/Cociente_100pT__1gsfElectron_ak5PFMultiJet->Integral());

  Cociente_pT__Muon_ak5FastJet =(TH1F*)FastJetFile->Get("Cociente_pT__Muon-ak5FastJet"); Cociente_pT__Muon_ak5FastJet->Scale(1.0/Cociente_pT__Muon_ak5FastJet->Integral());
  Cociente_pT__Muon_ak5PFJet =(TH1F*)JetFile->Get("Cociente_pT__Muon-ak5PFJet"); Cociente_pT__Muon_ak5PFJet->Scale(1.0/Cociente_pT__Muon_ak5PFJet->Integral());
  Cociente_pT__Muon_ak5PFBTag =(TH1F*)BTagFile->Get("Cociente_pT__Muon-ak5PFJet"); Cociente_pT__Muon_ak5PFBTag->Scale(1.0/Cociente_pT__Muon_ak5PFBTag->Integral());
  Cociente_pT__Muon_ak5PFMultiJet =(TH1F*)MultiJetFile->Get("Cociente_pT__Muon-ak5PFJet"); Cociente_pT__Muon_ak5PFMultiJet->Scale(1.0/Cociente_pT__Muon_ak5PFMultiJet->Integral());

    CocCoord_pT__Muon_ak5PFJet =(TH1F*)JetFileCx->Get("Cociente_pT__Muon-ak5PFJet"); CocCoord_pT__Muon_ak5PFJet->Scale(1.0/CocCoord_pT__Muon_ak5PFJet->Integral());
    CocCoord_pT__Muon_ak5PFBTag =(TH1F*)BTagFileCx->Get("Cociente_pT__Muon-ak5PFJet"); CocCoord_pT__Muon_ak5PFBTag->Scale(1.0/CocCoord_pT__Muon_ak5PFBTag->Integral());
    CocCoord_pT__Muon_ak5PFMultiJet =(TH1F*)MultiJetFileCx->Get("Cociente_pT__Muon-ak5PFJet"); CocCoord_pT__Muon_ak5PFMultiJet->Scale(1.0/CocCoord_pT__Muon_ak5PFMultiJet->Integral());

  Cociente_pT100__1Muon_ak5FastJet =(TH1F*)FastJetFile->Get("Cociente_pT<100__1Muon-ak5FastJet");  Cociente_pT100__1Muon_ak5FastJet->Scale(1.0/Cociente_pT100__1Muon_ak5FastJet->Integral());
  Cociente_pT100__1Muon_ak5PFJet =(TH1F*)JetFile->Get("Cociente_pT<100__1Muon-ak5PFJet");   Cociente_pT100__1Muon_ak5PFJet->Scale(1.0/Cociente_pT100__1Muon_ak5PFJet->Integral());
  Cociente_pT100__1Muon_ak5PFBTag =(TH1F*)BTagFile->Get("Cociente_pT<100__1Muon-ak5PFJet");   Cociente_pT100__1Muon_ak5PFBTag->Scale(1.0/Cociente_pT100__1Muon_ak5PFBTag->Integral());
  Cociente_pT100__1Muon_ak5PFMultiJet =(TH1F*)MultiJetFile->Get("Cociente_pT<100__1Muon-ak5PFJet");   Cociente_pT100__1Muon_ak5PFMultiJet->Scale(1.0/Cociente_pT100__1Muon_ak5PFMultiJet->Integral());

  Cociente_100pT__1Muon_ak5FastJet =(TH1F*)FastJetFile->Get("Cociente_pT>100__1Muon-ak5FastJet");  Cociente_100pT__1Muon_ak5FastJet->Scale(1.0/Cociente_100pT__1Muon_ak5FastJet->Integral());
  Cociente_100pT__1Muon_ak5PFJet =(TH1F*)JetFile->Get("Cociente_pT>100__1Muon-ak5PFJet");   Cociente_100pT__1Muon_ak5PFJet->Scale(1.0/Cociente_100pT__1Muon_ak5PFJet->Integral());
  Cociente_100pT__1Muon_ak5PFBTag =(TH1F*)BTagFile->Get("Cociente_pT>100__1Muon-ak5PFJet");   Cociente_100pT__1Muon_ak5PFBTag->Scale(1.0/Cociente_100pT__1Muon_ak5PFBTag->Integral());
  Cociente_100pT__1Muon_ak5PFMultiJet =(TH1F*)MultiJetFile->Get("Cociente_pT>100__1Muon-ak5PFJet");   Cociente_100pT__1Muon_ak5PFMultiJet->Scale(1.0/Cociente_100pT__1Muon_ak5PFMultiJet->Integral());


  auto   legend = new TLegend(0.61,0.74,0.90,0.92);    legend->SetTextSize(0.04);
    legend->AddEntry(ak5FastJet__pT, "MC FastJet", "lp");
    legend->AddEntry(ak5PFJet_pt_, "Open-Data PF Jet", "lp");
    legend->AddEntry(ak5PFBTag_pt_, "Open-Data PF BTag", "lp");
    legend->AddEntry(ak5PFMultiJet_pt_, "Open-Data PF MultiJet", "lp");


  TCanvas* Espectro_pT__Jets = new TCanvas("pT Jets","Espectro de pT de FastJet y PFJets",10,10,1920,1080);
  Espectro_pT__Jets->SetFillColor(0);  Espectro_pT__Jets->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  ak5FastJet__pT->SetTitle("Espectro de p_{T} de Jets; p_{T} [GeV]; Probabilidad");
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
  legend -> Draw();


  TCanvas* Espectro_pT__Muons = new TCanvas("pT Muones","Espectro de pT de Muones y Muons",10,10,1920,1080);
  Espectro_pT__Muons->SetFillColor(0);  Espectro_pT__Muons->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  Muons_pt_->SetTitle("Espectro de p_{T} de Muones; p_{T} [GeV]; Probabilidad");
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
  legend -> Draw();


  TCanvas* Espectro_pT__Electrons = new TCanvas("pT Electrones","Espectro de pT de Electrones y gsfElectrones",10,10,1920,1080);
  Espectro_pT__Electrons->SetFillColor(0);  Espectro_pT__Electrons->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  Electrons_pt_->SetTitle("Espectro de p_{T} de Electrones; p_{T} [GeV]; Probabilidad");
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
  legend -> Draw();


  Espectro_pT__Jets -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/pT__FastJet_PFJets.png"); Espectro_pT__Jets -> Close();
  Espectro_pT__Muons -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/pT__Muons.png"); Espectro_pT__Muons -> Close();
  Espectro_pT__Electrons -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/pT__Electrons.png"); Espectro_pT__Electrons -> Close();



  TCanvas* Cociente_pT__Electron_Jet = new TCanvas("Cociente_pT__Electron_Jet","Cociente pT FastJet y PFJets para electrones",10,10,1920,1080);
  Cociente_pT__Electron_Jet->SetFillColor(0);  Cociente_pT__Electron_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  Cociente_pT__Electron_ak5FastJet->SetTitle("Cociente p_{T} para electrones; p_{T}^{Electron} / p_{T}^{Jet}; U. A.");
  Cociente_pT__Electron_ak5FastJet->GetXaxis()->SetLabelSize(0.05); Cociente_pT__Electron_ak5FastJet->GetYaxis()->SetLabelSize(0.05);
  Cociente_pT__Electron_ak5FastJet->GetXaxis()->SetTitleSize(0.05); Cociente_pT__Electron_ak5FastJet->GetYaxis()->SetTitleSize(0.05);
  Cociente_pT__Electron_ak5FastJet->GetXaxis()->SetTitleOffset(1.0);Cociente_pT__Electron_ak5FastJet->GetYaxis()->SetTitleOffset(1.0);
  // Cociente_pT__Electron_ak5FastJet->SetAxisRange(0.0, 1.2, "X");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Cociente_pT__Electron_ak5FastJet -> Draw("E1"); Cociente_pT__Electron_ak5FastJet->SetLineColor(1); Cociente_pT__Electron_ak5FastJet->SetLineWidth(2);
  Cociente_pT__Electron_ak5FastJet->SetMarkerStyle(20); Cociente_pT__Electron_ak5FastJet->SetMarkerColor(1); Cociente_pT__Electron_ak5FastJet->SetMarkerSize(2);
  Cociente_pT__gsfElectron_ak5PFJet -> Draw("E1same"); Cociente_pT__gsfElectron_ak5PFJet->SetLineColor(2); Cociente_pT__gsfElectron_ak5PFJet->SetLineWidth(2);
  Cociente_pT__gsfElectron_ak5PFJet->SetMarkerStyle(23); Cociente_pT__gsfElectron_ak5PFJet->SetMarkerColor(2); Cociente_pT__gsfElectron_ak5PFJet->SetMarkerSize(2);
  Cociente_pT__gsfElectron_ak5PFBTag -> Draw("E1same"); Cociente_pT__gsfElectron_ak5PFBTag->SetLineColor(4); Cociente_pT__gsfElectron_ak5PFBTag->SetLineWidth(2);
  Cociente_pT__gsfElectron_ak5PFBTag->SetMarkerStyle(22); Cociente_pT__gsfElectron_ak5PFBTag->SetMarkerColor(4); Cociente_pT__gsfElectron_ak5PFBTag->SetMarkerSize(2);
  Cociente_pT__gsfElectron_ak5PFMultiJet -> Draw("E1same"); Cociente_pT__gsfElectron_ak5PFMultiJet->SetLineColor(8); Cociente_pT__gsfElectron_ak5PFMultiJet->SetLineWidth(2);
  Cociente_pT__gsfElectron_ak5PFMultiJet->SetMarkerStyle(34); Cociente_pT__gsfElectron_ak5PFMultiJet->SetMarkerColor(8); Cociente_pT__gsfElectron_ak5PFMultiJet->SetMarkerSize(2);
  legend -> Draw();


  TCanvas* Cociente_pT100__1Electron_Jet = new TCanvas("Cociente_pT100__1Electron_Jet","Cociente pT<100 FastJet y PFJets para electrones",10,10,1920,1080);
  Cociente_pT100__1Electron_Jet->SetFillColor(0);  Cociente_pT100__1Electron_Jet->SetFrameBorderMode(0);  gPad->SetLogy();

  // Esto es para modificar las etiquetas del canvas.
  Cociente_pT100__1Electron_ak5FastJet->SetTitle("Cociente p_{T} para el electrones m#acute{a}s energ#acute{e}tico en cada Jet (p_{T}^{Jet} < 100); p_{T}^{Electron} / p_{T}^{Jet}; U. A.");
  Cociente_pT100__1Electron_ak5FastJet->GetXaxis()->SetLabelSize(0.05); Cociente_pT100__1Electron_ak5FastJet->GetYaxis()->SetLabelSize(0.05);
  Cociente_pT100__1Electron_ak5FastJet->GetXaxis()->SetTitleSize(0.05); Cociente_pT100__1Electron_ak5FastJet->GetYaxis()->SetTitleSize(0.05);
  Cociente_pT100__1Electron_ak5FastJet->GetXaxis()->SetTitleOffset(1.0);Cociente_pT100__1Electron_ak5FastJet->GetYaxis()->SetTitleOffset(1.0);
  // Cociente_pT100__1Electron_ak5FastJet->SetAxisRange(0.0, 1.2, "X");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Cociente_pT100__1Electron_ak5FastJet -> Draw("E1"); Cociente_pT100__1Electron_ak5FastJet->SetLineColor(1); Cociente_pT100__1Electron_ak5FastJet->SetLineWidth(2);
  Cociente_pT100__1Electron_ak5FastJet->SetMarkerStyle(20); Cociente_pT100__1Electron_ak5FastJet->SetMarkerColor(1); Cociente_pT100__1Electron_ak5FastJet->SetMarkerSize(2);
  Cociente_pT100__1gsfElectron_ak5PFJet -> Draw("E1same"); Cociente_pT100__1gsfElectron_ak5PFJet->SetLineColor(2); Cociente_pT100__1gsfElectron_ak5PFJet->SetLineWidth(2);
  Cociente_pT100__1gsfElectron_ak5PFJet->SetMarkerStyle(23); Cociente_pT100__1gsfElectron_ak5PFJet->SetMarkerColor(2); Cociente_pT100__1gsfElectron_ak5PFJet->SetMarkerSize(2);
  Cociente_pT100__1gsfElectron_ak5PFBTag -> Draw("E1same"); Cociente_pT100__1gsfElectron_ak5PFBTag->SetLineColor(9); Cociente_pT100__1gsfElectron_ak5PFBTag->SetLineWidth(2);
  Cociente_pT100__1gsfElectron_ak5PFBTag->SetMarkerStyle(22); Cociente_pT100__1gsfElectron_ak5PFBTag->SetMarkerColor(9); Cociente_pT100__1gsfElectron_ak5PFBTag->SetMarkerSize(2);
  Cociente_pT100__1gsfElectron_ak5PFMultiJet -> Draw("E1same"); Cociente_pT100__1gsfElectron_ak5PFMultiJet->SetLineColor(8); Cociente_pT100__1gsfElectron_ak5PFMultiJet->SetLineWidth(2);
  Cociente_pT100__1gsfElectron_ak5PFMultiJet->SetMarkerStyle(34); Cociente_pT100__1gsfElectron_ak5PFMultiJet->SetMarkerColor(8); Cociente_pT100__1gsfElectron_ak5PFMultiJet->SetMarkerSize(2);
  legend -> Draw();


  TCanvas* Cociente_100pT__1Electron_Jet = new TCanvas("Cociente_100pT__1Electron_Jet","Cociente pT>100 FastJet y PFJets para electrones",10,10,1920,1080);
  Cociente_100pT__1Electron_Jet->SetFillColor(0);  Cociente_100pT__1Electron_Jet->SetFrameBorderMode(0);  gPad->SetLogy();

  // Esto es para modificar las etiquetas del canvas.
  Cociente_100pT__1Electron_ak5FastJet->SetTitle("Cociente p_{T} para el electron m#acute{a}s energ#acute{e}tico en cada Jet (p_{T}^{Jet} > 100); p_{T}^{Electron} / p_{T}^{Jet}; U. A.");
  Cociente_100pT__1Electron_ak5FastJet->GetXaxis()->SetLabelSize(0.05); Cociente_100pT__1Electron_ak5FastJet->GetYaxis()->SetLabelSize(0.05);
  Cociente_100pT__1Electron_ak5FastJet->GetXaxis()->SetTitleSize(0.05); Cociente_100pT__1Electron_ak5FastJet->GetYaxis()->SetTitleSize(0.05);
  Cociente_100pT__1Electron_ak5FastJet->GetXaxis()->SetTitleOffset(1.0);Cociente_100pT__1Electron_ak5FastJet->GetYaxis()->SetTitleOffset(1.0);
  // Cociente_100pT__1Electron_ak5FastJet->SetAxisRange(0.0, 1.2, "X");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Cociente_100pT__1Electron_ak5FastJet -> Draw("E1"); Cociente_100pT__1Electron_ak5FastJet->SetLineColor(1); Cociente_100pT__1Electron_ak5FastJet->SetLineWidth(2);
  Cociente_100pT__1Electron_ak5FastJet->SetMarkerStyle(20); Cociente_100pT__1Electron_ak5FastJet->SetMarkerColor(1); Cociente_100pT__1Electron_ak5FastJet->SetMarkerSize(2);
  Cociente_100pT__1gsfElectron_ak5PFJet -> Draw("E1same"); Cociente_100pT__1gsfElectron_ak5PFJet->SetLineColor(2); Cociente_100pT__1gsfElectron_ak5PFJet->SetLineWidth(2);
  Cociente_100pT__1gsfElectron_ak5PFJet->SetMarkerStyle(23); Cociente_100pT__1gsfElectron_ak5PFJet->SetMarkerColor(2); Cociente_100pT__1gsfElectron_ak5PFJet->SetMarkerSize(2);
  Cociente_100pT__1gsfElectron_ak5PFBTag -> Draw("E1same"); Cociente_100pT__1gsfElectron_ak5PFBTag->SetLineColor(9); Cociente_100pT__1gsfElectron_ak5PFBTag->SetLineWidth(2);
  Cociente_100pT__1gsfElectron_ak5PFBTag->SetMarkerStyle(22); Cociente_100pT__1gsfElectron_ak5PFBTag->SetMarkerColor(9); Cociente_100pT__1gsfElectron_ak5PFBTag->SetMarkerSize(2);
  Cociente_100pT__1gsfElectron_ak5PFMultiJet -> Draw("E1same"); Cociente_100pT__1gsfElectron_ak5PFMultiJet->SetLineColor(8); Cociente_100pT__1gsfElectron_ak5PFMultiJet->SetLineWidth(2);
  Cociente_100pT__1gsfElectron_ak5PFMultiJet->SetMarkerStyle(34); Cociente_100pT__1gsfElectron_ak5PFMultiJet->SetMarkerColor(8); Cociente_100pT__1gsfElectron_ak5PFMultiJet->SetMarkerSize(2);
  legend -> Draw();



  TCanvas* Cociente_pT__Muon_Jet = new TCanvas("Cociente_pT__Muon_Jet","Cociente pT FastJet y PFJets para muones",10,10,1920,1080);
  Cociente_pT__Muon_Jet->SetFillColor(0);  Cociente_pT__Muon_Jet->SetFrameBorderMode(0);  gPad->SetLogy();

  // Esto es para modificar las etiquetas del canvas.
  Cociente_pT__Muon_ak5FastJet->SetTitle("Cociente p_{T} para muones; p_{T}^{Muon} / p_{T}^{Jet}; U. A.");
  Cociente_pT__Muon_ak5FastJet->GetXaxis()->SetLabelSize(0.05); Cociente_pT__Muon_ak5FastJet->GetYaxis()->SetLabelSize(0.05);
  Cociente_pT__Muon_ak5FastJet->GetXaxis()->SetTitleSize(0.05); Cociente_pT__Muon_ak5FastJet->GetYaxis()->SetTitleSize(0.05);
  Cociente_pT__Muon_ak5FastJet->GetXaxis()->SetTitleOffset(1.0);Cociente_pT__Muon_ak5FastJet->GetYaxis()->SetTitleOffset(1.0);
  Cociente_pT__Muon_ak5FastJet->SetAxisRange(0.0, 1.2, "X");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Cociente_pT__Muon_ak5FastJet -> Draw("E1"); Cociente_pT__Muon_ak5FastJet->SetLineColor(1); Cociente_pT__Muon_ak5FastJet->SetLineWidth(2);
  Cociente_pT__Muon_ak5FastJet->SetMarkerStyle(20); Cociente_pT__Muon_ak5FastJet->SetMarkerColor(1); Cociente_pT__Muon_ak5FastJet->SetMarkerSize(2);
  Cociente_pT__Muon_ak5PFJet -> Draw("E1same"); Cociente_pT__Muon_ak5PFJet->SetLineColor(2); Cociente_pT__Muon_ak5PFJet->SetLineWidth(2);
  Cociente_pT__Muon_ak5PFJet->SetMarkerStyle(23); Cociente_pT__Muon_ak5PFJet->SetMarkerColor(2); Cociente_pT__Muon_ak5PFJet->SetMarkerSize(2);
  Cociente_pT__Muon_ak5PFBTag -> Draw("E1same"); Cociente_pT__Muon_ak5PFBTag->SetLineColor(4); Cociente_pT__Muon_ak5PFBTag->SetLineWidth(2);
  Cociente_pT__Muon_ak5PFBTag->SetMarkerStyle(22); Cociente_pT__Muon_ak5PFBTag->SetMarkerColor(4); Cociente_pT__Muon_ak5PFBTag->SetMarkerSize(2);
  Cociente_pT__Muon_ak5PFMultiJet -> Draw("E1same"); Cociente_pT__Muon_ak5PFMultiJet->SetLineColor(8); Cociente_pT__Muon_ak5PFMultiJet->SetLineWidth(2);
  Cociente_pT__Muon_ak5PFMultiJet->SetMarkerStyle(34); Cociente_pT__Muon_ak5PFMultiJet->SetMarkerColor(8); Cociente_pT__Muon_ak5PFMultiJet->SetMarkerSize(2);
  legend -> Draw();


  TCanvas* Cociente_pT100__1Muon_Jet = new TCanvas("Cociente_pT100__1Muon_Jet","Cociente pT<100 FastJet y PFJets para muones",10,10,1920,1080);
  Cociente_pT100__1Muon_Jet->SetFillColor(0);  Cociente_pT100__1Muon_Jet->SetFrameBorderMode(0);  gPad->SetLogy();

  // Esto es para modificar las etiquetas del canvas.
  Cociente_pT100__1Muon_ak5FastJet->SetTitle("Cociente p_{T} para el mu#acute{o}n m#acute{a}s energ#acute{e}tico en cada Jet (p_{T}^{Jet} < 100); p_{T}^{Muon} / p_{T}^{Jet}; U. A.");
  Cociente_pT100__1Muon_ak5FastJet->GetXaxis()->SetLabelSize(0.05); Cociente_pT100__1Muon_ak5FastJet->GetYaxis()->SetLabelSize(0.05);
  Cociente_pT100__1Muon_ak5FastJet->GetXaxis()->SetTitleSize(0.05); Cociente_pT100__1Muon_ak5FastJet->GetYaxis()->SetTitleSize(0.05);
  Cociente_pT100__1Muon_ak5FastJet->GetXaxis()->SetTitleOffset(1.0);Cociente_pT100__1Muon_ak5FastJet->GetYaxis()->SetTitleOffset(1.0);
  Cociente_pT100__1Muon_ak5FastJet->SetAxisRange(0.0, 1.2, "X");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Cociente_pT100__1Muon_ak5FastJet -> Draw("E1"); Cociente_pT100__1Muon_ak5FastJet->SetLineColor(1); Cociente_pT100__1Muon_ak5FastJet->SetLineWidth(2);
  Cociente_pT100__1Muon_ak5FastJet->SetMarkerStyle(20); Cociente_pT100__1Muon_ak5FastJet->SetMarkerColor(1); Cociente_pT100__1Muon_ak5FastJet->SetMarkerSize(2);
  Cociente_pT100__1Muon_ak5PFJet -> Draw("E1same"); Cociente_pT100__1Muon_ak5PFJet->SetLineColor(2); Cociente_pT100__1Muon_ak5PFJet->SetLineWidth(2);
  Cociente_pT100__1Muon_ak5PFJet->SetMarkerStyle(23); Cociente_pT100__1Muon_ak5PFJet->SetMarkerColor(2); Cociente_pT100__1Muon_ak5PFJet->SetMarkerSize(2);
  Cociente_pT100__1Muon_ak5PFBTag -> Draw("E1same"); Cociente_pT100__1Muon_ak5PFBTag->SetLineColor(9); Cociente_pT100__1Muon_ak5PFBTag->SetLineWidth(2);
  Cociente_pT100__1Muon_ak5PFBTag->SetMarkerStyle(22); Cociente_pT100__1Muon_ak5PFBTag->SetMarkerColor(9); Cociente_pT100__1Muon_ak5PFBTag->SetMarkerSize(2);
  Cociente_pT100__1Muon_ak5PFMultiJet -> Draw("E1same"); Cociente_pT100__1Muon_ak5PFMultiJet->SetLineColor(8); Cociente_pT100__1Muon_ak5PFMultiJet->SetLineWidth(2);
  Cociente_pT100__1Muon_ak5PFMultiJet->SetMarkerStyle(34); Cociente_pT100__1Muon_ak5PFMultiJet->SetMarkerColor(8); Cociente_pT100__1Muon_ak5PFMultiJet->SetMarkerSize(2);
  legend -> Draw();


  TCanvas* Cociente_100pT__1Muon_Jet = new TCanvas("Cociente_100pT__1Muon_Jet","Cociente pT>100 FastJet y PFJets para muones",10,10,1920,1080);
  Cociente_100pT__1Muon_Jet->SetFillColor(0);  Cociente_100pT__1Muon_Jet->SetFrameBorderMode(0);  gPad->SetLogy();

  // Esto es para modificar las etiquetas del canvas.
  Cociente_100pT__1Muon_ak5FastJet->SetTitle("Cociente p_{T} para el mu#acute{o}n m#acute{a}s energ#acute{e}tico en cada Jet (p_{T}^{Jet} > 100); p_{T}^{Muon} / p_{T}^{Jet}; U. A.");
  Cociente_100pT__1Muon_ak5FastJet->GetXaxis()->SetLabelSize(0.05); Cociente_100pT__1Muon_ak5FastJet->GetYaxis()->SetLabelSize(0.05);
  Cociente_100pT__1Muon_ak5FastJet->GetXaxis()->SetTitleSize(0.05); Cociente_100pT__1Muon_ak5FastJet->GetYaxis()->SetTitleSize(0.05);
  Cociente_100pT__1Muon_ak5FastJet->GetXaxis()->SetTitleOffset(1.0);Cociente_100pT__1Muon_ak5FastJet->GetYaxis()->SetTitleOffset(1.0);
  Cociente_100pT__1Muon_ak5FastJet->SetAxisRange(0.0, 1.2, "X");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Cociente_100pT__1Muon_ak5FastJet -> Draw("E1"); Cociente_100pT__1Muon_ak5FastJet->SetLineColor(1); Cociente_100pT__1Muon_ak5FastJet->SetLineWidth(2);
  Cociente_100pT__1Muon_ak5FastJet->SetMarkerStyle(20); Cociente_100pT__1Muon_ak5FastJet->SetMarkerColor(1); Cociente_100pT__1Muon_ak5FastJet->SetMarkerSize(2);
  Cociente_100pT__1Muon_ak5PFJet -> Draw("E1same"); Cociente_100pT__1Muon_ak5PFJet->SetLineColor(2); Cociente_100pT__1Muon_ak5PFJet->SetLineWidth(2);
  Cociente_100pT__1Muon_ak5PFJet->SetMarkerStyle(23); Cociente_100pT__1Muon_ak5PFJet->SetMarkerColor(2); Cociente_100pT__1Muon_ak5PFJet->SetMarkerSize(2);
  Cociente_100pT__1Muon_ak5PFBTag -> Draw("E1same"); Cociente_100pT__1Muon_ak5PFBTag->SetLineColor(9); Cociente_100pT__1Muon_ak5PFBTag->SetLineWidth(2);
  Cociente_100pT__1Muon_ak5PFBTag->SetMarkerStyle(22); Cociente_100pT__1Muon_ak5PFBTag->SetMarkerColor(9); Cociente_100pT__1Muon_ak5PFBTag->SetMarkerSize(2);
  Cociente_100pT__1Muon_ak5PFMultiJet -> Draw("E1same"); Cociente_100pT__1Muon_ak5PFMultiJet->SetLineColor(8); Cociente_100pT__1Muon_ak5PFMultiJet->SetLineWidth(2);
  Cociente_100pT__1Muon_ak5PFMultiJet->SetMarkerStyle(34); Cociente_100pT__1Muon_ak5PFMultiJet->SetMarkerColor(8); Cociente_100pT__1Muon_ak5PFMultiJet->SetMarkerSize(2);
  legend -> Draw();



  Cociente_pT__Electron_Jet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT__Electron_Jet.png"); Cociente_pT__Electron_Jet -> Close();
  Cociente_pT100__1Electron_Jet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT<100__1Electron_Jet.png"); Cociente_pT100__1Electron_Jet -> Close();
  Cociente_100pT__1Electron_Jet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT>100__1Electron_Jet.png"); Cociente_100pT__1Electron_Jet -> Close();
  Cociente_pT__Muon_Jet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT__Muon_Jet.png"); Cociente_pT__Muon_Jet -> Close();
  Cociente_pT100__1Muon_Jet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT<100__1Muon_Jet.png"); Cociente_pT100__1Muon_Jet -> Close();
  Cociente_100pT__1Muon_Jet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT>100__1Muon_Jet.png"); Cociente_100pT__1Muon_Jet -> Close();



  // Comparacion entre las distribuciones de Cocientes, utilizando como criterio distintos vertices.

  auto   legen = new TLegend(0.61,0.83,0.90,0.92);    legen->SetTextSize(0.04);
    legen->AddEntry(Cociente_pT__Muon_ak5FastJet, "Simulacion.", "lp");
    legen->AddEntry(CocCoord_pT__Muon_ak5PFJet, "fCoordinates", "lp");
    legen->AddEntry(Cociente_pT__Muon_ak5PFJet, "pfP4 fCoordinates", "lp");


  TCanvas* CocCoord_pT__Muon_Jet = new TCanvas("CocCoord_pT__Muon_Jet","Cociente pT FastJet y PFJets para muones en AOD's Jet",10,10,1920,1080);
  CocCoord_pT__Muon_Jet->SetFillColor(0);  CocCoord_pT__Muon_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  Cociente_pT__Muon_ak5FastJet->SetTitle("Cociente p_{T} para muones en AOD's Jet; p_{T}^{Muon} / p_{T}^{Jet}; U. A.");
  Cociente_pT__Muon_ak5FastJet->GetXaxis()->SetLabelSize(0.05); Cociente_pT__Muon_ak5FastJet->GetYaxis()->SetLabelSize(0.05);
  Cociente_pT__Muon_ak5FastJet->GetXaxis()->SetTitleSize(0.05); Cociente_pT__Muon_ak5FastJet->GetYaxis()->SetTitleSize(0.05);
  Cociente_pT__Muon_ak5FastJet->GetXaxis()->SetTitleOffset(1.0);Cociente_pT__Muon_ak5FastJet->GetYaxis()->SetTitleOffset(1.0);
  Cociente_pT__Muon_ak5FastJet->SetAxisRange(0.0, 2.0, "X");
  Cociente_pT__Muon_ak5FastJet->SetAxisRange(0.00001, 0.3, "Y");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Cociente_pT__Muon_ak5FastJet -> Draw("E1"); Cociente_pT__Muon_ak5FastJet->SetLineColor(1); Cociente_pT__Muon_ak5FastJet->SetLineWidth(2);
  Cociente_pT__Muon_ak5FastJet->SetMarkerStyle(20); Cociente_pT__Muon_ak5FastJet->SetMarkerColor(1); Cociente_pT__Muon_ak5FastJet->SetMarkerSize(2);
  CocCoord_pT__Muon_ak5PFJet -> Draw("E1same"); CocCoord_pT__Muon_ak5PFJet->SetLineColor(2); CocCoord_pT__Muon_ak5PFJet->SetLineWidth(2);
  CocCoord_pT__Muon_ak5PFJet->SetMarkerStyle(22); CocCoord_pT__Muon_ak5PFJet->SetMarkerColor(2); CocCoord_pT__Muon_ak5PFJet->SetMarkerSize(2);
  Cociente_pT__Muon_ak5PFJet -> Draw("E1same"); Cociente_pT__Muon_ak5PFJet->SetLineColor(4); Cociente_pT__Muon_ak5PFJet->SetLineWidth(2);
  Cociente_pT__Muon_ak5PFJet->SetMarkerStyle(23); Cociente_pT__Muon_ak5PFJet->SetMarkerColor(4); Cociente_pT__Muon_ak5PFJet->SetMarkerSize(2);
  legen -> Draw();

  CocCoord_pT__Muon_Jet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/CocCoord_pT__Muon_Jet.png"); CocCoord_pT__Muon_Jet -> Close();


  TCanvas* CocCoord_pT__Muon_BTag = new TCanvas("CocCoord_pT__Muon_BTag","Cociente pT FastJet y PFJets para muones en AOD's BTag",10,10,1920,1080);
  CocCoord_pT__Muon_BTag->SetFillColor(0);  CocCoord_pT__Muon_BTag->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  Cociente_pT__Muon_ak5FastJet->SetTitle("Cociente p_{T} para muones en AOD's BTag; p_{T}^{Muon} / p_{T}^{Jet}; U. A.");
  Cociente_pT__Muon_ak5FastJet->GetXaxis()->SetLabelSize(0.05); Cociente_pT__Muon_ak5FastJet->GetYaxis()->SetLabelSize(0.05);
  Cociente_pT__Muon_ak5FastJet->GetXaxis()->SetTitleSize(0.05); Cociente_pT__Muon_ak5FastJet->GetYaxis()->SetTitleSize(0.05);
  Cociente_pT__Muon_ak5FastJet->GetXaxis()->SetTitleOffset(1.0);Cociente_pT__Muon_ak5FastJet->GetYaxis()->SetTitleOffset(1.0);
  Cociente_pT__Muon_ak5FastJet->SetAxisRange(0.0, 2.0, "X");
  Cociente_pT__Muon_ak5FastJet->SetAxisRange(0.00001, 0.3, "Y");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Cociente_pT__Muon_ak5FastJet -> Draw("E1"); Cociente_pT__Muon_ak5FastJet->SetLineColor(1); Cociente_pT__Muon_ak5FastJet->SetLineWidth(2);
  Cociente_pT__Muon_ak5FastJet->SetMarkerStyle(20); Cociente_pT__Muon_ak5FastJet->SetMarkerColor(1); Cociente_pT__Muon_ak5FastJet->SetMarkerSize(2);
  CocCoord_pT__Muon_ak5PFBTag -> Draw("E1same"); CocCoord_pT__Muon_ak5PFBTag->SetLineColor(2); CocCoord_pT__Muon_ak5PFBTag->SetLineWidth(2);
  CocCoord_pT__Muon_ak5PFBTag->SetMarkerStyle(22); CocCoord_pT__Muon_ak5PFBTag->SetMarkerColor(2); CocCoord_pT__Muon_ak5PFBTag->SetMarkerSize(2);
  Cociente_pT__Muon_ak5PFBTag -> Draw("E1same"); Cociente_pT__Muon_ak5PFBTag->SetLineColor(4); Cociente_pT__Muon_ak5PFBTag->SetLineWidth(2);
  Cociente_pT__Muon_ak5PFBTag->SetMarkerStyle(23); Cociente_pT__Muon_ak5PFBTag->SetMarkerColor(4); Cociente_pT__Muon_ak5PFBTag->SetMarkerSize(2);
  legen -> Draw();

  CocCoord_pT__Muon_BTag -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/CocCoord_pT__Muon_BTag.png"); CocCoord_pT__Muon_BTag -> Close();


  TCanvas* CocCoord_pT__Muon_MultiJet = new TCanvas("CocCoord_pT__Muon_MultiJet","Cociente pT FastJet y PFJets para muones en AOD's MultiJet",10,10,1920,1080);
  CocCoord_pT__Muon_MultiJet->SetFillColor(0);  CocCoord_pT__Muon_MultiJet->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  Cociente_pT__Muon_ak5FastJet->SetTitle("Cociente p_{T} para muones en AOD's MultiJet; p_{T}^{Muon} / p_{T}^{Jet}; U. A.");
  Cociente_pT__Muon_ak5FastJet->GetXaxis()->SetLabelSize(0.05); Cociente_pT__Muon_ak5FastJet->GetYaxis()->SetLabelSize(0.05);
  Cociente_pT__Muon_ak5FastJet->GetXaxis()->SetTitleSize(0.05); Cociente_pT__Muon_ak5FastJet->GetYaxis()->SetTitleSize(0.05);
  Cociente_pT__Muon_ak5FastJet->GetXaxis()->SetTitleOffset(1.0);Cociente_pT__Muon_ak5FastJet->GetYaxis()->SetTitleOffset(1.0);
  Cociente_pT__Muon_ak5FastJet->SetAxisRange(0.0, 2.0, "X");
  Cociente_pT__Muon_ak5FastJet->SetAxisRange(0.00001, 0.3, "Y");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Cociente_pT__Muon_ak5FastJet -> Draw("E1"); Cociente_pT__Muon_ak5FastJet->SetLineColor(1); Cociente_pT__Muon_ak5FastJet->SetLineWidth(2);
  Cociente_pT__Muon_ak5FastJet->SetMarkerStyle(20); Cociente_pT__Muon_ak5FastJet->SetMarkerColor(1); Cociente_pT__Muon_ak5FastJet->SetMarkerSize(2);
  CocCoord_pT__Muon_ak5PFMultiJet -> Draw("E1same"); CocCoord_pT__Muon_ak5PFMultiJet->SetLineColor(2); CocCoord_pT__Muon_ak5PFMultiJet->SetLineWidth(2);
  CocCoord_pT__Muon_ak5PFMultiJet->SetMarkerStyle(22); CocCoord_pT__Muon_ak5PFMultiJet->SetMarkerColor(2); CocCoord_pT__Muon_ak5PFMultiJet->SetMarkerSize(2);
  Cociente_pT__Muon_ak5PFMultiJet -> Draw("E1same"); Cociente_pT__Muon_ak5PFMultiJet->SetLineColor(4); Cociente_pT__Muon_ak5PFMultiJet->SetLineWidth(2);
  Cociente_pT__Muon_ak5PFMultiJet->SetMarkerStyle(23); Cociente_pT__Muon_ak5PFMultiJet->SetMarkerColor(4); Cociente_pT__Muon_ak5PFMultiJet->SetMarkerSize(2);
  legen -> Draw();

  CocCoord_pT__Muon_MultiJet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/CocCoord_pT__Muon_MultiJet.png"); CocCoord_pT__Muon_MultiJet -> Close();


  TCanvas* CocCoord_pT__gsfElectron_Jet = new TCanvas("CocCoord_pT__gsfElectron_Jet","Cociente pT FastJet y PFJets para gsfElectrones en AOD's Jet",10,10,1920,1080);
  CocCoord_pT__gsfElectron_Jet->SetFillColor(0);  CocCoord_pT__gsfElectron_Jet->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  Cociente_pT__Electron_ak5FastJet->SetTitle("Cociente p_{T} para electrones en AOD's Jet; p_{T}^{Electron} / p_{T}^{Jet}; U. A.");
  Cociente_pT__Electron_ak5FastJet->GetXaxis()->SetLabelSize(0.05); Cociente_pT__Electron_ak5FastJet->GetYaxis()->SetLabelSize(0.05);
  Cociente_pT__Electron_ak5FastJet->GetXaxis()->SetTitleSize(0.05); Cociente_pT__Electron_ak5FastJet->GetYaxis()->SetTitleSize(0.05);
  Cociente_pT__Electron_ak5FastJet->GetXaxis()->SetTitleOffset(1.0);Cociente_pT__Electron_ak5FastJet->GetYaxis()->SetTitleOffset(1.0);
  Cociente_pT__Muon_ak5FastJet->SetAxisRange(0.00001, 0.3, "Y");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Cociente_pT__Electron_ak5FastJet -> Draw("E1"); Cociente_pT__Electron_ak5FastJet->SetLineColor(1); Cociente_pT__Electron_ak5FastJet->SetLineWidth(2);
  Cociente_pT__Electron_ak5FastJet->SetMarkerStyle(20); Cociente_pT__Electron_ak5FastJet->SetMarkerColor(1); Cociente_pT__Electron_ak5FastJet->SetMarkerSize(2);
  CocCoord_pT__gsfElectron_ak5PFJet -> Draw("E1same"); CocCoord_pT__gsfElectron_ak5PFJet->SetLineColor(2); CocCoord_pT__gsfElectron_ak5PFJet->SetLineWidth(2);
  CocCoord_pT__gsfElectron_ak5PFJet->SetMarkerStyle(22); CocCoord_pT__gsfElectron_ak5PFJet->SetMarkerColor(2); CocCoord_pT__gsfElectron_ak5PFJet->SetMarkerSize(2);
  Cociente_pT__gsfElectron_ak5PFJet -> Draw("E1same"); Cociente_pT__gsfElectron_ak5PFJet->SetLineColor(4); Cociente_pT__gsfElectron_ak5PFJet->SetLineWidth(2);
  Cociente_pT__gsfElectron_ak5PFJet->SetMarkerStyle(23); Cociente_pT__gsfElectron_ak5PFJet->SetMarkerColor(4); Cociente_pT__gsfElectron_ak5PFJet->SetMarkerSize(2);
  legen -> Draw();

  CocCoord_pT__gsfElectron_Jet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/CocCoord_pT__gsfElectron_Jet.png"); CocCoord_pT__gsfElectron_Jet -> Close();


  TCanvas* CocCoord_pT__gsfElectron_BTag = new TCanvas("CocCoord_pT__gsfElectron_BTag","Cociente pT FastJet y PFBTags para gsfElectrones en AOD's Jet",10,10,1920,1080);
  CocCoord_pT__gsfElectron_BTag->SetFillColor(0);  CocCoord_pT__gsfElectron_BTag->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  Cociente_pT__Electron_ak5FastJet->SetTitle("Cociente p_{T} para electrones en AOD's BTag; p_{T}^{Electron} / p_{T}^{Jet}; U. A.");
  Cociente_pT__Electron_ak5FastJet->GetXaxis()->SetLabelSize(0.05); Cociente_pT__Electron_ak5FastJet->GetYaxis()->SetLabelSize(0.05);
  Cociente_pT__Electron_ak5FastJet->GetXaxis()->SetTitleSize(0.05); Cociente_pT__Electron_ak5FastJet->GetYaxis()->SetTitleSize(0.05);
  Cociente_pT__Electron_ak5FastJet->GetXaxis()->SetTitleOffset(1.0);Cociente_pT__Electron_ak5FastJet->GetYaxis()->SetTitleOffset(1.0);
  Cociente_pT__Muon_ak5FastJet->SetAxisRange(0.00001, 0.3, "Y");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Cociente_pT__Electron_ak5FastJet -> Draw("E1"); Cociente_pT__Electron_ak5FastJet->SetLineColor(1); Cociente_pT__Electron_ak5FastJet->SetLineWidth(2);
  Cociente_pT__Electron_ak5FastJet->SetMarkerStyle(20); Cociente_pT__Electron_ak5FastJet->SetMarkerColor(1); Cociente_pT__Electron_ak5FastJet->SetMarkerSize(2);
  CocCoord_pT__gsfElectron_ak5PFBTag -> Draw("E1same"); CocCoord_pT__gsfElectron_ak5PFBTag->SetLineColor(2); CocCoord_pT__gsfElectron_ak5PFBTag->SetLineWidth(2);
  CocCoord_pT__gsfElectron_ak5PFBTag->SetMarkerStyle(22); CocCoord_pT__gsfElectron_ak5PFBTag->SetMarkerColor(2); CocCoord_pT__gsfElectron_ak5PFBTag->SetMarkerSize(2);
  Cociente_pT__gsfElectron_ak5PFBTag -> Draw("E1same"); Cociente_pT__gsfElectron_ak5PFBTag->SetLineColor(4); Cociente_pT__gsfElectron_ak5PFBTag->SetLineWidth(2);
  Cociente_pT__gsfElectron_ak5PFBTag->SetMarkerStyle(23); Cociente_pT__gsfElectron_ak5PFBTag->SetMarkerColor(4); Cociente_pT__gsfElectron_ak5PFBTag->SetMarkerSize(2);
  legen -> Draw();

  CocCoord_pT__gsfElectron_BTag -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/CocCoord_pT__gsfElectron_BTag.png"); CocCoord_pT__gsfElectron_BTag -> Close();


  TCanvas* CocCoord_pT__gsfElectron_MultiJet = new TCanvas("CocCoord_pT__gsfElectron_MultiJet","Cociente pT FastJet y PFMultiJets para gsfElectrones en AOD's MultiJet",10,10,1920,1080);
  CocCoord_pT__gsfElectron_MultiJet->SetFillColor(0);  CocCoord_pT__gsfElectron_MultiJet->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  Cociente_pT__Electron_ak5FastJet->SetTitle("Cociente p_{T} para electrones en AOD's MultiJet; p_{T}^{Electron} / p_{T}^{Jet}; U. A.");
  Cociente_pT__Electron_ak5FastJet->GetXaxis()->SetLabelSize(0.05); Cociente_pT__Electron_ak5FastJet->GetYaxis()->SetLabelSize(0.05);
  Cociente_pT__Electron_ak5FastJet->GetXaxis()->SetTitleSize(0.05); Cociente_pT__Electron_ak5FastJet->GetYaxis()->SetTitleSize(0.05);
  Cociente_pT__Electron_ak5FastJet->GetXaxis()->SetTitleOffset(1.0);Cociente_pT__Electron_ak5FastJet->GetYaxis()->SetTitleOffset(1.0);
  Cociente_pT__Muon_ak5FastJet->SetAxisRange(0.00001, 0.3, "Y");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Cociente_pT__Electron_ak5FastJet -> Draw("E1"); Cociente_pT__Electron_ak5FastJet->SetLineColor(1); Cociente_pT__Electron_ak5FastJet->SetLineWidth(2);
  Cociente_pT__Electron_ak5FastJet->SetMarkerStyle(20); Cociente_pT__Electron_ak5FastJet->SetMarkerColor(1); Cociente_pT__Electron_ak5FastJet->SetMarkerSize(2);
  CocCoord_pT__gsfElectron_ak5PFMultiJet -> Draw("E1same"); CocCoord_pT__gsfElectron_ak5PFMultiJet->SetLineColor(2); CocCoord_pT__gsfElectron_ak5PFMultiJet->SetLineWidth(2);
  CocCoord_pT__gsfElectron_ak5PFMultiJet->SetMarkerStyle(22); CocCoord_pT__gsfElectron_ak5PFMultiJet->SetMarkerColor(2); CocCoord_pT__gsfElectron_ak5PFMultiJet->SetMarkerSize(2);
  Cociente_pT__gsfElectron_ak5PFMultiJet -> Draw("E1same"); Cociente_pT__gsfElectron_ak5PFMultiJet->SetLineColor(4); Cociente_pT__gsfElectron_ak5PFMultiJet->SetLineWidth(2);
  Cociente_pT__gsfElectron_ak5PFMultiJet->SetMarkerStyle(23); Cociente_pT__gsfElectron_ak5PFMultiJet->SetMarkerColor(4); Cociente_pT__gsfElectron_ak5PFMultiJet->SetMarkerSize(2);
  legen -> Draw();

  CocCoord_pT__gsfElectron_MultiJet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/CocCoord_pT__gsfElectron_MultiJet.png"); CocCoord_pT__gsfElectron_MultiJet -> Close();
}


//################################################################################################################

void Vertice() {
  //Abrimos el archivo que nos interesa y el árbol que queremos leer.
  TFile *FastJetFile = new TFile("/home/saksevul/T/PYTHIA/FastJet/ak5FJ.SoftHard.root");
  TFile *JetFile = new TFile("/home/saksevul/T/OpenData/Jet_20000/ak5PF.Vertex.root");
  TFile *BTagFile = new TFile("/home/saksevul/T/OpenData/BTag_20000/ak5PF.Vertex.root");
  TFile *MultiJetFile = new TFile("/home/saksevul/T/OpenData/MultiJet_20000/ak5PF.Vertex.root");

  TH1F  *Muons__fX, *Muons__fY, *Muons__fZ,
        *MuonsJet_fX_, *MuonsJet_fY_, *MuonsJet_fZ_,
        *MuonsBTag_fX_, *MuonsBTag_fY_, *MuonsBTag_fZ_,
        *MuonsMultiJet_fX_, *MuonsMultiJet_fY_, *MuonsMultiJet_fZ_,
        *Electrons__fX, *Electrons__fY, *Electrons__fZ,
        *gsfElectronsJet_fX_, *gsfElectronsJet_fY_, *gsfElectronsJet_fZ_,
        *gsfElectronsBTag_fX_, *gsfElectronsBTag_fY_, *gsfElectronsBTag_fZ_,
        *gsfElectronsMultiJet_fX_, *gsfElectronsMultiJet_fY_, *gsfElectronsMultiJet_fZ_;

  Muons__fX =(TH1F*)FastJetFile->Get("Muons__fX"); Muons__fX->Scale(1.0/Muons__fX->Integral());
  MuonsJet_fX_ =(TH1F*)JetFile->Get("Muons_fX_"); MuonsJet_fX_->Scale(1.0/MuonsJet_fX_->Integral());
  MuonsBTag_fX_ =(TH1F*)BTagFile->Get("Muons_fX_"); MuonsBTag_fX_->Scale(1.0/MuonsBTag_fX_->Integral());
  MuonsMultiJet_fX_ =(TH1F*)MultiJetFile->Get("Muons_fX_"); MuonsMultiJet_fX_->Scale(1.0/MuonsMultiJet_fX_->Integral());
  Muons__fY =(TH1F*)FastJetFile->Get("Muons__fY"); Muons__fY->Scale(1.0/Muons__fY->Integral());
  MuonsJet_fY_ =(TH1F*)JetFile->Get("Muons_fY_"); MuonsJet_fY_->Scale(1.0/MuonsJet_fY_->Integral());
  MuonsBTag_fY_ =(TH1F*)BTagFile->Get("Muons_fY_"); MuonsBTag_fY_->Scale(1.0/MuonsBTag_fY_->Integral());
  MuonsMultiJet_fY_ =(TH1F*)MultiJetFile->Get("Muons_fY_"); MuonsMultiJet_fY_->Scale(1.0/MuonsMultiJet_fY_->Integral());
  Muons__fZ =(TH1F*)FastJetFile->Get("Muons__fZ"); Muons__fZ->Scale(1.0/Muons__fZ->Integral());
  MuonsJet_fZ_ =(TH1F*)JetFile->Get("Muons_fZ_"); MuonsJet_fZ_->Scale(1.0/MuonsJet_fZ_->Integral());
  MuonsBTag_fZ_ =(TH1F*)BTagFile->Get("Muons_fZ_"); MuonsBTag_fZ_->Scale(1.0/MuonsBTag_fZ_->Integral());
  MuonsMultiJet_fZ_ =(TH1F*)MultiJetFile->Get("Muons_fZ_"); MuonsMultiJet_fZ_->Scale(1.0/MuonsMultiJet_fZ_->Integral());

  Electrons__fX =(TH1F*)FastJetFile->Get("Electrons__fX"); Electrons__fX->Scale(1.0/Electrons__fX->Integral());
  gsfElectronsJet_fX_ =(TH1F*)JetFile->Get("gsfElectrons_fX_"); gsfElectronsJet_fX_->Scale(1.0/gsfElectronsJet_fX_->Integral());
  gsfElectronsBTag_fX_ =(TH1F*)BTagFile->Get("gsfElectrons_fX_"); gsfElectronsBTag_fX_->Scale(1.0/gsfElectronsBTag_fX_->Integral());
  gsfElectronsMultiJet_fX_ =(TH1F*)MultiJetFile->Get("gsfElectrons_fX_"); gsfElectronsMultiJet_fX_->Scale(1.0/gsfElectronsMultiJet_fX_->Integral());
  Electrons__fY =(TH1F*)FastJetFile->Get("Electrons__fY"); Electrons__fY->Scale(1.0/Electrons__fY->Integral());
  gsfElectronsJet_fY_ =(TH1F*)JetFile->Get("gsfElectrons_fY_"); gsfElectronsJet_fY_->Scale(1.0/gsfElectronsJet_fY_->Integral());
  gsfElectronsBTag_fY_ =(TH1F*)BTagFile->Get("gsfElectrons_fY_"); gsfElectronsBTag_fY_->Scale(1.0/gsfElectronsBTag_fY_->Integral());
  gsfElectronsMultiJet_fY_ =(TH1F*)MultiJetFile->Get("gsfElectrons_fY_"); gsfElectronsMultiJet_fY_->Scale(1.0/gsfElectronsMultiJet_fY_->Integral());
  Electrons__fZ =(TH1F*)FastJetFile->Get("Electrons__fZ"); Electrons__fZ->Scale(1.0/Electrons__fZ->Integral());
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

//################################################################################################################

void rootMacro(){
  // // Le damos algo de personalización al las gráficas.
  // gROOT->ForceStyle();
  // gStyle->SetPadBorderMode(0);    gStyle->SetPadBorderSize(0);
  // gStyle->SetPadTopMargin(0.08);  gStyle->SetPadBottomMargin(0.12);
  // gStyle->SetPadLeftMargin(0.10); gStyle->SetPadRightMargin(0.10);
  // gStyle->SetOptStat(0);          gStyle->SetOptTitle(1);


  // Corremos los macros que nos interesan.
  // DistanciaAngular();
  pT();
  // Multiplicidad();
  // Vertice();

}
