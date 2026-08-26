function main()
    lines = readlines("hoa30.txt")
    filtered = filter(l -> !isempty(strip(l)), lines)
    if isempty(filtered) return end

    header = split(filtered[1])
    n = parse(Int, header[1])
    d = parse(Int, header[2])

    tap_huan_luyen = []
    for i in 2:(n+1)
        parts = split(filtered[i])
        x = parse.(Float64, replace.(parts[1:d], "," => "."))
        nhan = String(parts[d+1])
        push!(tap_huan_luyen, (i - 1, x, nhan))
    end

    input_data = read(stdin, String)
    q = parse.(Float64, split(replace(input_data, "," => ".")))

    if isempty(tap_huan_luyen) || isempty(q) return end

    min_dist_sq = -1.0
    best_index = -1
    best_label = ""

    for (idx, x, nhan) in tap_huan_luyen
        current_dist_sq = 0.0
        limit = min(length(q), length(x))
        for j in 1:limit
            diff = q[j] - x[j]
            current_dist_sq += diff * diff
        end

        if min_dist_sq < 0 || current_dist_sq < min_dist_sq
            min_dist_sq = current_dist_sq
            best_index = idx
            best_label = nhan
        end
    end

    final_dist = sqrt(min_dist_sq)
    println("$(best_label) — mẫu $(best_index), khoảng cách $(round(final_dist, digits=4))")
end

main()