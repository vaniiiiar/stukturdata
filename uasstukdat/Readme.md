UAS STUKTUR DATA

- Bikin direktori dengan cara "mkdir(nama file)"
- Untuk memastikan direktorinya sudah terbuat "cd (nama file)"
- lalu buka file yang sudah dibuat selanjutnya " code .  "
- ketik / copy isi dalam file vscode jika sudah selesai ctrl + s

selesai di vscode beralih ke terminal lagi dan melakukan step tsb
- nano docker-compose.yml
- pastikan yang keluuar di terminal sama yang ada di vscode lalu jika sudah semua sama pencet ctrl x , ctrl y
- lalu ketik docker compose up -d --build, untuk ngebuild file docker dan di jalanin agar bisa terhbung ke navicat
- pastikan build berhasil dan tidak ada eror
- buka navicat
- conection, add new conection (mysql) dengan conection yang telah anda disediakan  dalam visual studio code
- add new table sesuaiin dengan code yang kamu buat membutuhkan berapa banyak table
- jika sudah buka terminal lagi
- apt-get install libmysqlclient-dev
- [Y/N] pilih Y
- lakukan hingga install selesai
-  untuk compile bisa di terminal atau bisa di visual studio code 
    1. g++ -o myapp main.cpp -lmysqlclient
    2. ./(myapp)
    jika sudah maka hasil output akan otomatis terhubung dengan database di navicat.
