

// -*- C++ -*-
//
// Package:    Analyzer
// Class:      Analyzer
// 
/**\class Analyzer Analyzer.cc Analysis/Analyzer/src/Analyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  
//         Created:  Mon Aug 28 05:16:01 GMT 2017
// $Id$
//
//


// system include files
#include<vector>
#include<TLorentzVector.h>
#include<cmath>
#include <memory>
#include "vector"
#include "algorithm"
#include <TH1.h>
#include <TFile.h>
#include <TTree.h>
#include <TROOT.h>
#include "DataFormats/TrackReco/interface/TrackFwd.h"
// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "DataFormats/HLTReco/interface/TriggerObject.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "HLTrigger/HLTcore/interface/HLTConfigData.h"
#include "DataFormats/JetReco/interface/PFJet.h"
#include "DataFormats/JetReco/interface/PFJetCollection.h"

#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/TrackReco/interface/Track.h"

//ClassImp(Lepton)
//
// class declaration
//

//struct Lepton {

//float pt;
//float eta;


//};

class Analyzer : public edm::EDAnalyzer {
   public:
      explicit Analyzer(const edm::ParameterSet&);
      ~Analyzer();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() ;
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;
              bool cmsStandardCuts(const edm::Event&, const edm::EventSetup&);
      virtual void beginRun(edm::Run const&, edm::EventSetup const&);
      virtual void endRun(edm::Run const&, edm::EventSetup const&);
      virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
      virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
      TFile * file;
     // TH1F * h1;
      //TH1F * h2;
      //TH1F * histo;
      //TH1F * passHist;
    
      //TH1F * top2Mass_hist;
      TH1F * h_mass_mu;
      TH1F * h_mass_e;
      TH1F * h_mEffSimu;
      TH1F * h_mEffSimuGen;
      //TH1F * allHist;
      //TH1F * divHist;
      //TH1F * jetMass;
      //TH1F * jetPt;
      //TH1F * jetPt_trig;
      TH1F * h_Lxy_e;
      TH1F * h_Lxy_m;
      TTree * myTree;
      int e_count, m_count,if1,if2,if3,ev, numElectrones, numPositrones, corr, event;
     // TCanvas * myCanvas;
     // Lepton * mylep;
      //struct tracks_ {float pt; float  eta;};
      //struct myStruct_ {std::vector<float> track_pt; std::vector<float> track_eta;
                            // float pt; float eta;
                           
                           // };
      //myStruct_ leptons;
      std::vector<float> myVec,p_vec, e_vec;
      std::vector<float>ptVec;
      std::vector<int>index;
      TLorentzVector v1, v2, v3, v4, vTot, ve, vmu, top2;
      double maxMassE, maxMassM;
      //myStruct_ all;
      //myStruct_ notLeptons; 
      //tracks_ dummyTrack;
      //TROOT * gROOT;
     // HLTConfigData CD;
      // ----------member data ---------------------------
      edm::InputTag trackTags_; //used to select what tracks to read from configuration file
};

/*class lepton_event{
public:
  lepton lep;


};*/


//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
Analyzer::Analyzer(const edm::ParameterSet& iConfig)
:
 trackTags_(iConfig.getUntrackedParameter<edm::InputTag>("tracks"))

{
   //now do what ever initialization is needed

}


Analyzer::~Analyzer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
Analyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
	 ev++;
   using namespace edm;

  using reco::TrackCollection;

   Handle<TrackCollection> tracks;
   std::vector<Handle<TrackCollection>> track_vec;
    std::vector<TrackCollection::const_iterator> itTrack_vecP;
    std::vector<TrackCollection::const_iterator> itTrack_vecP2;
    std::vector<TrackCollection::const_iterator> itTrack_vecM;
    //std::vector<double> itTrackEnergyP, itTrackEnergyM;
   iEvent.getByLabel(trackTags_,tracks);
   std::cout<<"tracktags_: "<<trackTags_<<std::endl;
     
       
edm::InputTag trigEventTag("hltTriggerSummaryAOD","","HLT"); //make sure have correct process on MC
//data process=HLT, MC depends, Spring11 is REDIGI311X
edm::Handle<trigger::TriggerEvent> trigEvent; 
iEvent.getByLabel(trigEventTag,trigEvent);

edm::Handle<edm::TriggerResults> trigResults; //our trigger result object
edm::InputTag trigResultsTag("TriggerResults","","HLT"); //make sure have correct process on MC
//data process=HLT, MC depends, Spring11 is REDIGI311X
iEvent.getByLabel(trigResultsTag,trigResults);
//const edm::TriggerNames& trigNames = iEvent.triggerNames(*trigResults);



   
/***************************************************************************Standar CMS Event Cuts*/
std::cout<<"standard cuts "<<cmsStandardCuts(iEvent,iSetup)<<std::endl;
 
/**************************************************************************Electron Identification Cuts*/
//Tracks with the following characteristics are looked for:
// high purity
// pt>41
// at leas 6 hits of wich at least 2 are 3D
// eta < 2
// transverse impact parameter significance > 3
std::string e_filterName("hltDoublePhoton33EgammaLHEDoubleFilter"); // dataset photones (para filtrar electrones)
//std::string e_filterName("hltDoubleEG43HEVTDoubleFilter"); // simulacion
 


//double d0, sigma;
 int electron_candidates = 0;
//it is important to specify the right HLT process for the filter, not doing this is a common bug
trigger::size_type e_filterIndex = trigEvent->filterIndex(edm::InputTag(e_filterName,"",trigEventTag.process())); 
if(e_filterIndex<trigEvent->sizeFilters()){ 
    const trigger::Keys& trigKeys = trigEvent->filterKeys(e_filterIndex); 
    const trigger::TriggerObjectCollection & e_trigObjColl(trigEvent->getObjects());
     std::cout<<"primer if    cambio******************"<<std::endl;
     
     
    
p_vec.clear();
e_vec.clear();
itTrack_vecP.clear();
itTrack_vecM.clear();
//itTrackEnergyP.clear();
//itTrackEnergyM.clear();
int trackC; // cuenta las vueltas del track loop
trackC = 0;
for(TrackCollection::const_iterator itTrack = tracks->begin();
	   
       itTrack != tracks->end();
       ++itTrack){ 
		   
		   trackC ++;
		   //std::cout<<"                vuelta "<<trackC<< " del loop de tracks"<<std::endl;
		   // d0 = itTrack->dxy();
		    //sigma = itTrack->dxyError();
		    //tips = d0/sigma;                                /*      Electrons      */
		   if (/*itTrack->quality(/*(reco::TrackBase::TrackQuality)2) && itTrack->pt() > 41 /*&&  itTrack->found() > 6 &&  itTrack->eta()<2 &&  tips >3*/ true ){
			   
			   corr ++;
			    //std::cout<<"charge "<<itTrack->charge()<<std::endl;
			    //std::cout<<"primary vertex "<<itTrack->dxy()<<std::endl;
		      if1++;
			    
			   int objC; //para contar el numero de vueltas en el loop de triger objects
			   objC = 0; 
			      //now loop of the trigger objects passing filter
                for(trigger::Keys::const_iterator keyIt=trigKeys.begin();keyIt!=trigKeys.end();++keyIt){ 
                const trigger::TriggerObject& obj = e_trigObjColl[*keyIt];
			       if2 ++;
			       objC ++;
			       //std::cout<<"                        vuelta "<<objC<< " del loop de objetos"<<std::endl;
			             double dEta2 =pow( itTrack->eta()-obj.eta(),2); 
						 double dPhi2 =pow( itTrack->phi()-obj.phi(),2);
						 double dR = sqrt(dPhi2+dEta2);
						 double ptotT , ptotO;
						 ptotT = sqrt((itTrack->pt())*(itTrack->pt()) +itTrack->pz()*itTrack->pz());
						 ptotO = sqrt(obj.pt()*obj.pt() + obj.pz()*obj.pz());
						 
						 std::cout<<"energia del trigger object: "<<obj.energy()<<" pt: "<<obj.pt()<<" eta: "<<obj.eta()<<std::endl;
						  if((dR<0.1)&& abs(ptotT - ptotO) < 3){electron_candidates++; e_count++;    if3++; 
							 // std::cout<<"momento: "<<itTrack->pt()<<std::endl;
							    p_vec.push_back(itTrack->pt());
							    e_vec.push_back(obj.energy());
							    if(itTrack->charge() == 1){
							    itTrack_vecP.push_back(itTrack);
							   // itTrackEnergyP.push_back(obj.energy());                          
							    std::cout<<"                               energia (matching loop) +: "<< obj.energy()<<std::endl;
							    std::cout<<"                               pt track: "<< itTrack->pt()<<" pt obj: "<<obj.pt()<<std::endl;
							                               }
							    else if (itTrack->charge() == -1){
							    itTrack_vecM.push_back(itTrack);
							   // itTrackEnergyM.push_back(obj.energy());
							    std::cout<<"                               energia (matching loop) -: "<< obj.energy()<<std::endl;
							    std::cout<<"                               pt track: "<< itTrack->pt()<<" pt obj: "<<obj.pt()<<std::endl;                   
							                        }
							    
							
							    
							    
							    
							    
							    
							    }
						  
		            }
		           // for(unsigned int i = 0; i<itTrack_vec.size(); i ++){std::cout<<"hi"<<std::endl;}
			   
			     }
			   }  //falta numero de 3d hitts
		    
		     

   
}
 std::cout<<"Matching Done"<<"\n"<<std::endl;
 //for(unsigned int i = 0; i<itTrack_vecP.size(); i ++){std::cout<<itTrack_vecP[i]->pt()<<std::endl;}
 std::cout<<" Electron candidates " <<electron_candidates<<std::endl;
 std::cout<<"numero de positivos " <<itTrack_vecP.size()<<std::endl;
 std::cout<<"numero de negativos "<<itTrack_vecM.size()<<std::endl;
 std::cout<<"numoero total "<<itTrack_vecM.size() + itTrack_vecP.size()<<std::endl;
 if(itTrack_vecM.size() + itTrack_vecP.size()>1){std::cout<<"mas de un electron"<<std::endl;}
 
 
 /************************************************************************** X mass and matching*/
 
for(unsigned int i = 0; i<itTrack_vecP.size(); i ++){
	std::cout<<"for 1"<<std::endl;
	float dv,dx,dy,dz ;
	dv = 99999;
	int doubleCountErrP = 0;
	bool doubleCountErrM = false;
	std::vector<int> doubleCountErrV;
	for (unsigned int i = 0; i< itTrack_vecM.size(); i++){
		doubleCountErrV.push_back(1);
	  std::cout<<" hola"<<std::endl;
	  } 
    for(unsigned int j = 0; j<itTrack_vecM.size(); j ++){
    
      dx = itTrack_vecP[i]->vx() - itTrack_vecM[j]->vx();
      dy = itTrack_vecP[i]->vy() - itTrack_vecM[j]->vy();
      dz = itTrack_vecP[i]->vz() - itTrack_vecM[j]->vz();
      dv = sqrt(dx*dx + dy*dy +dz*dz);
      std::cout<<" for 2"<<std::endl;
      if(dv< 0.1){
		   if ( doubleCountErrV[j] ==0){
				doubleCountErrM = true;
			    }
		   doubleCountErrV[j] = 0;
		   doubleCountErrP ++;
		  
							    
		  std::cout<<"match"<<std::endl;
		  
		  std::cout<<"Vertex displacement: "<<dv <<std::endl;
	      // calcular masa invariante de par de electrones
	      double px, py, pz, E,E1,E2, eMass;
	      px = itTrack_vecP[i]->px() + itTrack_vecM[j]->px();
	      py = itTrack_vecP[i]->py() + itTrack_vecM[j]->py();
	      pz = itTrack_vecP[i]->pz() + itTrack_vecM[j]->pz();
	      //E = itTrackEnergyP[i] + itTrackEnergyM[j];
	      E1 = sqrt(itTrack_vecP[i]->pt()*itTrack_vecP[i]->pt() + itTrack_vecP[i]->pz()*itTrack_vecP[i]->pz());
	      E2 = sqrt(itTrack_vecM[j]->pt()*itTrack_vecM[j]->pt() + itTrack_vecM[j]->pz()*itTrack_vecM[j]->pz());
	      E  = E1 + E2;
	      
	      std::cout<<"px: "<<px<<" py: "<<py<<" pz: "<<pz<< " E: "<<E<<" i: "<<i<<" j: "<<j<<std::endl;
	     // std::cout<<"energia +"<<itTrackEnergyP[i]<<" energia - :"<<itTrackEnergyM[j]<<std::endl;
	      eMass = sqrt(E*E - px*px -py*py -pz*pz);
	      std::cout<<"masa calculada: "<<eMass<<std::endl;
	      h_mass_e->Fill(eMass);
              if (eMass>maxMassE)
				{maxMassE=eMass; }
		  } 
		  
	 
	 
 }
 
if(dv< 0.1){
		  
	// encontrar Lxy/S_xy
							    
	double vx, vy, L;
	vx = itTrack_vecP[i]->vx();
	vy = itTrack_vecP[i]->vy();
	L = sqrt(vx*vx + vy*vy);
	h_Lxy_e->Fill(L);
        }
if (doubleCountErrP> 1) {std::cout<<"Warning: double match (same positron matched twice)"<<std::endl;}
if (doubleCountErrM){std::cout<<"Warning: double match (same electron , matched twice)"<<std::endl;}
 }
 
/**************************************************************************Muon Identification Cuts*/
 //Tracks with the following characteristics are looked for:
// high purity
// pt > 33
// at leas 6 hits of wich at least 2 are 3D
// eta < 2
// transverse impact parameter significance > 2

 int muon_candidates = 0;



//std::string m_filterName("hltHT250"); 
std::string m_filterName("hltL2DoubleMu23NoVertexL2PreFiltered"); 



//it is important to specify the right HLT process for the filter, not doing this is a common bug
trigger::size_type m_filterIndex = trigEvent->filterIndex(edm::InputTag(m_filterName,"",trigEventTag.process())); 
if(m_filterIndex<trigEvent->sizeFilters()){ 
    const trigger::Keys& trigKeys = trigEvent->filterKeys(m_filterIndex); 
    const trigger::TriggerObjectCollection & m_trigObjColl(trigEvent->getObjects());
    

   
p_vec.clear();
e_vec.clear();
itTrack_vecP.clear();
itTrack_vecP2.clear();
itTrack_vecM.clear();
//itTrackEnergyP.clear();
//itTrackEnergyM.clear(); 

std::cout<<"primero "<<itTrack_vecP.size()<<std::endl;

 
 for(TrackCollection::const_iterator itTrack = tracks->begin();
       itTrack != tracks->end();
       ++itTrack){ 
		   // d0 = itTrack->dxy();
		    //sigma = itTrack->dxyError();
		    //tips = d0/sigma;
		   if (/*itTrack->quality((reco::TrackBase::TrackQuality)2) && itTrack->pt() > 33 && /*itTrack->found() > 6 && itTrack->eta()<2 && tips >2*/ true){
			   
			 
	            //now loop of the trigger objects passing filter
                for(trigger::Keys::const_iterator keyIt=trigKeys.begin();keyIt!=trigKeys.end();++keyIt){ 
                const trigger::TriggerObject& obj = m_trigObjColl[*keyIt];
			       std::cout<<"energia del trigger object: "<<obj.energy()<<" pt: "<<obj.pt()<<" eta: "<<obj.eta()<<std::endl;
			      ///std::cout<<"                        vuelta "<<objC<< " del loop de objetos"<<std::endl;
			             double dEta2 =pow( itTrack->eta()-obj.eta(),2); 
						 double dPhi2 =pow( itTrack->phi()-obj.phi(),2);
						 double dR = sqrt(dPhi2+dEta2);
						 
						 //std::cout<<"energia del trigger object: "<<obj.energy()<<" pt: "<<obj.pt()<<" eta: "<<obj.eta()<<std::endl;
						  double ptotT , ptotO;
						 ptotT = sqrt((itTrack->pt())*(itTrack->pt()) +itTrack->pz()*itTrack->pz());
						 ptotO = sqrt(obj.pt()*obj.pt() + obj.pz()*obj.pz());
						 
						 //std::cout<<"energia del trigger object: "<<obj.energy()<<" pt: "<<obj.pt()<<" eta: "<<obj.eta()<<std::endl;
						  if((dR<0.1)&&(abs(ptotT - ptotO) < 3)){muon_candidates++; m_count ++;    if3++; 
							 // std::cout<<"momento: "<<itTrack->pt()<<std::endl;
							   // p_vec.push_back(itTrack->pt());
							    //e_vec.push_back(obj.energy());
							    if(itTrack->charge() == 1){
							    itTrack_vecP2.push_back(itTrack);
							    //itTrackEnergyP.push_back(obj.energy());                          
							    std::cout<<"                               energia (matching loop muon ) +: "<< obj.energy()<<std::endl;
							    std::cout<<"                               pt track: "<< itTrack->pt()<<" pt obj: "<<obj.pt()<<std::endl;
							                               }
							    else if (itTrack->charge() == -1){
							    itTrack_vecM.push_back(itTrack);
							    //itTrackEnergyM.push_back(obj.energy());
							    std::cout<<"                               energia (matching loop muon ) -: "<< obj.energy()<<std::endl;
							    std::cout<<"                               pt track: "<< itTrack->pt()<<" pt obj: "<<obj.pt()<<std::endl;                   
							                        }
							    
							
							    
							    
							    
							    
							    
							    }
						 
		            }

			   
			     }
			   }  //falta numero de 3d hitts 
		    
		     

   
}

std::cout<<" Muon candidates " <<muon_candidates<<std::endl;
 std::cout<<"Matching Done"<<"\n"<<std::endl;
 //for(unsigned int i = 0; i<itTrack_vecP.size(); i ++){std::cout<<itTrack_vecP[i]->pt()<<std::endl;}
 std::cout<<" Muon candidates " <<electron_candidates<<std::endl;
 std::cout<<"numero de positivos " <<itTrack_vecP.size()<<std::endl;
 std::cout<<"numero de negativos "<<itTrack_vecM.size()<<std::endl;
 std::cout<<"numoero total "<<itTrack_vecM.size() + itTrack_vecP.size()<<std::endl;
 if(itTrack_vecM.size() + itTrack_vecP2.size()>1){std::cout<<"mas de un muon"<<std::endl;}
 
/************************************************************************** X canditate formation*/
 

  
std::cout<<"segundo "<<itTrack_vecP2.size()<<std::endl;
for(unsigned int i = 0; i<itTrack_vecP2.size(); i ++){
	std::cout<<"muon primer if"<<std::endl;
	float dv,dx,dy,dz ;
	dv = 99999;
	int doubleCountErrP = 0;
	bool doubleCountErrM = false;
	std::vector<int> doubleCountErrV;
	for (unsigned int i = 0; i< itTrack_vecM.size(); i++){
		doubleCountErrV.push_back(1);
	  
	  } 
    for(unsigned int j = 0; j<itTrack_vecM.size(); j ++){
    
      dx = itTrack_vecP2[i]->vx() - itTrack_vecM[j]->vx();
      dy = itTrack_vecP2[i]->vy() - itTrack_vecM[j]->vy();
      dz = itTrack_vecP2[i]->vz() - itTrack_vecM[j]->vz();
      dv = sqrt(dx*dx + dy*dy +dz*dz);
      if(dv< 0.1){
		   if ( doubleCountErrV[j] ==0){
				doubleCountErrM = true;
			    }
		   doubleCountErrV[j] = 0;
		   doubleCountErrP ++;
		  
							    
		  std::cout<<"match"<<std::endl;
		  
		  std::cout<<"Vertex displacement: "<<dv <<std::endl;
	      // calcular masa invariante de par de electrones
	      double px, py, pz, E,E1,E2, mMass;
	      px = itTrack_vecP2[i]->px() + itTrack_vecM[j]->px();
	      py = itTrack_vecP2[i]->py() + itTrack_vecM[j]->py();
	      pz = itTrack_vecP2[i]->pz() + itTrack_vecM[j]->pz();
	      //E = itTrackEnergyP[i] + itTrackEnergyM[j];
	      E1 = sqrt(itTrack_vecP2[i]->pt()*itTrack_vecP2[i]->pt() + itTrack_vecP2[i]->pz()*itTrack_vecP2[i]->pz());
	      E2 = sqrt(itTrack_vecM[j]->pt()*itTrack_vecM[j]->pt() + itTrack_vecM[j]->pz()*itTrack_vecM[j]->pz());
	      E  = E1 + E2;
	      
	      std::cout<<"px: "<<px<<" py: "<<py<<" pz: "<<pz<< " E: "<<E<<" i: "<<i<<" j: "<<j<<std::endl;
	     // std::cout<<"energia +"<<itTrackEnergyP[i]<<" energia - :"<<itTrackEnergyM[j]<<std::endl;
	      mMass = sqrt(E*E - px*px -py*py -pz*pz);
	      std::cout<<"masa calculada: "<<mMass<<std::endl;
	      h_mass_mu->Fill(mMass);
              if (mMass>maxMassM)
				{maxMassM=mMass; }
		  } 
		  
	 
	 
 }
 
if(dv< 0.1){  // usar pointer a vertice para comparar                                                                                 ( para corregir)
		  
	// encontrar Lxy/S_xy
							    
	double vx, vy, L;
	vx = itTrack_vecP2[i]->vx();
	vy = itTrack_vecP2[i]->vy();
	L = sqrt(vx*vx + vy*vy);
	h_Lxy_m->Fill(L);
        }
if (doubleCountErrP> 1) {std::cout<<"Warning: double match (same positron matched twice)"<<std::endl;}
if (doubleCountErrM){std::cout<<"Warning: double match (same electron , matched twice)"<<std::endl;}
 }



//end muons
 

std::cout<<"vuelta: "<< ++event<<std::endl;

#ifdef THIS_IS_AN_EVENT_EXAMPLE
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif
   
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
}


// ------------ method called once each job just before starting event loop  ------------
void 
Analyzer::beginJob()
{
//gROOT = new TROOT();
//gROOT->ProcessLine(".L Lepton.cc+")
file = new TFile("TT.root","recreate");
//file = new TFile("simu.root","recreate");
//const bool oldAddDir = TH1::AddDirectoryStatus();
TH1::AddDirectory(true);
//histo = new TH1F("pt","pt",1000,0,100);
//passHist = new TH1F("passed","passed triger",15,0,100);
maxMassE=0;
maxMassM=0;
e_count=0;
corr = 0;
m_count=0;
ev = 0;
event=0;
if1 = 0;
if2 = 0;
if3 = 0;
h_mass_mu = new TH1F("muonM","Muon mass",50,0,500);
h_mass_e = new TH1F("electronM", "electron mass",100,0,500);
h_Lxy_e = new TH1F("lxye", "Transverce Displacement (Electron channel)",20,0,50);
h_Lxy_m = new TH1F("lxym", "Transverce Displacement (Muon channle)",20,0,50);

//Tracking efficiency

h_mEffSimuGen = new TH1F("mEffSimu", "generated muons impact parameter",50,0,50);
h_mEffSimuGen->Sumw2();
h_mEffSimu = new TH1F("mEff", "generated muons impact parameter",50,0,50);
h_mEffSimu->Sumw2();
//top2Mass_hist = new TH1F("top2M","top two jets mass",200,0,1000000);

}

// ------------ method called once each job just after ending the event loop  ------------
void 
Analyzer::endJob() 
{
std::cout<<"eventos procesados "<<ev<<std::endl;
std::cout<<"Electrons found "<<e_count<<std::endl;
std::cout<<"Muons found "<<m_count<<std::endl;
//std::cout<<"primer if "<<if1<<std::endl;	
//std::cout<<"segundo if "<<if2<<std::endl;
//std::cout<<"tercer if "<<if3<<std::endl;
 std::cout<<"masa maxima encontrada (electron channel): "<<maxMassE<<std::endl;
 
 std::cout<<"masa maxima encontrada (muon channel): "<<maxMassM<<std::endl;

   h_mEffSimu->Divide(h_mEffSimuGen);
 std::cout<<"corr: "<<corr<<std::endl;
file->Write();
file->Close();
}

// First cut. 
bool
Analyzer::cmsStandardCuts(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{

 /* Primary vertex must have at least 4 associated tracks
 * Each of these tracks must be at a distance < 2cm and < 24cm with respect to the primary vertex int the transverse and parallel beam direction respectively. 
 * If an event contains 10 or more tracks, at leas 25% of them must be "hight purity"
 */

 int highPurity = 0;
 int countTrack1 = 0;
 int countTrack2 = 0;
 int countVert = 0;
 bool ret = false;
 bool purity = false;
edm::Handle<reco::VertexCollection> vertHand;
iEvent.getByLabel( "offlinePrimaryVertices",vertHand);
 
 for(reco::VertexCollection::const_iterator itVert = vertHand->begin();
       itVert != vertHand->begin() +1;
       ++itVert){
	    countVert ++;
		
         
        for(reco::Vertex::trackRef_iterator itTrack = itVert->tracks_begin();
       itTrack != itVert->tracks_end();
       ++itTrack){ 
		   double dx, dy, dz,dxy;
		   dx = (**itTrack).vx();
		   dy = (**itTrack).vy();
		   dz = (**itTrack).vz();
		   dxy = sqrt(dx*dx +dy*dy);
		   
		   int hits = (**itTrack).numberOfValidHits();
		   double chi2 = (**itTrack).chi2();
		   
		   if(hits>3 && chi2 < 1 ){
			   highPurity++;
			   
			   
			   }
		   if((dxy< 2) && (dz<= 24))
		   {countTrack1 ++;}
		    countTrack2 ++;
		    // std::cout<<(**itTrack).theta()<<std::endl;
		         
		     }
            
		   }  
   if (countTrack2 > 9){ // check that more than 25% are high purity
	   if (highPurity > (0.25*(double)countTrack2)){
		   purity = true;
		   }
		else {
			
			purity = false;
			}
	   }
   else {purity = true;}
   
   if (countTrack1 > 3 && purity )
   {ret = true;}
   return ret;

}


// ------------ method called when starting to processes a run  ------------
void 
Analyzer::beginRun(edm::Run const& iRun, edm::EventSetup const& iSetup )
{
//CD.init(iRun,iSetup,processName_,changed);
//CD.dump("Triggers");
}

// ------------ method called when ending the processing of a run  ------------
void 
Analyzer::endRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void 
Analyzer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void 
Analyzer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
Analyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);

 //Specify that only 'tracks' is allowed
 //To use, remove the default given above and uncomment below
 //ParameterSetDescription desc;
 //desc.addUntracked<edm::InputTag>("tracks","ctfWithMaterialTracks");
 //descriptions.addDefault(desc);
}


//define this as a plug-in
DEFINE_FWK_MODULE(Analyzer);
