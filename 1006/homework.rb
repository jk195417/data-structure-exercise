begin
  content=[]
  open("hw2.txt", "r") do |file|
    file.each do |line|
      content << line.chomp.to_i(2)
    end
  end
  ans = content[0] - content[1]
  printf("%08b-%08b=%08b",content[0],content[1],ans)
  puts "(#{content[0]}-#{content[1]}=#{ans})"
rescue 
  puts "hw2.txt do not exist"
end