#include<iostream>
#include <vector>
#include<queue>

using namespace std;

inline bool isValid(int x,int y,int n,int m){
    return x>=0 && y>=0 && x<n && y<m;
}

void find_path(string & path,vector<vector<char>>&shape,int x,int y){
    if(shape[x][y]=='E')return;

    if(shape[x][y]=='U'){
        find_path(path,shape,x+1,y);
    }
    else if(shape[x][y]=='D'){
        find_path(path,shape,x-1,y);
    }
    else if(shape[x][y]=='L'){
        find_path(path,shape,x,y+1);
    }
    else if(shape[x][y]=='R'){
        find_path(path,shape,x,y-1);
    }

    path+=shape[x][y];
}

int main(){
    
    int n,m;cin>>n>>m;
    vector<vector<char>>build(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char wof;cin>>wof;
            build[i].push_back(wof);
        }
    }
    
    // U,L,D,R
    vector<int>delr={-1,0,1,0};
    vector<int>delc={0,-1,0,1};
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    queue<pair<int,int>>q;
    vector<vector<char>>shape(n,vector<char>(m));
    bool flag=false;
    int ex=-1,ey=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(build[i][j]=='A'){
                q.push({i,j});
                shape[i][j]='E';
                visited[i][j]=true;

                while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;
                    if(build[x][y]=='B'){
                        flag=true;
                        ex=x,ey=y;
                        break;
                    }
                    q.pop();
                    for(int k=0;k<4;k++){
                        int dx=x+delr[k];
                        int dy=y+delc[k];
                        if(isValid(dx,dy,n,m) && !visited[dx][dy] && build[dx][dy]!='#'){
                            visited[dx][dy]=true;
                            q.push({dx,dy});
                            if(k==0)shape[dx][dy]='U';
                            else if(k==1)shape[dx][dy]='L';
                            else if(k==2)shape[dx][dy]='D';
                            else shape[dx][dy]='R';
                        }
                    }
                }
            }
        }
    }
    if(!flag)cout<<"NO";
    else{
        string path="";
        find_path(path,shape,ex,ey);
        cout<<"YES"<<endl;
        cout<<path.length()<<endl;
        cout<<path;
    }
    
    
    return 0;

}