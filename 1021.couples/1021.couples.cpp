#include <iostream>
#include <stack>
using namespace std;

int couple_set[200002];

int main(void) {
    int couple_num;
    while (cin >> couple_num && couple_num) {
        stack<int> match;
        int boy, girl;
        for (int i = 0; i < couple_num; i++) {
            cin >> boy >> girl;
            couple_set[boy] = girl;
            couple_set[girl] = boy;
        }
        for (int i = 1; i <= couple_num*2; i++) {
            if (match.empty() || match.top() != couple_set[i]) {
                match.push(i);
            }
            else {
                match.pop();
            }
        }
        if (match.empty()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}