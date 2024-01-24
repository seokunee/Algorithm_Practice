#include<iostream>
#include<cmath>

#define mod 1000000007

using namespace std;
long long K, P, N;

long long calc(long long count){
    if (count == 1)
        return P;
    long long result = calc(count / 2);
    result = (result * result) % mod;
    if (count % 2 == 1)
        result = (result * P) % mod;
    return result;
}

int main(int argc, char** argv)
{
    cin >> K >> P >> N;
    cout << (calc(N * 10) * K) % mod;
    return 0;
}
