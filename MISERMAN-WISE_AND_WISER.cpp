#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin>>N>>M;
    int grid[N][M];
    int dpTable[N][M];
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            cin>>grid[i][j];
        }
    }
    for(int i=0; i<M; ++i)
    {
        dpTable[0][i] = grid[0][i];
    }
    for(int i=1; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            int previousCumFare = 0;
            if(j-1>=0 && j+1<M)
                previousCumFare = min(dpTable[i-1][j-1], min(dpTable[i-1][j], dpTable[i-1][j+1]));
            else if(j-1<0 && j+1<M)
                previousCumFare = min(dpTable[i-1][j], dpTable[i-1][j+1]);
            else if(j-1>=0 && j+1>=M)
                previousCumFare = min(dpTable[i-1][j-1], dpTable[i-1][j]);
            else
                previousCumFare = dpTable[i-1][j];
            dpTable[i][j] = previousCumFare + grid[i][j];
        }
    }
    int minCost = dpTable[N-1][0];
    for(int i =0; i<M; ++i)
    {
        if(dpTable[N-1][i]<minCost)
            minCost = dpTable[N-1][i];
    }
    cout<<minCost<<endl;
}
