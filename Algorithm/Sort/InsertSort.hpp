#ifndef _INSERTSORT_H
#define _INSERTSORT_H

void InsertSort(int *data, int num) {
    for (int i = 1; i < num; i++) {
        int current = data[i];
        int index = i - 1;
        while (index >= 0 && data[index] > current) {
            data[index + 1] = data[index];
            index--;
        }
        data[index + 1] = current;
    }
}

#endif // !_INSERTSORT_H