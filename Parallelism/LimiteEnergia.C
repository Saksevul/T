void LimiteEnergia() {
  // Le damos algo de personalización al las gráficas.
  gROOT->ForceStyle();
  gStyle->SetPadBorderMode(0);    gStyle->SetPadBorderSize(0);
  gStyle->SetPadTopMargin(0.082);  gStyle->SetPadBottomMargin(0.12);
  gStyle->SetPadLeftMargin(0.10); gStyle->SetPadRightMargin(0.02);
  gStyle->SetOptStat(0);          gStyle->SetOptTitle(1);

  //Abrimos el archivo que nos interesa y el árbol que queremos leer.
  TFile *ak5File = new TFile("/home/saksevul/T/OpenData/BTag_20000/ak5PF_Limits.root");
  TFile *ak7File = new TFile("/home/saksevul/T/OpenData/BTag_20000/ak7PF_Limits.root");
  TFile *kt4File = new TFile("/home/saksevul/T/OpenData/BTag_20000/kt4PF_Limits.root");
  TFile *kt6File = new TFile("/home/saksevul/T/OpenData/BTag_20000/kt6PF_Limits.root");


  TH1F *ak5_MuonEnergy =(TH1F*)ak5File->Get("Jets_1MuonEnergy"); ak5_MuonEnergy->Scale(1.0/ak5_MuonEnergy->Integral());
  TH1F *ak7_MuonEnergy =(TH1F*)ak7File->Get("Jets_1MuonEnergy"); ak7_MuonEnergy->Scale(1.0/ak7_MuonEnergy->Integral());
  TH1F *kt4_MuonEnergy =(TH1F*)kt4File->Get("Jets_1MuonEnergy"); kt4_MuonEnergy->Scale(1.0/kt4_MuonEnergy->Integral());
  TH1F *kt6_MuonEnergy =(TH1F*)kt6File->Get("Jets_1MuonEnergy"); kt6_MuonEnergy->Scale(1.0/kt6_MuonEnergy->Integral());

  TH1F *ak5_PhotonEnergy =(TH1F*)ak5File->Get("Jets_1PhotonEnergy"); ak5_PhotonEnergy->Scale(1.0/ak5_PhotonEnergy->Integral());
  TH1F *ak7_PhotonEnergy =(TH1F*)ak7File->Get("Jets_1PhotonEnergy"); ak7_PhotonEnergy->Scale(1.0/ak7_PhotonEnergy->Integral());
  TH1F *kt4_PhotonEnergy =(TH1F*)kt4File->Get("Jets_1PhotonEnergy"); kt4_PhotonEnergy->Scale(1.0/kt4_PhotonEnergy->Integral());
  TH1F *kt6_PhotonEnergy =(TH1F*)kt6File->Get("Jets_1PhotonEnergy"); kt6_PhotonEnergy->Scale(1.0/kt6_PhotonEnergy->Integral());

  TH1F *ak5_ElectronEnergy =(TH1F*)ak5File->Get("Jets_1ElectronEnergy"); ak5_ElectronEnergy->Scale(1.0/ak5_ElectronEnergy->Integral());
  TH1F *ak7_ElectronEnergy =(TH1F*)ak7File->Get("Jets_1ElectronEnergy"); ak7_ElectronEnergy->Scale(1.0/ak7_ElectronEnergy->Integral());
  TH1F *kt4_ElectronEnergy =(TH1F*)kt4File->Get("Jets_1ElectronEnergy"); kt4_ElectronEnergy->Scale(1.0/kt4_ElectronEnergy->Integral());
  TH1F *kt6_ElectronEnergy =(TH1F*)kt6File->Get("Jets_1ElectronEnergy"); kt6_ElectronEnergy->Scale(1.0/kt6_ElectronEnergy->Integral());

  TH1F *ak5_NeuHadronEnergy =(TH1F*)ak5File->Get("Jets_1NeutralHadronEnergy"); ak5_NeuHadronEnergy->Scale(1.0/ak5_NeuHadronEnergy->Integral());
  TH1F *ak7_NeuHadronEnergy =(TH1F*)ak7File->Get("Jets_1NeutralHadronEnergy"); ak7_NeuHadronEnergy->Scale(1.0/ak7_NeuHadronEnergy->Integral());
  TH1F *kt4_NeuHadronEnergy =(TH1F*)kt4File->Get("Jets_1NeutralHadronEnergy"); kt4_NeuHadronEnergy->Scale(1.0/kt4_NeuHadronEnergy->Integral());
  TH1F *kt6_NeuHadronEnergy =(TH1F*)kt6File->Get("Jets_1NeutralHadronEnergy"); kt6_NeuHadronEnergy->Scale(1.0/kt6_NeuHadronEnergy->Integral());

  TH1F *ak5_CharHadronEnergy =(TH1F*)ak5File->Get("Jets_1ChargedHadronEnergy"); ak5_CharHadronEnergy->Scale(1.0/ak5_CharHadronEnergy->Integral());
  TH1F *ak7_CharHadronEnergy =(TH1F*)ak7File->Get("Jets_1ChargedHadronEnergy"); ak7_CharHadronEnergy->Scale(1.0/ak7_CharHadronEnergy->Integral());
  TH1F *kt4_CharHadronEnergy =(TH1F*)kt4File->Get("Jets_1ChargedHadronEnergy"); kt4_CharHadronEnergy->Scale(1.0/kt4_CharHadronEnergy->Integral());
  TH1F *kt6_CharHadronEnergy =(TH1F*)kt6File->Get("Jets_1ChargedHadronEnergy"); kt6_CharHadronEnergy->Scale(1.0/kt6_CharHadronEnergy->Integral());


  auto   Legend = new TLegend(0.63,0.68,0.90,0.92);    Legend->SetTextSize(0.04); Legend->SetFillStyle(0); Legend->SetBorderSize(0);
    Legend->AddEntry(ak5_MuonEnergy, "ak5PFJets", "l");
    Legend->AddEntry(ak7_MuonEnergy, "ak7PFJets", "l");
    Legend->AddEntry(kt4_MuonEnergy, "kt4PFJets", "l");
    Legend->AddEntry(kt6_MuonEnergy, "kt6PFJets", "l");


  TCanvas* Lim_BTag_Energia_Muones = new TCanvas("Lim_BTag_Energia_Muones","Lim_BTag_Energia_Muones",10,10,1920,1080);
  Lim_BTag_Energia_Muones->SetFillColor(0);  Lim_BTag_Energia_Muones->SetFrameBorderMode(0);  gPad->SetLogy(); gPad->SetGrid(1,1);
  // Esto es para modificar las etiquetas del canvas.
  ak5_MuonEnergy->SetTitle("Espectro de Energ#acute{i}a para Muones en AODs BTag_; E [GeV]; U. A.");
  ak5_MuonEnergy->GetXaxis()->SetLabelSize(0.05); ak5_MuonEnergy->GetYaxis()->SetLabelSize(0.05);
  ak5_MuonEnergy->GetXaxis()->SetTitleSize(0.05); ak5_MuonEnergy->GetYaxis()->SetTitleSize(0.05);
  ak5_MuonEnergy->GetXaxis()->SetTitleOffset(1.0);ak5_MuonEnergy->GetYaxis()->SetTitleOffset(1.0);
  ak5_MuonEnergy->SetAxisRange(0.0, 8.0, "X");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  ak5_MuonEnergy -> Draw("HIST"); ak5_MuonEnergy->SetLineColor(2); ak5_MuonEnergy->SetLineWidth(3);
  ak5_MuonEnergy->SetMarkerStyle(20); ak5_MuonEnergy->SetMarkerColor(2); ak5_MuonEnergy->SetMarkerSize(2);
  ak7_MuonEnergy -> Draw("HISTsame"); ak7_MuonEnergy->SetLineColor(4); ak7_MuonEnergy->SetLineWidth(3);
  ak7_MuonEnergy->SetMarkerStyle(23); ak7_MuonEnergy->SetMarkerColor(4); ak7_MuonEnergy->SetMarkerSize(2);
  kt4_MuonEnergy -> Draw("HISTsame"); kt4_MuonEnergy->SetLineColor(41); kt4_MuonEnergy->SetLineWidth(3);
  kt4_MuonEnergy->SetMarkerStyle(23); kt4_MuonEnergy->SetMarkerColor(41); kt4_MuonEnergy->SetMarkerSize(2);
  kt6_MuonEnergy -> Draw("HISTsame"); kt6_MuonEnergy->SetLineColor(32); kt6_MuonEnergy->SetLineWidth(3);
  kt6_MuonEnergy->SetMarkerStyle(23); kt6_MuonEnergy->SetMarkerColor(32); kt6_MuonEnergy->SetMarkerSize(2);
  Legend->Draw(); Lim_BTag_Energia_Muones->SaveAs("/home/saksevul/T/Parallelism/Comparisons/Lim_BTag_Energia_Muones.pdf");
  Lim_BTag_Energia_Muones->SaveAs("/home/saksevul/T/Parallelism/Comparisons/Lim_BTag_Energia_Muones.png"); Lim_BTag_Energia_Muones->Close();

  TCanvas* Lim_BTag_Energia_Fotones = new TCanvas("Lim_BTag_Energia_Fotones","Lim_BTag_Energia_Fotones",10,10,1920,1080);
  Lim_BTag_Energia_Fotones->SetFillColor(0);  Lim_BTag_Energia_Fotones->SetFrameBorderMode(0);  gPad->SetLogy(); gPad->SetGrid(1,1);
  // Esto es para modificar las etiquetas del canvas.
  ak5_PhotonEnergy->SetTitle("Espectro de Energ#acute{i}a para Fotones en AODs BTag_; E [GeV]; U. A.");
  ak5_PhotonEnergy->GetXaxis()->SetLabelSize(0.05); ak5_PhotonEnergy->GetYaxis()->SetLabelSize(0.05);
  ak5_PhotonEnergy->GetXaxis()->SetTitleSize(0.05); ak5_PhotonEnergy->GetYaxis()->SetTitleSize(0.05);
  ak5_PhotonEnergy->GetXaxis()->SetTitleOffset(1.0);ak5_PhotonEnergy->GetYaxis()->SetTitleOffset(1.0);
  ak5_PhotonEnergy->SetAxisRange(0.0, 2.0, "X");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  ak5_PhotonEnergy -> Draw("HIST"); ak5_PhotonEnergy->SetLineColor(2); ak5_PhotonEnergy->SetLineWidth(3);
  ak5_PhotonEnergy->SetMarkerStyle(20); ak5_PhotonEnergy->SetMarkerColor(2); ak5_PhotonEnergy->SetMarkerSize(2);
  ak7_PhotonEnergy -> Draw("HISTsame"); ak7_PhotonEnergy->SetLineColor(4); ak7_PhotonEnergy->SetLineWidth(3);
  ak7_PhotonEnergy->SetMarkerStyle(23); ak7_PhotonEnergy->SetMarkerColor(4); ak7_PhotonEnergy->SetMarkerSize(2);
  kt4_PhotonEnergy -> Draw("HISTsame"); kt4_PhotonEnergy->SetLineColor(41); kt4_PhotonEnergy->SetLineWidth(3);
  kt4_PhotonEnergy->SetMarkerStyle(23); kt4_PhotonEnergy->SetMarkerColor(41); kt4_PhotonEnergy->SetMarkerSize(2);
  kt6_PhotonEnergy -> Draw("HISTsame"); kt6_PhotonEnergy->SetLineColor(32); kt6_PhotonEnergy->SetLineWidth(3);
  kt6_PhotonEnergy->SetMarkerStyle(23); kt6_PhotonEnergy->SetMarkerColor(32); kt6_PhotonEnergy->SetMarkerSize(2);
  Legend->Draw(); Lim_BTag_Energia_Fotones->SaveAs("/home/saksevul/T/Parallelism/Comparisons/Lim_BTag_Energia_Fotones.pdf");
  Lim_BTag_Energia_Fotones->SaveAs("/home/saksevul/T/Parallelism/Comparisons/Lim_BTag_Energia_Fotones.png"); Lim_BTag_Energia_Fotones->Close();

  TCanvas* Lim_BTag_Energia_Electrones = new TCanvas("Lim_BTag_Energia_Electrones","Lim_BTag_Energia_Electrones",10,10,1920,1080);
  Lim_BTag_Energia_Electrones->SetFillColor(0);  Lim_BTag_Energia_Electrones->SetFrameBorderMode(0);  gPad->SetLogy(); gPad->SetGrid(1,1);
  // Esto es para modificar las etiquetas del canvas.
  ak5_ElectronEnergy->SetTitle("Espectro de Energ#acute{i}a para Electrones en AODs BTag_; E [GeV]; U. A.");
  ak5_ElectronEnergy->GetXaxis()->SetLabelSize(0.05); ak5_ElectronEnergy->GetYaxis()->SetLabelSize(0.05);
  ak5_ElectronEnergy->GetXaxis()->SetTitleSize(0.05); ak5_ElectronEnergy->GetYaxis()->SetTitleSize(0.05);
  ak5_ElectronEnergy->GetXaxis()->SetTitleOffset(1.0);ak5_ElectronEnergy->GetYaxis()->SetTitleOffset(1.0);
  ak5_ElectronEnergy->SetAxisRange(0.0, 5.0, "X");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  ak5_ElectronEnergy -> Draw("HIST"); ak5_ElectronEnergy->SetLineColor(2); ak5_ElectronEnergy->SetLineWidth(3);
  ak5_ElectronEnergy->SetMarkerStyle(20); ak5_ElectronEnergy->SetMarkerColor(2); ak5_ElectronEnergy->SetMarkerSize(2);
  ak7_ElectronEnergy -> Draw("HISTsame"); ak7_ElectronEnergy->SetLineColor(4); ak7_ElectronEnergy->SetLineWidth(3);
  ak7_ElectronEnergy->SetMarkerStyle(23); ak7_ElectronEnergy->SetMarkerColor(4); ak7_ElectronEnergy->SetMarkerSize(2);
  kt4_ElectronEnergy -> Draw("HISTsame"); kt4_ElectronEnergy->SetLineColor(41); kt4_ElectronEnergy->SetLineWidth(3);
  kt4_ElectronEnergy->SetMarkerStyle(23); kt4_ElectronEnergy->SetMarkerColor(41); kt4_ElectronEnergy->SetMarkerSize(2);
  kt6_ElectronEnergy -> Draw("HISTsame"); kt6_ElectronEnergy->SetLineColor(32); kt6_ElectronEnergy->SetLineWidth(3);
  kt6_ElectronEnergy->SetMarkerStyle(23); kt6_ElectronEnergy->SetMarkerColor(32); kt6_ElectronEnergy->SetMarkerSize(2);
  Legend->Draw(); Lim_BTag_Energia_Electrones->SaveAs("/home/saksevul/T/Parallelism/Comparisons/Lim_BTag_Energia_Electrones.pdf");
  Lim_BTag_Energia_Electrones->SaveAs("/home/saksevul/T/Parallelism/Comparisons/Lim_BTag_Energia_Electrones.png"); Lim_BTag_Energia_Electrones->Close();

  TCanvas* Lim_BTag_Energia_HadNeutros = new TCanvas("Lim_BTag_Energia_HadNeutros","Lim_BTag_Energia_HadNeutros",10,10,1920,1080);
  Lim_BTag_Energia_HadNeutros->SetFillColor(0);  Lim_BTag_Energia_HadNeutros->SetFrameBorderMode(0);  gPad->SetLogy(); gPad->SetGrid(1,1);
  // Esto es para modificar las etiquetas del canvas.
  ak5_NeuHadronEnergy->SetTitle("Espectro de Energ#acute{i}a para HadNeutros en AODs BTag_; E [GeV]; U. A.");
  ak5_NeuHadronEnergy->GetXaxis()->SetLabelSize(0.05); ak5_NeuHadronEnergy->GetYaxis()->SetLabelSize(0.05);
  ak5_NeuHadronEnergy->GetXaxis()->SetTitleSize(0.05); ak5_NeuHadronEnergy->GetYaxis()->SetTitleSize(0.05);
  ak5_NeuHadronEnergy->GetXaxis()->SetTitleOffset(1.0);ak5_NeuHadronEnergy->GetYaxis()->SetTitleOffset(1.0);
  ak5_NeuHadronEnergy->SetAxisRange(0.0, 5.0, "X");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  ak5_NeuHadronEnergy -> Draw("HIST"); ak5_NeuHadronEnergy->SetLineColor(2); ak5_NeuHadronEnergy->SetLineWidth(3);
  ak5_NeuHadronEnergy->SetMarkerStyle(20); ak5_NeuHadronEnergy->SetMarkerColor(2); ak5_NeuHadronEnergy->SetMarkerSize(2);
  ak7_NeuHadronEnergy -> Draw("HISTsame"); ak7_NeuHadronEnergy->SetLineColor(4); ak7_NeuHadronEnergy->SetLineWidth(3);
  ak7_NeuHadronEnergy->SetMarkerStyle(23); ak7_NeuHadronEnergy->SetMarkerColor(4); ak7_NeuHadronEnergy->SetMarkerSize(2);
  kt4_NeuHadronEnergy -> Draw("HISTsame"); kt4_NeuHadronEnergy->SetLineColor(41); kt4_NeuHadronEnergy->SetLineWidth(3);
  kt4_NeuHadronEnergy->SetMarkerStyle(23); kt4_NeuHadronEnergy->SetMarkerColor(41); kt4_NeuHadronEnergy->SetMarkerSize(2);
  kt6_NeuHadronEnergy -> Draw("HISTsame"); kt6_NeuHadronEnergy->SetLineColor(32); kt6_NeuHadronEnergy->SetLineWidth(3);
  kt6_NeuHadronEnergy->SetMarkerStyle(23); kt6_NeuHadronEnergy->SetMarkerColor(32); kt6_NeuHadronEnergy->SetMarkerSize(2);
  Legend->Draw(); Lim_BTag_Energia_HadNeutros->SaveAs("/home/saksevul/T/Parallelism/Comparisons/Lim_BTag_Energia_HadNeutros.pdf");
  Lim_BTag_Energia_HadNeutros->SaveAs("/home/saksevul/T/Parallelism/Comparisons/Lim_BTag_Energia_HadNeutros.png"); Lim_BTag_Energia_HadNeutros->Close();

  TCanvas* Lim_BTag_Energia_HadCargados = new TCanvas("Lim_BTag_Energia_HadCargados","Lim_BTag_Energia_HadCargados",10,10,1920,1080);
  Lim_BTag_Energia_HadCargados->SetFillColor(0);  Lim_BTag_Energia_HadCargados->SetFrameBorderMode(0);  gPad->SetLogy(); gPad->SetGrid(1,1);
  // Esto es para modificar las etiquetas del canvas.
  ak5_CharHadronEnergy->SetTitle("Espectro de Energ#acute{i}a para HadCargados en AODs BTag_; E [GeV]; U. A.");
  ak5_CharHadronEnergy->GetXaxis()->SetLabelSize(0.05); ak5_CharHadronEnergy->GetYaxis()->SetLabelSize(0.05);
  ak5_CharHadronEnergy->GetXaxis()->SetTitleSize(0.05); ak5_CharHadronEnergy->GetYaxis()->SetTitleSize(0.05);
  ak5_CharHadronEnergy->GetXaxis()->SetTitleOffset(1.0);ak5_CharHadronEnergy->GetYaxis()->SetTitleOffset(1.0);
  ak5_CharHadronEnergy->SetAxisRange(0.0, 5.0, "X");
  // Aqui ponemos todas las gráficas que necesitamos en el canvas.
  ak5_CharHadronEnergy -> Draw("HIST"); ak5_CharHadronEnergy->SetLineColor(2); ak5_CharHadronEnergy->SetLineWidth(3);
  ak5_CharHadronEnergy->SetMarkerStyle(20); ak5_CharHadronEnergy->SetMarkerColor(2); ak5_CharHadronEnergy->SetMarkerSize(2);
  ak7_CharHadronEnergy -> Draw("HISTsame"); ak7_CharHadronEnergy->SetLineColor(4); ak7_CharHadronEnergy->SetLineWidth(3);
  ak7_CharHadronEnergy->SetMarkerStyle(23); ak7_CharHadronEnergy->SetMarkerColor(4); ak7_CharHadronEnergy->SetMarkerSize(2);
  kt4_CharHadronEnergy -> Draw("HISTsame"); kt4_CharHadronEnergy->SetLineColor(41); kt4_CharHadronEnergy->SetLineWidth(3);
  kt4_CharHadronEnergy->SetMarkerStyle(23); kt4_CharHadronEnergy->SetMarkerColor(41); kt4_CharHadronEnergy->SetMarkerSize(2);
  kt6_CharHadronEnergy -> Draw("HISTsame"); kt6_CharHadronEnergy->SetLineColor(32); kt6_CharHadronEnergy->SetLineWidth(3);
  kt6_CharHadronEnergy->SetMarkerStyle(23); kt6_CharHadronEnergy->SetMarkerColor(32); kt6_CharHadronEnergy->SetMarkerSize(2);
  Legend->Draw(); Lim_BTag_Energia_HadCargados->SaveAs("/home/saksevul/T/Parallelism/Comparisons/Lim_BTag_Energia_HadCargados.pdf");
  Lim_BTag_Energia_HadCargados->SaveAs("/home/saksevul/T/Parallelism/Comparisons/Lim_BTag_Energia_HadCargados.png"); Lim_BTag_Energia_HadCargados->Close();

}
