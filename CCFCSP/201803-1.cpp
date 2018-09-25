#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    std::vector<int> jumps;

    int input;
    do {
        cin >> input;
        jumps.push_back(input);
    } while (input != 0);

    int current = 0;
    int score = 0;
    int grade = 0;
    while (current != jumps.size()) {
        if (jumps[current] == 0) {
            cout << score << endl;
            break;
        }
        else if (jumps[current] == 1) {
            score++;
            grade = 0;
        }
        else {
            grade++;
            score += 2*grade; 
        }
        current++;
    }
}