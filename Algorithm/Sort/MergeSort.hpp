#ifndef _MERGESORT_HPP_
#define _MERGESORT_HPP_

void Merge(int *data, int start, int mid, int end) {
    int num = end - start;
    int *temp = new int[num];
    for (int i = 0, j = start; j <= end; i++, j++) {
        temp[i] = data[j];
    }

    // 合并左右半部, 每次从左右半部中选出小的一个
    int count = 0, l = start, r = mid + 1;
    while (l <= mid || r <= end) {
        if (l <= mid && (data[l] < data[r] || r > end)) {
            temp[count++] = data[l++];
        }
        else {
            temp[count++] = data[r++];
        }
    }

    for (int i = 0, j = start; j <= end; i++, j++) {
        data[j] = temp[i];
    }

    delete [] temp;
}

void MergeSort(int *data, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        MergeSort(data, start, mid); // 将左半部继续划分
        MergeSort(data, mid + 1, end); // 将右半部继续划分
        Merge(data, start, mid, end); // 合并左右半部
    }
}

#endif