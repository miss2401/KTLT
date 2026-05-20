//Name
//MSSV
//Class
//4_2. Chương trình C sử dụng con trỏ để duyệt một mảng các số nguyên và in các giá trị theo thứ tự đảo ngược

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

int main(){
    double *arr = Tao_mang();
    double *end = arr + n - 1;
    while(end >= arr) printf("%lf ",*(end--));
    return 0;
}