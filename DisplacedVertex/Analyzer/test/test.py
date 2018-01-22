import FWCore.ParameterSet.Config as cms
process = cms.Process("Demo")
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(1000))
process.source = cms.Source("PoolSource", fileNames = cms.untracked.vstring(
#    VBFToHToZZTo2L2Nu_M-450_7TeV
 'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/VBFToHToZZTo2L2Nu_M-450_7TeV-powheg15-pythia6/AODSIM/PU_S13_START53_LV6-v1/00000/00F7DF50-20C8-E311-8B1E-001E673973D2.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/VBFToHToZZTo2L2Nu_M-450_7TeV-powheg15-pythia6/AODSIM/PU_S13_START53_LV6-v1/00000/022860BC-1FC8-E311-A8F5-001E6739672F.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/VBFToHToZZTo2L2Nu_M-450_7TeV-powheg15-pythia6/AODSIM/PU_S13_START53_LV6-v1/00000/02C120BD-1FC8-E311-B66F-0025B3E063B4.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/VBFToHToZZTo2L2Nu_M-450_7TeV-powheg15-pythia6/AODSIM/PU_S13_START53_LV6-v1/00000/061DC17F-20C8-E311-BE84-002590200894.root'

#  Otro dataset

 ))
process.demo = cms.EDAnalyzer("Analyzer", tracks = cms.untracked.InputTag("generalTracks"))
process.p = cms.Path(process.demo)
