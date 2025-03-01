#include "./lc_tools.h"
#include <vector>

using namespace std;

class ProductOfNumbers {
  private:
    std::vector<int> vInt;

  public:
    ProductOfNumbers() : vInt{std::vector<int>(1, 1)} {}

    void add(const int num) {
        if (num)
            vInt.push_back(num * vInt.back());
        else {
            vInt.clear();
            vInt.push_back(1);
        }
    }

    int getProduct(const int k) {
        return k < vInt.size() ? vInt.back() / vInt[vInt.size() - k - 1] : 0;
    }
};

int main() {
    ProductOfNumbers *obj = new ProductOfNumbers();
    obj->add(3);
    obj->add(0);
    obj->add(2);
    obj->add(5);
    obj->add(4);
    obj->getProduct(2);
    obj->getProduct(3);
    obj->getProduct(4);
    obj->add(8);
    obj->getProduct(2);
}
