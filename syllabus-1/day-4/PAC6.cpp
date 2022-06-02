#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

void solve(){
    int n,r,x,y;
    ll m;
    cin>>n>>m>>r>>x>>y;
    x--;
    y--;
    
    vector<vector<pair<int,int>>> arr(n);
    for(int i=0;i<r;++i){
        int a,b,c;
        cin>>a>>b>>c;
        a--;    b--;
        
        arr[a].push_back({b,c});
        arr[b].push_back({a,c});
    }
    
    vector<ll> costs(n,-1);
    vector<bool> visited(n,0);
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0,x});
    costs[x] = 0;
    
    while(q.empty() == false){
        pair<int,int> temp = q.top();
        q.pop();
        int node = temp.second;
        int val = temp.first;
        
        if(visited[node] == 1) continue;
        
        // cout<<node + 1<<endl;
        
        visited[node] = 1;
        for(auto i: arr[node]){
            if(visited[i.first] == 0){
                if(costs[i.first] == -1){
                    costs[i.first] = i.second + val;
                }else{
                    costs[i.first] = min(costs[i.first],(ll)i.second + val);
                }
                q.push({costs[i.first],i.first});
            }
        }
        
        // for(ll i: costs){
        //     cout<<i<<" ";
        // }cout<<endl;
    }
    
    if(costs[y] > m){
        cout<<"died"<<endl;
        return;
    }
    cout<<"alive "<<costs[y]<<endl;
}

int main(){
    
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}