#include <iostream>
#include <vector>

#ifndef LC_TOOLS
#define LC_TOOLS

template <typename T>
std::ostream &operator<<(std::ostream &c, const std::vector<T> &arr) noexcept {
    if (arr.empty())
        return (c << "[]"), c;

    c << '[';
    for (const T &col : arr)
        c << col << ',';
    c << "\b]";

    return c;
}

template <typename T>
std::ostream &operator<<(std::ostream &c,
                         const std::vector<std::vector<T>> &arr) noexcept {
    if (arr.empty())
        return (c << "[]"), c;

#ifdef MULTILINE
    c << "[\n";
    for (const std::vector<T> &row : arr)
        c << "  " << row << '\n';
    c << "]";
#else
    c << '[';
    for (const std::vector<T> &row : arr)
        c << row << ',';
    c << "\b]";
#endif

    return c;
}

#endif
