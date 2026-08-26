kc_euclid(u, v) = sqrt(sum((u .- v) .^ 2))
kc_manhattan(u, v) = sum(abs.(u .- v))

function bo_mot_mau(D, kc, ten_do_do)
    dung = 0
    tong = length(D)
    danh_sach_sai = Int[]
    
    for i in 1:tong
        min_dist = Inf
        best_label = ""
        for j in 1:tong
            if i == j continue end
            d = kc(D[i][2], D[j][2])
            if d < min_dist
                min_dist = d
                best_label = D[j][3]
            end
        end
        if best_label == D[i][3]
            dung += 1
        else
            push!(danh_sach_sai, D[i][1])
        end
    end
    ti_le = dung / tong * 100.0
    sai_str = isempty(danh_sach_sai) ? " — khong mau nao sai" : " — sai mau: $(danh_sach_sai)"
    println("$(ten_do_do): $(dung)/$(tong) = $(round(ti_le, digits=2))%$(sai_str)")
end

function doc_file(filename)
    if !isfile(filename) return [] end
    lines = readlines(filename)
    filtered = filter(l -> !isempty(strip(l)), lines)
    if isempty(filtered) return [] end

    header = split(filtered[1])
    n = parse(Int, header[1])
    d = parse(Int, header[2])

    D = []
    for i in 2:(n+1)
        parts = split(filtered[i])
        x = parse.(Float64, replace.(parts[1:d], "," => "."))
        nhan = String(parts[d+1])
        push!(D, (i - 1, x, nhan))
    end
    return D
end

function main()
    # 1 & 2. Chạy trên hoa30.txt
    D30 = doc_file("hoa30.txt")
    if !isempty(D30)
        bo_mot_mau(D30, kc_euclid, "Euclid")
        bo_mot_mau(D30, kc_manhattan, "Manhattan")
    end

    # 3. Chạy trên hoa9.txt
    D9 = doc_file("hoa9.txt")
    if !isempty(D9)
        bo_mot_mau(D9, kc_euclid, "Tap 9 mau - Euclid")
        bo_mot_mau(D9, kc_manhattan, "Tap 9 mau - Manhattan")
    end
end

main()