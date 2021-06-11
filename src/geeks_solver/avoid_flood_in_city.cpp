#include<avoid_flood_in_city.h>
#include<iostream>
#include<set>
#include<map>
std::vector<int> avoid_flood_in_city(std::vector<int> rains)
{
    std::set<int> setDryDays;
    std::vector<int> result_out;
    std::map<int,int> mapRainyDays;
    result_out.resize(rains.size());
    for (int nIndex = 0; nIndex < rains.size(); nIndex++)
    {
        if(rains[nIndex] > 0) {
            std::map<int,int>::iterator it =  mapRainyDays.find( rains[nIndex]);
            if( mapRainyDays.end() == it ){
                mapRainyDays[rains[nIndex]] = nIndex;
                result_out[nIndex] = -1;
            }
            else{
                int nLastRainyday = mapRainyDays[rains[nIndex]];
                std::set<int>::iterator itSet = setDryDays.lower_bound(nLastRainyday + 1);
                if(itSet == setDryDays.end())
                    return {};
                else {
                    result_out[*itSet] = rains[nIndex];
                    setDryDays.erase( itSet );
                    mapRainyDays[rains[nIndex]] = nIndex;
                    result_out[nIndex] = -1;
                    
                }
            }
        }
        else {
            setDryDays.insert(nIndex);
            result_out[nIndex] = 1;
        }
    }
    return result_out;
}
