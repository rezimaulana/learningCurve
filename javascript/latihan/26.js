window.onload = function() {
    alert("Selamat Datang Di Program Perhitungan Gaji")
}
let aHari = ['Senin','Selasa','Rabu','Kamis','Jum\'at','Sabtu','Minggu']
let aBulan = ['Januari', 'Februari', 'Maret', 'April', 'Mei', 'Juni', 'Juli', 'Agustus', 'September', 'Oktober', 'November', 'Desember']
waktu = new Date
hari = aHari[waktu.getDay()]
tanggal = waktu.getDate()
bulan = aBulan[waktu.getMonth()]
tahun = waktu.getFullYear()
document.getElementById("todate").innerHTML = hari+", "+tanggal+" "+bulan+" "+tahun
document.getElementById("konfirmasi").onchange = function validasi() {
    document.getElementById("submit").disabled = !this.checked
}
function result() {
    let ceklis = confirm("Apakah Data Sudah Diisi Dengan Benar?")
    if (ceklis==true) {
        golonganPegawai = document.getElementById("golonganPegawai").value
        jumlahAnakPegawai = parseFloat(document.getElementById("jumlahAnakPegawai").value)
        let gajiPokokPegawai
        let tunjanganAnakPegawai
        let totalGajiPegawai
        if (golonganPegawai=='A'){
            gajiPokokPegawai=3000000
            tunjanganAnakPegawai=jumlahAnakPegawai*(0.2*gajiPokokPegawai)
            totalGajiPegawai=gajiPokokPegawai+tunjanganAnakPegawai
        }
        else if (golonganPegawai=='B'){
            gajiPokokPegawai=2000000
            tunjanganAnakPegawai=jumlahAnakPegawai*(0.15*gajiPokokPegawai)
            totalGajiPegawai=gajiPokokPegawai+tunjanganAnakPegawai
        }
        else if (golonganPegawai=='C'){
            gajiPokokPegawai=1000000
            tunjanganAnakPegawai=jumlahAnakPegawai*(0.1*gajiPokokPegawai)
            totalGajiPegawai=gajiPokokPegawai+tunjanganAnakPegawai
        }
        document.getElementById("oGolonganPegawai").innerHTML = "Golongan Pegawai : "+golonganPegawai
        document.getElementById("oJumlahAnakPegawai").innerHTML = "Jumlah Anak Pegawai : "+jumlahAnakPegawai
        document.getElementById("oGajiPokokPegawai").innerHTML = "Gaji Pokok Pegawai : "+gajiPokokPegawai
        document.getElementById("oTunjanganAnakPegawai").innerHTML = "Tunjangan Anak Pegawai : "+tunjanganAnakPegawai
        document.getElementById("oTotalGajiPegawai").innerHTML = "Total Gaji Pegawai : "+totalGajiPegawai
    }
    else {
        alert("Periksa Data Kembali")
    }
}