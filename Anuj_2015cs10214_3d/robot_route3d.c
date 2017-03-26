#include <stdio.h>
#include<string.h>
#include<stdbool.h>
int main(int argc,char* argv[])
{int strt=0,i,j,k,row=0,col=0,ht=0,total=0,t,totalcovered=0;
//int stud[99][99][99];
	FILE *fp = fopen(argv[1], "r");
	        fscanf(fp, "Start=%d", &strt);
	        printf("%d\n",strt);
	        
	        while(fscanf(fp,"%d,%d",&j,&k)>0)
	        {
			ht++;
			}
			fclose(fp);
			row=(j/10000)+1;
			col=((j/100)%100)+1;
			ht=(j%100)+1;
			total=total+row*col*ht;
			printf("%d,%d,%d,%d\n",row,col,ht,total);	        
	FILE *fp1 = fopen(argv[1], "r");
		 	 FILE *fp2 = fopen(argv[2], "w");
	        fscanf(fp1, "Start=%d", &strt);


int stud[row][col][ht];
row--;
col--;
ht--;
for(i=0;i<=row;i++)
	{for(j=0;j<=col;j++)
		{for(k=0;k<=ht;k++)
		{
			fscanf(fp,"%d,%d",&t,&stud[i][j][k]);
		}
		}
	}	
for(i=0;i<=row;i++)
	{for(j=0;j<=col;j++)
		{for(k=0;k<=ht;k++)
		{
			printf("%d\n",stud[i][j][k]);
		}
		}
	}
	
	int valid(int rowg,int column,int height)
	{
	return rowg>=0 && rowg<=row && column>=0 && column<= col&& height>=0 && height<=ht && (stud[rowg][column][height]==2);
	}
	
				void DFS(int row1,int column,int height)
	      		{

				stud[row1][column][height]=3;
				totalcovered--;
				int n=0;
				if(row1<=9)
				{printf("0%d",row1);
				fprintf(fp2,"0%d",row1);}
				else {
					printf("%d",row1);
					fprintf(fp2,"%d",row1);}
			 if(column<=9)
			 {
				printf("0%d",column);
				fprintf(fp2,"0%d",column);}
				else {printf("%d",column);
				fprintf(fp2,"%d",column);}
			 if(height<=9)
			 {
				printf("0%d\n",height);
				fprintf(fp2,"0%d,",height);}
				else {printf("%d\n",height);
				fprintf(fp2,"%d,",height);}

				int rser[]	={0,+1,-1,0,0,0};
				int colser[]={-1,0,0,+1,0,0};
				int htser[]	={0,0,0,0,-1,+1};

				for(n=0;n<6;n++)
				{

					if(valid(row1+rser[n],column+colser[n],height+htser[n]))
					{DFS(row1+rser[n],column+colser[n],height+htser[n]);
				if(totalcovered!=0)
				{
				if(row1<=9)
				{printf("0%d",row1);
				fprintf(fp2,"0%d",row1);
				}
				else {printf("%d",row1);
				fprintf(fp2,"%d",row1);
				}
				if(column<=9)
				{printf("0%d",column);
				fprintf(fp2,"0%d",column);
				}
				else {
					printf("%d",column);
					fprintf(fp2,"%d",column);}
				if(height<=9)
				{printf("0%d\n",height);
				fprintf(fp2,"0%d\n",height);
				}
				else {
					printf("%d\n",height);
					fprintf(fp2,"%d\n",height);}					
					
					}
					}
					}
				

				}
	
	
	int valid1(int rowg,int column,int height)
	{
	return rowg>=0 && rowg<=row && column>=0 && column<= col&& height>=0 && height<=ht && (stud[rowg][column][height]==1);

	}
	
				void DFS1(int row1,int column,int height)
	      		{

				stud[row1][column][height]=2;

				totalcovered++;
				int n=0;
				int rser[]	={0,+1,-1,0,0,0};
				int colser[]={-1,0,0,+1,0,0};
				int htser[]	={0,0,0,0,-1,+1};
				for(n=0;n<6;n++)
				{
					if(valid1(row1+rser[n],column+colser[n],height+htser[n]))
					{DFS1(row1+rser[n],column+colser[n],height+htser[n]);}
					
				}
			}
					DFS1(strt/10000,(strt/100)%100,strt%100);
				printf("	%d\n",totalcovered);
				if(totalcovered<=9)
				fprintf(fp2,"00000%d\n",totalcovered);							
				else if(totalcovered<=99)
				fprintf(fp2,"0000%d\n",totalcovered);
				else if(totalcovered<=999)
				fprintf(fp2,"000%d\n",totalcovered);
				else if(totalcovered<=9999)
				fprintf(fp2,"00%d\n",totalcovered);
				else if(totalcovered<=99999)
				fprintf(fp2,"0%d\n",totalcovered);				
				else if(totalcovered<=999999)
				fprintf(fp2,"%d\n",totalcovered);
				DFS(strt/10000,(strt/100)%100,strt%100);
				fclose(fp2);
return 1;
}
