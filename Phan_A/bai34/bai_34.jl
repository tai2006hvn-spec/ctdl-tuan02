function dao_nguoc(n::Int128)::Int128
    sign = n < 0 ? -1 : 1
    temp = abs(n)
    rev = Int128(0)
    while temp > 0
        rev = rev * 10 + temp % 10
        temp = div(temp, 10)
    end
    return rev * sign
end

function main()
    input_data = split(read(stdin, String))
    if isempty(input_data)
        return
    end
    n = parse(Int128, input_data[1])
    println(dao_nguoc(n))
end

main()