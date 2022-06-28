#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// function to count the divisors 
bool countDivisors(int n) 
{ 
    ll cnt = 0; 
    for (ll i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            // If divisors are equal, 
            // count only one 
            if (n / i == i) 
                cnt++; 
  
            else // Otherwise count both 
                cnt = cnt + 2; 
        } 
    } if(cnt==3)
    return true;
    else
    return false;
} 
  
/* Driver program to test above function */
int main() 
{ 
    ll t;cin>>t;
    while(t--)
    {ll n;cin>>n;
           if(countDivisors(n)) 
           cout<<"YES"<<endl;
           else{
               cout<<"NO"<<endl;
               
           }
        
    }
           
    return 0; 
} 