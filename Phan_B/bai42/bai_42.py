import sys
import time
import random

def cua_so_ngay_tho(a, k):
    n = len(a)
    max_sum = -float('inf')
    best_idx = 1
    for i in range(n - k + 1):
        current_sum = sum(a[i:i+k])
        if current_sum > max_sum:
            max_sum = current_sum
            best_idx = i + 1
    return max_sum, best_idx

def cua_so_truot(a, k):
    n = len(a)
    if k > n or k <= 0:
        return 0, 1
    current_sum = sum(a[:k])
    max_sum = current_sum
    best_idx = 1

    for i in range(k, n):
        current_sum = current_sum + a[i] - a[i - k]
        if current_sum > max_sum:
            max_sum = current_sum
            best_idx = i - k + 2
    return max_sum, best_idx

if __name__ == "__main__":
    input_data = sys.stdin.read().split()
    if input_data:
        n = int(input_data[0])
        k = int(input_data[1])
        a = [int(x) for x in input_data[2:n+2]]

        if n >= 100000:
            print(f"--- BANG DO THOI GIAN PYTHON VỚI n = {n}, k = {k} ---")
            
            start1 = time.perf_counter()
            tong1, vt1 = cua_so_ngay_tho(a, k)
            end1 = time.perf_counter()
            t_ngay_tho = end1 - start1

            start2 = time.perf_counter()
            tong2, vt2 = cua_so_truot(a, k)
            end2 = time.perf_counter()
            t_truot = end2 - start2

            print(f"Cách ngây thơ O(n*k): {t_ngay_tho:.4f}s (Kết quả: {tong1})")
            print(f"Cửa sổ trượt O(n)   : {t_truot:.4f}s (Kết quả: {tong2})")
            if t_truot > 0:
                print(f"Số lần nhanh hơn    : ~{t_ngay_tho / t_truot:.1f} lần")
        else:
            tong, vi_tri = cua_so_truot(a, k)
            print(f"tong {tong}, bat dau tai vi tri {vi_tri}")