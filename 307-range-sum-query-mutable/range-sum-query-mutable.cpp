class NumArray {
public:
    int n;
    vector<int>segmentTree;

    void builtTree(int i, int l, int r, vector<int> &nums){
        //base case
        if(l==r){
            segmentTree[i] = nums[l];
            return; 
        }
        int mid = (l+r)/2;
        builtTree(2*i+1, l, mid, nums);
        builtTree(2*i+2, mid+1, r, nums);

        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }

    void updateQuery(int i, int idx, int l, int r,int val){
        if(l==r){
            segmentTree[i] = val;
            return;
        }
        int mid = (l+r)/2;
        if(idx <= mid) updateQuery(2*i+1,idx, l, mid,val);
        else updateQuery(2*i+2,idx, mid+1, r ,val);
        
        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
             
    }

    int rangeSum(int start, int end, int i, int l, int r){
        if(r<start || l>end){
            return 0;
        }
        else if(l>=start && r<=end){
            return segmentTree[i];
        }
        else{
            int mid = (l+r)/2;
            return rangeSum(start, end, 2*i+1, l, mid)+
            rangeSum(start, end, 2*i+2, mid+1, r);
        }
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segmentTree.resize(4*n);
         builtTree(0, 0, n-1, nums);
    }
    
    void update(int index, int val) {
        return updateQuery(0,index,0,n-1,val);
    }
    
    int sumRange(int left, int right) {
        return rangeSum(left, right, 0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */