#include <iostream>

class A {
  private:
    int *m_a;

  public:
    // default constructor
    A(int a = 0) : m_a{new int{a}} {}
    // constructor
    A(int *a) : m_a{a} { a = nullptr; }
    // copy constructor
    // A(const A &from) : m_a(nullptr) { *this = from; } // ⤹same
    A(const A &from) : m_a{new int{from.getAVal()}} {}
    // move constructor
    A(A &&from) : m_a{from.getAAddr()} { from.setA(nullptr); }
    // destructor
    ~A() { delete m_a; }
    // move assignment operator
    A &operator=(A &&from) {
        if (!myself(from)) {
            if (m_a)
                delete m_a;
            setA(from.getAAddr());
            from.setA(nullptr);
        }
        return *this;
    }
    // copy assignment operator
    A &operator=(const A &from) {
        if (!myself(from)) {
            if (m_a)
                delete m_a;
            m_a = new int{from.getAVal()};
        }
        return *this;
    }

    int *getAAddr() const { return m_a; }
    int getAVal() const { return m_a ? *m_a : -1; }

    void setA(int *a) { m_a = a; }
    void setA(int a) { m_a = new int{a}; }

  private:
    bool myself(const A &other) const { return this == &other; }
};

int main() {
    A z;
    A a{9}; // constructor
    std::cout << "z: " << z.getAAddr() << ' ' << z.getAVal() << '\n';
    std::cout << "a: " << a.getAAddr() << ' ' << a.getAVal() << '\n';

    std::cout << "\nA b{std::move(a)}\n";
    A b{std::move(a)}; // move constructor
    std::cout << "a: " << a.getAAddr() << ' ' << a.getAVal() << '\n';
    std::cout << "b: " << b.getAAddr() << ' ' << b.getAVal() << '\n';

    std::cout << "\na = std::move(b)\n";
    a = std::move(b); // move operation
    std::cout << "a: " << a.getAAddr() << ' ' << a.getAVal() << '\n';
    std::cout << "b: " << b.getAAddr() << ' ' << b.getAVal() << '\n';

    std::cout << "\nb = a\n";
    b = a; // copy operation
    std::cout << "a: " << a.getAAddr() << ' ' << a.getAVal() << '\n';
    std::cout << "b: " << b.getAAddr() << ' ' << b.getAVal() << '\n';
    return 0;
}
