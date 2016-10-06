print " Please enter a number : #{ARGV[0]}"
number = (ARGV[0] || gets.chomp).to_i
puts ""

# 初始想法
puts "p0 :"
(0..2**number-1).each { |i| puts "%0#{number}b" % i }


# 遞減
def p1(num,bit)
  if num <= 0
    print("%0#{bit}b\n" % num)
  else
    print("%0#{bit}b\n" % num)
    p1(num-1, bit)
  end
end
puts "p1 :"
p1(2**number-1, number)

# 遞增
def p2(num,bit)
  if num >= 2**bit - 1
    print("%0#{bit}b\n" % num)
  else
    print("%0#{bit}b\n" % num)
    p2(num+1, bit)
  end
end
puts "p2 :"
p2(0, number)

# 餘數
def p3(num,bit)
  if bit == 1
    print num % 2,"\n"
  else
    print( num/(2**(bit-1)) )
    p3( num % (2**(bit-1)), bit-1 )
  end
end

puts "p3 :"
(0..2**number-1).each { |n| p3(n, number) }









