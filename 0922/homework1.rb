print "Please enter a number : " if ARGV.empty?
number = (ARGV[0] || gets.chomp).to_i
ary = (1..number**2).to_a.shuffle
ary.each.with_index { |val,idx| (idx % number == number - 1) ? (puts "#{val}") : (print "#{val}\t") }