// PYTHIA is licenced under the GNU GPL v2 or later, see COPYING for details.

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
int main(int argc, char* argv[]) {   // Float_t PI=3.1415927;

  // Create the ROOT application environment.
  TApplication theApp("hist", &argc, argv);
  // Create file on which histogram(s) can be saved.
  TFile* OutputFile = new TFile("/home/saksevul/T/PYTHIA/FastJet/ak5FJ-2.root", "RECREATE"); // initial pT Hat Minimum (ver y/o editar Master Macro y ciclo for pTHM, 6 en total).
  // Histograms.
  // FastJet.
  TH1F* h_Jets_pt_         = new TH1F("Jets_pt_",  "Espectro de p_{T} de ak5FastJet; p_{T} [GeV]; Ocurrencia", 1200, 0, 2400);
  TH1F *h_Jets_eta_        = new TH1F("Jets_eta_", "Distribución en #eta de ak5FastJet; #eta; Ocurrencia", 599, -5.95, 5.95);
  TH1F *h_Jets__Energy     = new TH1F("Jets_Energy", "Energ#acute{i}a de FastJets; Energ#acute{i}a [GeV]; Frecuencia", 1800, 0, 3600);
  TH1F *h_MuonEnergy       = new TH1F("Jets_MuonEnergy", "Energ#acute{i}a de Muones; Energ#acute{i}a [GeV]; Frecuencia", 1800, 0, 3600);
  TH1F *h_PhotonEnergy     = new TH1F("Jets_PhotonEnergy", "Energ#acute{i}a de Fotones; Energ#acute{i}a [GeV]; Frecuencia", 1800, 0, 3600);
  TH1F *h_ElectronEnergy   = new TH1F("Jets_ElectronEnergy", "Energ#acute{i}a de Electrones; Energ#acute{i}a [GeV]; Frecuencia", 1800, 0, 3600);
  TH1F *h_NeutralHadEnergy = new TH1F("Jets_NeutralHadEnergy", "Energ#acute{i}a de Hadrones Neutros; Energ#acute{i}a [GeV]; Frecuencia", 1800, 0, 3600);
  TH1F *h_ChargedHadEnergy = new TH1F("Jets_ChargedHadEnergy", "Energ#acute{i}a de Hadrones Cargados; Energ#acute{i}a [GeV]; Frecuencia", 1800, 0, 3600);
  // Multiplicidades
  TH1F* h_Jets__Multiplicity           = new TH1F("Jets__Multiplicity", "Multiplicidad, de ak5FastJet por Evento; Multilicidad; Frecuencia", 120, 0, 120);
  TH1F *h_Jets__MuonMultiplicity       = new TH1F("Jets_Multiplicity__Muon", "Multiplicidad, != 0, de Muones en cada ak5FastJet; Multiplicidad Muon; Frecuencia", 120, 0, 120);
  TH1F *h_Jets__PhotonMultiplicity     = new TH1F("Jets_Multiplicity__Photon", "Multiplicidad, != 0, de Fotones en cada ak5FastJet; Multiplicidad Foton; Frecuencia", 120, 0, 120);
  TH1F *h_Jets__ElectronMultiplicity   = new TH1F("Jets_Multiplicity__Electron", "Multiplicidad, != 0, de Electrones en cada ak5FastJet; Multiplicidad Electron; Frecuencia", 120, 0, 120);
  TH1F *h_Jets__NeutralHad_Multiplicity= new TH1F("Jets_Multiplicity__NeutralHad", "Multiplicidad, != 0, de Hadrones Neutros en cada ak5FastJet; Multiplicidad HadronNeutral; Frecuencia", 120, 0, 120);
  TH1F *h_Jets__ChargedHad_Multiplicity= new TH1F("Jets_Multiplicity__ChargedHad", "Multiplicidad, != 0, de Hadrones Cargados en cada ak5FastJet; Multiplicidad HadronCargado; Frecuencia", 120, 0, 120);
  // Cocientes.
  TH1F *h_Jets__EnergyQuotient_Muon_Jet    = new TH1F("Jets_Energy_Quotient__Muon-Jet",   "Cociente Energia  Muon / ak5FastJet; Energia_{Muon}/Energia_{ak5FastJet}; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_0Jet10     = new TH1F("Jets_Energy_Quot__Muon-0Jet10",    "Cociente Energ#acute{i}a  Muon / 0<ak5FastJet<10; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_10Jet30    = new TH1F("Jets_Energy_Quot__Muon-10Jet30",   "Cociente Energ#acute{i}a  Muon / 10<ak5FastJet<30; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_30Jet60    = new TH1F("Jets_Energy_Quot__Muon-30Jet60",   "Cociente Energ#acute{i}a  Muon / 30<ak5FastJet<60; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_60Jet100   = new TH1F("Jets_Energy_Quot__Muon-60Jet100",  "Cociente Energ#acute{i}a  Muon / 60<ak5FastJet<100; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_100Jet200  = new TH1F("Jets_Energy_Quot__Muon-100Jet200", "Cociente Energ#acute{i}a  Muon / 100<ak5FastJet<200; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_200Jet300  = new TH1F("Jets_Energy_Quot__Muon-200Jet300", "Cociente Energ#acute{i}a  Muon / 200<ak5FastJet<300; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_300Jet400  = new TH1F("Jets_Energy_Quot__Muon-300Jet400", "Cociente Energ#acute{i}a  Muon / 300<ak5FastJet<400; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_400Jet500  = new TH1F("Jets_Energy_Quot__Muon-400Jet500", "Cociente Energ#acute{i}a  Muon / 400<ak5FastJet<500; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_500Jet600  = new TH1F("Jets_Energy_Quot__Muon-500Jet600", "Cociente Energ#acute{i}a  Muon / 500<ak5FastJet<600; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_600Jet700  = new TH1F("Jets_Energy_Quot__Muon-600Jet700", "Cociente Energ#acute{i}a  Muon / 600<ak5FastJet<700; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_700Jet800  = new TH1F("Jets_Energy_Quot__Muon-700Jet800", "Cociente Energ#acute{i}a  Muon / 700<ak5FastJet<800; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_800Jet900  = new TH1F("Jets_Energy_Quot__Muon-800Jet900", "Cociente Energ#acute{i}a  Muon / 800<ak5FastJet<900; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_900Jet1000 = new TH1F("Jets_Energy_Quot__Muon-900Jet1000", "Cociente Energ#acute{i}a  Muon / 900<ak5FastJet<1000; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Muon_1000Jet    = new TH1F("Jets_Energy_Quot__Muon-1000Jet",   "Cociente Energ#acute{i}a  Muon / 1000<ak5FastJet; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuotient_Photon_Jet    = new TH1F("Jets_Energy_Quotient__Photon-Jet",   "Cociente Energia  Photon / ak5FastJet; Energia_{Photon}/Energia_{ak5FastJet}; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_0Jet10     = new TH1F("Jets_Energy_Quot__Photon-0Jet10",    "Cociente Energ#acute{i}a  Photon / 0<ak5FastJet<10; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_10Jet30    = new TH1F("Jets_Energy_Quot__Photon-10Jet30",   "Cociente Energ#acute{i}a  Photon / 10<ak5FastJet<30; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_30Jet60    = new TH1F("Jets_Energy_Quot__Photon-30Jet60",   "Cociente Energ#acute{i}a  Photon / 30<ak5FastJet<60; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_60Jet100   = new TH1F("Jets_Energy_Quot__Photon-60Jet100",  "Cociente Energ#acute{i}a  Photon / 60<ak5FastJet<100; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_100Jet200  = new TH1F("Jets_Energy_Quot__Photon-100Jet200", "Cociente Energ#acute{i}a  Photon / 100<ak5FastJet<200; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_200Jet300  = new TH1F("Jets_Energy_Quot__Photon-200Jet300", "Cociente Energ#acute{i}a  Photon / 200<ak5FastJet<300; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_300Jet400  = new TH1F("Jets_Energy_Quot__Photon-300Jet400", "Cociente Energ#acute{i}a  Photon / 300<ak5FastJet<400; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_400Jet500  = new TH1F("Jets_Energy_Quot__Photon-400Jet500", "Cociente Energ#acute{i}a  Photon / 400<ak5FastJet<500; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_500Jet600  = new TH1F("Jets_Energy_Quot__Photon-500Jet600", "Cociente Energ#acute{i}a  Photon / 500<ak5FastJet<600; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_600Jet700  = new TH1F("Jets_Energy_Quot__Photon-600Jet700", "Cociente Energ#acute{i}a  Photon / 600<ak5FastJet<700; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_700Jet800  = new TH1F("Jets_Energy_Quot__Photon-700Jet800", "Cociente Energ#acute{i}a  Photon / 700<ak5FastJet<800; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_800Jet900  = new TH1F("Jets_Energy_Quot__Photon-800Jet900", "Cociente Energ#acute{i}a  Photon / 800<ak5FastJet<900; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_900Jet1000 = new TH1F("Jets_Energy_Quot__Photon-900Jet1000", "Cociente Energ#acute{i}a  Photon / 900<ak5FastJet<1000; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Photon_1000Jet    = new TH1F("Jets_Energy_Quot__Photon-1000Jet",   "Cociente Energ#acute{i}a  Photon / 1000<ak5FastJet; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuotient_Electron_Jet    = new TH1F("Jets_Energy_Quotient__Electron-Jet",   "Cociente Energia  Electron / ak5FastJet; Energia_{Electron}/Energia_{ak5FastJet}; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_0Jet10     = new TH1F("Jets_Energy_Quot__Electron-0Jet10",    "Cociente Energ#acute{i}a  Electron / 0<ak5FastJet<10; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_10Jet30    = new TH1F("Jets_Energy_Quot__Electron-10Jet30",   "Cociente Energ#acute{i}a  Electron / 10<ak5FastJet<30; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_30Jet60    = new TH1F("Jets_Energy_Quot__Electron-30Jet60",   "Cociente Energ#acute{i}a  Electron / 30<ak5FastJet<60; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_60Jet100   = new TH1F("Jets_Energy_Quot__Electron-60Jet100",  "Cociente Energ#acute{i}a  Electron / 60<ak5FastJet<100; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_100Jet200  = new TH1F("Jets_Energy_Quot__Electron-100Jet200", "Cociente Energ#acute{i}a  Electron / 100<ak5FastJet<200; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_200Jet300  = new TH1F("Jets_Energy_Quot__Electron-200Jet300", "Cociente Energ#acute{i}a  Electron / 200<ak5FastJet<300; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_300Jet400  = new TH1F("Jets_Energy_Quot__Electron-300Jet400", "Cociente Energ#acute{i}a  Electron / 300<ak5FastJet<400; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_400Jet500  = new TH1F("Jets_Energy_Quot__Electron-400Jet500", "Cociente Energ#acute{i}a  Electron / 400<ak5FastJet<500; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_500Jet600  = new TH1F("Jets_Energy_Quot__Electron-500Jet600", "Cociente Energ#acute{i}a  Electron / 500<ak5FastJet<600; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_600Jet700  = new TH1F("Jets_Energy_Quot__Electron-600Jet700", "Cociente Energ#acute{i}a  Electron / 600<ak5FastJet<700; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_700Jet800  = new TH1F("Jets_Energy_Quot__Electron-700Jet800", "Cociente Energ#acute{i}a  Electron / 700<ak5FastJet<800; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_800Jet900  = new TH1F("Jets_Energy_Quot__Electron-800Jet900", "Cociente Energ#acute{i}a  Electron / 800<ak5FastJet<900; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_900Jet1000 = new TH1F("Jets_Energy_Quot__Electron-900Jet1000", "Cociente Energ#acute{i}a  Electron / 900<ak5FastJet<1000; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_Electron_1000Jet    = new TH1F("Jets_Energy_Quot__Electron-1000Jet",   "Cociente Energ#acute{i}a  Electron / 1000<ak5FastJet; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuotient_NeutralHad_Jet  = new TH1F("Jets_Energy_Quotient__NeutralHad-Jet",     "Cociente Energia  NeutralHad / ak5FastJet; Energia_{NeutralHad}/Energia_{ak5FastJet}; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_0Jet10     = new TH1F("Jets_Energy_Quot__NeutralHad-0Jet10",    "Cociente Energ#acute{i}a  NeutralHad / 0<ak5FastJet<10; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_10Jet30    = new TH1F("Jets_Energy_Quot__NeutralHad-10Jet30",   "Cociente Energ#acute{i}a  NeutralHad / 10<ak5FastJet<30; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_30Jet60    = new TH1F("Jets_Energy_Quot__NeutralHad-30Jet60",   "Cociente Energ#acute{i}a  NeutralHad / 30<ak5FastJet<60; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_60Jet100   = new TH1F("Jets_Energy_Quot__NeutralHad-60Jet100",  "Cociente Energ#acute{i}a  NeutralHad / 60<ak5FastJet<100; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_100Jet200  = new TH1F("Jets_Energy_Quot__NeutralHad-100Jet200", "Cociente Energ#acute{i}a  NeutralHad / 100<ak5FastJet<200; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_200Jet300  = new TH1F("Jets_Energy_Quot__NeutralHad-200Jet300", "Cociente Energ#acute{i}a  NeutralHad / 200<ak5FastJet<300; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_300Jet400  = new TH1F("Jets_Energy_Quot__NeutralHad-300Jet400", "Cociente Energ#acute{i}a  NeutralHad / 300<ak5FastJet<400; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_400Jet500  = new TH1F("Jets_Energy_Quot__NeutralHad-400Jet500", "Cociente Energ#acute{i}a  NeutralHad / 400<ak5FastJet<500; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_500Jet600  = new TH1F("Jets_Energy_Quot__NeutralHad-500Jet600", "Cociente Energ#acute{i}a  NeutralHad / 500<ak5FastJet<600; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_600Jet700  = new TH1F("Jets_Energy_Quot__NeutralHad-600Jet700", "Cociente Energ#acute{i}a  NeutralHad / 600<ak5FastJet<700; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_700Jet800  = new TH1F("Jets_Energy_Quot__NeutralHad-700Jet800", "Cociente Energ#acute{i}a  NeutralHad / 700<ak5FastJet<800; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_800Jet900  = new TH1F("Jets_Energy_Quot__NeutralHad-800Jet900", "Cociente Energ#acute{i}a  NeutralHad / 800<ak5FastJet<900; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_900Jet1000 = new TH1F("Jets_Energy_Quot__NeutralHad-900Jet1000", "Cociente Energ#acute{i}a  NeutralHad / 900<ak5FastJet<1000; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_NeutralHad_1000Jet    = new TH1F("Jets_Energy_Quot__NeutralHad-1000Jet",   "Cociente Energ#acute{i}a  NeutralHad / 1000<ak5FastJet; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuotient_ChargedHad_Jet    = new TH1F("Jets_Energy_Quotient__ChargedHad-Jet",   "Cociente Energia  ChargedHad / ak5FastJet; Energia_{ChagedHad}/Energia_{ak5FastJet}; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_0Jet10     = new TH1F("Jets_Energy_Quot__ChargedHad-0Jet10",    "Cociente Energ#acute{i}a  ChargedHad / 0<ak5FastJet<10; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_10Jet30    = new TH1F("Jets_Energy_Quot__ChargedHad-10Jet30",   "Cociente Energ#acute{i}a  ChargedHad / 10<ak5FastJet<30; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_30Jet60    = new TH1F("Jets_Energy_Quot__ChargedHad-30Jet60",   "Cociente Energ#acute{i}a  ChargedHad / 30<ak5FastJet<60; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_60Jet100   = new TH1F("Jets_Energy_Quot__ChargedHad-60Jet100",  "Cociente Energ#acute{i}a  ChargedHad / 60<ak5FastJet<100; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_100Jet200  = new TH1F("Jets_Energy_Quot__ChargedHad-100Jet200", "Cociente Energ#acute{i}a  ChargedHad / 100<ak5FastJet<200; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_200Jet300  = new TH1F("Jets_Energy_Quot__ChargedHad-200Jet300", "Cociente Energ#acute{i}a  ChargedHad / 200<ak5FastJet<300; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_300Jet400  = new TH1F("Jets_Energy_Quot__ChargedHad-300Jet400", "Cociente Energ#acute{i}a  ChargedHad / 300<ak5FastJet<400; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_400Jet500  = new TH1F("Jets_Energy_Quot__ChargedHad-400Jet500", "Cociente Energ#acute{i}a  ChargedHad / 400<ak5FastJet<500; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_500Jet600  = new TH1F("Jets_Energy_Quot__ChargedHad-500Jet600", "Cociente Energ#acute{i}a  ChargedHad / 500<ak5FastJet<600; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_600Jet700  = new TH1F("Jets_Energy_Quot__ChargedHad-600Jet700", "Cociente Energ#acute{i}a  ChargedHad / 600<ak5FastJet<700; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_700Jet800  = new TH1F("Jets_Energy_Quot__ChargedHad-700Jet800", "Cociente Energ#acute{i}a  ChargedHad / 700<ak5FastJet<800; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_800Jet900  = new TH1F("Jets_Energy_Quot__ChargedHad-800Jet900", "Cociente Energ#acute{i}a  ChargedHad / 800<ak5FastJet<900; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_900Jet1000 = new TH1F("Jets_Energy_Quot__ChargedHad-900Jet1000", "Cociente Energ#acute{i}a  ChargedHad / 900<ak5FastJet<1000; Indice; Frecuencia", 120, 0, 1.2);
  TH1F *h_Jets__EnergyQuot_ChargedHad_1000Jet    = new TH1F("Jets_Energy_Quot__ChargedHad-1000Jet",   "Cociente Energ#acute{i}a  ChargedHad / 1000<ak5FastJet; Indice; Frecuencia", 120, 0, 1.2);
// Distancia angular.
  // TH1F* h_Jets__D__Jet_Jet  = new TH1F("ak5FastJet__D__Jet-Jet", "Distancia angular #sqrt{(#Delta#phi_{ij})^{2} + (#Delta#eta_{ij})^{2}} del ak5FastJet_{i} al ak5FastJet_{j}, por Evento; Valor; Ocurrencia", 120, 0, 12);
  // // Pdg Id().
  // TH1I*h__Pdg_Id = new TH1I("Pdg_Id", "Partículas contenidas en los Jets; PDG id(); Frecuencia", 800, -4000, 4000);
  // TH1I*h__OtherPdg_Id = new TH1I("OtherPdg_Id", "Partículas contenidas en los Jets; PDG id(); Frecuencia", 800, -4000, 4000);
  // TH1I*h__JetMother = new TH1I("JetMother", "Madre de Jet; PDG id(); Frecuencia", 43, -21.5, 21.5);
  // TH1I*h__OtherMother = new TH1I("OtherMother", "Madre de Jet distinta a Quark o Gluon; PDG id(); Frecuencia", 43, -21.5, 21.5);

  // Generator. Shorthand for event.
  Pythia pythia;
  Event& event = pythia.event;

  // // Soft QCD processes.
  // pythia.readString("SoftQCD:nonDiffractive = on");
  // pythia.readString("SoftQCD:singleDiffractive = on");
  // pythia.readString("SoftQCD:doubleDiffractive = on");
  // pythia.readString("PhaseSpace:pTHatMin = 2.0");
  // pythia.readString("PhaseSpace:pTHatMax = 1200.0");
  // pythia.readString("PhaseSpace:mHatMax = 1200.0");
  // pythia.readString("ParticleDecays:limitTau0 = On");
  // pythia.readString("ParticleDecays:tau0Max = 10.0");

  // Process selection.
  pythia.readString("HardQCD:all = on");
  pythia.readString("PhaseSpace:pTHatMin = 2.0"); // initial pT Hat Minimum (ver y/o editar Master Macro y ciclo for pTHM, 6 en total).
  // pythia.readString("HardQCD:hardccbar = on");
  // pythia.readString("HardQCD:hardbbbar = on");
  // pythia.readString("HardQCD:3parton = on");
  // pythia.readString("PromptPhoton:all = on");
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


  // Number of events, generated and listed ones (for jets). (Ver y/o editar bashMacro, 2 en total).
  int nEvent    = 4800;
  printf("\n\n\n\t Numero de Eventos = %i \t pTHatMin = 2.0\n\n\t Salida:  ak5FJ-2.root \n\n\n\n", nEvent); // initial pT Hat Minimum (ver y/o editar Master Macro y ciclo for pTHM, 6 en total).
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
    for (size_t i=0; i<sortedJets.size(); i++){

      Float_t MuonEnergy=0.0, PhotonEnergy=0.0, ElectronEnergy=0.0, NeutralHadEnergy=0.0, ChargedHadEnergy=0.0;
      Int_t MuonMultiplicity=0, PhotonMultiplicity=0, ElectronMultiplicity=0, NeutralHadMultiplicity=0, ChargedHadMultiplicity=0;

      if ( abs(sortedJets[i].eta()) > etaMax ) continue;

      h_Jets_pt_ -> Fill(sortedJets[i].pt());
      h_Jets_eta_-> Fill(sortedJets[i].eta());
      // Multiplicidad de Jets en cada Evento.
      h_Jets__Multiplicity -> Fill(sortedJets.size());

      for (size_t j=0; j<sortedJets[i].constituents().size(); j++) {

        Int_t JCIndex = sortedJets[i].constituents()[j].user_info<MyInfo>().Index(); // Event Index.

        // Muons.
        if      (abs(event[JCIndex].id())==13) {MuonEnergy=MuonEnergy + sortedJets[i].constituents()[j].E(); MuonMultiplicity=MuonMultiplicity+1;}
        // Photons.
        else if (abs(event[JCIndex].id())==22) {PhotonEnergy=PhotonEnergy + sortedJets[i].constituents()[j].E(); PhotonMultiplicity=PhotonMultiplicity+1;}
        // Electrons.
        else if (abs(event[JCIndex].id())==11) {ElectronEnergy=ElectronEnergy + sortedJets[i].constituents()[j].E(); ElectronMultiplicity=ElectronMultiplicity+1;}
        // Neutral Hadrons.
        else if (event[JCIndex].isNeutral()  ) {NeutralHadEnergy=NeutralHadEnergy + sortedJets[i].constituents()[j].E(); NeutralHadMultiplicity=NeutralHadMultiplicity+1;}
        // Charged Hadrons.
        else if (event[JCIndex].isCharged()  ) {ChargedHadEnergy=ChargedHadEnergy + sortedJets[i].constituents()[j].E(); ChargedHadMultiplicity=ChargedHadMultiplicity+1;}
      }

      // Energies.
      Float_t JetEnergy = MuonEnergy + PhotonEnergy + ElectronEnergy + NeutralHadEnergy + ChargedHadEnergy;

      h_Jets__Energy -> Fill (JetEnergy);

      // Cociente de la energia de las partículas respecto a al E del Jet. Y Multiplicidad de las particulas en cada Jet.
      if (MuonMultiplicity > 0) { h_MuonEnergy -> Fill(MuonEnergy);
        h_Jets__EnergyQuotient_Muon_Jet -> Fill(MuonEnergy/JetEnergy);
        if      (     JetEnergy&&JetEnergy<10 ) h_Jets__EnergyQuot_Muon_0Jet10    -> Fill(MuonEnergy/JetEnergy);
        else if ( 10<=JetEnergy&&JetEnergy<30 ) h_Jets__EnergyQuot_Muon_10Jet30   -> Fill(MuonEnergy/JetEnergy);
        else if ( 30<=JetEnergy&&JetEnergy<60 ) h_Jets__EnergyQuot_Muon_30Jet60   -> Fill(MuonEnergy/JetEnergy);
        else if ( 60<=JetEnergy&&JetEnergy<100) h_Jets__EnergyQuot_Muon_60Jet100  -> Fill(MuonEnergy/JetEnergy);
        else if (100<=JetEnergy&&JetEnergy<200) h_Jets__EnergyQuot_Muon_100Jet200 -> Fill(MuonEnergy/JetEnergy);
        else if (200<=JetEnergy&&JetEnergy<300) h_Jets__EnergyQuot_Muon_200Jet300 -> Fill(MuonEnergy/JetEnergy);
        else if (300<=JetEnergy&&JetEnergy<400) h_Jets__EnergyQuot_Muon_300Jet400 -> Fill(MuonEnergy/JetEnergy);
        else if (400<=JetEnergy&&JetEnergy<500) h_Jets__EnergyQuot_Muon_400Jet500 -> Fill(MuonEnergy/JetEnergy);
        else if (500<=JetEnergy&&JetEnergy<600) h_Jets__EnergyQuot_Muon_500Jet600 -> Fill(MuonEnergy/JetEnergy);
        else if (600<=JetEnergy&&JetEnergy<700) h_Jets__EnergyQuot_Muon_600Jet700 -> Fill(MuonEnergy/JetEnergy);
        else if (700<=JetEnergy&&JetEnergy<800) h_Jets__EnergyQuot_Muon_700Jet800 -> Fill(MuonEnergy/JetEnergy);
        else if (800<=JetEnergy&&JetEnergy<900) h_Jets__EnergyQuot_Muon_800Jet900 -> Fill(MuonEnergy/JetEnergy);
        else if (900<=JetEnergy&&JetEnergy<1000)h_Jets__EnergyQuot_Muon_900Jet1000-> Fill(MuonEnergy/JetEnergy);
        else                         h_Jets__EnergyQuot_Muon_1000Jet   -> Fill(MuonEnergy/JetEnergy);
        //Multiplicidad de Muones en cada Jet.
        h_Jets__MuonMultiplicity-> Fill(MuonMultiplicity);
      }
      if (PhotonMultiplicity > 0) { h_PhotonEnergy -> Fill(PhotonEnergy);
        h_Jets__EnergyQuotient_Photon_Jet -> Fill(PhotonEnergy/JetEnergy);
        if      (     JetEnergy&&JetEnergy<10 ) h_Jets__EnergyQuot_Photon_0Jet10    -> Fill(PhotonEnergy/JetEnergy);
        else if ( 10<=JetEnergy&&JetEnergy<30 ) h_Jets__EnergyQuot_Photon_10Jet30   -> Fill(PhotonEnergy/JetEnergy);
        else if ( 30<=JetEnergy&&JetEnergy<60 ) h_Jets__EnergyQuot_Photon_30Jet60   -> Fill(PhotonEnergy/JetEnergy);
        else if ( 60<=JetEnergy&&JetEnergy<100) h_Jets__EnergyQuot_Photon_60Jet100  -> Fill(PhotonEnergy/JetEnergy);
        else if (100<=JetEnergy&&JetEnergy<200) h_Jets__EnergyQuot_Photon_100Jet200 -> Fill(PhotonEnergy/JetEnergy);
        else if (200<=JetEnergy&&JetEnergy<300) h_Jets__EnergyQuot_Photon_200Jet300 -> Fill(PhotonEnergy/JetEnergy);
        else if (300<=JetEnergy&&JetEnergy<400) h_Jets__EnergyQuot_Photon_300Jet400 -> Fill(PhotonEnergy/JetEnergy);
        else if (400<=JetEnergy&&JetEnergy<500) h_Jets__EnergyQuot_Photon_400Jet500 -> Fill(PhotonEnergy/JetEnergy);
        else if (500<=JetEnergy&&JetEnergy<600) h_Jets__EnergyQuot_Photon_500Jet600 -> Fill(PhotonEnergy/JetEnergy);
        else if (600<=JetEnergy&&JetEnergy<700) h_Jets__EnergyQuot_Photon_600Jet700 -> Fill(PhotonEnergy/JetEnergy);
        else if (700<=JetEnergy&&JetEnergy<800) h_Jets__EnergyQuot_Photon_700Jet800 -> Fill(PhotonEnergy/JetEnergy);
        else if (800<=JetEnergy&&JetEnergy<900) h_Jets__EnergyQuot_Photon_800Jet900 -> Fill(PhotonEnergy/JetEnergy);
        else if (900<=JetEnergy&&JetEnergy<1000)h_Jets__EnergyQuot_Photon_900Jet1000-> Fill(PhotonEnergy/JetEnergy);
        else                         h_Jets__EnergyQuot_Photon_1000Jet   -> Fill(PhotonEnergy/JetEnergy);
        //Multiplicidad de Fotones en cada Jet.
        h_Jets__PhotonMultiplicity-> Fill(PhotonMultiplicity);
      }
      if (ElectronMultiplicity > 0) { h_ElectronEnergy -> Fill(ElectronEnergy);
        h_Jets__EnergyQuotient_Electron_Jet -> Fill(ElectronEnergy/JetEnergy);
        if      (     JetEnergy&&JetEnergy<10 ) h_Jets__EnergyQuot_Electron_0Jet10    -> Fill(ElectronEnergy/JetEnergy);
        else if ( 10<=JetEnergy&&JetEnergy<30 ) h_Jets__EnergyQuot_Electron_10Jet30   -> Fill(ElectronEnergy/JetEnergy);
        else if ( 30<=JetEnergy&&JetEnergy<60 ) h_Jets__EnergyQuot_Electron_30Jet60   -> Fill(ElectronEnergy/JetEnergy);
        else if ( 60<=JetEnergy&&JetEnergy<100) h_Jets__EnergyQuot_Electron_60Jet100  -> Fill(ElectronEnergy/JetEnergy);
        else if (100<=JetEnergy&&JetEnergy<200) h_Jets__EnergyQuot_Electron_100Jet200 -> Fill(ElectronEnergy/JetEnergy);
        else if (200<=JetEnergy&&JetEnergy<300) h_Jets__EnergyQuot_Electron_200Jet300 -> Fill(ElectronEnergy/JetEnergy);
        else if (300<=JetEnergy&&JetEnergy<400) h_Jets__EnergyQuot_Electron_300Jet400 -> Fill(ElectronEnergy/JetEnergy);
        else if (400<=JetEnergy&&JetEnergy<500) h_Jets__EnergyQuot_Electron_400Jet500 -> Fill(ElectronEnergy/JetEnergy);
        else if (500<=JetEnergy&&JetEnergy<600) h_Jets__EnergyQuot_Electron_500Jet600 -> Fill(ElectronEnergy/JetEnergy);
        else if (600<=JetEnergy&&JetEnergy<700) h_Jets__EnergyQuot_Electron_600Jet700 -> Fill(ElectronEnergy/JetEnergy);
        else if (700<=JetEnergy&&JetEnergy<800) h_Jets__EnergyQuot_Electron_700Jet800 -> Fill(ElectronEnergy/JetEnergy);
        else if (800<=JetEnergy&&JetEnergy<900) h_Jets__EnergyQuot_Electron_800Jet900 -> Fill(ElectronEnergy/JetEnergy);
        else if (900<=JetEnergy&&JetEnergy<1000)h_Jets__EnergyQuot_Electron_900Jet1000-> Fill(ElectronEnergy/JetEnergy);
        else                         h_Jets__EnergyQuot_Electron_1000Jet   -> Fill(ElectronEnergy/JetEnergy);
        //Multiplicidad de Electrones en cada Jet.
        h_Jets__ElectronMultiplicity-> Fill(ElectronMultiplicity);
      }
      if (NeutralHadMultiplicity > 0) { h_NeutralHadEnergy -> Fill(NeutralHadEnergy);
        h_Jets__EnergyQuotient_NeutralHad_Jet -> Fill(NeutralHadEnergy/JetEnergy);
        if      (     JetEnergy&&JetEnergy<10 ) h_Jets__EnergyQuot_NeutralHad_0Jet10    -> Fill(NeutralHadEnergy/JetEnergy);
        else if ( 10<=JetEnergy&&JetEnergy<30 ) h_Jets__EnergyQuot_NeutralHad_10Jet30   -> Fill(NeutralHadEnergy/JetEnergy);
        else if ( 30<=JetEnergy&&JetEnergy<60 ) h_Jets__EnergyQuot_NeutralHad_30Jet60   -> Fill(NeutralHadEnergy/JetEnergy);
        else if ( 60<=JetEnergy&&JetEnergy<100) h_Jets__EnergyQuot_NeutralHad_60Jet100  -> Fill(NeutralHadEnergy/JetEnergy);
        else if (100<=JetEnergy&&JetEnergy<200) h_Jets__EnergyQuot_NeutralHad_100Jet200 -> Fill(NeutralHadEnergy/JetEnergy);
        else if (200<=JetEnergy&&JetEnergy<300) h_Jets__EnergyQuot_NeutralHad_200Jet300 -> Fill(NeutralHadEnergy/JetEnergy);
        else if (300<=JetEnergy&&JetEnergy<400) h_Jets__EnergyQuot_NeutralHad_300Jet400 -> Fill(NeutralHadEnergy/JetEnergy);
        else if (400<=JetEnergy&&JetEnergy<500) h_Jets__EnergyQuot_NeutralHad_400Jet500 -> Fill(NeutralHadEnergy/JetEnergy);
        else if (500<=JetEnergy&&JetEnergy<600) h_Jets__EnergyQuot_NeutralHad_500Jet600 -> Fill(NeutralHadEnergy/JetEnergy);
        else if (600<=JetEnergy&&JetEnergy<700) h_Jets__EnergyQuot_NeutralHad_600Jet700 -> Fill(NeutralHadEnergy/JetEnergy);
        else if (700<=JetEnergy&&JetEnergy<800) h_Jets__EnergyQuot_NeutralHad_700Jet800 -> Fill(NeutralHadEnergy/JetEnergy);
        else if (800<=JetEnergy&&JetEnergy<900) h_Jets__EnergyQuot_NeutralHad_800Jet900 -> Fill(NeutralHadEnergy/JetEnergy);
        else if (900<=JetEnergy&&JetEnergy<1000)h_Jets__EnergyQuot_NeutralHad_900Jet1000-> Fill(NeutralHadEnergy/JetEnergy);
        else                         h_Jets__EnergyQuot_NeutralHad_1000Jet   -> Fill(NeutralHadEnergy/JetEnergy);
        //Multiplicidad de Hadrones Neutros en cada Jet.
        h_Jets__NeutralHad_Multiplicity-> Fill(NeutralHad_Multiplicity);
      }
      if (ChargedHadMultiplicity > 0) { h_ChargedHadEnergy -> Fill(ChargedHadEnergy);
        h_Jets__EnergyQuotient_ChargedHad_Jet -> Fill(ChargedHadEnergy/JetEnergy);
        if      (     JetEnergy&&JetEnergy<10 ) h_Jets__EnergyQuot_ChargedHad_0Jet10    -> Fill(ChargedHadEnergy/JetEnergy);
        else if ( 10<=JetEnergy&&JetEnergy<30 ) h_Jets__EnergyQuot_ChargedHad_10Jet30   -> Fill(ChargedHadEnergy/JetEnergy);
        else if ( 30<=JetEnergy&&JetEnergy<60 ) h_Jets__EnergyQuot_ChargedHad_30Jet60   -> Fill(ChargedHadEnergy/JetEnergy);
        else if ( 60<=JetEnergy&&JetEnergy<100) h_Jets__EnergyQuot_ChargedHad_60Jet100  -> Fill(ChargedHadEnergy/JetEnergy);
        else if (100<=JetEnergy&&JetEnergy<200) h_Jets__EnergyQuot_ChargedHad_100Jet200 -> Fill(ChargedHadEnergy/JetEnergy);
        else if (200<=JetEnergy&&JetEnergy<300) h_Jets__EnergyQuot_ChargedHad_200Jet300 -> Fill(ChargedHadEnergy/JetEnergy);
        else if (300<=JetEnergy&&JetEnergy<400) h_Jets__EnergyQuot_ChargedHad_300Jet400 -> Fill(ChargedHadEnergy/JetEnergy);
        else if (400<=JetEnergy&&JetEnergy<500) h_Jets__EnergyQuot_ChargedHad_400Jet500 -> Fill(ChargedHadEnergy/JetEnergy);
        else if (500<=JetEnergy&&JetEnergy<600) h_Jets__EnergyQuot_ChargedHad_500Jet600 -> Fill(ChargedHadEnergy/JetEnergy);
        else if (600<=JetEnergy&&JetEnergy<700) h_Jets__EnergyQuot_ChargedHad_600Jet700 -> Fill(ChargedHadEnergy/JetEnergy);
        else if (700<=JetEnergy&&JetEnergy<800) h_Jets__EnergyQuot_ChargedHad_700Jet800 -> Fill(ChargedHadEnergy/JetEnergy);
        else if (800<=JetEnergy&&JetEnergy<900) h_Jets__EnergyQuot_ChargedHad_800Jet900 -> Fill(ChargedHadEnergy/JetEnergy);
        else if (900<=JetEnergy&&JetEnergy<1000)h_Jets__EnergyQuot_ChargedHad_900Jet1000-> Fill(ChargedHadEnergy/JetEnergy);
        else                         h_Jets__EnergyQuot_ChargedHad_1000Jet   -> Fill(ChargedHadEnergy/JetEnergy);
        // Multiplicidad de Hadrones Cargados en cada Jet.
        h_Jets__ChargedHad_Multiplicity-> Fill(ChargedHad_Multiplicity);
      }
    }  // End of the i loop.
  }  // End of Event loop.

// #######################################################################################################################################################################


  // Statistics. Histograms.
  // pythia.stat();

  h_Jets_pt_         -> Write();
  h_Jets_eta_       -> Write();
  h_Jets__Energy    -> Write();
  h_MuonEnergy      -> Write();
  h_PhotonEnergy    -> Write();
  h_ElectronEnergy  -> Write();
  h_NeutralHadEnergy-> Write();
  h_ChargedHadEnergy-> Write();
  // Multiplicidad
  h_Jets__Multiplicity           -> Write();
  h_Jets__MuonMultiplicity
  h_Jets__PhotonMultiplicity
  h_Jets__ElectronMultiplicity
  h_Jets__NeutralHad_Multiplicity
  h_Jets__ChargedHad_Multiplicity
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
  h_Jets__EnergyQuotient_NeutralHad_Jet   -> Write();
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
  // Distancia Angular.
  // h_Jets__D__Jet_Jet -> Write();

  // Done.
  delete OutputFile;
  return 0;
}
