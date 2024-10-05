#ifndef run
#define run

#include "G4UserRunAction.hh"
#include "g4root.hh"

class MyRunAction : public G4UserRunAction
{
private:
    /* data */
public:
    MyRunAction(/* args */);
    ~MyRunAction();

    virtual void BeginOfRunAction(const G4Run *);
    virtual void EndOfRunAction(const G4Run *);
};


#endif