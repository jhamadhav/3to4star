#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

void dfs(vector<vector<int>>& arr, int node,vector<int>& visited, vector<int>& disc,vector<int>& low, vector<int>& ap,int timer, int parent){
    
    int children = 0;
    disc[node] = low[node] = ++timer;
    
    visited[node] = 1;
    for(auto i : arr[node]){
        if(visited[i] == 0){
            children++;
            dfs(arr,i,visited,disc,low,ap,timer,node);
            
            low[node] = min(low[node],low[i]);
            
            if (parent != -1 && low[i] >= disc[node]){
                ap[node] = 1;
            }
        }else if(i != parent){
            low[node] = min(low[node],disc[i]);
        }
    }
    
    if (parent == -1 && children > 1){
        ap[node] = 1;
    }
    
}

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    
    vector<vector<int>> arr(n);
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    
    vector<int> visited(n,0),disc(n), low(n),ap(n,0);
    dfs(arr,0,visited,disc,low,ap,0,-1);
    
    ll cost = 0;
    for(int i=0;i<n;++i){
        if(ap[i] == 1){
            // cout<<i<<" ";
            cost += k;
        }
    }
    cout<<cost<<endl;
}

int main(){
    
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}