#include "fourth.h"

int main(int argc,char** argv){
    FILE * fp=fopen(argv[1],"r");


    int column1=0,row1=0,column2=0,row2=0;

    fscanf(fp,"%d\t%d\n",&row1,&column1);
    int arr1[row1][column1];
    for(int i=0;i<row1;i++){
        for(int j=0;j<column1;j++){
            fscanf(fp,"%d",&arr1[i][j]);
        }
    }

    fscanf(fp,"%d\t%d\n",&row2,&column2);
    int arr2[row2][column2];
    for(int i=0;i<row2;i++){
        for(int j=0;j<column2;j++){
            fscanf(fp,"%d",&arr2[i][j]);
        }
    }
    // Multiply(arr1,row1,column1,arr2,row2,column2);

    if(row2!=column1){
        printf("bad-matrices\n");
        return 0;
    }
    int arr3[row1][column2];
    for(int i=0;i<row1;i++){
        for(int j=0;j<column2;j++){
            arr3[i][j]=0;
            for(int k=0;k<column1;k++){
                arr3[i][j]+=arr1[i][k]*arr2[k][j];
            }
        }
    }

    for(int i=0;i<row1;i++){
        for(int j=0;j<column2;j++){
            printf("%d\t",arr3[i][j]);
        }
            printf("\n");
    }
    return 0;
}