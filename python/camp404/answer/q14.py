def faktorial(angka):
    if angka == 0 or angka == 1:
        return 1
    else:
        return angka * (faktorial(angka-1))

angka = int(input('Masukan Angka\n'))
print('Faktorial ',angka,' = ',faktorial(angka))