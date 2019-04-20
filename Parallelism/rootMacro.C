void DistanciaAngular() {
  //Abrimos el archivo que nos interesa y el árbol que queremos leer.
  TFile *inFile = new TFile("/home/saksevul/T/OpenData/Jet_20000/ak5PF-0001.root", "READ");
  TFile *inputFile = new TFile("/home/saksevul/T/PYTHIA/ak5FJ.root", "READ");

  TH1F *D__Muon_ak5PFJet, *D__gsfElectron_ak5PFJet, *ak5PFJets__D_Jet_Jet,
       *D__Muon_ak5FastJet, *D__Electron_ak5FastJet, *ak5FastJet__D_Jet_Jet;

  ak5PFJets__D_Jet_Jet =(TH1F*)inFile->Get("ak5PFJets__D__Jet_Jet");
  ak5FastJet__D_Jet_Jet =(TH1F*)inputFile->Get("ak5FastJet__D__Jet_Jet");


    auto   legend = new TLegend(0.75,0.80,0.90,0.92);
      legend->SetTextSize(0.04);
      legend->AddEntry(ak5PFJets__D_Jet_Jet, "PFJets", "lp");
      legend->AddEntry(ak5FastJet__D_Jet_Jet, "FastJet", "lp");


  //Creamos un liezo en el cual dibujarémos los histogramas sin modificar.
  TCanvas* ak5PFJet__D_Jet_Jet = new TCanvas("DistanciaAngular","Distancia Angular de FastJet y PFJets por Evento",10,10,1920,1080);
  ak5PFJet__D_Jet_Jet -> SetFillColor(0);  ak5PFJet__D_Jet_Jet -> SetFrameBorderMode(0);  gPad ->SetLogy();

  // Esto es para modificar las etiquetas del canvas.
  ak5PFJets__D_Jet_Jet->SetTitle("Distancia Angular entre los Jets de cada Evento; Distancia Angular; Probabilidad");
  ak5PFJets__D_Jet_Jet->GetXaxis()->SetLabelSize(0.05); ak5PFJets__D_Jet_Jet->GetYaxis()->SetLabelSize(0.05);
  ak5PFJets__D_Jet_Jet->GetXaxis()->SetTitleSize(0.05); ak5PFJets__D_Jet_Jet->GetYaxis()->SetTitleSize(0.05);
  ak5PFJets__D_Jet_Jet->GetXaxis()->SetTitleOffset(1.0);ak5PFJets__D_Jet_Jet->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  ak5PFJets__D_Jet_Jet -> Draw(""); ak5PFJets__D_Jet_Jet -> SetLineColor(2);
  ak5PFJets__D_Jet_Jet -> SetMarkerStyle(45); ak5PFJets__D_Jet_Jet -> SetMarkerColor(2);
  ak5FastJet__D_Jet_Jet -> Draw("same"); ak5FastJet__D_Jet_Jet -> SetLineColor(4);
  ak5FastJet__D_Jet_Jet -> SetMarkerStyle(41); ak5FastJet__D_Jet_Jet -> SetMarkerColor(4);
  legend -> Draw();

  ak5PFJet__D_Jet_Jet     -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/D_Jet_Jet FastJet y PFJets.png"    ); ak5PFJet__D_Jet_Jet     -> Close();

}

//################################################################################################################

void Multiplicidad() {
  //Abrimos el archivo que nos interesa y el árbol que queremos leer.
  TFile *inFile = new TFile("/home/saksevul/T/OpenData/Jet_20000/ak5PF-0001.root", "READ");
  TFile *inputFile = new TFile("/home/saksevul/T/PYTHIA/ak5FJ.root", "READ");

  TH1F *ak5PFJets__Multiplicidad,
       *ak5FastJet__Multiplicidad;

  ak5PFJets__Multiplicidad =(TH1F*)inFile->Get("ak5PFJets__Multiplicidad");
  ak5FastJet__Multiplicidad =(TH1F*)inputFile->Get("ak5FastJet__Multiplicidad");


    auto   legend = new TLegend(0.75,0.80,0.90,0.92);
      legend->SetTextSize(0.04);
      legend->AddEntry(ak5PFJets__Multiplicidad, "PFJets", "lp");
      legend->AddEntry(ak5FastJet__Multiplicidad, "FastJet", "lp");


  //Creamos un liezo en el cual dibujarémos los histogramas sin modificar.
  TCanvas* Espectro_Multiplicidad__Jets = new TCanvas("Multiplicidad de Jets","Multiplicidad de FastJet y PFJets por Evento",10,10,1920,1080);
  Espectro_Multiplicidad__Jets -> SetFillColor(0);  Espectro_Multiplicidad__Jets -> SetFrameBorderMode(0);  gPad ->SetLogy();

    // Esto es para modificar las etiquetas del canvas.
    ak5PFJets__Multiplicidad->SetTitle("Multiplicidad de Jets por Evento; Numero de Jets; Probabilidad");
    ak5PFJets__Multiplicidad->GetXaxis()->SetLabelSize(0.05); ak5PFJets__Multiplicidad->GetYaxis()->SetLabelSize(0.05);
    ak5PFJets__Multiplicidad->GetXaxis()->SetTitleSize(0.05); ak5PFJets__Multiplicidad->GetYaxis()->SetTitleSize(0.05);
    ak5PFJets__Multiplicidad->GetXaxis()->SetTitleOffset(1.0);ak5PFJets__Multiplicidad->GetYaxis()->SetTitleOffset(1.0);
    // Aqui ponemos todas las gráficas que necesitamos en el canvas.
    ak5PFJets__Multiplicidad -> Draw(""); ak5PFJets__Multiplicidad -> SetLineColor(2);
    ak5PFJets__Multiplicidad -> SetMarkerStyle(45); ak5PFJets__Multiplicidad -> SetMarkerColor(2);
    ak5FastJet__Multiplicidad -> Draw("same"); ak5FastJet__Multiplicidad -> SetLineColor(4);
    ak5FastJet__Multiplicidad -> SetMarkerStyle(41); ak5FastJet__Multiplicidad -> SetMarkerColor(4);
    legend -> Draw();

  Espectro_Multiplicidad__Jets -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Multiplicidad__FastJet_PFJets.png"); Espectro_Multiplicidad__Jets -> Close();

}

//################################################################################################################

void pT() {
  //Abrimos el archivo que nos interesa y el árbol que queremos leer.
  TFile *inFile = new TFile("/home/saksevul/T/OpenData/Jet_20000/ak5PF-0001.root", "READ");
  TFile *inputFile = new TFile("/home/saksevul/T/PYTHIA/ak5FJ.root", "READ");

  TH1F *Muons_pt_, *gsfElectrons_pt_, *ak5PFJets_pt_,
       *Muons__pT, *Electrons__pT, *ak5FastJet__pT,
       *Cociente_pT__gsfElectron_ak5PFJet, *Cociente_pT__Muon_ak5PFJet,
       *Cociente_pT__Electron_ak5FastJet, *Cociente_pT__Muon_ak5FastJet;

  ak5PFJets_pt_ =(TH1F*)inFile->Get("ak5PFJets_pt_");
  ak5FastJet__pT =(TH1F*)inputFile->Get("ak5FastJet__pT");

  Cociente_pT__gsfElectron_ak5PFJet =(TH1F*)inFile->Get("Cociente_pT__gsfElectron-ak5PFJet");
  Cociente_pT__Electron_ak5FastJet =(TH1F*)inputFile->Get("Cociente_pT__Electron-ak5FastJet");

  Cociente_pT__Muon_ak5PFJet =(TH1F*)inFile->Get("Cociente_pT__Muon-ak5PFJet");
  Cociente_pT__Muon_ak5FastJet =(TH1F*)inputFile->Get("Cociente_pT__Muon-ak5FastJet");


  auto   legend = new TLegend(0.75,0.80,0.90,0.92);
    legend->SetTextSize(0.04);
    legend->AddEntry(Cociente_pT__gsfElectron_ak5PFJet, "PFJets", "lp");
    legend->AddEntry(Cociente_pT__Electron_ak5FastJet, "FastJet", "lp");


  //Creamos un liezo en el cual dibujarémos los histogramas sin modificar.
  TCanvas* Espectro_pT__Jets = new TCanvas("pT","Espectro de pT de FastJet y PFJets",10,10,1920,1080);
  Espectro_pT__Jets -> SetFillColor(0);  Espectro_pT__Jets -> SetFrameBorderMode(0);  gPad ->SetLogy();

  // Esto es para modificar las etiquetas del canvas.
  ak5PFJets_pt_->SetTitle("Espectro de p_{T} de Jets; p_{T} [GeV]; Probabilidad");
  ak5PFJets_pt_->GetXaxis()->SetLabelSize(0.05); ak5PFJets_pt_->GetYaxis()->SetLabelSize(0.05);
  ak5PFJets_pt_->GetXaxis()->SetTitleSize(0.05); ak5PFJets_pt_->GetYaxis()->SetTitleSize(0.05);
  ak5PFJets_pt_->GetXaxis()->SetTitleOffset(1.0);ak5PFJets_pt_->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  ak5PFJets_pt_ -> Draw(""); ak5PFJets_pt_ -> SetLineColor(2);
  ak5PFJets_pt_ -> SetMarkerStyle(45); ak5PFJets_pt_ -> SetMarkerColor(2);
  ak5FastJet__pT -> Draw("same"); ak5FastJet__pT -> SetLineColor(4);
  ak5FastJet__pT -> SetMarkerStyle(41); ak5FastJet__pT -> SetMarkerColor(4);
  legend -> Draw();


  TCanvas* Cociente_pT__Electron_Jet = new TCanvas("Cociente_pT__Electron_Jet","Cociente pT FastJet y PFJets para electrones",10,10,1920,1080);
  Cociente_pT__Electron_Jet -> SetFillColor(0);  Cociente_pT__Electron_Jet -> SetFrameBorderMode(0);  gPad ->SetLogy();

  // Esto es para modificar las etiquetas del canvas.
  Cociente_pT__gsfElectron_ak5PFJet->SetTitle("Cociente pT para electrones; Cociente; Frecuencia");
  Cociente_pT__gsfElectron_ak5PFJet->GetXaxis()->SetLabelSize(0.05); Cociente_pT__gsfElectron_ak5PFJet->GetYaxis()->SetLabelSize(0.05);
  Cociente_pT__gsfElectron_ak5PFJet->GetXaxis()->SetTitleSize(0.05); Cociente_pT__gsfElectron_ak5PFJet->GetYaxis()->SetTitleSize(0.05);
  Cociente_pT__gsfElectron_ak5PFJet->GetXaxis()->SetTitleOffset(1.0);Cociente_pT__gsfElectron_ak5PFJet->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Cociente_pT__gsfElectron_ak5PFJet -> Draw(""); Cociente_pT__gsfElectron_ak5PFJet -> SetLineColor(2);
  Cociente_pT__gsfElectron_ak5PFJet -> SetMarkerStyle(45); Cociente_pT__gsfElectron_ak5PFJet -> SetMarkerColor(2);
  Cociente_pT__Electron_ak5FastJet -> Draw("same"); Cociente_pT__Electron_ak5FastJet -> SetLineColor(4);
  Cociente_pT__Electron_ak5FastJet -> SetMarkerStyle(41); Cociente_pT__Electron_ak5FastJet -> SetMarkerColor(4);
  legend -> Draw();


  TCanvas* Cociente_pT__Muon_Jet = new TCanvas("Cociente_pT__Muon_Jet","Cociente pT FastJet y PFJets para muones",10,10,1920,1080);
  Cociente_pT__Muon_Jet -> SetFillColor(0);  Cociente_pT__Muon_Jet -> SetFrameBorderMode(0);  gPad ->SetLogy();

  // Esto es para modificar las etiquetas del canvas.
  Cociente_pT__Muon_ak5PFJet->SetTitle("Cociente pT para muones; Cociente; Frecuencia");
  Cociente_pT__Muon_ak5PFJet->GetXaxis()->SetLabelSize(0.05); Cociente_pT__Muon_ak5PFJet->GetYaxis()->SetLabelSize(0.05);
  Cociente_pT__Muon_ak5PFJet->GetXaxis()->SetTitleSize(0.05); Cociente_pT__Muon_ak5PFJet->GetYaxis()->SetTitleSize(0.05);
  Cociente_pT__Muon_ak5PFJet->GetXaxis()->SetTitleOffset(1.0);Cociente_pT__Muon_ak5PFJet->GetYaxis()->SetTitleOffset(1.0);
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  Cociente_pT__Muon_ak5PFJet -> Draw(""); Cociente_pT__Muon_ak5PFJet -> SetLineColor(2);
  Cociente_pT__Muon_ak5PFJet -> SetMarkerStyle(45); Cociente_pT__Muon_ak5PFJet -> SetMarkerColor(2);
  Cociente_pT__Electron_ak5FastJet -> Draw("same"); Cociente_pT__Electron_ak5FastJet -> SetLineColor(4);
  Cociente_pT__Electron_ak5FastJet -> SetMarkerStyle(41); Cociente_pT__Electron_ak5FastJet -> SetMarkerColor(4);
  legend -> Draw();


  Espectro_pT__Jets -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/pT__FastJet_PFJets.png"); Espectro_pT__Jets -> Close();
  Cociente_pT__Electron_Jet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT__Electron_Jet.png"); Cociente_pT__Electron_Jet -> Close();
  Cociente_pT__Muon_Jet -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/Cociente_pT__Muon_Jet.png"); Cociente_pT__Muon_Jet -> Close();

}

//################################################################################################################

void Vertice() {
  //Abrimos el archivo que nos interesa y el árbol que queremos leer.
  TFile *inFile = new TFile("/home/saksevul/T/OpenData/Jet_20000/ak5PF-0001.root", "READ");
  TFile *inputFile = new TFile("/home/saksevul/T/PYTHIA/ak5FJ.root", "READ");

  TH1F  *Muons_fX_, *Muons_fY_, *Muons_fZ_,
        *Muons__fX, *Muons__fY, *Muons__fZ,
        *gsfElectrons_fX_, *gsfElectrons_fY_, *gsfElectrons_fZ_,
        *Electrons__fX, *Electrons__fY, *Electrons__fZ;

  Muons_fX_ =(TH1F*)inFile->Get("Muons_fX_");
  Muons__fX =(TH1F*)inputFile->Get("Muons__fX");
  Muons_fY_ =(TH1F*)inFile->Get("Muons_fY_");
  Muons__fY =(TH1F*)inputFile->Get("Muons__fY");
  Muons_fZ_ =(TH1F*)inFile->Get("Muons_fZ_");
  Muons__fZ =(TH1F*)inputFile->Get("Muons__fZ");

  gsfElectrons_fX_ =(TH1F*)inFile->Get("gsfElectrons_fX_");
  Electrons__fX =(TH1F*)inputFile->Get("Electrons__fX");
  gsfElectrons_fY_ =(TH1F*)inFile->Get("gsfElectrons_fY_");
  Electrons__fY =(TH1F*)inputFile->Get("Electrons__fY");
  gsfElectrons_fZ_ =(TH1F*)inFile->Get("gsfElectrons_fZ_");
  Electrons__fZ =(TH1F*)inputFile->Get("Electrons__fZ");


  auto   legend = new TLegend(0.75,0.80,0.90,0.92);
    legend->SetTextSize(0.04);
      legend->AddEntry(gsfElectrons_fX_, "PFJets", "lp");
      legend->AddEntry(Electrons__fX, "FastJet", "lp");


  TCanvas* fX_Electrons = new TCanvas("fX_Electrons","X vertice de FastJet y PFJets para electrones",10,10,1920,1080);
  fX_Electrons -> SetFillColor(0);  fX_Electrons -> SetFrameBorderMode(0);  gPad ->SetLogy();

    // Esto es para modificar las etiquetas del canvas.
    gsfElectrons_fX_->SetTitle("Vertice en el eje X para electrones; Posicion [cm]; Frecuencia");
    gsfElectrons_fX_->GetXaxis()->SetLabelSize(0.05); gsfElectrons_fX_->GetYaxis()->SetLabelSize(0.05);
    gsfElectrons_fX_->GetXaxis()->SetTitleSize(0.05); gsfElectrons_fX_->GetYaxis()->SetTitleSize(0.05);
    gsfElectrons_fX_->GetXaxis()->SetTitleOffset(1.0);gsfElectrons_fX_->GetYaxis()->SetTitleOffset(1.0);
    // Aqui ponemos todas las gráficas que necesitamos en el canvas.
    gsfElectrons_fX_ -> Draw(""); gsfElectrons_fX_ -> SetLineColor(2);
    gsfElectrons_fX_ -> SetMarkerStyle(45); gsfElectrons_fX_ -> SetMarkerColor(2);
    Electrons__fX -> Draw("same"); Electrons__fX -> SetLineColor(4);
    Electrons__fX -> SetMarkerStyle(41); Electrons__fX -> SetMarkerColor(4);
    legend -> Draw();


  TCanvas* fY_Electrons = new TCanvas("fY_Electrons","Y vertice de FastJet y PFJets para electrones",10,10,1920,1080);
  fY_Electrons -> SetFillColor(0);  fY_Electrons -> SetFrameBorderMode(0);  gPad ->SetLogy();

    // Esto es para modificar las etiquetas del canvas.
    gsfElectrons_fY_->SetTitle("Vertice en el eje Y para electrones; Posicion [cm]; Frecuencia");
    gsfElectrons_fY_->GetXaxis()->SetLabelSize(0.05); gsfElectrons_fY_->GetYaxis()->SetLabelSize(0.05);
    gsfElectrons_fY_->GetXaxis()->SetTitleSize(0.05); gsfElectrons_fY_->GetYaxis()->SetTitleSize(0.05);
    gsfElectrons_fY_->GetXaxis()->SetTitleOffset(1.0);gsfElectrons_fY_->GetYaxis()->SetTitleOffset(1.0);
    // Aqui ponemos todas las gráficas que necesitamos en el canvas.
    gsfElectrons_fY_ -> Draw(""); gsfElectrons_fY_ -> SetLineColor(2);
    gsfElectrons_fY_ -> SetMarkerStyle(45); gsfElectrons_fY_ -> SetMarkerColor(2);
    Electrons__fY -> Draw("same"); Electrons__fY -> SetLineColor(4);
    Electrons__fY -> SetMarkerStyle(41); Electrons__fY -> SetMarkerColor(4);
    legend -> Draw();


  TCanvas* fZ_Electrons = new TCanvas("fZ_Electrons","X vertice de FastJet y PFJets para electrones",10,10,1920,1080);
  fZ_Electrons -> SetFillColor(0);  fZ_Electrons -> SetFrameBorderMode(0);  gPad ->SetLogy();

    // Esto es para modificar las etiquetas del canvas.
    gsfElectrons_fZ_->SetTitle("Vertice en el eje Z para electrones; Posicion [cm]; Frecuencia");
    gsfElectrons_fZ_->GetXaxis()->SetLabelSize(0.05); gsfElectrons_fZ_->GetYaxis()->SetLabelSize(0.05);
    gsfElectrons_fZ_->GetXaxis()->SetTitleSize(0.05); gsfElectrons_fZ_->GetYaxis()->SetTitleSize(0.05);
    gsfElectrons_fZ_->GetXaxis()->SetTitleOffset(1.0);gsfElectrons_fZ_->GetYaxis()->SetTitleOffset(1.0);
    // Aqui ponemos todas las gráficas que necesitamos en el canvas.
    gsfElectrons_fZ_ -> Draw(""); gsfElectrons_fZ_ -> SetLineColor(2);
    gsfElectrons_fZ_ -> SetMarkerStyle(45); gsfElectrons_fZ_ -> SetMarkerColor(2);
    Electrons__fZ -> Draw("same"); Electrons__fZ -> SetLineColor(4);
    Electrons__fZ -> SetMarkerStyle(41); Electrons__fZ -> SetMarkerColor(4);
    legend -> Draw();

  fX_Electrons -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/fX_Electrones__FastJe-PFJets.png"); fX_Electrons -> Close();
  fY_Electrons -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/fY_Electrones__FastJe-PFJets.png"); fY_Electrons -> Close();
  fZ_Electrons -> SaveAs("/home/saksevul/T/Parallelism/Comparisons/fZ_Electrones__FastJe-PFJets.png"); fZ_Electrons -> Close();



  TCanvas* fX_Muons = new TCanvas("fX_Muons","X vertice de FastJet y PFJets para muones",10,10,1920,1080);
  fX_Muons -> SetFillColor(0);  fX_Muons -> SetFrameBorderMode(0);  gPad ->SetLogy();

    // Esto es para modificar las etiquetas del canvas.
    Muons_fX_->SetTitle("Vertice en el eje X para muones; Posicion [cm]; Frecuencia");
    Muons_fX_->GetXaxis()->SetLabelSize(0.05); Muons_fX_->GetYaxis()->SetLabelSize(0.05);
    Muons_fX_->GetXaxis()->SetTitleSize(0.05); Muons_fX_->GetYaxis()->SetTitleSize(0.05);
    Muons_fX_->GetXaxis()->SetTitleOffset(1.0);Muons_fX_->GetYaxis()->SetTitleOffset(1.0);
    // Aqui ponemos todas las gráficas que necesitamos en el canvas.
    Muons_fX_ -> Draw(""); Muons_fX_ -> SetLineColor(2);
    Muons_fX_ -> SetMarkerStyle(45); Muons_fX_ -> SetMarkerColor(2);
    Muons__fX -> Draw("same"); Muons__fX -> SetLineColor(4);
    Muons__fX -> SetMarkerStyle(41); Muons__fX -> SetMarkerColor(4);
    legend -> Draw();


  TCanvas* fY_Muons = new TCanvas("fY_Muons","Y vertice de FastJet y PFJets para muones",10,10,1920,1080);
  fY_Muons -> SetFillColor(0);  fY_Muons -> SetFrameBorderMode(0);  gPad ->SetLogy();

    // Esto es para modificar las etiquetas del canvas.
    Muons_fY_->SetTitle("Vertice en el eje Y para muones; Posicion [cm]; Frecuencia");
    Muons_fY_->GetXaxis()->SetLabelSize(0.05); Muons_fY_->GetYaxis()->SetLabelSize(0.05);
    Muons_fY_->GetXaxis()->SetTitleSize(0.05); Muons_fY_->GetYaxis()->SetTitleSize(0.05);
    Muons_fY_->GetXaxis()->SetTitleOffset(1.0);Muons_fY_->GetYaxis()->SetTitleOffset(1.0);
    // Aqui ponemos todas las gráficas que necesitamos en el canvas.
    Muons_fY_ -> Draw(""); Muons_fY_ -> SetLineColor(2);
    Muons_fY_ -> SetMarkerStyle(45); Muons_fY_ -> SetMarkerColor(2);
    Muons__fY -> Draw("same"); Muons__fY -> SetLineColor(4);
    Muons__fY -> SetMarkerStyle(41); Muons__fY -> SetMarkerColor(4);
    legend -> Draw();


  TCanvas* fZ_Muons = new TCanvas("fZ_Muons","X vertice de FastJet y PFJets para muones",10,10,1920,1080);
  fZ_Muons -> SetFillColor(0);  fZ_Muons -> SetFrameBorderMode(0);  gPad ->SetLogy();

    // Esto es para modificar las etiquetas del canvas.
    Muons_fZ_->SetTitle("Vertice en el eje Z para muones; Posicion [cm]; Frecuencia");
    Muons_fZ_->GetXaxis()->SetLabelSize(0.05); Muons_fZ_->GetYaxis()->SetLabelSize(0.05);
    Muons_fZ_->GetXaxis()->SetTitleSize(0.05); Muons_fZ_->GetYaxis()->SetTitleSize(0.05);
    Muons_fZ_->GetXaxis()->SetTitleOffset(1.0);Muons_fZ_->GetYaxis()->SetTitleOffset(1.0);
    // Aqui ponemos todas las gráficas que necesitamos en el canvas.
    Muons_fZ_ -> Draw(""); Muons_fZ_ -> SetLineColor(2);
    Muons_fZ_ -> SetMarkerStyle(45); Muons_fZ_ -> SetMarkerColor(2);
    Muons__fZ -> Draw("same"); Muons__fZ -> SetLineColor(4);
    Muons__fZ -> SetMarkerStyle(41); Muons__fZ -> SetMarkerColor(4);
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
