#include<iostream>
#include<bits/stdc++.h>
#include<string>
unordered_map<int,int>mp;
using namespace std;
int ans(vector<int>v,int n)
{for (int i=0;i<v.size();i++) {
string str=bitset<32>(v[i]).to_string();

for(int j=0;j<str.size();j++){
    if(str[j]==1)
    mp[i]++;
}
}
int sum=0;
for(auto x:mp)
{
    if(x.second%2==0)
    sum =sum+(x*(x-1))/2;
}
cout<<sum<<endl;
}
int main()
{
int t;cin>>t;
while(t--)
{
    int n;cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
       int a; cin>>a;v.push_back(a);
    }
     return ans(v,n);
}
return 0;
}