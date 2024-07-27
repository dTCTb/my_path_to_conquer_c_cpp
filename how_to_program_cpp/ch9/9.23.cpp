// Fig. 9.23: fig09_23.cpp
// Using the this pointer to refer to object members
#include <iomanip>
#include <iostream>
using namespace std;

class Test {
  public:
    explicit Test(int = 0);
    void print() const;

  private:
    int x;
};

Test::Test(int value) : x(value) {}

void Test::print() const {
    cout << setw(12) << "x = " << x << '\n';
    cout << setw(12) << "this->x = " << this->x << '\n';
    cout << setw(12) << "(*this).x = " << (*this).x << '\n';
}

int main() {
    Test testObject(12);
    testObject.print();
    return 0;
}
/* execution result
 *         x = 12
 *   this->x = 12
 * (*this).x = 12
 */
