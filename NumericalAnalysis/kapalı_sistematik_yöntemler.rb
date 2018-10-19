def fonksiyon(x)
	(x**2) - 5
end

def ikiye_bolme_yontemi(x_bot, x_top, minimum_bagil_hata)
	bagil_hata = 100.0
	temp = 5.0

		puts "x alt      x üst      x orta      f(x alt)      f(x üst)      f(x orta)      f(x mid)"
	while bagil_hata > minimum_bagil_hata
		x_mid = (x_bot + x_top) / 2.0
		bagil_hata = (((x_mid - temp) / x_mid) * 100).abs

		deneme = <<-HEREDOC
#{x_bot.round(4)}        #{x_top.round(4)}        #{x_mid.round(4)}        #{fonksiyon(x_bot).round(4)}        #{fonksiyon(x_top).round(4)}        #{fonksiyon(x_mid).round(4)}        #{bagil_hata.round(4)}
		HEREDOC

		puts deneme	
				
		temp = x_mid

		if fonksiyon(x_bot) * fonksiyon(x_mid) < 0
			x_top = x_mid
		elsif fonksiyon(x_bot) * fonksiyon(x_mid) > 0
			x_bot = x_mid
		elsif fonksiyon(x_bot) * fonksiyon(x_mid) == 0
			return x_mid
		end
	end
end

def yer_degistirme_yontemi(x_bot, x_top, minimum_bagil_hata)
	bagil_hata = 100.0
	temp = 5.0

	while bagil_hata > minimum_bagil_hata
		x_mid = ((x_top * fonksiyon(x_bot)) - (x_bot * fonksiyon(x_top))) / (fonksiyon(x_bot) - fonksiyon(x_top))

		puts "x alt : #{x_bot}"
		puts "x üst : #{x_top}"
		puts "x orta : #{x_mid}"
		puts "f(x alt) : #{fonksiyon(x_bot)}"
		puts "f(x üst) : #{fonksiyon(x_top)}"
		puts "f(x orta) : #{fonksiyon(x_mid)}" 
		
		bagil_hata = (((x_mid - temp) / x_mid) * 100).abs
		puts "Bağıl hata : %#{bagil_hata}"
		puts "-------------------------------------------"
		
		temp = x_mid

		if fonksiyon(x_bot) * fonksiyon(x_top) < 0
			x_top = x_mid
		elsif fonksiyon(x_bot) * fonksiyon(x_top) > 0
			x_bot = x_mid
		elsif fonksiyon(x_bot) * fonksiyon(x_top) == 0
			return 0
		end
	end
end


#puts yer_degistirme_yontemi(x_bot, x_top, minimum_bagil_hata)

def main
	x_bot = 2.0
	x_top = 3.0
	minimum_bagil_hata = 0.01

	puts ikiye_bolme_yontemi(x_bot, x_top, minimum_bagil_hata)
end

main if __FILE__ == $PROGRAM_NAME
