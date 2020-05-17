#include <iostream>
#include<limits.h>
#include"graphics_part.h";
#include"dijikstra.h"
using namespace std;

int V=35;   //V is the number of locations in our college. V- Vertices -> points

int main()
{
    cout << "\nPSG Tech Virtual Map ";

    int **map = new int*[V];

    for(int i=0;i<V;i++)
    {
      map[i]=new int[V];
    }

   for(int i=0;i<V;i++)
   {
      for(int j=0;j<V;j++)
      {
        map[i][j]=0;
      }
   }

   //Initializing Vertices. Verticces are initialized based on sample map drawn.

   cout<<"\nLOADING MAP";
   map[0][12]=map[0][8]=map[0][4]=map[0][1]=1;
   map[1][0]=map[1][4]=map[1][5]=map[1][2]=map[1][6]=1;
   map[2][1]=1;
   map[3][6]=map[3][31]=map[3][32]=map[3][33]=1;
   map[4][0]=map[4][1]=map[4][5]=1;
   map[5][1]=map[5][4]=map[5][7]=1;
   map[6][1]=map[6][3]=1;
   map[7][5]=map[7][9]=1;
   map[8][0]=map[8][9]=1;
   map[9][16]=map[9][8]=map[9][7]=1;
   map[10][11]=map[10][12]=map[10][13]=map[10][14]=map[10][15]=map[10][17]=1;
   map[11][10]=1;
   map[12][0]=map[12][10]=map[12][22]=map[12][25]=1;
   map[13][10]=1;
   map[14][10]=1;
   map[15][10]=map[15][21]=map[15][16]=1;
   map[16][15]=map[16][18]=map[16][19]=map[16][9]=1;
   map[17][10]=map[17][20]=map[17][18]=1;
   map[18][17]=map[18][16]=1;
   map[19][16]=1;
   map[20][17]=map[20][21]=1;
   map[21][20]=map[21][15]=1;
   map[22][12]=map[22][23]=1;
   map[23][22]=map[23][24]=1;
   map[24][23]=1;
   map[25][12]=map[25][30]=map[25][26]=1;
   map[26][25]=map[26][29]=1;
   map[27][30]=map[27][28]=1;
   map[28][34]=map[28][27]=1;
   map[29][30]=map[29][26]=1;
   map[30][25]=map[30][27]=map[30][29]=1;
   map[31][3]=1;
   map[32][3]=1;
   map[33][3]=1;
   map[34][28]=1;
   cout<<"\nMAP LOADED";

   display_map(map,V);

   cout<<"\nBack To Main ";

   int start_location,end_location;

   cout<<"\nEnter the start location and end location ";
   cin>>start_location>>end_location;

   int *path;
   path=ShortestPath(map,start_location,end_location,V);

   DisplayPathInMap(map,start_location,end_location,path,V);

    return 0;
}
