import FWCore.ParameterSet.Config as cms
process = cms.Process("Demo")
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(10000))
process.source = cms.Source("PoolSource", fileNames = cms.untracked.vstring(
 
 
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/DYJetsToLL_M-10To50_TuneZ2_7TeV-pythia6/AODSIM/PU_S13_START53_LV6-v1/00000/001988CE-B20B-E411-942E-0025905A6118.root'
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/DYJetsToLL_M-10To50_TuneZ2_7TeV-pythia6/AODSIM/PU_S13_START53_LV6-v1/00000/0031D4CC-7810-E411-A5DC-00304867904A.root'
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/DYJetsToLL_M-10To50_TuneZ2_7TeV-pythia6/AODSIM/PU_S13_START53_LV6-v1/00000/003ABCE4-1312-E411-9C51-0026189438CB.root'
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/DYJetsToLL_M-10To50_TuneZ2_7TeV-pythia6/AODSIM/PU_S13_START53_LV6-v1/00000/0049F55D-FE0B-E411-B9F0-002618943949.root'
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/DYJetsToLL_M-10To50_TuneZ2_7TeV-pythia6/AODSIM/PU_S13_START53_LV6-v1/00000/0086B2AF-9410-E411-909B-0025905A6136.root'
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/DYJetsToLL_M-10To50_TuneZ2_7TeV-pythia6/AODSIM/PU_S13_START53_LV6-v1/00000/00A6FCA8-950B-E411-87D0-0025905A6104.root'
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/DYJetsToLL_M-10To50_TuneZ2_7TeV-pythia6/AODSIM/PU_S13_START53_LV6-v1/00000/00DE7886-0712-E411-ABA4-0025905A60DE.root'
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/DYJetsToLL_M-10To50_TuneZ2_7TeV-pythia6/AODSIM/PU_S13_START53_LV6-v1/00000/00E8F667-A90B-E411-80E1-003048FFD75C.root'
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/DYJetsToLL_M-10To50_TuneZ2_7TeV-pythia6/AODSIM/PU_S13_START53_LV6-v1/00000/02050768-0512-E411-8378-0025905A6134.root'
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/DYJetsToLL_M-10To50_TuneZ2_7TeV-pythia6/AODSIM/PU_S13_START53_LV6-v1/00000/022C2FE5-E90B-E411-9191-0025905A48D8.root'


 ))
process.demo = cms.EDAnalyzer("Analyzer", tracks = cms.untracked.InputTag("generalTracks"))
process.p = cms.Path(process.demo)




