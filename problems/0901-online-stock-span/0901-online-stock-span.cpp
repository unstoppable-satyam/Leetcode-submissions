class StockSpanner {
public:
    vector<int> v;
    stack<int> st;
    int day;
    StockSpanner() {
        v.resize(10010,0);
        day = 0;
        // st.push(0);
        // st.pop();
    }
    
    int next(int price) {

        while( (!st.empty()) && ( v[st.top()] <= price)  ){
            st.pop();
        }
        int old_day = -1;
        if(!st.empty() ) old_day = st.top();
        int ans = day - old_day;

        st.push(day);
        v[day++] = price; 
        return ans;  
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */