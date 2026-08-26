function la_chinh_phuong(n::Int128)::Bool
    if n < 0
        return false
    end
    l = Int128(0)
    r = n
    while l <= r
        mid = div(l + r, 2)
        bp = mid * mid
        if bp == n
            return true
        elseif bp < n
            l = mid + 1
        else
            r = mid - 1
        end
    end
    return false
end

function main()
    input_data = split(read(stdin, String))
    if isempty(input_data)
        return
    end
    n = parse(Int128, input_data[1])
    if la_chinh_phuong(n)
        println("YES")
    else
        println("NO")
    end
end

main()