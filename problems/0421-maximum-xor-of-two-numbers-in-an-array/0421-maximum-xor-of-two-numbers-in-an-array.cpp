class Solution {
public:

    struct Node{
        Node* Links[2] = {NULL};
        int endWith=0;
        int pfWith=0;

        void addNode(char ch,Node* node){
            Links[ch-'0'] = node;
        }
        bool contains(char ch){
            return Links[ch-'0'] != NULL;
        }

        Node* getNode(char ch){
            return Links[ch-'0'];
        }

        void increaseEndWith(){
            endWith++;
        }
        void decreaseEndWith(){
            endWith--;
        }
        void increasepfWith(){
            pfWith++;
        }
        void decreasepfWith(){
            pfWith--;
        }

    };



    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int ls = 0;
        for(int i =0; i<n; i++){
            for(int j =31; j>=0 ; j--){
                if(nums[i]&(1<<j)){
                    ls = max(ls,j);
                    break;
                }
            }
        }

        Node* root = new Node();
        Node* node = root;
        for(int i = 0; i<n; i++){
            node = root;
            for(int j =31; j>=0; j--){
                char ch = '0' + ((nums[i]>>j)&1);
                if(!node->contains(ch)){
                    node->addNode(ch,new Node());
                }
                node = node->Links[((nums[i]>>j)&1)];
            }
        }
        int ans = 0;
        
        for(int i = 0; i<n; i++){
            node = root;
            int cur = 0;
            for(int j =31; j>=0; j--){
                char ch = '0' + (!((nums[i]>>j)&1));
                //char ch2 = '0' + ((nums[i]>>j)&1);
                if(node->contains(ch)){
                    cur = (cur|(1<<j));
                    node = node->Links[!((nums[i]>>j)&1)];
                }
                else {   
                    node = node->Links[((nums[i]>>j)&1)];
                }
                
            }
            ans = max(ans,cur);
        }
        return ans;

    }
};