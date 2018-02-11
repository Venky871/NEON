#include<arm_neon.h>
#include<stdio.h>
static int i,j=0,a[2];
static int32x2_t mat_A[2],mat_B[2],mat_R[2];
void mat_read(int32x2_t *mat1,int vect_len,int no_vect)
{
	i=0;
	j=0;
 while(i<no_vect)
 {
 printf("enter vector %d\n",i);
  for(j=0;j<vect_len;j++)
  {
  scanf("%d\n",&a[j]);
  }
mat1[i]=vld1_s32(a);
 i++; 	 
 }	
 printf("\n");
}
void mat_print(int32x2_t *mat1,int vect_len,int no_vect)
{
printf("matrix elements are\n");
for(j=0;j<no_vect;j++)
{
printf("%d\x20\x20",vget_lane_s32(mat1[j],0));
}	
printf("\n");
for(j=0;j<no_vect;j++)
{
printf("%d\x20\x20",vget_lane_s32(mat1[j],1));
}
printf("\n");
}
void  mat_add(int32x2_t *mat3,int32x2_t *mat1,int32x2_t *mat2,int vect_len,int no_vect)
{
	i=0;
while(i<no_vect)
{
mat3[i]=vadd_s32(mat1[i],mat2[i]);
		i++;
		}	
printf("\n");
	}

	
int main()
{
mat_read(mat_A,2,2);	
mat_read(mat_B,2,2);
mat_print(mat_A,2,2);
mat_print(mat_B,2,2);
mat_R[0]=vmla_lane_s32(mat_R[0],mat_A[0],mat_B[0],0);
mat_R[0]=vmla_lane_s32(mat_R[0],mat_A[1],mat_B[0],1);
mat_R[1]=vmla_lane_s32(mat_R[1],mat_A[0],mat_B[1],0);
mat_R[1]=vmla_lane_s32(mat_R[1],mat_A[1],mat_B[1],1);
mat_print(mat_R,2,2);
// matresult = vadd_s8 (mat1[i],  mat2[j]);  
return 0;
}
