import FWCore.ParameterSet.Config as cms
process = cms.Process("Demo")
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(500000))
process.source = cms.Source("PoolSource", fileNames = cms.untracked.vstring(
 
 
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/0020AF81-A835-E311-97DC-00261894398C.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/0062BD79-9235-E311-9320-003048FFCC2C.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/008B0182-5E35-E311-B039-003048FFD71E.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/009A5FA1-0D36-E311-B603-00261894388A.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/00ADCF5D-7435-E311-9347-00261894397A.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/00C4AE70-4335-E311-9743-0026189438D9.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/00EF5A25-6235-E311-8D64-002618B27F8A.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/0200DC35-9535-E311-8AE6-003048678B34.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/02495C0E-3A35-E311-A75D-003048678BE6.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/02A4FDA7-7135-E311-AEAB-003048FFCBFC.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/02A5EA3E-6F35-E311-9232-003048678F8A.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/02CC8DC7-9435-E311-8DDD-0026189438F3.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/02DC4EAD-9235-E311-B0C3-002618943985.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/02F46E80-7335-E311-B046-003048FFD732.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/041E647E-5435-E311-8A79-002618943856.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/04302453-1136-E311-95F0-00261894393E.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/0467D790-6C35-E311-B1DA-003048678FEA.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/04695FC2-5B35-E311-AADF-003048FF9AA6.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/046B867E-A835-E311-B2E8-003048FFD728.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/0490CFDC-4A35-E311-85B6-002618943920.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/049A90E4-6835-E311-A384-003048678BEA.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/04F1C9E5-A935-E311-9F92-002618943945.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/061185A7-6A35-E311-A8D1-003048678FEA.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/062E45B5-1036-E311-9CA0-0025905964BA.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/06872350-1136-E311-B9B2-002618943972.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/068A7559-9535-E311-998F-003048678B18.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/0698FAA3-A835-E311-9077-003048FFD730.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/06C90E65-1036-E311-9B29-003048FFCB74.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/06D8874F-1136-E311-99F6-003048FFCC0A.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/06F9095B-6335-E311-901D-003048D15DDA.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/081F9C81-7335-E311-9E3E-00304867904E.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/082FEFBB-9435-E311-94C2-00261894398A.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/0882F73E-5735-E311-95DE-00261894382A.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/08A7C079-9235-E311-80BB-002590593878.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/08D7F7AF-0D36-E311-9FFE-002590593902.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/0A1F51A8-4F35-E311-B159-003048679164.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/0A3AF0BB-0D36-E311-9223-0025905964A6.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/0A3B9FF6-3735-E311-8F7D-003048FFCBA8.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/0A5F6975-7035-E311-B873-0026189438EB.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/0A859F13-7135-E311-8B28-0030486792AC.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/0A8B6FAB-4935-E311-A1A2-002590593920.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/0A8C3DF6-5235-E311-B3DF-00261894398C.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/0AE1FB8D-4D35-E311-85C6-003048FFCB84.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/0AE85014-6635-E311-987C-0026189438AF.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/0AF86F54-6A35-E311-BECC-002618943918.root',

 
   #'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/Photon/AOD/12Oct2013-v1/20001/0202659F-E239-E311-BF9F-003048CF68C8.root'
  #'file:reco_test.root'
 #'file:reco.root'
 ))
process.demo = cms.EDAnalyzer("Analyzer", tracks = cms.untracked.InputTag("generalTracks"))
process.p = cms.Path(process.demo)
