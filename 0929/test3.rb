print " Please enter a number : #{ARGV[0]}"
number = (ARGV[0] || gets.chomp).to_i
puts ""

def p(string,n)
  i = 0
  if n <= 1
    print "#{string}\n"
  else
    while i < n
      string[n-1],string[i] =  string[i],string[n-1]
      p(string, n-1)
      string[n-1],string[i] =  string[i],string[n-1]
     i += 1 
    end
  end
end

letters = ("a".."z").take(number)
p(letters,letters.length)