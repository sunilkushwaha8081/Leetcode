#include <iostream>
#include <stack>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> st; // {price, span}

    StockSpanner() {
    }

    int next(int price) {
        int span = 1;

        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});
        return span;
    }
};

int main() {
    StockSpanner obj;

    cout << obj.next(100) << endl; // 1
    cout << obj.next(80) << endl;  // 1
    cout << obj.next(60) << endl;  // 1
    cout << obj.next(70) << endl;  // 2
    cout << obj.next(60) << endl;  // 1
    cout << obj.next(75) << endl;  // 4
    cout << obj.next(85) << endl;  // 6

    return 0;
}