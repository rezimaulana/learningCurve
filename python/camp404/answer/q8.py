bawah = int(input('Masukan Angka Awal'))
atas = int(input('Masukan Angka Akhir'))
for i in range(bawah, atas+1):
    if i % 2 == 1:
        print(i)
