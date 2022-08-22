def hitungTotal(hargaSatuan, jumlahBarang):
    hargaNet = hargaSatuan * jumlahBarang
    return hargaNet
def hitungNet(hargaSatuan, jumlahBarang):
    hargaTotal = hitungTotal(hargaSatuan, jumlahBarang) - 5000
    return hargaTotal

hargaSatuan = int(input('Masukan Harga Satuan\n'))
jumlahBarang = int(input('Masukan Jumlah Barang\n'))

if hitungTotal(hargaSatuan, jumlahBarang) >= 50000:
    print(hitungNet(hargaSatuan, jumlahBarang))
else:
    print(hitungTotal(hargaSatuan, jumlahBarang))

