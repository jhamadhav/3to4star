#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

vector<pair<int,int>> cord = {{-1,0},{1,0},{0,-1},{0,1},{1,1},{-1,-1},{1,-1},{-1,1}};
bool isValid(int x,int y, int n, int m){
    return (x >= 0 && y >= 0 && x < n && y < m);
}

void solve(){
    int r,c,k;
    cin>>r>>c>>k;
    r--;
    c--;
    
    vector<vector<bool>> visited(8,vector<bool>(8,0));
    visited[r][c] = 1;
    
    queue<pair<int,int>> q;
    q.push({r,c});
    
    int count = 1;
    while(q.empty() == false && k--){
        int len = q.size();
        while(len--){
            pair<int,int> node = q.front();
            q.pop();
            
            for(int i=0;i<cord.size();++i){
                int cr = node.first + cord[i].first;
                int cc = node.second + cord[i].second;
                
                if(isValid(cr,cc,8,8) && visited[cr][cc] == 0){
                    q.push({cr,cc});
                    visited[cr][cc] = 1;
                    count++;
                }
            }
        }
    }
    cout<<count<<endl;
}

int main(){
    
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}