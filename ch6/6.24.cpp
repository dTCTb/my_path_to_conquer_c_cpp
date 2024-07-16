// Fig. 6.24: fig06_24.cpp
// Name mangling to enable type-safe linkage.

// function square for int values
int square(int x) { return x * x; }

// function square for double values
double square(double y) { return y * y; }

/* function that receives arguments of types
 * int, float, char and int & */
void nothing1(int a, float b, char c, int &d) {
    // empty function body
}

/* function that receives arguments of types
 * char, int, float & and double & */
int nothing2(char a, int b, float &c, double &d) { return 0; }

int main() { return 0; }

// clang++ -Wall -g -c -o ./bin/6.24.o 6.24.cpp
/* symbol table
 * nm ./bin/6.24.o
 * 000000000000001c T __Z6squared
 * 0000000000000000 T __Z6squarei
 * 0000000000000038 T __Z8nothing1ifcRi
 * 0000000000000054 T __Z8nothing2ciRfRd
 * 0000000000000074 T _main
 * 0000000000000000 t ltmp0
 * 0000000000000588 s ltmp1
 */
