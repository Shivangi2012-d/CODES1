class StockSpanner {
public:
    stack<pair<int,int>>s;
    int i=0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        while(!s.empty()&&price>=s.top().second)
        {
            s.pop();
        }
        int res=s.empty()?i+1:i-s.top().first;
        s.push(make_pair(i,price));
        i++;
        return res;
    }
};