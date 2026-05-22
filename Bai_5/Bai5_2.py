# Name:
# MSSV:
# Class:
#1. Xây dựng chương trình chồng toán tử cho số phức, vecto, ma trận

class SoPhuc:
    def __init__(self, thuc=0.0, ao=0.0):
        self.thuc = thuc
        self.ao = ao

    def __str__(self):
        dau = "+" if self.ao >= 0 else "-"
        return f"{self.thuc} {dau} {abs(self.ao)}i"

    def __add__(self, khac):
        return SoPhuc(self.thuc + khac.thuc, self.ao + khac.ao)

    def __sub__(self, khac):
        return SoPhuc(self.thuc - khac.thuc, self.ao - khac.ao)

    def __mul__(self, khac):
        r = self.thuc * khac.thuc - self.ao * khac.ao
        i = self.thuc * khac.ao + self.ao * khac.thuc
        return SoPhuc(r, i)

    def nhap():
        thuc = float(input("   Nhập phần thực: "))
        ao = float(input("   Nhập phần ảo: "))
        return SoPhuc(thuc, ao)

class Vector:
    def __init__(self, n):
        self.n = n
        self.phan_tu = [0.0] * n  

    def __str__(self):
        return "(" + ", ".join(map(str, self.phan_tu)) + ")"

    def __add__(self, khac):
        if self.n != khac.n:
            raise ValueError("Kích thước hai vector phải bằng nhau!")
        kq = Vector(self.n)
        for i in range(self.n):
            kq.phan_tu[i] = self.phan_tu[i] + khac.phan_tu[i]
        return kq

    def __sub__(self, khac):
        if self.n != khac.n:
            raise ValueError("Kích thước hai vector phải bằng nhau!")
        kq = Vector(self.n)
        for i in range(self.n):
            kq.phan_tu[i] = self.phan_tu[i] - khac.phan_tu[i]
        return kq
    def nhap(self):
        for i in range(self.n):
            self.phan_tu[i] = float(input(f"   Thành phần [{i}]: "))

class MaTran:
    def __init__(self, hang, cot):
        self.hang = hang
        self.cot = cot
        self.data = [[0.0 for _ in range(cot)] for _ in range(hang)]
    def __str__(self):
        ket_qua = ""
        for i in range(self.hang):
            ket_qua += "\t".join(map(str, self.data[i])) + "\n"
        return ket_qua
    def __add__(self, khac):
        if self.hang != khac.hang or self.cot != khac.cot:
            raise ValueError("Kích thước hai ma trận phải bằng nhau!")
        kq = MaTran(self.hang, self.cot)
        for i in range(self.hang):
            for j in range(self.cot):
                kq.data[i][j] = self.data[i][j] + khac.data[i][j]
        return kq
    def __mul__(self, khac):
        if self.cot != khac.hang:
            raise ValueError("Số cột ma trận 1 phải bằng số hàng ma trận 2!")
        kq = MaTran(self.hang, khac.cot)
        for i in range(self.hang):
            for j in range(khac.cot):
                for k in range(self.cot):
                    kq.data[i][j] += self.data[i][k] * khac.data[k][j]
        return kq

    # Hàm nhập ma trận
    def nhap(self):
        for i in range(self.hang):
            for j in range(self.cot):
                self.data[i][j] = float(input(f"   Phần tử [{i}][{j}]: "))

def main():
    print(" SỐ PHỨC ")
    print("Nhập số phức 1:")
    sp1 = SoPhuc.nhap()
    print("Nhập số phức 2:")
    sp2 = SoPhuc.nhap()
    print(f"-> Tổng (sp1 + sp2): {sp1 + sp2}")
    print(f"-> Tích (sp1 * sp2): {sp1 * sp2}\n")

    print(" VECTOR ")
    kthuoc_v = int(input("Nhập kích thước cho các vector: "))
    v1 = Vector(kthuoc_v)
    v2 = Vector(kthuoc_v)
    print("Nhập Vector 1:")
    v1.nhap()
    print("Nhập Vector 2:")
    v2.nhap()
    print(f"-> Hiệu (v1 - v2) = {v1 - v2}\n")

    # 3. Thử nghiệm Ma Trận
    print(" MA TRẬN ")
    h = int(input("Nhập số hàng của ma trận: "))
    c = int(input("Nhập số cột của ma trận: "))
    mt1 = MaTran(h, c)
    mt2 = MaTran(h, c)
    print("Nhập Ma Trận 1:")
    mt1.nhap()
    print("Nhập Ma Trận 2:")
    mt2.nhap()
    print("-> Tổng hai Ma trận (mt1 + mt2) là:\n" + str(mt1 + mt2))

main()