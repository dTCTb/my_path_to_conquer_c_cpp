// Fig. 9.7: 9.7_CreateAndDestroy.h
// CreateAndDestroy class definition
// Member-function defined in 9.8_CreateAndDestroy.cpp
#include <string>
using namespace std;

#ifndef CREATE_H
#define CREATE_H

class CreateAndDestroy {
  public:
    CreateAndDestroy(int, string);
    ~CreateAndDestroy();

  private:
    int objectID;
    string message;
};

#endif
