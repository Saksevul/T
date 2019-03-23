void rootMacro(){
  // Le damos algo de personalización al las gráficas.
  gROOT->ForceStyle();
    gStyle -> SetPadBorderMode(0);    gStyle -> SetPadBorderSize(0);
    gStyle -> SetPadTopMargin(0.08);  gStyle -> SetPadBottomMargin(0.12);
    gStyle -> SetPadLeftMargin(0.10); gStyle -> SetPadRightMargin(0.10);
    gStyle -> SetOptStat(0);          gStyle -> SetOptTitle(1);


  //Abrimos el archivo que nos interesa y el árbol que queremos leer.
  TFile *inFile = new TFile("/home/saksevul/T/OpenData/Jet_20000/ak5PF.root", "READ");
  TH1F *ak5PFJets__pT, *ak5PFJets__Multiplicidad, *ak5PFJets__D_Jet_Jet;
  ak5PFJets__pT =(TH1F*)inFile->Get("ak5PFJets_pt_");
  ak5PFJets__Multiplicidad =(TH1F*)inFile->Get("ak5PFJets__Multiplicidad");
  ak5PFJets__D_Jet_Jet =(TH1F*)inFile->Get("ak5PFJets__DistanciaAngular_Jet_Jet");

  TFile *inputFile = new TFile("/home/saksevul/T/FastJet/simulacion.root", "READ");
  TH1F *ak5FastJet__pT, *ak5FastJet__Multiplicidad, *ak5FastJet__D_Jet_Jet;
  ak5FastJet__pT =(TH1F*)inputFile->Get("ak5FastJet__pT");
  ak5FastJet__Multiplicidad =(TH1F*)inputFile->Get("ak5FastJet__Multiplicidad");
  ak5FastJet__D_Jet_Jet =(TH1F*)inputFile->Get("ak5FastJet__DistanciaAngular_Jet_Jet");


  //Creamos un liezo en el cual dibujarémos los histogramas sin modificar.
  TCanvas* ak5PFJet__Multiplicidad = new TCanvas("Multiplicidad","Multiplicidad de FastJet y PFJets por Evento",10,10,1920,1080);
  ak5PFJet__Multiplicidad -> SetFillColor(0);  ak5PFJet__Multiplicidad -> SetFrameBorderMode(0);  gPad ->SetLogy();

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

  //Creamos un liezo en el cual dibujarémos los histogramas sin modificar.
  TCanvas* ak5PFJet__pT = new TCanvas("pT","Espectro de pT de FastJet y PFJets",10,10,1920,1080);
  ak5PFJet__pT -> SetFillColor(0);  ak5PFJet__pT -> SetFrameBorderMode(0);  gPad ->SetLogy();

    // Esto es para modificar las etiquetas del canvas.
    ak5PFJets__pT->SetTitle("Espectro de p_{T} de Jets; p_{T} [GeV]; Probabilidad");
    ak5PFJets__pT->GetXaxis()->SetLabelSize(0.05); ak5PFJets__pT->GetYaxis()->SetLabelSize(0.05);
    ak5PFJets__pT->GetXaxis()->SetTitleSize(0.05); ak5PFJets__pT->GetYaxis()->SetTitleSize(0.05);
    ak5PFJets__pT->GetXaxis()->SetTitleOffset(1.0);ak5PFJets__pT->GetYaxis()->SetTitleOffset(1.0);
    // Aqui ponemos todas las gráficas que necesitamos en el canvas.
    ak5PFJets__pT -> Draw(""); ak5PFJets__pT -> SetLineColor(2);
    ak5PFJets__pT -> SetMarkerStyle(45); ak5PFJets__pT -> SetMarkerColor(2);
    ak5FastJet__pT -> Draw("same"); ak5FastJet__pT -> SetLineColor(4);
    ak5FastJet__pT -> SetMarkerStyle(41); ak5FastJet__pT -> SetMarkerColor(4);


  ak5PFJet__Multiplicidad -> SaveAs("/home/saksevul/T/FastJet/Multiplicidad FastJet y PFJets.pdf"); ak5PFJet__Multiplicidad -> Close();
  ak5PFJet__D_Jet_Jet     -> SaveAs("/home/saksevul/T/FastJet/D_Jet_Jet FastJet y PFJets.pdf"    ); ak5PFJet__D_Jet_Jet     -> Close();
  ak5PFJet__pT            -> SaveAs("/home/saksevul/T/FastJet/pT FastJet y PFJets.pdf"           ); ak5PFJet__pT            -> Close();


  return 0;
}
