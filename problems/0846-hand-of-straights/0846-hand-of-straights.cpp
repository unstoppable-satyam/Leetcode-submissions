class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        int n = hand.size();
        if( (n%k) != 0 ) return false;
        sort(hand.begin(),hand.end());
        map<int,int> mp;
        bool chk=  true;
        for(int i = 0 ; i< n; i++){
            mp[hand[i]]++;
        }
        int cnt = n/k;
        while(cnt){
            int prev = -1;
            int tot = 0;
            // cout<<" Bdb " <<endl; 
            for (auto it = mp.begin(); it != mp.end(); ) {
                int cur = it->first;
                int freq = it->second;
                if( ! (prev == -1 || cur == prev+ 1 )){
                    // cout<<" cur "<<cur<<endl;
                    return false;
                }
                mp[cur]--;
                tot++;
                prev = cur;

                if (mp[cur] == 0) {
                    it = mp.erase(it);  // Erase returns the next iterator
                } 
                else {
                    ++it;
                }

                if (tot == k) {
                    break;
                }
            }
            if(tot != k ) return false;
            cnt--;
        }
        return true;
    }
};