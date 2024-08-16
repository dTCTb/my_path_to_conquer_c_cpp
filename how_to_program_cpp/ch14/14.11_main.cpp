// Fig 14.11: 14.11_main.cpp
// Creating a randomly access file
#include "ClientData.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

int main() {
    std::ofstream outCredit("./ch14/credit.dat",
                            std::ios::out | std::ios::binary);

    if (!outCredit) {
        std::cerr << "File could not be opened.\n";
        exit(EXIT_FAILURE);
    }

    ClientData blankClient;

    for (int i = 0; i < 100; ++i)
        outCredit.write(reinterpret_cast<const char *>(&blankClient),
                        sizeof(ClientData));
    return 0;
}
