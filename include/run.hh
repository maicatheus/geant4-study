#ifndef run
#define run

#include "G4UserRunAction.hh"
#include "G4Run.hh"
#include "g4root.hh"

class MyRunAction : public G4UserRunAction
{
private:
    G4AnalysisManager *man;
public:
    MyRunAction(/* args */);
    ~MyRunAction();

    virtual void BeginOfRunAction(const G4Run *);
    virtual void EndOfRunAction(const G4Run *);
};


#endif