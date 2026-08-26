import sys

def kadane_chi_so(a):
    n = len(a)
    max_sum = a[0]
    current_sum = a[0]
    best_start, best_end = 0, 0
    temp_start = 0

    for i in range(1, n):
        if a[i] > current_sum + a[i]:
            current_sum = a[i]
            temp_start = i
        else:
            current_sum += a[i]

        if current_sum > max_sum:
            max_sum = current_sum
            best_start = temp_start
            best_end = i

    # Đánh số từ 1
    return max_sum, best_start + 1, best_end + 1

if __name__ == "__main__":
    input_data = sys.stdin.read().split()
    if input_data:
        n = int(input_data[0])
        a = [int(x) for x in input_data[1:n+1]]
        tong, dau, cuoi = kadane_chi_so(a)
        print(f"tong {tong}, doan [{dau}..{cuoi}]")