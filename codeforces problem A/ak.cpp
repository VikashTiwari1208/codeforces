#include <bits/stdc++.h>
using namespace std;
 

void pas(vector<vector<int>> &v ,int n,int m)
{ if(v[n][m]!=3||n<0||m<0||m>=4||n>=3)
        return;
        
    v[n][m]=3;
    pas(v,n-1,m);
    pas(v,n+1,m);
    pas(v,n,m-1);
   pas(v,n,m+1);
	
}
int main() { 
                vector<vector<int>> v{{1,2,1,1} ,{2,1,1,2} ,{1,0,1,0}};
                int sum=0;
                int m,n;
                cin>>n>>m;
                pas(v,n,m);
                for(int i=0;i<3;i++)
                {
                	for(int j=0;j<4;j++)
                  {
                  	cout<<v[i][j]<<" ";
                  }
                	cout<<endl;
                }
               

	// your code goes here
	return 0;
}