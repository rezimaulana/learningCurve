/* window.onload = function() {
    alert("Selamat Datang di Aplikasi Pemesanan Kereta Api");
    <body onload="alert('Selamat Datang di Aplikasi Pemesanan Kereta Api')">
} */
window.onload = function() {
    alert("Selamat Datang di Aplikasi Pemesanan Kereta Api");
}

let ahari = ['Senin','Selasa','Rabu','Kamis','Jum\'at','Sabtu','Minggu']
let abulan = ['Januari', 'Februari', 'Maret', 'April', 'Mei', 'Juni', 'Juli', 'Agustus', 'September', 'Oktober', 'November', 'Desember']

let waktu = new Date
let tgl = waktu.getDate()
let hari = ahari[waktu.getDay()]
let bulan = abulan[waktu.getMonth()]
let tahun = waktu.getFullYear()

document.getElementById("displayTanggal").innerHTML = hari+", "+tgl+" "+bulan+" "+tahun;

document.getElementById("konfirmasi").onchange = function validasi(){
    document.getElementById("submit").disabled = !this.checked
}

function result(){
    let valid = confirm("Apakah Data Sudah Diisi Dengan Benar?")
    if (valid==true){
        
        let identitas
        if (document.getElementById("ktp").checked){
            identitas = document.getElementById("ktp").value
        }
        else if (document.getElementById("sim").checked){
            identitas = document.getElementById("sim").value
        }	

        let noIden = document.getElementById("noIden").value
        let nama = document.getElementById("nama").value
        let tanggal = document.getElementById("tanggal").value
        let asalStasiun = document.getElementById("asalStasiun").value
        let tujuanStasiun = document.getElementById("tujuanStasiun").value
        let tDewasa =  parseFloat(document.getElementById("tDewasa").value)
        let tAnak = parseFloat(document.getElementById("tAnak").value)
        let kelas = document.getElementById("kelas").value
        let total

        if (tujuanStasiun=='jkt'){
            if (kelas=='eks'){
                total = ((tDewasa*100000)+(tAnak*(0.1*100000)))
            }
            else if (kelas=='bis'){
                total = ((tDewasa*80000)+(tAnak*(0.1*80000)))
            }
            tujuanStasiun = "Gambir - Jakarta"
        }
        else if (tujuanStasiun=='yog'){
            if (kelas=='eks'){
                total = ((tDewasa*200000)+(tAnak*(0.1*200000)))
            }
            else if (kelas=='bis'){
                total = ((tDewasa*180000)+(tAnak*(0.1*180000)))
            }
            tujuanStasiun = "Lempuyangan - Yogyakarta"
        }
        else if (tujuanStasiun=='sby'){
            if (kelas=='eks'){
                total = ((tDewasa*300000)+(tAnak*(0.1*300000)))
                
            }
            else if (kelas=='bis'){
                total = ((tDewasa*280000)+(tAnak*(0.1*280000)))
            }
            tujuanStasiun = "Gubeng - Surabaya"
        }
        if (kelas=='eks'){
            kelas = 'Eksekutif'
        }
        else if (kelas=='bis'){
            kelas = 'Bisnis'
        }

        document.getElementById("oIdentitas").innerHTML = "Jenis Identitas : "+identitas
        document.getElementById("oNoIden").innerHTML = "No. Identitas : "+noIden
        document.getElementById("oNama").innerHTML = "Nama : "+nama
        document.getElementById("oTanggal").innerHTML = "Tanggal Berangkat : "+tanggal
        document.getElementById("oStasiunAsal").innerHTML = "Stasiun Asal : "+asalStasiun
        document.getElementById("oStasiunTujuan").innerHTML = "Stasiun Tujuan : "+tujuanStasiun
        document.getElementById("oTiket").innerHTML = "Jumlah Tiket : Dewasa = "+tDewasa+", Anak = "+tAnak
        document.getElementById("oKelas").innerHTML = "Kelas : "+kelas
        document.getElementById("oTotal").innerHTML = "Total Bayar : Rp"+total
    }
    else{
        alert("Periksa Data Kembali")
    }
}
