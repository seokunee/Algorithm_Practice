#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
    int N;
    cin >> N;
    int S, F;
    vector<pair<int, int>> arr;
    for (int i = 0; i < N; i++){
        cin >> S >> F;
        arr.push_back(make_pair(F, S));
    }
    sort(arr.begin(), arr.end());
    pair<int, int> cur = arr[0];
    int count = 1;
    for (int i = 1; i < N; i++){
        int curClassEndTime = cur.first;
        int nextClassStartTime = arr[i].second;
        if (curClassEndTime <= nextClassStartTime){
            count++;
            cur = arr[i];
        }
    }
    cout << count << endl;
    return 0;
}
