import math
import sys

# Đảm bảo in tiếng Việt có dấu đúng trên console
if sys.platform == "win32":
    sys.stdout.reconfigure(encoding='utf-8')

def kc_euclid(u, v):
    return math.sqrt(sum((a - b) ** 2 for a, b in zip(u, v)))

def kc_manhattan(u, v):
    return sum(abs(a - b) for a, b in zip(u, v))

def lang_gieng_gan_nhat(q, D, kc=kc_euclid, ten_do_do="Euclid"):
    min_dist = float('inf')
    best_index = -1
    best_label = ""
    
    for idx, x, nhan in D:
        d = kc(q, x)
        if d < min_dist:
            min_dist = d
            best_index = idx
            best_label = nhan
            
    print(f"{ten_do_do}: {best_label} — mau {best_index}, khoang cach {min_dist:.4f}")

def bo_mot_mau(D, kc=kc_euclid, ten_do_do="Euclid"):
    dung = 0
    tong = len(D)
    danh_sach_sai = []
    
    for i in range(tong):
        min_dist = float('inf')
        best_label = ""
        for j in range(tong):
            if i == j:
                continue
            d = kc(D[i][1], D[j][1])
            if d < min_dist:
                min_dist = d
                best_label = D[j][2]
        
        if best_label == D[i][2]:
            dung += 1
        else:
            danh_sach_sai.append(D[i][0])
            
    ti_le = dung / tong * 100.0
    sai_str = f" — sai mau: {danh_sach_sai}" if danh_sach_sai else " — khong mau nao sai"
    print(f"{ten_do_do} tong the: {dung}/{tong} = {ti_le:.2f}%{sai_str}")

def kiem_tra_mau_26(D):
    target_id = 26
    idx_26 = next((i for i, item in enumerate(D) if item[0] == target_id), -1)
    if idx_26 == -1:
        return

    min_dist = float('inf')
    best_index = -1
    best_label = ""

    for j in range(len(D)):
        if j == idx_26:
            continue
        d = kc_manhattan(D[idx_26][1], D[j][1])
        if d < min_dist:
            min_dist = d
            best_index = D[j][0]
            best_label = D[j][2]
            
    print(f"Kiem tra mau 26 khi bi bo ra (Manhattan) -> Du doan: {best_label} (lang gieng mau {best_index}, khoang cach {min_dist:.1f})")

def doc_file(filename):
    try:
        with open(filename, "r", encoding="utf-8") as f:
            lines = [line.strip() for line in f if line.strip()]
    except FileNotFoundError:
        print(f"Khong tim thay tep {filename}!")
        return []
    
    n, d = map(int, lines[0].split())
    D = []
    for i in range(1, n + 1):
        parts = lines[i].split()
        x = [float(val.replace(",", ".")) for val in parts[:d]]
        nhan = parts[d]
        D.append((i, x, nhan))
    return D

def main():
    D = doc_file("hoa30.txt")
    if not D:
        return

    print("--- 1. Mau moi (6.5; 3.0; 5.5; 2.0) ---")
    q = [6.5, 3.0, 5.5, 2.0]
    lang_gieng_gan_nhat(q, D, kc_euclid, "Euclid")
    lang_gieng_gan_nhat(q, D, kc_manhattan, "Manhattan")

    print("\n--- 2. Bo mot mau tren toan tap ---")
    bo_mot_mau(D, kc_euclid, "Euclid")
    bo_mot_mau(D, kc_manhattan, "Manhattan")

    print("\n--- 3. Truong hop mau 26 bi bo ra ---")
    kiem_tra_mau_26(D)

if __name__ == "__main__":
    main()