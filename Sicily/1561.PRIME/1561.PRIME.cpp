#include <iostream>
#include <cmath>
using namespace std;

/*基础做法为从 2 到 n-1 逐个除*/
/*改良版为从 2 到 sqrt(n) 即可，因为两因数(若存在)，必然有一个小于sqrt(n)，一个大于sqrt(n)*/
/*最佳版， 大于 5 的素数都在 6 的倍数两侧， 但在 6 的倍数两侧的数不一定是素数*/
bool IsPrime(int num) {
    if (num == 2 || num == 3) return true;    //小于5的两个素数另外处理
    if (num % 6 != 1 && num % 6 != 5) return false;   //
    int temp = sqrt(num);
    for (int i = 5; i <= temp; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

int main(void) {
    int n;
    cin >> n;   // find the n th prime number
    int count = 0;
    int current = 2;
    while (count != n) {
        if (IsPrime(current)) count++;
        current++;
    }
    cout << current - 1 << endl;
    return 0;
}