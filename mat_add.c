#include<stdio.h>
#include<time.h>
static int i,j,k;
# define start_m 1.0
# define rows 1000
# define colums 1000
static float b[rows][colums],c[rows][colums],d[rows][colums];
void read(float a[rows][colums])
{
	for(i=0;i<rows;i++)
	{
		    k=start_m;
		        for(j=0;j<colums;j++)
				    {
					            
					            a[i][j]=k;
						            k++;
							        }
	}
}
void print(float a[rows][colums])
{
	for(i=0;i<rows;i++)
	{
		    for(j=0;j<colums;j++)
			        {
					     printf("%f\x20\x20",a[i][j]);
					         }
		        printf("\n");
	}
}
void add(float mat1[rows][colums],float mat2[rows][colums],float mat3[rows][colums])
{
	for(i=0;i<rows;i++)
	{
		    for(j=0;j<colums;j++)
			        {
					    mat3[i][j]=mat1[i][j]+mat2[i][j];       
					        }
	}
}
int main()
{
clock_t start,end;
start=clock();
read(b);
//print(b);
read(c);
//print(c);
add(b,c,d);
print(d);
end=clock();
double t=((double)end-start)/CLOCKS_PER_SEC;
printf("\n time=%f",t);
return 0;
}
