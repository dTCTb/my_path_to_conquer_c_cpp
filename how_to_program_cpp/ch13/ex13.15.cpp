// exercise 13.15 (448)
/* (Point 類) 編寫一個程序完成下面的功能。
 * a) 創建用戶自定義類Point，使其擁有private
 * 整型數據成員xCoordinate 和yCoordinate，
 * 並聲明重載的流插入和流提取運算符函數為該類的友元。
 * b) 定義流插入和流提取運算符函數。
 * 流提取運算符函數應該判定輸入的數據是否有效，
 * 如果不是，它應該設置failbit 位表示有錯誤的輸入。
 * 當輸入發錯誤時，流插入運算符不能顯示這個點。
 * （呢度我用咗do-while loop 嚟叫user 不斷重新輸入）
 * c) 編寫一個main 函數，測試用戶自定義類Point 的輸入／輸出，
 * 其中使用重載的流提取和流插入運算符。
 */
#include <iostream>
using namespace std;

class Point {
    friend ostream &operator<<(ostream &, Point &);
    friend istream &operator>>(istream &, Point &);

  private:
    int xCoordinate;
    int yCoordinate;

  public:
    Point() {};
    Point(int sx, int sy) : xCoordinate(sx), yCoordinate(sy) {}
    Point(Point &) = default;
    Point(Point &&) = default;
    ~Point() = default;
    Point &operator=(Point &) = default;
    Point &operator=(Point &&) = default;

    inline Point &setX(int x) noexcept {
        xCoordinate = x;
        return *this;
    }

    inline int &setX() noexcept { return xCoordinate; }
    inline Point &setY(int y) noexcept {
        yCoordinate = y;
        return *this;
    }
    inline int &setY() noexcept { return yCoordinate; }

    int getX() const noexcept { return xCoordinate; }
    int getY() const noexcept { return yCoordinate; }
};

ostream &operator<<(ostream &c, Point &p) {
    c << '(' << p.getX() << ',' << p.getY() << ')';
    return c;
}

istream &operator>>(istream &c, Point &p) {
    // int x, y;
    do {
        if (c.fail()) {
            c.clear();
            c.ignore(1024, '\n');
            cerr << "Invalid input, please try again" << endl;
        }

        cout << "x: ";
        c >> p.setX();

        if (c.peek() == '\n') {
            cout << "y: ";
            c >> p.setY();
        } else
            c >> p.setY();
    } while (c.fail());
    // p.setX(x).setY(y);
    return c;
}

int main() {
    cin.tie(0);
    Point dot, tod;
    cin >> dot >> tod;
    cout << dot << '\n' << tod << endl;
}
/* 我喺呢個exercise 學到：
 * 1. 處理流錯誤時，要定要reset 咗stream status 先，
 *    因為修stream 唔係good 嘅狀態嘅話，我係用唔到任何對stream 嘅操作，
 *    包括ignore() get() getline() 呢啲喺條stream 到拎嘢走嘅operation。
 *    我就係卡咗喺呢度好耐，我先ignore 咗stream buffer 然後先clear() 呢個次序
 *    係錯曬！！！
 * 2. ignore() 原來係會一路計discard 咗幾多個字符，
 *    同時每次discard 前都會比較下係咪delimiter 個字符嚟，
 *    而呢個discard 同比較係確確實實地extract 咗個字符，所以我原先以為嘅
 *    cin.ignore(100000, '\n').get(); 係錯誤地理解為discard 到\n 前，
 *    然後再get() 埋個\n，但原來係extract 咗\n，發現係delimiter 嚟，
 *    所以就stop 咗ignore()。
 * 3. 更深刻地了解到，一但cin 有failbit 發生，但連嗰導致failbit 發生嘅字符
 *    都唔extract，並且因為再唔係good 狀態，所以所有嘅cin operation 都跳過曬
 *    完全唔執行。
 */
