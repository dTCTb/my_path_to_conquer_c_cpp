// clang-format off
// Fig. 9.16: fig09_16.cpp
// const objects and const member functions
#include "9.4_Time.h"

int main() {
    Time wakeUp(6, 45, 0);
    const Time noon(12, 0, 0);
                               // OBJECT    MEMBER FUNCTION
    wakeUp.setHour(18);        // non-const non-const
//  noon.setHour(12);          // const     non-const <- error

    wakeUp.getHour();          // non-const const

    noon.getMinute();          // const     const
    noon.printUniversal();     // const     const
//  noon.printStandard9_16();  // const     non-const <- error
    
    return 0;
}
