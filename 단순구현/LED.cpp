#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> leds;

void printVint(vector<int> &arr){
  cout << "{";
  for (int value : arr)
    cout << value << " ";
  cout << "}" << endl;
}

void printVVint(vector<vector<int>> arr){
  for (auto line : arr)
    printVint(line);
}

int calSwith(string str) {
  vector<vector<int>> records;
  records.push_back(leds[str[0] - '0']);
  for (int i = 0; i < str.size() - 1; i++) { // 다른 부분
    int left = str[i] - '0';
    int right = str[i + 1] - '0';
    vector<int> lled = leds[left];
    vector<int> rled = leds[right];
    vector<int> record(7, 0);
    for (int k = 0; k < 7; k++) {
      if (lled[k] == rled[k])
        record[k] = 0;
      else
        record[k] = 1;
    }
    records.push_back(record);
  }

  int answer = 0;
  while (records.size() != 0) {
    if (find(records[0].begin(), records[0].end(), 1) == records[0].end()){
      records.erase(records.begin());
      continue;
    }
    int len = records.size();
    int x = 0;
    while (x < 7){ // 그 줄에서 1인 거를 하나 찾는다.
      if (records[0][x] == 1)
        break;
      x++;
    }
    
    vector<int> xSeroLine; // led가 포함된 record의 idx가 저장
    for (int y = 0; y < len; y++){ // 그리고 그 1이 records중에서 어디어디에 포함되어있는지 확인
      xSeroLine.push_back(records[y][x]);
    }

    for (int k = x; k < 7; k++){ // record[0]중에서 k와 같은 위치에 1을 가지는 led를 찾는다.
      bool same = true;
      for (int i = 0; i < len; i++){
        if (records[i][k] != xSeroLine[i]){
          same = false;
          break;
        }
      }
      if (same){
        for (int i = 0; i < len; i++){ // 지운다.
          records[i][k] = 0;
        }
      }
    }
    answer++;
  }
  return answer;
}

int main() {
  vector<int> answer;
  vector<string> arr = {"3839", "2", "29471500"};
  leds.push_back({1, 1, 1, 1, 1, 1, 0}); // 0
  leds.push_back({0, 1, 1, 0, 0, 0, 0}); // 1
  leds.push_back({1, 1, 0, 1, 1, 0, 1}); // 2
  leds.push_back({1, 1, 1, 1, 0, 0, 1}); // 3
  leds.push_back({0, 1, 1, 0, 0, 1, 1}); // 4
  leds.push_back({1, 0, 1, 1, 0, 1, 1}); // 5
  leds.push_back({1, 0, 1, 1, 1, 1, 1}); // 6
  leds.push_back({1, 1, 1, 0, 0, 0, 0}); // 7
  leds.push_back({1, 1, 1, 1, 1, 1, 1}); // 8
  leds.push_back({1, 1, 1, 1, 0, 1, 1}); // 9

  for (string str : arr)
    answer.push_back(calSwith(str));
  cout << "answer = ";
  printVint(answer);
  return 0;
}
// // result : [3, 1 , 7]