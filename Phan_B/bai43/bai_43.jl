const DEM = Ref{Int}(0)

function fib_de_quy(n)
    DEM[] += 1
    n <= 2 && return 1
    return fib_de_quy(n - 1) + fib_de_quy(n - 2)
end

function fib_ghi_nho(n, memo = Dict{Int, Int}())
    n <= 2 && return 1
    haskey(memo, n) && return memo[n]
    memo[n] = fib_ghi_nho(n - 1, memo) + fib_ghi_nho(n - 2, memo)
    return memo[n]
end

function fib_lap(n)
    n <= 2 && return 1
    a = Int128(1)
    b = Int128(1)
    c = Int128(1)
    for i in 3:n
        c = a + b
        a = b
        b = c
    end
    return c
end

input_data = split(read(stdin, String))
if !isempty(input_data)
    n = parse(Int, input_data[1])
    if n >= 93
        println("tran long long -- phai phat hien va bao")
    else
        f_val = fib_lap(n)
        if n <= 30
            DEM[] = 0
            fib_de_quy(n)
            println("F = $f_val, so loi goi = $(DEM[])")
        else
            so_loi_goi = 2 * f_val - 1
            println("F = $f_val, so loi goi = $so_loi_goi")
        end
    end
end