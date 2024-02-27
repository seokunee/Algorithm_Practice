#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long long K[55];

void setK(){
  K[0] = 1;
  long long mul = 1;
  for (long long i = 1; i < 55; i++){
    mul *= 2;
    K[i] = mul + K[i - 1] * 2;
  }
}

long long countAllOne(long long x){
  long long result = x & 1;
  for (int i = 54; i > 0; i--){
    if (x & (1LL << i)) {
      result += K[i - 1] + (x - (1LL << i) + 1);
      x -= 1LL << i;
    }
  }
  return result;
}

int main(){
  long long A, B;
  cin >> A >> B;

  setK();
  cout << countAllOne(B) - countAllOne(A - 1) << endl;
  return 0;
}