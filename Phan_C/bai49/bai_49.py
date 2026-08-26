import math

def kc_euclid(u, v):
    return math.sqrt(sum((a - b) ** 2 for a, b in zip(u, v)))

def kc_manhattan(u, v):
    return sum(abs(a - b) for a, b in zip(u, v))

def bo_mot_mau(D, kc, ten_do_do):
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
    print(f"{ten_do_do}: {dung}/{tong} = {ti_le:.2f}%{sai_str}")

def doc_file(filename):
    try:
        with open(filename, "r", encoding="utf-8") as f:
            lines = [line.strip() for line in f if line.strip()]
    except FileNotFoundError:
        return []
    if not lines:
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
    # 1 & 2. Chạy trên hoa30.txt
    D30 = doc_file("hoa30.txt")
    if D30:
        bo_mot_mau(D30, kc_euclid, "Euclid")
        bo_mot_mau(D30, kc_manhattan, "Manhattan")
        
    # 3. Chạy trên hoa9.txt
    D9 = doc_file("hoa9.txt")
    if D9:
        bo_mot_mau(D9, kc_euclid, "Tap 9 mau - Euclid")
        bo_mot_mau(D9, kc_manhattan, "Tap 9 mau - Manhattan")

if __name__ == "__main__":
    main()