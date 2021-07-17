#include <bits/stdc++.h>
using namespace std;
#define ROW 4
#define COL 5

void findUniqueRows(int M[ROW][COL]){
    for(int i=0; i<ROW; i++){
        int flag=0;
        for(int j=0; j<i; j++){
            flag=1;
            for(int k=0; k<COL; k++)
                if(M[i][k]!=M[j][k])
                    flag=0;
                if(flag==1)
                    break;
        }
        if(flag==0){
            for(int k=0; k<COL; k++)
                cout<<M[i][k]<<" ";
            cout<<endl;
        }
    }
}

// Driver Code
int main() 
{ 
    int M[ROW][COL] = {{0, 1, 0, 0, 1}, 
                       {1, 0, 1, 1, 0}, 
                       {0, 1, 0, 0, 1}, 
                       {1, 0, 1, 0, 0}}; 
  
    findUniqueRows(M); 
  
    return 0; 
} 
