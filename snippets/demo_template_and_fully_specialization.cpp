#include <iostream>

template <typename D> class A {
  public:
    A<D>() = default;
    A<D>(const A<D> &) { std::cout << "Copy Constructor\n"; }
    void foo() const { std::cout << "hi\n"; }
    A<D> *get(A<D> &q) { return new A<D>{q}; }
};

// full specialization of class template with double as template argument
template <> class A<double> {
  public:
    A() = default;
    A(const A &) { std::cout << "This is A<double> Copy Constructor\n"; }
    void foo() const { std::cout << "A<double> hi\n"; }
    A *get(A &q) { return new A{q}; }
};

template <typename D> class B : private A<D> {
  public:
    void pop() const { this->foo(); } // B<D> * const this
    // A<double> *p(A<double> &q) { return ((A<double> *const)this)->get(q); }
    [[nodiscard]] A<D> *p(A<D> &q) { return this->get(q); }
    A<double> *p(A<double> &q) {
        return reinterpret_cast<A<double> *>(this)->get(q);
    }
};

void piyo(A<double> *qq) {
    A<double> *&Q = qq;
    Q->foo();
}

int main() {
    [[maybe_unused]] A<double> a;
    B<int> b; // b is an instance of the specialization of class template B with
              // int as template argument
    // qq is a pointer to the specialization of class template A with double as
    // the template argument
    A<double> *qq = b.p(a);
    qq->foo();
    piyo(qq);
    A<int> t;
    [[maybe_unused]] A<int> *q = b.p(t);
    if (int i{1}; i)
        std::cout << "goo\n";
}
