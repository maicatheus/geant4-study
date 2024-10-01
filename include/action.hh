#ifndef ACTION_HH
#define ACTION_HH

#include "G4VUserActionInitialization.hh"
#include "generator.hh"

class MyActionInitialization : public G4VUserActionInitialization
{
private:
    /* data */
public:
    MyActionInitialization(/* args */);
    ~MyActionInitialization();

    virtual void Build() const;
};


#endif