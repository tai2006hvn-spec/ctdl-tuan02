import sys

def la_chinh_phuong(n: int) -> bool:
    if n < 0:
        return False
    l, r = 0, n
    while l <= r:
        mid = (l + r) // 2
        bp = mid * mid
        if bp == n:
            return True
        elif bp < n:
            l = mid + 1
        else:
            r = mid - 1
    return False

if __name__ == "__main__":
    input_data = sys.stdin.read().split()
    if input_data:
        n = int(input_data[0])
        if la_chinh_phuong(n):
            print("YES")
        else:
            print("NO")