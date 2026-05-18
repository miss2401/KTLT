//Name
//MSSV
//Class
#include<stdio.h>

int n;

void Tim_Kiem(double arr[], int n, double k){
    double k;
    printf("\n Nhap so can tim: ");
    while(scanf("%lf", &k) != 1 || k < 0){
        printf("k khong thuoc mang");
        break;
    }
    for(int i = 0; i < n; i++){
        if(arr[i] == k){
            printf("k nam o vi tri so %d trong mang.", i);
            return;
        }
    }
    printf("k khong thuoc mang.");
    return;
}

void Tim_Kiem_Min(double arr[], int n, double k){
    
    for(int i = 0; i < n; i++){
        if(arr[i] == k){
            printf("k = 3 nam o vi tri so %d trong mang.", i);
            return;
        }
    }
    printf("k khong thuoc mang.");
    return;
}

double *Tao_mang(){
    printf("Nhap kich thuoc mang: ");
    while(scanf("%d", &n) != 1 || n < 0){
        printf("Nhap lai n: ");
        while(getchar() != '\n');
    }
    double arr[n];
    for(int i = 0; i < n; i++){
        printf("\n");
        printf("Gia tri cua arr[%d] = ", i);
        scanf("%lf", &arr[i]);    
    }
    return arr;
}
int main(){

    double *arr = Tao_mang();
    Tim_Kiem(arr, n);

}