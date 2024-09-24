#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct trie {
    trie *arr[26];
    bool end;
    trie() : arr{nullptr}, end{false} {}
};

class Solution {
  public:
    int minExtraChar(string s, vector<string> &dictionary) {
        int min{};

        map<size_t, vector<string>> table{};

        for (string &dict : dictionary)
            (table[dict.size()]).push_back(dict);

        // auto compare = [&s](auto bb, auto be, size_t i) -> size_t {
        //     while (bb != be) {
        //         string tmpStr{s.substr(i, bb->first)};
        //         for (string &dict : bb->second) {
        //             if (tmpStr == dict) {
        //                 return bb->first;
        //             }
        //         }
        //         ++bb;
        //     }
        //     return 0UL;
        // };

        // 1st Trial
        // 用咗呢個除咗eg4 錯，其他啱
        for (size_t i{}; i < s.size();) {
            size_t tmpI{i};

            for (auto bb{table.rbegin()}; bb != table.rend(); ++bb) {
                string tmpStr{s.substr(i, bb->first)};
                for (string &dict : bb->second)
                    if (tmpStr == dict)
                        i += bb->first;
                if (i != tmpI)
                    break;
            }

            // if (size_t r = compare(table.rbegin(), table.rend(), i))
            //     i += r;

            if (tmpI == i) {
                ++i;
                ++min;
            }
        }

        // 2nd Trial
        // 諗住試下由後開始，但好似錯仲多
        /* for (size_t i{s.size()}; i > 0;) {
            size_t tmpI{i};
            for (auto bb{table.rbegin()}; bb != table.rend(); ++bb) {
                if (i < bb->first)
                    continue;
                string tmpStr{s.substr(i - bb->first, bb->first)};
                for (string &dict : bb->second)
                    if (tmpStr == dict)
                        i -= bb->first;
                if (i != tmpI)
                    break;
            }
            if (tmpI == i) {
                --i;
                ++min;
            }
        } */

        // 4th Trial
        // 每次解決到一個case 之很，另一個又唔得，你老母
        // 用呢個eg4 啱，除咗eg3 eg8
        // eg8 係因為dict 有n nk kl，下面方法會先match nk 然後n，剩低l
        // 但好撚on9 嘅係，nkl 呢個組合，標準答案係match 咗n 然後kl
        // 好撚on9, 我用1st trial 同4th trial 組合pass 到2024/2028
        // 但就差呢個位，另到我用咗半日，真係有6個鐘以上，做呢條leetcode
        // 屌你老母testcase
        string S{s};
        size_t used{};
        for (auto bb{table.rbegin()}; bb != table.rend(); ++bb) {
            for (size_t i{}; i < S.size() && S.size() - i >= bb->first;) {
                string tmpStr{S.substr(i, bb->first)};
                bool replaced{false};

                // check if the string contains ' ', if yes jump to next cycle
                if (strchr(tmpStr.data(), '#')) {
                    ++i;
                    continue;
                }

                for (string &dict : bb->second) {
                    if (tmpStr == dict) {
                        S.replace(i, bb->first, "#");
                        replaced = true;
                        used += bb->first;
                        break;
                    }
                }
                if (!replaced)
                    //     i = 0;
                    // else
                    ++i;
            }
        }

        // return min; // 1st Trial result
        return s.size() - used; // 4th Trial result
        // 如果1st 同4th 都各有錯嘅，咁我兩個都run 然後揀個細嘅return 咪得！
        // return (min < s.size() - used) ? min : s.size() - used;
    }

    // 3rd Trial
    // 仲試埋新學到嘅trie 都係有錯，都係解決唔到eg4 嘅'ea' & 'encgpg' 問題
    // 用呢個eg4 & eg7 都會錯，其他啱
    int trie(string s, vector<string> &dictionary) {
        int min{};
        struct trie *root = new struct trie {};
        for (string &dict : dictionary) {
            struct trie *cur{root};
            for (char c : dict) {
                if (cur->arr[c - 'a'] == nullptr)
                    cur->arr[c - 'a'] = new struct trie {};
                cur = cur->arr[c - 'a'];
            }
            cur->end = true;
        }

        for (size_t i{}; i < s.size();) {
            struct trie *cur{root};
            size_t tmpI{i};
            while (cur->arr[s[tmpI] - 'a']) {
                cur = cur->arr[s[tmpI] - 'a'];
                ++tmpI;
            }
            if (cur->end)
                i += tmpI - i;
            else {
                ++i;
                ++min;
            }
        }

        return min;
    }
};

int main() {
    typedef std::pair<std::string, std::vector<std::string>> testCase;
    Solution s;

    auto test = [&s](testCase &eg, int ans) {
        static size_t no{0};
        int myAns{s.minExtraChar(eg.first, eg.second)};
        cout << "Testcase " << ++no << ": " << (myAns == ans) << " [" << myAns
             << '|' << ans << "]\n";
    };

    testCase eg1{"leetscode", {"leet", "code", "leetcode"}};
    testCase eg2{"sayhelloworld", {"hello", "world"}};
    testCase eg3{"aakodubkrlauvfkzje",
                 {"ix",  "qoqw", "ax",   "ar",   "v",    "hxpl", "nxcg", "thr",
                  "kod", "pns",  "cdo",  "euy",  "es",   "rf",   "bxcx", "xe",
                  "ua",  "vws",  "vumr", "zren", "bzt",  "qwxn", "ami",  "rrbk",
                  "ak",  "uan",  "g",    "vfk",  "jxmg", "fhb",  "nqgd", "fau",
                  "rl",  "h",    "r",    "jxvo", "tv",   "smfp", "lmck", "od"}};
    //            12   .
    testCase eg4{"metzeaencgpgvsckjrqafkxgyzbe",
                 {"zdzz",  "lgrhy", "r",     "ohk",  "zkowk", "g",    "zqpn",
                  "anoni", "ka",    "qafkx", "t",    "jr",    "xdye", "mppc",
                  "bqqb",  "encgp", "yf",    "vl",   "ctsxk", "gn",   "cujh",
                  "ce",    "rwrpq", "tze",   "zxhg", "yzbe",  "c",    "o",
                  "hnk",   "gv",    "uzbc",  "xn",   "kk",    "ujjd", "vv",
                  "mxhmv", "ugn",   "at",    "kumr", "ensv",  "x",    "uy",
                  "gb",    "ae",    "jljuo", "xqkgj"}};
    testCase eg5{"dwmodizxvvbosxxw",
                 {"ox", "lb", "diz", "gu", "v", "ksv", "o", "nuq", "r", "txhe",
                  "e", "wmo", "cehy", "tskz", "ds", "kzbu"}};
    //            111111110001111000111111000
    testCase eg6{"kevlplxozaizdhxoimmraiakbak",
                 {"yv",    "bmab", "hv",    "bnsll", "mra",   "jjqf",  "g",
                  "aiyzi", "ip",   "pfctr", "flr",   "ybbcl", "biu",   "ke",
                  "lpl",   "iak",  "pirua", "ilhqd", "zdhx",  "fux",   "xaw",
                  "pdfvt", "xf",   "t",     "wq",    "r",     "cgmud", "aokas",
                  "xv",    "jf",   "cyys",  "wcaz",  "rvegf", "ysg",   "xo",
                  "uwb",   "lw",   "okgk",  "vbmi",  "v",     "mvo",   "fxyx",
                  "ad",    "e"}};
    testCase eg7{"rkmsilizktprllwoimafyuqmeqrujxdzgp",
                 {"afy",   "lyso",  "ymdt",  "uqm",  "cfybt", "lwoim", "hdzeg",
                  "th",    "rkmsi", "d",     "e",    "tp",    "r",     "jx",
                  "tofxe", "etjx",  "llqs",  "cpir", "p",     "ncz",   "ofeyx",
                  "eqru",  "l",     "demij", "tjky", "jgodm", "y",     "ernt",
                  "jfns",  "akjtl", "wt",    "tk",   "zg",    "lxoi",  "kt"}};
    testCase eg8{"jldenbyrtfdvgsfdvgstgnqenbyrnklhobd",
                 {"leu",  "e",  "fdvgs", "i",  "q",     "nk",  "tz", "logd",
                  "rm",   "tg", "fmil",  "kl", "xp",    "rlz", "sr", "w",
                  "dvjv", "ow", "cub",   "n",  "enbyr", "bd",  "cwz"}};
    vector<testCase *> testCases{&eg1, &eg2, &eg3, &eg4,
                                 &eg5, &eg6, &eg7, &eg8};

    // for (testCase *eg : testCases)
    //     cout << s.minExtraChar(eg->first, eg->second) << endl;

    size_t no{};
    int tmpMin{};
    cout << boolalpha;
    test(eg1, 1);
    test(eg2, 3);
    test(eg3, 9);
    test(eg4, 5);
    test(eg5, 7);
    test(eg6, 9);
    test(eg7, 2);
    test(eg8, 6);
}
