MPI ile çalýþabilmek için öncelikle MPI iletiþim protokolü ile çalýþabilen bir kütüphaneye ihtiyaç vardýr
Dev C++ ile MPICH entegrasyonu yapýlarak hýzlý bir þekilde proje oluþturulabilir.
Projenin sorunsuz bir þekilde derlenmesi için bazý ayarlar yapýlmalýdýr. Project
menüsü altýnda ki Project Options bölümünde Parameters menüsünde ki linkler bölümüne -lmpi komutu eklenir
Ardýndan Directories menüsüne MPICH kütüphaneleri eklenir. Bunun için sýrasýyla
Library Directories ve Include Directories bölümleri eklenmelidir ardýndan proje derlenip sorunsuz çalýþtýrýlabilir

klasör içerisinde rapor ve örnek sonuçlar vardýr
 