// Fig. 8.14: fig08_14.cpp
// sizeof operator used to determine standard data type sizes
#include <iostream>
using namespace std;

int main() {
    char c;
    short s;
    int i;
    long l;
    long long ll;
    float f;
    double d;
    long double ld;
    int array[20];
    int *ptr = array;

    cout << "sizeof c = " << sizeof c << "\tsizeof(char) = " << sizeof(char)
         << "\nsizeof s = " << sizeof s << "\tsizeof(short) = " << sizeof(short)
         << "\nsizeof i = " << sizeof i << "\tsizeof(int) = " << sizeof(int)
         << "\nsizeof l = " << sizeof l << "\tsizeof(long) = " << sizeof(long)
         << "\nsizeof ll = " << sizeof ll
         << "\tsizeof(long long) = " << sizeof(long long)
         << "\nsizeof f = " << sizeof f << "\tsizeof(float) = " << sizeof(float)
         << "\nsizeof d = " << sizeof d
         << "\tsizeof(double) = " << sizeof(double)
         << "\nsizeof ld = " << sizeof ld
         << "\tsizeof(long double) = " << sizeof(long double)
         << "\nsizeof array = " << sizeof array
         << "\nsizeof ptr = " << sizeof ptr << endl;

    return 0;
}
/* execution result
 * sizeof c = 1    sizeof(char) = 1
 * sizeof s = 2    sizeof(short) = 2
 * sizeof i = 4    sizeof(int) = 4
 * sizeof l = 8    sizeof(long) = 8
 * sizeof ll = 8   sizeof(long long) = 8
 * sizeof f = 4    sizeof(float) = 4
 * sizeof d = 8    sizeof(double) = 8
 * sizeof ld = 8   sizeof(long double) = 8
 * sizeof array = 80
 * sizeof ptr = 8
 */
