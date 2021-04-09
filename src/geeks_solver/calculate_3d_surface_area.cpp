#include <calculate_3d_surface_area.h>

int calculate_3d_surface_area(int nWidth, int nLength, int** dimension )
{
    int nSurfaceArea = 0;
    int **ppBoard= new int*[nWidth + 2];
    int nNullHeightCnt=0;
    for(int nIdx = 0; nIdx <= nWidth+1; nIdx++ )
    {
        ppBoard[nIdx] = new int[nLength+2];
        ppBoard[nIdx][0] = 0;
        ppBoard[nIdx][nLength+1] = 0;
    }
    for(int nIdx =1; nIdx <= nLength+1; nIdx++ )
    {
        ppBoard[0][nIdx] = 0;
        ppBoard[nWidth+1][nIdx] = 0;
    }
    for( int nRow = 1; nRow <= nWidth; nRow++ )
    {
        for(int nCol = 1; nCol <= nLength; nCol++)
        {
            if(dimension[nRow-1][nCol-1] == 0)
                nNullHeightCnt++;
            ppBoard[nRow][nCol] = dimension[nRow-1][nCol -1];
        }
    }  
    for( int i= 0; i < nWidth+2; ++i) {
        for(int j=0; j< nLength+2; ++j) {
        }
    }
    for(int nRow = 1; nRow<= nWidth ; nRow++ )
    {
        for(int nCol = 1; nCol <= nLength; nCol++ )
        {
            if(ppBoard[nRow][nCol] > ppBoard[nRow][nCol-1]) {
                 nSurfaceArea+= (ppBoard[nRow][nCol] - ppBoard[nRow][nCol -1]); 
            }
            if(ppBoard[nRow][nCol] > ppBoard[nRow-1][nCol]) {
                 nSurfaceArea+= (ppBoard[nRow][nCol] - ppBoard[nRow-1][nCol]); 
            }
            if(ppBoard[nRow][nCol] > ppBoard[nRow][nCol+1]) {
                 nSurfaceArea+= (ppBoard[nRow][nCol] - ppBoard[nRow][nCol +1]); 
            } 
            if(ppBoard[nRow][nCol] > ppBoard[nRow +1][nCol]) {
                 nSurfaceArea+= (ppBoard[nRow][nCol] - ppBoard[nRow+1][nCol]); 
            }
        }
    }
    nSurfaceArea += (nWidth * nLength * 2);
    nSurfaceArea -= nNullHeightCnt;
    return nSurfaceArea;
}
