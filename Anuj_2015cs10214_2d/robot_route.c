#include <stdio.h>
#include<string.h>
#include<stdbool.h>
int main(int argc,char* argv[])
{
	int strt,i,j,k,row=0,col=0,total=0,totalcovered=0;
	int stud[99][99];
        FILE *fp;
	fp = fopen(argv[1], "r");
	        
			//reading the input inside a 99*99 array
			
			fscanf(fp, "Start=%d", &strt);
	        printf("%d\n",strt);
	        while(fscanf(fp,"%d,%d",&j,&k)>0)
	        {
	        if	(j/100==0)
	        	row++;
	        col++;	
			stud[j/100][j%100]=k;
			if(k==0)
				total--;
			printf("%d\n",stud[j/100][j%100]);			
			}

			fclose(fp);


			col=col/row;
			total=total+row*col;
			printf("%d,%d,%d\n",row,col,total);	        
			row--;
	        col--;
			//totalcovered=total;
//	printf("koi");
	 FILE *fp2;
	 	fp2 = fopen(argv[2], "w"); 	
	 
	 //ijjat ka array mein firse daala
	 
/*	 	int *arr[row];
    	for (i=0; i<=row; i++)
         arr[i] = (int *)malloc(col+1 * sizeof(int));
	 FILE *fp1 = fopen(argv[1], "r");

	        fscanf(fp1, "Start=%d", &strt);
	        printf("%d",strt);
	        while(fscanf(fp1,"%d,%d",&j,&k)>0)
	        {
			arr[j/100][j%100]=k;
			printf("%d",arr[j/100][j%100]);	
			}
			fclose(fp1);
*/
//print kar diya,jabki zaroorat

/*	        for(i=0;i<=row;i++)
	        	{
				for(j=0;j<=col;j++)
	        	{
	        	printf("%d",stud[i][j]);	
				}
			//	printf("\n");
				}*/
//printf("\n");
	int valid(int rowg,int column)
	{
	return rowg>=0 && rowg<=row && column>=0 && column<= col&& (stud[rowg][column]==2);
	}
	
				void DFS(int row1,int column)
	      		{

				stud[row1][column]=3;
				totalcovered--;
				int n=0;/*
				if(row1<=9)
				{printf("0%d",row1);
				fprintf(fp2,"0%d",row1);}
				else {
					printf("%d",row1);
					fprintf(fp2,"%d",row1);}
			 if(column<=9)
			 {
				printf("0%d\n",column);
				fprintf(fp2,"0%d,",column);}
				else {printf("%d\n",column);
				fprintf(fp2,"%d\n",column);}*/
				for(n=0;n<4;n++)
				{
				
				if(n==0)
					{
					if(valid(row1,column-1))
					{DFS(row1,column-1);
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
				{printf("0%d\n",column);
				fprintf(fp2,"0%d,",column);
				}
				else {
					printf("%d\n",column);
					fprintf(fp2,"%d,",column);}}
					}}
				if(n==1)
					{
					if(valid(row1+1,column))
					{DFS(row1+1,column);
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
				{printf("0%d\n",column);
				fprintf(fp2,"0%d,",column);
				}
				else {
					printf("%d\n",column);
					fprintf(fp2,"%d,",column);
				}
				}					
					}}
				if(n==2)
					{
					if(valid(row1-1,column))
					{
					DFS(row1-1,column);
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
				{printf("0%d\n",column);
				fprintf(fp2,"0%d,",column);
				}
				else {
					printf("%d\n",column);
					fprintf(fp2,"%d,",column);
				}
				}					
					}}
				if(n==3)
					{
					if(valid(row1,column+1))
					{
					DFS(row1,column+1);	
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
				{printf("0%d\n",column);
				fprintf(fp2,"0%d,",column);
				}
				else {
					printf("%d\n",column);
					fprintf(fp2,"%d,",column);
				}
				}
					}
				}}
				
				// if no backtracking is to be printed
				/*if(totalcovered!=0)
				{*/
				

				//}*/
				}
	
	
	int valid1(int rowg,int column)
	{
	return rowg>=0 && rowg<=row && column>=0 && column<= col&& (stud[rowg][column]==1);
	}
	
				void DFS1(int row1,int column)
	      		{

				stud[row1][column]=2;
				totalcovered++;
				int n=0;
				/*if(row1<=9)
				printf("0%d",row1);
				else printf("%d",row1);
			 if(column<=9)
				printf("0%d\n",column);
				else printf("%d",column);*/
				for(n=0;n<4;n++)
				{
				
				if(n==0)
					{
					if(valid1(row1,column-1))
					DFS1(row1,column-1);
					}
				if(n==1)
					{
					if(valid1(row1+1,column))
					DFS1(row1+1,column);
					}
				if(n==2)
					{
					if(valid1(row1-1,column))
					DFS1(row1-1,column);}
				if(n==3)
					{
					if(valid1(row1,column+1))
					DFS1(row1,column+1);	}
				}
				// if no backtracking is to be printed
				/*if(totalcovered!=0)
				{
				if(row1<=9)
				printf("0%d",row1);
				else printf("%d",row1);
				if(column<=9)
				printf("0%d\n",column);
				else printf("%d",column);
				}*/
				}	
				DFS1(strt/100,strt%100);
				if(totalcovered<=9)
				fprintf(fp2,"000%d\n",totalcovered);							
				else if(totalcovered<=99)
				fprintf(fp2,"00%d\n",totalcovered);
				else if(totalcovered<=999)
				fprintf(fp2,"0%d\n",totalcovered);
				else if(totalcovered<=9999)
				fprintf(fp2,"%d\n",totalcovered);								
				DFS(strt/100,strt%100);
				fclose(fp2);
return 1;
}
