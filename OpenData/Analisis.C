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
  TLeaf *Jets_phi_                       = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.phi_");
  // TLeaf *Jets_meta_jrea                  = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.mJetArea");
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
  TH1F* h_Jets_pt_         = new TH1F("Jets_pt_",  "Espectro de p_{T} de ak5FastJet; p_{T} [GeV]; Ocurrencia", 1200, 0, 2400);
  TH1F *h_Jets_eta_        = new TH1F("Jets_eta_", "Distribución en #eta de ak5FastJet; #eta; Ocurrencia", 599, -5.95, 5.95);
  TH1F *h_JetEnergy        = new TH1F("Jets_Energy", "Energ#acute{i}a de FastJets; Energ#acute{i}a [GeV]; Frecuencia", 1800, 0, 3600);
  TH1F *h_MuonEnergy       = new TH1F("Jets_MuonEnergy", "Energ#acute{i}a de Muones; Energ#acute{i}a [GeV]; Frecuencia", 1800, 0, 3600);
  TH1F *h_PhotonEnergy     = new TH1F("Jets_PhotonEnergy", "Energ#acute{i}a de Fotones; Energ#acute{i}a [GeV]; Frecuencia", 1800, 0, 3600);
  TH1F *h_ElectronEnergy   = new TH1F("Jets_ElectronEnergy", "Energ#acute{i}a de Electrones; Energ#acute{i}a [GeV]; Frecuencia", 1800, 0, 3600);
  TH1F *h_NeutralHadronEnergy = new TH1F("Jets_NeutralHadronEnergy", "Energ#acute{i}a de Hadrones Neutros; Energ#acute{i}a [GeV]; Frecuencia", 1800, 0, 3600);
  TH1F *h_ChargedHadronEnergy = new TH1F("Jets_ChargedHadronEnergy", "Energ#acute{i}a de Hadrones Cargados; Energ#acute{i}a [GeV]; Frecuencia", 1800, 0, 3600);
  // Multiplicidad.
  TH1F* h_Jets__Multipicity= new TH1F("Jets__Multiplicity", "Multiplicidad, de ak5FastJet, por Evento; Multilicidad; Ocurrencia", 120, 0, 120);
  TH1F *h_Jets__MuonMultiplicity       = new TH1F("Jets_Multiplicity__Muon!=0", "Multiplicidad, != 0, de Muones en cada ak5PFJet; Multiplicidad Muon; Frecuencia", 12, 0, 12);
  TH1F *h_Jets__PhotonMultiplicity     = new TH1F("Jets_Multiplicity__Photon!=0", "Multiplicidad, != 0, de Fotones en cada ak5PFJet; Multiplicidad Foton; Frecuencia", 120, 0, 120);
  TH1F *h_Jets__ElectronMultiplicity   = new TH1F("Jets_Multiplicity__Electron!=0", "Multiplicidad, != 0, de Electrones en cada ak5PFJet; Multiplicidad Electron; Frecuencia", 12, 0, 12);
  TH1F *h_Jets__ChaHad_Multiplicity    = new TH1F("Jets_Multiplicity__ChaHad", "Multiplicidad HadronCargado en cada ak5PFJet; Multiplicidad HadronCargado; Frecuencia", 100, 0, 100);
  TH1F *h_Jets__NeuHad_Multiplicity    = new TH1F("Jets_Multiplicity__NeuHad", "Multiplicidad HadronNeutro en cada ak5PFJet; Multiplicidad HadronNeutral; Frecuencia", 100, 0, 100);
  TH1F *h_Jets__Multiplicity       = new TH1F("Jets__Multiplicity", "Multiplicidad de ak5PFJet por Evento; Numero de Jets; Frecuencia", 120, 0, 120);
  TH1F *h_Jets_pT04__Multiplicity  = new TH1F("Jets_pT>04__Multiplicity", "Multiplicidad de ak5PFJet, con p_{T} > 04 GeV, por Evento; Numero de Jets; Frecuencia", 120, 0, 120);
  TH1F *h_Jets_pT08__Multiplicity  = new TH1F("Jets_pT>08__Multiplicity", "Multiplicidad de ak5PFJet, con p_{T} > 08 GeV, por Evento; Numero de Jets; Frecuencia", 120, 0, 120);
  TH1F *h_Jets_pT16__Multiplicity  = new TH1F("Jets_pT>16__Multiplicity", "Multiplicidad de ak5PFJet, con p_{T} > 16 GeV, por Evento; Numero de Jets; Frecuencia", 120, 0, 120);
  TH1F *h_Jets_pT32__Multiplicity  = new TH1F("Jets_pT>32__Multiplicity", "Multiplicidad de ak5PFJet, con p_{T} > 32 GeV, por Evento; Numero de Jets; Frecuencia", 120, 0, 120);
  TH1F *h_Jets_pT64__Multiplicity  = new TH1F("Jets_pT>64__Multiplicity", "Multiplicidad de ak5PFJet, con p_{T} > 64 GeV, por Evento; Numero de Jets; Frecuencia", 120, 0, 120);
  // Espectro de p_T.
  TH1F *h_Jets_Multiplicity64__pT = new TH1F("Jets_Mult<=64__pT", "Distribucion de pT de ak5PFJet, con Multilicidad <= 64, por Evento; p_{T} [GeV]; Frecuencia", 800, 0, 3200);
  TH1F *h_Jets_Multiplicity32__pT = new TH1F("Jets_Mult<=32__pT", "Distribucion de pT de ak5PFJet, con Multilicidad <= 32, por Evento; p_{T} [GeV]; Frecuencia", 800, 0, 3200);
  TH1F *h_Jets_Multiplicity16__pT = new TH1F("Jets_Mult<=16__pT", "Distribucion de pT de ak5PFJet, con Multilicidad <= 16, por Evento; p_{T} [GeV]; Frecuencia", 800, 0, 3200);
  TH1F *h_Jets_Multiplicity08__pT = new TH1F("Jets_Mult<=08__pT", "Distribucion de pT de ak5PFJet, con Multilicidad <= 08, por Evento; p_{T} [GeV]; Frecuencia", 800, 0, 3200);
  TH1F *h_Jets_Multiplicity04__pT = new TH1F("Jets_Mult<=04__pT", "Distribucion de pT de ak5PFJet, con Multilicidad <= 04, por Evento; p_{T} [GeV]; Frecuencia", 800, 0, 3200);
  TH1F *h_Jets_Multiplicity02__pT = new TH1F("Jets_Mult<=02__pT", "Distribucion de pT de ak5PFJet, con Multilicidad <= 02, por Evento; p_{T} [GeV]; Frecuencia", 800, 0, 3200);
  // Cocientes.
  TH1F *h_Jets__EnergyQuotient_Muon_Jet    = new TH1F("Jets_Energy_Quotient__Muon-Jet",   "Cociente Energia  Muon / ak5PFJet; Energia_{Muon}/Energia_{ak5PFJet}; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_Jet100     = new TH1F("Jets_Energy_Quot__Muon-0Jet100",   "Cociente Energ#acute{i}a  Muon / 0<ak5PFJet<100; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_100Jet200  = new TH1F("Jets_Energy_Quot__Muon-100Jet100", "Cociente Energ#acute{i}a  Muon / 100<ak5PFJet<200; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_200Jet300  = new TH1F("Jets_Energy_Quot__Muon-200Jet100", "Cociente Energ#acute{i}a  Muon / 200<ak5PFJet<300; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_300Jet400  = new TH1F("Jets_Energy_Quot__Muon-300Jet100", "Cociente Energ#acute{i}a  Muon / 300<ak5PFJet<400; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_400Jet500  = new TH1F("Jets_Energy_Quot__Muon-400Jet100", "Cociente Energ#acute{i}a  Muon / 400<ak5PFJet<500; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_500Jet600  = new TH1F("Jets_Energy_Quot__Muon-500Jet100", "Cociente Energ#acute{i}a  Muon / 500<ak5PFJet<600; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_600Jet700  = new TH1F("Jets_Energy_Quot__Muon-600Jet100", "Cociente Energ#acute{i}a  Muon / 600<ak5PFJet<700; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_700Jet800  = new TH1F("Jets_Energy_Quot__Muon-700Jet100", "Cociente Energ#acute{i}a  Muon / 700<ak5PFJet<800; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_800Jet900  = new TH1F("Jets_Energy_Quot__Muon-800Jet100", "Cociente Energ#acute{i}a  Muon / 800<ak5PFJet<900; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_900Jet1000 = new TH1F("Jets_Energy_Quot__Muon-900Jet100", "Cociente Energ#acute{i}a  Muon / 900<ak5PFJet<1000; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_1000Jet    = new TH1F("Jets_Energy_Quot__Muon-1000Jet",   "Cociente Energ#acute{i}a  Muon / 1000<ak5PFJet; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuotient_Photon_Jet    = new TH1F("Jets_Energy_Quotient__Photon-Jet",   "Cociente Energia  Photon / ak5PFJet; Energia_{Photon}/Energia_{ak5PFJet}; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_Jet100     = new TH1F("Jets_Energy_Quot__Photon-0Jet100",   "Cociente Energ#acute{i}a  Photon / 0<ak5PFJet<100; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_100Jet200  = new TH1F("Jets_Energy_Quot__Photon-100Jet100", "Cociente Energ#acute{i}a  Photon / 100<ak5PFJet<200; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_200Jet300  = new TH1F("Jets_Energy_Quot__Photon-200Jet100", "Cociente Energ#acute{i}a  Photon / 200<ak5PFJet<300; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_300Jet400  = new TH1F("Jets_Energy_Quot__Photon-300Jet100", "Cociente Energ#acute{i}a  Photon / 300<ak5PFJet<400; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_400Jet500  = new TH1F("Jets_Energy_Quot__Photon-400Jet100", "Cociente Energ#acute{i}a  Photon / 400<ak5PFJet<500; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_500Jet600  = new TH1F("Jets_Energy_Quot__Photon-500Jet100", "Cociente Energ#acute{i}a  Photon / 500<ak5PFJet<600; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_600Jet700  = new TH1F("Jets_Energy_Quot__Photon-600Jet100", "Cociente Energ#acute{i}a  Photon / 600<ak5PFJet<700; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_700Jet800  = new TH1F("Jets_Energy_Quot__Photon-700Jet100", "Cociente Energ#acute{i}a  Photon / 700<ak5PFJet<800; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_800Jet900  = new TH1F("Jets_Energy_Quot__Photon-800Jet100", "Cociente Energ#acute{i}a  Photon / 800<ak5PFJet<900; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_900Jet1000 = new TH1F("Jets_Energy_Quot__Photon-900Jet100", "Cociente Energ#acute{i}a  Photon / 900<ak5PFJet<1000; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_1000Jet    = new TH1F("Jets_Energy_Quot__Photon-1000Jet",   "Cociente Energ#acute{i}a  Photon / 1000<ak5PFJet; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuotient_Electron_Jet    = new TH1F("Jets_Energy_Quotient__Electron-Jet",   "Cociente Energia  Electron / ak5PFJet; Energia_{Electron}/Energia_{ak5PFJet}; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_Jet100     = new TH1F("Jets_Energy_Quot__Electron-0Jet100",   "Cociente Energ#acute{i}a  Electron / 0<ak5PFJet<100; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_100Jet200  = new TH1F("Jets_Energy_Quot__Electron-100Jet100", "Cociente Energ#acute{i}a  Electron / 100<ak5PFJet<200; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_200Jet300  = new TH1F("Jets_Energy_Quot__Electron-200Jet100", "Cociente Energ#acute{i}a  Electron / 200<ak5PFJet<300; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_300Jet400  = new TH1F("Jets_Energy_Quot__Electron-300Jet100", "Cociente Energ#acute{i}a  Electron / 300<ak5PFJet<400; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_400Jet500  = new TH1F("Jets_Energy_Quot__Electron-400Jet100", "Cociente Energ#acute{i}a  Electron / 400<ak5PFJet<500; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_500Jet600  = new TH1F("Jets_Energy_Quot__Electron-500Jet100", "Cociente Energ#acute{i}a  Electron / 500<ak5PFJet<600; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_600Jet700  = new TH1F("Jets_Energy_Quot__Electron-600Jet100", "Cociente Energ#acute{i}a  Electron / 600<ak5PFJet<700; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_700Jet800  = new TH1F("Jets_Energy_Quot__Electron-700Jet100", "Cociente Energ#acute{i}a  Electron / 700<ak5PFJet<800; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_800Jet900  = new TH1F("Jets_Energy_Quot__Electron-800Jet100", "Cociente Energ#acute{i}a  Electron / 800<ak5PFJet<900; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_900Jet1000 = new TH1F("Jets_Energy_Quot__Electron-900Jet100", "Cociente Energ#acute{i}a  Electron / 900<ak5PFJet<1000; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_1000Jet    = new TH1F("Jets_Energy_Quot__Electron-1000Jet",   "Cociente Energ#acute{i}a  Electron / 1000<ak5PFJet; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuotient_NeutralHad_Jet  = new TH1F("Jets_Energy_Quotient__NeutralHad-Jet",     "Cociente Energia  NeutralHad / ak5PFJet; Energia_{NeutralHad}/Energia_{ak5PFJet}; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_Jet100     = new TH1F("Jets_Energy_Quot__NeutralHad-0Jet100",   "Cociente Energ#acute{i}a  NeutralHad / 0<ak5PFJet<100; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_100Jet200  = new TH1F("Jets_Energy_Quot__NeutralHad-100Jet100", "Cociente Energ#acute{i}a  NeutralHad / 100<ak5PFJet<200; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_200Jet300  = new TH1F("Jets_Energy_Quot__NeutralHad-200Jet100", "Cociente Energ#acute{i}a  NeutralHad / 200<ak5PFJet<300; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_300Jet400  = new TH1F("Jets_Energy_Quot__NeutralHad-300Jet100", "Cociente Energ#acute{i}a  NeutralHad / 300<ak5PFJet<400; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_400Jet500  = new TH1F("Jets_Energy_Quot__NeutralHad-400Jet100", "Cociente Energ#acute{i}a  NeutralHad / 400<ak5PFJet<500; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_500Jet600  = new TH1F("Jets_Energy_Quot__NeutralHad-500Jet100", "Cociente Energ#acute{i}a  NeutralHad / 500<ak5PFJet<600; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_600Jet700  = new TH1F("Jets_Energy_Quot__NeutralHad-600Jet100", "Cociente Energ#acute{i}a  NeutralHad / 600<ak5PFJet<700; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_700Jet800  = new TH1F("Jets_Energy_Quot__NeutralHad-700Jet100", "Cociente Energ#acute{i}a  NeutralHad / 700<ak5PFJet<800; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_800Jet900  = new TH1F("Jets_Energy_Quot__NeutralHad-800Jet100", "Cociente Energ#acute{i}a  NeutralHad / 800<ak5PFJet<900; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_900Jet1000 = new TH1F("Jets_Energy_Quot__NeutralHad-900Jet100", "Cociente Energ#acute{i}a  NeutralHad / 900<ak5PFJet<1000; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_1000Jet    = new TH1F("Jets_Energy_Quot__NeutralHad-1000Jet",   "Cociente Energ#acute{i}a  NeutralHad / 1000<ak5PFJet; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuotient_ChargedHad_Jet    = new TH1F("Jets_Energy_Quotient__ChargedHad-Jet",   "Cociente Energia  ChargedHad / ak5PFJet; Energia_{ChagedHad}/Energia_{ak5PFJet}; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_Jet100     = new TH1F("Jets_Energy_Quot__ChargedHad-0Jet100",   "Cociente Energ#acute{i}a  ChargedHad / 0<ak5PFJet<100; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_100Jet200  = new TH1F("Jets_Energy_Quot__ChargedHad-100Jet100", "Cociente Energ#acute{i}a  ChargedHad / 100<ak5PFJet<200; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_200Jet300  = new TH1F("Jets_Energy_Quot__ChargedHad-200Jet100", "Cociente Energ#acute{i}a  ChargedHad / 200<ak5PFJet<300; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_300Jet400  = new TH1F("Jets_Energy_Quot__ChargedHad-300Jet100", "Cociente Energ#acute{i}a  ChargedHad / 300<ak5PFJet<400; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_400Jet500  = new TH1F("Jets_Energy_Quot__ChargedHad-400Jet100", "Cociente Energ#acute{i}a  ChargedHad / 400<ak5PFJet<500; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_500Jet600  = new TH1F("Jets_Energy_Quot__ChargedHad-500Jet100", "Cociente Energ#acute{i}a  ChargedHad / 500<ak5PFJet<600; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_600Jet700  = new TH1F("Jets_Energy_Quot__ChargedHad-600Jet100", "Cociente Energ#acute{i}a  ChargedHad / 600<ak5PFJet<700; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_700Jet800  = new TH1F("Jets_Energy_Quot__ChargedHad-700Jet100", "Cociente Energ#acute{i}a  ChargedHad / 700<ak5PFJet<800; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_800Jet900  = new TH1F("Jets_Energy_Quot__ChargedHad-800Jet100", "Cociente Energ#acute{i}a  ChargedHad / 800<ak5PFJet<900; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_900Jet1000 = new TH1F("Jets_Energy_Quot__ChargedHad-900Jet100", "Cociente Energ#acute{i}a  ChargedHad / 900<ak5PFJet<1000; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_1000Jet    = new TH1F("Jets_Energy_Quot__ChargedHad-1000Jet",   "Cociente Energ#acute{i}a  ChargedHad / 1000<ak5PFJet; Indice; Frecuencia", 120, 0, 1.2);

  // Distancia angular.
  TH1F *h_Jets__D__Jet_Jet      = new TH1F("Jets__D__Jet-Jet", "Distancia angular #sqrt{(#Delta#phi_{ij})^{2} + (#Delta#eta_{ij})^{2}} del ak5PFJet_{i} al ak5PFJet_{j}, por Evento; Valor; Frecuencia", 120, 0, 12);
  TH1F *h_Jets_pT04__D__Jet_Jet = new TH1F("Jets_pT>04__D__Jet-Jet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del ak5PFJet_{i} al ak5PFJet_{j}, por Evento; Valor; Frecuencia", 120, 0, 12);
  TH1F *h_Jets_pT08__D__Jet_Jet = new TH1F("Jets_pT>08__D__Jet-Jet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del ak5PFJet_{i} al ak5PFJet_{j}, por Evento; Valor; Frecuencia", 120, 0, 12);
  TH1F *h_Jets_pT16__D__Jet_Jet = new TH1F("Jets_pT>16__D__Jet-Jet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del ak5PFJet_{i} al ak5PFJet_{j}, por Evento; Valor; Frecuencia", 120, 0, 12);
  TH1F *h_Jets_pT32__D__Jet_Jet = new TH1F("Jets_pT>32__D__Jet-Jet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del ak5PFJet_{i} al ak5PFJet_{j}, por Evento; Valor; Frecuencia", 120, 0, 12);
  TH1F *h_Jets_pT64__D__Jet_Jet = new TH1F("Jets_pT>64__D__Jet-Jet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del ak5PFJet_{i} al ak5PFJet_{j}, por Evento; Valor; Frecuencia", 120, 0, 12);
  // TH1F *h__eta_D__jet_jet   = new TH1F("Jets_distancia_eta  jet jet", "Distancia angular #eta entre todos los jets de cada evento; Distancia angular; Frecuencia", 120, 0, 12);
  // TH1F *h__phi_D__jet_jet   = new TH1F("Jets_distancia_phi  jet jet", "Distancia angular #phi entre todos los jets de cada evento; Distancia angular; Frecuencia", 63, 0, 6.3);



    printf("\t\t %i) Histogramas creados. \n", nprint++);


  Float_t etaMax = 1.479;

  //###################################################################################################################################################################################
  // Hacemos un loop respecto a todo el conjunto de datos de interés.
  for (Int_t e=0; e<Eventos->GetEntries(); e++) {   // Int_t MultJet_04=0, MultJet_08=0, MultJet_16=0, MultJet_32=0, MultJet_64=0;

    // Eventos->GetEntry(e);
    // Jets->GetEntry(e);
    Jets_pt_  ->GetBranch()->GetEntry(e);
    Jets_eta_ ->GetBranch()->GetEntry(e);
    Jets_phi_ ->GetBranch()->GetEntry(e);
    // Jets_mPileupEnergy -> GetBranch()->GetEntry(e);
    Jets_mMuonEnergy         ->GetBranch()->GetEntry(e);  Jets_mMuonMultiplicity         ->GetBranch()->GetEntry(e);
    Jets_mPhotonEnergy       ->GetBranch()->GetEntry(e);  Jets_mPhotonMultiplicity       ->GetBranch()->GetEntry(e);
    Jets_mElectronEnergy     ->GetBranch()->GetEntry(e);  Jets_mElectronMultiplicity     ->GetBranch()->GetEntry(e);
    Jets_mNeutralHadronEnergy->GetBranch()->GetEntry(e);  Jets_mNeutralHadronMultiplicity->GetBranch()->GetEntry(e);
    Jets_mChargedHadronEnergy->GetBranch()->GetEntry(e);  Jets_mChargedHadronMultiplicity->GetBranch()->GetEntry(e);

    for (Int_t i=0; i<Jets_pt_->GetLen(); i++) {      // Float_t iJet_pT=Jets_pt_->GetValue(i), iJet_eta=Jets_eta_->GetValue(i), iJet_phi=Jets_phi_->GetValue(i);
      if ( fabs(iJet_eta) > etaMax ) continue;

      h_Jets_pt_ -> Fill(Jets_pt_->GetValue(i));
      h_Jets_eta_-> Fill(Jets_eta_->GetValue(i));

      // // Multiplicidad de Jets en cada Evento. Se tomo p_T como criterio de selección.
      // if (iJet_pT >  4.0)  ++MultJet_04;
      // if (iJet_pT >  8.0)  ++MultJet_08;
      // if (iJet_pT > 16.0)  ++MultJet_16;
      // if (iJet_pT > 32.0)  ++MultJet_32;
      // if (iJet_pT > 64.0)  ++MultJet_64;
      //
      // // Espectro de p_T. Tomando como criterio de seleccion la multiplicidad de Jets en cada Evento.
      // if (Jets_pt_->GetLen() <= 64)  h_Jets_Multiplicity64__pT -> Fill(iJet_pT);
      // if (Jets_pt_->GetLen() <= 32)  h_Jets_Multiplicity32__pT -> Fill(iJet_pT);
      // if (Jets_pt_->GetLen() <= 16)  h_Jets_Multiplicity16__pT -> Fill(iJet_pT);
      // if (Jets_pt_->GetLen() <= 8 )  h_Jets_Multiplicity08__pT -> Fill(iJet_pT);
      // if (Jets_pt_->GetLen() <= 4 )  h_Jets_Multiplicity04__pT -> Fill(iJet_pT);
      // if (Jets_pt_->GetLen() <= 2 )  h_Jets_Multiplicity02__pT -> Fill(iJet_pT);

      // for (Int_t j=i+1; j<Jets_pt_->GetLen(); j++) {      Float_t jJet_pT=Jets_pt_->GetValue(j), jJet_eta=Jets_eta_->GetValue(j), jJet_phi=Jets_phi_->GetValue(j);
      //   // h__eta_D__jet_jet -> Fill( fabs(iJet_eta - jJet_eta) );
      //   // h__phi_D__jet_jet -> Fill( fabs(iJet_phi - jJet_phi) );
      //   if ( fabs(iJet_phi-jJet_phi) <= PI ) {
      //     h_Jets__D__Jet_Jet    -> Fill( sqrt(pow(iJet_eta-jJet_eta, 2) +  pow(iJet_phi-jJet_phi, 2)) );
      //     if ( 4.0<iJet_pT &&  4.0<jJet_pT)  h_Jets_pT04__D__Jet_Jet -> Fill( sqrt(pow(iJet_eta-jJet_eta, 2) +  pow(iJet_phi-jJet_phi, 2)) );
      //     if ( 8.0<iJet_pT &&  8.0<jJet_pT)  h_Jets_pT08__D__Jet_Jet -> Fill( sqrt(pow(iJet_eta-jJet_eta, 2) +  pow(iJet_phi-jJet_phi, 2)) );
      //     if (16.0<iJet_pT && 16.0<jJet_pT)  h_Jets_pT16__D__Jet_Jet -> Fill( sqrt(pow(iJet_eta-jJet_eta, 2) +  pow(iJet_phi-jJet_phi, 2)) );
      //     if (32.0<iJet_pT && 32.0<jJet_pT)  h_Jets_pT32__D__Jet_Jet -> Fill( sqrt(pow(iJet_eta-jJet_eta, 2) +  pow(iJet_phi-jJet_phi, 2)) );
      //     if (64.0<iJet_pT && 64.0<jJet_pT)  h_Jets_pT64__D__Jet_Jet -> Fill( sqrt(pow(iJet_eta-jJet_eta, 2) +  pow(iJet_phi-jJet_phi, 2)) );
      //   } else if {  // Esto es debido a que ningún Jet puede estar a una distancia mayor a PI, de otro Jet.
      //     h_Jets__D__Jet_Jet    -> Fill( sqrt(pow(iJet_eta-jJet_eta, 2) +  pow(2*PI-fabs(iJet_phi-jJet_phi), 2)) );
      //     if ( 4.0<iJet_pT &&  4.0<jJet_pT)  h_Jets_pT04__D__Jet_Jet -> Fill( sqrt(pow(iJet_eta-jJet_eta, 2) +  pow(2*PI-fabs(iJet_phi-jJet_phi), 2)) );
      //     if ( 8.0<iJet_pT &&  8.0<jJet_pT)  h_Jets_pT08__D__Jet_Jet -> Fill( sqrt(pow(iJet_eta-jJet_eta, 2) +  pow(2*PI-fabs(iJet_phi-jJet_phi), 2)) );
      //     if (16.0<iJet_pT && 16.0<jJet_pT)  h_Jets_pT16__D__Jet_Jet -> Fill( sqrt(pow(iJet_eta-jJet_eta, 2) +  pow(2*PI-fabs(iJet_phi-jJet_phi), 2)) );
      //     if (32.0<iJet_pT && 32.0<jJet_pT)  h_Jets_pT32__D__Jet_Jet -> Fill( sqrt(pow(iJet_eta-jJet_eta, 2) +  pow(2*PI-fabs(iJet_phi-jJet_phi), 2)) );
      //     if (64.0<iJet_pT && 64.0<jJet_pT)  h_Jets_pT64__D__Jet_Jet -> Fill( sqrt(pow(iJet_eta-jJet_eta, 2) +  pow(2*PI-fabs(iJet_phi-jJet_phi), 2)) );
      //   }
      // }

      Float_t JetEnergy=Jets_mChargedHadronEnergy->GetValue(i)+Jets_mNeutralHadronEnergy->GetValue(i)+Jets_mElectronEnergy->GetValue(i)+Jets_mPhotonEnergy->GetValue(i)+Jets_mMuonEnergy->GetValue(i);

      h_JetEnergy -> Fill(JetEnergy);

      // Cociente de la energia de las partículas respecto a al E del Jet. Y Multiplicidad de las particulas en cada Jet.
      if (Jets_mMuonMultiplicity->GetValue(i) != 0) { h_MuonEnergy -> Fill(Jets_mMuonEnergy->GetValue(i));
        h_Jets__EnergyQuotient_Muon_Jet -> Fill(Jets_mMuonEnergy->GetValue(i)/JetEnergy);
        if          ( JetEnergy<100) {  h_Jets__EnergyQuot_Muon_Jet100    -> Fill(Jets_mMuonEnergy->GetValue(i)/JetEnergy)  }
        else if (100<=JetEnergy<200) {  h_Jets__EnergyQuot_Muon_100Jet200 -> Fill(Jets_mMuonEnergy->GetValue(i)/JetEnergy)  }
        else if (200<=JetEnergy<300) {  h_Jets__EnergyQuot_Muon_200Jet300 -> Fill(Jets_mMuonEnergy->GetValue(i)/JetEnergy)  }
        else if (300<=JetEnergy<400) {  h_Jets__EnergyQuot_Muon_300Jet400 -> Fill(Jets_mMuonEnergy->GetValue(i)/JetEnergy)  }
        else if (400<=JetEnergy<500) {  h_Jets__EnergyQuot_Muon_400Jet500 -> Fill(Jets_mMuonEnergy->GetValue(i)/JetEnergy)  }
        else if (500<=JetEnergy<600) {  h_Jets__EnergyQuot_Muon_500Jet600 -> Fill(Jets_mMuonEnergy->GetValue(i)/JetEnergy)  }
        else if (600<=JetEnergy<700) {  h_Jets__EnergyQuot_Muon_600Jet700 -> Fill(Jets_mMuonEnergy->GetValue(i)/JetEnergy)  }
        else if (700<=JetEnergy<800) {  h_Jets__EnergyQuot_Muon_700Jet800 -> Fill(Jets_mMuonEnergy->GetValue(i)/JetEnergy)  }
        else if (800<=JetEnergy<900) {  h_Jets__EnergyQuot_Muon_800Jet900 -> Fill(Jets_mMuonEnergy->GetValue(i)/JetEnergy)  }
        else if (900<=JetEnergy<1000){  h_Jets__EnergyQuot_Muon_900Jet1000-> Fill(Jets_mMuonEnergy->GetValue(i)/JetEnergy)  }
        else                         {  h_Jets__EnergyQuot_Muon_1000Jet   -> Fill(Jets_mMuonEnergy->GetValue(i)/JetEnergy)  }
      }
      if (Jets_mPhotonMultiplicity->GetValue(i) != 0) { h_PhotonEnergy -> Fill(Jets_mPhotonEnergy->GetValue(i));
        h_Jets__EnergyQuotient_Photon_Jet -> Fill(Jets_mPhotonEnergy->GetValue(i)/JetEnergy);
        if          ( JetEnergy<100) {  h_Jets__EnergyQuot_Photon_Jet100    -> Fill(Jets_mPhotonEnergy->GetValue(i)/JetEnergy)  }
        else if (100<=JetEnergy<200) {  h_Jets__EnergyQuot_Photon_100Jet200 -> Fill(Jets_mPhotonEnergy->GetValue(i)/JetEnergy)  }
        else if (200<=JetEnergy<300) {  h_Jets__EnergyQuot_Photon_200Jet300 -> Fill(Jets_mPhotonEnergy->GetValue(i)/JetEnergy)  }
        else if (300<=JetEnergy<400) {  h_Jets__EnergyQuot_Photon_300Jet400 -> Fill(Jets_mPhotonEnergy->GetValue(i)/JetEnergy)  }
        else if (400<=JetEnergy<500) {  h_Jets__EnergyQuot_Photon_400Jet500 -> Fill(Jets_mPhotonEnergy->GetValue(i)/JetEnergy)  }
        else if (500<=JetEnergy<600) {  h_Jets__EnergyQuot_Photon_500Jet600 -> Fill(Jets_mPhotonEnergy->GetValue(i)/JetEnergy)  }
        else if (600<=JetEnergy<700) {  h_Jets__EnergyQuot_Photon_600Jet700 -> Fill(Jets_mPhotonEnergy->GetValue(i)/JetEnergy)  }
        else if (700<=JetEnergy<800) {  h_Jets__EnergyQuot_Photon_700Jet800 -> Fill(Jets_mPhotonEnergy->GetValue(i)/JetEnergy)  }
        else if (800<=JetEnergy<900) {  h_Jets__EnergyQuot_Photon_800Jet900 -> Fill(Jets_mPhotonEnergy->GetValue(i)/JetEnergy)  }
        else if (900<=JetEnergy<1000){  h_Jets__EnergyQuot_Photon_900Jet1000-> Fill(Jets_mPhotonEnergy->GetValue(i)/JetEnergy)  }
        else                         {  h_Jets__EnergyQuot_Photon_1000Jet   -> Fill(Jets_mPhotonEnergy->GetValue(i)/JetEnergy)  }
      }
      if (Jets_mElectronMultiplicity->GetValue(i) != 0) { h_ElectronEnergy -> Fill(Jets_mElectronEnergy->GetValue(i));
        h_Jets__EnergyQuotient_Electron_Jet -> Fill(Jets_mElectronEnergy->GetValue(i)/JetEnergy);
        if          ( JetEnergy<100) {  h_Jets__EnergyQuot_Electron_Jet100    -> Fill(Jets_mElectronEnergy->GetValue(i)/JetEnergy)  }
        else if (100<=JetEnergy<200) {  h_Jets__EnergyQuot_Electron_100Jet200 -> Fill(Jets_mElectronEnergy->GetValue(i)/JetEnergy)  }
        else if (200<=JetEnergy<300) {  h_Jets__EnergyQuot_Electron_200Jet300 -> Fill(Jets_mElectronEnergy->GetValue(i)/JetEnergy)  }
        else if (300<=JetEnergy<400) {  h_Jets__EnergyQuot_Electron_300Jet400 -> Fill(Jets_mElectronEnergy->GetValue(i)/JetEnergy)  }
        else if (400<=JetEnergy<500) {  h_Jets__EnergyQuot_Electron_400Jet500 -> Fill(Jets_mElectronEnergy->GetValue(i)/JetEnergy)  }
        else if (500<=JetEnergy<600) {  h_Jets__EnergyQuot_Electron_500Jet600 -> Fill(Jets_mElectronEnergy->GetValue(i)/JetEnergy)  }
        else if (600<=JetEnergy<700) {  h_Jets__EnergyQuot_Electron_600Jet700 -> Fill(Jets_mElectronEnergy->GetValue(i)/JetEnergy)  }
        else if (700<=JetEnergy<800) {  h_Jets__EnergyQuot_Electron_700Jet800 -> Fill(Jets_mElectronEnergy->GetValue(i)/JetEnergy)  }
        else if (800<=JetEnergy<900) {  h_Jets__EnergyQuot_Electron_800Jet900 -> Fill(Jets_mElectronEnergy->GetValue(i)/JetEnergy)  }
        else if (900<=JetEnergy<1000){  h_Jets__EnergyQuot_Electron_900Jet1000-> Fill(Jets_mElectronEnergy->GetValue(i)/JetEnergy)  }
        else                         {  h_Jets__EnergyQuot_Electron_1000Jet   -> Fill(Jets_mElectronEnergy->GetValue(i)/JetEnergy)  }
      }
      if (Jets_mNeutralHadronMultiplicity->GetValue(i) != 0) { h_NeutralHadronEnergy -> Fill(Jets_mNeutralHadronEnergy->GetValue(i));
        h_Jets__EnergyQuotient_NeutralHad_Jet -> Fill(Jets_mNeutralHadronEnergy->GetValue(i)/JetEnergy);
        if          ( JetEnergy<100) {  h_Jets__EnergyQuot_NeutralHad_Jet100    -> Fill(Jets_mNeutralHadronEnergy->GetValue(i)/JetEnergy)  }
        else if (100<=JetEnergy<200) {  h_Jets__EnergyQuot_NeutralHad_100Jet200 -> Fill(Jets_mNeutralHadronEnergy->GetValue(i)/JetEnergy)  }
        else if (200<=JetEnergy<300) {  h_Jets__EnergyQuot_NeutralHad_200Jet300 -> Fill(Jets_mNeutralHadronEnergy->GetValue(i)/JetEnergy)  }
        else if (300<=JetEnergy<400) {  h_Jets__EnergyQuot_NeutralHad_300Jet400 -> Fill(Jets_mNeutralHadronEnergy->GetValue(i)/JetEnergy)  }
        else if (400<=JetEnergy<500) {  h_Jets__EnergyQuot_NeutralHad_400Jet500 -> Fill(Jets_mNeutralHadronEnergy->GetValue(i)/JetEnergy)  }
        else if (500<=JetEnergy<600) {  h_Jets__EnergyQuot_NeutralHad_500Jet600 -> Fill(Jets_mNeutralHadronEnergy->GetValue(i)/JetEnergy)  }
        else if (600<=JetEnergy<700) {  h_Jets__EnergyQuot_NeutralHad_600Jet700 -> Fill(Jets_mNeutralHadronEnergy->GetValue(i)/JetEnergy)  }
        else if (700<=JetEnergy<800) {  h_Jets__EnergyQuot_NeutralHad_700Jet800 -> Fill(Jets_mNeutralHadronEnergy->GetValue(i)/JetEnergy)  }
        else if (800<=JetEnergy<900) {  h_Jets__EnergyQuot_NeutralHad_800Jet900 -> Fill(Jets_mNeutralHadronEnergy->GetValue(i)/JetEnergy)  }
        else if (900<=JetEnergy<1000){  h_Jets__EnergyQuot_NeutralHad_900Jet1000-> Fill(Jets_mNeutralHadronEnergy->GetValue(i)/JetEnergy)  }
        else                         {  h_Jets__EnergyQuot_NeutralHad_1000Jet   -> Fill(Jets_mNeutralHadronEnergy->GetValue(i)/JetEnergy)  }
      }
      if (Jets_mChargedHadronMultiplicity->GetValue(i) != 0) { h_ChargedHadronEnergy -> Fill(Jets_mChargedHadronEnergy->GetValue(i));
        h_Jets__EnergyQuotient_ChargedHad_Jet -> Fill(Jets_mChargedHadronEnergy->GetValue(i)/JetEnergy);
        if          ( JetEnergy<100) {  h_Jets__EnergyQuot_ChargedHad_Jet100    -> Fill(Jets_mChargedHadronEnergy->GetValue(i)/JetEnergy)  }
        else if (100<=JetEnergy<200) {  h_Jets__EnergyQuot_ChargedHad_100Jet200 -> Fill(Jets_mChargedHadronEnergy->GetValue(i)/JetEnergy)  }
        else if (200<=JetEnergy<300) {  h_Jets__EnergyQuot_ChargedHad_200Jet300 -> Fill(Jets_mChargedHadronEnergy->GetValue(i)/JetEnergy)  }
        else if (300<=JetEnergy<400) {  h_Jets__EnergyQuot_ChargedHad_300Jet400 -> Fill(Jets_mChargedHadronEnergy->GetValue(i)/JetEnergy)  }
        else if (400<=JetEnergy<500) {  h_Jets__EnergyQuot_ChargedHad_400Jet500 -> Fill(Jets_mChargedHadronEnergy->GetValue(i)/JetEnergy)  }
        else if (500<=JetEnergy<600) {  h_Jets__EnergyQuot_ChargedHad_500Jet600 -> Fill(Jets_mChargedHadronEnergy->GetValue(i)/JetEnergy)  }
        else if (600<=JetEnergy<700) {  h_Jets__EnergyQuot_ChargedHad_600Jet700 -> Fill(Jets_mChargedHadronEnergy->GetValue(i)/JetEnergy)  }
        else if (700<=JetEnergy<800) {  h_Jets__EnergyQuot_ChargedHad_700Jet800 -> Fill(Jets_mChargedHadronEnergy->GetValue(i)/JetEnergy)  }
        else if (800<=JetEnergy<900) {  h_Jets__EnergyQuot_ChargedHad_800Jet900 -> Fill(Jets_mChargedHadronEnergy->GetValue(i)/JetEnergy)  }
        else if (900<=JetEnergy<1000){  h_Jets__EnergyQuot_ChargedHad_900Jet1000-> Fill(Jets_mChargedHadronEnergy->GetValue(i)/JetEnergy)  }
        else                         {  h_Jets__EnergyQuot_ChargedHad_1000Jet   -> Fill(Jets_mChargedHadronEnergy->GetValue(i)/JetEnergy)  }
      }
    } // for loop i


    // Multiplicidad de Jets en cada Evento. Se tomo p_T como criterio de selección.
    h_Jets__Multiplicity -> Fill(Jets_pt_->GetLen());
    // if (MultJet_04 > 0)  h_Jets_pT04__Multiplicity -> Fill(MultJet_04);  // Aqui llenamos los histogramas con la cantidad de jets,
    // if (MultJet_08 > 0)  h_Jets_pT08__Multiplicity -> Fill(MultJet_08);  // en cada evento, que cumple con tener p_T > x GeV.
    // if (MultJet_16 > 0)  h_Jets_pT16__Multiplicity -> Fill(MultJet_16);  // En otras palabras, estos son espectros de multiplicidad
    // if (MultJet_32 > 0)  h_Jets_pT32__Multiplicity -> Fill(MultJet_32);  // en funcion de distintos rangos de p_T.
    // if (MultJet_64 > 0)  h_Jets_pT64__Multiplicity -> Fill(MultJet_64);


      // printf("\t \t Dont worry. Evento %i hecho. =D \n\n", e);

  } // for loop e
  //###################################################################################################################################################################################


    printf("\t\t %i) Datos extraidos. \n", nprint++);


  // Guardamos nustros histogramas en el archivo root que nos interesa.
  h_Jets_pt_        -> Write();
  h_Jets_eta_       -> Write();
  h_JetEnergy       -> Write();
  h_MuonEnergy      -> Write();
  h_PhotonEnergy    -> Write();
  h_ElectronEnergy  -> Write();
  h_NeutralHadronEnergy-> Write();
  h_ChargedHadronEnergy-> Write();
  // Multiplicidades
  h_Jets__Multipicity-> Write();
  // h_Jets__MuonMultiplicity      -> Write();
  // h_Jets__PhotonMultiplicity    -> Write();
  // h_Jets__ElectronMultiplicity  -> Write();
  // h_Jets__NeuHad_Multiplicity   -> Write();
  // h_Jets__ChaHad_Multiplicity   -> Write();
  // h_Jets_pT04__Multiplicity -> Write();
  // h_Jets_pT08__Multiplicity -> Write();
  // h_Jets_pT16__Multiplicity -> Write();
  // h_Jets_pT32__Multiplicity -> Write();
  // h_Jets_pT64__Multiplicity -> Write();
  // // Momentos Transverso.
  // h_Jets_Multiplicity64__pT -> Write();
  // h_Jets_Multiplicity32__pT -> Write();
  // h_Jets_Multiplicity16__pT -> Write();
  // h_Jets_Multiplicity08__pT -> Write();
  // h_Jets_Multiplicity04__pT -> Write();
  // h_Jets_Multiplicity02__pT-> Write();
  // Cocientes
  h_Jets__EnergyQuotient_Muon_Jet   -> Write();
  h_Jets__EnergyQuot_Muon_Jet100    -> Write();
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
  h_Jets__EnergyQuot_Photon_Jet100    -> Write();
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
  h_Jets__EnergyQuot_Electron_Jet100    -> Write();
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
  h_Jets__EnergyQuot_NeutralHad_Jet100    -> Write();
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
  h_Jets__EnergyQuot_ChargedHad_Jet100    -> Write();
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
  // Distancias Angulares: eta, phi y total
  // h_Jets__D__Jet_Jet      -> Write();
  // h_Jets_pT04__D__Jet_Jet -> Write();
  // h_Jets_pT08__D__Jet_Jet -> Write();
  // h_Jets_pT16__D__Jet_Jet -> Write();
  // h_Jets_pT32__D__Jet_Jet -> Write();
  // h_Jets_pT64__D__Jet_Jet -> Write();


  // Cerramos y eliminamos los archivos abierto y creado.
  InputFile->Close();
  delete OutputFile;
  // new TBrowser();


    printf("\t\t %i) Análisis terminado. Fuck yeah!\n\n", nprint++);

}
