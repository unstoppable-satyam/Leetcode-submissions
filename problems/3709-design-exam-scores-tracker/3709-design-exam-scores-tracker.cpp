class ExamTracker {
public:
    map<long long ,long long> mp;
    map<long long ,long long> hs;
    ExamTracker() {
        mp.clear();
        hs.clear();
        mp[0] = 0;
        hs[0] = 0;
    }
    
    void record(int time, int score) {
        mp[time] = score;
        if( hs.empty() ) hs[time] = score;
        else{
            auto it = hs.rbegin();
            long long lastscoresum = it->second;
            hs[time] = score;
            hs[time] += lastscoresum;
        }
    }
    
    long long totalScore(int startTime, int endTime) {
        auto it1 = hs.upper_bound(endTime);
        it1--;
        long long rt = it1->second;
        auto it2 = hs.lower_bound(startTime);
        long long lf = 0;
        if( it2 != hs.begin() ) {
            it2--; 
            lf = it2->second;
        }
        return rt-lf;
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */