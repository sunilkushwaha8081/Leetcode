#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int>& student, vector<int>& cookie) {
    sort(student.begin(), student.end());
    sort(cookie.begin(), cookie.end());

    int i = 0, j = 0, count = 0;

    while (i < student.size() && j < cookie.size()) {
        if (cookie[j] >= student[i]) {
            count++;
            i++;
            j++;
        } else {
            j++;
        }
    }

    return count;
}

int main() {
    vector<int> student = {1, 2, 3};
    vector<int> cookie = {1, 1};

    cout << findContentChildren(student, cookie) << endl;

    return 0;
}