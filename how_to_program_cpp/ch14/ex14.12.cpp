#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

const int PNUM_MAX = 7; // maximum digit of a phone number
void entry(const std::string &foo);
void mapping(const std::string &number, const std::string &shadow);
std::fstream file("./ch14/phoneList.txt", std::ios::out);

int main(int argc, char **argv) {
    if (!file) {
        std::cerr << "File could not open.\n";
        exit(1);
    }

    std::string number;
    if (argc == 2) {
        number = argv[1];
    re:
        try {
            if (number.length() != PNUM_MAX)
                throw std::invalid_argument("phone numbers have to be 7-digit");
            for (char d : number)
                if (d == '0' || d == '1')
                    throw std::invalid_argument("only 2~9 should be used");
        } catch (std::invalid_argument &ex) {
            std::cout << ex.what() << std::endl;
            std::cout << "change " << number << "\nto     ";
            std::getline(std::cin, number);
            goto re;
        }

        entry(number);
        file.close();
        std::cout << "Please check file \"phoneList.txt\" for the "
                     "result.\nThanks for using~~\n";
    } else {
        std::cout << "phone number: ";
        std::getline(std::cin, number);
        goto re;
    }
}

// 呢度嘥咗我3~4個鐘由諗到試，再debug 然後終於得咗。
// onLung9 復雜到癲，我都幾肯定第時睇返都未必明......
void entry(const std::string &number) {
    std::string shadow = "0000000";
    //                    ^MSB  ^LSB(rp)
    char *const rp = &shadow[PNUM_MAX - 1]; // fix rp point to LSB (i.e. 6)
    char *lp = rp - 1;                      // lp point to left of rp (i.e. 5)

    // fix the 進位 of LSB，如果係9 就0123 進位，其他都係012 就進
    char least = (number[PNUM_MAX - 1] == '9' ? '4' : '3');
    while (true) {
        // 固定最右邊嘅位012 or 0123 咁加上去
        while (*rp < least) {
            // std::cout << foo << std::endl; // check shadow number map
            mapping(number, shadow);
            ++(*rp);
        }
        *rp = '0'; // 當進位時就reset 返做0 for 下次loop

        /* number[lp - &shadow[0]] == '9' ? '3' : '2'
         * 咁復雜其實都係想判斷*lp 嘅進位值係幾多，但因為lp 係會郁，所以就咁囉..
         *  0x 1 2 3 4 5 6 7
         *  [] 0 1 2 3 4 5 6
         * foo 0 0 0 0 0 0 0
         *     ^x        ^lp
         * memory 入邊x 係細過lp，所以 lp - x == 0x6 - 0x1 = 5
         * 5 係number 嘅index，咁樣變相就揾到*lp 嘅值係咪'9'，從而判斷進位值。
         * foo 0 0 0 0 0 0 0
         *     ^x    ^lp     -- 0x4 - 0x1 = 3 */
        while (*lp == (number[lp - &shadow[0]] == '9' ? '3' : '2')) {
            // 咁其實呢個while-loop 好簡單做一件事嘅姐
            // 就係判斷*lp 要唔要進位，要嘅就reset 做'0'再左移一個位，
            // 直到lp 指向嘅值唔需要進位>1
            *lp-- = '0';

            // 呢個係判斷當lp 指向MSB 同時個值已經無得再進位嘅時候，就可以quit
            // 咗呢個function 去
            if (lp == &shadow[0] &&
                *lp == (number[lp - &shadow[0]] == '9' ? '3' : '2')) {
                return; // 唯一出口
            }
        }
        ++(*lp);     // 1< 就可以加1
        lp = rp - 1; // 然後再reset lp 指向最右邊數起第二個位
    }
}

void mapping(const std::string &number, const std::string &shadow) {
    // change std::cout stream buffer to file phoneList buffer
    std::streambuf *stdout;
    stdout = std::cout.rdbuf(file.rdbuf());

    char two[] = "ABC";
    char three[] = "DEF";
    char four[] = "GHI";
    char five[] = "JKL";
    char six[] = "MNO";
    char seven[] = "PRS";
    char eight[] = "TUV";
    char nine[] = "WXYZ";

    for (int i = 0; i < PNUM_MAX; ++i) {
        switch (number[i]) {
        case '2':
            std::cout << two[shadow[i] - '0'];
            break;
        case '3':
            std::cout << three[shadow[i] - '0'];
            break;
        case '4':
            std::cout << four[shadow[i] - '0'];
            break;
        case '5':
            std::cout << five[shadow[i] - '0'];
            break;
        case '6':
            std::cout << six[shadow[i] - '0'];
            break;
        case '7':
            std::cout << seven[shadow[i] - '0'];
            break;
        case '8':
            std::cout << eight[shadow[i] - '0'];
            break;
        case '9':
            std::cout << nine[shadow[i] - '0'];
            break;
        default:
            break;
        };
    };
    std::cout.put('\n');

    // change back std::cout stream buffer to its original
    std::cout.rdbuf(stdout);
}
