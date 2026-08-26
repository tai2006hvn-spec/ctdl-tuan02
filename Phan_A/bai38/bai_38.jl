function da_sap_xep(a, nghiem_ngat=false)
    n = length(a)
    for i in 1:(n - 1)
        if nghiem_ngat
            if a[i] >= a[i+1]
                return false
            end
        else
            if a[i] > a[i+1]
                return false
            end
        end
    end
    return true
end

input_data = split(read(stdin, String))
if !isempty(input_data)
    n = parse(Int, input_data[1])
    a = [parse(Int, input_data[i]) for i in 2:(n+1)]
    nn = da_sap_xep(a, true)
    kg = da_sap_xep(a, false)
    nn_str = nn ? "YES" : "NO"
    kg_str = kg ? "YES" : "NO"
    println("nghiem ngat: $nn_str — khong giam: $kg_str")
end