//Name
//MSSV
//Class
//2.Merge Sort

#include<stdio.h>

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

void Merge(double arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    double A[n1], B[n2];
    for(int i = 0; i < n1; i++){
        A[i] = arr[l + 1];
    }
    for(int i = 0; i < n2; i++){
        B[i] = arr[m + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if( A[i] < B[j]) arr[l++] = A[i++];
        else arr[l++] = B[j++];
    } 
    while(i < n1) arr[l++] = A[i++];
    while(j < n2) arr[l++] = B[j++];
}

void Merge_Sort(double arr[], int l, int r){
    if(l < r){
        int m = l + (r - l) /  2;
        Merge_Sort(arr, l, m);
        Merge_Sort(arr, m + 1, r);
        Merge(arr, l, m, r);
    }
}
int main(){
    double *arr = Tao_mang();
    Merge_Sort(arr, 0, n - 1);
    printf("Mảng sau khi sắp xếp: ");
    display(arr);
    free(arr);
    return 0;
}