// Fig. 9.22: fig09_22.cpp
// Friends can access private members of a class
#include <iostream>
using namespace std;

class Count {
  public:
    friend void setX(Count &, int); // friend declaration
    Count() : x(0) {}
    void print() const { cout << x << endl; }

  private:
    int x;
};

void setX(Count &c, int val) { c.x = val; }

int main() {
    Count counter;

    cout << "counter.x after instantiation: ";
    counter.print();

    // set x using a friend function
    setX(counter, 8);

    cout << "counter.x after call setX friend function: ";
    counter.print();
    return 0;
}
/* execution result
 * counter.x after instantiation: 0
 * counter.x after call setX friend function: 8
 */
