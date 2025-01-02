void buildtree(int ind ,int low ,int high ,vector<int>&segment,vector<int>&nums){
    if(low==high) {
        segment[ind] = nums[low];
        return; 
    }
    int mid  = (low +high)/2;
    buildtree(2*ind+1,low,mid,segment,nums);
    buildtree(2*ind+2,mid+1,high,segment,nums);
    segment[i]=segment[2*ind+1]+segment[2*n+2];
}