#include<stdio.h>
int bitStringA[15],bitStringB[15],bitStringUnion[15],bitStringIntersection[15],bitStringDifference[15],sizeA,sizeB;
void Initialize(){
        for(int i=0;i<15;i++){
                bitStringA[i]=0;
                bitStringB[i]=0;
                bitStringUnion[i]=0;
                bitStringIntersection[i]=0;
                bitStringDifference[i]=0;
        }      
}
void GenerateBitString(int arr[],int size,int bitArray[]){
        for(int i=0;i<size;i++){
                bitArray[arr[i]]=1;
        }

}
void printBitString(int arr[],int size){
       int nullCheck=0;
        for(int i=0;i<=size;i++){
                if(arr[i]==1){
                        printf("%d\t",i);
                        nullCheck=1;
                }
        }
        if(nullCheck==0){
                        printf("No data found");
                }
}

void Intersection(){
for(int i=0;i<=sizeA+sizeB;i++){
                bitStringIntersection[i]=bitStringA[i]&bitStringB[i];
        }
        printf("The Intersection of both BitStrings are \n");
        printBitString(bitStringIntersection,sizeA+sizeB);

}
void Difference(){
for(int i=0;i<=sizeA+sizeB;i++){
                bitStringDifference[i]=bitStringA[i]&(!bitStringB[i]);
        }    
        printf("The Difference of both BitStrings are \n");
        printBitString(bitStringDifference,sizeA+sizeB);

}
void Equivalency(){
for(int i=0;i<=sizeA;i++){
                if(bitStringA[i]!=bitStringB[i]){
                        printf("BitStrings are not equal\n");
                        return;
                }
        }
                printf("BitStrings are Equal");

}
void Union(){
        for(int i=0;i<=sizeA+sizeB;i++){
                bitStringUnion[i]=bitStringA[i]|bitStringB[i];
        }
        printf("The Union of both BitString is \n");
        printBitString(bitStringUnion,sizeA+sizeB);
}
void main(){
        printf("Enter the size of set A:");
        scanf("%d",&sizeA);
        printf("Enter the size of set B:");
        scanf("%d",&sizeB);
        int setA[sizeA],setB[sizeB];
        printf("Enter elements of set A:");
        for(int i=0;i<sizeA;i++)
                scanf("%d",&setA[i]);
        printf("Enter elements of set B:");
        for(int i=0;i<sizeB;i++)
                scanf("%d",&setB[i]);
        Initialize();
        GenerateBitString(setA,sizeA,bitStringA);
        GenerateBitString(setB,sizeB,bitStringB);
        int choice;
        while(choice!=5){
        printf("\n1.Union\n2.Intersection\n3.Difference\n4.Equivalency\n5.Exit\n");
        scanf("%d",&choice);
                switch(choice){
                        case 1:Union();
                                break;
                        case 2:Intersection();
                                break;
                        case 3:Difference();
                                break;
                        case 4:Equivalency();
                                break;
                        Default:printf("Exiting");
                                choice=5;
                                break;
                }
        }

}
