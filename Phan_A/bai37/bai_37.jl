function dem(a)
    chan = 0
    le = 0
    am = 0
    for x in a
        if x % 2 != 0
            le += 1
        else
            chan += 1
        end
        if x < 0
            am += 1
        end
    end
    return chan, le, am
end

input_data = split(read(stdin, String))
if !isempty(input_data)
    n = parse(Int, input_data[1])
    a = [parse(Int, input_data[i]) for i in 2:(n+1)]
    chan, le, am = dem(a)
    println("chan $chan, le $le, am $am")
end