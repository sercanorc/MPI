MPI ile çalışabilmek için öncelikle MPI iletişim protokolü ile çalışabilen bir kütüphaneye ihtiyaç vardır
Dev C++ ile MPICH entegrasyonu yapılarak hızlı bir şekilde proje oluşturulabilir.
Projenin sorunsuz bir şekilde derlenmesi için bazı ayarlar yapılmalıdır. Project
menüsü altında ki Project Options bölümünde Parameters menüsünde ki linkler bölümüne -lmpi komutu eklenir
Ardından Directories menüsüne MPICH kütüphaneleri eklenir. Bunun için sırasıyla
Library Directories ve Include Directories bölümleri eklenmelidir ardından proje derlenip sorunsuz çalıştırılabilir
 
