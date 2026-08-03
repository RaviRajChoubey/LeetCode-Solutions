class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int left=0;
        vector<int> freq(26,0);
        int maxfreq=0;
        int ans=0;
        for(int i=0;i<n;i++) {
            freq[s[i]-'A']++;
            maxfreq=max(maxfreq,freq[s[i]-'A']);
            while((i-left+1)-maxfreq > k) {
                freq[s[left]-'A']--;
                left++;
            }

            ans=max(ans,i-left+1);
        }

        return ans;
    }
};