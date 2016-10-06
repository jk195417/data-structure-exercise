def factorial(n)
  n == 0 ? 1 : n * factorial(n-1)
end
n = (ARGV[0] || gets.chomp).to_i
puts "#{n}! = #{factorial(n)}"