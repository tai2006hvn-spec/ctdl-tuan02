import sys

def da_sap_xep(a, nghiem_ngat=False) -> bool:
    n = len(a)
    for i in range(n - 1):
        if nghiem_ngat:
            if a[i] >= a[i + 1]:
                return False
        else:
            if a[i] > a[i + 1]:
                return False
    return True

if __name__ == "__main__":
    input_data = sys.stdin.read().split()
    if input_data:
        n = int(input_data[0])
        a = [int(x) for x in input_data[1:n+1]]
        nn = da_sap_xep(a, nghiem_ngat=True)
        kg = da_sap_xep(a, nghiem_ngat=False)
        print(f"nghiem ngat: {'YES' if nn else 'NO'} — khong giam: {'YES' if kg else 'NO'}")