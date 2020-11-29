// This Code has been developed as project for "Grid Generation" Course.
// Title: "Generating a unstructured grid using Advanced Front Method"
// First Phase
// Ashkan Bagherzadeh
// Student ID : 99211211
// 28 November 2020


#include<iostream>
#include <stdio.h>
#include <math.h>
#include <fstream>
using namespace std;


//distance caluculation between P1[x1,y1] and P2[x2,y2]
float distance(float x1,float y1 ,float x2 ,float y2){
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

//export .plt file
void exportgrid(float Node_Coord[][2],int Vtriangle[][3],int N,int E){
	
ofstream MyFile("Grid.plt");
  // Write to the file
	MyFile << "VARIABLES = X ,Y \n";
	MyFile << "ZONE N="<<N<< " E="<<E<< " F=FEPOINT, ET=TRIANGLE \n";
	
	int i;
	                for( i=0; i<N; i++)
                {
						MyFile <<Node_Coord[i][0]<<" "<<Node_Coord[i][1]<<"\n";
                }
	
		                for( i=0; i<E; i++)
                {
						MyFile <<Vtriangle[i][0]<<" "<<Vtriangle[i][1]<<" "<<Vtriangle[i][2]<<"\n";
                }
	
  // Close the file
  MyFile.close();

}



int main(){
	
	
	
// Data Structure Initialization	

	//Node Coordinates
	float Node_Coord[16][2]={0,3,1,3,2,3,3,3,0,2,1,2,2,2,3,2,0,1,1,1,2,1,3,1,0,0,1,0,2,0,3,0};
	
	//Edge Connection
	int Edge_Node[33][2]={1,2,2,3,3,4,1,5,2,5,2,6,6,3,3,7,7,4,4,8,5,6,6,7,7,8,5,9,9,6,6,10,10,7,7,11,11,8,8,12,9,10,10,11,11,12,9,13,13,10,10,14,14,11,11,15,15,12,12,16,13,14,14,15,15,16};
	
	//Edges making Triangle
	int Triangle[18][3]={1,4,5,5,6,11,2,6,7,7,8,12,3,8,9,9,10,13,11,14,15,15,16,21,16,12,17,17,18,22,13,18,19,19,20,23,21,24,25,25,26,31,26,22,27,27,28,32,28,23,29,29,30,33};
	
	
	int v =  sizeof Node_Coord / sizeof Node_Coord[0]; // number of vertices
	int e =  sizeof Edge_Node / sizeof Edge_Node[0]; // number of Edges
	int c =  sizeof Triangle / sizeof Triangle[0]; // number of Triangles


	//Front array
	int Front[e] = {0};
	
	


	int i,j; // counter of loops 

	
   
   
float Edge_Mid[e][2]; //coordinate of middle of edge i
float Edge_Length[e]; // length of edge i

// calculate length and mid of edge array
for( i=0; i<e; i++)
{

	Edge_Mid[i][0]=(Node_Coord[Edge_Node[i][0]-1][0]+ Node_Coord[Edge_Node[i][1]-1][0])/2;
	Edge_Mid[i][1]=(Node_Coord[Edge_Node[i][0]-1][1]+ Node_Coord[Edge_Node[i][1]-1][1])/2;
	Edge_Length[i]=distance(Node_Coord[Edge_Node[i][0]-1][0],Node_Coord[Edge_Node[i][0]-1][1],Node_Coord[Edge_Node[i][1]-1][0],Node_Coord[Edge_Node[i][1]-1][1]);

}

	
	
//Redefine triangels with vertices
 //coordinate of middle of edge i


int Vtriangle[18][3]={1,2,5,2,5,6,2,3,6,3,6,7,3,4,7,4,7,8,5,6,9,6,9,10,6,7,10,7,10,11,7,8,11,8,11,12,9,10,13,10,13,14,10,11,14,11,14,15,11,12,15,12,15,16};



// calculate length and mid of edge array
for( i=0; i<e; i++)
{

	Edge_Mid[i][0]=(Node_Coord[Edge_Node[i][0]-1][0]+ Node_Coord[Edge_Node[i][1]-1][0])/2;
	Edge_Mid[i][1]=(Node_Coord[Edge_Node[i][0]-1][1]+ Node_Coord[Edge_Node[i][1]-1][1])/2;
	Edge_Length[i]=distance(Node_Coord[Edge_Node[i][0]-1][0],Node_Coord[Edge_Node[i][0]-1][1],Node_Coord[Edge_Node[i][1]-1][0],Node_Coord[Edge_Node[i][1]-1][1]);

}
	
	
	
	
	
	
	int rows=c;
	int cols=3;
	
	
	        cout<<"\n Edge_Node : \n";
        for( i=0; i<rows; i++)
        {
                for( j=0; j<cols; j++)
                {
                        cout<<" "<< Edge_Length[i]<<" ";
                        cout<<"\n";
                }
                
        }

    

// make tecplot file
exportgrid(Node_Coord,Vtriangle,v,c);



		return 0;
}

