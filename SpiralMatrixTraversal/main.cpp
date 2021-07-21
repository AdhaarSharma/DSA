// C++ Program to print a matrix spirally
 
#include <bits/stdc++.h>
using namespace std;
#define r 3
#define c 6
 
void spiralPrint(int m, int n, int (*a)[c])
{
    int T,B,R,L,dir;
    T=0;
    B=r-1;
    L=0;
    R=c-1;
    dir=0;
    int i=0;
    while(T<=B&&L<=R){
        if(dir==0){
            for(i=L; i<=R; i++)
                cout<<a[T][i]<<" ";
            T++;
        }
        else if(dir==1){
            for(i=T; i<=B; i++)
                cout<<a[i][R]<<" ";
            R--;
        }
        else if(dir==2){
            for(i=R; i>=L; i--)
                cout<<a[B][i]<<" ";
            B--;
        }
        else if(dir==3){
            for(i=B; i>=T; i--)
                cout<<a[i][L]<<" ";
            L++;
        }
        dir=(dir+1)%4;
    }
}
 
/* Driver Code */
int main()
{
    int a[r][c] = { { 1, 2, 3, 4, 5, 6 },
                    { 7, 8, 9, 10, 11, 12 },
                    { 13, 14, 15, 16, 17, 18 } };
     
      // Function Call
    spiralPrint(r, c, a);
    return 0;
}
 