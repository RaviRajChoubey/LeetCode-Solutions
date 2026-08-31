class Solution {
public:
    void findsum(int index,set<vector<int>>& ds,vector<int>& a,int k,int n) {
        if(k==0 && n==0) {
            ds.insert(a);
            return;
        }
        if(k<0 || n<0 || index>9) {
            return;
        }
        a.push_back(index);
        findsum(index+1,ds,a,k-1,n-index);
        a.pop_back();

        findsum(index+1,ds,a,k,n);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        set<vector<int>> ds;
        vector<int> a;
        findsum(1,ds,a,k,n);
        vector<vector<int>> ans(ds.begin(),ds.end());
        return ans;
    }
};