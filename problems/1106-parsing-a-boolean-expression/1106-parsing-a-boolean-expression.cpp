class Solution {
private:
bool solve(char oper, vector<int> &temp){
    if( oper == '!' ){
        return temp[0] != 1;
    }
    else if( oper == '&'){
        int ret = temp[0];
        for(int i = 1; i< temp.size(); i++){
            ret = ret&temp[i];
        }
        return (ret==1);
    }
    else if( oper == '|'){
        int ret = temp[0];
        for(int i = 1; i< temp.size(); i++){
            ret = ret|temp[i];
        }
        return (ret==1);
    }
    else{
        cout<<" error h khi ";
        return false;
    }
}


public:
    bool parseBoolExpr(string s) {
        stack<char> st;
        st.push(s[0]);
        if(s.size() == 1) return s[0]=='t';

        // bool ans;
        int n = s.size();
        for(int i= 0; i< n; i++){
            if(s[i] == ')'){
                vector<int> temp;
                while(st.top() != '('){
                    char tp = st.top();
                    st.pop();
                    if(tp == 'f' ) temp.push_back(0);
                    else if(tp == 't') temp.push_back(1);
                }
                st.pop();
                if( st.empty() ) continue;
                char oper = st.top();
                st.pop();
                bool to_push=  solve(oper,temp);
                if( to_push ) st.push('t');
                else st.push('f');
            }
            else{
                st.push(s[i]);
            }
        }
        if(st.top() == 't' ) return true;
        else if(st.top() == 'f')  return false;
        else{
            cout<<" st.top() me problem ";
            return false;
        }
    }
};