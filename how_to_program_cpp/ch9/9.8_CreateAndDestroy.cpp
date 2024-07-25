// Fig. 9.8: CreateAndDestroy.cpp
// CreateAndDestroy class member-function definitions
#include "9.7_CreateAndDestroy.h"
#include <iostream>
using namespace std;

CreateAndDestroy::CreateAndDestroy(int ID, string messageString)
    : objectID(ID), message(messageString) {
    cout << "Object " << objectID << "\tconstructor runs\t" << message << endl;
}

CreateAndDestroy::~CreateAndDestroy() {
    cout << (objectID == 1 || objectID == 6 ? "\n" : "");
    cout << "Object " << objectID << "\tdestructor runs\t" << message << endl;
}
