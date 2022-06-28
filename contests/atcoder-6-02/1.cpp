#include<bits/stdc++.h>
using namespace std;
int maxfav(string s,int k,char c)
{
 int n=s.length();
 int maxlength=1;
 int l=0;int r=0;
 int cnt=0;
 while(r<n)
 {
     if(s[r]!=c)
     {
         cnt++;
     }
     while(cnt>k)
     {
         if(s[l]!=c)
         {
             cnt--;
         }
         l++;
     }
     cout<<r<<" "<<l<<" "<<cnt<<" ";
     maxlength=max(maxlength,r-l+1);
     cout<<maxlength<<endl;
     r++;
 }
 return maxlength;
}
int main()
{
    int t ;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        string s;
        cin>>s;
    int op1=maxfav(s,m,'c');
    int op2=maxfav(s,m,'e');
    cout<<max(op1,op2)<<endl;
    }
    return 0;
}