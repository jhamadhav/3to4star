class NumArray {
private:
vector<int> st, arr;
int n;
public:
    int build(int l, int r, int index){
        
        if(l == r){
            st[index] = arr[l];
            // cout<<l<<"-"<<r<<": "<<arr[l]<<endl;
            return arr[l];
        }
        
        int mid = l + (r-l)/2;
        int res = build(l,mid,2*index+1) + build(mid+1,r,2*index+2);
        
        // cout<<l<<"-"<<r<<": "<<res<<endl;
        st[index] = res;
        return res;
    }
    
    NumArray(vector<int>& nums) {
        arr = nums;
        n = nums.size();
        st = vector<int>(4*n,0);
        build(0,n-1,0);
        
        // for(int i: st){
        //     cout<<i<<" ";
        // }cout<<endl;
    }
    
    void update(int index, int val) {
        int temp = val;
        val -= arr[index];
        arr[index] = temp;
        int l=0, r = n-1;
        
        int i = 0;
        while(l<=r){
            st[i] += val;
            
            if(l == r)  break;
            
            int mid = l + (r-l)/2;
            if(index <= mid){
                r = mid;
                i = 2*i + 1;
            }else{
                l = mid + 1;
                i = 2*i + 2;
            }
        }
        // for(int i: st){
        //     cout<<i<<" ";
        // }cout<<endl;
    }
    int query(int l, int r, int index,int a, int b){
        if(l >= a && r <= b){
            return st[index];
        }
        if(r < a || l > b) return 0;
        int mid = l + (r-l)/2;
        return query(l,mid,2*index+1,a,b) + query(mid+1,r,2*index+2,a,b);
    }
    
    int sumRange(int left, int right) {
        return query(0,n-1,0,left,right);
    }
};
