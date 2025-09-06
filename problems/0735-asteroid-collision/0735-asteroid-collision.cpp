class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        //vector<int> rem(n,1);
        vector<int> lastGrEqEle(n,-1);
        stack<int> st;
        for(int i =0;i < n; i++){
            if(asteroids[i] >= 0 ){
                st.push(i);
            }
            else{
                while(!st.empty() && abs(asteroids[i]) >= asteroids[st.top()] ){
                    if( abs(asteroids[i]) == asteroids[st.top()] ){
                        lastGrEqEle[i] = st.top();
                        st.pop();
                        break;
                    }
                    st.pop();
                }
                if( !st.empty() &&  lastGrEqEle[i] == -1 ){
                    lastGrEqEle[i] = st.top();
                }
            }
        }
        for(int i = 0; i< n; i++){
            cout<<lastGrEqEle[i]<<" ";
        }
        cout<<endl;
        vector<int> res;
        for(int i = n-1; i>=0 ; i--){
            if(asteroids[i] >= 0){
                res.push_back(asteroids[i]);
            }
            else{
                int j = lastGrEqEle[i];
                if( j >= 0 ){
                    if( asteroids[j] == abs(asteroids[i]) ){
                        i = j ;
                    }
                    else{
                        i = j+1;
                    }
                }
                else{
                    for(int k  = i; k >= 0; k--){
                        if(asteroids[k] < 0 && lastGrEqEle[k] == -1 )
                            res.push_back( asteroids[k]);
                    }
                    break;
                }
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};