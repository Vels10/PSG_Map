#include<graphics.h>

using namespace std;

void make_vertices(int x,int y)
{
   circle(x,y,5);
   floodfill(x,y,WHITE);
}

void make_edges(int **map,int graph_vertices[35][2],int V)
{
   for(int i=0;i<V;i++)
   {
      for(int j=0;j<V;j++)
      {
         if(map[i][j]==1)
         {
            line(graph_vertices[i][0],graph_vertices[i][1],graph_vertices[j][0],graph_vertices[j][1]);
         }
      }
   }
}

void SetFlagArray(bool *flag_array,int *path,int end_location)
{
  if(path[end_location]==-1)
   {
      flag_array[end_location]=1;
      return;
   }

   SetFlagArray(flag_array,path,path[end_location]);
   flag_array[end_location]=1;
}

void make_path(int **map,int graph_vertices[35][2],int start_location,int end_location,int *path,int V)  //Called in Line 418
{
   bool *flag_array=new bool[V];

   for(int i=0;i<V;i++)
      flag_array[i]=0;

   flag_array[end_location]=1;
   flag_array[start_location]=1;

   SetFlagArray(flag_array,path,end_location);
   bool flag_i=0,flag_j=0;
   for(int i=0;i<V;i++)
   {
      for(int j=0;j<V;j++)
      {
         flag_i=flag_array[i];
         flag_j=flag_array[j];
         if(map[i][j]==1)
         {
            if(flag_i && flag_j)
            {
               setcolor(BLUE);
               setlinestyle(1,1,3);
               line(graph_vertices[i][0],graph_vertices[i][1],graph_vertices[j][0],graph_vertices[j][1]);
            }
            else
            {
               setcolor(BLACK);
               line(graph_vertices[i][0],graph_vertices[i][1],graph_vertices[j][0],graph_vertices[j][1]);
            }
         }
      }
   }
}

int display_map(int **map,int V)
{
   int graph_vertices[35][2];       //Graph Vertices are found by making a plot of real graph in a graph sheet.

   //graph_vertice[i][0]          -  Holds x coordinate of i th vertice
   //graph_vertice[i][1]          -  Holds y coordinate of i th vertice

   graph_vertices[0][0]=485;
   graph_vertices[0][1]=400;


   graph_vertices[1][0]=375;
   graph_vertices[1][1]=340;


   graph_vertices[2][0]=320;
   graph_vertices[2][1]=400;


   graph_vertices[3][0]=210;
   graph_vertices[3][1]=340;


   graph_vertices[4][0]=485;
   graph_vertices[4][1]=340;


   graph_vertices[5][0]=375;
   graph_vertices[5][1]=260;


   graph_vertices[6][0]=265;
   graph_vertices[6][1]=280;

   graph_vertices[7][0]=375;
   graph_vertices[7][1]=120;

   graph_vertices[8][0]=540;
   graph_vertices[8][1]=260;

   graph_vertices[9][0]=540;
   graph_vertices[9][1]=120;

   graph_vertices[10][0]=760;
   graph_vertices[10][1]=320;

   graph_vertices[11][0]=650;
   graph_vertices[11][1]=360;

   graph_vertices[12][0]=760;
   graph_vertices[12][1]=400;

   graph_vertices[13][0]=650;
   graph_vertices[13][1]=320;

   graph_vertices[14][0]=650;
   graph_vertices[14][1]=280;

   graph_vertices[15][0]=760;
   graph_vertices[15][1]=220;

   graph_vertices[16][0]=705;
   graph_vertices[16][1]=120;

   graph_vertices[17][0]=870;
   graph_vertices[17][1]=320;

   graph_vertices[18][0]=870;
   graph_vertices[18][1]=260;

   graph_vertices[19][0]=1145;
   graph_vertices[19][1]=120;

   graph_vertices[20][0]=815;
   graph_vertices[20][1]=280;

   graph_vertices[21][0]=815;
   graph_vertices[21][1]=260;

   graph_vertices[22][0]=980;
   graph_vertices[22][1]=340;

   graph_vertices[23][0]=980;
   graph_vertices[23][1]=260;

   graph_vertices[24][0]=980;
   graph_vertices[24][1]=200;

   graph_vertices[25][0]=760;
   graph_vertices[25][1]=440;

   graph_vertices[26][0]=595;
   graph_vertices[26][1]=460;

   graph_vertices[27][0]=870;
   graph_vertices[27][1]=560;

   graph_vertices[28][0]=1035;
   graph_vertices[28][1]=560;

   graph_vertices[29][0]=595;
   graph_vertices[29][1]=520;

   graph_vertices[30][0]=705;
   graph_vertices[30][1]=560;

   graph_vertices[31][0]=210;
   graph_vertices[31][1]=300;

   graph_vertices[32][0]=155;
   graph_vertices[32][1]=380;

   graph_vertices[33][0]=100;
   graph_vertices[33][1]=340;


   graph_vertices[34][0]=1035;
   graph_vertices[34][1]=520;


   //int gd=DETECT , g;
   //initgraph(&gd,&gm,"C:\\TC\\BGI");

   initwindow(1300,700);

   /*line(50,50,50,630);
   line(50,630,1195,630);
   line(1195,630,1195,50);
   line(1195,50,50,50);*/

   for(int i=0;i<35;i++)
      make_vertices(graph_vertices[i][0],graph_vertices[i][1]);

   make_edges(map,graph_vertices,V);

   setcolor(WHITE);
   outtextxy(graph_vertices[0][0],graph_vertices[0][1],"0 - entrance");
   outtextxy(graph_vertices[1][0],graph_vertices[1][1],"1 - C-Block");
   outtextxy(graph_vertices[2][0],graph_vertices[2][1],"2 - A-Block Parking");
   outtextxy(graph_vertices[3][0],graph_vertices[3][1],"3 - A-Block");
   outtextxy(graph_vertices[4][0],graph_vertices[4][1],"4 - D-Block");
   outtextxy(graph_vertices[5][0],graph_vertices[5][1],"5 - Y-Block");
   outtextxy(graph_vertices[6][0],graph_vertices[6][1],"6 - Golden Quadrilateral");
   outtextxy(graph_vertices[7][0],graph_vertices[7][1],"7 - Library");
   outtextxy(graph_vertices[8][0],graph_vertices[8][1],"8 - Accounts Department");
   outtextxy(graph_vertices[9][0],graph_vertices[9][1],"9 - I-Block");
   outtextxy(graph_vertices[10][0],graph_vertices[10][1],"10 - F-Block");
   outtextxy(graph_vertices[11][0],graph_vertices[11][1],"11 - F-Block Canteen");
   outtextxy(graph_vertices[12][0],graph_vertices[12][1],"12 - Sky Walk College Side");
   outtextxy(graph_vertices[13][0],graph_vertices[13][1],"13 - Ladies Washroom");
   outtextxy(graph_vertices[14][0],graph_vertices[14][1],"14 - Mens Washroom");
   outtextxy(graph_vertices[15][0],graph_vertices[15][1],"15 - Stationery");
   outtextxy(graph_vertices[16][0],graph_vertices[16][1],"16 - Polytechnic Entrance");
   outtextxy(graph_vertices[17][0],graph_vertices[17][1],"17 - J-Block");
   outtextxy(graph_vertices[18][0],graph_vertices[18][1],"18 - J-Block Canteen");
   outtextxy(graph_vertices[19][0],graph_vertices[19][1],"19 - Parking");
   outtextxy(graph_vertices[20][0],graph_vertices[20][1],"20 - Textiles Department");
   outtextxy(graph_vertices[21][0],graph_vertices[21][1],"21 - Soil Spinning Lab");
   outtextxy(graph_vertices[22][0],graph_vertices[22][1],"22 - E-Block");
   outtextxy(graph_vertices[23][0],graph_vertices[23][1],"23 - K-Block");
   outtextxy(graph_vertices[24][0],graph_vertices[24][1],"24 - M-Block");
   outtextxy(graph_vertices[25][0],graph_vertices[25][1],"25 - Sky Walk IM Side");
   outtextxy(graph_vertices[26][0],graph_vertices[26][1],"26 - N-Block");
   outtextxy(graph_vertices[27][0],graph_vertices[27][1],"27 - Mens Hostel Entrance");
   outtextxy(graph_vertices[28][0],graph_vertices[28][1],"28 - Womens Hostel Entrance");
   outtextxy(graph_vertices[29][0],graph_vertices[29][1],"29 - IM Ground");
   outtextxy(graph_vertices[30][0],graph_vertices[30][1],"30 - Guest House");
   outtextxy(graph_vertices[31][0],graph_vertices[31][1],"31- Mens Waiting Area");
   outtextxy(graph_vertices[32][0],graph_vertices[32][1],"32 - Womens Waiting Area");
   outtextxy(graph_vertices[33][0],graph_vertices[33][1],"33 - A Block Stationery");
   outtextxy(graph_vertices[34][0],graph_vertices[34][1],"34 - Sports Complex");

   settextstyle(0,HORIZ_DIR,3);
   outtextxy(200,410,"AVINASHI ROAD");
   settextstyle(0,VERT_DIR,3);
   outtextxy(1145,100,"PIONNER MILL ROAD");
   settextstyle(0,HORIZ_DIR,3);
   outtextxy(1085,20,"PSG TECH");
   outtextxy(1145,40,"MAP");

   settextstyle(0,HORIZ_DIR,2);
   outtextxy(100,10,"NORTH UPWARDS ");

   getch();
   closegraph();

   return 0;
}


int DisplayPathInMap(int **map,int start_location,int end_location,int *path,int V)
{
   int graph_vertices[35][2];       //Graph Vertices are found by making a plot of real graph in a graph sheet.

   //graph_vertice[i][0]          -  Holds x coordinate of i th vertice
   //graph_vertice[i][1]          -  Holds y coordinate of i th vertice

   graph_vertices[0][0]=485;
   graph_vertices[0][1]=400;

   graph_vertices[1][0]=375;
   graph_vertices[1][1]=340;

   graph_vertices[2][0]=320;
   graph_vertices[2][1]=400;

   graph_vertices[3][0]=210;
   graph_vertices[3][1]=340;

   graph_vertices[4][0]=485;
   graph_vertices[4][1]=340;

   graph_vertices[5][0]=375;
   graph_vertices[5][1]=260;

   graph_vertices[6][0]=265;
   graph_vertices[6][1]=280;

   graph_vertices[7][0]=375;
   graph_vertices[7][1]=120;

   graph_vertices[8][0]=540;
   graph_vertices[8][1]=260;

   graph_vertices[9][0]=540;
   graph_vertices[9][1]=120;

   graph_vertices[10][0]=760;
   graph_vertices[10][1]=320;

   graph_vertices[11][0]=650;
   graph_vertices[11][1]=360;

   graph_vertices[12][0]=760;
   graph_vertices[12][1]=400;

   graph_vertices[13][0]=650;
   graph_vertices[13][1]=320;

   graph_vertices[14][0]=650;
   graph_vertices[14][1]=280;

   graph_vertices[15][0]=760;
   graph_vertices[15][1]=220;


   graph_vertices[16][0]=705;
   graph_vertices[16][1]=120;


   graph_vertices[17][0]=870;
   graph_vertices[17][1]=320;


   graph_vertices[18][0]=870;
   graph_vertices[18][1]=260;


   graph_vertices[19][0]=1145;
   graph_vertices[19][1]=120;


   graph_vertices[20][0]=815;
   graph_vertices[20][1]=280;


   graph_vertices[21][0]=815;
   graph_vertices[21][1]=260;


   graph_vertices[22][0]=980;
   graph_vertices[22][1]=340;


   graph_vertices[23][0]=980;
   graph_vertices[23][1]=260;


   graph_vertices[24][0]=980;
   graph_vertices[24][1]=200;


   graph_vertices[25][0]=760;
   graph_vertices[25][1]=440;

   graph_vertices[26][0]=595;
   graph_vertices[26][1]=460;

   graph_vertices[27][0]=870;
   graph_vertices[27][1]=560;

   graph_vertices[28][0]=1035;
   graph_vertices[28][1]=560;

   graph_vertices[29][0]=595;
   graph_vertices[29][1]=520;


   graph_vertices[30][0]=705;
   graph_vertices[30][1]=560;


   graph_vertices[31][0]=210;
   graph_vertices[31][1]=300;


   graph_vertices[32][0]=155;
   graph_vertices[32][1]=380;

   graph_vertices[33][0]=100;
   graph_vertices[33][1]=340;


   graph_vertices[34][0]=1035;
   graph_vertices[34][1]=520;


   //int gd=DETECT , g;
   //initgraph(&gd,&gm,"C:\\TC\\BGI");

   initwindow(1300,700);

   //setcolor(RED);

   /*line(50,50,50,630);
   line(50,630,1195,630);
   line(1195,630,1195,50);
   line(1195,50,50,50);*/


   for(int i=0;i<35;i++)
      make_vertices(graph_vertices[i][0],graph_vertices[i][1]);

   make_path(map,graph_vertices,start_location,end_location,path,V);

   setcolor(WHITE);
   outtextxy(graph_vertices[0][0],graph_vertices[0][1],"0 - entrance");
   outtextxy(graph_vertices[1][0],graph_vertices[1][1],"1 - C-Block");
   outtextxy(graph_vertices[2][0],graph_vertices[2][1],"2 - A-Block Parking");
   outtextxy(graph_vertices[3][0],graph_vertices[3][1],"3 - A-Block");
   outtextxy(graph_vertices[4][0],graph_vertices[4][1],"4 - D-Block");
   outtextxy(graph_vertices[5][0],graph_vertices[5][1],"5 - Y-Block");
   outtextxy(graph_vertices[6][0],graph_vertices[6][1],"6 - Golden Quadrilateral");
   outtextxy(graph_vertices[7][0],graph_vertices[7][1],"7 - Library");
   outtextxy(graph_vertices[8][0],graph_vertices[8][1],"8 - Accounts Department");
   outtextxy(graph_vertices[9][0],graph_vertices[9][1],"9 - I-Block");
   outtextxy(graph_vertices[10][0],graph_vertices[10][1],"10 - F-Block");
   outtextxy(graph_vertices[11][0],graph_vertices[11][1],"11 - F-Block Canteen");
   outtextxy(graph_vertices[12][0],graph_vertices[12][1],"12 - Sky Walk College Side");
   outtextxy(graph_vertices[13][0],graph_vertices[13][1],"13 - Ladies Washroom");
   outtextxy(graph_vertices[14][0],graph_vertices[14][1],"14 - Mens Washroom");
   outtextxy(graph_vertices[15][0],graph_vertices[15][1],"15 - Stationery");
   outtextxy(graph_vertices[16][0],graph_vertices[16][1],"16 - Polytechnic Entrance");
   outtextxy(graph_vertices[17][0],graph_vertices[17][1],"17 - J-Block");
   outtextxy(graph_vertices[18][0],graph_vertices[18][1],"18 - J-Block Canteen");
   outtextxy(graph_vertices[19][0],graph_vertices[19][1],"19 - Parking");
   outtextxy(graph_vertices[20][0],graph_vertices[20][1],"20 - Textiles Department");
   outtextxy(graph_vertices[21][0],graph_vertices[21][1],"21 - Soil Spinning Lab");
   outtextxy(graph_vertices[22][0],graph_vertices[22][1],"22 - E-Block");
   outtextxy(graph_vertices[23][0],graph_vertices[23][1],"23 - K-Block");
   outtextxy(graph_vertices[24][0],graph_vertices[24][1],"24 - M-Block");
   outtextxy(graph_vertices[25][0],graph_vertices[25][1],"25 - Sky Walk IM Side");
   outtextxy(graph_vertices[26][0],graph_vertices[26][1],"26 - N-Block");
   outtextxy(graph_vertices[27][0],graph_vertices[27][1],"27 - Mens Hostel Entrance");
   outtextxy(graph_vertices[28][0],graph_vertices[28][1],"28 - Womens Hostel Entrance");
   outtextxy(graph_vertices[29][0],graph_vertices[29][1],"29 - IM Ground");
   outtextxy(graph_vertices[30][0],graph_vertices[30][1],"30 - Guest House");
   outtextxy(graph_vertices[31][0],graph_vertices[31][1],"31- Mens Waiting Area");
   outtextxy(graph_vertices[32][0],graph_vertices[32][1],"32 - Womens Waiting Area");
   outtextxy(graph_vertices[33][0],graph_vertices[33][1],"33 - A Block Stationery");
   outtextxy(graph_vertices[34][0],graph_vertices[34][1],"34 - Sports Complex");

   settextstyle(0,HORIZ_DIR,3);
   outtextxy(200,410,"AVINASHI ROAD");
   settextstyle(0,VERT_DIR,3);
   outtextxy(1145,100,"PIONNER MILL ROAD");
   settextstyle(0,HORIZ_DIR,3);
   outtextxy(1085,20,"PSG TECH");
   outtextxy(1145,40,"MAP");

   settextstyle(0,HORIZ_DIR,2);
   outtextxy(100,10,"NORTH UPWARDS ");
   getch();
   closegraph();

   return 0;

}
