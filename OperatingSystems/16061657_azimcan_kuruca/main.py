#!/usr/bin/env python3

import random, os, sys, re
import threading
import time

def zaman(start_time):
	result = round((time.time()-start_time)*1000, 5)
	if result > 1000:
		return f'{round(result/1000, 5)}s'
	else:
		return f'{result}ms'

def rand():
	return random.randint(10, 100)

def matrix_create(row_size, column_size):
	matrix = []
	row = []
	for x in range(0, row_size):
		for y in range(0, column_size):
			row.append(rand())
		matrix.append(row)
		row = []

	return matrix

def delete_file(file_name):
	if os.path.isfile(file_name): 
		os.remove(file_name)

def write_file(file_name, matrix):
	print("Dosyaya yaziliyor...", end='')
	f = open(file_name,"a+")

	for row in matrix:
		for cell in row:
			f.write(str(cell))
			f.write(" ")
		f.write("\n")
	f.write("-\n")
	f.close()
	print("Ok")

def read_file(file_name):
	print("Dosyadan okunuyor...", end='')
	matrisler = []
	try:
		f = open(file_name, "r")
	except:
		print("Dosya okunamadi.")
		sys.exit(1)

	c = f.readlines()

	matrix = []
	for line in c:
		line = line.split()

		if line[0] == "-":
			matrisler.append(matrix)
			matrix = []
		else:
			for i in range(0, len(line)): 
				line[i] = int(line[i])
			matrix.append(line)

	print("Ok")
	return matrisler

def thread(line_no, line, matris):
	thread_time = time.time()
	toplam = 0
	for i in range(len(matris[0])):
		for j in range(len(line)):
			toplam += (line[j] * matris[j][i])
		c[line_no][i] = toplam
		toplam = 0
	print(f"{zaman(thread_time)}: Thread {line_no}: Ok")


if __name__ == "__main__":
	if len(sys.argv) != 2:
		print("Bir parametre giriniz.")
		sys.exit(1)

	if not re.search('.mx', sys.argv[1]):
		print("Parametre (dosya_adi.mx) seklinde olmali.")
		sys.exit(1)


	while True:
		a = input("Matris boyutlarini axb ve bxc olacak sekilde a b c olarak giriniz: ")
		matris_size = a.split()
		try:
			for i in range(0, len(matris_size)): 
				matris_size[i] = int(matris_size[i])
			break
		except:
			print("Sayi giriniz.")

	main_time = time.time()

	file_name = sys.argv[1]

	# Matrisler olusturulur ve dosyaya yazdirilir
	delete_file(file_name)
	write_file(file_name, matrix_create(matris_size[0], matris_size[1]))
	write_file(file_name, matrix_create(matris_size[1], matris_size[2]))

	# Matrisleri dosyadan okur
	matrisler = read_file(file_name)

	matris_A = matrisler[0]
	matris_B = matrisler[1]

	# Sonuc matrisi olusturur
	c = []
	for x in range(matris_size[0]):
		line = []
		for y in range(matris_size[2]):
			line.append(0)
		c.append(line)

	# Threadler olusturulur ve baslatilir
	format = "%(asctime)s: %(message)s"

	threads = []
	line_no = 0

	print()
	for line in matris_A:
		threads.append(threading.Thread(target=thread, args=(line_no, line, matris_B)))
		line_no+=1

	for thread in threads:
		thread.start()

	for thread in threads:
		thread.join()

	print()
	delete_file("result.mx")
	write_file("result.mx", c)

	if matris_size[0] > 20 and matris_size[2] > 20: 
		print("Sonuclar result.mx dosyasindadir.")
	else:
		print("========= Sonuc =======")
		for line in c:
			print(line)


	print(f'\nProgram calima zamani: {zaman(main_time)}')