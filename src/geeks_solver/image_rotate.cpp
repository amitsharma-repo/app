#include "image_rotate.h"  

int swap( int n, vector<vector<int>>& matrix, int nRow, int nCol)
{
    int nRet = matrix[nRow][nCol];
    matrix[nRow][nCol] = n;
    return nRet;
}

void rotate(std::vector<std::vector<int>>& matrix) 
{
    int nLeft, nTop = 0;
    int nRight, nBottom = matrix.size() - 1;
    while ( nLeft < nRight)
    {
        int i = nLeft;
        while (i < nRight)
        {
            int nTemp = matrix[nTop][nLeft + i];
            nTemp = swap(nTemp, matrix, nTop + i, nRight);
            nTemp = swap(nTemp , matrix, nBottom, nRight - i);
            nTemp = swap(nTemp, matrix, nBottom -i ,nLeft);
            nTemp = swap(nTemp, matrix, nTop, nLeft + i);
            i++;
        }
        nLeft++; nRight--;
        nTop++; nBottom++;
    }
}
