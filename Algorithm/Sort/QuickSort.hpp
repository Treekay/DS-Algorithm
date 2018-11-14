#ifndef _QUICKSORT_H
#define _QUICKSORT_H

void QuickSort(int *data, int left, int right) {
	if (left >right) return;

    // 将最左的数作为基准
	int pos = left;
    int pivot = data[pos];
	int end = right;
 
    // 当左右哨兵相遇时退出循环
	while(left != right) {
		while(data[right] >= pivot && left < right) right--; // 从后往前找到比基准小的数
		while(data[left] <= pivot && left < right) left++; // 从前往后找到比基准大的数
		if(left < right) {
			int temp = data[right];
			data[right] = data[left];
			data[left] = temp;
		}	
	}
    // 基准放回中间
    data[pos] = data[left];
	data[left] = pivot;
 
	//递归处理归位后的基准数的左右两侧
	QuickSort(data, pos, left - 1);  //此时left = right
	QuickSort(data, left + 1, end);
}

#endif // !_QUICKSORT_H