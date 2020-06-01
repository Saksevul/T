void Analisis() {   Float_t PI=TMath::Pi(); Int_t nprint=1;

  //Abrimos los archivos que nos interesan y los árboles que queremos leer.
  TFile *InputFile = new TFile("/media/saksevul/Pawahtun/CMS_Run2011A/BTag_20000/0001.root");
  TTree *Eventos = (TTree*)InputFile->Get("Events");

  //Crear el archivo de salida que queremos. Tiene que ir después del imputFile.
  TFile* OutputFile = new TFile("/home/saksevul/T/OpenData/BTag_20000/ak5PF-0001.root", "RECREATE");


    printf("\n\t JCA: ak5PF, InputFile: BTag_20000/0001.root. \n\n\t\t %i) Archivos abiertos. \n", nprint++);


  //Jets
  TLeaf *Jets_pt_                        = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.pt_");
  TLeaf *Jets_eta_                       = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.eta_");
  // TLeaf *Jets_mJetArea                  = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.mJetArea");
  TLeaf *Jets_mPileupEnergy              = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.mPileupEnergy");
  TLeaf *Jets_mChargedHadronEnergy       = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mChargedHadronEnergy");
  TLeaf *Jets_mNeutralHadronEnergy       = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mNeutralHadronEnergy");
  TLeaf *Jets_mElectronEnergy            = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mElectronEnergy");
  TLeaf *Jets_mPhotonEnergy              = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mPhotonEnergy");
  TLeaf *Jets_mMuonEnergy                = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mMuonEnergy");
  TLeaf *Jets_mHFHadronEnergy            = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mHFHadronEnergy");
  TLeaf *Jets_mHFEMEnergy                = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mHFEMEnergy");
  TLeaf *Jets_mChargedHadronMultiplicity = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mChargedHadronMultiplicity");
  TLeaf *Jets_mNeutralHadronMultiplicity = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mNeutralHadronMultiplicity");
  TLeaf *Jets_mPhotonMultiplicity        = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mPhotonMultiplicity");
  TLeaf *Jets_mElectronMultiplicity      = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mElectronMultiplicity");
  TLeaf *Jets_mMuonMultiplicity          = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mMuonMultiplicity");
  TLeaf *Jets_mHFHadronMultiplicity      = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mHFHadronMultiplicity");
  TLeaf *Jets_mHFEMMultiplicity          = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mHFEMMultiplicity");


    printf("\t\t %i) Ramas leidas. \n", nprint++);


  // Jets
  TH1F* h_Jets_pt_            = new TH1F("Jets_pt_",  "Espectro de p_{T} de ak5FastJet; p_{T} [GeV]; Ocurrencia", 1200, 0, 2400);
  TH1F *h_Jets_eta_           = new TH1F("Jets_eta_", "Distribución en #eta de ak5FastJet; #eta; Ocurrencia", 599, -5.95, 5.95);
  TH1F *h_Jets__Energy        = new TH1F("Jets_Energy", "Energ#acute{i}a de FastJets; Energ#acute{i}a [GeV]; Frecuencia", 1800, 0, 3600);
  TH1F *h_MuonEnergy          = new TH1F("Jets_MuonEnergy", "Energ#acute{i}a de Muones; Energ#acute{i}a [GeV]; Frecuencia", 1800, 0, 3600);
  TH1F *h_PhotonEnergy        = new TH1F("Jets_PhotonEnergy", "Energ#acute{i}a de Fotones; Energ#acute{i}a [GeV]; Frecuencia", 1800, 0, 3600);
  TH1F *h_ElectronEnergy      = new TH1F("Jets_ElectronEnergy", "Energ#acute{i}a de Electrones; Energ#acute{i}a [GeV]; Frecuencia", 1800, 0, 3600);
  TH1F *h_NeutralHadronEnergy = new TH1F("Jets_NeutralHadronEnergy", "Energ#acute{i}a de Hadrones Neutros; Energ#acute{i}a [GeV]; Frecuencia", 1800, 0, 3600);
  TH1F *h_ChargedHadronEnergy = new TH1F("Jets_ChargedHadronEnergy", "Energ#acute{i}a de Hadrones Cargados; Energ#acute{i}a [GeV]; Frecuencia", 1800, 0, 3600);
  // Multiplicidad.
  TH1F *h_Jets__Multiplicity           = new TH1F("Jets__Multiplicity", "Multiplicidad de ak5PFJet por Evento; Multiplicidad; Frecuencia", 120, 0, 120);
  TH1F *h_Jets__MuonMultiplicity       = new TH1F("Jets_Multiplicity__Muon", "Multiplicidad, != 0, de Muones en cada ak5PFJet; Multiplicidad Muon; Frecuencia", 120, 0, 120);
  TH1F *h_Jets__PhotonMultiplicity     = new TH1F("Jets_Multiplicity__Photon", "Multiplicidad, != 0, de Fotones en cada ak5PFJet; Multiplicidad Foton; Frecuencia", 120, 0, 120);
  TH1F *h_Jets__ElectronMultiplicity   = new TH1F("Jets_Multiplicity__Electron", "Multiplicidad, != 0, de Electrones en cada ak5PFJet; Multiplicidad Electron; Frecuencia", 120, 0, 120);
  TH1F *h_Jets__NeutralHad_Multiplicity= new TH1F("Jets_Multiplicity__NeutralHad", "Multiplicidad, != 0, de Hadrones Neutros en cada ak5PFJet; Multiplicidad HadronNeutral; Frecuencia", 120, 0, 120);
  TH1F *h_Jets__ChargedHad_Multiplicity= new TH1F("Jets_Multiplicity__ChargedHad", "Multiplicidad, != 0, de Hadrones Cargados en cada ak5PFJet; Multiplicidad HadronCargado; Frecuencia", 120, 0, 120);
  // Cocientes.
  TH1F *h_Jets__EnergyQuotient_Muon_Jet    = new TH1F("Jets_Energy_Quotient__Muon-Jet",   "Cociente Energia  Muon / ak5PFJet; Energia_{Muon}/Energia_{ak5PFJet}; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_0Jet10     = new TH1F("Jets_Energy_Quot__Muon-0Jet10",    "Cociente Energ#acute{i}a  Muon / 0<ak5FastJet<10; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_10Jet30    = new TH1F("Jets_Energy_Quot__Muon-10Jet30",   "Cociente Energ#acute{i}a  Muon / 10<ak5FastJet<30; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_30Jet60    = new TH1F("Jets_Energy_Quot__Muon-30Jet60",   "Cociente Energ#acute{i}a  Muon / 30<ak5FastJet<60; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_60Jet100   = new TH1F("Jets_Energy_Quot__Muon-60Jet100",  "Cociente Energ#acute{i}a  Muon / 60<ak5FastJet<100; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_100Jet200  = new TH1F("Jets_Energy_Quot__Muon-100Jet200", "Cociente Energ#acute{i}a  Muon / 100<ak5PFJet<200; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_200Jet300  = new TH1F("Jets_Energy_Quot__Muon-200Jet300", "Cociente Energ#acute{i}a  Muon / 200<ak5PFJet<300; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_300Jet400  = new TH1F("Jets_Energy_Quot__Muon-300Jet400", "Cociente Energ#acute{i}a  Muon / 300<ak5PFJet<400; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_400Jet500  = new TH1F("Jets_Energy_Quot__Muon-400Jet500", "Cociente Energ#acute{i}a  Muon / 400<ak5PFJet<500; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_500Jet600  = new TH1F("Jets_Energy_Quot__Muon-500Jet600", "Cociente Energ#acute{i}a  Muon / 500<ak5PFJet<600; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_600Jet700  = new TH1F("Jets_Energy_Quot__Muon-600Jet700", "Cociente Energ#acute{i}a  Muon / 600<ak5PFJet<700; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_700Jet800  = new TH1F("Jets_Energy_Quot__Muon-700Jet800", "Cociente Energ#acute{i}a  Muon / 700<ak5PFJet<800; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_800Jet900  = new TH1F("Jets_Energy_Quot__Muon-800Jet900", "Cociente Energ#acute{i}a  Muon / 800<ak5PFJet<900; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_900Jet1000 = new TH1F("Jets_Energy_Quot__Muon-900Jet1000", "Cociente Energ#acute{i}a  Muon / 900<ak5PFJet<1000; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_1000Jet    = new TH1F("Jets_Energy_Quot__Muon-1000Jet",   "Cociente Energ#acute{i}a  Muon / 1000<ak5PFJet; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuotient_Photon_Jet    = new TH1F("Jets_Energy_Quotient__Photon-Jet",   "Cociente Energia  Photon / ak5PFJet; Energia_{Photon}/Energia_{ak5PFJet}; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_0Jet10     = new TH1F("Jets_Energy_Quot__Photon-0Jet10",    "Cociente Energ#acute{i}a  Photon / 0<ak5FastJet<10; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_10Jet30    = new TH1F("Jets_Energy_Quot__Photon-10Jet30",   "Cociente Energ#acute{i}a  Photon / 10<ak5FastJet<30; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_30Jet60    = new TH1F("Jets_Energy_Quot__Photon-30Jet60",   "Cociente Energ#acute{i}a  Photon / 30<ak5FastJet<60; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_60Jet100   = new TH1F("Jets_Energy_Quot__Photon-60Jet100",  "Cociente Energ#acute{i}a  Photon / 60<ak5FastJet<100; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_100Jet200  = new TH1F("Jets_Energy_Quot__Photon-100Jet200", "Cociente Energ#acute{i}a  Photon / 100<ak5PFJet<200; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_200Jet300  = new TH1F("Jets_Energy_Quot__Photon-200Jet300", "Cociente Energ#acute{i}a  Photon / 200<ak5PFJet<300; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_300Jet400  = new TH1F("Jets_Energy_Quot__Photon-300Jet400", "Cociente Energ#acute{i}a  Photon / 300<ak5PFJet<400; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_400Jet500  = new TH1F("Jets_Energy_Quot__Photon-400Jet500", "Cociente Energ#acute{i}a  Photon / 400<ak5PFJet<500; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_500Jet600  = new TH1F("Jets_Energy_Quot__Photon-500Jet600", "Cociente Energ#acute{i}a  Photon / 500<ak5PFJet<600; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_600Jet700  = new TH1F("Jets_Energy_Quot__Photon-600Jet700", "Cociente Energ#acute{i}a  Photon / 600<ak5PFJet<700; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_700Jet800  = new TH1F("Jets_Energy_Quot__Photon-700Jet800", "Cociente Energ#acute{i}a  Photon / 700<ak5PFJet<800; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_800Jet900  = new TH1F("Jets_Energy_Quot__Photon-800Jet900", "Cociente Energ#acute{i}a  Photon / 800<ak5PFJet<900; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_900Jet1000 = new TH1F("Jets_Energy_Quot__Photon-900Jet1000", "Cociente Energ#acute{i}a  Photon / 900<ak5PFJet<1000; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_1000Jet    = new TH1F("Jets_Energy_Quot__Photon-1000Jet",   "Cociente Energ#acute{i}a  Photon / 1000<ak5PFJet; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuotient_Electron_Jet    = new TH1F("Jets_Energy_Quotient__Electron-Jet",   "Cociente Energia  Electron / ak5PFJet; Energia_{Electron}/Energia_{ak5PFJet}; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_0Jet10     = new TH1F("Jets_Energy_Quot__Electron-0Jet10",    "Cociente Energ#acute{i}a  Electron / 0<ak5FastJet<10; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_10Jet30    = new TH1F("Jets_Energy_Quot__Electron-10Jet30",   "Cociente Energ#acute{i}a  Electron / 10<ak5FastJet<30; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_30Jet60    = new TH1F("Jets_Energy_Quot__Electron-30Jet60",   "Cociente Energ#acute{i}a  Electron / 30<ak5FastJet<60; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_60Jet100   = new TH1F("Jets_Energy_Quot__Electron-60Jet100",  "Cociente Energ#acute{i}a  Electron / 60<ak5FastJet<100; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_100Jet200  = new TH1F("Jets_Energy_Quot__Electron-100Jet200", "Cociente Energ#acute{i}a  Electron / 100<ak5PFJet<200; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_200Jet300  = new TH1F("Jets_Energy_Quot__Electron-200Jet300", "Cociente Energ#acute{i}a  Electron / 200<ak5PFJet<300; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_300Jet400  = new TH1F("Jets_Energy_Quot__Electron-300Jet400", "Cociente Energ#acute{i}a  Electron / 300<ak5PFJet<400; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_400Jet500  = new TH1F("Jets_Energy_Quot__Electron-400Jet500", "Cociente Energ#acute{i}a  Electron / 400<ak5PFJet<500; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_500Jet600  = new TH1F("Jets_Energy_Quot__Electron-500Jet600", "Cociente Energ#acute{i}a  Electron / 500<ak5PFJet<600; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_600Jet700  = new TH1F("Jets_Energy_Quot__Electron-600Jet700", "Cociente Energ#acute{i}a  Electron / 600<ak5PFJet<700; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_700Jet800  = new TH1F("Jets_Energy_Quot__Electron-700Jet800", "Cociente Energ#acute{i}a  Electron / 700<ak5PFJet<800; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_800Jet900  = new TH1F("Jets_Energy_Quot__Electron-800Jet900", "Cociente Energ#acute{i}a  Electron / 800<ak5PFJet<900; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_900Jet1000 = new TH1F("Jets_Energy_Quot__Electron-900Jet1000", "Cociente Energ#acute{i}a  Electron / 900<ak5PFJet<1000; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_1000Jet    = new TH1F("Jets_Energy_Quot__Electron-1000Jet",   "Cociente Energ#acute{i}a  Electron / 1000<ak5PFJet; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuotient_NeutralHad_Jet  = new TH1F("Jets_Energy_Quotient__NeutralHad-Jet",     "Cociente Energia  NeutralHad / ak5PFJet; Energia_{NeutralHad}/Energia_{ak5PFJet}; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_0Jet10     = new TH1F("Jets_Energy_Quot__NeutralHad-0Jet10",    "Cociente Energ#acute{i}a  NeutralHad / 0<ak5FastJet<10; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_10Jet30    = new TH1F("Jets_Energy_Quot__NeutralHad-10Jet30",   "Cociente Energ#acute{i}a  NeutralHad / 10<ak5FastJet<30; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_30Jet60    = new TH1F("Jets_Energy_Quot__NeutralHad-30Jet60",   "Cociente Energ#acute{i}a  NeutralHad / 30<ak5FastJet<60; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_60Jet100   = new TH1F("Jets_Energy_Quot__NeutralHad-60Jet100",  "Cociente Energ#acute{i}a  NeutralHad / 60<ak5FastJet<100; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_100Jet200  = new TH1F("Jets_Energy_Quot__NeutralHad-100Jet200", "Cociente Energ#acute{i}a  NeutralHad / 100<ak5PFJet<200; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_200Jet300  = new TH1F("Jets_Energy_Quot__NeutralHad-200Jet300", "Cociente Energ#acute{i}a  NeutralHad / 200<ak5PFJet<300; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_300Jet400  = new TH1F("Jets_Energy_Quot__NeutralHad-300Jet400", "Cociente Energ#acute{i}a  NeutralHad / 300<ak5PFJet<400; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_400Jet500  = new TH1F("Jets_Energy_Quot__NeutralHad-400Jet500", "Cociente Energ#acute{i}a  NeutralHad / 400<ak5PFJet<500; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_500Jet600  = new TH1F("Jets_Energy_Quot__NeutralHad-500Jet600", "Cociente Energ#acute{i}a  NeutralHad / 500<ak5PFJet<600; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_600Jet700  = new TH1F("Jets_Energy_Quot__NeutralHad-600Jet700", "Cociente Energ#acute{i}a  NeutralHad / 600<ak5PFJet<700; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_700Jet800  = new TH1F("Jets_Energy_Quot__NeutralHad-700Jet800", "Cociente Energ#acute{i}a  NeutralHad / 700<ak5PFJet<800; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_800Jet900  = new TH1F("Jets_Energy_Quot__NeutralHad-800Jet900", "Cociente Energ#acute{i}a  NeutralHad / 800<ak5PFJet<900; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_900Jet1000 = new TH1F("Jets_Energy_Quot__NeutralHad-900Jet1000", "Cociente Energ#acute{i}a  NeutralHad / 900<ak5PFJet<1000; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_1000Jet    = new TH1F("Jets_Energy_Quot__NeutralHad-1000Jet",   "Cociente Energ#acute{i}a  NeutralHad / 1000<ak5PFJet; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuotient_ChargedHad_Jet    = new TH1F("Jets_Energy_Quotient__ChargedHad-Jet",   "Cociente Energia  ChargedHad / ak5PFJet; Energia_{ChagedHad}/Energia_{ak5PFJet}; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_0Jet10     = new TH1F("Jets_Energy_Quot__ChargedHad-0Jet10",    "Cociente Energ#acute{i}a  ChargedHad / 0<ak5FastJet<10; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_10Jet30    = new TH1F("Jets_Energy_Quot__ChargedHad-10Jet30",   "Cociente Energ#acute{i}a  ChargedHad / 10<ak5FastJet<30; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_30Jet60    = new TH1F("Jets_Energy_Quot__ChargedHad-30Jet60",   "Cociente Energ#acute{i}a  ChargedHad / 30<ak5FastJet<60; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_60Jet100   = new TH1F("Jets_Energy_Quot__ChargedHad-60Jet100",  "Cociente Energ#acute{i}a  ChargedHad / 60<ak5FastJet<100; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_100Jet200  = new TH1F("Jets_Energy_Quot__ChargedHad-100Jet200", "Cociente Energ#acute{i}a  ChargedHad / 100<ak5PFJet<200; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_200Jet300  = new TH1F("Jets_Energy_Quot__ChargedHad-200Jet300", "Cociente Energ#acute{i}a  ChargedHad / 200<ak5PFJet<300; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_300Jet400  = new TH1F("Jets_Energy_Quot__ChargedHad-300Jet400", "Cociente Energ#acute{i}a  ChargedHad / 300<ak5PFJet<400; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_400Jet500  = new TH1F("Jets_Energy_Quot__ChargedHad-400Jet500", "Cociente Energ#acute{i}a  ChargedHad / 400<ak5PFJet<500; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_500Jet600  = new TH1F("Jets_Energy_Quot__ChargedHad-500Jet600", "Cociente Energ#acute{i}a  ChargedHad / 500<ak5PFJet<600; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_600Jet700  = new TH1F("Jets_Energy_Quot__ChargedHad-600Jet700", "Cociente Energ#acute{i}a  ChargedHad / 600<ak5PFJet<700; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_700Jet800  = new TH1F("Jets_Energy_Quot__ChargedHad-700Jet800", "Cociente Energ#acute{i}a  ChargedHad / 700<ak5PFJet<800; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_800Jet900  = new TH1F("Jets_Energy_Quot__ChargedHad-800Jet900", "Cociente Energ#acute{i}a  ChargedHad / 800<ak5PFJet<900; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_900Jet1000 = new TH1F("Jets_Energy_Quot__ChargedHad-900Jet1000", "Cociente Energ#acute{i}a  ChargedHad / 900<ak5PFJet<1000; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_1000Jet    = new TH1F("Jets_Energy_Quot__ChargedHad-1000Jet",   "Cociente Energ#acute{i}a  ChargedHad / 1000<ak5PFJet; Indice; Frecuencia", 120, 0, 1.2);


    printf("\t\t %i) Histogramas creados. \n", nprint++);


  Float_t etaMax = 1.479;

  //###################################################################################################################################################################################
  // Hacemos un loop respecto a todo el conjunto de datos de interés.
  for (Int_t e=0; e<Eventos->GetEntries(); e++) {   // Int_t MultJet_04=0, MultJet_08=0, MultJet_16=0, MultJet_32=0, MultJet_64=0;

    // Eventos->GetEntry(e);
    // Jets->GetEntry(e);
    Jets_pt_  ->GetBranch()->GetEntry(e);
    Jets_eta_ ->GetBranch()->GetEntry(e);
    // Jets_mPileupEnergy -> GetBranch()->GetEntry(e);
    Jets_mMuonEnergy         ->GetBranch()->GetEntry(e);  Jets_mMuonMultiplicity         ->GetBranch()->GetEntry(e);
    Jets_mPhotonEnergy       ->GetBranch()->GetEntry(e);  Jets_mPhotonMultiplicity       ->GetBranch()->GetEntry(e);
    Jets_mElectronEnergy     ->GetBranch()->GetEntry(e);  Jets_mElectronMultiplicity     ->GetBranch()->GetEntry(e);
    Jets_mNeutralHadronEnergy->GetBranch()->GetEntry(e);  Jets_mNeutralHadronMultiplicity->GetBranch()->GetEntry(e);
    Jets_mChargedHadronEnergy->GetBranch()->GetEntry(e);  Jets_mChargedHadronMultiplicity->GetBranch()->GetEntry(e);

    for (Int_t i=0; i<Jets_pt_->GetLen(); i++) {
      if (fabs(Jets_eta_->GetValue(i)) > etaMax) continue;

      // Seleccion respecto a energías mínimas.
      if (Jets_mMuonMultiplicity->GetValue(i)>0 && Jets_mMuonEnergy->GetValue(i)/Jets_mMuonMultiplicity->GetValue(i)<8.0) continue;
      if (Jets_mPhotonMultiplicity->GetValue(i)>0 && Jets_mPhotonEnergy->GetValue(i)/Jets_mPhotonMultiplicity->GetValue(i)<0.8) continue;
      if (Jets_mElectronMultiplicity->GetValue(i)>0 && Jets_mElectronEnergy->GetValue(i)/Jets_mElectronMultiplicity->GetValue(i)<3.8) continue;
      if (Jets_mNeutralHadronMultiplicity->GetValue(i)>0 && Jets_mNeutralHadronEnergy->GetValue(i)/Jets_mNeutralHadronMultiplicity->GetValue(i)<2.6) continue;
      if (Jets_mChargedHadronMultiplicity->GetValue(i)>0 && Jets_mChargedHadronEnergy->GetValue(i)/Jets_mChargedHadronMultiplicity->GetValue(i)<1.0) continue;

      h_Jets_pt_ -> Fill(Jets_pt_->GetValue(i));
      h_Jets_eta_-> Fill(Jets_eta_->GetValue(i));
      // Multiplicidad de Jets en cada Evento.
      h_Jets__Multiplicity -> Fill(Jets_pt_->GetLen());

      // Energías.
      Float_t JetEnergy=Jets_mChargedHadronEnergy->GetValue(i)+Jets_mNeutralHadronEnergy->GetValue(i)+Jets_mElectronEnergy->GetValue(i)+Jets_mPhotonEnergy->GetValue(i)+Jets_mMuonEnergy->GetValue(i);

      h_Jets__Energy -> Fill(JetEnergy);

      // Cociente de la energia de las partículas respecto a al E del Jet. Y Multiplicidad de las particulas en cada Jet.
      if (Jets_mMuonMultiplicity->GetValue(i) != 0) { h_MuonEnergy -> Fill(Jets_mMuonEnergy->GetValue(i));
        h_Jets__EnergyQuotient_Muon_Jet -> Fill(Jets_mMuonEnergy->GetValue(i)/JetEnergy);
        if      (     JetEnergy&&JetEnergy<10 ) h_Jets__EnergyQuot_Muon_0Jet10    -> Fill(Jets_mMuonEnergy->GetValue(i)/JetEnergy);
        else if ( 10<=JetEnergy&&JetEnergy<30 ) h_Jets__EnergyQuot_Muon_10Jet30   -> Fill(Jets_mMuonEnergy->GetValue(i)/JetEnergy);
        else if ( 30<=JetEnergy&&JetEnergy<60 ) h_Jets__EnergyQuot_Muon_30Jet60   -> Fill(Jets_mMuonEnergy->GetValue(i)/JetEnergy);
        else if ( 60<=JetEnergy&&JetEnergy<100) h_Jets__EnergyQuot_Muon_60Jet100  -> Fill(Jets_mMuonEnergy->GetValue(i)/JetEnergy);
        else if (100<=JetEnergy&&JetEnergy<200) h_Jets__EnergyQuot_Muon_100Jet200 -> Fill(Jets_mMuonEnergy->GetValue(i)/JetEnergy);
        else if (200<=JetEnergy&&JetEnergy<300) h_Jets__EnergyQuot_Muon_200Jet300 -> Fill(Jets_mMuonEnergy->GetValue(i)/JetEnergy);
        else if (300<=JetEnergy&&JetEnergy<400) h_Jets__EnergyQuot_Muon_300Jet400 -> Fill(Jets_mMuonEnergy->GetValue(i)/JetEnergy);
        else if (400<=JetEnergy&&JetEnergy<500) h_Jets__EnergyQuot_Muon_400Jet500 -> Fill(Jets_mMuonEnergy->GetValue(i)/JetEnergy);
        else if (500<=JetEnergy&&JetEnergy<600) h_Jets__EnergyQuot_Muon_500Jet600 -> Fill(Jets_mMuonEnergy->GetValue(i)/JetEnergy);
        else if (600<=JetEnergy&&JetEnergy<700) h_Jets__EnergyQuot_Muon_600Jet700 -> Fill(Jets_mMuonEnergy->GetValue(i)/JetEnergy);
        else if (700<=JetEnergy&&JetEnergy<800) h_Jets__EnergyQuot_Muon_700Jet800 -> Fill(Jets_mMuonEnergy->GetValue(i)/JetEnergy);
        else if (800<=JetEnergy&&JetEnergy<900) h_Jets__EnergyQuot_Muon_800Jet900 -> Fill(Jets_mMuonEnergy->GetValue(i)/JetEnergy);
        else if (900<=JetEnergy&&JetEnergy<1000)h_Jets__EnergyQuot_Muon_900Jet1000-> Fill(Jets_mMuonEnergy->GetValue(i)/JetEnergy);
        else                                    h_Jets__EnergyQuot_Muon_1000Jet   -> Fill(Jets_mMuonEnergy->GetValue(i)/JetEnergy);
        //Multiplicidad de Muones en cada Jet.
        h_Jets__MuonMultiplicity->Fill(Jets_mMuonMultiplicity->GetValue(i));
      }
      if (Jets_mPhotonMultiplicity->GetValue(i) != 0) { h_PhotonEnergy -> Fill(Jets_mPhotonEnergy->GetValue(i));
        h_Jets__EnergyQuotient_Photon_Jet -> Fill(Jets_mPhotonEnergy->GetValue(i)/JetEnergy);
        if      (     JetEnergy&&JetEnergy<10 ) h_Jets__EnergyQuot_Photon_0Jet10    -> Fill(Jets_mPhotonEnergy->GetValue(i)/JetEnergy);
        else if ( 10<=JetEnergy&&JetEnergy<30 ) h_Jets__EnergyQuot_Photon_10Jet30   -> Fill(Jets_mPhotonEnergy->GetValue(i)/JetEnergy);
        else if ( 30<=JetEnergy&&JetEnergy<60 ) h_Jets__EnergyQuot_Photon_30Jet60   -> Fill(Jets_mPhotonEnergy->GetValue(i)/JetEnergy);
        else if ( 60<=JetEnergy&&JetEnergy<100) h_Jets__EnergyQuot_Photon_60Jet100  -> Fill(Jets_mPhotonEnergy->GetValue(i)/JetEnergy);
        else if (100<=JetEnergy&&JetEnergy<200) h_Jets__EnergyQuot_Photon_100Jet200 -> Fill(Jets_mPhotonEnergy->GetValue(i)/JetEnergy);
        else if (200<=JetEnergy&&JetEnergy<300) h_Jets__EnergyQuot_Photon_200Jet300 -> Fill(Jets_mPhotonEnergy->GetValue(i)/JetEnergy);
        else if (300<=JetEnergy&&JetEnergy<400) h_Jets__EnergyQuot_Photon_300Jet400 -> Fill(Jets_mPhotonEnergy->GetValue(i)/JetEnergy);
        else if (400<=JetEnergy&&JetEnergy<500) h_Jets__EnergyQuot_Photon_400Jet500 -> Fill(Jets_mPhotonEnergy->GetValue(i)/JetEnergy);
        else if (500<=JetEnergy&&JetEnergy<600) h_Jets__EnergyQuot_Photon_500Jet600 -> Fill(Jets_mPhotonEnergy->GetValue(i)/JetEnergy);
        else if (600<=JetEnergy&&JetEnergy<700) h_Jets__EnergyQuot_Photon_600Jet700 -> Fill(Jets_mPhotonEnergy->GetValue(i)/JetEnergy);
        else if (700<=JetEnergy&&JetEnergy<800) h_Jets__EnergyQuot_Photon_700Jet800 -> Fill(Jets_mPhotonEnergy->GetValue(i)/JetEnergy);
        else if (800<=JetEnergy&&JetEnergy<900) h_Jets__EnergyQuot_Photon_800Jet900 -> Fill(Jets_mPhotonEnergy->GetValue(i)/JetEnergy);
        else if (900<=JetEnergy&&JetEnergy<1000)h_Jets__EnergyQuot_Photon_900Jet1000-> Fill(Jets_mPhotonEnergy->GetValue(i)/JetEnergy);
        else                                    h_Jets__EnergyQuot_Photon_1000Jet   -> Fill(Jets_mPhotonEnergy->GetValue(i)/JetEnergy);
        //Multiplicidad de Fotones en cada Jet.
        h_Jets__PhotonMultiplicity->Fill(Jets_mPhotonMultiplicity->GetValue(i));
      }
      if (Jets_mElectronMultiplicity->GetValue(i) != 0) { h_ElectronEnergy -> Fill(Jets_mElectronEnergy->GetValue(i));
        h_Jets__EnergyQuotient_Electron_Jet -> Fill(Jets_mElectronEnergy->GetValue(i)/JetEnergy);
        if      (     JetEnergy&&JetEnergy<10 ) h_Jets__EnergyQuot_Electron_0Jet10    -> Fill(Jets_mElectronEnergy->GetValue(i)/JetEnergy);
        else if ( 10<=JetEnergy&&JetEnergy<30 ) h_Jets__EnergyQuot_Electron_10Jet30   -> Fill(Jets_mElectronEnergy->GetValue(i)/JetEnergy);
        else if ( 30<=JetEnergy&&JetEnergy<60 ) h_Jets__EnergyQuot_Electron_30Jet60   -> Fill(Jets_mElectronEnergy->GetValue(i)/JetEnergy);
        else if ( 60<=JetEnergy&&JetEnergy<100) h_Jets__EnergyQuot_Electron_60Jet100  -> Fill(Jets_mElectronEnergy->GetValue(i)/JetEnergy);
        else if (100<=JetEnergy&&JetEnergy<200) h_Jets__EnergyQuot_Electron_100Jet200 -> Fill(Jets_mElectronEnergy->GetValue(i)/JetEnergy);
        else if (200<=JetEnergy&&JetEnergy<300) h_Jets__EnergyQuot_Electron_200Jet300 -> Fill(Jets_mElectronEnergy->GetValue(i)/JetEnergy);
        else if (300<=JetEnergy&&JetEnergy<400) h_Jets__EnergyQuot_Electron_300Jet400 -> Fill(Jets_mElectronEnergy->GetValue(i)/JetEnergy);
        else if (400<=JetEnergy&&JetEnergy<500) h_Jets__EnergyQuot_Electron_400Jet500 -> Fill(Jets_mElectronEnergy->GetValue(i)/JetEnergy);
        else if (500<=JetEnergy&&JetEnergy<600) h_Jets__EnergyQuot_Electron_500Jet600 -> Fill(Jets_mElectronEnergy->GetValue(i)/JetEnergy);
        else if (600<=JetEnergy&&JetEnergy<700) h_Jets__EnergyQuot_Electron_600Jet700 -> Fill(Jets_mElectronEnergy->GetValue(i)/JetEnergy);
        else if (700<=JetEnergy&&JetEnergy<800) h_Jets__EnergyQuot_Electron_700Jet800 -> Fill(Jets_mElectronEnergy->GetValue(i)/JetEnergy);
        else if (800<=JetEnergy&&JetEnergy<900) h_Jets__EnergyQuot_Electron_800Jet900 -> Fill(Jets_mElectronEnergy->GetValue(i)/JetEnergy);
        else if (900<=JetEnergy&&JetEnergy<1000)h_Jets__EnergyQuot_Electron_900Jet1000-> Fill(Jets_mElectronEnergy->GetValue(i)/JetEnergy);
        else                                    h_Jets__EnergyQuot_Electron_1000Jet   -> Fill(Jets_mElectronEnergy->GetValue(i)/JetEnergy);
        //Multiplicidad de Electrones en cada Jet.
        h_Jets__ElectronMultiplicity->Fill(Jets_mElectronMultiplicity->GetValue(i));
      }
      if (Jets_mNeutralHadronMultiplicity->GetValue(i) != 0) { h_NeutralHadronEnergy -> Fill(Jets_mNeutralHadronEnergy->GetValue(i));
        h_Jets__EnergyQuotient_NeutralHad_Jet -> Fill(Jets_mNeutralHadronEnergy->GetValue(i)/JetEnergy);
        if      (     JetEnergy&&JetEnergy<10 ) h_Jets__EnergyQuot_NeutralHad_0Jet10    -> Fill(Jets_mNeutralHadronEnergy->GetValue(i)/JetEnergy);
        else if ( 10<=JetEnergy&&JetEnergy<30 ) h_Jets__EnergyQuot_NeutralHad_10Jet30   -> Fill(Jets_mNeutralHadronEnergy->GetValue(i)/JetEnergy);
        else if ( 30<=JetEnergy&&JetEnergy<60 ) h_Jets__EnergyQuot_NeutralHad_30Jet60   -> Fill(Jets_mNeutralHadronEnergy->GetValue(i)/JetEnergy);
        else if ( 60<=JetEnergy&&JetEnergy<100) h_Jets__EnergyQuot_NeutralHad_60Jet100  -> Fill(Jets_mNeutralHadronEnergy->GetValue(i)/JetEnergy);
        else if (100<=JetEnergy&&JetEnergy<200) h_Jets__EnergyQuot_NeutralHad_100Jet200 -> Fill(Jets_mNeutralHadronEnergy->GetValue(i)/JetEnergy);
        else if (200<=JetEnergy&&JetEnergy<300) h_Jets__EnergyQuot_NeutralHad_200Jet300 -> Fill(Jets_mNeutralHadronEnergy->GetValue(i)/JetEnergy);
        else if (300<=JetEnergy&&JetEnergy<400) h_Jets__EnergyQuot_NeutralHad_300Jet400 -> Fill(Jets_mNeutralHadronEnergy->GetValue(i)/JetEnergy);
        else if (400<=JetEnergy&&JetEnergy<500) h_Jets__EnergyQuot_NeutralHad_400Jet500 -> Fill(Jets_mNeutralHadronEnergy->GetValue(i)/JetEnergy);
        else if (500<=JetEnergy&&JetEnergy<600) h_Jets__EnergyQuot_NeutralHad_500Jet600 -> Fill(Jets_mNeutralHadronEnergy->GetValue(i)/JetEnergy);
        else if (600<=JetEnergy&&JetEnergy<700) h_Jets__EnergyQuot_NeutralHad_600Jet700 -> Fill(Jets_mNeutralHadronEnergy->GetValue(i)/JetEnergy);
        else if (700<=JetEnergy&&JetEnergy<800) h_Jets__EnergyQuot_NeutralHad_700Jet800 -> Fill(Jets_mNeutralHadronEnergy->GetValue(i)/JetEnergy);
        else if (800<=JetEnergy&&JetEnergy<900) h_Jets__EnergyQuot_NeutralHad_800Jet900 -> Fill(Jets_mNeutralHadronEnergy->GetValue(i)/JetEnergy);
        else if (900<=JetEnergy&&JetEnergy<1000)h_Jets__EnergyQuot_NeutralHad_900Jet1000-> Fill(Jets_mNeutralHadronEnergy->GetValue(i)/JetEnergy);
        else                                    h_Jets__EnergyQuot_NeutralHad_1000Jet   -> Fill(Jets_mNeutralHadronEnergy->GetValue(i)/JetEnergy);
        //Multiplicidad de Hadrones Neutros en cada Jet.
        h_Jets__NeutralHad_Multiplicity->Fill(Jets_mNeutralHadronMultiplicity->GetValue(i));
      }
      if (Jets_mChargedHadronMultiplicity->GetValue(i) != 0) { h_ChargedHadronEnergy -> Fill(Jets_mChargedHadronEnergy->GetValue(i));
        h_Jets__EnergyQuotient_ChargedHad_Jet -> Fill(Jets_mChargedHadronEnergy->GetValue(i)/JetEnergy);
        if      (     JetEnergy&&JetEnergy<10 ) h_Jets__EnergyQuot_ChargedHad_0Jet10    -> Fill(Jets_mChargedHadronEnergy->GetValue(i)/JetEnergy);
        else if ( 10<=JetEnergy&&JetEnergy<30 ) h_Jets__EnergyQuot_ChargedHad_10Jet30   -> Fill(Jets_mChargedHadronEnergy->GetValue(i)/JetEnergy);
        else if ( 30<=JetEnergy&&JetEnergy<60 ) h_Jets__EnergyQuot_ChargedHad_30Jet60   -> Fill(Jets_mChargedHadronEnergy->GetValue(i)/JetEnergy);
        else if ( 60<=JetEnergy&&JetEnergy<100) h_Jets__EnergyQuot_ChargedHad_60Jet100  -> Fill(Jets_mChargedHadronEnergy->GetValue(i)/JetEnergy);
        else if (100<=JetEnergy&&JetEnergy<200) h_Jets__EnergyQuot_ChargedHad_100Jet200 -> Fill(Jets_mChargedHadronEnergy->GetValue(i)/JetEnergy);
        else if (200<=JetEnergy&&JetEnergy<300) h_Jets__EnergyQuot_ChargedHad_200Jet300 -> Fill(Jets_mChargedHadronEnergy->GetValue(i)/JetEnergy);
        else if (300<=JetEnergy&&JetEnergy<400) h_Jets__EnergyQuot_ChargedHad_300Jet400 -> Fill(Jets_mChargedHadronEnergy->GetValue(i)/JetEnergy);
        else if (400<=JetEnergy&&JetEnergy<500) h_Jets__EnergyQuot_ChargedHad_400Jet500 -> Fill(Jets_mChargedHadronEnergy->GetValue(i)/JetEnergy);
        else if (500<=JetEnergy&&JetEnergy<600) h_Jets__EnergyQuot_ChargedHad_500Jet600 -> Fill(Jets_mChargedHadronEnergy->GetValue(i)/JetEnergy);
        else if (600<=JetEnergy&&JetEnergy<700) h_Jets__EnergyQuot_ChargedHad_600Jet700 -> Fill(Jets_mChargedHadronEnergy->GetValue(i)/JetEnergy);
        else if (700<=JetEnergy&&JetEnergy<800) h_Jets__EnergyQuot_ChargedHad_700Jet800 -> Fill(Jets_mChargedHadronEnergy->GetValue(i)/JetEnergy);
        else if (800<=JetEnergy&&JetEnergy<900) h_Jets__EnergyQuot_ChargedHad_800Jet900 -> Fill(Jets_mChargedHadronEnergy->GetValue(i)/JetEnergy);
        else if (900<=JetEnergy&&JetEnergy<1000)h_Jets__EnergyQuot_ChargedHad_900Jet1000-> Fill(Jets_mChargedHadronEnergy->GetValue(i)/JetEnergy);
        else                                    h_Jets__EnergyQuot_ChargedHad_1000Jet   -> Fill(Jets_mChargedHadronEnergy->GetValue(i)/JetEnergy);
        // Multiplicidad de Hadrones Cargados en cada Jet.
        h_Jets__ChargedHad_Multiplicity->Fill(Jets_mChargedHadronMultiplicity->GetValue(i));
      }
      // Multiplicidad de Partículas en cada Jet.
    } // for loop i

      // printf("\t \t Dont worry. Evento %i hecho. =D \n\n", e);

  } // for loop e
  //###################################################################################################################################################################################


    printf("\t\t %i) Datos extraidos. \n", nprint++);


  // Guardamos nustros histogramas en el archivo root que nos interesa.
  h_Jets_pt_           -> Write();
  h_Jets_eta_          -> Write();
  h_Jets__Energy       -> Write();
  h_MuonEnergy         -> Write();
  h_PhotonEnergy       -> Write();
  h_ElectronEnergy     -> Write();
  h_NeutralHadronEnergy-> Write();
  h_ChargedHadronEnergy-> Write();
  // Multiplicidad
  h_Jets__Multiplicity           -> Write();
  h_Jets__MuonMultiplicity       -> Write();
  h_Jets__PhotonMultiplicity     -> Write();
  h_Jets__ElectronMultiplicity   -> Write();
  h_Jets__NeutralHad_Multiplicity-> Write();
  h_Jets__ChargedHad_Multiplicity-> Write();
  // Cocientes
  h_Jets__EnergyQuotient_Muon_Jet   -> Write();
  h_Jets__EnergyQuot_Muon_0Jet10    -> Write();
  h_Jets__EnergyQuot_Muon_10Jet30   -> Write();
  h_Jets__EnergyQuot_Muon_30Jet60   -> Write();
  h_Jets__EnergyQuot_Muon_60Jet100  -> Write();
  h_Jets__EnergyQuot_Muon_100Jet200 -> Write();
  h_Jets__EnergyQuot_Muon_200Jet300 -> Write();
  h_Jets__EnergyQuot_Muon_300Jet400 -> Write();
  h_Jets__EnergyQuot_Muon_400Jet500 -> Write();
  h_Jets__EnergyQuot_Muon_500Jet600 -> Write();
  h_Jets__EnergyQuot_Muon_600Jet700 -> Write();
  h_Jets__EnergyQuot_Muon_700Jet800 -> Write();
  h_Jets__EnergyQuot_Muon_800Jet900 -> Write();
  h_Jets__EnergyQuot_Muon_900Jet1000-> Write();
  h_Jets__EnergyQuot_Muon_1000Jet   -> Write();
  h_Jets__EnergyQuotient_Photon_Jet   -> Write();
  h_Jets__EnergyQuot_Photon_0Jet10    -> Write();
  h_Jets__EnergyQuot_Photon_10Jet30   -> Write();
  h_Jets__EnergyQuot_Photon_30Jet60   -> Write();
  h_Jets__EnergyQuot_Photon_60Jet100  -> Write();
  h_Jets__EnergyQuot_Photon_100Jet200 -> Write();
  h_Jets__EnergyQuot_Photon_200Jet300 -> Write();
  h_Jets__EnergyQuot_Photon_300Jet400 -> Write();
  h_Jets__EnergyQuot_Photon_400Jet500 -> Write();
  h_Jets__EnergyQuot_Photon_500Jet600 -> Write();
  h_Jets__EnergyQuot_Photon_600Jet700 -> Write();
  h_Jets__EnergyQuot_Photon_700Jet800 -> Write();
  h_Jets__EnergyQuot_Photon_800Jet900 -> Write();
  h_Jets__EnergyQuot_Photon_900Jet1000-> Write();
  h_Jets__EnergyQuot_Photon_1000Jet   -> Write();
  h_Jets__EnergyQuotient_Electron_Jet   -> Write();
  h_Jets__EnergyQuot_Electron_0Jet10    -> Write();
  h_Jets__EnergyQuot_Electron_10Jet30   -> Write();
  h_Jets__EnergyQuot_Electron_30Jet60   -> Write();
  h_Jets__EnergyQuot_Electron_60Jet100  -> Write();
  h_Jets__EnergyQuot_Electron_100Jet200 -> Write();
  h_Jets__EnergyQuot_Electron_200Jet300 -> Write();
  h_Jets__EnergyQuot_Electron_300Jet400 -> Write();
  h_Jets__EnergyQuot_Electron_400Jet500 -> Write();
  h_Jets__EnergyQuot_Electron_500Jet600 -> Write();
  h_Jets__EnergyQuot_Electron_600Jet700 -> Write();
  h_Jets__EnergyQuot_Electron_700Jet800 -> Write();
  h_Jets__EnergyQuot_Electron_800Jet900 -> Write();
  h_Jets__EnergyQuot_Electron_900Jet1000-> Write();
  h_Jets__EnergyQuot_Electron_1000Jet   -> Write();
  h_Jets__EnergyQuotient_NeutralHad_Jet -> Write();
  h_Jets__EnergyQuot_NeutralHad_0Jet10    -> Write();
  h_Jets__EnergyQuot_NeutralHad_10Jet30   -> Write();
  h_Jets__EnergyQuot_NeutralHad_30Jet60   -> Write();
  h_Jets__EnergyQuot_NeutralHad_60Jet100  -> Write();
  h_Jets__EnergyQuot_NeutralHad_100Jet200 -> Write();
  h_Jets__EnergyQuot_NeutralHad_200Jet300 -> Write();
  h_Jets__EnergyQuot_NeutralHad_300Jet400 -> Write();
  h_Jets__EnergyQuot_NeutralHad_400Jet500 -> Write();
  h_Jets__EnergyQuot_NeutralHad_500Jet600 -> Write();
  h_Jets__EnergyQuot_NeutralHad_600Jet700 -> Write();
  h_Jets__EnergyQuot_NeutralHad_700Jet800 -> Write();
  h_Jets__EnergyQuot_NeutralHad_800Jet900 -> Write();
  h_Jets__EnergyQuot_NeutralHad_900Jet1000-> Write();
  h_Jets__EnergyQuot_NeutralHad_1000Jet   -> Write();
  h_Jets__EnergyQuotient_ChargedHad_Jet   -> Write();
  h_Jets__EnergyQuot_ChargedHad_0Jet10    -> Write();
  h_Jets__EnergyQuot_ChargedHad_10Jet30   -> Write();
  h_Jets__EnergyQuot_ChargedHad_30Jet60   -> Write();
  h_Jets__EnergyQuot_ChargedHad_60Jet100  -> Write();
  h_Jets__EnergyQuot_ChargedHad_100Jet200 -> Write();
  h_Jets__EnergyQuot_ChargedHad_200Jet300 -> Write();
  h_Jets__EnergyQuot_ChargedHad_300Jet400 -> Write();
  h_Jets__EnergyQuot_ChargedHad_400Jet500 -> Write();
  h_Jets__EnergyQuot_ChargedHad_500Jet600 -> Write();
  h_Jets__EnergyQuot_ChargedHad_600Jet700 -> Write();
  h_Jets__EnergyQuot_ChargedHad_700Jet800 -> Write();
  h_Jets__EnergyQuot_ChargedHad_800Jet900 -> Write();
  h_Jets__EnergyQuot_ChargedHad_900Jet1000-> Write();
  h_Jets__EnergyQuot_ChargedHad_1000Jet   -> Write();


  // Cerramos y eliminamos los archivos abierto y creado.
  InputFile->Close();
  delete OutputFile;
  // new TBrowser();


    printf("\t\t %i) Análisis terminado!\n\n", nprint++);

}
