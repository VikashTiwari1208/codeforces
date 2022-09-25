#include <bits/stdc++.h> 
#define ll long long 
using namespace std; 

bool dhoni() 
{ 
               int n; 
               cin >> n; 
               int K; 
               cin >> K; 
               int a[n + 1]; 
               int b[n + 1]; 

               for (int i = 1; i <= n; i++) 
               { 
                              cin >> a[i]; 
               } 

               for (int i = 1; i <= n; i++) 
               { 
                              cin >> b[i]; 
               } 

               int i = 1; 
               int j = 1; 
               int ind = -1; 
               bool flag = true; 

               for (int i = 1; i <= n; i++) 
               { 
                              if (a[i] != b[i]) 
                                          flag=false; 
               } 
               if (flag) 
                              return true; 

               while (i <= n) 
               { 
                              if (b[1] == a[i]) 
                              { 
                                             ind = i; 

                                             i++; 
                                             j++; 
                                             break; 
                              } 
                              i++; 
               } 

               if (ind == -1) 
                              return false; 
               while (i <= n && j <= n) 
               { 
                              if (b[j] == a[i]) 
                              { 
                                             i++; 
                                             j++; 
                              } 
                              else 
                              { 
                                             return false; 
                              } 
               } 

               for (int k = 1; k < ind; k++) 
               { 
                              if (j == n + 1) 
                                             return false; 
                              if (a[k] == b[j]) 
                              { 
                                             j++; 
                              } 
                              else 
                                             return false; 
               } 

               if (K % 2 != 0) 
                              return true; 
               return false; 
} 

int main() 
{ 
     // freopen("input.txt","r",stdin);
     //   freopen("output1.txt","w",stdout);
               int testcases; 
               cin >> testcases; 
               for (int i = 1; i <= testcases;i++) 
               { 
                            bool ans=dhoni();
                              if (ans) 
                              { 

                                             cout << "Case #" <<i<< ":" 
                                                  << " "; 
                                             cout << "YES"; 
                              } 
                              else 
                              { 

                                             cout << "Case #" << i << ":" 
                                                  << " "; 
                                             cout << "NO"; 
                              } 
                              cout << endl; 
               } 
}