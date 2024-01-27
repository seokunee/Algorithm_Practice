#include<iostream>
#include<vector>
#define ALWAYS_WIN 1
#define HAVE_EVER_LOSE -1
#define NO_FRIEND 0

using namespace std;

int main(int argc, char** argv)
{
    int N, M, W;
    cin >> N >> M;
    vector<int> iambest(N, 0);
    vector<int> weight;
    for (int i = 0; i < N; i++){
        cin >> W;
        weight.push_back(W);
    }

    int left, right;
    for (int i = 0; i < M; i++){
        cin >> left >> right;
        int prevLeft = iambest[left - 1];
        int prevRight = iambest[right - 1];
        if (weight[left - 1] > weight[right - 1]){
            iambest[left - 1] = 1;
            iambest[right - 1] = -1;
        }
        else if (weight[left - 1] < weight[right - 1]){
            iambest[right - 1] = 1;
            iambest[left - 1] = -1;
        }
        else {
            iambest[left - 1] = -1;
            iambest[right - 1] = -1;
        }

        if (prevLeft == -1)
            iambest[left - 1] = -1;
        if (prevRight == -1)
            iambest[right - 1] = -1;
    }

    int answer = 0;
    for (int i = 0; i < N; i++){
        if (iambest[i] == 1 || iambest[i] == 0)
            answer++;
    }
    cout << answer << endl;
    return 0;
}
