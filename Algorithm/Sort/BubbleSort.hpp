#ifndef _BUBBLESORT_H
#define _BUBBLESORT_H

void BubbleSort(int *data, int num) {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

#endif // !_BUBBLESORT_H