class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string a = "";

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                a.push_back(i + 'a');
            }
            freq[i] /= 2;
        }

        string b = "";
        for (int i = 0; i < 26; i++) {
            while (freq[i] != 0) {
                b.push_back(i + 'a');
                freq[i]--;
            }
        }
        string ans = "";
        ans += b;
        if (a != "") {
            ans += a;
        }
        reverse(b.begin(), b.end());
        ans += b;
        return ans;
    }
};