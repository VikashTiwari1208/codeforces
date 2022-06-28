#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
   
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    vector<int>v;
    int sum=0;
    for(int i=0;i<4;i++)
    {
        int x;
        cin>>x;
        sum+=x;
        v.push_back(x);
    }
    if(sum%2)
    {
        cout<<"NO";
    }
    else{
        sum=sum/2;
        sort(v.begin(),v.end());
        int i=0,j=3;
        int flag=1;
        while(i<j)
        {
          if((v[i]+v[j])==sum)
          {
              flag=0;
              cout<<"YES";
              break;
          }
          else if(v[i]+v[j]<sum)
          {
              i++;
          }
          else
          {
              j--;
          }
        }
        if(flag)
        {
            cout<<"NO";
        }
    }
    return 0;
}