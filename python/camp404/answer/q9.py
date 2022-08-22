def bilGen():
    angka = int(input('Masukan Angka Akhir\n'))
    if angka <= 0:
        print('Input harus angka positif!\n')
        bilGen()
    else:
        print('Bilangan genap dari 0 - ',angka)
        for i in range(angka+1):
            if i % 2 == 0:
                print(i)
                

bilGen()