class Solution {
// vector<int> nse(vector<int> &h){
//     int n = h.size();
//     vector<int> ret(n,n);
//     stack<int> st;
//     for(int i =  n-1 ; i>= 0 ; i--){
//         while(!st.empty() && h[st.top()] >= h[i] ){
//             st.pop();
//         }
//         if( !st.empty() ){
//             ret[i] = st.top();
//         }
//         st.push(i);
//     }
//     return ret;
// }

// vector<int> pse(vector<int> &h){
//     int n = h.size();
//     vector<int> ret(n,-1);
//     stack<int> st;
//     for(int i = 0; i < n ; i++){
//         while(!st.empty() && h[st.top()] >= h[i] ){
//             st.pop();
//         }
//         if( !st.empty() ){
//             ret[i] = st.top();
//         }
//         st.push(i);
//     }
//     return ret;
// }
public:
    int largestRectangleArea(vector<int>& heights) {
        int mx = 0;
        int n = heights.size();
        // vector<int> ns = nse(heights);
        // vector<int> ps = pse(heights);
        // for(int i = 0 ; i < n ; i++){
        //     int leftBoundary = ps[i] + 1;
        //     int rightBoundary = ns[i] -1;
        //     mx = max(mx, heights[i]*(rightBoundary-leftBoundary+1));
        // }
        stack<int> st;
        for(int i = 0; i< n; i++){
            while( !st.empty() && heights[st.top()] >= heights[i] ){
                int element = heights[st.top()] ; st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                mx = max( mx, element*(nse-pse-1) );
                //cout<<"element  "<<element<<" "<<element*(nse-pse-1)<<endl;
            }
            st.push(i);
        }
        while( !st.empty() ){
            int element =  heights[st.top()]; st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            mx = max( mx, element*(nse-pse-1) );
            //cout<<"element  "<<element<<" "<<element*(nse-pse-1)<<endl;
        } 
        return mx;
    }
};