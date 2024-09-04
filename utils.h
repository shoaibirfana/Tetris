 
const char title[] = "PF-Project, Fall-2022";

 
const int M = 20;   // these are the number of rows in the grid 
const int N = 10;   // these are the number of column in the grid 

 
int gameGrid[M][N] = {0};
 
int point_1[4][2], point_2[4][2];//point_1 is the displaying piece and point_2 is one step behind of it 


 /////////////////////////check is the block reack at end row or is go out from first and ninth column/////////////////////
bool anamoly(){
    for (int i=0;i<4;i++)
        if (point_1[i][0]<0 || point_1[i][0]>=N || point_1[i][1]>=M)
            return 0;
        else if (gameGrid[point_1[i][1]][point_1[i][0]])
            return 0;
    return 1;
};