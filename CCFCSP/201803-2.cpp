#include <iostream>
using namespace std;

int main(void) {
    int n; /* the nums of the balls */
    int l; /* the length of the whole line */
    int t; /* the time of simulating */
    cin >> n >> l >> t;

    int balls_pos[n];
    int moves[n];

    for (int i = 0; i < n; i++) {
        cin >> balls_pos[i];
        // default move towards right
        // right as 1, left as -1
        moves[i] = 1;
        if (balls_pos[i] == 0 || balls_pos[i] == l) {
            moves[i] = -1;
        }
    }

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < n; j++) {
            balls_pos[j] += moves[j];

            /* check if in the endpoint */
            if (balls_pos[j] == 0 || balls_pos[j] == l) {
                /* if so, change the direction */
                moves[j] = -moves[j];
            }
        }
        /* check if struck with other balls */
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (balls_pos[k] == balls_pos[j] && k != j) {
                    moves[k] = -moves[k];
                    moves[j] = moves[j];
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << balls_pos[i] << " ";
    }
    return 0;
}