#include "../../termcolor.h"
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <string>

// clang-format off
void a() noexcept; void b() noexcept;
void c() noexcept; void d() noexcept;
void e() noexcept; void f() noexcept;
void g() noexcept; void h() noexcept;
void i() noexcept; void j() noexcept;

// std::array<std::string, 10> questions{
std::map<char, std::string> questions{
    {'a', BLU("16.3 a) ") "請使用fill算法，用\"hello\"填充整個名為items 的array 對象，元素類型為string"},
    {'b', BLU("16.3 b) ") "nextInt 函數返回序列中的下一個int值，在第一次調用的時候從0元素開始。\n"
              "        請使用generate 算法和nextInt 函數填充名為integers 的array 對象，元素類型為int"},
    {'c', BLU("16.3 c) ") "請使用equal 算法比較兩個列表(strings1 和strings2)是否相等。\n"
              "        將結果保存在bool 類型的變量result 中。"},
    {'d', BLU("16.3 d) ") "請使用remove_if 算法删除名為colors 的string 類型的vector 對象中\n"
              "        所有以\"bl\"開頭的字符串。"},
    {'e', BLU("16.3 e) ") "請使用replace_if 算法將名為values 的int 類型的array 對象中\n"
              "        所有值大於100 的元素替換為10。"},
    {'f', BLU("16.3 f) ") "請使用minmax_element 算法尋找名為temperatures 的\n"
              "        double 類型的array 對象中的最小和最大值。"},
    {'g', BLU("16.3 g) ") "請使用sort 算法對名為colors 的string 類型的array 對象進行排序。"},
    {'h', BLU("16.3 h) ") "請使用reverse 算法對名為colors 的string 類型的array 對象中的元素進行順序反轉。"},
    {'i', BLU("16.3 i) ") "請使用merge 算法將兩個有序的名為values1 和values2 的array 對象的內容\n"
              "        合併到名為results 的第三個array 對象中。"},
    {'j', BLU("16.3 j) ") "請編寫一個返回int 參數平方的lambda 表達式，並把該lambda 表達式賦值給變量squareInt。"},
};

void runAll() { a(); b(); c(); d(); e(); f(); g(); h(); i(); j();  }

int main(int argc, char **argv) {
    if (argc > 1) {
        std::string la = *(argv + 1);
        for (char &q : la)
            switch (q) {
                case 'a': a(); break;
                case 'b': b(); break;
                case 'c': c(); break;
                case 'd': d(); break;
                case 'e': e(); break;
                case 'f': f(); break;
                case 'g': g(); break;
                case 'h': h(); break;
                case 'i': i(); break;
                default: std::cout << "16.3 " << q << ") doesn't exist\n"; break;
            };
    } else runAll();
    return 0;
}
// clang-format on

void a() noexcept {
    std::ostream_iterator<std::string> o(std::cout, " ");
    std::array<std::string, 5> items;

    // question
    std::cout << questions['a'] << "\n> array items element (before): ";
    std::copy(items.cbegin(), items.cend(), o);
    std::cin.ignore(1024, '\n');

    // answer
    std::fill(items.begin(), items.end(), "hello");

    // result
    std::cout << "> array items element (after) : ";
    std::copy(items.cbegin(), items.cend(), o);
    // std::for_each(items.cbegin(), items.cend(),
    //               [](const std::string &x) { std::cout << x << ' '; });
    std::cout << "\n\n";
}

void b() noexcept {
    std::ostream_iterator<int> o(std::cout, " ");
    const std::array<int, 5> ori{5, 4, 3, 2, 1};
    std::array<int, 5> integers;
    auto nextInt = [&ori]() {
        static int x{0};
        return ori[x++];
    };

    // question
    std::cout << questions['b'] << "\n> array ori element: ";
    std::copy(ori.cbegin(), ori.cend(), o);
    std::cout << "\n> array integers element (before): ";
    std::copy(integers.cbegin(), integers.cend(), o);
    std::cin.ignore(1024, '\n');

    // answer
    std::generate(integers.begin(), integers.end(), nextInt);

    // result
    std::cout << "> array integers element (after): ";
    std::copy(integers.cbegin(), integers.cend(), o);
    std::cout << "\n\n";
}

void c() noexcept {
    std::ostream_iterator<std::string> o(std::cout, " ");
    std::array<std::string, 3> strings1{"apple", "banana", "orange"};
    std::array<std::string, 3> strings2{strings1};

    // question
    std::cout << questions['c'];
    std::cout << "\n> strings1: ";
    std::copy(strings1.cbegin(), strings1.cend(), o);
    std::cout << "\n> strings2: ";
    std::copy(strings2.cbegin(), strings2.cend(), o);
    std::cin.ignore(1024, '\n');

    // answer
    bool same =
        std::equal(strings1.cbegin(), strings1.cend(), strings2.cbegin());

    // result
    std::cout << "> strings1 " << (same ? "is" : "is not")
              << " same with strings2" << "\n\n";
}

void d() noexcept {
    std::ostream_iterator<std::string> o(std::cout, " ");
    std::array<std::string, 3> colors{"red", "blue", "brown"};

    // question
    std::cout << questions['d'] << "\n> array colors element (before): ";
    std::copy(colors.cbegin(), colors.cend(), o);
    std::cin.ignore(1024, '\n');

    // answer
    std::array<std::string, 3>::const_iterator end_a =
        std::remove_if(colors.begin(), colors.end(), [](const std::string &x) {
            return x.substr(0, 2) == "bl";
        });
#if defined CPP20
    std::array<std::string, 3>::const_iterator end_b =
        std::remove_if(colors.begin(), colors.end(), [](const std::string &x) {
            return x.starts_with("bl");
        });
#endif

    // result
    std::cout << "> array colors element (after): ";
    std::copy(colors.cbegin(), end_a, o);
#if defined CPP20
    std::cout << AQUC;
    std::cout << "\n> (using basic_string::starts_with since C++20) <";
    std::cout << "\n> array colors element (after): ";
    std::copy(colors.cbegin(), end_b, o);
    std::cout << RESET;
#endif
    std::cout << "\n\n";
}

void e() noexcept {
    std::ostream_iterator<int> o(std::cout, " ");
    std::array<int, 10> values{1, 100, 101, 55, 200, 679, 4, -23, 88, 1000};

    // clang-format off
    // question
    std::cout << questions['e'] << "\n> array values element (before): ";
    std::copy(values.cbegin(), values.cend(), o);
    std::cin.ignore(1024, '\n');
    // clang-format on

    // answer
    std::replace_if(
        values.begin(), values.end(), [](const int &x) { return x > 100; }, 10);

    // result
    std::cout << "> array values element (after) : ";
    std::copy(values.cbegin(), values.cend(), o);
    std::cout << "\n\n";
}

void f() noexcept {
    std::ostream_iterator<double> o(std::cout, " ");
    std::array<double, 10> temperatures{28.1, 35.5, 27.1,  32.4, 28.5,
                                        32.9, 33.6, 28.99, 28.2, 30.85};
    (std::cout << std::fixed).precision(2);

    // question
    std::cout << questions['f'] << "\narray temperatures element (before): ";
    std::copy(temperatures.cbegin(), temperatures.cend(), o);
    std::cin.ignore(1024, '\n');

    // answer
    std::pair<std::array<double, 10>::const_iterator,
              std::array<double, 10>::const_iterator>
        minmax_temp = std::minmax_element(
            temperatures.cbegin(), temperatures.cend(), std::less<double>());
#if defined CPP17
    auto [min_temp_b, max_temp_b] = std::minmax_element(
        temperatures.cbegin(), temperatures.cend(), std::less<double>());
#endif

    // result
    std::cout << "> minimum temperature: " << *minmax_temp.first;
    std::cout << "\n> maximum temperature: " << *minmax_temp.second;
#if defined CPP17
    std::cout << BLUC;
    std::cout << "\n> (using structured binding since C++17) <";
    std::cout << "\n> minimum temperature: " << *min_temp_b;
    std::cout << "\n> maximum temperature: " << *max_temp_b;
    std::cout << RESET;
#endif
    std::cout << "\n\n";
}

void g() noexcept {
    std::ostream_iterator<std::string> o(std::cout, ", ");
    std::array<std::string, 10> colors{
        "red",  "sea green", "brick red", "olive",   "lime",
        "teal", "yellow",    "cyan",      "magenta", "brown"};

    // question
    std::cout << questions['g'] << "\n> array colors element (before): \n> ";
    std::copy(colors.cbegin(), colors.cend(), o);
    std::cout << "\b\b  ";
    std::cin.ignore(1024, '\n');

    // answer
    std::sort(colors.begin(), colors.end(), std::greater<std::string>());

    // result
    std::cout << "> array colors element (after) : \n> ";
    std::copy(colors.cbegin(), colors.cend(), o);
    std::cout << "\b\b  ";
    std::cout << "\n\n";
}

void h() noexcept {
    std::ostream_iterator<std::string> o(std::cout, ", ");
    std::array<std::string, 10> colors{
        "red",  "sea green", "brick red", "olive",   "lime",
        "teal", "yellow",    "cyan",      "magenta", "brown"};

    // question
    std::cout << questions['h'] << "\n> array colors element (before): \n> ";
    std::copy(colors.cbegin(), colors.cend(), o);
    std::cout << "\b\b  ";
    std::cin.ignore(1024, '\n');

    // answer
    std::reverse(colors.begin(), colors.end());

    // result
    std::cout << "> array colors element (after) : \n> ";
    std::copy(colors.cbegin(), colors.cend(), o);
    std::cout << "\b\b  ";
    std::cout << "\n\n";
}

void i() noexcept {
    std::ostream_iterator<int> o(std::cout, " ");
    std::array<int, 5> values1{1, 3, 5, 7, 9};
    std::array<int, 5> values2{2, 4, 6, 8, 10};
    std::array<int, 10> results{};

    // question
    std::cout << questions['i'];
    std::cout << "\n> array values1 element (before): ";
    std::copy(values1.cbegin(), values1.cend(), o);
    std::cout << "\n> array values2 element (before): ";
    std::copy(values2.cbegin(), values2.cend(), o);
    std::cin.ignore(1024, '\n');

    // answer
    std::merge(values1.cbegin(), values1.cend(), values2.cbegin(),
               values2.cend(), results.begin(), std::less<int>());

    // result
    std::cout << "> array results element (after) : ";
    std::copy(results.cbegin(), results.cend(), o);
    std::cout << "\n\n";
}

void j() noexcept {
    int squareInt{};

    // question
    std::cout << questions['j'];
    std::cin.ignore(1024, '\n');

    // answer
    auto calculateSquareInt = [](int &&x) { return x * x; };
    squareInt = calculateSquareInt(6);

    // result
    std::cout << "> auto calculateSquareInt = [](int &&x) { return x * x; };";
    std::cout << "\n> Passing '6' to lambda calculateSquareInt resulting -> "
              << squareInt;
    std::cout << "\n\n";
}
