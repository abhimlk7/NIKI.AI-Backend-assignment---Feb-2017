#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
void pow(long long int Fib[2][2], long long int num);

void mult(long long int Fib[2][2], long long int M[2][2]);
long long int mfibonacci(long long int num)

{
  long long int Fib[2][2] = {{1,1},{1,0}};
  switch(num)
  {
    case 0 : return 0;
    case 1 : return 2;
    case 2 : return 3;
    default: pow(Fib, num-2);
             return (Fib[0][0]*3+Fib[0][1]*2)%MOD;
  
  }

}
void mult(long long int Fib[2][2], long long int M[2][2])
{
    long long int p =  ((Fib[0][0]*M[0][0])%MOD + (Fib[0][1]*M[1][0])%MOD)%MOD;
    long long int q =  ((Fib[0][0]*M[0][1])%MOD + (Fib[0][1]*M[1][1])%MOD)%MOD;
    long long int r =  ((Fib[1][0]*M[0][0])%MOD + (Fib[1][1]*M[1][0])%MOD)%MOD;
    long long int s =  ((Fib[1][0]*M[0][1])%MOD + (Fib[1][1]*M[1][1])%MOD)%MOD;
 
    Fib[0][0] = p;
    Fib[0][1] = q;
    Fib[1][0] = r;
    Fib[1][1] = s;
}


void pow(long long int Fib[2][2], long long int num)
{
  if( num == 0 || num == 1)
      return;
  long long int M[2][2] = {{1,1},{1,0}};
 
  pow(Fib, num/2);
  mult(Fib, Fib);
 
  if (num%2 != 0)
     mult(Fib, M);
}


int main()
{
//	freopen("input.txt","r",stdin);
	long long int Test;
	cin >> Test;
	while(Test--)
	{
		long long int number;
		cin >> number;
		cout << mfibonacci(number) << endl;
	}
	return 0;
}
