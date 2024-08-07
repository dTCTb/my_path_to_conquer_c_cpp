#include <iostream>
using namespace std;

struct A {
    A() { cout << "A()" << endl; }
    ~A() { cout << "~A()" << endl; }
};

struct B final : A {
    B() { cout << "B()" << endl; }
    ~B() { cout << "~B()" << endl; }
    operator A *() const noexcept { return const_cast<B *>(this); }
};

struct C {
    C() { cout << "C()" << endl; }
    virtual ~C() { cout << "~C()" << endl; }
};

struct D final : C {
    D() { cout << "D()" << endl; }
    virtual ~D() noexcept override final { cout << "~D()" << endl; }
    operator C *() const noexcept { return const_cast<D *>(this); }
};

int main() {
    cout << "classes without virtual destructor\n";
    A *pa = new B();
    delete pa; // static bind to class A destructor
    cout << "- -- - -- -" << endl;
    cout << "classes with virtual destructor\n";
    C *pb = new D();
    delete pb; // dynamic bind to class D destructor
}
/* execution result
 * classes without virtual destructor
 * A()
 * B()
 * ~A()
 * - -- - -- -
 * classes with virtual destructor
 * C()
 * D()
 * ~D()
 * ~C()
 */
