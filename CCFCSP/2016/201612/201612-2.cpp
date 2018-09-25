#include <iostream>
using namespace std;

int main(void) {
  int salary_range[] = {3500, 3500+1500, 3500+4500, 3500+9000, 3500+35000, 3500+55000, 3500+80000};
  int taxrate[] = {3, 10, 20, 25, 30, 35, 45};

  int income_range[7];

  int S, T;
  cin >> T;

  /* count the income range */
  income_range[0] = salary_range[0];
  for (int i = 1; i < 7; i++) {
    income_range[i] = income_range[i-1] + (salary_range[i] - salary_range[i-1]) - (salary_range[i] - salary_range[i-1])*taxrate[i-1]/100;
  }

  int i;
  for (i = 0;i < 7; i++) {
    if (T <= income_range[i]) break;
  }

  if (i == 0) S = T;
  else S = salary_range[i-1] + (T - income_range[i-1])*100 / (100 - taxrate[i-1]);

  cout << S << endl;

  return 0;
}