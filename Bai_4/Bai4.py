#Name
#MSSV
#Class
#4.Liệt kê các số có số lần xuất hiện nhiều nhất trong mảng

n = int(input('Nhập kích thước mảng: '))
arr = []
for i in range(n):
    arr.append(int(input(f"Giá trị của arr[{i}] là: ")))
print("\n",arr)
table = dict()
dem = 1
for i in arr:
    if i not in table:
        table[i] = 1
    else:
        table[i] += 1
        if(table[i] > dem):
            dem = table[i]
print(table)
for u,v in table.items():
    if v == dem:
        print(f"{u} xuất hiện nhiều nhất với số lần là {v}")
        
