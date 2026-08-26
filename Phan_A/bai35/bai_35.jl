function la_nguyen_to(x::Int)::Bool
    if x < 2
        return false
    end
    i = 2
    while i * i <= x
        if x % i == 0
            return false
        end
        i += 1
    end
    return true
end

function dem_va_tong_kiem_tra_tung_so(n::Int)
    dem = Int128(0)
    tong = Int128(0)
    for i in 2:n
        if la_nguyen_to(i)
            dem += 1
            tong += i
        end
    end
    return (dem, tong)
end

function sang_eratosthenes(n::Int)
    if n < 2
        return (Int128(0), Int128(0))
    end
    is_prime = trues(n)
    is_prime[1] = false
    p = 2
    while p * p <= n
        if is_prime[p]
            for i in (p * p):p:n
                is_prime[i] = false
            end
        end
        p += 1
    end
    dem = Int128(0)
    tong = Int128(0)
    for i in 2:n
        if is_prime[i]
            dem += 1
            tong += i
        end
    end
    return (dem, tong)
end

function main()
    mode = length(ARGS) > 0 ? parse(Int, ARGS[1]) : 2
    input_data = split(read(stdin, String))
    if isempty(input_data)
        return
    end
    n = parse(Int, input_data[1])
    if n <= 30
        primes = [i for i in 2:n if la_nguyen_to(i)]
        println(join(primes, " "))
    else
        dem, tong = mode == 1 ? dem_va_tong_kiem_tra_tung_so(n) : sang_eratosthenes(n)
        if n >= 1000000
            println("so luong = $dem, tong = $tong")
        else
            println("so luong = $dem")
        end
    end
end

main()