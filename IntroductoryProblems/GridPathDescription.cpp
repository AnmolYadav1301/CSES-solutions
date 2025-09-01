#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool isDiagonalBlockage(int r,int c,vector<vector<bool>>& visited){

    if((r-1>=0 && c+1<7 && visited[r-1][c+1] && !visited[r][c+1] && !visited[r-1][c])||//upper right diagonal
      (r+1<7 && c-1>=0 && visited[r+1][c-1] && !visited[r][c-1] && !visited[r+1][c])|| //lower left diagonal
      (r-1>=0 && c-1>=0 && visited[r-1][c-1] && !visited[r][c-1] && !visited[r-1][c])||//upper left diagonal
      (r+1<7 && c+1<7 && visited[r+1][c+1] && !visited[r][c+1] && !visited[r+1][c])//lower right diagonal
      )return true;

      return false;
}

//backtracking and early path prunning 

int f(string& s, int steps,int r,int c, vector<vector<bool>>&visited){
   
    if(r==6 && c==0 ){
        return steps==48 ? 1 : 0;
    }
    if(r>6 || r<0 || c>6 || c<0 || visited[r][c])return 0;
    if((r==0 && c>0 && !visited[r][c-1]) || //top wall
        (c==0 && r>0 && !visited[r-1][c])|| //left wall
        (r==6 && c<6 && !visited[r][c+1])|| // bottom wall
        (r>0 && c==6 && !visited[r-1][c])|| //right wall
        (r-1>=0 && r+1<7 && c-1>=0 && c+1<7 && visited[r-1][c] && visited[r+1][c] && !visited[r][c-1] && !visited[r][c+1])||//up down blockage
        (r-1>=0 && r+1<7 && c-1>=0 && c+1<7 && visited[r][c-1] && visited[r][c+1] && !visited[r-1][c] && !visited[r+1][c]) ||//right left blockage
        isDiagonalBlockage(r,c,visited))return 0;

    if(steps>=48)return 0;

    visited[r][c]=true;

    int total=0;

    if(s[steps]=='?'){
        total+=f(s,steps+1,r+1,c,visited)+f(s,steps+1,r-1,c,visited)+f(s,steps+1,r,c+1,visited)+f(s,steps+1,r,c-1,visited);
    }
    else if(s[steps]=='D')total+=f(s,steps+1,r+1,c, visited);//bottom
    else if(s[steps]=='U')total+=f(s,steps+1,r-1,c, visited);//top
    else if(s[steps]=='L')total+=f(s,steps+1,r,c-1, visited);//left
    else total+=f(s,steps+1,r,c+1, visited);//right

    visited[r][c]=false;

    return total;

}

int main(){

    string s;cin>>s;
    
    vector<vector<bool>>visited(7,vector<bool>(7,false));
    cout<<f(s,0,0,0,visited)<<'\n';

}