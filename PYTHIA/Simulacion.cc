NeutralHadronEnergy// PYTHIA is licenced under the GNU GPL v2 or later, see COPYING for details.

// Stdlib header file for input and output.
#include <iostream>
// Header file to access Pythia 8 program elements.
#include "Pythia8/Pythia.h"
// ROOT, for histogramming.
#include "TH1.h"
// ROOT, for interactive graphics.
#include "TVirtualPad.h"
#include "TApplication.h"
// ROOT, for saving file.
#include "TFile.h"

// The FastJet3.h header enables automatic initialisation of fastjet::PseudoJet objects from Pythia8 Particle and Vec4 objects,
// as well as advanced features such as access to (a copy of) the original Pythia 8 Particle directly from the PseudoJet,
// and fastjet selectors that make use of the Particle properties.
// See the extensive comments in the header file for further details and examples.
#include "Pythia8Plugins/FastJet3.h"
// Definido para poder utilizar información definida por el usuario.
#include "fastjet/MyInfo.h"

using namespace Pythia8;

//----------------------------------------------------------------------------------------------------------------
int main(int argc, char* argv[]) {   Float_t PI=3.1415927;

  // Create the ROOT application environment.
  TApplication theApp("hist", &argc, argv);
  // Create file on which histogram(s) can be saved.
  TFile* OutputFile = new TFile("/home/saksevul/T/PYTHIA/FastJet/ak5FJ-10.root", "RECREATE");
  // Histograms.
  // FastJet.
  TH1F* h_Jets_pt_         = new TH1F("Jets_pt_",  "Espectro de p_{T} de ak5FastJet; p_{T} [GeV]; Ocurrencia", 1200, 0, 2400);
  TH1F *h_Jets_eta_        = new TH1F("Jets_eta_", "Distribución en #eta de ak5FastJet; #eta; Ocurrencia", 599, -5.95, 5.95);
  TH1F *h_JetEnergy        = new TH1F("Jets_Energy", "Energ#acute{i}a de FastJets; Energ#acute{i}a [GeV]; Frecuencia", 1800, 0, 3600);
  TH1F *h_MuonEnergy       = new TH1F("Jets_MuonEnergy", "Energ#acute{i}a de Muones; Energ#acute{i}a [GeV]; Frecuencia", 1800, 0, 3600);
  TH1F *h_PhotonEnergy     = new TH1F("Jets_PhotonEnergy", "Energ#acute{i}a de Fotones; Energ#acute{i}a [GeV]; Frecuencia", 1800, 0, 3600);
  TH1F *h_ElectronEnergy   = new TH1F("Jets_ElectronEnergy", "Energ#acute{i}a de Electrones; Energ#acute{i}a [GeV]; Frecuencia", 1800, 0, 3600);
  TH1F *h_NeutralHadronEnergy = new TH1F("Jets_NeutralHadronEnergy", "Energ#acute{i}a de Hadrones Neutros; Energ#acute{i}a [GeV]; Frecuencia", 1800, 0, 3600);
  TH1F *h_ChargedHadronEnergy = new TH1F("Jets_ChargedHadronEnergy", "Energ#acute{i}a de Hadrones Cargados; Energ#acute{i}a [GeV]; Frecuencia", 1800, 0, 3600);
  // Multiplicidades
  TH1F* h_Jets__Multipicity= new TH1F("Jets__Multiplicity", "Multiplicidad, de ak5FastJet, por Evento; Multilicidad; Ocurrencia", 120, 0, 120);
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
  TH1F *h__D__Muon_Jet     = new TH1F("_D__Muon-Jet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del Muon al ak5FastJet; Valor; Frecuencia", 120, 0, 1.2);
  TH1F *h__D__Electron_Jet = new TH1F("_D__Electron-Jet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del Electron al ak5FastJet; Valor; Frecuencia", 120, 0, 1.2);
  // TH1F* h_Jets__D__Jet_Jet  = new TH1F("ak5FastJet__D__Jet-Jet", "Distancia angular #sqrt{(#Delta#phi_{ij})^{2} + (#Delta#eta_{ij})^{2}} del ak5FastJet_{i} al ak5FastJet_{j}, por Evento; Valor; Ocurrencia", 120, 0, 12);
  // Pdg Id().
  TH1I*h__Pdg_Id = new TH1I("Pdg_Id", "Partículas contenidas en los Jets; PDG id(); Frecuencia", 800, -4000, 4000);
  TH1I*h__OtherPdg_Id = new TH1I("OtherPdg_Id", "Partículas contenidas en los Jets; PDG id(); Frecuencia", 800, -4000, 4000);
  TH1I*h__JetMother = new TH1I("JetMother", "Madre de Jet; PDG id(); Frecuencia", 43, -21.5, 21.5);
  TH1I*h__OtherMother = new TH1I("OtherMother", "Madre de Jet distinta a Quark o Gluon; PDG id(); Frecuencia", 43, -21.5, 21.5);

  // Generator. Shorthand for event.
  Pythia pythia;
  Event& event = pythia.event;

  // // Soft QCD processes.
  // pythia.readString("SoftQCD:nonDiffractive = on");
  // pythia.readString("SoftQCD:singleDiffractive = on");
  // pythia.readString("SoftQCD:doubleDiffractive = on");
  // pythia.readString("PhaseSpace:pTHatMin = 1.0");
  // pythia.readString("PhaseSpace:pTHatMax = 1200.0");
  // pythia.readString("PhaseSpace:mHatMax = 1200.0");
  // pythia.readString("ParticleDecays:limitTau0 = On");
  // pythia.readString("ParticleDecays:tau0Max = 10.0");

  // Process selection.
  pythia.readString("HardQCD:all = on");
  pythia.readString("PhaseSpace:pTHatMin = 10.0");
  // pythia.readString("HardQCD:hardccbar = on");
  // pythia.readString("HardQCD:hardbbbar = on");
  // pythia.readString("HardQCD:3parton = on");
  pythia.readString("PromptPhoton:all = on");
  pythia.readString("WeakBosonExchange:all = on");
  pythia.readString("ParticleDecays:limitTau0 = On");
  pythia.readString("ParticleDecays:tau0Max = 10.0");

  // No event record printout.
  pythia.readString("Next:numberShowInfo = 0");
  pythia.readString("Next:numberShowProcess = 0");
  pythia.readString("Next:numberShowEvent = 0");

  // LHC initialization.
  pythia.readString("Beams:eCM = 7000.0");
  pythia.init();


  // Number of events, generated and listed ones (for jets).
  int nEvent    = 12000;
  printf("\n\n\n\t Numero de Eventos = %i \t pTHatMin = 10.0\n\n\t Salida:  ak5FJ-10.root \n\n\n\n", nEvent);
  // Select common parameters FastJet analyses.
  int    JCA    = -1;     // anti-kT= -1; C/A = 0; kT = 1.
  double R      = 0.5;    // Jet size.
  double pTMin  = 3.0;    // Min jet pT.
  double etaMax = 1.479;    // Pseudorapidity range of detector.
  int    select = 2;      // Which particles are included?
  int    massSet= 2;      // Which mass are they assumed to have?

  fastjet::JetDefinition jetDef(fastjet::genkt_algorithm, R, JCA);
  std::vector <fastjet::PseudoJet> fjInputs;  //
  // Set up FastJet jet finder. // generalised k_T algorithm.
  //fastjet::JetDefinition jetDef(algorithm, R);
  // there's no need for a pointer to the jetDef (it's a fairly small object)


  // Begin event loop. Generate event. Skip if error. Por Evento se refiere a una colisión o a un decaimiento.
  for (int iEvent = 0; iEvent < nEvent; ++iEvent) {    if (!pythia.next()) continue;

    // Begin FastJet analysis: extract particles from event record.
    fjInputs.resize(0);    Vec4   pTemp;    double mTemp;

    for (int i = 0; i < event.size(); ++i) if ( event[i].isFinal()) {      // Require visible/charged particles inside detector.
      if      (select >  2 &&  event[i].isNeutral() ) continue;
      else if (select == 2 && !event[i].isVisible() ) continue;   // Particle with strong or electric charge, or composed of ones having it.
      if (/*etaMax < 20. &&*/ abs(event[i].eta()) > etaMax ) continue;

      if ( abs(event[i].id()) == 13 && event[i].e() < 4.00 ) continue;
      else if ( abs(event[i].id()) == 22 && event[i].e() < 0.32) continue;
      else if ( abs(event[i].id()) == 11 && event[i].e() < 3.00) continue;
      else if ( abs(event[i].isNeutral()) && event[i].e() < 0.80) continue;
      else if ( abs(event[i].isCharged()) && event[i].e() < 0.40) continue;

      // Create a PseudoJet from the complete Pythia particle.
      fastjet::PseudoJet particleTemp = event[i];

      // Optionally modify mass and energy.
      pTemp = event[i].p();
      mTemp = event[i].m();
      if (massSet < 2) {
        mTemp = (massSet == 0 || event[i].id() == 22) ? 0. : 0.13957;
        pTemp.e( sqrt(pTemp.pAbs2() + mTemp*mTemp) );
        particleTemp.reset_momentum( pTemp.px(), pTemp.py(), pTemp.pz(), pTemp.e() );
      }

      // particleTemp.reset_momentum( event[i].px(), event[i].py(), event[i].pz(), event[i].e() );

      // Esto es para poder conocer índice del evento de cada constituyentes del Jet.
      particleTemp.set_user_info( new MyInfo( i ) );  // particleTemp son las partículas candidatas a formar parte del Jet.

      // Store acceptable particles as input to Fastjet.
      // Conversion to PseudoJet is performed automatically with the help of the code in FastJet3.h.
      fjInputs.push_back( particleTemp);  // Agrega un nuevo elemento al final del vector fjInputs.
    }

    // Run Fastjet algorithm and sort jets in pT order.
    vector <fastjet::PseudoJet> inclusiveJets, sortedJets;
    fastjet::ClusterSequence clustSeq(fjInputs, jetDef);
    inclusiveJets = clustSeq.inclusive_jets(pTMin);
    sortedJets    = sorted_by_pt(inclusiveJets);



    // #######################################################################################################################################################################
    // Esto ya es de mi propia cosecha.
    for (size_t i=0; i<sortedJets.size(); i++){   Bool_t FlagE=false, FlagM=false; Float_t JMpT = 0.0, pTE=0.0, pTM=0.0;  Int_t motherM, motherE; Int_t JMIndex;

      Float_t MuonEnergy = 0.0, PhotonEnergy = 0.0, ElectronEnergy = 0.0, NeutralHadronEnergy =0.0, ChargedHadronEnergy = 0.0;

      if ( abs(sortedJets[i].eta()) > etaMax ) continue;

      h_Jets_pt_ -> Fill(sortedJets[i].pt());
      h_Jets_eta_-> Fill(sortedJets[i].eta());

      // // Distancia Angular entre Jets de un mismo Evento.
      // for (size_t j=i+1; j<sortedJets.size(); j++) {
      //   if ( abs(sortedJets[i].phi_std()-sortedJets[j].phi_std()) <= PI ) {
      //     h_Jets__D__Jet_Jet -> Fill( sqrt(pow2(sortedJets[i].eta()-sortedJets[j].eta()) +  pow2(sortedJets[i].phi_std()-sortedJets[j].phi_std())) );
      //   } else {
      //     h_Jets__D__Jet_Jet -> Fill( sqrt(pow2(sortedJets[i].eta()-sortedJets[j].eta()) +  pow2(2*PI-abs(sortedJets[i].phi_std()-sortedJets[j].phi_std()))) );
      // } }-

      for (size_t j=0; j<sortedJets[i].constituents().size(); j++) {   Int_t JCIndex = sortedJets[i].constituents()[j].user_info<MyInfo>().Index(); // Event Index.

        // Para conocer el partón madre el Jet en función de su partícula más energética.
        if ( JMpT < sortedJets[i].constituents()[j].pt() ) {  JMpT = sortedJets[i].constituents()[j].pt();  JMIndex = event[JCIndex].mother1();
          while ( abs(event[JMIndex].id()) > 21 ) { JMIndex=event[JMIndex].mother1(); }
        }

        // Muons.
        if ( abs(event[JCIndex].id()) == 13 ) {  motherM=event[JCIndex].mother1();
          MuonEnergy = MuonEnergy + sortedJets[i].constituents()[j].E();
          if ( abs(event[JCIndex].eta()) < etaMax ) {
            if ( sortedJets[i].constituents()[j].pt() > pTM) { FlagM=true; pTM=sortedJets[i].constituents()[j].pt(); }  // Para obtener información del Muón màs energético.
          }
          while ( abs(event[motherM].id()) > 21 ) motherM=event[motherM].mother1();
          if ( abs(event[motherM].id()) == 21 ) {     h__pTQuotient21_Muon_Jet -> Fill ( sortedJets[i].constituents()[j].pt()/sortedJets[i].pt() );  }
          else if ( abs(event[motherM].id()) == 1 ) { h__pTQuotient01_Muon_Jet -> Fill ( sortedJets[i].constituents()[j].pt()/sortedJets[i].pt() );  }
          else if ( abs(event[motherM].id()) == 2 ) { h__pTQuotient02_Muon_Jet -> Fill ( sortedJets[i].constituents()[j].pt()/sortedJets[i].pt() );  }
          else if ( abs(event[motherM].id()) == 3 ) { h__pTQuotient03_Muon_Jet -> Fill ( sortedJets[i].constituents()[j].pt()/sortedJets[i].pt() );  }
          else if ( abs(event[motherM].id()) == 4 ) { h__pTQuotient04_Muon_Jet -> Fill ( sortedJets[i].constituents()[j].pt()/sortedJets[i].pt() );  }
          else if ( abs(event[motherM].id()) == 5 ) { h__pTQuotient05_Muon_Jet -> Fill ( sortedJets[i].constituents()[j].pt()/sortedJets[i].pt() );  }
          else {
            h__pTQuotientOt_Muon_Jet -> Fill ( sortedJets[i].constituents()[j].pt()/sortedJets[i].pt() );
            h__OtherMother -> Fill(event[motherM].id());
          }
        }

        // Photons.
        else if ( abs(event[JCIndex].id()) == 22 ) { PhotonEnergy = PhotonEnergy + sortedJets[i].constituents()[j].E(); }

        // Electrons.
        else if ( abs(event[JCIndex].id()) == 11 ) {  motherE=event[JCIndex].mother1();
          ElectronEnergy = ElectronEnergy + sortedJets[i].constituents()[j].E();
          if ( abs(event[JCIndex].eta()) < etaMax ) {
            if ( sortedJets[i].constituents()[j].pt() > pTE) { FlagE=true; pTE=sortedJets[i].constituents()[j].pt(); }
          }
          while ( abs(event[motherE].id()) > 21 ) motherE=event[motherE].mother1();
          // const char * nombre; nombre=event[motherE].name().c_str();
          // printf(" Madre final de este Electron = %s.\n", nombre);
          if ( abs(event[motherE].id()) == 21 ) {     h__pTQuotient21_Electron_Jet -> Fill ( sortedJets[i].constituents()[j].pt()/sortedJets[i].pt() );  }
          else if ( abs(event[motherE].id()) == 1 ) { h__pTQuotient01_Electron_Jet -> Fill ( sortedJets[i].constituents()[j].pt()/sortedJets[i].pt() );  }
          else if ( abs(event[motherE].id()) == 2 ) { h__pTQuotient02_Electron_Jet -> Fill ( sortedJets[i].constituents()[j].pt()/sortedJets[i].pt() );  }
          else if ( abs(event[motherE].id()) == 3 ) { h__pTQuotient03_Electron_Jet -> Fill ( sortedJets[i].constituents()[j].pt()/sortedJets[i].pt() );  }
          else if ( abs(event[motherE].id()) == 4 ) { h__pTQuotient04_Electron_Jet -> Fill ( sortedJets[i].constituents()[j].pt()/sortedJets[i].pt() );  }
          else if ( abs(event[motherE].id()) == 5 ) { h__pTQuotient05_Electron_Jet -> Fill ( sortedJets[i].constituents()[j].pt()/sortedJets[i].pt() );  }
          else {
            h__pTQuotientOt_Electron_Jet -> Fill ( sortedJets[i].constituents()[j].pt()/sortedJets[i].pt() );
            h__OtherMother -> Fill(event[motherE].id());
          }
        }

        // Neutral Hadrons.
        else if ( event[JCIndex].isNeutral() ) NeutralHadronEnergy = NeutralHadronEnergy + sortedJets[i].constituents()[j].E();
        // Charged Hadrons.
        else if ( event[JCIndex].isCharged() ) ChargedHadronEnergy = ChargedHadronEnergy + sortedJets[i].constituents()[j].E();
        //Other Particles.
        else h__OtherPdg_Id -> Fill(event[JCIndex].id());

        // Pdg Id().
        h__Pdg_Id -> Fill(event[JCIndex].id());
      } // j for loop.  Jet Constituents.


      // Energies.
      Float_t JetEnergy = MuonEnergy + PhotonEnergy + ElectronEnergy + NeutralHadronEnergy + ChargedHadronEnergy;

      h_JetEnergy -> Fill (JetEnergy);

      // Cociente de la energia de las partículas respecto a al E del Jet. Y Multiplicidad de las particulas en cada Jet.
      if (MuonEnergy > 0.0) { h_MuonEnergy -> Fill(MuonEnergy);
        h_Jets__EnergyQuotient_Muon_Jet -> Fill(MuonEnergy/JetEnergy);
        if          ( JetEnergy<100) {  h_Jets__EnergyQuot_Muon_Jet100    -> Fill(MuonEnergy/JetEnergy)  }
        else if (100<=JetEnergy<200) {  h_Jets__EnergyQuot_Muon_100Jet200 -> Fill(MuonEnergy/JetEnergy)  }
        else if (200<=JetEnergy<300) {  h_Jets__EnergyQuot_Muon_200Jet300 -> Fill(MuonEnergy/JetEnergy)  }
        else if (300<=JetEnergy<400) {  h_Jets__EnergyQuot_Muon_300Jet400 -> Fill(MuonEnergy/JetEnergy)  }
        else if (400<=JetEnergy<500) {  h_Jets__EnergyQuot_Muon_400Jet500 -> Fill(MuonEnergy/JetEnergy)  }
        else if (500<=JetEnergy<600) {  h_Jets__EnergyQuot_Muon_500Jet600 -> Fill(MuonEnergy/JetEnergy)  }
        else if (600<=JetEnergy<700) {  h_Jets__EnergyQuot_Muon_600Jet700 -> Fill(MuonEnergy/JetEnergy)  }
        else if (700<=JetEnergy<800) {  h_Jets__EnergyQuot_Muon_700Jet800 -> Fill(MuonEnergy/JetEnergy)  }
        else if (800<=JetEnergy<900) {  h_Jets__EnergyQuot_Muon_800Jet900 -> Fill(MuonEnergy/JetEnergy)  }
        else if (900<=JetEnergy<1000){  h_Jets__EnergyQuot_Muon_900Jet1000-> Fill(MuonEnergy/JetEnergy)  }
        else                         {  h_Jets__EnergyQuot_Muon_1000Jet   -> Fill(MuonEnergy/JetEnergy)  }
      }
      if (PhotonEnergy > 0.0) { h_PhotonEnergy -> Fill(PhotonEnergy);
        h_Jets__EnergyQuotient_Photon_Jet -> Fill(PhotonEnergy/JetEnergy);
        if          ( JetEnergy<100) {  h_Jets__EnergyQuot_Photon_Jet100    -> Fill(PhotonEnergy/JetEnergy)  }
        else if (100<=JetEnergy<200) {  h_Jets__EnergyQuot_Photon_100Jet200 -> Fill(PhotonEnergy/JetEnergy)  }
        else if (200<=JetEnergy<300) {  h_Jets__EnergyQuot_Photon_200Jet300 -> Fill(PhotonEnergy/JetEnergy)  }
        else if (300<=JetEnergy<400) {  h_Jets__EnergyQuot_Photon_300Jet400 -> Fill(PhotonEnergy/JetEnergy)  }
        else if (400<=JetEnergy<500) {  h_Jets__EnergyQuot_Photon_400Jet500 -> Fill(PhotonEnergy/JetEnergy)  }
        else if (500<=JetEnergy<600) {  h_Jets__EnergyQuot_Photon_500Jet600 -> Fill(PhotonEnergy/JetEnergy)  }
        else if (600<=JetEnergy<700) {  h_Jets__EnergyQuot_Photon_600Jet700 -> Fill(PhotonEnergy/JetEnergy)  }
        else if (700<=JetEnergy<800) {  h_Jets__EnergyQuot_Photon_700Jet800 -> Fill(PhotonEnergy/JetEnergy)  }
        else if (800<=JetEnergy<900) {  h_Jets__EnergyQuot_Photon_800Jet900 -> Fill(PhotonEnergy/JetEnergy)  }
        else if (900<=JetEnergy<1000){  h_Jets__EnergyQuot_Photon_900Jet1000-> Fill(PhotonEnergy/JetEnergy)  }
        else                         {  h_Jets__EnergyQuot_Photon_1000Jet   -> Fill(PhotonEnergy/JetEnergy)  }
      }
      if (ElectronEnergy > 0.0) { h_ElectronEnergy -> Fill(ElectronEnergy);
        h_Jets__EnergyQuotient_Electron_Jet -> Fill(ElectronEnergy/JetEnergy);
        if          ( JetEnergy<100) {  h_Jets__EnergyQuot_Electron_Jet100    -> Fill(ElectronEnergy/JetEnergy)  }
        else if (100<=JetEnergy<200) {  h_Jets__EnergyQuot_Electron_100Jet200 -> Fill(ElectronEnergy/JetEnergy)  }
        else if (200<=JetEnergy<300) {  h_Jets__EnergyQuot_Electron_200Jet300 -> Fill(ElectronEnergy/JetEnergy)  }
        else if (300<=JetEnergy<400) {  h_Jets__EnergyQuot_Electron_300Jet400 -> Fill(ElectronEnergy/JetEnergy)  }
        else if (400<=JetEnergy<500) {  h_Jets__EnergyQuot_Electron_400Jet500 -> Fill(ElectronEnergy/JetEnergy)  }
        else if (500<=JetEnergy<600) {  h_Jets__EnergyQuot_Electron_500Jet600 -> Fill(ElectronEnergy/JetEnergy)  }
        else if (600<=JetEnergy<700) {  h_Jets__EnergyQuot_Electron_600Jet700 -> Fill(ElectronEnergy/JetEnergy)  }
        else if (700<=JetEnergy<800) {  h_Jets__EnergyQuot_Electron_700Jet800 -> Fill(ElectronEnergy/JetEnergy)  }
        else if (800<=JetEnergy<900) {  h_Jets__EnergyQuot_Electron_800Jet900 -> Fill(ElectronEnergy/JetEnergy)  }
        else if (900<=JetEnergy<1000){  h_Jets__EnergyQuot_Electron_900Jet1000-> Fill(ElectronEnergy/JetEnergy)  }
        else                         {  h_Jets__EnergyQuot_Electron_1000Jet   -> Fill(ElectronEnergy/JetEnergy)  }
      }
      if (NeutralHadronEnergy > 0.0) { h_NeutralHadronEnergy -> Fill(NeutralHadronEnergy);
        h_Jets__EnergyQuotient_NeutralHad_Jet -> Fill(NeutralHadronEnergy/JetEnergy);
        if          ( JetEnergy<100) {  h_Jets__EnergyQuot_NeutralHad_Jet100    -> Fill(NeutralHadronEnergy/JetEnergy)  }
        else if (100<=JetEnergy<200) {  h_Jets__EnergyQuot_NeutralHad_100Jet200 -> Fill(NeutralHadronEnergy/JetEnergy)  }
        else if (200<=JetEnergy<300) {  h_Jets__EnergyQuot_NeutralHad_200Jet300 -> Fill(NeutralHadronEnergy/JetEnergy)  }
        else if (300<=JetEnergy<400) {  h_Jets__EnergyQuot_NeutralHad_300Jet400 -> Fill(NeutralHadronEnergy/JetEnergy)  }
        else if (400<=JetEnergy<500) {  h_Jets__EnergyQuot_NeutralHad_400Jet500 -> Fill(NeutralHadronEnergy/JetEnergy)  }
        else if (500<=JetEnergy<600) {  h_Jets__EnergyQuot_NeutralHad_500Jet600 -> Fill(NeutralHadronEnergy/JetEnergy)  }
        else if (600<=JetEnergy<700) {  h_Jets__EnergyQuot_NeutralHad_600Jet700 -> Fill(NeutralHadronEnergy/JetEnergy)  }
        else if (700<=JetEnergy<800) {  h_Jets__EnergyQuot_NeutralHad_700Jet800 -> Fill(NeutralHadronEnergy/JetEnergy)  }
        else if (800<=JetEnergy<900) {  h_Jets__EnergyQuot_NeutralHad_800Jet900 -> Fill(NeutralHadronEnergy/JetEnergy)  }
        else if (900<=JetEnergy<1000){  h_Jets__EnergyQuot_NeutralHad_900Jet1000-> Fill(NeutralHadronEnergy/JetEnergy)  }
        else                         {  h_Jets__EnergyQuot_NeutralHad_1000Jet   -> Fill(NeutralHadronEnergy/JetEnergy)  }
      }
      if (ChargedHadronEnergy > 0.0) { h_ChargedHadronEnergy -> Fill(ChargedHadronEnergy);
        h_Jets__EnergyQuotient_ChargedHad_Jet -> Fill(ChargedHadronEnergy/JetEnergy);
        if          ( JetEnergy<100) {  h_Jets__EnergyQuot_ChargedHad_Jet100    -> Fill(ChargedHadronEnergy/JetEnergy)  }
        else if (100<=JetEnergy<200) {  h_Jets__EnergyQuot_ChargedHad_100Jet200 -> Fill(ChargedHadronEnergy/JetEnergy)  }
        else if (200<=JetEnergy<300) {  h_Jets__EnergyQuot_ChargedHad_200Jet300 -> Fill(ChargedHadronEnergy/JetEnergy)  }
        else if (300<=JetEnergy<400) {  h_Jets__EnergyQuot_ChargedHad_300Jet400 -> Fill(ChargedHadronEnergy/JetEnergy)  }
        else if (400<=JetEnergy<500) {  h_Jets__EnergyQuot_ChargedHad_400Jet500 -> Fill(ChargedHadronEnergy/JetEnergy)  }
        else if (500<=JetEnergy<600) {  h_Jets__EnergyQuot_ChargedHad_500Jet600 -> Fill(ChargedHadronEnergy/JetEnergy)  }
        else if (600<=JetEnergy<700) {  h_Jets__EnergyQuot_ChargedHad_600Jet700 -> Fill(ChargedHadronEnergy/JetEnergy)  }
        else if (700<=JetEnergy<800) {  h_Jets__EnergyQuot_ChargedHad_700Jet800 -> Fill(ChargedHadronEnergy/JetEnergy)  }
        else if (800<=JetEnergy<900) {  h_Jets__EnergyQuot_ChargedHad_800Jet900 -> Fill(ChargedHadronEnergy/JetEnergy)  }
        else if (900<=JetEnergy<1000){  h_Jets__EnergyQuot_ChargedHad_900Jet1000-> Fill(ChargedHadronEnergy/JetEnergy)  }
        else                         {  h_Jets__EnergyQuot_ChargedHad_1000Jet   -> Fill(ChargedHadronEnergy/JetEnergy)  }
      }
      // Pdg Id().
      h__JetMother -> Fill(event[JMIndex].id());
    } // i for loop.  Event Jets.

    h_Jets__Multipicity -> Fill(sortedJets.size());

  }  // End of Event loop.

// #######################################################################################################################################################################


  // Statistics. Histograms.
  // pythia.stat();

  h_Jets_pt_        -> Write();
  h_Jets_eta_       -> Write();
  h_JetEnergy       -> Write();
  h_JetMultipicity-> Write();
  h_MuonEnergy      -> Write();
  h_PhotonEnergy    -> Write();
  h_ElectronEnergy  -> Write();
  h_NeutralHadronEnergy-> Write();
  h_ChargedHadronEnergy-> Write();

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

  // h_Jets__D__Jet_Jet -> Write();

  // Madre de Jets.
  h__OtherPdg_Id -> Write();
  h__Pdg_Id      -> Write();
  h__OtherMother -> Write();
  h__JetMother   -> Write();

  // Done.
  delete OutputFile;
  return 0;
}
