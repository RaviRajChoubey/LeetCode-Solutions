class Solution {
public:
    void findsum(int index,vector<int>& nums,vector<int>& ds,set<vector<int>>& result) {
        if(index==nums.size()) {
            result.insert(ds);
            return;
        }
        ds.push_back(nums[index]);
        findsum(index+1,nums,ds,result);
        ds.pop_back();
        findsum(index+1,nums,ds,result);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> result;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        findsum(0,nums,ds,result);
        vector<vector<int>> ans(result.begin(),result.end());
        return ans;
    }
};