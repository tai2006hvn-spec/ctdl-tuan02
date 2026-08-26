function tich_lon_nhat(a)
    isempty(a) && return 0
    max_so_far = a[1]
    curr_max = a[1]
    curr_min = a[1]

    for i in 2:length(a)
        x = a[i]
        if x < 0
            curr_max, curr_min = curr_min, curr_max
        end
        curr_max = max(x, curr_max * x)
        curr_min = min(x, curr_min * x)
        max_so_far = max(max_so_far, curr_max)
    end
    return max_so_far
end

input_data = split(read(stdin, String))
if !isempty(input_data)
    n = parse(Int, input_data[1])
    a = [parse(Int, input_data[i]) for i in 2:(n+1)]
    println(tich_lon_nhat(a))
end
