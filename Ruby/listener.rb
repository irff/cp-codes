require 'open-uri'

url = gets
page = open(url)

text = page.read

puts text