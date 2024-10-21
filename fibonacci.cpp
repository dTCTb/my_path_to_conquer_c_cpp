#include <iostream>

int /* recursive */ fibonacci(int x) {
    return x == 1 || x == 2 ? 1 : fibonacci(x - 2) + fibonacci(x - 1);
}

bool validation(int argc, char **argv) noexcept {
    using std::cout;
    bool isCorrect{true};
    if (argc != 2) {
        cout << "USAGE: " << *(argv) << " <int>\n";
        isCorrect = false;
    } else if (int x = atoi(argv[1]); x <= 0 || x > 45) {
        cout << "please input range from 1 to 45\n";
        if (x > 45)
            cout << x << " is too large for the recursive fibonacci\n";
        isCorrect = false;
    }
    return isCorrect;
}

int main(int argc, char **argv) noexcept {
    if (validation(argc, argv)) {
        for (size_t i{}; i < std::atoi(argv[1]); ++i)
            std::cout << fibonacci(i + 1) << ' ';
        std::cout.put('\n');
    }
}
