def fibonacii(n)
  n <= 1 ? n : fibonacii(n-1)+fibonacii(n-2)
end
(ARGV[0].to_i + 1).times do |i|
  puts "fib(#{i}) : #{fibonacii(i)}"
end