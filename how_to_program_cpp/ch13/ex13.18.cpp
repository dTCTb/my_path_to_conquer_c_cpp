/* exercise 13.18 (448)
 * (空字符終止字符串)
 * 編寫一個程序，展示函數getline 和有3 個參數的get 成員函數都會以字符串
 * 終止符——空字符來作為輸入字符串的結尾字符。並展示get
 * 函數將分隔符留在輸入流中， 而getline
 * 則將分隔符從流中提取出來並弄棄。在流中沒有被讀取的字符會怎樣？
 */
#include <iostream>
using namespace std;

int main() {
    char str[10];

    cin.get(str, 10);
    if (str[cin.gcount()] == '\0')
        cout << "Yeah, it is NULL character\n";
    cout << str << endl;

    if (cin.peek() == '\n')
        cin.ignore(); // discard \n
    else
        cin.ignore(1024, '\n');

    cin.getline(str, 10);
    if (str[cin.gcount() == 9 ? 9 : cin.gcount() - 1] == '\0')
        cout << "Yeah, it is NULL character again\n";
    return 0;
}
// gcount() 係以extract 咗幾多個字符為count
// 就連extract 完再discard 嘅getline 入面嗰個\n 都計埋
// 所以gcount 呢個值係以extract 呢個動作為計算
// 之所以會有?; 係因為getline 有個機制如果起過10-1 characters
// 佢會喺9 呢個數字stop，而唔會extract 到\n character
// 但如果extract 到9個或以下字符就會extract 到\n，所以gcount 會有9個
