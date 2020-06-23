#include <stdio.h>
#include<stdlib.h>

// void Multiply(int arr1[][],int row1,int column1, int arr2[][],int row2, int column2){
//     if(row1!=column2||row2!=column1){
//         printf("bad-matrices\n");
//         return;
//     }
//     int arr3[row1][column2];
//     for(int i=0;i<row1;i++){
//         for(int j=0;j<column2;j++){
//             arr3[i][j]=0;
//             for(int k=0;k<column1;k++){
//                 arr3[i][j]+=arr1[i][k]*arr2[k][j];
//             }
//         }
//     }

//     for(int i=0;i<row1;i++){
//         for(int j=0;j<column2;j++){
//             printf("%d\t",arr3[i][j]);
//         }
//             printf("\n");
//     }
// }