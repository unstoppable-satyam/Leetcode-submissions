class Solution {
public:
    string frequencySort(string s) {
        vector<int> hs(62,0);
        int n = s.size();
        for(int i= 0 ; i< n ; i++){
            if( 'a' <= s[i]  && s[i] <= 'z')
                hs[ (s[i] - 'a')]++;
            else if( 'A' <= s[i] && s[i] <= 'Z' ){
                hs[ s[i] - 'A' + 26]++;
            }
            else
                hs[52 +s[i]-'0']++;
        }
        priority_queue<pair<int,char> > pq;
        for(int i = 0; i< 26 ; i++){
            pq.push({hs[i],char('a'+i)});
        }
        for(int i = 26; i< 52 ; i++){
            pq.push({hs[i],char('A'+i-26)});
        }
        for(int i = 52; i< 62 ; i++){
            pq.push({hs[i],char('0'+i-52)});
        }
        string ret;
        while(!pq.empty() ){
            auto it = pq.top();
            pq.pop();
            char ch = it.second;
            int cnt = it.first;
            for(int i= 0 ; i<cnt; i++){
                ret.push_back(ch);
            }
        }
        return ret;
    }
};