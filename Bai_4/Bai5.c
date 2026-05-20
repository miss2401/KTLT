//Name
//MSSV
//Class
//5. Thực hiện các phép toán của vecto và ma trận (+, -, tích) qua hàm

#include <stdio.h>       
#include <stdlib.h>

double *Tao_vecto(int *size) {
    printf("Nhap kich thuoc vector: ");
    scanf("%d", size);
    double *arr = malloc(sizeof(double) * (*size));
    if (!arr) return NULL;
    for (int i = 0; i < *size; i++) {
        printf("  arr[%d] = ", i);
        scanf("%lf", &arr[i]);
    }
    return arr;
}

void Cong_vecto(double *a, double *b, int m) {
    printf("Tong 2 vecto: ");
    for (int i = 0; i < m; i++)      
        printf("%.2lf ", a[i] + b[i]);
    printf("\n");
}
void Tru_vecto(double *a, double *b, int m) {
    printf("Hieu 2 vecto: ");
    for (int i = 0; i < m; i++)       
        printf("%.2lf ", a[i] - b[i]);   
    printf("\n");
}

void Tich_vecto(double *a, double *b, int m) {
    double c = 0;
    for (int i = 0; i < m; i++)  
        c += a[i] * b[i];
    printf("Tich vo huong: %.2lf\n", c);
}

double *Tao_ma_tran(int *rows, int *cols) {
    printf("Nhap kich thuoc (dong cot): ");
    scanf("%d %d", rows, cols);
    double *arr = malloc(sizeof(double) * (*rows) * (*cols));
    if (!arr) return NULL;
    for (int i = 0; i < *rows; i++)
        for (int j = 0; j < *cols; j++) {
            printf("  A[%d][%d] = ", i, j);
            scanf("%lf", &arr[i * (*cols) + j]);  
        }
    return arr;
}

void In_ma_tran(double *A, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printf("  ");
        for (int j = 0; j < cols; j++)
            printf("%8.2lf", A[i * cols + j]);
        printf("\n");
    }
}

void Cong_ma_tran(double *A, double *B, int rows, int cols) {
    printf("Tong A + B:\n");
    for (int i = 0; i < rows; i++) {
        printf("  ");
        for (int j = 0; j < cols; j++)
            printf("%8.2lf", A[i*cols+j] + B[i*cols+j]);  
        printf("\n");
    }
}

void Tru_ma_tran(double *A, double *B, int rows, int cols) {
    printf("Hieu A - B:\n");
    for (int i = 0; i < rows; i++) {
        printf("  ");
        for (int j = 0; j < cols; j++)
            printf("%8.2lf", A[i*cols+j] - B[i*cols+j]); 
        printf("\n");
    }
}
void Tich_ma_tran(double *A, int rA, int cA,
                  double *B, int rB, int cB) {
    if (cA != rB) {
        printf("Khong the nhan: so cot A (%d) != so dong B (%d)\n", cA, rB);
        return;
    }
    double *C = calloc(rA * cB, sizeof(double));
    for (int i = 0; i < rA; i++)
        for (int j = 0; j < cB; j++)
            for (int k = 0; k < cA; k++)
                C[i*cB + j] += A[i*cA + k] * B[k*cB + j];
    printf("Tich A * B (%dx%d):\n", rA, cB);
    In_ma_tran(C, rA, cB);
    free(C);
}

int main() {
    int k;
    printf("Nhap 1 (vecto) hoac 2 (ma tran): ");
    scanf("%d", &k);

    if (k == 1) {
        int m;
        double *a = Tao_vecto(&m);   
        double *b = Tao_vecto(&m);
        Cong_vecto(a, b, m);         
        Tru_vecto(a, b, m);
        Tich_vecto(a, b, m);
        free(a); free(b);
    } else {
        int rA, cA, rB, cB;
        double *A = Tao_ma_tran(&rA, &cA);
        double *B = Tao_ma_tran(&rB, &cB);

        if (rA == rB && cA == cB) {
            Cong_ma_tran(A, B, rA, cA);
            Tru_ma_tran(A, B, rA, cA);
        } else printf("Khong the cong/tru: A(%dx%d) va B(%dx%d) khac kich thuoc\n",rA, cA, rB, cB);
        Tich_ma_tran(A, rA, cA, B, rB, cB); 
        free(A); free(B);
    }
    return 0;
}