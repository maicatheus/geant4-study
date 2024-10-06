#include "run.hh"

MyRunAction::MyRunAction()
{
    man = G4AnalysisManager::Instance();

    man->CreateNtuple("Hits", "Hits");
    man->CreateNtupleIColumn("fEvent");
    man->CreateNtupleDColumn("fx");
    man->CreateNtupleDColumn("fy");
    man->CreateNtupleDColumn("fz");
    man->FinishNtuple(0);
}

MyRunAction::~MyRunAction() {}

void MyRunAction::BeginOfRunAction(const G4Run* g4Run){

    G4int runId = g4Run->GetRunID();

    std::stringstream strRunId;
    strRunId << runId;

    man->OpenFile("output" + strRunId.str() + ".root");
}

void MyRunAction::EndOfRunAction(const G4Run *)
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    man->Write();
    man->CloseFile("output.root");
}
