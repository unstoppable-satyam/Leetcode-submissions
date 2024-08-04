class Solution {
public:
    string reverseWords(string s) {
        //getline(cin, s);
        //stringstream ss(s);
        //string word;
        int n = s.size();
        vector<string> words;
        for(int i = 0 ; i<s.size();){
            string temp;
            while(i < n && s[i] == ' '){
                i++;
            }
            while( i < s.size() && s[i] != ' '){
                temp+=s[i++];
            }
            words.push_back(temp);
            while(i < n && s[i] == ' '){
                i++;
            }
        }
        reverse(words.begin() , words.end());
        string ret;
        for(int i = 0; i < words.size() ; i++){
            ret += words[i];
            if(i != words.size() - 1 ) ret +=" ";
        }
        return ret;
    }
};