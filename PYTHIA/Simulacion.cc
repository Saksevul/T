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
  TFile* OutputFile = new TFile("/home/saksevul/T/PYTHIA/FastJet/ak5FJ-1.root", "RECREATE");
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
  TH1F* h_ak5FastJet_pt_         = new TH1F("ak5FastJet_pt_",  "Espectro de p_{T} de ak5FastJet; p_{T} [GeV]; Ocurrencia", 300, 0, 30);
  TH1F *h_ak5FastJet_eta_        = new TH1F("ak5FastJet_eta_", "Distribución en #eta de ak5FastJet; #eta; Ocurrencia", 119, -5.95, 5.95);
  TH1F* h_ak5FastJet__Multipicity= new TH1F("ak5FastJet__Multiplicidad", "Multiplicidad, de ak5FastJet, por Evento; Multilicidad; Ocurrencia", 120, 0, 120);
  // Cocientes.
  TH1F *h__pTQuotient_Muon_ak5FastJet  = new TH1F("Cociente_pT__Muon-ak5FastJet",  "Cociente p_{T}  Muon / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient_1Muon_ak5FastJet = new TH1F("Cociente_pT<100__1Muon-ak5FastJet",  "Cociente p_{T}  Muon / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuot100__1Muon_ak5FastJet = new TH1F("Cociente_pT>100__1Muon-ak5FastJet",  "Cociente p_{T}  Muon / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient01_Muon_ak5FastJet  = new TH1F("Cociente01_pT__Muon-ak5FastJet",  "Cociente p_{T}  Muon / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient02_Muon_ak5FastJet  = new TH1F("Cociente02_pT__Muon-ak5FastJet",  "Cociente p_{T}  Muon / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient03_Muon_ak5FastJet  = new TH1F("Cociente03_pT__Muon-ak5FastJet",  "Cociente p_{T}  Muon / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient04_Muon_ak5FastJet  = new TH1F("Cociente04_pT__Muon-ak5FastJet",  "Cociente p_{T}  Muon / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient05_Muon_ak5FastJet  = new TH1F("Cociente05_pT__Muon-ak5FastJet",  "Cociente p_{T}  Muon / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient21_Muon_ak5FastJet  = new TH1F("Cociente21_pT__Muon-ak5FastJet",  "Cociente p_{T}  Muon / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotientOt_Muon_ak5FastJet  = new TH1F("CocienteOt_pT__Muon-ak5FastJet",  "Cociente p_{T}  Muon / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient_Electron_ak5FastJet  = new TH1F("Cociente_pT__Electron-ak5FastJet",  "Cociente p_{T}  Electron / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient_1Electron_ak5FastJet = new TH1F("Cociente_pT<100__1Electron-ak5FastJet",  "Cociente p_{T}  Electron / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuot100__1Electron_ak5FastJet = new TH1F("Cociente_pT>100__1Electron-ak5FastJet",  "Cociente p_{T}  Electron / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient01_Electron_ak5FastJet  = new TH1F("Cociente01_pT__Electron-ak5FastJet",  "Cociente p_{T}  Electron / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient02_Electron_ak5FastJet  = new TH1F("Cociente02_pT__Electron-ak5FastJet",  "Cociente p_{T}  Electron / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient03_Electron_ak5FastJet  = new TH1F("Cociente03_pT__Electron-ak5FastJet",  "Cociente p_{T}  Electron / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient04_Electron_ak5FastJet  = new TH1F("Cociente04_pT__Electron-ak5FastJet",  "Cociente p_{T}  Electron / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient05_Electron_ak5FastJet  = new TH1F("Cociente05_pT__Electron-ak5FastJet",  "Cociente p_{T}  Electron / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotient21_Electron_ak5FastJet  = new TH1F("Cociente21_pT__Electron-ak5FastJet",  "Cociente p_{T}  Electron / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  TH1F *h__pTQuotientOt_Electron_ak5FastJet  = new TH1F("CocienteOt_pT__Electron-ak5FastJet",  "Cociente p_{T}  Electron / ak5FastJet; Indice; Ocurrencia", 100, 0, 2);
  // Distancia angular.
  TH1F *h__D__Muon_ak5FastJet     = new TH1F("_D__Muon-ak5FastJet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del Muon al ak5FastJet; Valor; Frecuencia", 120, 0, 1.2);
  TH1F *h__D__Electron_ak5FastJet = new TH1F("_D__Electron-ak5FastJet", "Distancia angular #sqrt{(#Delta#phi)^{2} + (#Delta#eta)^{2}} del Electron al ak5FastJet; Valor; Frecuencia", 120, 0, 1.2);
  // TH1F* h_ak5FastJet__D__Jet_Jet  = new TH1F("ak5FastJet__D__Jet-Jet", "Distancia angular #sqrt{(#Delta#phi_{ij})^{2} + (#Delta#eta_{ij})^{2}} del ak5FastJet_{i} al ak5FastJet_{j}, por Evento; Valor; Ocurrencia", 120, 0, 12);
  // Madre de Jets.
  TH1I*h__JetMother = new TH1I("JetMother", "Madre de Jet; PDG id(); Frecuencia", 43, -21.5, 21.5);
  TH1I*h__OtherMother = new TH1I("OtherMother", "Madre de Jet distinta a Quark o Gluon; PDG id(); Frecuencia", 43, -21.5, 21.5);
  // Id() de partículas.
  TH1I*h__NeutralParticles = new TH1I("NeutralParticles", "Part#acute{i}culas neutras contenidas en Jets; U. A.; Frecuencia", 1, 0, 1);

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
  pythia.readString("PhaseSpace:pTHatMin = 1.0");
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
  int nEvent    = 200000;
  // printf("\n\n\n%i\n\n\n", nEvent);
  // Select common parameters FastJet analyses.
  int    JCA    = -1;     // anti-kT= -1; C/A = 0; kT = 1.
  double R      = 0.5;    // Jet size.
  double pTMin  = 3.0;    // Min jet pT.
  double etaMax = 5.0;    // Pseudorapidity range of detector.
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

      if ( abs(event[i].id()) == 11 && event[i].pT() < 2.5 ) continue;
      else if ( abs(event[i].id()) == 13 && event[i].pT() < 1.0 ) continue;
      else if ( abs(event[i].id()) == 22 && event[i].pT() < 10.0) continue;

      if ( event[i].pT() < 0.7 ) continue;
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

      // Esto es para poder conocer el pdg id de los constituyentes de Jet.
      particleTemp.set_user_info(new MyInfo( i, event[i].xProd(), event[i].yProd(), event[i].zProd()));

      // Store acceptable particles as input to Fastjet.
      // Conversion to PseudoJet is performed automatically with the help of the code in FastJet3.h.
      fjInputs.push_back( particleTemp);  // Agrega un nuevo elemento al final del vector fjInputs.
    }

    // Run Fastjet algorithm and sort jets in pT order.
    vector <fastjet::PseudoJet> inclusiveJets, sortedJets;
    fastjet::ClusterSequence clustSeq(fjInputs, jetDef);
    inclusiveJets = clustSeq.inclusive_jets(pTMin);
    sortedJets    = sorted_by_pt(inclusiveJets);

    // ###################################################################################################################################################
    // Esto ya es de mi propia cosecha.
    for (size_t i=0; i<sortedJets.size(); i++){   Bool_t FlagE=false, FlagM=false; Float_t JMpT = 0.0, pTE=0.0, pTM=0.0;  Int_t motherM, motherE; Int_t JMIndex;

      h_ak5FastJet_pt_ -> Fill(sortedJets[i].pt());
      h_ak5FastJet_eta_-> Fill(sortedJets[i].eta());

      // // Distancia Angular entre Jets de un mismo Evento.
      // for (size_t j=i+1; j<sortedJets.size(); j++) {
      //   if ( abs(sortedJets[i].phi_std()-sortedJets[j].phi_std()) <= PI ) {
      //     h_ak5FastJet__D__Jet_Jet -> Fill( sqrt(pow2(sortedJets[i].eta()-sortedJets[j].eta()) +  pow2(sortedJets[i].phi_std()-sortedJets[j].phi_std())) );
      //   } else {
      //     h_ak5FastJet__D__Jet_Jet -> Fill( sqrt(pow2(sortedJets[i].eta()-sortedJets[j].eta()) +  pow2(2*PI-abs(sortedJets[i].phi_std()-sortedJets[j].phi_std()))) );
      // } }-

      for (size_t j=0; j<sortedJets[i].constituents().size(); j++) {   Int_t JCIndex = sortedJets[i].constituents()[j].user_info<MyInfo>().Index(); // Event Index.

        if ( event[JCIndex].isNeutral() )   h__NeutralParticles -> Fill(0);

        // Para conocer el partón madre el Jet en función de su partícula más energética.
        if ( JMpT < sortedJets[i].constituents()[j].pt() ) {  JMpT = sortedJets[i].constituents()[j].pt();  JMIndex = event[JCIndex].mother1();
          while ( abs(event[JMIndex].id()) > 21 ) { JMIndex=event[JMIndex].mother1(); }
        }

        if ( abs(event[JCIndex].id()) == 13 ) {  motherM=event[JCIndex].mother1();
          h_Muons_pt_ -> Fill(sortedJets[i].constituents()[j].pt());
          h_Muons_eta_-> Fill(sortedJets[i].constituents()[j].eta());
          if ( event[JCIndex].pT() > 5.5 && abs(event[JCIndex].eta()) < 1.48 ) {
            if ( pow2(event[JCIndex].xProd()) + pow2(event[JCIndex].yProd()) + pow2(event[JCIndex].zProd()) <= 25 ) {
              h_Muons__fX -> Fill(event[JCIndex].xProd()/10.0);
              h_Muons__fY -> Fill(event[JCIndex].yProd()/10.0);
              h_Muons__fZ -> Fill(event[JCIndex].zProd()/10.0);
              h__pTQuotient_Muon_ak5FastJet -> Fill(sortedJets[i].constituents()[j].pt()/sortedJets[i].pt());
              if ( abs(event[JCIndex].phi() - sortedJets[i].phi_std()) <= PI ) {
                h__D__Muon_ak5FastJet -> Fill(sqrt( pow2(event[JCIndex].eta()-sortedJets[i].eta()) + pow2(event[JCIndex].phi()-sortedJets[i].phi_std()) ));
              } else {
                h__D__Muon_ak5FastJet -> Fill(sqrt( pow2(event[JCIndex].eta()-sortedJets[i].eta()) + pow2(2*PI-abs(event[JCIndex].phi()-sortedJets[i].phi_std())) ));
              }
              if ( sortedJets[i].constituents()[j].pt() > pTM) { FlagM=true; pTM=sortedJets[i].constituents()[j].pt(); }  // Para obtener información del Muón màs energético.
          } }
          while ( abs(event[motherM].id()) > 21 ) motherM=event[motherM].mother1();
          if ( abs(event[motherM].id()) == 21 ) {     h__pTQuotient21_Muon_ak5FastJet -> Fill ( sortedJets[i].constituents()[j].pt()/sortedJets[i].pt() );  }
          else if ( abs(event[motherM].id()) == 1 ) { h__pTQuotient01_Muon_ak5FastJet -> Fill ( sortedJets[i].constituents()[j].pt()/sortedJets[i].pt() );  }
          else if ( abs(event[motherM].id()) == 2 ) { h__pTQuotient02_Muon_ak5FastJet -> Fill ( sortedJets[i].constituents()[j].pt()/sortedJets[i].pt() );  }
          else if ( abs(event[motherM].id()) == 3 ) { h__pTQuotient03_Muon_ak5FastJet -> Fill ( sortedJets[i].constituents()[j].pt()/sortedJets[i].pt() );  }
          else if ( abs(event[motherM].id()) == 4 ) { h__pTQuotient04_Muon_ak5FastJet -> Fill ( sortedJets[i].constituents()[j].pt()/sortedJets[i].pt() );  }
          else if ( abs(event[motherM].id()) == 5 ) { h__pTQuotient05_Muon_ak5FastJet -> Fill ( sortedJets[i].constituents()[j].pt()/sortedJets[i].pt() );  }
          else {
            h__pTQuotientOt_Muon_ak5FastJet -> Fill ( sortedJets[i].constituents()[j].pt()/sortedJets[i].pt() );
            h__OtherMother -> Fill(event[motherM].id());
          }
        }


        else if ( abs(event[JCIndex].id()) == 11 ) {  motherE=event[JCIndex].mother1();
          h_Electrons_pt_ -> Fill(sortedJets[i].constituents()[j].pt());
          h_Electrons_eta_-> Fill(sortedJets[i].constituents()[j].eta());
          if ( event[JCIndex].pT() > 5.5 && abs(event[JCIndex].eta()) < 1.48 ) {
            if ( pow2(event[JCIndex].xProd()) + pow2(event[JCIndex].yProd()) + pow2(event[JCIndex].zProd()) <= 25 ) {
              h_Electrons__fX -> Fill(event[JCIndex].xProd()/10.0);
              h_Electrons__fY -> Fill(event[JCIndex].yProd()/10.0);
              h_Electrons__fZ -> Fill(event[JCIndex].zProd()/10.0);
              h__pTQuotient_Electron_ak5FastJet -> Fill(sortedJets[i].constituents()[j].pt()/sortedJets[i].pt());
              if ( abs(event[JCIndex].phi() - sortedJets[i].phi_std()) <= PI ) {
                h__D__Electron_ak5FastJet -> Fill(sqrt( pow2(event[JCIndex].eta()-sortedJets[i].eta()) + pow2(event[JCIndex].phi()-sortedJets[i].phi_std()) ));
              } else {
                h__D__Electron_ak5FastJet -> Fill(sqrt( pow2(event[JCIndex].eta()-sortedJets[i].eta()) + pow2(2*PI-abs(event[JCIndex].phi()-sortedJets[i].phi_std())) ));
              }
              if ( sortedJets[i].constituents()[j].pt() > pTE) { FlagE=true; pTE=sortedJets[i].constituents()[j].pt(); }
              // if ( sortedJets[i].phi_std() < 0 ) printf("%f\n", sortedJets[i].phi_std());
          } }
          while ( abs(event[motherE].id()) > 21 ) motherE=event[motherE].mother1();
          // const char * nombre; nombre=event[motherE].name().c_str();
          // printf(" Madre final de este Electron = %s.\n", nombre);
          if ( abs(event[motherE].id()) == 21 ) {     h__pTQuotient21_Electron_ak5FastJet -> Fill ( sortedJets[i].constituents()[j].pt()/sortedJets[i].pt() );  }
          else if ( abs(event[motherE].id()) == 1 ) { h__pTQuotient01_Electron_ak5FastJet -> Fill ( sortedJets[i].constituents()[j].pt()/sortedJets[i].pt() );  }
          else if ( abs(event[motherE].id()) == 2 ) { h__pTQuotient02_Electron_ak5FastJet -> Fill ( sortedJets[i].constituents()[j].pt()/sortedJets[i].pt() );  }
          else if ( abs(event[motherE].id()) == 3 ) { h__pTQuotient03_Electron_ak5FastJet -> Fill ( sortedJets[i].constituents()[j].pt()/sortedJets[i].pt() );  }
          else if ( abs(event[motherE].id()) == 4 ) { h__pTQuotient04_Electron_ak5FastJet -> Fill ( sortedJets[i].constituents()[j].pt()/sortedJets[i].pt() );  }
          else if ( abs(event[motherE].id()) == 5 ) { h__pTQuotient05_Electron_ak5FastJet -> Fill ( sortedJets[i].constituents()[j].pt()/sortedJets[i].pt() );  }
          else {
            h__pTQuotientOt_Electron_ak5FastJet -> Fill ( sortedJets[i].constituents()[j].pt()/sortedJets[i].pt() );
            h__OtherMother -> Fill(event[motherE].id());
          }
        }


        else if ( abs(event[JCIndex].id()) == 22 ) {
          h_Photons_pt_ -> Fill(sortedJets[i].constituents()[j].pt());
          h_Photons_eta_-> Fill(sortedJets[i].constituents()[j].eta());
        }
      } // j for loop.


      if ( sortedJets[i].pt() <= 100 ) {
        if ( FlagM == true ) h__pTQuotient_1Muon_ak5FastJet     -> Fill ( pTM/sortedJets[i].pt() );
        if ( FlagE == true ) h__pTQuotient_1Electron_ak5FastJet -> Fill ( pTE/sortedJets[i].pt() );
      } else {
        if ( FlagM == true ) h__pTQuot100__1Muon_ak5FastJet     -> Fill ( pTM/sortedJets[i].pt() );
        if ( FlagE == true ) h__pTQuot100__1Electron_ak5FastJet -> Fill ( pTE/sortedJets[i].pt() );
      }

      h__JetMother -> Fill(event[JMIndex].id());
    }

    h_ak5FastJet__Multipicity -> Fill(sortedJets.size());

  }  // End of event loop.

//--------------------------------------------------------------------------------------------------------------


  // Statistics. Histograms.
  // pythia.stat();

  h_Muons_pt_ -> Write();
  h_Muons_eta_-> Write();
  h_Muons__fX -> Write();
  h_Muons__fY -> Write();
  h_Muons__fZ -> Write();

  h_Photons_pt_ -> Write();
  h_Photons_eta_-> Write();

  h_Electrons_pt_ -> Write();
  h_Electrons_eta_-> Write();
  h_Electrons__fX -> Write();
  h_Electrons__fY -> Write();
  h_Electrons__fZ -> Write();

  h_ak5FastJet_pt_         -> Write();
  h_ak5FastJet_eta_        -> Write();
  h_ak5FastJet__Multipicity-> Write();

  h__pTQuotient_Muon_ak5FastJet   -> Write();
  h__pTQuotient_1Muon_ak5FastJet  -> Write();
  h__pTQuot100__1Muon_ak5FastJet  -> Write();
  h__pTQuotient01_Muon_ak5FastJet -> Write();
  h__pTQuotient02_Muon_ak5FastJet -> Write();
  h__pTQuotient03_Muon_ak5FastJet -> Write();
  h__pTQuotient04_Muon_ak5FastJet -> Write();
  h__pTQuotient05_Muon_ak5FastJet -> Write();
  h__pTQuotient21_Muon_ak5FastJet -> Write();
  h__pTQuotientOt_Muon_ak5FastJet -> Write();

  h__pTQuotient_Electron_ak5FastJet  -> Write();
  h__pTQuotient_1Electron_ak5FastJet -> Write();
  h__pTQuot100__1Electron_ak5FastJet -> Write();
  h__pTQuotient01_Electron_ak5FastJet-> Write();
  h__pTQuotient02_Electron_ak5FastJet-> Write();
  h__pTQuotient03_Electron_ak5FastJet-> Write();
  h__pTQuotient04_Electron_ak5FastJet-> Write();
  h__pTQuotient05_Electron_ak5FastJet-> Write();
  h__pTQuotient21_Electron_ak5FastJet-> Write();
  h__pTQuotientOt_Electron_ak5FastJet-> Write();

  h__D__Muon_ak5FastJet    -> Write();
  h__D__Electron_ak5FastJet-> Write();
  // h_ak5FastJet__D__Jet_Jet -> Write();

  // Madre de Jets.
  h__OtherMother -> Write();
  h__JetMother   -> Write();
  h__NeutralParticles -> Write();

  // Done.
  delete OutputFile;
  return 0;
}
