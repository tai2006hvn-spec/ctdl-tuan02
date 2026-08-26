function kadane_chi_so(a)
    n = length(a)
    max_sum = a[1]
    current_sum = a[1]
    best_start = 1
    best_end = 1
    temp_start = 1

    for i in 2:n
        if a[i] > current_sum + a[i]
            current_sum = a[i]
            temp_start = i
        else
            current_sum += a[i]
        end

        if current_sum > max_sum
            max_sum = current_sum
            best_start = temp_start
            best_end = i
        end
    end
    return max_sum, best_start, best_end
end

input_data = split(read(stdin, String))
if !isempty(input_data)
    n = parse(Int, input_data[1])
    a = [parse(Int, input_data[i]) for i in 2:(n+1)]
    tong, dau, cuoi = kadane_chi_so(a)
    println("tong $tong, doan [$dau..$cuoi]")
end