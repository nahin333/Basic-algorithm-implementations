#include <iostream>

using namespace std;

class tst{
  static int a;
  public:
      static int disp()
      {
          return a;
      }
};

int  tst::a=1;

int main()
{
    cout<<tst::disp();
}
