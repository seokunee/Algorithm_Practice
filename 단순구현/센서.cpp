// 2212
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
  int N,K,V;
  cin >> N >> K;
  vector<int> arr;
  for (int i = 0; i < N; i++){
    cin >> V;
    arr.push_back(V);
  }

  sort(arr.begin(), arr.end());
  vector<int> diss;
  for (int i = 0; i < N - 1; i++){
    diss.push_back(arr[i + 1] - arr[i]);
  }

  sort(diss.begin(), diss.end(), [](const auto &a, const auto &b){
    return a > b;
  });
  int answer = 0;
  for (int i = 0; i < diss.size(); i++){
    if (i < K - 1)
      continue;
    else
      answer += diss[i];
  }
  cout << answer << endl;
  return 0;
}