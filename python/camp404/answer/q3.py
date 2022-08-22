def cekGanjilGenap():
    number = int(input('Input bilangan positif\n'))
    if (number < 0):
        print('Masukan bilangan positif\n')
    elif (number % 2 == 0):
        print('{0} adalah bilangan genap.'.format(number))
    elif (number % 2 == 1):
        print('{0} adalah bilangan ganjil.'.format(number))

cekGanjilGenap()