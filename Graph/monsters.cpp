#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool isValid(int x,int y,int n,int m){
    return (x>=0 && x<n && y>=0 && y<m);
}
bool isBoundary(int x,int y,int n,int m){
    return (x==0 || x==n-1 || y==0 || y==m-1);
}
int main(){
    int n,m;cin>>n>>m;

    vector<vector<char>>mp(n,vector<char>(m));
    pair<int,int>s,e;
    queue<pair<int,int>>q;
    vector<vector<char>>visited(n,vector<char>(m,'.'));
    vector<vector<char>>path(n,vector<char>(m,'.'));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mp[i][j];
            if(mp[i][j]=='A'){
                s={i,j};
            }
            else if(mp[i][j]=='M'){
                q.push({i,j});
                visited[i][j]='M';
            }
        }
    }
    vector<int>dr={1,-1,0,0};
    vector<int>dc={0,0,-1,1};
    //D, U, L, and R
    q.push(s);
    visited[s.first][s.second]='A';
    bool flag=false;

    while(!q.empty()){
        int x=q.front().first,y=q.front().second;
        q.pop();
        char node=visited[x][y];
        if(node=='A' && isBoundary(x,y,n,m)){
            flag=true;
            e={x,y};
            break;
        }
        for(int i=0;i<4;i++){
            int r=x+dr[i],c=y+dc[i];
            if(isValid(r,c,n,m)  && visited[r][c]=='.' && mp[r][c]=='.'){

                if(node=='A'){
                    if(i==0){
                        path[r][c]='D';
                    }
                    else if(i==1)path[r][c]='U';
                    else if(i==2)path[r][c]='L';
                    else path[r][c]='R';
                }
                visited[r][c]=node;
                q.push({r,c});
            }
        }
    }
    vector<char>ans;
    // cout<<flag<<":"<<e.first<<e.second<<endl;
    if(flag){
        pair<int,int>curr=e;
        while(curr.first!=s.first || curr.second!=s.second){
            int i=curr.first,j=curr.second;
            char direction=path[i][j];
            ans.push_back(direction);
            if(direction=='D')curr={i-1,j};
            else if(direction=='U')curr={i+1,j};
            else if(direction=='L')curr={i,j+1};
            else if(direction=='R')curr={i,j-1};            
        }
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        for(int i=ans.size()-1;i>=0;i--)cout<<ans[i];
        cout<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }


    return 0;
}