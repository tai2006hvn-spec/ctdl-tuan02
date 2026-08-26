import sys

def giai_thua(n: int) -> int:
    kq = 1
    for i in range(1, n + 1):
        kq *= i
    return kq

if __name__ == "__main__":
    input_data = sys.stdin.read().split()
    if input_data:
        n = int(input_data[0])
        # Nguong gioi han LLONG_MAX cua C++ de mo phỏng kiem tra tran so
        LLONG_MAX = 9223372036854775807
        kq = giai_thua(n)
        if kq > LLONG_MAX:
            print(f"TRAN SO ({n}! = {kq} > {LLONG_MAX})")
        else:
            print(kq)