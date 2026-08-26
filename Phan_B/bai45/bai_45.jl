function luy_thua_mod(a::Int, b::Int, m::Int)
    if m == 1
        return 0
    end
    r = Int128(1) % m
    base = Int128(a) % m
    exp = Int128(b)
    mod_val = Int128(m)
    
    while exp > 0
        if exp % 2 == 1
            r = (r * base) % mod_val
        end
        base = (base * base) % mod_val
        exp ÷= 2
    end
    return Int(r)
end

input_data = strip(read(stdin, String))
if !isempty(input_data)
    parts = parse.(Int, split(input_data))
    if length(parts) >= 3
        a, b, m = parts[1], parts[2], parts[3]
        actual = luy_thua_mod(a, b, m)
        println("Ket qua: $actual")
    end
end