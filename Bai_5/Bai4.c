//Name
//MSSV
//Class
//4. Counting sort
#include <stdio.h>
#include <stdlib.h>

int n;

int *Tao_mang(){
    printf("Nhập kích thước mảng: ");
    while(scanf("%d", &n) != 1 || n <= 0){
        printf("Nhập lại n: ");
        while(getchar() != '\n');
    }
    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) return NULL;
    for(int i = 0; i < n; i++){
        printf("Giá trị của arr[%d] = ", i);
        while(!scanf("%d", &arr[i])){ 
            printf("Nhập lại: ");
            while(getchar() != '\n');
        }    
    }
    return arr;
}

void display(int arr[]){
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void countsort(int arr[], int n) {
    if (n <= 1) return;
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    int range = max - min + 1;
    int *count = (int *)calloc(range, sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));

    if (count == NULL || output == NULL) return;
    for (int i = 0; i < n; i++) {
        count[arr[i] - min]++;
    }
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];}
    free(count);
    free(output);
}

int main(){
    int *arr = Tao_mang();
    if (arr == NULL) return 1;
    countsort(arr, n);
    printf("Mảng sau khi sắp xếp: ");
    display(arr);
    free(arr);
    return 0;
}