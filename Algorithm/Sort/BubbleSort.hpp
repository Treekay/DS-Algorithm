#ifndef _BUBBLESORT_H
#define _BUBBLESORT_H

void BubbleSort(int *data, int num) {
    for (int i = 0; i < num; i++) {
        for (int j = i; j < num; j++) {
            if (data[i] > data[j]) {
                int temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

#endif // !_BUBBLESORT_H