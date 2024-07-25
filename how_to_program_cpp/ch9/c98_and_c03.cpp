// clang-format off
class Entity {
public:
    static const unsigned char  a = 'a';
    static const signed   char  b = 'b';
    static const          char  c = 'c';
    static const unsigned int   d = 1;
    static const signed   int   e = 2;
    static const unsigned short f = 3;
    static const signed   short g = 4;
    static const unsigned long  h = 5L;
    static const signed   long  i = 6L;
    // static const float          j = 7.0F; // don't know static const
    // static const double         k = 8.0;  // float & double can or can't
    // compiler just error and tell me add constexpr
    unsigned char  A = 'a';
    signed   char  B = 'b';
             char  C = 'c';
    unsigned int   D = 1;
    signed   int   E = 2;
    unsigned short F = 3;
    signed   short G = 4;
    unsigned long  H = 5L;
    signed   long  I = 6L;
    float          J = 7.0F;
    double         K = 8.0;
};
/* use below commands
 * $clang++ -std=c++98 -Wall -o out c98_and_c03.cpp
 *                       or
 * $clang++ -std=c++03 -Wall -o out c98_and_c03.cpp
 * warning from compiler that:
 * A~K default member initializer for non-static data member is a C++11 extension
 *
 *
 * $clang++ -std=c++11 -Wall -o out c98_and_c03.cpp
 * no warning from compiler
 */

int main() {
    return 0;
}
