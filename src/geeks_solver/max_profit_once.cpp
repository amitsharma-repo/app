#include<max_profit_once.h>
int maxProfitOnce(std::vector<int>& prices) {
        int nMinPrice = prices[0];
        int nProfit = 0;
        for (int nIdx = 1; nIdx < prices.size(); ++nIdx)
        {
            if (prices[nIdx] > nMinPrice)
            {
                nProfit = prices[nIdx] - nMinPrice  > nProfit ?  prices[nIdx] - nMinPrice : nProfit;
            }
            else
            {
                nMinPrice = prices[nIdx];
            }
        }
        return nProfit;
    }
