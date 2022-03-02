class NumArray {
public:
    vector<int>A,tree;
    int n;
    void build(int node, int start, int end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node] = A[start];
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node+1, start, mid);
        // Recurse on the right child
        build(2*node+2, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node+2] + tree[2*node+1];
    }
}
    
 void update1(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        // Leaf node
        A[idx] = val;
        tree[node] = val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update1(2*node+1, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update1(2*node+2, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
}
    
 int query1(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query1(2*node+1, start, mid, l, r);
    int p2 = query1(2*node+2, mid+1, end, l, r);
    return (p1 + p2);
}   
    
    
    NumArray(vector<int>& nums) {
        
        //tree.resize(100000,0);
        n=nums.size();
         tree.resize(4*n,0);
        A=nums;
        build(0,0,n-1);
    }
    
    void update(int index, int val) {
        
        return update1(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        
        return query1(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */