  #include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin>>n;
   map<pair<string,string>,int>experts;
   map<pair<string,string>,int>customers;
   for(int i=0;i<n;i++)
   {
    string q,l;
    cin>>q>>l;
   experts[{q,l}]++;
   }
   int m;
   cin>>m;
   for(int i=0;i<n;i++)
   {
    string q,l;
    cin>>q>>l;
    customers[{q,l}]++;
   }
   int ans=0;
   for(auto x:customers)
   {
    ans+=min(x.second,experts[x.first]);
   }
   cout<<m-ans;
}