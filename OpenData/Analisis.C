void Analisis() {   Float_t PI=TMath::Pi(); Int_t nprint=1;

  //Abrimos los archivos que nos interesan y los árboles que queremos leer.
  TFile *InputFile = new TFile("/home/saksevul/CMS_1.3.0/CMS_Run2011A/BTag_20000/0001.root");
  TTree *Eventos = (TTree*)InputFile->Get("Events");
  // TBranch *Muons = Eventos->GetBranch("recoMuons_muons__RECO.obj");
  // TBranch *gsfElectrons = Eventos->GetBranch("recoGsfElectrons_gsfElectrons__RECO.obj");
  // TBranch *ak5PFJets = Eventos->GetBranch("recoPFJets_ak5PFJets__RECO.obj");

  //Crear el archivo de salida que queremos. Tiene que ir después del imputFile.
  TFile* OutputFile = new TFile("/home/saksevul/T/OpenData/BTag_20000/ak5PF-0001.root", "RECREATE");


    printf("\n\n JCA: ak5PF, InputFile: BTag_20000/0001.root. \n\n\n\t %i) Archivos abiertos. \n\n", nprint++);


  // Muones
  TLeaf *Muons_pt_ = Eventos->GetLeaf("recoMuons_muons__RECO.obj.pt_" );
  TLeaf *Muons_eta_= Eventos->GetLeaf("recoMuons_muons__RECO.obj.eta_");
  TLeaf *Muons_phi_= Eventos->GetLeaf("recoMuons_muons__RECO.obj.phi_");
  TLeaf *Muons_fX_ = Eventos->GetLeaf("recoMuons_muons__RECO.obj.vertex_.fCoordinates.fX");
  TLeaf *Muons_fY_ = Eventos->GetLeaf("recoMuons_muons__RECO.obj.vertex_.fCoordinates.fY");
  TLeaf *Muons_fZ_ = Eventos->GetLeaf("recoMuons_muons__RECO.obj.vertex_.fCoordinates.fZ");
  // Fotones
  TLeaf *Photons_pt_ = Eventos->GetLeaf("recoPhotons_photons__RECO.obj.pt_" );
  TLeaf *Photons_eta_= Eventos->GetLeaf("recoPhotons_photons__RECO.obj.eta_");
  TLeaf *Photons_phi_= Eventos->GetLeaf("recoPhotons_photons__RECO.obj.phi_");
  TLeaf *Photons_fX_ = Eventos->GetLeaf("recoPhotons_photons__RECO.obj.vertex_.fCoordinates.fX");
  TLeaf *Photons_fY_ = Eventos->GetLeaf("recoPhotons_photons__RECO.obj.vertex_.fCoordinates.fY");
  TLeaf *Photons_fZ_ = Eventos->GetLeaf("recoPhotons_photons__RECO.obj.vertex_.fCoordinates.fZ");
  // gsfElectrones
  TLeaf *gsfElectrons_pt_ = Eventos->GetLeaf("recoGsfElectrons_gsfElectrons__RECO.obj.pt_");
  TLeaf *gsfElectrons_eta_= Eventos->GetLeaf("recoGsfElectrons_gsfElectrons__RECO.obj.eta_");
  TLeaf *gsfElectrons_phi_= Eventos->GetLeaf("recoGsfElectrons_gsfElectrons__RECO.obj.phi_");
  TLeaf *gsfElectrons_fX_ = Eventos->GetLeaf("recoGsfElectrons_gsfElectrons__RECO.obj.vertex_.fCoordinates.fX");
  TLeaf *gsfElectrons_fY_ = Eventos->GetLeaf("recoGsfElectrons_gsfElectrons__RECO.obj.vertex_.fCoordinates.fY");
  TLeaf *gsfElectrons_fZ_ = Eventos->GetLeaf("recoGsfElectrons_gsfElectrons__RECO.obj.vertex_.fCoordinates.fZ");
  //ak5PFJets
  TLeaf *ak5PFJets_pt_                        = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.pt_");
  TLeaf *ak5PFJets_eta_                       = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.eta_");
  TLeaf *ak5PFJets_phi_                       = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.phi_");
  TLeaf *ak5PFJets_meta_jrea                  = Eventos->GetLeaf ("recoPFJets_ak5PFJets__RECO.obj.mJetArea");
  TLeaf *ak5PFJets_mPileupEnergy              = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.mPileupEnergy");
  TLeaf *ak5PFJets_mPassNumber                = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.mPassNumber");
  TLeaf *ak5PFJets_mChargedHadronEnergy       = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mChargedHadronEnergy");
  TLeaf *ak5PFJets_mNeutralHadronEnergy       = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mNeutralHadronEnergy");
  TLeaf *ak5PFJets_mElectronEnergy            = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mElectronEnergy");
  TLeaf *ak5PFJets_mPhotonEnergy              = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mPhotonEnergy");
  TLeaf *ak5PFJets_mMuonEnergy                = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mMuonEnergy");
  TLeaf *ak5PFJets_mHFHadronEnergy            = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mHFHadronEnergy");
  TLeaf *ak5PFJets_mHFEMEnergy                = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mHFEMEnergy");
  TLeaf *ak5PFJets_mChargedHadronMultiplicity = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mChargedHadronMultiplicity");
  TLeaf *ak5PFJets_mNeutralHadronMultiplicity = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mNeutralHadronMultiplicity");
  TLeaf *ak5PFJets_mPhotonMultiplicity        = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mPhotonMultiplicity");
  TLeaf *ak5PFJets_mElectronMultiplicity      = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mElectronMultiplicity");
  TLeaf *ak5PFJets_mMuonMultiplicity          = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mMuonMultiplicity");
  TLeaf *ak5PFJets_mHFHadronMultiplicity      = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mHFHadronMultiplicity");
  TLeaf *ak5PFJets_mHFEMMultiplicity          = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mHFEMMultiplicity");


    printf("\t %i) Ramas leidas. \n\n", nprint++);


  // Muons
  TH1F *h_Muons_pt_ = new TH1F("Muons_pt_",  "p_{T} de Muones contenidos en ak5PFJets; p_{T} [GeV]; Frecuencia",  1200, 0, 1200);
  TH1F *h_Muons_eta_= new TH1F("Muons_eta_", "recoMuones_muons__RECO.obj.eta_; #eta; Probabilidad", 59, -5.9, 5.9);
  TH1F *h_Muons_phi_= new TH1F("Muons_phi_", "recoMuones_muons__RECO.obj.phi_; #phi [Rad]; Probabilidad", 61, -3.1424, 3.1424);
  TH1D *h_Muons_fX_ = new TH1D("Muons_fX_", "Vertice en X de Muones contenidos en ak5PFJets; Distancia [cm]; Frecuencia", 241, -24.1, 24.1);
  TH1D *h_Muons_fY_ = new TH1D("Muons_fY_", "Vertice en Y de Muones contenidos en ak5PFJets; Distancia [cm]; Frecuencia", 241, -24.1, 24.1);
  TH1D *h_Muons_fZ_ = new TH1D("Muons_fZ_", "Vertice en Z de Muones contenidos en ak5PFJets; Distancia [cm]; Frecuencia", 1241, -124.1, 124.1);
  // gsfElectrons
  TH1F *h_gsfElectrons_pt_ = new TH1F("gsfElectrons_pt_",  "p_{T} de gsfElectrones contenidos en ak5PFJets; p_{T} [GeV]; Frecuencia",  1200, 0, 1200);
  TH1F *h_gsfElectrons_eta_= new TH1F("gsfElectrons_eta_", "recoGsfElectrons_gsfElectrons__RECO.obj.eta_; #eta; Probabilidad", 59, -5.9, 5.9);
  TH1F *h_gsfElectrons_phi_= new TH1F("gsfElectrons_phi_", "recoGsfElectrons_gsfElectrons__RECO.obj.phi_; #phi [Rad]; Probabilidad", 61, -3.1424, 3.1424);
  TH1D *h_gsfElectrons_fX_ = new TH1D("gsfElectrons_fX_", "Vertice en X de gsfElectrones contenidos en ak5PFJets; Distancia [cm]; Frecuencia", 241, -24.1, 24.1);
  TH1D *h_gsfElectrons_fY_ = new TH1D("gsfElectrons_fY_", "Vertice en Y de gsfElectrones contenidos en ak5PFJets; Distancia [cm]; Frecuencia", 241, -24.1, 24.1);
  TH1D *h_gsfElectrons_fZ_ = new TH1D("gsfElectrons_fZ_", "Vertice en Z de gsfElectrones contenidos en ak5PFJets; Distancia [cm]; Frecuencia", 241, -24.1, 24.1);
  // ak5PFJets
  TH1F *h_ak5PFJets_pt_                       = new TH1F("ak5PFJets_pt_",  "recoPFJets_PFJets__RECO.obj.pt_; p_{T} [GeV]; Probabilidad",  3200, 0, 3200);
  // TH1F *h_ak5PFJets_eta_                      = new TH1F("ak5PFJets_eta_", "recoPFJets_PFJets__RECO.obj.eta_; #eta; Probabilidad", 59, -5.9, 5.9);
  // TH1F *h_ak5PFJets_phi_                      = new TH1F("ak5PFJets_phi_", "recoPFJets_PFJets__RECO.obj.phi_; #phi [Rad]; Probabilidad", 61, -3.1416, 3.1416);
  // TH1F *h_ak5PFJets_meta_jrea                 = new TH1F("ak5PFJets_meta_jrea", "recoPFJets_PFJets__RECO.obj.mJetArea; meta_jrea; Probabilidad", 60, 0.0, 2.4);
  // TH1F *h_ak5PFJets_mPileupEnergy             = new TH1F("ak5PFJets_mPileupEnergy", "recoPFJets_PFJets__RECO.obj.mPileupEnergy; mPileupEnergy; Probabilidad", 49, -0.98, 0.98);
  // TH1I *h_ak5PFJets_mPassNumber               = new TH1I("ak5PFJets_mPassNumber", "recoPFJets_PFJets__RECO.obj.mPassNumber; mPassNumber; Probabilidad", 49, -0.98, 0.98);
  // TH1F *h_ak5PFJets_mChargedHadronEnergy      = new TH1F("ak5PFJets_mChargedHadronEnergy", "recoPFJets_PFJets__RECO.obj.m_specific.mChargedHadronEnergy; mChargedHadronEnergy; Probabilidad", 60, 0, 480);
  // TH1F *h_ak5PFJets_mNeutralHadronEnergy      = new TH1F("ak5PFJets_mNeutralHadronEnergy", "recoPFJets_PFJets__RECO.obj.m_specific.mNeutralHadronEnergy; mNeutralHadronEnergy; Probabilidad", 60, 0, 480);
  // TH1F *h_ak5PFJets_mPhotonEnergy             = new TH1F("ak5PFJets_mPhotonEnergy", "recoPFJets_PFJets__RECO.obj.m_specific.mPhotonEnergy; mPhotonEnergy; Probabilidad", 60, 0, 480);
  // TH1F *h_ak5PFJets_mElectronEnergy           = new TH1F("ak5PFJets_mElectronEnergy", "recoPFJets_PFJets__RECO.obj.m_specific.mElectronEnergy; mElectronEnergy; Probabilidad", 60, 0, 120);
  // TH1F *h_ak5PFJets_mMuonEnergy               = new TH1F("ak5PFJets_mMuonEnergy", "recoPFJets_PFJets__RECO.obj.m_specific.mMuonEnergy; mMuonEnergy; Probabilidad", 60, 0, 360);
  // TH1F *h_ak5PFJets_mHFHadronEnergy           = new TH1F("ak5PFJets_mHFHadronEnergy", "recoPFJets_PFJets__RECO.obj.m_specific.mHFHadronEnergy; mHFHadronEnergy; Probabilidad", 60, 0, 4800);
  // TH1F *h_ak5PFJets_mHFEMEnergy               = new TH1F("ak5PFJets_mHFEMEnergy", "recoPFJets_PFJets__RECO.obj.m_specific.mHFEMEnergy; mHFEMEnergy; Probabilidad", 60, 0, 1800);
  // TH1I *h_ak5PFJets_mChargedHadronMultiplicity= new TH1I("ak5PFJets_mChargedHadronMultiplicity", "recoPFJets_PFJets__RECO.obj.m_specific.mChargedHadronMultiplicity; mChargedHadronMultiplicity; Probabilidad", 60, 0, 60);
  // TH1I *h_ak5PFJets_mNeutralHadronMultiplicity= new TH1I("ak5PFJets_mNeutralHadronMultiplicity", "recoPFJets_PFJets__RECO.obj.m_specific.mNeutralHadronMultiplicity; mNeutralHadronMultiplicity; Probabilidad", 60, 0, 24);
  // TH1I *h_ak5PFJets_mPhotonMultiplicity       = new TH1I("ak5PFJets_mPhotonMultiplicity", "recoPFJets_PFJets__RECO.obj.m_specific.mPhotonMultiplicity; mPhotonMultiplicity; Probabilidad", 40, 0, 40);
  // TH1I *h_ak5PFJets_mElectronMultiplicity     = new TH1I("ak5PFJets_mElectronMultiplicity", "recoPFJets_PFJets__RECO.obj.m_specific.mElectronMultiplicity; mElectronMultiplicity; Probabilidad", 13, 0, 13);
  // TH1I *h_ak5PFJets_mMuonMultiplicity         = new TH1I("ak5PFJets_mMuonMultiplicity", "recoPFJets_PFJets__RECO.obj.m_specific.mMuonMultiplicity; mMuonMultiplicity; Probabilidad", 13, 0, 13);
  // TH1I *h_ak5PFJets_mHFHadronMultiplicity     = new TH1I("ak5PFJets_mHFHadronMultiplicity", "recoPFJets_PFJets__RECO.obj.m_specific.mHFHadronMultiplicity; mHFHadronMultiplicity; Probabilidad", 40, 0, 40);
  TH1I *h_ak5PFJets_mHFEMMultiplicity         = new TH1I("ak5PFJets_mHFEMMultiplicity", "recoPFJets_PFJets__RECO.obj.m_specific.mHFEMMultiplicity; mHFEMMultiplicity; Probabilidad", 40, 0, 40);
  // Multiplicidad.
  TH1F *h_Muons__Multiplicity         = new TH1F("Muones__Multiplicidad", "Multiplicidad, != 0, de Muones por Evento; Numero de muones; Frecuencia", 48, 0, 48);
  TH1F *h_Photons__Multiplicity       = new TH1F("Fotones__Multiplicidad", "Multiplicidad, != 0, de Fotones por Evento; Numero de fotones; Frecuencia", 24, 0, 24);
  TH1F *h_gsfElectrons__Multiplicity  = new TH1F("gsfElectrones__Multiplicidad", "Multiplicidad, != 0, de gsfElectrones por Evento; Numero de electrones; Frecuencia", 24, 0, 24);
  TH1F *h_ak5PFJets__MuonMultiplicity       = new TH1F("ak5PFJets__Multiplicidad_Muon!=0", "Multiplicidad, != 0, de Muones en cada ak5PFJet; Multiplicidad Muon; Probabilidad", 12, 0, 12);
  TH1F *h_ak5PFJets__PhotonMultiplicity     = new TH1F("ak5PFJets__Multiplicidad_Photon!=0", "Multiplicidad, != 0, de Fotones en cada ak5PFJet; Multiplicidad Foton; Probabilidad", 120, 0, 120);
  TH1F *h_ak5PFJets__ElectronMultiplicity   = new TH1F("ak5PFJets__Multiplicidad_Electron!=0", "Multiplicidad, != 0, de Electrones en cada ak5PFJet; Multiplicidad Electron; Probabilidad", 12, 0, 12);
  TH1I *h_ak5PFJets__Multiplicity_1Electron = new TH1I("ak5PFJets__Multiplicidad_1Electron", "Multipicidad de Jets con 1 Electron por Evento; Cantidad; Frecuencia", 41, -20.5, 20.5);
  TH1F *h_ak5PFJets__ChaHad_Multiplicity    = new TH1F("ak5PFJets__Multiplicidad_ChaHad", "Multiplicidad HadronCargado en cada ak5PFJet; Multiplicidad HadronCargado; Probabilidad", 100, 0, 100);
  TH1F *h_ak5PFJets__NeuHad_Multiplicity    = new TH1F("ak5PFJets__Multiplicidad_NeuHad", "Multiplicidad HadronNeutro en cada ak5PFJet; Multiplicidad HadronNeutral; Probabilidad", 100, 0, 100);
  TH1F *h_ak5PFJets__Multiplicity       = new TH1F("ak5PFJets__Multiplicidad", "Multiplicidad de ak5PFJets por Evento; Numero de Jets; Frecuencia", 120, 0, 120);
  TH1F *h_ak5PFJets_pT04__Multiplicity  = new TH1F("ak5PFJets_pT>04__Multiplicidad", "Multiplicidad de ak5PFJets, con p_{T} > 04 GeV, por Evento; Numero de Jets; Frecuencia", 120, 0, 120);
  TH1F *h_ak5PFJets_pT08__Multiplicity  = new TH1F("ak5PFJets_pT>08__Multiplicidad", "Multiplicidad de ak5PFJets, con p_{T} > 08 GeV, por Evento; Numero de Jets; Frecuencia", 120, 0, 120);
  TH1F *h_ak5PFJets_pT16__Multiplicity  = new TH1F("ak5PFJets_pT>16__Multiplicidad", "Multiplicidad de ak5PFJets, con p_{T} > 16 GeV, por Evento; Numero de Jets; Frecuencia", 120, 0, 120);
  TH1F *h_ak5PFJets_pT32__Multiplicity  = new TH1F("ak5PFJets_pT>32__Multiplicidad", "Multiplicidad de ak5PFJets, con p_{T} > 32 GeV, por Evento; Numero de Jets; Frecuencia", 120, 0, 120);
  TH1F *h_ak5PFJets_pT64__Multiplicity  = new TH1F("ak5PFJets_pT>64__Multiplicidad", "Multiplicidad de ak5PFJets, con p_{T} > 64 GeV, por Evento; Numero de Jets; Frecuencia", 120, 0, 120);
  // Espectro de p_T.
  TH1F *h_ak5PFJets_Multiplicity64__pT = new TH1F("ak5PFJets_Mult<=64__pT", "Distribucion de pT de ak5PFJets, con Multilicidad <= 64, por Evento; p_{T} [GeV]; Frecuencia", 800, 0, 3200);
  TH1F *h_ak5PFJets_Multiplicity32__pT = new TH1F("ak5PFJets_Mult<=32__pT", "Distribucion de pT de ak5PFJets, con Multilicidad <= 32, por Evento; p_{T} [GeV]; Frecuencia", 800, 0, 3200);
  TH1F *h_ak5PFJets_Multiplicity16__pT = new TH1F("ak5PFJets_Mult<=16__pT", "Distribucion de pT de ak5PFJets, con Multilicidad <= 16, por Evento; p_{T} [GeV]; Frecuencia", 800, 0, 3200);
  TH1F *h_ak5PFJets_Multiplicity08__pT = new TH1F("ak5PFJets_Mult<=08__pT", "Distribucion de pT de ak5PFJets, con Multilicidad <= 08, por Evento; p_{T} [GeV]; Frecuencia", 800, 0, 3200);
  TH1F *h_ak5PFJets_Multiplicity04__pT = new TH1F("ak5PFJets_Mult<=04__pT", "Distribucion de pT de ak5PFJets, con Multilicidad <= 04, por Evento; p_{T} [GeV]; Frecuencia", 800, 0, 3200);
  TH1F *h_ak5PFJets_Multiplicity02__pT = new TH1F("ak5PFJets_Mult<=02__pT", "Distribucion de pT de ak5PFJets, con Multilicidad <= 02, por Evento; p_{T} [GeV]; Frecuencia", 800, 0, 3200);
  // Cocientes.
  TH1F *h__pTQuotient_Muon_ak5PFJet         = new TH1F("Cociente_pT__Muon-ak5PFJet",  "Cociente p_{T}  Muon / ak5PFJet; Indice; Frecuencia", 100, 0, 2);
  TH1F *h__pTQuotient_1Muon_ak5PFJet        = new TH1F("Cociente_pT<100__1Muon-ak5PFJet",  "Cociente_{p_{T} < 100}  Muon_{MasEnergetico} / ak5PFJet; Indice; Frecuencia", 100, 0, 2);
  TH1F *h__pTQuot100__1Muon_ak5PFJet        = new TH1F("Cociente_pT>100__1Muon-ak5PFJet",  "Cociente_{p_{T} > 100}  Muon_{MasEnergetico} / ak5PFJet; Indice; Frecuencia", 100, 0, 2);
  TH1F *h__pTQuotient_gsfElectron_ak5PFJet  = new TH1F("Cociente_pT__gsfElectron-ak5PFJet",  "Cociente p_{T}  gsfElectron / ak5PFJet; Indice; Frecuencia", 100, 0, 2);
  TH1F *h__pTQuotient_1gsfElectron_ak5PFJet = new TH1F("Cociente_pT<100__1gsfElectron-ak5PFJet",  "Cociente_{p_{T} < 100}  gsfElectron_{MasEnergetico} / ak5PFJet; Indice; Frecuencia", 100, 0, 2);
  TH1F *h__pTQuot100__1gsfElectron_ak5PFJet = new TH1F("Cociente_pT>100__1gsfElectron-ak5PFJet",  "Cociente_{p_{T} > 100}  gsfElectron_{MasEnergetico} / ak5PFJet; Indice; Frecuencia", 100, 0, 2);

  TH1F *h_ak5PFJets__EnergyQuotient_ChaHad_Jet  = new TH1F("Cociente_ak5PFJets__Energia_ChaHad-p_T_Jet", "Cociente Energia_{ChaHad}/p_{TJet} para cada ak5PFJet; Energia_{ChaHad}/p_{Tak5PFJet}; Probabilidad", 100, 0, 10);
  TH1F *h_ak5PFJets__EnergyQuotient_NeuHad_Jet  = new TH1F("Cociente_ak5PFJets__Energia_NeuHad-p_T_Jet", "Cociente Energia_{NeuHad}/p_{TJet} para cada ak5PFJet; Energia_{NueHad}/p_{Tak5PFJet}; Probabilidad", 100, 0, 10);
  TH1F *h_ak5PFJets__EnergyQuotient_Electron_Jet= new TH1F("Cociente_ak5PFJets__Energia_Electron-p_T_Jet", "Cociente Energia_{Electron}/p_{TJet} para cada ak5PFJet; Energia_{Electron}/p_{Tak5PFJet}; Probabilidad", 100, 0, 10);
  TH1F *h_ak5PFJets__EnergyQuotient_Photon_Jet  = new TH1F("Cociente_ak5PFJets__Energia_Photon-p_T_Jet", "Cociente Energia_{Photon}/p_{TJet} para cada ak5PFJet; Energia_{Photon}/p_{Tak5PFJet}; Probabilidad", 100, 0, 10);
  TH1F *h_ak5PFJets__EnergyQuotient_Muon_Jet    = new TH1F("Cociente_ak5PFJets__Energia_Muon-p_T_Jet", "Cociente Energia_{Muon}/p_{TJet} para cada ak5PFJet; Energia_{Muon}/p_{Tak5PFJet}; Probabilidad", 100, 0, 10);
  // Distancia eta.
  TH1F *h__eta_D__Muon_ak5PFJet        = new TH1F("D_eta__Muon-ak5PFJet", "Diferencia |#eta_{Muon} - #eta_{ak5PFJet}|; Distancia angular; Frecuencia", 120, 0, 1.2);
  TH1F *h__eta_D__Photon_ak5PFJet      = new TH1F("D_eta__Foton-ak5PFJet", "Diferencia |#eta_{Foton} - #eta_{ak5PFJet}|; Distancia angular; Frecuencia", 120, 0, 1.2);
  TH1F *h__eta_D__gsfElectron_ak5PFJet = new TH1F("D_eta__gsfElectron-ak5PFJet", "Diferencia |#eta_{gsfElectron} - #eta_{ak5PFJet}|; Distancia angular; Frecuencia", 120, 0, 1.2);
  // Distancia phi.
  TH1F *h__phi_D__Muon_ak5PFJet        = new TH1F("D_phi__Muon-ak5PFJet", "Diferencia |#phi_{Muon} - #phi_{ak5PFJet}|; Distancia angular; Frecuencia", 120, 0, 1.2);
  TH1F *h__phi_D__Photon_ak5PFJet      = new TH1F("D_phi__Foton-ak5PFJet", "Diferencia |#phi_{Foton} - #phi_{ak5PFJet}|; Distancia angular; Frecuencia", 120, 0, 1.2);
  TH1F *h__phi_D__gsfElectron_ak5PFJet = new TH1F("D_phi__gsfElectron-ak5PFJet", "Diferencia |#phi_{gsfElectron} - #phi_{ak5PFJet}|; Distancia angular; Frecuencia", 120, 0, 1.2);
  // Distancia angular.
  TH1F *h__D__Muon_ak5PFJet        = new TH1F("D__Muon-ak5PFJet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del Muon al ak5PFJet; Valor; Frecuencia", 120, 0, 1.2);
  TH1F *h__D__Photon_ak5PFJet      = new TH1F("D__Foton-ak5PFJet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del Foton al ak5PFJet; Valor; Frecuencia", 120, 0, 1.2);
  TH1F *h__D__gsfElectron_ak5PFJet = new TH1F("D__gsfElectron-ak5PFJet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del gsfElectron al ak5PFJet; Valor; Frecuencia", 480, 0, 1.2);
  TH1F *h_ak5PFJets__D__Jet_Jet      = new TH1F("ak5PFJets__D__Jet-Jet", "Distancia angular #sqrt{(#Delta#phi_{ij})^{2} + (#Delta#eta_{ij})^{2}} del ak5PFJet_{i} al ak5PFJet_{j}, por Evento; Valor; Frecuencia", 120, 0, 12);
  TH1F *h_ak5PFJets_pT04__D__Jet_Jet = new TH1F("ak5PFJets_pT>04__D__Jet-Jet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del ak5PFJet_{i} al ak5PFJet_{j}, por Evento; Valor; Frecuencia", 120, 0, 12);
  TH1F *h_ak5PFJets_pT08__D__Jet_Jet = new TH1F("ak5PFJets_pT>08__D__Jet-Jet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del ak5PFJet_{i} al ak5PFJet_{j}, por Evento; Valor; Frecuencia", 120, 0, 12);
  TH1F *h_ak5PFJets_pT16__D__Jet_Jet = new TH1F("ak5PFJets_pT>16__D__Jet-Jet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del ak5PFJet_{i} al ak5PFJet_{j}, por Evento; Valor; Frecuencia", 120, 0, 12);
  TH1F *h_ak5PFJets_pT32__D__Jet_Jet = new TH1F("ak5PFJets_pT>32__D__Jet-Jet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del ak5PFJet_{i} al ak5PFJet_{j}, por Evento; Valor; Frecuencia", 120, 0, 12);
  TH1F *h_ak5PFJets_pT64__D__Jet_Jet = new TH1F("ak5PFJets_pT>64__D__Jet-Jet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del ak5PFJet_{i} al ak5PFJet_{j}, por Evento; Valor; Frecuencia", 120, 0, 12);
  // TH1F *h__eta_D__jet_jet   = new TH1F("ak5PFJets_distancia_eta  jet jet", "Distancia angular #eta entre todos los jets de cada evento; Distancia angular; Frecuencia", 120, 0, 12);
  // TH1F *h__phi_D__jet_jet   = new TH1F("ak5PFJets_distancia_phi  jet jet", "Distancia angular #phi entre todos los jets de cada evento; Distancia angular; Frecuencia", 63, 0, 6.3);


    printf("\t %i) Histogramas creados. \n\n", nprint++);


  //---------------------------------------------------------------------------------------------------------------
  for (Int_t e=0; e<Eventos->GetEntries(); e++) {  //Creamos unos histogramas para conocer la distribución de los vértices.
    gsfElectrons_fX_ ->GetBranch()->GetEntry(e);  Muons_fX_ ->GetBranch()->GetEntry(e);
    gsfElectrons_fY_ ->GetBranch()->GetEntry(e);  Muons_fY_ ->GetBranch()->GetEntry(e);
    gsfElectrons_fZ_ ->GetBranch()->GetEntry(e);  Muons_fZ_ ->GetBranch()->GetEntry(e);
    for (Int_t i=0; i<gsfElectrons_fX_->GetLen(); i++) {
      h_gsfElectrons_fX_ -> Fill(gsfElectrons_fX_->GetValue(i));  h_Muons_fX_ -> Fill(Muons_fX_->GetValue(i));
      h_gsfElectrons_fY_ -> Fill(gsfElectrons_fY_->GetValue(i));  h_Muons_fY_ -> Fill(Muons_fY_->GetValue(i));
      h_gsfElectrons_fZ_ -> Fill(gsfElectrons_fZ_->GetValue(i));  h_Muons_fZ_ -> Fill(Muons_fZ_->GetValue(i));
  } }

  TF1 *gauss = new TF1("gauss", "gaus");
  h_gsfElectrons_fX_->Fit("gauss", "CNQ");  Float_t x_electron=gauss->GetParameter(1), sx_electron=0.5 /*gauss->GetParameter(2)*/;  h_gsfElectrons_fX_->Reset("ICESM");
  h_gsfElectrons_fY_->Fit("gauss", "CNQ");  Float_t y_electron=gauss->GetParameter(1), sy_electron=0.5 /*gauss->GetParameter(2)*/;  h_gsfElectrons_fY_->Reset("ICESM");
  h_gsfElectrons_fZ_->Fit("gauss", "CNQ");  Float_t z_electron=gauss->GetParameter(1), sz_electron=0.5 /*gauss->GetParameter(2)*/;  h_gsfElectrons_fZ_->Reset("ICESM");
  h_Muons_fX_->Fit("gauss", "CNQ");  Float_t x_muon=gauss->GetParameter(1), sx_muon=0.5 /*gauss->GetParameter(2)*/;  h_Muons_fX_->Reset("ICESM");
  h_Muons_fY_->Fit("gauss", "CNQ");  Float_t y_muon=gauss->GetParameter(1), sy_muon=0.5 /*gauss->GetParameter(2)*/;  h_Muons_fY_->Reset("ICESM");
  h_Muons_fZ_->Fit("gauss", "CNQ");  Float_t z_muon=gauss->GetParameter(1), sz_muon=0.5 /*gauss->GetParameter(2)*/;  h_Muons_fZ_->Reset("ICESM");

  //---------------------------------------------------------------------------------------------------------------
  // Hacemos un loop respecto a todo el conjunto de datos de interés.
  for (Int_t e=0; e<Eventos->GetEntries(); e++) {   Int_t MultJet_04=0, MultJet_08=0, MultJet_16=0, MultJet_32=0, MultJet_64=0;

    // Eventos->GetEntry(e);
    // Muons->GetEntry(e);
    // gsfElectrons->GetEntry(e);
    // ak5PFJets->GetEntry(e);
    Muons_pt_ ->GetBranch()->GetEntry(e);  Photons_pt_ ->GetBranch()->GetEntry(e);  gsfElectrons_pt_ ->GetBranch()->GetEntry(e);  ak5PFJets_pt_  ->GetBranch()->GetEntry(e);
    Muons_eta_->GetBranch()->GetEntry(e);  Photons_eta_->GetBranch()->GetEntry(e);  gsfElectrons_eta_->GetBranch()->GetEntry(e);  ak5PFJets_eta_ ->GetBranch()->GetEntry(e);
    Muons_phi_->GetBranch()->GetEntry(e);  Photons_phi_->GetBranch()->GetEntry(e);  gsfElectrons_phi_->GetBranch()->GetEntry(e);  ak5PFJets_phi_ ->GetBranch()->GetEntry(e);
    Muons_fX_ ->GetBranch()->GetEntry(e);  Photons_fX_ ->GetBranch()->GetEntry(e);  gsfElectrons_fX_ ->GetBranch()->GetEntry(e);
    Muons_fY_ ->GetBranch()->GetEntry(e);  Photons_fY_ ->GetBranch()->GetEntry(e);  gsfElectrons_fY_ ->GetBranch()->GetEntry(e);
    Muons_fZ_ ->GetBranch()->GetEntry(e);  Photons_fZ_ ->GetBranch()->GetEntry(e);  gsfElectrons_fZ_ ->GetBranch()->GetEntry(e);
    ak5PFJets_mChargedHadronEnergy->GetBranch()->GetEntry(e);  ak5PFJets_mChargedHadronMultiplicity->GetBranch()->GetEntry(e);
    ak5PFJets_mNeutralHadronEnergy->GetBranch()->GetEntry(e);  ak5PFJets_mNeutralHadronMultiplicity->GetBranch()->GetEntry(e);
    ak5PFJets_mElectronEnergy     ->GetBranch()->GetEntry(e);  ak5PFJets_mElectronMultiplicity     ->GetBranch()->GetEntry(e);
    ak5PFJets_mPhotonEnergy       ->GetBranch()->GetEntry(e);  ak5PFJets_mPhotonMultiplicity       ->GetBranch()->GetEntry(e);
    ak5PFJets_mMuonEnergy         ->GetBranch()->GetEntry(e);  ak5PFJets_mMuonMultiplicity         ->GetBranch()->GetEntry(e);

    for (Int_t i=0; i<ak5PFJets_pt_->GetLen(); i++) {      Float_t iPF_pT=ak5PFJets_pt_->GetValue(i), iPF_eta=ak5PFJets_eta_->GetValue(i), iPF_phi=ak5PFJets_phi_->GetValue(i);
      // Multiplicidad de ak5PFJets en cada Evento. Se tomo p_T como criterio de selección.
      if (iPF_pT >  4.0)  ++MultJet_04;
      if (iPF_pT >  8.0)  ++MultJet_08;
      if (iPF_pT > 16.0)  ++MultJet_16;
      if (iPF_pT > 32.0)  ++MultJet_32;
      if (iPF_pT > 64.0)  ++MultJet_64;

      // Espectro de p_T. Tomando como criterio de seleccion la multiplicidad de ak5PFJets en cada Evento.
      h_ak5PFJets_pt_ -> Fill(iPF_pT);
      if (ak5PFJets_pt_->GetLen() <= 64)  h_ak5PFJets_Multiplicity64__pT -> Fill(iPF_pT);
      if (ak5PFJets_pt_->GetLen() <= 32)  h_ak5PFJets_Multiplicity32__pT -> Fill(iPF_pT);
      if (ak5PFJets_pt_->GetLen() <= 16)  h_ak5PFJets_Multiplicity16__pT -> Fill(iPF_pT);
      if (ak5PFJets_pt_->GetLen() <= 8 )  h_ak5PFJets_Multiplicity08__pT -> Fill(iPF_pT);
      if (ak5PFJets_pt_->GetLen() <= 4 )  h_ak5PFJets_Multiplicity04__pT -> Fill(iPF_pT);
      if (ak5PFJets_pt_->GetLen() <= 2 )  h_ak5PFJets_Multiplicity02__pT -> Fill(iPF_pT);

      // for (Int_t j=i+1; j<ak5PFJets_pt_->GetLen(); j++) {      Float_t jPF_pT=ak5PFJets_pt_->GetValue(j), jPF_eta=ak5PFJets_eta_->GetValue(j), jPF_phi=ak5PFJets_phi_->GetValue(j);
      //   // h__eta_D__jet_jet -> Fill( fabs(iPF_eta - jPF_eta) );
      //   // h__phi_D__jet_jet -> Fill( fabs(iPF_phi - jPF_phi) );
      //   if ( fabs(iPF_phi-jPF_phi) <= PI ) {
      //     h_ak5PFJets__D__Jet_Jet    -> Fill( sqrt(pow(iPF_eta-jPF_eta, 2) +  pow(iPF_phi-jPF_phi, 2)) );
      //     if ( 4.0<iPF_pT &&  4.0<jPF_pT)  h_ak5PFJets_pT04__D__Jet_Jet -> Fill( sqrt(pow(iPF_eta-jPF_eta, 2) +  pow(iPF_phi-jPF_phi, 2)) );
      //     if ( 8.0<iPF_pT &&  8.0<jPF_pT)  h_ak5PFJets_pT08__D__Jet_Jet -> Fill( sqrt(pow(iPF_eta-jPF_eta, 2) +  pow(iPF_phi-jPF_phi, 2)) );
      //     if (16.0<iPF_pT && 16.0<jPF_pT)  h_ak5PFJets_pT16__D__Jet_Jet -> Fill( sqrt(pow(iPF_eta-jPF_eta, 2) +  pow(iPF_phi-jPF_phi, 2)) );
      //     if (32.0<iPF_pT && 32.0<jPF_pT)  h_ak5PFJets_pT32__D__Jet_Jet -> Fill( sqrt(pow(iPF_eta-jPF_eta, 2) +  pow(iPF_phi-jPF_phi, 2)) );
      //     if (64.0<iPF_pT && 64.0<jPF_pT)  h_ak5PFJets_pT64__D__Jet_Jet -> Fill( sqrt(pow(iPF_eta-jPF_eta, 2) +  pow(iPF_phi-jPF_phi, 2)) );
      //   } else if {  // Esto es debido a que ningún Jet puede estar a una distancia mayor a PI, de otro Jet.
      //     h_ak5PFJets__D__Jet_Jet    -> Fill( sqrt(pow(iPF_eta-jPF_eta, 2) +  pow(2*PI-fabs(iPF_phi-jPF_phi), 2)) );
      //     if ( 4.0<iPF_pT &&  4.0<jPF_pT)  h_ak5PFJets_pT04__D__Jet_Jet -> Fill( sqrt(pow(iPF_eta-jPF_eta, 2) +  pow(2*PI-fabs(iPF_phi-jPF_phi), 2)) );
      //     if ( 8.0<iPF_pT &&  8.0<jPF_pT)  h_ak5PFJets_pT08__D__Jet_Jet -> Fill( sqrt(pow(iPF_eta-jPF_eta, 2) +  pow(2*PI-fabs(iPF_phi-jPF_phi), 2)) );
      //     if (16.0<iPF_pT && 16.0<jPF_pT)  h_ak5PFJets_pT16__D__Jet_Jet -> Fill( sqrt(pow(iPF_eta-jPF_eta, 2) +  pow(2*PI-fabs(iPF_phi-jPF_phi), 2)) );
      //     if (32.0<iPF_pT && 32.0<jPF_pT)  h_ak5PFJets_pT32__D__Jet_Jet -> Fill( sqrt(pow(iPF_eta-jPF_eta, 2) +  pow(2*PI-fabs(iPF_phi-jPF_phi), 2)) );
      //     if (64.0<iPF_pT && 64.0<jPF_pT)  h_ak5PFJets_pT64__D__Jet_Jet -> Fill( sqrt(pow(iPF_eta-jPF_eta, 2) +  pow(2*PI-fabs(iPF_phi-jPF_phi), 2)) );
      //   }
      // }

      // Cociente de la energía de las partículas respecto al p_T del Jet. Y Multiplicidad de las particulas en cada Jet.
      if (ak5PFJets_mChargedHadronMultiplicity->GetValue(i) != 0) {
        h_ak5PFJets__EnergyQuotient_ChaHad_Jet -> Fill(ak5PFJets_mChargedHadronEnergy->GetValue(i)/iPF_pT);
        h_ak5PFJets__ChaHad_Multiplicity -> Fill(ak5PFJets_mChargedHadronMultiplicity->GetValue(i));      }
      if (ak5PFJets_mNeutralHadronMultiplicity->GetValue(i) != 0) {
        h_ak5PFJets__EnergyQuotient_NeuHad_Jet -> Fill(ak5PFJets_mNeutralHadronEnergy->GetValue(i)/iPF_pT);
        h_ak5PFJets__NeuHad_Multiplicity -> Fill(ak5PFJets_mNeutralHadronMultiplicity->GetValue(i));      }
      if (ak5PFJets_mElectronMultiplicity->GetValue(i) != 0) {
        h_ak5PFJets__EnergyQuotient_Electron_Jet -> Fill(ak5PFJets_mElectronEnergy->GetValue(i)/iPF_pT);
        h_ak5PFJets__ElectronMultiplicity -> Fill(ak5PFJets_mElectronMultiplicity->GetValue(i));      }
      if (ak5PFJets_mPhotonMultiplicity->GetValue(i) != 0) {
        h_ak5PFJets__EnergyQuotient_Photon_Jet -> Fill(ak5PFJets_mPhotonEnergy->GetValue(i)/iPF_pT);
        h_ak5PFJets__PhotonMultiplicity -> Fill(ak5PFJets_mPhotonMultiplicity->GetValue(i));      }
      if (ak5PFJets_mMuonMultiplicity->GetValue(i) != 0) {
        h_ak5PFJets__EnergyQuotient_Muon_Jet -> Fill(ak5PFJets_mMuonEnergy->GetValue(i)/iPF_pT);
        h_ak5PFJets__MuonMultiplicity -> Fill(ak5PFJets_mMuonMultiplicity->GetValue(i));    }

      // Muones
      if (ak5PFJets_mMuonMultiplicity->GetValue(i) > 0) {   Int_t Index[100]; Float_t D[100]; Bool_t Flag=false; Float_t pT=0.0; // Defino valores de referencia. Estos cambiarán más adelante.
        for (Int_t j=0; j<Muons_pt_->GetLen(); j++) {                                                             // Busco el electón que esté mas cerca, angularmente, del jet.
          if ( fabs(Muons_phi_->GetValue(j)-iPF_phi) <= PI ) {
            D[j] = sqrt(pow(Muons_eta_->GetValue(j)-iPF_eta,2)+pow(Muons_phi_->GetValue(j)-iPF_phi,2));
          } else { D[j] = sqrt(pow(Muons_eta_->GetValue(j)-iPF_eta,2)+pow(2*PI-fabs(Muons_phi_->GetValue(j)-iPF_phi),2));  }
        }
        TMath::Sort(Muons_pt_->GetLen(), D, Index, false);                                                        // TMath::Sort devuelve el ordenamiento a partir de ìndices, no de valores.
        for (Int_t j=0; j<ak5PFJets_mMuonMultiplicity->GetValue(i); j++) {
          if ( pow(Muons_fX_->GetValue(Index[j])-x_muon,2) + pow(Muons_fY_->GetValue(Index[j])-y_muon,2) + pow(Muons_fZ_->GetValue(Index[j])-z_muon,2) <= 0.25 ) {
            h_Muons_pt_ -> Fill(Muons_pt_->GetValue(Index[j]));
            h_Muons_fX_ -> Fill(Muons_fX_->GetValue(Index[j]));
            h_Muons_fY_ -> Fill(Muons_fY_->GetValue(Index[j]));
            h_Muons_fZ_ -> Fill(Muons_fZ_->GetValue(Index[j]));
            h__pTQuotient_Muon_ak5PFJet  -> Fill(Muons_pt_->GetValue(Index[j])/iPF_pT);
            h__eta_D__Muon_ak5PFJet -> Fill(fabs(Muons_eta_->GetValue(Index[j]) - ak5PFJets_eta_->GetValue(i)));  // Distancia en el ángulo ETA entre el Jet y su Muón.
            h__phi_D__Muon_ak5PFJet -> Fill(fabs(Muons_phi_->GetValue(Index[j]) - ak5PFJets_phi_->GetValue(i)));  // Distancia en el ángulo PHI entre el Jet y su Muón.
            h__D__Muon_ak5PFJet -> Fill(D[Index[j]]);                                                             // Distancia angular total entre el Jet y su Muón.
            if (Muons_pt_->GetValue(Index[j]) > pT) { Flag=true; pT=Muons_pt_->GetValue(Index[j]); }
            // printf(" Entrada : %i, Indice: %i, Distancia Angular: %f.\n", j, Index[j], D[Index[j]]);
          }
        } // printf("\n");
        if ( iPF_pT <= 100 ) {  if (Flag == true) h__pTQuotient_1Muon_ak5PFJet -> Fill(pT/iPF_pT);  }              // Cociente_pT respecto al Muón más energético.
        else {  if (Flag == true) h__pTQuot100__1Muon_ak5PFJet -> Fill(pT/iPF_pT);  }
      } // if loop

      // Electrones.
      if (ak5PFJets_mElectronMultiplicity->GetValue(i) > 0) {   Int_t Index[100]; Float_t D[100]; Bool_t Flag=false; Float_t pT=0.0;
        for (Int_t j=0; j<gsfElectrons_pt_->GetLen(); j++) {
          if ( fabs(gsfElectrons_phi_->GetValue(j)-iPF_phi) <= PI ) {
            D[j] = sqrt(pow(gsfElectrons_eta_->GetValue(j)-iPF_eta,2)+pow(gsfElectrons_phi_->GetValue(j)-iPF_phi,2));
          } else { D[j] = sqrt(pow(gsfElectrons_eta_->GetValue(j)-iPF_eta,2)+pow(2*PI-fabs(gsfElectrons_phi_->GetValue(j)-iPF_phi),2));  }
        }
        TMath::Sort(gsfElectrons_pt_->GetLen(), D, Index, false);
        for (Int_t j=0; j<ak5PFJets_mElectronMultiplicity->GetValue(i); j++) {
          if ( pow(gsfElectrons_fX_->GetValue(Index[j])-x_electron,2) + pow(gsfElectrons_fY_->GetValue(Index[j])-y_electron,2) + pow(gsfElectrons_fZ_->GetValue(Index[j])-z_electron,2) <= 0.25 ) {
            h_gsfElectrons_pt_ -> Fill(gsfElectrons_pt_->GetValue(Index[j]));
            h_gsfElectrons_fX_ -> Fill(gsfElectrons_fX_->GetValue(Index[j]));
            h_gsfElectrons_fY_ -> Fill(gsfElectrons_fY_->GetValue(Index[j]));
            h_gsfElectrons_fZ_ -> Fill(gsfElectrons_fZ_->GetValue(Index[j]));
            h__pTQuotient_gsfElectron_ak5PFJet -> Fill(gsfElectrons_pt_->GetValue(Index[j])/iPF_pT);
            h__eta_D__gsfElectron_ak5PFJet -> Fill(fabs(gsfElectrons_eta_->GetValue(Index[j]) - ak5PFJets_eta_->GetValue(i)));
            h__phi_D__gsfElectron_ak5PFJet -> Fill(fabs(gsfElectrons_phi_->GetValue(Index[j]) - ak5PFJets_phi_->GetValue(i)));
            h__D__gsfElectron_ak5PFJet -> Fill(D[Index[j]]);
            if (gsfElectrons_pt_->GetValue(Index[j]) > pT) { Flag=true; pT=gsfElectrons_pt_->GetValue(Index[j]); }
          }
        }
        if ( iPF_pT <= 100 ) {  if (Flag == true) h__pTQuotient_1gsfElectron_ak5PFJet -> Fill(pT/iPF_pT); }
        else {  if (Flag == true) h__pTQuot100__1gsfElectron_ak5PFJet -> Fill(pT/iPF_pT); }
      }
    } // for loop i


    // Multiplicidad de ak5PFJets en cada Evento. Se tomo p_T como criterio de selección.
    h_ak5PFJets__Multiplicity -> Fill(ak5PFJets_pt_->GetLen());
    if (MultJet_04 > 0)  h_ak5PFJets_pT04__Multiplicity -> Fill(MultJet_04);  // Aqui llenamos los histogramas con la cantidad de jets,
    if (MultJet_08 > 0)  h_ak5PFJets_pT08__Multiplicity -> Fill(MultJet_08);  // en cada evento, que cumple con tener p_T > x GeV.
    if (MultJet_16 > 0)  h_ak5PFJets_pT16__Multiplicity -> Fill(MultJet_16);  // En otras palabras, estos son espectros de multiplicidad
    if (MultJet_32 > 0)  h_ak5PFJets_pT32__Multiplicity -> Fill(MultJet_32);  // en funcion de distintos rangos de p_T.
    if (MultJet_64 > 0)  h_ak5PFJets_pT64__Multiplicity -> Fill(MultJet_64);

    // Multiplicidad, != 0, de los Electrones, Fotones y Muones reconstruidos en cada Evento.
    if (gsfElectrons_pt_->GetLen() != 0) h_gsfElectrons__Multiplicity -> Fill(gsfElectrons_pt_->GetLen());
    if (Photons_pt_->GetLen() != 0)      h_Photons__Multiplicity      -> Fill(Photons_pt_->GetLen());
    if (Muons_pt_->GetLen() != 0)        h_Muons__Multiplicity        -> Fill(Muons_pt_->GetLen());


      // printf("\t \t Dont worry. Evento %i hecho. =D \n\n", e);

  } // for loop e
  //---------------------------------------------------------------------------------------------------------------


    printf("\t %i) Datos extraidos. \n\n", nprint++);


  // Guardamos nustros histogramas en el archivo root que nos interesa.
  // Muons
  h_Muons_pt_ -> Write();
  // h_Muons_eta_-> Write();
  // h_Muons_phi_-> Write();
  h_Muons_fX_ -> Write();
  h_Muons_fY_ -> Write();
  h_Muons_fZ_ -> Write();
  // gsfElectrons
  h_gsfElectrons_pt_ -> Write();
  // h_gsfElectrons_eta_-> Write();
  // h_gsfElectrons_phi_-> Write();
  h_gsfElectrons_fX_ -> Write();
  h_gsfElectrons_fY_ -> Write();
  h_gsfElectrons_fZ_ -> Write();
  // ak5PFJets
  h_ak5PFJets_pt_                       -> Write();
  // h_ak5PFJets_eta_                      -> Write();
  // h_ak5PFJets_phi_                      -> Write();
  // h_ak5PFJets_meta_jrea                 -> Write();
  // h_ak5PFJets_mPileupEnergy             -> Write();
  // h_ak5PFJets_mPassNumber               -> Write();
  // h_ak5PFJets_mChargedHadronEnergy      -> Write();
  // h_ak5PFJets_mNeutralHadronEnergy      -> Write();
  // h_ak5PFJets_mPhotonEnergy             -> Write();
  // h_ak5PFJets_mElectronEnergy           -> Write();
  // h_ak5PFJets_mMuonEnergy               -> Write();
  // h_ak5PFJets_mHFHadronEnergy           -> Write();
  // h_ak5PFJets_mHFEMEnergy               -> Write();
  // h_ak5PFJets_mChargedHadronMultiplicity-> Write();
  // h_ak5PFJets_mNeutralHadronMultiplicity-> Write();
  // h_ak5PFJets_mPhotonMultiplicity       -> Write();
  // h_ak5PFJets_mElectronMultiplicity     -> Write();
  // h_ak5PFJets_mMuonMultiplicity         -> Write();
  // h_ak5PFJets_mHFHadronMultiplicity     -> Write();
  // h_ak5PFJets_mHFEMMultiplicity         -> Write();
  // Multiplicidades
  h_Muons__Multiplicity       -> Write();
  h_Photons__Multiplicity     -> Write();
  h_gsfElectrons__Multiplicity-> Write();
  h_ak5PFJets__MuonMultiplicity      -> Write();
  h_ak5PFJets__PhotonMultiplicity    -> Write();
  h_ak5PFJets__ElectronMultiplicity  -> Write();
  h_ak5PFJets__Multiplicity_1Electron-> Write();
  h_ak5PFJets__ChaHad_Multiplicity   -> Write();
  h_ak5PFJets__NeuHad_Multiplicity   -> Write();
  h_ak5PFJets__Multiplicity      -> Write();
  h_ak5PFJets_pT04__Multiplicity -> Write();
  h_ak5PFJets_pT08__Multiplicity -> Write();
  h_ak5PFJets_pT16__Multiplicity -> Write();
  h_ak5PFJets_pT32__Multiplicity -> Write();
  h_ak5PFJets_pT64__Multiplicity -> Write();
  // Momentos Transverso.
  h_ak5PFJets_Multiplicity64__pT -> Write();
  h_ak5PFJets_Multiplicity32__pT -> Write();
  h_ak5PFJets_Multiplicity16__pT -> Write();
  h_ak5PFJets_Multiplicity08__pT -> Write();
  h_ak5PFJets_Multiplicity04__pT -> Write();
  h_ak5PFJets_Multiplicity02__pT-> Write();
  // Cocientes
  h__pTQuotient_Muon_ak5PFJet        -> Write();
  h__pTQuotient_1Muon_ak5PFJet       -> Write();
  h__pTQuot100__1Muon_ak5PFJet       -> Write();
  h__pTQuotient_gsfElectron_ak5PFJet -> Write();
  h__pTQuotient_1gsfElectron_ak5PFJet-> Write();
  h__pTQuot100__1gsfElectron_ak5PFJet-> Write();
  h_ak5PFJets__EnergyQuotient_ChaHad_Jet  -> Write();
  h_ak5PFJets__EnergyQuotient_NeuHad_Jet  -> Write();
  h_ak5PFJets__EnergyQuotient_Electron_Jet-> Write();
  h_ak5PFJets__EnergyQuotient_Photon_Jet  -> Write();
  h_ak5PFJets__EnergyQuotient_Muon_Jet    -> Write();
  // Distancias Angulares: eta, phi y total
  h__eta_D__Muon_ak5PFJet       -> Write();
  // h__eta_D__Photon_ak5PFJet     -> Write();
  h__eta_D__gsfElectron_ak5PFJet-> Write();
  h__phi_D__Muon_ak5PFJet       -> Write();
  // h__phi_D__Photon_ak5PFJet     -> Write();
  h__phi_D__gsfElectron_ak5PFJet-> Write();
  h__D__Muon_ak5PFJet       -> Write();
  // h__D__Photon_ak5PFJet     -> Write();
  h__D__gsfElectron_ak5PFJet-> Write();
  h_ak5PFJets__D__Jet_Jet      -> Write();
  // h_ak5PFJets_pT04__D__Jet_Jet -> Write();
  // h_ak5PFJets_pT08__D__Jet_Jet -> Write();
  // h_ak5PFJets_pT16__D__Jet_Jet -> Write();
  // h_ak5PFJets_pT32__D__Jet_Jet -> Write();
  // h_ak5PFJets_pT64__D__Jet_Jet -> Write();


  // Cerramos y eliminamos los archivos abierto y creado.
  InputFile->Close();
  delete OutputFile;
  // new TBrowser();


    printf("\t %i) Análisis terminado, Son of a bitch!\n\n", nprint++);

}
