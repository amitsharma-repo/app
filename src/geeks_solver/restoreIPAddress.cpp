#include <restoreIPAddress.h>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct DPValidAddress
{
    set<string> firstSubset;
    set<string> secondSubset;
    set<string> thirdSubset;
    set<string> forthSubset;
};

void printSubnet(std::set<string> subnet)
{
  for_each(subnet.begin(), subnet.end(), [](string str){
      std::cout << str << "    " ;
      });
  std::cout << std::endl;
}
void updateNewSubnet(set<string>& vecSubnetUpdate, const set<string> vecNxtSubnet, char ch)
{
    for_each(vecNxtSubnet.begin(), vecNxtSubnet.end(), [&](const string& subnet) {
        string str(1,ch);
        string strCheck(str);
        int nIdx = subnet.find('.');
        if(nIdx > 0)
        {
          strCheck.append(subnet.substr(0, nIdx));
        }
        else
        {
          strCheck.append(subnet);
        }
        stringstream stream(strCheck);
        int nSubnet;
        stream >> nSubnet;
        if (nSubnet <= 255)
        {
          str.append(subnet);
          vecSubnetUpdate.insert(str);
        }
    });
}

void addNewSubnet(set<string>& vecSubnetUpdate, const set<string>& vecDiagSubnet, char ch)
{
    for_each(vecDiagSubnet.begin(), vecDiagSubnet.end(), [&](string subnet) {
         string str{ch};
         str.append(".");
         str.append(subnet);
         vecSubnetUpdate.insert(str);
    });
}

void recuseValidIPAddr(char ch, vector<DPValidAddress>& vecDP, int nIdx)
{
    set<string> vecNxt;
    set<string> vecDiag;
    //populating firstSubset
    {
        vecNxt = vecDP[nIdx +1].firstSubset;
        updateNewSubnet(vecDP[nIdx].firstSubset, vecNxt, ch);
       // printSubnet(vecDP[nIdx].firstSubset);
    }
    //populating secondSubset
    {
        vecNxt = vecDP[nIdx +1].secondSubset;
        vecDiag = vecDP[nIdx +1].firstSubset;
        addNewSubnet(vecDP[nIdx].secondSubset, vecDiag, ch);
        updateNewSubnet(vecDP[nIdx].secondSubset, vecNxt, ch);
        //printSubnet(vecDP[nIdx].secondSubset);
    }
    //populating thirdSubset
    {
        vecNxt = vecDP[nIdx +1].thirdSubset;
        vecDiag = vecDP[nIdx +1].secondSubset;
        addNewSubnet(vecDP[nIdx].thirdSubset, vecDiag, ch);
        updateNewSubnet(vecDP[nIdx].thirdSubset, vecNxt, ch);
        //printSubnet(vecDP[nIdx].thirdSubset);
    }
    //populating forthSubset
    {
        vecNxt = vecDP[nIdx +1].forthSubset;
        vecDiag = vecDP[nIdx +1].thirdSubset;
        addNewSubnet(vecDP[nIdx].forthSubset, vecDiag, ch);
        updateNewSubnet(vecDP[nIdx].forthSubset, vecNxt, ch);
        //printSubnet(vecDP[nIdx].forthSubset);
    }
}

std::set<std::string> restoreIpAddresses(std::string s) {
    std::vector<DPValidAddress> vecDP;
    vecDP.resize(s.size());
    string str{s[s.size()-1]};
    vecDP[s.size()-1].firstSubset.insert(str);
    for (int nIdx = s.size() -2; nIdx >= 0; nIdx--)
    {
        recuseValidIPAddr(s[nIdx], vecDP, nIdx);
    }
    return vecDP[0].forthSubset;
}
