#pragma GCC optimize("Ofast")
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define M 1000000007LL
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

long long binpow(long long base, long long exp, int mod)
{
   long long res = 1;
   while (exp > 0)
   {
      if (exp % 2 == 1)
         res = (res * base) % mod;
      exp = exp >> 1;
      base = (base * base) % mod;
   }
   return res;
}

long long mod(long long x)
{
   return ((x % M + M) % M);
}

long long add(long long a, long long b)
{
   return mod(mod(a) + mod(b));
}

long long mul(long long a, long long b)
{
   return mod(mod(a) * mod(b));
}
bool isPrime(int n) 
{ 
    // Corner case 
    if (n <= 1) 
        return false; 
  
    // Check from 2 to n-1 
    for (int i = 2; i*i<= n; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
} 
int main()
{
    fast;
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output1.txt","w",stdout);
       #endif
    string p;
	int n;
	cin>>p>>n;
	int len=p.length();
	int a=0,b=0,c=0;
	for(int i=0;i<len;i++)
	{
		if(p[i]=='*')   a++;
		else if(p[i]=='?')   b++;
		else   c++;
	}
	if(c-a-b>n||(n>c&&a==0))
	{
		cout<<"Impossible";
		return 0;
	}
	if(n>c)
	{
		int cnt=n-c;
		for(int i=0;i<len;i++)
		{
			if(p[i]=='*')
			{
				if(cnt>0){
					for(int j=1;j<=cnt;j++) cout<<p[i-1];
					cnt=0;
				}
				else continue;
			}
			else if(p[i]=='?')  continue;
			else cout<<p[i];
		}
	}
	else
	{
		int cnt=c-n;
		for(int i=0;i<len;i++)
		{	
			if(p[i]=='*'||p[i]=='?')      continue;
			if(p[i+1]=='*'||p[i+1]=='?')
			{
				if(cnt>0)
				{
					cnt--;
					continue;
				}	
			}
				cout<<p[i];
		}
	} 
    return 0;
    } 
	  