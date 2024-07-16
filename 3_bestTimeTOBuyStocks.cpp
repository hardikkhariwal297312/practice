class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int i=0,j=1;
        while(j<prices.size()){
            int p=prices[j]-prices[i];
            if(p<=0){i=j;j++;}
            else {profit=max(p,profit);j++;}
        }
        return profit;
    }
};