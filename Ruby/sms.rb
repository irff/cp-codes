require 'rubygems'
require 'twilio-ruby'
 
account_sid = "ACcd1c03f85413fb1cd326b9c65923d63e"
auth_token = "1743c4df087019b850129ffa50fee0dc"
client = Twilio::REST::Client.new account_sid, auth_token
 
from = "+15414445026" # Your Twilio number
 
friends = {
"+6289652567808" => "Irfan",
"+6283865087650" => "Mas Alfan"
}
friends.each do |key, value|
  client.account.messages.create(
    :from => from,
    :to => key,
    :body => "Halo #{value}, piye kabare le? Isih kepenak jamanku to.."
  ) 
  puts "Sent message to #{value}"
end