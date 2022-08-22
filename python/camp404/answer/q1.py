def hitungUangJajan():
    uangSaku = int(input("Input Integer\n"))
    periodeHari = int(input("Input Jumlah Hari\n"))
    if (uangSaku > 0 and periodeHari > 0):
        jumlahAlokasiPerHari = uangSaku / periodeHari
        output = print('Jumlah alokasi uang jajan per hari', jumlahAlokasiPerHari)
        return output
    else:
        print('Input harus bernilai positif atau lebih besar dari 0')
        hitungUangJajan()

hitungUangJajan()