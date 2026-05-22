//Name
//MSSV
//Class
//1. Insertion sort, Selection sort, Bubble sort
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
            while(getchar() != '\n');
        }    
    }
    return arr;
}
void display(double arr[]){
    for(int i = 0; i < n; i++) printf("%lf ", arr[i]);
}

void InsertSort(double arr[]){
    for(int i = 1; i < n; i++){
        int j = i;
        while(j > 0 && arr[j] < arr[j - 1]){
            double temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j--] = temp;
        }
    }
}

void Selection_sort(double arr[]){
    for(int i = 0; i < n - 1; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min])min = j;
        }
        double temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void Bubble_sort(double arr[]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main(){
    double *arr = Tao_mang();
    //Selection_sort(arr);
    Bubble_sort(arr);
    printf("Mảng sau khi sắp xếp: ");
    display(arr);
    return 0;
}