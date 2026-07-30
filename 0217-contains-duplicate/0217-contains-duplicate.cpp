class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        // map<int,int> mp;
        // for(int i=0;i<n;i++) {
        //     mp[nums[i]]++;
        // }
        // for(int i=0;i<n;i++) {
        //     if(mp[i]>1) {
        //         return true;
        //     }
        // }
        // return false;
        // for(int i=0;i<n-1;i++) {
        //     for(int j=i+1;j<=n;j++) {
        //         if(nums[i]==nums[j]) {
        //             return true;
        //             break;
        //         }
        //     }
        // }
        // return false;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++) {
            if(nums[i]==nums[i+1]) {
                return true;
            }
        }
        return false;
    }
};