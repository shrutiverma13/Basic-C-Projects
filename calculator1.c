#include<stdio.h>
 #include<math.h>
 #define PI 3.14159265
 #define C 100
 float sine(float x);
 float cosine(float x);
 float tangent(float x);
 float exponent(float x);
 float logb10(float x);
 float logb2(float x);
 float power(float x, float y);
 float fmodu(float x, float y);
 float cosec(float x);
 float sec(float x);
 float cot(float x);
 void readMatrix(float a[][C], int rows, int cols){

     printf("Give values row-wise setup. by space = ");

       for(int i=0;i<rows;i++){
       for(int j=0;j<cols;j++)
       scanf("%f", &a[i][j]);
     }
         return;
     }
       void printMatrix(float a[][C], int rows, int cols) {
       for (int i=0; i<rows; i++){
         for (int j=0; j<cols; j++)
           printf("%.2f ",a[i][j]);
          printf("\n");
       }
       return;
       }
       void eliminate(float a[][C], int mat)
       {
         for (int row=0; row<mat; row++)
         {
           for (int i=row+1; i<mat; i++)
           {
             if (a[row][row]==0.0)
             {
               int k;
               for (k=row+1; k<mat; k++)
               if (a[k][row]!=0)
                 break;
               float temp;
               for (int col=row; col<mat; col++)
               {
                 temp=a[row][col];
                 a[row][col]=a[k][col];
                 a[k][col]=temp;
               }
             }
             float c=-a[i][row]/a[row][row];
             a[i][row]=0.0;
             for (int j=row+1; j<mat; j++)
               a[i][j]+=c*a[row][j];
           }
         }
         return;
       }

       void detmat(float a[][C], int mat, float m)
       {
         m=1;
         for (int i=0; i<mat; i++)
           m*=a[i][i];
         printf(" %.2f\n",m);
         return;
       }
       void backsubstitute(float a[][C], float x[], int n) {
         for (int row=n-1; row>-1; row--) {
           float sum=0;
           for (int j=row+1; j<n; j++)
             sum+=x[j]*a[row][j];
           x[row]=(a[row][n]-sum)/a[row][row];
         }
         return;
       }
int main()
{
  int n;
  float x,y,z;
  do
  {
  printf ("\nMENU\n1.ADDITION\n2.SUBTRACTION\n3.MULTIPLICATION\n4.DIVISION\n");
  printf("5.SIN\n6.COS\n7.TAN\n8.EXP\n9.LOG10\n10.LOG2\n11.X^Y\n12.FMOD\n");
  printf ("13.SQUARE ROOT(X)\n14.X^1/Y\n15.X!\n16.MATRIX DETERMINANT\n");
  printf("17.SOLUTION OF LINEAR EQUATIONS\n");
  printf("18.COSEC\n19.SEC\n20.COT\n21.X^2\n22.EXIT\n");
  printf("Enter your choice:\n");
  scanf("%d", &n);
if(n==1){
  printf("X + Y\n");
  printf("Enter x and y: ");
  scanf("%f %f", &x,&y);
  z = x + y;
  printf("%f", z);
}
else if(n==2){
  printf("X - Y\n");
  printf("Enter x and y: ");
  scanf("%f %f", &x,&y);
  z = x - y;
  printf("%f", z);
}
else if(n==3){
  printf("X * Y\n");
  printf("Enter x and y: ");
  scanf("%f %f", &x,&y);
  z = x * y;
  printf("%f", z);
}
else if(n==4){
  printf("x / y");
  printf("Enter x and y: ");
  scanf("%f %f", &x,&y);
  z = x / y;
  printf("%f", z);
}
else if(n==5)
{
  printf("Enter the degree:\n");
  scanf("%f", &x);
  z=sine(x);
  printf("sin(%.2f) = %.2f\n",x,z);
}

else  if(n==6)
{
  printf("Enter the degree:\n");
  scanf("%f", &x);
  z=cosine(x);
  printf("cos(%.2f) = %.2f\n",x,z);
}

  else  if(n==7)
{
  printf("Enter the degree:\n");
  scanf("%f", &x);
  z=tangent(x);
  printf("tan(%.2f) = %.2f\n",x,z);
}

   else if(n==8)
{
  printf("Enter the power of e:\n");
  scanf("%f", &x);
  z=exponent(x);
  printf("e^(%.2f) = %.2f\n",x,z);

}
 else  if(n==9)
{
  printf("Enter the number to find log10:\n");
  scanf("%f", &x);
  z=logb10(x);
  printf("logb10(%.2f) = %.2f\n",x,z);
}

 else if(n==10)
{
  printf("Enter the number to find log2:\n");
  scanf("%f", &x);
  z=logb2(x);
  printf("log2(%.2f) = %.2f\n",x,z);
}

  else   if(n==11)
{
  printf("Enter the base:\n");
  scanf("%f", &x);
  printf("Enter the exponent:\n");
  scanf("%f", &y);
  z=power(x,y);
  printf("%.2fd^%.2f = %.2f\n", x,y,z);
}

   else  if(n==12)
{
  printf("Enter the number:\n");
  scanf("%f", &x);
  printf("Enter the modulor:\n");
  scanf("%f", &y);
  z=fmodu(x,y);
  printf("The floating point remainder of %.2f / %.2f = %.2f\n",x,y,z);
   }
   else if(n==13){
     printf("Enter X: ");
     scanf("%f", &x);
     z = sqrt(x);
     printf("\n%f \n\n", z);
   }
   else if(n==14){
     printf("Enter x: ");
     scanf("%f", &x);
     printf("Enter y: ");
     scanf("%f", &y);
     z =  pow(x, (1/y));
     printf("\n%f \n", z);
   }
   else if(n==15){
     printf("Enter x: ");
     scanf("%f", &x);
     z = 1;
     for(int i=1;i<= x;i++){
       z=z*i;
     }
     printf("\n%f \n", z);
   }
   else if(n==16){
     float a[C][C], m;
     int rows,cols,mat;
     printf("Matrix operation for printing and finding the determinant ");
     printf("\ngive the number of rows  = ");
     scanf("%d", &rows);
     printf("\ngive the number of cols  = ");
     scanf("%d", &cols);
     if(rows*cols<0 || rows*cols==0){
         printf("illilgal input of rows or cols is < %d or 0", C);
         return 0;
     }
     if(rows<0 && cols<0){
       printf("your rows and cols are not defined give valid inputs");
       return 0;
}
       if(rows==cols){
         mat=rows=cols;
       }
       if(rows!=cols){
         printf("There is no determinant for your marix");
       }


     readMatrix(a,rows,cols);
     printf("\nMatrix is \n"); printMatrix(a,rows,cols);
     eliminate(a,mat);
     printf("\nDeterminant of your matrix");
     detmat(a,mat,m);
   }
   else if(n==17){
     float a[C][C], x[C];
     int n;//no. of unknowns
     printf("Give no. of unknowns = ");
     scanf("%d", &n);
     printf ("Give the coefficients and RHS row-wise sep. by white space\n");
     for (int i=0; i<n; i++)
       for (int j=0; j<=n; j++)
         scanf("%f", &a[i][j]);
     eliminate(a, n);
     printf("\nArray after elimination\n");
     printMatrix(a, n, n);
     backsubstitute(a, x, n);
     printf("\nLinear eqn. solns after backsubstitution\n");
     for (int i=0; i<n; i++) {
       printf("x%d = %.2f\n", i+1, x[i]);
     }
   }
  else if(n==18){
    printf("Enter the degree:\n");
    scanf("%f", &x);
    z=cosec(x);
    printf("cosec(%.2f) = %.2f\n",x,z);
  }
  else if(n==19){
    printf("Enter the degree:\n");
    scanf("%f", &x);
    z=sec(x);
    printf("sec(%.2f) = %.2f\n",x,z);
  }
  else if(n==20){
    printf("Enter the degree:\n");
    scanf("%f", &x);
    z=cot(x);
    printf("cot(%.2f) = %.2f\n",x,z);
  }
  else if(n==21){
    printf("Enter the base:\n");
    scanf("%f", &x);
    z=power(x,2);
    printf("%.2f^2 = %.2f\n", x,z);
  }
}while(n!=22 || n >22);
   return 0;
  }

  float sine(float x)
  {
  return sin(x*PI/180);
  }
  float cosec(float x)
  {
    return (1/sin(x*PI/180));
  }
  float cosine(float x)
   {
   return cos(x*PI/180);
    }
  float sec(float x)
  {
    return (1/cos(x*PI/180));
  }
    float tangent(float x)
   {
    return tan(x*PI/180);
    }
    float cot(float x)
    {
      return (1/tan(x*PI/180));
    }

     float exponent(float x)
    {
  return exp(x);
    }

   float logb10(float x)
     {
  return log10(x);
   }

    float logb2(float x)
    {
    return log2(x);
    }

    float power(float x, float y)
     {
    return pow(x,y);
    }

    float fmodu(float x, float y)
     {
     return fmod(x,y);
      }
