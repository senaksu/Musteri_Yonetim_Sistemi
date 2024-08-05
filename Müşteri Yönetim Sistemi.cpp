


#include<iostream> //cin ve cout dosyalarının tanımlı olduğu kütüphaneyi ekledim.
#include<fstream> //dosyalama işlemleri için gerekli kütüphaneyi ekledim.
#include<string> //string değişkeni için gerekli kütüphaneyi ekledim.
#include <stdio.h> //dosya giriş çıkış işlemleri için gerekli kütüphaneyi ekledim.
#include<locale.h>
#include <windows.h>



using namespace std;
int main()
{
    setlocale(LC_ALL, "Turkish");
    // ürün bilgileri urun.txt dosyasında  yer alacak bilgiler
    string urunKodu;
    string   urunAdi;
    string  urunUreticisi;
    string   urunTeminSuresi;
    string urunUretimTarihi;
    string urunFiyatGenel;
    string urunFiyatOzel;
    string urunKdv;
    string  urunStokAdedi;

    // müşterileri bilgileri  için cari.txt dosyasında yer alacak bilgiler
    string firmaNo;
    string  firmaAdi;
    string  firmaTel;
    string firmaSorumlusu;
    string musteriKatagori;
    string musteriAdres;

    // sipariş bilgileri siparis.txt dosyasında yer alacak bilgiler
    //string  firmaNo yukarıda tanımlı
    string  siparisKodu;
    string  siparisTarihi;
    string  siparisTutari;
    string  siparisListesi;
    string siparisAlan;
    string siparisUrunKodu;
    string siparisUrunAdedi;

    // işlemler için 
    string urunAramaKod;        // aranacak ürün kodu
    string silUrunKod;            //silinecek ürün kodu
    string duzenUrunKod;             // düzenlenecek ürün kodu
    string  araFirmaNo;               // aranacak müşteri
    string duzenFirmaNo;        // düzenlenecek müşteri
    string silFirmaNo;             // silinecek müşteri
    string  araSiparisKod;             //aranacak siparis kodu
    string   silSiparisKod;            // silinecek siparişin kodu
    string duzenSiparisKod;      //düzenlenecek sipariş kodu

    int numara, secim1, secim2, secim3;
    char cevap = 'e';
    int gecici = 0;

    cout << '\t' << '\t' << "**HOSGELDİNİZ**" << endl;
    cout << endl;
    cout << "--LÜTFEN SEÇİM NUMARANIZI YAZINIZ--" << endl;
    cout << "  1-  ÜRÜN İŞLEMLERİ" << endl;
    cout << "  2-  MÜŞTERİ İŞLEMLERİ " << endl;
    cout << "  3-  SİPARİŞ İŞLEMLERİ" << endl;
    cout << "  4-  ÇIKIŞ  " << endl;
    cout << endl;
    cin >> numara;


    if (numara == 1)   // Eğer seçim numarası 1'e eşitse 
    {
        cout << "  >>1-ÜRÜN İLE İLGİLİ İŞLEMLER<<" << endl;
        cout << "    1) Ürün Ekleme" << endl;
        cout << "    2) Ürün Arama" << endl;
        cout << "    3) Ürün Listeleme" << endl;
        cout << "    4) Ürün Düzeltme" << endl;
        cout << "    5) Ürün Silme " << endl;
        cout << " =>  Lütfen yukarıdan yapmak istediğiniz işlemin numarasını yazınız" << endl;
        cin >> secim1;  // işlem numarasını secim1 değişkenine aktardım.

        if (secim1 == 1) {

            ofstream DosyaYaz; //Dosya çıkışı yapabilmek için gerekli kodu yazdım.

            DosyaYaz.open("urun.txt", ios::app); //urun.txt dosyasını dosya ekleme modunda açtım

            do
            {
                cout << "   *1-Ürün Ekleme* " << endl;
                cout << "\n Ürün Kodu :"; cin >> urunKodu;
                cout << "\n Ürün Adı :"; cin >> urunAdi;
                cout << "\n Ürün Üreticisi :"; cin >> urunUreticisi;
                cout << "\n Ürün Temin süresi :"; cin >> urunTeminSuresi;
                cout << "\n Ürün Üretim Tarihi :"; cin >> urunUretimTarihi;
                cout << "\n Ürün Fiyat (genel) :"; cin >> urunFiyatGenel;
                cout << "\n Ürün Fiyat(özel) :"; cin >> urunFiyatOzel;
                cout << "\n Ürün KDV Oranı :"; cin >> urunKdv;
                cout << "\n Ürün Stok Adedi :"; cin >> urunStokAdedi;
                DosyaYaz << "\n" << urunKodu << " " << urunAdi << " " << urunUreticisi << " "
                    << urunTeminSuresi << " " << urunUretimTarihi << " " << urunFiyatGenel << " "
                    << urunFiyatOzel << " " << urunKdv << " " << urunStokAdedi;

                cout << "  Ürün eklendi " << endl;
                cout << "Ürün Eklemeye Devam Edecek Misiniz? (e/h) " << endl; cin >> cevap;
            } while (!(cevap == 'h'));

            DosyaYaz.close();
        }

        if (secim1 == 2) {    // seçim numarası 2 olursa "ürün arama".

            ifstream DosyaOku;
            DosyaOku.open("urun.txt");
            cout << " *2-Ürün Arama*" << endl;
            cout << " Aradığınız ürünün kodunu giriniz :";
            cin >> urunAramaKod;
            bool bulundu_mu = false;
            while (!DosyaOku.eof())   //urun.txt dosyasını sonuna kadar okumayı sağlar
            {
                DosyaOku >> urunKodu >> urunAdi >> urunUreticisi >> urunTeminSuresi >> urunUretimTarihi >> urunFiyatGenel >>
                    urunFiyatOzel >> urunKdv >> urunStokAdedi;
                if (urunAramaKod == urunKodu)  // Eğer aranan ürün kodu dosyadakiyle aynıysa ürün bilgilerini ekrana yazar
                {
                    cout << "\n Ürün Bilgileri \n";
                    cout << " ürün kodu :" << urunKodu << endl;
                    cout << " ürün adı :" << urunAdi << endl;
                    cout << " ürün üreticisi:" << urunUreticisi << endl;
                    cout << " ürün temin süresi :" << urunTeminSuresi << endl;
                    cout << " ürün üretim tarihi:" << urunUretimTarihi << endl;
                    cout << " ürün fiyat(genel) :" << urunFiyatGenel << endl;
                    cout << " ürün fiyat(özel) :" << urunFiyatOzel << endl;
                    cout << " ürün kdv :" << urunKdv << endl;
                    cout << " ürün stok adedi:" << urunStokAdedi << endl;
                    bulundu_mu = true;

                }

            }
            DosyaOku.close();
            if (!bulundu_mu) // ürün kodu dosyada yoksa ürün yoktur yazar
                cout << "  Aradığınız ürün koduyla eşleşen ürün yoktur  ";
        }

        if (secim1 == 3)// seçim numarası 3 olursa "ürün listeleme".
        {
            cout << "*3-Ürün Listesi*" << endl << endl;
            ifstream DosyaOku("urun.txt");
            while (!(DosyaOku.eof())) //urun.txt dosyasını sonuna kadar okur
            {
                DosyaOku >> urunKodu >> urunAdi >> urunUreticisi >> urunTeminSuresi >> urunUretimTarihi >> urunFiyatGenel >>
                    urunFiyatOzel >> urunKdv >> urunStokAdedi;
                cout << "\n Ürün Bilgileri \n";
                cout << " ürün kodu :" << urunKodu << endl;
                cout << " ürün adı :" << urunAdi << endl;
                cout << " ürün üreticisi:" << urunUreticisi << endl;
                cout << " ürün temin süresi :" << urunTeminSuresi << endl;
                cout << " ürün üretim tarihi:" << urunUretimTarihi << endl;
                cout << " ürün fiyat(genel) :" << urunFiyatGenel << endl;
                cout << " ürün fiyat(özel) :" << urunFiyatOzel << endl;
                cout << " ürün kdv :" << urunKdv << endl;
                cout << " ürün stok adedi:" << urunStokAdedi << endl;

            }
            DosyaOku.close(); //dosya okumayı kapattım.






        }

        if (secim1 == 4)      // seçim 4 olursa ürün düzenleme
        {

            cout << "* 4-Ürün Bilgileri Düzenleme*" << endl;
            ifstream DosyaOku("urun.txt");
            ofstream DosyaYaz("duzenurun.tmp");
            cout << " Düzenlenecek Ürünün Kodunu Giriniz : " << endl;
            cin >> duzenUrunKod;
            while (!(DosyaOku.eof())) // urun.txt dosyasını sonuna kadar okuttum
            {
                DosyaOku >> urunKodu >> urunAdi >> urunUreticisi >> urunTeminSuresi >> urunUretimTarihi >> urunFiyatGenel >>
                    urunFiyatOzel >> urunKdv >> urunStokAdedi;
                if (duzenUrunKod == urunKodu)
                {
                    cout << "  >>Ürün Bilgileri<<";
                    cout << "\n Ürün Kodu :" << urunKodu;
                    cout << "\n Ürün Adı :" << urunAdi;
                    cout << "\n Ürün Üreticisi :" << urunUreticisi;
                    cout << "\n Ürün Temin süresi :" << urunTeminSuresi;
                    cout << "\n Ürün Üretim Tarihi :" << urunUretimTarihi;
                    cout << "\n Ürün Fiyat (genel) :" << urunFiyatGenel;
                    cout << "\n Ürün Fiyat(özel) :" << urunFiyatOzel;
                    cout << "\n Ürün KDV Oranı :" << urunKdv;
                    cout << "\n Ürün Stok Adedi :" << urunStokAdedi << endl << endl;
                    cout << "  Ürün Bilgilerini Tekrar Giriniz " << endl << endl;

                    cout << "\n Yeni Ürün Kodu :"; cin >> urunKodu;
                    cout << "\n Yeni Ürün Adı :"; cin >> urunAdi;
                    cout << "\n Yeni Yeni Ürün Üreticisi :"; cin >> urunUreticisi;
                    cout << "\n Yeni Ürün Temin süresi :"; cin >> urunTeminSuresi;
                    cout << "\n Yeni Ürün Üretim Tarihi :"; cin >> urunUretimTarihi;
                    cout << "\n Yeni Ürün Fiyat (genel) :"; cin >> urunFiyatGenel;
                    cout << "\n Yeni Ürün Fiyat(özel) :"; cin >> urunFiyatOzel;
                    cout << "\n Yeni Ürün KDV Oranı :"; cin >> urunKdv;
                    cout << "\n Yeni Ürün Stok Adedi :"; cin >> urunStokAdedi;
                    DosyaYaz << "\n" << urunKodu << " " << urunAdi << " " << urunUreticisi << " "
                        << urunTeminSuresi << " " << urunUretimTarihi << " " << urunFiyatGenel << " "
                        << urunFiyatOzel << " " << urunKdv << " " << urunStokAdedi;
                    gecici = 1;
                }
                else
                {
                    DosyaYaz << "\n" << urunKodu << " " << urunAdi << " " << urunUreticisi << " "
                        << urunTeminSuresi << " " << urunUretimTarihi << " " << urunFiyatGenel << " "
                        << urunFiyatOzel << " " << urunKdv << " " << urunStokAdedi;
                }


            }


            if (gecici == 0)
            {
                cout << "/n Aradığınız kod ile ürün yoktur" << endl;
            }
            DosyaYaz.close();
            DosyaOku.close();
            remove("urun.txt");// urun.txt dosyasından seçilen ürün silinir.
            rename("duzenurun.tmp", "urun.txt"); //duzenurun.tmp dosyası urun.txt dosyası olarak değişir.


        }

        if (secim1 == 5) // seçim numarası 5 olursa "ürün silme".
        {

            cout << "Silinecek Ürünün Kodunu Giriniz : ";
            cin >> silUrunKod;
            ifstream DosyaOku("urun.txt");
            ofstream DosyaYaz("urunsil.tmp");//Gecici bir dosya açılır
            while (!(DosyaOku.eof())) // urun.txt dosyasını sonuna kadar okur.
            {
                DosyaOku >> urunKodu >> urunAdi >> urunUreticisi >> urunTeminSuresi >> urunUretimTarihi >> urunFiyatGenel >>
                    urunFiyatOzel >> urunKdv >> urunStokAdedi;
                if (silUrunKod == urunKodu)
                {
                    cout << "  >>Ürün Bilgileri<<" << endl;
                    cout << "\n Ürün Kodu :" << urunKodu << endl;
                    cout << "\n Ürün Adı :" << urunAdi << endl;
                    cout << "\n Ürün Üreticisi :" << urunUreticisi << endl;
                    cout << "\n Ürün Temin süresi :" << urunTeminSuresi << endl;
                    cout << "\n Ürün Üretim Tarihi :" << urunUretimTarihi << endl;
                    cout << "\n Ürün Fiyat (genel) :" << urunFiyatGenel << endl;
                    cout << "\n Ürün Fiyat(özel) :" << urunFiyatOzel << endl;
                    cout << "\n Ürün KDV Oranı :" << urunKdv << endl;
                    cout << "\n Ürün Stok Adedi :" << urunStokAdedi << endl << endl;
                    cout << "/n  Ürün Silme İşlemi Başarıyla Gerçekleşti " << endl;
                }
                else
                {
                    DosyaYaz << "\n" << urunKodu << " " << urunAdi << " " << urunUreticisi << " "
                        << urunTeminSuresi << " " << urunUretimTarihi << " " << urunFiyatGenel << " "
                        << urunFiyatOzel << " " << urunKdv << " " << urunStokAdedi;
                }


            }

            DosyaYaz.close();
            DosyaOku.close();
            remove("urun.txt"); //dosyayı sildim
            rename("urunsil.tmp", "urun.txt");   // gecici dosyalar ürün silindikten sonra ürün dosyasına aktarılır

            ifstream DosyaOku_("sipariş.txt");
            ofstream DosyaYaz_("silspr.tmp");//Gecici bir dosya açılır
            while (!(DosyaOku_.eof())) // sipariş.txt dosyasını sonuna kadar okur.
            {
                DosyaOku_ >> siparisKodu >> firmaNo >> siparisTarihi >> siparisTutari
                    >> siparisListesi >> siparisAlan >> siparisUrunKodu >> siparisUrunAdedi;

                if (silUrunKod == siparisUrunKodu) // eğer silinen ürünle ilgili sipariş  varsa siparişi de siler 
                {
                    cout << " Sipariş Bilgileri \n";
                    cout << " Sipariş Kodu :" << siparisKodu << endl;
                    cout << " Firma No :" << firmaNo << endl;
                    cout << " Sipariş Tarihi :" << siparisTarihi << endl;
                    cout << " Sipariş Tutarı : " << siparisTutari << endl;
                    cout << " Sipariş Listesi Dosyası :" << siparisListesi << endl;
                    cout << " Siparişi Alan :" << siparisAlan << endl;
                    cout << " Sipariş Ürün Kodu :" << siparisUrunKodu << endl;
                    cout << " Sipariş Ürün Adedi :" << siparisUrunAdedi << endl;
                    cout << " Ürünü Sildiğiniz İçin Sipariş Silme İşlemi Başarıyla Gerçekleşti " << endl;
                }
                else
                {
                    DosyaYaz_ << "\n" << siparisKodu << " " << firmaNo << " " << siparisTarihi << " " << siparisTutari << " " <<
                        siparisListesi << " " << siparisAlan << " " << siparisUrunKodu << " " << siparisUrunAdedi;
                }

            }

            DosyaYaz_.close();
            DosyaOku_.close();
            remove("sipariş.txt");//dosyayi sildim.
            rename("silspr.tmp", "sipariş.txt");//Gecici dosyalar kayıt silindikten tmp dosyasi txt dosyasina aktarılır.




        }

    }

    if (numara == 2)// başlangıç ekranında numara 2 yi seçerse müşteri işlemleri 
    {
        cout << "  >>2-MÜŞTERİ DOSYASI İŞLEMLERİ<<" << endl;
        cout << "    1) Müşteri Ekle" << endl;
        cout << "    2) Müşteri Arama" << endl;
        cout << "    3) Müşteri Düzeltme" << endl;
        cout << "    4) Müşteri Silme" << endl;
        cout << " =>  Lütfen yukarıdan yapmak istediğiniz işlemin numarasını yazınız" << endl;
        cin >> secim2;
        if (secim2 == 1)
        {
            cout << "   *1-Müşteri Ekleme* " << endl;
            ofstream DosyaYaz;
            DosyaYaz.open("cari.txt", ios::app);
            do
            {
                cout << "\n Firma No :"; cin >> firmaNo;
                cout << "\n Firma Adı :"; cin >> firmaAdi;
                cout << "\n Firma Telefon :"; cin >> firmaTel;
                cout << "\n Firma Sorumlusu :"; cin >> firmaSorumlusu;
                cout << "\n Müşteri Katagorisi(genel-özel) :"; cin >> musteriKatagori;
                cout << " \n Adres :"; cin >> musteriAdres;
                DosyaYaz << "\n" << firmaNo << " " << firmaAdi << " " << firmaTel << " " <<
                    firmaSorumlusu << " " << musteriKatagori << " " << musteriAdres;
                cout << "  Müşteri eklendi " << endl;
                cout << "Müşteri Eklemeye Devam Edecek Misiniz?(e/h) " << endl; cin >> cevap;
            } while (!(cevap == 'h'));

            DosyaYaz.close();
        }

        if (secim2 == 2)  // seçim numarası 2 olursa "müşteri arama".
        {

            ifstream DosyaOku;
            DosyaOku.open("cari.txt");
            cout << " *2-Müşteri Arama*" << endl;
            cout << " Aradığınız müşterinin firma numarasını giriniz :" << endl;
            cin >> araFirmaNo;
            bool bulundu_mu = false;
            while ((!DosyaOku.eof())) //cari.txt dosyasını sonuna kadar okumayı sağlar    
            {
                DosyaOku >> firmaNo >> firmaAdi >> firmaTel >>
                    firmaSorumlusu >> musteriKatagori >> musteriAdres;
                if (araFirmaNo == firmaNo)// Eğer aranan firma no dosyadakiyle aynıysa müşteri bilgilerini ekrana yazar
                {
                    cout << "\n Müşteri Bilgileri \n";
                    cout << "\n Firma No :" << firmaNo;
                    cout << "\n Firma Adı :" << firmaAdi;
                    cout << "\n Firma Telefon :" << firmaTel;
                    cout << "\n Firma Sorumlusu :" << firmaSorumlusu;
                    cout << "\n Müşteri Katagorisi(genel-özel) :" << musteriKatagori;
                    cout << " \n Adres :" << musteriAdres;
                    bulundu_mu = true;
                }

            }
            DosyaOku.close();
            if (!bulundu_mu)   // Aranan firma no  dosyada yoksa müşteri yoktur yazar
                cout << "  Aradığınız firma numarasıyla eşleşen müşteri yoktur  " << endl;
        }

        if (secim2 == 3)   // seçim numarası 3 olursa "müşteri düzeltme".
        {

            cout << "* 3-Müşteri Bilgileri Düzenleme *" << endl;
            ifstream DosyaOku("cari.txt");
            ofstream DosyaYaz("duzenmus.tmp");
            cout << " Düzenlenecek Müşterinin Firma Numarasını Giriniz : " << endl;
            cin >> duzenFirmaNo;
            while (!(DosyaOku.eof()))  // cari.txt dosyasını sonuna kadar okuttum.
            {

                DosyaOku >> firmaNo >> firmaAdi >> firmaTel >>
                    firmaSorumlusu >> musteriKatagori >> musteriAdres;
                if (duzenFirmaNo == firmaNo)
                {
                    cout << "\n Müşteri Bilgileri \n";
                    cout << "\n Firma No :" << firmaNo;
                    cout << "\n Firma Adı :" << firmaAdi;
                    cout << "\n Firma Telefon :" << firmaTel;
                    cout << "\n Firma Sorumlusu :" << firmaSorumlusu;
                    cout << "\n Müşteri Katagorisi(genel-özel) :" << musteriKatagori;
                    cout << " \n Adres :" << musteriAdres;
                    cout << "  Ürün Bilgilerini Tekrar Giriniz " << endl << endl;

                    cout << "\n Yeni Firma No :"; cin >> firmaNo;
                    cout << "\n Yeni Firma Adı :"; cin >> firmaAdi;
                    cout << "\n Yeni Firma Telefon :"; cin >> firmaTel;
                    cout << "\n Yeni Firma Sorumlusu :"; cin >> firmaSorumlusu;
                    cout << "\n Yeni Müşteri Katagorisi(genel-özel) :"; cin >> musteriKatagori;
                    cout << " \n Yeni Adres :"; cin >> musteriAdres;
                    DosyaYaz << " \n" << firmaNo << " " << firmaAdi << " " << firmaTel << " " <<
                        firmaSorumlusu << " " << musteriKatagori << " " << musteriAdres;
                    gecici = 1;
                    break;
                }

                else {
                    DosyaYaz << " \n" << firmaNo << " " << firmaAdi << " " << firmaTel << " " <<
                        firmaSorumlusu << " " << musteriKatagori << " " << musteriAdres;
                }

                if (gecici == 0)
                {
                    cout << "\n Aradığınız firma numarası ile müşteri yoktur" << endl;
                }


            }
            DosyaYaz.close();
            DosyaOku.close();
            remove("cari.txt");// cari.txt dosyasından seçilen müşteri silinir.
            rename("duzenmus.tmp", "cari.txt");//duzenmus.tmp dosyası cari.txt dosyası olarak değişir.

        }

        if (secim2 == 4)   // seçim numarası 4 olursa "müşteri silme".
        {
            cout << " *Müşteri Silme*" << endl;
            cout << "Silinecek Müşterinin Firma Numarasını  Giriniz : ";
            cin >> silFirmaNo;
            ifstream DosyaOku("cari.txt");
            ofstream DosyaYaz("silmus.tmp");//Gecici bir dosya açılır
            while (!(DosyaOku.eof())) // cari.txt dosyasını sonuna kadar okur.
            {
                DosyaOku >> firmaNo >> firmaAdi >> firmaTel >>
                    firmaSorumlusu >> musteriKatagori >> musteriAdres;

                if (silFirmaNo == firmaNo)
                {
                    cout << "\n Müşteri Bilgileri \n";
                    cout << "\n Firma No :" << firmaNo;
                    cout << "\n Firma Adı :" << firmaAdi;
                    cout << "\n Firma Telefon :" << firmaTel;
                    cout << "\n Firma Sorumlusu :" << firmaSorumlusu;
                    cout << "\n Müşteri Katagorisi(genel-özel) :" << musteriKatagori;
                    cout << " \n Adres :" << musteriAdres;
                    cout << "\n  Müşteri Silme İşlemi Başarıyla Gerçekleşti " << endl;
                    break;
                }
                else
                {
                    DosyaYaz << "\n" << firmaNo << " " << firmaAdi << " " << firmaTel << " " <<
                        firmaSorumlusu << " " << musteriKatagori << " " << musteriAdres << endl;
                }
            }
            DosyaYaz.close();
            DosyaOku.close();
            remove("cari.txt");   // Seçilen müşteri silinir
            rename("silmus.tmp", "cari.txt");  //Gecici dosyalar kayıt silindikten silmus.tmp dosyası cari.txt dosyasina aktarılır


            ifstream DosyaOku_("sipariş.txt");
            ofstream DosyaYaz_("silspr.tmp");//Gecici bir dosya açılır
            while (!(DosyaOku_.eof())) // sipariş.txt dosyasını sonuna kadar okur.
            {
                DosyaOku_ >> siparisKodu >> firmaNo >> siparisTarihi >> siparisTutari
                    >> siparisListesi >> siparisAlan >> siparisUrunKodu >> siparisUrunAdedi;

                if (silFirmaNo == firmaNo)
                {
                    cout << endl;
                    cout << " Sipariş Bilgileri \n";
                    cout << " Sipariş Kodu :" << siparisKodu << endl;
                    cout << " Firma No :" << firmaNo << endl;
                    cout << " Sipariş Tarihi :" << siparisTarihi << endl;
                    cout << " Sipariş Tutarı : " << siparisTutari << endl;
                    cout << " Sipariş Listesi Dosyası :" << siparisListesi << endl;
                    cout << " Siparişi Alan :" << siparisAlan << endl;
                    cout << " Sipariş Ürün Kodu :" << siparisUrunKodu << endl;
                    cout << " Sipariş Ürün Adedi :" << siparisUrunAdedi << endl;
                    cout << "  Müşteri Silindiği İçin Sipariş Silme İşlemi Başarıyla Gerçekleşti " << endl;
                }
                else
                {
                    DosyaYaz_ << "\n" << siparisKodu << " " << firmaNo << " " << siparisTarihi << " " << siparisTutari << " " <<
                        siparisListesi << " " << siparisAlan << " " << siparisUrunKodu << " " << siparisUrunAdedi;
                }

            }

            DosyaYaz_.close();
            DosyaOku_.close();
            remove("sipariş.txt");//dosyayi sildim.
            rename("silspr.tmp", "sipariş.txt");//Gecici dosyalar kayıt silindikten tmp dosyasi txt dosyasina aktarılır.



        }



    }

    if (numara == 3) // başlangıç ekranında numara 3'ü seçerse sipariş işlemleri
    {
        cout << "  >>SİPARİŞ İLE İLGİLİ İŞLEMLER<<" << endl;
        cout << "    1) Sipariş Oluştur" << endl;
        cout << "    2) Sipariş Arama" << endl;
        cout << "    3) Sipariş Silme" << endl;
        cout << "    4) Sipariş Düzeltme" << endl;
        cout << "    5) Sipariş Raporlama" << endl;
        cout << " =>  Lütfen yukarıdan yapmak istediğiniz işlemin numarasını yazınız" << endl;
        cin >> secim3;
        if (secim3 == 1)
        {
            cout << " * 1-Sipariş Oluşturma* " << endl;
            ofstream DosyaYaz;
            DosyaYaz.open("sipariş.txt", ios::app);
            do
            {
                cout << " Sipariş Kodu :"; cin >> siparisKodu;
                cout << " Firma No :"; cin >> firmaNo;
                cout << " Sipariş Tarihi :"; cin >> siparisTarihi;
                cout << " Sipariş Tutarı :"; cin >> siparisTutari;
                cout << " Sipariş Listesi Dosyası :"; cin >> siparisListesi;
                cout << " Siparişi Alan :"; cin >> siparisAlan;
                cout << " Sipariş Ürün Kodu :"; cin >> siparisUrunKodu;
                cout << " Sipariş Ürün Adedi :"; cin >> siparisUrunAdedi;
                DosyaYaz << "\n" << siparisKodu << " " << firmaNo << " " << siparisTarihi << " " << siparisTutari << " "
                    << siparisListesi << " " << siparisAlan << " " << siparisUrunKodu << " " << siparisUrunAdedi;
                cout << " \n Sipariş Oluşturuldu " << endl;
                cout << "Sipariş Oluşturmaya Devam Edecek Misiniz? (e/h) " << endl; cin >> cevap;
            } while (!(cevap == 'h'));
            DosyaYaz.close();
        }

        if (secim3 == 2) {    // seçim numarası 2 olursa "sipariş arama".

            ifstream DosyaOku;
            DosyaOku.open("sipariş.txt");
            cout << " * 2-Sipariş Arama*" << endl;
            cout << " Aradığınız siparişin kodunu giriniz :";
            cin >> araSiparisKod;
            bool bulundu_mu = false;
            while (!DosyaOku.eof())   //sipariş.txt dosyasını sonuna kadar okumayı sağlar
            {
                DosyaOku >> siparisKodu >> firmaNo >> siparisTarihi >> siparisTutari
                    >> siparisListesi >> siparisAlan >> siparisUrunKodu >> siparisUrunAdedi;


                if (araSiparisKod == siparisKodu)  // Eğer aranan ürün kodu dosyadakiyle aynıysa ürün bilgilerini ekrana yazar
                {
                    cout << "\n Sipariş Bilgileri \n";
                    cout << " Sipariş Kodu :" << siparisKodu << endl;
                    cout << " Firma No :" << firmaNo << endl;
                    cout << " Sipariş Tarihi :" << siparisTarihi << endl;
                    cout << " Sipariş Tutarı :" << siparisTutari << endl;
                    cout << " Sipariş Listesi Dosyası :" << siparisListesi << endl;
                    cout << " Siparişi Alan :" << siparisAlan << endl;
                    cout << " Sipariş Ürün Kodu : " << siparisUrunKodu << endl;
                    cout << " Sipariş Ürün Adedi : " << siparisUrunAdedi << endl;
                    bulundu_mu = true;
                }

            }DosyaOku.close();

            if (!bulundu_mu) // sipariş kodu dosyada yoksa sipariş yoktur yazar
                cout << "  Aradığınız sipariş koduyla eşleşen ürün yoktur";

        }


        if (secim3 == 3)// seçim numarası 3 olursa "sipariş silme".
        {
            cout << "  *3-Sipariş Silme*" << endl;
            cout << "Silinecek Siparişin Kodunu Giriniz : ";
            cin >> silSiparisKod;
            ifstream DosyaOku("sipariş.txt");
            ofstream DosyaYaz("silspr.tmp");//Gecici bir dosya açılır
            while (!(DosyaOku.eof())) // sipariş.txt dosyasını sonuna kadar okur.
            {
                DosyaOku >> siparisKodu >> firmaNo >> siparisTarihi >> siparisTutari
                    >> siparisListesi >> siparisAlan >> siparisUrunKodu >> siparisUrunAdedi;

                if (silSiparisKod == siparisKodu)
                {
                    cout << " Sipariş Bilgileri \n";
                    cout << " Sipariş Kodu :" << siparisKodu << endl;
                    cout << " Firma No :" << firmaNo << endl;
                    cout << " Sipariş Tarihi :" << siparisTarihi << endl;
                    cout << " Sipariş Tutarı : " << siparisTutari << endl;
                    cout << " Sipariş Listesi Dosyası :" << siparisListesi << endl;
                    cout << " Siparişi Alan :" << siparisAlan << endl;
                    cout << " Sipariş Ürün Kodu : " << siparisUrunKodu << endl;
                    cout << " Sipariş Ürün Adedi : " << siparisUrunAdedi << endl;
                    cout << " Silme İşlemi Başarıyla Gerçekleşti " << endl;
                }
                else
                {
                    DosyaYaz << "\n" << siparisKodu << " " << firmaNo << " " << siparisTarihi << " " << siparisTutari << " " <<
                        siparisListesi << " " << siparisAlan << " " << siparisUrunKodu << " " << siparisUrunAdedi;
                }

            }

            DosyaYaz.close();
            DosyaOku.close();
            remove("sipariş.txt");//dosyayi sildim.
            rename("silspr.tmp", "sipariş.txt");//Gecici dosyalar kayıt silindikten tmp dosyasi txt dosyasina aktarılır.


        }

        if (secim3 == 4)
        {

            cout << "*4-Sipariş Bilgileri Düzenleme*" << endl;
            ifstream DosyaOku("sipariş.txt");
            ofstream DosyaYaz("duzspr.tmp");
            cout << " Düzenlenecek Siparişin Kodunu Giriniz : ";
            cin >> duzenSiparisKod;
            while (!(DosyaOku.eof())) // sipariş.txt dosyasını sonuna kadar okuttum
            {
                DosyaOku >> siparisKodu >> firmaNo >> siparisTarihi >> siparisTutari
                    >> siparisListesi >> siparisAlan >> siparisUrunKodu >> siparisUrunAdedi;
                if (duzenSiparisKod == siparisKodu)
                {
                    cout << "\n Sipariş Bilgileri \n";
                    cout << "  Sipariş Kodu :" << siparisKodu << endl;
                    cout << "  Firma No :" << firmaNo << endl;
                    cout << "  Sipariş Tarihi :" << siparisTarihi << endl;
                    cout << "  Sipariş Tutarı :" << siparisTutari << endl;
                    cout << "  Sipariş Listesi Dosyası :" << siparisListesi << endl;
                    cout << "  Siparişi Alan :" << siparisAlan << endl;
                    cout << "  Sipariş Ürün Kodu : " << siparisUrunKodu << endl;
                    cout << "  Sipariş Ürün Adedi : " << siparisUrunAdedi << endl;
                    cout << "  Ürün Bilgilerini Tekrar Giriniz " << endl << endl;

                    cout << "\n  Yeni Sipariş Kodu :"; cin >> siparisKodu;
                    cout << "\n  Yeni Firma No :"; cin >> firmaNo;
                    cout << "\n  Yeni Sipariş Tarihi :"; cin >> siparisTarihi;
                    cout << "\n  Yeni Sipariş Tutarı :"; cin >> siparisTutari;
                    cout << "\n  Yeni Sipariş Listesi Dosyası :"; cin >> siparisListesi;
                    cout << "\n  Yeni Siparişi Alan :"; cin >> siparisAlan;
                    cout << "\n  Sipariş Ürün Kodu :"; cin >> siparisUrunKodu;
                    cout << "\n  Sipariş Ürün Adedi :";  cin >> siparisUrunAdedi;
                    DosyaYaz << "\n" << siparisKodu << " " << firmaNo << " " << siparisTarihi << " " << siparisTutari << " " <<
                        siparisListesi << " " << siparisAlan << " " << siparisUrunKodu << " " << siparisUrunAdedi;;
                    gecici = 1;
                }
                else
                {
                    DosyaYaz << "\n" << siparisKodu << " " << firmaNo << " " << siparisTarihi << " " << siparisTutari << " " <<
                        siparisListesi << " " << siparisAlan << "  " << siparisUrunKodu << " " << siparisUrunAdedi;
                }


            }


            if (gecici == 0)
            {
                cout << "\n Aradığınız kod ile sipariş yoktur" << endl;
            }
            DosyaYaz.close();
            DosyaOku.close();
            remove("sipariş.txt");// sipariş.txt dosyasından seçilen ürün silinir.
            rename("duzspr.tmp", "sipariş.txt");//gecici.tmp dosyası urun.txt dosyası olarak değişir.


        }

        if (secim3 == 5)//seçim numarası 5 olursa "sipariş raporlama".
        {
            cout << " *5-Sipariş Raporlama* " << endl << endl;
            ifstream DosyaOku("sipariş.txt");
            while (!(DosyaOku.eof())) //sipariş.txt dosyasını sonuna kadar okur
            {
                DosyaOku >> siparisKodu >> firmaNo >> siparisTarihi >> siparisTutari
                    >> siparisListesi >> siparisAlan >> siparisUrunKodu >> siparisUrunAdedi;
                cout << "\n    Sipariş Bilgileri \n";
                cout << " Sipariş Kodu :" << siparisKodu << endl;
                cout << " Firma No :" << firmaNo << endl;
                cout << " Sipariş Tarihi :" << siparisTarihi << endl;
                cout << " Sipariş Tutarı :" << siparisTutari << endl;
                cout << " Sipariş Listesi Dosyası :" << siparisListesi << endl;
                cout << " Siparişi Alan :" << siparisAlan << endl;
                cout << " Sipariş Ürün Kodu : " << siparisUrunKodu << endl;
                cout << " Sipariş Ürün Adedi : " << siparisUrunAdedi << endl;


            }
            DosyaOku.close(); //dosya okumayı kapattım.


        }







    }
}


