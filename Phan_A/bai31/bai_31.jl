using Printf

function main()
    input_data = split(read(stdin, String))
    if isempty(input_data)
        return
    end
    n = parse(Int, input_data[1])
    a = [parse(Int, x) for x in input_data[2:n+1]]
    
    tong = sum(a)
    trung_binh = tong / n
    nho_nhat = minimum(a)
    lon_nhat = maximum(a)
    
    @printf("%d %.4f %d %d\n", tong, trung_binh, nho_nhat, lon_nhat)
end

main()