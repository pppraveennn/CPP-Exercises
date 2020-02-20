#include <iostream>

using namespace std;

int exponent(int x, int y) {
  int z = x;
  for(int i = 1; i <= y-1; i++) {
    x = x*z;
  }
  return x;
}

int main()
{
    cout << exponent(2,3) << endl;
    return 0;
}
