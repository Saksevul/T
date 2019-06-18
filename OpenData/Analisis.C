void Analisis() {   Float_t PI=TMath::Pi(); Int_t nprint=1;

  //Abrimos los archivos que nos interesan y los árboles que queremos leer.
  TFile *InputFile = new TFile("/media/saksevul/Pawahtun/CMS_Run2011A/BTag_20000/0001.root");
  TTree *Eventos = (TTree*)InputFile->Get("Events");

  //Crear el archivo de salida que queremos. Tiene que ir después del imputFile.
  TFile* OutputFile = new TFile("/home/saksevul/T/OpenData/BTag_20000/ak5PF-0001.root", "RECREATE");


    printf("\n\t JCA: ak5PF, InputFile: BTag_20000/0001.root. \n\n\t\t %i) Archivos abiertos. \n", nprint++);


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
  // Electrones
  TLeaf *Electrons_pt_ = Eventos->GetLeaf("recoGsfElectrons_gsfElectrons__RECO.obj.pt_");
  TLeaf *Electrons_eta_= Eventos->GetLeaf("recoGsfElectrons_gsfElectrons__RECO.obj.eta_");
  TLeaf *Electrons_phi_= Eventos->GetLeaf("recoGsfElectrons_gsfElectrons__RECO.obj.phi_");
  TLeaf *Electrons_fX_ = Eventos->GetLeaf("recoGsfElectrons_gsfElectrons__RECO.obj.corrections_.pflowP4.fCoordinates.fX");
  TLeaf *Electrons_fY_ = Eventos->GetLeaf("recoGsfElectrons_gsfElectrons__RECO.obj.corrections_.pflowP4.fCoordinates.fY");
  TLeaf *Electrons_fZ_ = Eventos->GetLeaf("recoGsfElectrons_gsfElectrons__RECO.obj.corrections_.pflowP4.fCoordinates.fZ");
  //Jets
  TLeaf *Jets_pt_                        = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.pt_");
  TLeaf *Jets_eta_                       = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.eta_");
  TLeaf *Jets_phi_                       = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.phi_");
  TLeaf *Jets_meta_jrea                  = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.mJetArea");
  TLeaf *Jets_mPileupEnergy              = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.mPileupEnergy");
  TLeaf *Jets_mPassNumber                = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.mPassNumber");
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


  // Muons
  // TH1F *h_Muons_pt_   = new TH1F("Muons_pt_",   "p_{T} de Muones contenidos en ak5PFJet; p_{T} [GeV]; Frecuencia",  600, 0, 300);
  // TH1F *h_Muons_eta_  = new TH1F("Muons_eta_",  "recoMuones_muons__RECO.obj.eta_; #eta; Frecuencia", 59, -5.9, 5.9);
  TH1D *h_Muons_fX_   = new TH1D("Muons_fX_",   "Vertice en X de Muones contenidos en ak5PFJet; Distancia [cm]; Frecuencia", 39, -1.95, 1.95);
  TH1D *h_Muons_fY_   = new TH1D("Muons_fY_",   "Vertice en Y de Muones contenidos en ak5PFJet; Distancia [cm]; Frecuencia", 39, -1.95, 1.95);
  TH1D *h_Muons_fZ_   = new TH1D("Muons_fZ_",   "Vertice en Z de Muones contenidos en ak5PFJet; Distancia [cm]; Frecuencia", 39, -1.95, 1.95);
  // Electrons
  // TH1F *h_Electrons_pt_   = new TH1F("Electrons_pt_",   "p_{T} de Electrones contenidos en ak5PFJet; p_{T} [GeV]; Frecuencia",  900, 0, 450);
  // TH1F *h_Electrons_eta_  = new TH1F("Electrons_eta_",  "recoElectrons_Electrons__RECO.obj.eta_; #eta; Frecuencia", 59, -5.9, 5.9);
  TH1D *h_Electrons_fX_   = new TH1D("Electrons_fX_",   "Vertice en X de Electrones contenidos en ak5PFJet; Distancia [cm]; Frecuencia", 39, -1.95, 1.95);
  TH1D *h_Electrons_fY_   = new TH1D("Electrons_fY_",   "Vertice en Y de Electrones contenidos en ak5PFJet; Distancia [cm]; Frecuencia", 39, -1.95, 1.95);
  TH1D *h_Electrons_fZ_   = new TH1D("Electrons_fZ_",   "Vertice en Z de Electrones contenidos en ak5PFJet; Distancia [cm]; Frecuencia", 39, -1.95, 1.95);
  // // Jets
  // TH1F *h_Jets_pt_   = new TH1F("ak5PFJet_pt_",   "recoPFJets_PFJets__RECO.obj.pt_; p_{T} [GeV]; Frecuencia",  1200, 0, 1200);
  // TH1F *h_Jets_eta_  = new TH1F("ak5PFJet_eta_",  "recoPFJets_PFJets__RECO.obj.eta_; #eta; Frecuencia", 59, -5.9, 5.9);
  // Multiplicidad.
  TH1F *h_Muons__Multiplicity         = new TH1F("Muones__Multiplicidad", "Multiplicidad, != 0, de Muones por Evento; Numero de muones; Frecuencia", 48, 0, 48);
  TH1F *h_Photons__Multiplicity       = new TH1F("Fotones__Multiplicidad", "Multiplicidad, != 0, de Fotones por Evento; Numero de fotones; Frecuencia", 24, 0, 24);
  TH1F *h_Electrons__Multiplicity  = new TH1F("Electrones__Multiplicidad", "Multiplicidad, != 0, de Electrones por Evento; Numero de electrones; Frecuencia", 24, 0, 24);
  TH1F *h_Jets__MuonMultiplicity       = new TH1F("ak5PFJet__Multiplicidad_Muon!=0", "Multiplicidad, != 0, de Muones en cada ak5PFJet; Multiplicidad Muon; Frecuencia", 12, 0, 12);
  TH1F *h_Jets__PhotonMultiplicity     = new TH1F("ak5PFJet__Multiplicidad_Photon!=0", "Multiplicidad, != 0, de Fotones en cada ak5PFJet; Multiplicidad Foton; Frecuencia", 120, 0, 120);
  TH1F *h_Jets__ElectronMultiplicity   = new TH1F("ak5PFJet__Multiplicidad_Electron!=0", "Multiplicidad, != 0, de Electrones en cada ak5PFJet; Multiplicidad Electron; Frecuencia", 12, 0, 12);
  TH1I *h_Jets__Multiplicity_1Electron = new TH1I("ak5PFJet__Multiplicidad_1Electron", "Multipicidad de Jets con 1 Electron por Evento; Cantidad; Frecuencia", 41, -20.5, 20.5);
  TH1F *h_Jets__ChaHad_Multiplicity    = new TH1F("ak5PFJet__Multiplicidad_ChaHad", "Multiplicidad HadronCargado en cada ak5PFJet; Multiplicidad HadronCargado; Frecuencia", 100, 0, 100);
  TH1F *h_Jets__NeuHad_Multiplicity    = new TH1F("ak5PFJet__Multiplicidad_NeuHad", "Multiplicidad HadronNeutro en cada ak5PFJet; Multiplicidad HadronNeutral; Frecuencia", 100, 0, 100);
  TH1F *h_Jets__Multiplicity       = new TH1F("ak5PFJet__Multiplicidad", "Multiplicidad de ak5PFJet por Evento; Numero de Jets; Frecuencia", 120, 0, 120);
  TH1F *h_Jets_pT04__Multiplicity  = new TH1F("ak5PFJet_pT>04__Multiplicidad", "Multiplicidad de ak5PFJet, con p_{T} > 04 GeV, por Evento; Numero de Jets; Frecuencia", 120, 0, 120);
  TH1F *h_Jets_pT08__Multiplicity  = new TH1F("ak5PFJet_pT>08__Multiplicidad", "Multiplicidad de ak5PFJet, con p_{T} > 08 GeV, por Evento; Numero de Jets; Frecuencia", 120, 0, 120);
  TH1F *h_Jets_pT16__Multiplicity  = new TH1F("ak5PFJet_pT>16__Multiplicidad", "Multiplicidad de ak5PFJet, con p_{T} > 16 GeV, por Evento; Numero de Jets; Frecuencia", 120, 0, 120);
  TH1F *h_Jets_pT32__Multiplicity  = new TH1F("ak5PFJet_pT>32__Multiplicidad", "Multiplicidad de ak5PFJet, con p_{T} > 32 GeV, por Evento; Numero de Jets; Frecuencia", 120, 0, 120);
  TH1F *h_Jets_pT64__Multiplicity  = new TH1F("ak5PFJet_pT>64__Multiplicidad", "Multiplicidad de ak5PFJet, con p_{T} > 64 GeV, por Evento; Numero de Jets; Frecuencia", 120, 0, 120);
  // Espectro de p_T.
  TH1F *h_Jets_Multiplicity64__pT = new TH1F("ak5PFJet_Mult<=64__pT", "Distribucion de pT de ak5PFJet, con Multilicidad <= 64, por Evento; p_{T} [GeV]; Frecuencia", 800, 0, 3200);
  TH1F *h_Jets_Multiplicity32__pT = new TH1F("ak5PFJet_Mult<=32__pT", "Distribucion de pT de ak5PFJet, con Multilicidad <= 32, por Evento; p_{T} [GeV]; Frecuencia", 800, 0, 3200);
  TH1F *h_Jets_Multiplicity16__pT = new TH1F("ak5PFJet_Mult<=16__pT", "Distribucion de pT de ak5PFJet, con Multilicidad <= 16, por Evento; p_{T} [GeV]; Frecuencia", 800, 0, 3200);
  TH1F *h_Jets_Multiplicity08__pT = new TH1F("ak5PFJet_Mult<=08__pT", "Distribucion de pT de ak5PFJet, con Multilicidad <= 08, por Evento; p_{T} [GeV]; Frecuencia", 800, 0, 3200);
  TH1F *h_Jets_Multiplicity04__pT = new TH1F("ak5PFJet_Mult<=04__pT", "Distribucion de pT de ak5PFJet, con Multilicidad <= 04, por Evento; p_{T} [GeV]; Frecuencia", 800, 0, 3200);
  TH1F *h_Jets_Multiplicity02__pT = new TH1F("ak5PFJet_Mult<=02__pT", "Distribucion de pT de ak5PFJet, con Multilicidad <= 02, por Evento; p_{T} [GeV]; Frecuencia", 800, 0, 3200);
  // Cocientes.
  TH1F *h__pTQuotient_Muon_Jet         = new TH1F("Cociente_pT__Muon-ak5PFJet",  "Cociente p_{T}  Muon / ak5PFJet; Indice; Frecuencia", 100, 0, 2);
  TH1F *h__pTQuotient_1Muon_Jet        = new TH1F("Cociente_pT<100__1Muon-ak5PFJet",  "Cociente_{p_{T} < 100}  Muon_{MasEnergetico} / ak5PFJet; Indice; Frecuencia", 100, 0, 2);
  TH1F *h__pTQuot100__1Muon_Jet        = new TH1F("Cociente_pT>100__1Muon-ak5PFJet",  "Cociente_{p_{T} > 100}  Muon_{MasEnergetico} / ak5PFJet; Indice; Frecuencia", 100, 0, 2);
  TH1F *h__pTQuotient_Electron_Jet  = new TH1F("Cociente_pT__Electron-ak5PFJet",  "Cociente p_{T}  Electron / ak5PFJet; Indice; Frecuencia", 100, 0, 2);
  TH1F *h__pTQuotient_1Electron_Jet = new TH1F("Cociente_pT<100__1Electron-ak5PFJet",  "Cociente_{p_{T} < 100}  Electron_{MasEnergetico} / ak5PFJet; Indice; Frecuencia", 100, 0, 2);
  TH1F *h__pTQuot100__1Electron_Jet = new TH1F("Cociente_pT>100__1Electron-ak5PFJet",  "Cociente_{p_{T} > 100}  Electron_{MasEnergetico} / ak5PFJet; Indice; Frecuencia", 100, 0, 2);

  TH1F *h_Jets__EnergyQuotient_Muon_Jet    = new TH1F("Cociente_Energia_ak5PFJet__Muon-Jet", "Cociente Energia  Muon / ak5PFJet; Energia_{Muon}/Energia_{ak5PFJet}; Frecuencia", 20, 0, 2);
  TH1F *h_Jets__EnergyQuotient_Photon_Jet  = new TH1F("Cociente_Energia_ak5PFJet__Photon-Jet", "Cociente Energia  Photon / ak5PFJet; Energia_{Photon}/Energia_{ak5PFJet}; Frecuencia", 20, 0, 2);
  TH1F *h_Jets__EnergyQuotient_Electron_Jet= new TH1F("Cociente_Energia_ak5PFJet__Electron-Jet", "Cociente Energia  Electron / ak5PFJet; Energia_{Electron}/Energia_{ak5PFJet}; Frecuencia", 20, 0, 2);
  TH1F *h_Jets__EnergyQuotient_NeutralHad_Jet  = new TH1F("Cociente_Energia_ak5PFJet__NeutralHad-Jet", "Cociente Energia  NeutralHad / ak5PFJet; Energia_{NeutralHad}/Energia_{ak5PFJet}; Frecuencia", 20, 0, 2);
  TH1F *h_Jets__EnergyQuotient_ChargedHad_Jet  = new TH1F("Cociente_Energia_ak5PFJet__ChargedHad-Jet", "Cociente Energia  ChargedHad / ak5PFJet; Energia_{ChagedHad}/Energia_{ak5PFJet}; Frecuencia", 20, 0, 2);
  // Distancia eta.
  TH1F *h__eta_D__Muon_Jet        = new TH1F("D_eta__Muon-ak5PFJet", "Diferencia |#eta_{Muon} - #eta_{ak5PFJet}|; Distancia angular; Frecuencia", 120, 0, 1.2);
  TH1F *h__eta_D__Photon_Jet      = new TH1F("D_eta__Foton-ak5PFJet", "Diferencia |#eta_{Foton} - #eta_{ak5PFJet}|; Distancia angular; Frecuencia", 120, 0, 1.2);
  TH1F *h__eta_D__Electron_Jet = new TH1F("D_eta__Electron-ak5PFJet", "Diferencia |#eta_{Electron} - #eta_{ak5PFJet}|; Distancia angular; Frecuencia", 120, 0, 1.2);
  // Distancia phi.
  TH1F *h__phi_D__Muon_Jet        = new TH1F("D_phi__Muon-ak5PFJet", "Diferencia |#phi_{Muon} - #phi_{ak5PFJet}|; Distancia angular; Frecuencia", 120, 0, 1.2);
  TH1F *h__phi_D__Photon_Jet      = new TH1F("D_phi__Foton-ak5PFJet", "Diferencia |#phi_{Foton} - #phi_{ak5PFJet}|; Distancia angular; Frecuencia", 120, 0, 1.2);
  TH1F *h__phi_D__Electron_Jet = new TH1F("D_phi__Electron-ak5PFJet", "Diferencia |#phi_{Electron} - #phi_{ak5PFJet}|; Distancia angular; Frecuencia", 120, 0, 1.2);
  // Distancia angular.
  TH1F *h__D__Muon_Jet        = new TH1F("D__Muon-ak5PFJet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del Muon al ak5PFJet; Valor; Frecuencia", 120, 0, 1.2);
  TH1F *h__D__Photon_Jet      = new TH1F("D__Foton-ak5PFJet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del Foton al ak5PFJet; Valor; Frecuencia", 120, 0, 1.2);
  TH1F *h__D__Electron_Jet = new TH1F("D__Electron-ak5PFJet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del Electron al ak5PFJet; Valor; Frecuencia", 480, 0, 1.2);
  TH1F *h_Jets__D__Jet_Jet      = new TH1F("ak5PFJet__D__Jet-Jet", "Distancia angular #sqrt{(#Delta#phi_{ij})^{2} + (#Delta#eta_{ij})^{2}} del ak5PFJet_{i} al ak5PFJet_{j}, por Evento; Valor; Frecuencia", 120, 0, 12);
  TH1F *h_Jets_pT04__D__Jet_Jet = new TH1F("ak5PFJet_pT>04__D__Jet-Jet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del ak5PFJet_{i} al ak5PFJet_{j}, por Evento; Valor; Frecuencia", 120, 0, 12);
  TH1F *h_Jets_pT08__D__Jet_Jet = new TH1F("ak5PFJet_pT>08__D__Jet-Jet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del ak5PFJet_{i} al ak5PFJet_{j}, por Evento; Valor; Frecuencia", 120, 0, 12);
  TH1F *h_Jets_pT16__D__Jet_Jet = new TH1F("ak5PFJet_pT>16__D__Jet-Jet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del ak5PFJet_{i} al ak5PFJet_{j}, por Evento; Valor; Frecuencia", 120, 0, 12);
  TH1F *h_Jets_pT32__D__Jet_Jet = new TH1F("ak5PFJet_pT>32__D__Jet-Jet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del ak5PFJet_{i} al ak5PFJet_{j}, por Evento; Valor; Frecuencia", 120, 0, 12);
  TH1F *h_Jets_pT64__D__Jet_Jet = new TH1F("ak5PFJet_pT>64__D__Jet-Jet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del ak5PFJet_{i} al ak5PFJet_{j}, por Evento; Valor; Frecuencia", 120, 0, 12);
  // TH1F *h__eta_D__jet_jet   = new TH1F("ak5PFJet_distancia_eta  jet jet", "Distancia angular #eta entre todos los jets de cada evento; Distancia angular; Frecuencia", 120, 0, 12);
  // TH1F *h__phi_D__jet_jet   = new TH1F("ak5PFJet_distancia_phi  jet jet", "Distancia angular #phi entre todos los jets de cada evento; Distancia angular; Frecuencia", 63, 0, 6.3);



    printf("\t\t %i) Histogramas creados. \n", nprint++);


  Float_t etaMax = 1.479;


  //###################################################################################################################################################################################
  for (Int_t e=0; e<Eventos->GetEntries(); e++) {  //Creamos unos histogramas para conocer la distribución de los vértices.
    Electrons_fX_ ->GetBranch()->GetEntry(e);  Muons_fX_ ->GetBranch()->GetEntry(e);
    Electrons_fY_ ->GetBranch()->GetEntry(e);  Muons_fY_ ->GetBranch()->GetEntry(e);
    Electrons_fZ_ ->GetBranch()->GetEntry(e);  Muons_fZ_ ->GetBranch()->GetEntry(e);
    for (Int_t i=0; i<Electrons_fX_->GetLen(); i++) {
      h_Electrons_fX_ -> Fill(Electrons_fX_->GetValue(i));
      h_Electrons_fY_ -> Fill(Electrons_fY_->GetValue(i));
      h_Electrons_fZ_ -> Fill(Electrons_fZ_->GetValue(i));
    }
    for (Int_t i=0; i<Muons_fX_->GetLen(); i++) {
      h_Muons_fX_ -> Fill(Muons_fX_->GetValue(i));
      h_Muons_fY_ -> Fill(Muons_fY_->GetValue(i));
      h_Muons_fZ_ -> Fill(Muons_fZ_->GetValue(i));
    }
  }
  // Ajustamos ua Gaussiana a los histogramas. Esto para obtener el valor medio.
  TF1 *gauss = new TF1("gauss", "gaus");
  h_Electrons_fX_->Fit("gauss", "CNQ");  Float_t x_e=gauss->GetParameter(1) /*, sx_e=gauss->GetParameter(2)*/;  h_Electrons_fX_->Reset("ICESM");
  h_Electrons_fY_->Fit("gauss", "CNQ");  Float_t y_e=gauss->GetParameter(1) /*, sy_e=gauss->GetParameter(2)*/;  h_Electrons_fY_->Reset("ICESM");
  h_Electrons_fZ_->Fit("gauss", "CNQ");  Float_t z_e=gauss->GetParameter(1) /*, sz_e=gauss->GetParameter(2)*/;  h_Electrons_fZ_->Reset("ICESM");
  h_Muons_fX_->Fit("gauss", "CNQ");  Float_t x_m=gauss->GetParameter(1) /*, sx_m=gauss->GetParameter(2)*/;  h_Muons_fX_->Reset("ICESM");
  h_Muons_fY_->Fit("gauss", "CNQ");  Float_t y_m=gauss->GetParameter(1) /*, sy_m=gauss->GetParameter(2)*/;  h_Muons_fY_->Reset("ICESM");
  h_Muons_fZ_->Fit("gauss", "CNQ");  Float_t z_m=gauss->GetParameter(1) /*, sz_m=gauss->GetParameter(2)*/;  h_Muons_fZ_->Reset("ICESM");


  //###################################################################################################################################################################################
  // Hacemos un loop respecto a todo el conjunto de datos de interés.
  for (Int_t e=0; e<Eventos->GetEntries(); e++) {   // Int_t MultJet_04=0, MultJet_08=0, MultJet_16=0, MultJet_32=0, MultJet_64=0;

    // Eventos->GetEntry(e);
    // Muons->GetEntry(e);
    // Electrons->GetEntry(e);
    // Jets->GetEntry(e);
    Muons_pt_ ->GetBranch()->GetEntry(e);  Electrons_pt_ ->GetBranch()->GetEntry(e);  Jets_pt_  ->GetBranch()->GetEntry(e);
    Muons_eta_->GetBranch()->GetEntry(e);  Electrons_eta_->GetBranch()->GetEntry(e);  Jets_eta_ ->GetBranch()->GetEntry(e);
    Muons_phi_->GetBranch()->GetEntry(e);  Electrons_phi_->GetBranch()->GetEntry(e);  Jets_phi_ ->GetBranch()->GetEntry(e);
    Muons_fX_ ->GetBranch()->GetEntry(e);  Electrons_fX_ ->GetBranch()->GetEntry(e);
    Muons_fY_ ->GetBranch()->GetEntry(e);  Electrons_fY_ ->GetBranch()->GetEntry(e);
    Muons_fZ_ ->GetBranch()->GetEntry(e);  Electrons_fZ_ ->GetBranch()->GetEntry(e);
    Jets_mPileupEnergy -> GetBranch()->GetEntry(e);
    // Jets_mChargedHadronEnergy->GetBranch()->GetEntry(e);  Jets_mChargedHadronMultiplicity->GetBranch()->GetEntry(e);
    // Jets_mNeutralHadronEnergy->GetBranch()->GetEntry(e);  Jets_mNeutralHadronMultiplicity->GetBranch()->GetEntry(e);
    Jets_mElectronEnergy     ->GetBranch()->GetEntry(e);  Jets_mElectronMultiplicity     ->GetBranch()->GetEntry(e);
    Jets_mPhotonEnergy       ->GetBranch()->GetEntry(e);  Jets_mPhotonMultiplicity       ->GetBranch()->GetEntry(e);
    Jets_mMuonEnergy         ->GetBranch()->GetEntry(e);  Jets_mMuonMultiplicity         ->GetBranch()->GetEntry(e);

    for (Int_t i=0; i<Jets_pt_->GetLen(); i++) {      Float_t iJet_pT=Jets_pt_->GetValue(i), iJet_eta=Jets_eta_->GetValue(i), iJet_phi=Jets_phi_->GetValue(i);
      if ( fabs(iJet_eta) > etaMax-0.7 ) continue;

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

      // Cociente de la energía de las partículas respecto al p_T del Jet. Y Multiplicidad de las particulas en cada Jet.
      if (Jets_mChargedHadronMultiplicity->GetValue(i) != 0) {
        h_Jets__EnergyQuotient_ChaHad_Jet -> Fill(Jets_mChargedHadronEnergy->GetValue(i)/JetEnergy);
        h_Jets__ChaHad_Multiplicity -> Fill(Jets_mChargedHadronMultiplicity->GetValue(i));      }
      if (Jets_mNeutralHadronMultiplicity->GetValue(i) != 0) {
        h_Jets__EnergyQuotient_NeuHad_Jet -> Fill(Jets_mNeutralHadronEnergy->GetValue(i)/JetEnergy);
        h_Jets__NeuHad_Multiplicity -> Fill(Jets_mNeutralHadronMultiplicity->GetValue(i));      }
      if (Jets_mElectronMultiplicity->GetValue(i) != 0) {
        h_Jets__EnergyQuotient_Electron_Jet -> Fill(Jets_mElectronEnergy->GetValue(i)/JetEnergy);
        h_Jets__ElectronMultiplicity -> Fill(Jets_mElectronMultiplicity->GetValue(i));      }
      if (Jets_mPhotonMultiplicity->GetValue(i) != 0) {
        h_Jets__EnergyQuotient_Photon_Jet -> Fill(Jets_mPhotonEnergy->GetValue(i)/JetEnergy);
        h_Jets__PhotonMultiplicity -> Fill(Jets_mPhotonMultiplicity->GetValue(i));      }
      if (Jets_mMuonMultiplicity->GetValue(i) != 0) {
        h_Jets__EnergyQuotient_Muon_Jet -> Fill(Jets_mMuonEnergy->GetValue(i)/JetEnergy);
        h_Jets__MuonMultiplicity -> Fill(Jets_mMuonMultiplicity->GetValue(i));    }

      // Muones
      if (Jets_mMuonMultiplicity->GetValue(i) > 0) {   Int_t Index[100]; Float_t D[100]; Bool_t Flag=false; Float_t pT=0.0; // Defino valores de referencia. Estos cambiarán más adelante.
        for (Int_t j=0; j<Muons_pt_->GetLen(); j++) {                                                             // Busco el electón que esté mas cerca, angularmente, del jet.
          if ( fabs(Muons_phi_->GetValue(j)-iJet_phi) <= PI ) {
            D[j] = sqrt(pow(Muons_eta_->GetValue(j)-iJet_eta,2)+pow(Muons_phi_->GetValue(j)-iJet_phi,2));
          } else { D[j] = sqrt(pow(Muons_eta_->GetValue(j)-iJet_eta,2)+pow(2*PI-fabs(Muons_phi_->GetValue(j)-iJet_phi),2));  }
        }
        TMath::Sort(Muons_pt_->GetLen(), D, Index, false);                                                        // TMath::Sort devuelve el ordenamiento a partir de ìndices, no de valores.
        for (Int_t j=0; j<Jets_mMuonMultiplicity->GetValue(i); j++) {
          if ( fabs(Muons_eta_->GetValue(Index[j])) < etaMax ) {
            if ( pow(Muons_fX_->GetValue(Index[j])-x_m,2) + pow(Muons_fY_->GetValue(Index[j])-y_m,2) + pow(Muons_fZ_->GetValue(Index[j])-z_m,2) <= 0.25 ) {
              h_Muons_fX_  -> Fill(Muons_fX_->GetValue(Index[j]));
              h_Muons_fY_  -> Fill(Muons_fY_->GetValue(Index[j]));
              h_Muons_fZ_  -> Fill(Muons_fZ_->GetValue(Index[j]));
              h__pTQuotient_Muon_Jet  -> Fill(Muons_pt_->GetValue(Index[j])/iJet_pT);
              h__eta_D__Muon_Jet -> Fill(fabs(Muons_eta_->GetValue(Index[j]) - Jets_eta_->GetValue(i)));  // Distancia en el ángulo ETA entre el Jet y su Muón.
              h__phi_D__Muon_Jet -> Fill(fabs(Muons_phi_->GetValue(Index[j]) - Jets_phi_->GetValue(i)));  // Distancia en el ángulo PHI entre el Jet y su Muón.
              h__D__Muon_Jet -> Fill(D[Index[j]]);                                                             // Distancia angular total entre el Jet y su Muón.
              if (Muons_pt_->GetValue(Index[j]) > pT) { Flag=true; pT=Muons_pt_->GetValue(Index[j]); }
              // printf(" Entrada : %i, Indice: %i, Distancia Angular: %f.\n", j, Index[j], D[Index[j]]);
            }
          }
        } // printf("\n");
        if ( iJet_pT <= 100.0 && Flag == true ) h__pTQuotient_1Muon_Jet -> Fill(pT/iJet_pT);              // Cociente_pT respecto al Muón más energético.
        else if ( Flag == true ) h__pTQuot100__1Muon_Jet -> Fill(pT/iJet_pT);
      } // if loop

      // Electrones.
      if (Jets_mElectronMultiplicity->GetValue(i) > 0) {   Int_t Index[100]; Float_t D[100]; Bool_t Flag=false; Float_t pT=0.0;
        for (Int_t j=0; j<Electrons_pt_->GetLen(); j++) {
          if ( fabs(Electrons_phi_->GetValue(j)-iJet_phi) <= PI ) {
            D[j] = sqrt(pow(Electrons_eta_->GetValue(j)-iJet_eta,2)+pow(Electrons_phi_->GetValue(j)-iJet_phi,2));
          } else { D[j] = sqrt(pow(Electrons_eta_->GetValue(j)-iJet_eta,2)+pow(2*PI-fabs(Electrons_phi_->GetValue(j)-iJet_phi),2));  }
        }
        TMath::Sort(Electrons_pt_->GetLen(), D, Index, false);
        for (Int_t j=0; j<Jets_mElectronMultiplicity->GetValue(i); j++) {
          if ( fabs(Electrons_eta_->GetValue(Index[j])) < etaMax ) {
            if ( pow(Electrons_fX_->GetValue(Index[j])-x_e,2) + pow(Electrons_fY_->GetValue(Index[j])-y_e,2) + pow(Electrons_fZ_->GetValue(Index[j])-z_e,2) <= 0.25 ) {
              h_Electrons_fX_  -> Fill(Electrons_fX_->GetValue(Index[j]));
              h_Electrons_fY_  -> Fill(Electrons_fY_->GetValue(Index[j]));
              h_Electrons_fZ_  -> Fill(Electrons_fZ_->GetValue(Index[j]));
              h__pTQuotient_Electron_Jet -> Fill(Electrons_pt_->GetValue(Index[j])/iJet_pT);
              h__eta_D__Electron_Jet -> Fill(fabs(Electrons_eta_->GetValue(Index[j]) - Jets_eta_->GetValue(i)));
              h__phi_D__Electron_Jet -> Fill(fabs(Electrons_phi_->GetValue(Index[j]) - Jets_phi_->GetValue(i)));
              h__D__Electron_Jet -> Fill(D[Index[j]]);
              if (Electrons_pt_->GetValue(Index[j]) > pT) { Flag=true; pT=Electrons_pt_->GetValue(Index[j]); }
            }
          }
        }
        if ( iJet_pT <= 100.0 && Flag == true ) h__pTQuotient_1Electron_Jet -> Fill(pT/iJet_pT);
        else if (Flag == true) h__pTQuot100__1Electron_Jet -> Fill(pT/iJet_pT);
      }
    } // for loop i


    // Multiplicidad de Jets en cada Evento. Se tomo p_T como criterio de selección.
    h_Jets__Multiplicity -> Fill(Jets_pt_->GetLen());
    // if (MultJet_04 > 0)  h_Jets_pT04__Multiplicity -> Fill(MultJet_04);  // Aqui llenamos los histogramas con la cantidad de jets,
    // if (MultJet_08 > 0)  h_Jets_pT08__Multiplicity -> Fill(MultJet_08);  // en cada evento, que cumple con tener p_T > x GeV.
    // if (MultJet_16 > 0)  h_Jets_pT16__Multiplicity -> Fill(MultJet_16);  // En otras palabras, estos son espectros de multiplicidad
    // if (MultJet_32 > 0)  h_Jets_pT32__Multiplicity -> Fill(MultJet_32);  // en funcion de distintos rangos de p_T.
    // if (MultJet_64 > 0)  h_Jets_pT64__Multiplicity -> Fill(MultJet_64);

    // Multiplicidad, != 0, de los Electrones, Fotones y Muones reconstruidos en cada Evento.
    if (Electrons_pt_->GetLen() != 0) h_Electrons__Multiplicity -> Fill(Electrons_pt_->GetLen());
    if (Photons_pt_->GetLen() != 0)   h_Photons__Multiplicity   -> Fill(Photons_pt_->GetLen());
    if (Muons_pt_->GetLen() != 0)     h_Muons__Multiplicity     -> Fill(Muons_pt_->GetLen());


      // printf("\t \t Dont worry. Evento %i hecho. =D \n\n", e);

  } // for loop e
  //###################################################################################################################################################################################


    printf("\t\t %i) Datos extraidos. \n", nprint++);


  // Guardamos nustros histogramas en el archivo root que nos interesa.
  // Muons
  // h_Muons_pt_  -> Write();
  // h_Muons_eta_ -> Write();
  h_Muons_fX_  -> Write();
  h_Muons_fY_  -> Write();
  h_Muons_fZ_  -> Write();
  // Electrons
  // h_Electrons_pt_  -> Write();
  // h_Electrons_eta_ -> Write();
  h_Electrons_fX_  -> Write();
  h_Electrons_fY_  -> Write();
  h_Electrons_fZ_  -> Write();
  // // Jets
  // h_Jets_pt_  -> Write();
  // h_Jets_eta_ -> Write();
  // Multiplicidades
  h_Muons__Multiplicity       -> Write();
  h_Photons__Multiplicity     -> Write();
  h_Electrons__Multiplicity-> Write();
  h_Jets__MuonMultiplicity      -> Write();
  h_Jets__PhotonMultiplicity    -> Write();
  h_Jets__ElectronMultiplicity  -> Write();
  h_Jets__Multiplicity_1Electron-> Write();
  h_Jets__ChaHad_Multiplicity   -> Write();
  h_Jets__NeuHad_Multiplicity   -> Write();
  h_Jets__Multiplicity      -> Write();
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
  h__pTQuotient_Muon_Jet        -> Write();
  h__pTQuotient_1Muon_Jet       -> Write();
  h__pTQuot100__1Muon_Jet       -> Write();
  h__pTQuotient_Electron_Jet -> Write();
  h__pTQuotient_1Electron_Jet-> Write();
  h__pTQuot100__1Electron_Jet-> Write();
  h_Jets__EnergyQuotient_ChaHad_Jet  -> Write();
  h_Jets__EnergyQuotient_NeuHad_Jet  -> Write();
  h_Jets__EnergyQuotient_Electron_Jet-> Write();
  h_Jets__EnergyQuotient_Photon_Jet  -> Write();
  h_Jets__EnergyQuotient_Muon_Jet    -> Write();
  // Distancias Angulares: eta, phi y total
  h__eta_D__Muon_Jet       -> Write();
  // h__eta_D__Photon_Jet     -> Write();
  h__eta_D__Electron_Jet-> Write();
  h__phi_D__Muon_Jet       -> Write();
  // h__phi_D__Photon_Jet     -> Write();
  h__phi_D__Electron_Jet-> Write();
  h__D__Muon_Jet       -> Write();
  // h__D__Photon_Jet     -> Write();
  h__D__Electron_Jet-> Write();
  h_Jets__D__Jet_Jet      -> Write();
  // h_Jets_pT04__D__Jet_Jet -> Write();
  // h_Jets_pT08__D__Jet_Jet -> Write();
  // h_Jets_pT16__D__Jet_Jet -> Write();
  // h_Jets_pT32__D__Jet_Jet -> Write();
  // h_Jets_pT64__D__Jet_Jet -> Write();


  // Cerramos y eliminamos los archivos abierto y creado.
  InputFile->Close();
  delete OutputFile;
  // new TBrowser();


    printf("\t\t %i) Análisis terminado, Son of a bitch!\n\n", nprint++);

}
