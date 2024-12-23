class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int> mp;
        int n = flowers.size();
        for(int i = 0 ; i<n ;i++){
            mp[flowers[i][0]]++;
            mp[flowers[i][1]+1]--;
        }
        int sum = 0;
        for(auto it : mp ){
            //cout<<it.first<<" "<<it.second<<endl;
            sum += it.second;
            mp[it.first] = sum;
            //cout<<it.first<<" "<<it.second<<endl;
        }
        // for(auto it : mp ){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        int q = people.size();
        vector<int> ret(q);
        for(int i = 0; i<q ; i++){
            auto it = mp.upper_bound(people[i]);
            //if(it != mp.end())cout<<it->first<<" "<<it->second<<endl;
            if(it != mp.begin() ){
                it--;
                ret[i] = it->second;
            }
            else{
                ret[i] = 0;
            }
        }

        return ret;
    }
};