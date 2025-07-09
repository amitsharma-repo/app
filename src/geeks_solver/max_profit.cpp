#include<max_profit.h>

int maxProfit(std::vector<int>& prices) {
        int nBuyIdx = 0;
        int nProfit = 0;
        int nSellIdx = 0;
        bool bProfitCal = false;
        for (int nIdx = 1; nIdx < prices.size(); ++nIdx)
        {
            if (prices[nIdx] > prices[nSellIdx])
            {
                nSellIdx = nIdx;
                bProfitCal = true;
            }
            else
            {
                //std::cout << "nSell Price " << prices[nSellIdx] << " nBuy Price " << prices[nBuyIdx] << std::endl;
                nProfit += prices[nSellIdx] - prices[nBuyIdx];
                nSellIdx = nBuyIdx = nIdx;
                bProfitCal = false;
            }
        }
        if (bProfitCal && prices[nSellIdx] > prices[nBuyIdx])
        {
            nProfit += prices[nSellIdx] - prices[nBuyIdx];
        }
        return nProfit;
    }
