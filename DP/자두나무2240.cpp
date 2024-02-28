// 2240 자두나무
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int DP[3][31][1001]; // 위치, 걸음수, 시간
vector<int> loc;
int T, W, V;

int solve(){
  DP[1][W][0] = 0;
  for (int i = 0; i < loc.size(); i++){
    for (int w = 0; w <= W; w++){
      for (int l = 1; l < 3; l++){ 
        if (DP[l][w][i] == -1)
          continue;
        
        // 그대로 가는 경우
        if (l == loc[i + 1]) // 다음 스텝에서 내 자리에 자두가 떨어지는 경우
          DP[l][w][i + 1] = max(DP[l][w][i + 1], DP[l][w][i] + 1); // 원래 있던 놈 vs 내가 지금 추가한놈
        else{
          DP[l][w][i + 1] = max(DP[l][w][i + 1], DP[l][w][i]);
        }

        // 옮기는 경우
        if (w - 1 >= 0){
          int opp = l == 1 ? 2 : 1;
          if (opp == loc[i + 1]) // 다음 스텝에서 내 자리에 자두가 떨어지는 경우
            DP[opp][w - 1][i + 1] = max(DP[opp][w - 1][i + 1], DP[l][w][i] + 1); // 원래 있던 놈 vs 내가 지금 추가한놈
          else
            DP[opp][w - 1][i + 1] = max(DP[opp][w - 1][i + 1], DP[l][w][i]);
        }
      }
    }
  }

  int MAX = -1;
  for (int w = 0; w <= W; w++){
    for (int l = 1; l < 3; l++){
      MAX = max(MAX, DP[l][w][T]);
    }
  }
  return MAX;
}

void print(){
  cout << "           ";
  for (int i = 0; i < loc.size(); i++){
    cout << loc[i] << "  ";
  }
  cout << endl; 
  for (int w = 0; w <= W; w++){
    for (int l = 1; l < 3; l++){
      cout << "l:" << l << ", w:" << w << ":";
      for (int i = 0; i < loc.size(); i++){
        cout << DP[l][w][i] << " ";
      }
      cout << endl;
    }
  }
}

int main(){
  cin >> T >> W;
  memset(DP, -1, sizeof(DP));
  loc.push_back(1);
  for(int i = 0; i < T; i++){
    cin >> V;
    loc.push_back(V);
  }

  cout << solve() << endl;
  return 0;
}