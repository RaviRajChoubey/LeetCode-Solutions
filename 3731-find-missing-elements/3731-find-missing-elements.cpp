class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int a=INT_MAX;
        int b=INT_MIN;
        vector<int> ans;
        for(int i=0;i<n;i++) {
            mp[nums[i]]++;
            a=min(a,nums[i]);
            b=max(b,nums[i]);
        }

        for(int it=a;it<b;it++) {
            if(mp.find(it)==mp.end()) {
                ans.push_back(it);
            }
        }

        return ans;
    }
};