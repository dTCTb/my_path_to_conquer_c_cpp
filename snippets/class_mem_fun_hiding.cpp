#include <iostream>
class A {
  public:
    virtual void p() const { std::cout << "A::p()" << std::endl; }
    virtual void p(int) const { std::cout << "A::p(int)" << std::endl; }
};

class B final : public A {
  public:
    // using A::p;
    // 一但override 咗base class 嘅mem-fun, 係唔會inherit 埋同名嘅mem-fun
    virtual void p() const noexcept final override {
        std::cout << "B::p()" << std::endl;
    }
    // virtual void p(int) const override;
};

void foo(int x);
void foo(int y);

int main() {
    B b;
    b.p(); // B::p()
    // b.p(1);
    b.A::p(1); // A::p(int)

    A *r = &b;
    r->p();  // B::p()
    r->p(1); // A::p(int)
}
