// 12869 
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int visited[61][61][61];

bool checkAllDie(vector<int> &arr){
  for (int value : arr){
    if (value <= 0)
      continue;
    return false;
  }
  return true;
}

vector<int> makeNextVec(vector<int> &arr, vector<int> minus){
  vector<int> tmp;
  for (int i = 0; i < arr.size(); i++){
    int value = arr[i] - minus[i] <= 0 ? 0 : arr[i] - minus[i];
    tmp.push_back(value);
  }
  return tmp;
}

int main(){
  int N,V;
  memset(visited, 0, sizeof(visited));
  queue<pair<vector<int>, int>> que; 
  vector<int> arr = {0, 0, 0};
  vector<int> hit = {9, 3, 1};
  cin >> N;
  
  for (int i = 0; i < N; i++){
    cin >> V;
    arr[i] = V;
  }

  que.push(make_pair(arr, 0));
  while (que.size() != 0){
    auto value = que.front();
    vector<int> vec = value.first;
    int depth = value.second;
    que.pop();
    if (visited[vec[0]][vec[1]][vec[2]]== 1)
      continue;
    visited[vec[0]][vec[1]][vec[2]]= 1;
    if (checkAllDie(vec)){
      cout << value.second << endl;
      break;
    }
    
    if (N == 1){
      que.push(make_pair(makeNextVec(vec,{9, 0, 0}), depth + 1));
    }else if(N == 2){
      que.push(make_pair(makeNextVec(vec,{9, 3, 0}), depth + 1));
      que.push(make_pair(makeNextVec(vec,{3, 9, 0}), depth + 1));
    } else if(N == 3){ 
      que.push(make_pair(makeNextVec(vec,{9, 3, 1}), depth + 1));
      que.push(make_pair(makeNextVec(vec,{9, 1, 3}), depth + 1));
      que.push(make_pair(makeNextVec(vec,{3, 1, 9}), depth + 1));
      que.push(make_pair(makeNextVec(vec,{3, 9, 1}), depth + 1));
      que.push(make_pair(makeNextVec(vec,{1, 3, 9}), depth + 1));
      que.push(make_pair(makeNextVec(vec,{1, 9, 3}), depth + 1));
    }
  }
  return 0;
}