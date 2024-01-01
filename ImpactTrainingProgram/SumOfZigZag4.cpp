#include<bits/stdc++.h>
using namespace std;  

int main()  

{  

 int r, c, i, j, sum = 0;  

 cin>>r>>c;  

 int mat[r][c];  

 for(i = 0; i < r; i++){  

   for(j = 0; j < c; j++){  

     cin>>mat[i][j];  

   }  

 }  

 for(j = 0; j < c; j++){  

    sum += mat[0][j];  

 }  

 for(i = 1; i <= r-2; i++){  

   for(j = c-2; j > 0; j--){  

     sum += mat[i][j];  

   }  

 }  

 for(j = 0; j < c; j++){  

   sum += mat[r-1][j];  

 }  

 cout<<"Sum of Zig-Zag pattern is "<<sum;  

 return 0;  

}