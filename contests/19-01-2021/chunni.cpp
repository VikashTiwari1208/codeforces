#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N=1e5+1;
vector<bool> prime(N,true);
vector<int>pr;
void SieveOfEratosthenes() 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
  
    for (ll p=2; p*p<=N; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (ll i=p*p; i<=N; i += p) 
                prime[i] = false; 
        } 
    }
    for (int p=2; p<=N; p++) 
       if (prime[p]) 
           pr.push_back(p);
}
int main()
{
    ll t;cin>>t;
    SieveOfEratosthenes();
    while(t--)
    {    
        unordered_map<ll,ll>mp;
        ll n;
        ll a=INT64_MIN;
        ll m;
        cin>>n;
        ll z=n;
        for(auto x:pr)
        {
            int count=0;
            while(n%x==0&&n>1)
            {
                n=n/x;
                count++;
            }
            if(count>0)
            {
                mp[x]=count;
            }
        }
        if(n>1)
        {
            mp[n]=1;
        }
        for(auto y:mp){
        	if(a<y.second)
            {
             m=y.first;
            }
         a=max(a,y.second);
        }
        cout<<a<<endl;
        for(ll i=0;i<a-1;i++)
        {
            cout<<m<<" ";
        }
        cout<<(z/(ll)pow(m,a-1))<<endl;
    }
    return 0;
}