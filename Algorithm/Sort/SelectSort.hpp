#ifndef _SELECTSORT_H
#define _SELECTSORT_H

void SelectSort(int *data, int num) {
    for (int i = 0; i < num - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < num; j++) {
            if (data[j] < data[minPos]) {
                minPos = j;
            }
        }
        int temp = data[i];
        data[i] = data[minPos];
        data[minPos] = temp;
    }
}

#endif