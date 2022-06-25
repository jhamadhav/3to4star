#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

// global vals
const ll MAXNUM = 1e5 + 10;
vector<vector<int>> arr(MAXNUM);
vector<ll> vals(MAXNUM), ft(MAXNUM); // fenwick tree
vector<int> discovery(MAXNUM), beginTime(MAXNUM),endTime(MAXNUM), discTime(MAXNUM);

int timer = -1;
void initDFS(vector<bool>& visited,int node = 0){
    timer++;
    
    //add node to discovery
    discovery[timer] = node;
    discTime[node] = timer;
    
    //being time
    beginTime[node] = timer;
    
    visited[node] = 1;
    for(int i: arr[node]){
        if(visited[i])  continue;
        initDFS(visited,i);
    }
    
    //end time
    endTime[node] = timer;
}

void printArray(vector<auto> a, int n, int val = 0){
    cout<<"[ ";
    for(int i=0;i<n;++i){
        cout<<a[i] + val<<" ";
    }cout<<"]"<<endl;
}

void update(int i,int n, int val){ // element at index i is zero; val: 1 zero found, 0 zero removed
    while(i <= n){
        ft[i] += val;
        i += (i & (-i)); // next index is and of i and 2's compliment of i
    }
}

ll sum(int i){
    ll s = 0;
    while( i > 0){
        s += ft[i];
        i = i - (i & (-i));
    }
    return s;
}

void solve(){
    int n,q;
    cin>>n>>q;
    
    //input arr;
    for(int i=0;i<n-1;++i){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    
    // input vals
    for(int i=0;i<n;++i){
        cin>>vals[i];
    }
    
    //step 1: we will convert this Qs to a range question query for sub array 
    //1. calc discovery time for nodes
    //2. begin time and end time
    // than subtree of node x is from begin[x] to end[x] in our discovery array;
    vector<bool> visited(n,0);
    initDFS(visited);
    
    //printArray
    // printArray(discovery,n,1);
    // printArray(beginTime,n,1);
    // printArray(endTime,n,1);
    
    
    //make fenwick tree 
    // we will traverse the array in form of discovery time
    int i = 1;
    for(auto num: discovery){
        if(vals[num] == 0){
            update(i,n,1);
        }
        i++;
    }
    // printArray(ft,n+1);
    
    //queries
    while(q--){
        char ty;
        cin>>ty;
        if(ty == 'U'){
            int u;
            ll v;
            cin>>u>>v;
            u--;
            
            //if we already have 0 at u we will remove count of 1 
            if(vals[u] == 0){
                update(discTime[u],n,-1);
                vals[u] += v;
            }else{
                vals[u] += v;
                if(vals[u] == 0){
                    update(discTime[u],n,1);
                }
            }
        }else{
            int index;
            cin>>index;
            index--;
            
            int ei = endTime[index] + 1;
            int bi = beginTime[index] + 1;
            
            // cout<<ei<<" "<<bi<<endl;

            cout<<1LL*(sum(ei) - sum(bi))<<endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}