// clang-format off
#include <iostream>

class CustomStack {
  public:
    CustomStack(int maxSize) noexcept;
    ~CustomStack() noexcept;
    void push(int x) noexcept;
    int pop() noexcept;
    void increment(int k, int val) noexcept;

    // tool member-function
    void print() const noexcept {
        for (int i{top}; i > -1; --i) std::cout << arr[i] << '\n';
    }
    int getTop() const noexcept { return top; }
    size_t getMaxSize() const noexcept { return max; }
    int *getData() const noexcept { return arr; }

  private:
    int *const arr;
    const size_t max;
    int top;
};

CustomStack::CustomStack(int maxSize) noexcept
    : arr{new int[maxSize]},
      max{static_cast<size_t>(maxSize)},
      top{-1}
    {}

CustomStack::~CustomStack() noexcept {
    delete[] arr;
}

void CustomStack::push(int x) noexcept {
    if (top + 1 < max) arr[++top] = x;
}

int CustomStack::pop() noexcept {
    return top > -1 ? arr[top--] : top;
}

void CustomStack::increment(int k, int val) noexcept {
    /* no idea why size_t i{} will cause RTE (heap-buffer-overflow) on LeetCode
       but everything fine when using int i{} as initializer
       if MUST use size_t i{}; then the control expression have to:
       i <= top && i < max && i < k so that no RTE (heap-buffer-overflow) happen
    */
    for (size_t i{}; i <= top && i < k; ++i)
        arr[i] += val;
}

// clang-format on
class StackDriver {
  private:
    CustomStack *obj;

    bool isAlive() const {
        if (!obj) {
            std::cout << "[Stack Not Exists]\n";
            return false;
        }
        return true;
    }
    bool isEmpty() const {
        if (!isAlive())
            return false;
        if (obj->getTop() == -1) {
            std::cout << "[Stack Empty]\n";
            return true;
        }
        return false;
    }

    bool inputInvalid() const {
        std::cout << "Invalid Input, please try again\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        return false;
    }

    bool pushHelper() const noexcept {
        if (obj->getTop() == obj->getMaxSize() - 1) {
            std::cout << "[Stack Fulled]\n";
            return false;
        }
        int val{};
        std::cin >> val;
        if (std::cin.good()) {
            obj->push(val);
        } else
            return inputInvalid();
        return true;
    }

    void printHelp() const noexcept {
        std::cout << "[ [a]dd / [p]op / [l]ist / [i]ncrement / [c]reate / "
                     "[q]uit ]\n";
    }

    void createStackInstance() noexcept {
        if (obj) {
            std::cout << "Stack with " << obj->getMaxSize()
                      << " size have been created, you want to "
                         "recreate? [y/n] ";
            std::cin.ignore(1000, '\n');
            if (std::cin.get() == 'n')
                return;
            delete obj;
            obj = nullptr;
        }
        int maxSize{};
        std::cout << "Please enter the size of Stack: ";
        std::cin >> maxSize;
        obj = new CustomStack{maxSize};
        std::cout << "Stack with " << obj->getMaxSize() << " size Created\n";
    }

    bool incrementHelper() {
        if (isEmpty())
            return false;

        int k{}, val{};
        std::cin >> k >> val;
        if (std::cin.good())
            obj->increment(k, val);
        else
            return inputInvalid();
        return true;
    }

    void printHelper() {
        if (obj->getTop() == -1)
            std::cout << "[Stack Empty]\n";
        else {
            std::cout << "[Stack Top]\n";
            obj->print();
            std::cout << "[Stack Bot]\n";
        }
    }

  public:
    StackDriver() : obj{nullptr} {}
    ~StackDriver() { delete obj; }
    void start() noexcept {
        char i{};
        while (i != 'q') {
            std::cout << "> ";
            std::cin >> i;
            switch (i) {
            case 'c':
                createStackInstance();
                break;
            case 'l':
                if (isAlive())
                    printHelper();
                break;
            case 'p':
                if (isAlive())
                    if (obj->pop() == -1)
                        std::cout << "[Stack Empty]\n";
                break;
            case 'a':
                if (isAlive())
                    pushHelper();
                break;
            case 'i':
                if (isAlive())
                    incrementHelper();
                break;
            case 'h':
                printHelp();
                break;
            default:
                break;
            }
        }
    }
};

int main() {
    StackDriver test;
    test.start();
}
