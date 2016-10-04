print "Input a number : "
input = gets.chomp.to_i
number = 2**(input)-1
(number+1).times { |i| puts "%0#{input}b" % i }
