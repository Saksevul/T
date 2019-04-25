void DistanciaAngular() {
  //Abrimos el archivo que nos interesa y el árbol que queremos leer.
  TFile *FastJetFile = new TFile("/home/saksevul/T/PYTHIA/ak5FJ.root");
  TFile *JetFile = new TFile("/home/saksevul/T/OpenData/Jet_20000/ak5PF-0001.root");
  TFile *BTagFile = new TFile("/home/saksevul/T/OpenData/BTag_20000/ak5PF-0001.root");
  TFile *MultiJetFile = new TFile("/home/saksevul/T/OpenData/MultiJet_20000/ak5PF-0001.root");

  TH1F *D__Muon_ak5FastJet, *D__Electron_ak5FastJet, *ak5FastJet__D_Jet_Jet,
       *D__Muon_ak5PFJet, *D__gsfElectron_ak5PFJet, *ak5PFBTag__D_Jet_Jet;

  ak5FastJet__D_Jet_Jet =(TH1F*)FastJetFile->Get("ak5FastJet__D__Jet_Jet"); ak5PFBTag__D_Jet_Jet-> Scale(1.0/ak5PFBTag__D_Jet_Jet->Integral());
  ak5PFBTag__D_Jet_Jet =(TH1F*)BTagFile->Get("ak5PFJets__D__Jet_Jet"); ak5PFBTag__D_Jet_Jet-> Scale(1.0/ak5PFBTag__D_Jet_Jet->Integral());


    auto   legend = new TLegend(0.65,0.80,0.90,0.92);
      legend->SetTextSize(0.04);
      legend->AddEntry(ak5PFBTag__D_Jet_Jet, "Open-Data PFJets", "lp");
      legend->AddEntry(ak5FastJet__D_Jet_Jet, "MC FastJet", "lp");


  //Creamos un liezo en el cual dibujarémos los histogramas sin modificar.
  TCanvas* ak5PFJet__D_Jet_Jet = new TCanvas("DistanciaAngular","Distancia Angular de FastJet y PFJets por Evento",10,10,1920,1080);
  ak5PFJet__D_Jet_Jet -> SetFillColor(0);  ak5PFJet__D_Jet_Jet -> SetFrameBorderMode(0);  gPad ->SetLogy();

  // Esto es para modificar las etiquetas del canvas.
  ak5PFBTag__D_Jet_Jet->SetTitle("Distancia Angular entre los Jets de cada Evento; Distancia Angular; Probabilidad");
  ak5PFBTag__D_Jet_Jet->GetXaxis()->SetLabelSize(0.05); ak5PFBTag__D_Jet_Jet->GetYaxis()->SetLabelSize(0.05);
  ak5PFBTag__D_Jet_Jet->GetXaxis()->SetTitleSize(0.05); ak5PFBTag__D_Jet_Jet->GetYaxis()->SetTitleSize(0.05);
  ak5PFBTag__D_Jet_Jet->GetXaxis()->SetTitleOffset(1.0);ak5PFBTag__D_Jet_Jet->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  ak5PFBTag__D_Jet_Jet -> Draw(""); ak5PFBTag__D_Jet_Jet -> SetLineColor(2);
  ak5PFBTag__D_Jet_Jet -> SetMarkerStyle(45); ak5PFBTag__D_Jet_Jet -> SetMarkerColor(2);
  ak5FastJet__D_Jet_Jet -> Draw("same"); ak5FastJet__D_Jet_Jet -> SetLineColor(4);
  ak5FastJet__D_Jet_Jet -> SetMarkerStyle(41); ak5FastJet__D_Jet_Jet -> SetMarkerColor(4);
  legend -> Draw();

  ak5PFJet__D_Jet_Jet     -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/D_Jet_Jet FastJet y PFJets.png"    ); ak5PFJet__D_Jet_Jet     -> Close();

}

//################################################################################################################

void Multiplicidad() {
  //Abrimos el archivo que nos interesa y el árbol que queremos leer.
  TFile *FastJetFile = new TFile("/home/saksevul/T/PYTHIA/ak5FJ.root");
  TFile *JetFile = new TFile("/home/saksevul/T/OpenData/Jet_20000/ak5PF-0001.root");
  TFile *BTagFile = new TFile("/home/saksevul/T/OpenData/BTag_20000/ak5PF-0001.root");
  TFile *MultiJetFile = new TFile("/home/saksevul/T/OpenData/MultiJet_20000/ak5PF-0001.root");

  TH1F *ak5FastJet__Multiplicidad, *ak5PFJet__Multiplicidad, *ak5PFBTag__Multiplicidad, *ak5PFMultiJet__Multiplicidad;

  ak5FastJet__Multiplicidad =(TH1F*)FastJetFile->Get("ak5FastJet__Multiplicidad"); ak5FastJet__Multiplicidad -> Scale(1.0/ak5FastJet__Multiplicidad->Integral());
  ak5PFJet__Multiplicidad =(TH1F*)JetFile->Get("ak5PFJet__Multiplicidad"); ak5PFJet__Multiplicidad -> Scale(1.0/ak5PFJet__Multiplicidad->Integral());
  ak5PFBTag__Multiplicidad =(TH1F*)BTagFile->Get("ak5PFJet__Multiplicidad"); ak5PFBTag__Multiplicidad -> Scale(1.0/ak5PFBTag__Multiplicidad->Integral());
  ak5PFMultiJet__Multiplicidad =(TH1F*)MultiJetFile->Get("ak5PFJet__Multiplicidad"); ak5PFMultiJet__Multiplicidad -> Scale(1.0/ak5PFMultiJet__Multiplicidad->Integral());


    auto   legend = new TLegend(0.65,0.80,0.90,0.92);
      legend->SetTextSize(0.04);
      legend->AddEntry(ak5FastJet__Multiplicidad, "MC FastJet", "lp");
      legend->AddEntry(ak5PFJet__Multiplicidad, "Open-Data PF Jet", "lp");
      legend->AddEntry(ak5PFBTag__Multiplicidad, "Open-Data PF BTag", "lp");
      legend->AddEntry(ak5PFMultiJet__Multiplicidad, "Open-Data PF MultiJet", "lp");


  //Creamos un liezo en el cual dibujarémos los histogramas sin modificar.
  TCanvas* Espectro_Multiplicidad__Jets = new TCanvas("Multiplicidad de Jets","Multiplicidad de FastJet y PFJets por Evento",10,10,1920,1080);
  Espectro_Multiplicidad__Jets -> SetFillColor(0);  Espectro_Multiplicidad__Jets -> SetFrameBorderMode(0);  gPad ->SetLogy();

    // Esto es para modificar las etiquetas del canvas.
    ak5FastJet__Multiplicidad->SetTitle("Multiplicidad de Jets por Evento; Numero de Jets; Probabilidad");
    ak5FastJet__Multiplicidad->GetXaxis()->SetLabelSize(0.05); ak5FastJet__Multiplicidad->GetYaxis()->SetLabelSize(0.05);
    ak5FastJet__Multiplicidad->GetXaxis()->SetTitleSize(0.05); ak5FastJet__Multiplicidad->GetYaxis()->SetTitleSize(0.05);
    ak5FastJet__Multiplicidad->GetXaxis()->SetTitleOffset(1.0);ak5FastJet__Multiplicidad->GetYaxis()->SetTitleOffset(1.0);
    // Aqui ponemos todas las gráficas que necesitamos en el canvas.
    ak5FastJet__Multiplicidad -> Draw(""); ak5FastJet__Multiplicidad -> SetLineColor(1);
    ak5FastJet__Multiplicidad -> SetMarkerStyle(45); ak5FastJet__Multiplicidad -> SetMarkerColor(1);
    ak5PFJet__Multiplicidad -> Draw("same"); ak5PFJet__Multiplicidad -> SetLineColor(2);
    ak5PFJet__Multiplicidad -> SetMarkerStyle(41); ak5PFJet__Multiplicidad -> SetMarkerColor(2);
    ak5PFBTag__Multiplicidad -> Draw("same"); ak5PFBTag__Multiplicidad -> SetLineColor(4);
    ak5PFBTag__Multiplicidad -> SetMarkerStyle(41); ak5PFBTag__Multiplicidad -> SetMarkerColor(4);
    ak5PFMultiJet__Multiplicidad -> Draw("same"); ak5PFMultiJet__Multiplicidad -> SetLineColor(8);
    ak5PFMultiJet__Multiplicidad -> SetMarkerStyle(41); ak5PFMultiJet__Multiplicidad -> SetMarkerColor(8);
    legend -> Draw();

  Espectro_Multiplicidad__Jets -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Multiplicidad__FastJet_PFJets.png"); Espectro_Multiplicidad__Jets -> Close();

}

//################################################################################################################

void pT() {
  //Abrimos el archivo que nos interesa y el árbol que queremos leer.
  TFile *FastJetFile = new TFile("/home/saksevul/T/PYTHIA/ak5FJ.root");
  TFile *JetFile = new TFile("/home/saksevul/T/OpenData/Jet_20000/ak5PF-0001.root");
  TFile *BTagFile = new TFile("/home/saksevul/T/OpenData/BTag_20000/ak5PF-0001.root");
  TFile *MultiJetFile = new TFile("/home/saksevul/T/OpenData/MultiJet_20000/ak5PF-0001.root");

  TH1F *Muons__pT, *Electrons__pT, *ak5FastJet__pT,
      *MuonsJet_pt_, *gsfElectronsJet_pt_, *ak5PFBTag_pt_,
       *MuonsBTag_pt_, *gsfElectronsBTag_pt_, *ak5PFBTag_pt_,
       *MuonsMultiJet_pt_, *gsfElectronsMultiJet_pt_, *ak5PFBTag_pt_,
       *Cociente_pT__Electron_ak5FastJet, *Cociente_pT__Muon_ak5FastJet,
       *Cociente_pT__gsfElectron_ak5PFJet, *Cociente_pT__Muon_ak5PFJet,
       *Cociente_pT__gsfElectron_ak5PFBTag, *Cociente_pT__Muon_ak5PFBTag,
       *Cociente_pT__gsfElectron_ak5PFMultiJet, *Cociente_pT__Muon_ak5PFMultiJet;

  ak5FastJet__pT =(TH1F*)FastJetFile->Get("ak5FastJet__pT"); ak5FastJet__pT -> Scale(1.0/ak5FastJet__pT->Integral());
  ak5PFJet_pt_ =(TH1F*)JetFile->Get("ak5PFJets_pt_"); ak5PFJet_pt_ -> Scale(1.0/ak5PFJet_pt_->Integral());
  ak5PFBTag_pt_ =(TH1F*)BTagFile->Get("ak5PFJets_pt_"); ak5PFBTag_pt_ -> Scale(1.0/ak5PFBTag_pt_->Integral());
  ak5PFMultiJet_pt_ =(TH1F*)MultiJetFile->Get("ak5PFJets_pt_"); ak5PFMultiJet_pt_ -> Scale(1.0/ak5PFMultiJet_pt_->Integral());

  Cociente_pT__Electron_ak5FastJet =(TH1F*)FastJetFile->Get("Cociente_pT__Electron-ak5FastJet");  Cociente_pT__Electron_ak5FastJet -> Scale(1.0/Cociente_pT__Electron_ak5FastJet->Integral());
  Cociente_pT__gsfElectron_ak5PFJet =(TH1F*)JetFile->Get("Cociente_pT__gsfElectron-ak5PFJet");   Cociente_pT__gsfElectron_ak5PFJet-> Scale(1.0/Cociente_pT__gsfElectron_ak5PFJet->Integral());
  Cociente_pT__gsfElectron_ak5PFBTag =(TH1F*)BTagFile->Get("Cociente_pT__gsfElectron-ak5PFJet");   Cociente_pT__gsfElectron_ak5PFBTag-> Scale(1.0/Cociente_pT__gsfElectron_ak5PFBTag->Integral());
  Cociente_pT__gsfElectron_ak5PFMultiJet =(TH1F*)MultiJetFile->Get("Cociente_pT__gsfElectron-ak5PFJet");   Cociente_pT__gsfElectron_ak5PFMultiJet-> Scale(1.0/Cociente_pT__gsfElectron_ak5PFMultiJet->Integral());

  Cociente_pT__Muon_ak5FastJet =(TH1F*)FastJetFile->Get("Cociente_pT__Muon-ak5FastJet"); Cociente_pT__Muon_ak5FastJet-> Scale(1.0/Cociente_pT__Muon_ak5FastJet->Integral());
  Cociente_pT__Muon_ak5PFJet =(TH1F*)JetFile->Get("Cociente_pT__Muon-ak5PFJet"); Cociente_pT__Muon_ak5PFJet-> Scale(1.0/Cociente_pT__Muon_ak5PFJet->Integral());
  Cociente_pT__Muon_ak5PFBTag =(TH1F*)BTagFile->Get("Cociente_pT__Muon-ak5PFJet"); Cociente_pT__Muon_ak5PFBTag-> Scale(1.0/Cociente_pT__Muon_ak5PFBTag->Integral());
  Cociente_pT__Muon_ak5PFMultiJet =(TH1F*)MultiJetFile->Get("Cociente_pT__Muon-ak5PFJet"); Cociente_pT__Muon_ak5PFMultiJet-> Scale(1.0/Cociente_pT__Muon_ak5PFMultiJet->Integral());


  auto   legend = new TLegend(0.65,0.80,0.90,0.92);
    legend->SetTextSize(0.04);
    legend->AddEntry(Cociente_pT__Electron_ak5FastJet, "MC FastJet", "lp");
    legend->AddEntry(Cociente_pT__gsfElectron_ak5PFJet, "Open-Data PF Jets", "lp");
    legend->AddEntry(Cociente_pT__gsfElectron_ak5PFBTag, "Open-Data PF BTag", "lp");
    legend->AddEntry(Cociente_pT__gsfElectron_ak5PFMultiJet, "Open-Data PF MultiJets", "lp");


  //Creamos un liezo en el cual dibujarémos los histogramas sin modificar.
  TCanvas* Espectro_pT__Jets = new TCanvas("pT","Espectro de pT de FastJet y PFJets",10,10,1920,1080);
  Espectro_pT__Jets -> SetFillColor(0);  Espectro_pT__Jets -> SetFrameBorderMode(0);  gPad ->SetLogy();

  // Esto es para modificar las etiquetas del canvas.
  ak5FastJet__pT->SetTitle("Espectro de p_{T} de Jets; p_{T} [GeV]; Probabilidad");
  ak5FastJet__pT->GetXaxis()->SetLabelSize(0.05); ak5FastJet__pT->GetYaxis()->SetLabelSize(0.05);
  ak5FastJet__pT->GetXaxis()->SetTitleSize(0.05); ak5FastJet__pT->GetYaxis()->SetTitleSize(0.05);
  ak5FastJet__pT->GetXaxis()->SetTitleOffset(1.0);ak5FastJet__pT->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  ak5FastJet__pT -> Draw(""); ak5FastJet__pT -> SetLineColor(1);
  ak5FastJet__pT -> SetMarkerStyle(45); ak5FastJet__pT -> SetMarkerColor(1);
  ak5PFJet_pt_ -> Draw("same"); ak5PFJet_pt_ -> SetLineColor(2);
  ak5PFJet_pt_ -> SetMarkerStyle(41); ak5PFJet_pt_ -> SetMarkerColor(2);
  ak5PFBTag_pt_ -> Draw("same"); ak5PFBTag_pt_ -> SetLineColor(4);
  ak5PFBTag_pt_ -> SetMarkerStyle(41); ak5PFBTag_pt_ -> SetMarkerColor(4);
  ak5PFMultiJet_pt_ -> Draw("same"); ak5PFMultiJet_pt_ -> SetLineColor(8);
  ak5PFMultiJet_pt_ -> SetMarkerStyle(41); ak5PFMultiJet_pt_ -> SetMarkerColor(8);
  legend -> Draw();


  TCanvas* Cociente_pT__Electron_Jet = new TCanvas("Cociente_pT__Electron_Jet","Cociente pT FastJet y PFJets para electrones",10,10,1920,1080);
  Cociente_pT__Electron_Jet -> SetFillColor(0);  Cociente_pT__Electron_Jet -> SetFrameBorderMode(0);  gPad ->SetLogy();

  // Esto es para modificar las etiquetas del canvas.
  Cociente_pT__Electron_ak5FastJet->SetTitle("Cociente pT para electrones; Cociente; Frecuencia");
  Cociente_pT__Electron_ak5FastJet->GetXaxis()->SetLabelSize(0.05); Cociente_pT__Electron_ak5FastJet->GetYaxis()->SetLabelSize(0.05);
  Cociente_pT__Electron_ak5FastJet->GetXaxis()->SetTitleSize(0.05); Cociente_pT__Electron_ak5FastJet->GetYaxis()->SetTitleSize(0.05);
  Cociente_pT__Electron_ak5FastJet->GetXaxis()->SetTitleOffset(1.0);Cociente_pT__Electron_ak5FastJet->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Cociente_pT__Electron_ak5FastJet -> Draw(""); Cociente_pT__Electron_ak5FastJet -> SetLineColor(1);
  Cociente_pT__Electron_ak5FastJet -> SetMarkerStyle(45); Cociente_pT__Electron_ak5FastJet -> SetMarkerColor(1);
  Cociente_pT__gsfElectron_ak5PFJet -> Draw("same"); Cociente_pT__gsfElectron_ak5PFJet -> SetLineColor(2);
  Cociente_pT__gsfElectron_ak5PFJet -> SetMarkerStyle(41); Cociente_pT__gsfElectron_ak5PFJet -> SetMarkerColor(2);
  Cociente_pT__gsfElectron_ak5PFBTag -> Draw("same"); Cociente_pT__gsfElectron_ak5PFBTag -> SetLineColor(4);
  Cociente_pT__gsfElectron_ak5PFBTag -> SetMarkerStyle(41); Cociente_pT__gsfElectron_ak5PFBTag -> SetMarkerColor(4);
  Cociente_pT__gsfElectron_ak5PFMultiJet -> Draw("same"); Cociente_pT__gsfElectron_ak5PFMultiJet -> SetLineColor(8);
  Cociente_pT__gsfElectron_ak5PFMultiJet -> SetMarkerStyle(41); Cociente_pT__gsfElectron_ak5PFMultiJet -> SetMarkerColor(8);
  legend -> Draw();


  TCanvas* Cociente_pT__Muon_Jet = new TCanvas("Cociente_pT__Muon_Jet","Cociente pT FastJet y PFJets para muones",10,10,1920,1080);
  Cociente_pT__Muon_Jet -> SetFillColor(0);  Cociente_pT__Muon_Jet -> SetFrameBorderMode(0);  gPad ->SetLogy();

  // Esto es para modificar las etiquetas del canvas.
  Cociente_pT__Muon_ak5FastJet->SetTitle("Cociente pT para muones; Cociente; Frecuencia");
  Cociente_pT__Muon_ak5FastJet->GetXaxis()->SetLabelSize(0.05); Cociente_pT__Muon_ak5FastJet->GetYaxis()->SetLabelSize(0.05);
  Cociente_pT__Muon_ak5FastJet->GetXaxis()->SetTitleSize(0.05); Cociente_pT__Muon_ak5FastJet->GetYaxis()->SetTitleSize(0.05);
  Cociente_pT__Muon_ak5FastJet->GetXaxis()->SetTitleOffset(1.0);Cociente_pT__Muon_ak5FastJet->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Cociente_pT__Muon_ak5FastJet -> Draw(""); Cociente_pT__Muon_ak5FastJet -> SetLineColor(1);
  Cociente_pT__Muon_ak5FastJet -> SetMarkerStyle(45); Cociente_pT__Muon_ak5FastJet -> SetMarkerColor(1);
  Cociente_pT__Muon_ak5PFJet -> Draw("same"); Cociente_pT__Muon_ak5PFJet -> SetLineColor(2);
  Cociente_pT__Muon_ak5PFJet -> SetMarkerStyle(41); Cociente_pT__Muon_ak5PFJet -> SetMarkerColor(2);
  Cociente_pT__Muon_ak5PFBTag -> Draw("same"); Cociente_pT__Muon_ak5PFBTag -> SetLineColor(4);
  Cociente_pT__Muon_ak5PFBTag -> SetMarkerStyle(41); Cociente_pT__Muon_ak5PFBTag -> SetMarkerColor(4);
  Cociente_pT__Muon_ak5PFMultiJet -> Draw("same"); Cociente_pT__Muon_ak5PFMultiJet -> SetLineColor(8);
  Cociente_pT__Muon_ak5PFMultiJet -> SetMarkerStyle(41); Cociente_pT__Muon_ak5PFMultiJet -> SetMarkerColor(8);
  legend -> Draw();


  Espectro_pT__Jets -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/pT__FastJet_PFJets.png"); Espectro_pT__Jets -> Close();
  Cociente_pT__Electron_Jet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT__Electron_Jet.png"); Cociente_pT__Electron_Jet -> Close();
  Cociente_pT__Muon_Jet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT__Muon_Jet.png"); Cociente_pT__Muon_Jet -> Close();

}

//################################################################################################################

void Vertice() {
  //Abrimos el archivo que nos interesa y el árbol que queremos leer.
  TFile *FastJetFile = new TFile("/home/saksevul/T/PYTHIA/ak5FJ.root");
  TFile *JetFile = new TFile("/home/saksevul/T/OpenData/Jet_20000/ak5PF-0001.root");
  TFile *BTagFile = new TFile("/home/saksevul/T/OpenData/BTag_20000/ak5PF-0001.root");
  TFile *MultiJetFile = new TFile("/home/saksevul/T/OpenData/MultiJet_20000/ak5PF-0001.root");

  TH1F  *Muons__fX, *Muons__fY, *Muons__fZ,
        *MuonsJet_fX_, *MuonsJet_fY_, *MuonsJet_fZ_,
        *MuonsBTag_fX_, *MuonsBTag_fY_, *MuonsBTag_fZ_,
        *MuonsMultiJet_fX_, *MuonsMultiJet_fY_, *MuonsMultiJet_fZ_,
        *Electrons__fX, *Electrons__fY, *Electrons__fZ,
        *gsfElectronsJet_fX_, *gsfElectronsJet_fY_, *gsfElectronsJet_fZ_,
        *gsfElectronsBTag_fX_, *gsfElectronsBTag_fY_, *gsfElectronsBTag_fZ_,
        *gsfElectronsMultiJet_fX_, *gsfElectronsMultiJet_fY_, *gsfElectronsMultiJet_fZ_;

  Muons__fX =(TH1F*)FastJetFile->Get("Muons__fX"); Muons__fX -> Scale(1.0/Muons__fX->Integral());
  MuonsJet_fX_ =(TH1F*)JetFile->Get("Muons_fX_"); MuonsJet_fX_ -> Scale(1.0/MuonsJet_fX_->Integral());
  Muons__fY =(TH1F*)FastJetFile->Get("Muons__fY"); Muons__fY -> Scale(1.0/Muons__fY->Integral());
  MuonsBTag_fY_ =(TH1F*)BTagFile->Get("Muons_fY_"); MuonsBTag_fY_ -> Scale(1.0/MuonsBTag_fY_->Integral());
  Muons__fZ =(TH1F*)FastJetFile->Get("Muons__fZ"); Muons__fZ -> Scale(1.0/Muons__fZ->Integral());
  MuonsMultiJet_fZ_ =(TH1F*)MultiJetFile->Get("Muons_fZ_"); MuonsMultiJet_fZ_ -> Scale(1.0/MuonsMultiJet_fZ_->Integral());

  Electrons__fX =(TH1F*)FastJetFile->Get("Electrons__fX"); Electrons__fX -> Scale(1.0/Electrons__fX->Integral());
  gsfElectronsJet_fX_ =(TH1F*)JetFile->Get("gsfElectrons_fX_"); gsfElectronsJet_fX_ -> Scale(1.0/gsfElectronsJet_fX_->Integral());
  Electrons__fY =(TH1F*)FastJetFile->Get("Electrons__fY"); Electrons__fY -> Scale(1.0/Electrons__fY->Integral());
  gsfElectronsBTag_fY_ =(TH1F*)BTagFile->Get("gsfElectrons_fY_"); gsfElectronsBTag_fY_ -> Scale(1.0/gsfElectronsBTag_fY_->Integral());
  Electrons__fZ =(TH1F*)FastJetFile->Get("Electrons__fZ"); Electrons__fZ -> Scale(1.0/Electrons__fZ->Integral());
  gsfElectronsMultiJet_fZ_ =(TH1F*)MultiJetFile->Get("gsfElectrons_fZ_"); gsfElectronsMultiJet_fZ_ -> Scale(1.0/gsfElectronsMultiJet_fZ_->Integral());


  auto   legend = new TLegend(0.65,0.80,0.90,0.92);
    legend->SetTextSize(0.04);
      legend->AddEntry(gsfElectronsBTag_fX_, "Open-Data PFJets", "lp");
      legend->AddEntry(Electrons__fX, "MC FastJet", "lp");


  TCanvas* fX_Electrons = new TCanvas("fX_Electrons","X vertice de FastJet y PFJets para electrones",10,10,1920,1080);
  fX_Electrons -> SetFillColor(0);  fX_Electrons -> SetFrameBorderMode(0);  gPad ->SetLogy();

    // Esto es para modificar las etiquetas del canvas.
    Electrons__fX->SetTitle("Vertice en el eje X para electrones; Posicion [cm]; Frecuencia");
    Electrons__fX->GetXaxis()->SetLabelSize(0.05); Electrons__fX->GetYaxis()->SetLabelSize(0.05);
    Electrons__fX->GetXaxis()->SetTitleSize(0.05); Electrons__fX->GetYaxis()->SetTitleSize(0.05);
    Electrons__fX->GetXaxis()->SetTitleOffset(1.0);Electrons__fX->GetYaxis()->SetTitleOffset(1.0);
    // Aqui ponemos todas las gráficas que necesitamos en el canvas.
    Electrons__fX -> Draw(""); Electrons__fX -> SetLineColor(1);
    Electrons__fX -> SetMarkerStyle(45); Electrons__fX -> SetMarkerColor(1);
    gsfElectronsJet_fX_ -> Draw("same"); gsfElectronsJet_fX_ -> SetLineColor(2);
    gsfElectronsJet_fX_ -> SetMarkerStyle(41); gsfElectronsJet_fX_ -> SetMarkerColor(2);
    gsfElectronsBTag_fX_ -> Draw("same"); gsfElectronsBTag_fX_ -> SetLineColor(4);
    gsfElectronsBTag_fX_ -> SetMarkerStyle(41); gsfElectronsBTag_fX_ -> SetMarkerColor(4);
    gsfElectronsMultiJet_fX_ -> Draw("same"); gsfElectronsMultiJet_fX_ -> SetLineColor(8);
    gsfElectronsMultiJet_fX_ -> SetMarkerStyle(41); gsfElectronsMultiJet_fX_ -> SetMarkerColor(8);
    legend -> Draw();


  TCanvas* fY_Electrons = new TCanvas("fY_Electrons","Y vertice de FastJet y PFJets para electrones",10,10,1920,1080);
  fY_Electrons -> SetFillColor(0);  fY_Electrons -> SetFrameBorderMode(0);  gPad ->SetLogy();

    // Esto es para modificar las etiquetas del canvas.
    Electrons__fY->SetTitle("Vertice en el eje Y para electrones; Posicion [cm]; Frecuencia");
    Electrons__fY->GetXaxis()->SetLabelSize(0.05); Electrons__fY->GetYaxis()->SetLabelSize(0.05);
    Electrons__fY->GetXaxis()->SetTitleSize(0.05); Electrons__fY->GetYaxis()->SetTitleSize(0.05);
    Electrons__fY->GetXaxis()->SetTitleOffset(1.0);Electrons__fY->GetYaxis()->SetTitleOffset(1.0);
    // Aqui ponemos todas las gráficas que necesitamos en el canvas.
    Electrons__fY -> Draw(""); Electrons__fY -> SetLineColor(1);
    Electrons__fY -> SetMarkerStyle(45); Electrons__fY -> SetMarkerColor(1);
    gsfElectronsJet_fY_ -> Draw("same"); gsfElectronsJet_fY_ -> SetLineColor(2);
    gsfElectronsJet_fY_ -> SetMarkerStyle(41); gsfElectronsJet_fY_ -> SetMarkerColor(2);
    gsfElectronsBTag_fY_ -> Draw("same"); gsfElectronsBTag_fY_ -> SetLineColor(4);
    gsfElectronsBTag_fY_ -> SetMarkerStyle(41); gsfElectronsBTag_fY_ -> SetMarkerColor(4);
    gsfElectronsMultiJet_fY_ -> Draw("same"); gsfElectronsMultiJet_fY_ -> SetLineColor(8);
    gsfElectronsMultiJet_fY_ -> SetMarkerStyle(41); gsfElectronsMultiJet_fY_ -> SetMarkerColor(8);
    legend -> Draw();


  TCanvas* fZ_Electrons = new TCanvas("fZ_Electrons","X vertice de FastJet y PFJets para electrones",10,10,1920,1080);
  fZ_Electrons -> SetFillColor(0);  fZ_Electrons -> SetFrameBorderMode(0);  gPad ->SetLogy();

    // Esto es para modificar las etiquetas del canvas.
    Electrons__fZ->SetTitle("Vertice en el eje Z para electrones; Posicion [cm]; Frecuencia");
    Electrons__fZ->GetXaxis()->SetLabelSize(0.05); Electrons__fZ->GetYaxis()->SetLabelSize(0.05);
    Electrons__fZ->GetXaxis()->SetTitleSize(0.05); Electrons__fZ->GetYaxis()->SetTitleSize(0.05);
    Electrons__fZ->GetXaxis()->SetTitleOffset(1.0);Electrons__fZ->GetYaxis()->SetTitleOffset(1.0);
    // Aqui ponemos todas las gráficas que necesitamos en el canvas.
    Electrons__fZ -> Draw(""); Electrons__fZ -> SetLineColor(1);
    Electrons__fZ -> SetMarkerStyle(45); Electrons__fZ -> SetMarkerColor(1);
    gsfElectronsJet_fZ_ -> Draw("same"); gsfElectronsJet_fZ_ -> SetLineColor(2);
    gsfElectronsJet_fZ_ -> SetMarkerStyle(41); gsfElectronsJet_fZ_ -> SetMarkerColor(2);
    gsfElectronsBTag_fZ_ -> Draw("same"); gsfElectronsBTag_fZ_ -> SetLineColor(4);
    gsfElectronsBTag_fZ_ -> SetMarkerStyle(41); gsfElectronsBTag_fZ_ -> SetMarkerColor(4);
    gsfElectronsMultiJet_fZ_ -> Draw("same"); gsfElectronsMultiJet_fZ_ -> SetLineColor(8);
    gsfElectronsMultiJet_fZ_ -> SetMarkerStyle(41); gsfElectronsMultiJet_fZ_ -> SetMarkerColor(8);
    legend -> Draw();

  fX_Electrons -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/fX_Electrones__FastJe-PFJets.png"); fX_Electrons -> Close();
  fY_Electrons -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/fY_Electrones__FastJe-PFJets.png"); fY_Electrons -> Close();
  fZ_Electrons -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/fZ_Electrones__FastJe-PFJets.png"); fZ_Electrons -> Close();



  TCanvas* fX_Muons = new TCanvas("fX_Muons","X vertice de FastJet y PFJets para muones",10,10,1920,1080);
  fX_Muons -> SetFillColor(0);  fX_Muons -> SetFrameBorderMode(0);  gPad ->SetLogy();

    // Esto es para modificar las etiquetas del canvas.
    Muons__fX->SetTitle("Vertice en el eje X para muones; Posicion [cm]; Frecuencia");
    Muons__fX->GetXaxis()->SetLabelSize(0.05); Muons__fX->GetYaxis()->SetLabelSize(0.05);
    Muons__fX->GetXaxis()->SetTitleSize(0.05); Muons__fX->GetYaxis()->SetTitleSize(0.05);
    Muons__fX->GetXaxis()->SetTitleOffset(1.0);Muons__fX->GetYaxis()->SetTitleOffset(1.0);
    // Aqui ponemos todas las gráficas que necesitamos en el canvas.
    Muons__fX -> Draw(""); Muons__fX -> SetLineColor(1);
    Muons__fX -> SetMarkerStyle(45); Muons__fX -> SetMarkerColor(1);
    MuonsJet_fX_ -> Draw("same"); MuonsJet_fX_ -> SetLineColor(2);
    MuonsJet_fX_ -> SetMarkerStyle(41); MuonsJet_fX_ -> SetMarkerColor(2);
    MuonsBTag_fX_ -> Draw("same"); MuonsBTag_fX_ -> SetLineColor(4);
    MuonsBTag_fX_ -> SetMarkerStyle(41); MuonsBTag_fX_ -> SetMarkerColor(4);
    MuonsMultiJet_fX_ -> Draw("same"); MuonsMultiJet_fX_ -> SetLineColor(8);
    MuonsMultiJet_fX_ -> SetMarkerStyle(41); MuonsMultiJet_fX_ -> SetMarkerColor(8);
    legend -> Draw();


  TCanvas* fY_Muons = new TCanvas("fY_Muons","Y vertice de FastJet y PFJets para muones",10,10,1920,1080);
  fY_Muons -> SetFillColor(0);  fY_Muons -> SetFrameBorderMode(0);  gPad ->SetLogy();

    // Esto es para modificar las etiquetas del canvas.
    Muons__fY->SetTitle("Vertice en el eje Y para muones; Posicion [cm]; Frecuencia");
    Muons__fY->GetXaxis()->SetLabelSize(0.05); Muons__fY->GetYaxis()->SetLabelSize(0.05);
    Muons__fY->GetXaxis()->SetTitleSize(0.05); Muons__fY->GetYaxis()->SetTitleSize(0.05);
    Muons__fY->GetXaxis()->SetTitleOffset(1.0);Muons__fY->GetYaxis()->SetTitleOffset(1.0);
    // Aqui ponemos todas las gráficas que necesitamos en el canvas.
    Muons__fY -> Draw(""); Muons__fY -> SetLineColor(1);
    Muons__fY -> SetMarkerStyle(45); Muons__fY -> SetMarkerColor(1);
    MuonsJet_fY_ -> Draw("same"); MuonsJet_fY_ -> SetLineColor(2);
    MuonsJet_fY_ -> SetMarkerStyle(41); MuonsJet_fY_ -> SetMarkerColor(2);
    MuonsBTag_fY_ -> Draw("same"); MuonsBTag_fY_ -> SetLineColor(4);
    MuonsBTag_fY_ -> SetMarkerStyle(41); MuonsBTag_fY_ -> SetMarkerColor(4);
    MuonsMultiJet_fY_ -> Draw("same"); MuonsMultiJet_fY_ -> SetLineColor(8);
    MuonsMultiJet_fY_ -> SetMarkerStyle(41); MuonsMultiJet_fY_ -> SetMarkerColor(8);
    legend -> Draw();


  TCanvas* fZ_Muons = new TCanvas("fZ_Muons","X vertice de FastJet y PFJets para muones",10,10,1920,1080);
  fZ_Muons -> SetFillColor(0);  fZ_Muons -> SetFrameBorderMode(0);  gPad ->SetLogy();

    // Esto es para modificar las etiquetas del canvas.
    Muons__fZ->SetTitle("Vertice en el eje Z para muones; Posicion [cm]; Frecuencia");
    Muons__fZ->GetXaxis()->SetLabelSize(0.05); Muons__fZ->GetYaxis()->SetLabelSize(0.05);
    Muons__fZ->GetXaxis()->SetTitleSize(0.05); Muons__fZ->GetYaxis()->SetTitleSize(0.05);
    Muons__fZ->GetXaxis()->SetTitleOffset(1.0);Muons__fZ->GetYaxis()->SetTitleOffset(1.0);
    // Aqui ponemos todas las gráficas que necesitamos en el canvas.
    Muons__fZ -> Draw(""); Muons__fZ -> SetLineColor(1);
    Muons__fZ -> SetMarkerStyle(45); Muons__fZ -> SetMarkerColor(1);
    MuonsJet_fZ_ -> Draw("same"); MuonsJet_fZ_ -> SetLineColor(2);
    MuonsJet_fZ_ -> SetMarkerStyle(41); MuonsJet_fZ_ -> SetMarkerColor(2);
    MuonsBTag_fZ_ -> Draw("same"); MuonsBTag_fZ_ -> SetLineColor(4);
    MuonsBTag_fZ_ -> SetMarkerStyle(41); MuonsBTag_fZ_ -> SetMarkerColor(4);
    MuonsMultiJet_fZ_ -> Draw("same"); MuonsMultiJet_fZ_ -> SetLineColor(8);
    MuonsMultiJet_fZ_ -> SetMarkerStyle(41); MuonsMultiJet_fZ_ -> SetMarkerColor(8);
    legend -> Draw();

  fX_Muons -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/fX_Muones__FastJet-PFJets.png"); fX_Muons -> Close();
  fY_Muons -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/fY_Muones__FastJet-PFJets.png"); fY_Muons -> Close();
  fZ_Muons -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/fZ_Muones__FastJet-PFJets.png"); fZ_Muons -> Close();


}

//################################################################################################################

void rootMacro(){
  // Le damos algo de personalización al las gráficas.
  gROOT->ForceStyle();
  gStyle -> SetPadBorderMode(0);    gStyle -> SetPadBorderSize(0);
  gStyle -> SetPadTopMargin(0.08);  gStyle -> SetPadBottomMargin(0.12);
  gStyle -> SetPadLeftMargin(0.10); gStyle -> SetPadRightMargin(0.10);
  gStyle -> SetOptStat(0);          gStyle -> SetOptTitle(1);


  // Corremos los macros que nos interesan.
  // DistanciaAngular();
  pT();
  // Multiplicidad();
  Vertice();

}
