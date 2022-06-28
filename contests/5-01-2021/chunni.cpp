#include<iostream>
#include<bits/stdc++.h>
using namespace std;
  
void bad(int idx,int &cnt,int arr[],int mini){
   if(idx<0)
   {
       return ;
   }
   else
   {
     mini=min(arr[idx],mini);
       bad(idx-1,cnt,arr,mini);
       if(arr[idx]>mini)
       {
           cnt++;
       }
   }
   
}
int main()
{
    #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output1.txt","w",stdout);
       #endif
int t;
cin>>t;
while(t--)
{
    int n;cin>>n;int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
   int cnt=0; 
    int mini=arr[n-1]; 
    bad(n-2,cnt,arr,mini);
    cout<<cnt<<endl;
}
return 0;
}