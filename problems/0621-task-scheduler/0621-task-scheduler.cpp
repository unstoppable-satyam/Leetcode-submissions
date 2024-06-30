#include<bits/stdc++.h>
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26];
        for( auto c : tasks){
            freq[c-'A']++;
        }
        sort(freq, freq+26);
        int mx_freq = freq[25];
        int i= 24;
        while(i >= 0 && freq[i]== mx_freq){
            i--;
        }
        int mx_freq_cnt = 25-i;
        int ans = (n+1)*(mx_freq-1)+ mx_freq_cnt;
        ans = max(int(tasks.size()),ans);
        return ans;
    }
};