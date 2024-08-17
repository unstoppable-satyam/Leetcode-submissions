class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int mx = 0;
        int lastMax = values[0];
        int index = 0;
        for(int i=1; i<n; i++){
            mx = max(mx, values[i] + values[index] - (i - index) );
            if( values[i]  >  lastMax - (i - index) ){
                index = i;
                lastMax = values[i];
                //cout<<" i "<<i<<endl;
            }
        }
        return mx;
    }
};