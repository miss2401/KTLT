//Name
//MSSV
//Class
//2.Tìm kiếm 1 giá trị trong mảng đã được sắp xếp tăng dần (tìm kiếm nhị phân)
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
        while(!scanf("%lf", &arr[i]) || (i > 0 && arr[i] < arr[i - 1])){
            printf("Nhập lại: ");
            while(getchar() != '\n');
        }    
    }
    return arr;
}
void Binary_Search(double arr[], int l, int r, double k){
    if(l < r){
        int m = l + (r - l) / 2;
        if(arr[m] == k){
            printf("Số cần tìm là %lf ở vị trí %d.", k, m);
            return;
        }
        if(arr[m] < k ) l = m ;
        if(arr[m] > k) r = m - 1;
        Binary_Search(arr, l, r, k);
    }
}
int main(){
    
    double *arr = Tao_mang();
    double k;
    printf("\nNhập số cần tìm: ");
    while(scanf("%lf", &k) != 1 || k < 0){
        printf("k không thuộc mảng.");
        break;
    }
    Binary_Search(arr, 0, n - 1, k);
    free(arr);
    return 0;

}