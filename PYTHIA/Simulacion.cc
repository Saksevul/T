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
int main(int argc, char* argv[]) {   Float_t PI=3.1415927;

  // Create the ROOT application environment.
  TApplication theApp("hist", &argc, argv);
  // Create file on which histogram(s) can be saved.
  TFile* OutputFile = new TFile("/home/saksevul/T/PYTHIA/FastJet/ak5FJ-10.root", "RECREATE");
  // Histograms.
  // Muones.
  TH1F *h_Muons_pt_ = new TH1F("Muons_pt_",  "p_{T} de Muones contenidos en ak5FastJet; p_{T} [GeV]; Frecuencia",  300, 0, 10);
  TH1F *h_Muons_eta_= new TH1F("Muons_eta_", "Distribuci#acute{o}n de #eta de Muones contenidos en ak5FastJet; #eta; Frecuencia", 119, -5.95, 5.95);
  TH1D *h_Muons__fX = new TH1D("Muons__fX", "Vertice en X de Muones contenidos en ak5FastJet; Distancia [cm]; Frecuencia", 39, -1.95, 1.95);
  TH1D *h_Muons__fY = new TH1D("Muons__fY", "Vertice en Y de Muones contenidos en ak5FastJet; Distancia [cm]; Frecuencia", 39, -1.95, 1.95);
  TH1D *h_Muons__fZ = new TH1D("Muons__fZ", "Vertice en Z de Muones contenidos en ak5FastJet; Distancia [cm]; Frecuencia", 39, -1.95, 1.95);
  // Fotones
  TH1F *h_Photons_pt_ = new TH1F("Photons_pt_",  "p_{T} de Photones contenidos en ak5FastJet; p_{T} [GeV]; Frecuencia",  1200, 0, 40);
  TH1F *h_Photons_eta_= new TH1F("Photons_eta_", "Distribuci#acute{o}n de #eta de Fotones contenidos en ak5FastJet; #eta; Frecuencia", 119, -5.95, 5.95);
  // Electrones.
  TH1F *h_Electrons_pt_ = new TH1F("Electrons_pt_",  "p_{T} de Electrones contenidos en ak5FastJet; p_{T} [GeV]; Frecuencia",  600, 0, 20);
  TH1F *h_Electrons_eta_= new TH1F("Electrons_eta_", "Distribuci#acute{o}n de #eta de Electrones contenidos en ak5FastJet; #eta; Frecuencia", 119, -5.95, 5.95);
  TH1D *h_Electrons__fX = new TH1D("Electrons__fX", "Vertice en X de Electrones contenidos en ak5FastJet; Distancia [cm]; Frecuencia", 39, -1.95, 1.95);
  TH1D *h_Electrons__fY = new TH1D("Electrons__fY", "Vertice en Y de Electrones contenidos en ak5FastJet; Distancia [cm]; Frecuencia", 39, -1.95, 1.95);
  TH1D *h_Electrons__fZ = new TH1D("Electrons__fZ", "Vertice en Z de Electrones contenidos en ak5FastJet; Distancia [cm]; Frecuencia", 39, -1.95, 1.95);
  // FastJet.
  TH1F* h_Jets_pt_         = new TH1F("Jets_pt_",  "Espectro de p_{T} de ak5FastJet; p_{T} [GeV]; Ocurrencia", 300, 0, 30);
  TH1F *h_Jets_eta_        = new TH1F("Jets_eta_", "Distribución en #eta de ak5FastJet; #eta; Ocurrencia", 119, -5.95, 5.95);
  TH1F* h_Jets__Multipicity= new TH1F("Jets__Multiplicity", "Multiplicidad, de ak5FastJet, por Evento; Multilicidad; Ocurrencia", 120, 0, 120);
  TH1F *h_JetEnergy        = new TH1F("Jets_JetEnergy", "Energ#acute{i}a de FastJets; Energ#acute{i}a [GeV]; Frecuencia", 200, 0, 2);
  TH1F *h_MuonEnergy       = new TH1F("Jets_MuonEnergy", "Energ#acute{i}a de Muones; Energ#acute{i}a [GeV]; Frecuencia", 500, 0, 10);
  TH1F *h_PhotonEnergy     = new TH1F("Jets_PhotonEnergy", "Energ#acute{i}a de Fotones; Energ#acute{i}a [GeV]; Frecuencia", 1000, 0, 10);
  TH1F *h_ElectronEnergy   = new TH1F("Jets_ElectronEnergy", "Energ#acute{i}a de Electrones; Energ#acute{i}a [GeV]; Frecuencia", 1000, 0, 10);
  TH1F *h_NeutralHadEnergy = new TH1F("Jets_NeutralHadronEnergy", "Energ#acute{i}a de Hadrones Neutros; Energ#acute{i}a [GeV]; Frecuencia", 1500, 0, 20);
  TH1F *h_ChargedHadEnergy = new TH1F("Jets_ChargedHadronEnergy", "Energ#acute{i}a de Hadrones Cargados; Energ#acute{i}a [GeV]; Frecuencia", 1500, 0, 20);

  // Cocientes.
  TH1F *h__pTQuotient_Muon_Jet  = new TH1F("pT_Quotient__Muon-Jet",  "Cociente p_{T}  Muon / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient_1Muon_Jet = new TH1F("pT_Quotient__1Muon-Jet<100",  "Cociente p_{T}  Muon / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuot100__1Muon_Jet = new TH1F("pT_Quotient__1Muon-Jet>100",  "Cociente p_{T}  Muon / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient01_Muon_Jet  = new TH1F("pT_Quotient01__Muon-Jet",  "Cociente p_{T}  Muon / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient02_Muon_Jet  = new TH1F("pT_Quotient02__Muon-Jet",  "Cociente p_{T}  Muon / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient03_Muon_Jet  = new TH1F("pT_Quotient03__Muon-Jet",  "Cociente p_{T}  Muon / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient04_Muon_Jet  = new TH1F("pT_Quotient04__Muon-Jet",  "Cociente p_{T}  Muon / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient05_Muon_Jet  = new TH1F("pT_Quotient05__Muon-Jet",  "Cociente p_{T}  Muon / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient21_Muon_Jet  = new TH1F("pT_Quotient21__Muon-Jet",  "Cociente p_{T}  Muon / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotientOt_Muon_Jet  = new TH1F("pT_QuotientOt__Muon-Jet",  "Cociente p_{T}  Muon / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient_Electron_Jet  = new TH1F("pT_Quotient__Electron-Jet",  "Cociente p_{T}  Electron / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient_1Electron_Jet = new TH1F("pT_Quotient__1Electron-Jet<100",  "Cociente p_{T}  Electron / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuot100__1Electron_Jet = new TH1F("pT_Quotient__1Electron-Jet>100",  "Cociente p_{T}  Electron / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient01_Electron_Jet  = new TH1F("pT_Quotient01__Electron-Jet",  "Cociente p_{T}  Electron / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient02_Electron_Jet  = new TH1F("pT_Quotient02__Electron-Jet",  "Cociente p_{T}  Electron / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient03_Electron_Jet  = new TH1F("pT_Quotient03__Electron-Jet",  "Cociente p_{T}  Electron / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient04_Electron_Jet  = new TH1F("pT_Quotient04__Electron-Jet",  "Cociente p_{T}  Electron / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient05_Electron_Jet  = new TH1F("pT_Quotient05__Electron-Jet",  "Cociente p_{T}  Electron / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient21_Electron_Jet  = new TH1F("pT_Quotient21__Electron-Jet",  "Cociente p_{T}  Electron / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotientOt_Electron_Jet  = new TH1F("pT_QuotientOt__Electron-Jet",  "Cociente p_{T}  Electron / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);

  TH1F *h_Jets__EnergyQuotient_Muon_Jet       = new TH1F("Jets_Energy_Quotient__Muon-Jet",    "Cociente Energia  Muon / ak5FastJet; Energia_{Muon}/Energia_{ak5FastJet}; Frecuencia", 100, 0, 2);
  TH1F *h_Jets__EnergyQuot200_Muon_Jet        = new TH1F("Jets_Energy_Quotient__Muon-Jet<200", "Cociente Energ#acute{i}a < 200  Muon / ak5FastJet; Indice; Frecuencia", 100, 0, 2);
  TH1F *h_Jets__Energy200Quot_Muon_Jet        = new TH1F("Jets_Energy_Quotient__Muon-Jet>200", "Cociente Energ#acute{i}a > 200  Muon / ak5FastJet; Indice; Frecuencia", 100, 0, 2);
  TH1F *h_Jets__EnergyQuotient_Photon_Jet     = new TH1F("Jets_Energy_Quotient__Photon-Jet",      "Cociente Energia  Photon / ak5FastJet; Energia_{Photon}/Energia_{ak5FastJet}; Frecuencia", 100, 0, 2);
  TH1F *h_Jets__EnergyQuot200_Photon_Jet      = new TH1F("Jets_Energy_Quotient__Photon-Jet<200", "Cociente Energ#acute{i}a < 200  Photon / ak5FastJet; Indice; Frecuencia", 100, 0, 2);
  TH1F *h_Jets__Energy200Quot_Photon_Jet      = new TH1F("Jets_Energy_Quotient__Photon-Jet>200",  "Cociente Energ#acute{i}a > 200  Photon / ak5FastJet; Indice; Frecuencia", 100, 0, 2);
  TH1F *h_Jets__EnergyQuotient_Electron_Jet   = new TH1F("Jets_Energy_Quotient__Electron-Jet",      "Cociente Energia  Electron / ak5FastJet; Energia_{Electron}/Energia_{ak5FastJet}; Frecuencia", 100, 0, 2);
  TH1F *h_Jets__EnergyQuot200_Electron_Jet    = new TH1F("Jets_Energy_Quotient__Electron-Jet<200",  "Cociente Energ#acute{i}a < 200  Electron / ak5FastJet; Indice; Frecuencia", 100, 0, 2);
  TH1F *h_Jets__Energy200Quot_Electron_Jet    = new TH1F("Jets_Energy_Quotient__Electron-Jet>200",  "Cociente Energ#acute{i}a > 200  Electron / ak5FastJet; Indice; Frecuencia", 100, 0, 2);
  TH1F *h_Jets__EnergyQuotient_NeutralHad_Jet = new TH1F("Jets_Energy_Quotient__NeutralHad-Jet",    "Cociente Energia  NeutralHad / ak5FastJet; Energia_{NeutralHad}/Energia_{ak5FastJet}; Frecuencia", 100, 0, 2);
  TH1F *h_Jets__EnergyQuot200_NeutralHad_Jet  = new TH1F("Jets_Energy_Quotient__NeutralHad-Jet<200",  "Cociente Energ#acute{i}a < 200  NeutralHad / ak5FastJet; Indice; Frecuencia", 100, 0, 2);
  TH1F *h_Jets__Energy200Quot_NeutralHad_Jet  = new TH1F("Jets_Energy_Quotient__NeutralHad-Jet>200",  "Cociente Energ#acute{i}a > 200  NeutralHad / ak5FastJet; Indice; Frecuencia", 100, 0, 2);
  TH1F *h_Jets__EnergyQuotient_ChargedHad_Jet = new TH1F("Jets_Energy_Quotient__ChargedHad-Jet",    "Cociente Energia  ChargedHad / ak5FastJet; Energia_{ChargedHad}/Energia_{ak5FastJet}; Frecuencia", 100, 0, 2);
  TH1F *h_Jets__EnergyQuot200_ChargedHad_Jet  = new TH1F("Jets_Energy_Quotient__ChargedHad-Jet<200",  "Cociente Energ#acute{i}a < 200  ChargedHad / ak5FastJet; Indice; Frecuencia", 100, 0, 2);
  TH1F *h_Jets__Energy200Quot_ChargedHad_Jet  = new TH1F("Jets_Energy_Quotient__ChargedHad-Jet>200",  "Cociente Energ#acute{i}a > 200  ChargedHad / ak5FastJet; Indice; Frecuencia", 100, 0, 2);
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

      if ( abs(event[i].id()) == 13 && event[i].e() < 4.0 ) continue;
      else if ( abs(event[i].id()) == 22 && event[i].e() < 0.32) continue;
      else if ( abs(event[i].id()) == 11 && event[i].e() < 3.0 ) continue;
      else if ( abs(event[i].isNeutral()) && event[i].e() < 0.8) continue;
      else if ( abs(event[i].isCharged()) && event[i].e() < 0.4) continue;

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

      Float_t MuonEnergy = 0.0, PhotonEnergy = 0.0, ElectronEnergy = 0.0, NeutralHadEnergy =0.0, ChargedHadEnergy = 0.0;

      if ( abs(sortedJets[i].eta()) > etaMax-0.5 ) continue;

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
          h_Muons_pt_ -> Fill(sortedJets[i].constituents()[j].pt());
          h_Muons_eta_-> Fill(sortedJets[i].constituents()[j].eta());
          MuonEnergy = MuonEnergy + sortedJets[i].constituents()[j].E();
          if ( abs(event[JCIndex].eta()) < etaMax ) {
            if ( pow2(event[JCIndex].xProd()) + pow2(event[JCIndex].yProd()) + pow2(event[JCIndex].zProd()) <= 25 ) {
              h_Muons__fX -> Fill(event[JCIndex].xProd()/10.0);
              h_Muons__fY -> Fill(event[JCIndex].yProd()/10.0);
              h_Muons__fZ -> Fill(event[JCIndex].zProd()/10.0);
              h__pTQuotient_Muon_Jet -> Fill(sortedJets[i].constituents()[j].pt()/sortedJets[i].pt());
              if ( abs(event[JCIndex].phi() - sortedJets[i].phi_std()) <= PI ) {
                h__D__Muon_Jet -> Fill(sqrt( pow2(event[JCIndex].eta()-sortedJets[i].eta()) + pow2(event[JCIndex].phi()-sortedJets[i].phi_std()) ));
              } else {
                h__D__Muon_Jet -> Fill(sqrt( pow2(event[JCIndex].eta()-sortedJets[i].eta()) + pow2(2*PI-abs(event[JCIndex].phi()-sortedJets[i].phi_std())) ));
              }
              if ( sortedJets[i].constituents()[j].pt() > pTM) { FlagM=true; pTM=sortedJets[i].constituents()[j].pt(); }  // Para obtener información del Muón màs energético.
          } }
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
        else if ( abs(event[JCIndex].id()) == 22 ) {
          h_Photons_pt_ -> Fill(sortedJets[i].constituents()[j].pt());
          h_Photons_eta_-> Fill(sortedJets[i].constituents()[j].eta());
          PhotonEnergy = PhotonEnergy + sortedJets[i].constituents()[j].E();
        }

        // Electrons.
        else if ( abs(event[JCIndex].id()) == 11 ) {  motherE=event[JCIndex].mother1();
          h_Electrons_pt_ -> Fill(sortedJets[i].constituents()[j].pt());
          h_Electrons_eta_-> Fill(sortedJets[i].constituents()[j].eta());
          ElectronEnergy = ElectronEnergy + sortedJets[i].constituents()[j].E();
          if ( abs(event[JCIndex].eta()) < etaMax ) {
            if ( pow2(event[JCIndex].xProd()) + pow2(event[JCIndex].yProd()) + pow2(event[JCIndex].zProd()) <= 25 ) {
              h_Electrons__fX -> Fill(event[JCIndex].xProd()/10.0);
              h_Electrons__fY -> Fill(event[JCIndex].yProd()/10.0);
              h_Electrons__fZ -> Fill(event[JCIndex].zProd()/10.0);
              h__pTQuotient_Electron_Jet -> Fill(sortedJets[i].constituents()[j].pt()/sortedJets[i].pt());
              if ( abs(event[JCIndex].phi() - sortedJets[i].phi_std()) <= PI ) {
                h__D__Electron_Jet -> Fill(sqrt( pow2(event[JCIndex].eta()-sortedJets[i].eta()) + pow2(event[JCIndex].phi()-sortedJets[i].phi_std()) ));
              } else {
                h__D__Electron_Jet -> Fill(sqrt( pow2(event[JCIndex].eta()-sortedJets[i].eta()) + pow2(2*PI-abs(event[JCIndex].phi()-sortedJets[i].phi_std())) ));
              }
              if ( sortedJets[i].constituents()[j].pt() > pTE) { FlagE=true; pTE=sortedJets[i].constituents()[j].pt(); }
              // if ( sortedJets[i].phi_std() < 0 ) printf("%f\n", sortedJets[i].phi_std());
          } }
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
        else if ( event[JCIndex].isNeutral() ) NeutralHadEnergy = NeutralHadEnergy + sortedJets[i].constituents()[j].E();
        // Charged Hadrons.
        else if ( event[JCIndex].isCharged() ) ChargedHadEnergy = ChargedHadEnergy + sortedJets[i].constituents()[j].E();
        //Other Particles.
        else h__OtherPdg_Id -> Fill(event[JCIndex].id());

        // Pdg Id().
        h__Pdg_Id -> Fill(event[JCIndex].id());
      } // j for loop.  Jet Constituents.


      if ( sortedJets[i].pt() <= 100 ) {
        if ( FlagM == true ) h__pTQuotient_1Muon_Jet     -> Fill ( pTM/sortedJets[i].pt() );
        if ( FlagE == true ) h__pTQuotient_1Electron_Jet -> Fill ( pTE/sortedJets[i].pt() );
      } else {
        if ( FlagM == true ) h__pTQuot100__1Muon_Jet     -> Fill ( pTM/sortedJets[i].pt() );
        if ( FlagE == true ) h__pTQuot100__1Electron_Jet -> Fill ( pTE/sortedJets[i].pt() );
      }


      // Energies.
      Float_t JetEnergy = MuonEnergy + PhotonEnergy + ElectronEnergy + NeutralHadEnergy + ChargedHadEnergy;

      h_JetEnergy -> Fill ( JetEnergy / sortedJets[i].E() );

      if ( MuonEnergy > 0.0 ) {
        h_MuonEnergy -> Fill ( MuonEnergy );
        h_Jets__EnergyQuotient_Muon_Jet -> Fill ( MuonEnergy / JetEnergy );  }
      if ( PhotonEnergy > 0.0 ) {
        h_PhotonEnergy -> Fill ( PhotonEnergy );
        h_Jets__EnergyQuotient_Photon_Jet -> Fill ( PhotonEnergy / JetEnergy );  }
      if ( ElectronEnergy > 0.0 ) {
        h_ElectronEnergy -> Fill ( ElectronEnergy );
        h_Jets__EnergyQuotient_Electron_Jet -> Fill ( ElectronEnergy / JetEnergy );  }
      if ( NeutralHadEnergy > 0.0 ) {
        h_NeutralHadEnergy -> Fill ( NeutralHadEnergy );
        h_Jets__EnergyQuotient_NeutralHad_Jet -> Fill ( NeutralHadEnergy / JetEnergy );  }
      if ( ChargedHadEnergy > 0.0 ) {
        h_ChargedHadEnergy -> Fill ( ChargedHadEnergy );
        h_Jets__EnergyQuotient_ChargedHad_Jet -> Fill ( ChargedHadEnergy / JetEnergy );  }


      if ( JetEnergy <= 200 ) {
        /* code */
        if ( MuonEnergy       > 0.0 ) h_Jets__EnergyQuot200_Muon_Jet      -> Fill ( MuonEnergy / JetEnergy );
        if ( PhotonEnergy     > 0.0 ) h_Jets__EnergyQuot200_Photon_Jet    -> Fill ( PhotonEnergy / JetEnergy );
        if ( ElectronEnergy   > 0.0 ) h_Jets__EnergyQuot200_Electron_Jet  -> Fill ( ElectronEnergy / JetEnergy );
        if ( NeutralHadEnergy > 0.0 ) h_Jets__EnergyQuot200_NeutralHad_Jet-> Fill ( NeutralHadEnergy / JetEnergy );
        if ( ChargedHadEnergy > 0.0 ) h_Jets__EnergyQuot200_ChargedHad_Jet-> Fill ( ChargedHadEnergy / JetEnergy );
      } else {
        /* code */
        if ( MuonEnergy       > 0.0 ) h_Jets__Energy200Quot_Muon_Jet      -> Fill ( MuonEnergy / JetEnergy );
        if ( PhotonEnergy     > 0.0 ) h_Jets__Energy200Quot_Photon_Jet    -> Fill ( PhotonEnergy / JetEnergy );
        if ( ElectronEnergy   > 0.0 ) h_Jets__Energy200Quot_Electron_Jet  -> Fill ( ElectronEnergy / JetEnergy );
        if ( NeutralHadEnergy > 0.0 ) h_Jets__Energy200Quot_NeutralHad_Jet-> Fill ( NeutralHadEnergy / JetEnergy );
        if ( ChargedHadEnergy > 0.0 ) h_Jets__Energy200Quot_ChargedHad_Jet-> Fill ( ChargedHadEnergy / JetEnergy );
      }

      // Pdg Id().
      h__JetMother -> Fill(event[JMIndex].id());
    } // i for loop.  Event Jets.

    h_Jets__Multipicity -> Fill(sortedJets.size());

  }  // End of Event loop.

// #######################################################################################################################################################################


  // Statistics. Histograms.
  // pythia.stat();

  h_Muons_pt_ -> Write();
  h_Muons_eta_-> Write();
  // h_Muons__fX -> Write();
  // h_Muons__fY -> Write();
  // h_Muons__fZ -> Write();

  h_Photons_pt_ -> Write();
  h_Photons_eta_-> Write();

  h_Electrons_pt_ -> Write();
  h_Electrons_eta_-> Write();
  // h_Electrons__fX -> Write();
  // h_Electrons__fY -> Write();
  // h_Electrons__fZ -> Write();

  h_Jets_pt_        -> Write();
  h_Jets_eta_       -> Write();
  h_JetEnergy     -> Write();
  h_MuonEnergy      -> Write();
  h_PhotonEnergy    -> Write();
  h_ElectronEnergy  -> Write();
  h_NeutralHadEnergy-> Write();
  h_ChargedHadEnergy-> Write();
  // h_Jets__Multipicity-> Write();

  h__pTQuotient_Muon_Jet   -> Write();
  h__pTQuotient_1Muon_Jet  -> Write();
  h__pTQuot100__1Muon_Jet  -> Write();
  // h__pTQuotient01_Muon_Jet -> Write();
  // h__pTQuotient02_Muon_Jet -> Write();
  // h__pTQuotient03_Muon_Jet -> Write();
  // h__pTQuotient04_Muon_Jet -> Write();
  // h__pTQuotient05_Muon_Jet -> Write();
  // h__pTQuotient21_Muon_Jet -> Write();
  // h__pTQuotientOt_Muon_Jet -> Write();

  h__pTQuotient_Electron_Jet  -> Write();
  h__pTQuotient_1Electron_Jet -> Write();
  h__pTQuot100__1Electron_Jet -> Write();
  // h__pTQuotient01_Electron_Jet-> Write();
  // h__pTQuotient02_Electron_Jet-> Write();
  // h__pTQuotient03_Electron_Jet-> Write();
  // h__pTQuotient04_Electron_Jet-> Write();
  // h__pTQuotient05_Electron_Jet-> Write();
  // h__pTQuotient21_Electron_Jet-> Write();
  // h__pTQuotientOt_Electron_Jet-> Write();

  h_Jets__EnergyQuotient_Muon_Jet       -> Write();
  h_Jets__EnergyQuot200_Muon_Jet        -> Write();
  h_Jets__Energy200Quot_Muon_Jet        -> Write();
  h_Jets__EnergyQuotient_Photon_Jet     -> Write();
  h_Jets__EnergyQuot200_Photon_Jet      -> Write();
  h_Jets__Energy200Quot_Photon_Jet      -> Write();
  h_Jets__EnergyQuotient_Electron_Jet   -> Write();
  h_Jets__EnergyQuot200_Electron_Jet    -> Write();
  h_Jets__Energy200Quot_Electron_Jet    -> Write();
  h_Jets__EnergyQuotient_NeutralHad_Jet -> Write();
  h_Jets__EnergyQuot200_NeutralHad_Jet  -> Write();
  h_Jets__Energy200Quot_NeutralHad_Jet  -> Write();
  h_Jets__EnergyQuotient_ChargedHad_Jet -> Write();
  h_Jets__EnergyQuot200_ChargedHad_Jet  -> Write();
  h_Jets__Energy200Quot_ChargedHad_Jet  -> Write();

  // h__D__Muon_Jet    -> Write();
  // h__D__Electron_Jet-> Write();
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
