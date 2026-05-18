//Name
//MSSV
//Class
#include<stdio.h>
#include<stdlib.h>

int n;

void Tim_Kiem(double arr[], int n){
    double k;
    printf("\nNhap so can tim: ");
    while(scanf("%lf", &k) != 1 || k < 0){
        printf("k khong thuoc mang");
        break;
    }
    for(int i = 0; i < n; i++){
        if(arr[i] == k){
            printf("k nam o vi tri so %d trong mang.", i);
        }
    }
    printf("k khong thuoc mang.");
}
void Tim_Kiem_Min(double arr[], int n){
    double min = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    printf("\nSo be nhat cua mang la: %lf", min);
    return;
}

double *Tao_mang(){
    printf("Nhap kich thuoc mang: ");
    while(scanf("%d", &n) != 1 || n < 0){
        printf("Nhap lai n: ");
        while(getchar() != '\n');
    }
    double *arr = malloc(n * sizeof(double));
    if (arr == NULL) return NULL;
    for(int i = 0; i < n; i++){
        printf("\n");
        printf("Gia tri cua arr[%d] = ", i);
        while(!scanf("%lf", &arr[i])){
            printf("Gia tri khong hop le: ");
            while(getchar() != "\n");
        }    
    }
    return arr;
}
int main(){

    double *arr = Tao_mang();
    Tim_Kiem(arr, n);
    Tim_Kiem_Min(arr, n);
    printf("\n");
}