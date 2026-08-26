kc_euclid(u, v) = sqrt(sum((u .- v) .^ 2))
kc_manhattan(u, v) = sum(abs.(u .- v))

function lang_gieng_gan_nhat(q, D, kc, ten_do_do)
    min_dist = Inf
    best_index = -1
    best_label = ""
    
    for (idx, x, nhan) in D
        d = kc(q, x)
        if d < min_dist
            min_dist = d
            best_index = idx
            best_label = nhan
        end
    end
    println("$(ten_do_do): $(best_label) — mau $(best_index), khoang cach $(round(min_dist, digits=4))")
end

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
    println("$(ten_do_do) tong the: $(dung)/$(tong) = $(round(ti_le, digits=2))%$(sai_str)")
end

function kiem_tra_mau_26(D)
    target_id = 26
    idx_26 = findfirst(item -> item[1] == target_id, D)
    if idx_26 === nothing return end

    min_dist = Inf
    best_index = -1
    best_label = ""

    for j in 1:length(D)
        if j == idx_26 continue end
        d = kc_manhattan(D[idx_26][2], D[j][2])
        if d < min_dist
            min_dist = d
            best_index = D[j][1]
            best_label = D[j][3]
        end
    end
    println("Kiem tra mau 26 khi bi bo ra (Manhattan) -> Du doan: $(best_label) (lang gieng mau $(best_index), khoang cach $(round(min_dist, digits=1)))")
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
    D = doc_file("hoa30.txt")
    if isempty(D) return end

    println("--- 1. Mau moi (6.5; 3.0; 5.5; 2.0) ---")
    q = [6.5, 3.0, 5.5, 2.0]
    lang_gieng_gan_nhat(q, D, kc_euclid, "Euclid")
    lang_gieng_gan_nhat(q, D, kc_manhattan, "Manhattan")

    println("\n--- 2. Bo mot mau tren toan tap ---")
    bo_mot_mau(D, kc_euclid, "Euclid")
    bo_mot_mau(D, kc_manhattan, "Manhattan")

    println("\n--- 3. Truong hop mau 26 bi bo ra ---")
    kiem_tra_mau_26(D)
end

main()