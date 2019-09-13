void Analisis_Limits() {   Float_t PI=TMath::Pi(); Int_t nprint=1;

  //Abrimos los archivos que nos interesan y los árboles que queremos leer.
  TFile *InputFile = new TFile("/media/saksevul/Pawahtun/CMS_Run2011A/BTag_20000/0001.root");
  TTree *Eventos = (TTree*)InputFile->Get("Events");

  //Crear el archivo de salida que queremos. Tiene que ir después del imputFile.
  TFile* OutputFile = new TFile("/home/saksevul/T/OpenData/BTag_20000/ak5PF_Limits-0001.root", "RECREATE");


    printf("\n JCA: ak5PF_Limits, InputFile: BTag_20000/0001.root. \n\n\t %i) Archivos abiertos. \n", nprint++);


  // Muones
  TLeaf *Muons_pt_ = Eventos->GetLeaf("recoMuons_muons__RECO.obj.pt_" );
  TLeaf *Muons_eta_= Eventos->GetLeaf("recoMuons_muons__RECO.obj.eta_");
  // Photons
  TLeaf *Photons_pt_ = Eventos->GetLeaf("recoPhotons_photons__RECO.obj.pt_" );
  TLeaf *Photons_eta_= Eventos->GetLeaf("recoPhotons_photons__RECO.obj.eta_");
  // Electronnes
  TLeaf *Electronns_pt_ = Eventos->GetLeaf("recoGsfElectrons_gsfElectrons__RECO.obj.pt_" );
  TLeaf *Electronns_eta_= Eventos->GetLeaf("recoGsfElectrons_gsfElectrons__RECO.obj.eta_");
  //ak5PFJets
  TLeaf *ak5PFJets_pt_ = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.pt_" );
  TLeaf *ak5PFJets_eta_= Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.eta_");
  TLeaf *PileupEnergy  = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.mPileupEnergy");
  TLeaf *ChargedHadronEnergy = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mChargedHadronEnergy");
  TLeaf *NeutralHadronEnergy = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mNeutralHadronEnergy");
  TLeaf *ElectronEnergy      = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mElectronEnergy");
  TLeaf *PhotonEnergy        = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mPhotonEnergy");
  TLeaf *MuonEnergy          = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mMuonEnergy");
  TLeaf *ChargedHadronMultiplicity = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mChargedHadronMultiplicity");
  TLeaf *NeutralHadronMultiplicity = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mNeutralHadronMultiplicity");
  TLeaf *PhotonMultiplicity        = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mPhotonMultiplicity");
  TLeaf *ElectronMultiplicity      = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mElectronMultiplicity");
  TLeaf *MuonMultiplicity          = Eventos->GetLeaf("recoPFJets_ak5PFJets__RECO.obj.m_specific.mMuonMultiplicity");


    printf("\t %i) Ramas leidas. \n", nprint++);


  // Muons
  TH1F *h_Muons_pt_ = new TH1F("Muons_pt_",  "recoMuons_muons__RECO.obj.pt_; p_{T} [GeV]; Frecuencia", 1152, 0, 48);
  TH1F *h_Muons_eta_= new TH1F("Muons_eta_", "recoMuones_muons__RECO.obj.eta_; #eta; Frecuencia", 599, -5.99, 5.99);
  // Photons
  TH1F *h_Photons_pt_ = new TH1F("Photons_pt_",  "recoPhotons_photons__RECO.obj.pt_s; p_{T} [GeV]; Frecuencia", 288, 0, 12);
  TH1F *h_Photons_eta_= new TH1F("Photons_eta_", "recoPhotons_photons__RECO.obj.eta_; #eta; Frecuencia", 599, -5.99, 5.99);
  // Electronns
  TH1F *h_Electronns_pt_ = new TH1F("Electrons_pt_",  "recoGsfElectrons_gsfElectrons__RECO.obj.pt_; p_{T} [GeV]; Frecuencia", 864, 0, 36);
  TH1F *h_Electronns_eta_= new TH1F("Electrons_eta_", "recoGsfElectrons_gsfElectrons__RECO.obj.eta_; #eta; Frecuencia", 599, -5.99, 5.99);
  // ak5PFJets
  TH1F *h_Jets_pt_ = new TH1F("Jets_pt_",  "recoPFJets_ak5PFJets__RECO.obj.pt_; p_{T} [GeV]; Frecuencia", 1536, 0, 64);
  TH1F *h_Jets_eta_= new TH1F("Jets_eta_", "recoPFJets_PFJets__RECO.obj.eta_; #eta; Frecuencia", 599, -5.99, 5.99);
  TH1F *h_JetEnergy           = new TH1F("Jets_JetEnergy", "Energ#acute{i}a de ak5PFJets; Energ#acute{i}a [GeV]; Frecuencia", 2000, 0, 30);
  TH1F *h_MuonEnergy          = new TH1F("Jets_MuonEnergy", "recoPFJets_ak5PFJets__RECO.obj.m_specific.mMuonEnergy; Energ#acute{i}a [GeV]; Frecuencia", 500, 0, 10);
  TH1F *h_PhotonEnergy        = new TH1F("Jets_PhotonEnergy", "recoPFJets_ak5PFJets__RECO.obj.m_specific.mPhotonEnergy; Energ#acute{i}a [GeV]; Frecuencia", 1000, 0, 10);
  TH1F *h_ElectronEnergy      = new TH1F("Jets_ElectronEnergy", "recoPFJets_ak5PFJets__RECO.obj.m_specific.mElectronEnergy; Energ#acute{i}a [GeV]; Frecuencia", 1000, 0, 10);
  TH1F *h_NeutralHadEnergy = new TH1F("Jets_NeutralHadronEnergy", "recoPFJets_ak5PFJets__RECO.obj.m_specific.mNeutralHadronEnergy; Energ#acute{i}a [GeV]; Frecuencia", 1500, 0, 20);
  TH1F *h_ChargedHadEnergy = new TH1F("Jets_ChargedHadronEnergy", "recoPFJets_ak5PFJets__RECO.obj.m_specific.mChargedHadronEnergy; Energ#acute{i}a [GeV]; Frecuencia", 1500, 0, 20);

  TH1F *h_1ChargedHadEnergy = new TH1F("Jets_1ChargedHadronEnergy", "recoPFJets_ak5PFJets__RECO.obj.m_specific.mChargedHadronEnergy; Energ#acute{i}a [GeV]; Frecuencia", 1500, 0, 20);
  TH1F *h_1NeutralHadEnergy = new TH1F("Jets_1NeutralHadronEnergy", "recoPFJets_ak5PFJets__RECO.obj.m_specific.mNeutralHadronEnergy; Energ#acute{i}a [GeV]; Frecuencia", 1500, 0, 20);
  TH1F *h_1ElectronEnergy      = new TH1F("Jets_1ElectronEnergy", "recoPFJets_ak5PFJets__RECO.obj.m_specific.mElectronEnergy; Energ#acute{i}a [GeV]; Frecuencia", 1000, 0, 10);
  TH1F *h_1PhotonEnergy        = new TH1F("Jets_1PhotonEnergy", "recoPFJets_ak5PFJets__RECO.obj.m_specific.mPhotonEnergy; Energ#acute{i}a [GeV]; Frecuencia", 1000, 0, 10);
  TH1F *h_1MuonEnergy          = new TH1F("Jets_1MuonEnergy", "recoPFJets_ak5PFJets__RECO.obj.m_specific.mMuonEnergy; Energ#acute{i}a [GeV]; Frecuencia", 500, 0, 10);

  TH1F *h_nChargedHadEnergy = new TH1F("Jets_nChargedHadronEnergy", "recoPFJets_ak5PFJets__RECO.obj.m_specific.mChargedHadronEnergy; Energ#acute{i}a [GeV]; Frecuencia", 1500, 0, 20);
  TH1F *h_nNeutralHadEnergy = new TH1F("Jets_nNeutralHadronEnergy", "recoPFJets_ak5PFJets__RECO.obj.m_specific.mNeutralHadronEnergy; Energ#acute{i}a [GeV]; Frecuencia", 1500, 0, 20);
  TH1F *h_nElectronEnergy      = new TH1F("Jets_nElectronEnergy", "recoPFJets_ak5PFJets__RECO.obj.m_specific.mElectronEnergy; Energ#acute{i}a [GeV]; Frecuencia", 1000, 0, 10);
  TH1F *h_nPhotonEnergy        = new TH1F("Jets_nPhotonEnergy", "recoPFJets_ak5PFJets__RECO.obj.m_specific.mPhotonEnergy; Energ#acute{i}a [GeV]; Frecuencia", 1000, 0, 10);
  TH1F *h_nMuonEnergy          = new TH1F("Jets_nMuonEnergy", "recoPFJets_ak5PFJets__RECO.obj.m_specific.mMuonEnergy; Energ#acute{i}a [GeV]; Frecuencia", 500, 0, 10);


    printf("\t %i) Histogramas creados. \n", nprint++);


  Float_t etaMax = 1.479;


  //##############################################################################################################################
  // Hacemos un loop respecto a todo el conjunto de datos de interés.
  for (Int_t e=0; e<Eventos->GetEntries(); e++) {

    Muons_pt_ ->GetBranch()->GetEntry(e);  Photons_pt_ ->GetBranch()->GetEntry(e);  Electronns_pt_ ->GetBranch()->GetEntry(e);  ak5PFJets_pt_ ->GetBranch()->GetEntry(e);
    Muons_eta_->GetBranch()->GetEntry(e);  Photons_eta_->GetBranch()->GetEntry(e);  Electronns_eta_->GetBranch()->GetEntry(e);  ak5PFJets_eta_->GetBranch()->GetEntry(e);

    PileupEnergy -> GetBranch()->GetEntry(e);
    ChargedHadronEnergy -> GetBranch()->GetEntry(e); ChargedHadronMultiplicity -> GetBranch()->GetEntry(e);
    NeutralHadronEnergy -> GetBranch()->GetEntry(e); NeutralHadronMultiplicity -> GetBranch()->GetEntry(e);
    ElectronEnergy      -> GetBranch()->GetEntry(e); ElectronMultiplicity      -> GetBranch()->GetEntry(e);
    PhotonEnergy        -> GetBranch()->GetEntry(e); PhotonMultiplicity        -> GetBranch()->GetEntry(e);
    MuonEnergy          -> GetBranch()->GetEntry(e); MuonMultiplicity          -> GetBranch()->GetEntry(e);


    for (Int_t i=0; i<Muons_pt_->GetLen(); i++) {
      if ( fabs(Muons_eta_->GetValue(i)) > etaMax ) continue;
        h_Muons_pt_ -> Fill(Muons_pt_ ->GetValue(i));
        h_Muons_eta_-> Fill(Muons_eta_->GetValue(i));
    }

    for (Int_t i=0; i<Photons_pt_->GetLen(); i++) {
      if ( fabs(Photons_eta_->GetValue(i)) > etaMax ) continue;
        h_Photons_pt_ -> Fill(Photons_pt_ ->GetValue(i));
        h_Photons_eta_-> Fill(Photons_eta_->GetValue(i));
    }

    for (Int_t i=0; i<Electronns_pt_->GetLen(); i++) {
      if ( fabs(Electronns_eta_->GetValue(i)) > etaMax ) continue;
        h_Electronns_pt_ -> Fill(Electronns_pt_ ->GetValue(i));
        h_Electronns_eta_-> Fill(Electronns_eta_->GetValue(i));
    }

    for (Int_t i=0; i<ak5PFJets_pt_->GetLen(); i++) {
      if ( fabs(ak5PFJets_eta_->GetValue(i)) > etaMax-0.5 ) continue;

        Float_t JetEnergy = ChargedHadronEnergy->GetValue(i) + NeutralHadronEnergy->GetValue(i) + ElectronEnergy->GetValue(i) + PhotonEnergy->GetValue(i) + MuonEnergy->GetValue(i);

        h_Jets_pt_ -> Fill(ak5PFJets_pt_ ->GetValue(i));
        h_Jets_eta_-> Fill(ak5PFJets_eta_->GetValue(i));
        h_JetEnergy     -> Fill( JetEnergy );

        if ( ChargedHadronMultiplicity->GetValue(i) != 0 ) h_ChargedHadEnergy -> Fill(ChargedHadronEnergy->GetValue(i));
        if ( NeutralHadronMultiplicity->GetValue(i) != 0 ) h_NeutralHadEnergy -> Fill(NeutralHadronEnergy->GetValue(i));
        if ( ElectronMultiplicity->GetValue(i) != 0 )      h_ElectronEnergy -> Fill(ElectronEnergy->GetValue(i));
        if ( PhotonMultiplicity->GetValue(i) != 0 )        h_PhotonEnergy -> Fill(PhotonEnergy->GetValue(i));
        if ( MuonMultiplicity->GetValue(i) != 0 )          h_MuonEnergy -> Fill(MuonEnergy->GetValue(i));

        if ( ChargedHadronMultiplicity->GetValue(i) == 1 ) h_1ChargedHadEnergy -> Fill(ChargedHadronEnergy->GetValue(i));
        if ( NeutralHadronMultiplicity->GetValue(i) == 1 ) h_1NeutralHadEnergy -> Fill(NeutralHadronEnergy->GetValue(i));
        if ( ElectronMultiplicity->GetValue(i) == 1 )      h_1ElectronEnergy -> Fill(ElectronEnergy->GetValue(i));
        if ( PhotonMultiplicity->GetValue(i) == 1 )        h_1PhotonEnergy -> Fill(PhotonEnergy->GetValue(i));
        if ( MuonMultiplicity->GetValue(i) == 1 )          h_1MuonEnergy -> Fill(MuonEnergy->GetValue(i));

        if ( ChargedHadronMultiplicity->GetValue(i) != 0 ) h_nChargedHadEnergy -> Fill( ChargedHadronEnergy->GetValue(i) / ChargedHadronMultiplicity->GetValue(i) );
        if ( NeutralHadronMultiplicity->GetValue(i) != 0 ) h_nNeutralHadEnergy -> Fill( NeutralHadronEnergy->GetValue(i) / NeutralHadronMultiplicity->GetValue(i) );
        if ( ElectronMultiplicity->GetValue(i) != 0 )      h_nElectronEnergy -> Fill( ElectronEnergy->GetValue(i) / ElectronMultiplicity->GetValue(i) );
        if ( PhotonMultiplicity->GetValue(i) != 0 )        h_nPhotonEnergy -> Fill( PhotonEnergy->GetValue(i) / PhotonMultiplicity->GetValue(i) );
        if ( MuonMultiplicity->GetValue(i) != 0 )          h_nMuonEnergy -> Fill( MuonEnergy->GetValue(i) / MuonMultiplicity->GetValue(i) );
    }

  } // for loop e
  //##############################################################################################################################


    printf("\t %i) Datos extraidos. \n", nprint++);


  // Guardamos nustros histogramas en el archivo root que nos interesa.
  // Muons
  h_Muons_pt_ -> Write();
  h_Muons_eta_-> Write();
  // Photons
  h_Photons_pt_ -> Write();
  h_Photons_eta_-> Write();
  // Electronns
  h_Electronns_pt_ -> Write();
  h_Electronns_eta_-> Write();
  // ak5PFJets
  h_Jets_pt_ -> Write();
  h_Jets_eta_-> Write();
  h_JetEnergy     -> Write();
  h_MuonEnergy       -> Write();
  h_1MuonEnergy      -> Write();
  h_nMuonEnergy      -> Write();
  h_PhotonEnergy     -> Write();
  h_1PhotonEnergy    -> Write();
  h_nPhotonEnergy    -> Write();
  h_ElectronEnergy   -> Write();
  h_1ElectronEnergy  -> Write();
  h_nElectronEnergy  -> Write();
  h_NeutralHadEnergy -> Write();
  h_1NeutralHadEnergy-> Write();
  h_nNeutralHadEnergy-> Write();
  h_ChargedHadEnergy -> Write();
  h_1ChargedHadEnergy-> Write();
  h_nChargedHadEnergy-> Write();

  // Cerramos y eliminamos los archivos abierto y creado.
  InputFile->Close();
  delete OutputFile;


    printf("\t %i) Análisis terminado, Son of a bitch!\n\n", nprint++);

}
