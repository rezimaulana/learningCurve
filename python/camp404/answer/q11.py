def ganGen():
    angka = int(input('Masukan Angka \n'))
    if angka % 2 == 0:
        print('Bilangan Genap\n')
        coba()
    elif angka % 2 ==1:
        print('Bilangan Ganjil')
    else:
        ganGen()
    coba()

def coba():
    tryAgain = input('Try Again? y/t\n')
    if tryAgain == 'y':
        ganGen()
    elif tryAgain == 't':
        pass
    else:
        coba()
        
ganGen()