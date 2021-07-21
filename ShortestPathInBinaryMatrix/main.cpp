int dir[8][2] = {{0,1},{-1,0},{0,-1},{1,0},{1,1},{-1,1},{1,-1},{-1,-1}};
struct point{
    int x;
    int y;
    int c;
    point(int x, int y, int c){
        this->x = x;
        this->y = y;
        this->c = c;
    }
};

class Solution {
   public:
   int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       queue<point> q;
       int n = grid.size();
       if(!grid[0][0]){
           q.push(point(0,0,1));
           grid[0][0] = 1;
       }
       while(!q.empty()){
           point curr = q.front();
           q.pop();
           int x = curr.x;
           int y = curr.y;
           int c = curr.c;
           if(x==n-1 && y==n-1)
               return c;
           c++;
           for(int i = 0; i<8; i++){
               int X = x + dir[i][0];
               int Y = y + dir[i][1];
               if(X>=0 && X<n && Y>=0 && Y<n && !grid[X][Y]){
                       grid[X][Y] = 1;
                       q.push(point(X,Y,c));
                }
           }
       }
       return -1;
   }
};