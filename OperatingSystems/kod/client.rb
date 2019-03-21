require 'socket'
require 'json'

class Client
   def initialize(socket_address, socket_port)
      @socket = TCPSocket.open(socket_address, socket_port)
      @request_object = send_request
      @response_object = listen_response

      @request_object.join
      @response_object.join
   end

   def send_request
      Thread.new do
          request = {}
          print "> Username: "
          request["username"] = $stdin.gets.chomp
        loop do
          @socket.puts request.to_json
          request = {}
          print "> Message: " 
          request["message"] = $stdin.gets.chomp
        end
      end

   end

   def listen_response
      Thread.new do
        loop do
          response = JSON.parse(@socket.gets)
          puts "OK.. Username: #{response[username]}, Id: #{response[client_id]}" if !response.has_key?("username")
          
          if response.eql?'quit'
            @socket.close
          end
        end
      end
   end
end

Client.new("localhost", 3000)