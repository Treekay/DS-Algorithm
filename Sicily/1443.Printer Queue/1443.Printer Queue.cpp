#include <iostream>
#include <queue>
using namespace std;

typedef struct job {
    int priority;
    int init_pos;
}job;

int main(void) {
    int test_time;
    cin >> test_time;
    while (test_time--) {
        int n;
        int pos;
        cin >> n >> pos;

        queue<job> controller;
        int num[n];

        for (int i = 0; i < n; i++) {
          job poi;
          cin >> poi.priority;
          poi.init_pos = i;
          controller.push(poi);

          num[i] = poi.priority;
        }

        for (int i = 0; i < n; i++) {
          for (int j = i + 1; j < n; j++) {
            if (num[i] < num[j]) {
              swap(num[i], num[j]);
            }
          }
        }

        int temp = 0;
        int count = 0;
        while (1) {
            if (controller.front().priority < num[temp]) {
                job poi;
                poi.priority = controller.front().priority;
                poi.init_pos = controller.front().init_pos;
                controller.pop();
                controller.push(poi);
            }
            else {
                count++;
                if (controller.front().init_pos == pos) break;
                controller.pop();
                temp++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
