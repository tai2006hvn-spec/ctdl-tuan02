import math
import sys

D = [
    ([1.4, 0.2], "Setosa"),
    ([1.4, 0.1], "Setosa"),
    ([1.3, 0.2], "Setosa"),
    ([4.7, 1.4], "Versicolor"),
    ([4.5, 1.5], "Versicolor"),
    ([4.9, 1.5], "Versicolor"),
    ([5.9, 2.2], "Virginica"),
    ([6.9, 2.1], "Virginica"),
    ([5.8, 2.2], "Virginica")
]

def lang_gieng_gan_nhat(q, D):
    min_dist_sq = float('inf')
    best_label = ""
    best_index = -1
    
    for i, (x, y) in enumerate(D):
        dist_sq = sum((q[j] - x[j]) ** 2 for j in range(len(q)))
        if dist_sq < min_dist_sq:
            min_dist_sq = dist_sq
            best_label = y
            best_index = i + 1
            
    actual_dist = math.sqrt(min_dist_sq)
    return best_label, actual_dist, best_index

if __name__ == "__main__":
    q = [float(val) for val in sys.stdin.readline().strip().split()]
    if q:
        label, dist, index = lang_gieng_gan_nhat(q, D)
        if dist < 1e-9:
            print(f"{label} — trùng đúng mẫu {index}, khoảng cách 0")
        else:
            fmt = ".1f" if dist < 1 else ".4f"
            print(f"{label} — láng giềng là mẫu {index}, khoảng cách {format(dist, fmt)}")