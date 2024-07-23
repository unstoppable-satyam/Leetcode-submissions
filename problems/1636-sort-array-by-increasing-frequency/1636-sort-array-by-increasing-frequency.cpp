bool cmp(pair<int,int> &a, pair<int,int> &b ){
        if(a.second == b.second ){
            return a.first > b.first;
        }
        return a.second < b.second;
    }

class Solution {

public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp; // {freq,num}
        int n = nums.size();
        for(int i = 0; i< n ; i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>> v(mp.begin() , mp.end());
        sort(v.begin() , v.end() , cmp);
        vector<int> ret;
        for(int i = 0 ; i< v.size() ; i++){
            int ele = v[i].first;
            int fr = v[i].second;
            while(fr--){
                ret.push_back(ele);
            }
        }

        return ret;
    }
};