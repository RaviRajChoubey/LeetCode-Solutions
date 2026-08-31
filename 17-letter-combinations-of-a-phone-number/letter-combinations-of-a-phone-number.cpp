class Solution {
public:
    void combination(int ind,vector<string> &ans,string s,string combs[],string digits) {
        if(ind==digits.size()) {
            ans.push_back(s);
            return;
        }

        int n=digits[ind]-'0';
        for(int i=0;i<combs[n].size();i++) {
            combination(ind+1,ans,s+combs[n][i],combs,digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        string combs[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string s="";
        combination(0,ans,s,combs,digits);
        return ans;
    }
};