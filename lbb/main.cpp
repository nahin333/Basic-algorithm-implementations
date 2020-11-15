#include <iostream>

using namespace std;



float limitedSquare(float x)
   {
      return (x <= -10.0 || x >= 10.0) ? 100 : x*x;
   }


int main()
{

    float a,b;
    cin >> a;
    b = limitedSquare(a);
    cout << b << endl;
    return 0;
}

