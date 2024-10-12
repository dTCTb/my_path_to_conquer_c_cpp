#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {
  public:
    /* Editorial Deque */
    static bool deque_areSentencesSimilar(std::string s1, std::string s2) {
        std::istringstream iss1(s1);
        std::deque<std::string> deque1(
            (std::istream_iterator<std::string>(iss1)),
            std::istream_iterator<std::string>());
        std::istringstream iss2(s2);
        std::deque<std::string> deque2(
            (std::istream_iterator<std::string>(iss2)),
            std::istream_iterator<std::string>());
        // Compare the prefixes or beginning of the strings.
        while (!deque1.empty() && !deque2.empty() &&
               deque1.front() == deque2.front()) {
            deque1.pop_front();
            deque2.pop_front();
        }
        // Compare the suffixes or ending of the strings.
        while (!deque1.empty() && !deque2.empty() &&
               deque1.back() == deque2.back()) {
            deque1.pop_back();
            deque2.pop_back();
        }
        return deque1.empty() || deque2.empty();
    }
    /* Editorial Two Pointers */
    static bool twoPointers_areSentencesSimilar(string s1, string s2) {
        // Convert sentences to lists of words
        stringstream ss1(s1), ss2(s2);
        string word;
        vector<string> s1Words, s2Words;
        while (ss1 >> word)
            s1Words.push_back(word);
        while (ss2 >> word)
            s2Words.push_back(word);

        int start = 0, ends1 = s1Words.size() - 1, ends2 = s2Words.size() - 1;

        // If words in s1 are more than s2, swap them and return the answer.
        if (s1Words.size() > s2Words.size())
            return twoPointers_areSentencesSimilar(s2, s1);

        // Find the maximum words matching from the beginning.
        while (start < s1Words.size() && s1Words[start] == s2Words[start])
            ++start;

        // Find the maximum words matching in the end.
        while (ends1 >= 0 && s1Words[ends1] == s2Words[ends2]) {
            --ends1;
            --ends2;
        }

        // If ends1 index is less than start, then sentence is similar.
        return ends1 < start;
    }

    /* 128/138 testcases passed */
    static bool my_areSentencesSimilar(string sentence1,
                                       string sentence2) noexcept {
        stringstream ss1{sentence1};
        stringstream ss2{sentence2};
        string s1, s2;
        vector<string> S1, S2;
        int prefix{-1}, suffix{-1};
        while (ss1 >> s1)
            S1.push_back(s1);
        while (ss2 >> s2)
            S2.push_back(s2);

        for (size_t i{}; i < S1.size() && i < S2.size(); ++i) {
            if (S1[i] == S2[i])
                prefix = i;
            else
                break;
        }
        for (int i{(int)S1.size() - 1}, j{(int)S2.size() - 1}; i >= 0 && j >= 0;
             --i, --j) {
            if (S1[i] == S2[j])
                suffix = S2.size() - j;
            else
                break;
        }
        if (prefix != -1 && suffix != -1)
            return true;
        if (prefix == S1.size() - 1 || prefix == S2.size() - 1)
            return true;
        if (suffix == S2.size() - 1)
            return true;
        if (sentence2.size() > sentence1.size())
            return false;

        cout << prefix << ' ' << suffix << '\n';
        if (prefix != -1 && suffix == -1 && S1.back() == S2.back())
            return true;
        if (prefix == -1 && suffix != -1 && S1.front() == S2.front())
            return true;

        return false;
    }
};

int main() {
    Solution s;
    // string s1{"My name is Haley"};
    // string s2{"My Haley"};
    // string s1{"a A b A"};
    // string s2{"A"};
    // string s1{"z z z z"};
    // string s2{"zz z"};
    // string s1{"hello racecar"};
    // string s2{"hello racecar acecar"};
    string s1{"Eating right now"};
    string s2{"Eating"};
    cout << boolalpha << Solution::twoPointers_areSentencesSimilar(s1, s2)
         << '\n';
}

function<char(void)> _ = []() -> char {
    std::ios::sync_with_stdio(false);
    std::cout.tie(0);
    std::cin.tie(0);
    return 'c';
};
