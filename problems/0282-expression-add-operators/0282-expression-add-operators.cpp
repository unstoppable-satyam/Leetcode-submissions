typedef long long ll;

class Solution {
public:
    vector<string> ret;
    // bool evalExp(string &s, int target){
    //     int n = s.size();

    //     vector<long long> v; // Changed to long long
    //     string oper;

    //     int ind = 0;
        
    //     // --- Parse First Operand ---
    //     int start = ind;
    //     long long val = 0;
    //     while( ind < n && isdigit(s[ind]) ){
    //         val = val * 10 + (s[ind] - '0');
    //         ind++;
    //     }
    //     // Leading zero check: if length > 1 and starts with '0'
    //     if (ind - start > 1 && s[start] == '0') return false; 
        
    //     v.push_back(val);

    //     // --- Parse Remaining Operands ---
    //     while(ind < n){
    //         char op = s[ind]; // Operator
    //         ind++;
            
    //         start = ind;
    //         val = 0;
    //         while(ind < n && isdigit(s[ind]) ){
    //             val = val * 10 + (s[ind] - '0');
    //             ind++;
    //         }
    //         // Leading zero check
    //         if (ind - start > 1 && s[start] == '0') return false;

    //         if( op == '*' ){
    //             long long left = v.back();
    //             v.pop_back();
    //             long long mul =left * val ;
    //             if( mul > INT_MAX ) return false;
    //             v.push_back(mul); // Safely multiply using long long
    //         } 
    //         else{
    //             oper += op; 
    //             v.push_back(val);
    //         }
    //     }
        
    //     // --- Evaluate Final Additions and Subtractions ---
    //     int sz = v.size();
    //     long long tot = v[0];
    //     for(int i = 1; i < sz; i++){
    //         if(oper[i-1] == '+'){
    //             tot += v[i];
    //         }
    //         else{
    //             tot -= v[i];
    //         }
    //     }
        
    //     return (tot == target);
    // }

    // void solve(int i, int n, string &number, string &temp, int target){
    //     if(i == n ){
    //         if( evalExp(temp,target)){
    //             ret.push_back(temp);
    //         }
    //         // ret.push_back(temp);
    //         return;
    //     }

    //     temp += '+';
    //     temp += number[i];
    //     solve(i+1,n,number,temp,target);
    //     temp.pop_back();
    //     temp.pop_back();

    //     temp += '-';
    //     temp += number[i];
    //     solve(i+1,n,number,temp,target);
    //     temp.pop_back();
    //     temp.pop_back();

    //     temp += '*';
    //     temp += number[i];
    //     solve(i+1,n,number,temp,target);
    //     temp.pop_back();
    //     temp.pop_back();

    //     // ?????the case of first digit as zero ?????
    //     temp += number[i];
    //     solve(i+1,n,number,temp,target);
    //     temp.pop_back();
    
    // }

    void solve(int ind, const string& num, string& path, ll target, ll cur_val, ll prev_operand) {
        // Base Case: If we have reached the end of the string
        if (ind == num.size()) {
            if (cur_val == target) {
                ret.push_back(path);
            }
            return;
        }

        // We use path_len to easily backtrack the string to its exact state 
        // before we appended the current chunk and operator.
        int path_len = path.size();

        // Loop to extract operands of different lengths starting from 'ind'
        for (int i = ind; i < num.size(); ++i) {
            
            // Leading Zero Check: A multi-digit operand cannot start with '0'
            if (i > ind && num[ind] == '0') {
                break; 
            }

            // Extract the chunk and convert it to a number
            string s = num.substr(ind, i - ind + 1);
            ll val = stoll(s);

            if (ind == 0) {
                // First operand: We don't prepend any operator
                path += s;
                solve(i + 1, num, path, target, val, val);
                path.resize(path_len); // Backtrack
            } 
            else {
                // '+' Operator
                path += "+" + s;
                solve(i + 1, num, path, target, cur_val + val, val);
                path.resize(path_len); // Backtrack

                // '-' Operator
                path += "-" + s;
                // Note: We pass -val as the prev_operand so multiplication respects the sign
                solve(i + 1, num, path, target, cur_val - val, -val);
                path.resize(path_len); // Backtrack

                // '*' Operator
                path += "*" + s;
                // Reverse the previous operation, then add the multiplied value
                solve(i + 1, num, path, target, cur_val - prev_operand + (prev_operand * val), prev_operand * val);
                path.resize(path_len); // Backtrack
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        //num  = "412";
        // int n = num.size();
        string temp;
        solve( 0,num,temp,1LL*target ,0, 0);
        // string test_s = "412";
        // solve()

        return ret;
    }
};