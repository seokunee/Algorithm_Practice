// 2179
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
using namespace std;

int N;
vector<pair<string, int>> arr;

int main(){
  cin >> N;
  string str;
  vector<string> origin;
  for (int i = 0; i < N; i++){
    cin >> str;
    arr.push_back(make_pair(str, i));
    origin.push_back(str);
  }
  int MAX = 0;
  sort(arr.begin(), arr.end(), [](const auto &a, const auto &b){
    return a.first < b.first;
  });

  int len = arr.size();

  set<string> dusa;
  
  for (int k = 0; k < len - 1; k++){
    int i = 0;
    string one = arr[k].first;
    string two = arr[k + 1].first;
    while (one[i] && two[i] && one[i] == two[i]){
      i++;
    }

    if (i > 0 && MAX <= i){
      string tmp = one.substr(0, i);
      if (MAX == i)
        dusa.insert(tmp);
      else {
        MAX = i;
        dusa.clear();
        dusa.insert(tmp);
      }
    }
  }

  string depyo = "";
  
  for (string val : origin){
    if (depyo == "") {
      for (string com : dusa){
        if (val.compare(0, com.size(), com) == 0){
          depyo = com;
          cout << val << endl;
          break;
        }
      }
    } else {
      if (val.compare(0, depyo.size(), depyo) == 0){
        cout << val << endl;
        break;
      }
    }
  }
  
  return 0;
}