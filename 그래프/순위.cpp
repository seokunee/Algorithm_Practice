#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int arr[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    memset(arr, -1, sizeof(arr));
    for (auto re : results){
        int win = re[0];
        int lose = re[1];
        arr[win][lose] = 1;
        arr[lose][win] = 0;
    }

    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (arr[i][j] != -1)
                    continue;
                if (arr[i][k] == 1 && arr[k][j] == 1)
                    arr[i][j] = 1;
                if (arr[i][k] == 0 && arr[k][j] == 0)
                    arr[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++){
        int pass = 0;
        for (int k = 1; k <= n; k++){
            if (arr[i][k] == -1){
                pass++;
            }
        }
        if (pass == 1)
            answer++;
    }

    return answer;
}
