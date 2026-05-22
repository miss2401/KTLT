//Name
//MSSV
//Class
//3. Heap sort
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
int main(){
    double *arr = Tao_mang();
    Heap_sort(arr, n);
    printf("Mảng sau khi sắp xếp: ");
    display(arr);
    free(arr);
    return 0;
}