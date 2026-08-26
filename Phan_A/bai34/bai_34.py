import sys

def dao_nguoc(n: int) -> int:
    sign = -1 if n < 0 else 1
    temp = abs(n)
    rev = 0
    while temp > 0:
        rev = rev * 10 + temp % 10
        temp //= 10
    return rev * sign

if __name__ == "__main__":
    input_data = sys.stdin.read().split()
    if input_data:
        n = int(input_data[0])
        print(dao_nguoc(n))