/* Problem of the Day #2 */

#include <ctime>
#include <iostream>

using namespace std;

int main() {
  time_t sec_since_epoch = time(nullptr);
  int hours = sec_since_epoch/3600;
  int days = hours/24;
  int years = days/365;
  cout << "Hours: " << hours << endl;
  cout << "Days: " << days << endl;
  cout << "Years: " << years << endl;

  return 0;
}
