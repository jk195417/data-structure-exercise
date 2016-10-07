puts "please enter a number : "
num = gets.chomp.to_i

def ten_to_two(num)
  num > 0 ? bits = num.to_s(2).length + 1 : bits = num.to_s(2).length
  bits.downto(0).map { |n| num[n] }.join
end

puts "#{num}的二進制 : #{ten_to_two(num)}"
puts "-#{num}的二進制(2's complement) : #{ten_to_two(-num)}"





