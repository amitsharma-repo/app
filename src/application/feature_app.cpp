#include<tuple>
#include<vector>
#include<find_smallest_range_from_klist.h>
#include<algorithm>
#include<iostream>
using namespace std;
List* create_link_List(const std::vector<int>& vec_data)
{
    List *pList , *pStart;
    pList = pStart = nullptr;

    for_each( vec_data.begin(), vec_data.end(), [ & ](int nData){
            if( pList == nullptr) {
                pList = new List( nData );
                pStart = pList;
            }
            else {
                pList->pNxt_ = new List( nData );
                pList = pList->pNxt_;
            }
   });
    return pStart;
}


int main()
{
    List **ppList = new List*[3];
    ppList[0]   = create_link_List( {4, 7, 9, 12, 15} );
    ppList[1]   = create_link_List( {0, 8 ,10 , 14 , 20} );
    ppList[2]   = create_link_List( {6 ,12 ,16, 30 , 50} );
    
   std::tuple<int,int> range= find_smallest_range(3, ppList);
    std::cout << get<0>(range) <<std::endl; 
	std::cout <<get<1>(range) << std::endl;
}
