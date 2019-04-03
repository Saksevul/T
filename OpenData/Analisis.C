void Analisis() {   Float_t PI=TMath::Pi(); Int_t nprint=1, evento=0;

  //Abrimos los archivos que nos interesan y los árboles que queremos leer.
  TFile* InputFile = new TFile("/home/saksevul/CMS_1.3.0/CMS_Run2011A/Jet_AOD_12Oct2013-v1_20000/0001.root", "READ");
  TTreeReader reader("Events", InputFile);

  //Crear el archivo de salida que queremos. Tiene que ir después del imputFile.
  TFile* OutputFile = new TFile("/home/saksevul/T/OpenData/Jet_20000/.ak5PF-0001.root", "RECREATE");


  printf("\n\n InputFile: Jet_20000/0001.root, JCA: ak5PF. \n\n\n\t %i) Archivos abiertos. \n\n", nprint++);


  // Electrones
	TTreeReaderArray<Bool_t> gsfElectrons_present ( reader, "recoGsfElectrons_gsfElectrons__RECO.present" );
	TTreeReaderArray<Int_t>  gsfElectrons_qx3_ ( reader, "recoGsfElectrons_gsfElectrons__RECO.obj.qx3_" );
	TTreeReaderArray<Float_t>gsfElectrons_pt_  ( reader, "recoGsfElectrons_gsfElectrons__RECO.obj.pt_" );
	TTreeReaderArray<Float_t>gsfElectrons_eta_ ( reader, "recoGsfElectrons_gsfElectrons__RECO.obj.eta_" );
	TTreeReaderArray<Float_t>gsfElectrons_phi_ ( reader, "recoGsfElectrons_gsfElectrons__RECO.obj.phi_" );
	TTreeReaderArray<Float_t>gsfElectrons_mass_( reader, "recoGsfElectrons_gsfElectrons__RECO.obj.mass_" );
  TTreeReaderArray<Double32_t> gsfElectrons_fX_( reader, "recoGsfElectrons_gsfElectrons__RECO.obj.vertex_.fCoordinates.fX" );
  // Muones
  TTreeReaderArray<Bool_t> muons_present ( reader, "recoMuons_muons__RECO.present" );
  TTreeReaderArray<Int_t>  muons_qx3_ ( reader, "recoMuons_muons__RECO.obj.qx3_" );
  TTreeReaderArray<Float_t>muons_pt_  ( reader, "recoMuons_muons__RECO.obj.pt_" );
  TTreeReaderArray<Float_t>muons_eta_ ( reader, "recoMuons_muons__RECO.obj.eta_" );
  TTreeReaderArray<Float_t>muons_phi_ ( reader, "recoMuons_muons__RECO.obj.phi_" );
  TTreeReaderArray<Float_t>muons_mass_( reader, "recoMuons_muons__RECO.obj.mass_" );
  // Fotones
  TTreeReaderArray<Bool_t> photons_present ( reader, "recoPhotons_photons__RECO.present" );
  TTreeReaderArray<Int_t>  photons_qx3_ ( reader, "recoPhotons_photons__RECO.obj.qx3_" );
  TTreeReaderArray<Float_t>photons_pt_  ( reader, "recoPhotons_photons__RECO.obj.pt_" );
  TTreeReaderArray<Float_t>photons_eta_ ( reader, "recoPhotons_photons__RECO.obj.eta_" );
  TTreeReaderArray<Float_t>photons_phi_ ( reader, "recoPhotons_photons__RECO.obj.phi_" );
  TTreeReaderArray<Float_t>photons_mass_( reader, "recoPhotons_photons__RECO.obj.mass_" );
  // PF Jets
  TTreeReaderArray<Bool_t> ak5PFJets_present ( reader, "recoPFJets_ak5PFJets__RECO.present" );
  TTreeReaderArray<Int_t>  ak5PFJets_qx3_         ( reader, "recoPFJets_ak5PFJets__RECO.obj.qx3_" );
  TTreeReaderArray<Float_t>ak5PFJets_pt_          ( reader, "recoPFJets_ak5PFJets__RECO.obj.pt_" );
  TTreeReaderArray<Float_t>ak5PFJets_eta_         ( reader, "recoPFJets_ak5PFJets__RECO.obj.eta_" );
  TTreeReaderArray<Float_t>ak5PFJets_phi_         ( reader, "recoPFJets_ak5PFJets__RECO.obj.phi_" );
  TTreeReaderArray<Float_t>ak5PFJets_mass_        ( reader, "recoPFJets_ak5PFJets__RECO.obj.mass_" );
  TTreeReaderArray<Int_t>  ak5PFJets_pdgId_       ( reader, "recoPFJets_ak5PFJets__RECO.obj.pdgId_" );
  TTreeReaderArray<Int_t>  ak5PFJets_status_      ( reader, "recoPFJets_ak5PFJets__RECO.obj.status_" );
  // TTreeReaderArray<Float_t>ak5PFJets_dau          ( reader, "recoPFJets_ak5PFJets__RECO.obj.dau" ); // vector<edm::Ptr<reco::Candidate> > dau[recoPFJets_ak5PFJets__RECO.obj_]
  TTreeReaderArray<Float_t>ak5PFJets_meta_jrea     ( reader, "recoPFJets_ak5PFJets__RECO.obj.mJetArea" );
  TTreeReaderArray<Float_t>ak5PFJets_mPileupEnergy( reader, "recoPFJets_ak5PFJets__RECO.obj.mPileupEnergy" );
  TTreeReaderArray<Int_t>  ak5PFJets_mPassNumber  ( reader, "recoPFJets_ak5PFJets__RECO.obj.mPassNumber" );
  TTreeReaderArray<Float_t>ak5PFJets_mChargedHadronEnergy      ( reader, "recoPFJets_ak5PFJets__RECO.obj.m_specific.mChargedHadronEnergy" );
  TTreeReaderArray<Float_t>ak5PFJets_mNeutralHadronEnergy      ( reader, "recoPFJets_ak5PFJets__RECO.obj.m_specific.mNeutralHadronEnergy" );
  TTreeReaderArray<Float_t>ak5PFJets_mElectronEnergy           ( reader, "recoPFJets_ak5PFJets__RECO.obj.m_specific.mElectronEnergy" );
  TTreeReaderArray<Float_t>ak5PFJets_mPhotonEnergy             ( reader, "recoPFJets_ak5PFJets__RECO.obj.m_specific.mPhotonEnergy" );
  TTreeReaderArray<Float_t>ak5PFJets_mMuonEnergy               ( reader, "recoPFJets_ak5PFJets__RECO.obj.m_specific.mMuonEnergy" );
  TTreeReaderArray<Float_t>ak5PFJets_mHFHadronEnergy           ( reader, "recoPFJets_ak5PFJets__RECO.obj.m_specific.mHFHadronEnergy" );
  TTreeReaderArray<Float_t>ak5PFJets_mHFEMEnergy               ( reader, "recoPFJets_ak5PFJets__RECO.obj.m_specific.mHFEMEnergy" );
  TTreeReaderArray<Int_t>  ak5PFJets_mChargedHadronMultiplicity( reader, "recoPFJets_ak5PFJets__RECO.obj.m_specific.mChargedHadronMultiplicity" );
  TTreeReaderArray<Int_t>  ak5PFJets_mNeutralHadronMultiplicity( reader, "recoPFJets_ak5PFJets__RECO.obj.m_specific.mNeutralHadronMultiplicity" );
  TTreeReaderArray<Int_t>  ak5PFJets_mPhotonMultiplicity       ( reader, "recoPFJets_ak5PFJets__RECO.obj.m_specific.mPhotonMultiplicity" );
  TTreeReaderArray<Int_t>  ak5PFJets_mElectronMultiplicity     ( reader, "recoPFJets_ak5PFJets__RECO.obj.m_specific.mElectronMultiplicity" );
  TTreeReaderArray<Int_t>  ak5PFJets_mMuonMultiplicity         ( reader, "recoPFJets_ak5PFJets__RECO.obj.m_specific.mMuonMultiplicity" );
  TTreeReaderArray<Int_t>  ak5PFJets_mHFHadronMultiplicity     ( reader, "recoPFJets_ak5PFJets__RECO.obj.m_specific.mHFHadronMultiplicity" );
  TTreeReaderArray<Int_t>  ak5PFJets_mHFEMMultiplicity         ( reader, "recoPFJets_ak5PFJets__RECO.obj.m_specific.mHFEMMultiplicity" );
  // TTreeReaderArray<Int_t>  ak5PFJets_size                      ( reader, "recoPFJets_ak5PFJets__RECO.@obj.size()" );
  // Error in <TTreeReaderArrayBase::GetBranchAndLeaf()>: The tree does not have a branch called recoPFJets_ak5PFJets__RECO.@obj.size(). You could check with TTree::Print() for available branches.


  printf("\t %i) Ramas leidas. \n\n", nprint++);


  //Creamos histogramas para leer los parámetros que nos interesan.

  // gsfElectrons
  TH1I *h_gsfElectrons_present = new TH1I("gsfElectrons_present", "recoGsfElectrons_gsfElectrons__RECO.present; Present; Probabilidad", 19, -9.5, 9.5);
  TH1I *h_gsfElectrons_qx3_  = new TH1I("gsfElectrons_qx3_", "recoGsfElectrons_gsfElectrons__RECO.obj.qx3_; qx3; Probabilidad", 59, -59, 59);
  TH1F *h_gsfElectrons_pt_   = new TH1F("gsfElectrons_pt_",  "recoGsfElectrons_gsfElectrons__RECO.obj.pt_; p_{T} [GeV]; Probabilidad",  60, -4, 476);
  TH1F *h_gsfElectrons_eta_  = new TH1F("gsfElectrons_eta_", "recoGsfElectrons_gsfElectrons__RECO.obj.eta_; #eta; Probabilidad", 59, -5.9, 5.9);
  TH1F *h_gsfElectrons_phi_  = new TH1F("gsfElectrons_phi_", "recoGsfElectrons_gsfElectrons__RECO.obj.phi_; #phi [Rad]; Probabilidad", 61, -3.1424, 3.1424);
  TH1F *h_gsfElectrons_mass_ = new TH1F("gsfElectrons_mass_","recoGsfElectrons_gsfElectrons__RECO.obj.mass_; Masa [GeV]; Probabilidad",60, 0, 60);

  // ak5PFJets
  TH1I *h_ak5PFJets_present = new TH1I("ak5PFJets_present", "recoPFJets_PFJets__RECO.present; Present; Probabilidad", 19, -9.5, 9.5);
  TH1I *h_ak5PFJets_qx3_         = new TH1I("ak5PFJets_qx3_", "recoPFJets_PFJets__RECO.obj.qx3_; qx3; Probabilidad", 59, -59, 59);
  TH1F *h_ak5PFJets_pt_          = new TH1F("ak5PFJets_pt_",  "recoPFJets_PFJets__RECO.obj.pt_; p_{T} [GeV]; Probabilidad",  3200, 0, 3200);
  TH1F *h_ak5PFJets_eta_         = new TH1F("ak5PFJets_eta_", "recoPFJets_PFJets__RECO.obj.eta_; #eta; Probabilidad", 59, -5.9, 5.9);
  TH1F *h_ak5PFJets_phi_         = new TH1F("ak5PFJets_phi_", "recoPFJets_PFJets__RECO.obj.phi_; #phi [Rad]; Probabilidad", 61, -3.1416, 3.1416);
  TH1F *h_ak5PFJets_mass_        = new TH1F("ak5PFJets_mass_","recoPFJets_PFJets__RECO.obj.mass_; Masa [GeV]; Probabilidad",60, 0, 60);
  TH1I *h_ak5PFJets_pdgId_       = new TH1I("ak5PFJets_pdgId_", "recoPFJets_PFJets__RECO.obj.pdgId_; pdgId; Probabilidad", 31, -1.505, 1.505);
  TH1I *h_ak5PFJets_status_      = new TH1I("ak5PFJets_status_", "recoPFJets_PFJets__RECO.obj.status_; status; Probabilidad", 31, -1.505, 1.505);
  TH1F *h_ak5PFJets_meta_jrea    = new TH1F("ak5PFJets_meta_jrea", "recoPFJets_PFJets__RECO.obj.mJetArea; meta_jrea; Probabilidad", 60, 0.0, 2.4);
  TH1F *h_ak5PFJets_mPileupEnergy= new TH1F("ak5PFJets_mPileupEnergy", "recoPFJets_PFJets__RECO.obj.mPileupEnergy; mPileupEnergy; Probabilidad", 49, -0.98, 0.98);
  TH1I *h_ak5PFJets_mPassNumber  = new TH1I("ak5PFJets_mPassNumber", "recoPFJets_PFJets__RECO.obj.mPassNumber; mPassNumber; Probabilidad", 49, -0.98, 0.98);
  TH1F *h_ak5PFJets_mChargedHadronEnergy      = new TH1F("ak5PFJets_mChargedHadronEnergy", "recoPFJets_PFJets__RECO.obj.m_specific.mChargedHadronEnergy; mChargedHadronEnergy; Probabilidad", 60, 0, 480);
  TH1F *h_ak5PFJets_mNeutralHadronEnergy      = new TH1F("ak5PFJets_mNeutralHadronEnergy", "recoPFJets_PFJets__RECO.obj.m_specific.mNeutralHadronEnergy; mNeutralHadronEnergy; Probabilidad", 60, 0, 480);
  TH1F *h_ak5PFJets_mPhotonEnergy             = new TH1F("ak5PFJets_mPhotonEnergy", "recoPFJets_PFJets__RECO.obj.m_specific.mPhotonEnergy; mPhotonEnergy; Probabilidad", 60, 0, 480);
  TH1F *h_ak5PFJets_mElectronEnergy           = new TH1F("ak5PFJets_mElectronEnergy", "recoPFJets_PFJets__RECO.obj.m_specific.mElectronEnergy; mElectronEnergy; Probabilidad", 60, 0, 120);
  TH1F *h_ak5PFJets_mMuonEnergy               = new TH1F("ak5PFJets_mMuonEnergy", "recoPFJets_PFJets__RECO.obj.m_specific.mMuonEnergy; mMuonEnergy; Probabilidad", 60, 0, 360);
  TH1F *h_ak5PFJets_mHFHadronEnergy           = new TH1F("ak5PFJets_mHFHadronEnergy", "recoPFJets_PFJets__RECO.obj.m_specific.mHFHadronEnergy; mHFHadronEnergy; Probabilidad", 60, 0, 4800);
  TH1F *h_ak5PFJets_mHFEMEnergy               = new TH1F("ak5PFJets_mHFEMEnergy", "recoPFJets_PFJets__RECO.obj.m_specific.mHFEMEnergy; mHFEMEnergy; Probabilidad", 60, 0, 1800);
  TH1I *h_ak5PFJets_mChargedHadronMultiplicity= new TH1I("ak5PFJets_mChargedHadronMultiplicity", "recoPFJets_PFJets__RECO.obj.m_specific.mChargedHadronMultiplicity; mChargedHadronMultiplicity; Probabilidad", 60, 0, 60);
  TH1I *h_ak5PFJets_mNeutralHadronMultiplicity= new TH1I("ak5PFJets_mNeutralHadronMultiplicity", "recoPFJets_PFJets__RECO.obj.m_specific.mNeutralHadronMultiplicity; mNeutralHadronMultiplicity; Probabilidad", 60, 0, 24);
  TH1I *h_ak5PFJets_mPhotonMultiplicity       = new TH1I("ak5PFJets_mPhotonMultiplicity", "recoPFJets_PFJets__RECO.obj.m_specific.mPhotonMultiplicity; mPhotonMultiplicity; Probabilidad", 40, 0, 40);
  TH1I *h_ak5PFJets_mElectronMultiplicity     = new TH1I("ak5PFJets_mElectronMultiplicity", "recoPFJets_PFJets__RECO.obj.m_specific.mElectronMultiplicity; mElectronMultiplicity; Probabilidad", 13, 0, 13);
  TH1I *h_ak5PFJets_mMuonMultiplicity         = new TH1I("ak5PFJets_mMuonMultiplicity", "recoPFJets_PFJets__RECO.obj.m_specific.mMuonMultiplicity; mMuonMultiplicity; Probabilidad", 13, 0, 13);
  TH1I *h_ak5PFJets_mHFHadronMultiplicity     = new TH1I("ak5PFJets_mHFHadronMultiplicity", "recoPFJets_PFJets__RECO.obj.m_specific.mHFHadronMultiplicity; mHFHadronMultiplicity; Probabilidad", 40, 0, 40);
  TH1I *h_ak5PFJets_mHFEMMultiplicity         = new TH1I("ak5PFJets_mHFEMMultiplicity", "recoPFJets_PFJets__RECO.obj.m_specific.mHFEMMultiplicity; mHFEMMultiplicity; Probabilidad", 40, 0, 40);

  // Multiplicidad de ak5PFJets en cada Evento. Se tomo p_T como criterio de selección.
  TH1F *h_ak5PFJets__Multiplicity       = new TH1F("ak5PFJets__Multiplicidad", "Multiplicidad de ak5PFJets por Evento; Numero de Jets; Ocurrencia", 120, 0, 120);
  TH1F *h_ak5PFJets_pT04__Multiplicity  = new TH1F("ak5PFJets_pT>04  Multiplicidad", "Multiplicidad de ak5PFJets, con p_{T} > 04 GeV, por Evento; Numero de Jets; Ocurrencia", 120, 0, 120);
  TH1F *h_ak5PFJets_pT08__Multiplicity  = new TH1F("ak5PFJets_pT>08  Multiplicidad", "Multiplicidad de ak5PFJets, con p_{T} > 08 GeV, por Evento; Numero de Jets; Ocurrencia", 120, 0, 120);
  TH1F *h_ak5PFJets_pT16__Multiplicity  = new TH1F("ak5PFJets_pT>16  Multiplicidad", "Multiplicidad de ak5PFJets, con p_{T} > 16 GeV, por Evento; Numero de Jets; Ocurrencia", 120, 0, 120);
  TH1F *h_ak5PFJets_pT32__Multiplicity  = new TH1F("ak5PFJets_pT>32  Multiplicidad", "Multiplicidad de ak5PFJets, con p_{T} > 32 GeV, por Evento; Numero de Jets; Ocurrencia", 120, 0, 120);
  TH1F *h_ak5PFJets_pT64__Multiplicity  = new TH1F("ak5PFJets_pT>64  Multiplicidad", "Multiplicidad de ak5PFJets, con p_{T} > 64 GeV, por Evento; Numero de Jets; Ocurrencia", 120, 0, 120);
  // Espectro de p_T. Tomando como criterio de seleccion la multiplicidad de Jets en cada Evento.
  TH1F *h_ak5PFJets_Multiplicity64__pT = new TH1F("ak5PFJets_Mult<=64  pT", "Distribucion de pT de ak5PFJets, con Multilicidad <= 64, por Evento; p_{T} [GeV]; Ocurrencia", 800, 0, 3200);
  TH1F *h_ak5PFJets_Multiplicity32__pT = new TH1F("ak5PFJets_Mult<=32  pT", "Distribucion de pT de ak5PFJets, con Multilicidad <= 32, por Evento; p_{T} [GeV]; Ocurrencia", 800, 0, 3200);
  TH1F *h_ak5PFJets_Multiplicity16__pT = new TH1F("ak5PFJets_Mult<=16  pT", "Distribucion de pT de ak5PFJets, con Multilicidad <= 16, por Evento; p_{T} [GeV]; Ocurrencia", 800, 0, 3200);
  TH1F *h_ak5PFJets_Multiplicity08__pT = new TH1F("ak5PFJets_Mult<=08  pT", "Distribucion de pT de ak5PFJets, con Multilicidad <= 08, por Evento; p_{T} [GeV]; Ocurrencia", 800, 0, 3200);
  TH1F *h_ak5PFJets_Multiplicity04__pT = new TH1F("ak5PFJets_Mult<=04  pT", "Distribucion de pT de ak5PFJets, con Multilicidad <= 04, por Evento; p_{T} [GeV]; Ocurrencia", 800, 0, 3200);
  TH1F *h_ak5PFJets_Multiplicity02__pT = new TH1F("ak5PFJets_Mult<=02  pT", "Distribucion de pT de ak5PFJets, con Multilicidad <= 02, por Evento; p_{T} [GeV]; Ocurrencia", 800, 0, 3200);
  // Distancia angular entre Jets.
  TH1F *h_ak5PFJets__D_Jet_Jet      = new TH1F("ak5PFJets__DistanciaAngular_Jet_Jet", "Distancia angular #sqrt{(#Delta#phi_{ij})^{2} + (#Delta#eta_{ij})^{2}} del ak5PFJet_{i} al ak5PFJet_{j}, por Evento; Valor; Ocurrencia", 120, 0, 12);
  TH1F *h_ak5PFJets_pT04__D_Jet_Jet = new TH1F("ak5PFJets_pT>04  D Jet Jet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del ak5PFJet_{i} al ak5PFJet_{j}, por Evento; Valor; Ocurrencia", 120, 0, 12);
  TH1F *h_ak5PFJets_pT08__D_Jet_Jet = new TH1F("ak5PFJets_pT>08  D Jet Jet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del ak5PFJet_{i} al ak5PFJet_{j}, por Evento; Valor; Ocurrencia", 120, 0, 12);
  TH1F *h_ak5PFJets_pT16__D_Jet_Jet = new TH1F("ak5PFJets_pT>16  D Jet Jet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del ak5PFJet_{i} al ak5PFJet_{j}, por Evento; Valor; Ocurrencia", 120, 0, 12);
  TH1F *h_ak5PFJets_pT32__D_Jet_Jet = new TH1F("ak5PFJets_pT>32  D Jet Jet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del ak5PFJet_{i} al ak5PFJet_{j}, por Evento; Valor; Ocurrencia", 120, 0, 12);
  TH1F *h_ak5PFJets_pT64__D_Jet_Jet = new TH1F("ak5PFJets_pT>64  D Jet Jet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del ak5PFJet_{i} al ak5PFJet_{j}, por Evento; Valor; Ocurrencia", 120, 0, 12);
  // TH1F *h__etaDistance__jet_jet   = new TH1F("ak5PFJets_distancia_eta  jet jet", "Distancia angular #eta entre todos los jets de cada evento; Distancia angular; Ocurrencia", 120, 0, 12);
  // TH1F *h__phiDistance__jet_jet   = new TH1F("ak5PFJets_distancia_phi  jet jet", "Distancia angular #phi entre todos los jets de cada evento; Distancia angular; Ocurrencia", 63, 0, 6.3);
  // Cociente de la energía de las partículas respecto al p_T del Jet.
  TH1F *h_ak5PFJets__EnergyQuotient_ChaHad_Jet  = new TH1F("ak5PFJets  Energia_ChaHad / p_T_Jet", "Cociente Energia_{ChaHad}/p_{TJet} para cada ak5PFJet; Energia_{ChaHad}/p_{Tak5PFJet}; Probabilidad", 100, 0, 100);
  TH1F *h_ak5PFJets__EnergyQuotient_NeuHad_Jet  = new TH1F("ak5PFJets  Energia_NeuHad / p_T_Jet", "Cociente Energia_{NeuHad}/p_{TJet} para cada ak5PFJet; Energia_{NueHad}/p_{Tak5PFJet}; Probabilidad", 100, 0, 100);
  TH1F *h_ak5PFJets__EnergyQuotient_Electron_Jet= new TH1F("ak5PFJets  Energia_Electron / p_T_Jet", "Cociente Energia_{Electron}/p_{TJet} para cada ak5PFJet; Energia_{Electron}/p_{Tak5PFJet}; Probabilidad", 100, 0, 10);
  TH1F *h_ak5PFJets__EnergyQuotient_Photon_Jet  = new TH1F("ak5PFJets  Energia_Photon / p_T_Jet", "Cociente Energia_{Photon}/p_{TJet} para cada ak5PFJet; Energia_{Photon}/p_{Tak5PFJet}; Probabilidad", 100, 0, 100);
  TH1F *h_ak5PFJets__EnergyQuotient_Muon_Jet    = new TH1F("ak5PFJets  Energia_Muon / p_T_Jet", "Cociente Energia_{Muon}/p_{TJet} para cada ak5PFJet; Energia_{Muon}/p_{Tak5PFJet}; Probabilidad", 100, 0, 100);
  // Multiplicidad de las particulas en cada Jet.
  TH1F *h_ak5PFJets__ChaHad_Multiplicity  = new TH1F("ak5PFJets  Multiplicidad_ChaHad", "Multiplicidad HadronCargado en cada ak5PFJet; Multiplicidad HadronCargado; Probabilidad", 100, 0, 100);
  TH1F *h_ak5PFJets__NeuHad_Multiplicity  = new TH1F("ak5PFJets  Multiplicidad_NeuHad", "Multiplicidad HadronNeutro en cada ak5PFJet; Multiplicidad HadronNeutral; Probabilidad", 100, 0, 100);

  // Electrones
  TH1F *h_gsfElectrons__Multiplicity        = new TH1F("gsfElectrones  Multiplicidad", "Multiplicidad, != 0, de gsfElectrones por Evento; Numero de electrones; Ocurrencia", 13, 0, 13);
  TH1F *h_ak5PFJets__ElectronMultiplicity   = new TH1F("ak5PFJets  Multiplicidad_Electron!=0", "Multiplicidad, != 0, de Electrones en cada ak5PFJet; Multiplicidad Electron; Probabilidad", 12, 0, 12);
  TH1F *h__pTQuotient_gsfElectron_ak5PFJet  = new TH1F(" Cociente_pT  gsfElectron / ak5PFJet",  "Cociente p_{T}  gsfElectron / ak5PFJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient_gsfElectron_ak5PFJet_Rmin= new TH1F(" Cociente_pT  gsfElectron / ak5PFJet R menor a 0.2",  "Cociente p_{T}  gsfElectron/ak5PFJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient_gsfElectron_ak5PFJet_Rmax= new TH1F(" Cociente_pT  gsfElectron / ak5PFJet R mayor a 0.2",  "Cociente p_{T}  gsfElectron/ak5PFJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__etaDistance_gsfElectron_ak5PFJet = new TH1F(" Distancia_eta  gsfElectron ak5PFJet", "Diferencia |#eta_{gsfElectron} - #eta_{ak5PFJet}|; Distancia angular; Ocurrencia", 120, 0, 12);
  TH1F *h__phiDistance_gsfElectron_ak5PFJet = new TH1F(" Distancia_phi  gsfElectron ak5PFJet", "Diferencia |#phi_{gsfElectron} - #phi_{ak5PFJet}|; Distancia angular; Ocurrencia", 120, 0, 12);
  TH1F *h__angDistance_gsfElectron_ak5PFJet = new TH1F(" Distancia_angular  gsfElectron ak5PFJet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del gsfElectron al ak5PFJets; Valor; Ocurrencia", 120, 0, 12);
  // Fotones
  TH1F *h_Photons__Multiplicity         = new TH1F("Fotones  Multiplicidad", "Multiplicidad, != 0, de Fotones por Evento; Numero de fotones; Ocurrencia", 13, 0, 13);
  TH1F *h_ak5PFJets__PhotonMultiplicity = new TH1F("ak5PFJets  Multiplicidad_Photon!=0", "Multiplicidad, != 0, de Fotones en cada ak5PFJet; Multiplicidad Foton; Probabilidad", 120, 0, 120);
  TH1F *h__pTQuotient_Photon_ak5PFJet   = new TH1F(" Cociente_pT  Foton / ak5PFJet",  "Cociente p_{T}  Foton / ak5PFJets; Indice; Ocurrencia", 100, 0, 10);
  TH1F *h__etaDistance_Photon_ak5PFJet  = new TH1F(" Distancia_eta  Foton ak5PFJet", "Diferencia |#eta_{Foton} - #eta_{ak5PFJet}|; Distancia angular; Ocurrencia", 120, 0, 12);
  TH1F *h__phiDistance_Photon_ak5PFJet  = new TH1F(" Distancia_phi  Foton ak5PFJet", "Diferencia |#phi_{Foton} - #phi_{ak5PFJet}|; Distancia angular; Ocurrencia", 120, 0, 12);
  TH1F *h__angDistance_Photon_ak5PFJet  = new TH1F(" Distancia_angular  Foton ak5PFJet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del Foton al ak5PFJets; Valor; Ocurrencia", 120, 0, 12);
  // Muones
  TH1F *h_Muons__Multiplicity         = new TH1F("Muones  Multiplicidad", "Multiplicidad, != 0, de Muones por Evento; Numero de muones; Ocurrencia", 13, 0, 13);
  TH1F *h_ak5PFJets__MuonMultiplicity = new TH1F("ak5PFJets  Multiplicidad_Muon!=0", "Multiplicidad, != 0, de Muones en cada ak5PFJet; Multiplicidad Muon; Probabilidad", 12, 0, 12);
  TH1F *h__pTQuotient_Muon_ak5PFJet   = new TH1F(" Cociente_pT  Muon / ak5PFJet",  "Cociente p_{T}  Muon / ak5PFJets; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__etaDistance_Muon_ak5PFJet  = new TH1F(" Distancia_eta  Muon ak5PFJet", "Diferencia |#eta_{Muon} - #eta_{ak5PFJet}|; Distancia angular; Ocurrencia", 120, 0, 12);
  TH1F *h__phiDistance_Muon_ak5PFJet  = new TH1F(" Distancia_phi  Muon ak5PFJet", "Diferencia |#phi_{Muon} - #phi_{ak5PFJet}|; Distancia angular; Ocurrencia", 120, 0, 12);
  TH1F *h__angDistance_Muon_ak5PFJet  = new TH1F(" Distancia_angular  Muon ak5PFJet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del Muon al ak5PFJets; Valor; Ocurrencia", 120, 0, 12);


  printf("\t %i) Histogramas creados. \n\n", nprint++);


  // Hacemos un loop respecto a todo el conjunto de datos de interés.
  while (reader.Next()) {   Int_t MultJet_04=0, MultJet_08=0, MultJet_16=0, MultJet_32=0, MultJet_64=0;

    // Realizo un ciclo for sobre todos los Jets.
    for (Int_t i=0; i<ak5PFJets_pt_.GetSize(); i++){

      // Multiplicidad de ak5PFJets en cada Evento. Se tomo p_T como criterio de selección.
      if (ak5PFJets_pt_[i] >  4.0)  ++MultJet_04;
      if (ak5PFJets_pt_[i] >  8.0)  ++MultJet_08;
      if (ak5PFJets_pt_[i] > 16.0)  ++MultJet_16;
      if (ak5PFJets_pt_[i] > 32.0)  ++MultJet_32;
      if (ak5PFJets_pt_[i] > 64.0)  ++MultJet_64;

      // Espectro de p_T. Tomando como criterio de seleccion la multiplicidad de ak5PFJets en cada Evento.
      h_ak5PFJets_pt_ -> Fill(ak5PFJets_pt_[i]);
      if (ak5PFJets_pt_.GetSize() <= 64)  h_ak5PFJets_Multiplicity64__pT -> Fill(ak5PFJets_pt_[i]);
      if (ak5PFJets_pt_.GetSize() <= 32)  h_ak5PFJets_Multiplicity32__pT -> Fill(ak5PFJets_pt_[i]);
      if (ak5PFJets_pt_.GetSize() <= 16)  h_ak5PFJets_Multiplicity16__pT -> Fill(ak5PFJets_pt_[i]);
      if (ak5PFJets_pt_.GetSize() <= 8 )  h_ak5PFJets_Multiplicity08__pT -> Fill(ak5PFJets_pt_[i]);
      if (ak5PFJets_pt_.GetSize() <= 4 )  h_ak5PFJets_Multiplicity04__pT -> Fill(ak5PFJets_pt_[i]);
      if (ak5PFJets_pt_.GetSize() <= 2 )  h_ak5PFJets_Multiplicity02__pT -> Fill(ak5PFJets_pt_[i]);

      // Hacemos este loop para conocer la distancia angular relativa entre Jets. Comenzamos en j=i+1 para no repetir ninguna medida.
      for (Int_t j=i+1; j<ak5PFJets_pt_.GetSize(); j++) {
        // h__etaDistance__jet_jet -> Fill( abs(ak5PFJets_eta_[i] - ak5PFJets_eta_[j]) );
        // h__phiDistance__jet_jet -> Fill( abs(ak5PFJets_phi_[i] - ak5PFJets_phi_[j]) );
        if ( abs(ak5PFJets_phi_[i]-ak5PFJets_phi_[j]) < PI ) {
          h_ak5PFJets__D_Jet_Jet    -> Fill( sqrt(pow(ak5PFJets_eta_[i]-ak5PFJets_eta_[j], 2) +  pow(ak5PFJets_phi_[i]-ak5PFJets_phi_[j], 2)) );
          if ( 4.0<ak5PFJets_pt_[i] &&  4.0<ak5PFJets_pt_[j])  h_ak5PFJets_pT04__D_Jet_Jet -> Fill( sqrt(pow(ak5PFJets_eta_[i]-ak5PFJets_eta_[j], 2) +  pow(ak5PFJets_phi_[i]-ak5PFJets_phi_[j], 2)) );
          if ( 8.0<ak5PFJets_pt_[i] &&  8.0<ak5PFJets_pt_[j])  h_ak5PFJets_pT08__D_Jet_Jet -> Fill( sqrt(pow(ak5PFJets_eta_[i]-ak5PFJets_eta_[j], 2) +  pow(ak5PFJets_phi_[i]-ak5PFJets_phi_[j], 2)) );
          if (16.0<ak5PFJets_pt_[i] && 16.0<ak5PFJets_pt_[j])  h_ak5PFJets_pT16__D_Jet_Jet -> Fill( sqrt(pow(ak5PFJets_eta_[i]-ak5PFJets_eta_[j], 2) +  pow(ak5PFJets_phi_[i]-ak5PFJets_phi_[j], 2)) );
          if (32.0<ak5PFJets_pt_[i] && 32.0<ak5PFJets_pt_[j])  h_ak5PFJets_pT32__D_Jet_Jet -> Fill( sqrt(pow(ak5PFJets_eta_[i]-ak5PFJets_eta_[j], 2) +  pow(ak5PFJets_phi_[i]-ak5PFJets_phi_[j], 2)) );
          if (64.0<ak5PFJets_pt_[i] && 64.0<ak5PFJets_pt_[j])  h_ak5PFJets_pT64__D_Jet_Jet -> Fill( sqrt(pow(ak5PFJets_eta_[i]-ak5PFJets_eta_[j], 2) +  pow(ak5PFJets_phi_[i]-ak5PFJets_phi_[j], 2)) );
        } else {  // Esto es debido a que ningún Jet puede estar a una distancia mayor a PI, de otro Jet.
          h_ak5PFJets__D_Jet_Jet    -> Fill( sqrt(pow(ak5PFJets_eta_[i]-ak5PFJets_eta_[j], 2) +  pow(2*PI-abs(ak5PFJets_phi_[i]-ak5PFJets_phi_[j]), 2)) );
          if ( 4.0<ak5PFJets_pt_[i] &&  4.0<ak5PFJets_pt_[j])  h_ak5PFJets_pT04__D_Jet_Jet -> Fill( sqrt(pow(ak5PFJets_eta_[i]-ak5PFJets_eta_[j], 2) +  pow(2*PI-abs(ak5PFJets_phi_[i]-ak5PFJets_phi_[j]), 2)) );
          if ( 8.0<ak5PFJets_pt_[i] &&  8.0<ak5PFJets_pt_[j])  h_ak5PFJets_pT08__D_Jet_Jet -> Fill( sqrt(pow(ak5PFJets_eta_[i]-ak5PFJets_eta_[j], 2) +  pow(2*PI-abs(ak5PFJets_phi_[i]-ak5PFJets_phi_[j]), 2)) );
          if (16.0<ak5PFJets_pt_[i] && 16.0<ak5PFJets_pt_[j])  h_ak5PFJets_pT16__D_Jet_Jet -> Fill( sqrt(pow(ak5PFJets_eta_[i]-ak5PFJets_eta_[j], 2) +  pow(2*PI-abs(ak5PFJets_phi_[i]-ak5PFJets_phi_[j]), 2)) );
          if (32.0<ak5PFJets_pt_[i] && 32.0<ak5PFJets_pt_[j])  h_ak5PFJets_pT32__D_Jet_Jet -> Fill( sqrt(pow(ak5PFJets_eta_[i]-ak5PFJets_eta_[j], 2) +  pow(2*PI-abs(ak5PFJets_phi_[i]-ak5PFJets_phi_[j]), 2)) );
          if (64.0<ak5PFJets_pt_[i] && 64.0<ak5PFJets_pt_[j])  h_ak5PFJets_pT64__D_Jet_Jet -> Fill( sqrt(pow(ak5PFJets_eta_[i]-ak5PFJets_eta_[j], 2) +  pow(2*PI-abs(ak5PFJets_phi_[i]-ak5PFJets_phi_[j]), 2)) );
        }
      }

      // Cociente de la energía de las partículas respecto al p_T del Jet. Y Multiplicidad de las particulas en cada Jet.
      if (ak5PFJets_mChargedHadronMultiplicity[i] != 0) {
        h_ak5PFJets__EnergyQuotient_ChaHad_Jet -> Fill(ak5PFJets_mChargedHadronEnergy[i]/ak5PFJets_pt_[i]);
        h_ak5PFJets__ChaHad_Multiplicity -> Fill(ak5PFJets_mChargedHadronMultiplicity[i]);      }
      if (ak5PFJets_mNeutralHadronMultiplicity[i] != 0) {
        h_ak5PFJets__EnergyQuotient_NeuHad_Jet -> Fill(ak5PFJets_mNeutralHadronEnergy[i]/ak5PFJets_pt_[i]);
        h_ak5PFJets__NeuHad_Multiplicity -> Fill(ak5PFJets_mNeutralHadronMultiplicity[i]);      }
      if (ak5PFJets_mElectronMultiplicity[i] != 0) {
        h_ak5PFJets__EnergyQuotient_Electron_Jet -> Fill(ak5PFJets_mElectronEnergy[i]/ak5PFJets_pt_[i]);
        h_ak5PFJets__ElectronMultiplicity -> Fill(ak5PFJets_mElectronMultiplicity[i]);      }
      if (ak5PFJets_mPhotonMultiplicity[i] != 0) {
        h_ak5PFJets__EnergyQuotient_Photon_Jet -> Fill(ak5PFJets_mPhotonEnergy[i]/ak5PFJets_pt_[i]);
        h_ak5PFJets__PhotonMultiplicity -> Fill(ak5PFJets_mPhotonMultiplicity[i]);      }
      if (ak5PFJets_mMuonMultiplicity[i] != 0) {
        h_ak5PFJets__EnergyQuotient_Muon_Jet -> Fill(ak5PFJets_mMuonEnergy[i]/ak5PFJets_pt_[i]);
        h_ak5PFJets__MuonMultiplicity -> Fill(ak5PFJets_mMuonMultiplicity[i]);    }

      // Elesctrones. // Selecciono los Jets que contiene un sólo electrón.
      if (ak5PFJets_mElectronMultiplicity[i] == 1) {   Float_t etaD=10, phiD=PI; Int_t eta_j, phi_j; // Defino valores de referencia. Estos cambiarán más adelante.
        for (Int_t j = 0; j < gsfElectrons_pt_.GetSize(); j++) {
          // Busco el electón que esté mas cerca, en ETA, del jet.
          if ( abs(gsfElectrons_eta_[j]-ak5PFJets_eta_[i]) < etaD ) {
            etaD = abs(gsfElectrons_eta_[j]-ak5PFJets_eta_[i]);      // etaD: diatancia en ETA.
            eta_j = j;   }                                            // eta_j: j-ésimo en ETA.
          // Busco el electón que esté mas cerca, en PHI, del jet.
          if ( abs(gsfElectrons_phi_[j]-ak5PFJets_phi_[i]) < phiD ) {
            phiD = abs(gsfElectrons_phi_[j]-ak5PFJets_phi_[i]);      // phiD: diatancia en PHI.
            phi_j = j;                                                  // phi_j: j-ésimo en PHI.
          } else if ( 2*PI-abs(gsfElectrons_phi_[j]-ak5PFJets_phi_[i]) < phiD ) {   // Si la distancia entre el Jet y el Electron es
            phiD = 2*PI-abs(gsfElectrons_phi_[j]-ak5PFJets_phi_[i]);                // mayor a 2*PI, entonces le aplicamos una corrección.
            phi_j = j;   }
        }
        if (eta_j == phi_j) {       // Esto es para corroborar que el electrón más cercano en ETA es también el más cercano en PHI.
          h__pTQuotient_gsfElectron_ak5PFJet -> Fill(gsfElectrons_pt_[eta_j]/ak5PFJets_pt_[i]);
          if (sqrt(etaD*etaD + phiD*phiD) < 0.2) {
            h__pTQuotient_gsfElectron_ak5PFJet_Rmin -> Fill(gsfElectrons_pt_[eta_j]/ak5PFJets_pt_[i]);
          } else {
            h__pTQuotient_gsfElectron_ak5PFJet_Rmax -> Fill(gsfElectrons_pt_[eta_j]/ak5PFJets_pt_[i]);
          }
          h__etaDistance_gsfElectron_ak5PFJet -> Fill(etaD);                 // Distancia en el ángulo ETA entre el jet y su electrón.
          h__phiDistance_gsfElectron_ak5PFJet -> Fill(phiD);                 // Distancia en el ángulo PHI entre el jet y su electrón.
          h__angDistance_gsfElectron_ak5PFJet -> Fill(sqrt(etaD*etaD + phiD*phiD)); // Distancia angular total entre el jet y su electrón.
      } }

      // Fotones
      if (ak5PFJets_mPhotonMultiplicity[i] == 1) {   Float_t etaD=10, phiD=PI; Int_t eta_j, phi_j;
        for (Int_t j = 0; j < photons_pt_.GetSize(); j++) {
          if ( abs(photons_eta_[j]-ak5PFJets_eta_[i]) < etaD ) {
            etaD = abs(photons_eta_[j]-ak5PFJets_eta_[i]);
            eta_j = j;   }
          if ( abs(photons_phi_[j]-ak5PFJets_phi_[i]) < phiD ) {
            phiD = abs(photons_phi_[j]-ak5PFJets_phi_[i]);
            phi_j = j;
          } else if ( 2*PI-abs(photons_phi_[j]-ak5PFJets_phi_[i]) < phiD ) {
            phiD = 2*PI-abs(photons_phi_[j]-ak5PFJets_phi_[i]);
            phi_j = j;   }
        h__pTQuotient_Photon_ak5PFJet  -> Fill(photons_pt_[j]);
      }
        if (eta_j == phi_j) {
          h__etaDistance_Photon_ak5PFJet -> Fill(etaD);
          h__phiDistance_Photon_ak5PFJet -> Fill(phiD);
          h__angDistance_Photon_ak5PFJet -> Fill(sqrt(etaD*etaD + phiD*phiD));
      } }

      // Muones
      if (ak5PFJets_mMuonMultiplicity[i] == 1) {   Float_t etaD=10, phiD=PI; Int_t eta_j, phi_j;
        for (Int_t j = 0; j < muons_pt_.GetSize(); j++) {
          if ( abs(muons_eta_[j]-ak5PFJets_eta_[i]) < etaD ) {
            etaD = abs(muons_eta_[j]-ak5PFJets_eta_[i]);
            eta_j = j;   }
          if ( abs(muons_phi_[j]-ak5PFJets_phi_[i]) < phiD ) {
            phiD = abs(muons_phi_[j]-ak5PFJets_phi_[i]);
            phi_j = j;
          } else if ( 2*PI-abs(muons_phi_[j]-ak5PFJets_phi_[i]) < phiD ) {
            phiD = 2*PI-abs(muons_phi_[j]-ak5PFJets_phi_[i]);
            phi_j = j;    }
        }
        if (eta_j == phi_j) {
          h__pTQuotient_Muon_ak5PFJet  -> Fill(muons_pt_[eta_j]/ak5PFJets_pt_[i]);
          h__etaDistance_Muon_ak5PFJet -> Fill(etaD);
          h__phiDistance_Muon_ak5PFJet -> Fill(phiD);
          h__angDistance_Muon_ak5PFJet -> Fill(sqrt(etaD*etaD + phiD*phiD));
      } }

    }

    // Multiplicidad de ak5PFJets en cada Evento. Se tomo p_T como criterio de selección.
    h_ak5PFJets__Multiplicity -> Fill(ak5PFJets_pt_.GetSize());
    if (MultJet_04 > 0)  h_ak5PFJets_pT04__Multiplicity -> Fill(MultJet_04);  // Aqui llenamos los histogramas con la cantidad de jets,
    if (MultJet_08 > 0)  h_ak5PFJets_pT08__Multiplicity -> Fill(MultJet_08);  // en cada evento, que cumple con tener p_T > x GeV.
    if (MultJet_16 > 0)  h_ak5PFJets_pT16__Multiplicity -> Fill(MultJet_16);  // En otras palabras, estos son espectros de multiplicidad
    if (MultJet_32 > 0)  h_ak5PFJets_pT32__Multiplicity -> Fill(MultJet_32);  // en funcion de distintos rangos de p_T.
    if (MultJet_64 > 0)  h_ak5PFJets_pT64__Multiplicity -> Fill(MultJet_64);

    // Multiplicidad, != 0, de los Electrones, Fotones y Muones reconstruidos en cada Evento.
    if (gsfElectrons_pt_.GetSize() != 0) h_gsfElectrons__Multiplicity -> Fill(gsfElectrons_pt_.GetSize());
    if (photons_pt_.GetSize() != 0)      h_Photons__Multiplicity      -> Fill(photons_pt_.GetSize());
    if (muons_pt_.GetSize() != 0)        h_Muons__Multiplicity        -> Fill(muons_pt_.GetSize());


    // printf("\t \t Dont worry. While %i hecho. =D \n\n", evento++);
  }


  printf("\t %i) Analisis hecho. \n\n", nprint++);

  h_ak5PFJets__Multiplicity -> Scale(1.0/h_ak5PFJets__Multiplicity->Integral());
  h_ak5PFJets_pt_           -> Scale(1.0/h_ak5PFJets_pt_          ->Integral());
  h_ak5PFJets__D_Jet_Jet    -> Scale(1.0/h_ak5PFJets__D_Jet_Jet   ->Integral());

  // Guardamos nustros histogramas en el archivo root que nos interesa.
  h_ak5PFJets__Multiplicity      -> Write();
  h_ak5PFJets_pT04__Multiplicity -> Write();
  h_ak5PFJets_pT08__Multiplicity -> Write();
  h_ak5PFJets_pT16__Multiplicity -> Write();
  h_ak5PFJets_pT32__Multiplicity -> Write();
  h_ak5PFJets_pT64__Multiplicity -> Write();

	h_ak5PFJets_pt_                -> Write();
  h_ak5PFJets_Multiplicity64__pT -> Write();
  h_ak5PFJets_Multiplicity32__pT -> Write();
  h_ak5PFJets_Multiplicity16__pT -> Write();
  h_ak5PFJets_Multiplicity08__pT -> Write();
  h_ak5PFJets_Multiplicity04__pT -> Write();
  h_ak5PFJets_Multiplicity02__pT -> Write();

  h_ak5PFJets__D_Jet_Jet      -> Write();
  h_ak5PFJets_pT04__D_Jet_Jet -> Write();
  h_ak5PFJets_pT08__D_Jet_Jet -> Write();
  h_ak5PFJets_pT16__D_Jet_Jet -> Write();
  h_ak5PFJets_pT32__D_Jet_Jet -> Write();
  h_ak5PFJets_pT64__D_Jet_Jet -> Write();
  // h__etaDistance__jet_jet   -> Write();
  // h__phiDistance__jet_jet   -> Write();

  h_ak5PFJets__EnergyQuotient_ChaHad_Jet  -> Write();
  h_ak5PFJets__EnergyQuotient_NeuHad_Jet  -> Write();
  h_ak5PFJets__EnergyQuotient_Electron_Jet-> Write();
  h_ak5PFJets__EnergyQuotient_Photon_Jet  -> Write();
  h_ak5PFJets__EnergyQuotient_Muon_Jet    -> Write();

  h_ak5PFJets__ChaHad_Multiplicity  -> Write();
  h_ak5PFJets__NeuHad_Multiplicity  -> Write();


  h_gsfElectrons__Multiplicity        -> Write();
  h_ak5PFJets__ElectronMultiplicity   -> Write();
  h__pTQuotient_gsfElectron_ak5PFJet  -> Write();
  h__pTQuotient_gsfElectron_ak5PFJet_Rmin-> Write();
  h__pTQuotient_gsfElectron_ak5PFJet_Rmax-> Write();
  h__etaDistance_gsfElectron_ak5PFJet -> Write();
  h__phiDistance_gsfElectron_ak5PFJet -> Write();
  h__angDistance_gsfElectron_ak5PFJet -> Write();

  h_Photons__Multiplicity         -> Write();
  h_ak5PFJets__PhotonMultiplicity -> Write();
  h__pTQuotient_Photon_ak5PFJet   -> Write();
  h__etaDistance_Photon_ak5PFJet  -> Write();
  h__phiDistance_Photon_ak5PFJet  -> Write();
  h__angDistance_Photon_ak5PFJet  -> Write();

  h_Muons__Multiplicity         -> Write();
  h_ak5PFJets__MuonMultiplicity -> Write();
  h__pTQuotient_Muon_ak5PFJet   -> Write();
  h__etaDistance_Muon_ak5PFJet  -> Write();
  h__phiDistance_Muon_ak5PFJet  -> Write();
  h__angDistance_Muon_ak5PFJet  -> Write();


  // printf("\t %i) Histogramas, sin modificar, guardados. \n\n", nprint++);


  delete OutputFile;


  printf("\t %i) Análisis terminado. A la primera como siempre.\n\n", nprint++);


  return 0;
}
