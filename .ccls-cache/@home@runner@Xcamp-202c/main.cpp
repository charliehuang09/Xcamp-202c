#include <iostream>
#include <set>
#include <vector>
using namespace std;
int n, l, p;
vector<vector<int>> binary;
int times = 0;
void dfs(vector<int> input, int pos, int one) {
  if (pos == l) {
    binary.push_back(input);
    times++;
    if (times == p) {
      for (int i = 0; i < l; i++) {
         cout << input[i];
      }
       cout << "\n";
      exit(0);
    }
    return;
  }

  input[pos] = 0;
  dfs(input, pos + 1, one);
  if (one < n) {
    input[pos] = 1;
    dfs(input, pos + 1, one + 1);
  }
}
int main() {
  cin >> l >> n >> p;
  vector<int> arr;
  for (int i = 0; i < l; i++) {
    arr.push_back(0);
  }
  dfs(arr, 0, 0);
}