#include <iostream>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

/* struct Path;

struct HashFunction {
    size_t operator()(const pair<string, Path *> &x) const {
        return accumulate(x.first.begin(), x.first.end(), 0L);
    }
}; */

/* struct Path {
    // unordered_set<pair<string, Path *>, HashFunction> sub;
    vector<pair<string, Path *>> sub;
    Path(string x) {
        sub.reserve(10);
        sub.push_back({x, nullptr});
    }
    void add(string x) {
        bool match = binary_search(sub.cbegin(), sub.cend(), x,
                                   [&x](string t) -> bool { return t == x; });
        Path *cur = this;
    }
}; */

class Solution {
  public:
    /* vector<string> removeSubfolders(vector<string> &folder) {
        vector<string> ret;
        Path *root = new Path{"/"};
        ret.reserve(30);

        for (string path : folder) {
            size_t i{1}, j{1};
            while (j < path.size()) {
                while (path[j] != '/' && j < path.size())
                    ++j;
                string tmp{path.substr(i, j - i)};
                cout << tmp << '\n';
                root->add(tmp);
                i = ++j;
            }
        }

        return ret;
    } */
    vector<string> removeSubfolders(vector<string> &folder) {
        // Create a set to store all folder paths for fast lookup
        unordered_set<string> folderSet(folder.begin(), folder.end());
        vector<string> result;

        // Iterate through each folder to check if it's a sub-folder
        for (string &f : folder) {
            bool isSubFolder = false;
            string prefix = f;

            // Check all prefixes of the current folder path
            while (!prefix.empty()) {
                size_t pos = prefix.find_last_of('/');
                if (pos == string::npos)
                    break;

                // Reduce the prefix to its parent folder
                prefix = prefix.substr(0, pos);

                // If the parent folder exists in the set, mark as sub-folder
                if (folderSet.count(prefix)) {
                    isSubFolder = true;
                    break;
                }
            }

            // If not a sub-folder, add it to the result
            if (!isSubFolder) {
                result.push_back(f);
            }
        }

        return result;
    }
};

basic_ostream<char> &operator<<(basic_ostream<char> &COUT, vector<string> s) {
    for (string &str : s)
        COUT << str << '\n';
    cout << "---\n";
    return COUT;
}

int main() {
    Solution s;
    vector<string> s1{"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};
    vector<string> s2{"/a", "/a/b/c", "/a/b/d"};
    vector<string> s3{"/a/b/c", "/a/b/ca", "/a/b/d"};
    vector<string> s4{"/aa/ab/ac/ae", "/aa/ab/af/ag", "/ap/aq/ar/as",
                      "/ap/aq/ar",    "/ap/ax/ay/az", "/ap",
                      "/ap/aq/ar/at", "/aa/ab/af/ah", "/aa/ai/aj/ak",
                      "/aa/ai/am/ao"};
    cout << s.removeSubfolders(s1);
    cout << s.removeSubfolders(s2);
    cout << s.removeSubfolders(s3);
    cout << s.removeSubfolders(s4);
}
