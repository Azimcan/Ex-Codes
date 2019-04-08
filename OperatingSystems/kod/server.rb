require 'socket'
require 'json'

class User
  attr_accessor :username, :client_id
  def initialize(username=nil, client_id=nil)

    @username = username
    @client_id = client_id

    @data = { 
      username: username, 
      client_id: client_id 
    }
  end

  def to_s
    '#{@data}'
  end
end

class Server
  def initialize(socket_address, socket_port)
    socket = TCPServer.open(socket_address, socket_port)

    @server_data = {server: socket, clients: [] }

    puts 'Started server.........'
    run

  end

  def run
    loop{
      client_connection = @server_data[:server].accept
      Thread.start(client_connection) do |client_id|
        request = JSON.parse(client_id.gets)
        
        user_save(request["username"], client_id) if request.has_key?("username")

        establish_chatting(request["username"], client_id)
      end
    }.join
  end

  def establish_chatting(username, client_id)
    loop do
      request = JSON.parse(client_id.gets)
      puts @server_data[:clients]

      @server_data[:clients].each do |client|
        client.client_id.puts "#{request["username"]} : #{request["message"]}"
      end
    end
  end

  def user_save(username, client_id)
    user = User.new(username, client_id)
    @server_data[:clients] << user
    puts "OK.. Username: #{username}, Id: #{client_id}"
    client_id.puts user.show.to_json
  end
end
