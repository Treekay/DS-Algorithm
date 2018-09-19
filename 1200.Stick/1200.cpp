
#include<iostream>
using namespace std;
 
int main() {
  int n,temp,res;

  while(cin >> n && n != 0) {   
    res = 0;
    while(n--) {
      cin >> temp;
      res ^= temp;
    }

    cout << res << endl;
  }
  return 0;
}         