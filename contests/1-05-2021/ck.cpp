#include<bits/stdc++.h>
using namespace std;
#define int long long;
int32_t main()
{
int t;
cin>>t;
while(t--){
int n,m,k;
          cin>>n>>m>>k;
          priority_queue<pair<long long int,int>, vector<pair<int,int>>, greater<pair<int,int>>pq;
          for(int i=0;i<m;i++)
          {
              pq.push(make_pair(0,i+1));
          }
          vector<pair<int,int>> v(n);
          int i=0;
          for(auto &x:v)
          {
              int a;
              cin>>a;
              x=make_pair(a,i);
              i++;
          }
          vector<int> ans(n);
          sort(v.begin(),v.end());
          for(int i=n-1;i>=0;i--)
          {
             auto p=pq.top();
             pq.pop();
             ans[v[i].second]=p.second;
             p.first+=v[i].first;
             pq.push(p);
          }
         int maxi=INT64_MIN;int mini=INT64_MAX;
         for(int i=0;i<m;i++)
         {
             auto x=pq.top();
             pq.pop();
             maxi=max(maxi,x.first);
             mini=min(mini,x.first);
         }
         //towwer heigth diff <k;
         if(maxi-mini<=k)
         {
            cout<<"YES"<<endl;
            for(auto x:ans)
            {
                cout<<x<<" ";
            }
            cout<<endl;
         }
         else
         {
             cout<<"NO";
             cout<<endl;
         }}
         return 0;}