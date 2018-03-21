#include<arm_neon.h>
#include<stdio.h>
#include<time.h>
# define rows 1000
# define colums 500 
static int i,j=0,k;
static float32_t l,a[2];
static float32x2_t mat_A[rows][colums],mat_B[rows][colums],mat_R[rows][colums];
void mat_read(float32x2_t *mat1,int vect_len,int no_vect,float32_t start_value)
{
		i=0;
			j=0;
			 while(i<no_vect)
				  {
					   //printf("enter vector %d\n",i);
					     for(j=0;j<vect_len;j++)
						       {
							         a[j]=start_value;
							         start_value++;
								   }
					     mat1[i]=vld1_f32(a);
					      i++; 	 
					       }	
			  printf("\n");
}
void mat_print(float32x2_t *mat1,int vect_len,int no_vect)
{
	//printf("matrix elements are\n");
	for(j=0;j<no_vect;j++)
	{
		printf("%f\x20\x20",vget_lane_f32(mat1[j],0));
		printf("%f\x20\x20",vget_lane_f32(mat1[j],1));
	}	
	
}
void  mat_add(float32x2_t *mat3,float32x2_t *mat1,float32x2_t *mat2,int vect_len,int no_vect)
{
		i=0;
		while(i<no_vect)
		{
			mat3[i]=vadd_f32(mat1[i],mat2[i]);
					i++;
							}	
		printf("\n");
			}

	
int main()
{
	clock_t start,end;
	start=clock();
	for(k=0,l=1.0;k<rows;k++)
	{
	mat_read(mat_A[k],2,colums,l);
	l=l+0;	
     }
     for(k=0,l=1.0;k<rows;k++)
{     
	mat_read(mat_B[k],2,colums,l);
	l=l+0;
}

/*for(k=0;k<rows;k++)
{
	mat_print(mat_A[k],2,colums);
}
for(k=0;k<rows;k++)
{
	mat_print(mat_B[k],2,colums);
}*/
for(k=0;k<rows;k++)
{
	mat_add(mat_R[k],mat_A[k],mat_B[k],2,colums);
}
for(k=0;k<rows;k++)
{
	mat_print(mat_R[k],2,colums);
}
end=clock();
double t=((double)(end-start))/CLOCKS_PER_SEC;
printf("\ntime=%f",t);	
return 0;
	 }
	
