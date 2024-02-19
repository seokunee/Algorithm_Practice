#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
  int F,S,G,U,D;
  cin >> F >> S >> G >> U >> D;
  int answer = -1;
  queue<pair<int, int>> que;
  vector<int> visited(1000001, 0);
  que.push({S, 0});
  visited[S] = 1;

  if (S == G){
    cout << 0 << endl;
    return 0;
  }
  while (que.size() != 0){
    pair<int, int> num = que.front();
    int idx = num.first;
    int depth = num.second;
    que.pop();

    int up = idx + U;
    int down = idx - D;
    if (up == G || down == G) {
      answer = depth + 1;
      break;
    }
    if (up <= F){
      if (visited[up] == 0){
        visited[up] = 1;
        que.push({up, depth + 1});
      }
    }
    if (down >= 1) {
      if (visited[down] == 0){
        visited[down] = 1;
        que.push({down, depth + 1});
      }
    }
  }
  if (answer == -1)
    cout << "use the stairs" << endl;
  else
    cout << answer << endl;
  return 0;
}