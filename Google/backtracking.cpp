#include<iostream>
#include<vector>
#include<set>

using namespace std;

int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};

void print(vector<vector<char>>& grid){

    int n=grid.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j];
        }
        cout<<'\n';
    }
}

bool isValid(int r, int c, int n){
    return (r>=0 && r<n && c>=0 && c<n);
}

bool solve(vector<vector<char>>& grid, vector<bool>& plant_col, int row, vector<set<int>>&plantable_places){

    if(row==grid.size())return true;

    for(auto col:plantable_places[row]){
        plant_col[col]=true;
        grid[row][col]='X';
        if(solve(grid, plant_col, row+1, plantable_places))return true;
        plant_col[col]=false;
        grid[row][col]='0';
    }

    return false;


}

bool plantTree(vector<vector<char>>& grid){

    int n=grid.size();
    vector<bool>plant_col(n,false);
    vector<set<int>>plantable_places(n);

    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(grid[row][col]=='H'){
                for(int i=0;i<4;i++){
                    int nr=row+dr[i],nc=col+dc[i];
                    if(isValid(nr,nc,n) && grid[nr][nc]=='0'){
                        plantable_places[nr].insert(nc);
                    }
                }
            }
        }
    }

    
    if(solve(grid,plant_col,0,plantable_places))print(grid);
    else cout<<"NO SOLUTION\n";

}

int main(){

    int n;cin>>n;
    vector<vector<char>>grid(n,vector<char>(n,'0'));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }

    plantTree(grid);

    return 0;
}
//TC : n!
//SC : O(n)+ recursive stack O(n);

//naive approach if u just don't store the placeable places initially
// for(int col=0;col<grid.size();col++){
//     if(grid[row][col]=='0'){
//         for(int i=0;i<4;i++){
//             int r=row+dr[i],c=col+dc[i];
//             if(isValid(r,c,grid.size()) && grid[r][c]=='H' && !plant_col[col]){
//                 plant_col[col]=true;
//                 grid[row][col]='X';
//                 if(solve(grid, plant_col, row+1, plantable_places))return true;
//                 plant_col[col]=false;
//                 grid[row][col]='0';
//             }
//         }
//     }
// }
