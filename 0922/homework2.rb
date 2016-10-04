begin
  content=[]
  open("2.txt", "r") do |file|
    file.each do |line|
      content << line.chomp.to_f
    end
  end
  apr = content[1] / 100 + 1
  years = Math.log((content[2]/content[0]),apr)
  puts(
    "money now : #{content[0]}",
    "bonus : #{content[1]}, in other words that APR : #{apr}",
    "money estimate : #{content[2]}",
    "------------------------------",
    "you need #{years} years to let your #{content[0]} grow up to #{content[2]}"
  )
rescue
  puts "file that you want to open do not exist"
end