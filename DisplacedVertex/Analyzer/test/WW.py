

import FWCore.ParameterSet.Config as cms
process = cms.Process("Demo")
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(10000))
process.source = cms.Source("PoolSource", fileNames = cms.untracked.vstring(
  

'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WW_TuneZ2_7TeV_pythia6_tauola/AODSIM/PU_S13_START53_LV6-v1/00000/005AB0F8-CFB5-E311-B2D2-AC162DACB208.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WW_TuneZ2_7TeV_pythia6_tauola/AODSIM/PU_S13_START53_LV6-v1/00000/0070A7AC-69B5-E311-A277-00266CFFBC60.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WW_TuneZ2_7TeV_pythia6_tauola/AODSIM/PU_S13_START53_LV6-v1/00000/0216BE1F-97B5-E311-B455-00266CFFBF4C.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WW_TuneZ2_7TeV_pythia6_tauola/AODSIM/PU_S13_START53_LV6-v1/00000/02504E44-C6B5-E311-962A-78E7D1E49636.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WW_TuneZ2_7TeV_pythia6_tauola/AODSIM/PU_S13_START53_LV6-v1/00000/04B05413-34B6-E311-8F2E-1CC1DE046FC0.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WW_TuneZ2_7TeV_pythia6_tauola/AODSIM/PU_S13_START53_LV6-v1/00000/080DB22A-C3B5-E311-9722-1CC1DE1D1452.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WW_TuneZ2_7TeV_pythia6_tauola/AODSIM/PU_S13_START53_LV6-v1/00000/087C1703-99B5-E311-8F65-1CC1DE1D16E6.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WW_TuneZ2_7TeV_pythia6_tauola/AODSIM/PU_S13_START53_LV6-v1/00000/089CEC16-B8B5-E311-9C9C-00266CFF0138.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WW_TuneZ2_7TeV_pythia6_tauola/AODSIM/PU_S13_START53_LV6-v1/00000/0A3ECEAC-7EB5-E311-BCE6-00266CFFBDE8.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WW_TuneZ2_7TeV_pythia6_tauola/AODSIM/PU_S13_START53_LV6-v1/00000/0A630087-F7B5-E311-9106-00266CFFBF80.root',

 ))
process.demo = cms.EDAnalyzer("Analyzer", tracks = cms.untracked.InputTag("generalTracks"))
process.p = cms.Path(process.demo)






