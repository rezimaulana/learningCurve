def kelipatanTiga():
    angka = int(input('Masukan Angka Akhir\n'))
    while angka > 0:
        if angka % 3 == 0:
            print(angka, end=" ")
        angka = angka - 1
                

kelipatanTiga()