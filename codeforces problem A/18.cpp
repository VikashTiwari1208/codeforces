#include <iostream>
#include <bits/stdc++.h>

using namespace std;

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
void check(char c, char d)
{
    if(c==d)
    {
        cout<<"TIE";
    }
    else if(c=='S')
    {
       if(d=='P')
       {
           cout<<"JAMES";
       }
       else if(d=='R')
       {
           cout<<"ALYSSA";
       }
       
    }
    else if(c=='P')
    {
        if(d=='R')
       {
           cout<<"JAMES";
       }
       else if(d=='S')
       {
           cout<<"ALYSSA";
       }
    }
    else if(c=='R')
    {
        if(d=='S')
       {
           cout<<"JAMES";
       }
       else if(d=='P')
       {
           cout<<"ALYSSA";
       }
    }
    
}
int main()
{
    fast;
    string s1,s2;
    cin>>s1>>s2;
      map<char,int>mp1;
    map<char,int>mp2;
  for(auto x:s1)
  {
      mp1[x]++;
  }
  for(auto x:s2)
  {
      mp2[x]++;
  }
   vector<int>v1;
   vector<int>v2;
   int maxi1=INT_MIN;
    int maxi2=INT_MIN;
   for(auto x:mp1)
   {
       maxi1=max(x.second,maxi1);
       v1.push_back(x.second);
   }
   for(auto x:mp2)
   {
       maxi2=max(x.second,maxi2);
        v2.push_back(x.second);
   }
   int frqmaxi1=0;
   int frqmaxi2=0;
   for(auto x:v1)
   {
      if(x==maxi1)
      {
         frqmaxi1++;
      }
   }
   for(auto x:v2)
   {
      if(x==maxi2)
      {
         frqmaxi2++;
      }
   }
  
   if(frqmaxi1>1&&frqmaxi2>1)
   {
      char c=s1[s1.size()-1];
      char d=s2[s2.size()-1];
      check(c,d);
   }
   else if(frqmaxi1>1&&frqmaxi2<=1)
   {
    char c=s1[s1.size()-1];
    char d;
    for(auto x:mp2)
    {
       if(x.second==maxi2)
       {
          d=x.first;
          break;
       }
    }
    check(c,d);
   }
   else if(frqmaxi1<=1&&frqmaxi2>1)
   {
    char c;
    char d=s2[s2.size()-1];
    for(auto x:mp1)
    {
       if(x.second==maxi1)
       {
          c=x.first;
          break;
       }
    }
    check(c,d);
   }
   else
   {
     char c;
    char d;
    for(auto x:mp1)
    {
       if(x.second==maxi1)
       {
          c=x.first;
          break;
       }
    } 
    for(auto x:mp2)
    {
       if(x.second==maxi2)
       {
          d=x.first;
          break;
       }
    }
    check(c,d);
   }
   
    return 0;
}