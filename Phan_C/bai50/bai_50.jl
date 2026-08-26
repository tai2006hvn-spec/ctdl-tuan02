using Random
using Printf

function generate_data(n::Int, d::Int, seed::Int)
    Random.seed!(seed)
    return rand(Float64, d, n)
end

function classify(query::Vector{Float64}, train::Matrix{Float64}, d::Int, n::Int)
    min_dist = Inf
    best_idx = -1
    for i in 1:n
        dist = 0.0
        for j in 1:d
            diff = query[j] - train[j, i]
            dist += diff * diff
        end
        if dist < min_dist
            min_dist = dist
            best_idx = i
        end
    end
    return best_idx
end

function main()
    d = 20
    q = 1000
    n_sizes = [1000, 10000, 100000]
    
    queries = generate_data(q, d, 12345)
    
    # JIT warm-up
    train_warmup = generate_data(10, d, 1)
    classify(queries[:, 1], train_warmup, d, 10)
    
    times = Float64[]
    for n in n_sizes
        train = generate_data(n, d, 54321)
        
        t = @elapsed for i in 1:q
            classify(queries[:, i], train, d, n)
        end
        push!(times, t)
    end
    
    ratio1 = times[2] / times[1]
    ratio2 = times[3] / times[2]
    
    @printf("T(10k)/T(1k) = %.2f ; T(100k)/T(10k) = %.2f\n", ratio1, ratio2)
    @printf("n=10^3: %.4fs | n=10^4: %.4fs | n=10^5: %.4fs\n", times[1], times[2], times[3])
end

main()