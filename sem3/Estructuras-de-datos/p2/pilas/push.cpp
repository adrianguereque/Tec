// stack::push/pop
#include <iostream>       // cout
#include <stack>          // stack
using namespace std;
int main ()
{
  stack<int> mystack;

  for (int i=0; i<5; ++i){
    cout<<i<<" ";
    mystack.push(i);
  } 
  cout<<endl<< "Size = "<<mystack.size()<<endl;
  cout << "Popping out elements...";
  while (!mystack.empty())
  {
     cout << ' ' << mystack.top();
     mystack.pop();
  }
  cout << '\n';

  return 0;
}