#include <iostream>
using namespace std;

int main(void) {
    int n; /* num of students */
    cin >> n;
    int student_queue[n];
    for (int i = 0; i < n; i++) {
        student_queue[i] = i+1;
    }

    int times; /* num of command */
    cin >> times;
    int move_no;
    int move;
    while (times--) {
        cin >> move_no >> move;
        int move_position;
        /* find the move_position */
        for (int i = 0; i < n; i++) {
            if (student_queue[i] == move_no) {
                move_position = i;
                break;
            }
        }
        if (move > 0) {
            for (int i = move_position; i < move_position + move; i++) {
                int temper = student_queue[i];
                student_queue[i] = student_queue[i+1];
                student_queue[i+1] = temper;
            }
        }
        else {
            for (int i = move_position; i > move_position + move; i--) {
                int temper = student_queue[i];
                student_queue[i] = student_queue[i-1];
                student_queue[i-1] = temper;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << student_queue[i] << " ";
    }
    return 0;
}