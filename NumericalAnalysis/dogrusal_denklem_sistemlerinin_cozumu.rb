#!/usr/bin/ruby
# encoding: utf-8

class DenklemSistemi
	def initialize()
		@denklem = []
	end



	def to_s
		"#{denklem1}"
		"#{denklem2}"
	end
end

class Denklem < DenklemSistemi
	def initialize(a, b, c, y, denklemSistemi)
		@a, @b, @c = a, b, c
		@y = y
		denklemSistemi.denklem[0] = 
	end

	def to_s
		"#{@a}x\u2081 + #{@b}x\u2082 + #{@c}x\u2083 = #{@y}"	
	end
end



def main
	denklemSistemi = DenklemSistemi.new
	
	denklem1 = Denklem.new(1, 2, 3, 6)
	denklem2 = Denklem.new(2, 4, 6, 12)

	puts denklemSistemi

end

main if __FILE__ == $PROGRAM_NAME