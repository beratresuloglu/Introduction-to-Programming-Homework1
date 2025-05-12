									/*****************************************************************
									**					 SAKARYA ÜNİVERSİTESİ						**
									**			 BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ	 		**
									**				BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ					**
									**				  PROGRAMLAMAYA GİRİŞ DERSİ						**
									**																**
									**			 ÖDEV NUMARASI.....: 1								**
									**           ÖĞRENCİ ADI.......: BERAT RESULOĞLU				**
									**		     ÖĞRENCİ NUMARASI..: B231210050						**
									**			 DERS GRUBU........: B GRUBU (CÜNEYT BAYILMIŞ)		**
									*****************************************************************/


#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>;
#include <string>;
#include <vector>;
#include <locale.h>
#include <cmath>;
using namespace std;


int main()
{
	// Çıktı ekranında Türkçe karakterler görebilmek için Türkçe karakter kütüphanesini ekliyorum.
	setlocale(LC_ALL, "Turkish");

	// Student isimli yapı veri tipini tanımlayıp öğrencilerin bilgilerini tanımlıyorum.
	struct student
	{
		string name;
		string surName;
		int midTermGrade = 0;
		int homeWork1 = 0;
		int homeWork2 = 0;
		int quiz1 = 0;
		int quiz2 = 0;
		int midYearGrade = 0;
		int finalGrade = 0;
		float yearEndGrade = 0;
		string yearEndGradeLetter;

	};

	// names dizisi oluşturuyorum.
	string names[50] = { "Ahmet", "Ayşe", "Mehmet", "Fatma",
		"Mustafa", "Zeynep", "Ahmet", "Elif", "Emir", "Ebru",
		"Hüseyin", "Selin", "Cem", "Leyla", "Burak", "Yasmin",
		"Erdem", "Aysel", "Can", "Merve", "Oğuz", "Ayla", "Baran",
		"Nil", "Özgür", "Belgin", "Serkan", "Deniz", "Tuğba", "Furkan",
		"Ece", "Arda", "Şule", "Volkan", "Zara", "Alp", "Selma", "Tuncay",
		"Sedef", "Taylan", "Lale", "Serdar", "Asuman", "Serap", "Uğur",
		"Gamze","Alper", "Nihal", "Seray", "İlker" };

	// surNames dizisi oluşturuyorum.
	string surNames[50] = { "Yılmaz", "Kaya", "Demir", "Çelik", "Öztürk",
		"Kara", "Yıldırım", "Özdemir", "Arslan", "Koç", "Güneş", "Türk",
		"Şahin", "Kurt", "Yalçın", "Kaplan", "Gül", "Topal", "Aksoy",
		"Yılmazer", "Acar", "Sarı", "Bulut", "Eren", "Kocaman", "Öztürkmen",
		"Taş", "Bozkurt", "Karadağ", "Çetin", "Aydın", "Türkoğlu", "Aktaş",
		"Bilgin", "Gür", "Erdoğan", "Tuncer", "Uysal", "Duman", "Söylemez",
		"Avcı", "Bakır", "Karadeniz", "Bayram", "Karagöz", "Küçük", "Kurtuluş",
		"Genç", "Büyükgöz", "Turan" };


	srand(time(0));  // Her seferinde farklı bir isim ve soyisim seçmesi için srand(time(0)) komutunu kullanıyorum.

	int numberOfStudents;
	cout << "Lütfen sınıf mevcudunu tam sayı olacak biçimde giriniz:  ";      // Kullanıcıdan sınıf mevcudunu istiyorum.
	cin >> numberOfStudents;
	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << setw(53) << "SINIFTAKİ ÖĞRENCİLER" << endl;
	cout << "------------------------------------------------------------------------------------------------" << endl;

	vector <student> students;  // Dinamik bir dizi yapısı kullanacağım için vector tanımlıyorum. 

	
	for (int i = 0; i < numberOfStudents; i++)	// names ve surNames dizilerinden öğrenci sayısı kadar rastgele ad ve soyadlar seçiyorum.
	{
		student knowLedges;
		int index = rand() % 50;
		knowLedges.name = names[index];
		index = rand() % 50;
		knowLedges.surName = surNames[index];
		students.push_back(knowLedges);
	}

	for (int i = 0; i < numberOfStudents; i++)	// öğrenci sayısı kadar seçilen ad ve soyadları birleştirip yazdırıyorum.
	{
		cout << i + 1 << ")" << students[i].name << " " << students[i].surName << endl;
	}

	cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << setw(65) << "ÖĞRENCİLERİN ALDIĞI NOTLAR" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl;

	int twentyPercentOfStudents = numberOfStudents * 0.2;
	int thirtyPercentOfStudents = numberOfStudents * 0.3;
	int fiftyPercentOfStudents = numberOfStudents - (twentyPercentOfStudents + thirtyPercentOfStudents);


	// öğrenci sayısının yüzde yirmisi kadar 80-100 aralığından random not seçip random bir öğrenciye atıyorum
	for (int i = 0; i < twentyPercentOfStudents; i++) 
	{
		int randomGrade = 80 + (rand() % 21);	// 80-100 aralığından rastgele bir not seç.
		int randomStudentIndex = rand() % numberOfStudents;		// Sınıftan rastgele bir öğrenci seç.

		while (students[randomStudentIndex].midTermGrade != 0)		// Random seçilen öğrencinin notu daha önce atanmışsa
		{
			randomStudentIndex = rand() % numberOfStudents;		// Tekrar random bir öğrenci seç		
		}
		students[randomStudentIndex].midTermGrade = randomGrade;	// Rastgele verilen notu rastgele bir öğrencinin vize puanına ata.


		randomGrade = 80 + (rand() % 21);
		randomStudentIndex = rand() % numberOfStudents;

		while (students[randomStudentIndex].homeWork1 != 0)
		{
			randomStudentIndex = rand() % numberOfStudents;
		}
		students[randomStudentIndex].homeWork1 = randomGrade;


		randomGrade = 80 + (rand() % 21);
		randomStudentIndex = rand() % numberOfStudents;

		while (students[randomStudentIndex].homeWork2 != 0)
		{
			randomStudentIndex = rand() % numberOfStudents;
		}
		students[randomStudentIndex].homeWork2 = randomGrade;


		randomGrade = 80 + (rand() % 21);
		randomStudentIndex = rand() % numberOfStudents;

		while (students[randomStudentIndex].quiz1 != 0)
		{
			randomStudentIndex = rand() % numberOfStudents;
		}
		students[randomStudentIndex].quiz1 = randomGrade;


		randomGrade = 80 + (rand() % 21);
		randomStudentIndex = rand() % numberOfStudents;

		while (students[randomStudentIndex].quiz2 != 0)
		{
			randomStudentIndex = rand() % numberOfStudents;
		}
		students[randomStudentIndex].quiz2 = randomGrade;

		randomGrade = 80 + (rand() % 21);
		randomStudentIndex = rand() % numberOfStudents;

		while (students[randomStudentIndex].finalGrade != 0)
		{
			randomStudentIndex = rand() % numberOfStudents;
		}
		students[randomStudentIndex].finalGrade = randomGrade;
	}

	// öğrenci sayısının yüzde otuzu kadar 0-50 arasından random bir not belirleyip random bir öğrenciye atıyorum
	for (int i = 0; i < thirtyPercentOfStudents; i++) 
	{
		int randomGrade = (rand() % 51);   // 0-50 aralığından rastgele sayılar seç
		int randomStudentIndex = rand() % numberOfStudents;   // Rastgele bir öğrenci seç

		while (students[randomStudentIndex].midTermGrade != 0) // Öğrencinin vize notu daha çnce atanmışsa
		{
			randomStudentIndex = rand() % numberOfStudents;  // Rastgele başka bir öğrenci seç
		}
		students[randomStudentIndex].midTermGrade = randomGrade;  // Rastgele verilen notu öğrencinin vize notuna ata


		randomGrade = (rand() % 51);
		randomStudentIndex = rand() % numberOfStudents;

		while (students[randomStudentIndex].homeWork1 != 0)
		{
			randomStudentIndex = rand() % numberOfStudents;
		}
		students[randomStudentIndex].homeWork1 = randomGrade;



		randomGrade = (rand() % 51);
		randomStudentIndex = rand() % numberOfStudents;

		while (students[randomStudentIndex].homeWork2 != 0)
		{
			randomStudentIndex = rand() % numberOfStudents;
		}
		students[randomStudentIndex].homeWork2 = randomGrade;

		randomGrade = (rand() % 51);
		randomStudentIndex = rand() % numberOfStudents;

		while (students[randomStudentIndex].quiz1 != 0)
		{
			randomStudentIndex = rand() % numberOfStudents;
		}
		students[randomStudentIndex].quiz1 = randomGrade;

		randomGrade = (rand() % 51);
		randomStudentIndex = rand() % numberOfStudents;

		while (students[randomStudentIndex].quiz2 != 0)
		{
			randomStudentIndex = rand() % numberOfStudents;
		}
		students[randomStudentIndex].quiz2 = randomGrade;

		randomGrade = (rand() % 51);
		randomStudentIndex = rand() % numberOfStudents;

		while (students[randomStudentIndex].finalGrade != 0)
		{
			randomStudentIndex = rand() % numberOfStudents;
		}
		students[randomStudentIndex].finalGrade = randomGrade;

	}

	// öğrenci sayısının yüzde ellisi kadar 50-80 arasından random bir not seçip random bir öğrenciye atıyorum
	for (int i = 0; i < fiftyPercentOfStudents; i++)
	{
		int randomGrade = 50 + (rand() % 31);  // 50-80 aralığından rastgele bir sayı seç
		int randomStudentIndex = rand() % numberOfStudents;  // Rastgele bir öğrenci seç

		while (students[randomStudentIndex].midTermGrade != 0)  // Öğrencinin vize notu daha önce atanmışsa
		{
			randomStudentIndex = rand() % numberOfStudents;  // Rastgele başka bir öğrenci seç
		}
		students[randomStudentIndex].midTermGrade = randomGrade;  // Rastgele verilen notu öğrencinin vize notuna ata

		randomGrade = 50 + (rand() % 31);
		randomStudentIndex = rand() % numberOfStudents;

		while (students[randomStudentIndex].homeWork1 != 0)
		{
			randomStudentIndex = rand() % numberOfStudents;
		}
		students[randomStudentIndex].homeWork1 = randomGrade;


		randomGrade = 50 + (rand() % 31);
		randomStudentIndex = rand() % numberOfStudents;

		while (students[randomStudentIndex].homeWork2 != 0)
		{
			randomStudentIndex = rand() % numberOfStudents;
		}
		students[randomStudentIndex].homeWork2 = randomGrade;

		randomGrade = 50 + (rand() % 31);
		randomStudentIndex = rand() % numberOfStudents;

		while (students[randomStudentIndex].quiz1 != 0)
		{
			randomStudentIndex = rand() % numberOfStudents;
		}
		students[randomStudentIndex].quiz1 = randomGrade;

		randomGrade = 50 + (rand() % 31);
		randomStudentIndex = rand() % numberOfStudents;

		while (students[randomStudentIndex].quiz2 != 0)
		{
			randomStudentIndex = rand() % numberOfStudents;
		}
		students[randomStudentIndex].quiz2 = randomGrade;

		randomGrade = 50 + (rand() % 31);
		randomStudentIndex = rand() % numberOfStudents;

		while (students[randomStudentIndex].finalGrade != 0)
		{
			randomStudentIndex = rand() % numberOfStudents;
		}
		students[randomStudentIndex].finalGrade = randomGrade;

	}

	// Öğrencilerin adını,soyadını,vize notunu,ödev notlarını ve kısa sınav notlarını ekrana yazdırıyorum. 
	for (int i = 0; i < numberOfStudents; i++)
	{
		cout << i + 1 << ")" << left << students[i].name << " " << students[i].surName << left << "\t\t" << "Vize:" << students[i].midTermGrade << left << "\t\t" << " Ödev1:" << students[i].homeWork1 << left << "\t " << " Ödev2:" << students[i].homeWork2 << left << "\t " << "Quiz1:" << students[i].quiz1 << left << "\t" << "Quiz2:" << students[i].quiz2 << left << "\t" << "Final:" << students[i].finalGrade << endl;
	}



	float midTermWeight;
	float homeWork1Weight;
	float homeWork2Weight;
	float quiz1Weight;
	float quiz2Weight;
	float midYearWeight;
	float finalWeight;
	float totalGrade = 0;
	float meanGrade = 0;
	float maxGrade = 0;
	float minGrade = 100;

	// Kullanıcıdan vize,ödev ve kısa sınavların yüzdelerini alıyorum.
	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << setw(53) << "SINAV AĞIRLIKLARI" << endl;
	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << "\nLütfen 1 sınav, 2 quiz ve 2 ödevin yüzde kaçının hesaplanacağını toplamda 100 olacak şekilde giriniz: " << endl;
	cout << "(ör. Vize için:50, 1.Ödev için:15, 2.Ödev için:15, 1.Quiz için:10, 2.Quiz için:10 )" << endl;
	cout << "\nVize için:  ";
	cin >> midTermWeight;
	cout << "1.Ödev için:  ";
	cin >> homeWork1Weight;
	cout << "2.Ödev için  ";
	cin >> homeWork2Weight;
	cout << "1.Quiz için:  ";
	cin >> quiz1Weight;
	cout << "2.Quiz için : ";
	cin >> quiz2Weight;
	cout << "\nLütfen yıl içi notunun ve final notunun geçme puanına etkisini toplam 100 olacak şekilde giriniz:" << endl;
	cout << "(ör. Yıl içi notu için:40, Final notu için:60)" << endl;
	cout << "\nYıl içi notu için:";
	cin >> midYearWeight;
	cout << "Final sınavı için:";
	cin >> finalWeight;

	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << setw(53) << "YIL SONU NOTLARI" << endl;
	cout << "------------------------------------------------------------------------------------------------" << endl;

	// Kullanıcıdan alınan yüzdeleri 100'e bölerek ağırlıkları oluşturuyorum
	midTermWeight = midTermWeight / 100;
	homeWork1Weight = homeWork1Weight / 100;
	homeWork2Weight = homeWork2Weight / 100;
	quiz1Weight = quiz1Weight / 100;
	quiz2Weight = quiz2Weight / 100;
	midYearWeight = midYearWeight / 100;
	finalWeight = finalWeight / 100;

	
	for (int i = 0; i < numberOfStudents; i++)
	{
		// Yıl içi, final ve yıl sonu notlarını hesaplatıp ekrana yazdırıyorum
		students[i].midYearGrade = (students[i].midTermGrade * midTermWeight) + (students[i].homeWork1 * homeWork1Weight) + (students[i].homeWork2 * homeWork2Weight) + (students[i].quiz1 * quiz1Weight) + (students[i].quiz2 * quiz2Weight);
		students[i].yearEndGrade = (students[i].midYearGrade * midYearWeight) + (students[i].finalGrade * finalWeight) ;
		cout << students[i].name << " " << students[i].surName << "\t" << "Yıl içi puanı: " << students[i].midYearGrade << "\t" << "Final puanı: " << students[i].finalGrade << "      " << "AĞIRLIKLI YIL SONU PUANI: " << students[i].yearEndGrade << endl;

		// Sınıf ortalaması, en yüksek notu ve en düşük notunu hesaplatıyorum 
		totalGrade = totalGrade + students[i].yearEndGrade;
		meanGrade = totalGrade / numberOfStudents;

		if (students[i].yearEndGrade < minGrade)
		{
			minGrade = students[i].yearEndGrade;
		}
		if (students[i].yearEndGrade > maxGrade)
		{
			maxGrade = students[i].yearEndGrade;
		}

	}

	// Standart sapmayı bulduruyorum
	float standardDeviation = 0;
	float varyans = 0;
	for (int i = 0; i < numberOfStudents; i++)
	{
		varyans += pow(students[i].yearEndGrade - meanGrade, 2);

	}

	standardDeviation = sqrt(varyans / numberOfStudents);
	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << "En düşük not:" << "\t" << minGrade << endl;
	cout << "En yüksek not:" << "\t" << maxGrade << endl;
	cout << "Sınıf ortalaması:" << "\t" << meanGrade << endl;
	cout << "Sınıfın standart sapması:" << "\t" << standardDeviation << endl;
	cout << "------------------------------------------------------------------------------------------------" << endl;

	// Yıl sonu notu harf karşılıklarını yazdırmak için sayaçlar oluşturuyorum
	float passingGrade;
	int countAA = 0;
	int countBA = 0;
	int countBB = 0;
	int countCB = 0;
	int countCC = 0;
	int countDC = 0;
	int countDD = 0;
	int countFD = 0;
	int countFF = 0;
	float countPassed = 0;
	float countFailed = 0;

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* 
https://www.mevzuat.gov.tr/File/GeneratePdf?mevzuatNo=36104&mevzuatTur=UniversiteYonetmeligi&mevzuatTertip=5#:~:text=MADDE%2017%20%E2%80%93%20(1)%20%C3%96%C4%9Frencilerin,65%2D74%20Zay%C4%B1f%20DC%201
			Başarı Derecesi Harf Notu Başarı Notu Puanı
			Pekiyi AA 4,00 90 - 100
			İyi - Pekiyi BA 3,50 85 - 89
			İyi BB 3,00 80 - 84
			Orta - İyi CB 2,50 75 - 79
			Orta CC 2,00 65 - 74
			Zayıf DC 1,50 58 - 64
			Çok Zayıf DD 1,00 50 - 57
			Başarısız FD 0,50 40 - 49
			Başarısız FF 0,00 39 ve altı 
			*/
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	cout << "\nLütfen sınıf geçme notunu 100'den küçük olacak biçimde belirleyiniz:" << "\t";
	cin >> passingGrade;
	cout << endl;

	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << setw(60) << "YIL SONU NOTLARININ HARF KARŞILIKLARI" << endl;
	cout << "------------------------------------------------------------------------------------------------" << endl;

	// Harf karşılıklarını yazdırıyorum
	for (int i = 0; i < numberOfStudents; i++)
	{
		if (students[i].yearEndGrade >= 90)
		{
			students[i].yearEndGradeLetter = "AA";
			countAA = countAA + 1;
		}
		else if (students[i].yearEndGrade >= 85)
		{
			students[i].yearEndGradeLetter = "BA";
			countBA = countBA + 1;
		}
		else if (students[i].yearEndGrade >= 80)
		{
			students[i].yearEndGradeLetter = "BB";
			countBB = countBB + 1;
		}
		else if (students[i].yearEndGrade >= 75)
		{
			students[i].yearEndGradeLetter = "CB";
			countCB = countCB + 1;
		}
		else if (students[i].yearEndGrade >= 65)
		{
			students[i].yearEndGradeLetter = "CC";
			countCC = countCC + 1;

		}
		else if (students[i].yearEndGrade >= 58)
		{
			students[i].yearEndGradeLetter = "DC";
			countDC = countDC + 1;
		}
		else if (students[i].yearEndGrade >= 50)
		{
			students[i].yearEndGradeLetter = "DD";
			countDD = countDD + 1;
		}
		else if (students[i].yearEndGrade >= 40)
		{
			students[i].yearEndGradeLetter = "FD";
			countFD = countFD + 1;
		}
		else
		{
			students[i].yearEndGradeLetter = "FF";
			countFF = countFF + 1;
		}


		if (students[i].yearEndGrade >= passingGrade)
		{
			cout << students[i].name << " " << students[i].surName << "\t" << students[i].yearEndGradeLetter << " ile dersi geçti" << endl;
			countPassed = countPassed + 1;
		}
		else
		{
			cout << students[i].name << " " << students[i].surName << "\t" << students[i].yearEndGradeLetter << " ile dersten kaldı" << endl;
			countFailed = countFailed + 1;
		}


	}

	// En son ekrana kaç öğrencinin hangi harf notundan aldığını, dersi geçip geçmediğini, dersi geçen öğrenci sayısını, ve yüzdesini yazdırıyorum
	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << "AA alan öğrenci sayısı:" << "\t" << countAA << endl;
	cout << "BA alan öğrenci sayısı:" << "\t" << countBA << endl;
	cout << "BB alan öğrenci sayısı:" << "\t" << countBB << endl;
	cout << "CB alan öğrenci sayısı:" << "\t" << countCB << endl;
	cout << "CC alan öğrenci sayısı:" << "\t" << countCC << endl;
	cout << "DC alan öğrenci sayısı:" << "\t" << countDC << endl;
	cout << "DD alan öğrenci sayısı:" << "\t" << countDD << endl;
	cout << "FD alan öğrenci sayısı:" << "\t" << countFD << endl;
	cout << "FF alan öğrenci sayısı:" << "\t" << countFF << endl;
	cout << "\nDERSİ GEÇEN ÖĞRENCİ SAYISI:" << "\t" << countPassed << "\t " << "%" << (countPassed / numberOfStudents) * 100 << endl;
	cout << "DERSTEN KALAN ÖĞRENCİ SAYISI:" << "\t" << countFailed << "\t " << "%" << (countFailed / numberOfStudents) * 100 << endl;
	cout << "------------------------------------------------------------------------------------------------" << endl;

	system("pause");
	return 0;
}

