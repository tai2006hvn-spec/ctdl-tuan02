using Random

function thuat_toan_o_n2(a)
    n = length(a)
    max_sum = -typemax(Int64)
    for i in 1:n
        current_sum = Int64(0)
        for j in i:n
            current_sum += a[j]
            if current_sum > max_sum
                max_sum = current_sum
            end
        end
    end
    return max_sum
end

function do_thoi_gian(n, lap=3)
    a = rand(-50:50, n)
    thuat_toan_o_n2(a) 
    
    min_time = Inf
    for _ in 1:lap
        t = @elapsed thuat_toan_o_n2(a)
        if t < min_time
            min_time = t
        end
    end
    return min_time
end

moc_ns = [500, 1000, 2000, 4000]
ket_qua = Float64[]

println("Dang do thoi gian chay cho cac moc n (Julia)...")
for n in moc_ns
    t = do_thoi_gian(n)
    push!(ket_qua, t)
end

r1 = ket_qua[2] / ket_qua[1]
r2 = ket_qua[3] / ket_qua[2]
r3 = ket_qua[4] / ket_qua[3]

println("\n=== BANG 1: KET QUA KIEM CHUNG TI LE ===")
println("n = 500 -> 1000  | ti le ~ $(round(r1, digits=2))")
println("n = 1000 -> 2000 | ti le ~ $(round(r2, digits=2))")
println("n = 2000 -> 4000 | ti le ~ $(round(r3, digits=2))\n")

println("=== BANG 2: BANG DO THOI GIAN O(n^2) ===")
println("Ngôn ngữ\tn = 500\t\tn = 1000\tn = 2000\tn = 4000\t\tTỉ lệ cuối")
println("Julia\t\t$(round(ket_qua[1], digits=4))s\t$(round(ket_qua[2], digits=4))s\t$(round(ket_qua[3], digits=4))s\t$(round(ket_qua[4], digits=4))s\t\t~$(round(r3, digits=2))\n")

try
    using Plots
    plot(moc_ns, ket_qua, marker=:circle, label="Thuật toán O(n^2)", 
         xlabel="Kích thước đầu vào (n)", ylabel="Thời gian chạy T(n) (giây)",
         title="Đồ thị biểu diễn thời gian thực thi thuật toán O(n^2)(julia)",
         linewidth = 2.5,
         markersize = 7,
         size = (900, 550),      
         margin = 8Plots.mm,    
         grid = true)
    savefig("do_thi_O_n2_julia.png")
    println("=> Đã tự động tạo và lưu thành công file ảnh đồ thị: do_thi_O_n2_julia.png")
catch
    println("=> Thư viện Plots.jl chưa được cài đặt. Hãy chạy lệnh 'using Pkg; Pkg.add(\"Plots\")' trong môi trường Julia nếu muốn tự động tạo ảnh đồ thị.")
end