#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

vector<pair<int,int>> cord = {{-1,0},{1,0},{0,1},{0,-1}};
bool isValid(int x, int y, int n, int m){
    return (x >= 0 && y >= 0 && x < n && y < m);
}

bool dfs(vector<vector<int>>& arr, vector<vector<bool>>& visited, int x, int y, int val){
    
    bool flag = true;
    int n = arr.size(), m = arr[0].size();
    visited[x][y] = true;
    
    for(int i=0;i<cord.size();++i){
        int cx = x + cord[i].first;
        int cy = y + cord[i].second;
        
        if(isValid(cx,cy,n,m) == false) continue;
        
        if(arr[cx][cy] > val){
            flag = false;
        }
        
        
        if(arr[cx][cy] == val && visited[cx][cy] == false){
            if(dfs(arr,visited,cx,cy,val) == false){
                flag = false;
            }
        }
    }
    
    return flag;
}

void solve(){
    int n,m;
    cin>>n>>m;
    
    // grid input
    vector<vector<int>> arr(n,vector<int>(m,0));
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>arr[i][j];
        }
    }
    
    int res = 0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(visited[i][j]) continue;
            
            // if all are reachable then add to solution
            if(dfs(arr,visited,i,j,arr[i][j]) == true){
                // cout<<"("<<i<<","<<j<<") "; // valid coordinates
                res++;
            }
        }
    }
    // cout<<endl;
    cout<<res<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}