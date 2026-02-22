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

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int q = queries.size();
        vector<pair<pair<int,int>,int>> que(q);
        for(int i= 0; i<q ; i++){
            // {{ mi,xi} , indi}
            que[i] = {{queries[i][1],queries[i][0]}, i};
        }
        sort(que.begin(),que.end());

        Node* root = new Node();
        Node* node = root;
        vector<int> ret(q);
        int j = 0;
        for(int i = 0; i<q; i++){
            while(j<n && nums[j] <= que[i].first.first){
                node = root;
                for(int k =31; k>=0; k--){
                    char ch = '0' + ((nums[j]>>k)&1);
                    if(!node->contains(ch)){
                        node->addNode(ch,new Node());
                    }
                    node = node->Links[((nums[j]>>k)&1)];
                }
                j++;
            }
            if(j == 0){
                ret[que[i].second] = -1;
                continue;
            }
            int ans = 0;
            node = root;
            int cur = 0;
            int x = que[i].first.second;
            bool fnd = true;
            for(int j =31; j>=0; j--){
                char ch = '0' + (!((x>>j)&1));
                if( node->contains(ch)) {
                    cur = (cur|(1<<j));
                    node = node->Links[!((x>>j)&1)];
                }
                else {   
                    node = node->Links[((x>>j)&1)];
                }
                
            }
            
            ans = max(ans,cur);
            ret[que[i].second] = ans;
        }
        
        return ret;
    }
};