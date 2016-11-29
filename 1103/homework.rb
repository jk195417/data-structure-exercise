f = []
File.open("./homework.txt", "r") do |file|
  file.each do |line|
    f << line
  end
end
puts f[0]

words = []
e_idx = []
s_idx = []
f[0].each_char.with_index do |chr,idx|
  e_idx << idx if(chr == "e")
  s_idx << idx if(chr == "s")
  words << chr
  if (!s_idx.empty? && !e_idx.empty?)
    (s_idx.last-e_idx.last+1).times do
      words.pop
    end
    s_idx.pop
    e_idx.pop
  end
end

print words.join()
puts ""
