class NumArray {
public:
    vector<int> ft,arr;
    int n;
    
    void updateFT(int i, int val){
        while(i < n){
            ft[i] += val;
            i += (i & (-i));
        }
    }
    int sumFT(int i){
        int s = 0;
        while(i > 0){
            s += ft[i];
            i = i - (i & (-i));
        }
        return s;
    }
    
    NumArray(vector<int>& nums) {
        n = nums.size() + 1;
        ft = vector<int>(n,0);
        arr = nums;
        
        int i = 1;
        for(int num: nums){
            updateFT(i,num);
            i++;
        }
        
        // for(int i=1;i<n;++i){
        //     cout<<ft[i]<<" ";
        // }cout<<endl;
    }
    
    void update(int i, int val) {
        
        updateFT(i+1,val - arr[i]);
        arr[i] = val;
    }
    
    int sumRange(int left, int right) {
        return sumFT(right+1) - sumFT(left);
    }
};
