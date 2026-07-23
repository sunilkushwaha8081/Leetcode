#include <iostream>
#include <string>
#include <climits>
#include <cctype>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();

        // Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // Check sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        long long num = 0;

        // Read digits
        while (i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');

            // Handle overflow
            if (sign * num >= INT_MAX)
                return INT_MAX;

            if (sign * num <= INT_MIN)
                return INT_MIN;

            i++;
        }

        return sign * num;
    }
};

int main() {
    Solution obj;
    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    int result = obj.myAtoi(s);

    cout << "Converted Integer = " << result << endl;

    return 0;
}