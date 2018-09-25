#include <iostream>
using namespace std;

int main(void) {
    int n; /* nums of keys */
    int k; /* nums of teachers */

    cin >> n >> k;

    typedef struct teacher {
        int key_no;
        int start;
        int end;
    } teacher;

    int key_boxs[n];
    for (int i = 0; i < n; i++) {
        key_boxs[i] = i+1;
    }
    teacher teachers[k];

    int total_times = 0; /* the total times */
    for (int i = 0; i < k; i++) {
        cin >> teachers[i].key_no >> teachers[i].start >> teachers[i].end;
        if (total_times < teachers[i].start + teachers[i].end) {
            total_times = teachers[i].start + teachers[i].end;
        }
    }

    int temporary_box[n] = {0};

    /* stimulate */
    for (int t = 1; t <= total_times; t++) {
        /* return the key */
        for (int i = 0; i < k; i++) {
            if (teachers[i].start + teachers[i].end == t) {
                temporary_box[teachers[i].key_no-1] = teachers[i].key_no;
            }
        }
        /* find the empty key box*/
        for (int j = 0; j < n; j++) {
            if (temporary_box[j] != 0) {
                for (int i = 0; i < n; i++) {
                    if (key_boxs[i] == 0) {
                        key_boxs[i] = temporary_box[j];
                        temporary_box[j] = 0;
                        break;
                    }
                }
            }
        }

        /* take the key */
        for (int i = 0; i < k; i++) {
            if (teachers[i].start == t) {
                /* find the key he wants */
                for (int j = 0; j < n; j++) {
                    if (key_boxs[j] == teachers[i].key_no) {
                        key_boxs[j] = 0;
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << key_boxs[i] << " ";
    }
    return 0;
}