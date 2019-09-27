#include <bits/stdc++.h>

using namespace std;


int main() {
    string number;
    int n, k, i, j, l;
    while (cin >> n >> k) {
        cin >> number;
        l = 0;
        if(number.size() < 2 && k) {
            cout << 0 << endl;
            continue;
        }
        for (int i = 0; i < number.size() && l < k; ++i) {
            if (i == 0 and number[0] != '1') {
                l++;
                number[0] = '1';
            } else if (i and number[i] != '0') {
                l++;
                number[i] = '0';
            }
        }
        cout << number << endl;
    }
}