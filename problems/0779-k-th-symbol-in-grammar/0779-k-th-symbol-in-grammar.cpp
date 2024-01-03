auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

class Solution {
public:
        int kthGrammar(int n, int k) {
        if(n==1){ return 0;}
        int parent = kthGrammar(n-1,ceil(k/2.0));
        if(parent == 1){
            if(k&1) return 1;
            else return 0;
        }    
        else{
            if(k&1) return 0;
            else return 1;
        }
    }
};