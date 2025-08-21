class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        vector<int > last_occ(n+1,-1);  // store last occurance of any fruit
        int l = 0, r = 1;
        int f1 =fruits[0], f2 = -1;
        last_occ[fruits[0]] = 0;
        
        int gb = 1;
        for(; r<n; r++){
          if(last_occ[fruits[r]] != -1 ){
            gb = max(gb,r-l+1);
            last_occ[fruits[r]] = r;
          }
          else{
            last_occ[fruits[r]] = r;
            if(f2 == -1 ){
              f2 = fruits[r];
            }
            else{
              int mn = min(last_occ[f1] , last_occ[f2]);
              last_occ[fruits[mn]] = -1;
              l = mn+1;
              f1 = fruits[l];
              f2 = fruits[r];
            }
            gb = max(gb,r-l+1);
          }
        }
        return gb;
    }
};