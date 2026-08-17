#include <vector>
using namespace std;

class Solution {
private:
    void calc(int ind,int target,vector<int>& candidates,vector<vector<int>>& ans,vector<int>& a) {
        if(target==0) {
                // && find(ans.begin(),ans.end(),a)==ans.end()
            ans.push_back(a);
            return;
        }

        for(int i=ind;i<candidates.size();i++) {
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            a.push_back(candidates[i]);
            calc(i+1,target-candidates[i],candidates,ans,a);
            a.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> a;
        calc(0,target,candidates,ans,a);
        // sort(ans.begin(),ans.end());
        return ans;
    }
};