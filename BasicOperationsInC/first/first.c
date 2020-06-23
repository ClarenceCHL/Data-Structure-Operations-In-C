#include "first.h"

int main(int argc,char** argv){

    FILE* fp = fopen(argv[1],"r");
    // Cannot read the file
    if(strcmp(argv[1],"")==0||fp==NULL){
        return 0;
    }

    int count = 0;
    fscanf(fp,"%d",&count);
    if(count == 0){
        return 0;
    }

    int arrayOdd[count],arrayEven[count];
    int oddNum=0,evenNum = 0;
    int num;
    while(fscanf(fp,"%d",&num)!=EOF){
        if(num%2!=0){
            arrayOdd[oddNum]=num;
            oddNum++;
        }else{
            arrayEven[evenNum]=num;
            evenNum++;
        }
    }

    // sort the Even numbers in ascending order
    for(int i=0;i<evenNum-1;i++){
        int minindex=i;
        for(int j=i+1;j<evenNum;j++){
            if(arrayEven[minindex]>arrayEven[j]){
                minindex=j;
            }
        }
        int t= arrayEven[i];
        arrayEven[i]=arrayEven[minindex];
        arrayEven[minindex]=t;
    }
    
    // sort the odd numbers in decending order
    for(int i=0;i<oddNum-1;i++){
        int maxindex=i;
        for(int j=i+1;j<oddNum;j++){
            if(arrayOdd[maxindex]<arrayOdd[j]){
                maxindex=j;
            }
        }
        int t= arrayOdd[i];
        arrayOdd[i]=arrayOdd[maxindex];
        arrayOdd[maxindex]=t;
    }

    for(int i=0;i<evenNum;i++){
        printf("%d\t",arrayEven[i]);
    }
    for(int i=0;i<oddNum;i++){
        printf("%d\t",arrayOdd[i]);
    }
    printf("\n");
    fclose(fp);
    return 0;
}