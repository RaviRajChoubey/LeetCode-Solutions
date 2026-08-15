#include <vector>
using namespace std;

class Solution {
private:
    void calc(int ind,int target,vector<int>& candidates,vector<vector<int>>& ans,vector<int>& a) {
        if(ind==candidates.size()) {
            if(target==0) {
                ans.push_back(a);
            }
            return;
        }

        if(target >= candidates[ind]) {
            a.push_back(candidates[ind]);
            calc(ind,target-candidates[ind],candidates,ans,a);
            a.pop_back();
        }
        calc(ind+1,target,candidates,ans,a);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> a;
        calc(0,target,candidates,ans,a);
        return ans;
    }
};