using Printf

const D = [
    ([1.4, 0.2], "Setosa"),
    ([1.4, 0.1], "Setosa"),
    ([1.3, 0.2], "Setosa"),
    ([4.7, 1.4], "Versicolor"),
    ([4.5, 1.5], "Versicolor"),
    ([4.9, 1.5], "Versicolor"),
    ([5.9, 2.2], "Virginica"),
    ([6.9, 2.1], "Virginica"),
    ([5.8, 2.2], "Virginica")
]

function lang_gieng_gan_nhat(q, D)
    min_dist_sq = Inf
    best_label = ""
    best_index = -1
    
    for (i, (x, y)) in enumerate(D)
        dist_sq = sum((q .- x) .^ 2)
        if dist_sq < min_dist_sq
            min_dist_sq = dist_sq
            best_label = y
            best_index = i
        end
    end
    
    actual_dist = sqrt(min_dist_sq)
    return best_label, actual_dist, best_index
end

if abspath(PROGRAM_FILE) == @__FILE__
    input_line = readline(stdin)
    if !isempty(strip(input_line))
        q = parse.(Float64, split(input_line))
        label, dist, index = lang_gieng_gan_nhat(q, D)
        
        if dist < 1e-9
            println("$label — trùng đúng mẫu $index, khoảng cách 0")
        else
            if dist < 1
                @printf("%s — láng giềng là mẫu %d, khoảng cách %.1f\n", label, index, dist)
            else
                @printf("%s — láng giềng là mẫu %d, khoảng cách %.4f\n", label, index, dist)
            end
        end
    end
end