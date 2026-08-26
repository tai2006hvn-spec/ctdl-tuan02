import sys

def luy_thua_mod(a: int, b: int, m: int) -> int:
    if m == 1:
        return 0
    r = 1 % m
    a %= m
    while b > 0:
        if b % 2 == 1:
            r = (r * a) % m
        a = (a * a) % m
        b //= 2
    return r

if __name__ == "__main__":
    input_data = sys.stdin.read().strip()
    if input_data:
        parts = input_data.split()
        if len(parts) >= 3:
            a, b, m = int(parts[0]), int(parts[1]), int(parts[2])
            actual = luy_thua_mod(a, b, m)
            print(f"Ket qua: {actual}")