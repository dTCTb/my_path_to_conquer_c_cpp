// Fig. 12.2: 12.2_main.cpp
// Aiming a derived-class pointer at a base-class object
#include "BCE.h"
#include "CE.h"
#include <iostream>

int main() {
    CommissionEmployee ce("Sue", "Jones", "222-22-2222", 10000, .06);
    BasePlusCommissionEmployee *bce = nullptr;
#if defined PRINT
    std::cout << "compiler error message when execute 'bce = &ce'\n"
                 "clang: Incompatible pointer types assigning to "
                 "'BasePlusCommissionEmployee *' from 'CommissionEmployee *' "
                 "[typecheck_convert_incompatible_pointer]"
              << std::endl;
#else
    bce = &ce;
#endif
    return 0;
}
