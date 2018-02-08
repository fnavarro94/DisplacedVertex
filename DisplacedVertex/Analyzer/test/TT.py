
import FWCore.ParameterSet.Config as cms
process = cms.Process("Demo")
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(10000))
process.source = cms.Source("PoolSource", fileNames = cms.untracked.vstring(
  
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/TTJets_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v1/00000/0005D1FB-4BCF-E311-9FE4-002590A8312A.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/TTJets_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v1/00000/002B0269-0DC7-E311-8AC7-002481E150DA.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/TTJets_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v1/00000/002D845F-65C7-E311-96FE-001E6739689C.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/TTJets_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v1/00000/002FB2D4-F6C7-E311-8D85-002590A3C95E.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/TTJets_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v1/00000/00332A5F-6DC8-E311-9955-002481E154CE.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/TTJets_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v1/00000/00345E78-7CC5-E311-A9C7-001E6739730A.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/TTJets_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v1/00000/003754F5-4CCF-E311-A6DB-001E67397E13.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/TTJets_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v1/00000/0038BB67-4ACF-E311-B701-001E673969D2.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/TTJets_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v1/00000/003FA38E-4BC7-E311-9853-001E67396928.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/TTJets_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v1/00000/0045CF26-C7C7-E311-8A79-002590A83136.root'

 ))
process.demo = cms.EDAnalyzer("Analyzer", tracks = cms.untracked.InputTag("generalTracks"))
process.p = cms.Path(process.demo)





