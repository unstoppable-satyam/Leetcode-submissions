class Solution {
public:
    string interpret(string command) {
        string s;
        for (int i = 0; i < command.size(); i++)
        {   
            if(command[i] == 'G'){
                s.push_back('G');     
            }
            if(command[i] == '('){
                if(command[i+1] == ')'){
                    s.push_back('o');
                }
                if(command[i+1] == 'a'){
                    s.push_back('a');
                    s.push_back('l');
                }
            }
        }
        return s;
    }
};