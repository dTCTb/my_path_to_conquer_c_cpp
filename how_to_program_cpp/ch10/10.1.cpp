// Fig. 10.1: fig10_01.cpp
// Standard Library string class test program
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1("happy");
    string s2(" birthday");
    string s3;

    // cout << "s1 is \"" << s1 << "\"; s2 is \"" << s2 << "\"; s3 is \"" << s3
    // << "\"\n";
    printf("s1 is \"%s\"; s2 is \"%s\"; s3 is \"%s\"\n", s1.data(), s2.data(),
           s3.data());
    cout << "\nThe results of comparing s2 and s1:"
         << "\ns2 == s1 yields " << (s2 == s1 ? "true" : "false")
         << "\ns2 != s1 yields " << (s2 != s1 ? "true" : "false")
         << "\ns2 > s1 yields " << (s2 > s1 ? "true" : "false")
         << "\ns2 < s1 yields " << (s2 < s1 ? "true" : "false")
         << "\ns2 >= s1 yields " << (s2 >= s1 ? "true" : "false")
         << "\ns2 <= s1 yields " << (s2 <= s1 ? "true" : "false");

    cout << "\n\nTesting s3.empty():" << endl;

    if (s3.empty()) {
        cout << "s3 is empty; assignment s1 to s3;" << endl;
        s3 = s1;
        cout << "s3 is \"" << s3 << '\"';
    }

    cout << "\n\ns1 += s2 yields s1 = ";
    s1 += s2;
    cout << s1;

    cout << "\n\ns1 += \" to you\" yields" << endl;
    s1 += " to you";
    cout << "s1 = " << s1 << "\n\n";
    cout << "The substring of s1 starting at location 0 for\n"
         << "14 characters, s1.substr(0, 14), is:\n"
         << s1.substr(0, 14) << "\n\n";

    cout << "The substring of s1 starting at\n"
         << "location 15, s1.substr(15), is:\n"
         << s1.substr(15) << endl;

    string s4(s1);
    cout << "\ns4 = " << s4 << "\n\n";

    cout << "assigning s4 to s4" << endl;
    s4 = s4;
    cout << "s4 = " << s4 << endl;

    s1[0] = 'H';
    s1[6] = 'B';
    cout << "\ns1 after s1[0] = 'H' and s1[6] = 'B' is: " << s1 << "\n\n";

    try {
        cout << "Attempt to assign 'd' to s1.at(30) yields:" << endl;
        s1.at(30) = 'd';
    } catch (out_of_range &ex) {
        cout << "An exception occured: " << ex.what() << endl;
    }
}
/* execution result
 * s1 is "happy"; s2 is " birthday"; s3 is ""
 *
 * The results of comparing s2 and s1:
 * s2 == s1 yields false
 * s2 != s1 yields true
 * s2 > s1 yields false
 * s2 < s1 yields true
 * s2 >= s1 yields false
 * s2 <= s1 yields true
 *
 * Testing s3.empty():
 * s3 is empty; assignment s1 to s3;
 * s3 is "happy"
 *
 * s1 += s2 yields s1 = happy birthday
 *
 * s1 += " to you" yields
 * s1 = happy birthday to you
 *
 * The substring of s1 starting at location 0 for
 * 14 characters, s1.substr(0, 14), is:
 * happy birthday
 *
 * The substring of s1 starting at
 * location 15, s1.substr(15), is:
 * to you
 *
 * s4 = happy birthday to you
 *
 * assigning s4 to s4
 * s4 = happy birthday to you
 *
 * s1 after s1[0] = 'H' and s1[6] = 'B' is: Happy Birthday to you
 *
 * Attempt to assign 'd' to s1.at(30) yields:
 * An exception occured: basic_string
 */
