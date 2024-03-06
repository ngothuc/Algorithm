#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int year;
  cin >> year;

  int count = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {
        sum += a[i];
      }
    }

    if (sum >= year) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}

