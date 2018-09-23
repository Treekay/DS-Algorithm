#include <iostream>
#include <memory.h>
#include <string>
using namespace std;

int main() {
    string str;
    while (cin >> str && str != "0") {
        int len = str.length();
        int dp[len];
        memset(dp,0,sizeof(dp)); 
        dp[0] = 1;
        for (int index = 1; index < len ; index++){
            if (str[index] == '0') {
                if (index == 1) dp[index] = dp[index-1];
                else dp[index] = dp[index-2];
            }
            else {
                if ((str[index-1] == '1' && str[index] <= '9')|| (str[index-1] == '2' && str[index] <= '6')) {
                    if (index == 1) dp[index] = dp[index-1] + 1;
                    else dp[index] = dp[index-1] + dp[index-2];
                }
                else dp[index] = dp[index-1];
            }
        }
        cout << dp[len-1] << endl;
    }
    return 0;
}