class StockSpanner {
public:
stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
            int count=1;
            if(st.size()==0){
                st.push({price,count});
                return count;
            } 
            if(st.top().first > price){
                st.push({price,count});
                return count;
            }
            else{
                while(st.empty() || st.top().first<=price){
                    if(st.empty()){
                        break;
                    }
                count+=st.top().second;
                st.pop();
            }
                st.push({price,count});
                return count;
            }
            return -1;
            
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */