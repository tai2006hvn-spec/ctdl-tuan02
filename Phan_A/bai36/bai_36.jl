function giai_thua(n::Int)
    LLONG_MAX = 9223372036854775807
    kq = BigInt(1)
    for i in 1:n
        kq *= i
    end
    if kq > LLONG_MAX
        # Dùng $(n)! để Julia không bị nhầm lẫn với hàm n!
        println("TRAN SO ($(n)! = $kq > $LLONG_MAX)")
    else
        println(Int(kq))
    end
end

input_data = split(read(stdin, String))
if !isempty(input_data)
    n = parse(Int, input_data[1])
    giai_thua(n)
end