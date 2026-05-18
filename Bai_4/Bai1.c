//Name
//MSSV
//Class
//1.Tìm kiếm 1 giá trị có trong mảng hay không, tìm min, max
#include<stdio.h>
#include<stdlib.h>

int n;
double *Tao_mang(){
    printf("Nhập kích thước mảng: ");
    while(scanf("%d", &n) != 1 || n < 0){
        printf("Nhập lại n: ");
        while(getchar() != '\n');
    }
    double *arr = malloc(n * sizeof(double));
    if (arr == NULL) return NULL;
    for(int i = 0; i < n; i++){
        printf("Giá trị của arr[%d] = ", i);
        while(!scanf("%lf", &arr[i])){
            printf("Nhập lại: ");
            while(getchar() != "\n");
        }    
    }
    return arr;
}

void Tim_Kiem(double arr[], int n){
    double k;
    printf("\nNhập số cần tìm: ");
    while(scanf("%lf", &k) != 1 || k < 0){
        printf("k không thuộc mảng.");
        break;
    }
    for(int i = 0; i < n; i++){
        if(arr[i] == k){
            printf("k ở vị trí %d trong mảng.", i);
        }
    }
    printf("k không thuộc mảng.");
}
void Tim_Kiem_Min(double arr[], int n){
    double min = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    printf("\nSố bé nhất của mảng là %lf", min);
}

void Tim_Kiem_Max(double arr[], int n){
    double max = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    printf("\nSố lớn nhất là: %lf", max);
}
int main(){

    double *arr = Tao_mang();

    Tim_Kiem(arr, n);
    Tim_Kiem_Min(arr, n);
    Tim_Kiem_Max(arr, n);

    printf("\n");
    return 0;
}