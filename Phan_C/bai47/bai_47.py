import math
import sys

def main():
    try:
        with open("hoa30.txt", "r", encoding="utf-8") as f:
            lines = [line.strip() for line in f if line.strip()]
    except FileNotFoundError:
        return

    n, d = map(int, lines[0].split())
    tap_huan_luyen = []
    
    for i in range(1, n + 1):
        parts = lines[i].split()
        x = [float(val.replace(",", ".")) for val in parts[:d]]
        nhan = parts[d]
        tap_huan_luyen.append((i, x, nhan))

    q = []
    for line in sys.stdin:
        for val in line.split():
            q.append(float(val.replace(",", ".")))

    if not tap_huan_luyen or not q:
        return

    min_dist_sq = -1.0
    best_index = -1
    best_label = ""

    for idx, x, nhan in tap_huan_luyen:
        current_dist_sq = 0.0
        limit = min(len(q), len(x))
        for j in range(limit):
            diff = q[j] - x[j]
            current_dist_sq += diff * diff

        if min_dist_sq < 0 or current_dist_sq < min_dist_sq:
            min_dist_sq = current_dist_sq
            best_index = idx
            best_label = nhan

    final_dist = math.sqrt(min_dist_sq)
    print(f"{best_label} — mẫu {best_index}, khoảng cách {final_dist:.4f}")

if __name__ == "__main__":
    main()