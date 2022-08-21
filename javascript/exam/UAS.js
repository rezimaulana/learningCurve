window.onload = function() {
    alert("Selamat Datang Di Kuliah Online")
}
let aHari = ['Senin','Selasa','Rabu','Kamis','Jum\'at','Sabtu','Minggu']
let aBulan = ['Januari', 'Februari', 'Maret', 'April', 'Mei', 'Juni', 'Juli', 'Agustus', 'September', 'Oktober', 'November', 'Desember']
waktu = new Date
hari = aHari[waktu.getDay()]
tanggal = waktu.getDate()
bulan = aBulan[waktu.getMonth()]
tahun = waktu.getFullYear()
let todate1 = hari+", "+tanggal+" "+bulan+" "+tahun
let todate2 = tanggal+" "+bulan+" "+tahun
document.getElementById("todate").innerHTML = todate1
document.getElementById("konfirmasi").onchange = function validasi() {
    document.getElementById("submit").disabled = !this.checked
}
function result(){
    let validasi = confirm=("Apakah Data Sudah Diisi Dengan Benar")
    if (validasi=true) {
        alert("Akun Anda Sudah Berhasil Terdaftar")
        let nim = document.getElementById("nim").value
        let nama = document.getElementById("nama").value
        let jenisKelamin
        if (document.getElementById("L").checked) {
            jenisKelamin = document.getElementById("L").value
        }
        else if (document.getElementById("P").checked) {
            jenisKelamin = document.getElementById("P").value
        }
        let email = document.getElementById("email").value
        let tl = document.getElementById("tl").value
        let username = document.getElementById("username").value
        let pass = document.getElementById("pass").value
        document.getElementById("oTanggalPendaftaran").innerHTML = "Tanggal Pendaftaran : "+todate2
        document.getElementById("oNim").innerHTML = "NIM : "+nim
        document.getElementById("oNama").innerHTML = "Nama : "+nama
        document.getElementById("oJenisKelamin").innerHTML = "Jenis Kelamin : "+jenisKelamin
        document.getElementById("oEmail").innerHTML = "Email : "+email
        document.getElementById("oTanggalLahir").innerHTML = "Tanggal Lahir : "+tl
        document.getElementById("oUsername").innerHTML = "Username : "+username
        document.getElementById("oPass").innerHTML = "Password : "+pass
    }
    else {
        alert("Periksa Kembali Data")
    }
}