void EnergyQuotient() {

  //Abrimos el archivo que nos interesa y el árbol que queremos leer.
  TFile *FJFile = new TFile("/home/saksevul/T/PYTHIA/FastJet/ak5FJ.root");
  TFile *JetFile = new TFile("/home/saksevul/T/OpenData/Jet_20000/ak5PF.root");
  TFile *BTagFile = new TFile("/home/saksevul/T/OpenData/BTag_20000/ak5PF.root");
  TFile *MinBiasFile = new TFile("/home/saksevul/T/OpenData/MinBias_20000/ak5PF.root");
  TFile *MultiJetFile = new TFile("/home/saksevul/T/OpenData/MultiJet_20000/ak5PF.root");


  TH1F *Energy_Quot__Muon_FJ =(TH1F*)FJFile->Get("Jets_Energy_Quotient__Muon-Jet"); Energy_Quot__Muon_FJ->Scale(1.0/Energy_Quot__Muon_FJ->Integral()); Energy_Quot__Muon_FJ->Rebin();
  TH1F *Energy_Quot__Muon_0FJ100 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Muon-0Jet100"); Energy_Quot__Muon_0FJ100->Scale(1.0/Energy_Quot__Muon_0FJ100->Integral()); Energy_Quot__Muon_0FJ100->Rebin();
  TH1F *Energy_Quot__Muon_100FJ200 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Muon-100Jet100"); Energy_Quot__Muon_100FJ200->Scale(1.0/Energy_Quot__Muon_100FJ200->Integral()); Energy_Quot__Muon_100FJ200->Rebin();
  TH1F *Energy_Quot__Muon_200FJ300 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Muon-200Jet100"); Energy_Quot__Muon_200FJ300->Scale(1.0/Energy_Quot__Muon_200FJ300->Integral()); Energy_Quot__Muon_200FJ300->Rebin();
  TH1F *Energy_Quot__Muon_300FJ400 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Muon-300Jet100"); Energy_Quot__Muon_300FJ400->Scale(1.0/Energy_Quot__Muon_300FJ400->Integral()); Energy_Quot__Muon_300FJ400->Rebin();
  TH1F *Energy_Quot__Muon_400FJ500 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Muon-400Jet100"); Energy_Quot__Muon_400FJ500->Scale(1.0/Energy_Quot__Muon_400FJ500->Integral()); Energy_Quot__Muon_400FJ500->Rebin();
  TH1F *Energy_Quot__Muon_500FJ600 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Muon-500Jet100"); Energy_Quot__Muon_500FJ600->Scale(1.0/Energy_Quot__Muon_500FJ600->Integral()); Energy_Quot__Muon_500FJ600->Rebin();
  TH1F *Energy_Quot__Muon_600FJ700 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Muon-600Jet100"); Energy_Quot__Muon_600FJ700->Scale(1.0/Energy_Quot__Muon_600FJ700->Integral()); Energy_Quot__Muon_600FJ700->Rebin();
  TH1F *Energy_Quot__Muon_700FJ800 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Muon-700Jet100"); Energy_Quot__Muon_700FJ800->Scale(1.0/Energy_Quot__Muon_700FJ800->Integral()); Energy_Quot__Muon_700FJ800->Rebin();
  TH1F *Energy_Quot__Muon_800FJ900 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Muon-800Jet100"); Energy_Quot__Muon_800FJ900->Scale(1.0/Energy_Quot__Muon_800FJ900->Integral()); Energy_Quot__Muon_800FJ900->Rebin();
  TH1F *Energy_Quot__Muon_900FJ1000 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Muon-900Jet100"); Energy_Quot__Muon_900FJ1000->Scale(1.0/Energy_Quot__Muon_900FJ1000->Integral()); Energy_Quot__Muon_900FJ1000->Rebin();
  TH1F *Energy_Quot__Muon_1000FJ =(TH1F*)FJFile->Get("Jets_Energy_Quot__Muon-1000Jet"); Energy_Quot__Muon_1000FJ->Scale(1.0/Energy_Quot__Muon_1000FJ->Integral()); Energy_Quot__Muon_1000FJ->Rebin();

  TH1F *Energy_Quot__Muon_Jet =(TH1F*)JetFile->Get("Jets_Energy_Quotient__Muon-Jet"); Energy_Quot__Muon_Jet->Scale(1.0/Energy_Quot__Muon_Jet->Integral()); Energy_Quot__Muon_Jet->Rebin();
  TH1F *Energy_Quot__Muon_0Jet100 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Muon-0Jet100"); Energy_Quot__Muon_0Jet100->Scale(1.0/Energy_Quot__Muon_0Jet100->Integral()); Energy_Quot__Muon_0Jet100->Rebin();
  TH1F *Energy_Quot__Muon_100Jet200 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Muon-100Jet100"); Energy_Quot__Muon_100Jet200->Scale(1.0/Energy_Quot__Muon_100Jet200->Integral()); Energy_Quot__Muon_100Jet200->Rebin();
  TH1F *Energy_Quot__Muon_200Jet300 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Muon-200Jet100"); Energy_Quot__Muon_200Jet300->Scale(1.0/Energy_Quot__Muon_200Jet300->Integral()); Energy_Quot__Muon_200Jet300->Rebin();
  TH1F *Energy_Quot__Muon_300Jet400 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Muon-300Jet100"); Energy_Quot__Muon_300Jet400->Scale(1.0/Energy_Quot__Muon_300Jet400->Integral()); Energy_Quot__Muon_300Jet400->Rebin();
  TH1F *Energy_Quot__Muon_400Jet500 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Muon-400Jet100"); Energy_Quot__Muon_400Jet500->Scale(1.0/Energy_Quot__Muon_400Jet500->Integral()); Energy_Quot__Muon_400Jet500->Rebin();
  TH1F *Energy_Quot__Muon_500Jet600 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Muon-500Jet100"); Energy_Quot__Muon_500Jet600->Scale(1.0/Energy_Quot__Muon_500Jet600->Integral()); Energy_Quot__Muon_500Jet600->Rebin();
  TH1F *Energy_Quot__Muon_600Jet700 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Muon-600Jet100"); Energy_Quot__Muon_600Jet700->Scale(1.0/Energy_Quot__Muon_600Jet700->Integral()); Energy_Quot__Muon_600Jet700->Rebin();
  TH1F *Energy_Quot__Muon_700Jet800 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Muon-700Jet100"); Energy_Quot__Muon_700Jet800->Scale(1.0/Energy_Quot__Muon_700Jet800->Integral()); Energy_Quot__Muon_700Jet800->Rebin();
  TH1F *Energy_Quot__Muon_800Jet900 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Muon-800Jet100"); Energy_Quot__Muon_800Jet900->Scale(1.0/Energy_Quot__Muon_800Jet900->Integral()); Energy_Quot__Muon_800Jet900->Rebin();
  TH1F *Energy_Quot__Muon_900Jet1000 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Muon-900Jet100"); Energy_Quot__Muon_900Jet1000->Scale(1.0/Energy_Quot__Muon_900Jet1000->Integral()); Energy_Quot__Muon_900Jet1000->Rebin();
  TH1F *Energy_Quot__Muon_1000Jet =(TH1F*)JetFile->Get("Jets_Energy_Quot__Muon-1000Jet"); Energy_Quot__Muon_1000Jet->Scale(1.0/Energy_Quot__Muon_1000Jet->Integral()); Energy_Quot__Muon_1000Jet->Rebin();

  TH1F *Energy_Quot__Muon_BTag =(TH1F*)BTagFile->Get("Jets_Energy_Quotient__Muon-Jet"); Energy_Quot__Muon_BTag->Scale(1.0/Energy_Quot__Muon_BTag->Integral()); Energy_Quot__Muon_BTag->Rebin();
  TH1F *Energy_Quot__Muon_0BTag100 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Muon-0Jet100"); Energy_Quot__Muon_0BTag100->Scale(1.0/Energy_Quot__Muon_0BTag100->Integral()); Energy_Quot__Muon_0BTag100->Rebin();
  TH1F *Energy_Quot__Muon_100BTag200 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Muon-100Jet100"); Energy_Quot__Muon_100BTag200->Scale(1.0/Energy_Quot__Muon_100BTag200->Integral()); Energy_Quot__Muon_100BTag200->Rebin();
  TH1F *Energy_Quot__Muon_200BTag300 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Muon-200Jet100"); Energy_Quot__Muon_200BTag300->Scale(1.0/Energy_Quot__Muon_200BTag300->Integral()); Energy_Quot__Muon_200BTag300->Rebin();
  TH1F *Energy_Quot__Muon_300BTag400 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Muon-300Jet100"); Energy_Quot__Muon_300BTag400->Scale(1.0/Energy_Quot__Muon_300BTag400->Integral()); Energy_Quot__Muon_300BTag400->Rebin();
  TH1F *Energy_Quot__Muon_400BTag500 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Muon-400Jet100"); Energy_Quot__Muon_400BTag500->Scale(1.0/Energy_Quot__Muon_400BTag500->Integral()); Energy_Quot__Muon_400BTag500->Rebin();
  TH1F *Energy_Quot__Muon_500BTag600 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Muon-500Jet100"); Energy_Quot__Muon_500BTag600->Scale(1.0/Energy_Quot__Muon_500BTag600->Integral()); Energy_Quot__Muon_500BTag600->Rebin();
  TH1F *Energy_Quot__Muon_600BTag700 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Muon-600Jet100"); Energy_Quot__Muon_600BTag700->Scale(1.0/Energy_Quot__Muon_600BTag700->Integral()); Energy_Quot__Muon_600BTag700->Rebin();
  TH1F *Energy_Quot__Muon_700BTag800 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Muon-700Jet100"); Energy_Quot__Muon_700BTag800->Scale(1.0/Energy_Quot__Muon_700BTag800->Integral()); Energy_Quot__Muon_700BTag800->Rebin();
  TH1F *Energy_Quot__Muon_800BTag900 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Muon-800Jet100"); Energy_Quot__Muon_800BTag900->Scale(1.0/Energy_Quot__Muon_800BTag900->Integral()); Energy_Quot__Muon_800BTag900->Rebin();
  TH1F *Energy_Quot__Muon_900BTag1000 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Muon-900Jet100"); Energy_Quot__Muon_900BTag1000->Scale(1.0/Energy_Quot__Muon_900BTag1000->Integral()); Energy_Quot__Muon_900BTag1000->Rebin();
  TH1F *Energy_Quot__Muon_1000BTag =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Muon-1000Jet"); Energy_Quot__Muon_1000BTag->Scale(1.0/Energy_Quot__Muon_1000BTag->Integral()); Energy_Quot__Muon_1000BTag->Rebin();

  TH1F *Energy_Quot__Muon_MinBias =(TH1F*)MinBiasFile->Get("Jets_Energy_Quotient__Muon-Jet"); Energy_Quot__Muon_MinBias->Scale(1.0/Energy_Quot__Muon_MinBias->Integral()); Energy_Quot__Muon_MinBias->Rebin();
  TH1F *Energy_Quot__Muon_0MinBias100 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Muon-0Jet100"); Energy_Quot__Muon_0MinBias100->Scale(1.0/Energy_Quot__Muon_0MinBias100->Integral()); Energy_Quot__Muon_0MinBias100->Rebin();
  TH1F *Energy_Quot__Muon_100MinBias200 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Muon-100Jet100"); Energy_Quot__Muon_100MinBias200->Scale(1.0/Energy_Quot__Muon_100MinBias200->Integral()); Energy_Quot__Muon_100MinBias200->Rebin();
  TH1F *Energy_Quot__Muon_200MinBias300 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Muon-200Jet100"); Energy_Quot__Muon_200MinBias300->Scale(1.0/Energy_Quot__Muon_200MinBias300->Integral()); Energy_Quot__Muon_200MinBias300->Rebin();
  TH1F *Energy_Quot__Muon_300MinBias400 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Muon-300Jet100"); Energy_Quot__Muon_300MinBias400->Scale(1.0/Energy_Quot__Muon_300MinBias400->Integral()); Energy_Quot__Muon_300MinBias400->Rebin();
  TH1F *Energy_Quot__Muon_400MinBias500 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Muon-400Jet100"); Energy_Quot__Muon_400MinBias500->Scale(1.0/Energy_Quot__Muon_400MinBias500->Integral()); Energy_Quot__Muon_400MinBias500->Rebin();
  TH1F *Energy_Quot__Muon_500MinBias600 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Muon-500Jet100"); Energy_Quot__Muon_500MinBias600->Scale(1.0/Energy_Quot__Muon_500MinBias600->Integral()); Energy_Quot__Muon_500MinBias600->Rebin();
  TH1F *Energy_Quot__Muon_600MinBias700 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Muon-600Jet100"); Energy_Quot__Muon_600MinBias700->Scale(1.0/Energy_Quot__Muon_600MinBias700->Integral()); Energy_Quot__Muon_600MinBias700->Rebin();
  TH1F *Energy_Quot__Muon_700MinBias800 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Muon-700Jet100"); Energy_Quot__Muon_700MinBias800->Scale(1.0/Energy_Quot__Muon_700MinBias800->Integral()); Energy_Quot__Muon_700MinBias800->Rebin();
  TH1F *Energy_Quot__Muon_800MinBias900 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Muon-800Jet100"); Energy_Quot__Muon_800MinBias900->Scale(1.0/Energy_Quot__Muon_800MinBias900->Integral()); Energy_Quot__Muon_800MinBias900->Rebin();
  TH1F *Energy_Quot__Muon_900MinBias1000 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Muon-900Jet100"); Energy_Quot__Muon_900MinBias1000->Scale(1.0/Energy_Quot__Muon_900MinBias1000->Integral()); Energy_Quot__Muon_900MinBias1000->Rebin();
  TH1F *Energy_Quot__Muon_1000MinBias =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Muon-1000Jet"); Energy_Quot__Muon_1000MinBias->Scale(1.0/Energy_Quot__Muon_1000MinBias->Integral()); Energy_Quot__Muon_1000MinBias->Rebin();

  TH1F *Energy_Quot__Muon_MultiJet =(TH1F*)MultiJetFile->Get("Jets_Energy_Quotient__Muon-Jet"); Energy_Quot__Muon_MultiJet->Scale(1.0/Energy_Quot__Muon_MultiJet->Integral()); Energy_Quot__Muon_MultiJet->Rebin();
  TH1F *Energy_Quot__Muon_0MultiJet100 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Muon-0Jet100"); Energy_Quot__Muon_0MultiJet100->Scale(1.0/Energy_Quot__Muon_0MultiJet100->Integral()); Energy_Quot__Muon_0MultiJet100->Rebin();
  TH1F *Energy_Quot__Muon_100MultiJet200 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Muon-100Jet100"); Energy_Quot__Muon_100MultiJet200->Scale(1.0/Energy_Quot__Muon_100MultiJet200->Integral()); Energy_Quot__Muon_100MultiJet200->Rebin();
  TH1F *Energy_Quot__Muon_200MultiJet300 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Muon-200Jet100"); Energy_Quot__Muon_200MultiJet300->Scale(1.0/Energy_Quot__Muon_200MultiJet300->Integral()); Energy_Quot__Muon_200MultiJet300->Rebin();
  TH1F *Energy_Quot__Muon_300MultiJet400 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Muon-300Jet100"); Energy_Quot__Muon_300MultiJet400->Scale(1.0/Energy_Quot__Muon_300MultiJet400->Integral()); Energy_Quot__Muon_300MultiJet400->Rebin();
  TH1F *Energy_Quot__Muon_400MultiJet500 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Muon-400Jet100"); Energy_Quot__Muon_400MultiJet500->Scale(1.0/Energy_Quot__Muon_400MultiJet500->Integral()); Energy_Quot__Muon_400MultiJet500->Rebin();
  TH1F *Energy_Quot__Muon_500MultiJet600 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Muon-500Jet100"); Energy_Quot__Muon_500MultiJet600->Scale(1.0/Energy_Quot__Muon_500MultiJet600->Integral()); Energy_Quot__Muon_500MultiJet600->Rebin();
  TH1F *Energy_Quot__Muon_600MultiJet700 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Muon-600Jet100"); Energy_Quot__Muon_600MultiJet700->Scale(1.0/Energy_Quot__Muon_600MultiJet700->Integral()); Energy_Quot__Muon_600MultiJet700->Rebin();
  TH1F *Energy_Quot__Muon_700MultiJet800 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Muon-700Jet100"); Energy_Quot__Muon_700MultiJet800->Scale(1.0/Energy_Quot__Muon_700MultiJet800->Integral()); Energy_Quot__Muon_700MultiJet800->Rebin();
  TH1F *Energy_Quot__Muon_800MultiJet900 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Muon-800Jet100"); Energy_Quot__Muon_800MultiJet900->Scale(1.0/Energy_Quot__Muon_800MultiJet900->Integral()); Energy_Quot__Muon_800MultiJet900->Rebin();
  TH1F *Energy_Quot__Muon_900MultiJet1000 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Muon-900Jet100"); Energy_Quot__Muon_900MultiJet1000->Scale(1.0/Energy_Quot__Muon_900MultiJet1000->Integral()); Energy_Quot__Muon_900MultiJet1000->Rebin();
  TH1F *Energy_Quot__Muon_1000MultiJet =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Muon-1000Jet"); Energy_Quot__Muon_1000MultiJet->Scale(1.0/Energy_Quot__Muon_1000MultiJet->Integral()); Energy_Quot__Muon_1000MultiJet->Rebin();

  TH1F *CLONE_E_Q__Muon_FJ =(TH1F*)Energy_Quot__Muon_FJ->Clone(); CLONE_E_Q__Muon_FJ->SetMarkerSize(6); CLONE_E_Q__Muon_FJ->SetMarkerStyle(21); CLONE_E_Q__Muon_FJ->SetMarkerColor(14);
  TH1F *CLONE_E_Q__Muon_Jet =(TH1F*)Energy_Quot__Muon_Jet->Clone(); CLONE_E_Q__Muon_Jet->SetMarkerSize(6); CLONE_E_Q__Muon_Jet->SetMarkerStyle(23); CLONE_E_Q__Muon_Jet->SetMarkerColor(42);
  TH1F *CLONE_E_Q__Muon_BTag =(TH1F*)Energy_Quot__Muon_BTag->Clone(); CLONE_E_Q__Muon_BTag->SetMarkerSize(6); CLONE_E_Q__Muon_BTag->SetMarkerStyle(22); CLONE_E_Q__Muon_BTag->SetMarkerColor(33);
  TH1F *CLONE_E_Q__Muon_MinBias =(TH1F*)Energy_Quot__Muon_MinBias->Clone(); CLONE_E_Q__Muon_MinBias->SetMarkerSize(6); CLONE_E_Q__Muon_MinBias->SetMarkerStyle(20); CLONE_E_Q__Muon_MinBias->SetMarkerColor(5);
  TH1F *CLONE_E_Q__Muon_MultiJet =(TH1F*)Energy_Quot__Muon_MultiJet->Clone(); CLONE_E_Q__Muon_MultiJet->SetMarkerSize(6); CLONE_E_Q__Muon_MultiJet->SetMarkerStyle(34); CLONE_E_Q__Muon_MultiJet->SetMarkerColor(8);


  TH1F *Energy_Quot__Photon_FJ =(TH1F*)FJFile->Get("Jets_Energy_Quotient__Photon-Jet"); Energy_Quot__Photon_FJ->Scale(1.0/Energy_Quot__Photon_FJ->Integral()); Energy_Quot__Photon_FJ->Rebin();
  TH1F *Energy_Quot__Photon_0FJ100 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Photon-0Jet100"); Energy_Quot__Photon_0FJ100->Scale(1.0/Energy_Quot__Photon_0FJ100->Integral()); Energy_Quot__Photon_0FJ100->Rebin();
  TH1F *Energy_Quot__Photon_100FJ200 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Photon-100Jet100"); Energy_Quot__Photon_100FJ200->Scale(1.0/Energy_Quot__Photon_100FJ200->Integral()); Energy_Quot__Photon_100FJ200->Rebin();
  TH1F *Energy_Quot__Photon_200FJ300 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Photon-200Jet100"); Energy_Quot__Photon_200FJ300->Scale(1.0/Energy_Quot__Photon_200FJ300->Integral()); Energy_Quot__Photon_200FJ300->Rebin();
  TH1F *Energy_Quot__Photon_300FJ400 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Photon-300Jet100"); Energy_Quot__Photon_300FJ400->Scale(1.0/Energy_Quot__Photon_300FJ400->Integral()); Energy_Quot__Photon_300FJ400->Rebin();
  TH1F *Energy_Quot__Photon_400FJ500 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Photon-400Jet100"); Energy_Quot__Photon_400FJ500->Scale(1.0/Energy_Quot__Photon_400FJ500->Integral()); Energy_Quot__Photon_400FJ500->Rebin();
  TH1F *Energy_Quot__Photon_500FJ600 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Photon-500Jet100"); Energy_Quot__Photon_500FJ600->Scale(1.0/Energy_Quot__Photon_500FJ600->Integral()); Energy_Quot__Photon_500FJ600->Rebin();
  TH1F *Energy_Quot__Photon_600FJ700 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Photon-600Jet100"); Energy_Quot__Photon_600FJ700->Scale(1.0/Energy_Quot__Photon_600FJ700->Integral()); Energy_Quot__Photon_600FJ700->Rebin();
  TH1F *Energy_Quot__Photon_700FJ800 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Photon-700Jet100"); Energy_Quot__Photon_700FJ800->Scale(1.0/Energy_Quot__Photon_700FJ800->Integral()); Energy_Quot__Photon_700FJ800->Rebin();
  TH1F *Energy_Quot__Photon_800FJ900 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Photon-800Jet100"); Energy_Quot__Photon_800FJ900->Scale(1.0/Energy_Quot__Photon_800FJ900->Integral()); Energy_Quot__Photon_800FJ900->Rebin();
  TH1F *Energy_Quot__Photon_900FJ1000 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Photon-900Jet100"); Energy_Quot__Photon_900FJ1000->Scale(1.0/Energy_Quot__Photon_900FJ1000->Integral()); Energy_Quot__Photon_900FJ1000->Rebin();
  TH1F *Energy_Quot__Photon_1000FJ =(TH1F*)FJFile->Get("Jets_Energy_Quot__Photon-1000Jet"); Energy_Quot__Photon_1000FJ->Scale(1.0/Energy_Quot__Photon_1000FJ->Integral()); Energy_Quot__Photon_1000FJ->Rebin();

  TH1F *Energy_Quot__Photon_Jet =(TH1F*)JetFile->Get("Jets_Energy_Quotient__Photon-Jet"); Energy_Quot__Photon_Jet->Scale(1.0/Energy_Quot__Photon_Jet->Integral()); Energy_Quot__Photon_Jet->Rebin();
  TH1F *Energy_Quot__Photon_0Jet100 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Photon-0Jet100"); Energy_Quot__Photon_0Jet100->Scale(1.0/Energy_Quot__Photon_0Jet100->Integral()); Energy_Quot__Photon_0Jet100->Rebin();
  TH1F *Energy_Quot__Photon_100Jet200 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Photon-100Jet100"); Energy_Quot__Photon_100Jet200->Scale(1.0/Energy_Quot__Photon_100Jet200->Integral()); Energy_Quot__Photon_100Jet200->Rebin();
  TH1F *Energy_Quot__Photon_200Jet300 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Photon-200Jet100"); Energy_Quot__Photon_200Jet300->Scale(1.0/Energy_Quot__Photon_200Jet300->Integral()); Energy_Quot__Photon_200Jet300->Rebin();
  TH1F *Energy_Quot__Photon_300Jet400 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Photon-300Jet100"); Energy_Quot__Photon_300Jet400->Scale(1.0/Energy_Quot__Photon_300Jet400->Integral()); Energy_Quot__Photon_300Jet400->Rebin();
  TH1F *Energy_Quot__Photon_400Jet500 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Photon-400Jet100"); Energy_Quot__Photon_400Jet500->Scale(1.0/Energy_Quot__Photon_400Jet500->Integral()); Energy_Quot__Photon_400Jet500->Rebin();
  TH1F *Energy_Quot__Photon_500Jet600 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Photon-500Jet100"); Energy_Quot__Photon_500Jet600->Scale(1.0/Energy_Quot__Photon_500Jet600->Integral()); Energy_Quot__Photon_500Jet600->Rebin();
  TH1F *Energy_Quot__Photon_600Jet700 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Photon-600Jet100"); Energy_Quot__Photon_600Jet700->Scale(1.0/Energy_Quot__Photon_600Jet700->Integral()); Energy_Quot__Photon_600Jet700->Rebin();
  TH1F *Energy_Quot__Photon_700Jet800 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Photon-700Jet100"); Energy_Quot__Photon_700Jet800->Scale(1.0/Energy_Quot__Photon_700Jet800->Integral()); Energy_Quot__Photon_700Jet800->Rebin();
  TH1F *Energy_Quot__Photon_800Jet900 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Photon-800Jet100"); Energy_Quot__Photon_800Jet900->Scale(1.0/Energy_Quot__Photon_800Jet900->Integral()); Energy_Quot__Photon_800Jet900->Rebin();
  TH1F *Energy_Quot__Photon_900Jet1000 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Photon-900Jet100"); Energy_Quot__Photon_900Jet1000->Scale(1.0/Energy_Quot__Photon_900Jet1000->Integral()); Energy_Quot__Photon_900Jet1000->Rebin();
  TH1F *Energy_Quot__Photon_1000Jet =(TH1F*)JetFile->Get("Jets_Energy_Quot__Photon-1000Jet"); Energy_Quot__Photon_1000Jet->Scale(1.0/Energy_Quot__Photon_1000Jet->Integral()); Energy_Quot__Photon_1000Jet->Rebin();

  TH1F *Energy_Quot__Photon_BTag =(TH1F*)BTagFile->Get("Jets_Energy_Quotient__Photon-Jet"); Energy_Quot__Photon_BTag->Scale(1.0/Energy_Quot__Photon_BTag->Integral()); Energy_Quot__Photon_BTag->Rebin();
  TH1F *Energy_Quot__Photon_0BTag100 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Photon-0Jet100"); Energy_Quot__Photon_0BTag100->Scale(1.0/Energy_Quot__Photon_0BTag100->Integral()); Energy_Quot__Photon_0BTag100->Rebin();
  TH1F *Energy_Quot__Photon_100BTag200 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Photon-100Jet100"); Energy_Quot__Photon_100BTag200->Scale(1.0/Energy_Quot__Photon_100BTag200->Integral()); Energy_Quot__Photon_100BTag200->Rebin();
  TH1F *Energy_Quot__Photon_200BTag300 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Photon-200Jet100"); Energy_Quot__Photon_200BTag300->Scale(1.0/Energy_Quot__Photon_200BTag300->Integral()); Energy_Quot__Photon_200BTag300->Rebin();
  TH1F *Energy_Quot__Photon_300BTag400 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Photon-300Jet100"); Energy_Quot__Photon_300BTag400->Scale(1.0/Energy_Quot__Photon_300BTag400->Integral()); Energy_Quot__Photon_300BTag400->Rebin();
  TH1F *Energy_Quot__Photon_400BTag500 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Photon-400Jet100"); Energy_Quot__Photon_400BTag500->Scale(1.0/Energy_Quot__Photon_400BTag500->Integral()); Energy_Quot__Photon_400BTag500->Rebin();
  TH1F *Energy_Quot__Photon_500BTag600 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Photon-500Jet100"); Energy_Quot__Photon_500BTag600->Scale(1.0/Energy_Quot__Photon_500BTag600->Integral()); Energy_Quot__Photon_500BTag600->Rebin();
  TH1F *Energy_Quot__Photon_600BTag700 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Photon-600Jet100"); Energy_Quot__Photon_600BTag700->Scale(1.0/Energy_Quot__Photon_600BTag700->Integral()); Energy_Quot__Photon_600BTag700->Rebin();
  TH1F *Energy_Quot__Photon_700BTag800 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Photon-700Jet100"); Energy_Quot__Photon_700BTag800->Scale(1.0/Energy_Quot__Photon_700BTag800->Integral()); Energy_Quot__Photon_700BTag800->Rebin();
  TH1F *Energy_Quot__Photon_800BTag900 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Photon-800Jet100"); Energy_Quot__Photon_800BTag900->Scale(1.0/Energy_Quot__Photon_800BTag900->Integral()); Energy_Quot__Photon_800BTag900->Rebin();
  TH1F *Energy_Quot__Photon_900BTag1000 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Photon-900Jet100"); Energy_Quot__Photon_900BTag1000->Scale(1.0/Energy_Quot__Photon_900BTag1000->Integral()); Energy_Quot__Photon_900BTag1000->Rebin();
  TH1F *Energy_Quot__Photon_1000BTag =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Photon-1000Jet"); Energy_Quot__Photon_1000BTag->Scale(1.0/Energy_Quot__Photon_1000BTag->Integral()); Energy_Quot__Photon_1000BTag->Rebin();

  TH1F *Energy_Quot__Photon_MinBias =(TH1F*)MinBiasFile->Get("Jets_Energy_Quotient__Photon-Jet"); Energy_Quot__Photon_MinBias->Scale(1.0/Energy_Quot__Photon_MinBias->Integral()); Energy_Quot__Photon_MinBias->Rebin();
  TH1F *Energy_Quot__Photon_0MinBias100 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Photon-0Jet100"); Energy_Quot__Photon_0MinBias100->Scale(1.0/Energy_Quot__Photon_0MinBias100->Integral()); Energy_Quot__Photon_0MinBias100->Rebin();
  TH1F *Energy_Quot__Photon_100MinBias200 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Photon-100Jet100"); Energy_Quot__Photon_100MinBias200->Scale(1.0/Energy_Quot__Photon_100MinBias200->Integral()); Energy_Quot__Photon_100MinBias200->Rebin();
  TH1F *Energy_Quot__Photon_200MinBias300 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Photon-200Jet100"); Energy_Quot__Photon_200MinBias300->Scale(1.0/Energy_Quot__Photon_200MinBias300->Integral()); Energy_Quot__Photon_200MinBias300->Rebin();
  TH1F *Energy_Quot__Photon_300MinBias400 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Photon-300Jet100"); Energy_Quot__Photon_300MinBias400->Scale(1.0/Energy_Quot__Photon_300MinBias400->Integral()); Energy_Quot__Photon_300MinBias400->Rebin();
  TH1F *Energy_Quot__Photon_400MinBias500 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Photon-400Jet100"); Energy_Quot__Photon_400MinBias500->Scale(1.0/Energy_Quot__Photon_400MinBias500->Integral()); Energy_Quot__Photon_400MinBias500->Rebin();
  TH1F *Energy_Quot__Photon_500MinBias600 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Photon-500Jet100"); Energy_Quot__Photon_500MinBias600->Scale(1.0/Energy_Quot__Photon_500MinBias600->Integral()); Energy_Quot__Photon_500MinBias600->Rebin();
  TH1F *Energy_Quot__Photon_600MinBias700 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Photon-600Jet100"); Energy_Quot__Photon_600MinBias700->Scale(1.0/Energy_Quot__Photon_600MinBias700->Integral()); Energy_Quot__Photon_600MinBias700->Rebin();
  TH1F *Energy_Quot__Photon_700MinBias800 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Photon-700Jet100"); Energy_Quot__Photon_700MinBias800->Scale(1.0/Energy_Quot__Photon_700MinBias800->Integral()); Energy_Quot__Photon_700MinBias800->Rebin();
  TH1F *Energy_Quot__Photon_800MinBias900 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Photon-800Jet100"); Energy_Quot__Photon_800MinBias900->Scale(1.0/Energy_Quot__Photon_800MinBias900->Integral()); Energy_Quot__Photon_800MinBias900->Rebin();
  TH1F *Energy_Quot__Photon_900MinBias1000 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Photon-900Jet100"); Energy_Quot__Photon_900MinBias1000->Scale(1.0/Energy_Quot__Photon_900MinBias1000->Integral()); Energy_Quot__Photon_900MinBias1000->Rebin();
  TH1F *Energy_Quot__Photon_1000MinBias =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Photon-1000Jet"); Energy_Quot__Photon_1000MinBias->Scale(1.0/Energy_Quot__Photon_1000MinBias->Integral()); Energy_Quot__Photon_1000MinBias->Rebin();

  TH1F *Energy_Quot__Photon_MultiJet =(TH1F*)MultiJetFile->Get("Jets_Energy_Quotient__Photon-Jet"); Energy_Quot__Photon_MultiJet->Scale(1.0/Energy_Quot__Photon_MultiJet->Integral()); Energy_Quot__Photon_MultiJet->Rebin();
  TH1F *Energy_Quot__Photon_0MultiJet100 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Photon-0Jet100"); Energy_Quot__Photon_0MultiJet100->Scale(1.0/Energy_Quot__Photon_0MultiJet100->Integral()); Energy_Quot__Photon_0MultiJet100->Rebin();
  TH1F *Energy_Quot__Photon_100MultiJet200 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Photon-100Jet100"); Energy_Quot__Photon_100MultiJet200->Scale(1.0/Energy_Quot__Photon_100MultiJet200->Integral()); Energy_Quot__Photon_100MultiJet200->Rebin();
  TH1F *Energy_Quot__Photon_200MultiJet300 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Photon-200Jet100"); Energy_Quot__Photon_200MultiJet300->Scale(1.0/Energy_Quot__Photon_200MultiJet300->Integral()); Energy_Quot__Photon_200MultiJet300->Rebin();
  TH1F *Energy_Quot__Photon_300MultiJet400 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Photon-300Jet100"); Energy_Quot__Photon_300MultiJet400->Scale(1.0/Energy_Quot__Photon_300MultiJet400->Integral()); Energy_Quot__Photon_300MultiJet400->Rebin();
  TH1F *Energy_Quot__Photon_400MultiJet500 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Photon-400Jet100"); Energy_Quot__Photon_400MultiJet500->Scale(1.0/Energy_Quot__Photon_400MultiJet500->Integral()); Energy_Quot__Photon_400MultiJet500->Rebin();
  TH1F *Energy_Quot__Photon_500MultiJet600 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Photon-500Jet100"); Energy_Quot__Photon_500MultiJet600->Scale(1.0/Energy_Quot__Photon_500MultiJet600->Integral()); Energy_Quot__Photon_500MultiJet600->Rebin();
  TH1F *Energy_Quot__Photon_600MultiJet700 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Photon-600Jet100"); Energy_Quot__Photon_600MultiJet700->Scale(1.0/Energy_Quot__Photon_600MultiJet700->Integral()); Energy_Quot__Photon_600MultiJet700->Rebin();
  TH1F *Energy_Quot__Photon_700MultiJet800 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Photon-700Jet100"); Energy_Quot__Photon_700MultiJet800->Scale(1.0/Energy_Quot__Photon_700MultiJet800->Integral()); Energy_Quot__Photon_700MultiJet800->Rebin();
  TH1F *Energy_Quot__Photon_800MultiJet900 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Photon-800Jet100"); Energy_Quot__Photon_800MultiJet900->Scale(1.0/Energy_Quot__Photon_800MultiJet900->Integral()); Energy_Quot__Photon_800MultiJet900->Rebin();
  TH1F *Energy_Quot__Photon_900MultiJet1000 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Photon-900Jet100"); Energy_Quot__Photon_900MultiJet1000->Scale(1.0/Energy_Quot__Photon_900MultiJet1000->Integral()); Energy_Quot__Photon_900MultiJet1000->Rebin();
  TH1F *Energy_Quot__Photon_1000MultiJet =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Photon-1000Jet"); Energy_Quot__Photon_1000MultiJet->Scale(1.0/Energy_Quot__Photon_1000MultiJet->Integral()); Energy_Quot__Photon_1000MultiJet->Rebin();


  TH1F *Energy_Quot__Electron_FJ =(TH1F*)FJFile->Get("Jets_Energy_Quotient__Electron-Jet"); Energy_Quot__Electron_FJ->Scale(1.0/Energy_Quot__Electron_FJ->Integral()); Energy_Quot__Electron_FJ->Rebin();
  TH1F *Energy_Quot__Electron_0FJ100 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Electron-0Jet100"); Energy_Quot__Electron_0FJ100->Scale(1.0/Energy_Quot__Electron_0FJ100->Integral()); Energy_Quot__Electron_0FJ100->Rebin();
  TH1F *Energy_Quot__Electron_100FJ200 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Electron-100Jet100"); Energy_Quot__Electron_100FJ200->Scale(1.0/Energy_Quot__Electron_100FJ200->Integral()); Energy_Quot__Electron_100FJ200->Rebin();
  TH1F *Energy_Quot__Electron_200FJ300 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Electron-200Jet100"); Energy_Quot__Electron_200FJ300->Scale(1.0/Energy_Quot__Electron_200FJ300->Integral()); Energy_Quot__Electron_200FJ300->Rebin();
  TH1F *Energy_Quot__Electron_300FJ400 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Electron-300Jet100"); Energy_Quot__Electron_300FJ400->Scale(1.0/Energy_Quot__Electron_300FJ400->Integral()); Energy_Quot__Electron_300FJ400->Rebin();
  TH1F *Energy_Quot__Electron_400FJ500 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Electron-400Jet100"); Energy_Quot__Electron_400FJ500->Scale(1.0/Energy_Quot__Electron_400FJ500->Integral()); Energy_Quot__Electron_400FJ500->Rebin();
  TH1F *Energy_Quot__Electron_500FJ600 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Electron-500Jet100"); Energy_Quot__Electron_500FJ600->Scale(1.0/Energy_Quot__Electron_500FJ600->Integral()); Energy_Quot__Electron_500FJ600->Rebin();
  TH1F *Energy_Quot__Electron_600FJ700 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Electron-600Jet100"); Energy_Quot__Electron_600FJ700->Scale(1.0/Energy_Quot__Electron_600FJ700->Integral()); Energy_Quot__Electron_600FJ700->Rebin();
  TH1F *Energy_Quot__Electron_700FJ800 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Electron-700Jet100"); Energy_Quot__Electron_700FJ800->Scale(1.0/Energy_Quot__Electron_700FJ800->Integral()); Energy_Quot__Electron_700FJ800->Rebin();
  TH1F *Energy_Quot__Electron_800FJ900 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Electron-800Jet100"); Energy_Quot__Electron_800FJ900->Scale(1.0/Energy_Quot__Electron_800FJ900->Integral()); Energy_Quot__Electron_800FJ900->Rebin();
  TH1F *Energy_Quot__Electron_900FJ1000 =(TH1F*)FJFile->Get("Jets_Energy_Quot__Electron-900Jet100"); Energy_Quot__Electron_900FJ1000->Scale(1.0/Energy_Quot__Electron_900FJ1000->Integral()); Energy_Quot__Electron_900FJ1000->Rebin();
  TH1F *Energy_Quot__Electron_1000FJ =(TH1F*)FJFile->Get("Jets_Energy_Quot__Electron-1000Jet"); Energy_Quot__Electron_1000FJ->Scale(1.0/Energy_Quot__Electron_1000FJ->Integral()); Energy_Quot__Electron_1000FJ->Rebin();

  TH1F *Energy_Quot__Electron_Jet =(TH1F*)JetFile->Get("Jets_Energy_Quotient__Electron-Jet"); Energy_Quot__Electron_Jet->Scale(1.0/Energy_Quot__Electron_Jet->Integral()); Energy_Quot__Electron_Jet->Rebin();
  TH1F *Energy_Quot__Electron_0Jet100 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Electron-0Jet100"); Energy_Quot__Electron_0Jet100->Scale(1.0/Energy_Quot__Electron_0Jet100->Integral()); Energy_Quot__Electron_0Jet100->Rebin();
  TH1F *Energy_Quot__Electron_100Jet200 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Electron-100Jet100"); Energy_Quot__Electron_100Jet200->Scale(1.0/Energy_Quot__Electron_100Jet200->Integral()); Energy_Quot__Electron_100Jet200->Rebin();
  TH1F *Energy_Quot__Electron_200Jet300 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Electron-200Jet100"); Energy_Quot__Electron_200Jet300->Scale(1.0/Energy_Quot__Electron_200Jet300->Integral()); Energy_Quot__Electron_200Jet300->Rebin();
  TH1F *Energy_Quot__Electron_300Jet400 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Electron-300Jet100"); Energy_Quot__Electron_300Jet400->Scale(1.0/Energy_Quot__Electron_300Jet400->Integral()); Energy_Quot__Electron_300Jet400->Rebin();
  TH1F *Energy_Quot__Electron_400Jet500 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Electron-400Jet100"); Energy_Quot__Electron_400Jet500->Scale(1.0/Energy_Quot__Electron_400Jet500->Integral()); Energy_Quot__Electron_400Jet500->Rebin();
  TH1F *Energy_Quot__Electron_500Jet600 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Electron-500Jet100"); Energy_Quot__Electron_500Jet600->Scale(1.0/Energy_Quot__Electron_500Jet600->Integral()); Energy_Quot__Electron_500Jet600->Rebin();
  TH1F *Energy_Quot__Electron_600Jet700 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Electron-600Jet100"); Energy_Quot__Electron_600Jet700->Scale(1.0/Energy_Quot__Electron_600Jet700->Integral()); Energy_Quot__Electron_600Jet700->Rebin();
  TH1F *Energy_Quot__Electron_700Jet800 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Electron-700Jet100"); Energy_Quot__Electron_700Jet800->Scale(1.0/Energy_Quot__Electron_700Jet800->Integral()); Energy_Quot__Electron_700Jet800->Rebin();
  TH1F *Energy_Quot__Electron_800Jet900 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Electron-800Jet100"); Energy_Quot__Electron_800Jet900->Scale(1.0/Energy_Quot__Electron_800Jet900->Integral()); Energy_Quot__Electron_800Jet900->Rebin();
  TH1F *Energy_Quot__Electron_900Jet1000 =(TH1F*)JetFile->Get("Jets_Energy_Quot__Electron-900Jet100"); Energy_Quot__Electron_900Jet1000->Scale(1.0/Energy_Quot__Electron_900Jet1000->Integral()); Energy_Quot__Electron_900Jet1000->Rebin();
  TH1F *Energy_Quot__Electron_1000Jet =(TH1F*)JetFile->Get("Jets_Energy_Quot__Electron-1000Jet"); Energy_Quot__Electron_1000Jet->Scale(1.0/Energy_Quot__Electron_1000Jet->Integral()); Energy_Quot__Electron_1000Jet->Rebin();

  TH1F *Energy_Quot__Electron_BTag =(TH1F*)BTagFile->Get("Jets_Energy_Quotient__Electron-Jet"); Energy_Quot__Electron_BTag->Scale(1.0/Energy_Quot__Electron_BTag->Integral()); Energy_Quot__Electron_BTag->Rebin();
  TH1F *Energy_Quot__Electron_0BTag100 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Electron-0Jet100"); Energy_Quot__Electron_0BTag100->Scale(1.0/Energy_Quot__Electron_0BTag100->Integral()); Energy_Quot__Electron_0BTag100->Rebin();
  TH1F *Energy_Quot__Electron_100BTag200 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Electron-100Jet100"); Energy_Quot__Electron_100BTag200->Scale(1.0/Energy_Quot__Electron_100BTag200->Integral()); Energy_Quot__Electron_100BTag200->Rebin();
  TH1F *Energy_Quot__Electron_200BTag300 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Electron-200Jet100"); Energy_Quot__Electron_200BTag300->Scale(1.0/Energy_Quot__Electron_200BTag300->Integral()); Energy_Quot__Electron_200BTag300->Rebin();
  TH1F *Energy_Quot__Electron_300BTag400 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Electron-300Jet100"); Energy_Quot__Electron_300BTag400->Scale(1.0/Energy_Quot__Electron_300BTag400->Integral()); Energy_Quot__Electron_300BTag400->Rebin();
  TH1F *Energy_Quot__Electron_400BTag500 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Electron-400Jet100"); Energy_Quot__Electron_400BTag500->Scale(1.0/Energy_Quot__Electron_400BTag500->Integral()); Energy_Quot__Electron_400BTag500->Rebin();
  TH1F *Energy_Quot__Electron_500BTag600 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Electron-500Jet100"); Energy_Quot__Electron_500BTag600->Scale(1.0/Energy_Quot__Electron_500BTag600->Integral()); Energy_Quot__Electron_500BTag600->Rebin();
  TH1F *Energy_Quot__Electron_600BTag700 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Electron-600Jet100"); Energy_Quot__Electron_600BTag700->Scale(1.0/Energy_Quot__Electron_600BTag700->Integral()); Energy_Quot__Electron_600BTag700->Rebin();
  TH1F *Energy_Quot__Electron_700BTag800 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Electron-700Jet100"); Energy_Quot__Electron_700BTag800->Scale(1.0/Energy_Quot__Electron_700BTag800->Integral()); Energy_Quot__Electron_700BTag800->Rebin();
  TH1F *Energy_Quot__Electron_800BTag900 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Electron-800Jet100"); Energy_Quot__Electron_800BTag900->Scale(1.0/Energy_Quot__Electron_800BTag900->Integral()); Energy_Quot__Electron_800BTag900->Rebin();
  TH1F *Energy_Quot__Electron_900BTag1000 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Electron-900Jet100"); Energy_Quot__Electron_900BTag1000->Scale(1.0/Energy_Quot__Electron_900BTag1000->Integral()); Energy_Quot__Electron_900BTag1000->Rebin();
  TH1F *Energy_Quot__Electron_1000BTag =(TH1F*)BTagFile->Get("Jets_Energy_Quot__Electron-1000Jet"); Energy_Quot__Electron_1000BTag->Scale(1.0/Energy_Quot__Electron_1000BTag->Integral()); Energy_Quot__Electron_1000BTag->Rebin();

  TH1F *Energy_Quot__Electron_MinBias =(TH1F*)MinBiasFile->Get("Jets_Energy_Quotient__Electron-Jet"); Energy_Quot__Electron_MinBias->Scale(1.0/Energy_Quot__Electron_MinBias->Integral()); Energy_Quot__Electron_MinBias->Rebin();
  TH1F *Energy_Quot__Electron_0MinBias100 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Electron-0Jet100"); Energy_Quot__Electron_0MinBias100->Scale(1.0/Energy_Quot__Electron_0MinBias100->Integral()); Energy_Quot__Electron_0MinBias100->Rebin();
  TH1F *Energy_Quot__Electron_100MinBias200 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Electron-100Jet100"); Energy_Quot__Electron_100MinBias200->Scale(1.0/Energy_Quot__Electron_100MinBias200->Integral()); Energy_Quot__Electron_100MinBias200->Rebin();
  TH1F *Energy_Quot__Electron_200MinBias300 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Electron-200Jet100"); Energy_Quot__Electron_200MinBias300->Scale(1.0/Energy_Quot__Electron_200MinBias300->Integral()); Energy_Quot__Electron_200MinBias300->Rebin();
  TH1F *Energy_Quot__Electron_300MinBias400 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Electron-300Jet100"); Energy_Quot__Electron_300MinBias400->Scale(1.0/Energy_Quot__Electron_300MinBias400->Integral()); Energy_Quot__Electron_300MinBias400->Rebin();
  TH1F *Energy_Quot__Electron_400MinBias500 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Electron-400Jet100"); Energy_Quot__Electron_400MinBias500->Scale(1.0/Energy_Quot__Electron_400MinBias500->Integral()); Energy_Quot__Electron_400MinBias500->Rebin();
  TH1F *Energy_Quot__Electron_500MinBias600 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Electron-500Jet100"); Energy_Quot__Electron_500MinBias600->Scale(1.0/Energy_Quot__Electron_500MinBias600->Integral()); Energy_Quot__Electron_500MinBias600->Rebin();
  TH1F *Energy_Quot__Electron_600MinBias700 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Electron-600Jet100"); Energy_Quot__Electron_600MinBias700->Scale(1.0/Energy_Quot__Electron_600MinBias700->Integral()); Energy_Quot__Electron_600MinBias700->Rebin();
  TH1F *Energy_Quot__Electron_700MinBias800 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Electron-700Jet100"); Energy_Quot__Electron_700MinBias800->Scale(1.0/Energy_Quot__Electron_700MinBias800->Integral()); Energy_Quot__Electron_700MinBias800->Rebin();
  TH1F *Energy_Quot__Electron_800MinBias900 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Electron-800Jet100"); Energy_Quot__Electron_800MinBias900->Scale(1.0/Energy_Quot__Electron_800MinBias900->Integral()); Energy_Quot__Electron_800MinBias900->Rebin();
  TH1F *Energy_Quot__Electron_900MinBias1000 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Electron-900Jet100"); Energy_Quot__Electron_900MinBias1000->Scale(1.0/Energy_Quot__Electron_900MinBias1000->Integral()); Energy_Quot__Electron_900MinBias1000->Rebin();
  TH1F *Energy_Quot__Electron_1000MinBias =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__Electron-1000Jet"); Energy_Quot__Electron_1000MinBias->Scale(1.0/Energy_Quot__Electron_1000MinBias->Integral()); Energy_Quot__Electron_1000MinBias->Rebin();

  TH1F *Energy_Quot__Electron_MultiJet =(TH1F*)MultiJetFile->Get("Jets_Energy_Quotient__Electron-Jet"); Energy_Quot__Electron_MultiJet->Scale(1.0/Energy_Quot__Electron_MultiJet->Integral()); Energy_Quot__Electron_MultiJet->Rebin();
  TH1F *Energy_Quot__Electron_0MultiJet100 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Electron-0Jet100"); Energy_Quot__Electron_0MultiJet100->Scale(1.0/Energy_Quot__Electron_0MultiJet100->Integral()); Energy_Quot__Electron_0MultiJet100->Rebin();
  TH1F *Energy_Quot__Electron_100MultiJet200 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Electron-100Jet100"); Energy_Quot__Electron_100MultiJet200->Scale(1.0/Energy_Quot__Electron_100MultiJet200->Integral()); Energy_Quot__Electron_100MultiJet200->Rebin();
  TH1F *Energy_Quot__Electron_200MultiJet300 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Electron-200Jet100"); Energy_Quot__Electron_200MultiJet300->Scale(1.0/Energy_Quot__Electron_200MultiJet300->Integral()); Energy_Quot__Electron_200MultiJet300->Rebin();
  TH1F *Energy_Quot__Electron_300MultiJet400 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Electron-300Jet100"); Energy_Quot__Electron_300MultiJet400->Scale(1.0/Energy_Quot__Electron_300MultiJet400->Integral()); Energy_Quot__Electron_300MultiJet400->Rebin();
  TH1F *Energy_Quot__Electron_400MultiJet500 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Electron-400Jet100"); Energy_Quot__Electron_400MultiJet500->Scale(1.0/Energy_Quot__Electron_400MultiJet500->Integral()); Energy_Quot__Electron_400MultiJet500->Rebin();
  TH1F *Energy_Quot__Electron_500MultiJet600 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Electron-500Jet100"); Energy_Quot__Electron_500MultiJet600->Scale(1.0/Energy_Quot__Electron_500MultiJet600->Integral()); Energy_Quot__Electron_500MultiJet600->Rebin();
  TH1F *Energy_Quot__Electron_600MultiJet700 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Electron-600Jet100"); Energy_Quot__Electron_600MultiJet700->Scale(1.0/Energy_Quot__Electron_600MultiJet700->Integral()); Energy_Quot__Electron_600MultiJet700->Rebin();
  TH1F *Energy_Quot__Electron_700MultiJet800 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Electron-700Jet100"); Energy_Quot__Electron_700MultiJet800->Scale(1.0/Energy_Quot__Electron_700MultiJet800->Integral()); Energy_Quot__Electron_700MultiJet800->Rebin();
  TH1F *Energy_Quot__Electron_800MultiJet900 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Electron-800Jet100"); Energy_Quot__Electron_800MultiJet900->Scale(1.0/Energy_Quot__Electron_800MultiJet900->Integral()); Energy_Quot__Electron_800MultiJet900->Rebin();
  TH1F *Energy_Quot__Electron_900MultiJet1000 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Electron-900Jet100"); Energy_Quot__Electron_900MultiJet1000->Scale(1.0/Energy_Quot__Electron_900MultiJet1000->Integral()); Energy_Quot__Electron_900MultiJet1000->Rebin();
  TH1F *Energy_Quot__Electron_1000MultiJet =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__Electron-1000Jet"); Energy_Quot__Electron_1000MultiJet->Scale(1.0/Energy_Quot__Electron_1000MultiJet->Integral()); Energy_Quot__Electron_1000MultiJet->Rebin();


  TH1F *Energy_Quot__NeutralHad_FJ =(TH1F*)FJFile->Get("Jets_Energy_Quotient__NeutralHad-Jet"); Energy_Quot__NeutralHad_FJ->Scale(1.0/Energy_Quot__NeutralHad_FJ->Integral()); Energy_Quot__NeutralHad_FJ->Rebin();
  TH1F *Energy_Quot__NeutralHad_0FJ100 =(TH1F*)FJFile->Get("Jets_Energy_Quot__NeutralHad-0Jet100"); Energy_Quot__NeutralHad_0FJ100->Scale(1.0/Energy_Quot__NeutralHad_0FJ100->Integral()); Energy_Quot__NeutralHad_0FJ100->Rebin();
  TH1F *Energy_Quot__NeutralHad_100FJ200 =(TH1F*)FJFile->Get("Jets_Energy_Quot__NeutralHad-100Jet100"); Energy_Quot__NeutralHad_100FJ200->Scale(1.0/Energy_Quot__NeutralHad_100FJ200->Integral()); Energy_Quot__NeutralHad_100FJ200->Rebin();
  TH1F *Energy_Quot__NeutralHad_200FJ300 =(TH1F*)FJFile->Get("Jets_Energy_Quot__NeutralHad-200Jet100"); Energy_Quot__NeutralHad_200FJ300->Scale(1.0/Energy_Quot__NeutralHad_200FJ300->Integral()); Energy_Quot__NeutralHad_200FJ300->Rebin();
  TH1F *Energy_Quot__NeutralHad_300FJ400 =(TH1F*)FJFile->Get("Jets_Energy_Quot__NeutralHad-300Jet100"); Energy_Quot__NeutralHad_300FJ400->Scale(1.0/Energy_Quot__NeutralHad_300FJ400->Integral()); Energy_Quot__NeutralHad_300FJ400->Rebin();
  TH1F *Energy_Quot__NeutralHad_400FJ500 =(TH1F*)FJFile->Get("Jets_Energy_Quot__NeutralHad-400Jet100"); Energy_Quot__NeutralHad_400FJ500->Scale(1.0/Energy_Quot__NeutralHad_400FJ500->Integral()); Energy_Quot__NeutralHad_400FJ500->Rebin();
  TH1F *Energy_Quot__NeutralHad_500FJ600 =(TH1F*)FJFile->Get("Jets_Energy_Quot__NeutralHad-500Jet100"); Energy_Quot__NeutralHad_500FJ600->Scale(1.0/Energy_Quot__NeutralHad_500FJ600->Integral()); Energy_Quot__NeutralHad_500FJ600->Rebin();
  TH1F *Energy_Quot__NeutralHad_600FJ700 =(TH1F*)FJFile->Get("Jets_Energy_Quot__NeutralHad-600Jet100"); Energy_Quot__NeutralHad_600FJ700->Scale(1.0/Energy_Quot__NeutralHad_600FJ700->Integral()); Energy_Quot__NeutralHad_600FJ700->Rebin();
  TH1F *Energy_Quot__NeutralHad_700FJ800 =(TH1F*)FJFile->Get("Jets_Energy_Quot__NeutralHad-700Jet100"); Energy_Quot__NeutralHad_700FJ800->Scale(1.0/Energy_Quot__NeutralHad_700FJ800->Integral()); Energy_Quot__NeutralHad_700FJ800->Rebin();
  TH1F *Energy_Quot__NeutralHad_800FJ900 =(TH1F*)FJFile->Get("Jets_Energy_Quot__NeutralHad-800Jet100"); Energy_Quot__NeutralHad_800FJ900->Scale(1.0/Energy_Quot__NeutralHad_800FJ900->Integral()); Energy_Quot__NeutralHad_800FJ900->Rebin();
  TH1F *Energy_Quot__NeutralHad_900FJ1000 =(TH1F*)FJFile->Get("Jets_Energy_Quot__NeutralHad-900Jet100"); Energy_Quot__NeutralHad_900FJ1000->Scale(1.0/Energy_Quot__NeutralHad_900FJ1000->Integral()); Energy_Quot__NeutralHad_900FJ1000->Rebin();
  TH1F *Energy_Quot__NeutralHad_1000FJ =(TH1F*)FJFile->Get("Jets_Energy_Quot__NeutralHad-1000Jet"); Energy_Quot__NeutralHad_1000FJ->Scale(1.0/Energy_Quot__NeutralHad_1000FJ->Integral()); Energy_Quot__NeutralHad_1000FJ->Rebin();

  TH1F *Energy_Quot__NeutralHad_Jet =(TH1F*)JetFile->Get("Jets_Energy_Quotient__NeutralHad-Jet"); Energy_Quot__NeutralHad_Jet->Scale(1.0/Energy_Quot__NeutralHad_Jet->Integral()); Energy_Quot__NeutralHad_Jet->Rebin();
  TH1F *Energy_Quot__NeutralHad_0Jet100 =(TH1F*)JetFile->Get("Jets_Energy_Quot__NeutralHad-0Jet100"); Energy_Quot__NeutralHad_0Jet100->Scale(1.0/Energy_Quot__NeutralHad_0Jet100->Integral()); Energy_Quot__NeutralHad_0Jet100->Rebin();
  TH1F *Energy_Quot__NeutralHad_100Jet200 =(TH1F*)JetFile->Get("Jets_Energy_Quot__NeutralHad-100Jet100"); Energy_Quot__NeutralHad_100Jet200->Scale(1.0/Energy_Quot__NeutralHad_100Jet200->Integral()); Energy_Quot__NeutralHad_100Jet200->Rebin();
  TH1F *Energy_Quot__NeutralHad_200Jet300 =(TH1F*)JetFile->Get("Jets_Energy_Quot__NeutralHad-200Jet100"); Energy_Quot__NeutralHad_200Jet300->Scale(1.0/Energy_Quot__NeutralHad_200Jet300->Integral()); Energy_Quot__NeutralHad_200Jet300->Rebin();
  TH1F *Energy_Quot__NeutralHad_300Jet400 =(TH1F*)JetFile->Get("Jets_Energy_Quot__NeutralHad-300Jet100"); Energy_Quot__NeutralHad_300Jet400->Scale(1.0/Energy_Quot__NeutralHad_300Jet400->Integral()); Energy_Quot__NeutralHad_300Jet400->Rebin();
  TH1F *Energy_Quot__NeutralHad_400Jet500 =(TH1F*)JetFile->Get("Jets_Energy_Quot__NeutralHad-400Jet100"); Energy_Quot__NeutralHad_400Jet500->Scale(1.0/Energy_Quot__NeutralHad_400Jet500->Integral()); Energy_Quot__NeutralHad_400Jet500->Rebin();
  TH1F *Energy_Quot__NeutralHad_500Jet600 =(TH1F*)JetFile->Get("Jets_Energy_Quot__NeutralHad-500Jet100"); Energy_Quot__NeutralHad_500Jet600->Scale(1.0/Energy_Quot__NeutralHad_500Jet600->Integral()); Energy_Quot__NeutralHad_500Jet600->Rebin();
  TH1F *Energy_Quot__NeutralHad_600Jet700 =(TH1F*)JetFile->Get("Jets_Energy_Quot__NeutralHad-600Jet100"); Energy_Quot__NeutralHad_600Jet700->Scale(1.0/Energy_Quot__NeutralHad_600Jet700->Integral()); Energy_Quot__NeutralHad_600Jet700->Rebin();
  TH1F *Energy_Quot__NeutralHad_700Jet800 =(TH1F*)JetFile->Get("Jets_Energy_Quot__NeutralHad-700Jet100"); Energy_Quot__NeutralHad_700Jet800->Scale(1.0/Energy_Quot__NeutralHad_700Jet800->Integral()); Energy_Quot__NeutralHad_700Jet800->Rebin();
  TH1F *Energy_Quot__NeutralHad_800Jet900 =(TH1F*)JetFile->Get("Jets_Energy_Quot__NeutralHad-800Jet100"); Energy_Quot__NeutralHad_800Jet900->Scale(1.0/Energy_Quot__NeutralHad_800Jet900->Integral()); Energy_Quot__NeutralHad_800Jet900->Rebin();
  TH1F *Energy_Quot__NeutralHad_900Jet1000 =(TH1F*)JetFile->Get("Jets_Energy_Quot__NeutralHad-900Jet100"); Energy_Quot__NeutralHad_900Jet1000->Scale(1.0/Energy_Quot__NeutralHad_900Jet1000->Integral()); Energy_Quot__NeutralHad_900Jet1000->Rebin();
  TH1F *Energy_Quot__NeutralHad_1000Jet =(TH1F*)JetFile->Get("Jets_Energy_Quot__NeutralHad-1000Jet"); Energy_Quot__NeutralHad_1000Jet->Scale(1.0/Energy_Quot__NeutralHad_1000Jet->Integral()); Energy_Quot__NeutralHad_1000Jet->Rebin();

  TH1F *Energy_Quot__NeutralHad_BTag =(TH1F*)BTagFile->Get("Jets_Energy_Quotient__NeutralHad-Jet"); Energy_Quot__NeutralHad_BTag->Scale(1.0/Energy_Quot__NeutralHad_BTag->Integral()); Energy_Quot__NeutralHad_BTag->Rebin();
  TH1F *Energy_Quot__NeutralHad_0BTag100 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__NeutralHad-0Jet100"); Energy_Quot__NeutralHad_0BTag100->Scale(1.0/Energy_Quot__NeutralHad_0BTag100->Integral()); Energy_Quot__NeutralHad_0BTag100->Rebin();
  TH1F *Energy_Quot__NeutralHad_100BTag200 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__NeutralHad-100Jet100"); Energy_Quot__NeutralHad_100BTag200->Scale(1.0/Energy_Quot__NeutralHad_100BTag200->Integral()); Energy_Quot__NeutralHad_100BTag200->Rebin();
  TH1F *Energy_Quot__NeutralHad_200BTag300 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__NeutralHad-200Jet100"); Energy_Quot__NeutralHad_200BTag300->Scale(1.0/Energy_Quot__NeutralHad_200BTag300->Integral()); Energy_Quot__NeutralHad_200BTag300->Rebin();
  TH1F *Energy_Quot__NeutralHad_300BTag400 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__NeutralHad-300Jet100"); Energy_Quot__NeutralHad_300BTag400->Scale(1.0/Energy_Quot__NeutralHad_300BTag400->Integral()); Energy_Quot__NeutralHad_300BTag400->Rebin();
  TH1F *Energy_Quot__NeutralHad_400BTag500 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__NeutralHad-400Jet100"); Energy_Quot__NeutralHad_400BTag500->Scale(1.0/Energy_Quot__NeutralHad_400BTag500->Integral()); Energy_Quot__NeutralHad_400BTag500->Rebin();
  TH1F *Energy_Quot__NeutralHad_500BTag600 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__NeutralHad-500Jet100"); Energy_Quot__NeutralHad_500BTag600->Scale(1.0/Energy_Quot__NeutralHad_500BTag600->Integral()); Energy_Quot__NeutralHad_500BTag600->Rebin();
  TH1F *Energy_Quot__NeutralHad_600BTag700 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__NeutralHad-600Jet100"); Energy_Quot__NeutralHad_600BTag700->Scale(1.0/Energy_Quot__NeutralHad_600BTag700->Integral()); Energy_Quot__NeutralHad_600BTag700->Rebin();
  TH1F *Energy_Quot__NeutralHad_700BTag800 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__NeutralHad-700Jet100"); Energy_Quot__NeutralHad_700BTag800->Scale(1.0/Energy_Quot__NeutralHad_700BTag800->Integral()); Energy_Quot__NeutralHad_700BTag800->Rebin();
  TH1F *Energy_Quot__NeutralHad_800BTag900 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__NeutralHad-800Jet100"); Energy_Quot__NeutralHad_800BTag900->Scale(1.0/Energy_Quot__NeutralHad_800BTag900->Integral()); Energy_Quot__NeutralHad_800BTag900->Rebin();
  TH1F *Energy_Quot__NeutralHad_900BTag1000 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__NeutralHad-900Jet100"); Energy_Quot__NeutralHad_900BTag1000->Scale(1.0/Energy_Quot__NeutralHad_900BTag1000->Integral()); Energy_Quot__NeutralHad_900BTag1000->Rebin();
  TH1F *Energy_Quot__NeutralHad_1000BTag =(TH1F*)BTagFile->Get("Jets_Energy_Quot__NeutralHad-1000Jet"); Energy_Quot__NeutralHad_1000BTag->Scale(1.0/Energy_Quot__NeutralHad_1000BTag->Integral()); Energy_Quot__NeutralHad_1000BTag->Rebin();

  TH1F *Energy_Quot__NeutralHad_MinBias =(TH1F*)MinBiasFile->Get("Jets_Energy_Quotient__NeutralHad-Jet"); Energy_Quot__NeutralHad_MinBias->Scale(1.0/Energy_Quot__NeutralHad_MinBias->Integral()); Energy_Quot__NeutralHad_MinBias->Rebin();
  TH1F *Energy_Quot__NeutralHad_0MinBias100 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__NeutralHad-0Jet100"); Energy_Quot__NeutralHad_0MinBias100->Scale(1.0/Energy_Quot__NeutralHad_0MinBias100->Integral()); Energy_Quot__NeutralHad_0MinBias100->Rebin();
  TH1F *Energy_Quot__NeutralHad_100MinBias200 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__NeutralHad-100Jet100"); Energy_Quot__NeutralHad_100MinBias200->Scale(1.0/Energy_Quot__NeutralHad_100MinBias200->Integral()); Energy_Quot__NeutralHad_100MinBias200->Rebin();
  TH1F *Energy_Quot__NeutralHad_200MinBias300 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__NeutralHad-200Jet100"); Energy_Quot__NeutralHad_200MinBias300->Scale(1.0/Energy_Quot__NeutralHad_200MinBias300->Integral()); Energy_Quot__NeutralHad_200MinBias300->Rebin();
  TH1F *Energy_Quot__NeutralHad_300MinBias400 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__NeutralHad-300Jet100"); Energy_Quot__NeutralHad_300MinBias400->Scale(1.0/Energy_Quot__NeutralHad_300MinBias400->Integral()); Energy_Quot__NeutralHad_300MinBias400->Rebin();
  TH1F *Energy_Quot__NeutralHad_400MinBias500 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__NeutralHad-400Jet100"); Energy_Quot__NeutralHad_400MinBias500->Scale(1.0/Energy_Quot__NeutralHad_400MinBias500->Integral()); Energy_Quot__NeutralHad_400MinBias500->Rebin();
  TH1F *Energy_Quot__NeutralHad_500MinBias600 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__NeutralHad-500Jet100"); Energy_Quot__NeutralHad_500MinBias600->Scale(1.0/Energy_Quot__NeutralHad_500MinBias600->Integral()); Energy_Quot__NeutralHad_500MinBias600->Rebin();
  TH1F *Energy_Quot__NeutralHad_600MinBias700 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__NeutralHad-600Jet100"); Energy_Quot__NeutralHad_600MinBias700->Scale(1.0/Energy_Quot__NeutralHad_600MinBias700->Integral()); Energy_Quot__NeutralHad_600MinBias700->Rebin();
  TH1F *Energy_Quot__NeutralHad_700MinBias800 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__NeutralHad-700Jet100"); Energy_Quot__NeutralHad_700MinBias800->Scale(1.0/Energy_Quot__NeutralHad_700MinBias800->Integral()); Energy_Quot__NeutralHad_700MinBias800->Rebin();
  TH1F *Energy_Quot__NeutralHad_800MinBias900 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__NeutralHad-800Jet100"); Energy_Quot__NeutralHad_800MinBias900->Scale(1.0/Energy_Quot__NeutralHad_800MinBias900->Integral()); Energy_Quot__NeutralHad_800MinBias900->Rebin();
  TH1F *Energy_Quot__NeutralHad_900MinBias1000 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__NeutralHad-900Jet100"); Energy_Quot__NeutralHad_900MinBias1000->Scale(1.0/Energy_Quot__NeutralHad_900MinBias1000->Integral()); Energy_Quot__NeutralHad_900MinBias1000->Rebin();
  TH1F *Energy_Quot__NeutralHad_1000MinBias =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__NeutralHad-1000Jet"); Energy_Quot__NeutralHad_1000MinBias->Scale(1.0/Energy_Quot__NeutralHad_1000MinBias->Integral()); Energy_Quot__NeutralHad_1000MinBias->Rebin();

  TH1F *Energy_Quot__NeutralHad_MultiJet =(TH1F*)MultiJetFile->Get("Jets_Energy_Quotient__NeutralHad-Jet"); Energy_Quot__NeutralHad_MultiJet->Scale(1.0/Energy_Quot__NeutralHad_MultiJet->Integral()); Energy_Quot__NeutralHad_MultiJet->Rebin();
  TH1F *Energy_Quot__NeutralHad_0MultiJet100 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__NeutralHad-0Jet100"); Energy_Quot__NeutralHad_0MultiJet100->Scale(1.0/Energy_Quot__NeutralHad_0MultiJet100->Integral()); Energy_Quot__NeutralHad_0MultiJet100->Rebin();
  TH1F *Energy_Quot__NeutralHad_100MultiJet200 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__NeutralHad-100Jet100"); Energy_Quot__NeutralHad_100MultiJet200->Scale(1.0/Energy_Quot__NeutralHad_100MultiJet200->Integral()); Energy_Quot__NeutralHad_100MultiJet200->Rebin();
  TH1F *Energy_Quot__NeutralHad_200MultiJet300 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__NeutralHad-200Jet100"); Energy_Quot__NeutralHad_200MultiJet300->Scale(1.0/Energy_Quot__NeutralHad_200MultiJet300->Integral()); Energy_Quot__NeutralHad_200MultiJet300->Rebin();
  TH1F *Energy_Quot__NeutralHad_300MultiJet400 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__NeutralHad-300Jet100"); Energy_Quot__NeutralHad_300MultiJet400->Scale(1.0/Energy_Quot__NeutralHad_300MultiJet400->Integral()); Energy_Quot__NeutralHad_300MultiJet400->Rebin();
  TH1F *Energy_Quot__NeutralHad_400MultiJet500 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__NeutralHad-400Jet100"); Energy_Quot__NeutralHad_400MultiJet500->Scale(1.0/Energy_Quot__NeutralHad_400MultiJet500->Integral()); Energy_Quot__NeutralHad_400MultiJet500->Rebin();
  TH1F *Energy_Quot__NeutralHad_500MultiJet600 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__NeutralHad-500Jet100"); Energy_Quot__NeutralHad_500MultiJet600->Scale(1.0/Energy_Quot__NeutralHad_500MultiJet600->Integral()); Energy_Quot__NeutralHad_500MultiJet600->Rebin();
  TH1F *Energy_Quot__NeutralHad_600MultiJet700 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__NeutralHad-600Jet100"); Energy_Quot__NeutralHad_600MultiJet700->Scale(1.0/Energy_Quot__NeutralHad_600MultiJet700->Integral()); Energy_Quot__NeutralHad_600MultiJet700->Rebin();
  TH1F *Energy_Quot__NeutralHad_700MultiJet800 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__NeutralHad-700Jet100"); Energy_Quot__NeutralHad_700MultiJet800->Scale(1.0/Energy_Quot__NeutralHad_700MultiJet800->Integral()); Energy_Quot__NeutralHad_700MultiJet800->Rebin();
  TH1F *Energy_Quot__NeutralHad_800MultiJet900 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__NeutralHad-800Jet100"); Energy_Quot__NeutralHad_800MultiJet900->Scale(1.0/Energy_Quot__NeutralHad_800MultiJet900->Integral()); Energy_Quot__NeutralHad_800MultiJet900->Rebin();
  TH1F *Energy_Quot__NeutralHad_900MultiJet1000 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__NeutralHad-900Jet100"); Energy_Quot__NeutralHad_900MultiJet1000->Scale(1.0/Energy_Quot__NeutralHad_900MultiJet1000->Integral()); Energy_Quot__NeutralHad_900MultiJet1000->Rebin();
  TH1F *Energy_Quot__NeutralHad_1000MultiJet =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__NeutralHad-1000Jet"); Energy_Quot__NeutralHad_1000MultiJet->Scale(1.0/Energy_Quot__NeutralHad_1000MultiJet->Integral()); Energy_Quot__NeutralHad_1000MultiJet->Rebin();


  TH1F *Energy_Quot__ChargedHad_FJ =(TH1F*)FJFile->Get("Jets_Energy_Quotient__ChargedHad-Jet"); Energy_Quot__ChargedHad_FJ->Scale(1.0/Energy_Quot__ChargedHad_FJ->Integral()); Energy_Quot__ChargedHad_FJ->Rebin();
  TH1F *Energy_Quot__ChargedHad_0FJ100 =(TH1F*)FJFile->Get("Jets_Energy_Quot__ChargedHad-0Jet100"); Energy_Quot__ChargedHad_0FJ100->Scale(1.0/Energy_Quot__ChargedHad_0FJ100->Integral()); Energy_Quot__ChargedHad_0FJ100->Rebin();
  TH1F *Energy_Quot__ChargedHad_100FJ200 =(TH1F*)FJFile->Get("Jets_Energy_Quot__ChargedHad-100Jet100"); Energy_Quot__ChargedHad_100FJ200->Scale(1.0/Energy_Quot__ChargedHad_100FJ200->Integral()); Energy_Quot__ChargedHad_100FJ200->Rebin();
  TH1F *Energy_Quot__ChargedHad_200FJ300 =(TH1F*)FJFile->Get("Jets_Energy_Quot__ChargedHad-200Jet100"); Energy_Quot__ChargedHad_200FJ300->Scale(1.0/Energy_Quot__ChargedHad_200FJ300->Integral()); Energy_Quot__ChargedHad_200FJ300->Rebin();
  TH1F *Energy_Quot__ChargedHad_300FJ400 =(TH1F*)FJFile->Get("Jets_Energy_Quot__ChargedHad-300Jet100"); Energy_Quot__ChargedHad_300FJ400->Scale(1.0/Energy_Quot__ChargedHad_300FJ400->Integral()); Energy_Quot__ChargedHad_300FJ400->Rebin();
  TH1F *Energy_Quot__ChargedHad_400FJ500 =(TH1F*)FJFile->Get("Jets_Energy_Quot__ChargedHad-400Jet100"); Energy_Quot__ChargedHad_400FJ500->Scale(1.0/Energy_Quot__ChargedHad_400FJ500->Integral()); Energy_Quot__ChargedHad_400FJ500->Rebin();
  TH1F *Energy_Quot__ChargedHad_500FJ600 =(TH1F*)FJFile->Get("Jets_Energy_Quot__ChargedHad-500Jet100"); Energy_Quot__ChargedHad_500FJ600->Scale(1.0/Energy_Quot__ChargedHad_500FJ600->Integral()); Energy_Quot__ChargedHad_500FJ600->Rebin();
  TH1F *Energy_Quot__ChargedHad_600FJ700 =(TH1F*)FJFile->Get("Jets_Energy_Quot__ChargedHad-600Jet100"); Energy_Quot__ChargedHad_600FJ700->Scale(1.0/Energy_Quot__ChargedHad_600FJ700->Integral()); Energy_Quot__ChargedHad_600FJ700->Rebin();
  TH1F *Energy_Quot__ChargedHad_700FJ800 =(TH1F*)FJFile->Get("Jets_Energy_Quot__ChargedHad-700Jet100"); Energy_Quot__ChargedHad_700FJ800->Scale(1.0/Energy_Quot__ChargedHad_700FJ800->Integral()); Energy_Quot__ChargedHad_700FJ800->Rebin();
  TH1F *Energy_Quot__ChargedHad_800FJ900 =(TH1F*)FJFile->Get("Jets_Energy_Quot__ChargedHad-800Jet100"); Energy_Quot__ChargedHad_800FJ900->Scale(1.0/Energy_Quot__ChargedHad_800FJ900->Integral()); Energy_Quot__ChargedHad_800FJ900->Rebin();
  TH1F *Energy_Quot__ChargedHad_900FJ1000 =(TH1F*)FJFile->Get("Jets_Energy_Quot__ChargedHad-900Jet100"); Energy_Quot__ChargedHad_900FJ1000->Scale(1.0/Energy_Quot__ChargedHad_900FJ1000->Integral()); Energy_Quot__ChargedHad_900FJ1000->Rebin();
  TH1F *Energy_Quot__ChargedHad_1000FJ =(TH1F*)FJFile->Get("Jets_Energy_Quot__ChargedHad-1000Jet"); Energy_Quot__ChargedHad_1000FJ->Scale(1.0/Energy_Quot__ChargedHad_1000FJ->Integral()); Energy_Quot__ChargedHad_1000FJ->Rebin();

  TH1F *Energy_Quot__ChargedHad_Jet =(TH1F*)JetFile->Get("Jets_Energy_Quotient__ChargedHad-Jet"); Energy_Quot__ChargedHad_Jet->Scale(1.0/Energy_Quot__ChargedHad_Jet->Integral()); Energy_Quot__ChargedHad_Jet->Rebin();
  TH1F *Energy_Quot__ChargedHad_0Jet100 =(TH1F*)JetFile->Get("Jets_Energy_Quot__ChargedHad-0Jet100"); Energy_Quot__ChargedHad_0Jet100->Scale(1.0/Energy_Quot__ChargedHad_0Jet100->Integral()); Energy_Quot__ChargedHad_0Jet100->Rebin();
  TH1F *Energy_Quot__ChargedHad_100Jet200 =(TH1F*)JetFile->Get("Jets_Energy_Quot__ChargedHad-100Jet100"); Energy_Quot__ChargedHad_100Jet200->Scale(1.0/Energy_Quot__ChargedHad_100Jet200->Integral()); Energy_Quot__ChargedHad_100Jet200->Rebin();
  TH1F *Energy_Quot__ChargedHad_200Jet300 =(TH1F*)JetFile->Get("Jets_Energy_Quot__ChargedHad-200Jet100"); Energy_Quot__ChargedHad_200Jet300->Scale(1.0/Energy_Quot__ChargedHad_200Jet300->Integral()); Energy_Quot__ChargedHad_200Jet300->Rebin();
  TH1F *Energy_Quot__ChargedHad_300Jet400 =(TH1F*)JetFile->Get("Jets_Energy_Quot__ChargedHad-300Jet100"); Energy_Quot__ChargedHad_300Jet400->Scale(1.0/Energy_Quot__ChargedHad_300Jet400->Integral()); Energy_Quot__ChargedHad_300Jet400->Rebin();
  TH1F *Energy_Quot__ChargedHad_400Jet500 =(TH1F*)JetFile->Get("Jets_Energy_Quot__ChargedHad-400Jet100"); Energy_Quot__ChargedHad_400Jet500->Scale(1.0/Energy_Quot__ChargedHad_400Jet500->Integral()); Energy_Quot__ChargedHad_400Jet500->Rebin();
  TH1F *Energy_Quot__ChargedHad_500Jet600 =(TH1F*)JetFile->Get("Jets_Energy_Quot__ChargedHad-500Jet100"); Energy_Quot__ChargedHad_500Jet600->Scale(1.0/Energy_Quot__ChargedHad_500Jet600->Integral()); Energy_Quot__ChargedHad_500Jet600->Rebin();
  TH1F *Energy_Quot__ChargedHad_600Jet700 =(TH1F*)JetFile->Get("Jets_Energy_Quot__ChargedHad-600Jet100"); Energy_Quot__ChargedHad_600Jet700->Scale(1.0/Energy_Quot__ChargedHad_600Jet700->Integral()); Energy_Quot__ChargedHad_600Jet700->Rebin();
  TH1F *Energy_Quot__ChargedHad_700Jet800 =(TH1F*)JetFile->Get("Jets_Energy_Quot__ChargedHad-700Jet100"); Energy_Quot__ChargedHad_700Jet800->Scale(1.0/Energy_Quot__ChargedHad_700Jet800->Integral()); Energy_Quot__ChargedHad_700Jet800->Rebin();
  TH1F *Energy_Quot__ChargedHad_800Jet900 =(TH1F*)JetFile->Get("Jets_Energy_Quot__ChargedHad-800Jet100"); Energy_Quot__ChargedHad_800Jet900->Scale(1.0/Energy_Quot__ChargedHad_800Jet900->Integral()); Energy_Quot__ChargedHad_800Jet900->Rebin();
  TH1F *Energy_Quot__ChargedHad_900Jet1000 =(TH1F*)JetFile->Get("Jets_Energy_Quot__ChargedHad-900Jet100"); Energy_Quot__ChargedHad_900Jet1000->Scale(1.0/Energy_Quot__ChargedHad_900Jet1000->Integral()); Energy_Quot__ChargedHad_900Jet1000->Rebin();
  TH1F *Energy_Quot__ChargedHad_1000Jet =(TH1F*)JetFile->Get("Jets_Energy_Quot__ChargedHad-1000Jet"); Energy_Quot__ChargedHad_1000Jet->Scale(1.0/Energy_Quot__ChargedHad_1000Jet->Integral()); Energy_Quot__ChargedHad_1000Jet->Rebin();

  TH1F *Energy_Quot__ChargedHad_BTag =(TH1F*)BTagFile->Get("Jets_Energy_Quotient__ChargedHad-Jet"); Energy_Quot__ChargedHad_BTag->Scale(1.0/Energy_Quot__ChargedHad_BTag->Integral()); Energy_Quot__ChargedHad_BTag->Rebin();
  TH1F *Energy_Quot__ChargedHad_0BTag100 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__ChargedHad-0Jet100"); Energy_Quot__ChargedHad_0BTag100->Scale(1.0/Energy_Quot__ChargedHad_0BTag100->Integral()); Energy_Quot__ChargedHad_0BTag100->Rebin();
  TH1F *Energy_Quot__ChargedHad_100BTag200 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__ChargedHad-100Jet100"); Energy_Quot__ChargedHad_100BTag200->Scale(1.0/Energy_Quot__ChargedHad_100BTag200->Integral()); Energy_Quot__ChargedHad_100BTag200->Rebin();
  TH1F *Energy_Quot__ChargedHad_200BTag300 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__ChargedHad-200Jet100"); Energy_Quot__ChargedHad_200BTag300->Scale(1.0/Energy_Quot__ChargedHad_200BTag300->Integral()); Energy_Quot__ChargedHad_200BTag300->Rebin();
  TH1F *Energy_Quot__ChargedHad_300BTag400 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__ChargedHad-300Jet100"); Energy_Quot__ChargedHad_300BTag400->Scale(1.0/Energy_Quot__ChargedHad_300BTag400->Integral()); Energy_Quot__ChargedHad_300BTag400->Rebin();
  TH1F *Energy_Quot__ChargedHad_400BTag500 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__ChargedHad-400Jet100"); Energy_Quot__ChargedHad_400BTag500->Scale(1.0/Energy_Quot__ChargedHad_400BTag500->Integral()); Energy_Quot__ChargedHad_400BTag500->Rebin();
  TH1F *Energy_Quot__ChargedHad_500BTag600 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__ChargedHad-500Jet100"); Energy_Quot__ChargedHad_500BTag600->Scale(1.0/Energy_Quot__ChargedHad_500BTag600->Integral()); Energy_Quot__ChargedHad_500BTag600->Rebin();
  TH1F *Energy_Quot__ChargedHad_600BTag700 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__ChargedHad-600Jet100"); Energy_Quot__ChargedHad_600BTag700->Scale(1.0/Energy_Quot__ChargedHad_600BTag700->Integral()); Energy_Quot__ChargedHad_600BTag700->Rebin();
  TH1F *Energy_Quot__ChargedHad_700BTag800 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__ChargedHad-700Jet100"); Energy_Quot__ChargedHad_700BTag800->Scale(1.0/Energy_Quot__ChargedHad_700BTag800->Integral()); Energy_Quot__ChargedHad_700BTag800->Rebin();
  TH1F *Energy_Quot__ChargedHad_800BTag900 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__ChargedHad-800Jet100"); Energy_Quot__ChargedHad_800BTag900->Scale(1.0/Energy_Quot__ChargedHad_800BTag900->Integral()); Energy_Quot__ChargedHad_800BTag900->Rebin();
  TH1F *Energy_Quot__ChargedHad_900BTag1000 =(TH1F*)BTagFile->Get("Jets_Energy_Quot__ChargedHad-900Jet100"); Energy_Quot__ChargedHad_900BTag1000->Scale(1.0/Energy_Quot__ChargedHad_900BTag1000->Integral()); Energy_Quot__ChargedHad_900BTag1000->Rebin();
  TH1F *Energy_Quot__ChargedHad_1000BTag =(TH1F*)BTagFile->Get("Jets_Energy_Quot__ChargedHad-1000Jet"); Energy_Quot__ChargedHad_1000BTag->Scale(1.0/Energy_Quot__ChargedHad_1000BTag->Integral()); Energy_Quot__ChargedHad_1000BTag->Rebin();

  TH1F *Energy_Quot__ChargedHad_MinBias =(TH1F*)MinBiasFile->Get("Jets_Energy_Quotient__ChargedHad-Jet"); Energy_Quot__ChargedHad_MinBias->Scale(1.0/Energy_Quot__ChargedHad_MinBias->Integral()); Energy_Quot__ChargedHad_MinBias->Rebin();
  TH1F *Energy_Quot__ChargedHad_0MinBias100 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__ChargedHad-0Jet100"); Energy_Quot__ChargedHad_0MinBias100->Scale(1.0/Energy_Quot__ChargedHad_0MinBias100->Integral()); Energy_Quot__ChargedHad_0MinBias100->Rebin();
  TH1F *Energy_Quot__ChargedHad_100MinBias200 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__ChargedHad-100Jet100"); Energy_Quot__ChargedHad_100MinBias200->Scale(1.0/Energy_Quot__ChargedHad_100MinBias200->Integral()); Energy_Quot__ChargedHad_100MinBias200->Rebin();
  TH1F *Energy_Quot__ChargedHad_200MinBias300 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__ChargedHad-200Jet100"); Energy_Quot__ChargedHad_200MinBias300->Scale(1.0/Energy_Quot__ChargedHad_200MinBias300->Integral()); Energy_Quot__ChargedHad_200MinBias300->Rebin();
  TH1F *Energy_Quot__ChargedHad_300MinBias400 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__ChargedHad-300Jet100"); Energy_Quot__ChargedHad_300MinBias400->Scale(1.0/Energy_Quot__ChargedHad_300MinBias400->Integral()); Energy_Quot__ChargedHad_300MinBias400->Rebin();
  TH1F *Energy_Quot__ChargedHad_400MinBias500 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__ChargedHad-400Jet100"); Energy_Quot__ChargedHad_400MinBias500->Scale(1.0/Energy_Quot__ChargedHad_400MinBias500->Integral()); Energy_Quot__ChargedHad_400MinBias500->Rebin();
  TH1F *Energy_Quot__ChargedHad_500MinBias600 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__ChargedHad-500Jet100"); Energy_Quot__ChargedHad_500MinBias600->Scale(1.0/Energy_Quot__ChargedHad_500MinBias600->Integral()); Energy_Quot__ChargedHad_500MinBias600->Rebin();
  TH1F *Energy_Quot__ChargedHad_600MinBias700 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__ChargedHad-600Jet100"); Energy_Quot__ChargedHad_600MinBias700->Scale(1.0/Energy_Quot__ChargedHad_600MinBias700->Integral()); Energy_Quot__ChargedHad_600MinBias700->Rebin();
  TH1F *Energy_Quot__ChargedHad_700MinBias800 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__ChargedHad-700Jet100"); Energy_Quot__ChargedHad_700MinBias800->Scale(1.0/Energy_Quot__ChargedHad_700MinBias800->Integral()); Energy_Quot__ChargedHad_700MinBias800->Rebin();
  TH1F *Energy_Quot__ChargedHad_800MinBias900 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__ChargedHad-800Jet100"); Energy_Quot__ChargedHad_800MinBias900->Scale(1.0/Energy_Quot__ChargedHad_800MinBias900->Integral()); Energy_Quot__ChargedHad_800MinBias900->Rebin();
  TH1F *Energy_Quot__ChargedHad_900MinBias1000 =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__ChargedHad-900Jet100"); Energy_Quot__ChargedHad_900MinBias1000->Scale(1.0/Energy_Quot__ChargedHad_900MinBias1000->Integral()); Energy_Quot__ChargedHad_900MinBias1000->Rebin();
  TH1F *Energy_Quot__ChargedHad_1000MinBias =(TH1F*)MinBiasFile->Get("Jets_Energy_Quot__ChargedHad-1000Jet"); Energy_Quot__ChargedHad_1000MinBias->Scale(1.0/Energy_Quot__ChargedHad_1000MinBias->Integral()); Energy_Quot__ChargedHad_1000MinBias->Rebin();

  TH1F *Energy_Quot__ChargedHad_MultiJet =(TH1F*)MultiJetFile->Get("Jets_Energy_Quotient__ChargedHad-Jet"); Energy_Quot__ChargedHad_MultiJet->Scale(1.0/Energy_Quot__ChargedHad_MultiJet->Integral()); Energy_Quot__ChargedHad_MultiJet->Rebin();
  TH1F *Energy_Quot__ChargedHad_0MultiJet100 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__ChargedHad-0Jet100"); Energy_Quot__ChargedHad_0MultiJet100->Scale(1.0/Energy_Quot__ChargedHad_0MultiJet100->Integral()); Energy_Quot__ChargedHad_0MultiJet100->Rebin();
  TH1F *Energy_Quot__ChargedHad_100MultiJet200 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__ChargedHad-100Jet100"); Energy_Quot__ChargedHad_100MultiJet200->Scale(1.0/Energy_Quot__ChargedHad_100MultiJet200->Integral()); Energy_Quot__ChargedHad_100MultiJet200->Rebin();
  TH1F *Energy_Quot__ChargedHad_200MultiJet300 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__ChargedHad-200Jet100"); Energy_Quot__ChargedHad_200MultiJet300->Scale(1.0/Energy_Quot__ChargedHad_200MultiJet300->Integral()); Energy_Quot__ChargedHad_200MultiJet300->Rebin();
  TH1F *Energy_Quot__ChargedHad_300MultiJet400 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__ChargedHad-300Jet100"); Energy_Quot__ChargedHad_300MultiJet400->Scale(1.0/Energy_Quot__ChargedHad_300MultiJet400->Integral()); Energy_Quot__ChargedHad_300MultiJet400->Rebin();
  TH1F *Energy_Quot__ChargedHad_400MultiJet500 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__ChargedHad-400Jet100"); Energy_Quot__ChargedHad_400MultiJet500->Scale(1.0/Energy_Quot__ChargedHad_400MultiJet500->Integral()); Energy_Quot__ChargedHad_400MultiJet500->Rebin();
  TH1F *Energy_Quot__ChargedHad_500MultiJet600 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__ChargedHad-500Jet100"); Energy_Quot__ChargedHad_500MultiJet600->Scale(1.0/Energy_Quot__ChargedHad_500MultiJet600->Integral()); Energy_Quot__ChargedHad_500MultiJet600->Rebin();
  TH1F *Energy_Quot__ChargedHad_600MultiJet700 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__ChargedHad-600Jet100"); Energy_Quot__ChargedHad_600MultiJet700->Scale(1.0/Energy_Quot__ChargedHad_600MultiJet700->Integral()); Energy_Quot__ChargedHad_600MultiJet700->Rebin();
  TH1F *Energy_Quot__ChargedHad_700MultiJet800 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__ChargedHad-700Jet100"); Energy_Quot__ChargedHad_700MultiJet800->Scale(1.0/Energy_Quot__ChargedHad_700MultiJet800->Integral()); Energy_Quot__ChargedHad_700MultiJet800->Rebin();
  TH1F *Energy_Quot__ChargedHad_800MultiJet900 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__ChargedHad-800Jet100"); Energy_Quot__ChargedHad_800MultiJet900->Scale(1.0/Energy_Quot__ChargedHad_800MultiJet900->Integral()); Energy_Quot__ChargedHad_800MultiJet900->Rebin();
  TH1F *Energy_Quot__ChargedHad_900MultiJet1000 =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__ChargedHad-900Jet100"); Energy_Quot__ChargedHad_900MultiJet1000->Scale(1.0/Energy_Quot__ChargedHad_900MultiJet1000->Integral()); Energy_Quot__ChargedHad_900MultiJet1000->Rebin();
  TH1F *Energy_Quot__ChargedHad_1000MultiJet =(TH1F*)MultiJetFile->Get("Jets_Energy_Quot__ChargedHad-1000Jet"); Energy_Quot__ChargedHad_1000MultiJet->Scale(1.0/Energy_Quot__ChargedHad_1000MultiJet->Integral()); Energy_Quot__ChargedHad_1000MultiJet->Rebin();



  auto   Leg = new TLegend(0.74,0.76,1,1);    Leg->SetTextSize(0.04); Leg->SetFillStyle(0); Leg->SetBorderSize(0);
  Leg->AddEntry(CLONE_E_Q__Muon_FJ, "MC FastJet", "p");
  Leg->AddEntry(CLONE_E_Q__Muon_Jet, "Open-Data PF Jet", "p");
  Leg->AddEntry(CLONE_E_Q__Muon_BTag, "Open-Data PF BTag", "p");
  Leg->AddEntry(CLONE_E_Q__Muon_MinBias, "Open-Data PF MinBias", "p");
  Leg->AddEntry(CLONE_E_Q__Muon_MultiJet, "Open-Data PF MultiJet", "p");

  auto   Legend = new TLegend(0.74,0.76,1,1);    Legend->SetTextSize(0.04); Legend->SetFillStyle(0); Legend->SetBorderSize(0);
  Legend->AddEntry(Energy_Quot__Muon_FJ, "MC FastJet", "lep");
  Legend->AddEntry(Energy_Quot__Muon_Jet, "Open-Data PF Jet", "lep");
  Legend->AddEntry(Energy_Quot__Muon_BTag, "Open-Data PF BTag", "lep");
  Legend->AddEntry(Energy_Quot__Muon_MinBias, "Open-Data PF MinBias", "lep");
  Legend->AddEntry(Energy_Quot__Muon_MultiJet, "Open-Data PF MultiJet", "lep");



  TF1 *Cero = new TF1("Cero","0",0,1.08); Cero->GetYaxis()->SetRangeUser(-2,2); Cero->SetLineColor(14); Cero->SetLineStyle(2); Cero->SetLineWidth(2);
  Cero->GetXaxis()->SetTitleSize(0.15); Cero->GetYaxis()->SetTitleSize(0.2); Cero->GetYaxis()->SetTitleOffset(0.2);
  Cero->GetXaxis()->SetLabelSize(0.15); Cero->GetYaxis()->SetLabelSize(0.1);

  TH1F *Energy_Quot__Error = new TH1F("", "", 120, 0, 1.2); Energy_Quot__Error->Reset("ICES"); Energy_Quot__Error->Rebin();
  Energy_Quot__Error->SetMarkerSize(4); Energy_Quot__Error->SetLineWidth(2);



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



  TCanvas* Energy_Quotient__Muon_Jet  = new TCanvas("Energy_Quotient__Muon_Jet ","Energy_Quotient__Muon_Jet ",0,0,3240,2160);
  TPad *H__Muon_Jet = new TPad("H__Muon_Jet","", 0, 0.25, 1, 1); H__Muon_Jet->SetMargin(0.11,0,0,0); H__Muon_Jet->SetLogy(); H__Muon_Jet->Draw();
  TPad *E__Muon_Jet = new TPad("E__Muon_Jet","", 0, 0, 1, 0.25); E__Muon_Jet->SetMargin(0.11,0,0.33,0); E__Muon_Jet->Draw(); H__Muon_Jet->cd();
  Energy_Quot__Muon_FJ->SetTitle(" ; ; #frac{1}{N_{Tot}} #frac{dN}{dE}");
  Energy_Quot__Muon_FJ->GetYaxis()->SetTitleSize(0.05); Energy_Quot__Muon_FJ->GetYaxis()->SetTitleOffset(1.0);
  Energy_Quot__Muon_FJ->GetYaxis()->SetLabelSize(0.05); Energy_Quot__Muon_FJ->SetAxisRange(0.0, 1.04, "X");
  Energy_Quot__Muon_FJ->SetMarkerSize(6); Energy_Quot__Muon_FJ->SetMarkerColor(14); Energy_Quot__Muon_FJ->SetMarkerStyle(21);
  Energy_Quot__Muon_FJ->DrawCopy("P");    Energy_Quot__Muon_FJ->SetMarkerColor(1);  Energy_Quot__Muon_FJ->SetMarkerStyle(25);
  Energy_Quot__Muon_FJ->SetLineWidth(2);  Energy_Quot__Muon_FJ->SetLineColor(1);    Energy_Quot__Muon_FJ->DrawCopy("Esame");
  Energy_Quot__Muon_Jet ->SetMarkerSize(6);  Energy_Quot__Muon_Jet ->SetMarkerColor(42);Energy_Quot__Muon_Jet ->SetMarkerStyle(23);
  Energy_Quot__Muon_Jet ->DrawCopy("Psame"); Energy_Quot__Muon_Jet ->SetMarkerColor(2); Energy_Quot__Muon_Jet ->SetMarkerStyle(32);
  Energy_Quot__Muon_Jet ->SetLineWidth(2);   Energy_Quot__Muon_Jet ->SetLineColor(2);   Energy_Quot__Muon_Jet ->DrawCopy("Esame");
  Energy_Quot__Muon_BTag->SetMarkerSize(6);  Energy_Quot__Muon_BTag->SetMarkerColor(33);Energy_Quot__Muon_BTag->SetMarkerStyle(22);
  Energy_Quot__Muon_BTag->DrawCopy("Psame"); Energy_Quot__Muon_BTag->SetMarkerColor(4); Energy_Quot__Muon_BTag->SetMarkerStyle(26);
  Energy_Quot__Muon_BTag->SetLineWidth(2);   Energy_Quot__Muon_BTag->SetLineColor(4);   Energy_Quot__Muon_BTag->DrawCopy("Esame");
  Energy_Quot__Muon_MinBias->SetMarkerSize(6);  Energy_Quot__Muon_MinBias->SetMarkerColor(5); Energy_Quot__Muon_MinBias->SetMarkerStyle(20);
  Energy_Quot__Muon_MinBias->DrawCopy("Psame"); Energy_Quot__Muon_MinBias->SetMarkerColor(41);Energy_Quot__Muon_MinBias->SetMarkerStyle(24);
  Energy_Quot__Muon_MinBias->SetLineWidth(2);   Energy_Quot__Muon_MinBias->SetLineColor(41);  Energy_Quot__Muon_MinBias->DrawCopy("Esame");
  Energy_Quot__Muon_MultiJet->SetMarkerSize(6);  Energy_Quot__Muon_MultiJet->SetMarkerColor(8); Energy_Quot__Muon_MultiJet->SetMarkerStyle(34);
  Energy_Quot__Muon_MultiJet->DrawCopy("Psame"); Energy_Quot__Muon_MultiJet->SetMarkerColor(32);Energy_Quot__Muon_MultiJet->SetMarkerStyle(28);
  Energy_Quot__Muon_MultiJet->SetLineWidth(2);   Energy_Quot__Muon_MultiJet->SetLineColor(32);  Energy_Quot__Muon_MultiJet->DrawCopy("Esame");
  Leg->Draw(); Legend->Draw(); E__Muon_Jet->cd();
  Cero->SetTitle(";E^{Mu#acute{o}n}/E^{Jet};#xi"); Cero->Draw();
  Energy_Quot__Error->Add(Energy_Quot__Muon_FJ,-1); Energy_Quot__Error->Add(Energy_Quot__Muon_Jet ,1); Energy_Quot__Error->Divide(Energy_Quot__Muon_FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(23);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(2); Energy_Quot__Error->SetMarkerStyle(32);
  Energy_Quot__Error->SetLineColor(2);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Muon_FJ,-1); Energy_Quot__Error->Add(Energy_Quot__Muon_BTag,1); Energy_Quot__Error->Divide(Energy_Quot__Muon_FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(22);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(4); Energy_Quot__Error->SetMarkerStyle(26);
  Energy_Quot__Error->SetLineColor(4);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Muon_FJ,-1); Energy_Quot__Error->Add(Energy_Quot__Muon_MinBias,1); Energy_Quot__Error->Divide(Energy_Quot__Muon_FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(20);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(5); Energy_Quot__Error->SetMarkerStyle(24);
  Energy_Quot__Error->SetLineColor(5);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Muon_FJ,-1); Energy_Quot__Error->Add(Energy_Quot__Muon_MultiJet,1); Energy_Quot__Error->Divide(Energy_Quot__Muon_FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(34);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(8); Energy_Quot__Error->SetMarkerStyle(28);
  Energy_Quot__Error->SetLineColor(8);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quotient__Muon_Jet->Print("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient.pdf(","pdf");
  Energy_Quotient__Muon_Jet->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__Muon-Jet.pdf"); Energy_Quotient__Muon_Jet->Close();


  TH1F *Energy_Quot__Muon_FJ200 = new TH1F("Energy_Quot__Muon_FJ200", ";;", 120, 0, 1.2);   Energy_Quot__Muon_FJ200->Rebin();
  Energy_Quot__Muon_FJ200->Add(Energy_Quot__Muon_0FJ100,1);
  TH1F *Energy_Quot__Muon_Jet200 = new TH1F("Energy_Quot__Muon_Jet200", ";;", 120, 0, 1.2);   Energy_Quot__Muon_Jet200->Rebin();
  Energy_Quot__Muon_Jet200->Add(Energy_Quot__Muon_0Jet100,1);
  TH1F *Energy_Quot__Muon_BTag200 = new TH1F("Energy_Quot__Muon_BTag200", ";;", 120, 0, 1.2);   Energy_Quot__Muon_BTag200->Rebin();
  Energy_Quot__Muon_BTag200->Add(Energy_Quot__Muon_0BTag100,1);
  TH1F *Energy_Quot__Muon_MinBias200 = new TH1F("Energy_Quot__Muon_MinBias200", ";;", 120, 0, 1.2);   Energy_Quot__Muon_MinBias200->Rebin();
  Energy_Quot__Muon_MinBias200->Add(Energy_Quot__Muon_0MinBias100,1);
  TH1F *Energy_Quot__Muon_MultiJet200 = new TH1F("Energy_Quot__Muon_MultiJet200", ";;", 120, 0, 1.2);   Energy_Quot__Muon_MultiJet200->Rebin();
  Energy_Quot__Muon_MultiJet200->Add(Energy_Quot__Muon_0MultiJet100,1);

  TCanvas* Energy_Quotient__Muon_Jet200  = new TCanvas("Energy_Quotient__Muon_Jet200 ","Energy_Quotient__Muon_Jet200 ",0,0,3240,2160);
  TPad *H__Muon_Jet200 = new TPad("H__Muon_Jet200","", 0, 0.25, 1, 1); H__Muon_Jet200->SetMargin(0.11,0,0,0); H__Muon_Jet200->SetLogy(); H__Muon_Jet200->Draw();
  TPad *E__Muon_Jet200 = new TPad("E__Muon_Jet200","", 0, 0, 1, 0.25); E__Muon_Jet200->SetMargin(0.11,0,0.33,0); E__Muon_Jet200->Draw(); H__Muon_Jet200->cd();
  Energy_Quot__Muon_FJ200->SetTitle("; ; #frac{1}{N_{Tot}} #frac{dN}{dE}");
  Energy_Quot__Muon_FJ200->GetYaxis()->SetTitleSize(0.05); Energy_Quot__Muon_FJ200->GetYaxis()->SetTitleOffset(1.0);
  Energy_Quot__Muon_FJ200->GetYaxis()->SetLabelSize(0.05); Energy_Quot__Muon_FJ200->SetAxisRange(0.0, 1.04, "X");
  Energy_Quot__Muon_FJ200->SetMarkerSize(6); Energy_Quot__Muon_FJ200->SetMarkerColor(14); Energy_Quot__Muon_FJ200->SetMarkerStyle(21);
  Energy_Quot__Muon_FJ200->DrawCopy("P");    Energy_Quot__Muon_FJ200->SetMarkerColor(1);  Energy_Quot__Muon_FJ200->SetMarkerStyle(25);
  Energy_Quot__Muon_FJ200->SetLineWidth(2);  Energy_Quot__Muon_FJ200->SetLineColor(1);    Energy_Quot__Muon_FJ200->DrawCopy("Esame");
  Energy_Quot__Muon_Jet200 ->SetMarkerSize(6);  Energy_Quot__Muon_Jet200 ->SetMarkerColor(42);Energy_Quot__Muon_Jet200 ->SetMarkerStyle(23);
  Energy_Quot__Muon_Jet200 ->DrawCopy("Psame"); Energy_Quot__Muon_Jet200 ->SetMarkerColor(2); Energy_Quot__Muon_Jet200 ->SetMarkerStyle(32);
  Energy_Quot__Muon_Jet200 ->SetLineWidth(2);   Energy_Quot__Muon_Jet200 ->SetLineColor(2);   Energy_Quot__Muon_Jet200 ->DrawCopy("Esame");
  Energy_Quot__Muon_BTag200->SetMarkerSize(6);  Energy_Quot__Muon_BTag200->SetMarkerColor(33);Energy_Quot__Muon_BTag200->SetMarkerStyle(22);
  Energy_Quot__Muon_BTag200->DrawCopy("Psame"); Energy_Quot__Muon_BTag200->SetMarkerColor(4); Energy_Quot__Muon_BTag200->SetMarkerStyle(26);
  Energy_Quot__Muon_BTag200->SetLineWidth(2);   Energy_Quot__Muon_BTag200->SetLineColor(4);   Energy_Quot__Muon_BTag200->DrawCopy("Esame");
  Energy_Quot__Muon_MinBias200->SetMarkerSize(6);  Energy_Quot__Muon_MinBias200->SetMarkerColor(5); Energy_Quot__Muon_MinBias200->SetMarkerStyle(20);
  Energy_Quot__Muon_MinBias200->DrawCopy("Psame"); Energy_Quot__Muon_MinBias200->SetMarkerColor(41);Energy_Quot__Muon_MinBias200->SetMarkerStyle(24);
  Energy_Quot__Muon_MinBias200->SetLineWidth(2);   Energy_Quot__Muon_MinBias200->SetLineColor(41);  Energy_Quot__Muon_MinBias200->DrawCopy("Esame");
  Energy_Quot__Muon_MultiJet200->SetMarkerSize(6);  Energy_Quot__Muon_MultiJet200->SetMarkerColor(8); Energy_Quot__Muon_MultiJet200->SetMarkerStyle(34);
  Energy_Quot__Muon_MultiJet200->DrawCopy("Psame"); Energy_Quot__Muon_MultiJet200->SetMarkerColor(32);Energy_Quot__Muon_MultiJet200->SetMarkerStyle(28);
  Energy_Quot__Muon_MultiJet200->SetLineWidth(2);   Energy_Quot__Muon_MultiJet200->SetLineColor(32);  Energy_Quot__Muon_MultiJet200->DrawCopy("Esame");
  Leg->Draw(); Legend->Draw(); E__Muon_Jet200->cd();
  Cero->SetTitle(";E^{Mu#acute{o}n}/E^{Jet}, E^{Jet}<200;#xi"); Cero->Draw();
  Energy_Quot__Error->Add(Energy_Quot__Muon_FJ200,-1); Energy_Quot__Error->Add(Energy_Quot__Muon_Jet200 ,1); Energy_Quot__Error->Divide(Energy_Quot__Muon_FJ200);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(23);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(2); Energy_Quot__Error->SetMarkerStyle(32);
  Energy_Quot__Error->SetLineColor(2);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Muon_FJ200,-1); Energy_Quot__Error->Add(Energy_Quot__Muon_BTag200,1); Energy_Quot__Error->Divide(Energy_Quot__Muon_FJ200);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(22);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(4); Energy_Quot__Error->SetMarkerStyle(26);
  Energy_Quot__Error->SetLineColor(4);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Muon_FJ200,-1); Energy_Quot__Error->Add(Energy_Quot__Muon_MinBias200,1); Energy_Quot__Error->Divide(Energy_Quot__Muon_FJ200);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(20);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(5); Energy_Quot__Error->SetMarkerStyle(24);
  Energy_Quot__Error->SetLineColor(5);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Muon_FJ200,-1); Energy_Quot__Error->Add(Energy_Quot__Muon_MultiJet200,1); Energy_Quot__Error->Divide(Energy_Quot__Muon_FJ200);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(34);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(8); Energy_Quot__Error->SetMarkerStyle(28);
  Energy_Quot__Error->SetLineColor(8);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quotient__Muon_Jet200->Print("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient.pdf","pdf");
  Energy_Quotient__Muon_Jet200->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__Muon-Jet200.pdf"); Energy_Quotient__Muon_Jet200->Close();


  TH1F *Energy_Quot__Muon_200FJ = new TH1F("Energy_Quot__Muon_FJ200", ";;", 120, 0, 1.2);   Energy_Quot__Muon_200FJ->Rebin();
  Energy_Quot__Muon_200FJ -> Add(Energy_Quot__Muon_200FJ300,1);
  TH1F *Energy_Quot__Muon_200Jet = new TH1F("Energy_Quot__Muon_Jet200", ";;", 120, 0, 1.2);   Energy_Quot__Muon_200Jet->Rebin();
  Energy_Quot__Muon_200Jet -> Add(Energy_Quot__Muon_200Jet300,1);
  TH1F *Energy_Quot__Muon_200BTag = new TH1F("Energy_Quot__Muon_BTag200", ";;", 120, 0, 1.2);   Energy_Quot__Muon_200BTag->Rebin();
  Energy_Quot__Muon_200BTag -> Add(Energy_Quot__Muon_200BTag300,1);
  TH1F *Energy_Quot__Muon_200MinBias = new TH1F("Energy_Quot__Muon_MinBias200", ";;", 120, 0, 1.2);   Energy_Quot__Muon_200MinBias->Rebin();
  Energy_Quot__Muon_200MinBias -> Add(Energy_Quot__Muon_200MinBias300,1);
  TH1F *Energy_Quot__Muon_200MultiJet = new TH1F("Energy_Quot__Muon_MultiJet200", ";;", 120, 0, 1.2);   Energy_Quot__Muon_200MultiJet->Rebin();
  Energy_Quot__Muon_200MultiJet -> Add(Energy_Quot__Muon_200MultiJet300,1);

  TCanvas* Energy_Quotient__Muon_200Jet = new TCanvas("Energy_Quotient__Muon_200Jet","Energy_Quotient__Muon_200Jet",0,0,3240,2160);
  TPad *H__Muon_200Jet = new TPad("H__Muon_200Jet","", 0, 0.25, 1, 1); H__Muon_200Jet->SetMargin(0.11,0,0,0); H__Muon_200Jet->SetLogy(); H__Muon_200Jet->Draw();
  TPad *E__Muon_200Jet = new TPad("E__Muon_200Jet","", 0, 0, 1, 0.25); E__Muon_200Jet->SetMargin(0.11,0,0.33,0); E__Muon_200Jet->Draw(); H__Muon_200Jet->cd();
  Energy_Quot__Muon_200FJ->SetTitle("; ; #frac{1}{N_{Tot}} #frac{dN}{dE}");
  Energy_Quot__Muon_200FJ->GetYaxis()->SetTitleSize(0.05); Energy_Quot__Muon_200FJ->GetYaxis()->SetTitleOffset(1.0);
  Energy_Quot__Muon_200FJ->GetYaxis()->SetLabelSize(0.05); Energy_Quot__Muon_200FJ->SetAxisRange(0.0, 1.04, "X");
  Energy_Quot__Muon_200FJ->SetMarkerSize(6); Energy_Quot__Muon_200FJ->SetMarkerColor(14); Energy_Quot__Muon_200FJ->SetMarkerStyle(21);
  Energy_Quot__Muon_200FJ->DrawCopy("P");    Energy_Quot__Muon_200FJ->SetMarkerColor(1);  Energy_Quot__Muon_200FJ->SetMarkerStyle(25);
  Energy_Quot__Muon_200FJ->SetLineWidth(2);  Energy_Quot__Muon_200FJ->SetLineColor(1);    Energy_Quot__Muon_200FJ->DrawCopy("Esame");
  Energy_Quot__Muon_200Jet->SetMarkerSize(6);  Energy_Quot__Muon_200Jet->SetMarkerColor(42);Energy_Quot__Muon_200Jet->SetMarkerStyle(23);
  Energy_Quot__Muon_200Jet->DrawCopy("Psame"); Energy_Quot__Muon_200Jet->SetMarkerColor(2); Energy_Quot__Muon_200Jet->SetMarkerStyle(32);
  Energy_Quot__Muon_200Jet->SetLineWidth(2);   Energy_Quot__Muon_200Jet->SetLineColor(2);   Energy_Quot__Muon_200Jet->DrawCopy("Esame");
  Energy_Quot__Muon_200BTag->SetMarkerSize(6);  Energy_Quot__Muon_200BTag->SetMarkerColor(33);Energy_Quot__Muon_200BTag->SetMarkerStyle(22);
  Energy_Quot__Muon_200BTag->DrawCopy("Psame"); Energy_Quot__Muon_200BTag->SetMarkerColor(4); Energy_Quot__Muon_200BTag->SetMarkerStyle(26);
  Energy_Quot__Muon_200BTag->SetLineWidth(2);   Energy_Quot__Muon_200BTag->SetLineColor(4);   Energy_Quot__Muon_200BTag->DrawCopy("Esame");
  Energy_Quot__Muon_200MinBias->SetMarkerSize(6);  Energy_Quot__Muon_200MinBias->SetMarkerColor(5); Energy_Quot__Muon_200MinBias->SetMarkerStyle(20);
  Energy_Quot__Muon_200MinBias->DrawCopy("Psame"); Energy_Quot__Muon_200MinBias->SetMarkerColor(41);Energy_Quot__Muon_200MinBias->SetMarkerStyle(24);
  Energy_Quot__Muon_200MinBias->SetLineWidth(2);   Energy_Quot__Muon_200MinBias->SetLineColor(41);  Energy_Quot__Muon_200MinBias->DrawCopy("Esame");
  Energy_Quot__Muon_200MultiJet->SetMarkerSize(6);  Energy_Quot__Muon_200MultiJet->SetMarkerColor(8); Energy_Quot__Muon_200MultiJet->SetMarkerStyle(34);
  Energy_Quot__Muon_200MultiJet->DrawCopy("Psame"); Energy_Quot__Muon_200MultiJet->SetMarkerColor(32);Energy_Quot__Muon_200MultiJet->SetMarkerStyle(28);
  Energy_Quot__Muon_200MultiJet->SetLineWidth(2);   Energy_Quot__Muon_200MultiJet->SetLineColor(32);  Energy_Quot__Muon_200MultiJet->DrawCopy("Esame");
  Leg->Draw(); Legend->Draw(); E__Muon_200Jet->cd();
  Cero->SetTitle(";E^{Mu#acute{o}n}/E^{Jet}, E^{Jet}>200;#xi"); Cero->Draw();
  Energy_Quot__Error->Add(Energy_Quot__Muon_200FJ,-1); Energy_Quot__Error->Add(Energy_Quot__Muon_200Jet,1); Energy_Quot__Error->Divide(Energy_Quot__Muon_200FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(23);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(2); Energy_Quot__Error->SetMarkerStyle(32);
  Energy_Quot__Error->SetLineColor(2);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Muon_200FJ,-1); Energy_Quot__Error->Add(Energy_Quot__Muon_200BTag,1); Energy_Quot__Error->Divide(Energy_Quot__Muon_200FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(22);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(4); Energy_Quot__Error->SetMarkerStyle(26);
  Energy_Quot__Error->SetLineColor(4);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Muon_200FJ,-1); Energy_Quot__Error->Add(Energy_Quot__Muon_200MinBias,1); Energy_Quot__Error->Divide(Energy_Quot__Muon_200FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(20);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(5); Energy_Quot__Error->SetMarkerStyle(24);
  Energy_Quot__Error->SetLineColor(5);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Muon_200FJ,-1); Energy_Quot__Error->Add(Energy_Quot__Muon_200MultiJet,1); Energy_Quot__Error->Divide(Energy_Quot__Muon_200FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(34);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(8); Energy_Quot__Error->SetMarkerStyle(28);
  Energy_Quot__Error->SetLineColor(8);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quotient__Muon_200Jet->Print("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient.pdf","pdf");
  Energy_Quotient__Muon_200Jet->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__Muon-200Jet.pdf"); Energy_Quotient__Muon_200Jet->Close();


  TCanvas* Energy_Quotient__Photon_Jet  = new TCanvas("Energy_Quotient__Photon_Jet ","Energy_Quotient__Photon_Jet ",0,0,3240,2160);
  TPad *H__Photon_Jet = new TPad("H__Photon_Jet","", 0, 0.25, 1, 1); H__Photon_Jet->SetMargin(0.11,0,0,0); H__Photon_Jet->SetLogy(); H__Photon_Jet->Draw();
  TPad *E__Photon_Jet = new TPad("E__Photon_Jet","", 0, 0, 1, 0.25); E__Photon_Jet->SetMargin(0.11,0,0.33,0); E__Photon_Jet->Draw(); H__Photon_Jet->cd();
  Energy_Quot__Photon_FJ->SetTitle("; ; #frac{1}{N_{Tot}} #frac{dN}{dE}");
  Energy_Quot__Photon_FJ->GetYaxis()->SetTitleSize(0.05); Energy_Quot__Photon_FJ->GetYaxis()->SetTitleOffset(1.0);
  Energy_Quot__Photon_FJ->GetYaxis()->SetLabelSize(0.05); Energy_Quot__Photon_FJ->SetAxisRange(0.0, 1.04, "X");
  Energy_Quot__Photon_FJ->SetMarkerSize(6); Energy_Quot__Photon_FJ->SetMarkerColor(14); Energy_Quot__Photon_FJ->SetMarkerStyle(21);
  Energy_Quot__Photon_FJ->DrawCopy("P");    Energy_Quot__Photon_FJ->SetMarkerColor(1);  Energy_Quot__Photon_FJ->SetMarkerStyle(25);
  Energy_Quot__Photon_FJ->SetLineWidth(2);  Energy_Quot__Photon_FJ->SetLineColor(1);    Energy_Quot__Photon_FJ->DrawCopy("Esame");
  Energy_Quot__Photon_Jet ->SetMarkerSize(6);  Energy_Quot__Photon_Jet ->SetMarkerColor(42);Energy_Quot__Photon_Jet ->SetMarkerStyle(23);
  Energy_Quot__Photon_Jet ->DrawCopy("Psame"); Energy_Quot__Photon_Jet ->SetMarkerColor(2); Energy_Quot__Photon_Jet ->SetMarkerStyle(32);
  Energy_Quot__Photon_Jet ->SetLineWidth(2);   Energy_Quot__Photon_Jet ->SetLineColor(2);   Energy_Quot__Photon_Jet ->DrawCopy("Esame");
  Energy_Quot__Photon_BTag->SetMarkerSize(6);  Energy_Quot__Photon_BTag->SetMarkerColor(33);Energy_Quot__Photon_BTag->SetMarkerStyle(22);
  Energy_Quot__Photon_BTag->DrawCopy("Psame"); Energy_Quot__Photon_BTag->SetMarkerColor(4); Energy_Quot__Photon_BTag->SetMarkerStyle(26);
  Energy_Quot__Photon_BTag->SetLineWidth(2);   Energy_Quot__Photon_BTag->SetLineColor(4);   Energy_Quot__Photon_BTag->DrawCopy("Esame");
  Energy_Quot__Photon_MinBias->SetMarkerSize(6);  Energy_Quot__Photon_MinBias->SetMarkerColor(5); Energy_Quot__Photon_MinBias->SetMarkerStyle(20);
  Energy_Quot__Photon_MinBias->DrawCopy("Psame"); Energy_Quot__Photon_MinBias->SetMarkerColor(41);Energy_Quot__Photon_MinBias->SetMarkerStyle(24);
  Energy_Quot__Photon_MinBias->SetLineWidth(2);   Energy_Quot__Photon_MinBias->SetLineColor(41);  Energy_Quot__Photon_MinBias->DrawCopy("Esame");
  Energy_Quot__Photon_MultiJet->SetMarkerSize(6);  Energy_Quot__Photon_MultiJet->SetMarkerColor(8); Energy_Quot__Photon_MultiJet->SetMarkerStyle(34);
  Energy_Quot__Photon_MultiJet->DrawCopy("Psame"); Energy_Quot__Photon_MultiJet->SetMarkerColor(32);Energy_Quot__Photon_MultiJet->SetMarkerStyle(28);
  Energy_Quot__Photon_MultiJet->SetLineWidth(2);   Energy_Quot__Photon_MultiJet->SetLineColor(32);  Energy_Quot__Photon_MultiJet->DrawCopy("Esame");
  Leg->Draw(); Legend->Draw(); E__Photon_Jet->cd();
  Cero->SetTitle(";E^{Fot#acute{o}n}/E^{Jet};#xi"); Cero->Draw(); Cero->GetYaxis()->SetRangeUser(-0.4,0.4);
  Energy_Quot__Error->Add(Energy_Quot__Photon_FJ,-1); Energy_Quot__Error->Add(Energy_Quot__Photon_Jet ,1); Energy_Quot__Error->Divide(Energy_Quot__Photon_FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(23);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(2); Energy_Quot__Error->SetMarkerStyle(32);
  Energy_Quot__Error->SetLineColor(2);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Photon_FJ,-1); Energy_Quot__Error->Add(Energy_Quot__Photon_BTag,1); Energy_Quot__Error->Divide(Energy_Quot__Photon_FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(22);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(4); Energy_Quot__Error->SetMarkerStyle(26);
  Energy_Quot__Error->SetLineColor(4);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Photon_FJ,-1); Energy_Quot__Error->Add(Energy_Quot__Photon_MinBias,1); Energy_Quot__Error->Divide(Energy_Quot__Photon_FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(20);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(5); Energy_Quot__Error->SetMarkerStyle(24);
  Energy_Quot__Error->SetLineColor(5);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Photon_FJ,-1); Energy_Quot__Error->Add(Energy_Quot__Photon_MultiJet,1); Energy_Quot__Error->Divide(Energy_Quot__Photon_FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(34);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(8); Energy_Quot__Error->SetMarkerStyle(28);
  Energy_Quot__Error->SetLineColor(8);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quotient__Photon_Jet->Print("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient.pdf","pdf");
  Energy_Quotient__Photon_Jet->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__Photon-Jet.pdf"); Energy_Quotient__Photon_Jet->Close();


  TH1F *Energy_Quot__Photon_FJ200 = new TH1F("Energy_Quot__Photon_FJ200", ";;", 120, 0, 1.2);   Energy_Quot__Photon_FJ200->Rebin();
  Energy_Quot__Photon_FJ200->Add(Energy_Quot__Photon_0FJ100,1);
  TH1F *Energy_Quot__Photon_Jet200 = new TH1F("Energy_Quot__Photon_Jet200", ";;", 120, 0, 1.2);   Energy_Quot__Photon_Jet200->Rebin();
  Energy_Quot__Photon_Jet200->Add(Energy_Quot__Photon_0Jet100,1);
  TH1F *Energy_Quot__Photon_BTag200 = new TH1F("Energy_Quot__Photon_BTag200", ";;", 120, 0, 1.2);   Energy_Quot__Photon_BTag200->Rebin();
  Energy_Quot__Photon_BTag200->Add(Energy_Quot__Photon_0BTag100,1);
  TH1F *Energy_Quot__Photon_MinBias200 = new TH1F("Energy_Quot__Photon_MinBias200", ";;", 120, 0, 1.2);   Energy_Quot__Photon_MinBias200->Rebin();
  Energy_Quot__Photon_MinBias200->Add(Energy_Quot__Photon_0MinBias100,1);
  TH1F *Energy_Quot__Photon_MultiJet200 = new TH1F("Energy_Quot__Photon_MultiJet200", ";;", 120, 0, 1.2);   Energy_Quot__Photon_MultiJet200->Rebin();
  Energy_Quot__Photon_MultiJet200->Add(Energy_Quot__Photon_0MultiJet100,1);

  TCanvas* Energy_Quotient__Photon_Jet200  = new TCanvas("Energy_Quotient__Photon_Jet200 ","Energy_Quotient__Photon_Jet200 ",0,0,3240,2160);
  TPad *H__Photon_Jet200 = new TPad("H__Photon_Jet200","", 0, 0.25, 1, 1); H__Photon_Jet200->SetMargin(0.11,0,0,0); H__Photon_Jet200->SetLogy(); H__Photon_Jet200->Draw();
  TPad *E__Photon_Jet200 = new TPad("E__Photon_Jet200","", 0, 0, 1, 0.25); E__Photon_Jet200->SetMargin(0.11,0,0.33,0); E__Photon_Jet200->Draw(); H__Photon_Jet200->cd();
  Energy_Quot__Photon_FJ200->SetTitle("; ; #frac{1}{N_{Tot}} #frac{dN}{dE}");
  Energy_Quot__Photon_FJ200->GetYaxis()->SetTitleSize(0.05); Energy_Quot__Photon_FJ200->GetYaxis()->SetTitleOffset(1.0);
  Energy_Quot__Photon_FJ200->GetYaxis()->SetLabelSize(0.05); Energy_Quot__Photon_FJ200->SetAxisRange(0.0, 1.04, "X");
  Energy_Quot__Photon_FJ200->SetMarkerSize(6); Energy_Quot__Photon_FJ200->SetMarkerColor(14); Energy_Quot__Photon_FJ200->SetMarkerStyle(21);
  Energy_Quot__Photon_FJ200->DrawCopy("P");    Energy_Quot__Photon_FJ200->SetMarkerColor(1);  Energy_Quot__Photon_FJ200->SetMarkerStyle(25);
  Energy_Quot__Photon_FJ200->SetLineWidth(2);  Energy_Quot__Photon_FJ200->SetLineColor(1);    Energy_Quot__Photon_FJ200->DrawCopy("Esame");
  Energy_Quot__Photon_Jet200 ->SetMarkerSize(6);  Energy_Quot__Photon_Jet200 ->SetMarkerColor(42);Energy_Quot__Photon_Jet200 ->SetMarkerStyle(23);
  Energy_Quot__Photon_Jet200 ->DrawCopy("Psame"); Energy_Quot__Photon_Jet200 ->SetMarkerColor(2); Energy_Quot__Photon_Jet200 ->SetMarkerStyle(32);
  Energy_Quot__Photon_Jet200 ->SetLineWidth(2);   Energy_Quot__Photon_Jet200 ->SetLineColor(2);   Energy_Quot__Photon_Jet200 ->DrawCopy("Esame");
  Energy_Quot__Photon_BTag200->SetMarkerSize(6);  Energy_Quot__Photon_BTag200->SetMarkerColor(33);Energy_Quot__Photon_BTag200->SetMarkerStyle(22);
  Energy_Quot__Photon_BTag200->DrawCopy("Psame"); Energy_Quot__Photon_BTag200->SetMarkerColor(4); Energy_Quot__Photon_BTag200->SetMarkerStyle(26);
  Energy_Quot__Photon_BTag200->SetLineWidth(2);   Energy_Quot__Photon_BTag200->SetLineColor(4);   Energy_Quot__Photon_BTag200->DrawCopy("Esame");
  Energy_Quot__Photon_MinBias200->SetMarkerSize(6);  Energy_Quot__Photon_MinBias200->SetMarkerColor(5); Energy_Quot__Photon_MinBias200->SetMarkerStyle(20);
  Energy_Quot__Photon_MinBias200->DrawCopy("Psame"); Energy_Quot__Photon_MinBias200->SetMarkerColor(41);Energy_Quot__Photon_MinBias200->SetMarkerStyle(24);
  Energy_Quot__Photon_MinBias200->SetLineWidth(2);   Energy_Quot__Photon_MinBias200->SetLineColor(41);  Energy_Quot__Photon_MinBias200->DrawCopy("Esame");
  Energy_Quot__Photon_MultiJet200->SetMarkerSize(6);  Energy_Quot__Photon_MultiJet200->SetMarkerColor(8); Energy_Quot__Photon_MultiJet200->SetMarkerStyle(34);
  Energy_Quot__Photon_MultiJet200->DrawCopy("Psame"); Energy_Quot__Photon_MultiJet200->SetMarkerColor(32);Energy_Quot__Photon_MultiJet200->SetMarkerStyle(28);
  Energy_Quot__Photon_MultiJet200->SetLineWidth(2);   Energy_Quot__Photon_MultiJet200->SetLineColor(32);  Energy_Quot__Photon_MultiJet200->DrawCopy("Esame");
  Leg->Draw(); Legend->Draw(); E__Photon_Jet200->cd();
  Cero->SetTitle(";E^{Fot#acute{o}n}/E^{Jet}, E^{Jet}<200;#xi"); Cero->Draw();
  Energy_Quot__Error->Add(Energy_Quot__Photon_FJ200,-1); Energy_Quot__Error->Add(Energy_Quot__Photon_Jet200 ,1); Energy_Quot__Error->Divide(Energy_Quot__Photon_FJ200);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(23);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(2); Energy_Quot__Error->SetMarkerStyle(32);
  Energy_Quot__Error->SetLineColor(2);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Photon_FJ200,-1); Energy_Quot__Error->Add(Energy_Quot__Photon_BTag200,1); Energy_Quot__Error->Divide(Energy_Quot__Photon_FJ200);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(22);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(4); Energy_Quot__Error->SetMarkerStyle(26);
  Energy_Quot__Error->SetLineColor(4);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Photon_FJ200,-1); Energy_Quot__Error->Add(Energy_Quot__Photon_MinBias200,1); Energy_Quot__Error->Divide(Energy_Quot__Photon_FJ200);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(20);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(5); Energy_Quot__Error->SetMarkerStyle(24);
  Energy_Quot__Error->SetLineColor(5);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Photon_FJ200,-1); Energy_Quot__Error->Add(Energy_Quot__Photon_MultiJet200,1); Energy_Quot__Error->Divide(Energy_Quot__Photon_FJ200);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(34);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(8); Energy_Quot__Error->SetMarkerStyle(28);
  Energy_Quot__Error->SetLineColor(8);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quotient__Photon_Jet200->Print("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient.pdf","pdf");
  Energy_Quotient__Photon_Jet200->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__Photon-Jet200.pdf"); Energy_Quotient__Photon_Jet200->Close();


  TH1F *Energy_Quot__Photon_200FJ = new TH1F("Energy_Quot__Photon_FJ200", ";;", 120, 0, 1.2);   Energy_Quot__Photon_200FJ->Rebin();
  Energy_Quot__Photon_200FJ->Add(Energy_Quot__Photon_200FJ300,1);
  TH1F *Energy_Quot__Photon_200Jet = new TH1F("Energy_Quot__Photon_Jet200", ";;", 120, 0, 1.2);   Energy_Quot__Photon_200Jet->Rebin();
  Energy_Quot__Photon_200Jet->Add(Energy_Quot__Photon_200Jet300,1);
  TH1F *Energy_Quot__Photon_200BTag = new TH1F("Energy_Quot__Photon_BTag200", ";;", 120, 0, 1.2);   Energy_Quot__Photon_200BTag->Rebin();
  Energy_Quot__Photon_200BTag->Add(Energy_Quot__Photon_200BTag300,1);
  TH1F *Energy_Quot__Photon_200MinBias = new TH1F("Energy_Quot__Photon_MinBias200", ";;", 120, 0, 1.2);   Energy_Quot__Photon_200MinBias->Rebin();
  Energy_Quot__Photon_200MinBias->Add(Energy_Quot__Photon_200MinBias300,1);
  TH1F *Energy_Quot__Photon_200MultiJet = new TH1F("Energy_Quot__Photon_MultiJet200", ";;", 120, 0, 1.2);   Energy_Quot__Photon_200MultiJet->Rebin();
  Energy_Quot__Photon_200MultiJet->Add(Energy_Quot__Photon_200MultiJet300,1);

  TCanvas* Energy_Quotient__Photon_200Jet = new TCanvas("Energy_Quotient__Photon_200Jet","Energy_Quotient__Photon_200Jet",0,0,3240,2160);
  TPad *H__Photon_200Jet = new TPad("H__Photon_200Jet","", 0, 0.25, 1, 1); H__Photon_200Jet->SetMargin(0.11,0,0,0); H__Photon_200Jet->SetLogy(); H__Photon_200Jet->Draw();
  TPad *E__Photon_200Jet = new TPad("E__Photon_200Jet","", 0, 0, 1, 0.25); E__Photon_200Jet->SetMargin(0.11,0,0.33,0); E__Photon_200Jet->Draw(); H__Photon_200Jet->cd();
  Energy_Quot__Photon_200FJ->SetTitle("; ; #frac{1}{N_{Tot}} #frac{dN}{dE}");
  Energy_Quot__Photon_200FJ->GetYaxis()->SetTitleSize(0.05); Energy_Quot__Photon_200FJ->GetYaxis()->SetTitleOffset(1.0);
  Energy_Quot__Photon_200FJ->GetYaxis()->SetLabelSize(0.05); Energy_Quot__Photon_200FJ->SetAxisRange(0.0, 1.04, "X");
  Energy_Quot__Photon_200FJ->SetMarkerSize(6); Energy_Quot__Photon_200FJ->SetMarkerColor(14); Energy_Quot__Photon_200FJ->SetMarkerStyle(21);
  Energy_Quot__Photon_200FJ->DrawCopy("P");    Energy_Quot__Photon_200FJ->SetMarkerColor(1);  Energy_Quot__Photon_200FJ->SetMarkerStyle(25);
  Energy_Quot__Photon_200FJ->SetLineWidth(2);  Energy_Quot__Photon_200FJ->SetLineColor(1);    Energy_Quot__Photon_200FJ->DrawCopy("Esame");
  Energy_Quot__Photon_200Jet->SetMarkerSize(6);  Energy_Quot__Photon_200Jet->SetMarkerColor(42);Energy_Quot__Photon_200Jet->SetMarkerStyle(23);
  Energy_Quot__Photon_200Jet->DrawCopy("Psame"); Energy_Quot__Photon_200Jet->SetMarkerColor(2); Energy_Quot__Photon_200Jet->SetMarkerStyle(32);
  Energy_Quot__Photon_200Jet->SetLineWidth(2);   Energy_Quot__Photon_200Jet->SetLineColor(2);   Energy_Quot__Photon_200Jet->DrawCopy("Esame");
  Energy_Quot__Photon_200BTag->SetMarkerSize(6);  Energy_Quot__Photon_200BTag->SetMarkerColor(33);Energy_Quot__Photon_200BTag->SetMarkerStyle(22);
  Energy_Quot__Photon_200BTag->DrawCopy("Psame"); Energy_Quot__Photon_200BTag->SetMarkerColor(4); Energy_Quot__Photon_200BTag->SetMarkerStyle(26);
  Energy_Quot__Photon_200BTag->SetLineWidth(2);   Energy_Quot__Photon_200BTag->SetLineColor(4);   Energy_Quot__Photon_200BTag->DrawCopy("Esame");
  Energy_Quot__Photon_200MinBias->SetMarkerSize(6);  Energy_Quot__Photon_200MinBias->SetMarkerColor(5); Energy_Quot__Photon_200MinBias->SetMarkerStyle(20);
  Energy_Quot__Photon_200MinBias->DrawCopy("Psame"); Energy_Quot__Photon_200MinBias->SetMarkerColor(41);Energy_Quot__Photon_200MinBias->SetMarkerStyle(24);
  Energy_Quot__Photon_200MinBias->SetLineWidth(2);   Energy_Quot__Photon_200MinBias->SetLineColor(41);  Energy_Quot__Photon_200MinBias->DrawCopy("Esame");
  Energy_Quot__Photon_200MultiJet->SetMarkerSize(6);  Energy_Quot__Photon_200MultiJet->SetMarkerColor(8); Energy_Quot__Photon_200MultiJet->SetMarkerStyle(34);
  Energy_Quot__Photon_200MultiJet->DrawCopy("Psame"); Energy_Quot__Photon_200MultiJet->SetMarkerColor(32);Energy_Quot__Photon_200MultiJet->SetMarkerStyle(28);
  Energy_Quot__Photon_200MultiJet->SetLineWidth(2);   Energy_Quot__Photon_200MultiJet->SetLineColor(32);  Energy_Quot__Photon_200MultiJet->DrawCopy("Esame");
  Leg->Draw(); Legend->Draw(); E__Photon_200Jet->cd();
  Cero->SetTitle(";E^{Fot#acute{o}n}/E^{Jet}, E^{Jet}>200;#xi"); Cero->Draw();
  Energy_Quot__Error->Add(Energy_Quot__Photon_200FJ,-1); Energy_Quot__Error->Add(Energy_Quot__Photon_200Jet,1); Energy_Quot__Error->Divide(Energy_Quot__Photon_200FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(23);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(2); Energy_Quot__Error->SetMarkerStyle(32);
  Energy_Quot__Error->SetLineColor(2);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Photon_200FJ,-1); Energy_Quot__Error->Add(Energy_Quot__Photon_200BTag,1); Energy_Quot__Error->Divide(Energy_Quot__Photon_200FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(22);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(4); Energy_Quot__Error->SetMarkerStyle(26);
  Energy_Quot__Error->SetLineColor(4);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Photon_200FJ,-1); Energy_Quot__Error->Add(Energy_Quot__Photon_200MinBias,1); Energy_Quot__Error->Divide(Energy_Quot__Photon_200FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(20);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(5); Energy_Quot__Error->SetMarkerStyle(24);
  Energy_Quot__Error->SetLineColor(5);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Photon_200FJ,-1); Energy_Quot__Error->Add(Energy_Quot__Photon_200MultiJet,1); Energy_Quot__Error->Divide(Energy_Quot__Photon_200FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(34);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(8); Energy_Quot__Error->SetMarkerStyle(28);
  Energy_Quot__Error->SetLineColor(8);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quotient__Photon_200Jet->Print("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient.pdf","pdf");
  Energy_Quotient__Photon_200Jet->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__Photon-200Jet.pdf"); Energy_Quotient__Photon_200Jet->Close();


  TCanvas* Energy_Quotient__Electron_Jet  = new TCanvas("Energy_Quotient__Electron_Jet ","Energy_Quotient__Electron_Jet ",0,0,3240,2160);
  TPad *H__Electron_Jet = new TPad("H__Electron_Jet","", 0, 0.25, 1, 1); H__Electron_Jet->SetMargin(0.11,0,0,0); H__Electron_Jet->SetLogy(); H__Electron_Jet->Draw();
  TPad *E__Electron_Jet = new TPad("E__Electron_Jet","", 0, 0, 1, 0.25); E__Electron_Jet->SetMargin(0.11,0,0.33,0); E__Electron_Jet->Draw(); H__Electron_Jet->cd();
  Energy_Quot__Electron_FJ->SetTitle("; ; #frac{1}{N_{Tot}} #frac{dN}{dE}");
  Energy_Quot__Electron_FJ->GetYaxis()->SetTitleSize(0.05); Energy_Quot__Electron_FJ->GetYaxis()->SetTitleOffset(1.0);
  Energy_Quot__Electron_FJ->GetYaxis()->SetLabelSize(0.05); Energy_Quot__Electron_FJ->SetAxisRange(0.0, 1.04, "X");
  Energy_Quot__Electron_FJ->SetMarkerSize(6); Energy_Quot__Electron_FJ->SetMarkerColor(14); Energy_Quot__Electron_FJ->SetMarkerStyle(21);
  Energy_Quot__Electron_FJ->DrawCopy("P");    Energy_Quot__Electron_FJ->SetMarkerColor(1);  Energy_Quot__Electron_FJ->SetMarkerStyle(25);
  Energy_Quot__Electron_FJ->SetLineWidth(2);  Energy_Quot__Electron_FJ->SetLineColor(1);    Energy_Quot__Electron_FJ->DrawCopy("Esame");
  Energy_Quot__Electron_Jet ->SetMarkerSize(6);  Energy_Quot__Electron_Jet ->SetMarkerColor(42);Energy_Quot__Electron_Jet ->SetMarkerStyle(23);
  Energy_Quot__Electron_Jet ->DrawCopy("Psame"); Energy_Quot__Electron_Jet ->SetMarkerColor(2); Energy_Quot__Electron_Jet ->SetMarkerStyle(32);
  Energy_Quot__Electron_Jet ->SetLineWidth(2);   Energy_Quot__Electron_Jet ->SetLineColor(2);   Energy_Quot__Electron_Jet ->DrawCopy("Esame");
  Energy_Quot__Electron_BTag->SetMarkerSize(6);  Energy_Quot__Electron_BTag->SetMarkerColor(33);Energy_Quot__Electron_BTag->SetMarkerStyle(22);
  Energy_Quot__Electron_BTag->DrawCopy("Psame"); Energy_Quot__Electron_BTag->SetMarkerColor(4); Energy_Quot__Electron_BTag->SetMarkerStyle(26);
  Energy_Quot__Electron_BTag->SetLineWidth(2);   Energy_Quot__Electron_BTag->SetLineColor(4);   Energy_Quot__Electron_BTag->DrawCopy("Esame");
  Energy_Quot__Electron_MinBias->SetMarkerSize(6);  Energy_Quot__Electron_MinBias->SetMarkerColor(5); Energy_Quot__Electron_MinBias->SetMarkerStyle(20);
  Energy_Quot__Electron_MinBias->DrawCopy("Psame"); Energy_Quot__Electron_MinBias->SetMarkerColor(41);Energy_Quot__Electron_MinBias->SetMarkerStyle(24);
  Energy_Quot__Electron_MinBias->SetLineWidth(2);   Energy_Quot__Electron_MinBias->SetLineColor(41);  Energy_Quot__Electron_MinBias->DrawCopy("Esame");
  Energy_Quot__Electron_MultiJet->SetMarkerSize(6);  Energy_Quot__Electron_MultiJet->SetMarkerColor(8); Energy_Quot__Electron_MultiJet->SetMarkerStyle(34);
  Energy_Quot__Electron_MultiJet->DrawCopy("Psame"); Energy_Quot__Electron_MultiJet->SetMarkerColor(32);Energy_Quot__Electron_MultiJet->SetMarkerStyle(28);
  Energy_Quot__Electron_MultiJet->SetLineWidth(2);   Energy_Quot__Electron_MultiJet->SetLineColor(32);  Energy_Quot__Electron_MultiJet->DrawCopy("Esame");
  Leg->Draw(); Legend->Draw(); E__Electron_Jet->cd();
  Cero->SetTitle(";E^{Electr#acute{o}n}/E^{Jet};#xi"); Cero->Draw();
  Energy_Quot__Error->Add(Energy_Quot__Electron_FJ,-1); Energy_Quot__Error->Add(Energy_Quot__Electron_Jet ,1); Energy_Quot__Error->Divide(Energy_Quot__Electron_FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(23);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(2); Energy_Quot__Error->SetMarkerStyle(32);
  Energy_Quot__Error->SetLineColor(2);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Electron_FJ,-1); Energy_Quot__Error->Add(Energy_Quot__Electron_BTag,1); Energy_Quot__Error->Divide(Energy_Quot__Electron_FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(22);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(4); Energy_Quot__Error->SetMarkerStyle(26);
  Energy_Quot__Error->SetLineColor(4);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Electron_FJ,-1); Energy_Quot__Error->Add(Energy_Quot__Electron_MinBias,1); Energy_Quot__Error->Divide(Energy_Quot__Electron_FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(20);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(5); Energy_Quot__Error->SetMarkerStyle(24);
  Energy_Quot__Error->SetLineColor(5);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Electron_FJ,-1); Energy_Quot__Error->Add(Energy_Quot__Electron_MultiJet,1); Energy_Quot__Error->Divide(Energy_Quot__Electron_FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(34);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(8); Energy_Quot__Error->SetMarkerStyle(28);
  Energy_Quot__Error->SetLineColor(8);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quotient__Electron_Jet->Print("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient.pdf","pdf");
  Energy_Quotient__Electron_Jet->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__Electron-Jet.pdf"); Energy_Quotient__Electron_Jet->Close();


  TH1F *Energy_Quot__Electron_FJ200 = new TH1F("Energy_Quot__Electron_FJ200", ";;", 120, 0, 1.2);   Energy_Quot__Electron_FJ200->Rebin();
  Energy_Quot__Electron_FJ200->Add(Energy_Quot__Electron_0FJ100,1);
  TH1F *Energy_Quot__Electron_Jet200 = new TH1F("Energy_Quot__Electron_Jet200", ";;", 120, 0, 1.2);   Energy_Quot__Electron_Jet200->Rebin();
  Energy_Quot__Electron_Jet200->Add(Energy_Quot__Electron_0Jet100,1);
  TH1F *Energy_Quot__Electron_BTag200 = new TH1F("Energy_Quot__Electron_BTag200", ";;", 120, 0, 1.2);   Energy_Quot__Electron_BTag200->Rebin();
  Energy_Quot__Electron_BTag200->Add(Energy_Quot__Electron_0BTag100,1);
  TH1F *Energy_Quot__Electron_MinBias200 = new TH1F("Energy_Quot__Electron_MinBias200", ";;", 120, 0, 1.2);   Energy_Quot__Electron_MinBias200->Rebin();
  Energy_Quot__Electron_MinBias200->Add(Energy_Quot__Electron_0MinBias100,1);
  TH1F *Energy_Quot__Electron_MultiJet200 = new TH1F("Energy_Quot__Electron_MultiJet200", ";;", 120, 0, 1.2);   Energy_Quot__Electron_MultiJet200->Rebin();
  Energy_Quot__Electron_MultiJet200->Add(Energy_Quot__Electron_0MultiJet100,1);

  TCanvas* Energy_Quotient__Electron_Jet200  = new TCanvas("Energy_Quotient__Electron_Jet200 ","Energy_Quotient__Electron_Jet200 ",0,0,3240,2160);
  TPad *H__Electron_Jet200 = new TPad("H__Electron_Jet200","", 0, 0.25, 1, 1); H__Electron_Jet200->SetMargin(0.11,0,0,0); H__Electron_Jet200->SetLogy(); H__Electron_Jet200->Draw();
  TPad *E__Electron_Jet200 = new TPad("E__Electron_Jet200","", 0, 0, 1, 0.25); E__Electron_Jet200->SetMargin(0.11,0,0.33,0); E__Electron_Jet200->Draw(); H__Electron_Jet200->cd();
  Energy_Quot__Electron_FJ200->SetTitle("; ; #frac{1}{N_{Tot}} #frac{dN}{dE}");
  Energy_Quot__Electron_FJ200->GetYaxis()->SetTitleSize(0.05); Energy_Quot__Electron_FJ200->GetYaxis()->SetTitleOffset(1.0);
  Energy_Quot__Electron_FJ200->GetYaxis()->SetLabelSize(0.05); Energy_Quot__Electron_FJ200->SetAxisRange(0.0, 1.04, "X");
  Energy_Quot__Electron_FJ200->SetMarkerSize(6); Energy_Quot__Electron_FJ200->SetMarkerColor(14); Energy_Quot__Electron_FJ200->SetMarkerStyle(21);
  Energy_Quot__Electron_FJ200->DrawCopy("P");    Energy_Quot__Electron_FJ200->SetMarkerColor(1);  Energy_Quot__Electron_FJ200->SetMarkerStyle(25);
  Energy_Quot__Electron_FJ200->SetLineWidth(2);  Energy_Quot__Electron_FJ200->SetLineColor(1);    Energy_Quot__Electron_FJ200->DrawCopy("Esame");
  Energy_Quot__Electron_Jet200 ->SetMarkerSize(6);  Energy_Quot__Electron_Jet200 ->SetMarkerColor(42);Energy_Quot__Electron_Jet200 ->SetMarkerStyle(23);
  Energy_Quot__Electron_Jet200 ->DrawCopy("Psame"); Energy_Quot__Electron_Jet200 ->SetMarkerColor(2); Energy_Quot__Electron_Jet200 ->SetMarkerStyle(32);
  Energy_Quot__Electron_Jet200 ->SetLineWidth(2);   Energy_Quot__Electron_Jet200 ->SetLineColor(2);   Energy_Quot__Electron_Jet200 ->DrawCopy("Esame");
  Energy_Quot__Electron_BTag200->SetMarkerSize(6);  Energy_Quot__Electron_BTag200->SetMarkerColor(33);Energy_Quot__Electron_BTag200->SetMarkerStyle(22);
  Energy_Quot__Electron_BTag200->DrawCopy("Psame"); Energy_Quot__Electron_BTag200->SetMarkerColor(4); Energy_Quot__Electron_BTag200->SetMarkerStyle(26);
  Energy_Quot__Electron_BTag200->SetLineWidth(2);   Energy_Quot__Electron_BTag200->SetLineColor(4);   Energy_Quot__Electron_BTag200->DrawCopy("Esame");
  Energy_Quot__Electron_MinBias200->SetMarkerSize(6);  Energy_Quot__Electron_MinBias200->SetMarkerColor(5); Energy_Quot__Electron_MinBias200->SetMarkerStyle(20);
  Energy_Quot__Electron_MinBias200->DrawCopy("Psame"); Energy_Quot__Electron_MinBias200->SetMarkerColor(41);Energy_Quot__Electron_MinBias200->SetMarkerStyle(24);
  Energy_Quot__Electron_MinBias200->SetLineWidth(2);   Energy_Quot__Electron_MinBias200->SetLineColor(41);  Energy_Quot__Electron_MinBias200->DrawCopy("Esame");
  Energy_Quot__Electron_MultiJet200->SetMarkerSize(6);  Energy_Quot__Electron_MultiJet200->SetMarkerColor(8); Energy_Quot__Electron_MultiJet200->SetMarkerStyle(34);
  Energy_Quot__Electron_MultiJet200->DrawCopy("Psame"); Energy_Quot__Electron_MultiJet200->SetMarkerColor(32);Energy_Quot__Electron_MultiJet200->SetMarkerStyle(28);
  Energy_Quot__Electron_MultiJet200->SetLineWidth(2);   Energy_Quot__Electron_MultiJet200->SetLineColor(32);  Energy_Quot__Electron_MultiJet200->DrawCopy("Esame");
  Leg->Draw(); Legend->Draw(); E__Electron_Jet200->cd();
  Cero->SetTitle(";E^{Electr#acute{o}n}/E^{Jet}, E^{Jet}<200;#xi"); Cero->Draw();
  Energy_Quot__Error->Add(Energy_Quot__Electron_FJ200,-1); Energy_Quot__Error->Add(Energy_Quot__Electron_Jet200 ,1); Energy_Quot__Error->Divide(Energy_Quot__Electron_FJ200);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(23);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(2); Energy_Quot__Error->SetMarkerStyle(32);
  Energy_Quot__Error->SetLineColor(2);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Electron_FJ200,-1); Energy_Quot__Error->Add(Energy_Quot__Electron_BTag200,1); Energy_Quot__Error->Divide(Energy_Quot__Electron_FJ200);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(22);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(4); Energy_Quot__Error->SetMarkerStyle(26);
  Energy_Quot__Error->SetLineColor(4);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Electron_FJ200,-1); Energy_Quot__Error->Add(Energy_Quot__Electron_MinBias200,1); Energy_Quot__Error->Divide(Energy_Quot__Electron_FJ200);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(20);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(5); Energy_Quot__Error->SetMarkerStyle(24);
  Energy_Quot__Error->SetLineColor(5);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Electron_FJ200,-1); Energy_Quot__Error->Add(Energy_Quot__Electron_MultiJet200,1); Energy_Quot__Error->Divide(Energy_Quot__Electron_FJ200);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(34);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(8); Energy_Quot__Error->SetMarkerStyle(28);
  Energy_Quot__Error->SetLineColor(8);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quotient__Electron_Jet200->Print("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient.pdf","pdf");
  Energy_Quotient__Electron_Jet200->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__Electron-Jet200.pdf"); Energy_Quotient__Electron_Jet200->Close();


  TH1F *Energy_Quot__Electron_200FJ = new TH1F("Energy_Quot__Electron_FJ200", ";;", 120, 0, 1.2);   Energy_Quot__Electron_200FJ->Rebin();
  Energy_Quot__Electron_200FJ->Add(Energy_Quot__Electron_200FJ300,1);
  TH1F *Energy_Quot__Electron_200Jet = new TH1F("Energy_Quot__Electron_Jet200", ";;", 120, 0, 1.2);   Energy_Quot__Electron_200Jet->Rebin();
  Energy_Quot__Electron_200Jet->Add(Energy_Quot__Electron_200Jet300,1);
  TH1F *Energy_Quot__Electron_200BTag = new TH1F("Energy_Quot__Electron_BTag200", ";;", 120, 0, 1.2);   Energy_Quot__Electron_200BTag->Rebin();
  Energy_Quot__Electron_200BTag->Add(Energy_Quot__Electron_200BTag300,1);
  TH1F *Energy_Quot__Electron_200MinBias = new TH1F("Energy_Quot__Electron_MinBias200", ";;", 120, 0, 1.2);   Energy_Quot__Electron_200MinBias->Rebin();
  Energy_Quot__Electron_200MinBias->Add(Energy_Quot__Electron_200MinBias300,1);
  TH1F *Energy_Quot__Electron_200MultiJet = new TH1F("Energy_Quot__Electron_MultiJet200", ";;", 120, 0, 1.2);   Energy_Quot__Electron_200MultiJet->Rebin();
  Energy_Quot__Electron_200MultiJet->Add(Energy_Quot__Electron_200MultiJet300,1);

  TCanvas* Energy_Quotient__Electron_200Jet = new TCanvas("Energy_Quotient__Electron_200Jet","Energy_Quotient__Electron_200Jet",0,0,3240,2160);
  TPad *H__Electron_200Jet = new TPad("H__Electron_200Jet","", 0, 0.25, 1, 1); H__Electron_200Jet->SetMargin(0.11,0,0,0); H__Electron_200Jet->SetLogy(); H__Electron_200Jet->Draw();
  TPad *E__Electron_200Jet = new TPad("E__Electron_200Jet","", 0, 0, 1, 0.25); E__Electron_200Jet->SetMargin(0.11,0,0.33,0); E__Electron_200Jet->Draw(); H__Electron_200Jet->cd();
  Energy_Quot__Electron_200FJ->SetTitle("; ; #frac{1}{N_{Tot}} #frac{dN}{dE}");
  Energy_Quot__Electron_200FJ->GetYaxis()->SetTitleSize(0.05); Energy_Quot__Electron_200FJ->GetYaxis()->SetTitleOffset(1.0);
  Energy_Quot__Electron_200FJ->GetYaxis()->SetLabelSize(0.05); Energy_Quot__Electron_200FJ->SetAxisRange(0.0, 1.04, "X");
  Energy_Quot__Electron_200FJ->SetMarkerSize(6); Energy_Quot__Electron_200FJ->SetMarkerColor(14); Energy_Quot__Electron_200FJ->SetMarkerStyle(21);
  Energy_Quot__Electron_200FJ->DrawCopy("P");    Energy_Quot__Electron_200FJ->SetMarkerColor(1);  Energy_Quot__Electron_200FJ->SetMarkerStyle(25);
  Energy_Quot__Electron_200FJ->SetLineWidth(2);  Energy_Quot__Electron_200FJ->SetLineColor(1);    Energy_Quot__Electron_200FJ->DrawCopy("Esame");
  Energy_Quot__Electron_200Jet->SetMarkerSize(6);  Energy_Quot__Electron_200Jet->SetMarkerColor(42);Energy_Quot__Electron_200Jet->SetMarkerStyle(23);
  Energy_Quot__Electron_200Jet->DrawCopy("Psame"); Energy_Quot__Electron_200Jet->SetMarkerColor(2); Energy_Quot__Electron_200Jet->SetMarkerStyle(32);
  Energy_Quot__Electron_200Jet->SetLineWidth(2);   Energy_Quot__Electron_200Jet->SetLineColor(2);   Energy_Quot__Electron_200Jet->DrawCopy("Esame");
  Energy_Quot__Electron_200BTag->SetMarkerSize(6);  Energy_Quot__Electron_200BTag->SetMarkerColor(33);Energy_Quot__Electron_200BTag->SetMarkerStyle(22);
  Energy_Quot__Electron_200BTag->DrawCopy("Psame"); Energy_Quot__Electron_200BTag->SetMarkerColor(4); Energy_Quot__Electron_200BTag->SetMarkerStyle(26);
  Energy_Quot__Electron_200BTag->SetLineWidth(2);   Energy_Quot__Electron_200BTag->SetLineColor(4);   Energy_Quot__Electron_200BTag->DrawCopy("Esame");
  Energy_Quot__Electron_200MinBias->SetMarkerSize(6);  Energy_Quot__Electron_200MinBias->SetMarkerColor(5); Energy_Quot__Electron_200MinBias->SetMarkerStyle(20);
  Energy_Quot__Electron_200MinBias->DrawCopy("Psame"); Energy_Quot__Electron_200MinBias->SetMarkerColor(41);Energy_Quot__Electron_200MinBias->SetMarkerStyle(24);
  Energy_Quot__Electron_200MinBias->SetLineWidth(2);   Energy_Quot__Electron_200MinBias->SetLineColor(41);  Energy_Quot__Electron_200MinBias->DrawCopy("Esame");
  Energy_Quot__Electron_200MultiJet->SetMarkerSize(6);  Energy_Quot__Electron_200MultiJet->SetMarkerColor(8); Energy_Quot__Electron_200MultiJet->SetMarkerStyle(34);
  Energy_Quot__Electron_200MultiJet->DrawCopy("Psame"); Energy_Quot__Electron_200MultiJet->SetMarkerColor(32);Energy_Quot__Electron_200MultiJet->SetMarkerStyle(28);
  Energy_Quot__Electron_200MultiJet->SetLineWidth(2);   Energy_Quot__Electron_200MultiJet->SetLineColor(32);  Energy_Quot__Electron_200MultiJet->DrawCopy("Esame");
  Leg->Draw(); Legend->Draw(); E__Electron_200Jet->cd();
  Cero->SetTitle(";E^{Electr#acute{o}n}/E^{Jet}, E^{Jet}>200;#xi"); Cero->Draw(); Cero->GetYaxis()->SetRangeUser(-0.6,1.2);
  Energy_Quot__Error->Add(Energy_Quot__Electron_200FJ,-1); Energy_Quot__Error->Add(Energy_Quot__Electron_200Jet,1); Energy_Quot__Error->Divide(Energy_Quot__Electron_200FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(23);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(2); Energy_Quot__Error->SetMarkerStyle(32);
  Energy_Quot__Error->SetLineColor(2);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Electron_200FJ,-1); Energy_Quot__Error->Add(Energy_Quot__Electron_200BTag,1); Energy_Quot__Error->Divide(Energy_Quot__Electron_200FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(22);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(4); Energy_Quot__Error->SetMarkerStyle(26);
  Energy_Quot__Error->SetLineColor(4);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Electron_200FJ,-1); Energy_Quot__Error->Add(Energy_Quot__Electron_200MinBias,1); Energy_Quot__Error->Divide(Energy_Quot__Electron_200FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(20);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(5); Energy_Quot__Error->SetMarkerStyle(24);
  Energy_Quot__Error->SetLineColor(5);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__Electron_200FJ,-1); Energy_Quot__Error->Add(Energy_Quot__Electron_200MultiJet,1); Energy_Quot__Error->Divide(Energy_Quot__Electron_200FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(34);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(8); Energy_Quot__Error->SetMarkerStyle(28);
  Energy_Quot__Error->SetLineColor(8);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quotient__Electron_200Jet->Print("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient.pdf","pdf");
  Energy_Quotient__Electron_200Jet->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__Electron-200Jet.pdf"); Energy_Quotient__Electron_200Jet->Close();


  TCanvas* Energy_Quotient__NeutralHad_Jet  = new TCanvas("Energy_Quotient__NeutralHad_Jet ","Energy_Quotient__NeutralHad_Jet ",0,0,3240,2160);
  TPad *H__NeutralHad_Jet = new TPad("H__NeutralHad_Jet","", 0, 0.25, 1, 1); H__NeutralHad_Jet->SetMargin(0.11,0,0,0); H__NeutralHad_Jet->SetLogy(); H__NeutralHad_Jet->Draw();
  TPad *E__NeutralHad_Jet = new TPad("E__NeutralHad_Jet","", 0, 0, 1, 0.25); E__NeutralHad_Jet->SetMargin(0.11,0,0.33,0); E__NeutralHad_Jet->Draw(); H__NeutralHad_Jet->cd();
  Energy_Quot__NeutralHad_FJ->SetTitle("; ; #frac{1}{N_{Tot}} #frac{dN}{dE}");
  Energy_Quot__NeutralHad_FJ->GetYaxis()->SetTitleSize(0.05); Energy_Quot__NeutralHad_FJ->GetYaxis()->SetTitleOffset(1.0);
  Energy_Quot__NeutralHad_FJ->GetYaxis()->SetLabelSize(0.05); Energy_Quot__NeutralHad_FJ->SetAxisRange(0.0, 1.04, "X");
  Energy_Quot__NeutralHad_FJ->SetMarkerSize(6); Energy_Quot__NeutralHad_FJ->SetMarkerColor(14); Energy_Quot__NeutralHad_FJ->SetMarkerStyle(21);
  Energy_Quot__NeutralHad_FJ->DrawCopy("P");    Energy_Quot__NeutralHad_FJ->SetMarkerColor(1);  Energy_Quot__NeutralHad_FJ->SetMarkerStyle(25);
  Energy_Quot__NeutralHad_FJ->SetLineWidth(2);  Energy_Quot__NeutralHad_FJ->SetLineColor(1);    Energy_Quot__NeutralHad_FJ->DrawCopy("Esame");
  Energy_Quot__NeutralHad_Jet ->SetMarkerSize(6);  Energy_Quot__NeutralHad_Jet ->SetMarkerColor(42);Energy_Quot__NeutralHad_Jet ->SetMarkerStyle(23);
  Energy_Quot__NeutralHad_Jet ->DrawCopy("Psame"); Energy_Quot__NeutralHad_Jet ->SetMarkerColor(2); Energy_Quot__NeutralHad_Jet ->SetMarkerStyle(32);
  Energy_Quot__NeutralHad_Jet ->SetLineWidth(2);   Energy_Quot__NeutralHad_Jet ->SetLineColor(2);   Energy_Quot__NeutralHad_Jet ->DrawCopy("Esame");
  Energy_Quot__NeutralHad_BTag->SetMarkerSize(6);  Energy_Quot__NeutralHad_BTag->SetMarkerColor(33);Energy_Quot__NeutralHad_BTag->SetMarkerStyle(22);
  Energy_Quot__NeutralHad_BTag->DrawCopy("Psame"); Energy_Quot__NeutralHad_BTag->SetMarkerColor(4); Energy_Quot__NeutralHad_BTag->SetMarkerStyle(26);
  Energy_Quot__NeutralHad_BTag->SetLineWidth(2);   Energy_Quot__NeutralHad_BTag->SetLineColor(4);   Energy_Quot__NeutralHad_BTag->DrawCopy("Esame");
  Energy_Quot__NeutralHad_MinBias->SetMarkerSize(6);  Energy_Quot__NeutralHad_MinBias->SetMarkerColor(5); Energy_Quot__NeutralHad_MinBias->SetMarkerStyle(20);
  Energy_Quot__NeutralHad_MinBias->DrawCopy("Psame"); Energy_Quot__NeutralHad_MinBias->SetMarkerColor(41);Energy_Quot__NeutralHad_MinBias->SetMarkerStyle(24);
  Energy_Quot__NeutralHad_MinBias->SetLineWidth(2);   Energy_Quot__NeutralHad_MinBias->SetLineColor(41);  Energy_Quot__NeutralHad_MinBias->DrawCopy("Esame");
  Energy_Quot__NeutralHad_MultiJet->SetMarkerSize(6);  Energy_Quot__NeutralHad_MultiJet->SetMarkerColor(8); Energy_Quot__NeutralHad_MultiJet->SetMarkerStyle(34);
  Energy_Quot__NeutralHad_MultiJet->DrawCopy("Psame"); Energy_Quot__NeutralHad_MultiJet->SetMarkerColor(32);Energy_Quot__NeutralHad_MultiJet->SetMarkerStyle(28);
  Energy_Quot__NeutralHad_MultiJet->SetLineWidth(2);   Energy_Quot__NeutralHad_MultiJet->SetLineColor(32);  Energy_Quot__NeutralHad_MultiJet->DrawCopy("Esame");
  Leg->Draw(); Legend->Draw(); E__NeutralHad_Jet->cd();
  Cero->SetTitle(";E^{Hadr#acute{o}nNeutro}/E^{Jet};#xi"); Cero->Draw(); Cero->GetYaxis()->SetRangeUser(-0.8,0.8);
  Energy_Quot__Error->Add(Energy_Quot__NeutralHad_FJ,-1); Energy_Quot__Error->Add(Energy_Quot__NeutralHad_Jet ,1); Energy_Quot__Error->Divide(Energy_Quot__NeutralHad_FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(23);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(2); Energy_Quot__Error->SetMarkerStyle(32);
  Energy_Quot__Error->SetLineColor(2);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__NeutralHad_FJ,-1); Energy_Quot__Error->Add(Energy_Quot__NeutralHad_BTag,1); Energy_Quot__Error->Divide(Energy_Quot__NeutralHad_FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(22);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(4); Energy_Quot__Error->SetMarkerStyle(26);
  Energy_Quot__Error->SetLineColor(4);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__NeutralHad_FJ,-1); Energy_Quot__Error->Add(Energy_Quot__NeutralHad_MinBias,1); Energy_Quot__Error->Divide(Energy_Quot__NeutralHad_FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(20);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(5); Energy_Quot__Error->SetMarkerStyle(24);
  Energy_Quot__Error->SetLineColor(5);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__NeutralHad_FJ,-1); Energy_Quot__Error->Add(Energy_Quot__NeutralHad_MultiJet,1); Energy_Quot__Error->Divide(Energy_Quot__NeutralHad_FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(34);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(8); Energy_Quot__Error->SetMarkerStyle(28);
  Energy_Quot__Error->SetLineColor(8);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quotient__NeutralHad_Jet->Print("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient.pdf","pdf");
  Energy_Quotient__NeutralHad_Jet->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__NeutralHad-Jet.pdf"); Energy_Quotient__NeutralHad_Jet->Close();


  TH1F *Energy_Quot__NeutralHad_FJ200 = new TH1F("Energy_Quot__NeutralHad_FJ200", ";;", 120, 0, 1.2);   Energy_Quot__NeutralHad_FJ200->Rebin();
  Energy_Quot__NeutralHad_FJ200->Add(Energy_Quot__NeutralHad_0FJ100,1);
  TH1F *Energy_Quot__NeutralHad_Jet200 = new TH1F("Energy_Quot__NeutralHad_Jet200", ";;", 120, 0, 1.2);   Energy_Quot__NeutralHad_Jet200->Rebin();
  Energy_Quot__NeutralHad_Jet200->Add(Energy_Quot__NeutralHad_0Jet100,1);
  TH1F *Energy_Quot__NeutralHad_BTag200 = new TH1F("Energy_Quot__NeutralHad_BTag200", ";;", 120, 0, 1.2);   Energy_Quot__NeutralHad_BTag200->Rebin();
  Energy_Quot__NeutralHad_BTag200->Add(Energy_Quot__NeutralHad_0BTag100,1);
  TH1F *Energy_Quot__NeutralHad_MinBias200 = new TH1F("Energy_Quot__NeutralHad_MinBias200", ";;", 120, 0, 1.2);   Energy_Quot__NeutralHad_MinBias200->Rebin();
  Energy_Quot__NeutralHad_MinBias200->Add(Energy_Quot__NeutralHad_0MinBias100,1);
  TH1F *Energy_Quot__NeutralHad_MultiJet200 = new TH1F("Energy_Quot__NeutralHad_MultiJet200", ";;", 120, 0, 1.2);   Energy_Quot__NeutralHad_MultiJet200->Rebin();
  Energy_Quot__NeutralHad_MultiJet200->Add(Energy_Quot__NeutralHad_0MultiJet100,1);

  TCanvas* Energy_Quotient__NeutralHad_Jet200  = new TCanvas("Energy_Quotient__NeutralHad_Jet200 ","Energy_Quotient__NeutralHad_Jet200 ",0,0,3240,2160);
  TPad *H__NeutralHad_Jet200 = new TPad("H__NeutralHad_Jet200","", 0, 0.25, 1, 1); H__NeutralHad_Jet200->SetMargin(0.11,0,0,0); H__NeutralHad_Jet200->SetLogy(); H__NeutralHad_Jet200->Draw();
  TPad *E__NeutralHad_Jet200 = new TPad("E__NeutralHad_Jet200","", 0, 0, 1, 0.25); E__NeutralHad_Jet200->SetMargin(0.11,0,0.33,0); E__NeutralHad_Jet200->Draw(); H__NeutralHad_Jet200->cd();
  Energy_Quot__NeutralHad_FJ200->SetTitle("; ; #frac{1}{N_{Tot}} #frac{dN}{dE}");
  Energy_Quot__NeutralHad_FJ200->GetYaxis()->SetTitleSize(0.05); Energy_Quot__NeutralHad_FJ200->GetYaxis()->SetTitleOffset(1.0);
  Energy_Quot__NeutralHad_FJ200->GetYaxis()->SetLabelSize(0.05); Energy_Quot__NeutralHad_FJ200->SetAxisRange(0.0, 1.04, "X");
  Energy_Quot__NeutralHad_FJ200->SetMarkerSize(6); Energy_Quot__NeutralHad_FJ200->SetMarkerColor(14); Energy_Quot__NeutralHad_FJ200->SetMarkerStyle(21);
  Energy_Quot__NeutralHad_FJ200->DrawCopy("P");    Energy_Quot__NeutralHad_FJ200->SetMarkerColor(1);  Energy_Quot__NeutralHad_FJ200->SetMarkerStyle(25);
  Energy_Quot__NeutralHad_FJ200->SetLineWidth(2);  Energy_Quot__NeutralHad_FJ200->SetLineColor(1);    Energy_Quot__NeutralHad_FJ200->DrawCopy("Esame");
  Energy_Quot__NeutralHad_Jet200 ->SetMarkerSize(6);  Energy_Quot__NeutralHad_Jet200 ->SetMarkerColor(42);Energy_Quot__NeutralHad_Jet200 ->SetMarkerStyle(23);
  Energy_Quot__NeutralHad_Jet200 ->DrawCopy("Psame"); Energy_Quot__NeutralHad_Jet200 ->SetMarkerColor(2); Energy_Quot__NeutralHad_Jet200 ->SetMarkerStyle(32);
  Energy_Quot__NeutralHad_Jet200 ->SetLineWidth(2);   Energy_Quot__NeutralHad_Jet200 ->SetLineColor(2);   Energy_Quot__NeutralHad_Jet200 ->DrawCopy("Esame");
  Energy_Quot__NeutralHad_BTag200->SetMarkerSize(6);  Energy_Quot__NeutralHad_BTag200->SetMarkerColor(33);Energy_Quot__NeutralHad_BTag200->SetMarkerStyle(22);
  Energy_Quot__NeutralHad_BTag200->DrawCopy("Psame"); Energy_Quot__NeutralHad_BTag200->SetMarkerColor(4); Energy_Quot__NeutralHad_BTag200->SetMarkerStyle(26);
  Energy_Quot__NeutralHad_BTag200->SetLineWidth(2);   Energy_Quot__NeutralHad_BTag200->SetLineColor(4);   Energy_Quot__NeutralHad_BTag200->DrawCopy("Esame");
  Energy_Quot__NeutralHad_MinBias200->SetMarkerSize(6);  Energy_Quot__NeutralHad_MinBias200->SetMarkerColor(5); Energy_Quot__NeutralHad_MinBias200->SetMarkerStyle(20);
  Energy_Quot__NeutralHad_MinBias200->DrawCopy("Psame"); Energy_Quot__NeutralHad_MinBias200->SetMarkerColor(41);Energy_Quot__NeutralHad_MinBias200->SetMarkerStyle(24);
  Energy_Quot__NeutralHad_MinBias200->SetLineWidth(2);   Energy_Quot__NeutralHad_MinBias200->SetLineColor(41);  Energy_Quot__NeutralHad_MinBias200->DrawCopy("Esame");
  Energy_Quot__NeutralHad_MultiJet200->SetMarkerSize(6);  Energy_Quot__NeutralHad_MultiJet200->SetMarkerColor(8); Energy_Quot__NeutralHad_MultiJet200->SetMarkerStyle(34);
  Energy_Quot__NeutralHad_MultiJet200->DrawCopy("Psame"); Energy_Quot__NeutralHad_MultiJet200->SetMarkerColor(32);Energy_Quot__NeutralHad_MultiJet200->SetMarkerStyle(28);
  Energy_Quot__NeutralHad_MultiJet200->SetLineWidth(2);   Energy_Quot__NeutralHad_MultiJet200->SetLineColor(32);  Energy_Quot__NeutralHad_MultiJet200->DrawCopy("Esame");
  Leg->Draw(); Legend->Draw(); E__NeutralHad_Jet200->cd();
  Cero->SetTitle(";E^{Hadr#acute{o}nNeutro}/E^{Jet}, E^{Jet}<200;#xi"); Cero->Draw();
  Energy_Quot__Error->Add(Energy_Quot__NeutralHad_FJ200,-1); Energy_Quot__Error->Add(Energy_Quot__NeutralHad_Jet200 ,1); Energy_Quot__Error->Divide(Energy_Quot__NeutralHad_FJ200);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(23);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(2); Energy_Quot__Error->SetMarkerStyle(32);
  Energy_Quot__Error->SetLineColor(2);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__NeutralHad_FJ200,-1); Energy_Quot__Error->Add(Energy_Quot__NeutralHad_BTag200,1); Energy_Quot__Error->Divide(Energy_Quot__NeutralHad_FJ200);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(22);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(4); Energy_Quot__Error->SetMarkerStyle(26);
  Energy_Quot__Error->SetLineColor(4);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__NeutralHad_FJ200,-1); Energy_Quot__Error->Add(Energy_Quot__NeutralHad_MinBias200,1); Energy_Quot__Error->Divide(Energy_Quot__NeutralHad_FJ200);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(20);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(5); Energy_Quot__Error->SetMarkerStyle(24);
  Energy_Quot__Error->SetLineColor(5);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__NeutralHad_FJ200,-1); Energy_Quot__Error->Add(Energy_Quot__NeutralHad_MultiJet200,1); Energy_Quot__Error->Divide(Energy_Quot__NeutralHad_FJ200);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(34);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(8); Energy_Quot__Error->SetMarkerStyle(28);
  Energy_Quot__Error->SetLineColor(8);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quotient__NeutralHad_Jet200->Print("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient.pdf","pdf");
  Energy_Quotient__NeutralHad_Jet200->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__NeutralHad-Jet200.pdf"); Energy_Quotient__NeutralHad_Jet200->Close();


  TH1F *Energy_Quot__NeutralHad_200FJ = new TH1F("Energy_Quot__NeutralHad_FJ200", ";;", 120, 0, 1.2);   Energy_Quot__NeutralHad_200FJ->Rebin();
  Energy_Quot__NeutralHad_200FJ->Add(Energy_Quot__NeutralHad_200FJ300,1);
  TH1F *Energy_Quot__NeutralHad_200Jet = new TH1F("Energy_Quot__NeutralHad_Jet200", ";;", 120, 0, 1.2);   Energy_Quot__NeutralHad_200Jet->Rebin();
  Energy_Quot__NeutralHad_200Jet->Add(Energy_Quot__NeutralHad_200Jet300,1);
  TH1F *Energy_Quot__NeutralHad_200BTag = new TH1F("Energy_Quot__NeutralHad_BTag200", ";;", 120, 0, 1.2);   Energy_Quot__NeutralHad_200BTag->Rebin();
  Energy_Quot__NeutralHad_200BTag->Add(Energy_Quot__NeutralHad_200BTag300,1);
  TH1F *Energy_Quot__NeutralHad_200MinBias = new TH1F("Energy_Quot__NeutralHad_MinBias200", ";;", 120, 0, 1.2);   Energy_Quot__NeutralHad_200MinBias->Rebin();
  Energy_Quot__NeutralHad_200MinBias->Add(Energy_Quot__NeutralHad_200MinBias300,1);
  TH1F *Energy_Quot__NeutralHad_200MultiJet = new TH1F("Energy_Quot__NeutralHad_MultiJet200", ";;", 120, 0, 1.2);   Energy_Quot__NeutralHad_200MultiJet->Rebin();
  Energy_Quot__NeutralHad_200MultiJet->Add(Energy_Quot__NeutralHad_200MultiJet300,1);

  TCanvas* Energy_Quotient__NeutralHad_200Jet = new TCanvas("Energy_Quotient__NeutralHad_200Jet","Energy_Quotient__NeutralHad_200Jet",0,0,3240,2160);
  TPad *H__NeutralHad_200Jet = new TPad("H__NeutralHad_200Jet","", 0, 0.25, 1, 1); H__NeutralHad_200Jet->SetMargin(0.11,0,0,0); H__NeutralHad_200Jet->SetLogy(); H__NeutralHad_200Jet->Draw();
  TPad *E__NeutralHad_200Jet = new TPad("E__NeutralHad_200Jet","", 0, 0, 1, 0.25); E__NeutralHad_200Jet->SetMargin(0.11,0,0.33,0); E__NeutralHad_200Jet->Draw(); H__NeutralHad_200Jet->cd();
  Energy_Quot__NeutralHad_200FJ->SetTitle("; ; #frac{1}{N_{Tot}} #frac{dN}{dE}");
  Energy_Quot__NeutralHad_200FJ->GetYaxis()->SetTitleSize(0.05); Energy_Quot__NeutralHad_200FJ->GetYaxis()->SetTitleOffset(1.0);
  Energy_Quot__NeutralHad_200FJ->GetYaxis()->SetLabelSize(0.05); Energy_Quot__NeutralHad_200FJ->SetAxisRange(0.0, 1.04, "X");
  Energy_Quot__NeutralHad_200FJ->SetMarkerSize(6); Energy_Quot__NeutralHad_200FJ->SetMarkerColor(14); Energy_Quot__NeutralHad_200FJ->SetMarkerStyle(21);
  Energy_Quot__NeutralHad_200FJ->DrawCopy("P");    Energy_Quot__NeutralHad_200FJ->SetMarkerColor(1);  Energy_Quot__NeutralHad_200FJ->SetMarkerStyle(25);
  Energy_Quot__NeutralHad_200FJ->SetLineWidth(2);  Energy_Quot__NeutralHad_200FJ->SetLineColor(1);    Energy_Quot__NeutralHad_200FJ->DrawCopy("Esame");
  Energy_Quot__NeutralHad_200Jet->SetMarkerSize(6);  Energy_Quot__NeutralHad_200Jet->SetMarkerColor(42);Energy_Quot__NeutralHad_200Jet->SetMarkerStyle(23);
  Energy_Quot__NeutralHad_200Jet->DrawCopy("Psame"); Energy_Quot__NeutralHad_200Jet->SetMarkerColor(2); Energy_Quot__NeutralHad_200Jet->SetMarkerStyle(32);
  Energy_Quot__NeutralHad_200Jet->SetLineWidth(2);   Energy_Quot__NeutralHad_200Jet->SetLineColor(2);   Energy_Quot__NeutralHad_200Jet->DrawCopy("Esame");
  Energy_Quot__NeutralHad_200BTag->SetMarkerSize(6);  Energy_Quot__NeutralHad_200BTag->SetMarkerColor(33);Energy_Quot__NeutralHad_200BTag->SetMarkerStyle(22);
  Energy_Quot__NeutralHad_200BTag->DrawCopy("Psame"); Energy_Quot__NeutralHad_200BTag->SetMarkerColor(4); Energy_Quot__NeutralHad_200BTag->SetMarkerStyle(26);
  Energy_Quot__NeutralHad_200BTag->SetLineWidth(2);   Energy_Quot__NeutralHad_200BTag->SetLineColor(4);   Energy_Quot__NeutralHad_200BTag->DrawCopy("Esame");
  Energy_Quot__NeutralHad_200MinBias->SetMarkerSize(6);  Energy_Quot__NeutralHad_200MinBias->SetMarkerColor(5); Energy_Quot__NeutralHad_200MinBias->SetMarkerStyle(20);
  Energy_Quot__NeutralHad_200MinBias->DrawCopy("Psame"); Energy_Quot__NeutralHad_200MinBias->SetMarkerColor(41);Energy_Quot__NeutralHad_200MinBias->SetMarkerStyle(24);
  Energy_Quot__NeutralHad_200MinBias->SetLineWidth(2);   Energy_Quot__NeutralHad_200MinBias->SetLineColor(41);  Energy_Quot__NeutralHad_200MinBias->DrawCopy("Esame");
  Energy_Quot__NeutralHad_200MultiJet->SetMarkerSize(6);  Energy_Quot__NeutralHad_200MultiJet->SetMarkerColor(8); Energy_Quot__NeutralHad_200MultiJet->SetMarkerStyle(34);
  Energy_Quot__NeutralHad_200MultiJet->DrawCopy("Psame"); Energy_Quot__NeutralHad_200MultiJet->SetMarkerColor(32);Energy_Quot__NeutralHad_200MultiJet->SetMarkerStyle(28);
  Energy_Quot__NeutralHad_200MultiJet->SetLineWidth(2);   Energy_Quot__NeutralHad_200MultiJet->SetLineColor(32);  Energy_Quot__NeutralHad_200MultiJet->DrawCopy("Esame");
  Leg->Draw(); Legend->Draw(); E__NeutralHad_200Jet->cd();
  Cero->SetTitle(";E^{Hadr#acute{o}nNeutro}/E^{Jet}, E^{Jet}>200;#xi"); Cero->Draw(); Cero->GetYaxis()->SetRangeUser(-2.6,1.2);
  Energy_Quot__Error->Add(Energy_Quot__NeutralHad_200FJ,-1); Energy_Quot__Error->Add(Energy_Quot__NeutralHad_200Jet,1); Energy_Quot__Error->Divide(Energy_Quot__NeutralHad_200FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(23);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(2); Energy_Quot__Error->SetMarkerStyle(32);
  Energy_Quot__Error->SetLineColor(2);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__NeutralHad_200FJ,-1); Energy_Quot__Error->Add(Energy_Quot__NeutralHad_200BTag,1); Energy_Quot__Error->Divide(Energy_Quot__NeutralHad_200FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(22);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(4); Energy_Quot__Error->SetMarkerStyle(26);
  Energy_Quot__Error->SetLineColor(4);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__NeutralHad_200FJ,-1); Energy_Quot__Error->Add(Energy_Quot__NeutralHad_200MinBias,1); Energy_Quot__Error->Divide(Energy_Quot__NeutralHad_200FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(20);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(5); Energy_Quot__Error->SetMarkerStyle(24);
  Energy_Quot__Error->SetLineColor(5);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__NeutralHad_200FJ,-1); Energy_Quot__Error->Add(Energy_Quot__NeutralHad_200MultiJet,1); Energy_Quot__Error->Divide(Energy_Quot__NeutralHad_200FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(34);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(8); Energy_Quot__Error->SetMarkerStyle(28);
  Energy_Quot__Error->SetLineColor(8);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quotient__NeutralHad_200Jet->Print("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient.pdf","pdf");
  Energy_Quotient__NeutralHad_200Jet->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__NeutralHad-200Jet.pdf"); Energy_Quotient__NeutralHad_200Jet->Close();


  TCanvas* Energy_Quotient__ChargedHad_Jet  = new TCanvas("Energy_Quotient__ChargedHad_Jet ","Energy_Quotient__ChargedHad_Jet ",0,0,3240,2160);
  TPad *H__ChargedHad_Jet = new TPad("H__ChargedHad_Jet","", 0, 0.25, 1, 1); H__ChargedHad_Jet->SetMargin(0.11,0,0,0); H__ChargedHad_Jet->SetLogy(); H__ChargedHad_Jet->Draw();
  TPad *E__ChargedHad_Jet = new TPad("E__ChargedHad_Jet","", 0, 0, 1, 0.25); E__ChargedHad_Jet->SetMargin(0.11,0,0.33,0); E__ChargedHad_Jet->Draw(); H__ChargedHad_Jet->cd();
  Energy_Quot__ChargedHad_FJ->SetTitle("; ; #frac{1}{N_{Tot}} #frac{dN}{dE}");
  Energy_Quot__ChargedHad_FJ->GetYaxis()->SetTitleSize(0.05); Energy_Quot__ChargedHad_FJ->GetYaxis()->SetTitleOffset(1.0);
  Energy_Quot__ChargedHad_FJ->GetYaxis()->SetLabelSize(0.05); Energy_Quot__ChargedHad_FJ->SetAxisRange(0.0, 1.04, "X");
  Energy_Quot__ChargedHad_FJ->SetMarkerSize(6); Energy_Quot__ChargedHad_FJ->SetMarkerColor(14); Energy_Quot__ChargedHad_FJ->SetMarkerStyle(21);
  Energy_Quot__ChargedHad_FJ->DrawCopy("P");    Energy_Quot__ChargedHad_FJ->SetMarkerColor(1);  Energy_Quot__ChargedHad_FJ->SetMarkerStyle(25);
  Energy_Quot__ChargedHad_FJ->SetLineWidth(2);  Energy_Quot__ChargedHad_FJ->SetLineColor(1);    Energy_Quot__ChargedHad_FJ->DrawCopy("Esame");
  Energy_Quot__ChargedHad_Jet ->SetMarkerSize(6);  Energy_Quot__ChargedHad_Jet ->SetMarkerColor(42);Energy_Quot__ChargedHad_Jet ->SetMarkerStyle(23);
  Energy_Quot__ChargedHad_Jet ->DrawCopy("Psame"); Energy_Quot__ChargedHad_Jet ->SetMarkerColor(2); Energy_Quot__ChargedHad_Jet ->SetMarkerStyle(32);
  Energy_Quot__ChargedHad_Jet ->SetLineWidth(2);   Energy_Quot__ChargedHad_Jet ->SetLineColor(2);   Energy_Quot__ChargedHad_Jet ->DrawCopy("Esame");
  Energy_Quot__ChargedHad_BTag->SetMarkerSize(6);  Energy_Quot__ChargedHad_BTag->SetMarkerColor(33);Energy_Quot__ChargedHad_BTag->SetMarkerStyle(22);
  Energy_Quot__ChargedHad_BTag->DrawCopy("Psame"); Energy_Quot__ChargedHad_BTag->SetMarkerColor(4); Energy_Quot__ChargedHad_BTag->SetMarkerStyle(26);
  Energy_Quot__ChargedHad_BTag->SetLineWidth(2);   Energy_Quot__ChargedHad_BTag->SetLineColor(4);   Energy_Quot__ChargedHad_BTag->DrawCopy("Esame");
  Energy_Quot__ChargedHad_MinBias->SetMarkerSize(6);  Energy_Quot__ChargedHad_MinBias->SetMarkerColor(5); Energy_Quot__ChargedHad_MinBias->SetMarkerStyle(20);
  Energy_Quot__ChargedHad_MinBias->DrawCopy("Psame"); Energy_Quot__ChargedHad_MinBias->SetMarkerColor(41);Energy_Quot__ChargedHad_MinBias->SetMarkerStyle(24);
  Energy_Quot__ChargedHad_MinBias->SetLineWidth(2);   Energy_Quot__ChargedHad_MinBias->SetLineColor(41);  Energy_Quot__ChargedHad_MinBias->DrawCopy("Esame");
  Energy_Quot__ChargedHad_MultiJet->SetMarkerSize(6);  Energy_Quot__ChargedHad_MultiJet->SetMarkerColor(8); Energy_Quot__ChargedHad_MultiJet->SetMarkerStyle(34);
  Energy_Quot__ChargedHad_MultiJet->DrawCopy("Psame"); Energy_Quot__ChargedHad_MultiJet->SetMarkerColor(32);Energy_Quot__ChargedHad_MultiJet->SetMarkerStyle(28);
  Energy_Quot__ChargedHad_MultiJet->SetLineWidth(2);   Energy_Quot__ChargedHad_MultiJet->SetLineColor(32);  Energy_Quot__ChargedHad_MultiJet->DrawCopy("Esame");
  Leg->Draw(); Legend->Draw(); E__ChargedHad_Jet->cd();
  Cero->SetTitle(";E^{Hadr#acute{o}nCargado}/E^{Jet};#xi"); Cero->Draw(); Cero->GetYaxis()->SetRangeUser(-0.6,0.6);
  Energy_Quot__Error->Add(Energy_Quot__ChargedHad_FJ,-1); Energy_Quot__Error->Add(Energy_Quot__ChargedHad_Jet ,1); Energy_Quot__Error->Divide(Energy_Quot__ChargedHad_FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(23);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(2); Energy_Quot__Error->SetMarkerStyle(32);
  Energy_Quot__Error->SetLineColor(2);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__ChargedHad_FJ,-1); Energy_Quot__Error->Add(Energy_Quot__ChargedHad_BTag,1); Energy_Quot__Error->Divide(Energy_Quot__ChargedHad_FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(22);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(4); Energy_Quot__Error->SetMarkerStyle(26);
  Energy_Quot__Error->SetLineColor(4);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__ChargedHad_FJ,-1); Energy_Quot__Error->Add(Energy_Quot__ChargedHad_MinBias,1); Energy_Quot__Error->Divide(Energy_Quot__ChargedHad_FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(20);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(5); Energy_Quot__Error->SetMarkerStyle(24);
  Energy_Quot__Error->SetLineColor(5);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__ChargedHad_FJ,-1); Energy_Quot__Error->Add(Energy_Quot__ChargedHad_MultiJet,1); Energy_Quot__Error->Divide(Energy_Quot__ChargedHad_FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(34);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(8); Energy_Quot__Error->SetMarkerStyle(28);
  Energy_Quot__Error->SetLineColor(8);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quotient__ChargedHad_Jet->Print("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient.pdf","pdf");
  Energy_Quotient__ChargedHad_Jet->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__ChargedHad-Jet.pdf"); Energy_Quotient__ChargedHad_Jet->Close();


  TH1F *Energy_Quot__ChargedHad_FJ200 = new TH1F("Energy_Quot__ChargedHad_FJ200", ";;", 120, 0, 1.2);   Energy_Quot__ChargedHad_FJ200->Rebin();
  Energy_Quot__ChargedHad_FJ200->Add(Energy_Quot__ChargedHad_0FJ100,1);
  TH1F *Energy_Quot__ChargedHad_Jet200 = new TH1F("Energy_Quot__ChargedHad_Jet200", ";;", 120, 0, 1.2);   Energy_Quot__ChargedHad_Jet200->Rebin();
  Energy_Quot__ChargedHad_Jet200->Add(Energy_Quot__ChargedHad_0Jet100,1);
  TH1F *Energy_Quot__ChargedHad_BTag200 = new TH1F("Energy_Quot__ChargedHad_BTag200", ";;", 120, 0, 1.2);   Energy_Quot__ChargedHad_BTag200->Rebin();
  Energy_Quot__ChargedHad_BTag200->Add(Energy_Quot__ChargedHad_0BTag100,1);
  TH1F *Energy_Quot__ChargedHad_MinBias200 = new TH1F("Energy_Quot__ChargedHad_MinBias200", ";;", 120, 0, 1.2);   Energy_Quot__ChargedHad_MinBias200->Rebin();
  Energy_Quot__ChargedHad_MinBias200->Add(Energy_Quot__ChargedHad_0MinBias100,1);
  TH1F *Energy_Quot__ChargedHad_MultiJet200 = new TH1F("Energy_Quot__ChargedHad_MultiJet200", ";;", 120, 0, 1.2);   Energy_Quot__ChargedHad_MultiJet200->Rebin();
  Energy_Quot__ChargedHad_MultiJet200->Add(Energy_Quot__ChargedHad_0MultiJet100,1);

  TCanvas* Energy_Quotient__ChargedHad_Jet200  = new TCanvas("Energy_Quotient__ChargedHad_Jet200 ","Energy_Quotient__ChargedHad_Jet200 ",0,0,3240,2160);
  TPad *H__ChargedHad_Jet200 = new TPad("H__ChargedHad_Jet200","", 0, 0.25, 1, 1); H__ChargedHad_Jet200->SetMargin(0.11,0,0,0); H__ChargedHad_Jet200->SetLogy(); H__ChargedHad_Jet200->Draw();
  TPad *E__ChargedHad_Jet200 = new TPad("E__ChargedHad_Jet200","", 0, 0, 1, 0.25); E__ChargedHad_Jet200->SetMargin(0.11,0,0.33,0); E__ChargedHad_Jet200->Draw(); H__ChargedHad_Jet200->cd();
  Energy_Quot__ChargedHad_FJ200->SetTitle("; ; #frac{1}{N_{Tot}} #frac{dN}{dE}");
  Energy_Quot__ChargedHad_FJ200->GetYaxis()->SetTitleSize(0.05); Energy_Quot__ChargedHad_FJ200->GetYaxis()->SetTitleOffset(1.0);
  Energy_Quot__ChargedHad_FJ200->GetYaxis()->SetLabelSize(0.05); Energy_Quot__ChargedHad_FJ200->SetAxisRange(0.0, 1.04, "X");
  Energy_Quot__ChargedHad_FJ200->SetMarkerSize(6); Energy_Quot__ChargedHad_FJ200->SetMarkerColor(14); Energy_Quot__ChargedHad_FJ200->SetMarkerStyle(21);
  Energy_Quot__ChargedHad_FJ200->DrawCopy("P");    Energy_Quot__ChargedHad_FJ200->SetMarkerColor(1);  Energy_Quot__ChargedHad_FJ200->SetMarkerStyle(25);
  Energy_Quot__ChargedHad_FJ200->SetLineWidth(2);  Energy_Quot__ChargedHad_FJ200->SetLineColor(1);    Energy_Quot__ChargedHad_FJ200->DrawCopy("Esame");
  Energy_Quot__ChargedHad_Jet200 ->SetMarkerSize(6);  Energy_Quot__ChargedHad_Jet200 ->SetMarkerColor(42);Energy_Quot__ChargedHad_Jet200 ->SetMarkerStyle(23);
  Energy_Quot__ChargedHad_Jet200 ->DrawCopy("Psame"); Energy_Quot__ChargedHad_Jet200 ->SetMarkerColor(2); Energy_Quot__ChargedHad_Jet200 ->SetMarkerStyle(32);
  Energy_Quot__ChargedHad_Jet200 ->SetLineWidth(2);   Energy_Quot__ChargedHad_Jet200 ->SetLineColor(2);   Energy_Quot__ChargedHad_Jet200 ->DrawCopy("Esame");
  Energy_Quot__ChargedHad_BTag200->SetMarkerSize(6);  Energy_Quot__ChargedHad_BTag200->SetMarkerColor(33);Energy_Quot__ChargedHad_BTag200->SetMarkerStyle(22);
  Energy_Quot__ChargedHad_BTag200->DrawCopy("Psame"); Energy_Quot__ChargedHad_BTag200->SetMarkerColor(4); Energy_Quot__ChargedHad_BTag200->SetMarkerStyle(26);
  Energy_Quot__ChargedHad_BTag200->SetLineWidth(2);   Energy_Quot__ChargedHad_BTag200->SetLineColor(4);   Energy_Quot__ChargedHad_BTag200->DrawCopy("Esame");
  Energy_Quot__ChargedHad_MinBias200->SetMarkerSize(6);  Energy_Quot__ChargedHad_MinBias200->SetMarkerColor(5); Energy_Quot__ChargedHad_MinBias200->SetMarkerStyle(20);
  Energy_Quot__ChargedHad_MinBias200->DrawCopy("Psame"); Energy_Quot__ChargedHad_MinBias200->SetMarkerColor(41);Energy_Quot__ChargedHad_MinBias200->SetMarkerStyle(24);
  Energy_Quot__ChargedHad_MinBias200->SetLineWidth(2);   Energy_Quot__ChargedHad_MinBias200->SetLineColor(41);  Energy_Quot__ChargedHad_MinBias200->DrawCopy("Esame");
  Energy_Quot__ChargedHad_MultiJet200->SetMarkerSize(6);  Energy_Quot__ChargedHad_MultiJet200->SetMarkerColor(8); Energy_Quot__ChargedHad_MultiJet200->SetMarkerStyle(34);
  Energy_Quot__ChargedHad_MultiJet200->DrawCopy("Psame"); Energy_Quot__ChargedHad_MultiJet200->SetMarkerColor(32);Energy_Quot__ChargedHad_MultiJet200->SetMarkerStyle(28);
  Energy_Quot__ChargedHad_MultiJet200->SetLineWidth(2);   Energy_Quot__ChargedHad_MultiJet200->SetLineColor(32);  Energy_Quot__ChargedHad_MultiJet200->DrawCopy("Esame");
  Leg->Draw(); Legend->Draw(); E__ChargedHad_Jet200->cd();
  Cero->SetTitle(";E^{Hadr#acute{o}nCargado}/E^{Jet}, E^{Jet}<200;#xi"); Cero->Draw();
  Energy_Quot__Error->Add(Energy_Quot__ChargedHad_FJ200,-1); Energy_Quot__Error->Add(Energy_Quot__ChargedHad_Jet200 ,1); Energy_Quot__Error->Divide(Energy_Quot__ChargedHad_FJ200);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(23);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(2); Energy_Quot__Error->SetMarkerStyle(32);
  Energy_Quot__Error->SetLineColor(2);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__ChargedHad_FJ200,-1); Energy_Quot__Error->Add(Energy_Quot__ChargedHad_BTag200,1); Energy_Quot__Error->Divide(Energy_Quot__ChargedHad_FJ200);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(22);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(4); Energy_Quot__Error->SetMarkerStyle(26);
  Energy_Quot__Error->SetLineColor(4);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__ChargedHad_FJ200,-1); Energy_Quot__Error->Add(Energy_Quot__ChargedHad_MinBias200,1); Energy_Quot__Error->Divide(Energy_Quot__ChargedHad_FJ200);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(20);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(5); Energy_Quot__Error->SetMarkerStyle(24);
  Energy_Quot__Error->SetLineColor(5);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__ChargedHad_FJ200,-1); Energy_Quot__Error->Add(Energy_Quot__ChargedHad_MultiJet200,1); Energy_Quot__Error->Divide(Energy_Quot__ChargedHad_FJ200);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(34);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(8); Energy_Quot__Error->SetMarkerStyle(28);
  Energy_Quot__Error->SetLineColor(8);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quotient__ChargedHad_Jet200->Print("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient.pdf","pdf");
  Energy_Quotient__ChargedHad_Jet200->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__ChargedHad-Jet200.pdf"); Energy_Quotient__ChargedHad_Jet200->Close();


  TH1F *Energy_Quot__ChargedHad_200FJ = new TH1F("Energy_Quot__ChargedHad_FJ200", ";;", 120, 0, 1.2);   Energy_Quot__ChargedHad_200FJ->Rebin();
  Energy_Quot__ChargedHad_200FJ->Add(Energy_Quot__ChargedHad_200FJ300,1);
  TH1F *Energy_Quot__ChargedHad_200Jet = new TH1F("Energy_Quot__ChargedHad_Jet200", ";;", 120, 0, 1.2);   Energy_Quot__ChargedHad_200Jet->Rebin();
  Energy_Quot__ChargedHad_200Jet->Add(Energy_Quot__ChargedHad_200Jet300,1);
  TH1F *Energy_Quot__ChargedHad_200BTag = new TH1F("Energy_Quot__ChargedHad_BTag200", ";;", 120, 0, 1.2);   Energy_Quot__ChargedHad_200BTag->Rebin();
  Energy_Quot__ChargedHad_200BTag->Add(Energy_Quot__ChargedHad_200BTag300,1);
  TH1F *Energy_Quot__ChargedHad_200MinBias = new TH1F("Energy_Quot__ChargedHad_MinBias200", ";;", 120, 0, 1.2);   Energy_Quot__ChargedHad_200MinBias->Rebin();
  Energy_Quot__ChargedHad_200MinBias->Add(Energy_Quot__ChargedHad_200MinBias300,1);
  TH1F *Energy_Quot__ChargedHad_200MultiJet = new TH1F("Energy_Quot__ChargedHad_MultiJet200", ";;", 120, 0, 1.2);   Energy_Quot__ChargedHad_200MultiJet->Rebin();
  Energy_Quot__ChargedHad_200MultiJet->Add(Energy_Quot__ChargedHad_200MultiJet300,1);

  TCanvas* Energy_Quotient__ChargedHad_200Jet = new TCanvas("Energy_Quotient__ChargedHad_200Jet","Energy_Quotient__ChargedHad_200Jet",0,0,3240,2160);
  TPad *H__ChargedHad_200Jet = new TPad("H__ChargedHad_200Jet","", 0, 0.25, 1, 1); H__ChargedHad_200Jet->SetMargin(0.11,0,0,0); H__ChargedHad_200Jet->SetLogy(); H__ChargedHad_200Jet->Draw();
  TPad *E__ChargedHad_200Jet = new TPad("E__ChargedHad_200Jet","", 0, 0, 1, 0.25); E__ChargedHad_200Jet->SetMargin(0.11,0,0.33,0); E__ChargedHad_200Jet->Draw(); H__ChargedHad_200Jet->cd();
  Energy_Quot__ChargedHad_200FJ->SetTitle("; ; #frac{1}{N_{Tot}} #frac{dN}{dE}");
  Energy_Quot__ChargedHad_200FJ->GetYaxis()->SetTitleSize(0.05); Energy_Quot__ChargedHad_200FJ->GetYaxis()->SetTitleOffset(1.0);
  Energy_Quot__ChargedHad_200FJ->GetYaxis()->SetLabelSize(0.05); Energy_Quot__ChargedHad_200FJ->SetAxisRange(0.0, 1.04, "X");
  Energy_Quot__ChargedHad_200FJ->SetMarkerSize(6); Energy_Quot__ChargedHad_200FJ->SetMarkerColor(14); Energy_Quot__ChargedHad_200FJ->SetMarkerStyle(21);
  Energy_Quot__ChargedHad_200FJ->DrawCopy("P");    Energy_Quot__ChargedHad_200FJ->SetMarkerColor(1);  Energy_Quot__ChargedHad_200FJ->SetMarkerStyle(25);
  Energy_Quot__ChargedHad_200FJ->SetLineWidth(2);  Energy_Quot__ChargedHad_200FJ->SetLineColor(1);    Energy_Quot__ChargedHad_200FJ->DrawCopy("Esame");
  Energy_Quot__ChargedHad_200Jet->SetMarkerSize(6);  Energy_Quot__ChargedHad_200Jet->SetMarkerColor(42);Energy_Quot__ChargedHad_200Jet->SetMarkerStyle(23);
  Energy_Quot__ChargedHad_200Jet->DrawCopy("Psame"); Energy_Quot__ChargedHad_200Jet->SetMarkerColor(2); Energy_Quot__ChargedHad_200Jet->SetMarkerStyle(32);
  Energy_Quot__ChargedHad_200Jet->SetLineWidth(2);   Energy_Quot__ChargedHad_200Jet->SetLineColor(2);   Energy_Quot__ChargedHad_200Jet->DrawCopy("Esame");
  Energy_Quot__ChargedHad_200BTag->SetMarkerSize(6);  Energy_Quot__ChargedHad_200BTag->SetMarkerColor(33);Energy_Quot__ChargedHad_200BTag->SetMarkerStyle(22);
  Energy_Quot__ChargedHad_200BTag->DrawCopy("Psame"); Energy_Quot__ChargedHad_200BTag->SetMarkerColor(4); Energy_Quot__ChargedHad_200BTag->SetMarkerStyle(26);
  Energy_Quot__ChargedHad_200BTag->SetLineWidth(2);   Energy_Quot__ChargedHad_200BTag->SetLineColor(4);   Energy_Quot__ChargedHad_200BTag->DrawCopy("Esame");
  Energy_Quot__ChargedHad_200MinBias->SetMarkerSize(6);  Energy_Quot__ChargedHad_200MinBias->SetMarkerColor(5); Energy_Quot__ChargedHad_200MinBias->SetMarkerStyle(20);
  Energy_Quot__ChargedHad_200MinBias->DrawCopy("Psame"); Energy_Quot__ChargedHad_200MinBias->SetMarkerColor(41);Energy_Quot__ChargedHad_200MinBias->SetMarkerStyle(24);
  Energy_Quot__ChargedHad_200MinBias->SetLineWidth(2);   Energy_Quot__ChargedHad_200MinBias->SetLineColor(41);  Energy_Quot__ChargedHad_200MinBias->DrawCopy("Esame");
  Energy_Quot__ChargedHad_200MultiJet->SetMarkerSize(6);  Energy_Quot__ChargedHad_200MultiJet->SetMarkerColor(8); Energy_Quot__ChargedHad_200MultiJet->SetMarkerStyle(34);
  Energy_Quot__ChargedHad_200MultiJet->DrawCopy("Psame"); Energy_Quot__ChargedHad_200MultiJet->SetMarkerColor(32);Energy_Quot__ChargedHad_200MultiJet->SetMarkerStyle(28);
  Energy_Quot__ChargedHad_200MultiJet->SetLineWidth(2);   Energy_Quot__ChargedHad_200MultiJet->SetLineColor(32);  Energy_Quot__ChargedHad_200MultiJet->DrawCopy("Esame");
  Leg->Draw(); Legend->Draw(); E__ChargedHad_200Jet->cd();
  Cero->SetTitle(";E^{Hadr#acute{o}nCargado}/E^{Jet}, E^{Jet}>200;#xi"); Cero->Draw();
  Energy_Quot__Error->Add(Energy_Quot__ChargedHad_200FJ,-1); Energy_Quot__Error->Add(Energy_Quot__ChargedHad_200Jet,1); Energy_Quot__Error->Divide(Energy_Quot__ChargedHad_200FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(23);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(2); Energy_Quot__Error->SetMarkerStyle(32);
  Energy_Quot__Error->SetLineColor(2);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__ChargedHad_200FJ,-1); Energy_Quot__Error->Add(Energy_Quot__ChargedHad_200BTag,1); Energy_Quot__Error->Divide(Energy_Quot__ChargedHad_200FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(22);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(4); Energy_Quot__Error->SetMarkerStyle(26);
  Energy_Quot__Error->SetLineColor(4);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__ChargedHad_200FJ,-1); Energy_Quot__Error->Add(Energy_Quot__ChargedHad_200MinBias,1); Energy_Quot__Error->Divide(Energy_Quot__ChargedHad_200FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(20);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(5); Energy_Quot__Error->SetMarkerStyle(24);
  Energy_Quot__Error->SetLineColor(5);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quot__Error->Add(Energy_Quot__ChargedHad_200FJ,-1); Energy_Quot__Error->Add(Energy_Quot__ChargedHad_200MultiJet,1); Energy_Quot__Error->Divide(Energy_Quot__ChargedHad_200FJ);
  Energy_Quot__Error->SetMarkerColor(14);Energy_Quot__Error->SetMarkerStyle(34);  Energy_Quot__Error->DrawCopy("Psame");
  Energy_Quot__Error->SetMarkerColor(8); Energy_Quot__Error->SetMarkerStyle(28);
  Energy_Quot__Error->SetLineColor(8);   Energy_Quot__Error->DrawCopy("Esame");
  Energy_Quot__Error->Reset("ICES");
  Energy_Quotient__ChargedHad_200Jet->Print("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient.pdf)","pdf");
  Energy_Quotient__ChargedHad_200Jet->SaveAs("/home/saksevul/T/Parallelism/ak5Jets/Energy_Quotient__ChargedHad-200Jet.pdf"); Energy_Quotient__ChargedHad_200Jet->Close();

}

//###################################################################################################################################################################################

void Limits() {

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
    legend->AddEntry(MuonsFJ_pt_, "Simulaci#acute{o}n MC", "l");
    legend->AddEntry(MuonsBTag_pt_, "Open-Data BTag", "l");
    legend->AddEntry(MuonsJet_pt_, "Open-Data Jet", "l");
    legend->AddEntry(MuonsMinBias_pt_, "Open-Data MinBias", "l");
    legend->AddEntry(MuonsMultiJet_pt_, "Open-Data MultiJet", "l");



  TCanvas* Limite_pT_Muones = new TCanvas("Limite_pT_Muones","Limite de pT para Muones",10,10,1920,1080);
  Limite_pT_Muones->SetFillColor(0);  Limite_pT_Muones->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  MuonsFJ_pt_->SetTitle("Espectro de p_{T} para Muones; p_{T} [GeV]; #frac{1}{N_{Tot}} #frac{dN}{dE}");
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
  PhotonsFJ_pt_->SetTitle("Espectro de p_{T} para Fotones; p_{T} [GeV]; #frac{1}{N_{Tot}} #frac{dN}{dE}");
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
  ElectronsFJ_pt_->SetTitle("Espectro de p_{T} para Electrones; p_{T} [GeV]; #frac{1}{N_{Tot}} #frac{dN}{dE}");
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

  TCanvas* Limite_pT_ak5PFJets = new TCanvas("Limite_pT_ak5PFJets","Limite de pT para Jets",10,10,1920,1080);
  Limite_pT_ak5PFJets->SetFillColor(0);  Limite_pT_ak5PFJets->SetFrameBorderMode(0);  gPad->SetLogy();
  // Esto es para modificar las etiquetas del canvas.
  ak5FJ_pt_->SetTitle("Espectro de p_{T} para Jets; p_{T} [GeV]; #frac{1}{N_{Tot}} #frac{dN}{dE}");
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
  MuonsFJ_eta_->SetTitle("Espectro de #eta para Muones; p_{T} [GeV]; #frac{1}{N_{Tot}} #frac{dN}{dE}");
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
  PhotonsFJ_eta_->SetTitle("Espectro de #eta para Fotones; p_{T} [GeV]; #frac{1}{N_{Tot}} #frac{dN}{dE}");
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
  ElectronsFJ_eta_->SetTitle("Espectro de #eta para Electrones; p_{T} [GeV]; #frac{1}{N_{Tot}} #frac{dN}{dE}");
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
  ak5FJ_eta_->SetTitle("Espectro de #eta para Jets; p_{T} [GeV]; #frac{1}{N_{Tot}} #frac{dN}{dE}");
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



  TCanvas* Limite_Energia_Muones = new TCanvas("Limite_Energia_Muones","Limite de E para Muones",10,10,1920,1080);
  Limite_Energia_Muones->SetFillColor(0);  Limite_Energia_Muones->SetFrameBorderMode(0);  gPad->SetLogy(); gPad->SetGrid(1,1);
  // Esto es para modificar las etiquetas del canvas.
  Jet_MuonEnergy->SetTitle("Espectro de E para Muones en ak5PFJets; E [GeV]; #frac{1}{N_{Tot}} #frac{dN}{dE}");
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

  TCanvas* Limite_Energia_Fotones = new TCanvas("Limite_Energia_Fotones","Limite de E para Fotones",10,10,1920,1080);
  Limite_Energia_Fotones->SetFillColor(0);  Limite_Energia_Fotones->SetFrameBorderMode(0);  gPad->SetLogy(); gPad->SetGrid(1,1);
  // Esto es para modificar las etiquetas del canvas.
  Jet_PhotonEnergy->SetTitle("Espectro de E para Fotones en ak5PFJets; E [GeV]; #frac{1}{N_{Tot}} #frac{dN}{dE}");
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

  TCanvas* Limite_Energia_Electrones = new TCanvas("Limite_Energia_Electrones","Limite E para Electrones",10,10,1920,1080);
  Limite_Energia_Electrones->SetFillColor(0);  Limite_Energia_Electrones->SetFrameBorderMode(0);  gPad->SetLogy(); gPad->SetGrid(1,1);
  // Esto es para modificar las etiquetas del canvas.
  Jet_ElectronEnergy->SetTitle("Espectro de E para Electrones en ak5PFJets; E [GeV]; #frac{1}{N_{Tot}} #frac{dN}{dE}");
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

  TCanvas* Limite_Energia_HadNeutros = new TCanvas("Limite_Energia_HadNeutros","Limite E para HadNeutros",10,10,1920,1080);
  Limite_Energia_HadNeutros->SetFillColor(0);  Limite_Energia_HadNeutros->SetFrameBorderMode(0);  gPad->SetLogy(); gPad->SetGrid(1,1);
  // Esto es para modificar las etiquetas del canvas.
  Jet_NeuHadEnergy->SetTitle("Espectro de E para HadNeutros en ak5PFJets; E [GeV]; #frac{1}{N_{Tot}} #frac{dN}{dE}");
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

  TCanvas* Limite_Energia_HadCargados = new TCanvas("Limite_Energia_HadCargados","Limite E para HadCargados",10,10,1920,1080);
  Limite_Energia_HadCargados->SetFillColor(0);  Limite_Energia_HadCargados->SetFrameBorderMode(0);  gPad->SetLogy(); gPad->SetGrid(1,1);
  // Esto es para modificar las etiquetas del canvas.
  Jet_CharHadEnergy->SetTitle("Espectro de E para HadCargados en ak5PFJets; E [GeV]; #frac{1}{N_{Tot}} #frac{dN}{dE}");
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
  Jet_JetEnergy->SetTitle("Espectro de E para Jets; E [GeV]; #frac{1}{N_{Tot}} #frac{dN}{dE}");
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
    ak5FastJet__Multiplicidad->SetTitle("Multiplicidad de Jets por Evento; Numero de Jets; #frac{1}{N_{Tot}} #frac{dN}{dE}");
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

void rootMacro(){

  gStyle->SetOptStat(0);

  // Corremos los macros que nos interesan.
  EnergyQuotient();
  // Limits();
  // Multiplicidad();
}
