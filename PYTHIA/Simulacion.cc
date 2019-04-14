// PYTHIA is licenced under the GNU GPL v2 or later, see COPYING for details.

// This is a simple test program.
// It compares SlowJet, FJcore and FastJet, showing that they
// find the same jets.

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

// The FastJet3.h header enables automatic initialisation of
// fastjet::PseudoJet objects from Pythia8 Particle and Vec4 objects,
// as well as advanced features such as access to (a copy of)
// the original Pythia 8 Particle directly from the PseudoJet,
// and fastjet selectors that make use of the Particle properties.
// See the extensive comments in the header file for further details
// and examples.
#include "Pythia8Plugins/FastJet3.h"

// Definido para poder utilizar información definida por el usuario.
#include "fastjet/MyInfo.hh"

using namespace Pythia8;

//----------------------------------------------------------------------------------------------------------------
int main(int argc, char* argv[]) {   Float_t PI=3.1415927;

  // Create the ROOT application environment.
  TApplication theApp("hist", &argc, argv);
  // Create file on which histogram(s) can be saved.
  TFile* OutputFile = new TFile("ak5FJ-0.root", "RECREATE");
  // Histograms.
  TH1F* h_ak5FastJet__pt          = new TH1F("ak5FastJet__pT", "Espectro de p_{T} de ak5FastJet; p_{T} [GeV]; Ocurrencia", 3200, 0, 3200);
  TH1F* h_ak5FastJet__phi         = new TH1F("ak5FastJet__phi", "Distribución en #phi de ak5FastJet; Valor; Ocurrencia", 126, 0, 2*PI);
  TH1F* h_ak5FastJet__D_Jet_Jet   = new TH1F("ak5FastJet__DistanciaAngular_Jet_Jet", "Distancia angular #sqrt{(#Delta#phi_{ij})^{2} + (#Delta#eta_{ij})^{2}} del ak5FastJet_{i} al ak5FastJet_{j}, por Evento; Valor; Ocurrencia", 120, 0, 12);
  TH1F* h_ak5FastJet__Multipicity = new TH1F("ak5FastJet__Multiplicidad", "Multiplicidad, de ak5FastJet, por Evento; Multilicidad; Ocurrencia", 120, 0, 120);
  TH1D *h_Electrons_fX_ = new TH1D("Electrons_fX_", "Vertice en X de Electrones contenidos en ak5FastJet; Distancia [cm]; Frecuencia", 481, -24.05, 24.05);
  TH1D *h_Electrons_fY_ = new TH1D("Electrons_fY_", "Vertice en Y de Electrones contenidos en ak5FastJet; Distancia [cm]; Frecuencia", 481, -24.05, 24.05);
  TH1D *h_Electrons_fZ_ = new TH1D("Electrons_fZ_", "Vertice en Z de Electrones contenidos en ak5FastJet; Distancia [cm]; Frecuencia", 481, -24.05, 24.05);
  TH1F *h__pTQuotient_gsfElectron_ak5PFJet  = new TH1F("Cociente_pT__Electron-ak5FastJet",  "Cociente p_{T}  gsfElectron / ak5PFJet; Indice; Ocurrencia", 100, 0, 2);
  // Generator. Shorthand for event.
  Pythia pythia;
  Event& event = pythia.event;
  // Process selection.
  pythia.readString("HardQCD:all = on");
  pythia.readString("PhaseSpace:pTHatMin = 300.0");
  // No event record printout.
  pythia.readString("Next:numberShowInfo = 0");
  pythia.readString("Next:numberShowProcess = 0");
  pythia.readString("Next:numberShowEvent = 0");
  // LHC initialization.
  pythia.readString("Beams:eCM = 7000.0");
  pythia.init();


  // Number of events, generated and listed ones (for jets).
  int nEvent    = 9600;
  // Select common parameters FastJet analyses.
  int    JCA    = -1;     // anti-kT= - -1; C/A = 0; kT = 1.
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
    fjInputs.resize(0);    Vec4   pTemp;    double mTemp;    int nAnalyze = 0;

    for (int i = 0; i < event.size(); ++i) if (event[i].isFinal()) {      // Require visible/charged particles inside detector.
      if      (select > 2 &&  event[i].isNeutral() ) continue;
      else if (select == 2 && !event[i].isVisible() ) continue; // Particle with strong or electric charge, or composed of ones having it.
      if (etaMax < 20. && abs(event[i].eta()) > etaMax) continue;

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

      // Esto es para poder conocer el pdg id de los constituyentes de Jet.
      particleTemp.set_user_info(new MyInfo(event[i].id(), event[i].xProd(), event[i].yProd(), event[i].zProd()));

      // if (event[i].id() == 21) {
      //
      //   const char * nombre; nombre=event[i].name().c_str();
      //   printf("\n %i : %i/%i, Nombre: %s \t | \t", iEvent, i, event.size(), nombre);
      //
      //   for (size_t j=event[i].motherList().size(); j-->0;) {
      //     const char * madre; madre=event[event[i].motherList()[j]].name().c_str();
      //     printf(" %s \t",  madre );
      //   }
      // }

      // Store acceptable particles as input to Fastjet.
      // Conversion to PseudoJet is performed automatically with the help of the code in FastJet3.h.
      fjInputs.push_back( particleTemp);  // Agrega un nuevo elemento al final del vector fjInputs.
      ++nAnalyze;

    }

    // Run Fastjet algorithm and sort jets in pT order.
    vector <fastjet::PseudoJet> inclusiveJets, sortedJets;
    fastjet::ClusterSequence clustSeq(fjInputs, jetDef);
    inclusiveJets = clustSeq.inclusive_jets(pTMin);
    sortedJets    = sorted_by_pt(inclusiveJets);

    // Esto ya es de mi propia cosecha.
    for (size_t i=0; i<sortedJets.size(); i++){

      h_ak5FastJet__pt -> Fill(sortedJets[i].pt());
      h_ak5FastJet__phi-> Fill(sortedJets[i].phi_std());

      for (size_t j=i+1; j<sortedJets.size(); j++) {
        if ( abs(sortedJets[i].phi_std()-sortedJets[j].phi_std()) < PI ) {
          h_ak5FastJet__D_Jet_Jet -> Fill( sqrt(pow2(sortedJets[i].eta()-sortedJets[j].eta()) +  pow2(sortedJets[i].phi_std()-sortedJets[j].phi_std())) );
        } else {
          h_ak5FastJet__D_Jet_Jet -> Fill( sqrt(pow2(sortedJets[i].eta()-sortedJets[j].eta()) +  pow2(2*PI-abs(sortedJets[i].phi_std()-sortedJets[j].phi_std()))) );
      } }

      for (size_t j=0; j<sortedJets[i].constituents().size(); j++) {
        if (sortedJets[i].constituents()[j].user_info<MyInfo>().pdg_id() == 11) { // printf("%f %f %f \n", sortedJets[i].constituents()[j].user_info<MyInfo>().vertex_fX(),
        // sortedJets[i].constituents()[j].user_info<MyInfo>().vertex_fY(), sortedJets[i].constituents()[j].user_info<MyInfo>().vertex_fZ() );
          h_Electrons_fX_ -> Fill(sortedJets[i].constituents()[j].user_info<MyInfo>().vertex_fX()/10.0);
          h_Electrons_fY_ -> Fill(sortedJets[i].constituents()[j].user_info<MyInfo>().vertex_fY()/10.0);
          h_Electrons_fZ_ -> Fill(sortedJets[i].constituents()[j].user_info<MyInfo>().vertex_fZ()/10.0);
          h__pTQuotient_gsfElectron_ak5PFJet -> Fill(sortedJets[i].constituents()[j].pt()/sortedJets[i].pt());
        }
      }
    }

    h_ak5FastJet__Multipicity -> Fill(sortedJets.size());

  }  // End of event loop.
//----------------------------------------------------------------------------------------------------------------


  // Statistics. Histograms.
  // pythia.stat();

  h_ak5FastJet__pt          -> Scale(1.0/h_ak5FastJet__pt->Integral());
  h_ak5FastJet__phi         -> Scale(1.0/h_ak5FastJet__phi->Integral());
  h_ak5FastJet__D_Jet_Jet   -> Scale(1.0/h_ak5FastJet__D_Jet_Jet->Integral());
  h_ak5FastJet__Multipicity -> Scale(1.0/h_ak5FastJet__Multipicity->Integral());

  h_ak5FastJet__pt          -> Write();
  h_ak5FastJet__phi         -> Write();
  h_ak5FastJet__D_Jet_Jet   -> Write();
  h_ak5FastJet__Multipicity -> Write();

  h_Electrons_fX_ -> Write();
  h_Electrons_fY_ -> Write();
  h_Electrons_fZ_ -> Write();
  h__pTQuotient_gsfElectron_ak5PFJet -> Write();

  // Done.
  delete OutputFile;
  return 0;
}
