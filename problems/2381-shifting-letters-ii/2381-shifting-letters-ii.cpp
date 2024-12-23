class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        int sz = s.size();
        vector<long long> v(sz); // Changed to long long
        
        for (int i = 0; i < sz; i++) {
            v[i] = s[i] - 'a';
        }
        
        int n = shifts.size();
        vector<long long> pf(sz, 0); // Changed to long long
        
        for (int i = 0; i < n; i++) {
            if (shifts[i][2] == 1) {
                pf[shifts[i][0]]++;
                if (shifts[i][1] != sz - 1) pf[shifts[i][1] + 1]--;
            } else {
                pf[shifts[i][0]]--;
                if (shifts[i][1] != sz - 1) pf[shifts[i][1] + 1]++;
            }
        }
        
        for (int i = 0; i < sz; i++) {
            if (i != 0) pf[i] += pf[i - 1];
            v[i] = (v[i] + pf[i]%26 + 26) % 26; // No % 26 on pf[i]
        }
        
        string ret(sz, '$');
        for (int i = 0; i < sz; i++) {
            ret[i] = char(v[i] + 'a');
        }
        
        return ret;
    }
};