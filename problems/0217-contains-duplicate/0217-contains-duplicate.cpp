auto init = []()
{ ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 'c';
}();

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        bool exists = false;
        int n= nums.size();
        for(int i = 0 ;i <n-1 ; i++){
            if(nums[i+1] == nums[i]){
                    exists = true;
                    break;
            }    
        }
        return exists;
    }
};