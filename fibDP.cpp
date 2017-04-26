#include <iostream>
#include <vector>
#include <map>

int passos = 0;
int passosn = 0;


using namespace std;

map<int, int> memo;

int fibn(int n)
{
  if(n <= 2)
  {
    passosn++;
    return 1;
  }
  else
  {
    passosn++;
    return fibn(n-1) + fibn(n-2);
  }
}

int fib(int n)
{
  int f;
  auto got = memo.find(n);

  if(got != memo.end())
    f = got->second;
  else if(n <= 2)
    f = 1;
  else
    f = fib(n-1) + fib(n-2);

  passos++;

  memo.insert(make_pair(n, f));

  return f;

}

int main()
{
  int n;

  cin >> n;

  cout << fib(n) << endl;

  for(auto it = memo.begin(); it != memo.end(); ++it)
    cout << it->first << " " << it->second << endl;

  cout << "passos = " << passos << endl << endl;

  cout << fibn(n) << endl;

  cout << "passosn = " << passosn << endl;

  return 0;
}
