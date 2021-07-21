#include <iostream>
#define N 5
using namespace std;

int maze[N][N]  =  {
   {1, 0, 0, 0, 0},
   {1, 1, 0, 1, 0},
   {0, 1, 1, 1, 0},
   {0, 0, 0, 1, 0},
   {1, 1, 1, 1, 1}
};

int sol[N][N];
void showpath(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cout<<sol[i][j]<<" ";
        cout<<endl;
    }
}

bool ValidPlace(int x, int y){
    if(x>=0 && x<N && y>=0 && y<N & maze[x][y]==1)
        return true;
    return false;
}

bool solveMaze(int x, int y){
    if(x==N-1 && y==N-1){
        sol[x][y]=1;
        return true;
    }
    if(ValidPlace(x,y)){
        sol[x][y]=1;
        if(solveMaze(x+1,y))
            return true;
        if(solveMaze(x,y+1))
            return true;
        sol[x][y]=0;
        return false;
    }
    return false;
}

bool Solution(){
    if(solveMaze(0,0)==false){
        cout<<"There is no path!"<<endl;
        return false;
    }
    showpath();
    return true;
}


int main() {
   Solution();
}