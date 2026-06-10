#  Sistem Pemesanan Tiket Film Sederhana (C++)

## Deskripsi Proyek

Sistem Pemesanan Tiket Film Sederhana adalah program berbasis bahasa C++ yang menerapkan konsep **Object-Oriented Programming (OOP)** serta struktur data **Queue** dan **Stack** untuk mengelola pemesanan tiket bioskop.

Program ini memungkinkan pengguna untuk:

* Memilih film yang tersedia.
* Memesan tiket berdasarkan jumlah kursi.
* Menyimpan antrian pemesanan menggunakan Queue.
* Memproses tiket sesuai urutan pemesanan (FIFO).
* Menyimpan riwayat pemesanan menggunakan Stack.
* Menampilkan riwayat pemesanan berdasarkan urutan terakhir dipesan (LIFO).

---

## Fitur Program

### 1. Pesan Tiket

Pengguna dapat memilih film yang tersedia dan memasukkan jumlah kursi yang ingin dipesan.

### 2. Proses Tiket Berikutnya

Sistem akan memproses tiket yang berada di urutan paling depan dalam antrian.

### 3. Lihat Antrian Tiket

Menampilkan seluruh tiket yang masih menunggu untuk diproses.

### 4. Lihat Riwayat Pemesanan

Menampilkan seluruh riwayat pemesanan yang pernah dilakukan.

### 5. Keluar Program

Mengakhiri program.

---

## Struktur Data yang Digunakan

### Queue (FIFO - First In First Out)

Digunakan untuk menyimpan antrian pemesanan tiket.

```cpp
queue<Ticket> bookingQueue;
```

Karakteristik:

* Tiket yang pertama dipesan akan diproses terlebih dahulu.
* Digunakan pada fitur:

  * createBooking()
  * processNextBooking()
  * showQueue()

---

### Stack (LIFO - Last In First Out)

Digunakan untuk menyimpan riwayat pemesanan tiket.

```cpp
stack<Ticket> history;
```

Karakteristik:

* Tiket yang terakhir dipesan akan ditampilkan terlebih dahulu.
* Digunakan pada fitur:

  * createBooking()
  * showHistory()

---

## Konsep OOP yang Digunakan

### Class

Program menggunakan class `BookingSystem` untuk mengelola seluruh proses pemesanan tiket.

```cpp
class BookingSystem
{
    ...
};
```

### Encapsulation

Data seperti:

```cpp
queue<Ticket> bookingQueue;
stack<Ticket> history;
int nextId;
```

disimpan dalam bagian `private` sehingga hanya dapat diakses melalui method yang tersedia.

### Constructor

```cpp
BookingSystem() : nextId(1) {}
```

Digunakan untuk menginisialisasi ID tiket pertama.

---

## Struktur Program

### Struct Ticket

Menyimpan informasi tiket:

```cpp
struct Ticket {
    int id;
    string film;
    int seats;
};
```

Keterangan:

* id → nomor tiket
* film → nama film
* seats → jumlah kursi

---

### Fungsi showFilms()

Menampilkan daftar film yang tersedia.

---

### Fungsi createBooking()

Membuat tiket baru kemudian menyimpannya ke:

* Queue (antrian)
* Stack (riwayat)

---

### Fungsi processNextBooking()

Mengambil tiket terdepan dari Queue lalu memprosesnya.

---

### Fungsi showQueue()

Menampilkan seluruh tiket yang masih berada dalam antrian.

---

### Fungsi showHistory()

Menampilkan seluruh riwayat pemesanan tiket yang tersimpan dalam Stack.

---

## Cara Menjalankan Program

### Compile

Menggunakan g++:

```bash
g++ main.cpp -o tiket
```

### Jalankan Program

```bash
./tiket
```

---

## Contoh Output

```text
=== Sistem Pemesanan Tiket Film Sederhana ===

1. Pesan tiket
2. Proses tiket berikutnya
3. Lihat antrian tiket
4. Lihat riwayat pemesanan
5. Keluar

Pilih menu:
```

---

## Pembagian Tugas Kelompok

###  Valentsea

**Bagian Class dan Struktur Program**

* Membuat `struct Ticket`
* Membuat `class BookingSystem`
* Membuat atribut dan constructor class

###  Khibran

**Implementasi Queue**

* Membuat `bookingQueue`
* Membuat fungsi `processNextBooking()`
* Membuat fungsi `showQueue()`
* Mengelola sistem antrian tiket menggunakan Queue (FIFO)

###  Chesa

**Implementasi Stack**

* Membuat fungsi `showHistory()`
* Mengelola dan menampilkan riwayat pemesanan menggunakan Stack (LIFO)

###  Shafira

**Implementasi Main Program**

* Menyusun alur program pada fungsi `main()`
* Membuat menu interaktif
* Menghubungkan seluruh fungsi agar dapat dijalankan oleh pengguna

---

## Anggota Kelompok

1. Valentsea
2. Khibran
3. Chesa
4. Shafira

---

## Kesimpulan

Program Sistem Pemesanan Tiket Film Sederhana berhasil menerapkan konsep OOP serta struktur data Queue dan Stack dalam satu aplikasi sederhana. Queue digunakan untuk mengelola antrian pemesanan tiket secara FIFO, sedangkan Stack digunakan untuk menyimpan dan menampilkan riwayat pemesanan secara LIFO. Dengan penerapan tersebut, program dapat mensimulasikan sistem pemesanan tiket bioskop yang terorganisir dan mudah digunakan.
