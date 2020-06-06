#include<find_smallest_range_from_klist.h>
#include<iostream>
#include<TestMain.cpp>

TEST(test_1, sample)
{
	 int nShared_res = 0;
     EXPECT_EQ(0, nShared_res);

}

TEST(test_smallest_rangle, smallest_range)
{
    list **ppList = new list*[4];
    ppList[0]   = new list();
    ppList[1]   = new list();
    ppList[2]   = new list();
    ppList[3]   = new list();
    
   find_smallest_range(4, ppList);
}
