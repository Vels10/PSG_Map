#include<iostream>

using namespace std;

void DisplayPath(int *path,int end_location)
{
   if(path[end_location]==-1)
   {
      cout<<"  "<<end_location<<"  ";
      return;
   }

   DisplayPath(path,path[end_location]);
   cout<<"  "<<end_location<<"  ";
}

int minDistance(int *dist,bool *vertex_visited,int V)
{
   int min=INT_MAX;
   int min_index;

   for(int i=0;i<V;i++)
   {
      if(vertex_visited[i]==false && dist[i]<=min)
      {
         min=dist[i];
         min_index=i;
      }
   }
   return min_index;
}


int* ShortestPath(int **G,int start_point,int end_point,int V)
{
   bool *vertex_visited = new bool[V];   //vertex_visited

   int *dist = new int[V];

   int *path = new int[V];

   path[start_point]=-1;
   for(int i=0;i<V;i++)
   {
      dist[i]=INT_MAX;
      vertex_visited[i]=false;
   }

   dist[start_point]=0;

      for(int i=0;i<V-1;i++)      //For calculating each distance     //i<V-1
      {
         int u=minDistance(dist,vertex_visited,V);
         //cout<<u<<"  ";

         vertex_visited[u]=true;

         for(int v=0;v<V;v++)            //For updating distance
         {
            if(vertex_visited[v]==false && G[u][v]!=0 && dist[u]!=INT_MAX && (dist[u]+G[u][v])<dist[v])
            {
               path[v]=u;                            //A kind of recursive array
               dist[v]=dist[u]+G[u][v];
            }
         }

      }
   cout<<"\nShortest Distance  "<<dist[end_point];

   cout<<"\nShortest Path ";

   DisplayPath(path,end_point);

   return path;
}

