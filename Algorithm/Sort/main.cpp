#include <iostream>

#include "MergeSort.hpp"
#include "QuickSort.hpp"
#include "SelectSort.hpp"
#include "BubbleSort.hpp"
#include "InsertSort.hpp"
#include "HeapSort.hpp"

using std::cin;
using std::cout;
using std::endl;

int main(void) {
    // 输入总数
    int len;
    cout << "totalNum: ";
    cin >> len;

    // 输入数字
    int data[len] = {0};
    for (int i = 0; i < len; i++) {
        cin >> data[i];
    }

    // 排序前的顺序
    cout << "before sorted: ";
    for (int i = 0; i < len; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    // 排序
    // MergeSort(data, 0, len-1);
    // QuickSort(data, 0, len - 1);
    // SelectSort(data, len);
    // BubbleSort(data, len);
    // InsertSort(data, len);
    HeapSort();

    // 排序后的顺序
    cout << "after sorted: ";
    for (int i = 0; i < len; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}