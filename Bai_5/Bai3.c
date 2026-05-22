//Name
//MSSV
//Class
//3. Heap sort, Quick sort, shell sort
#include <stdio.h>
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
void Heapify(double arr[], int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if(l < n && arr[l] > arr[largest]){
        largest = l;
    }
    if(r < n && arr[r] > arr[largest]){
        largest = r;
    }
    if(largest != i ){
        double temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        Heapify(arr, n, largest);
    }
    
}
void Heap_sort(double arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--) Heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        double temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        Heapify(arr, i, 0);
    }
}

int Partition(double arr[], int l, int r){
    int pivot = arr[r];
    int i = l - 1;
    for(int j = l; j < r; j++){
        if(arr[j] < pivot){
            double temp = arr[++i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    double temp = arr[++i];
    arr[i] = arr[r];
    arr[r] = temp;
    return i;
}
void Quick_sort(double arr[], int l, int r){
    if(l < r){
        int m = Partition(arr, l, r);
        Quick_sort(arr, l, m - 1);
        Quick_sort(arr, m + 1, r);
    }
}

void shellSort(double arr[], int n) {
    for (int i = n / 2; i > 0; i /= 2) {
        for (int j = i; j < n; j++) {
            
            int temp = arr[j];  
            int k = j;
            while (k >= i && arr[k - i] > temp) {
                arr[k] = arr[k - i];
                k -= i;
            }
            arr[k] = temp;
        }
    }
}
int main(){
    double *arr = Tao_mang();
    shellSort(arr,  n );
    printf("Mảng sau khi sắp xếp: ");
    display(arr);
    free(arr);
    return 0;
}