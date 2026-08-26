import time
import random

try:
    import matplotlib.pyplot as plt
    HAS_MATPLOTLIB = True
except ImportError:
    HAS_MATPLOTLIB = False

def thuat_toan_o_n2(a):
    n = len(a)
    max_sum = -float('inf')
    for i in range(n):
        current_sum = 0
        for j in range(i, n):
            current_sum += a[j]
            if current_sum > max_sum:
                max_sum = current_sum
    return max_sum

def do_thoi_gian(n, lap=3):
    a = [random.randint(-50, 50) for _ in range(n)]
    min_time = float('inf')
    for _ in range(lap):
        t0 = time.perf_counter()
        thuat_toan_o_n2(a)
        t1 = time.perf_counter()
        giay = t1 - t0
        if giay < min_time:
            min_time = giay
    return min_time

if __name__ == "__main__":
    moc_ns = [500, 1000, 2000, 4000]
    ket_qua = []
    
    print("Dang do thoi gian chay cho cac moc n...")
    for n in moc_ns:
        t = do_thoi_gian(n)
        ket_qua.append(t)

    print("\n=== BANG 1: KET QUA KIEM CHUNG TI LE ===")
    r1 = ket_qua[1] / ket_qua[0]
    r2 = ket_qua[2] / ket_qua[1]
    r3 = ket_qua[3] / ket_qua[2]
    print(f"n = 500 -> 1000  | ti le ~ {r1:.2f}")
    print(f"n = 1000 -> 2000 | ti le ~ {r2:.2f}")
    print(f"n = 2000 -> 4000 | ti le ~ {r3:.2f}\n")

    print("=== BANG 2: BANG DO THOI GIAN O(n^2) ===")
    print("Ngon ngu\tn = 500\t\tn = 1000\tn = 2000\tn = 4000\t\tTi le cuoi")
    print(f"Python\t\t{ket_qua[0]:.4f}s\t{ket_qua[1]:.4f}s\t{ket_qua[2]:.4f}s\t{ket_qua[3]:.4f}s\t\t~{r3:.2f}\n")

    if HAS_MATPLOTLIB:
        plt.figure(figsize=(7.5, 4))
        plt.plot(moc_ns, ket_qua, marker='o', color='#1f77b4', linestyle='-', linewidth=2.5, markersize=6, label='Thuật toán O(n^2)')
        plt.xlabel('Kích thước đầu vào (n)', fontsize=11, fontweight='bold')
        plt.ylabel('Thời gian chạy T(n) (giây)', fontsize=11, fontweight='bold')
        plt.title('Đồ thị biểu diễn thời gian thực thi thuật toán O(n^2)(python)', fontsize=12, fontweight='bold', pad=12)
        plt.grid(True, linestyle='--', alpha=0.6)
        plt.legend(loc='upper left')
        plt.savefig('do_thi_O_n2.png', dpi=300, bbox_inches='tight')
        print("=> Đã tự động tạo và lưu thành công file ảnh đồ thị: do_thi_O_n2.png")
    else:
        print("=> Thư viện matplotlib chưa được cài đặt. Hãy chạy lệnh 'pip install matplotlib' nếu muốn tự động tạo ảnh đồ thị.")