#include<arm_neon.h>
#include<stdio.h>
int main()
{
 int8x8_t matresult;
   int8x8_t mat1 ;
   int8x8_t mat2 ;
   int i ;int8_t a[8];
   int result ;
   printf("enter vector1\n");
   for(i=0;i<8;i++)
   {
     scanf("%d\n",&a[i]);
   }
   mat1= vld1_s8(a);
   printf("enter vector 2\n");
   for(i=0;i<8;i++)
   {
scanf("%d\n",&a[i]);
   }
   mat2=vld1_s8(a);
   printf("Contents of mat1:   ");
   printf("%d ", vget_lane_s8(mat1,0));
   printf("%d ", vget_lane_s8(mat1,1));
   printf("%d ", vget_lane_s8(mat1,2));
   printf("%d ", vget_lane_s8(mat1,3));
   printf("%d ", vget_lane_s8(mat1,4));
   printf("%d ", vget_lane_s8(mat1,5));
   printf("%d ", vget_lane_s8(mat1,6));
   printf("%d ", vget_lane_s8(mat1,7));
   printf("\n");

   printf("Contents of mat2:   ");
   printf("%d ", vget_lane_s8(mat2,0));
   printf("%d ", vget_lane_s8(mat2,1));
   printf("%d ", vget_lane_s8(mat2,2));
   printf("%d ", vget_lane_s8(mat2,3));
   printf("%d ", vget_lane_s8(mat2,4));
   printf("%d ", vget_lane_s8(mat2,5));
   printf("%d ", vget_lane_s8(mat2,6));
   printf("%d ", vget_lane_s8(mat2,7));
   printf("\n");
   matresult = vadd_s8 (mat1,  mat2);
   printf("Result of Addition: ");
   printf("%d ", vget_lane_s8(matresult,0));
   printf("%d ", vget_lane_s8(matresult,1));
   printf("%d ", vget_lane_s8(matresult,2));
   printf("%d ", vget_lane_s8(matresult,3));
   printf("%d ", vget_lane_s8(matresult,4));
   printf("%d ", vget_lane_s8(matresult,5));
   printf("%d ", vget_lane_s8(matresult,6));
   printf("%d ", vget_lane_s8(matresult,7));
   printf("\n");
   vst1_s8(a,matresult);
   for(i=0;i<8;i++)
   {
   printf("%d\x20\x20",a[i]);	
   }   
return 0;
}
