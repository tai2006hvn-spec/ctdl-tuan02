function phan_tich(n::Int128)
    so_chu_so = Int128(0)
    tong_chu_so = Int128(0)
    if n == 0
        return (1, 0)
    end
    while n > 0
        tong_chu_so += n % 10
        so_chu_so += 1
        n = div(n, 10)
    end
    return (so_chu_so, tong_chu_so)
end

function main()
    input_data = split(read(stdin, String))
    if isempty(input_data)
        return
    end
    n = parse(Int128, input_data[1])
    so_chu_so, tong_chu_so = phan_tich(n)
    println("$so_chu_so $tong_chu_so")
end

main()