class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        // Extract start and end times for event1
        int s1h = stoi(event1[0].substr(0, 2)); // Extract hours
        int s1m = stoi(event1[0].substr(3, 2)); // Extract minutes
        int e1h = stoi(event1[1].substr(0, 2)); // Extract hours
        int e1m = stoi(event1[1].substr(3, 2)); // Extract minutes

        // Extract start and end times for event2
        int s2h = stoi(event2[0].substr(0, 2)); // Extract hours
        int s2m = stoi(event2[0].substr(3, 2)); // Extract minutes
        int e2h = stoi(event2[1].substr(0, 2)); // Extract hours
        int e2m = stoi(event2[1].substr(3, 2)); // Extract minutes

        // Convert times to total minutes from the start of the day
        int num1 = s1h * 60 + s1m;
        int num2 = e1h * 60 + e1m;
        int num3 = s2h * 60 + s2m;
        int num4 = e2h * 60 + e2m;

        // Use a map to track overlaps
        map<int, int> mp;
        mp[num1]++;
        mp[num2 + 1]--;
        mp[num3]++;
        mp[num4 + 1]--;

        // Check for overlaps
        int sum = 0;
        for (auto it : mp) {
            sum += it.second;
            if (sum > 1) return true;
        }
        return false;
    }
};