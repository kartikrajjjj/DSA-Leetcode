class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int left=0;
        int right=1;

        while(right<prices.size()){
            int profit=prices[right]-prices[left];
            maxProfit=max(profit,maxProfit);
            if(profit<0){
                left+=1;
                right=left+1;
            }
            else{
                right+=1;
            }
        }
        return maxProfit;
    }
};