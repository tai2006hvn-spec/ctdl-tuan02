function cua_so_ngay_tho(a, k)
    n = length(a)
    max_sum = -typemax(Int128)
    best_idx = 1
    for i in 1:(n - k + 1)
        current_sum = sum(a[i:(i+k-1)])
        if current_sum > max_sum
            max_sum = current_sum
            best_idx = i
        end
    end
    return max_sum, best_idx
end

function cua_so_truot(a, k)
    n = length(a)
    (k > n || k <= 0) && return 0, 1
    current_sum = sum(a[1:k])
    max_sum = current_sum
    best_idx = 1

    for i in (k+1):n
        current_sum = current_sum + a[i] - a[i - k]
        if current_sum > max_sum
            max_sum = current_sum
            best_idx = i - k + 1
        end
    end
    return max_sum, best_idx
end

input_data = split(read(stdin, String))
if !isempty(input_data)
    n = parse(Int, input_data[1])
    k = parse(Int, input_data[2])
    a = [parse(Int, input_data[i]) for i in 3:(n+2)]

    if n >= 100000
        println("--- BANG DO THOI GIAN JULIA VỚI n = $n, k = $k ---")
        
        t_ngay_tho = @elapsed tong1, vt1 = cua_so_ngay_tho(a, k)
        t_truot = @elapsed tong2, vt2 = cua_so_truot(a, k)

        println("Cách ngây thơ O(n*k): $(t_ngay_tho)s (Kết quả: $tong1)")
        println("Cửa sổ trượt O(n)   : $(t_truot)s (Kết quả: $tong2)")
        println("Số lần nhanh hơn    : ~$(t_ngay_tho / t_truot) lần")
    else
        tong, vi_tri = cua_so_truot(a, k)
        println("tong $tong, bat dau tai vi tri $vi_tri")
    end
end