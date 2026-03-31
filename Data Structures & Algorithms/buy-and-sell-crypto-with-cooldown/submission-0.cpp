class Solution {
public:
    void maxProfitRecursion (vector<int>& prices, int index, string currentStatus, int buyPrice, int cost, int &finalAns) {
        if (index == prices.size()) {
            finalAns = max(finalAns, cost);
            return ;
        }
        // sell
        if (currentStatus == "none") {
            // buy
            maxProfitRecursion (prices, index+1, "buy", prices[index], cost, finalAns);
            // no buy
            maxProfitRecursion (prices, index+1, "none", 0, cost, finalAns);
        } else if (currentStatus == "buy") {
            // sell
            maxProfitRecursion (prices, index+1, "sell", 0, cost + prices[index] - buyPrice, finalAns);

            // no sell
            maxProfitRecursion (prices, index+1, "buy", buyPrice, cost, finalAns);
        } else if ( currentStatus == "sell") {
            // cool down
            maxProfitRecursion (prices, index+1, "none", 0, cost, finalAns);
        }


    }
    int maxProfit(vector<int>& prices) {
        int finalAns = 0;
        maxProfitRecursion (prices, 0, "none", 0, 0, finalAns);
        return finalAns;
    }
};
