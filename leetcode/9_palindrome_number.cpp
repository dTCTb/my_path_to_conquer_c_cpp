#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    virtual bool isPalindrome(int x) = 0;
    virtual ~Solution() = default;
};

// Solution 1: Two Pointers
class S1 : public Solution {
  public:
    bool isPalindrome(int x) noexcept override {
        string p{to_string(x)};
        for (size_t i{}, j{p.size() - 1}; i < p.size() / 2; ++i, --j)
            if (p[i] != p[j])
                return false;
        return true;
    }
};

// Solution 2: Arithmetic (Faster)
class S2 : public Solution {
  public:
    bool isPalindrome(int x) noexcept override {
        if (x < 0)
            return false;

        long q{x}, p{};
        while (q > 0)
            p = p * 10 + (q % 10), q /= 10;
        return x == p;
    }
};

void runTest() {
    Solution *pS1{new S1}, *pS2{new S2};
    cout << boolalpha;
    cout << 121 << ": " << pS1->isPalindrome(121) << '\n';
    cout << 1234567899 << ": " << pS2->isPalindrome(1234567899) << '\n';
    delete pS1;
    delete pS2;
}

int main() {
    int buffer;
    // Solution *p{new S1};
    Solution *p{new S2};
    for (;;) {
        cin >> buffer;
        if (cin.good())
            cout << buffer << (p->isPalindrome(buffer) ? " is " : " is not ")
                 << "a palindrome\n";
        else if (cin.clear(), cin.get() == 'q')
            break;
        else {
            cin.ignore(1000, '\n');
            cout << "Would you like to continue? ['y' for continue] ";
            if (cin.get() == 'y') {
                cin.ignore(1000, '\n');
            } else
                break;
        }
    }
    cin.clear();
    cin.ignore(1000, '\n');
    delete p;
}
