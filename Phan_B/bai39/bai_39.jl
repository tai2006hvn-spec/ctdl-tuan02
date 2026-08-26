function cach1(a)
    n = length(a)
    max_sum = -typemax(Int128)
    for i in 1:n
        for j in i:n
            s = sum(a[i:j])
            if s > max_sum; max_sum = s; end
        end
    end
    return max_sum
end

function cach2(a)
    n = length(a)
    max_sum = -typemax(Int128)
    for i in 1:n
        s = 0
        for j in i:n
            s += a[j]
            if s > max_sum; max_sum = s; end
        end
    end
    return max_sum
end

function kadane(a)
    max_sum = a[1]
    current_sum = a[1]
    for i in 2:length(a)
        current_sum = max(a[i], current_sum + a[i])
        max_sum = max(max_sum, current_sum)
    end
    return max_sum
end

input_data = split(read(stdin, String))
if !isempty(input_data)
    n = parse(Int, input_data[1])
    a = [parse(Int, input_data[i]) for i in 2:(n+1)]

    t1 = @elapsed r1 = cach1(a)
    println("Cach 1 time: $(t1)s (Ket qua: $r1)")

    t2 = @elapsed r2 = cach2(a)
    println("Cach 2 time: $(t2)s (Ket qua: $r2)")

    t3 = @elapsed r3 = kadane(a)
    println("Cach 3 time: $(t3)s (Ket qua: $r3)")
end