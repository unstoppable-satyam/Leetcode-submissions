class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if( s.size() != goal.size() ) return false;
        // for(int i= 0 ; i < s.size() ; i++){
        //     string temp = (s.substr(i,n-i)) + (s.substr(0,i)) ;
        //     //cout<<" temp "<<temp<<endl;
        //     if( temp == goal) return true;
        // }
        if( (s+s).contains(goal) ) return true;
        return false;
    }
};