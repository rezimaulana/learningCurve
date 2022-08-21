window.onload = function() {
    alert("Selamat Datang Di Aplikasi Penyewaan Mobil")
}
let aHari = ['Senin','Selasa','Rabu','Kamis','Jum\'at','Sabtu','Minggu']
let aBulan = ['Januari', 'Februari', 'Maret', 'April', 'Mei', 'Juni', 'Juli', 'Agustus', 'September', 'Oktober', 'November', 'Desember']
let waktu = new Date
let hari = aHari[waktu.getDay()]
let tanggal = waktu.getDate()
let bulan = aBulan[waktu.getMonth()]
let tahun = waktu.getFullYear()
document.getElementById("todate").innerHTML = hari+", "+tanggal+" "+bulan+" "+tahun;
document.getElementById("konfirmasi").onchange = function () {
    document.getElementById("submit").disabled = !this.checked
}
function result(){
    let validasi = confirm("Apakah Data Sudah Diisi Dengan Benar?")
    if (validasi == true) {
        let namaPenyewa = document.getElementById("namaPenyewa").value
        let jenisMobil
        let hargaMobil
        if (document.getElementById("fr").checked) {
            jenisMobil = document.getElementById("fr").value
            hargaMobil = 300000
        }
        else if (document.getElementById("lb").checked) {
            jenisMobil = document.getElementById("lb").value
            hargaMobil = 500000
        }
        else if (document.getElementById("lm").checked) {
            jenisMobil = document.getElementById("lm").value
            hargaMobil = 700000
        }
        let jumlahMobil = parseFloat(document.getElementById("jumlahMobil").value)
        let lamaSewa = parseFloat(document.getElementById("lamaSewa").value)
        let totalHargaSewa
        let diskon
        let totalBayar
        if (lamaSewa >= 3) {
            totalHargaSewa = lamaSewa*jumlahMobil*hargaMobil
            diskon = 0.1*totalHargaSewa
            totalBayar = totalHargaSewa - diskon
        }
        else {
            totalHargaSewa = lamaSewa*jumlahMobil*hargaMobil
            diskon = 0
            totalBayar = totalHargaSewa - diskon
        }
        document.getElementById("oNamaPenyewa").innerHTML = "Nama : "+namaPenyewa
        document.getElementById("oJenisMobil").innerHTML = "Jenis Mobil : "+jenisMobil
        document.getElementById("oJumlahMobil").innerHTML = "Jumlah Mobil : "+jumlahMobil
        document.getElementById("oLamaSewa").innerHTML = "Lama Sewa : "+lamaSewa+" hari"
        document.getElementById("oTotalHargaSewa").innerHTML = "Total Harga Sewa "+totalHargaSewa
        document.getElementById("oDiskon").innerHTML = "Diskon : "+diskon
        document.getElementById("oTotalBayar").innerHTML = "Total Bayar : "+totalBayar
    }
    else {
        alert("Periksa Data Kembali")
    }
}