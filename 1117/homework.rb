f=[]
File.open("homework.txt", "r") do |file|
  file.each do |line|
    f << line
  end
end
compute = []
answer = []
element = f[0].split
level = {
  "+" => 1,
  "-" => 1,
  "*" => 2,
  "/" => 2,
  "(" => 0,
  " " => -1,
}
element.each.with_index do |value,index|
  case value
  when "("
    compute << value
  when ")"
    while answer.last != "("
      answer << compute.pop
    end
    answer.pop
  when "+","-","*","/"
    if level[compute.last||" "] < level[value]
      compute << value
    elsif level[compute.last] >= level[value]
      while level[compute.last||" "] >= level[value]
        answer << compute.pop
      end
      compute << value
    end
  else
    element[index] = value.to_f
    answer << value
  end
end
while !compute.empty?
  answer << compute.pop
end
puts "Postfix : #{answer.join(" ")}"
ans = eval(element.join)
puts "#{element.join} = #{ans}"