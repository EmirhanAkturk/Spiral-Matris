#include<stdio.h>
void printList(int n,int arr[][n]){
    printf("\n");
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)
        {   
            printf("%d\t",arr[i][j]);
        }   
        printf("\n");
    }
    printf("\n");
}
int main(){
    
    int n;
    printf("Spiral matris boyutunu giriniz:");
    scanf("%d",&n);

    int arr[n][n];

    for(int i=0;i<n;++i){ //<3
        for(int j=0;j<n;++j)
        {   
            arr[j][i]=0;
        }    
    }

    int sayac=1;
    int i;
    int satır=0;
    int sutun=0;
    int asagiSol=1;

    for(int k=n;k>0;--k){
        if(k==n){
            for(i=sutun;i<sutun+k;++i){
                arr[satır][i]=sayac;
                ++sayac;
                printList(n,arr);
            }
            sutun=i-1;
        }

        else{
            if(asagiSol==1)//asagı ve sola
            {   //printf("e:%d ,satır:%d,sutun:%d,k:%d\n",e%2,satır,sutun,k);
                
                for(i=satır+1;i<=satır+k;++i){//asagı
                    arr[i][sutun]=sayac;
                    ++sayac;
                    printList(n,arr);
                }
                satır=i-1;
                //printf("e:%d ,satır:%d,sutun:%d\n",e%2,satır,sutun);
                
                for(i=sutun-1;i>=sutun-k;--i){//sola
                    arr[satır][i]=sayac;
                    ++sayac;
                    printList(n,arr);
                }
                sutun=i+1;
                asagiSol=0;
            }
            
            else{//yukarı ve saga

                for(i=satır-1;i>=satır-k;--i){//yukarı
                    arr[i][sutun]=sayac;
                    ++sayac;
                    printList(n,arr);
                }
                satır=i+1;
                for(i=sutun+1;i<=sutun+k;++i){//sağa
                    arr[satır][i]=sayac;
                    ++sayac;
                    printList(n,arr);
                }
                sutun=i-1;
                asagiSol=1;
            }
        }
    }

    printf("son hali:\n");
    printList(n,arr);
    return 0;
}