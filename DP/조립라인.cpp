#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	int N;
	int workTimeA, workTimeB, moveTimeAtoB, moveTimeBtoA;
	vector<pair<int, int>> work, move;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> workTimeA >> workTimeB >> moveTimeAtoB >> moveTimeBtoA;
		work.push_back(make_pair(workTimeA, workTimeB));
		move.push_back(make_pair(moveTimeAtoB, moveTimeBtoA));
	}

	int A = 0; // A의 최소 시간 기록
	int B = 0; // B의 최소 시간 기록
	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{ // 첫번째는 이동이 없기 떄문에 작업시간 고정
			A = work[i].first;
			B = work[i].second;
		}
		else
		{ // 직선으로 왔을때와 크로스로 왔을 때의 작업시간을 비교해서 최소값 선택
			int direc, cross;
			int tmpA = A;
			int tmpB = B;
			direc = tmpA + work[i].first;
			cross = tmpB + move[i - 1].second + work[i].first;
			A = min(direc, cross);

			direc = tmpB + work[i].second;
			cross = tmpA + move[i - 1].first + work[i].second;
			B = min(direc, cross);
		}
	}
	cout << min(A, B) << endl;
	return 0;
}
