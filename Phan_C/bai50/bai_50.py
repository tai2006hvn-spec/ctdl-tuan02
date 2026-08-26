import random
import time

def generate_data(n, d, seed):
    random.seed(seed)
    return [[random.random() for _ in range(d)] for _ in range(n)]

def classify(query, train_data, d):
    best_dist = float('inf')
    best_idx = -1
    for i, train_sample in enumerate(train_data):
        dist = 0.0
        for k in range(d):
            diff = query[k] - train_sample[k]
            dist += diff * diff
        if dist < best_dist:
            best_dist = dist
            best_idx = i
    return best_idx

def main():
    d = 20
    q = 1000
    n_sizes = [1000, 10000, 100000]
    
    queries = generate_data(q, d, 12345)
    times = []
    
    for n in n_sizes:
        train = generate_data(n, d, 54321)
        
        t0 = time.perf_counter()
        for query in queries:
            classify(query, train, d)
        t = time.perf_counter() - t0
        times.append(t)
        
    ratio1 = times[1] / times[0]
    ratio2 = times[2] / times[1]
    
    print(f"T(10k)/T(1k) = {ratio1:.2f} ; T(100k)/T(10k) = {ratio2:.2f}")
    print(f"n=10^3: {times[0]:.2f}s | n=10^4: {times[1]:.2f}s | n=10^5: {times[2]:.2f}s")

if __name__ == "__main__":
    main()