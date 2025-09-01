#include<iostream>
#include <vector>
#include<queue>
using namespace std;
inline bool isValid(int x,int y,int n,int m){
    return x>=0 && y>=0 && x<n && y<m;
}
int main(){
    // cout<<"enter the row & col"<<endl;
    int n,m;cin>>n>>m;
    vector<vector<char>>build(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char wof;cin>>wof;
            build[i].push_back(wof);
        }
    }
    // cout<<"value input done"<<endl;
    vector<int>delr={-1,0,1,0};
    vector<int>delc={0,-1,0,1};
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    queue<pair<int,int>>q;
    int rooms=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && build[i][j]=='.'){
                rooms++;
                q.push({i,j});
                visited[i][j]=true;
                while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int dx=x+delr[k];
                        int dy=y+delc[k];
                        if(isValid(dx,dy,n,m) && !visited[dx][dy] && build[dx][dy]=='.'){
                            visited[dx][dy]=true;
                            q.push({dx,dy});
                        }
                    }
                }
            }
        }
    }
    cout<<rooms;
    return 0;

}