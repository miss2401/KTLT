# Name:
# MSSV:
# Class:

# 1. Thực hành đệ quy qua cài đặt các bài toán sau

def fibonacci(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    return fibonacci(n - 1) + fibonacci(n - 2)

def handle_fibonacci():
    print("\n1. TÍNH SỐ FIBONACCI F(n)")
    n = int(input("Nhập n (n >= 0): "))
    print(f"Số Fibonacci F({n}) là: {fibonacci(n)}")

def check_vi_tri_hau(vi_tri_cac_hau, hang_hien_tai, cot_dang_xet):
    for hang_truoc in range(hang_hien_tai):
        cot_cua_hang_truoc = vi_tri_cac_hau[hang_truoc]
        if cot_cua_hang_truoc == cot_dang_xet or \
           abs(cot_cua_hang_truoc - cot_dang_xet) == abs(hang_truoc - hang_hien_tai):
            return False
    return True

def de_quy_n_hau(n, hang, vi_tri_cac_hau, cac_cach_xep):
    if hang == n:
        cac_cach_xep.append(list(vi_tri_cac_hau))
        return
    for cot in range(n):
        if check_vi_tri_hau(vi_tri_cac_hau, hang, cot):
            vi_tri_cac_hau[hang] = cot  
            de_quy_n_hau(n, hang + 1, vi_tri_cac_hau, cac_cach_xep) 

def handle_n_queens():
    print("\n2. BÀI TOÁN N HẬU ")
    n = int(input("Nhập số quân hậu N: "))
    vi_tri_cac_hau = [-1] * n
    cac_cach_xep = []
    
    de_quy_n_hau(n, 0, vi_tri_cac_hau, cac_cach_xep)
    
    print(f"Tìm thấy tổng cộng {len(cac_cach_xep)} cách xếp!")
    for idx, cach in enumerate(cac_cach_xep, 1):
        print(f" Cách {idx}: {cach} (Vị trí cột của mỗi hậu từ hàng 0 đến {n-1})")

def thap_ha_noi(n, coc_goc, coc_trung_gian, coc_dich):
    if n == 1:
        print(f" Di chuyển đĩa 1 từ cọc {coc_goc} sang cọc {coc_dich}")
        return
    thap_ha_noi(n - 1, coc_goc, coc_dich, coc_trung_gian)
    print(f" Di chuyển đĩa {n} từ cọc {coc_goc} sang cọc {coc_dich}")
    thap_ha_noi(n - 1, coc_trung_gian, coc_goc, coc_dich)

def handle_towers_of_hanoi():
    print("\n3. BÀI TOÁN THÁP HÀ NỘI")
    n = int(input("Nhập số lượng đĩa: "))
    thap_ha_noi(n, 'A', 'B', 'C')

_X_MA = [2, 1, -1, -2, -2, -1, 1, 2]
_Y_MA = [1, 2, 2, 1, -1, -2, -2, -1]

def hop_le_ma_di_tuan(x, y, ban_co, n):
    return 0 <= x < n and 0 <= y < n and ban_co[x][y] == -1

def de_quy_ma_di_tuan(n, x, y, so_buoc, ban_co):
    if so_buoc == n * n:
        return True
    for i in range(8):
        next_x = x + _X_MA[i]
        next_y = y + _Y_MA[i]
        if hop_le_ma_di_tuan(next_x, next_y, ban_co, n):
            ban_co[next_x][next_y] = so_buoc
            if de_quy_ma_di_tuan(n, next_x, next_y, so_buoc + 1, ban_co):
                return True
            ban_co[next_x][next_y] = -1 
            
    return False

def handle_knights_tour():
    print("\n4. BÀI TOÁN MÃ ĐI TUẦN ")
    n = int(input("Nhập kích thước bàn cờ: "))
    ban_co = [[-1 for _ in range(n)] for _ in range(n)]

    ban_co[0][0] = 0

    if de_quy_ma_di_tuan(n, 0, 0, 1, ban_co):
        for hang in ban_co:
            print("\t".join(f"{o:2d}" for o in hang))
    else:
        print("Không có lời giải.")

def liet_ke_hoan_vi(mang_goc, vi_tri_bat_dau, ket_qua):
    if vi_tri_bat_dau == len(mang_goc):
        ket_qua.append(list(mang_goc))
        return
    
    for i in range(vi_tri_bat_dau, len(mang_goc)):
        mang_goc[vi_tri_bat_dau], mang_goc[i] = mang_goc[i], mang_goc[vi_tri_bat_dau]
        liet_ke_hoan_vi(mang_goc, vi_tri_bat_dau + 1, ket_qua)    
        mang_goc[vi_tri_bat_dau], mang_goc[i] = mang_goc[i], mang_goc[vi_tri_bat_dau]

def handle_permutations():
    print("\n5. BÀI TOÁN LIỆT KÊ HOÁN VỊ")
    chuoi_vao = input(" ")
    mang_goc = chuoi_vao.split()
    
    cac_hoan_vi = []
    liet_ke_hoan_vi(mang_goc, 0, cac_hoan_vi)
    
    print(f"Tổng số hoán vị liệt kê được là: {len(cac_hoan_vi)}")
    for hv in cac_hoan_vi:
        print(" ", hv)

def main():
    while True:
        print("1. Tính số Fibonacci F(n)")
        print("2. Bài toán N hậu")
        print("3. Bài toán tháp Hà Nội")
        print("4. Bài toán mã đi tuần")
        print("5. Bài toán liệt kê hoán vị")
        print("0. Thoát chương trình")

        lua_chon = int(input("Chọn bài toán muốn chạy thử (0-5): "))
        if lua_chon == 0:
            break
        elif lua_chon == 1:
            handle_fibonacci()
        elif lua_chon == 2:
            handle_n_queens()
        elif lua_chon == 3:
            handle_towers_of_hanoi()
        elif lua_chon == 4:
            handle_knights_tour()
        elif lua_chon == 5:
            handle_permutations()

main()