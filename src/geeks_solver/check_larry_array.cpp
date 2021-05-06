
#include<check_larry_array.h>
bool check_larry_array(std::vector<int> vecInputArray)
{
    int nShiftReq = 0;
    for(int i = 0;i < vecInputArray.size(); ++i)
    {
        int value = vecInputArray[ i];
        int index = i + 1;
        if( value == index )
            continue;
        while( value > index) {
            if( index + 2 > vecInputArray.size()) {
                index--;
                nShiftReq++;
                continue;
            }
            nShiftReq++;
            index = index + 2;
        }
        if( value < index ) {
            nShiftReq+= (index - value ); 
        }
    }
    if( nShiftReq % 3 == 0)
        return true;
    else 
        return false;

}
