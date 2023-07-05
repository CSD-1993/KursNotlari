/*--------------------------------------------------------------------------------------------------------------------------

                                                     C ve Sistem Programcıları Derneği

                                                 Sistem Programlama ve İleri C Uygulamaları - 1

                                          Sınıfta Yapılan Örnekler ve Özet Notlar
        
                                                    Eğitmen: Kaan ASLAN
                                                    
                                        
             Bu Notlar Kaan ASLAN tarafından oluşturulmuştur. Kaynak belirtmek koşulu İle her türlü alıntı yapılabilir.

                              (Notları okurken editörünüzün "Line Wrapping" özelliğini pasif hale getiriniz.)
                                        
---------------------------------------------------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------------------------------------------------------------------
													1. Ders 27/05/2023 - Cumartesi
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
													2. Ders 03/06/2023 - Cumartesi
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
													3. Ders 04/06/2023 - Pazar
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
													4.Ders 10/06/2023 - Cumartesi
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	strtok fonsiyonun prototipi şöyledir:

	#include <string.h>

	char *strtok(char *str, const char *delims);

	Fonksiyon basit yazıları parse etmek için yani onları belirli ayıraç karakterlerinden ayırmak için kullanılmaktadır. Fonksiyonun birinci
	parametresi ayrıştırılacak olan yazının adresini almaktadır. Bu parametrenin const olmayan bir gösterici olduğuna dikkat ediniz. Fonksiyonun
	ikinci parametresi ayrıştırmada kullanılacak ayrıştırma karakterlerinin (delimiters) bulunduğu dizinin adresini almaktadır. 
	Fonksiyon şöyle çalışır: Fonksiyon önce birinci parametresiyle belirtilen adresten ilerleyerek ilk ayıraç karakteri olmayan karakterin 
	yerini elde eder. Sonra ayıraç karakteri olmayana kadar ilerlemeye devam eder. İlk ayıraç karakterini gördüğünde oraya null karakter yerleştirip
	o kısmın başlangıç adresiyle geri döner. strtok fonksiyonu genellikle bir kez çağrılmaz. Bir döngü içerisinde çağrılır. Çünkü fonksiyon bir kez
	çağrıldığında yalnızca ayıraçların ayırdığı ilk kısım elde edilir. İşte fonksiyonun kaldığı yerden devam etmesi için sonraki çağrılarda 
	birinci parametre yerine NULL adres girilmelidir. Fonksiyon en sonunda yazı ayrıştırılacak yazı bittiğinde NULL adrese geri dönmektedir. 
	Fonksiyonun tipik kullanuım kalını şöyledir:

	char *str;

	for (str = strtok(s, delims); str != NULL; str = strtok(NULL, delims))
		puts(str);

	Tabii aynı kalıp while döngüüs ile de gerçekleştirilebilir:

	str = strtok(s, delimes);
	while (str != NULL) {
		puts(str);
		str = strtok(NULL, delims);
	}

	Fonksiyonun birinci parametresiyle belirtilen dizi içerisindeki yazıyı bozduğuna dikkat ediniz. 

-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[] = "  Ali,    Veli, Selami   ";
	char *pstr;

	pstr = strtok(s, ", ");
	while (pstr != NULL) {
		puts(pstr);
		pstr = strtok(NULL, ", ");
	}

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	strtok Fonksiyonun Kullanımına örnek.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[] = "...,,,,,ali,...,,,veli,....,selami..,,,,,,hakan";
	char *str;

	for (str = strtok(s, ",."); str != NULL; str = strtok(NULL, ".,"))
		puts(str);

	return 0;
}

/* ------------------------------------------------------------------------------------------------------------------------------------------
	strtok fonksiyonun kullanımı örnek.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[] = "  Ali,    Veli, Selami   ";
	char *pstr;

	for (pstr = strtok(s, ", "); pstr != NULL; pstr = strtok(NULL, ", "))
		puts(pstr);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	strtok fonksiyonun kullanımına örnek.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[] = "12/11/2009";
	char *pstr;

	for (pstr = strtok(s, "/"); pstr != NULL; pstr = strtok(NULL, "/"))
		puts(pstr);

	return 0;
}

/* ------------------------------------------------------------------------------------------------------------------------------------------
	strtok Fonksiyonunun birinci parametresiyle aldığı adreste değişiklik yaptığına dikkat ediniz. Bu nedenle aşağıdaki kod
	tanımsız davranışa yol açacaktır:

	char *s = "12/11/2009";
	char *pstr;

	for (pstr = strtok(s, "/"); pstr != NULL; pstr = strtok(NULL, "/"))
		puts(pstr);

	Burada s föstericisi artık bir iki tırnak ile tahsis edilen string'i göstermektedir. C'de iki tırnak ile tahsis edilen string'lerin
	güncellenmesi "tanımsız davranışa (undefined behavior)" yol açmaktadır. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	char *s = "12/11/2009";
	char *pstr;

	for (pstr = strtok(s, "/"); pstr != NULL; pstr = strtok(NULL, "/"))
		puts(pstr);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	İleride görüleceği gibi static yerel değişken ve global değişken kullanan fonksiyonlar thread güvenli (thread safe) değildir. 
	Bunların thread güvenli versiyonları birer "eklenti (extension)" bulundurulabilmektedir. Örneğin Microsoft strtok fonksiyonunun 
	thread güvenli biçimini strtok_s ismiyle bir eklenti biçiminde bulundurmuştur. Fonksiyonun prototipi şöyledir:

	#include <string.h>
	
	char *strtok_s(char *str, const char *delims, char **context);

	Fonksiyonun strtok fonksiyonundna farkı kalınan yeri statik yerel bir nesnede saklamak yerine bir göstericide saklamasıdır. Fonksiyon
	bu göstericiye kalınan yerin adresini saklar ve adresi oradan kullanır. 

	Microsoft derleyicilerinde strtok fonksiyonun strtok_s ismiyle thread güvenli bir versiyonu da vardır. Microsoft'un strtok_s fonksiyonun  
	eşdeğeri GNU C kütüphanesinde strtok_r ismiyle bulunmaktadır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[] = "12/11/2009";
	char *pstr;
	char *pstrl;

	for (pstr = strtok_s(s, "/", &pstrl); pstr != NULL; pstr = strtok_s(NULL, "/", &pstrl))
		puts(pstr);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	strtok fonksiyonun gerçekleştirimi aşağıdaki gibi yapılabilir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

char *mystrtok(char *str, const cha *delim)
{
	static char *pos;
	char *beg;

	if (str != NULL)
		pos = str;

	while (*pos != '\0' && strchr(delim, *pos) != NULL)
		++pos;

	if (*pos == '\0')
		return NULL;

	beg = pos;

	while (*pos != '\0' && strchr(delim, *pos) == NULL)
		++pos;

	if (*pos != '\0')
		*pos++ = '\0';

	return beg;
}

int main(void)
{
	char s[] = "";
	char *pstr;

	for (pstr = mystrtok(s, ","); pstr != NULL; pstr = mystrtok(NULL, ","))
		puts(pstr);

	return 0;
}

/* ------------------------------------------------------------------------------------------------------------------------------------------
	strtok fonksiyonun birinci parametresinin const olan (yani birinci parametresindeki yazıyı değiştirmeyen) versyionu aşağıdaki gibi yazılabilir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

char *mystrtok(const char *str, const char *delim, char *dest)
{
	static const char *pos;
	const char *beg;

	if (str != NULL)
		pos = str;

	while (*pos != '\0' && strchr(delim, *pos) != NULL)
		++pos;

	if (*pos == '\0')
		return NULL;

	beg = pos;

	while (*pos != '\0' && strchr(delim, *pos) == NULL)
		++pos;

	strncpy(dest, beg, pos - beg);
	dest[pos - beg] = '\0';

	if (*pos != '\0')			/* bu kontrol kaldırılabilir */
		++pos;

	return dest;
}

int main(void)
{
	char text[] = "10/12/2009";
	char str[100];
	char *pstr;

	for (pstr = mystrtok(text, "/", str); pstr != NULL; pstr = mystrtok(NULL, "/", str))
		puts(pstr);

	return 0;
}

/* ------------------------------------------------------------------------------------------------------------------------------------------
	strtok fonksiyonun dinamik bir alan tahsis edip o alana geri dönen versyionu. Ancak burada fonksiyon kullanan kişinin bu alanı kendisinin 
	free etmesi gerekir. Ayrıca aşağıdaki örnekte yazının sonuna gelindiğinden dolayı mı yoksa bellek tahsisatının yapılamadığından dolayı mı 
	fonksiyonun NULL adrese geri döndüğü anlaşılamamaktadır. Bu tür durumlarda UNIX/Linux sistemlerinde errno değişkeninden faydalanılabilmektedir. 
	Aslında errno değişkeni C'de de bu amaçla kullanılabilir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mystrtok(const char *str, const char *delim)
{
	static const char *pos;
	const char *beg;
	char *dstr;

	if (str != NULL)
		pos = str;

	while (*pos != '\0' && strchr(delim, *pos) != NULL)
		++pos;

	if (*pos == '\0')
		return NULL;

	beg = pos;

	while (*pos != '\0' && strchr(delim, *pos) == NULL)
		++pos;

	if ((dstr = (char *)malloc(pos - beg + 1)) == NULL)
		return NULL;

	strncpy(dstr, beg, pos - beg);
	dstr[pos - beg] = '\0';

	return dstr;
}

int main(void)
{
	char text[] = "10/12/2009";
	char *pstr;

	for (pstr = mystrtok(text, "/"); pstr != NULL; pstr = mystrtok(NULL, "/")) {
		puts(pstr);
		free(pstr);
	}

	return 0;
}

/* ------------------------------------------------------------------------------------------------------------------------------------------
	Bir dosyayı satır satır okuyarak her satırı strtok fonksiyonuyla atomlarına ayrıştırabiliriz. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE		4096

int isall_space(const char *str)
{
	while (*str != '\0' && isspace(*str))
		++str;

	return *str == '\0';
}

int main(void)
{
	FILE *f;
	char line[MAX_LINE];
	char *str;

	if ((f = fopen("test.csv", "r")) == NULL) {
		fprintf(stderr, "cannot open file!..\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(line, MAX_LINE, f) != NULL) {
		if (isall_space(line))
			continue;
		if ((str = strchr(line, '\n')) != NULL)
			*str = '\0';
		for (str = strtok(line, ","); str != NULL; str = strtok(NULL, ","))
			printf("%s\n", str);
		printf("-----------------\n");
	}

	fclose(f);

	return 0;
}

/* test.csv */

Ali Serçe, 100, 200, 300
Sacit Bulut, 12.3, 56.3, 78.2

Hakan Akyıldız, 12.3, 67.3

Hüsnü Biter, 12, 34, 34


/* ------------------------------------------------------------------------------------------------------------------------------------------
	remove standart bir C fonksiyonudur. Yol ifadesi ile belirtilen dosyayı silmek için kullanılır. Fonksiyonun prototipi şöyledir:

	#include <stdio.h>
	
	int remove(const char *filename);
	
	Fonksiyon başarı durumunda 0 değerine başarısızlık durumunda sıfır dışı bir değere geri döner. Bir dosyanın silinememesi için çeşitli nedenler
	söz konusu olabilir. Örneğin dosya yoktur bu nedenle silinemez. Ya da örneğin silinmek istenen dosyaya prosesin silme yetkisi olmayabilir. 
	Bu nedenle fonksiyonun başarısı kontrol edilmelidir. 

	Bir dosya remove fonksiyonuyla silindiğinde dosya "geri dönüş kutusunda (recycle bin)" saklanmaz. Geri dönüşüm kutusu yüksek seviyeli bir 
	kabuk organizasyonudur. Geri dönüş kutusuyla işletim sisteminin çekirdeğinin bir ilgisi yoktur. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	if (remove("test.txt") != 0) {
		fprintf(stderr, "cannot remove file!..\n");
		exit(EXIT_FAILURE);
	}

	printf("success..\n");

	return 0;
}


/*------------------------------------------------------------------------------------------------------------------------------------------
	Bir dosya bir program tarafında açılmışsa dosyanın silinebilirliği sistemden sisteme değişebilmektedir.UNIX / Linux sistemlerinde genel olarak
	açık dosyalar silinebilmektedir.Ancak silme işlemi gerçek anlamda silinen dosyayının kapatılması durumunda yapılmaktadır.Aynı durum macOS
	sistemlerinde de böyledir.Windows sistemlerinde ise açık dosyaların silinebilirliği dosyanın açış moduna bağlı olarak değişebilmektedir.

	Aşağıdaki programı Windows sistemlerinde ve UNIX/Linux sistemlerinde deneyiniz. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *f;

	if ((f = fopen("test.txt", "r")) == NULL) {
		fprintf(stderr, "cannot open file!..\n");
		exit(EXIT_FAILURE);
	}
	printf("File successfully opened...\n");

	if (remove("test.txt")) {
		fprintf(stderr, "cannot remove file!..\n");
		exit(EXIT_FAILURE);
	}

	printf("file removed...\n");

	fclose(f);

	return 0;
}

/* ------------------------------------------------------------------------------------------------------------------------------------------
	rename isimli standart C fonksiyonu dosyanın ismini değiştirmek için kullanılır. Tabii bir dosyanın ismi başka dizinde de değiştirilebilir. 
	Bu da taşıma etkisi yaratmaktadır. rename fonksiyonunun prototipi şöyledir:

	#include <stdio.h>
	
	int rename(const char *old, const char *new);
	
	Fonksiyonun birinci parametresi ismi değiştirilecek dosyanın yol ifadesini ikinci parametresi ise yeni isimli yol ifadesini almaktadır. 
	Yukarıda da belirttiğimiz gibi bir dosyanın ismini başka bir dizindeki dosya ismi olarak dğeiştirebiliriz. Bu zaten bir taşıma gibi 
	işlev görmektedir. Tabii rename işlemi sırasında aslında dosyanın disk üzerindeki içeriği taşınmamaktadır. rename başarı durumunda 0 
	değerine başarısızlık durumunda -1 değerine geri dönmektedir. 

	Yine rename işlemi çeşitli nedenelrden dolayı yapılamayabilir. Örneğin yeni isimle zaten bir dosya bulunyor olabilir. Ya da proses bu işlemi 
	yapmaya yetkili olmayabilir. Bu nedenle fonksiyonun başarısı mutlaka kontrol edilmelidir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	if (rename("test.txt", "mest.txt") == -1) {
		fprintf(stderr, "cannot rename file!..\n");
		exit(EXIT_FAILURE);
	}

	printf("Success...\n");

	return 0;
}

/* ------------------------------------------------------------------------------------------------------------------------------------------
	system fonksiyonu ilgili sistemdeki "komut yorumlayıcı (command interpreter)" programını çalıştıran ve ona bizim fonksiyona argüman olarak 
	verdiğimiz komutu işlettiren standart bir C fonksiyonudur. Fonksiyonun prototipi şöyledir:

	#include <stdlib.h>

	int system(const char *string);

	Fonksiyonun geri dönüş değerinin anlamı derleyeiciyi yazanların isteğine bırakılmıştır. Ancak Windows, macOS ve UNIX/Linux sistemlerinde
	fonksiyon aşarı durumunda 0, başarısızlık durumunda sıfır dışı bir değere geri dönmektedir. Fonksiyonun çeşitli ayrıntılaarı vardır. Bu konu 
	ileride daha ayrıntılı biçimde ele alınacaktır. 

	C derleyicisinin olduğu bir sistemde komut yorumlayıcı olmak zorunda değildir. Örneğin işletim sistemi olmayan bir mikrodenetleyici sisteminde
	komut yorumlayıcı da olmayacaktır. İşte programcı ilgili sistemde bir komut yorumlayıcının olup olmadığını anlayabilmek için fonksiyonu NULL 
	adres ile çağırabilir. Bu durumda fonksiyon sıfır dışı herhangi bir değere geri dönerse ilgili sistemde komut yorumlayıcı vardır. Sıfır değerine
	geri dönerse ilgili sistemd ekomut yorumlayıcı yoktur. 

	Komut yorumlayıcılardaki komutlar o işletim sistemine hatta o komut yorumlayıya bağlı olarak dğeişebilmektedir. Dolsyayıyla system fonksiyonunda 
	vereceğiniz komutlar belli bir sistemdeki belli komut yaorumlayıcıları için anlamlı ve geçerli olmaktadır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	system("ls -l");

	return 0;
}

/* ------------------------------------------------------------------------------------------------------------------------------------------
	Programın çalışması sırasında belli bir amaçla yaratılan o amaç gerçekleştirildikten sonra silinen kısa ömürlü dosyalara "geçici dosyalar 
	(temporary files)" denilmektedir. Geçici dosyaları oluştururken önemli bir sorun bu dosyaların verilecek isimlerin tesadüfen var olan dosyalarla
	çakışmasıdır. 

	tmpfile isimli standart C fonksiyonu olmayan bir dosya ismi ile bir dosyayı "w+b" modunda yaratır ve dosyaya ilişkin dosya bilgi göstericisiyle
	geri döner. Böyle dosyalar kapatıldığında diskteki dosya da otomatik olarak silinecektir. Tabii tmpfile fonksiyonu da çeşitli nedenlerden 
	dolayı başarısız olabilir. Fonksiyon başarısızlık durumunda NULL adrese geri dönmektedir. Programcı fonksiyonun başarısını kontrol etmelidir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *f;
	int i, val;

	if ((f = tmpfile()) == NULL) {
		fprintf(stderr, "cannot create temporary file!..\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < 100; ++i)
		if (fwrite(&i, sizeof(int), 1, f) != 1) {
			fprintf(stderr, "cannot write file!..\n");
			exit(EXIT_FAILURE);
		}

	fseek(f, 0, SEEK_SET);

	while (fread(&val, sizeof(int), 1, f) > 0)
		printf("%d\n", val);

	if (ferror(f)) {
		fprintf(stderr, "cannot read file!..\n");
		exit(EXIT_FAILURE);
	}

	fclose(f);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	tmpfile fonksiyonu ile biz açılmış bir geçici dosya elde ederiz. Ancak o geçici dosyanın ismini bilmeyiz. Oysa bazı uygulamalarda programcı
	bir isimle geçici dosya oluşturmak isteyebilir. Örneğin bir text dosyadaki bütün "ankara" yazılarını "istanbul" yapmak isteyeim. Böyle bir 
	işlemi dosya üzerinde yapmak hem yavaşlığa hem de karmaşıklığa yol açar. Bunun kolay bir yolu bir geçici dosya oluşturmak asıl dosyadaki karakterleri 
	bu geçici dosyaya kopyalamak, ancak bu sırada "ankara" yazıları yerine "istanbul" yazılarını bu geçici dosyaya yazmak ve işlem birtince de 
	asıl dosyayı silip geçici dosyanın ismini değiştirmektir. İşte bunun için bizim geçici dosyanın ismini biliyor olmamız gerekir. 

	tmpnam isimli standart C fonksiyonu geçici dosyayı açmaz bize bir geçici dosyaya ilişkin yol ifadesi verir. Bu yol ifadesi ile belirtilen dosyayı 
	açmak programcının yapacağı bir iştir. tmpnam fonksiyonunun prototipi şöyledir:

	#include <stdio.h>
	
	char *tmpnam(char *s);

	Fonksiyonun parametresi geçici dosya isminin yerleştirileceği dizinin adresini almaktadır. Ancak fonksiyon çağrılırken argüman olarak NULL 
	adres de geçilebilir. Bu durumda fonksiyon geçici dosya ismini static yerel bir dizinin içerisine yerleştirir ve o dizinin 
	adresiyle geri döner. Eğer argüman olarak NULL adres geçilmezse fonksiyon argüman olarak geçilmiş olan adresin aynısıyla geri dönmektedir. 
	Fonksiyonun en az TMP_MAX (<stdio.h> içerisinde define edilmiştir) dosya ismi üretebileceği garanti edilmiştir. Ancak makul bir limit aşıldığında 
	fonksiyon başarısız olabilr. Bu duurmda NULL adrese geri döner. Geçici dosyanın yerleştirileceği dizinin maksimum uzunluğu için <stdio.h>
	içerisinde L_tmpnam isimli bir sembolik sabit de bulundurulmuştur. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* ------------------------------------------------------------------------------------------------------------------------------------------
	Bir dosyadaki # ile başlayan satırları silen program örneği. Programın tek bir komut satırı argümanı vardır. O da #'lerden arındırılacak dosyanın
	yol ifadesini belirtir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE		8192

int issharp(const char *line);

int main(int argc, char *argv[])
{
	FILE *f, *ftemp;
	char line[MAX_LINE];
	char *path;

	if (argc != 2) {
		fprintf(stderr, "wrong number of arguments!..\n");
		exit(EXIT_FAILURE);
	}

	if ((path = tmpnam(NULL)) == NULL) {
		fprintf(stderr, "cannot get temporary file!..\n");
		exit(EXIT_FAILURE);
	}

	if ((f = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "cannot open file!..\n");
		exit(EXIT_FAILURE);
	}

	if ((ftemp = fopen(path, "w")) == NULL) {
		fprintf(stderr, "cannot open file!..\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(line, MAX_LINE, f) != NULL) {
		if (!issharp(line))
			if (fputs(line, ftemp) == EOF) {
				fprintf(stderr, "cannot write file temporary file!..\n");
				goto FAILURE;
			}
	}

	if (ferror(f)) {
		fprintf(stderr, "cannot read file: %s\n", argv[1]);
		goto FAILURE;
	}

	fclose(f);
	fclose(ftemp);

	if (remove(argv[1]) != 0) {
		fprintf(stderr, "cannot remove file!..\n");
		goto FAILURE;
	}

	if (rename(path, argv[1]) != 0) {
		fprintf(stderr, "cannot rename file!..\n");
		exit(EXIT_FAILURE);
	}

	printf("sucess...\n");

	exit(EXIT_SUCCESS);

FAILURE:
	fclose(ftemp);
	if (remove(path) != 0)
		fprintf(stderr, "cannot remove file!..\n");

	exit(EXIT_FAILURE);

	return 0;
}

int issharp(const char *line)
{
	while (isspace(*line))
		++line;

	return *line == '#';
}

/*------------------------------------------------------------------------------------------------------------------------------------------
												6.Ders 17/06/2023 - Cumartesi
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	Bir programı komut satırında çalıştırırken program isminin yaznına yazılan yazılara programın "komut satırı argümanları (command line arguments)"
	denilmektedir. Örneğin:

	prog ali veli selami

	Burada çalıştırılmak istenen program "prog" isimli programdır. "prog", "ali", "veli", "selami" yazıları ise programın komut satırı argümanlarını 
	oluşturmaktadır. Komut satırı argümanlarının amacı programı çalıştırırken programın yapacağı işler konusund etkili olmaktır. 

	C'de programın programın komut satırı argümanları main fonksiyonundan alınmaktadır. Yani programın komut satırı argümanları tipik olarak 
	kabuk (shell) programı tarafındna komut satırından alınır ve main fonksiyonuna argüman olarak geçirilir. C standratlarına göre main fonksiyonunun
	parametrik yapısı iki biçimde olabilmektedir:

	int main(void)
	int main(int argc, char *argv[])

	Tabii burada argc va argv isimleri gelenekseldir. Bu isimlerin kullanılması zorunlu değildir. C standartları main fonksiyonun geri dönüş değerinin
	int türden olmasını zorunlu tutmaktadır. Ancak standartlar main fonksiyonun derleyiciye özgü bir biçimde başka parametrelere de sahip olabileceğini 
	belirtmektedir. Anımsanacağı gibi fonksiyonun parametre parantezindeki köşeli parantezler aslında "gösterici" anlamına gelmektedir. Bu durumda 
	main fonksiyonu şöyle de yazılabilir:

	int main(int argc, char **argv)

	Buradaki argc komut satırındaki argümanların program ismi dahil olmak üzere toplam sayısını belirtmektedir. argv ise programın ismi dahil olmak 
	üzere komut satırı argüman yazılarının başlangıç adreslerini tutan gösterici dizisini göstermektedir. Standartlar bu dizinin son elemanında 
	NULL adresin bulunucağını (yani argv[argc] değerinin NULL adres olacağını) garanti etmektedir. 
	
	Burada önemli noktalardan biri bu argc ve argv parametrelerinin main fonksiyonuna kim tarafından ve nasıl aktarıldığıdır. Biz programı komut 
	satırından çalıştırdığımızda bu kabuk programı komut satırında girdiğimiz yazıları boşluklaradan ayırır ve bunlardan bir gösterici dizisi
	oluşturur. Bu gösteri dizisinin adresini main fonksiyonuna geçirir. Tabii sürecin bazı ayrıntıları vardır. İleride bu ayrıntılar üzerinde d
	duracağız. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	Klavyeden (stdin dosyasından) girilen bir komut satırı yazısından argc ve argv parametrelerini oluşturan basit program aşağıdaki 
	yazılabilir. Burada bazı kontroller yapılmamıştır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#define MAX_CMDLINE         4096
#define MAX_ARGV            1024

int main(void)
{
    char cmdline[MAX_CMDLINE];
    char *argv[MAX_ARGV];
    char *str;
    int argc;

    fgets(cmdline, MAX_CMDLINE, stdin);
    
    argc = 0;
    for (str = strtok(cmdline, " \t"); str != NULL; str = strtok(NULL, " \t"))
        argv[argc++] = str;
    argv[argc] = NULL;

    printf("-------------\n");
    for (int i = 0; i < argc; ++i)
        puts(argv[i]);
    
    return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Komut satırı argümanlarında "seçenek (option)" denilen bir kavram vardır. Programın yaptığı iş üzerinde bazı belirlemeleri oluşturmak için 
	seçenek argümanlardan faydalanılmaktadır. Yani seçenekler bir şim çeşitli varyasyonlarını belirltmek için kullanılan komut satırı argümanlarıdır. 
	Seçenek belirtme işlemi UNIX/Linux dünyasında "-" karakteri ile Windows dünyasında "/" karakteri ile yapılmaktadır. Örneğin:
	
	gcc -c sample.c
	cl /c sample.c

	Burada UNIX/Linux sistemlerindeki gcc derleyicisinin -c seçeneği "derle fakat link etme" anlamına gelmektedir. Benzer biçimde Windows 
	sistemlerinde Microsoft C derleyicilerindeki /c seçeneği de aynı anlama gelmektedir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux dünyasında komut satırı argümanlarının oluşturulması için geniş bir kesim tarafındna kullanılan geleneksel bir biçim vardır. 
	Bu biçime "GNU biçimi" de denilmektedir. Biz de kursumuzda UNIX/Linux dünyasında yazacağımız programlarda bu geleneği kullanacağız. 
	GNU stilinde komut satırı argümanları üçe ayrılmaktadır:

	1) Argümansız seçenekler
	2) Argümanlı seçenekler
	3) Seçeneksiz argümanlar

	Argümansız seçenekler "-" karakterine yapışık tek bir harften oluşmaktadır. Harflerde büyük harf küçük harf duyarlılığı (case sensitivity)
	dikkate alınmaktadır. Örneğin:

	ls -l -i /usr/include

	Burada -l ve -i argümansız seçeneklerdir. /usr/include argğmanının bu seçeneklerle hiçbir ilgisi yoktur. Argümansız seçenekler tek bir 
	karakterden oluşturulduğu için birleştirilebilmektedir. Örneğin:

	ls -li

	Buradaki -li aslında -l -i ile tamamen aynı anlamdadır. Genel olarak GNU stilinde seçenekler arasındaki sıranın bir önemi yoktur. 
	Yani örneğin:

	ls -l -i

	ile

	ls -i -l 

	arasında bir farklılık yoktur.  

	Argümanlı seçeneklerde bir seçeneğin yanında o seçenekle ilişkili bir argüman da bulunur. Örneğin:

	gcc -o sample sample.c

	Burada -o seçeneği seçeneği tek başına kullanılmaz. Hedef dosyanın ismi seçeneğin argümanını oluşturmaktadır. O halde buradaki 
	-o seçeneği tipik olarak argümanlı seçeneğe bir örnektir. Argüman seçeneklerin birleştirilmesi tavsiye edilmez. Ancak birleştirme yapılabilmektedir. 
	Örneğin:

	gcc -co sample.o sample.c

	Bu yazım biçimini pek çok program kabul etse de biz tavsiye etmiyoruz. Buradaki argümanların aşağıdaki gibi belirtilesi daha uygundur:

	gcc -c -o sample.o sample.c

	Programlar argümanlı seçeneklerde seçeneğin argümanı hiç boşluk karakterleriyle ayrılmasa bile bunu kabul edebilmektedir. Örneğin:

	gcc -osample sample.c

	Burada -o argümanlı seçebek olduğu için onu başka bir seçenek izleyemeyeceğinden dolayı "sample" -o seçeneğinin argümanı olarak 
	ele alınmaktadır.

	Seçeneklerle ilgisi olmayan argümanlara "seçeneksiz argüman" denilmektedir. Örneğin:

	gcc -o sample sample.c

	Burada "sample.c" argümanı herhangi bir seçenekle ilgili değildir. Örneğin:

	cp x.txt y.txt

	Buradaki "x.txt" ve "y.txt" argümanları da seçeneklerle ilgili değildir. Seçeneksiz argümanların sonda bulunması gerekmez. Örneğin:

	gcc sample.c -o sample
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	Eskiden yalnızca tek karakterden oluşan kısa seçenekler kullanılıyrodu. Ancak daha sonraları bu kısa seçeneklerin yetersiz kaldığı ve 
	okunabilirliği bozduğu gerekçesiyle uzun seçenekler de kullanılmaya başlanmıştır. POSIX standartları uzun seçenekleri desteklememektedir. 
	Ancak UNIX/Linux dünyasında yaygın biçimde kullanılmaktadır. Uzun seçenekler "--" öneki ile başlatılmaktadır. Örneğin:

	prog --count -a -b --length 100

	Uzun seçenkler de arümanlı ve arümansız olabilmektedir. Yukarıdaki örnekte "--count" arümansız uzun seçenek, "-a" ve "-b" argümansız seçenekler 
	ve "--length 100" ise argümanlı uzun seçenektir. 
	
	Uzun seçeneklerde "isteğe bağlı argüman (optional argument)" denilen özel bir argüman da kullanılmaktadır. İsmi üzerinde "isteğe bağlı argüman" 
	uzun seçeneklerde yanında verilip verilmemesi isteğe bağlı olan argümanlardır. Uzun seçeneklerin isteğe bağlı argümanları "=" sentaksı ile 
	yapışık bir biçimde belirtilmektedir. Örneğin:

	prog --size=512

	Burada --size uzun seçeneğinin argümanı isteğe bağlıdır. Yani bu uzun seçenek argümansız da aşağıdaki gibi kullanılabilirdi:

	prog --size

	Genel olarak bugün programlar kısa seçenekleri de uzun seçenekleri de bir arada kullanmaktadır. Programcılar bazı kısa seçeneklerin 
	alternatif uzun seçeneklerini oluşturabilmektedir. Yukarıda da belirttiğimiz gibi POSIX standratları uzun seçenekleri desteklememektedir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	Yukarıda ele aldığımız komut satırı argüman sentaksı her program tarafından yukarıda açıklandığı gibi uygulanmayabilmektedir. Özellikle 
	henüz bu biçimin tam oturmadığı eski bazı programlarda burada ele aldığımız stil tam olarak uygulanmamıştır. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux dünyasında kullanılan komut satırı argümanlarını parse etmek için getopt ve getopt_long isimli iki fonksiyon bulunudurlmuştur. 
	getopt fonksiyonu bir POSIX fonksiyonudur. Ancak bu fonksiyon uzun seçenekleri parse etmemektedir. getopt_long ise uzun seçenekleri de parse eden
	getopt fonksiyonunun daha gelişmiş bir biçimidir. Ancak getopt_long bir POSIX fonksiyonu değildir. Ancak libc kütüphanesinde bulunmaktadır. 
	Bu fonksiyonlar Windows sistemlerinde hazır bir biçimde herhangi bir kütüphanede bulunmamaktadır. Zaten yukarıda da belirttiğimiz gibi Windows
	sistemlerindeki komut satırı argüman stili UNIX/Linux sistemlerindekinden farklıdır. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	getopt fonksiyonunun prototipi şöyledir:

	#include <unistd.h>

	int getopt(int argc, char * const argv[], const char *optstring);

	getopt fonksiyonunun ilk iki paramteresi main fonksiyonunun argc ve argv parametreleri gibidir. Yani programcı main fonksiyonunun bu parametrelerini 
	getopt fonksiyonuna geçirir. Fonksiyon üçüncü parametresinde kısa seçenekler belirtilmektedir. Bu parametre bir yazı biçiminde girilir. 
	Bu yazıdaki her bir karakter bir kısa seçeneği belirtir. Bir karakterin yanında ':' karakteri varsa bu ':' karakteri onun solundaki seçeneğin 
	argümanlı bir seçenek olduğunu belirtmektedir. Örneğin "ab:c" burada -a, -b ve -c seçenekleri belirtilmiştir. Ancak -b seçeneğinin bir argümanı da
	vardır. 

	getopt fonksiyonu bir kez çağrılmaz. Bir döngü içerisinde çağrılmalıdır. Çünkü fonksiyon her çağrıldığında bir kısa seçeneği bulmaktadır. 
	Fonksiyon bütün kısa seçenekleri bulduktan sonra artık bulacak bir seçenek kalmadığında -1 değerine geri dnmektedir. O halde fonksiyonun 
	çağrılma kalıbı şöyle olmaldır:

	int result;
	...

	while ((result = getopt(argc, argv, "ab:c")) != -1) {
		...
	}

	getopt her kısa seçeneği bulduğunda o kısa seçeneğe ilişkin karakterle (yani o karakterin sayısal karşılığı ile) geri dönmektedir. 
	O halde bizim getopt fonksiyonunun geri dönüş değerini switch içerisinde ele almamaız gerekir:

	while ((result = getopt(argc, argv, "ab:c")) != -1) {
        switch (result) {
            case 'a':
                ...
                break;
            case 'b':
                ...
                break;
            case 'c':
				...
                break;
        }
    }

	getopt fonksiyonu olmayan (yani üçüncü parametresinde belirtilmeyen) bir kısa seçenekle karşılaştığında ya da argümanı olması gerektiği 
	halde girilmemiş bir kısa seçenekle karşılaştığında '?' özel değerine geri dönmektedir. Programcının switch deyimine bu case bölümünü 
	ekleyerel bu durumu da değerlendirmesi uygun olur. Örneğin:

	while ((result = getopt(argc, argv, "ab:c")) != -1) {
        switch (result) {
            case 'a':
                ...
                break;
            case 'b':
                ...
                break;
            case 'c':
				...
                break;
			case '?':
				...
				break;
        }
    }

	getopt fonksiyonunun kullandığı dört global dğeişken vardır. Bu global değişkenler kütüphanenin içeisinde tanımlanmıştır. Bunları biz
	extern bildirimi ile kullanabiliriz. Ancak bunların extern bildirimleri zaten <unistd.h> dosyası içierisinde yapılmış durumdadır:

	extern int opterr;
	extern int optopt;
	extern int optind;
	extern char *optarg;

	Default durumda getopt fonksiyonu geçersiz bir seçenekle (yani üçüncü parametresinde belirtilmeyen bir seçenekle) karşılaştığında 
	stderr dosyasına (ekranda çıkacaktır) kendisi hata mesajını yazdırmaktadır. Programcılar genellikle bunu istemezler. getopt fonksiyonunun 
	hata geçersiz seçenekler için hata mesajını yazdırması opterr değişkenine 0 değeri atanarak sağlanabilir. Yani opterr değişkeni sıfır dışı 
	bir değerdeyse (default durum) fonksiyon mesajı stderr dosyasına kendisi de yazar, sıfır değerindeyse fonksiyon hata mesajını stder dosyasına 
	yazmaz. 

	getopt fonksiyonu geçersiz bir seçenekle ya da argümanı girilmemiş argümanlı bir seçenekle karşılaştığında '?' geri dönmekle birlikte aynı zamanda
	optopt global değişkenine geçersiz seçeneğin karakter karşılığıı yerleştirmektedir. Böylece programcı daha yeterli bir mesaj verebilmektedir. 
	Örneğin:

	opterr = 0;
    while ((result = getopt(argc, argv, "ab:c")) != -1) {
        switch (result) {
            case 'a':
                printf("-a given...\n");
                break;
            case 'b':
                printf("-b given...\n");
                break;
            case 'c':
                printf("-c given...\n");
                break;
            case '?':
            if (optopt == 'b')
                fprintf(stderr, "-b option given without argument!..\n");
            else
                fprintf(stderr, "invalid option: -%c\n", optopt);
            break;
        }
    }

	Argümanlı bir kısa seçenek bulunduğunda getopt fonksiyonu optarg global değişkenini o kısa seçeneğin argümanını gösterecek biçimde 
	set eder. Ancak optarg yeni bir argümanlı kısa eçenek bulunduğunda bu kez onun argümanını gösterecek biçimde set edilmektedir. Yani 
	programcı argümanlı kısa seçeneği bulduğu anda optarg değişkenine başvurmalı gerekirse onu başka bir göstericide saklamalıdır. 

	Pekiyi seçeneksiz argümnalrı nasıl edebiliriz? Seçeneksiz argümanlar argv dizisinin herhangi bir yerine bulunuyor olabilir. İşte getopt 
	fonksiyonu her zaman seçeneksiz argümanları girildiği sırada argv dizisinin sonuna taşır ve onların başladığı indeksi de optind global 
	değişkeninin göstermesini sağlar. O halde programcı getopt ile işini bitirdikten sonra (yani while döngüsünden çıktıktan sonra) optind
	indeksinden argc indeksine kadar ilerleyerek tüm seçeneksiz argümanları elde edebilmektedir. Örneğin:

	./sample -a ali -b veli selami -c

	Burada "ali" ve "selami" seçeneksiz argümanlardır. getopt bu argv dizisini şu halde getirmekltedir:

	./sample -a -b veli -c ali selami

	Şimdi burada optind indeksi artık "ali" argümanının bşaldağı indeksi belirtecektir. Onun ötesindeki türm argümanlar seçeneksiz argümanlardır. 
	Bu argümanları while dönüsünün dışnda şyle yazdırabiliriz:

	for (int i = optind; i < argc; ++i)
        puts(argv[i]);

	Programcının girilmiş olan seçenekleri saklayıp programın ilerleyen aşamalarında bunları kullanması gerekebilmektedir. Bunun için şöyle 
	bir kalıp önerilebilir: 
	
	- Her seçenek için bir flag değişkeni tutulur. Bu flag değişkenlerine başlangıçta 0 atanır.
	- Her argümanlı seçenek için bir gösterici tutulur. 
	- Her seçenekle karşılaşıldığında flag değişkenine 1 atanarak o seçeneğin kullanıldığı kaydedilir. 
	- Argümanlı seçeneklerle karşılaşıldığında onların argümanları göstericilerde saklanır. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* ------------------------------------------------------------------------------------------------------------------------------------------
	getopt fonksiyonunun kullanımına bir örnek. Burada -a, -b ve -c seçenekleri vardır. -z ve -c seçenekleri argümansız seçenek -b seçeneği 
	ise argümanlı bir seçenektir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int result;
    int a_flag, b_flag, c_flag;
    char *b_arg;

    a_flag = b_flag = c_flag = 0;
    opterr = 0;

    while ((result = getopt(argc, argv, "ab:c")) != -1) {
        switch (result) {
            case 'a':
                a_flag = 1;
                break;
            case 'b':
                b_flag = 1;
                b_arg = optarg;
                break;
            case 'c':
                c_flag = 1;
                break;
            case '?':
            if (optopt == 'b')
                fprintf(stderr, "-b option given without argument!..\n");
            else
                fprintf(stderr, "invalid option: -%c\n", optopt);
            break;
        }
    }

    if (a_flag)
        printf("-a given...\n");

    if (b_flag)
        printf("-b given with argument \"%s\"...\n", b_arg);

    if (c_flag)
        printf("-a given...\n");

    if (argc - optind != 0)
        printf("argument without options:\n");

    for (int i = optind; i < argc; ++i)
        puts(argv[i]);

    return 0;
}

/* ------------------------------------------------------------------------------------------------------------------------------------------
	Ayrıştırma işleminde bir hata oluştuğunda programın devam etmemesini isteriz. Ancak tüm hataların rapor edilmesi de gerekmektedir. 
	Bunun için bir flag değişkenindne faydalanılabilir. O flag değişkeni hata durumunda set edilir. Çıkışta kontrol edilip duruma göre 
	program sonlandırılır. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int result;
    int a_flag, b_flag, c_flag, err_flag;
    char *b_arg;

    a_flag = b_flag = c_flag = err_flag = 0;
    opterr = 0;

    while ((result = getopt(argc, argv, "ab:c")) != -1) {
        switch (result) {
            case 'a':
                a_flag = 1;
                break;
            case 'b':
                b_flag = 1;
                b_arg = optarg;
                break;
            case 'c':
                c_flag = 1;
                break;
            case '?':
            if (optopt == 'b')
                fprintf(stderr, "-b option given without argument!..\n");
            else
                fprintf(stderr, "invalid option: -%c\n", optopt);
			err_flag = 0;

            break;
        }
    }
	if (err_flag)
		exit(EXIT_FAILURE);

    if (a_flag)
        printf("-a given...\n");

    if (b_flag)
        printf("-b given with argument \"%s\"...\n", b_arg);

    if (c_flag)
        printf("-a given...\n");

    if (argc - optind != 0)
        printf("argument without options:\n");

    for (int i = optind; i < argc; ++i)
        puts(argv[i]);

    return 0;
}

/* ------------------------------------------------------------------------------------------------------------------------------------------
												7.Ders 18/06/2023 - Pazar
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	getopt fonksiyonun kullanımına bir örnek. Bu örnekte disp isimli program şu klomut satırı argümanlarını almaktadır:

	-x (display hex)
	-o (display octal)
	-t (display text)
	-n (number of character per line)

	Burada -x, -o ve -t seçeneklerinden yalnızca bir tanesi kullanılabilmektedir. eğer hiçbir seçenek kullanılmazsa default durum "-t" 
	biçimindedir. -n seçeneği yalnızca hex ve octal görüntülemede kullanılabilmektedir. Bu seçenek de belirtilmezse sanki "-n 16" gibi 
	bir belirleme yapıldığı varsayılmaktadır. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* disp.c */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>

#define DEFAULT_LINE_CHAR       16

bool disp_text(FILE *f);
bool disp_hex(FILE *f, int n_arg);
bool disp_octal(FILE *f, int n_arg);
int check_number(const char *str);

int main(int argc, char *argv[])
{
    int result;
    int t_flag, o_flag, x_flag, n_flag, err_flag;
    int n_arg;
    FILE *f;
    
    t_flag = o_flag = x_flag = n_flag = err_flag = 0;
    n_arg = DEFAULT_LINE_CHAR;
    opterr = 0;

    while ((result = getopt(argc, argv, "toxn:")) != -1) {
        switch (result) {
            case 't':
                t_flag = 1;
                break;
            case 'o':
                o_flag = 1;
                break;
            case 'x':
                x_flag = 1;
                break;
            case 'n':
                n_flag = 1;
                if ((n_arg = check_number(optarg)) < 0) {
                    fprintf(stderr, "-n argument is invalid!..\n");
                    err_flag = 1;
                }
                break;
            case '?':
                if (optopt == 'n')
                    fprintf(stderr, "-%c option given without argument!..\n", optopt);
                else
                    fprintf(stderr, "invalid option: -%c\n", optopt);
                err_flag = 1;

            break;
        }
    }

    if (err_flag) 
        exit(EXIT_FAILURE);

    if (t_flag + o_flag + x_flag > 1) {
        fprintf(stderr, "only one of -[tox] option may be specified!..\n");
        exit(EXIT_FAILURE);
    }

   if (t_flag + o_flag + x_flag == 0)
        t_flag = 1;

    if (t_flag && n_flag) {
        fprintf(stderr, "-n option cannot be used with -t option!..\n");
        exit(EXIT_FAILURE);
    }

    if (argc - optind == 0) {
        fprintf(stderr, "file must be specified!..\n");
        exit(EXIT_FAILURE);
    }
    if (argc - optind > 1) {
        fprintf(stderr, "too many files specified!..\n");
        exit(EXIT_FAILURE);
    }

    if ((f = fopen(argv[optind], t_flag ? "r" : "rb")) == NULL) {
        fprintf(stderr, "cannot open file: %s\n", argv[optind]);
        exit(EXIT_FAILURE);
    }
    if (t_flag)
        result = disp_text(f);
    else if (x_flag)
        result = disp_hex(f, n_arg);
    else if (o_flag)
        result = disp_octal(f, n_arg);

    if (!result) {
        fprintf(stderr, "canno read file: %s\n", argv[optind]);
        exit(EXIT_FAILURE);
    }

    fclose(f);

    return 0;
}

bool disp_text(FILE *f)
{
    int ch;

    while ((ch = fgetc(f)) != EOF)
        putchar(ch);

    return feof(f);       
}

bool disp_hex(FILE *f, int n_arg)
{
    size_t i;
    int ch;

    for (i = 0;(ch = fgetc(f)) != EOF; ++i) {
        if (i % n_arg == 0) {
            if (i != 0)
                putchar('\n');
            printf("%08zX ", i);
        }
        printf("%02X ", ch);

    }
    putchar('\n');

    return feof(f);
}

bool disp_octal(FILE *f, int n_arg)
{
    size_t i;
    int ch;

    for (i = 0;(ch = fgetc(f)) != EOF; ++i) {
        if (i % n_arg == 0) 
            printf("%08zo ", i);
    
        printf("%03o ", ch);
        if (i % n_arg == n_arg - 1)
            putchar('\n');
    }
    putchar('\n');

    return feof(f);
}

int check_number(const char *str)
{
    const char *temp;
    int result;

    while (isspace(*str))
        ++str;
    
    temp = str;

    while (isdigit(*str))
        ++str;
    
    if (*str != '\0')
        return -1;
    
    result = atoi(temp);
    if (!result)
        return -1;

    return result;
}

/* ------------------------------------------------------------------------------------------------------------------------------------------
	getopt kullanımına bir örnek. Aşağıdaki mycalc programı iki komut satırı argümanı üzerinde dört işlem uygulamaktadır. 
	Uygulanacak işlemler seçeneklerle belirtmiştir. Seçenekler şunlardır:

	-a (addition)
	-s (subtraction)
	-m (multiplication)
	-d (division)

	Programın kullanımı şöyledir:
	
	./mycalc [-asmd] <number1> <number2>
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* mycalc.h */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int result;
	int a_flag, s_flag, m_flag, d_flag;
	int err_flag;
	double arg1, arg2, val_result;

	opterr = 0;

	a_flag = s_flag = m_flag = d_flag = 0;
	err_flag = 0;

	while ((result = getopt(argc, argv, "asmd")) != -1) {
		switch (result) {
		case 'a':
			a_flag = 1;
			break;
		case 's':
			s_flag = 1;
			break;
		case 'm':
			m_flag = 1;
			break;
		case 'd':
			d_flag = 1;
			break;
		case '?':
			fprintf(stderr, "invalid option: -%c\n", optopt);
			err_flag = 1;
		}
	}

	if (err_flag)
		exit(EXIT_FAILURE);

	if (a_flag + s_flag + m_flag + d_flag != 1) {
		fprintf(stderr, "exactly one option must be specified!..\n");
		exit(EXIT_FAILURE);
	}

	if (argc - optind != 2) {
		fprintf(stderr, "wrong number of arguments!..\n");
		exit(EXIT_FAILURE);
	}

	arg1 = strtod(argv[optind], NULL);
	arg2 = strtod(argv[optind + 1], NULL);

	if (a_flag)
		val_result = arg1 + arg2;
	else if (s_flag)
		val_result = arg1 - arg2;
	else if (m_flag)
		val_result = arg1 * arg2;
	else
		val_result = arg1 / arg2;

	printf("%f\n", val_result);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
														8. Ders 01/07/2023 - Cumartesi
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	Daha önceden de belirttiğimiz gibi komut satırında uzun seçenek kullanımı POSIX standartlarında yoktur. Ancak Linux gibi pek çok 
	sistemdeki çeşitli yardımcı programlar uzun seçenekleri desteklemektedir. Programlarda bazı kısa seçeneklerin eşdeğer uzun seçenekleri
	bulunmaktadır. Bazı uzun seçeneklerin ise kısa senek eşdeğeir bulunmamaktadır. Bazı kısa seçeneklerin de uzun seçenek eşdeğerleri yoktur. 

	Uzun seçenekleri parse etmek için getopt_long isimli fonksiyon kullanılmakatdır. Uzun seçenekler POSIX standartlarında olmadığına göre 
	getopt_long fonksiyonu da bir POSIX fonksiyonu değildir. Ancak GNU'nun glibc kütüphanesinde bir eklenti biçiminde bulunmaktadır. 
	getopt_long fonksiyonu işlevsel olarak getopt fonksiyonunu kapsamaktadır. Ancak fonksiyonun kullanımı biaz daha zordur. Fonksiyonun 
	prototipi şöyledir:


	#include <getopt.h>

	int getopt_long(int argc, char * const argv[], const char *optstring, const struct option *longopts, int *longindex);

	Fonksiyonun birinci ve ikinci parametrelerine main fonksiyonundan alınan argc ve argv parametreleri geçirilir. Fonksiyonun üçüncü parametresi 
	yine kısa seçeneklerin belirtildiği yazının adresini almaktadır. Yani fonksiyonun ilk üç parametresi tamamen getopt fonksiyonu ile aynıdır. 
	Fonksiyonun dördüncü parametresi uzun seçeneklerin belirtildiği struct option türünden bir yapı dizisinin adresini almaktadır. Her uzun seçenek
	struct option türünden bir nesneyle ifade edilmektedir. struct option yapısı şöyle bildirilmiştir:

	struct option {
		const char *name;
		int         has_arg;
		int        *flag;
		int         val;
	};

	Fonksiyon bu yapı dizisinin bittiğini nasıl anlayacaktır? İşte yapı dizisinin son elemanına ilişkin yapı nesnesinin tüm elemanları 0'larla
	doldurulmalıdır. (0 sabitinin göstericiler söz konusu olduğunda NULL adres anlamına geldiğini de anımsayınız.)

	struct option yapısının name elemanı uzun seçeneğin ismini belirtmektedir. Yapının has_arg elemanı üç değerden birini alabilir:

	no_argument (0)
	required_argument (1)
	optional_argument (2)

	Bu eleman uzun seçeneğin argüman alıp almadığını belirtmektedir. Yapının flag ve val elemanları birbirleriyle ilişkilidir. Yapının val elemanı
	uzun seçenek bulunduğunda bunun hangi sayısal değerle ifade edileceğini belirtir. İşte bu flag elemanına int bir nesnenin adresi geçilirse bu durumda 
	uzun seçenek bulunduğunda bu val değeri bu int nesneye yerleştirilir. getopt_long iğse bu udurmda 0 değeri ile geri döner. Ancak bu flag 
	göstewricisine NULL adres de geçilebilir. Bu durumda getopt_long uzun seçenek bulunduğunda val elemanındaki değeri geri dönüş değeri olarak verir. 
	Örneğin:

	struct option options[] = {
		{"count", required_argument, NULL, 'c'},
		{0, 0, 0, 0}
	};

	Burada uzun seçenek "--count" biçimindedir. Bir argümanla kullanılmak zorundadır. Bu uzun seçenek bulunduğunda flag parametresi NULL adres 
	geçildiği için getopt_long fonksiyonu 'c' değeri ile geri dönecektir. Örneğin:

	int count_flag;
	...

	struct option options[] = {
		{"count", required_argument, &count_flag, 1},
		{0, 0, 0, 0}
	};

	Burada artık uzun seçenek bulunduğunda getopt_long fonksiyonu 0 ile geri dönecek ancak 1 değeri count_flag nesnesine yerleştirilecektir. 

	getopt_long fonksiyonunun son parametresi uzun seçenek bulunduğunda o uzun seçeneğin option dizisindeki kaçıncı indeksli uzun seçenek olduğunu 
	anlamak için kullanılmaktadır. Burada belirtilen adresteki nesneye uzun seçeneğin option dizisi içerisindeki ndeks numarası yerleştirilmektedir. 
	Ancak bu bilgiye genellikle gereksinim duyulmamaktadır. Bu parametre NULL geçilebilir. Bu durumda böyle bir yerleştirme yapılmaz. 

	Bu durumda getopt_long fonksiyonunun geri dönüş değeri beş biçimden biri olabilir:

	1) Fonksiyon bir kısa seçenek bulmuştur. Kısa seçeneğin karakter koduyla geri döner. 
	2) Fonksiyon bir uzun seçenek bulmuştur ve option yapısının flag elemanında NULL adres vardır. Bu durumda fonksiyon option yapısının 
	val elemanındaki değerler geri döner. 
	3) Fonksiyon bir uzun seçenek bulmuştur ve option yapısının flag elemanında NULL adres yoktur. Bu durumda fonksiyon val değerini bu adrese 
	yerleştirir ve 0 değeri ile geri döner. 
	4) Fonksiyon geçersiz (yani olmayan) bir kısa ya da uzun seçenekle karşılaşmıştır ya da argümanlı bir kısa seöenek ya da uzun seçeneğin 
	argümanı girilmemiştir. Bu durumda fonksiyon '?' karakterinin değeriyle geri döner. 
	5) Parse edecek argüman kalmamıştır fonksiyon -1 ile geröner. 

	getopt fonksiyonundaki yardımcı global değişkenlerin aynısı burada da kullanılmaktadır:

	opterr: Hata mesajının fonksiyon tarafından stderr dosyasına basılıp basılmayacağını belirtir. 
	optarg: Argümanlı bir kısa ya da uzun seçenekte argümanı belirtmektedir. Eğer "isteğe bağlı argümanlı" bir uzun seçenek bulunmuşsa 
	ve bu uzun seçenek için argüman girilmemişse optarg nesnesine NULL adres yerleştirilmektedir. 
	optind: Bu değişken yine seöeneksiz argümanların başladığı indeksi belirtmektedir. 
	optopt: Bu değişken geçerisz bir uzun ya da kısa seçenek girildiğinde hatanın nedenini belirtmektedir. 

	getopt_long geçersiz bir seçenekle karşılaştığında '?' geri dönmekle birlikte optopt değişkenini şu biçimlerde set etmektedir:

	1) Eğer fonksiyon argümanlı bir kısa seçenek bulduğu halde argüman girilmemişse o argümanlı kısa seçeneğin karakter karşışığını 
	optopt değişkenine yerleştirir. 
	2) Eğer fonksiyon argümanlı bir uzunseçenek bulduğu halde argüman girilmemişse o argümanlı uzun seçeneğin option yapısındaki val değerini 
	optopt değişkenine yerleştirmektedir. 
	3) Eğer fonksiyon geçersiz bir kısa seçenekle karşılaşmışsa bu duurmda optopt geçersiz kısa seçeneğin karakter karşılığına geri döner.
	4) Eğer fonksiyon geçersiz bir uzun seçenekle karşılaşmışsa bu duurmda optopt değişkenine 0 değeri yerleştirilmektedir.

	Maalesef getopt_long olmayan bir uzun seçenek girildiğinde bunubize vermemektedir. Ancak GNU'nun getopt_long gerçekleştirimine bakıldığında 
	bu geçersiz uzun seçeneğin argv dizisinin "optind - 1" indeksinde olduğu görülmektedir. Yani bu geçersiz uzun seçeneğe argv[optind - 1] 
	ifadesi ile erişilebilmektedir. Ancak bu durum glibc dokümanlarında belirtilmemiştir. Bu nedenle bu özelliğin kullanılması uygun değildir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	Aşağıdaki örnekteki komut satırı argümanları şunlardır:

	-a
	-b
	-c <arg> ya da --count <arg>
	--verbose
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char *argv[])
{
	int a_flag, b_flag, c_flag, verbose_flag;
	int err_flag;
	char *c_arg;
	int result;

	struct option options[] = {
		{"count", required_argument, NULL, 'c'},
		{"verbose", no_argument, &verbose_flag, 1},
		{0, 0, 0, 0}
	};

	a_flag = b_flag = c_flag = verbose_flag = err_flag = 0;

	opterr = 0;
	while ((result = getopt_long(argc, argv, "abc:", options, NULL)) != -1) {
		switch (result) {
		case 'a':
			a_flag = 1;
			break;
		case 'b':
			b_flag = 1;
			break;
		case 'c':
			c_flag = 1;
			c_arg = optarg;
			break;
		case '?':
			if (optopt == 'c')
				fprintf(stderr, "option -c or --count without argument!..\n");
			else if (optopt != 0)
				fprintf(stderr, "invalid option: -%c\n", optopt);
			else
				fprintf(stderr, "invalid long option!..\n");
			/* fprintf(stderr, "invalid long option: %s\n", argv[optind - 1]); */
			err_flag = 1;
			break;
		}
	}

	if (err_flag)
		exit(EXIT_FAILURE);

	if (a_flag)
		printf("-a option given\n");
	if (b_flag)
		printf("-b option given\n");
	if (c_flag)
		printf("-c or --count option given with argument \"%s\"\n", c_arg);
	if (verbose_flag)
		printf("--verbose given\n");

	if (optind != argc) {
		printf("Arguments without options");
		for (int i = optind; i < argc; ++i)
			printf("%s\n", argv[i]);
	}

	return 0;
}

/* ------------------------------------------------------------------------------------------------------------------------------------------
	getopt_long fonksiyonun kullanımına diğer bir örnekte aşağıda verilmiştir. Aşağıda programın komut satırı argümanları şunlardır:

	-a
	-b <arg>
	-c 
	-h ya da --help
	--count <arg>
	--line[=<arg>]

-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char *argv[])
{
	int result;
	int a_flag, b_flag, c_flag, h_flag, count_flag, line_flag;
	char *b_arg, *count_arg, *line_arg;
	int err_flag;
	int i;

	struct option options[] = {
		{"help", no_argument, &h_flag, 1},
		{"count", required_argument, NULL, 2},
		{"line", optional_argument, NULL, 3},
		{0, 0, 0, 0 },
	};

	a_flag = b_flag = c_flag = h_flag = count_flag = line_flag = 0;
	err_flag = 0;

	opterr = 0;
	while ((result = getopt_long(argc, argv, "ab:ch", options, NULL)) != -1) {
		switch (result) {
			case 'a':
				a_flag = 1;
				break;
			case 'b':
				b_flag = 1;
				b_arg = optarg;
				break;
			case 'c':
				c_flag = 1;
				break;
			case 'h':
				h_flag = 1;
				break;
			case 2:			/* --count */
				count_flag = 1;
				count_arg = optarg;
				break;
			case 3:			/* --line */
				line_flag = 1;
				line_arg = optarg;
				break;
			case '?':
				if (optopt == 'b')
					fprintf(stderr, "-b option must have an argument!..\n");
				else if (optopt == 2)
					fprintf(stderr, "argument must be specified with --count option\n");
				else if (optopt != 0)
					fprintf(stderr, "invalid option: -%c\n", optopt);
				else
					fprintf(stderr, "invalid long option!..\n");

				err_flag = 1;

				break;
		}
	}

	if (err_flag)
		exit(EXIT_FAILURE);

	if (a_flag)
		printf("-a option given...\n");

	if (b_flag)
		printf("-b option given with argument \"%s\"...\n", b_arg);

	if (c_flag)
		printf("-c option given...\n");

	if (h_flag)
		printf("-h or --help option given...\n");

	if (count_flag)
		printf("--count option specified with \"%s\"...\n", count_arg);

	if (line_flag) {
		if (line_arg != NULL)
			printf("--line option given with optional argument \"%s\"\n", line_arg);
		else
			printf("--line option given without optional argument...\n");
	}

	if (optind != argc) {
		printf("Arguments without options:\n");
		for (i = optind; i < argc; ++i)
			printf("%s\n", argv[i]);
	}

	return 0;
}

/* ------------------------------------------------------------------------------------------------------------------------------------------
	Aşağıdaki örnekte bir ya da birden fazla dosyanın içeriği görüntülenmektedir. Buradaki seçenekler şunlardır:

	-x: Hex olarak görünler
	-o: Octal olarak görüntüler
	-t: Yazı olarak görüntüler
	-h ya da --header: Her dosyanın başına dosya ismini de yazar
	--line[=<arg>]: Bu argüman hiç belirtilezse tüm dosya görüntülenir. İsteğe bağlı argüman girilmezse 10 satır görüntülenir. 
	İsteğe bağlı argüman girilirse girildiği kadar satır görüntülenir.

	myod [--top --header -x -o -t -h] <dosya listesi>
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* myod.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

/* Symbolic Constans */

#define DEF_LINE                10
#define HEX_OCTAL_LINE_LEN      16

/* Function Prorotypes */

int print_text(FILE *f, int nline);
int print_hex_octal(FILE *f, int nline, int hexflag);

int main(int argc, char *argv[])
{
	int result, err_flag = 0;
	int x_flag = 0, o_flag = 0, t_flag = 0, top_flag = 0, header_flag = 0;
	char *top_arg;
	struct option options[] = {
		{"top", optional_argument, NULL, 1},
		{"header", no_argument, NULL, 'h'},
		{0, 0, 0, 0}
	};
	FILE *f;
	int i, nline = -1;

	opterr = 0;
	while ((result = getopt_long(argc, argv, "xoth", options, NULL)) != -1) {
		switch (result) {
		case 'x':
			x_flag = 1;
			break;
		case 'o':
			o_flag = 1;
			break;
		case 't':
			t_flag = 1;
			break;
		case 'h':
			header_flag = 1;
			break;
		case 1:
			top_flag = 1;
			top_arg = optarg;
			break;
		case '?':
			if (optopt != 0)
				fprintf(stderr, "invalid switch: -%c\n", optopt);
			else
				fprintf(stderr, "invalid switch: %s\n", argv[optind - 1]);  /* argv[optind - 1] dokümante edilmemiş */
			err_flag = 1;
		}
	}

	if (err_flag)
		exit(EXIT_FAILURE);

	if (x_flag + o_flag + t_flag > 1) {
		fprintf(stderr, "only one option must be specified from -o, -t, -x\n");
		exit(EXIT_FAILURE);
	}
	if (x_flag + o_flag + t_flag == 0)
		t_flag = 1;

	if (top_flag)
		nline = top_arg != NULL ? (int)strtol(top_arg, NULL, 10) : DEF_LINE;

	if (optind == argc) {
		fprintf(stderr, "at least one file must be specified!..\n");
		exit(EXIT_FAILURE);
	}

	for (i = optind; i < argc; ++i) {
		if ((f = fopen(argv[i], "rb")) == NULL) {
			fprintf(stderr, "cannot open file: %s\n", argv[i]);
			continue;
		}

		if (header_flag)
			printf("%s\n\n", argv[i]);

		if (t_flag)
			result = print_text(f, nline);
		else if (x_flag)
			result = print_hex_octal(f, nline, 1);
		else
			result = print_hex_octal(f, nline, 0);

		if (i != argc - 1)
			putchar('\n');

		if (!result)
			fprintf(stderr, "cannot read file: %s\n", argv[i]);

		fclose(f);
	}

	return 0;
}

int print_text(FILE *f, int nline)
{
	int ch;
	int count;

	if (nline == -1)
		while ((ch = fgetc(f)) != EOF)
			putchar(ch);
	else {
		count = 0;
		while ((ch = fgetc(f)) != EOF && count < nline) {
			putchar(ch);
			if (ch == '\n')
				++count;
		}
	}

	return !ferror(f);
}

int print_hex_octal(FILE *f, int nline, int hexflag)
{
	int ch, i, count;
	const char *off_str, *ch_str;

	off_str = hexflag ? "%07X " : "%012o";
	ch_str = hexflag ? "%02X%c" : "%03o%c";

	if (nline == -1)
		for (i = 0; (ch = fgetc(f)) != EOF; ++i) {
			if (i % HEX_OCTAL_LINE_LEN == 0)
				printf(off_str, i);
			printf(ch_str, ch, i % HEX_OCTAL_LINE_LEN == HEX_OCTAL_LINE_LEN - 1 ? '\n' : ' ');
		}

	else {
		count = 0;
		for (i = 0; (ch = fgetc(f)) != EOF && count < nline; ++i) {
			if (i % HEX_OCTAL_LINE_LEN == 0)
				printf(off_str, i);
			printf(ch_str, ch, i % HEX_OCTAL_LINE_LEN == HEX_OCTAL_LINE_LEN - 1 ? '\n' : ' ');
			if (ch == '\n')
				++count;
		}
	}

	if (i % HEX_OCTAL_LINE_LEN != 0)
		putchar('\n');

	return !ferror(f);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	İşletim sistemlerinin çekirdekleri C Programlama Dili kullanılarak yazılmıştır. (Çekirdek kodlamasında C++ kullanılmamaktadır. Yaygın 
	işletim sistemlerinin bütün çekirdek kodları C'de yazılmış durumdadır.) Dolayısıyla işletim sistemlerinin çekirdekleri 
	"nesne yönelimli (object oriented)" değil "prosedürel teknikle" yazılmaktadır. Örneğin Linux çekirdeğinde binlerce fonksiyon bulunmaktadır. 

	İşletim sistemlerinin çekirdeklerindeki bir grup fonksiyon dışarıdan da uygulama programcıları tarafından çağrılabilmektedir. Bu fonksiyonlara
	"işletim sisteminin sistem fonksiyonları (system call)" denilmektedir. İşte dosya açma, kapama, dosyadan okuma yazma yapma yapma gibi, 
	dosya silme gibi, başka bir programı çalıştırma gibi işlemler aslında ilgili işletim sisteminin sistem fonksiyonları ile yapılmaktadır. 
	Biz bir dosyasyı C'de fopen isimli standart C fonksiyonu ile açarız. Ancak aslında dosya açma işinin asıl sorumlusu işletim sistemidir. 
	Yani fopen fonksiyonu aslında dosyayı kendisi açmamaktadır. İşletim sisteminin dosya açmakta kullanılan sistem fonksiyonunu çağırmaktadır. 
	Uygulama programcıları işletim sisteminin içerisindeki diğer fonksiyonları çağıramamaktadır. Yalnızca "sistem fonksiyonu" biçiminde yazılmış 
	olan fonksiyonları çağırabilmektedir. 

	İşletim sistemlerinin sistem fonksiyonlarının isimleri, parametrik yapıları işletim sisteminden işletim sistemine hatta aynı işletim sisteminde
	versiyondan versiyona değişebilmektedir. Dolaysıyla sistem fonksiyonlarının taşınabilirliği yoktur. Linux işletim sisteminde sistem fonksyionlarının
	isimleri sys_xxxx öneki ile başlatılarak isimlendirilmiştir. 

	UNIX türevi sistemlerdeki ortak C fonksiyonlarına POSIX fonksiyonları denilmektedir. POSIX kütüphanesinin amacı mimari olarak birbirine benzeyen 
	ancak çekirdek kodlaması bakımından birbirinden farklı olan UNIX türevi sistemlerde kulalnılabilecek ortak taşınabilir fonksiyonların 
	oluşturulmasıdır. POSIX fonksiyolarının bazıları doğrudna işletim sistemindeki sistem fonksiyonlarını bire bir çağırıyor olabilir. Bazı 
	POSIX fonksiyonları ise işletim sisteminin hiçbir sistem fonksiyonunu çağırtmıyor olabilir. Bazı POSIX fonksiyonları birden fazla sistem fonksiyonu 
	çağrılarak gerçekleştirilmiş de olabilir. 

	Windows API fonksiyonları da Windows sistemleri üzerinde taşınabilir bir kütüphane oluşturmaktadır. Yani nasıl POSIX kütüphanesai UNIX 
	türevi sistemlerin ortak fonksiyonlarını barındırıyorsa Windows API fonksiyonları da Windows sistemlerinde kullanılabilen ortak fonksiyonları 
	barındırmaktadır. Başka bir deyişle düzey v eişlev olarak POSIX fonksiyonlarıyla Windows API fonksiyonları benzerdir. Yine bazı Windows API 
	fonksiyonları Windows'un sistem fonksiyonlarını çağırabilmekte bazıları ise bir sistem çağrısı yapmayabilmektedir. 

	Standart C fonksiyonları her C derleyicisinde bulunan ortak fonksiyonlardır. Tabii bunların bazıları UNIX türevi sistemlerde POSIX fonksiyonları
	çağrılarak Windows sistemlerinde ise Windows API fonksiyonu çağrılarak yazılmış durumdadır. Örneğin fopen fonksiyonu Linux sistemlerinde 
	open isimi POSIX fonksiyonunu çağırmakta, open POSIX fonksiyonu ise sys_open sistem fonksiyonunu çağırmaktadır:

	fopen ---> open ---> sys_open

	Aynı fopen fonksiyonu Windows sistemlerinde CreateFile isimli API fonksiyonunu çağırmakta CreateFile Windows'un sistem fonksiyonunu çağırmaktadır. 

	fopen ---> CreateFile ---> NtCreeateFile

	Tabii fopen fonksiyonu UNIX türevi sistemlerde yalnızca open fonksiyonunu, Windows sistemlerinde CreateFile fonksiyonunu çağırmamaktadır. 
	Başka şeyler de yapmaktadır. Ancak asıl dosyanın açılması yukarıda belirrtiğimiz çağrılarla işletim sistemi tarafındna yapılmaktadır. 

	Java, C# ve Python gibi dillerde de tamamen bu tür işlemler benzer biçimde gerçekleştirilmektedir. Örneğin Python ile Linux sistemlerinde 
	bir dosya açılmak istendiğinde dosya open isimli fonksiyonla açılmaktadır. Aslında bu open fonksiyonu fopen fonksiyonunu çağırmaktadır. 

	open (Python) ---> fopen  --> open ---> sys_open

	Pekiyi bir C programcısının doğrudan işletim sisteminin sistem fonksiyonlarını çağırmasına gerek duyulmakta mıdır? Aslında çoğu zaman 
	C programcıları UNUX/Linux sistemlerinde POSIX fonksiyonlarını Windows sistemlerinde ise Windows API fonksiyonlarını kulalnmaktadır. 
	Ancak çok seyrek de olsa bazen C prograöcısının doğrudan ilgili sistem fonksiyonunu çağırması gerekebilmektedir. Örneğin Linux sistemlerinde 
	bazı sistem fonksiyonları hiçbir POSIX fonksiyonu tarafından çağrılmamaktadır. Programcı mecburen gerektiği zaman onları kendisi çağırır. 
	Ancak böylesi gereksinimler oldukça seyrektir. 

	Pekiyi bir C programcısının işletim sistemiyle ilgili en aşağı etkişelmi nasıl olmaktadır? İşte C programcısı en aşağı düzeyde aslında 
	sistem fonksiyonlarını kendisi çağırarak işini yapabilir. Ancak genellikle bunun yerine C programcıları UNIX/Linux sistemlerinde POSIX 
	fonksiyonlarını çağırarak, Windows sistemlerinde de Windows API fonksiyonlarını çağırarak aşağı seviyeli işlemleri yaparlar. Aslında C 
	programcısının işletim sistemi ile en yakın olabildiği çalışma biçimi "aygıt sürücü (device driver)" ya da "çekirdek modülü (kernel module)" 
	yazımı sırasındadır. Aygıt sürücüler ve çekirdek modülleri adeta çekirdeğin içerisine bir modül eklemek anlamına geşmektedir. 

	Bu durumda eğer biz bir işlemi etkin bir biçimde standart C fonksiyonları ile yapabiliyorsak onları çağırarak yaparız. Eğer standart C fonksiyonları
	bu işleme yetmiyorsa bu durumda UNIX/Linux sistemlerinde POSIX fonksiyonlarını Windows sistemlerinde de Windows API fonksiyonlarını kullanmalıyız. 
	Eğer hala bunlar yetersiz kalıyorsa işletim sisteminin sistem fonksiyonlarını doğrudan çağırabiliriz. 

	Örneğin bir dizin (directory) yaratmak istediğimizi düşünelim. Bu işi yapacak bir standart C fonksiyonu yoktur. O halde biz bu işlem için 
	UNIX/Linux sistemlerinde mkdir isimli POSIX fonksiyonunu Windows sistemlerinde de CreateDirectory isimli API fonksiyonunu kullanırız. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
														9. Ders - 02/07/2023-Pazar
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows'un API fonksiyonlarının prototipleri çeşitli başlık dosyalarının içerisinde bulundurulmuştur. Ancak en genel başlık dosyası 
	(bu dosya başka başlık dosyalarını da kendi içerisinde include etmektedir) <windows.h> isimli dosyadır. Dolayısıyla bir Windows API
	fonksiyonu kullanılacaksa bu dosyanın include edilmesi gerekir. 

	Windows API fonksiyonlarının yazı parametresi alanları ASCII ve UNICODE karakter kümeleri için iki farklı fonksiyon biçiminde yazılmıştır. 
	Örneğin yazı parametresi alan API fonksiyonun isminin xxxxx olduğunu varsayalım. Aslında xxxxx isimli bir fonksiyon yoktur. xxxxxA ve 
	xxxxxW biçiminde fonksiyonlar vardır. Ancak biz bu fonksiyonu kullanırken xxxxx ismini kullanırız. Önişlemci bu xxxxx ismini "yapılmış olan
	ayara göre" xxxxxA ya da xxxxxW haline getirmektedir. Biz kursumuzda bu API fonksiyonlaarın ASCII versiyonlarını kullanacağız. Ancak bir proje
	yaratıldığında Visual Stduio default ayarı UNICODE yapmaktadır. Bu nedenle bir proje yarattıktan sonra proje seçeneklerinden Advanced 
	sekmesinden "Cahatacter Set" seçeneği "Not Set" haline getirilmelidir. Aksi takdirde bizim bu API fonksiyonlarına UNICODE yazılar girmemiz 
	gerekir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows dünyasında çalışırken Windows sistemleri arasındaki taşınabilirliğin sağlanması ve okunabilirliğin artırılması için Microsoft 
	tarafından çeşitli typedef isimleri oluşturulmuştur. Windows API programcısının bu typedef isimlerine aşina olması gerekmektedir. Bu typedef
	isimlerinin hepsi büyük harflerle oluşturulmuştur. Programcı da kendi fonksiyonlarını yazarken mümkün olduğunca bu typedef isimlerini 
	kullanmalıdır. Bu typedef bildirimleri <windows.h> içerisinde bulunmaktadır. Önemli olanları şunlardır:

	BYTE: 1 byte uzunlupunda işaretsiz tamsayı türü (tipik olarak unsigned char)
	WORD: 2 byte uzunlupunda işaretsiz tamsayı türü (tipik olarak unsigned short)
	DWORD: 4 byte uzunlupunda işaretsiz tamsayı türü (tipik olarak unsigned int)
	QWORD: 8 byte uzunlupunda işaretsiz tamsayı türü (tipik olarak unsigned long long int)

	Adres türleri başına P ya da LP öneki getirilerek isimlendirilmiştir. 16 bit Windows sistemlerinde P öneki "near pointer", LP öneki 
	"far pointer" için kullanılıyordu. Ancak daha sonra 32 Windows sistemlerine geçildiğinde artık göstericiler arasında "yakın" ve "uzak"
	ayrımı kalkmıştır. Dolayısıyla P öneki ile LP öneki arasında bir fark kalmamıştır. Ancak geleneksel olarak programcılar P öneki yerine LP
	önekini tercih etmektedir. Bir göstericinin gösterdiği yerin const olduğu P ya da LP önekinden sonraki C ekiyle belirtmiştir. Örneğin 
	PC ya da LPC önekleri "gösterdiği yer const olan" göstericiler için kullanılmaktadır. Göstericilerin türü de bu öneki izlemektedir. 
	Örneğin LPCDWORD tür ismi "const DWORD *" anlamına gelmektedir. Ancak LPDWORD tür ismi "DWORD *" anlamına gelmektedir. void türü VOID olarak 
	da typedef edilmiştir. Bu duurmda örneğin LPVOID tür ismi "void *" anlamına gelir. LPCVOID tür ismi ise "const void *" anlamına gelmektedir. 
	char türden adresler PSTR ya da LPSTR ismiyle typedef edilmiştir. Bunlar const biçimleri de PCSTR ya da LPCSTR biçiminde isimlendirilmiştir. 
	HANDLE tür ismi genel olarak "handle" belirtir. Bu tür ismi "void *" olarak typedef edilmiştir. 

	PSTR, PCSTR, LPSTR ve LPCSTR gibi yazıları gösteren adres türlerinin T'li biçimleri de vardır. Örneğin LPSTR türünün yanı sıra LPTSTR türü gibi, 
	LPCSTR türünün yanı sıra LPCTSTR türü gibi. Bu T'li türler seçilen konfigürasyona göre ASCII ya da UNICODE olabilen türleri temsil etmektedir. 

	C'nin standart türleri de (her ne kadar gerekmiyorsa da) büyük harflerle typedef edilmiştir. Örneğin INT, LONG, CHAR, DOUBLE gibi typedef 
	isimleri orijinal C türlerine karşılık gelmektedir. 

	BOOL türü int olarak typedef edilmiştir. Bir API fonksiyonun geri dönüş değerinde BOOL gördüğümüzde bu geri dönüş değerinin başarı/balarısızlık 
	biçiminde bir değer verdiğini anlarız. Örneğin:

	BOOL SomeFunc(void);

	Yapılar büyük harflerle isimlendirilmiştir. Yapı isimlerinin başına "tag" öneki getirilmiştir. Ancak typedef isimlerinde bu "tag" öneki yoktur. 
	Örneğin:

	typedef struct tagRECT {
		...
	} RECT;

	Yine yapılar türünden adresler de bu yapı isimlerinin başına P, LP, PC, LPC gibi önekler getirilerek isimlendirilmiştir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows API programlamada kullanılan isimlendirme sistemine "Macar Notasyonu (Hungarian Notation)" denilmekteir. Windows API programcılarının 
	bu Macar notasyonu hakkında bilgi sahibi olması gerekmektedir. Macar notasyonun en belirgin özelliklerinden biri değişken isimlerinin başında 
	değişkenlerin türlerini belirten öneklerin bulunmasıdır. Öneklerin bazıları şunlardrı:

	b			BYTE, BOOL
	w			WORD
	dw			DWORD
	p, lp		Adres
	sz			CHAR türden yazı belirten diziler
	psz, lpsz	CHAR türden yazı belirten adres
	pc			CHAR türden adres
	h			HANDLE
	l			LONG
	u			UNSIGNED INT
	lu			UNSIGNED LONG

	Yapı türünden değişkenlerde o yapıya ilişkin küçük önekler kullanılmaktadır. Örneğin rect öneki dikdörtgen belirten RECT yapısı türünden
	değişkenlerde kullanılır. 

	Macar Notasyonunda bir değişken ismi onun türünü belirtne önekten sonra her sözcüğün ilk harfi büyük yazılarak isimlendirilmektedir. Örneğin:

	DWORD dwNumberOfSectors;
	LONG lStudentNumber;
	char szName[64];
	DWORD dwWordCount;
	LPSTR lpszFileName;

	Macar notasyonundaki önek getirme bazı programcılar tarafından daha gevşek bir biçimde yapılabilmektedir. Örneğin Microsoft da int türü 
	için özel bir önek kullanmamaktadır. Değişkenler için önek kullanılmıyor olsa da değişken harflendirilmesi "deve notasyonuna (camel sasting)"
	uygun yapılmalıdır. Örneğin:

	int numberOfStudents;

	Deve notasyonunda ilk sözcük tamamen küçük harflerle sonraki sözcüklerin yalnızca ilk harflari büyük harflerle yazılmaktadır. Tabii değişken 
	ismi zaten tek sözcükten oluşyorsa sözcüğün tamamı küçük harflerle yazılır. Örneğin:

	int i;
	int count;

	Tabii değişken türe ilişkin bir önek içeriyorsa zaten bu önek deve notasyonundaki ilk sözcüğün yerini tutmaktadır. 

	Macar Notasyonunda değişken isimleri biraz uzun olma eğilimindedir. Bu notasyon programcılar için yorucu olabilmektdir. 

	Macar notasyonunda fonksiyon isimleri "Pascal tarzı harflendirmeyle (Pascal casting)" oluşturulmaktadır. Pascal notasyonunda her 
	sözcüğün (ilk sözcük de dahil) ilk harfi büyük yazılmaktadır. Fonksiyon isimlerinde önce eylem belirten sözcük sonra o eylemin nesnesine 
	ilişkin sözcükler kullanılmaktadır. Örneğin:

	CreateFile
	ReadFile
	GetWindowLong
	SetWindowText

	Windows sistemlerinde Microsoft'un C ve C++ derleyicileri zaten default olarak API fonksiyonlarının bulunduğu kütüphane dosyalarına 
	link aşamasında referans etmektedir. Dolayısıyla API fonksiyonlarının kullanılması için porgramcının özel bir şey yapması gerekmemektedir. 
	-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux dünyasında POSIX fonksiyonlarında Windows'ta olduğu gibi özel bir yazım notasyonu kullanılmamıştır. POSIX fonksiyonları 
	klasik C isimlendirme tekniği ile isimlendirilmiştir. Fonksiyon isimlerinde hiç büyük harf kullanılmamıştır. Fonksiyon ismi uzunsa 
	sözcükleri ayırmak için alt tire kullanılmıştır. Genellik POSIX fonksiyonlarının isimleri kısa olma eğilimindedir. POSIX fonksiyonlarında 
	taşınabilirliği sağlamak için bazı typedef türleri de oluşturulmuştur. POSIX'in bu typedef türlerinin hemen hepsi <sys/types.h> dosyası 
	içerisinde bildirilmiştir. Fonksiyonların prototipileri ve bunlara ilişkin sembolik sabitler çeşitli başlık dosyalarında topalnmıştır. 
	Pek çok temel fonskyionun prototipi <unistd.h> isimli bir başlık dosyasında bulunmaktadır. POSIX sistemlerinde typedef isimleri xxxx_t biçiminde 
	"_t" soneki ile isimlendirilmiştir. Örneğin pid_t, pthread_mutex_t gibi. POSIX fonksiyonlarının kullanımı için programcının genellikle 
	link aşamasında özel bir kütüphaneye referans etmesi gerekmemektedir. Çünkü POSIX fonksiyonlarının çoğu standart C fonksiyonlarıyla aynı kütüphane 
	içerisinde (bunu "glibc" kütüphanesi denilmektdir) bulunmaktadır. Ancak bazı POSIX fonksiyonları başka kütüphanelerin içerisinde olduğu için 
	onlar kullanılırken o kütüphanelere referans etmek gerekmektedir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	Sistem programlamada yapılan işlemlerde çeşitli sorunlar ortaya çıkabilmektedir. Bu sorunların kaynağı programcının dışında da olabilmektedir. 
	Dolayısıyla sistem programcısının çağırdığı fonksiyonların başarısını kontrol etmesi ve sorunlar karşısında düzgün bir biçimde sorunun kaynağını 
	belirten hata mesajlarını oluşturması gerekir. Pekiyi het rürlü fonksiyonun başarısı kontrol edilmeli midir? Bu bakımdan fonksiyonları üç 
	gruba ayırabiliriz: 

	1) Her çağrıda başarı kontrolünün yapılması gerektiği fonksiyonlar: Bu fonksiyonlarda başarısızlık çok değişik faktörlere ve sistemin o anda 
	içinde bulunduğu koşullara bağlı olabilmektedir. Bu nedenle bu tür fonksiyonların başarılarının mutlaka programcı tarafından kontrol edilmesi 
	gerekir. Örneğin fopen gibi malloc gibi fonksiyonlar bu gruba örnek verilebilir. 

	2) Eğer programcı her şeyi doğru yapmışsa başarısız olma olasılığı olmayan fonksiyonlar: Bu tür fonksiyonlarda hata kontrolü yapılmaayabilir. 
	Çünkü bu tür fonksiyonlar "biz her şeyi düzgün yapmışsak başarısız olma olasılığı olmayan" fonksiyonlardır. Tabii programcı birtakım hatalar 
	yapmış olabilir. Bu nedenle bu bruptaki fonksiyonlar başarısız olmuş olabilir. Bu tür durumlarda hata kontrolleri projenin "debug" versiyonunda 
	yapılabilir "release" versiyonunda yapılmayabilir. Biz kursumuzda bu grup fonksiyonların başarısını kontrol etmeyeceğiz. fclose fonksiyonunu
	bu gruba örnek verebiliriz. Biz her şeyi doğru yapmışsa fclose fonksiyonun başarısız olma olasılığı yoktur. 

	3) Başarısz olma olasılığının olmadığı ya da bunun tespit olanağının olmadığı fonksiyonlar: Bazı fonksiyonların başarısız olma olasılığı yoktur. 
	Bazı fonksiyonların ise başarısız olma olasılığı olsa da bu başarısızlığın tespit edilmesi olanağı yoktur. Örneğin free fonksiyonu dinamik alanının
	geçerli alan olup olmadığını tespit edememektedir. Dolayısıyla free fonksiyonu bize zaten başarı-balarısızlık ile ilgili bir bilgi de 
	vermemektedir. Örneğin getpid POSIX fonksiyonu o anda çalışmakta olan prosesin id değerini bize verir. Bu fonksiyon başarısız olamaz. 
	Bu fonksiyonun başarısız olması işletim sisteminni kendisini inkar etmesi anlamına gelmektedir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

<BURADA KALDIK>
/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows sistemlerinde bir API fonksiyonu başarısız olmuşsa neden başarısız olduğu GetLastError isimli fonksiyonla tespit edilir. 
	Bu fonksiyonun prototipi şöyledir:

	DWORD GetLastError(void);

	Fonksiyon her farklı error gerekçesi için değişk bir değer vermektedir. Bu değerler aynı zamanda <windows.h> içerisinde
	ERROR_XXXX biçiminde sembolik sabitlerle define edilmiştir. Hatanın nedenini yazı biçiminde oluştuyrmak için FormatMessage isimli
	yardımcı bir API fonksiyonu da vardır. Ancak bu fonksiyonun kullanımı biraz karmaşıktır. Bunun yerine biz ExitSys isimli bir sarma (wrapper)
	fonksiyon yazacağız. Bu fonksiyon önce bizim verdiğimiz yazıyı, sonra ':' karakterini sonra da hata kodunu stderr dosyasına yazdırıp
	programı EXIT_FAILURE exit kodu ile sonlandırmaktadır. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	if (CreateSemaphore(NULL, -10, 1, "") == NULL)
		ExitSys("CreateSemaphore");

	printf("Ok\n");

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde bir POSIX fonksiyonu başarısız olduğunda errno değerinin yazısal karşılığı strerror fonksiyonuyla elde edilebilir.

	#include <string.h>

	char *strerror(int err);

	Fonksiyon static bir alanın adresiyle geri dönmektedir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

int main(void)
{
	int result;

	if ((result = open("test.dat", O_RDONLY)) == -1) {
		fprintf(stderr, "Open failed: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	printf("success...\n");

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde perror fonksiyonu (ki aynı zamanda perror bir standart C fonksiyonudur) önce programcının belirlediği mesajı, 
	sonra ':' karakterini sonra da errno değişkeninin değerinin yazısal karşılığını stderr dosyasına yazdırmaktadır.

	#include <stdio.h>

	void perror(const char *msg);

-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	int result;

	if ((result = open("test.dat", O_RDONLY)) == -1) {
		perror("open failed");
		exit(EXIT_FAILURE);
	}

	printf("success...\n");

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Genellikle UNIX/Linux sistemlerinde de bir POSIX fonksiyonu başarısız olduğunda programcı hata yazısını ekrana basıp programı sonlandırmaktadır.
	Bu işlem çok yapıldığından dolayı bir sarma fonksiyona (wrapper function) devredilebilir. Biz de kursumuzda exit_sys isimli bir sarma fonksiyon kullanacağız:

	void exit_sys(const char *msg)
	{
		perror(msg);

		exit(EXIT_FAILURE);
	}

-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void exit_sys(const char *msg);

int main(void)
{
	int result;

	if ((result = open("test.dat", O_RDONLY)) == -1)
		exit_sys("open");

	printf("success...\n");

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Handle sistemine bir örnek
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* Test.c */

#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

int main(void)
{
	HMATRIX hMatrix;

	if ((hMatrix = CreateMatrix(3, 3)) == NULL) {
		fprintf(stderr, "cannot create matrix!..\n");
		exit(EXIT_FAILURE);
	}

	SetElem(hMatrix, 0, 0, 1);
	SetElem(hMatrix, 0, 1, 2);
	SetElem(hMatrix, 0, 2, 3);

	SetElem(hMatrix, 1, 0, 4);
	SetElem(hMatrix, 1, 1, 5);
	SetElem(hMatrix, 1, 2, 6);

	SetElem(hMatrix, 2, 0, 7);
	SetElem(hMatrix, 2, 1, 7);
	SetElem(hMatrix, 2, 2, 9);

	DispMatrix(hMatrix);

	CloseMatrix(hMatrix);

	return 0;
}

/* Matrix.h */

#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

HMATRIX CreateMatrix(size_t rowSize, size_t colSize)
{
	HMATRIX hMatrix;

	if ((hMatrix = (HMATRIX)malloc(sizeof(MATRIX))) == NULL)
		return NULL;

	if ((hMatrix->pArray = (DATATYPE *)malloc(rowSize * colSize * sizeof(DATATYPE))) == NULL) {
		free(hMatrix);
		return NULL;
	}
	hMatrix->rowSize = rowSize;
	hMatrix->colSize = colSize;

	return hMatrix;
}

void CloseMatrix(HMATRIX hMatrix)
{
	free(hMatrix->pArray);
	free(hMatrix);
}

BOOL SetElem(HMATRIX hMatrix, size_t row, size_t col, int val)
{
	if (row >= hMatrix->rowSize || col >= hMatrix->colSize)
		return FALSE;

	hMatrix->pArray[row * hMatrix->colSize + col] = val;

	return TRUE;
}

int GetElem(HMATRIX hMatrix, size_t row, size_t col)
{
	return hMatrix->pArray[row * hMatrix->colSize + col];
}

void DispMatrix(HMATRIX hMatrix)
{
	size_t i, k;

	for (i = 0; i < hMatrix->rowSize; ++i) {
		for (k = 0; k < hMatrix->colSize; ++k)
			printf("%d ", GetElem(hMatrix, i, k));
		printf("\n");
	}
}

/* Test.c */

#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

int main(void)
{
	HMATRIX hMatrix;

	if ((hMatrix = CreateMatrix(3, 3)) == NULL) {
		fprintf(stderr, "cannot create matrix!..\n");
		exit(EXIT_FAILURE);
	}

	SetElem(hMatrix, 0, 0, 1);
	SetElem(hMatrix, 0, 1, 2);
	SetElem(hMatrix, 0, 2, 3);

	SetElem(hMatrix, 1, 0, 4);
	SetElem(hMatrix, 1, 1, 5);
	SetElem(hMatrix, 1, 2, 6);

	SetElem(hMatrix, 2, 0, 7);
	SetElem(hMatrix, 2, 1, 7);
	SetElem(hMatrix, 2, 2, 9);

	DispMatrix(hMatrix);

	CloseMatrix(hMatrix);

	return 0;
}

/* ------------------------------------------------------------------------------------------------------------------------------------------
	Yukarıdaki handle sistemind HMATRIX isimli handle türü void * olarak alınıp handle alanı programcıdan gizlenebilir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* Matrix.h */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <stddef.h>

/* Symbolic Constants */

#define TRUE		1
#define FALSE		0

/* Type declarations */

typedef int BOOL;
typedef int DATATYPE;

typedef struct tagMATRIX {
	DATATYPE *pArray;
	size_t rowSize;
	size_t colSize;
} MATRIX;

typedef void *HMATRIX;

/* Function Prototypes */

HMATRIX CreateMatrix(size_t rowSize, size_t colSize);
void CloseMatrix(HMATRIX hMatrix);
BOOL SetElem(HMATRIX hMatrix, size_t row, size_t col, int val);
int GetElem(HMATRIX hMatrix, size_t row, size_t col);
void DispMatrix(HMATRIX hMatrix);

#endif

/* Matrix.h */

#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

HMATRIX CreateMatrix(size_t rowSize, size_t colSize)
{
	MATRIX *pMatrix;

	if ((pMatrix = (MATRIX *)malloc(sizeof(MATRIX))) == NULL)
		return NULL;

	if ((pMatrix->pArray = (DATATYPE *)malloc(rowSize * colSize * sizeof(DATATYPE))) == NULL) {
		free(pMatrix);
		return NULL;
	}
	pMatrix->rowSize = rowSize;
	pMatrix->colSize = colSize;

	return pMatrix;
}

void CloseMatrix(HMATRIX hMatrix)
{
	MATRIX *pMatrix = (MATRIX *)hMatrix;

	free(pMatrix->pArray);
	free(pMatrix);
}

BOOL SetElem(HMATRIX hMatrix, size_t row, size_t col, int val)
{
	MATRIX *pMatrix = (MATRIX *)hMatrix;

	if (row >= pMatrix->rowSize || col >= pMatrix->colSize)
		return FALSE;

	pMatrix->pArray[row * pMatrix->colSize + col] = val;

	return TRUE;
}

int GetElem(HMATRIX hMatrix, size_t row, size_t col)
{
	MATRIX *pMatrix = (MATRIX *)hMatrix;

	return pMatrix->pArray[row * pMatrix->colSize + col];
}

void DispMatrix(HMATRIX hMatrix)
{
	size_t i, k;
	MATRIX *pMatrix = (MATRIX *)hMatrix;

	for (i = 0; i < pMatrix->rowSize; ++i) {
		for (k = 0; k < pMatrix->colSize; ++k)
			printf("%d ", GetElem(hMatrix, i, k));
		printf("\n");
	}
}

/* Test.c */

#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

int main(void)
{
	HMATRIX hMatrix;

	if ((hMatrix = CreateMatrix(3, 3)) == NULL) {
		fprintf(stderr, "cannot create matrix!..\n");
		exit(EXIT_FAILURE);
	}

	SetElem(hMatrix, 0, 0, 1);
	SetElem(hMatrix, 0, 1, 2);
	SetElem(hMatrix, 0, 2, 3);

	SetElem(hMatrix, 1, 0, 4);
	SetElem(hMatrix, 1, 1, 5);
	SetElem(hMatrix, 1, 2, 6);

	SetElem(hMatrix, 2, 0, 7);
	SetElem(hMatrix, 2, 1, 7);
	SetElem(hMatrix, 2, 2, 9);

	DispMatrix(hMatrix);

	CloseMatrix(hMatrix);

	return 0;
}

/* ------------------------------------------------------------------------------------------------------------------------------------------
	Ödev çözümü (HomeWork-03-1)
-------------------------------------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <getopt.h>

int main(int argc, char *argv[])
{
	int result;
	int c_flag, l_flag, L_flag, w_flag, help_flag, version_flag;
	int err_flag;
	int i;
	int lc, wc, cc, lcc, max_lcc, max_cc;
	int ch, flag;
	FILE *f;
	const char *delim = " \t\n.,!*-";

	struct option options[] = {
		{"bytes", no_argument, NULL, 'c'},
		{"lines", no_argument, NULL, 'l'},
		{"max_line_length", no_argument, NULL, 'L'},
		{"words", no_argument, NULL, 'w'},
		{"help", no_argument, NULL, 1},
		{"version", no_argument, NULL, 2},
		{0, 0, 0, 0 },
	};

	opterr = 0;

	c_flag = l_flag = L_flag = w_flag = help_flag = 0;
	version_flag = err_flag = 0;

	while ((result = getopt_long(argc, argv, "clLw", options, NULL)) != -1) {
		switch (result) {
		case 'c':
			c_flag = 1;
			break;
		case 'l':
			l_flag = 1;
			break;
		case 'L':
			L_flag = 1;
			break;
		case 'w':
			w_flag = 1;
			break;
		case 1:			            /* --help */
			help_flag = 1;
			break;
		case 2:                     /* --version */
			version_flag = 1;
			break;
		case '?':
			fprintf(stderr, "invalid option!..\n");
			err_flag = 1;

			break;
		}
	}

	if (err_flag)
		exit(EXIT_FAILURE);

	if (version_flag && (c_flag || l_flag || L_flag || w_flag)) {
		fprintf(stderr, "--version must not be used with other options!..\n");
		exit(EXIT_FAILURE);
	}

	if (help_flag && (c_flag || l_flag || L_flag || w_flag)) {
		fprintf(stderr, "--help must not be used with other options!..\n");
		exit(EXIT_FAILURE);
	}

	if (help_flag) {
		printf("usage: wc [-cwlL][--line, --help, --version] [path list]\n");
		exit(EXIT_SUCCESS);
	}

	if (version_flag) {
		printf("version 1.0\n");
		exit(EXIT_SUCCESS);
	}

	if (optind == argc) {
		fprintf(stderr, "at least one file must be specified!..\n");
		exit(EXIT_FAILURE);
	}

	max_cc = 0;
	for (i = optind; i < argc; ++i) {
		if ((f = fopen(argv[i], "r")) == NULL)
			continue;
		fseek(f, 0, SEEK_END);
		cc = ftell(f);
		if (cc > max_cc)
			max_cc = cc;
		fclose(f);
	}

	max_cc = (int)log10(max_cc) + 1;
	if (max_cc < 3)
		max_cc = 3;

	for (i = optind; i < argc; ++i) {
		if ((f = fopen(argv[i], "r")) == NULL) {
			fprintf(stderr, "file not found or cannot open: %s\n", argv[i]);
			continue;
		}

		cc = wc = lc = max_lcc = 0;
		flag = 1;
		lcc = 0;
		while ((ch = fgetc(f)) != EOF) {
			++cc;
			if (ch == '\n') {
				++lc;
				if (lcc > max_lcc)
					max_lcc = lcc;
				lcc = 0;
			}
			else
				++lcc;
			if (strchr(delim, ch))
				flag = 1;
			else if (flag) {
				flag = 0;
				++wc;
			}
		}

		if (l_flag + w_flag + c_flag + L_flag == 0)
			printf("%*d %*d %*d ", max_cc, cc, max_cc, wc, max_cc, cc);
		else {
			if (l_flag)
				printf("%*d ", max_cc, lc);
			if (w_flag)
				printf("%*d ", max_cc, wc);
			if (c_flag)
				printf("%*d ", max_cc, cc);
			if (L_flag)
				printf("%*d ", max_cc, max_lcc);
		}
		printf("%s\n", argv[i]);
	}

	return 0;
}

/*-------------------------------------------------------------------------------------------------------------------------------------------
	Windows sistemlerinde aşağı seviyeli olarak bir dosyayı açmak (ya da yaratmak) için CreateFile API fonksiyonu, 
	kapatmak için CloseHandle isimli API fonksiyonu kullanılmaktadır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	HANDLE hFile;

	if ((hFile = CreateFile("Mest.txt", GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL)) == INVALID_HANDLE_VALUE)
		ExitSys("CreateFile");

	printf("Ok\n");

	CloseHandle(hFile);

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*-----------------------------------------------------------------------------------------------------------------------------------------
	ReadFile Fonksiyonu ile bir text dosyanın okunarak ekrana yazdırılması
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define BUF_SIZE		4096

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	HANDLE hFile;
	char buf[BUF_SIZE + 1];
	DWORD dwRead;
	BOOL bResult;

	if ((hFile = CreateFile("Test.txt", GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL)) == INVALID_HANDLE_VALUE)
		ExitSys("CreateFile");

	while ((bResult = ReadFile(hFile, buf, BUF_SIZE, &dwRead, NULL)) && dwRead > 0) {
		buf[dwRead] = '\0';
		printf("%s", buf);
	}

	if (!bResult)
		ExitSys("ReadFile");

	CloseHandle(hFile);

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*-------------------------------------------------------------------------------------------------------------------------------------------
	Windows'ta ReadFile ve WriteFile fonksiyonlarının kullanımına bir örnek: Dosya Kopyalama.
	Aslında dosya kopyalamak için daha hızlı çalışabilen CopyFile isimli bir API fonksiyonu da bulunmaktadır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define BUF_SIZE		4096

void ExitSys(LPCSTR lpszMsg);

int main(int argc, char *argv[])
{
	HANDLE hFileSource, hFileDest;
	char buf[BUF_SIZE];
	DWORD dwRead, dwWritten;
	BOOL bResult;

	if (argc != 3) {
		fprintf(stderr, "Wrong number of arguments!..\n");
		exit(EXIT_FAILURE);
	}

	if ((hFileSource = CreateFile(argv[1], GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL)) == INVALID_HANDLE_VALUE)
		ExitSys("CreateFile");

	if ((hFileDest = CreateFile(argv[2], GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL)) == INVALID_HANDLE_VALUE)
		ExitSys("CreateFile");

	while ((bResult = ReadFile(hFileSource, buf, BUF_SIZE, &dwRead, NULL)) && dwRead > 0) {
		if (!WriteFile(hFileDest, buf, dwRead, &dwWritten, NULL))
			ExitSys("WriteFile");
		if (dwWritten != dwRead) {
			fprintf(stderr, "Cannot file write, maybe disk full!..\n");
			exit(EXIT_FAILURE);
		}
	}
	if (!bResult)
		ExitSys("WriteFile");

	CloseHandle(hFileSource);
	CloseHandle(hFileDest);

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*-------------------------------------------------------------------------------------------------------------------------------------------
	open POSIX fonksiyonu ile dosya açmaya bir örnek
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

void exit_sys(const char *msg);

int main()
{
	int fd;

	if ((fd = open("test.dat", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
		exit_sys("open");

	printf("Ok\n");

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*-------------------------------------------------------------------------------------------------------------------------------------------
	read POSIX fonksiyonu ile dosyadan okuma yapılmasına örnek
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

void exit_sys(const char *msg);

int main()
{
	int fd;
	unsigned char buf[1024];
	ssize_t result;
	ssize_t i;

	if ((fd = open("test.txt", O_RDONLY)) == -1)
		exit_sys("open");

	if ((result = read(fd, buf, 1024)) == -1)
		exit_sys("read");

	for (i = 0; i < result; ++i)
		printf("%02X%c", buf[i], i % 16 == 15 ? '\n' : ' ');
	printf("\n");

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*-------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde dosya kopyalamaya bir örnek. 

	./mycp [-i -n][--interactive --no-clobber] <source path> <destination path>

	Bir dosyanın olup olmadığını anlamak için ve ilgili prosesin dosyaya okuma/yazma/çalıştırma işlemini yapıp yapaayacağını
	anlayabilmek için access isimli bir POSIX fonksiyonu kullanılmaktadır. Bu fonksiyon open ile dosyayı açmaktan daha etkin bu işlemi
	yapabilmektedir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* mycp.c */
*
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <getopt.h>

#define BUF_SIZE    8192

void exit_sys(const char *msg);

int main(int argc, char *argv[])
{
	int result;
	int i_flag, n_flag;
	int err_flag;
	char buf[BUF_SIZE];
	int fds, fdd;
	ssize_t n;

	struct option options[] = {
		{"interactive", no_argument, NULL, 'i'},
		{"no-clobber", required_argument, NULL, 'n'},
		{0, 0, 0, 0 },
	};

	opterr = 0;

	i_flag = n_flag = 0;
	err_flag = 0;

	while ((result = getopt_long(argc, argv, "in", options, NULL)) != -1) {
		switch (result) {
		case 'i':
			i_flag = 1;
			break;
		case 'n':
			n_flag = 1;
			break;
		case '?':
			if (optopt != 0)
				fprintf(stderr, "invalid option: -%c\n", optopt);
			else
				fprintf(stderr, "invalid long option!..\n");

			err_flag = 1;

			break;
		}
	}

	if (err_flag)
		exit(EXIT_FAILURE);

	if (argc - optind != 2) {
		fprintf(stderr, "wrong number of arguments!..\n");
		exit(EXIT_FAILURE);
	}

	if (n_flag || i_flag) {
		if (access(argv[optind + 1], F_OK) == 0) {
			if (n_flag) {
				fprintf(stderr, "file already exits! (-n specified)\n");
				exit(EXIT_FAILURE);
			}
			if (i_flag) {
				printf("file already exists! Overwrite? (Y/N):");
				if (tolower(getchar()) != 'y')
					exit(EXIT_FAILURE);
			}
		}
	}

	if ((fds = open(argv[optind], O_RDONLY)) == -1)
		exit_sys("open");

	if ((fdd = open(argv[optind + 1], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
		exit_sys("open");

	while ((n = read(fds, buf, BUF_SIZE)) > 0)
		if (write(fdd, buf, n) == -1)
			exit_sys("write");

	if (n == -1)
		exit_sys("read");

	close(fds);
	close(fdd);

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*-------------------------------------------------------------------------------------------------------------------------------------------
	GUI Programlar özel bir biçimde organize edilmektedir. Bu konu özet olarak kusumuzda ele alınacaktır. Ancak siyah ekranda (konsol ekranında)
	renki yazı yazdırmak, imleci taşımak gibi işlemler için "ANSI Escape kodlarından faydalanılabilmektedir. UNIX/Linux sistemlerinde ayrıca Curses isimli 
	bir kütüphane bu konuda yetenekli işlemler yapmakta kullanılmaktadır. Windows sistemlerinde curses kütüphanesinin yaptıklarının benzerini yapan
	"Console API" fonksiyonları bulunmaktadır. 

	Aşağıda imleci 10, 10 hücresine taşıyıp oraya kırmızı renkte bir hello yazısı basan örnek görülmektedir
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main(void)
{
	printf("\x1B[10;10H");
	printf("\033[31;1;4mHello\033[0m");
	getchar();

	return 0;
}

/*-------------------------------------------------------------------------------------------------------------------------------------------
	Windows sistemlerinde siyah ekrana renkli yazılar yazdırabilmek için ve imleçle ilgili işlemler yapabilmek için console API'leri kulanılmaktadır.
	Aşağıda bu API'lere bir örnek verilmiştir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	HANDLE hConsole;
	char text[] = "This is a test";
	COORD coord;
	DWORD dwWritten;
	WORD attrs[] = { FOREGROUND_BLUE, FOREGROUND_RED, FOREGROUND_GREEN };

	if ((hConsole = GetStdHandle(STD_OUTPUT_HANDLE)) == INVALID_HANDLE_VALUE)
		ExitSys("GetStdHandle");

	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);

	coord.X = 10;
	coord.Y = 10;
	SetConsoleCursorPosition(hConsole, coord);

	WriteConsole(hConsole, text, strlen(text), &dwWritten, NULL);

	coord.X = 10;
	coord.Y = 11;
	SetConsoleCursorPosition(hConsole, coord);

	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
	WriteConsole(hConsole, text, strlen(text), &dwWritten, NULL);

	coord.X = 10;
	coord.Y = 12;

	SetConsoleCursorPosition(hConsole, coord);
	WriteConsole(hConsole, "ali", 3, &dwWritten, NULL);
	WriteConsoleOutputAttribute(hConsole, attrs, 3, coord, &dwWritten);

	coord.X = 10;
	coord.Y = 13;


	getchar();

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*-------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde open fonksiyonun üçüncü parameresinde verilen erişim hakları nihai durumu belirtmemektedir. Nihai durum üçüncüğ
	parametrede belirtilen erişim haklarının prosesin umask değeri ile işleme sokulmasıyla belirlenir. umask değerindeki set edilen bayraklar 
	open fonksiyınunda belirtilse bile dikkate alınmayacak hakları belirtir. open dışında bazı diğer yaratıcı POSIX fonksiyonları da umask değerini
	dikkate almaktadır. umask değeri üst prosesten alt prosese aktarılmaktadır. Shell prosesinin default umask değeri 022'dir. (Yani S_IWUSR|S_IWGRP)
	Proses kendi umask değerini umask isimli POSIX fonksiyonuyla değiştirebilemketdri 

		#incude <sys/stat.h>
		
		mode_t umask(mode_t mask);

	Aşağıdaki programda prosesin umask değeri 0 yapılarak maske ortadan kaldırılmıştır. 

	Shell prosesinin umask değeri umask shell komutuyla alınıp değiştirilebilmektedir.

-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

void exit_sys(const char *msg);

int main()
{
	int fd;

	/* umask(S_IWUSR|S_IWOTH);		default umask */

	umask(0);

	if ((fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) == -1)
		exit_sys("open");

	close(fd);

	printf("OK\n");

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*-------------------------------------------------------------------------------------------------------------------------------------------
	Windows'ta dosya silmek için DeleteFile isimli API fonksiyonu bulunmaktadır. remove standart C fonksiyonu aslında bu fonksiyonu çağırmaktadır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	if (!DeleteFile("test.txt"))
		ExitSys("DeleteFile");

	printf("Ok\n");

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/* ------------------------------------------------------------------------------------------------------------------------------------------
	Dosya taşımak demek o dosyanın diskteki verileri üzerinde değişiklik yapmadan yalnızca dizin girişlerini taşamak demektir. Yani dosya 
	taşıma işlemi sırasında gerçek anlamda bir kopyalama yapılmamaktadır. Windows'ta dosya taşıak için MoveFile API fonksiyonu kullanılır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	if (!MoveFile("Mample.c", "Tample.c", FALSE))
		ExitSys("CopyFile");

	printf("Ok\n");

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*-------------------------------------------------------------------------------------------------------------------------------------------
	Windows sistemlerinde GetFileSize API fonksiyonu açılmış bir dosyanın uzunluğunu bize verir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	HANDLE hFile;
	DWORD dwSize;

	if ((hFile = CreateFile("Tample.c", GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL)) == INVALID_HANDLE_VALUE)
		ExitSys("CreateFile");

	if ((dwSize = GetFileSize(hFile, NULL)) == INVALID_FILE_SIZE)
		if (GetLastError() != NO_ERROR)
			ExitSys("GetFileSize");

	printf("%lu\n", (unsigned long)dwSize);

	CloseHandle(hFile);

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*-------------------------------------------------------------------------------------------------------------------------------------------
	Ödev Çözümü (HomwWork-05-1)
-------------------------------------------------------------------------------------------------------------------------------------------*/
/* ga.h */

#ifndef GA_H_
#define GA_H_

#include <Windows.h>

/* Function Prototypes */

BOOL InitGA(void);
void Pos(int row, int col);
void WriteChar(int row, int col, int ch);
void WriteCharAttr(int row, int col, int ch, int attr);
void WriteStr(int row, int col, LPCSTR szStr);
void WriteStrAttribute(int row, int col, LPCSTR szStr, int attr);
void FillChar(int row, int col, int ch, int n);
void FillCharAttr(int row, int col, int ch, int n, int attr);
void VFillChar(int row, int col, int ch, int n);
void VFillCharAttr(int row, int col, int ch, int n, int attr);
void DrawFrame(int row1, int col1, int row2, int col2);

#endif

/* ga.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define BOX_UL	0x250C
#define BOX_UR	0x2510
#define BOX_LL	0x2514
#define BOX_LR	0x2518
#define BOX_H	0x2500
#define BOX_V	0x2502

static HANDLE hStdOut;

BOOL InitGA(void)
{
	if ((hStdOut = GetStdHandle(STD_OUTPUT_HANDLE)) == INVALID_HANDLE_VALUE)
		return FALSE;

	return TRUE;
}

void Pos(int row, int col)
{
	COORD coord;

	coord.X = col;
	coord.Y = row;

	SetConsoleCursorPosition(hStdOut, coord);
}

void WriteChar(int row, int col, int ch)
{
	COORD coord;
	DWORD dwWritten;
	char och = ch;

	coord.X = col;
	coord.Y = row;

	WriteConsoleOutputCharacter(hStdOut, &och, 1, coord, &dwWritten);
}

void WriteCharAttr(int row, int col, int ch, int attr)
{
	COORD coord;
	DWORD dwWritten;
	char och = ch;
	WORD wAttr = attr;

	coord.X = col;
	coord.Y = row;

	WriteConsoleOutputAttribute(hStdOut, &wAttr, 1, coord, &dwWritten);
	WriteConsoleOutputCharacter(hStdOut, &och, 1, coord, &dwWritten);
}

void WriteStr(int row, int col, LPCSTR szStr)
{
	COORD coord;
	DWORD dwWritten;

	coord.X = col;
	coord.Y = row;

	WriteConsoleOutputCharacter(hStdOut, szStr, strlen(szStr), coord, &dwWritten);
}

void WriteStrAttribute(int row, int col, LPCSTR szStr, int attr)
{
	COORD coord;
	DWORD dwWritten;
	WORD wAttr = attr;
	int i;

	coord.X = col;
	coord.Y = row;

	for (i = 0; szStr[i] != '\0'; ++i) {
		WriteConsoleOutputAttribute(hStdOut, &wAttr, 1, coord, &dwWritten);
		++coord.X;
	}

	coord.X = col;

	WriteConsoleOutputCharacter(hStdOut, szStr, i, coord, &dwWritten);
}

void FillChar(int row, int col, int ch, int n)
{
	int i;

	for (i = 0; i < n; ++i) {
		WriteChar(row, col, ch);
		++col;
	}
}

void FillCharAttr(int row, int col, int ch, int n, int attr)
{
	int i;

	for (i = 0; i < n; ++i) {
		WriteCharAttr(row, col, ch, attr);
		++col;
	}
}

void VFillChar(int row, int col, int ch, int n)
{
	int i;

	for (i = 0; i < n; ++i) {
		WriteChar(row, col, ch);
		++row;
	}
}

void VFillCharAttr(int row, int col, int ch, int n, int attr)
{
	int i;

	for (i = 0; i < n; ++i) {
		WriteCharAttr(row, col, ch, attr);
		++row;
	}
}

void DrawFrame(int row1, int col1, int row2, int col2)
{
	COORD coord;
	DWORD dwWritten;
	wchar_t ch;
	int i;

	coord.X = col1;
	coord.Y = row1;
	ch = BOX_UL;

	WriteConsoleOutputCharacterW(hStdOut, &ch, 1, coord, &dwWritten);

	coord.X = col2;
	coord.Y = row1;
	ch = BOX_UR;

	WriteConsoleOutputCharacterW(hStdOut, &ch, 1, coord, &dwWritten);

	coord.X = col1;
	coord.Y = row2;
	ch = BOX_LL;

	WriteConsoleOutputCharacterW(hStdOut, &ch, 1, coord, &dwWritten);

	coord.X = col2;
	coord.Y = row2;
	ch = BOX_LR;

	WriteConsoleOutputCharacterW(hStdOut, &ch, 1, coord, &dwWritten);

	ch = BOX_H;
	for (i = 0; i < col2 - col1 - 1; ++i) {
		coord.X = col1 + 1 + i;
		coord.Y = row1;
		WriteConsoleOutputCharacterW(hStdOut, &ch, 1, coord, &dwWritten);
		coord.Y = row2;
		WriteConsoleOutputCharacterW(hStdOut, &ch, 1, coord, &dwWritten);
	}

	ch = BOX_V;
	for (i = 0; i < row2 - row1 - 1; ++i) {
		coord.X = col1;
		coord.Y = row1 + 1 + i;
		WriteConsoleOutputCharacterW(hStdOut, &ch, 1, coord, &dwWritten);
		coord.X = col2;
		WriteConsoleOutputCharacterW(hStdOut, &ch, 1, coord, &dwWritten);
	}
}

/* test.c */

#include <stdio.h>
#include <stdlib.h>
#include "ga.h"

int main(void)
{
	InitGA();

	DrawFrame(10, 10, 20, 20);
	DrawFrame(22, 10, 25, 15);

	return 0;
}

/*-------------------------------------------------------------------------------------------------------------------------------------------
	Windows'ta bir dizin yaratmak için CreateDirectory isimli API fonksiyonu kullanılır. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	if (!CreateDirectory("TestDir", NULL))
		ExitSys("CreateDirectory");

	printf("Ok\n");

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*-------------------------------------------------------------------------------------------------------------------------------------------
	Windows'ta bir dizin silmek için RemoveDirectory isimli API fonksiyonu kullanılır. Ancak bu fonksiyon dizin'in içi boşsa silmeyi yapabilmektedir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	if (!RemoveDirectory("TestDir", NULL))
		ExitSys("CreateDirectory");

	printf("Ok\n");

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*-------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde dosya silmek için remove standart C fonksiyonu kullanılabilir. Ancak asıl dosya silen fonksiyon unlink isimli
	POSIX fonksiyonudur. unlink her zaman dizin girişini siler anck dosyanın katı bağ (hard link) sayacını 1 eksilttikten sonra sayaç 
	0'a düşerse dosyanın gerçek bilgilerini de silmektedir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void exit_sys(const char *msg);

int main()
{
	if (unlink("test.txt") == -1)
		exit_sys("unlink");

	printf("sucess...\n");

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*-------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde yaratılmış olan bir dosyanın erişim hakları chmod isimli POSIX fonksiyonuyla değiştirilebilir. Ancak bunun için
	chmod fonksiyonunu çağıran prosesin etkin kullanıcı id'sinin (effective user id) dosyanın kullanıcı id'si ile aynı olması (yani prosesin dosyanın 
	sahibi olması) ya da prosesin etkin kullanıcı id'sinin 0 olması (root olması) gerekmektedir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void exit_sys(const char *msg);

int main(void)
{
	if (chmod("test.txt", S_IRUSR | S_IWUSR) == -1)
		exit_sys("chmod");

	printf("success...\n");

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*-------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde zaten açılmış bir dosyanın erişim haklarını değiştirmek için fchmod fonksiyonu kullanılmaktadır. Dosyanın hangi modda
	açıldığının bir önemi yoktur.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

void exit_sys(const char *msg);

int main(void)
{
	int fd;

	if ((fd = open("test.txt", O_RDONLY)) == -1)
		exit_sys("open");

	if (fchmod(fd, S_IRUSR | S_IWUSR) == -1)
		exit_sys("fchmod");

	close(fd);

	printf("success...\n");

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*-------------------------------------------------------------------------------------------------------------------------------------------
	chmod komutunun octal erişim haklarıyla yazımına ilişkin bir örnek
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	unsigned int omode;
	mode_t modes[] = { S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH };
	mode_t mode;
	int i;

	if (argc < 3) {
		fprintf(stderr, "wrong number of arguments!..\n");
		exit(EXIT_FAILURE);
	}

	if (strlen(argv[1]) > 3) {
		fprintf(stderr, "mode must have maximum 3 octal digits!..\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; argv[1][i] != '\0'; ++i)
		if (argv[1][i] < '0' || argv[1][i] > '7') {
			fprintf(stderr, "invalid octal digit!..\n");
			exit(EXIT_FAILURE);
		}

	sscanf(argv[1], "%o", &omode);
	mode = 0;

	for (i = 0; i < 9; ++i)
		mode |= (omode >> (8 - i) & 1) ? modes[i] : 0;

	for (i = 2; i < argc; ++i)
		if (chmod(argv[i], mode) == -1)
			fprintf(stderr, "%s: %s\n", argv[i], strerror(errno));

	return 0;
}

/*-------------------------------------------------------------------------------------------------------------------------------------------
	mkdir POSIX fonksiyonu dizini yaratmak için rmdir POSIX fonksiyonu ise dizini silmek için kullanılmaktadır. 
	Bu örnekte dizin yaratan bir program verilmiştir. Program -m ya da --mode ile yaratılacak dizinin de erişim haklarını almaktadır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <getopt.h>

void exit_sys(const char *msg);

int main(int argc, char *argv[])
{
	mode_t modes[] = { S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH };
	unsigned int omode;
	mode_t mode;
	int m_flag, err_flag;
	char *m_arg;
	int result, i;

	struct option options[] = {
		{"mode", required_argument, NULL, 'm'},
		{0, 0, 0, 0 },
	};

	opterr = 0;

	m_flag = 0;
	err_flag = 0;

	while ((result = getopt_long(argc, argv, "m:", options, NULL)) != -1) {
		switch (result) {
		case 'm':
			m_flag = 1;
			m_arg = optarg;
			break;
		case '?':
			if (optopt == 'm')
				fprintf(stderr, "-m option must have an argument!..\n");
			else if (optopt != 0)
				fprintf(stderr, "invalid option: -%c\n", optopt);
			else
				fprintf(stderr, "invalid long option!..\n");

			err_flag = 1;
		}
	}

	if (err_flag)
		exit(EXIT_FAILURE);

	if (m_flag) {
		if (strlen(m_arg) > 3) {
			fprintf(stderr, "mode must have maximum 3 octal digits!..\n");
			exit(EXIT_FAILURE);
		}

		for (i = 0; m_arg[i] != '\0'; ++i)
			if (m_arg[i] < '0' || m_arg[i] > '7') {
				fprintf(stderr, "invalid octal digit!..\n");
				exit(EXIT_FAILURE);
			}

		sscanf(m_arg, "%o", &omode);

		mode = 0;
		for (i = 0; i < 9; ++i)
			mode |= (omode >> (8 - i) & 1) ? modes[i] : 0;
	}
	else
		mode = S_IRWXU | S_IRWXG | S_IRWXO;

	umask(0);
	for (i = optind; i < argc; ++i)
		if (mkdir(argv[i], mode) == -1)
			fprintf(stderr, "%s: %s\n", argv[i], strerror(errno));

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*-------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlrinde stat fonksiyonun kullanılması
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <sys/stat.h>

const char *getls_mode(mode_t mode);

int main(int argc, char *argv[])
{
	struct stat finfo;
	int i;

	if (argc == 1) {
		fprintf(stderr, "wrong number of arguments!..\n");
		exit(EXIT_FAILURE);
	}

	for (i = 1; i < argc; ++i) {
		if (stat(argv[i], &finfo) == -1) {
			fprintf(stderr, "stat: %s\n", strerror(errno));
			continue;
		}

		printf("----------------------------\n");
		printf("%s\n\n", argv[i]);
		printf("Mode: %s\n", getls_mode(finfo.st_mode));
		printf("%-20s%lld\n", "Size", (long long)finfo.st_size);
		printf("%-20s%llu\n", "I-Node", (unsigned long long)finfo.st_ino);
		printf("%-20s%lld\n", "User id", (long long)finfo.st_uid);
		printf("%-20s%lld\n", "Group id", (long long)finfo.st_gid);
		printf("%-20s%s", "Last Update", ctime(&finfo.st_mtime));
		printf("%-20s%s", "Last Read", ctime(&finfo.st_atime));
		printf("%-20s%s", "Last I-Node Update", ctime(&finfo.st_ctime));
	}

	return 0;
}

const char *getls_mode(mode_t mode)
{
	static char tmode[11];
	mode_t modef[] = { S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH };
	char *modec = "rwx";
	int i;

	if (S_ISREG(mode))
		tmode[0] = '-';
	else if (S_ISDIR(mode))
		tmode[0] = 'd';
	else if (S_ISCHR(mode))
		tmode[0] = 'c';
	else if (S_ISBLK(mode))
		tmode[0] = 'b';
	else if (S_ISFIFO(mode))
		tmode[0] = 'p';
	else if (S_ISLNK(mode))
		tmode[0] = 'l';
	else if (S_ISSOCK(mode))
		tmode[0] = 's';

	for (i = 0; i < 9; ++i)
		tmode[i + 1] = mode & modef[i] ? modec[i % 3] : '-';
	tmode[i + 1] = '\0';        /* may be omitted */

	return tmode;
}

/*-------------------------------------------------------------------------------------------------------------------------------------------
	Kullanıcının isminden hareketle kullanıcı bilgilerini almak için getpwnam, kullanıcı id'sinden hareketle kullanıcı bilgilerini almak için
	getpwuid POSIX fonksiyonları kullanılmaktadır. Bnezer biçimde grup isminden hareketle grup bilgileri almak için getgrnam, grup id'sinden hareketle
	grup bilgilerini almak için ise getgrgid fonksiyonu kullanılmaktadır. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>

const char *getls_mode(mode_t mode);

int main(int argc, char *argv[])
{
	struct stat finfo;
	int i;
	struct passwd *pwd;
	struct group *grp;

	if (argc == 1) {
		fprintf(stderr, "wrong number of arguments!..\n");
		exit(EXIT_FAILURE);
	}

	for (i = 1; i < argc; ++i) {
		if (stat(argv[i], &finfo) == -1) {
			fprintf(stderr, "stat: %s\n", strerror(errno));
			continue;
		}

		pwd = getpwuid(finfo.st_uid);
		grp = getgrgid(finfo.st_gid);

		printf("----------------------------\n");
		printf("%s\n\n", argv[i]);
		printf("Mode: %s\n", getls_mode(finfo.st_mode));
		printf("%-20s%lld\n", "Size", (long long)finfo.st_size);
		printf("%-20s%llu\n", "I-Node", (unsigned long long)finfo.st_ino);
		printf("%-20s%s(%lld)\n", "User id", pwd ? pwd->pw_name : "?????", (long long)finfo.st_uid);
		printf("%-20s%s(%lld)\n", "Group id", grp ? grp->gr_name : "?????", (long long)finfo.st_gid);
		printf("%-20s%s", "Last Update", ctime(&finfo.st_mtime));
		printf("%-20s%s", "Last Read", ctime(&finfo.st_atime));
		printf("%-20s%s", "Last I-Node Update", ctime(&finfo.st_ctime));
	}

	return 0;
}

const char *getls_mode(mode_t mode)
{
	static char tmode[11];
	mode_t modef[] = { S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH };
	char *modec = "rwx";
	int i;

	if (S_ISREG(mode))
		tmode[0] = '-';
	else if (S_ISDIR(mode))
		tmode[0] = 'd';
	else if (S_ISCHR(mode))
		tmode[0] = 'c';
	else if (S_ISBLK(mode))
		tmode[0] = 'b';
	else if (S_ISFIFO(mode))
		tmode[0] = 'p';
	else if (S_ISLNK(mode))
		tmode[0] = 'l';
	else if (S_ISSOCK(mode))
		tmode[0] = 's';

	for (i = 0; i < 9; ++i)
		tmode[i + 1] = mode & modef[i] ? modec[i % 3] : '-';
	tmode[i + 1] = '\0';        /* may be omitted */

	return tmode;
}

/*-------------------------------------------------------------------------------------------------------------------------------------------
	Aşağıdaki programda sistemdeki tüm kullanıcıların ve grupların isimleri yazdırılmıştır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>

int main(void)
{
	struct passwd *pwd;
	struct group *grp;

	while ((pwd = getpwent()) != NULL)
		printf("%s\n", pwd->pw_name);

	endpwent();

	printf("------------\n");

	while ((grp = getgrent()) != NULL)
		printf("%s\n", grp->gr_name);

	endgrent();

	return 0;
}

/*-------------------------------------------------------------------------------------------------------------------------------------------
	Belli dosyaların ls -l formatıyla yazdırılması örneği
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

void exit_sys(const char *msg);
const char *get_ls(const char *path);

int main(int argc, char *argv[])
{
	struct stat finfo;
	int i;

	if (argc == 1) {
		fprintf(stderr, "too few parameters!..\n");
		exit(EXIT_FAILURE);
	}

	for (i = 1; i < argc; ++i) {
		if (stat(argv[i], &finfo) == -1) {
			fprintf(stderr, "%s: %s\n", strerror(errno), argv[i]);
			continue;
		}
		printf("%s\n", get_ls(argv[i]));
	}

	return 0;
}

const char *get_ls(const char *path)
{
	struct stat finfo;
	static char buf[4096];
	static mode_t modes[] = { S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH };
	struct passwd *pass;
	struct group *gr;
	int index = 0;
	int i;

	if (stat(path, &finfo) == -1)
		return NULL;

	if (S_ISREG(finfo.st_mode))
		buf[index] = '-';
	else if (S_ISDIR(finfo.st_mode))
		buf[index] = 'd';
	else if (S_ISCHR(finfo.st_mode))
		buf[index] = 'c';
	else if (S_ISBLK(finfo.st_mode))
		buf[index] = 'b';
	else if (S_ISFIFO(finfo.st_mode))
		buf[index] = 'p';
	else if (S_ISLNK(finfo.st_mode))
		buf[index] = 'l';
	else if (S_ISSOCK(finfo.st_mode))
		buf[index] = 's';
	++index;

	for (i = 0; i < 9; ++i)
		buf[index++] = (finfo.st_mode & modes[i]) ? "rwx"[i % 3] : '-';
	buf[index] = '\0';

	index += sprintf(buf + index, " %llu", (unsigned long long)finfo.st_nlink);

	if ((pass = getpwuid(finfo.st_uid)) == NULL)
		return NULL;
	index += sprintf(buf + index, " %s", pass->pw_name);

	if ((gr = getgrgid(finfo.st_gid)) == NULL)
		return NULL;
	index += sprintf(buf + index, " %s", gr->gr_name);

	index += sprintf(buf + index, " %lld", (long long)finfo.st_size);
	index += strftime(buf + index, 100, " %b %e %H:%M", localtime(&finfo.st_mtime));

	sprintf(buf + index, " %s", path);

	return buf;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}


/*-------------------------------------------------------------------------------------------------------------------------------------------
	Ödev çözümü (HomeWork-07-1)
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* passgrp.h */

#ifndef PASSGRP_H_
#define PASSGRP_H_

struct passwd {
	char   *pw_name;       /* username */
	char   *pw_passwd;     /* user password */
	uid_t   pw_uid;        /* user ID */
	gid_t   pw_gid;        /* group ID */
	char   *pw_gecos;      /* user information */
	char   *pw_dir;        /* home directory */
	char   *pw_shell;      /* shell program */
};

struct passwd *csd_getpwnam(const char *name);
struct passwd *csd_getpwuid(uid_t uid);
void csd_endpwent(void);
struct passwd *csd_getpwent(void);
void csd_setpwent(void);

#endif

/* passgrp.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "passgrp.h"

#define MAX_LINE_CHAR       4096

static int is_all_ws(const char *str);

static FILE *g_f;

struct passwd *csd_getpwent(void)
{
	static struct passwd pass;
	static char buf[MAX_LINE_CHAR];
	char *str;
	int i;

	if (g_f == NULL)
		if ((g_f = fopen("/etc/passwd", "r")) == NULL)
			return NULL;

	do
		if (fgets(buf, MAX_LINE_CHAR, g_f) == NULL)
			return NULL;
	while (is_all_ws(buf));

	for (str = strtok(buf, ":"), i = 0; str != NULL; str = strtok(NULL, ":"), ++i)
		switch (i) {
		case 0:
			pass.pw_name = str;
			break;
		case 1:
			pass.pw_passwd = str;
			break;
		case 2:
			pass.pw_uid = (uid_t)strtol(str, NULL, 10);
			break;
		case 3:
			pass.pw_gid = (gid_t)strtol(str, NULL, 10);
			break;
		case 4:
			pass.pw_gecos = str;
			break;
		case 5:
			pass.pw_dir = str;
			break;
		case 6:
			pass.pw_shell = str;
			break;
		}

	return &pass;
}

void csd_setpwent(void)
{
	fseek(g_f, 0, SEEK_SET);
}

void csd_endpwent(void)
{
	if (g_f != NULL)
		fclose(g_f);

	g_f = NULL;
}

struct passwd *csd_getpwnam(const char *name)
{
	struct passwd *pass;

	while ((pass = csd_getpwent()) != NULL)
		if (!strcmp(name, pass->pw_name)) {
			csd_endpwent();
			return pass;
		}

	csd_endpwent();

	return NULL;
}

struct passwd *csd_getpwuid(uid_t uid)
{
	struct passwd *pass;

	csd_endpwent();

	while ((pass = csd_getpwent()) != NULL)
		if (uid == pass->pw_uid)
			return pass;

	return NULL;
}

static int is_all_ws(const char *str)
{
	while (*str != '\0') {
		if (!isspace(*str))
			return 0;
		++str;
	}

	return 1;
}

#if 1

int main(void)
{
	struct passwd *pass;

	while ((pass = csd_getpwent()) != NULL) {
		printf("User name: %s\n", pass->pw_name);
		printf("User Id: %lld\n", (long long)pass->pw_uid);
		printf("------------------------\n");
	}

	csd_setpwent();

	while ((pass = csd_getpwent()) != NULL) {
		printf("User name: %s\n", pass->pw_name);
		printf("User Id: %lld\n", (long long)pass->pw_uid);
		printf("------------------------\n");
	}

	csd_endpwent();

	printf("csd_getpwnam test...\n");
	if ((pass = csd_getpwnam("student")) != NULL) {
		printf("User name: %s\n", pass->pw_name);
		printf("User Id: %lld\n", (long long)pass->pw_uid);
	}

	return 0;
}

#endif

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows'ta Dizin içerisindeki dosyaların el edilmesi örneği 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void ExitSys(LPCSTR lpszMsg);

typedef unsigned my_t;

int main(void)
{
	WIN32_FIND_DATA finfo;
	HANDLE hFindFile;
	SYSTEMTIME st;

	if ((hFindFile = FindFirstFile("c:\\windows\\*.exe", &finfo)) == INVALID_HANDLE_VALUE)
		ExitSys("FindFirstFile");

	do {
		printf("%s\n", finfo.cFileName);
		printf("%d\n", finfo.nFileSizeLow);
		FileTimeToLocalFileTime(&finfo.ftLastWriteTime, &finfo.ftLastWriteTime);
		FileTimeToSystemTime(&finfo.ftLastWriteTime, &st);
		printf("Last Write Time: %02d/%02d/%04d %02d:%02d:%02d\n",
			st.wDay, st.wMonth, st.wYear, st.wHour, st.wMinute, st.wSecond);
		printf("----------------------------------\n");
	} while (FindNextFile(hFindFile, &finfo));

	FindClose(hFindFile);

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastError = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}


/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows'ta Dizin içerisindeki dosyaların el edilmesi örneği
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void ExitSys(LPCSTR lpszMsg);

typedef unsigned my_t;

int main(void)
{
	WIN32_FIND_DATA finfo;
	HANDLE hFindFile;
	SYSTEMTIME st;

	if ((hFindFile = FindFirstFile("c:\\windows\\*.*", &finfo)) == INVALID_HANDLE_VALUE)
		ExitSys("FindFirstFile");

	do {
		printf("%s %s\n", finfo.cFileName, finfo.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ? "<DIR>" : "");
		if (!(finfo.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			printf("%d\n", finfo.nFileSizeLow);
		FileTimeToLocalFileTime(&finfo.ftLastWriteTime, &finfo.ftLastWriteTime);
		FileTimeToSystemTime(&finfo.ftLastWriteTime, &st);
		printf("Last Write Time: %02d/%02d/%04d %02d:%02d:%02d\n", st.wDay, st.wMonth, st.wYear, st.wHour, st.wMinute, st.wSecond);
		printf("----------------------------------\n");
	} while (FindNextFile(hFindFile, &finfo));

	FindClose(hFindFile);

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastError = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde dizin içerisindeki dosyaların elde edilmesne örnek
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>

void exit_sys(const char *msg);

int main(int argc, char *argv[])
{
	DIR *dir;
	struct dirent *dent;

	if (argc != 2) {
		fprintf(stderr, "wrong number of arguments!..\n");
		exit(EXIT_FAILURE);
	}

	if ((dir = opendir(argv[1])) == NULL)
		exit_sys("open");

	while (errno = 0, (dent = readdir(dir)) != NULL)
		printf("%s\n", dent->d_name);

	if (errno != 0)
		exit_sys("readdir");

	closedir(dir);

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde dizin listesi elde edilirken yalnızca o dizindeki dosyaların isimleri inode numaraları elde edilmektedir. Eğer dosya
	bilgileri elde edilecekse ayrıca stat ya da lstat fonksiyonu uygulanmalıdır. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PATH      4096

void exit_sys(const char *msg);

int main(int argc, char *argv[])
{
	DIR *dir;
	struct dirent *dent;
	struct stat finfo;
	char path[MAX_PATH];

	if (argc != 2) {
		fprintf(stderr, "wrong number of arguments!..\n");
		exit(EXIT_FAILURE);
	}

	if ((dir = opendir(argv[1])) == NULL)
		exit_sys("open");

	while (errno = 0, (dent = readdir(dir)) != NULL) {
		sprintf(path, "%s/%s", argv[1], dent->d_name);
		if (stat(path, &finfo) == -1)
			exit_sys("stat");

		printf("-------------------------------\n");
		printf("%-25s%s\n", dent->d_name, S_ISDIR(finfo.st_mode) ? "<DIR>" : "");
		printf("%lld\n", (long long)finfo.st_size);
	}

	if (errno != 0)
		exit_sys("readdir");

	closedir(dir);

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Bir dizin'in içeriğini ls -l formatıyla yazdıran program. Burada hizalanma uygulanmamıştır
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>

#define MAX_PATH      4096

void exit_sys(const char *msg);
const char *get_ls(const char *path);

int main(int argc, char *argv[])
{
	DIR *dir;
	struct dirent *dent;
	struct stat finfo;
	char path[MAX_PATH];

	if (argc != 2) {
		fprintf(stderr, "wrong number of arguments!..\n");
		exit(EXIT_FAILURE);
	}

	if ((dir = opendir(argv[1])) == NULL)
		exit_sys("open");

	while (errno = 0, (dent = readdir(dir)) != NULL) {
		sprintf(path, "%s/%s", argv[1], dent->d_name);
		if (stat(path, &finfo) == -1)
			exit_sys("stat");

		printf("%s\n", get_ls(path));
	}

	if (errno != 0)
		exit_sys("readdir");

	closedir(dir);

	return 0;
}

const char *get_ls(const char *path)
{
	struct stat finfo;
	static char buf[4096];
	static mode_t modes[] = { S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH };
	struct passwd *pass;
	struct group *gr;
	char *str;
	int index = 0;
	int i;

	if (stat(path, &finfo) == -1)
		return NULL;

	if (S_ISREG(finfo.st_mode))
		buf[index] = '-';
	else if (S_ISDIR(finfo.st_mode))
		buf[index] = 'd';
	else if (S_ISCHR(finfo.st_mode))
		buf[index] = 'c';
	else if (S_ISBLK(finfo.st_mode))
		buf[index] = 'b';
	else if (S_ISFIFO(finfo.st_mode))
		buf[index] = 'p';
	else if (S_ISLNK(finfo.st_mode))
		buf[index] = 'l';
	else if (S_ISSOCK(finfo.st_mode))
		buf[index] = 's';
	++index;

	for (i = 0; i < 9; ++i)
		buf[index++] = (finfo.st_mode & modes[i]) ? "rwx"[i % 3] : '-';
	buf[index] = '\0';

	index += sprintf(buf + index, " %llu", (unsigned long long)finfo.st_nlink);

	if ((pass = getpwuid(finfo.st_uid)) == NULL)
		return NULL;
	index += sprintf(buf + index, " %s", pass->pw_name);

	if ((gr = getgrgid(finfo.st_gid)) == NULL)
		return NULL;
	index += sprintf(buf + index, " %s", gr->gr_name);

	index += sprintf(buf + index, " %lld", (long long)finfo.st_size);
	index += strftime(buf + index, 100, " %b %e %H:%M", localtime(&finfo.st_mtime));

	str = strrchr(path, '/');
	sprintf(buf + index, " %s", str ? str + 1 : path);

	return buf;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Dizin içeriğini hizalayarak ls -l formatında yazdıran örnek program
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>

#define MAX_PATH      4096

void exit_sys(const char *msg);
const char *get_ls(const char *path, int hlink_digit, int uname_digit, int gname_digit, int size_digit);

int main(int argc, char *argv[])
{
	DIR *dir;
	struct dirent *dent;
	struct stat finfo;
	char path[MAX_PATH];
	struct passwd *pass;
	struct group *gr;
	int len;
	int hlink_digit, uname_digit, gname_digit, size_digit;

	if (argc != 2) {
		fprintf(stderr, "wrong number of arguments!..\n");
		exit(EXIT_FAILURE);
	}

	if ((dir = opendir(argv[1])) == NULL)
		exit_sys("open");

	hlink_digit = uname_digit = gname_digit = size_digit = 0;

	while (errno = 0, (dent = readdir(dir)) != NULL) {
		sprintf(path, "%s/%s", argv[1], dent->d_name);
		if (stat(path, &finfo) == -1)
			exit_sys("stat");

		len = (int)log10(finfo.st_nlink) + 1;
		if (len > hlink_digit)
			hlink_digit = len;

		if ((pass = getpwuid(finfo.st_uid)) == NULL)
			exit_sys("getppuid");

		len = (int)strlen(pass->pw_name);
		if (len > uname_digit)
			uname_digit = len;

		if ((gr = getgrgid(finfo.st_gid)) == NULL)
			exit_sys("getgrgid");

		len = (int)strlen(gr->gr_name);
		if (len > gname_digit)
			gname_digit = len;

		len = (int)log10(finfo.st_size) + 1;
		if (len > size_digit)
			size_digit = len;
	}

	if (errno != 0)
		exit_sys("readdir");

	rewinddir(dir);
	while (errno = 0, (dent = readdir(dir)) != NULL) {
		sprintf(path, "%s/%s", argv[1], dent->d_name);
		if (stat(path, &finfo) == -1)
			exit_sys("stat");

		printf("%s\n", get_ls(path, hlink_digit, uname_digit, gname_digit, size_digit));
	}

	if (errno != 0)
		exit_sys("readdir");

	closedir(dir);

	return 0;
}

const char *get_ls(const char *path, int hlink_digit, int uname_digit, int gname_digit, int size_digit)
{
	struct stat finfo;
	static char buf[4096];
	static mode_t modes[] = { S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH };
	struct passwd *pass;
	struct group *gr;
	char *str;
	int index = 0;
	int i;

	if (stat(path, &finfo) == -1)
		return NULL;

	if (S_ISREG(finfo.st_mode))
		buf[index] = '-';
	else if (S_ISDIR(finfo.st_mode))
		buf[index] = 'd';
	else if (S_ISCHR(finfo.st_mode))
		buf[index] = 'c';
	else if (S_ISBLK(finfo.st_mode))
		buf[index] = 'b';
	else if (S_ISFIFO(finfo.st_mode))
		buf[index] = 'p';
	else if (S_ISLNK(finfo.st_mode))
		buf[index] = 'l';
	else if (S_ISSOCK(finfo.st_mode))
		buf[index] = 's';
	++index;

	for (i = 0; i < 9; ++i)
		buf[index++] = (finfo.st_mode & modes[i]) ? "rwx"[i % 3] : '-';
	buf[index] = '\0';

	index += sprintf(buf + index, " %*llu", hlink_digit, (unsigned long long)finfo.st_nlink);

	if ((pass = getpwuid(finfo.st_uid)) == NULL)
		return NULL;
	index += sprintf(buf + index, " %-*s", uname_digit, pass->pw_name);

	if ((gr = getgrgid(finfo.st_gid)) == NULL)
		return NULL;
	index += sprintf(buf + index, " %-*s", gname_digit, gr->gr_name);

	index += sprintf(buf + index, " %*lld", size_digit, (long long)finfo.st_size);
	index += strftime(buf + index, 100, " %b %e %H:%M", localtime(&finfo.st_mtime));

	str = strrchr(path, '/');
	sprintf(buf + index, " %s", str ? str + 1 : path);

	return buf;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Fonksiyon göstericileri
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void foo(void)
{
	printf("foo\n");
}

int main(void)
{
	void (*pf)(void);
	pf = foo;

	pf();

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Fonksiyon göstericileri
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

int mul(int a, int b)
{
	return a * b;
}

int sub(int a, int b)
{
	return a - b;
}

int main(void)
{
	int (*pf)(int, int);
	int result;

	pf = add;

	result = pf(10, 20);
	printf("%d\n", result);

	pf = mul;

	result = pf(10, 20);
	printf("%d\n", result);

	pf = sub;

	result = pf(10, 20);
	printf("%d\n", result);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Fonksiyon göstericileri
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int *foo(int *a)
{
	return a;
}

int main(void)
{
	int *(*pf)(int *) = foo;
	int a = 10;
	int *pi;


	pi = pf(&a);
	printf("%d\n", a);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Fonksiyon gösterici dizileri
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void foo(void)
{
	printf("foo\n");
}

void bar(void)
{
	printf("bar\n");
}

void tar(void)
{
	printf("tar\n");
}

int main(void)
{
	void (*a[3])(void);
	int i;

	a[0] = foo;
	a[1] = bar;
	a[2] = tar;

	for (i = 0; i < 3; ++i)
		a[i]();

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Fonksiyon gösterici dizilerine ilkdeğer verilmesi
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void foo(void)
{
	printf("foo\n");
}

void bar(void)
{
	printf("bar\n");
}

void tar(void)
{
	printf("tar\n");
}

int main(void)
{
	void (*a[3])(void) = { foo, bar, tar };
	int i;

	for (i = 0; i < 3; ++i)
		a[i]();

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Fonksiyon göstericilerine typedef işlemi
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void foo(void)
{
	printf("foo\n");
}

typedef void (*PF)(void);

int main(void)
{
	PF pf;      /* void (*p)(void) pf; */

	pf = foo;
	pf();

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Bir fonksiyonun parametre değişkeni bir fonlsiyon göstericisi olabilir
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void foo(int a, int (*pf)(int))
{
	int result;

	result = pf(a);

	printf("%d\n", result);
}

int bar(int a)
{
	return a * a;
}

int main(void)
{
	foo(10, bar);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Her ne kadar fonksiyon isimleri zaten fonksiyonların adreslerini belirtiyorsa da yine de istenirse fonksiyon isimleri & operatörüyle kullanılanilir. 
	Yani aslında C'de foo bir fonksiyon belirtmek üzere foo ifadesi ile &foo ifadesi eşdeğerdir. Benzer biçimde foo bir fonksiyon adresi belirtmek üzere
	bu fonksiyonu çağırmak için foo() ifadesiyle tamamen eşdeğer (*foo)() ifadesi de kullanılabilmektedir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void foo(void)
{
	printf("foo\n");
}

int main(void)
{
	void (*pf)(void);

	pf = &foo;      /* eşdeğeri: pf = foo */

	(*pf)();        /* eşdeğer: pf() */

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Fonksiyon göstericileri callback mekaznizmasının oluşturulması için sıkça kullanılmaktadır. Callback fonksiyon belli bir olay gerçekleştiğinde
	çağrılacak fonksiyona denilmektedir. Yani biz bir fonksiyona bir fonksiyon veririz. O fonksiyon da belli durumlarda bizim verdiğimiz fonksiyonu
	çağırır. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void foreach(const int *pi, size_t size, void (*pf)(int))
{
	size_t i;

	for (i = 0; i < size; ++i)
		pf(pi[i]);
}

void foo(int a)
{
	printf("%d\n", a * a);
}

int main(void)
{
	int a[] = { 10, 20, 30, 40, 50 };

	foreach(a, 5, foo);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Callback mekanizması fonksiyonları genelleştirmek için kullanılmaktadır. Aşağıdaki ListDir fonksiyonu bizden aldığı dizin ifadesindeki 
	dosyaları tek tek bulur, bizim belirlediğimiz fonksiyonu çağırır. Sonra da bizim fonksiyonumuz geri dönüş değeri pozitifse dizini dolaşmayı durdurur. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <Windows.h>

int ListDir(LPCSTR szPath, BOOL(*pf)(const WIN32_FIND_DATA *))
{
	HANDLE hFF;
	WIN32_FIND_DATA wfd;
	int result;

	if ((hFF = FindFirstFile(szPath, &wfd)) == INVALID_HANDLE_VALUE)
		return -1;

	do {
		if (!(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) && (result = pf(&wfd)) > 0)
			return result;
	} while (FindNextFile(hFF, &wfd));

	return 0;
}

int DispFile(const WIN32_FIND_DATA *pff)
{
	printf("%s\n", pff->cFileName);

	return 0;
}

int FindFile(const WIN32_FIND_DATA *pff)
{
	if (!strcmpi(pff->cFileName, "notepad.exe"))
		return 1;

	return 0;
}

BOOL Filter(const WIN32_FIND_DATA *pff)
{
	long long size = (long long)pff->nFileSizeHigh << 32 | pff->nFileSizeLow;

	if (size < 1000)
		printf("%s, %lld\n", pff->cFileName, size);

	return TRUE;
}

int main(void)
{
	int result;

	ListDir("c:\\windows\\*.*", DispFile);
	printf("-----------------------------\n");
	ListDir("c:\\windows\\*.*", Filter);
	printf("-----------------------------\n");

	if ((result = ListDir("c:\\windows\\*.*", FindFile)) == -1) {
		fprintf(stderr, "Path cannot find!..\n");
		exit(EXIT_FAILURE);
	}

	if (result > 0)
		printf("Found!..\n");
	else
		printf("Not Found...\n");

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Her türlü diziyi sıraya dizebilen genel bir sort fonksiyonun callback mekanizmasıyla yazılması
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void bsort(void *pv, size_t count, size_t width, int (*compare)(const void *, const void *))
{
	size_t i, k, j;
	char *pc = (char *)pv;
	char *pc1, *pc2;
	char temp;

	for (i = 0; i < count - 1; ++i)
		for (k = 0; k < count - 1 - i; ++k) {
			pc1 = pc + k * width;
			pc2 = pc + (k + 1) * width;
			if (compare(pc1, pc2) > 0) {
				for (j = 0; j < width; ++j) {
					temp = pc1[j];
					pc1[j] = pc2[j];
					pc2[j] = temp;
				}
			}
		}
}

struct PERSON {
	char name[32];
	int no;
};

int cmp(const void *pv1, const void *pv2)
{
	const struct PERSON *per1 = (const struct PERSON *)pv1;
	const struct PERSON *per2 = (const struct PERSON *)pv2;

	if (per1->no > per2->no)
		return 1;
	if (per1->no < per2->no)
		return -1;

	return 0;
}

int main(void)
{
	struct PERSON persons[] = {
		{"Ali Serce", 123},
		{"Veli Boz", 782},
		{"Sacit Apaydin", 824},
		{"Macit Flordun", 623},
		{ "Tansu Ciller", 482}
	};

	int i;

	bsort(persons, 5, sizeof(struct PERSON), cmp);

	for (i = 0; i < 5; ++i)
		printf("%-20s%d\n", persons[i].name, persons[i].no);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Aslında yukarıda yazdığımız bsort fonksiyonu ile aynı parametrik yapıya sahip qsort isimli bir standart C fonksiyonu da vardır. 

	void qsort(void *base, size_t nmemb, size_t size, int (*compare)(const void *, const void *));

	Fonksiyonun yine birinci parameresi dizinin başlangıç adresini, ikinci parametresi onun eleman sayısını, üçüncü parametresi bir elemanının 
	byte uzunluğunu, dördüncü parametresi ise karşılaştımra fonksiyonunu belirtmektedir. Bu karşılaştırma fonksiyonu programcı tarafından 
	eğer soldaki eleman sağdaki elemandan büyükse pozitid herhangi bir değere, eğer sağdaki eleman soldaki elemandan büyükse nehgatif herhangi bir değere
	ve iki eleman biribine eşitse 0 değerine geri dönmelidir. C standartlarında fonksiyonun hangi algoritmayı kullanması gerektiği belirtilmemiş olsa da
	tipik olarak fonksiyon derleyicilerde "quick sort" algoritmasını kullanarak gerçekleştirilmektedir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PERSON {
	char name[32];
	int no;
};

int cmp_no(const void *pv1, const void *pv2)
{
	const struct PERSON *per1 = (const struct PERSON *)pv1;
	const struct PERSON *per2 = (const struct PERSON *)pv2;

	if (per1->no > per2->no)
		return 1;
	if (per1->no < per2->no)
		return -1;

	return 0;
}

#include <ctype.h>

int istrcmp(const char *s1, const char *s2)
{
	while (tolower(*s1) == tolower(*s2)) {
		if (*s1 == '\0')
			return 0;
		++s1;
		++s2;
	}

	return tolower(*s1) - tolower(*s2);
}

int cmp_name(const void *pv1, const void *pv2)
{
	const struct PERSON *per1 = (const struct PERSON *)pv1;
	const struct PERSON *per2 = (const struct PERSON *)pv2;

	return istrcmp(per1->name, per2->name);
}

int main(void)
{
	struct PERSON persons[] = {
		{"ali serce", 123},
		{"Veli Boz", 782},
		{"ali serce ", 824},
		{"macit flordun", 623},
		{"Tansu Ciller", 482},
		{"ali serce", 516}
	};

#define SIZE(persons) (sizeof(persons) / sizeof(*persons))

	int i;

	qsort(persons, , sizeof(struct PERSON), cmp_no);

	for (i = 0; i < SIZE(persons); ++i)
		printf("%-20s%d\n", persons[i].name, persons[i].no);

	printf("--------------------------------------\n");

	qsort(persons, SIZE(persons), sizeof(struct PERSON), cmp_name);

	for (i = 0; i < SIZE(persons); ++i)
		printf("%-20s%d\n", persons[i].name, persons[i].no);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Bir gösterici dizisini qsort fonksiyonuyla sıraya dizerken aslında göstericilerin adresleriyle karşılaştırma fonksiyonu çağrılmaktadır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *pv1, const void *pv2)
{
	const char **ppc1 = (const char **)pv1;
	const char **ppc2 = (const char **)pv2;

	return strcmp(*ppc1, *ppc2);
}

int main(void)
{
	char *names[] = { "ali", "veli", "selami", "ayse", "fatma", "kazim" };
	int i;

	qsort(names, 6, sizeof(char *), compare);

	for (i = 0; i < 6; ++i)
		printf("%s ", names[i]);
	printf("\n");

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde ls -l işleminden elde edilen dosyaların isme göre sıraya dizilerek yazdırılması
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>

#define MAX_PATH        4096
#define BLOCK_SIZE      32

struct lsinfo {
	struct stat finfo;
	char *name;
};

void exit_sys(const char *msg);
const char *get_ls(const struct lsinfo *lsinfo, int hlink_digit, int uname_digit, int gname_digit, int size_digit);
int cmp_name(const void *lsinfo1, const void *lsinfo2);

int main(int argc, char *argv[])
{
	DIR *dir;
	struct dirent *dent;
	struct lsinfo *lsinfo;
	int count;
	char path[MAX_PATH];
	struct passwd *pass;
	struct group *gr;
	int len;
	int hlink_digit, uname_digit, gname_digit, size_digit;
	int i;

	if (argc != 2) {
		fprintf(stderr, "wrong number of arguments!..\n");
		exit(EXIT_FAILURE);
	}

	if ((dir = opendir(argv[1])) == NULL)
		exit_sys("open");

	lsinfo = NULL;
	for (count = 0, errno = 0; (dent = readdir(dir)) != NULL; ++count) {
		sprintf(path, "%s/%s", argv[1], dent->d_name);
		if (count % BLOCK_SIZE == 0)
			if ((lsinfo = realloc(lsinfo, (count + BLOCK_SIZE) * sizeof(struct lsinfo))) == NULL) {
				fprintf(stderr, "cannot allocate memory!..\n");
				exit(EXIT_FAILURE);
			}
		if ((lsinfo[count].name = (char *)malloc(strlen(dent->d_name) + 1)) == NULL) {
			fprintf(stderr, "cannot allocate memory!...\n");
			exit(EXIT_FAILURE);
		}
		strcpy(lsinfo[count].name, dent->d_name);
		if (stat(path, &lsinfo[count].finfo) == -1)
			exit_sys("stat");
	}

	if (errno != 0)
		exit_sys("readdir");

	closedir(dir);

	hlink_digit = uname_digit = gname_digit = size_digit = 0;

	for (i = 0; i < count; ++i) {
		len = (int)log10(lsinfo[i].finfo.st_nlink) + 1;
		if (len > hlink_digit)
			hlink_digit = len;

		if ((pass = getpwuid(lsinfo[i].finfo.st_uid)) == NULL)
			exit_sys("getppuid");

		len = (int)strlen(pass->pw_name);
		if (len > uname_digit)
			uname_digit = len;

		if ((gr = getgrgid(lsinfo[i].finfo.st_gid)) == NULL)
			exit_sys("getgrgid");

		len = (int)strlen(gr->gr_name);
		if (len > gname_digit)
			gname_digit = len;

		len = (int)log10(lsinfo[i].finfo.st_size) + 1;
		if (len > size_digit)
			size_digit = len;
	}

	qsort(lsinfo, count, sizeof(struct lsinfo), cmp_name);

	for (i = 0; i < count; ++i)
		printf("%s\n", get_ls(&lsinfo[i], hlink_digit, uname_digit, gname_digit, size_digit));

	for (i = 0; i < count; ++i)
		free(lsinfo[i].name);

	free(lsinfo);

	return 0;
}

const char *get_ls(const struct lsinfo *lsinfo, int hlink_digit, int uname_digit, int gname_digit, int size_digit)
{
	static char buf[4096];
	static mode_t modes[] = { S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH };
	struct passwd *pass;
	struct group *gr;
	int index = 0;
	int i;

	if (S_ISREG(lsinfo->finfo.st_mode))
		buf[index] = '-';
	else if (S_ISDIR(lsinfo->finfo.st_mode))
		buf[index] = 'd';
	else if (S_ISCHR(lsinfo->finfo.st_mode))
		buf[index] = 'c';
	else if (S_ISBLK(lsinfo->finfo.st_mode))
		buf[index] = 'b';
	else if (S_ISFIFO(lsinfo->finfo.st_mode))
		buf[index] = 'p';
	else if (S_ISLNK(lsinfo->finfo.st_mode))
		buf[index] = 'l';
	else if (S_ISSOCK(lsinfo->finfo.st_mode))
		buf[index] = 's';
	++index;

	for (i = 0; i < 9; ++i)
		buf[index++] = (lsinfo->finfo.st_mode & modes[i]) ? "rwx"[i % 3] : '-';
	buf[index] = '\0';

	index += sprintf(buf + index, " %*llu", hlink_digit, (unsigned long long)lsinfo->finfo.st_nlink);

	if ((pass = getpwuid(lsinfo->finfo.st_uid)) == NULL)
		return NULL;
	index += sprintf(buf + index, " %-*s", uname_digit, pass->pw_name);

	if ((gr = getgrgid(lsinfo->finfo.st_gid)) == NULL)
		return NULL;
	index += sprintf(buf + index, " %-*s", gname_digit, gr->gr_name);

	index += sprintf(buf + index, " %*lld", size_digit, (long long)lsinfo->finfo.st_size);
	index += strftime(buf + index, 100, " %b %e %H:%M", localtime(&lsinfo->finfo.st_mtime));

	sprintf(buf + index, " %s", lsinfo->name);

	return buf;
}

int istrcmp(const char *s1, const char *s2)
{
	while (tolower(*s1) == tolower(*s2)) {
		if (*s1 == '\0')
			return 0;
		++s1;
		++s2;
	}

	return tolower(*s1) - tolower(*s2);
}

int cmp_name(const void *pv1, const void *pv2)
{
	const struct lsinfo *lsinfo1 = (const struct lsinfo *)pv1;
	const struct lsinfo *lsinfo2 = (const struct lsinfo *)pv2;

	return istrcmp(lsinfo1->name, lsinfo2->name);
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	scandir POSIX fonksiyonun kullanıma bir örnek
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <dirent.h>

void exit_sys(const char *msg);

int mycallback(const struct dirent *de)
{
	if (tolower(de->d_name[0]) == 'a')
		return 1;

	return 0;
}

int main(void)
{
	struct dirent **dents;
	int i, count;

	if ((count = scandir("/usr/include", &dents, mycallback, NULL)) == -1)
		exit_sys("scandir");

	for (i = 0; i < count; ++i)
		printf("%s\n", dents[i]->d_name);

	for (i = 0; i < count; ++i)
		free(dents[i]);

	free(dents);

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	scandir POSIX fonksiyonunun kullanımına bir örnek
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/stat.h>

void exit_sys(const char *msg);

int mycallback(const struct dirent *de)
{
	struct stat finfo;
	char path[4096];

	sprintf(path, "/usr/include/%s", de->d_name);

	if (stat(path, &finfo) == -1)
		exit_sys("stat");

	return finfo.st_size < 1000;
}

int main(void)
{
	struct dirent **dents;
	int i, count;

	if ((count = scandir("/usr/include", &dents, mycallback, NULL)) == -1)
		exit_sys("scandir");

	for (i = 0; i < count; ++i)
		printf("%s\n", dents[i]->d_name);

	for (i = 0; i < count; ++i)
		free(dents[i]);

	free(dents);

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Fonksiyon gösterici dizilerine örnek
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void foo(void)
{
	printf("foo\n");
}

void bar(void)
{
	printf("bar\n");
}

void tar(void)
{
	printf("tar\n");
}

void car(void)
{
	printf("car\n");
}

int main(void)
{
	void (*pfs[4])(void);
	int i;

	pfs[0] = foo;
	pfs[1] = bar;
	pfs[2] = tar;
	pfs[3] = car;

	for (i = 0; i < 4; ++i)
		pfs[i]();

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Fonksiyon gösterici dizilerine küme parantezleri kullanılarak ilkdeğerler de verilebilir:
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void foo(void)
{
	printf("foo\n");
}

void bar(void)
{
	printf("bar\n");
}

void tar(void)
{
	printf("tar\n");
}

void car(void)
{
	printf("car\n");
}

int main(void)
{
	void (*pfs[])(void) = { foo, bar, tar, car };
	int i;

	for (i = 0; i < 4; ++i)
		pfs[i]();

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Komut satırı (REPL) oluşturan bir örnek. Bu örnekte komut bulunduğunda beelirlenen bir fonksiyon çağrılmaktadır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#define PROMPT					"CSD>"
#define MAX_CMD_LINE			4096
#define MAX_CMD_PARAMS			64

struct CMD {
	char *cmd_text;
	void (*proc)(void);
};

void parse_cmd_line(void);
void proc_dir(void);
void proc_copy(void);
void proc_cls(void);
void proc_rename(void);

char g_cmd_line[MAX_CMD_LINE];
struct CMD g_cmds[] = {
	{"dir", proc_dir},
	{"copy", proc_copy},
	{"cls", proc_cls},
	{"rename", proc_rename},
	{NULL, NULL},
};
char *g_params[MAX_CMD_PARAMS];
int g_nparams;

int main(void)
{
	char *str;
	int i;

	for (;;) {
		printf(PROMPT);
		fgets(g_cmd_line, MAX_CMD_LINE, stdin);
		if ((str = strchr(g_cmd_line, '\n')) != NULL)
			*str = '\0';

		parse_cmd_line();
		if (g_nparams == 0)
			continue;
		if (!strcmp(g_params[0], "exit"))
			break;
		for (i = 0; g_cmds[i].cmd_text != NULL; ++i)
			if (!strcmp(g_cmds[i].cmd_text, g_params[0])) {
				g_cmds[i].proc();
				break;
			}
		if (g_cmds[i].cmd_text == NULL)
			printf("command not found: %s\n\n", g_params[0]);
	}

	return 0;
}

void parse_cmd_line(void)
{
	char *str;

	g_nparams = 0;
	for (str = strtok(g_cmd_line, " \t"); str != NULL; str = strtok(NULL, " \t"))
		g_params[g_nparams++] = str;
	g_params[g_nparams] = NULL;
}

void proc_dir(void)
{
	printf("dir command\n");
}

void proc_copy(void)
{
	if (g_nparams != 3) {
		printf("argument too few or too many!..\n\n");
		return;
	}
}

void proc_cls(void)
{
	if (g_nparams != 1) {
		printf("too many arguments!\n\n");
		return;
	}
	printf("cls command\n");
}

void proc_rename(void)
{
	printf("rename command\n");
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Bir fonksiyonun adresini farklı türden bir fonksiyon gösterisine atarken tür dönüştürmesi yapmak gerekir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void foo(int a)
{
	printf("foo: %d\n", a);
}

int main(void)
{
	void (*pf)(void);
	void (*pf_original)(int);

	pf = (void (*)(void))foo;

	/* ..... */

	pf_original = (void (*) (int))pf;
	pf_original(100);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	C'de fonksiyon adresleri void bir göstericiye atanamaz. Tür dönüştürme operatörüyle fonksiyon adresleri data adreslerine (örneğin void * türüne)
	dönüştürülemez. Bunun tersi de yapılamaz. Ancak hile yoluyla bir fonksiyon adresi bir data adresine aşağıdaki gibi atanabilmektedir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void foo(int a)
{
	printf("foo: %d\n", a);
}

int main(void)
{
	void *pv;
	void (*pf)(int) = foo;		/* geçerli */

	pv = *(void **)&pf;			/* kandırmaca yol, ama standart bakımından geçerli */
	/* ... */


	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Tabii yukarıdaki işlemin tersi de benzer biçimde yapılabilmektedir
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void foo(int a)
{
	printf("foo: %d\n", a);
}

int main(void)
{
	void *pv;		/* pv'de bir fonksiyonun adresinin olduğunu varsayalım */
	void (*pf)(int);

	*(void **)&pf = pv;

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Bir fonksiyoun geri dönüş değeri bir fonksiyon adresi ise * atomu parantez içerisine alınır, parantezin sı-oluna geri dönüş değerine ilişkin
	fonksiyonun geri dönüş değeri, sağına ise geri dönüş değerine ilişkin fonksiyonun parametre türleri yazılır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int bar(double a)
{
	printf("bar: %f\n", a);

	return 0;
}

int (*foo(void)) (double)
{
	return bar;
}

int main(void)
{
	int (*pf)(double);

	pf = foo();

	pf(1.2);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Geri dönüş değeri fonksiyon göstericisi olan fonksiyonların tanımlanması işlemi typedef bildirimleri ile çok kolaylaşmaktadır
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int bar(double a)
{
	printf("bar: %f\n", a);

	return 0;
}

int (*foo(void)) (double)
{
	return bar;
}

int main(void)
{
	int (*pf)(double);

	pf = foo();

	pf(1.2);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Bildirimler daha karmaşık olabilir. Örneğin foo fonksiyonun kendi parametresi void ancak geri dönüş değeri parametresi double geri dönüş değeri
	parametresi long geri dönüş değeri int türden olan bir fonksiyon adresi olsun. Daha açık bir yazarsak biz burada bir foo fonksiyonu yazmak istiyoruz.

	foo

	foo fonksiyonun kendi parametresi void olsun diyoruz:

	foo(void)

	ancak foo fonksiyonun geri dönüş değeri bir fonksiyon adresi olsun istiyoruz:

	(*foo(void))

	Öyle bir fonksiyon adresi olsun ki o fonksiyonun parametresi double türden olsun:

	(*foo(void))(double)

	Ancak foo fonksiyonun geri döndürdüğü fonksiyon adresinin ilişkin olduğu fonksiyonunda geri dönüş değeri bir fonksiyon adresi olsun:

	(*(*foo(void))(double))

	Bu fonksiyonun parametresi long olsun:

	(*(*foo(void))(double))(long)

	ve geri dönüş değeri int olsun:

	int (*(*foo(void))(double))
	{
		....
	}

-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int tar(long a)
{
	printf("tar\n");

	return 0;
}

int (*bar(double a))(long)
{
	return tar;
}

int (*(*foo(void))(double))(long)
{
	printf("foo\n");

	return bar;
}

int main(void)
{
	int (*(*pf1)(double))(long);
	int (*pf2)(long);

	pf1 = foo();
	pf2 = pf1(0);
	pf2(0);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Tabii yukarıdaki karmaşık bildirim yine typedef sayesinde daha basit ifade edilebilirdi
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

typedef int (*PF1)(long);

int tar(long a)
{
	printf("tar\n");

	return 0;
}

PF1 bar(double a)
{
	return tar;
}

typedef PF1(*PF2)(double);

PF2 foo(void)
{
	printf("foo\n");

	return bar;
}

int main(void)
{
	PF2 pf2;
	PF1 pf1;

	pf2 = foo();
	pf1 = pf2(0);
	pf1(0);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Bir göstericinin adresi göstericiyi gösteren göstericide saklanabilir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main(void)
{
	int a = 10;
	int *pi;
	int **ppi;

	pi = &a;
	ppi = &pi;

	printf("%d\n", **ppi);

	**ppi = 20;
	printf("%d\n", a);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Bir gösterici dizisinin ismi onun ilk elemanının adresi olacağına göre göstericiyi gösteren göstericiye atanmalıdır
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main(void)
{
	char *names[] = { "ali", "veli", "selami" };
	char **str;

	str = names;

	puts(*str);

	++str;

	puts(*str);

	++str;

	puts(*str);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	C'de parametre parantezi içerisindeki dizisel gösterin tamamen "gösterici" anlamına gelmektedir. Köşeli parantezlerin içeirisndeki sayıların da
	hiçbir önemi yoktur. Dolayısıyla aşağıdaki prototiplerin hepsi aynıdır
-------------------------------------------------------------------------------------------------------------------------------------------*/

void foo(int *a);
void foo(int a[]);
void foo(int a[100]);
void foo(int a[5]);

/*------------------------------------------------------------------------------------------------------------------------------------------
	Fonksiyonun parametresi göstericiyi gösterene gösterici ise o parametre yine dizi sentaksıyla belirtilebilir. Dolayısıyla aşağıdaki prototipler
	yine eşdeğerdir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

void bar(int **a);
void bar(int *a[10]);
void bar(int *a[]);

/*------------------------------------------------------------------------------------------------------------------------------------------
	Fonksiyon parametresi fonksiyon göstericisi ise o da alternatif biçimde fonksiyon sentaksıyla belirtilebilmektedir. Aşağıdaki iki prototip
	eşdeğerdir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

void tar(int (*a)(double));
void tar(int a(double));

/*------------------------------------------------------------------------------------------------------------------------------------------
	Çok boyutlu diziler aslında C'de dizi dizileri olarak düşünülmelidir. Öneğin:

	int a[3][2];

	Burada a aslında 3 elemanlı bir dizidir. Ancak dizinin her elemanı int[2] türünden yani 2 elemanlı bir int dizidir. İlk köşeli parantez 
	her zaman asıl dizinin u<unluğunu belirtmektedir. Diğer köşeli parantezler eleman olan dizinin türü ile ilgilidir. Bir dizinin ismi dizinin
	eilk elemanın adresini belirttiğine göre yukarıdaki iki boyutlu dizide a ifadesi aslında iki elemanlı bir int dizinin adresini belirtir. 
	Biz C'de dizi isimlerinin adreslerini alabiliriz. Bu durumda elde edilen adres dizi türünden adres olur. Dizi türünden adresler 
	sembolik olarak "tür (*)[uzunuk]" biçiminde ifade edilir. Örneğin:

	int a[2];
	int (*p)[2];

	p = &a;


	Mademki bir dizinin ismi o dizinin ilk elemanın adresini belirtmektedir. O halde aşağıdaki iki boyutlu dizinin ismi hangi türdne adres belirtir?

	int a[3][2];

	Burada a 3 elemanlı, her elemanı 2 elemanlı bir dizi olan dizidir. O halde a ifadesi aslında int (*)[2] türündendir. Örneğin:

	int a[3][2];
	int(*p)[2];

	p = a;

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	Bir dizi göstericisinin gösterdiği yere erişirsek o diziin tamamına erişmiş oluruz. Örneğin:

	int a[3][2];
	int (*pa)[2];

	pa = a;

	Burada pa aslında matrisin ilk elemanı olan iki elemanlı int dizinin tamamını göstermektedir. Dolayısıyla *pa ifadesi aslında 2 elemanlı
	bir int diziyi temsil eder. Tabii bu ifade pa[0] ifadesiyle eşdeğerdir. Burada pa[1] ifadesi bu matrisin ikinci satırını oluşturan 2 elemanlı int diziyi 
	temsil etmektedir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main(void)
{
	int a[3][2] = { {1, 2}, {3, 4}, {5, 6} };
	int(*pa)[2];

	pa = a;

	printf("%d\n", (*pa)[0]);
	printf("%d\n", (*pa)[1]);

	printf("%d\n", pa[1][0]);
	printf("%d\n", pa[1][1]);

	printf("%d\n", pa[2][0]);
	printf("%d\n", pa[2][1]);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Pekiyi bir matrisi fonksiyona partametre olarak nasıl geçirebiliriz. İşte fonksiyonun parametre değişkeninin bir dizi göstrivisi olması gerekir. 
	Ayrıxa matrisin satır uzunluğunun da fonksiyona aktarılması uygun olur
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void foo(int(*pa)[2], size_t size)
{
	size_t i, k;

	for (i = 0; i < size; ++i) {
		for (k = 0; k < 2; ++k)
			printf("%d ", pa[i][k]);
		printf("\n");
	}
}

int main(void)
{
	int a[3][2] = { {1, 2}, {3, 4}, {5, 6} };

	foo(a, 3);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Tek boyutlu bir dizi bir dizi göstericisine tür dönüştürme operatörü kullanılarak atanabilir. Bubdan sonra dizi elemanlarına matris sentaksıyla
	erişilebilir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main(void)
{
	int a[6] = { 1, 2, 3, 4, 5, 6 };
	int (*b)[2];
	int i, k;

	b = (int(*)[2]) a;

	for (i = 0; i < 3; ++i) {
		for (k = 0; k < 2; ++k)
			printf("%d ", b[i][k]);
		printf("\n");
	}

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Bir matiris için de dinamik tahsisatlar yapabiliriz. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int(*pa)[2];
	int i, k;

	pa = (int(*)[2]) malloc(5 * sizeof(*pa));
	if (pa == NULL) {
		fprintf(stderr, "cannot allocate memory!..\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < 5; ++i)
		for (k = 0; k < 2; ++k)
			pa[i][k] = i + k;

	for (i = 0; i < 5; ++i) {
		for (k = 0; k < 2; ++k)
			printf("%d ", pa[i][k]);
		printf("\n");
	}

	free(pa);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	satır sütun uzunluğu belirtilerek bir matrisin genel biçimde fonksiyona aktarılması dizi göstericisi yoluyla mümkün değildir. Bu tür genel
	fonksiyonlar mecburen tek boyutlu diziye indirgeme yapılarak gerçekleştirilir. p T tütünden bir matrisin başlangıç adresini belirten T türünden 
	bir adres olmak üzere matirisn i, k indeksli elemanına p + i * colsize + k ifadesiyle erişilebilir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void foo(const int *pi, size_t rowsize, size_t colsize)
{
	size_t i, k;

	for (i = 0; i < rowsize; ++i) {
		for (k = 0; k < colsize; ++k)
			printf("%d ", *(pi + i * colsize + k));
		printf("\n");
	}
}

int main(void)
{
	int a[3][3] = { {1, 2, 3}, {3, 4, 6}, {7, 8, 9} };

	foo((int *)a, 3, 3);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Çok boyutlu dizi göstericileri söz konusu olabilir
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void foo(int(*pa)[3][9])
{
	/* ... */
}

int main(void)
{
	int a[5][3][9];

	foo(a);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Fonksiyonun parametre parantezi içerisinde çok boyutlu dizi sentaksı dizi göstericisi anlamına gelmektedir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

void foo(int a[][5])			/* int (*a)[5] */
{
	/* ... */
}

int main(void)
{
	int a[5];

	foo(&a);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Fonksiyonların geri dönüş değerleri dizi türünden adresler olabilir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int(*foo(void))[5]
{
	static int a[3] = {1, 2, 3, 4, 5};

	return &a;
}

int main(void)
{
	int(*pa)[5];
	int i;

	pa = foo();
	for (i = 0; i < 5; ++i)
		printf("%d ", (*pa)[i]);
	printf("\n");

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows sistemlerinde prosesin çalışma dizini (current working directory) GetCurrentDirectory API fonksiyonuyla elde edilir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <Windows.h>

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	char cwd[MAX_PATH];

	if (!GetCurrentDirectory(MAX_PATH, cwd))
		ExitSys("GetCurrentDirectory");

	printf("%s\n", cwd);

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastError = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	GetCurrentDirectory fonksiyonunda birinci parametre 0, ikinci parametre NULL geçilirse çalışma dizini için gereken karakter uzunluğu (byte değil)
	elde edilir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <Windows.h>

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	char *cwd;
	DWORD dwLen;

	if ((dwLen = GetCurrentDirectory(0, NULL)) == 0)
		ExitSys("GetCurrentDirectory");

	if ((cwd = (char *)malloc(dwLen)) == NULL) {
		fprintf(stderr, "Cannot allocate memory!..\n");
		exit(EXIT_FAILURE);
	}

	if (!GetCurrentDirectory(dwLen, cwd))
		ExitSys("GetCurrentDirectory");

	printf("%s\n", cwd);

	free(cwd);

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastError = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}
 
/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde prosesin çalışma dizini getcwd POSIX fonksiyonuyla elde edilir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void exit_sys(const char *msg);

int main(void)
{
	char cwd[4096];

	if (getcwd(cwd, 4096) == NULL)
		exit_sys("getcwd");

	puts(cwd);

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows sistemlerinde maksimum path uzunluğu MAX_PATH sembolik sabitiyle belirlenmiştir. Ancak POSIX sistemlerinde böyle bir sembolik sabit yoktur.
	Ancak çalışma zamanı sırasında bu sistemlerde maksimum path uzunluğu elde edilebilir. Aşağıdaki örnekte bunu elde eden path_max isimli bir
	fonksiyon verilmiştir. Ancak bu fonksiyonun nasıl yazıldığı UNIX/Linux Sistem Programlama kursunun konusu içerisindedir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

void exit_sys(const char *msg);

long path_max(void)
{
	static long result = 0;

#define PATH_MAX_INDETERMINATE_GUESS     4096

#ifdef PATH_MAX
	result = PATH_MAX;
#else
	if (result == 0) {
		errno = 0;
		if ((result = pathconf("/", _PC_PATH_MAX)) == -1 && errno == 0)
			result = PATH_MAX_INDETERMINATE_GUESS;
	}
#endif

	return result;
}

int main(void)
{
	char *cwd;
	long size;

	size = path_max();
	if ((cwd = (char *)malloc(size)) == NULL)
		exit_sys("malloc");

	if (getcwd(cwd, size) == NULL)
		exit_sys("getcwd");

	printf("size: %ld, cwd = %s\n", size, cwd);

	free(cwd);

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Basit bir shell uygulamasında (cmd.exe benzeri bir shell) GetCurrentDirectory ve SetCurrentDirectory API fonksiyonlarının kullanımı
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <windows.h>

#define MAX_CMD_LINE			4096
#define MAX_CMD_PARAMS			64

struct CMD {
	char *cmd_text;
	void (*proc)(void);
};

void ExitSys(LPCSTR lpszMsg);
void ParseCmdLine(void);
void DirProc(void);
void CopyProc(void);
void ClsProc(void);
void RenameProc(void);
void ChangeDirProc(void);
void DispDirectory(LPCTSTR lpszPath);

char g_cmd_line[MAX_CMD_LINE];
struct CMD g_cmds[] = {
	{"dir", DirProc},
	{"copy", CopyProc},
	{"cls", ClsProc},
	{"rename", RenameProc},
	{"cd", ChangeDirProc},
	{NULL, NULL},
};
char *g_params[MAX_CMD_PARAMS];
int g_nparams;
char g_cwd[MAX_PATH];

int main(void)
{
	char *str;
	int i;

	if (!GetCurrentDirectory(MAX_PATH, g_cwd))
		ExitSys("GetCurrentDirectory");

	for (;;) {
		printf("%s>", g_cwd);
		fgets(g_cmd_line, MAX_CMD_LINE, stdin);
		if ((str = strchr(g_cmd_line, '\n')) != NULL)
			*str = '\0';

		ParseCmdLine();
		if (g_nparams == 0)
			continue;
		if (!strcmp(g_params[0], "exit"))
			break;
		for (i = 0; g_cmds[i].cmd_text != NULL; ++i)
			if (!strcmp(g_cmds[i].cmd_text, g_params[0])) {
				g_cmds[i].proc();
				break;
			}
		if (g_cmds[i].cmd_text == NULL)
			printf("command not found: %s\n\n", g_params[0]);
	}

	return 0;
}

void ParseCmdLine(void)
{
	char *str;

	g_nparams = 0;
	for (str = strtok(g_cmd_line, " \t"); str != NULL; str = strtok(NULL, " \t"))
		g_params[g_nparams++] = str;
	g_params[g_nparams] = NULL;
}

void DirProc(void)
{
	if (g_nparams > 2) {
		printf("too many arguments!..\n");
		return;
	}

	DispDirectory(g_nparams == 1 ? g_cwd : g_params[1]);
}

void CopyProc(void)
{
	if (g_nparams != 3) {
		printf("argument too few or too many!..\n\n");
		return;
	}
}

void ClsProc(void)
{
	if (g_nparams != 1) {
		printf("too many arguments!\n\n");
		return;
	}
	printf("cls command\n");
}

void RenameProc(void)
{
	printf("rename command\n");
}

void ChangeDirProc(void)
{
	if (g_nparams > 2) {
		printf("too many arguments!..\n\n");
		return;
	}

	if (g_nparams == 1) {
		printf("%s\n\n", g_cwd);
		return;
	}

	if (!SetCurrentDirectory(g_params[1])) {
		printf("directory not found or cannot change: %s\n\n", g_params[1]);
		return;
	}

	if (!GetCurrentDirectory(MAX_PATH, g_cwd))
		ExitSys("GetCurrentDirectory");
}

void DispDirectory(LPCTSTR lpszPath)
{
	WIN32_FIND_DATA wfd;
	char lpszDirPath[MAX_PATH];
	HANDLE hFF;

	sprintf(lpszDirPath, "%s/*.*", lpszPath);
	if ((hFF = FindFirstFile(lpszDirPath, &wfd)) == INVALID_HANDLE_VALUE) {
		printf("directory not found or cannot display!\n\n");
		return;
	}

	do {
		if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			printf("%-10s", "<DIR>");
		else
			printf("%-10lu", wfd.nFileSizeLow);

		printf("%s\n", wfd.cFileName);
	} while (FindNextFile(hFF, &wfd));

	printf("\n");
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastError = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde proseslerin çalışma dizinleri chdir isimli POSIX fonksiyonuyla değiştirilir
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void exit_sys(const char *msg);

int main(void)
{
	char cwd[4096];

	if (getcwd(cwd, 4096) == NULL)
		exit_sys("getcwd");

	puts(cwd);

	if (chdir("/usr/include") == -1)
		exit_sys("getcwd");

	if (getcwd(cwd, 4096) == NULL)
		exit_sys("getcwd");

	puts(cwd);

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Özyinelemeye tipik bir örnek
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void foo(int a)
{
	printf("Giriş: a = %d\n", a);

	if (a == 0)
		return;

	foo(a - 1);

	printf("Çıkış: a = %d\n", a);
}

int main(void)
{
	foo(5);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Faktöriyel hesabı yapan iteratif fonksiyon
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

unsigned long factorial(int n)
{
	unsigned long f = 1;
	int i;

	for (i = 2; i <= n; ++i)
		f *= i;

	return f;
}

int main(void)
{
	unsigned long result;

	result = factorial(2);
	printf("%lu\n", result);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Faktöriyel hesabı yapan özyinelemeli fonksiyon
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

unsigned long long factorial(int n)
{
	if (n == 0)
		return 1;

	return n * factorial(n - 1);
}

int main(void)
{
	unsigned long long result;

	result = factorial(6);
	printf("%llu\n", result);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Yazıyı tersten yazdıran iteratif fonksiyon
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void putsrev(const char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; ++i)
		;

	for (--i; i >= 0; --i)
		putchar(str[i]);

	putchar('\n');
}

int main(void)
{
	putsrev("ankara");

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Yazıyı tersten yazdıran özyinelemeli fonksiyon
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void putsrev(const char *str)
{
	if (*str == '\0')
		return;

	putsrev(str + 1);
	putchar(*str);
}

int main(void)
{
	putsrev("ankara");
	putchar('\n');

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Yazıyı iteratif yolla ters çeviren fonksiyon
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void revstr(char *str)
{
	size_t n, i;
	char temp;

	for (n = 0; str[n] != '\0'; ++n)
		;

	for (i = 0; i < n / 2; ++i) {
		temp = str[n - 1 - i];
		str[n - 1 - i] = str[i];
		str[i] = temp;
	}
}

int main(void)
{
	char s[] = "ankara";

	revstr(s);
	puts(s);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Yukarıdaki fonksiyonun iteratif olarak başka bir yazım biçimi
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

void revstr(char *str, size_t left, size_t right)
{
	char temp;

	while (left < right) {
		temp = str[left];
		str[left] = str[right];
		str[right] = temp;
		++left, --right;
	}
}

int main(void)
{
	char s[] = "ankara";

	revstr(s, 0, strlen(s) - 1);
	puts(s);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Yukarıdaki fonksiyonun özyinelemeli biçimi
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

void revstr(char *str, size_t left, size_t right)
{
	char temp;

	while (left >= right)
		return;

	temp = str[left];
	str[left] = str[right];
	str[right] = temp;

	revstr(str, left + 1, right - 1);
}

int main(void)
{
	char s[] = "ankara";

	revstr(s, 0, strlen(s) - 1);
	puts(s);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Bazen özyinelemeli fonksiyonun parametrik yapısı kolay kullanıma izin veremeyebilir. Bu durumda programcı bir sarma fonksiyon(wrapper function)
	yazarak özyinelemeli fonksiyonu çağırır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void revstr_recur(char *str, size_t left, size_t right)
{
	char temp;

	while (left >= right)
		return;

	temp = str[left];
	str[left] = str[right];
	str[right] = temp;

	revstr_recur(str, left + 1, right - 1);
}

void revstr(char *str)
{
	size_t i;

	if (*str == '\0')
		return;

	for (i = 0; str[i] != '\0'; ++i)
		;

	revstr_recur(str, 0, i - 1);
}

int main(void)
{
	char s[] = "ankara";

	revstr(s);
	puts(s);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Bir int sayıyı binary olarak iteratif biçimde ekrana yazdıran fonksiyon
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void binprint(unsigned int n)
{
	int i;

	for (i = sizeof(n) * 8 - 1; i >= 0; --i)
		putchar((n >> i & 1) + '0');
	putchar('\n');
}

int main(void)
{
	binprint(21);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Yukarıdaki fonksiyonun baştaki 0'ları yazdırmayan biçimi
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void binprint(unsigned int n)
{
	int i;

	for (i = sizeof(n) * 8 - 1; i >= 0; --i)
		if (n >> i & 1)
			break;

	for (; i >= 0; --i)
		putchar((n >> i & 1) + '0');
	putchar('\n');
}

int main(void)
{
	binprint(21);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Yukarıdaki fonksiyonun özyinelemeli biçimi aşağıdaki gibi yazılabilir. Özyineleme düz olan bir şeyi tersten yaptırmak için de çok kullanılmaktadır. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void binprint(unsigned int n)
{
	if (n == 0)
		return;
	binprint(n >> 1);

	putchar((n & 1) + '0');
}

int main(void)
{
	binprint(21);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Bir tamsayının yalnızca putchar fonksiyonu kullanılarak ekrana yazdırılması
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>

void putint(long long n)
{
	char s[32];
	int i, nflag;

	nflag = 0;
	if (n < 0) {
		n = -n;
		nflag = 1;
	}
	i = (int)log10(n) + 1 + nflag;
	s[i--] = '\0';

	while (n) {
		s[i--] = n % 10 + '0';
		n /= 10;
	}
	if (nflag)
		s[i] = '-';

	for (i = 0; s[i] != '\0'; ++i)
		putchar(s[i]);
	putchar('\n');
}

int main(void)
{
	putint(-1234);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Yukarıdaki işlemin özyinelemeli biçimi. Burada özyineleme ters olan bir şeyi düz hale getirmektedir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void putint(long long n)
{
	if (n < 0) {
		n = -n;
		putchar('-');
	}

	if (n / 10)
		putint(n / 10);

	putchar(n % 10 + '0');
}

int main(void)
{
	putint(-1234);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Yukarıdaki fonksiyonun herhangi bir tabana göre genelleştirilmiş biçimi
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void putint(long long n, int base)
{
	if (n < 0) {
		n = -n;
		putchar('-');
	}

	if (n / base)
		putint(n / base, base);

	putchar(n % base > 9 ? n % base - 10 + 'A' : n % base + '0');
	/* putchar((n % base > 9 ? -10 + 'A' : '0') + n % base); */
}

int main(void)
{
	putint(123, 10);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Kapalı bir şeklin içinin boyanması için floodfill algoritması
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

char g_bitmap[10][22];

int read_bitmap(const char *path)
{
	FILE *f;
	int i;

	if ((f = fopen(path, "r")) == NULL)
		return 0;

	for (i = 0; i < 10; ++i)
		fgets(g_bitmap[i], 22, f);

	fclose(f);

	return 1;
}

void floodfill(int row, int col, int ch)
{
	if (g_bitmap[row][col] == '#' || g_bitmap[row][col] == ch)
		return;

	g_bitmap[row][col] = ch;

	floodfill(row - 1, col, ch);
	floodfill(row, col + 1, ch);
	floodfill(row + 1, col, ch);
	floodfill(row, col - 1, ch);
}

void disp_bitmap(void)
{
	int row, col;

	for (row = 0; row < 10; ++row) {
		for (col = 0; col < 20; ++col)
			putchar(g_bitmap[row][col]);
		putchar('\n');
	}
}

int main(void)
{
	if (!read_bitmap("bitmap.txt")) {
		fprintf(stderr, "cannot read bitmap!..\n");
		exit(EXIT_FAILURE);
	}

	floodfill(5, 5, '.');

	disp_bitmap();

	return 0;
}

/*
			 #######
		#####      #
 #######      ######
 #                 #
 #                 #
 #            ######
 ###          #
	#####     #
		 ##   #
		   ###

*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	Seçerek sıralama (selection sort) algoritmasının iteratif yazımı
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void ssort(int *pi, size_t size)
{
	size_t i, k;
	size_t min_index;
	int min;

	for (i = 0; i < size - 1; ++i) {
		min_index = i;
		min = pi[i];
		for (k = i + 1; k < size; ++k)
			if (pi[k] < min) {
				min = pi[k];
				min_index = k;
			}
		pi[min_index] = pi[i];
		pi[i] = min;
	}
}

void disp(const int *pi, size_t size)
{
	size_t i;

	for (i = 0; i < size; ++i)
		printf("%d ", pi[i]);
	printf("\n");
}

#define SIZE		10

int main(void)
{
	int a[SIZE] = { 34, 12, 7, 84, 72, 39, 75, 45, 59, 21 };

	ssort(a, SIZE);
	disp(a, SIZE);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Seçerek sıralama algoritmasının özyinelemeli uygulanması (bu algoritma için özyineleme kötü bir teknik)
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void ssort(int *pi, size_t size)
{
	size_t max_index, i;
	int max;

	if (size == 1)
		return;

	max = pi[0];
	max_index = 0;

	for (i = 1; i < size; ++i)
		if (pi[i] > max) {
			max = pi[i];
			max_index = i;
		}

	pi[max_index] = pi[size - 1];
	pi[size - 1] = max;

	ssort(pi, size - 1);
}

void disp(const int *pi, size_t size)
{
	size_t i;

	for (i = 0; i < size; ++i)
		printf("%d ", pi[i]);
	printf("\n");
}

#define SIZE		10

int main(void)
{
	int a[SIZE] = { 34, 12, 7, 84, 72, 39, 75, 45, 59, 21 };

	ssort(a, SIZE);
	disp(a, SIZE);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	8 vezir problemi bir satranç tahtasına birbirini yemeyen 8 vezirin yerleştirilmesi problemidir. Özyinelemeli bir çözüm gerektirir. Tipik çözümde
	tahta global bir matris olarak organize edilir. İlk boş yere vezir yerleştirilir. Vezirin etki alanı matriste işaretlenir ve fonksiyon kendisini 
	çağırır. Böylece yeni çağrımda da ilk boş yer bulunup aynı şeyler yapılacaktır. Tahta dolduğunda fonksiyon sonlandırılır. 8 değeri elde edildiğinde
	tahta print edilir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

#define SIZE		8

int g_qcount;
int g_count;
char g_board[SIZE][SIZE];

void init_board(void)
{
	int r, c;

	for (r = 0; r < SIZE; ++r)
		for (c = 0; c < SIZE; ++c)
			g_board[r][c] = '.';
}

void print_board(void)
{
	int r, c;

	printf("%d\n", g_count);

	for (r = 0; r < SIZE; ++r) {
		for (c = 0; c < SIZE; ++c)
			printf("%c", g_board[r][c]);
		printf("\n");
	}
	printf("\n");
}

void locate_queen(int row, int col)
{
	int r, c;

	g_board[row][col] = 'V';

	r = row;
	for (c = col + 1; c < SIZE; ++c)
		g_board[r][c] = 'o';
	for (c = col - 1; c >= 0; --c)
		g_board[r][c] = 'o';
	c = col;
	for (r = row - 1; r >= 0; --r)
		g_board[r][c] = 'o';
	for (r = row + 1; r < SIZE; ++r)
		g_board[r][c] = 'o';
	for (r = row - 1, c = col - 1; r >= 0 && c >= 0; --r, --c)
		g_board[r][c] = 'o';
	for (r = row - 1, c = col + 1; r >= 0 && c < SIZE; --r, ++c)
		g_board[r][c] = 'o';
	for (r = row + 1, c = col - 1; r < SIZE && c >= 0; ++r, --c)
		g_board[r][c] = 'o';
	for (r = row + 1, c = col + 1; r < SIZE && c < SIZE; ++r, ++c)
		g_board[r][c] = 'o';
}

void queen8(int row, int col)
{
	char board[SIZE][SIZE];
	int r, c;

	for (; row < SIZE; ++row) {
		for (; col < SIZE; ++col) {
			if (g_board[row][col] == '.') {
				for (r = 0; r < SIZE; ++r)
					for (c = 0; c < SIZE; ++c)
						board[r][c] = g_board[r][c];

				++g_qcount;
				locate_queen(row, col);

				if (g_qcount == SIZE) {
					++g_count;
					print_board();
				}

				queen8(row, col);
				--g_qcount;

				for (r = 0; r < SIZE; ++r)
					for (c = 0; c < SIZE; ++c)
						g_board[r][c] = board[r][c];
			}
		}
		col = 0;
	}
}

int main(void)
{
	init_board();
	queen8(0, 0);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows'ta dizin ağacını dolaşan özyinelemeli fonksiyon
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void WalkDir(LPCSTR lpszPath)
{
	HANDLE hFF;
	WIN32_FIND_DATA wfd;

	if (!SetCurrentDirectory(lpszPath))
		return;

	if ((hFF = FindFirstFile("*.*", &wfd)) == INVALID_HANDLE_VALUE)
		return;

	do {
		if (!strcmp(wfd.cFileName, ".") || !strcmp(wfd.cFileName, ".."))
			continue;
		if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			printf("%s\n", wfd.cFileName);
			WalkDir(wfd.cFileName);
			if (!SetCurrentDirectory(".."))
				break;
		}

	} while (FindNextFile(hFF, &wfd));

	FindClose(hFF);
}

int main(void)
{
	WalkDir("f:\\Dropbox\\Kurslar\\SysProg-1");

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows'ta UNIX/Linux sistemlerinde olduğu gibi bazı dizinlere prosesin geçişh hakkı (yani SetCurrentDirectory yapma hakkı) olmayabilir. 
	Bu duurmu da rapor edebiliriz. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void PutErrMsg(LPCSTR lpszMsg);

void WalkDir(LPCSTR lpszPath)
{
	HANDLE hFF;
	WIN32_FIND_DATA wfd;

	if (!SetCurrentDirectory(lpszPath)) {
		PutErrMsg(lpszPath);
		return;
	}

	if ((hFF = FindFirstFile("*.*", &wfd)) == INVALID_HANDLE_VALUE)
		return;

	do {
		if (!strcmp(wfd.cFileName, ".") || !strcmp(wfd.cFileName, ".."))
			continue;
		if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			printf("%s\n", wfd.cFileName);
			WalkDir(wfd.cFileName);
			if (!SetCurrentDirectory("..")) {
				PutErrMsg("..");
				break;
			}
		}

	} while (FindNextFile(hFF, &wfd));

	FindClose(hFF);
}

void PutErrMsg(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}
}

int main(void)
{
	WalkDir("f:\\dropbox\\kurslar\\sysprog-1");

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Dizinleri dolaşırken onları kademeli bir biçimde ekrana yazdırdabiliriz. Geçemediğimiz dizinler :xxxx: biçiminde gösterilmiştir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define TABSIZE		4

void PutErrMsg(LPCSTR lpszMsg);

void WalkDir(LPCSTR lpszPath, int level)
{
	HANDLE hFF;
	WIN32_FIND_DATA wfd;

	if (!SetCurrentDirectory(lpszPath)) {
		printf("%*s:%s:\n", level * TABSIZE, "", lpszPath);
		return;
	}

	if ((hFF = FindFirstFile("*.*", &wfd)) == INVALID_HANDLE_VALUE)
		return;

	do {
		if (!strcmp(wfd.cFileName, ".") || !strcmp(wfd.cFileName, ".."))
			continue;
		if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			printf("%*s%s\n", level * TABSIZE, "", wfd.cFileName);
			WalkDir(wfd.cFileName, level + 1);
			if (!SetCurrentDirectory(".."))
				break;
		}
	} while (FindNextFile(hFF, &wfd));

	FindClose(hFF);
}

int main(void)
{
	WalkDir("c:\\", 0);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Yukarıdaki WalkDir fonksiyonlarında önemli bir kusur fonksiyonun prosesin çalışma dizinini değiştirerek işini sonlandırmasıdır. 
	Fonksiyonun çağrılmadan önceki çalışma dizinini yeniden set etmesi için bir sarma fonksiyon kullanılabilir. (access POSIX fonksiyonu
	Windows sistemlerinde _access ismiyle de bulunmaktadır.)
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <windows.h>

#define TABSIZE		4

void PutErrMsg(LPCSTR lpszMsg);

void WalkDirRecur(LPCSTR lpszPath, int level)
{
	HANDLE hFF;
	WIN32_FIND_DATA wfd;

	if (!SetCurrentDirectory(lpszPath)) {
		printf("%*s:%s:\n", level * TABSIZE, "", lpszPath);
		return;
	}

	if ((hFF = FindFirstFile("*.*", &wfd)) == INVALID_HANDLE_VALUE)
		return;

	do {
		if (!strcmp(wfd.cFileName, ".") || !strcmp(wfd.cFileName, ".."))
			continue;
		if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			printf("%*s%s\n", level * TABSIZE, "", wfd.cFileName);
			WalkDirRecur(wfd.cFileName, level + 1);
			if (!SetCurrentDirectory(".."))
				break;
		}

	} while (FindNextFile(hFF, &wfd));

	FindClose(hFF);
}

void WalkDir(LPCSTR lpszPath)
{
	char cwd[MAX_PATH];

	if (_access(lpszPath, 0)) {
		fprintf(stderr, "Path not found: %s\n", lpszPath);
		return;
	}

	if (!GetCurrentDirectory(MAX_PATH, cwd))
		PutErrMsg("GetCurrentDirectory");

	WalkDirRecur(lpszPath, 0);

	if (!SetCurrentDirectory(cwd))
		PutErrMsg("SetCurrentDirectory");
}

void PutErrMsg(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}
}

int main(void)
{
	WalkDir("f:\\dropbox\\kurslar\\sysprog-1");

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Dizin ağacını dolaşırken bulun dizin girişlerini ekrana yazdırmak yerine başka bir şey yapmak isteyebiliriz. Böyle bir fonksiyonun genelleştirilmesi
	için fonksiyon göstericilerinden faydalanılabilir. Aşağıdaki örnekte dizin ağacını dolaşan fonksiyon her dizin girişini bulduğunda call-back
	bir fonksiyon çağırmaktadır. Öağrılan bu fonksiyon TRUE ile geri döndüğünde dolaşıma devam edilmekte FALSE ile geri döndüğünde dolaşım sonlandırılarak
	çıkış sağlanmaktadır. Dizin ağacını dolaşan fonksiyon erken sonlanmışsa FALSE ile normal sonlanmışsa TRUE ile geri dönmektedir. Koddaki _access ve _strcmpi
	fonksiyonları standart olmayan fonksiyonlardır. Microsoft standart olmayan ve API fonksiyonu da olmayan fonksiyonları _ ile başlayarak isimlendirmektedir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <windows.h>

void PutErrMsg(LPCSTR lpszMsg);

BOOL WalkDirRecur(LPCSTR lpszPath, BOOL(*Proc)(const WIN32_FIND_DATA *, int), int level)
{
	HANDLE hFF;
	WIN32_FIND_DATA wfd;
	BOOL result;

	result = TRUE;
	if (!SetCurrentDirectory(lpszPath))
		return;

	if ((hFF = FindFirstFile("*.*", &wfd)) == INVALID_HANDLE_VALUE)
		return;

	do {
		if (!Proc(&wfd, level)) {
			result = FALSE;
			break;
		}

		if (!strcmp(wfd.cFileName, ".") || !strcmp(wfd.cFileName, ".."))
			continue;
		if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			if (!WalkDirRecur(wfd.cFileName, Proc, level + 1)) {
				result = FALSE;
				break;
			}

			if (!SetCurrentDirectory(".."))
				break;
		}

	} while (FindNextFile(hFF, &wfd));

	FindClose(hFF);

	return result;
}

BOOL WalkDir(LPCSTR lpszPath, BOOL(*Proc)(const WIN32_FIND_DATA *, int))
{
	char cwd[MAX_PATH];
	BOOL result;

	if (_access(lpszPath, 0)) {
		fprintf(stderr, "Path not found: %s\n", lpszPath);
		return;
	}

	if (!GetCurrentDirectory(MAX_PATH, cwd))
		PutErrMsg("GetCurrentDirectory");

	result = WalkDirRecur(lpszPath, Proc, 0);

	if (!SetCurrentDirectory(cwd))
		PutErrMsg("SetCurrentDirectory");

	return result;
}

void PutErrMsg(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}
}

BOOL Proc(const WIN32_FIND_DATA *wfd, int level)
{
	printf("%*s%s %s\n", level * 4, "", wfd->cFileName, wfd->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ? "<DIR>" : "");

	if (!_strcmpi(wfd->cFileName, "sample.c"))
		return FALSE;

	return TRUE;
}

int main(void)
{
	BOOL result;

	result = WalkDir("f:\\dropbox\\kurslar\\sysprog-1", Proc);

	printf("%s\n", result ? "\nFonksiyon ağacı tamamen dolaştı\n" : "Fonksiyon erken sonlandı\n");

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde dizin ağacının dolaşılması
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

void walkdir(const char *path)
{
	DIR *dir;
	struct dirent *ent;
	struct stat finfo;

	if (chdir(path) == -1)
		return;

	if ((dir = opendir(".")) == NULL)
		return;

	while ((ent = readdir(dir)) != NULL) {
		printf("%s\n", ent->d_name);

		if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, ".."))
			continue;

		if (lstat(ent->d_name, &finfo) == -1)
			continue;

		if (S_ISDIR(finfo.st_mode)) {
			walkdir(ent->d_name);
			if (chdir("..") == -1)
				break;
		}
	}

	closedir(dir);
}

int main(void)
{
	walkdir(".");

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Yukarıdaki programı kademeli yazacak hale getirebiliriz
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#define TABSIZE		4

void walkdir(const char *path, int level)
{
	DIR *dir;
	struct dirent *ent;
	struct stat finfo;

	if (chdir(path) == -1)
		return;

	if ((dir = opendir(".")) == NULL)
		return;

	while ((ent = readdir(dir)) != NULL) {
		printf("%*s%s\n", level * TABSIZE, "", ent->d_name);

		if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, ".."))
			continue;

		if (lstat(ent->d_name, &finfo) == -1)
			continue;

		if (S_ISDIR(finfo.st_mode)) {
			walkdir(ent->d_name, level + 1);
			if (chdir("..") == -1)
				break;
		}
	}

	closedir(dir);
}

int main(void)
{
	walkdir(".", 0);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Fonksiyonun prosesin çalışma dizinini geri set eden sarmalı biçimi şöyle olabilir
-------------------------------------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#define TABSIZE		4

void walkdir_recur(const char *path, int level)
{
	DIR *dir;
	struct dirent *ent;
	struct stat finfo;

	if (chdir(path) == -1)
		return;

	if ((dir = opendir(".")) == NULL)
		return;

	while ((ent = readdir(dir)) != NULL) {
		printf("%*s%s\n", level * TABSIZE, "", ent->d_name);

		if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, ".."))
			continue;

		if (lstat(ent->d_name, &finfo) == -1)
			continue;

		if (S_ISDIR(finfo.st_mode)) {
			walkdir_recur(ent->d_name, level + 1);
			if (chdir("..") == -1)
				break;
		}
	}

	closedir(dir);
}

void walkdir(const char *path)
{
	char cwd[4096];

	if (getcwd(cwd, 4096) == NULL)
		perror("getcwd");

	walkdir_recur(path, 0);

	if (chdir(cwd) == -1)
		perror("chdir");
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "wrong number of arguments!..\n");
		exit(EXIT_FAILURE);
	}

	walkdir(argv[1]);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Hizalama en çok bir dosyanın içerisindeki bilgilerin bir yapıya okunacağı zaman çıkar. Aşağıdaki örnekte eğer hizalama byte hizalamasına
	çekilmezse bimap dosyanın başlık kısmındaki bilgiler yapı elemanlarına tam orturmaz.
-------------------------------------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(1)

struct BITMAP_HEADER {
	char magic[2];			/* 2 byte */
	uint32_t size;			/* 4 byte */
	uint16_t reserved1;		/* 2 byte */
	uint16_t reserved2;		/* 2 byte */
	uint32_t dataloc;		/* 4 byte */
};

#pragma pack(4)

int main(void)
{
	FILE *f;
	struct BITMAP_HEADER bh;

	if ((f = fopen("test.bmp", "rb")) == NULL) {
		fprintf(stderr, "Cannot open file!..\n");
		exit(EXIT_FAILURE);
	}

	fread(&bh, sizeof(struct BITMAP_HEADER), 1, f);

	printf("Magic: %c%c\n", bh.magic[0], bh.magic[1]);
	printf("Size: %u\n", bh.size);
	printf("Bitmap Data Locatiion: %u\n", bh.dataloc);

	fclose(f);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Yapı elemanların sırası hizalama boşlukları üzerinde etkili olmaktadır. Derleyiciler hçbir zaman yapı elemanlarının yerlerini optimizasyon amacıyla
	değiştirmezler. (Çünkü C ve C++ standartlarınca yapıların elemanlarının ilk yazlan düşük adreste olacak biçimde ardışıl dizildiği belirtilmektedir. 
	Padding byte'lar kontrollü olduğu için ardışıllığı bozmamaktadır.)
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct SAMPLE1 {
	char a;
	int b;
	char c;
	int d;
};

struct SAMPLE2 {
	char a;
	char c;
	int b;
	int d;
};

int main(void)
{
	struct SAMPLE1 s;
	struct SAMPLE1 k;

	printf("%u\n", sizeof(s));
	printf("%u\n", sizeof(k));


	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Read only LFU Algoritmasını kullanan basit bir önbellek sisteminin gerçekleştirilmesi
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* filecache.h */

#ifndef FILECACHE_H_
#define FILECACHE_H_

/* Symbolic Constants */

#define LINE_SIZE               32
#define NCACHE_LINES            10
#define INITIAL_COUNT           2

#ifdef DEBUG
#define DEBUG_PRINT(fmt, ...)  fprintf(stderr, fmt, ## __VA_ARGS__)     
#else
#define DEBUG_PRINT(fmt, ...)       
#endif

/* Type Definitions */

typedef struct tagCACHELINE {
	char buf[LINE_SIZE];
	int blockno;
	size_t count;
} CACHE_LINE;

typedef struct tagCACHE {
	int fd;
	CACHE_LINE clines[NCACHE_LINES];
	size_t tcount;
} CACHE, *HCACHE;

/* Function Prototypes */

HCACHE open_file(const char *path, int flags);
int read_file(HCACHE hc, int blockno, void *buf);
int close_file(HCACHE hc);

#endif

/* filecahe.c */

#define DEBUG

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include "filecache.h"

#ifdef DEBUG
static void print_cline_counts(HCACHE hc);
#endif

static size_t select_line(HCACHE hc);

HCACHE open_file(const char *path, int flags)
{
	HCACHE hc;
	int i;

	if ((hc = (HCACHE)malloc(sizeof(CACHE))) == NULL)
		return NULL;

	if ((hc->fd = open(path, flags)) == -1) {
		free(hc);
		return NULL;
	}

	for (i = 0; i < NCACHE_LINES; ++i) {
		hc->clines[i].blockno = -1;
		hc->clines[i].count = 0;
	}
	hc->tcount = 0;

	return hc;
}

int read_file(HCACHE hc, int blockno, void *buf)
{
	int i;
	int rline;

	for (i = 0; i < NCACHE_LINES; ++i)
		if (hc->clines[i].blockno == blockno) {
			DEBUG_PRINT("Cache hit block %d, used cache line %d\n", blockno, i);

			memcpy(buf, hc->clines[i].buf, LINE_SIZE);
			++hc->clines[i].count;
			++hc->tcount;

#ifdef DEBUG
			print_cline_counts(hc);
#endif

			return 0;
		}

	rline = select_line(hc);

	if (lseek(hc->fd, (off_t)blockno * LINE_SIZE, SEEK_SET) == -1)
		return -1;
	if (read(hc->fd, hc->clines[rline].buf, LINE_SIZE) == -1)
		return -1;
	hc->clines[rline].blockno = blockno;

	hc->clines[rline].count = hc->tcount / NCACHE_LINES + 1;
	hc->tcount += hc->clines[rline].count;

	memcpy(buf, hc->clines[rline].buf, LINE_SIZE);

	DEBUG_PRINT("Cache miss block %d, used cache line %d\n", blockno, rline);

#ifdef DEBUG
	print_cline_counts(hc);
#endif

	return 0;
}

int close_file(HCACHE hc)
{
	close(hc->fd);

	DEBUG_PRINT("Cache closed!\n");

	free(hc);
}

static size_t select_line(HCACHE hc)
{
	size_t min_count;
	size_t min_index;
	int i;

	min_count = hc->clines[0].count;
	min_index = 0;

	for (i = 1; i < NCACHE_LINES; ++i) {
		if (hc->clines[i].count < min_count) {
			min_count = hc->clines[i].count;
			min_index = i;
		}
	}

	return min_index;
}

#ifdef DEBUG

static void print_cline_counts(HCACHE hc)
{
	int i;

	putchar('\n');
	printf("Total count: %llu\n", (unsigned long long)hc->tcount);
	for (i = 0; i < NCACHE_LINES; ++i)
		printf("Cachle Line %d --> Block: %d, Count: %llu\n", i, hc->clines[i].blockno, (unsigned long long)hc->clines[i].count);

	putchar('\n');
}

#endif

/* filecache-test.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include "filecache.h"

int create_test_file(const char *path, int nblocks);

int main(int argc, char *argv[])
{
	HCACHE hc;
	char buf[32 + 1];
	int blockno;

#ifdef CREATE
	if (create_test_file("test.dat", 100) == -1) {
		perror("create_test_file");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
#endif

	if ((hc = open_file("test.dat", O_RDONLY)) == NULL) {
		fprintf(stderr, "cannot open file!..\n");
		exit(EXIT_FAILURE);
	}

	for (;;) {
		printf("Block No:");
		scanf("%d", &blockno);
		putchar('\n');
		if (blockno == -1)
			break;

		if (read_file(hc, blockno, buf) == -1) {
			perror("read_file");
			exit(EXIT_FAILURE);
		}
		buf[32] = '\0';
		printf("Block content: %s\n\n", buf);
	}

	close_file(hc);


	return 0;
}

int create_test_file(const char *path, int nblocks)
{
	FILE *f;
	int i, k;
	char buf[LINE_SIZE];

	srand(time(NULL));
	if ((f = fopen(path, "wb")) == NULL)
		return -1;

	for (i = 0; i < nblocks; ++i) {
		sprintf(buf, "%04d ", i);
		for (k = 5; k < 32; ++k)
			buf[k] = rand() % 26 + 'A';

		if (fwrite(buf, LINE_SIZE, 1, f) != 1)
			return -1;
	}

	fclose(f);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
    Büyük bir dosyayı Windows'ta ReadFile API fonksiyonuyla, UNIX/Linux sistemlerinde read fonksiyonuyla byte bu-yte okumak iyi bir teknk
    değildir. Çünkü böyle bir uygulamada proses her defasında sistem fonksiyonun çağrılması nedeni ile "kernel moda" geçecektir. Aşaüıda
    POSIX sistemlerinde 5 MB civarı bir dosya read fonksiyonuyla byte byte okunmuş ve bu işlemin ne kadar zaman aldığı hesaplanmıştır.
    Apple Macbook Pro M1 SOC'un kullanıldığı MAc OS X sistemlerinde bu zaman yaklaşık 1.45 saniye civarındadır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

void exit_sys(const char *msg);

int main(void)
{
    int fd;
    char ch;
    ssize_t result;
    size_t count;
    clock_t t1, t2;
    double ts;

    t1 = clock();

    if ((fd = open("/Users/KaanAslan/Study/SysProg/test.dat", O_RDONLY)) == -1)
        exit_sys("open");

    while ((result = read(fd, &ch, 1)) > 0)
        ;
    if (result == -1)
        exit_sys("read");

    close(fd);

    t2 = clock();

    ts = (double)(t2 - t1) / CLOCKS_PER_SEC;

    printf("Elapsed time: %f\n", ts);

    return 0;
}

void exit_sys(const char *msg)
{
    perror(msg);

    exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
    C'nin standart dosya fonksiyonları her açılan dosya için bir önbellek oluşturmaktadır. Böylece biz dosyaan okuma yaptığımızda aslında standart C fonksiyonları
    POSIX read fonksiyonunu ya da Windows'un ReadFile fonksiyonunu çağırıp bu önbelleği doldurmaktadır. Sonraki okumalarda yeniden bu fonksiyonları
    çağırmadan mümkğn olduğunca bize isteğimiz bilgileri hızlı bir biçimde önbellekten vermektedir. Buradaki önbelleğe C dünyasında "tampon (bug-ffer)"
    da denilmektedir. Bu tamponlamanın (yani önbellek sisteminin) amacı işletim sisteminin sistem fonksiyonlarının daha az çağrılmasını sağlamaktır.
    Bu önbellek sistemini işletim sisteminin oluşturduğu disk önbellek sistemi ile karıştırmayınız.İşletim sistemi diske erişimi azaltmak için önbeellek sistemi
    oluştururken standart C fonksiyonlarının önbellek sistemi işletim sisteminin sistem fonksiyonlarının daha az çağrılmasını sağlamaktadır.

    Aşağıdaki kodda aynı dosya (5 MB civarında) bu kez standart fgetc fonksiyonuyla byte buyte okunmuşturi Ortalama zaman 0.1 saniye civarındadır.
    Bu da işlemin 15 kat daha hızlı yapıldığı anlamına gelmektedir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    FILE *f;
    int ch;
    clock_t t1, t2;
    double ts;

    t1 = clock();

    if ((f = fopen("/Users/KaanAslan/Study/SysProg/test.dat", "rb")) == NULL) {
        fprintf(stderr, "Cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(f)) != EOF)
        ;

    fclose(f);

    t2 = clock();

    ts = (double)(t2 - t1) / CLOCKS_PER_SEC;

    printf("Elapsed time: %f\n", ts);

    return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
    C'nin stdio fonksiyonları read/write bir cache (tampon) kullanmaktadır. Dolayısıyla bizim dosyaya yazdığımız şeyler aslında tampona yazılmaktadır.
    Bu tampon da ya başka bilgi tampona aktarılırken dosyaya yazılır ya da fflush işlemi sırasında dosyaya yazılır. exit standart C fonksiyonu
    prosesi sonlandırmadan önce fopen ile açılmış olamn bütün dosyaları fclose ile kapatmaktadır. fclose ise dosyayı önce fflsuh ile flush eder.
    Aşağıdaki örnekte proses standart exit fonksiyonuyla değil POSIX'in _exit fonksiyomuyla sonlandırılmıştır. Dolayısıyşla dosyaya yazılanlar
    flush edilemeyecektir.

    Biz C'de hiç exit fonksiyonunu çağırmasak biel zaten main bitince exit fonksiyonu çağrılmaktadır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(void)
{
    FILE *f;

    if ((f = fopen("test.txt", "w")) == NULL) {
        fprintf(stderr, "Cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    fputc('a', f);
    fputc('b', f);
    fputc('\n', f);

    _exit(0);

    return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	fdopen isimli POSIX fonksiyonun kullanımı
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void exit_sys(const char *msg);

int main(int argc, char *argv[])
{
	int fd;
	ssize_t result;
	FILE *f;
	char buf[10 + 1];
	int ch;

	if ((fd = open("test.txt", O_RDONLY)) == -1)
		exit_sys("open");

	if ((result = read(fd, buf, 10)) == -1)
		exit_sys("read");

	buf[result] = '\0';
	printf("read ile okunan byte'lar: %s\n", buf);

	if ((f = fdopen(fd, "r")) == NULL) {
		fprintf(stderr, "cannot open file!..\n");
		exit(EXIT_FAILURE);
	}

	while ((ch = fgetc(f)) != EOF)
		putchar(ch);

	if (ferror(f)) {
		fprintf(stderr, "cannot read file!..\n");
		exit(EXIT_FAILURE);
	}

	fclose(f);

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	setbuf fonksiyonu dosya için ayrılan tamponun yerini değiştirmek için kullanılmaktadır. Bu fonksiyon tamponun boyutunu değiştirmez, BUFSIZ 
	büyüklüğündeki tamponun yerini değiştirir. Fakat bu fonksiyon aynı zamanda ikinci parametre iin NULL adres girilirse dosyayı sıfır tamponlamalı 
	(no buffered) moda da sokmaktadır. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void disp_hex(const void *buf, size_t size, size_t lbytes)
{
	size_t i, k, remainder;
	unsigned char *cbuf = (unsigned char *)buf;

	for (i = 0; i < size; ++i) {
		if (i % lbytes == 0)
			printf("%08x ", (unsigned int)i);

		printf("%02X ", cbuf[i]);

		if (i % lbytes == lbytes - 1) {
			for (k = 0; k < lbytes; ++k)
				printf("%c", iscntrl(cbuf[i - lbytes + k]) ? '.' : cbuf[i - lbytes + k]);
			putchar('\n');
		}
	}

	remainder = size % lbytes;
	for (k = 0; k < 3 * (lbytes - remainder); ++k)
		putchar(' ');

	for (k = 0; k < remainder; ++k)
		printf("%c", iscntrl(cbuf[i - remainder + k]) ? '.' : cbuf[i - remainder + k]);
	putchar('\n');
}

int main(void)
{
	FILE *f;
	char buf[BUFSIZ];

	if ((f = fopen("test.txt", "r+")) == NULL) {
		fprintf(stderr, "cannot open file!..\n");
		exit(EXIT_FAILURE);
	}

	setbuf(f, buf);

	fgetc(f);

	disp_hex(buf, BUFSIZ, 16);

	printf("---------------------------------------------\n");

	fputc('x', f);
	disp_hex(buf, BUFSIZ, 16);

	fclose(f);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	setvbuf fonksiyonu setbuf fonksiyonundan daha yeteneklidir. Çünkü bu fonksiyonla biz hem tamponun yerini, hem büyüklüğünü hem de tamponlama stratejisini
	değiştrebiliriz. Aşağıdaki örnekte dosyanın tampon 64 byte'a düşürülmüştür ve dosya Line buffered moda sokulmuştur. Her ne kadar line buffered modda
	tampon bir satır kadar bilgiyle dolduruluyorsa da kütüphaneler yine okuma sırasında tamponun tamamını doldurabilmektedir. Ancak yazma sırasında kesinlikle
	'\n' karakteri tampona yazıldığında tampon tazelenir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void disp_hex(const void *buf, size_t size, size_t lbytes)
{
	size_t i, k, remainder;
	unsigned char *cbuf = (unsigned char *)buf;

	for (i = 0; i < size; ++i) {
		if (i % lbytes == 0)
			printf("%08x ", (unsigned int)i);

		printf("%02X ", cbuf[i]);

		if (i % lbytes == lbytes - 1) {
			for (k = 0; k < lbytes; ++k)
				printf("%c", iscntrl(cbuf[i - lbytes + k]) ? '.' : cbuf[i - lbytes + k]);
			putchar('\n');
		}
	}

	remainder = size % lbytes;
	for (k = 0; k < 3 * (lbytes - remainder); ++k)
		putchar(' ');

	for (k = 0; k < remainder; ++k)
		printf("%c", iscntrl(cbuf[i - remainder + k]) ? '.' : cbuf[i - remainder + k]);
	putchar('\n');
}

int main(void)
{
	FILE *f;
	char buf[64] = { '\0' };

	if ((f = fopen("test.txt", "r+b")) == NULL) {
		fprintf(stderr, "cannot open file!..\n");
		exit(EXIT_FAILURE);
	}

	setvbuf(f, buf, _IOLBF, 64);
	fgetc(f);

	disp_hex(buf, 64, 16);

	fclose(f);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Klavye ve ekran "terminal aygıt sürücüsü" biçiminde isimlendirilen bir aygıt sürücü tarafından kontrol edilmektedir. Dolayısıyla aslında biz 
	ekrana bir şey yazmak istediğimizde bu aygıt sürücüyü açıp ona bir şeyler yazarız. Bizim aygıt sürücüye yazdığımız şeyleri aygıt sürücü ekrana yazdırmaktadır. 
	Aynı durum klavyeden okuma yaparken de söz konusudur. Aşağıda Linuz sistemlerinde pseudo terminal aygıt sürücü yoluyla açılıp bir şeyler yazılmıştır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void exit_sys(const char *msg);

int main(int argc, char *argv[])
{
	int fd;

	if ((fd = open("/dev/pts/0", O_WRONLY)) == -1)
		exit_sys("open");

	write(fd, "ankara", 6);

	close(fd);

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde bir proses yaratıldığında aten 0, 1 ve 2 numaralı betimleyiciler açık bir biçimde proses başlar. 0 numaralı betimleyici
	terminale ilişkin aygıt sürücüsünü girdi elde etmek için, 1 numaralı dosya betimleyicisi çıktı oluşturmak için temsil etmektedir. 2 numaralı betimleyici
	de stderr dosyasını temsil eder. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void exit_sys(const char *msg);

int main(void)
{
	char buf[4096];
	ssize_t result;

	if ((result = read(0, buf, 1024)) == -1)
		exit_sys("read");

	if (write(1, buf, result) == -1)
		exit_sys("write");

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Benzer biçimde Windows'ta da bir proses yaratıldığında terminal aygıt sürücülerine ilişkin dosya HANDLE değerleri işletim sistemi düzeyinde 
	elde edilmiş durumdadır. Ancak burada bu handle değerleri POSIX sistemlerindeki gibi baştan belli değildir. GetStdHandle API fonksiyonuyla bunlar
	elde edilmektedir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	HANDLE hStdin, hStdout;
	char buf[4096];
	DWORD dwRead, dwWritten;

	if ((hStdin = GetStdHandle(STD_INPUT_HANDLE)) == INVALID_HANDLE_VALUE)
		ExitSys("GetStdHandle");

	if ((hStdout = GetStdHandle(STD_OUTPUT_HANDLE)) == INVALID_HANDLE_VALUE)
		ExitSys("GetStdHandle");

	if (!ReadFile(hStdin, buf, 4096, &dwRead, NULL))
		ExitSys("ReadFile");

	if (!WriteFile(hStdout, buf, dwRead, &dwWritten, NULL))
		ExitSys("WriteFile");

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	C'nin Stdio ktüphenesinin yazımı için bir ipucu (tam bitilmiş bir kod değil)
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* csd_stdio.h */

#ifndef CSD_STDIO_H_
#define CSD_STDIO_H_

#define CSD_EOF         -1
#define CSD_BUFSIZ      5

#include <sys/types.h>

typedef struct {
	int fd;
	unsigned char *beg;    /* starting buffer address */
	size_t size;   		  /* buffer size */
	size_t count; 		  /* number of bytes in the buffer */
	unsigned char *pos;    /* current buffer address */
	off_t offset;  		  /* file offset */
	int dirty;
	int error;
	int eof;
	/* .... */
} CSD_FILE;

CSD_FILE *csd_fopen(const char *path, const char *mode);
int csd_fgetc(CSD_FILE *f);

#endif

/* csd_stdio.c */

#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "csd_stdio.h"

static ssize_t refresh_buffer(CSD_FILE *f);

CSD_FILE *csd_fopen(const char *path, const char *mode)
{
	CSD_FILE *f;
	int i;
	static char *modes[] = { "r", "r+", "w", "w+", "a", "a+", "rb", "r+b", "wb", "w+b", "ab", "a+b", NULL };
	static int flags[] = { O_RDONLY, O_RDWR, O_WRONLY | O_CREAT | O_TRUNC, O_RDWR | O_CREAT | O_TRUNC, O_WRONLY | O_CREAT | O_APPEND,
		O_WRONLY | O_CREAT | O_APPEND, O_WRONLY | O_CREAT | O_APPEND };

	if ((f = (CSD_FILE *)malloc(sizeof(CSD_FILE))) == NULL)
		return NULL;

	for (i = 0; modes[i] != NULL; ++i)
		if (!strcmp(mode, modes[i]))
			break;

	if (modes[i] == NULL) {
		free(f);
		return NULL;
	}

	if ((f->fd = open(path, flags[i % 6], S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1) {
		free(f);
		return NULL;
	}

	if ((f->beg = (unsigned char *)malloc(CSD_BUFSIZ)) == NULL) {
		free(f);
		return NULL;
	}

	f->size = CSD_BUFSIZ;
	f->count = 0;
	f->pos = NULL;
	f->offset = 0;
	f->dirty = 0;
	f->error = 0;

	return f;
}

static ssize_t refresh_buffer(CSD_FILE *f)
{
	ssize_t result;

	if (f->dirty) {
		if (lseek(f->fd, f->offset, SEEK_SET) == -1)
			return -1;
		if (write(f->fd, f->beg, f->pos - f->beg) == -1)
			return -1;
	}

	if (lseek(f->fd, f->offset + f->count, SEEK_SET) == -1)
		return -1;

	if ((result = read(f->fd, f->beg, f->size)) == -1)
		return -1;

	f->pos = f->beg;
	f->offset = f->offset + f->count;
	f->count = result;

	return result;
}

int csd_fgetc(CSD_FILE *f)
{
	ssize_t result;

	if (f->pos == NULL || f->pos == f->beg + f->count) {
		if ((result = refresh_buffer(f)) == -1) {
			f->error = 1;
			return CSD_EOF;
		}

		if (result == 0) {
			f->eof = 1;
			return CSD_EOF;
		}
	}

	return *f->pos++;
}

int csd_ferror(CSD_FILE *f)
{
	return f->error;
}

/* sample.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "csd_stdio.h"

void exit_sys(const char *msg);

int main(void)
{
	CSD_FILE *f;
	int ch;

	if ((f = csd_fopen("test.txt", "r")) == NULL) {
		fprintf(stderr, "cannot open file!..\n");
		exit(EXIT_FAILURE);
	}

	ch = csd_fgetc(f);
	putchar(ch);

	while ((ch = csd_fgetc(f)) != CSD_EOF)
		putchar(ch);

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	freopen standart C fonksiyonu stdin, stdout ve stderr dosyalarını (ve diğer dosyaları da) yönlendirmek için kullanılabilmektedir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *f;
	int i;

	if ((f = freopen("test.txt", "w", stdout)) == NULL) {
		fprintf(stderr, "Cannot open file!..\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < 10; ++i)
		printf("%d\n", i);

	fclose(f);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	freopen ile stdin dosyasının yönlendirilmesi
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *f;
	int i;
	int val;

	if ((f = freopen("test.txt", "r", stdin)) == NULL) {
		fprintf(stderr, "Cannot open file!..\n");
		exit(EXIT_FAILURE);
	}

	while (scanf("%d", &val) == 1)
		printf("%d\n", val);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerindeki C derleyicilerinde stdout dosyası default durumda satır tamponlamalı moddadır. Halbuki Windows sistemlerindeki C derleyici
	lerinde sıfır tamponlamalı moddadır. Bu nedenle aşağıdaki programda "ankara" yazısı UNIX/Linux sistemlerinde görülmeyecek ancak Windows sistemlerinde
	görülecektir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main(void)
{
	printf("ankara");

	for (;;)
		;
	
	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Tabii biz fflush fonksiyonuyla stdout dosyasını tazaleyebiliriz. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main(void)
{
	printf("ankara");
	fflush(stdout);

	for (;;)
		;
		
	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	En kötü olasılıkla stdout satır tamponlamalı olacağına göre aşağıdaki kodda her zaman "ankara" yazısı ekranda görüntülecenektir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main(void)
{
	printf("ankara\n");

	for (;;)
		;
		
	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	stdin dosyası işletim sistemlerinden dolayı genellikle default durumda ya da sonradan sıfır tamponlamalı moda sokulamamaktadır. Bu nedenle
	Windows sistemlerinde ve UNIX/Linux sistemlerinde stdin satır tamponlamalıdır. Yani bir stdin dosyasından bir karaleter bile okumak istesek
	eğer tampon doluysa bize bu karakter tampon verilir. Eğer tampon boş ise bizden bir satırlık bilgi istenir. Tampondaki satırın 
	sonunda '\n' karakteri de bulnmaktadır. Dolsyısıyla aşağıdaki kodda ikinci getchar klavyeden giriş beklemez. Tampondaki '\n' karakterini alarak 
	geri döner. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main(void)
{
	int ch;
	
	ch = getchar();
	printf("%c (%d)", ch, ch);

	ch = getchar();
	printf("%c (%d)", ch, ch);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	stdin tamponunu başaltabilen standart bir fonksiyon yoktur. Dolayısıyla programcının bunu bir fonksiyon ya da makroyla yapması gerekir. 
	Aşağıda böyle bir fonksiyon görülmektedir. Fonksiyondaki EOF konntrolü program bazı uç durumlarda gerekebilmektedir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void clear_stdin(void)
{
	int ch;

	while ((ch = getchar()) != '\n' && ch != EOF)
		;
}

int main(void)
{
	int ch;

	ch = getchar();
	printf("%c\n", ch);
	
	clear_stdin();
	
	ch = getchar();
	printf("%c\n", ch);
	
	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Yukarıdaki clear_stdin bir makro olarak da yazılabilirdi
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

#define clear_stdin()			\
do {							\
		int ch;					\
								\
	} while ((ch = getchar()) != '\n' && ch != EOF)	

int main(void)
{
	int ch;

	ch = getchar();
	printf("%c\n", ch);
	
	clear_stdin();
	
	ch = getchar();
	printf("%c\n", ch);
	
	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	İstersek işin başında stdout dosyasının da default tapmonlama modunu setbuf ya da setvbuf fonksiyonlarıyla değiştirebiliriz. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	
	printf("ali");

	for (;;)
		;

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	gets fonksiyonun gerçekleştirimi
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

char *mygets(char *str)
{
	int ch;
	size_t i;

	for (i = 0; (ch = getchar()) != '\n' && ch != EOF; ++i)
		str[i] = ch;

	if (i == 0 && ch == EOF)
		return NULL;

	str[i] = '\0';

	return str;
}

int main(void)
{
	char s[100];
	
	mygets(s);
	puts(s);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	C11'de gets fonksiyonu kaldırılmış ve yerine isteğe bağlı biimde gets_s fonksiyonu eklenmiştir. gets_s Microsoft derleyicilerinde zaten uzun süredir
	bulunmaktadır. Ancak gcc ve clang'ın kullandığı glibc kütüphanesinde bu fonksiyon bulunmamaktadır. Aşağıda bu fonksiyonun gerçekleştirimi yapılmıştır. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

char *mygets_s(char *str, size_t size)
{
	size_t i;
	int ch;

	for (i = 0; i < size - 1; ++i) {
		if ((ch = getchar()) == '\n' || ch == EOF)
			break;
		str[i] = ch;
	}

	if (i == 0 && ch == EOF)
		return NULL;

	str[i] = '\0';

	return str;
}

int main(void)
{
	char s[10];
	
	mygets_s(s, 10);
	puts(s);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	gets_s yeri,ne fgets fonksiyonu aşağıdaki gibi kullanılabilir
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[10];
    char *str;

    if ((str = fgets(s, 10, stdin)) != NULL)
        if ((str = strchr(s, '\n')) != NULL)    
            *str = '\0';

    if (str != NULL)        
        puts(s);

    return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Önce getchar, sonra gets kullanırken stdin tamponun boşaltılması gerekebilir
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void empty_stdin(void)
{
	int ch;

	while ((ch = getchar()) != '\n' && ch != EOF)
		;
}

int main(void)
{
	int ch;
	char name[512];

	printf("Bir karakter giriniz:");
	fflush(stdout);

	ch = getchar();
	empty_stdin();

	printf("Bir isim giriniz:");
	fflush(stdout);

	gets(name);

	printf("'%c' - \"%s\"\n", ch, name);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Tabii önce gets sonra getchar kullanılıyor olsaydı tamponu boşaltmaya gerek kalmazdı
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main(void)
{
	int ch;
	char name[512];

	printf("Bir isim giriniz:");
	fflush(stdout);
	gets(name);

	printf("Bir karakter giriniz:");
	fflush(stdout);
	ch = getchar();

	printf("'%c' - \"%s\"\n", ch, name);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	scanf fonksiyonu ile menü oluştururken geçirsiz girişlerin ele alınması örneği
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void empty_stdin(void)
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
}

int disp_menu(void)
{
	int option;

	printf("1) Ara\n");
	printf("2) Sil\n");
	printf("3) Çıkış\n\n");
	
	printf("Seçiminiz:");

	if (scanf("%d", &option) == 0) {
		empty_stdin();
		return 0;
	}

	return option;
}

int main(void)
{
	int option;

	for (;;) {
		option = disp_menu();

		switch (option) {
			case 1:
				printf("Aranıyor\n\n");
				break;
			case 2:
				printf("Siliniyor\n\n");
				break;
			case 3:
				goto EXIT;
			default:
				printf("Geçersiz giriş!\n\n");
		}
	}
EXIT:
	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	scanf fonksiyonunda format karakterleri arasındaki karakterlerin girişlerde mutlaka bulundurulması gerekir. Format karakterlerindeki herhangi bir 
	boşluk karakteri "boşluk karakteri görmeyene kadar stdin'den okuma yap ve onları at" anlamına gelmektedir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main(void)
{
	int day, month, year;

	printf("Tarihi dd/mm/yy biçiminde giriniz:");
	scanf("%d/%d/%d", &day, &month, &year);

	printf("%d-%d-%d\n", day, month, year);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	scanf fonksiyonunun baştaki boşluk karakterlerini (leading space) attığına, ancak sondakileri (trailing space) atmadığına dikkat edniz. 
	Bu durumda scanf fonksiyonundan sonra gets, getchar gibi fonksiyonları kullanmadan önce stdin tamponun boşaltılması gerekebilir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void empty_stdin(void)
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
}

int main(void)
{
	int no;
	char name[120];

	printf("No:");
	scanf("%d", &no);

	empty_stdin();	

	printf("Adı soyadı:");
	gets(name);

	printf("No: %d, Name: %s\n", no, name);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	EOF görene kadar scanf ile okuma yapan bir örnek
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main(void)
{
	int val;

	while (scanf("%d", &val) != EOF) 
		printf("%d\n", val);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	getenv standart C fonksiyonu ile bir çevre değişkeninin değerinin elde eidlmesi
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *val;

	if ((val = getenv("PATH")) == NULL) {
		fprintf(stderr, "Environment variable not found!..\n");
		exit(EXIT_FAILURE);
	}

	printf("%s\n", val);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows sistemlerinde çevre değişkenini elde eden asıl fonksiyon GetEnvironmentVariable isimli API fonksiyonudur. Aslında
	getenv bu sistemlerde bu API fonksiyonunu çağırmaktadır. UNIX/Linux sistemlerinde ise gerçekten asıl fonksiyon getenv fonksiyonudur.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define SIZE	4096

int main(void)
{
	char val[SIZE];
	DWORD dwResult;

	if ((dwResult = GetEnvironmentVariable("PATH", val, SIZE)) == 0 && GetLastError() == ERROR_ENVVAR_NOT_FOUND) {
		fprintf(stderr, "Environment variable not found!..\n");
		exit(EXIT_FAILURE);
	}

	if (dwResult > SIZE) {
		fprintf(stderr, "Insufficient buffer!..\n");
		exit(EXIT_FAILURE);
	}

	printf("%s\n", val);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde setenv fonksiyonu ile prosesin çevre değişkeni değiştirilebilir, ekleme yapılabilir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

void exit_sys(const char *msg);

int main(void)
{
	char *env;

	if (setenv("CITY", "Ankara", 1) == -1)
		exit_sys("setenv");

	if ((env = getenv("CITY")) == NULL) {
		fprintf(stderr, "cannot get environment variable!..\n");
		exit(EXIT_FAILURE);
	}
	puts(env);

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX(Linux sistemlerinde puenv isimli bir POSIX fonksiyonu da vardır. Bu fonksiyon Windows sistemlerinde _putenv ismiyle de bulunmaktadır. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

void exit_sys(const char *msg);

int main(void)
{
	char *env;

	if (putenv("CITY=Ankara") == -1)
		exit_sys("putenv");

	if ((env = getenv("CITY")) == NULL) {
		fprintf(stderr, "cannot get environment variable!..\n");
		exit(EXIT_FAILURE);
	}
	puts(env);

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows sistemlerinde çevre değişkenini set eden asıl fonksiyon SetEnvironmentVariable isimli API fonksiyonudurç
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define SIZE	4096

int main(void)
{
	char val[SIZE];
	DWORD dwResult;

	if (!SetEnvironmentVariable("CITY", "Ankara")) {
		fprintf(stderr, "Cannot set environment variable!..\n");
		exit(EXIT_FAILURE);
	}

	if ((dwResult = GetEnvironmentVariable("CITY", val, SIZE)) == 0 && GetLastError() == ERROR_ENVVAR_NOT_FOUND) {
		fprintf(stderr, "Environment variable not found!..\n");
		exit(EXIT_FAILURE);
	}

	if (dwResult > SIZE) {
		fprintf(stderr, "Insufficient buffer!..\n");
		exit(EXIT_FAILURE);
	}

	printf("%s\n", val);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde prosesin tüm çevre değişkenlerini elde edebilmek için environ isimli global göstericiyi gösteren göstericiden 
	faydalanılmaktadır. Bu göstericinin maalesef extern bildirimi herhangi bir başlık dosyasında yoktur.
-------------------------------------------------------------------------------------------------------------------------------------------*/

int main(void)
{
	int i;

	for (i = 0; environ[i] != NULL; ++i)
		puts(environ[i]);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows sistemlerinde GetEnvironmentStrings isimli API fonksiyonu çevre değişken listesini tek bir adresle 
	Anahtar=Değer\0Anahtar=Değer\0Anahtar=Değer\0\0
	biçiminde vermektedir. Söz konusu çevre değişken bloğu istenirse FreeEnvironmentStrings API fonksiyonuyla boşaltılabilir.
	(Yani bu fonksiyon çağrıldıktan sonra artık proseste çevre değişkeni kalmaz.)
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main(void)
{
	LPCH envStr;

	if ((envStr = GetEnvironmentStrings()) == NULL) {
		fprintf(stderr, "Cannot get environment strings!..\n");
		exit(EXIT_FAILURE);
	}

	while (*envStr != '\0') {
		puts(envStr);
		envStr += strlen(envStr) + 1;
	}

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Çevre değişkenleri sayesinde programlar kullanıcı tarafından ayarlanabilen çeşitli belirlemeleri kullanabilir. Aşağıdaki örnekte program
	"x.dat" isimli bir dosyayı DATADIR isimli bir çevre değişkeninin bulunduğu yerde aramamaktadır. Eğer bu çevre değişkeni yoksa dosya 
	prosesin çalışma dizininde arayacaktır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define DATAFILE		"x.dat"

int main(void)
{
	char *val;
	char path[4096];
	FILE *f;

	if ((val = getenv("DATADIR")) != NULL)
		sprintf(path, "%s/%s", val, DATAFILE);
	else
		sprintf(path, "./%s", DATAFILE);

	if ((f = fopen(path, "rb")) == NULL) {
		fprintf(stderr, "cannot open data file!..\n");
		exit(EXIT_FAILURE);
	}
	printf("Ok\n");

	/* ... */

	fclose(f);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows sistemlerinde proses yaratmak için (yani bir programı çalıştırabilmek için) CreateProcess isimli API fonksiyonu kullanılmaktadır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* Prog1.c */

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	char szPath[] = "Prog2 ali veli selami";
	char env[] = "ALI=10\0Veli=20\0";
	STARTUPINFO si = { sizeof(STARTUPINFO) };
	PROCESS_INFORMATION pa;

	if (!CreateProcess(NULL, szPath, NULL, NULL, TRUE, 0, env, "c:\\windows", &si, &pa))
		ExitSys("CreateProcess");

	printf("Ok\n");

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastError = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/* Prog2.c */

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main(int argc, char *argv[])
{
	LPCH envStr;
	char cwd[MAX_PATH];
	int i;

	printf("Command line arguments:\n");

	for (i = 0; i < argc; ++i)
		puts(argv[i]);

	printf("Current Woring Directory:\n");

	GetCurrentDirectory(MAX_PATH, cwd);
	printf("%s\n", cwd);

	printf("Environment Variables:\n");

	if ((envStr = GetEnvironmentStrings()) == NULL) {
		fprintf(stderr, "Cannot get environment strings!..\n");
		exit(EXIT_FAILURE);
	}

	while (*envStr != '\0') {
		puts(envStr);
		envStr += strlen(envStr) + 1;
	}

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	CreateProcess fonksiyonun birinci parametresi NULL geçilirse ikinci parametre boşluk karakterleriyle parse edildiğinden zaten boşluk karakteri içeren 
	dizinlerde sorun ortaya çıkar. Bu nedenle böylesi durumlarda ikinci parametredeki yazının tırnaklanması gerekmektedir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	char szPath[] = "\"C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe\" csystem.org cumhuriyet.com\"";
	STARTUPINFO si = { sizeof(STARTUPINFO) };
	PROCESS_INFORMATION pa;

	if (!CreateProcess(NULL, szPath, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pa))
		ExitSys("CreateProcess");

	printf("Ok\n");

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastError = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Tabii birinci parametre NULL geçilmedikten sonra bu tırnaklamanın birinci parametre için yapılmasına gerek yoktur
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	char szPath[] = "C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe\" csystem.org cumhuriyet.com";
	STARTUPINFO si = { sizeof(STARTUPINFO) };
	PROCESS_INFORMATION pa;

	if (!CreateProcess("C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe", szPath, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pa))
		ExitSys("CreateProcess");

	printf("Ok\n");

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastError = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows sistemlerinde HANDLE türüyle belirtilen tüm nesnelere (dosyalara, thread'lere, proseslere vs.) "kernel nesneleri" denilmektedir. 
	Tüm kernel nesneleri prosese özgü "proses handle tablosu" denilen bir tabloda giriş belirtmektedir. Tüm kernel nesnelerinin yok edilmesi (ya da
	kapatılması) CloseHandle isimli API fonksiyonu ile yapılmaktadır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	char szPath[] = "notepad.exe";
	STARTUPINFO si = { sizeof(STARTUPINFO) };
	PROCESS_INFORMATION pa;

	if (!CreateProcess(NULL, szPath, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pa))
		ExitSys("CreateProcess");

	CloseHandle(pa.hProcess);
	CloseHandle(pa.hThread);

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastError = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	ShellExecute fonksiyonu katman olarak bir shell fonksiyonudur. Dolayısıyla aslında kendi içerisinde CreateProcess fonksiyonunu çağırmaktadır.
	ShellExecute exeutable olmayan bir dosyayı da parametre olarak alabilir. Onun ilişkili olduğu executable dosyayı CreateProcess ile çalıştırıp
	söz konusu dosyayı da ona komut satırı argümanı olarak vermektedir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	HINSTANCE hInstance;

	hInstance = ShellExecute(NULL, "open", "C:\\Users\\CSD\\Desktop\\playlist.csv", NULL, NULL, SW_NORMAL);
	if ((int)hInstance < 32)
		ExitSys("ShellExecute");

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastError = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows sistemlerinde EnumProcess API fonksiyonuyla sistemde o anda bulunan proseslerin ID değerlerinin elde edilmesi
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <Psapi.h>

#define NPROC_IDS		1000

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	DWORD dwProcessIds[NPROC_IDS];
	DWORD dwNeeded;
	DWORD i;

	if (!EnumProcesses(dwProcessIds, sizeof(dwProcessIds), &dwNeeded))
		ExitSys("EnumProcesses");

	for (i = 0; i < dwNeeded / sizeof(DWORD); ++i)
		printf("%lu\n", (unsigned long)dwProcessIds[i]);

	printf("%lu process Ids listed...\n", dwNeeded / sizeof(DWORD));

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastError = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}
/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows sistemlerinde o anda sistemdeki proses listesini isimsel biçimde almak için önce Process OpenProcess fonksiyonuyla ID verilerek açılır. 
	Buradan bir HANDLE değeri elde edilir. Sonra bu handle değeri kullanılarak EnumProcessModules fonksiyonuyla prosesin modül listesi elde edilir. 
	Prosese ilişkin .exe ve dll dosyalarına modül denilmektedir. Prosesin ilk modülü her zaman exe dosya olmak zorundadır. Bu işlemlerden modülü temsil 
	eden HMODULE biçiminde bir handle elde edilir. Sonra da GetModuleBaseName fonksiyonuyla modülün ismi elde edilmektedir. 32 bit prosesler 64 bit proseslerin
	modül listesini okuyamamaktadır. Bu nedenle aşağıdaki programı 64 Windows sistemlerinde 64 bir uygulama olarak derleyiniz. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <Psapi.h>

#define NPROC_IDS		1000
#define NMODULES		1000
#define MAX_NAME		1024

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	DWORD dwProcessIds[NPROC_IDS];
	DWORD dwNeeded, dwProcessCount, dwModuleCount;
	DWORD i, k;
	HANDLE hProcess;
	HMODULE hModules[NMODULES];
	char szModuleName[MAX_NAME];
	DWORD listedCount = 0;

	if (!EnumProcesses(dwProcessIds, sizeof(dwProcessIds), &dwNeeded))
		ExitSys("EnumProcesses");

	dwProcessCount = dwNeeded / sizeof(DWORD);
	for (i = 0; i < dwProcessCount; ++i) {
		if ((hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, dwProcessIds[i])) == NULL) 
			continue;
		if (!EnumProcessModules(hProcess, hModules, sizeof(hModules), &dwNeeded)) 
			continue;
		++listedCount;
		dwModuleCount = dwNeeded / sizeof(DWORD);
		for (k = 0; k < dwModuleCount; ++k) {
			if (!GetModuleBaseName(hProcess, hModules[k], szModuleName, MAX_NAME)) 
				continue;
			if (k == 0)
				printf("%s%s", szModuleName, dwModuleCount > 1 ? ": " : "");
			else if (k != 1)
				printf(", ");
		    printf("%s", szModuleName);
		}
		printf("\n\n");
		CloseHandle(hProcess);
	}

	printf("%lu process Ids listed...\n", listedCount);

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastError = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Eskiden Windows'un 3'lü versiyonlarında işletim sistemi tamamen ASCII yazılarla çalışıyordu. Sonra 90'lı yılların ortalarında Windows'un
	32 bit versiyonları çıktığında kernel'ı hem ASCII hem de UNICODE'u destekleyecek biçimde değiştirdiler. Bütün yazı parametresi alan API
	fonksiyonları A'lı ve W'lu iki ayrı versyion olarak yazıldı. Yani bugün aslında CreateFile diye bir API fonksiyonu yoktur. CreateFileA ya da 
	CreateFileW isimli bir API fonksiyonu vardır. CreateFile ismi yerine windows.h içerisindeki makro aslında bunu UNICODE isimli sembolik sabit define
	edilmişse CreateFileW biçimine, edilmemişse CreateFileA biçimine dönüştürmektedir. İşte yazı parametresi alan API fonksiyonun ismi
	XXXXX olmak üzere aslında XXXXX isimli bir API fonksiyonu yoktur. XXXXXA ya da XXXXXW biçiminde API fonksiyonları vardır. Ancak programcılar
	kodlarında genellikle XXXXX isimlerini kullanırlar. Dönüştürmeyi önişlemciye yaptırırlar. Böylece eski kodlar da hiç değiştirilmeden yeni duruma
	uyum sağlamış olur. Pekiyi bu UNICODE sembolik sabiti ne zaman ve kim tarafından define edilmektedir. İşte proje ayarlarından karakter set UNICODE
	yapılmışsa bu sembolik sabit define edilmiş kabul edilir. Eğer karakter set UNICODE yapılmamışsa bu sembolik sabit define edilmemiş durumdadır. 
	Tüm makrolar bu sembolik sabite bakmaktadır. 

	Bir Windows programını UNICODE uyumlu yazmak demek karakter set ayarı değiştirildiğinde kodda değiştirilecek hiçbir şeyin olmaması demektir. 
	Programı UNICODE uyumlu yazabilmek için şunlara dikkat etmek gerekir:

	1) Program içerisindeki tüm string'ler TEXT makrosuyle kullanılmalıdır. Çünkü bu makro UNICODE sembolik sabitine bakarak string'i "..." 
	biçiminde string ya da L"...." biçiminde string haline dönüştürür. 

	2) char türü yerine TCHAR isimli typedef türünün kullanılması gerekir. Çünkü TCHAR duruma göre char ya da wchar_t türü olarak typedef edilmektedir.

	3) LPCSTR const char * anlamına LPSTR ise char * anlamına gelir. Bunların UNICODE versiyonları LPCWSTR ve LPWSTR biçimindedir. Ancak T li versiyonlar
	yine UNICODE sembolik sabitine bağlı olarak char * ya da wchar_t * türünden olmaktadır. Bu nedenle yazılara ilişkin gösteri parametreleri
	ya TCHAR *, const TCHAR * biçiminde ya da LPTSTR, LPCTSTR biçiminde belirtilmelidir. 

	4) Standart C fonksiyonları için de aynı durum söz konusudur. Örneğin ASCII programlarda printf kullanılırken UNICODE programlarda wprintf 
	kullanılmaktadır. Ancak uyumlu printf ismi için yine <tchar.h> dosyası içerisindeki _xxx biçimindeki özel fonksiyon isimleri kullanılır. 
	Her standart C fonksiyonun Windows sistemlerindeki UNICODE ismi bilinmelidir. Örneğin _tprintf printf fonksiyonun UNICODE uyumlu ismidir. 
	Bu isim UNICODE sembolik sabiti define edilmişse wprintf olarak, edilmemişse printf olarak değiştirilmektedir. main fonksiyonun argv parametresine de 
	dikkat etmek gerekir. Onun  da TCHAR biçiminde ifade eidlmesi gerekir. 

	Yukarıdaki programın UNICODE uyumlu versiyonu aşağıdaki gibi yazılabilir
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <Psapi.h>
#include <tchar.h>

#define NPROC_IDS		1000
#define NMODULES		1000
#define MAX_NAME		1024

void ExitSys(LPCTSTR lpszMsg);

int main(void)
{
	DWORD dwProcessIds[NPROC_IDS];
	DWORD dwNeeded, dwProcessCount, dwModuleCount;
	DWORD i, k;
	HANDLE hProcess;
	HMODULE hModules[NMODULES];
	TCHAR szModuleName[MAX_NAME];
	DWORD listedCount = 0;

	if (!EnumProcesses(dwProcessIds, sizeof(dwProcessIds), &dwNeeded))
		ExitSys(TEXT("EnumProcesses"));

	dwProcessCount = dwNeeded / sizeof(DWORD);
	for (i = 0; i < dwProcessCount; ++i) {
		if ((hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, dwProcessIds[i])) == NULL)
			continue;
		if (!EnumProcessModules(hProcess, hModules, sizeof(hModules), &dwNeeded))
			continue;
		++listedCount;
		dwModuleCount = dwNeeded / sizeof(DWORD);
		for (k = 0; k < dwModuleCount; ++k) {
			if (!GetModuleBaseName(hProcess, hModules[k], szModuleName, MAX_NAME))
				continue;
			if (k == 0)
				_tprintf(TEXT("%s%s"), szModuleName, dwModuleCount > 1 ? TEXT(": ") : TEXT(""));
			else if (k != 1)
				_tprintf(TEXT(", "));
			_tprintf(TEXT("%s"), szModuleName);
		}
		_tprintf(TEXT("\n\n"));
		CloseHandle(hProcess);
	}

	_tprintf(TEXT("%lu process Ids listed...\n"), listedCount);

	return 0;
}

void ExitSys(LPCTSTR lpszMsg)
{
	DWORD dwLastError = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		_ftprintf(stderr, TEXT("%s: %s"), lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde fork isimli POSIX fonksiyonu yeni bir proses yaratmak için kullanılmaktadır. Yeni proses yaratmanın başka bir
	yolu da yoktur. fork kendi içerisinde yaratılacak proses için yeni bir proses proses kontrol bloğu oluşturur. Üst prosesin proses kontrol bloğu
	bilgilerin yeni yarattığı alt proses kontrol bloğuna kopyalar. Üst prosesin bellek alanın tamamının alt proses için bir kopyasından oluşturur.
	Her iki proses de farklı iki akış olarak fork fonksiyonundan çıkar. Ancak üst proses geri dönüş değeri olarak alt prosesin id değeri ile, 
	alt proses ise 0 değeri ile fork fonksiyonundan çıkmaktadır. Dolayısıyla geçmişleri aynı olan ancak gelecekleri farklı olabilecek olan iki proses 
	söz konusu olmaktadır. fork başarısız da olabilir. Bu durumda -1 değerine geri döner. 

	Aşağıda tipik bir fork uygulama kalıbı görülmektedir
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void exit_sys(const char *msg);

int main(void)
{
	pid_t pid;

	if ((pid = fork()) == -1)
		exit_sys("fork");

	if (pid != 0) {
		printf("Parent process running...\n");
	}
	else {
		printf("Child process running...\n");
	}

	printf("common code...\n");

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	fork işleminden sonra artık üst proses ile alt proses arasında hiçbir bağlantı kalmamıştır. Dolayısıyla birinin yaptığı bir şey diğerini etkilemez. 
	Örneğin aşağıdaki kodda üst proses g_a globalk değişkenine 100 değerini atamıştır ancak bu g_a kendi kopyasındaki g_a'dır. Dolayısıyla alt proses
	bu g_a nesnesinin değerini değişmiş görmez.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void exit_sys(const char *msg);

int g_a;

int main(void)
{
	pid_t pid;

	if ((pid = fork()) == -1)
		exit_sys("fork");

	if (pid != 0) {
		printf("Parent process running...\n");
		g_a = 100;
	}
	else {
		printf("Child process running...\n");
		sleep(5);
		printf("%d\n", g_a);		/* 0 çıkacak */
	}

	printf("common code...\n");

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Aşağıdaki kodda toplam 8 tane"running" yazısı çıkacaktır
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void exit_sys(const char *msg);

int main(void)
{
	pid_t pid;

	if ((pid = fork()) == -1)
		exit_sys("fork");

	if ((pid = fork()) == -1)
		exit_sys("fork");

	if ((pid = fork()) == -1)
		exit_sys("fork");

	printf("running\n");

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Başka program dosyasını çalıştırabilmek için UNIX/Linux sistemlerinde exec fonksiyonları kullanılmaktadır. exec fonksiyonları bir aile belirtir.
	Aslında bu fonksiyonların hepsi aynı işlemleri biraz değişik parametrelerle yapmaktadır. exec ailesi 7 farklı fonksiyon vardır: 
	execl, execlp, execv, execvp, execle, execvpe ve execve. Aslında yalnızca execve bir sistem fonksiyonu olarak gerçekleştirilmiştir. Diğer exec 
	fonksiyonları kütüphane fonksiyonlarıdır ve nihayetinde execve fonksiyonunu çağırmaktadır. 

	exec fonksiyonları prosesin bellek alanını boşaltıp başka bir programı dosyasını o bellek alanına yükleyip onu çalıştırmaktadır. exec fonksiyonları
	proses yaratmaz. Mevcut prosesin başka bir kodla çalışmaya devam etmesini sağlar. Yani exec işlemi yapıldığında artık exec yapan kod yok olacak
	exec işleminde belirilen program kodu çalıştırılacaktır. Ancak exec işlemi proses kontrol bloğunu değiştirmez. Dolayısıyla prosesin id'si, etkin kullanıcı
	id'si, etkin grup id'si, çalışma dizini vs. aynı olarak kalacaktır. 

	execl fonksiyonu komut satır argümanlarını tek tek bir liste olarak almaktadır. Argüman listesinin sonuna (char *) NULL biçiminde NULL adres 
	girilmelidir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void exit_sys(const char *msg);

int main(void)
{
	printf("program running...\n");

	if (execl("/bin/ls", "/bin/ls", "-l", "-i", (char *)NULL) == -1)
		exit_sys("execl");

	printf("unreachable code!..\n");

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Tek başına fork bir prosesin özdenş kopyasını oluştup çalıştırmaktadır. Tek başına exec ise programın başka bir kodla çalışmasını sağlamaktadır.
	O halde hem üst prosesin kodu çalışsın hem de başka bir programın kodu çalışsın isteniyorsa fork ve exec birlikte kullanılmalıaıdır. Yani
	önce bir kez fork yapılır. Alt proseste exec uygulanır. Aşağıda tipik fork/exec kalıbını görüyorsunuz. Microsoft sistemlerinde zaten CreateProcess
	fonksiyonun yeni bir prosesi başka bir kodla çalıştırdığına dikkat ediniz. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void exit_sys(const char *msg);

int main(void)
{
	pid_t pid;
	int i;

	printf("program running...\n");

	if ((pid = fork()) == -1)
		exit_sys("fork");

	if (pid == 0)
		if (execl("/bin/ls", "/bin/ls", "-l", "-i", (char *)NULL) == -1)
			exit_sys("execl");

	for (i = 0; i < 10; ++i) {
		printf("%d\n", i);
		sleep(1);
	}

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Aslında fork exec kalıbı && operatörü ile de uygulanabilir
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void exit_sys(const char *msg);

int main(void)
{
	pid_t pid;
	int i;

	printf("program running...\n");

	if ((pid = fork()) == -1)
		exit_sys("fork");

	if (pid == 0 && execl("/bin/ls", "/bin/ls", "-l", "-i", (char *)NULL) == -1)
		exit_sys("execl");

	for (i = 0; i < 10; ++i) {
		printf("%d\n", i);
		sleep(1);
	}

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Aşağıdaki örnekte sample programı mample programını çalıştırmıştır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* sample.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void exit_sys(const char *msg);

int main(void)
{
	pid_t pid;

	printf("sample running...\n");

	if ((pid = fork()) == -1)
		exit_sys("fork");

	if (pid == 0 && execl("mample", "mample", "ali", "veli", "selami", (char *)NULL) == -1)
		exit_sys("execl");

	printf("sample ending...\n");

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/* mample.c */

#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;

	printf("mample running...\n");

	for (i = 0; i < argc; ++i)
		printf("%s\n", argv[i]);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	execv (v vector'den geliyor fonksiyonu execl (l list'ten geliyor)fonksiyonun komut satırı argümanlarını tek tek değil de bir gösterici dizisi 
	biçiminde tek bir parametreyle alan biçimidir. Yani çalıştırılacak programın komut satırı argümanları char türünden bir gösterici dizisine yerleşltirilip 
	bu dizinin adresi execv fonksiyonuna verilir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void exit_sys(const char *msg);

int main(void)
{
	pid_t pid;
	char *args[] = { "/bin/ls", "-l", "-i", NULL };
	int i;

	printf("program running...\n");

	if ((pid = fork()) == -1)
		exit_sys("fork");

	if (pid == 0 && execv("/bin/ls", args) == -1)
		exit_sys("execl");

	for (i = 0; i < 10; ++i) {
		printf("%d\n", i);
		sleep(1);
	}

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Bazen execv fonksiyonu daha uygun olabilmektedir. Örneğin komut satırı argümanıyla aldığımız bir propgramı çalıştırmak istesek execl 
	işimizi çok zorlaştıracaktır. Burada execv çok daha uygundur. Aşağıdaki programda komut satırı argümanlarıyla alınan program çalıştırılmaktadır.
	Programın sonunda wait fonksiyonu kullanılmıştır. Bu fonksiyon ileride ele alınacaktır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void exit_sys(const char *msg);

int main(int argc, char *argv[])
{
	pid_t pid;

    if (argc < 2) {
        fprintf(stderr, "wrong number of arguments!..\n");
        exit(EXIT_FAILURE);
    }

    if ((pid = fork()) == -1)
        exit_sys("fork");

    if (pid == 0 && execv(argv[1], &argv[1]) == -1)
        exit_sys("execv");

    if (wait(NULL) == -1)
        exit_sys("wait");
        
	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	exec fonksiyonlarının p'li versiyonları eğer dosya yol ifadesinde hiiç '/' karakteri yoksa ilgili dosyayı PATH çevre değişkeni ile belirtilen 
	dizinlerde tek tek aramaktadır. Eğer dosyanın yol ifadesinde en az bir '/' karakteri varsa bu durumda dosya belirtilen yol ifadesinde aranır.
	Yani bu durumda exec fonksiyonlarının p'li versiyonlarıyla p'siz versiyonları arasında bir fark olmaz.
	Aşağıdaki program yukarıdaki programın aynısıdır. Yalnızca execv yerine execvp kullanılmıştır. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void exit_sys(const char *msg);

int main(int argc, char *argv[])
{
	pid_t pid;

    if (argc < 2) {
        fprintf(stderr, "wrong number of arguments!..\n");
        exit(EXIT_FAILURE);
    }

    if ((pid = fork()) == -1)
        exit_sys("fork");

    if (pid == 0 && execvp(argv[1], &argv[1]) == -1)
        exit_sys("execv");

    if (wait(NULL) == -1)
        exit_sys("wait");

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Aslında UNIX/Linux sistemlerindeki shell programlarındaki komutların çok büyük çoğunluğu çalıştırılabilir dosyalardır. Yani örneğin ls 
	komutu aslında /bin/ls programıdır, cat komutu aslında /bin/cat programıdır. Çok az sayıda "internal" komut vardır. Bunlardan biri cd
	komutudur. Zaten cd komutu bir program olarak yazılamazdı. Eğer cd bir program olsaydı üst prosesin çalışma dizinini değil (yani shell'in)
	kendi prosesinin çalışma dizinini değiştirirdi. Hiçbir bir proses üst prosesinin çalışma diziinini değiştirememektedir.
	Aşağıda daha önce yzmış olduğumuz basit shell programının biraz daha geliştirilmiş bir biçimi vardır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define PROMPT					"CSD>"
#define MAX_CMD_LINE			4096
#define MAX_CMD_PARAMS			64
#define MAX_PATH                4096

struct CMD {
	char *cmd_text;
	void (*proc)(void);
};

void parse_cmd_line(void);
void proc_cd(void);

char g_cmd_line[MAX_CMD_LINE];
struct CMD g_cmds[] = {
    {"cd", proc_cd},
	{NULL, NULL},
};

char *g_params[MAX_CMD_PARAMS];
int g_nparams;

int main(void)
{
	char *str;
    pid_t pid;
    char cwd[MAX_PATH];
	int i;

	for (;;) {
        if (getcwd(cwd, MAX_PATH) == NULL) {
            perror("getcwd");
            exit(EXIT_FAILURE);
        }

		printf("%s>", cwd);
		fgets(g_cmd_line, MAX_CMD_LINE, stdin);
		if ((str = strchr(g_cmd_line, '\n')) != NULL)
			*str = '\0';

		parse_cmd_line();
		if (g_nparams == 0)
			continue;
		if (!strcmp(g_params[0], "exit"))
			break;
		for (i = 0; g_cmds[i].cmd_text != NULL; ++i)
			if (!strcmp(g_cmds[i].cmd_text, g_params[0])) {
				g_cmds[i].proc();
                goto NEXT_CMD;	
			}
	
        if ((pid = fork()) == -1)
            perror("fork");
        if (pid == 0 && execvp(g_params[0], &g_params[0]) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }

        if (wait(NULL) == -1) {
            perror("wait");
            exit(EXIT_FAILURE);
        }
    NEXT_CMD:
        ;
	}

	return 0;
}

void parse_cmd_line(void)
{
	char *str;

	g_nparams = 0;
	for (str = strtok(g_cmd_line, " \t"); str != NULL; str = strtok(NULL, " \t"))
		g_params[g_nparams++] = str;
	g_params[g_nparams] = NULL;
}

void proc_cd(void)
{
    char *env;

    if (g_nparams == 1) {
        if ((env = getenv("HOME")) == NULL) {
            perror("getenv");
            return;
        }
        if (chdir(env) == -1)
            perror("chdir");

        return;
    }

    if (g_nparams > 2) {
        fprintf(stderr, "too many arguments!..\n");
        return;
    }

    if (chdir(g_params[1]) == -1)
        perror("chdir");
}
/*------------------------------------------------------------------------------------------------------------------------------------------
	execle fonksiyonu tamamen execl fonksiyonu gibidir. Ancak fazladan bir parametresi vardır. Bu parametre çevre değişken listesini bir gösterici 
	dizisi biçiminde almaktadır. Böylelikle fork işlemiyle üst prosesten aktarılan çevre değişkenleri exec yapılırken değiştirilebilmektedir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* sample .c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void exit_sys(const char *msg);

int main(void)
{
	pid_t pid;
    char *env[] = {"city=eskişehir", "plaka=26", NULL};

	if ((pid = fork()) == -1)
		exit_sys("fork");

	if (pid == 0 && execle("mample", "mample", "ali", "veli", "selami", (char *)NULL, env) == -1)
		exit_sys("execl");

    if (wait(NULL) == -1)
        exit_sys("wait");

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/* mample.c */

#include <stdio.h>

extern char **environ;

int main(int argc, char *argv[])
{
	int i;

	printf("Command line arguments:\n");

	for (i = 0; i < argc; ++i)
		printf("%s\n", argv[i]);

    printf("Environment Variables:\n");

    for (i = 0; environ[i] != NULL; ++i)
        puts(environ[i]);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Aslında UNIX/Linux sistemlerinde genel olarak yalnızca execve bir sistem fonksiyonu olarak kernel içerisinde bulundurulmuştur. Diğer exec 
	fonksiyonları user mod fonksiyonlardır. Çeşitli düzenlemeleri yaptıktan sonra execve fonksiyonu çağırmaktadır. execve fonksiyonu komut satırı
	argümanlarını ve çevre değişkenleribi gösterici dizisi biçiminde bizden ister. Aşağıda bir execve kullanımı görülmektedir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* sample.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void exit_sys(const char *msg);

int main(void)
{
	pid_t pid;
    char *args[] = {"./mample", "mample", "ali", "veli", "selami", NULL};
    char *env[] = {"city=eskişehir", "plaka=26", NULL};

	if ((pid = fork()) == -1)
		exit_sys("fork");

	if (pid == 0 && execve("./mample", args, env) == -1)
		exit_sys("execve");

    if (wait(NULL) == -1)
        exit_sys("wait");

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/* mample.c */

#include <stdio.h>

extern char **environ;

int main(int argc, char *argv[])
{
	int i;

	printf("Command line arguments:\n");

	for (i = 0; i < argc; ++i)
		printf("%s\n", argv[i]);

    printf("Environment Variables:\n");

    for (i = 0; environ[i] != NULL; ++i)
        puts(environ[i]);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	exec fonksiyonları ile aslında çalıştırılabilir olmayan dosyalar da (örneğin text dosyalar) çalıştırılmak istenebilir. Bu durumda exec 
	fonksiyonları ilgili dosyayı açıp onun ilk iki karakterine bakmaktadır. Eğer dosyada ilk iki karakter #! biçimindeyse bu karakterlere
	shebang denilmektedir. shebang karakterlerini gerçek çalıştırılabilir bir dosya izlemektedir. İşte exec fonksiyonları burada belirtilen dosyayı
	çalıştırılar. Çalıştırdıkları dosyaya da exec yapılan dosyayı komut satır argümanı olarak yollarlar. Aslında bilindiği gibi UNIX/Linux sistemlerinde
	yalnızca execve fonksiyonu bir kernel sistem fonksiyonu olarak gerçekleştirilmiştir. Bu shebang kontrolü kernel tarafından bu execve içerisinde
	yapılmaktadır. execve burada belirtilen çalıştılabilir dosyayı bir yol ifadesi olarak kabul eder. Genel olarak buradaki dosyanın mutlak yol ifadesi belirtmesi
	istenmektedir. Ancak bugünkü sistemler göreli yol ifadelerini de kabul etmektedir. Buradaki dosya execve tarafından PATH çevre değişkenine bakılmadan
	doğrudan ele alınmaktadır. Burada belirtilen dosyadan sonra yazılan komut satırı argümanları buradaki çalıştırılabilen dosyaya tek bir komut satırı
	argümanı biçiminde aktarılmaktadır. exec fonksiyonlarının kendisinde belirtilen belirtilen argümanlar ise son argümanlar olarak kullanılırlar.

	Aşağıdaki örnekte bir shebang mekanizması uygulnamıştır. sample.c programı komut satırı argümanlarıyla alınan dosyayı execv ile çalıştırır. Bu dosya
	test.txt dosyası biçiminde örnekte girilecektir. Bu dosyanın başında da shebag olarak mample çalıştırılabilir dosyaı bulunmaktadır. mample programı
	kendi komut satırı argümanlarını ekrana yazdırmaktadır. Buradaki sample programının şöyle çalıştırıldığını varsayalım:

	./sample test.txt xxx yyy

	test.txt dosyasındakş shebang kısmı da şöyle olsun:


	#! mample ali veli selami

	Bu durumda mample ekrana şunları basmaktadır:

	/home/csd/Study/SysProg-2020/mample
	ali veli selami
	test.txt
	xxx
	yyy

	Ne olursa olsun exec yapılan dosya shebang içeren text bir dosya olsa bile onun da x özelliklerine sahip olması gerekir. Çünkü exec fonksiyonları
	bunu kontrol etmektedir. Bir dosyaya x hakları vermenin en pratik yolu şöyledir:

	chmod +x test.txt

-------------------------------------------------------------------------------------------------------------------------------------------*/

/* sample.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void exit_sys(const char* msg);

int main(int argc, char* argv[])
{
	pid_t pid;

	if (argc == 1) {
		fprintf(stderr, "wrong number of arguments!..\n");
		exit(EXIT_FAILURE);
	}

	if ((pid = fork()) == -1)
		exit_sys("fork");

	if (pid == 0 && execv(argv[1], &argv[1]) == -1)
		exit_sys("execv");

	if (wait(NULL) == -1)
		exit_sys("wait");

	return 0;
}

void exit_sys(const char* msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/* mample.c */

#include <stdio.h>

int main(int argc, char* argv[])
{
	int i;

	for (i = 0; i < argc; ++i)
		puts(argv[i]);

	return 0;
}

test.txt

#! mample ali veli selami

/*------------------------------------------------------------------------------------------------------------------------------------------
	shebang kullanımının en önemli faydası script dosyalarının sanki çalıştırılabilir bir dosya gibi çalıştırılmasını sağlamaktır. Örneğin aşağidaki
	python programı shebag sayesinde bağımısız bir program gibi komut satırından çalıştırılabilecektir.

	Windows sistemlerinde shebang gibi bir kullanım yoktur. benzer işlemler dosya ilişkilendirmesi yoluyla yapılmaktadır. ShellExecute fonksiyonun 
	dosya ilişkilendirmesine baktığını biliyorsunuz.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#! /usr/bin/python3

for i in range(10) :
	print(' {}'.format(i))

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows sistemlerinde prosesin sonlandırılması aslında ExitProcess API fonksiyonuyla yapılmaktadır. Bu sistemlerde exit isimli standart C 
	fonksiyonu stdio dosyalarını kapatıp birtakım son işlemeri yaptıktan sonra ExitProcess API fonksiyonu çağırır. Prosesin exit kodu proses sonlandığında
	proses kontrol bloğunda saklanır. O kodu prosesi çalıştıran üst proses GetExitCodeProcess API fonksiyonuyla almaktadır. Proseslerin exit kodlarının 
	kaç olacağının işletim sistemi tarafından bir önemi yoktur. İşletim sistemi yalnızca sonlanan proseslerin exit kodlarını saklar. Üst proses isterse ona verir.
	Dolayısıyla diğer semantik üst ve alt proseslerin kendi aralarında oluşturulmalıdır. Ancak yine de gelenek bakımından düzgün sonlanmış bir proses için
	exit kod 0, problemli sonlanmış proses için sıfır dışı bir değer tercih edilmektedir. Zaten <stdlib.h> dosyasındaki EXIT_SUCESS ve EXIT_FAILURE
	0 ve 1 olarak define edilmiştir. 

	Aşağıda Prog1isimli program Prog2 isimli programı çalıştırıp onun exit kodunu elde etmektedir. Program UNICODE uyumlu bir biçimde yazılmıştır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* Prog1.c */

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <tchar.h>

void ExitSys(LPCTSTR lpszMsg);

int main(void)
{
	TCHAR szPath[] = TEXT("Prog2");
	STARTUPINFO si = { sizeof(STARTUPINFO) };
	PROCESS_INFORMATION pa;
	DWORD dwExitCode;

	if (!CreateProcess(NULL, szPath, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pa))
		ExitSys(TEXT("CreateProcess"));

	_tprintf("Press ENTER to continue...\n");
	getchar();

	if (!GetExitCodeProcess(pa.hProcess, &dwExitCode))
		ExitSys("GetExitCodeProces");

	_tprintf(TEXT("Process Exit Code: %lu\n"), (unsigned long)dwExitCode);

	return 0;
}

void ExitSys(LPCTSTR lpszMsg)
{
	DWORD dwLastError = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		_ftprintf(stderr, TEXT("%s: %s"), lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/* Prog2.c */

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <tchar.h>

int main(void)
{
	_tprintf(TEXT("Prog2 running...\n"));

	exit(100);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	wait fonksiyonu ilk sonlanacak olab alt prosesi bekler. Onun exit kodunu alır. Sonlanan alt prosesin proses id değeri ile geri döner. 
	wait başarısızlık durumunda -1 değeriyle geri dönmektedir. wait alt prosesin yalnızca ezit kodunu değil onun neden sonlanmış olduğu bilgisini de
	elde etmektedir. Üç makro önemlidir: WIFEXITED, WIFSIGNALED ve WEXITSTATUS. Yalnızca normal sonlanan yani WIFEXITED sıfır dışı değerini veren proseslerin
	exit kodları oluşmaktadır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* sample */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void exit_sys(const char *msg);

int main(void)
{
	pid_t pid, pid_wait;
	int status;

	if ((pid = fork()) == -1)
		exit_sys("fork");

	if (pid == 0 && execl("mample", "mample", (char *)NULL) == -1)
		exit_sys("execl");

	printf("parent creates child with process id %lld\n", (long long)pid);

	if ((pid_wait = wait(&status)) == -1)
		exit_sys("wait");

	printf("parent waited child with process id %lld\n", (long long)pid_wait);
	if (WIFEXITED(status))
		printf("Child exit code: %d\n", WEXITSTATUS(status));
	else
		printf("child exited abnormally!..\n");

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/* mample.c */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("mample running...\n");

	exit(100);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Tabii eğer üst proses birden fazla kez fork yapmışsa üst proses de birden fazla kez wait yapmalıdır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void exit_sys(const char *msg);

int main(void)
{
	pid_t pid, pid_wait;
	int status;
	int i;

	if ((pid = fork()) == -1)
		exit_sys("fork");

	if (pid == 0) {
		sleep(2);
		exit(1);
	}

	if ((pid = fork()) == -1)
		exit_sys("fork");

	if (pid == 0) {
		sleep(1);
		exit(2);
	}

	if ((pid = fork()) == -1)
		exit_sys("fork");

	if (pid == 0) {
		sleep(3);
		exit(3);
	}

	for (i = 0; i < 3; ++i) {
		if ((pid_wait = wait(&status)) == -1)
			exit_sys("wait");
		printf("parent waited child with process id %lld\n", (long long)pid_wait);
		if (WIFEXITED(status))
			printf("Child exit code: %d\n", WEXITSTATUS(status));
		else
			printf("child exited abnormally!..\n");
	}

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	waitpid fonksiyonu wait fonksiyonunun daha yetenekli bir biçimidir. waitpid herhangi bir alt prosesi spesifik olarak bekleyebilir. 
	waitpid(-1, &status, 0) ile wait(&status) çağrıları eşdeğerdir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* sample.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void exit_sys(const char *msg);

int main(void)
{
	pid_t pid, pid_wait;
	int status;

	if ((pid = fork()) == -1)
		exit_sys("fork");

	if (pid == 0 && execl("mample", "mample", (char *)NULL) == -1)
		exit_sys("execl");

	printf("parent creates child with process id %lld\n", (long long)pid);

	if ((pid_wait = waitpid(pid, &status, 0)) == -1)
		exit_sys("wait");

	printf("parent waited child with process id %lld\n", (long long)pid_wait);
	if (WIFEXITED(status))
		printf("Child exit code: %d\n", WEXITSTATUS(status));
	else
		printf("child exited abnormally!..\n");

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/* mample.c */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("mample running...\n");

	exit(100);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde üst proses alt prosesi yaratıp onu wait fonksiyonları ile beklemezse alt proses bittiğinde onun kontrol bloğu 
	sisteme iade edilmez. Böyle böyle proseslere "zombie" prosesler denir. Zombie prosesler ps -l komutunda görüleblmektedir. Eğer üst proses
	alt prosesten daha önce sonlanırsa bu durumda init prosesi (proses id'si 1) alt prosesin üst prosesi yapılır. Artık alt proses sonlandığında
	onun exit kodunu init alacaktır. Aşağıda zombie oluşturan bir örnek verilmektedir:
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void exit_sys(const char *msg);

int main(void)
{
	pid_t pid;
	int i;

	if ((pid = fork()) == -1)
		exit_sys("fork");

	if (pid == 0)
		exit(0);

	for (i = 0; i < 30; ++i) {
		printf("child is zombie...\n");
		sleep(1);
	}

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde dosya betimleyicileri dosya betimleyici tablosunda bir indeks belirtmektedir. Proses çalışmaya başladığında dosya
	betimleyici tablosunun zaten 0, 1 ve 2 numaralı girişleri dolu durumdadır. open fonksiyonun ilk boş betimleyiciyi vereceği garanti edilmiştir. 
	Aşağıda bu garantinin testine ilişkin bir program görüyorsunuz
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void exit_sys(const char *msg);

int main(void)
{
	int fd1, fd2, fd3;

	if ((fd1 = open("test.txt", O_RDONLY)) == -1)
		exit_sys("open");

	printf("%d\n", fd1);		/* 3 */

	if ((fd2 = open("test.txt", O_RDONLY)) == -1)
		exit_sys("open");

	printf("%d\n", fd2);		/* 4 */

	close(fd1);

	if ((fd3 = open("test.txt", O_RDONLY)) == -1)
		exit_sys("open");

	printf("%d\n", fd3);		/* 3 */

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Linux sistemlerinde bir prosesin dosya betimleyici tablosu default olarak 1024 elemanlıdır. Dolayısıyla proses hiç kapatmadan en fazla 1024 dosya 
	aynı anda açık tutabilir. Tabii işin başında ilk üç giriş zaten dolu biçimdedir. Bu durumda proses onları kapamazsa ancak 1021 dosya açabilir.
	Aşağıda bu testi yapan bir program verilmiştir. 1024 uzunluk prosese özel izinverilmişse büyütülebilektedir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void exit_sys(const char *msg);

int main(void)
{
	int fd;
	int i;

	for (i = 0;; ++i) {
		if ((fd = open("test.txt", O_RDONLY)) == -1) {
			perror("open");
			break;
		}
		printf("%d\n", fd);
	}

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Değişken sayıda argüman alan fonksiyonlara örnekler
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdarg.h>

int add(int count, ...)
{
	va_list va;
	int arg;
	int i;
	int total;

	va_start(va, count);

	total = 0;
	for (i = 0; i < count; ++i) {
		arg = va_arg(va, int);
		total += arg;
	}

	va_end(va);

	return total;
}

int main(void)
{
	int result;

	result = add(5, 1, 2, 3, 4, 5);

	printf("%d\n", result);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Değişken sayıda argüman alan fonksiyonlara örnekler
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdarg.h>

void vputs(const char *str, ...)
{
	va_list va;
	const char *arg;

	va_start(va, str);

	arg = str;
	for (;;) {
		if (arg == NULL)
			break;
		puts(arg);
		arg = va_arg(va, const char *);
	}

	va_end(va);
}

int main(void)
{
	vputs("ali", "veli", "selami", (char *)NULL);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	printf fonksiyonun nasıl yazılmış olabileceğine ilişkin bir ipucu kodu
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdarg.h>

int myprintf(const char *format, ...)
{
	va_list va;
	int argi;
	double argd;
	int argc;
	int count;

	va_start(va, format);

	count = 0;
	while (*format != '\0') {
		if (*format == '%')
			switch (*++format) {
			case 'd':
				argi = va_arg(va, int);
				count += printf("%d", argi);
				break;
			case 'f':
				argd = va_arg(va, double);
				count += printf("%f", argd);
				break;
			case 'c':
				argc = va_arg(va, int);
				count += printf("%c", argc);
				break;
			}
		else {
			putchar(*format);
			++count;
		}
		++format;
	}

	va_end(va);

	return count;
}

int main(void)
{
	int a = 123;
	double b = 12.3;
	char c = 'x';
	int result;

	result = myprintf("a = %d, b = %f, c = %c\n", a, b, c);
	printf("%d\n", result);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	stdio.h'taki printf ailesi fonksiyonların va_list parametreli başı v ile başlayan versiyonları vardır. Bu sayede biz bu printf ailesi fonksiyonları
	sarmalayabilen fonksiyonlar yazabiliriz. Örneğin printf fonksiyonun v'li versiyonun ismi vprintf fonksiyonudur.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdarg.h>

int myprintf(const char *format, ...)
{
	va_list va;
	int result;

	va_start(va, format);

	result = vprintf(format, va);

	va_end(va);

	return result;
}

int main(void)
{
	int a = 10, b = 20, c = 30;

	myprintf("a = %d, b = %d, c = %d", a, b, c);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	fprintf fonksiyonunun v'li versiyonu vfprintf ismindedir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdarg.h>

void printerr(const char *format, ...)
{
	va_list va;


	va_start(va, format);

	fprintf(stderr, "Error: ");
	vfprintf(stderr, format, va);

	va_end(va);
}

int main(void)
{
	int errcode = 123;

	printerr("%d\n", errcode);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Örneğin bu kursta UNIX/Linux sistemlerinde başarıszlık durumunda errno değerini yazısını stderr dosyasına bastırıp prosesi sonlandıran 
	exit_sys fonksiyonun daha yeteneklisi bu v'li fonksiyonlarla yazılabilir
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

void exit_sys(const char *format, ...);

int main(int argc, char *argv[])
{
	int fd;

	if (argc != 2) {
		fprintf(stderr, "wrong number of arguments!..\n");
		exit(EXIT_FAILURE);
	}

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		exit_sys("Error open file %s", argv[1]);

	close(fd);

	return 0;
}

void exit_sys(const char *format, ...)
{
	va_list va;

	va_start(va, format);

	vfprintf(stderr, format, va);
	fprintf(stderr, ": %s\n", strerror(errno));

	va_end(va);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Mademki UNIX/Linux sistemlerinde open fonksiyonu en düşük boş betimleyiciyi bize vermektedir. O halde biz stdout aygıt sürücüne ilişkin 1 numaralı
	betimleyiciyi kapatıp hemen arkasından open fonksiyonu ile bir dosya açarsak open bize 1 numaralı betimleyiciyi verir. Yani artık 1 numaralı betimleyici
	terminal aygıt sürücüsüne ilişkin dosya nesnesini değil, disk dosyasına ilişkin dosya nesnesini gösteriyor durumda olur. İşte dosya yönlendirmeleri böyle
	bir mekanizmayla yapılmaktadır. printf, puts vs. gibi tüm standart C fonksiyonları ve diğer dillerdeki (Java, C#, Python vs.) ekrana yazan tüm fonksiyonlar
	eninde sonunda aslında write fonksiyonuyla 1 numaralı betimleyiciyi kullanarak yazımı yaparlar. Dolayısıyla bu yönlendirmeden sonra ekrana yazdırma için
	kullanılan tüm fonksiyonlar aslında dosyaya yazacaktır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void exit_sys(const char *msg);

int main(void)
{
	int fd;
	int i;

	close(1);

	if ((fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
		exit_sys("open");

	for (i = 0; i < 10; ++i)
		printf("%d\n", i);

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde dup fonksiyonu aynı dosya nesnesi gösteren yeni bir betimleyici oluşturup onunla geri dönmektedir. Dolayısıyla
	artık eski betimleyici ile yeni betimleyici tamamen eşdeğer olarak kullanılabilir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void exit_sys(const char *msg);

int main(void)
{
	int fd1;
	int fd2;
	char buf[10 + 1];
	ssize_t n;

	if ((fd1 = open("test.txt", O_RDONLY)) == -1)
		exit_sys("open");

	if ((fd2 = dup(fd1)) == -1)
		exit_sys("dup");

	if ((n = read(fd1, buf, 10)) == -1)
		exit_sys("read");

	buf[n] = '\0';
	puts(buf);

	if ((n = read(fd2, buf, 10)) == -1)
		exit_sys("read");

	buf[n] = '\0';
	puts(buf);

	close(fd1);
	close(fd2);

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	dup2 fonksiyonu IO yönlendirmesi için tercih edilmesi gereken fonksiyondur. Bu fonksiyon birinci parametresi ile belirtilen dosya betimleyicisinin
	gösterdiği dosya nesnesini gösteren yeni bir betimleyici yaratır. Ancak bu betimleyici dup fonksiyonunda olduğu gibi en düşük boş betimleyici değil
	ikinci parametresiyle belirtilen betimleycidir. Eğer ikinci parametresiyle belirtilen betimleyici bo değilse dup2 önce onu close ile kapatır
	sonra yönlendirmeyi yapar. Bu betimelicinin kapatılması ve yönlendirilmesi atomik bir biçimde gerçekleştirilemktedir. 
	dup2 başarı durumunda ikinci parametresiule belirtilen betimleyicinin kendisine, başarıszlık durumunda -1 değerine geri döner.

	Aşağıda stdout dosyasının dup2 ile doğru teknik kullanılarak yönlendirilmesi örneği verilmiştir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void exit_sys(const char* msg);

int main(void)
{
	int fd;
	int i;

	if ((fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
		exit_sys("open");

	if (dup2(fd, 1) == -1)
		exit_sys("dup2");

	close(fd);

	for (i = 0; i < 10; ++i)
		printf("%d\n", i);

	return 0;
}

void exit_sys(const char* msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Bir programın çalıştırdğı bir programın stdout gibi dosyalarını yönlendirebilmesi için önce bir kez fork yapması gerekir. alt proseste yönlendirmeyi 
	yapıp execuygulaması gerekir. Çünlü exec işlemi mevcut prosesin proses kontrol bloğuna ya da dosya betimleyici tablosuna dokunmamaktadır. 
	Yalnızca prosesin çalışan kodunu ortadan kaldırıp prosesin yeni bir kodla çalışmaya devam etmesini sağlamaktadır.

	Aşağıda redirect isimli program tek bir komut satırı argümanı almaktadır Bu argüman tıpkı kabuk programlarının istediği gibi
	'>' karakteri ile yönlendirme sentaksı içermelidir. ÖrneğiN:

	./redirect "ls -l > test.txt"

	Burada ./redirect programı ls programını çalıştırıp onun stdout dosyasına yazdıklarının test.txt dosyasına aktarılmasını
	sağlamktadır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* redirect.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_PROG_ARGS		512

void exit_sys(const char* msg);

int main(int argc, char* argv[])
{
	char* dirpos;
	char* progargs[MAX_PROG_ARGS], * str, * path;
	pid_t pid;
	int fd;
	int i;

	if (argc != 2) {
		fprintf(stderr, "wrong number of arguments!..\n");
		exit(EXIT_FAILURE);
	}

	if ((dirpos = strchr(argv[1], '>')) == NULL) {
		fprintf(stderr, "'>' direction symbol not found!..\n");
		exit(EXIT_FAILURE);
	}

	*dirpos = '\0';

	i = 0;
	for (str = strtok(argv[1], " \t"); str != NULL; str = strtok(NULL, " \t"))
		progargs[i++] = str;
	progargs[i] = NULL;

	if ((path = strtok(dirpos + 1, " \t")) == NULL) {
		fprintf(stderr, "cannot found file for redirection!..\n");
		exit(EXIT_FAILURE);
	}

	if (strtok(NULL, " \t") != NULL) {
		fprintf(stderr, "too many path given!..\n");
		exit(EXIT_FAILURE);
	}

	if ((pid = fork()) == -1)
		exit_sys("fork");

	if (pid == 0) {
		if ((fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
			exit_sys("open");
		if (dup2(fd, 1) == -1)
			exit_sys("dup2");
		close(fd);
		if (execvp(progargs[0], &progargs[0]) == -1)
			exit_sys("execvp");

		/* unreachable code */
	}

	if (waitpid(pid, NULL, 0) == -1)
		exit_sys("waitpid");

	return 0;
}

void exit_sys(const char* msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	üst proses fork işlemi yaptığında alt prosesin dosya betimleyici tablosu (file descriptor) üst prosesten kopyalanır. Yani alt proseste aynı
	numaralı betimleyiciler üst prosesteki ile aynı dosya nesnesini gösteriyor durumdadır. Aşağıdaki örnekte üst proses bir dosya yaratıp
	dosya göstericisini 10'uncu offet'e konumlandırmıştır. Alt proses artık bu dosyadan okuma yaptığında 10 numaralı offset'ten okur. 
	Çünkü üst proses ve alt proses aynı dosya nesnesini görüyor durumdadır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

void exit_sys(const char* msg);

int main(int argc, char* argv[])
{
	int fd;
	pid_t pid;
	char buf[10 + 1];
	ssize_t result;

	if ((fd = open("test.txt", O_RDONLY)) == -1)
		exit_sys("open");

	lseek(fd, 10, SEEK_SET);

	if ((pid = fork()) == -1)
		exit_sys("");

	if (pid == 0) {
		if ((result = read(fd, buf, 10)) == -1)
			exit_sys("read");
		buf[result] = '\0';
		puts(buf);

		close(fd);
		exit(EXIT_SUCCESS);
	}

	if (waitpid(pid, NULL, 0) == -1)
		exit_sys("waitpid");

	close(fd);

	return 0;
}

void exit_sys(const char* msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde isimsiz borular pipe POSIX fonksiyonuyla yaratılır ve yalnzca üst ve alt proseslerde haberleşme amacıyla kullanılır
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void exit_sys(const char* msg);

int main(int argc, char* argv[])
{
	int pfds[2];
	pid_t pid;
	int i, val;
	ssize_t result;

	if (pipe(pfds) == -1)
		exit_sys("pipe");

	if ((pid = fork()) == -1)
		exit_sys("fork");

	if (pid != 0) {		/* parent process */
		close(pfds[0]);

		for (i = 0; i < 1000; ++i)
			if (write(pfds[1], &i, sizeof(int)) == -1)
				exit_sys("write");

		close(pfds[1]);

		if (waitpid(pid, NULL, 0) == -1)
			exit_sys("waitpid");
	}
	else {				/* child process */
		close(pfds[1]);
		while ((result = read(pfds[0], &val, sizeof(int))) > 0) {
			printf("%d ", val);
			fflush(stdout);
		}
		if (result == -1)
			exit_sys("read");

		printf("\n");

		close(pfds[0]);
	}

	return 0;
}

void exit_sys(const char* msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Kabuk programı "a | b" boru işlemini tipk olarak şöyle yapmaktadır: Önce kabuk bir isimsiz boru yaratır. Sonra a programı için fork işlemi yapar.
	alt prosesin stdout dosyasını boruya yönlendirir ve exec uygular. Bundan sonra b programı için bir fork uygular b'nin stdin dosyasını boruya yönlendirir ve b için
	exec işlemi yapar. Tabii her proses gereksiz betimleyicileri kapatmalıdır. 

	Aşağıda program kabuğun yaptığı boru işleminin benzerini yapmaktadır. Program komut satırı argümanı olarak "ls -l | wc" gibi bir yazı alır.
	Burada '|' karakterini bulur. Onun sol tarafını ve sağ tarafını exec fonksiyonun v'li versiyonları için parse eder. Sonra yukarıda belirtildiği
	gibi isimsiz boru işlemlerini yapar. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* shellpipe.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS	512

void exit_sys(const char* msg);

int main(int argc, char* argv[])
{
	char* ppos;
	char *args_out[MAX_ARGS], *args_in[MAX_ARGS];
	char* str;
	int pfds[2];
	pid_t pid_out, pid_in;
	int i;

	if (argc != 2) {
		fprintf(stderr, "wrong number of arguments!..\n");
		exit(EXIT_FAILURE);
	}

	if ((ppos = strchr(argv[1], '|')) == NULL) {
		fprintf(stderr, "no pipe symbol!..\n");
		exit(EXIT_FAILURE);
	}

	*ppos = '\0';

	i = 0;
	for (str = strtok(argv[1], " \t"); str != NULL; str = strtok(NULL, " \t"))
		args_out[i++] = str;
	args_out[i] = NULL;

	i = 0;
	for (str = strtok(ppos + 1, " \t"); str != NULL; str = strtok(NULL, " \t"))
		args_in[i++] = str;
	args_in[i] = NULL;

	if (pipe(pfds) == -1)
		exit_sys("pipe");

	if ((pid_out = fork()) == -1)
		exit_sys("fork");

	if (pid_out == 0) {
		if (dup2(pfds[1], 1) == -1)
			exit_sys("dup2");
		close(pfds[0]);
		close(pfds[1]);
		if (execvp(args_out[0], &args_out[0]) == -1)
			exit_sys("execvp");

		/* unreachable code */
	}

	if ((pid_in = fork()) == -1)
		exit_sys("fork");

	if (pid_in == 0) {
		if (dup2(pfds[0], 0) == -1)
			exit_sys("dup2");
		close(pfds[0]);
		close(pfds[1]);
		if (execvp(args_in[0], &args_in[0]) == -1)
			exit_sys("execvp");

		/* unreachable code */
	}

	close(pfds[0]);
	close(pfds[1]);

	if (waitpid(pid_out, NULL, 0) == -1)
		exit_sys("waitpid");

	if (waitpid(pid_in, NULL, 0) == -1)
		exit_sys("waitpid");

	return 0;
}

void exit_sys(const char* msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows sistemlerinde isimsiz boru haberleşmesi yine üst proses ile alt proses arasında yapılabilmektedir. Ancak bu sistemlerde boru handle
	değerinin alt prosese aktarılabilmesi için SetHandleInformation fonksiyonu ile handle'ın alt prosese aktarılabilirliğini sağlamak gerekmetedir. 
	Alt proses aktarılah handler'ın değerini bilemez. Bu nednele üst prosesin ayrıca bunu komut satırı argümanlarıyla ya da çevre değişkenleri yoluyla
	ya da başka bir proseslerarası haberleşme yöntemiyle alt prosese aktarması gerekir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* Parent.c */

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <tchar.h>

void ExitSys(LPCTSTR lpszMsg);

int main(void)
{
	HANDLE hReadPipe, hWritePipe;
	TCHAR szArgs[1024];
	STARTUPINFO si = { sizeof(STARTUPINFO) };
	PROCESS_INFORMATION pa;
	int i;
	DWORD dwWritten;

	if (!CreatePipe(&hReadPipe, &hWritePipe, NULL, 0))
		ExitSys(TEXT("CreatePipe"));

	if (!SetHandleInformation(hReadPipe, HANDLE_FLAG_INHERIT, HANDLE_FLAG_INHERIT))
		ExitSys(TEXT("CreatePipe"));

	_stprintf(szArgs, TEXT("Child.exe %p"), hReadPipe);

	if (!CreateProcess(NULL, szArgs, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pa))
		ExitSys(TEXT("CreateProcess"));

	CloseHandle(hReadPipe);

	for (i = 0; i < 100; ++i)
		if (!WriteFile(hWritePipe, &i, sizeof(int), &dwWritten, NULL))
			ExitSys(TEXT("WriteFile"));

	CloseHandle(hWritePipe);

	WaitForSingleObject(pa.hProcess, INFINITE);

	return 0;
}

void ExitSys(LPCTSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		_ftprintf(stderr, TEXT("%s: %s"), lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/* Child.c */

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <tchar.h>

void ExitSys(LPCTSTR lpszMsg);

int _tmain(int argc, TCHAR *argv[])
{
	HANDLE hReadPipe;
	BOOL bResult;
	DWORD dwRead;
	int val;

	_stscanf(argv[1], TEXT("%p"), &hReadPipe);

	while (ReadFile(hReadPipe, &val, sizeof(int), &dwRead, NULL)) {
		_tprintf(TEXT("%d "), val);
		fflush(stdout);
	}

	if (GetLastError() != ERROR_BROKEN_PIPE)
		ExitSys(TEXT("ReadFile"));

	CloseHandle(hReadPipe);

	return 0;
}

void ExitSys(LPCTSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		_ftprintf(stderr, TEXT("%s: %s"), lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde İsimli borularla çalışmak için önce bir boru dosyasının yaratılması gerekir. Boru dosyalarına "fifo" dosyaları da 
	denilmektedir. Bu dosyalar gerçek birer dosya değildir.Yalnızca boruyu temsil eden dizin girişleridir. İsimli boru dosyalarını yaratmak içn mkfifo
	isimli bir POSIX fonksiyonu bulundurulmuştur. Aslında aynı zamanda kabuk üzerinden isimli boru yaratmak için bir "mkfifo" komutu da vardır. 
	Aşağıda mkfifo komutunun bir benzerinin nasıl yazılabileceğine ilişkin bir örnek program verilmiştir.
-------------------------------------------------------------------------------------------------------------------------------------------*/
/*mymkfifo.c  */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

void exit_sys(const char *msg);

int main(int argc, char *argv[])
{

	int result;
	int m_flag;
	char *m_arg;
	int err_flag;
	int mode;
	int i;

	umask(0);

	opterr = 0;

	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	err_flag = 0;
	m_flag = 0;

	while ((result = getopt(argc, argv, "m:")) != -1) {
		switch (result) {
		case 'm':
			m_flag = 1;
			m_arg = optarg;
			break;
		case '?':
			if (optopt == 'm')
				fprintf(stderr, "-m option must have an argument!..\n");
			else
				fprintf(stderr, "invalid option: -%c\n", optopt);

			err_flag = 1;
		}
	}

	if (err_flag)
		exit(EXIT_FAILURE);

	if (m_flag)
		sscanf(m_arg, "%o", &mode);

	if (optind == argc) {
		fprintf(stderr, "at least one path must be specified!..\n");
		exit(EXIT_FAILURE);
	}

	for (i = optind; i < argc; ++i)
		if (mkfifo(argv[i], mode) == -1)
			exit_sys("mkfifo");

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	İsimli borularda iki proses de isimli boru dosyasını open fonksiyonuyla açar. Tabii proseslerden biri yazma yapacaksa O_WRONLY modunda 
	okuma yapacaksa O_RDONLY modunda dosyayı açmalıdır. Böylece iki proses de aynı boruya ilişkin farklı iki betimleyici elde etmiş olur. Artık read ve
	write işlemleri tamamen isimsiz borularda olduğu gibidir. Ancak proseslerden biri boruyu O_WRONLY modunda açmışsa başka bir proses boruya yazma
	yapmak için boruyu açana kadar open blokede bekler. Benzer biçimde bir bir proses boruyu O_RDONLY modunda açmışsa başka bir proses boruyu yazma
	modunda açana kadar open fonksiyonu blokede bekler. Eğer proses boruyu O_RDWR modunda açarsa open fonksiyonunda bloke oluşmaz. Bu modda boruyu açmak
	nadiren gerekli olmaktadır. 

	Aşağıda isimli boru heberleşmesine ilişkin bir örnek verilmiştir:
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* prog1.c */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void exit_sys(const char *msg);

int main(void)
{
	int fd;
	int i;

	if ((fd = open("mypipe", O_WRONLY)) == -1)
		exit_sys("open");

	for (i = 0; i < 100000; ++i)
		if (write(fd, &i, sizeof(int)) == -1)
			exit_sys("write");

	close(fd);

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/* prog2.c */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void exit_sys(const char *msg);

int main(void)
{
	int fd;
	int val;
	ssize_t result;

	if ((fd = open("mypipe", O_RDONLY)) == -1)
		exit_sys("open");

	getchar();

	while ((result = read(fd, &val, sizeof(int))) > 0)
		printf("%d ", val), fflush(stdout);
	printf("\n");

	if (result == -1)
		exit_sys("read");

	close(fd);

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows'ta paylaşılan bellek alanlarını oluşturabilmek için iki proses aynı ismi vererek CreateFileMapping fonksiyonu ile file mapping nesnesi
	yaratır. Sonra MapViewOfFile fonksiyonu ile bu file mapping nesnesini map eder. 

	Aşağıda bu biçimde haberleşme örneği verilmiştir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* Process1.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	HANDLE hFileMapping;
	LPVOID pvAddr;
	int *pi;
	int i;

	if ((hFileMapping = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 4096, "SampleFileMappingExample")) == NULL)
		ExitSys("CreateFileMapping");

	if ((pvAddr = MapViewOfFile(hFileMapping, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 4096)) == NULL)
		ExitSys("MapViewOfFile");

	pi = (int *)pvAddr;

	for (i = 0; i < 1024; ++i)
		pi[i] = i;

	printf("4096 bytes written shared memory. Press ENTER to exit...\n");
	getchar();

	UnmapViewOfFile(pvAddr);
	CloseHandle(hFileMapping);

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastError = GetLastError();
	LPSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/* Process2.c */

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	HANDLE hFileMapping;
	LPVOID pvAddr;
	int *pi;
	int i;

	if ((hFileMapping = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 4096, "SampleFileMappingExample")) == NULL)
		ExitSys("CreateFileMapping");

	if ((pvAddr = MapViewOfFile(hFileMapping, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 4096)) == NULL)
		ExitSys("MapViewOfFile");

	pi = (int *)pvAddr;

	printf("Press ENTER to continue...\n");
	getchar();

	for (i = 0; i < 1024; ++i)
		printf("%d ", pi[i]);
	printf("\n");

	UnmapViewOfFile(pvAddr);
	CloseHandle(hFileMapping);

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastError = GetLastError();
	LPSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Bellek tabanlı dosyalar (memory mapped files) dosyaların RAM'e çekilip dosya işlemlerinin RAM üzerinde göstericilerle yapılmasını sağlayan bir tekniktir. 
	Dosya işlemlerini kolaylaştırır, birden fazla proses aynı dosya üzerinde işlem yapacaksa daha etkin bir mekanizma oluşturur. 

	Aşağıda Windows sistemlerinde bellek tabanlı dosya örneği verilmektedir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	HANDLE hFile;
	HANDLE hFileMapping;
	LPVOID pvAddr;
	LPSTR str;
	int i;
	char text[] = "01234567890123456789";

	if ((hFile = CreateFile("Test.txt", GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ|FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL)) == INVALID_HANDLE_VALUE)
		ExitSys("CreateFile");

	if ((hFileMapping = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, 0, NULL)) == NULL)
		ExitSys("CreateFileMapping");

	if ((pvAddr = MapViewOfFile(hFileMapping, FILE_MAP_READ|FILE_MAP_WRITE, 0, 0, 0)) == NULL)
		ExitSys("MapViewOfFile");

	str = (LPSTR)pvAddr;

	for (i = 0; i < 30; ++i)
		putchar(str[i]);
	putchar('\n');

	memcpy(str, text, strlen(text));

	UnmapViewOfFile(pvAddr);
	CloseHandle(hFileMapping);
	CloseHandle(hFile);

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastError = GetLastError();
	LPSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Dosya formatları üzerinde işlemle yaparken dosyanın bellek tabanlı bir biçimde açılması işlemleri oldukça kolaylaştırmaktadır. Aşağıdaki örnekte
	bir BMP dosyası bellek tabanlı olarak açılmış ve dosyanın başlık kısmı bir yapğı biçiminde elde edilmiştir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#pragma pack(1)
typedef struct tagBMP_HEADER {
	WORD wMagic;
	DWORD dwSize;
	WORD wReserved1;
	WORD wReserved2;
	DWORD dwImageDataOffset;
} BMP_HEADER;

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	HANDLE hFile;
	HANDLE hFileMapping;
	LPVOID pvAddr;
	BMP_HEADER *pBmpHeader;

	if ((hFile = CreateFile("Test.bmp", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL)) == INVALID_HANDLE_VALUE)
		ExitSys("CreateFile");

	if ((hFileMapping = CreateFileMapping(hFile, NULL, PAGE_READONLY, 0, 0, NULL)) == NULL)
		ExitSys("CreateFileMapping");

	if ((pvAddr = MapViewOfFile(hFileMapping, FILE_MAP_READ, 0, 0, 0)) == NULL)
		ExitSys("MapViewOfFile");

	pBmpHeader = (BMP_HEADER *)pvAddr;

	printf("Magic: (%04x) %c%c\n", (unsigned int)pBmpHeader->wMagic, (unsigned int)pBmpHeader->wMagic & 0xFF, (unsigned int)pBmpHeader->wMagic >> 8);
	printf("Size: %lu\n", (unsigned long int)pBmpHeader->dwSize);
	printf("Image Data Offset: %lu\n", (unsigned long int)pBmpHeader->dwSize);

	UnmapViewOfFile(pvAddr);
	CloseHandle(hFileMapping);
	CloseHandle(hFile);

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastError = GetLastError();
	LPSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde paylaşılan bellek alanları için iki farklı grup fonksiyon kullanılmaktadır. İlk grup eskiden beri olan ve "sistem 5
	payaşılan bellek alanları fonksiyonları" denilen gruptur. İkinci grup daha modern bir arayüz snmaktadır. Bu ikinci gruba "POSIX paylaşılan bellek alanları
	fonksiyonları" denilmektedir. Ancak aslında her iki grup fonksiyon da POSIX standartlarında bulunmaktadır.

	Aşağıda POSIX paylaşılan bellek alanı fonksiyonlarıyla proseslerarası haberleşme örneği verilmiştir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* prog1.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>

void exit_sys(const char *msg);

int main(void)
{
	int fdshm;
	void *shmaddr;
	char *str;

	if ((fdshm = shm_open("/sample_shared_memory_name", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
		exit_sys("shm_open");

	if (ftruncate(fdshm, 4096) == -1)
		exit_sys("ftruncate");

	if ((shmaddr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fdshm, 0)) == MAP_FAILED)
		exit_sys("mmap");

	str = (char *)shmaddr;

	strcpy(str, "This is a test...");

	printf("Press ENTER to exit...\n");
	getchar();

	if (munmap(shmaddr, 4096) == -1)
		exit_sys("munmap");

	close(fdshm);

	if (shm_unlink("/sample_shared_memory_name") == -1)
		exit_sys("shm_unlink");

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/* prog2.c */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

void exit_sys(const char *msg);

int main(void)
{
	int fdshm;
	void *shmaddr;
	char *str;

	if ((fdshm = shm_open("/sample_shared_memory_name", O_RDWR, 0)) == -1)
		exit_sys("shm_open");

	if ((shmaddr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fdshm, 0)) == MAP_FAILED)
		exit_sys("mmap");

	str = (char *)shmaddr;

	printf("press ENTER to read...\n");
	getchar();

	puts(str);

	if (munmap(shmaddr, 4096) == -1)
		exit_sys("munmap");

	close(fdshm);

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde mesaj kuyrukları için "Sistem 5 Mesaj KJuyruklarıo" ve "POSIX Mesaj Kuyrukları" olmak üzere iki farklı arayüz fonksiyon 
	grubu vardır. Aşağıdaki örnekte POSIX Mesaj Kuyrıukları örneği verilmiştir
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* prog1.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

#define MAX_MSG_SIZE        8192

void exit_sys(const char *msg);
void empty_stdin(void);

int main(void)
{
	struct mq_attr attr;
	mqd_t mq;
	char msg[MAX_MSG_SIZE], *str;
	unsigned int prio;

	attr.mq_maxmsg = 10;
	attr.mq_msgsize = MAX_MSG_SIZE;

	if ((mq = mq_open("/sample_message_queue", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH, &attr)) == -1)
		exit_sys("mq_open");

	for (;;) {
		printf("Message: ");
		fflush(stdout);

		fgets(msg, MAX_MSG_SIZE, stdin);
		if ((str = strchr(msg, '\n')) != NULL)
			*str = '\0';
		printf("Priority: ");
		fflush(stdout);
		scanf("%u", &prio);
		empty_stdin();

		if (mq_send(mq, msg, strlen(msg) + 1, prio) == -1)
			exit_sys("mq_send");

		if (!strcmp(msg, "quit"))
			break;
	}

	mq_close(mq);

	return 0;
}

void empty_stdin(void)
{
	int ch;

	while ((ch = getchar()) != EOF && ch != '\n')
		;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/* prog2.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

#define MAX_MSG_SIZE        8192

void exit_sys(const char *msg);

int main(void)
{
	mqd_t mq;
	struct mq_attr attr;
	char msg[MAX_MSG_SIZE];
	unsigned int prio;
	ssize_t result;

	if ((mq = mq_open("/sample_message_queue", O_RDONLY)) == -1)
		exit_sys("mq_open");

	for (;;) {
		printf("Message Queue Attibute\n");
		if (mq_getattr(mq, &attr) == -1)
			exit_sys("mq_getattr");
		printf("mq_flags: %ld\n", attr.mq_flags);
		printf("mq_maxmsg: %ld\n", attr.mq_maxmsg);
		printf("mq_msgsize: %ld\n", attr.mq_msgsize);
		printf("mq_curmsgs: %ld\n", attr.mq_curmsgs);
		printf("-----------------------\n");

		printf("Press ENTER to receive message..\n");
		getchar();

		if ((result = mq_receive(mq, msg, MAX_MSG_SIZE, &prio)) == -1)
			exit_sys("mq_receive");
		if (!strcmp(msg, "quit"))
			break;
		printf("-----------------------\n");
		printf("%lld bytes received with priority %u: \"%s\"\n", (long long)result, prio, msg);
		printf("-----------------------\n");
	}

	mq_close(mq);

	if (mq_unlink("/sample_message_queue") == -1)
		exit_sys("mq_unlink");


	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows'ta thread'lerin yaratılması
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);
DWORD __stdcall ThreadProc(LPVOID lpvParam);

int main(void)
{
	HANDLE hThread;
	DWORD dwThreadID;
	int i;

	if ((hThread = CreateThread(NULL, 0, ThreadProc, NULL, 0, &dwThreadID)) == NULL)
		ExitSys("CreateThread");


	for (i = 0; i < 10; ++i) {
		printf("Main thread: %d\n", i);
		Sleep(1000);
	}

	printf("press ENTER to exit...\n");
	getchar();

	return 0;
}

DWORD __stdcall ThreadProc(LPVOID lpvParam)
{
	int i;

	for (i = 0; i < 10; ++i) {
		printf("Other thread: %d\n", i);
		Sleep(1000);
	}

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde thread'lerin yaratılması
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void *thread_proc(void *param);
void exit_errno(const char *msg, int result);

int main(int argc, char *argv[])
{
	pthread_t tid;
	int result;
	int i;

	if ((result = pthread_create(&tid, NULL, thread_proc, NULL)) != 0)
		exit_errno("pthread_create", result);

	for (i = 0; i < 10; ++i) {
		printf("main thread: %d\n", i);
		sleep(1);
	}
	printf("press ENTER to exit..\n");
	getchar();

	return 0;
}

void *thread_proc(void *param)
{
	int i;

	for (i = 0; i < 10; ++i) {
		printf("other thread: %d\n", i);
		sleep(1);
	}

	return NULL;
}

void exit_errno(const char *msg, int result)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(result));

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows sistemlerinde bir thread akışı da ExitHread API fonksiyonu ile istenildiği zaman sonlandırılabilir. ExitThread API fonksiyonun parametresi
	thread'in exit kodudur. Thread'lerin ezit kodları Windows sistemlerinde DWORD bir değerdir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);
DWORD __stdcall ThreadProc(LPVOID lpvParam);
void Foo(void);

int main(void)
{
	HANDLE hThread;
	DWORD dwThreadID;
	int i;

	if ((hThread = CreateThread(NULL, 0, ThreadProc, NULL, 0, &dwThreadID)) == NULL)
		ExitSys("CreateThread");


	for (i = 0; i < 10; ++i) {
		printf("Main thread: %d\n", i);
		Sleep(1000);
	}

	printf("press ENTER to exit...\n");
	getchar();

	return 0;
}

DWORD __stdcall ThreadProc(LPVOID lpvParam)
{
	Foo();

	return 0;
}

void Foo(void)
{
	int i;

	for (i = 0; i < 10; ++i) {
		if (i == 5)
			ExitThread(0);
		printf("Other thread: %d\n", i);
		Sleep(1000);
	}
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde thread'ler pthread_exit fonksiyonuyla sonlandırılabilir. Bu fonksiyonun da parametresi thread'in exit kodudur. UNIX/Linux
	sistemlerinde thread'lerin exit kodları void * türündendir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void *thread_proc(void *param);
void exit_errno(const char *msg, int result);
void foo(void);

int main(int argc, char *argv[])
{
	pthread_t tid;
	int result;
	int i;

	if ((result = pthread_create(&tid, NULL, thread_proc, NULL)) != 0)
		exit_errno("pthread_create", result);

	for (i = 0; i < 10; ++i) {
		printf("main thread: %d\n", i);
		sleep(1);
	}
	printf("press ENTER to exit..\n");
	getchar();

	return 0;
}

void *thread_proc(void *param)
{
	foo();

	return NULL;
}

void foo(void)
{
	int i;

	for (i = 0; i < 10; ++i) {
		if (i == 5)
			pthread_exit(NULL);
		printf("other thread: %d\n", i);
		sleep(1);
	}
}

void exit_errno(const char *msg, int result)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(result));

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Proses sonlandığında tüm thread'ler de sonlandırılmaktadır. Dolayısıyla biz exit fonksiyonunu çağırdığımızda ya da akış main fonksiyonunu 
	bitiridiğinde (bu durumda da arka planda exit fonksiyonu çağrılmaktadır) tüm thread'ler sonlandırılır. Aşağıdaki örnekte aslında thread 
	sonsuz döngü içerisindedir. Ancak main fonksiyonu sonlandığı için tüm proses thread'lerle birlikte sonlandırılacaktır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);
DWORD __stdcall ThreadProc(LPVOID lpvParam);

int main(void)
{
	HANDLE hThread;
	DWORD dwThreadID;
	int i;

	if ((hThread = CreateThread(NULL, 0, ThreadProc, NULL, 0, &dwThreadID)) == NULL)
		ExitSys("CreateThread");

	for (i = 0; i < 10; ++i) {
		printf("Main thread: %d\n", i);
		Sleep(1000);
	}

	getchar();

	return 0;
}

DWORD __stdcall ThreadProc(LPVOID lpvParam)
{
	int i;

	for (i = 0;; ++i) {
		printf("Other thread: %d\n", i);
		Sleep(1000);
	}
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Ana thread de sonlandırılabilir. Bu durumda hem Windows sistemlerinde hem de UNIX/Linux sistemlerinde prosesin son thread'i sonlandırıldığında 
	proses otomatik olarak sonlandırılmaktadır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);
DWORD __stdcall ThreadProc(LPVOID lpvParam);

int main(void)
{
	HANDLE hThread;
	DWORD dwThreadID;
	int i;

	if ((hThread = CreateThread(NULL, 0, ThreadProc, NULL, 0, &dwThreadID)) == NULL)
		ExitSys("CreateThread");

	for (i = 0; i < 10; ++i) {
		printf("Main thread: %d\n", i);
		Sleep(1000);
	}

	ExitThread(0);

	return 0;
}

DWORD __stdcall ThreadProc(LPVOID lpvParam)
{
	int i;

	for (i = 0; i < 20; ++i) {
		printf("Other thread: %d\n", i);
		Sleep(1000);
	}
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Threadler arasında Windows sistemlerinde ve UNIX/Linux sistemlerinde üstlük/altlık (parent/child) ilişkisi yoktur. Bir thread başka bir thread'i
	Windows sistemlerinde TerminateThread API fonksiyonuyla o anda zorla sonlandırabilir. Bu tür sonlandırmalar tavsiye edilmemektedir. Çünkü bir thread'in
	belli bir noktada (örneğin printf fonksiyonunun içerisinde) zorla sonlandırılması programın çökmesine yol açabilmektedir. Aşağıdaki örnekte ana thread
	diğer thread'i zorla TerminateThread API fonksiyonuyla sonlandırmıştır. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);
DWORD __stdcall ThreadProc(LPVOID lpvParam);

int main(void)
{
	HANDLE hThread;
	DWORD dwThreadID;
	int i;

	if ((hThread = CreateThread(NULL, 0, ThreadProc, NULL, 0, &dwThreadID)) == NULL)
		ExitSys("CreateThread");

	for (i = 0; i < 10; ++i) {
		if (i == 5)
			TerminateThread(hThread, 0);
		printf("Main thread: %d\n", i);
		Sleep(1000);
	}

	return 0;
}

DWORD __stdcall ThreadProc(LPVOID lpvParam)
{
	int i;

	for (i = 0;; ++i) {
		putchar('.');
		Sleep(1000);
	}
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde de bir thread başka bir thread'i zorla pthread_cancel fonksiyonu ile sonlandırabilir. Ancak bu fonksiyon Windows sistemlerindeki
	TerminateThread fonksiyonu gibi çalışmamaktadır. UNIX/Linux sistemlerinde bir thread'e pthread_cancel fonksiyonu uygulanırsa thread akışı ancak bazı
	POSIX fonksiyonlarında sonlandırılmaktadır. Dolayısıyla bu sistemlerde pthread_cancel fonksiyonu TerminateThread fonksiyonuna göre çok daha güvenlidir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void *thread_proc(void *param);
void exit_errno(const char *msg, int errno);

int main(int argc, char *argv[])
{
	pthread_t tid;
	int result;
	int i;

	if ((result = pthread_create(&tid, NULL, thread_proc, NULL)) != 0)
		exit_errno("pthread_create", result);

	for (i = 0; i < 10; ++i) {
		if (i == 5)
			if ((result = pthread_cancel(tid)) != 0)
				exit_errno("pthread_cancel", result);

		printf("main thread: %d\n", i);
		sleep(1);
	}
	printf("press ENTER to exit..\n");
	getchar();

	return 0;
}

void *thread_proc(void *param)
{
	int i;

	for (i = 0;; ++i) {
		printf("other thread: %d\n", i);
		sleep(1);
	}

	return NULL;
}

void exit_errno(const char *msg, int errno)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Aşağıdaki örnekte pthread_cancel fonksiyonu sonsuz döngüdeki thread'i sonlandıramayacaktır. Çünkü bu thread sonlandırma için gereken 
	POSIX fonksiyonlarına (cancellation points) girmemiştir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void *thread_proc(void *param);
void exit_errno(const char *msg, int result);

int main(int argc, char *argv[])
{
	pthread_t tid;
	int result;
	int i;

	if ((result = pthread_create(&tid, NULL, thread_proc, NULL)) != 0)
		exit_errno("pthread_create", result);

	for (i = 0; i < 10; ++i) {
		if (i == 5)
			if ((result = pthread_cancel(tid)) != 0)
				exit_errno("pthread_cancel", result);

		printf("main thread: %d\n", i);
		sleep(1);
	}
	printf("press ENTER to exit..\n");
	getchar();

	return 0;
}

void *thread_proc(void *param)
{
	for (;;)
		;

	return NULL;
}

void exit_errno(const char *msg, int result)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(result));

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Thread'lerin stack'leri birbirlerinden ayrılmıştır. Bu nedenle farklı thread akışları aynı fonksiyon üzerinde ilerlerken o fonksiyondaki
	yerel değişkenlerin ve parametre değişkenlerinin farklı kopyalarını kullanıyor durumda olurlar.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);
DWORD __stdcall ThreadProc1(LPVOID lpvParam);
DWORD __stdcall ThreadProc2(LPVOID lpvParam);
void Foo(LPCSTR lpszName);

int main(void)
{
	HANDLE hThread1, hThread2;
	DWORD dwThreadID1, dwThreadID2;

	if ((hThread1 = CreateThread(NULL, 0, ThreadProc1, NULL, 0, &dwThreadID1)) == NULL)
		ExitSys("CreateThread");

	if ((hThread2 = CreateThread(NULL, 0, ThreadProc2, NULL, 0, &dwThreadID2)) == NULL)
		ExitSys("CreateThread");

	getchar();

	return 0;
}

DWORD __stdcall ThreadProc1(LPVOID lpvParam)
{
	Foo("Thread-1");

	return 0;
}

DWORD __stdcall ThreadProc2(LPVOID lpvParam)
{
	Foo("Thread-2");

	return 0;
}

void Foo(LPCSTR lpszName)
{
	int i = 0;

	Sleep(1000);
	++i;
	printf("%s: %i\n", lpszName, i);
	Sleep(1000);
	++i;
	printf("%s: %i\n", lpszName, i);
	Sleep(1000);
	++i;
	printf("%s: %i\n", lpszName, i);
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Ancak global değişkenlerin yaratıldığı DATA ve BSS alanları tüm thread'ler için ortak ve bir tanedir. Benzer biçimde HEAP alanı da tüm thread'ler
	için ortak ve 1 tanedir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);
DWORD __stdcall ThreadProc1(LPVOID lpvParam);
DWORD __stdcall ThreadProc2(LPVOID lpvParam);
void Foo(LPCSTR lpszName);

int main(void)
{
	HANDLE hThread1, hThread2;
	DWORD dwThreadID1, dwThreadID2;

	if ((hThread1 = CreateThread(NULL, 0, ThreadProc1, NULL, 0, &dwThreadID1)) == NULL)
		ExitSys("CreateThread");

	if ((hThread2 = CreateThread(NULL, 0, ThreadProc2, NULL, 0, &dwThreadID2)) == NULL)
		ExitSys("CreateThread");

	getchar();

	return 0;
}

DWORD __stdcall ThreadProc1(LPVOID lpvParam)
{
	Foo("Thread-1");

	return 0;
}

DWORD __stdcall ThreadProc2(LPVOID lpvParam)
{
	Foo("Thread-2");

	return 0;
}

int i = 0;

void Foo(LPCSTR lpszName)
{
	Sleep(1000);
	++i;
	printf("%s: %i\n", lpszName, i);
	Sleep(1000);
	++i;
	printf("%s: %i\n", lpszName, i);
	Sleep(1000);
	++i;
	printf("%s: %i\n", lpszName, i);
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows'ta bir thread'in sonlanmasını bloke biçimde başka bir thread WaitForSingleObject ve WaitForMultipleObjecst isimli API 
	fonksiyonlarıyla bekleyebilir. Aslında bu API fonksiyonları genel fonksiyonlardır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);
DWORD __stdcall ThreadProc1(LPVOID lpvParam);
DWORD __stdcall ThreadProc2(LPVOID lpvParam);
void Foo(LPCSTR lpszName);

int main(void)
{
	HANDLE hThread1, hThread2;
	DWORD dwThreadID1, dwThreadID2;

	if ((hThread1 = CreateThread(NULL, 0, ThreadProc1, NULL, 0, &dwThreadID1)) == NULL)
		ExitSys("CreateThread");

	if ((hThread2 = CreateThread(NULL, 0, ThreadProc2, NULL, 0, &dwThreadID2)) == NULL)
		ExitSys("CreateThread");

	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);

	printf("Threads finished...\n");

	return 0;
}

DWORD __stdcall ThreadProc1(LPVOID lpvParam)
{
	Foo("Thread-1");

	return 0;
}

DWORD __stdcall ThreadProc2(LPVOID lpvParam)
{
	Foo("Thread-2");

	return 0;
}

void Foo(LPCSTR lpszName)
{
	int i;

	for (i = 0; i < 10; ++i) {
		printf("%s: %d\n", lpszName, i);
		Sleep(1000);
	}
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	pthread_join POSIX fonksiyonu ile thread'lerin exit kodları da alınabilir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void *thread_proc1(void *param);
void *thread_proc2(void *param);
void foo(const char *name);
void exit_errno(const char *msg, int result);

int main(int argc, char *argv[])
{
	pthread_t tid1, tid2;
	int result;
	void *tret;

	if ((result = pthread_create(&tid1, NULL, thread_proc1, NULL)) != 0)
		exit_errno("pthread_create", result);

	if ((result = pthread_create(&tid2, NULL, thread_proc2, NULL)) != 0)
		exit_errno("pthread_create", result);

	if ((result = pthread_join(tid1, &tret)) != 0)
		exit_errno("pthread_join", result);

	printf("Thread-1 exited with %ld\n", (long)tret);

	if ((result = pthread_join(tid2, &tret)) != 0)
		exit_errno("pthread_join", result);

	printf("Thread-2 exited with %ld\n", (long)tret);

	return 0;
}

void *thread_proc1(void *param)
{
	foo("Thread-1");

	return (void *)100;
}

void *thread_proc2(void *param)
{
	foo("Thread-2");

	return (void *)200;
}

void foo(const char *name)
{
	int i;

	for (i = 0; i < 10; ++i) {
		printf("%s: %d\n", name, i);
		sleep(1);
	}
}

void exit_errno(const char *msg, int result)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(result));

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows sistemlerinde bir thread sonlandıktan sonra onun exit kodu GetExitCodeThread isimli API fonksiyonuyla elde edilebilmektedir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);
DWORD __stdcall ThreadProc1(LPVOID lpvParam);
DWORD __stdcall ThreadProc2(LPVOID lpvParam);
void Foo(LPCSTR lpszName);

int main(void)
{
	HANDLE hThread1, hThread2;
	DWORD dwThreadID1, dwThreadID2;
	DWORD dwExitCode;

	if ((hThread1 = CreateThread(NULL, 0, ThreadProc1, NULL, 0, &dwThreadID1)) == NULL)
		ExitSys("CreateThread");

	if ((hThread2 = CreateThread(NULL, 0, ThreadProc2, NULL, 0, &dwThreadID2)) == NULL)
		ExitSys("CreateThread");

	WaitForSingleObject(hThread1, INFINITE);

	if (!GetExitCodeThread(hThread1, &dwExitCode))
		ExitSys("CreateThread");

	printf("Thread-1 has been finished with exit code %lu\n", (unsigned long)dwExitCode);

	WaitForSingleObject(hThread2, INFINITE);

	if (!GetExitCodeThread(hThread2, &dwExitCode))
		ExitSys("CreateThread");

	printf("Thread-2 has been finished with exit code %lu\n", (unsigned long)dwExitCode);

	return 0;
}

DWORD __stdcall ThreadProc1(LPVOID lpvParam)
{
	Foo("Thread-1");

	return 100;
}

DWORD __stdcall ThreadProc2(LPVOID lpvParam)
{
	Foo("Thread-2");

	return 200;
}

void Foo(LPCSTR lpszName)
{
	int i;

	for (i = 0; i < 10; ++i) {
		printf("%s: %d\n", lpszName, i);
		Sleep(1000);
	}
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
Birden fazla thread ortak kaynaklara erişirken birbirlerini kimi zaman beklemek zorunda kalabilir. Örneğin iki thread aynı global değişkeni artırırken
bile eğer bir senkronizasyon sağlanmazsa umulmayan sonuçlar oluşabilmektedir. Aşağıdaki programda iki thread g_count isimli global değişkeni
birer milyon kez artırmıştır. Ancak sonuç sanıldığı gibi iki milyon olmamıştır. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);
DWORD __stdcall ThreadProc1(LPVOID lpvParam);
DWORD __stdcall ThreadProc2(LPVOID lpvParam);

int g_count;

int main(void)
{
	HANDLE hThread1, hThread2;
	DWORD dwThreadID1, dwThreadID2;
	
	if ((hThread1 = CreateThread(NULL, 0, ThreadProc1, NULL, 0, &dwThreadID1)) == NULL)
		ExitSys("CreateThread");

	if ((hThread2 = CreateThread(NULL, 0, ThreadProc2, NULL, 0, &dwThreadID2)) == NULL)
		ExitSys("CreateThread");

	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);

	printf("%d\n", g_count);

	return 0;
}

DWORD __stdcall ThreadProc1(LPVOID lpvParam)
{
	int i;

	for (i = 0; i < 1000000; ++i)
		++g_count;

	return 0;
}

DWORD __stdcall ThreadProc2(LPVOID lpvParam)
{
	int i;

	for (i = 0; i < 1000000; ++i)
		++g_count;

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	CRITICAL_SECTION nesnesinin kullanımına tipik bir örnek
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);
DWORD __stdcall ThreadProc1(LPVOID lpvParam);
DWORD __stdcall ThreadProc2(LPVOID lpvParam);

int g_count;
CRITICAL_SECTION g_cs;

int main(void)
{
	HANDLE hThread1, hThread2;
	DWORD dwThreadID1, dwThreadID2;

	InitializeCriticalSection(&g_cs);

	if ((hThread1 = CreateThread(NULL, 0, ThreadProc1, NULL, 0, &dwThreadID1)) == NULL)
		ExitSys("CreateThread");

	if ((hThread2 = CreateThread(NULL, 0, ThreadProc2, NULL, 0, &dwThreadID2)) == NULL)
		ExitSys("CreateThread");

	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);

	DeleteCriticalSection(&g_cs);

	printf("%d\n", g_count);

	return 0;
}

DWORD __stdcall ThreadProc1(LPVOID lpvParam)
{
	int i;

	for (i = 0; i < 1000000; ++i) {
		EnterCriticalSection(&g_cs);
		++g_count;
		LeaveCriticalSection(&g_cs);
	}


	return 0;
}

DWORD __stdcall ThreadProc2(LPVOID lpvParam)
{
	int i;


	for (i = 0; i < 1000000; ++i) {
		EnterCriticalSection(&g_cs);
		++g_count;
		LeaveCriticalSection(&g_cs);
	}

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Kritik kodlar farklı thread'lerin ortak bir kaynağa yazma amaçlı erişiminde gerekmektedir. Aşağıdaki örnekte iki thread bir hayali mekineyi
	sırasıyla 1, 2, 3, 4, 5 konumlarına sokacak olsun. Ancak bu işlemlerin arasında kesilme olsa bile başka bir thread önceki thread işlemini 
	bitirene kadar beklesin. Bu işlem tipik olarak kritik kod oluşturarak gerçekleştirilebilir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);
DWORD __stdcall ThreadProc1(LPVOID lpvParam);
DWORD __stdcall ThreadProc2(LPVOID lpvParam);
void DoMachine(LPCSTR szName);

CRITICAL_SECTION g_cs;

int main(void)
{
	HANDLE hThread1, hThread2;
	DWORD dwThreadID1, dwThreadID2;

	srand(time(NULL));

	InitializeCriticalSection(&g_cs);

	if ((hThread1 = CreateThread(NULL, 0, ThreadProc1, NULL, 0, &dwThreadID1)) == NULL)
		ExitSys("CreateThread");

	if ((hThread2 = CreateThread(NULL, 0, ThreadProc2, NULL, 0, &dwThreadID2)) == NULL)
		ExitSys("CreateThread");

	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);

	DeleteCriticalSection(&g_cs);

	return 0;
}

DWORD __stdcall ThreadProc1(LPVOID lpvParam)
{
	int i;

	for (i = 0; i < 10; ++i)
		DoMachine("Thread1");

	return 0;
}

DWORD __stdcall ThreadProc2(LPVOID lpvParam)
{
	int i;

	for (i = 0; i < 10; ++i)
		DoMachine("Thread2");

	return 0;
}

void DoMachine(LPCSTR lpszName)
{
	EnterCriticalSection(&g_cs);

	printf("-----------------\n");
	printf("1) %s\n", lpszName);
	Sleep(rand() % 500);
	printf("2) %s\n", lpszName);
	Sleep(rand() % 500);
	printf("3) %s\n", lpszName);
	Sleep(rand() % 500);
	printf("4) %s\n", lpszName);
	Sleep(rand() % 500);
	printf("5) %s\n", lpszName);
	Sleep(rand() % 500);

	LeaveCriticalSection(&g_cs);
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Birden fazla thread'in ortak bir veri yapısına (dinamik dizi, kuyruk, bağlı liste vs.) yazma amaçlı erişiminde thread'lerden biri işlemini
	yaparken kesilirse o veri yapısı karasız bir durumda kalabilir. Bu durumda diğer thread bu veri yapısına erişirken sorun ortaya çıkabilir.
	Aşağıdaki örnekte C++'te iki thread aynı dinamik diziye eleman eklemektedir. Burada senkronizasyon uygulanmazsa program çökebilir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <vector>

void ExitSys(LPCSTR lpszMsg);
DWORD __stdcall ThreadProc1(LPVOID lpvParam);
DWORD __stdcall ThreadProc2(LPVOID lpvParam);

CRITICAL_SECTION g_cs;
std::vector<int> g_v;

int main(void)
{
	HANDLE hThread1, hThread2;
	DWORD dwThreadID1, dwThreadID2;
	int i;

	srand(time(NULL));

	InitializeCriticalSection(&g_cs);

	if ((hThread1 = CreateThread(NULL, 0, ThreadProc1, NULL, 0, &dwThreadID1)) == NULL)
		ExitSys("CreateThread");

	if ((hThread2 = CreateThread(NULL, 0, ThreadProc2, NULL, 0, &dwThreadID2)) == NULL)
		ExitSys("CreateThread");

	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);

	DeleteCriticalSection(&g_cs);

	return 0;
}

DWORD __stdcall ThreadProc1(LPVOID lpvParam)
{
	int i;

	for (i = 0; i < 1000; ++i) {
		EnterCriticalSection(&g_cs);
		g_v.push_back(i);
		LeaveCriticalSection(&g_cs);
	}

	return 0;
}

DWORD __stdcall ThreadProc2(LPVOID lpvParam)
{
	int i;

	for (i = 0; i < 1000; ++i) {
		EnterCriticalSection(&g_cs);
		g_v.push_back(i);
		LeaveCriticalSection(&g_cs);
	}

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows'ta Mutex nesneleri ile aynı prosesin thread'leri arasında kritik kod oluşturma örneği
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);
DWORD __stdcall ThreadProc1(LPVOID lpvParam);
DWORD __stdcall ThreadProc2(LPVOID lpvParam);
void DoMachine(LPCSTR szName);

HANDLE g_hMutex;

int main(void)
{
	HANDLE hThread1, hThread2;
	DWORD dwThreadID1, dwThreadID2;

	srand(time(NULL));

	if ((g_hMutex = CreateMutex(NULL, FALSE, NULL)) == NULL)
		ExitSys("CeateMutex");

	if ((hThread1 = CreateThread(NULL, 0, ThreadProc1, NULL, 0, &dwThreadID1)) == NULL)
		ExitSys("CreateThread");

	if ((hThread2 = CreateThread(NULL, 0, ThreadProc2, NULL, 0, &dwThreadID2)) == NULL)
		ExitSys("CreateThread");

	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);

	CloseHandle(g_hMutex);

	return 0;
}

DWORD __stdcall ThreadProc1(LPVOID lpvParam)
{
	int i;

	for (i = 0; i < 10; ++i)
		DoMachine("Thread1");

	return 0;
}

DWORD __stdcall ThreadProc2(LPVOID lpvParam)
{
	int i;

	for (i = 0; i < 10; ++i)
		DoMachine("Thread2");

	return 0;
}

void DoMachine(LPCSTR lpszName)
{
	WaitForSingleObject(g_hMutex, INFINITE);

	printf("-----------------\n");
	printf("1) %s\n", lpszName);
	Sleep(rand() % 500);
	printf("2) %s\n", lpszName);
	Sleep(rand() % 500);
	printf("3) %s\n", lpszName);
	Sleep(rand() % 500);
	printf("4) %s\n", lpszName);
	Sleep(rand() % 500);
	printf("5) %s\n", lpszName);
	Sleep(rand() % 500);

	ReleaseMutex(g_hMutex);
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows sistemlerinde proseslerarası mutex nesnelerinin kullanılmasına ilişkin bir örnek. Bu örnekte iki proses paylaşılan bellek alanında 
	oluşturulan int bir nesneyi kritik kod içerisinde artırmaktadır. Kritik kod mutex nesnesiyle oluşturulmuştur. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* Prog1.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define SHARED_MEMORY_NAME		"MySharedMemoryTest"
#define MUTEX_NAME				"MyMutexTest"

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	HANDLE hFileMapping;
	HANDLE hMutex;
	LPVOID pvAddr;
	int* pi;
	int i;

	srand(time(NULL));

	if ((hFileMapping = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 4096, SHARED_MEMORY_NAME)) == NULL)
		ExitSys("CreateFileMapping");

	if ((pvAddr = MapViewOfFile(hFileMapping, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 4096)) == NULL)
		ExitSys("MapViewOfFile");

	if ((hMutex = CreateMutex(NULL, FALSE, MUTEX_NAME)) == NULL)
		ExitSys("CreateMutex");

	printf("Press ENTER to start...\n");
	getchar();

	pi = (int*)pvAddr;

	for (i = 0; i < 100000000; ++i) {
		WaitForSingleObject(hMutex, INFINITE);
		++* pi;
		ReleaseMutex(hMutex);
	}

	printf("Press ENTER to continue...\n");
	getchar();
	printf("Count = %d\n", *pi);

	CloseHandle(hMutex);
	UnmapViewOfFile(pvAddr);
	CloseHandle(hFileMapping);

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/* Prog2.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define SHARED_MEMORY_NAME		"MySharedMemoryTest"
#define MUTEX_NAME				"MyMutexTest"

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	HANDLE hFileMapping;
	HANDLE hMutex;
	LPVOID pvAddr;
	int* pi;
	int i;

	srand(time(NULL));

	if ((hFileMapping = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 4096, SHARED_MEMORY_NAME)) == NULL)
		ExitSys("CreateFileMapping");

	if ((pvAddr = MapViewOfFile(hFileMapping, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 4096)) == NULL)
		ExitSys("MapViewOfFile");

	if ((hMutex = CreateMutex(NULL, FALSE, MUTEX_NAME)) == NULL)
		ExitSys("CreateMutex");

	printf("Press ENTER to start...\n");
	getchar();

	pi = (int*)pvAddr;

	for (i = 0; i < 100000000; ++i) {
		WaitForSingleObject(hMutex, INFINITE);
		++* pi;
		ReleaseMutex(hMutex);
	}

	printf("Press ENTER to continue...\n");
	getchar();
	printf("Count = %d\n", *pi);

	CloseHandle(hMutex);
	UnmapViewOfFile(pvAddr);
	CloseHandle(hFileMapping);

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde mutex nesnelerinin kullanımı.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

void exit_errno(const char* msg, int result);
void* thread_proc1(void* param);
void* thread_proc2(void* param);
void do_machine(const char* name);

pthread_mutex_t g_mutex;

int main(int argc, char* argv[])
{
	int result;
	pthread_t tid1, tid2;

	srand(time(NULL));

	if ((result = pthread_mutex_init(&g_mutex, NULL)) != 0)
		exit_errno("pthread_mutex_init", result);

	if ((result = pthread_create(&tid1, NULL, thread_proc1, NULL)) != 0)
		exit_errno("pthread_create", result);

	if ((result = pthread_create(&tid2, NULL, thread_proc2, NULL)) != 0)
		exit_errno("pthread_create", result);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	pthread_mutex_destroy(&g_mutex);

	return 0;
}

void* thread_proc1(void* param)
{
	int i;

	for (i = 0; i < 10; ++i)
		do_machine("thread-1");

	return NULL;
}

void* thread_proc2(void* param)
{
	int i;

	for (i = 0; i < 10; ++i)
		do_machine("thread-2");

	return NULL;
}

void do_machine(const char* name)
{
	pthread_mutex_lock(&g_mutex);

	printf("---------------\n");
	printf("1) %s\n", name);
	usleep(rand() % 300000);
	printf("2) %s\n", name);
	usleep(rand() % 300000);
	printf("3) %s\n", name);
	usleep(rand() % 300000);
	printf("4) %s\n", name);
	usleep(rand() % 300000);
	printf("5) %s\n", name);
	usleep(rand() % 300000);

	pthread_mutex_unlock(&g_mutex);
}

void exit_errno(const char* msg, int result)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(result));

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde mutex nesneleri default durumda recursive değildir. Bu sistemlerde mutex nesnelerin recursive yapmak için
	önce pthread_mutexattr_t türünden bir nesne oluşturulur. Sonra bu nesne pthread_mutexattr_init fonksiyonuyla ilkdeğerlenir. Sonra da 
	pthread_mutexattr_settype fonksiyonu ile attribute recursive olarak set edilir. Son bu attribute nesnesi pthread_mutex_create fonksiyonunda
	kullanılır. en sonunda bu attribute nesnesi pthread_mutexattr_destroy fonksiyonuyla yok edilir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

void exit_errno(const char* msg, int result);
void* thread_proc1(void* param);
void* thread_proc2(void* param);
void recursive_test(const char* name);
void do_machine(const char* name);

pthread_mutex_t g_mutex;

int main(int argc, char* argv[])
{
	int result;
	pthread_t tid1, tid2;
	pthread_mutexattr_t mattr;

	srand(time(NULL));

	if ((result = pthread_mutexattr_init(&mattr)) != 0)
		exit_errno("pthread_mutexattr_init", result);

	if ((result = pthread_mutexattr_settype(&mattr, PTHREAD_MUTEX_RECURSIVE)) != 0)
		exit_errno("pthread_mutexattr_settype", result);

	if ((result = pthread_mutex_init(&g_mutex, &mattr)) != 0)
		exit_errno("pthread_mutex_init", result);

	pthread_mutexattr_destroy(mattr);

	if ((result = pthread_create(&tid1, NULL, thread_proc1, NULL)) != 0)
		exit_errno("pthread_create", result);

	if ((result = pthread_create(&tid2, NULL, thread_proc2, NULL)) != 0)
		exit_errno("pthread_create", result);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	pthread_mutex_destroy(&g_mutex);

	return 0;
}

void* thread_proc1(void* param)
{
	int i;

	for (i = 0; i < 10; ++i)
		do_machine("thread-1");

	return NULL;
}

void* thread_proc2(void* param)
{
	int i;

	for (i = 0; i < 10; ++i)
		do_machine("thread-2");

	return NULL;
}

void recursive_test(const char* name)
{
	pthread_mutex_lock(&g_mutex);

	printf("---------------\n");
	printf("1) %s\n", name);
	usleep(rand() % 300000);
	printf("2) %s\n", name);
	usleep(rand() % 300000);
	printf("3) %s\n", name);
	usleep(rand() % 300000);
	printf("4) %s\n", name);
	usleep(rand() % 300000);
	printf("5) %s\n", name);
	usleep(rand() % 300000);

	pthread_mutex_unlock(&g_mutex);
}

void do_machine(const char* name)
{
	pthread_mutex_lock(&g_mutex);

	recursive_test(name);

	pthread_mutex_unlock(&g_mutex);
}

void exit_errno(const char* msg, int result)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(result));

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde mutex nesnesini prosesler arasında kullanabilmek için mutex nesnesinin  paylaşılan bellek alanında yaratılması gerekir.
	Ancak ayrıca mutex'in prosesler arası kullanımını mümkün hale getirmek için mutex attribute nesnesinde pthread_mutexattr_setpshared fonksiyonu ile
	belirleme yapmak gerekir. Aşağıdaki örnekte prog1 programı önce paylaşılan bellek alanını ve mutex nesnesini oluşturmuştur. prog2 ise paylaşılan bellek alanındaki
	mutex nesnesini kullanmıştır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* prog1.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <pthread.h>

void exit_sys(const char* msg);
void exit_errno(const char* msg, int result);

struct SHARED_OBJECT {
	pthread_mutex_t mutex;
	int counter;
};

int main(int argc, char* argv[])
{
	int fdshm;
	int result;
	void* shmaddr;
	pthread_mutexattr_t mattr;
	struct SHARED_OBJECT* so;
	int i;

	if ((fdshm = shm_open("/sample_shared_memory_name", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
		exit_sys("shm_open");

	if (ftruncate(fdshm, 4096) == -1)
		exit_sys("ftruncate");

	if ((shmaddr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fdshm, 0)) == MAP_FAILED)
		exit_sys("mmap");

	so = (struct SHARED_OBJECT*)shmaddr;

	if ((result = pthread_mutexattr_init(&mattr)) != 0)
		exit_errno("pthread_mutexattr_init", result);

	if ((result = pthread_mutexattr_setpshared(&mattr, 1)) != 0)
		exit_errno("pthread_mutexattr_setpshared", result);

	if ((result = pthread_mutex_init(&so->mutex, &mattr)) != 0)
		exit_errno("pthread_mutexattr_setpshared", result);

	pthread_mutexattr_destroy(&mattr);

	printf("Press ENTER to continue...\n");
	getchar();
	printf("Entering loop...\n");

	for (i = 0; i < 1000000000; ++i) {
		pthread_mutex_lock(&so->mutex);
		++so->counter;
		pthread_mutex_unlock(&so->mutex);
	}

	printf("Press ENTER to exit...\n");
	getchar();

	printf("Counter: %d\n", so->counter);

	pthread_mutex_destroy(&so->mutex);

	if (munmap(shmaddr, 4096) == -1)
		exit_sys("munmap");

	close(fdshm);

	if (shm_unlink("/sample_shared_memory_name") == -1)
		exit_sys("shm_unlink");

	return 0;
}

void exit_sys(const char* msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

void exit_errno(const char* msg, int result)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(result));

	exit(EXIT_FAILURE);
}

/* prog2.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <pthread.h>

void exit_sys(const char* msg);
void exit_errno(const char* msg, int result);

struct SHARED_OBJECT {
	pthread_mutex_t mutex;
	int counter;
};

int main(int argc, char* argv[])
{
	int fdshm;
	void* shmaddr;
	struct SHARED_OBJECT* so;
	int i;

	if ((fdshm = shm_open("/sample_shared_memory_name", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
		exit_sys("shm_open");

	if ((shmaddr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fdshm, 0)) == MAP_FAILED)
		exit_sys("mmap");

	so = (struct SHARED_OBJECT*)shmaddr;

	printf("Press ENTER to continue...\n");
	getchar();
	printf("Entering loop...\n");

	for (i = 0; i < 1000000000; ++i) {
		pthread_mutex_lock(&so->mutex);
		++so->counter;
		pthread_mutex_unlock(&so->mutex);
	}

	printf("Press ENTER to exit...\n");
	getchar();

	printf("Counter: %d\n", so->counter);

	if (munmap(shmaddr, 4096) == -1)
		exit_sys("munmap");

	close(fdshm);

	return 0;
}

void exit_sys(const char* msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

void exit_errno(const char* msg, int result)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(result));

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows sistemlerinde semaphore nesnesinin kullanımına bir örnek. Bu örnekte binary semaphore ile kritik kod oluşturulmuştur.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);
DWORD __stdcall ThreadProc1(LPVOID lpvParam);
DWORD __stdcall ThreadProc2(LPVOID lpvParam);
void DoMachine(LPCSTR szName);

HANDLE g_hSemaphore;

int main(void)
{
	HANDLE hThread1, hThread2;
	DWORD dwThreadID1, dwThreadID2;

	srand(time(NULL));

	if ((g_hSemaphore = CreateSemaphore(NULL, 1, 1, NULL)) == NULL)
		ExitSys("CreateSemaphore");

	if ((hThread1 = CreateThread(NULL, 0, ThreadProc1, NULL, 0, &dwThreadID1)) == NULL)
		ExitSys("CreateThread");

	if ((hThread2 = CreateThread(NULL, 0, ThreadProc2, NULL, 0, &dwThreadID2)) == NULL)
		ExitSys("CreateThread");

	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);

	CloseHandle(g_hSemaphore);

	return 0;
}

DWORD __stdcall ThreadProc1(LPVOID lpvParam)
{
	int i;

	for (i = 0; i < 10; ++i)
		DoMachine("Thread1");

	return 0;
}

DWORD __stdcall ThreadProc2(LPVOID lpvParam)
{
	int i;

	for (i = 0; i < 10; ++i)
		DoMachine("Thread2");

	return 0;
}

void DoMachine(LPCSTR lpszName)
{
	WaitForSingleObject(g_hSemaphore, INFINITE);
	printf("-----------------\n");
	printf("1) %s\n", lpszName);
	Sleep(rand() % 500);
	printf("2) %s\n", lpszName);
	Sleep(rand() % 500);
	printf("3) %s\n", lpszName);
	Sleep(rand() % 500);
	printf("4) %s\n", lpszName);
	Sleep(rand() % 500);
	printf("5) %s\n", lpszName);
	Sleep(rand() % 500);
	ReleaseSemaphore(g_hSemaphore, 1, NULL);
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde semaphore nesnelerinin kullanımına örnek. Programda bir binary semaphore ile kritik kod oluşturulmuştur.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

void *thread_proc1(void* param);
void *thread_proc2(void* param);
void do_machine(const char* name);
void exit_sys(const char *msg);
void exit_errno(const char* msg, int result);

sem_t g_sem;

int main(int argc, char *argv[])
{
	int result;
	pthread_t tid1, tid2;

	srand(time(NULL));

	if (sem_init(&g_sem, 0, 1) == -1)
		exit_sys("sem_init");

	if ((result = pthread_create(&tid1, NULL, thread_proc1, NULL)) != 0)
		exit_errno("pthread_create", result);

	if ((result = pthread_create(&tid2, NULL, thread_proc2, NULL)) != 0)
		exit_errno("pthread_create", result);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	sem_destroy(&g_sem);

	return 0;
}

void *thread_proc1(void *param)
{
	int i;

	for (i = 0; i < 10; ++i)
		do_machine("thread-1");

	return NULL;
}

void *thread_proc2(void *param)
{
	int i;

	for (i = 0; i < 10; ++i)
		do_machine("thread-2");

	return NULL;
}

void do_machine(const char *name)
{
	if (sem_wait(&g_sem) == -1)
		exit_sys("sem_wait");

	printf("---------------\n");
	printf("1) %s\n", name);
	usleep(rand() % 300000);
	printf("2) %s\n", name);
	usleep(rand() % 300000);
	printf("3) %s\n", name);
	usleep(rand() % 300000);
	printf("4) %s\n", name);
	usleep(rand() % 300000);
	printf("5) %s\n", name);
	usleep(rand() % 300000);

	if (sem_post(&g_sem) == -1)
		exit_sys("sem_post");
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

void exit_errno(const char *msg, int result)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(result));

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Üretici-Tüketici Probleminin Windows sistemlerinde Semaphore Nesneleriyle Çözümü.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);
DWORD __stdcall ThreadProducer(LPVOID lpvParam);
DWORD __stdcall ThreadConsumer(LPVOID lpvParam);

HANDLE g_hSemProducer;
HANDLE g_hSemConsumer;
int g_shared;

int main(void)
{
	HANDLE hThreadProducer, hThreadConsumer;
	DWORD dwThreadIDProducer, dwThreadIDConsumer;

	srand(time(NULL));

	if ((g_hSemProducer = CreateSemaphore(NULL, 1, 1, NULL)) == NULL)
		ExitSys("CreateSemaphore");

	if ((g_hSemConsumer = CreateSemaphore(NULL, 0, 1, NULL)) == NULL)
		ExitSys("CreateSemaphore");

	if ((hThreadProducer = CreateThread(NULL, 0, ThreadProducer, NULL, 0, &dwThreadIDProducer)) == NULL)
		ExitSys("CreateThread");

	if ((hThreadConsumer = CreateThread(NULL, 0, ThreadConsumer, NULL, 0, &dwThreadIDConsumer)) == NULL)
		ExitSys("CreateThread");

	WaitForSingleObject(hThreadProducer, INFINITE);
	WaitForSingleObject(hThreadConsumer, INFINITE);

	CloseHandle(g_hSemProducer);
	CloseHandle(g_hSemConsumer);

	return 0;
}

DWORD __stdcall ThreadProducer(LPVOID lpvParam)
{
	int i;

	i = 0;
	for (;;) {
		Sleep(rand() % 300);

		WaitForSingleObject(g_hSemProducer, INFINITE);
		g_shared = i;
		ReleaseSemaphore(g_hSemConsumer, 1, NULL);

		++i;
		if (i == 100)
			break;
	}
	return 0;
}

DWORD __stdcall ThreadConsumer(LPVOID lpvParam)
{
	int val;

	for (;;) {
		WaitForSingleObject(g_hSemConsumer, INFINITE);
		val = g_shared;
		ReleaseSemaphore(g_hSemProducer, 1, NULL);

		Sleep(rand() % 200);
		printf("%d ", val);
		fflush(stdout);
		if (val == 99)
			break;
	}
	putchar('\n');
	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Üretici-Tketici Probleminin UNIX/Linux sistemlerinde semaphore nesneleriyle Çözümü.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

void *thread_producer(void* param);
void *thread_consumer(void* param);
void exit_sys(const char *msg);
void exit_errno(const char* msg, int result);

sem_t g_sem_producer;
sem_t g_sem_consumer;

int g_shared;

int main(int argc, char *argv[])
{
	int result;
	pthread_t tid_producer, tid_consumer;

	srand(time(NULL));

	if (sem_init(&g_sem_producer, 0, 1) == -1)
		exit_sys("sem_init");

	if (sem_init(&g_sem_consumer, 0, 0) == -1)
		exit_sys("sem_init");

	if ((result = pthread_create(&tid_producer, NULL, thread_producer, NULL)) != 0)
		exit_errno("pthread_create", result);

	if ((result = pthread_create(&tid_consumer, NULL, thread_consumer, NULL)) != 0)
		exit_errno("pthread_create", result);

	pthread_join(tid_producer, NULL);
	pthread_join(tid_consumer, NULL);

	sem_destroy(&g_sem_producer);
	sem_destroy(&g_sem_consumer);

	return 0;
}

void *thread_producer(void *param)
{
	int i;

	i = 0;
	for (;;) {
		usleep(rand() % 300000);

		sem_wait(&g_sem_producer);
		g_shared = i;
		sem_post(&g_sem_consumer);

		++i;
		if (i == 100)
			break;
	}

	return NULL;
}

void *thread_consumer(void *param)
{
	int val;

	for (;;) {
		sem_wait(&g_sem_consumer);
		val = g_shared;
		sem_post(&g_sem_producer);

		usleep(rand() % 200000);
		printf("%d ", val), fflush(stdout);
		if (val == 99)
			break;
	}
	putchar('\n');

	return NULL;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

void exit_errno(const char *msg, int result)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(result));

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows'ta prosesler arasında üretici-tüketici probleminin paylaşılan bellek alanları kullanılarak çözülmesi
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* Producer.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	HANDLE hFileMapping;
	LPVOID pvAddr;
	int *pshared;
	HANDLE hSemProducer;
	HANDLE hSemConsumer;
	int i;

	srand(time(NULL));

	if ((hSemProducer = CreateSemaphore(NULL, 1, 1, "MyProducerSemaphore")) == NULL)
		ExitSys("CreateFileMapping");

	if ((hSemConsumer = CreateSemaphore(NULL, 0, 1, "MyConsumerSemaphore")) == NULL)
		ExitSys("CreateFileMapping");

	if ((hFileMapping = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 4096, "MySharedMemory")) == NULL)
		ExitSys("CreateFileMapping");

	if ((pvAddr = MapViewOfFile(hFileMapping, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 4096)) == NULL)
		ExitSys("MapViewOfFile");
	pshared = (int *)pvAddr;

	i = 0;
	for (;;) {
		Sleep(rand() % 300);
		WaitForSingleObject(hSemProducer, INFINITE);
		*pshared = i;
		ReleaseSemaphore(hSemConsumer, 1, NULL);
		++i;
		if (i == 100)
			break;
	}
	putchar('\n');

	UnmapViewOfFile(pvAddr);
	CloseHandle(hFileMapping);
	CloseHandle(hSemProducer);
	CloseHandle(hSemConsumer);


	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastError = GetLastError();
	LPSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/* Consumer.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	HANDLE hFileMapping;
	LPVOID pvAddr;
	int *pshared;
	HANDLE hSemProducer;
	HANDLE hSemConsumer;
	int val;

	srand(time(NULL));
	if ((hSemProducer = CreateSemaphore(NULL, 1, 1, "MyProducerSemaphore")) == NULL)
		ExitSys("CreateFileMapping");

	if ((hSemConsumer = CreateSemaphore(NULL, 0, 1, "MyConsumerSemaphore")) == NULL)
		ExitSys("CreateFileMapping");

	if ((hFileMapping = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 4096, "MySharedMemory")) == NULL)
		ExitSys("CreateFileMapping");

	if ((pvAddr = MapViewOfFile(hFileMapping, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 4096)) == NULL)
		ExitSys("MapViewOfFile");

	pshared = (int *)pvAddr;

	for (;;) {
		WaitForSingleObject(hSemConsumer, INFINITE);
		val = *pshared;
		ReleaseSemaphore(hSemProducer, 1, NULL);
		Sleep(rand() % 200);
		printf("%d ", val), fflush(stdout);
		if (val == 99)
			break;
	}
	putchar('\n');

	UnmapViewOfFile(pvAddr);
	CloseHandle(hFileMapping);
	CloseHandle(hSemProducer);
	CloseHandle(hSemConsumer);

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastError = GetLastError();
	LPSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde prosesler arasında üretici-tüketici probleminin paylaşılan bellek alanları ile çözümü.
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* producer.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <semaphore.h>

void exit_sys(const char *msg);

int main(void)
{
	int fdshm;
	void *shmaddr;
	int *pshared;
	sem_t *sem_producer;
	sem_t *sem_consumer;
	int i;

	if ((fdshm = shm_open("/interprocess-producer-consumer-shared-memory", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
		exit_sys("shm_open");

	if (ftruncate(fdshm, 4096) == -1)
		exit_sys("ftruncate");

	if ((shmaddr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fdshm, 0)) == MAP_FAILED)
		exit_sys("mmap");

	pshared = (int *)shmaddr;

	if ((sem_producer = sem_open("/interprocess-producer-consumer-producer-semaphore", O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH, 1)) == NULL)
		exit_sys("sem_open");

	if ((sem_consumer = sem_open("/interprocess-producer-consumer-consumer-semaphore", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH, 0)) == NULL)
		exit_sys("sem_open");

	i = 0;
	for (;;) {
		usleep(rand() % 300000);
		sem_wait(sem_producer);
		*pshared = i;
		sem_post(sem_consumer);
		++i;
		if (i == 100)
			break;
	}

	sem_destroy(sem_consumer);
	sem_destroy(sem_producer);

	if (sem_unlink("/interprocess-producer-consumer-consumer-semaphore") == -1)
		exit_sys("shm_unlink");

	if (sem_unlink("/interprocess-producer-consumer-producer-semaphore") == -1)
		exit_sys("shm_unlink");

	if (munmap(shmaddr, 4096) == -1)
		exit_sys("munmap");

	close(fdshm);

	if (shm_unlink("/interprocess-producer-consumer-shared-memory") == -1)
		exit_sys("shm_unlink");

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/* consumer.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <semaphore.h>

void exit_sys(const char *msg);

int main(void)
{
	int fdshm;
	void *shmaddr;
	int *pshared;
	sem_t *sem_producer;
	sem_t *sem_consumer;
	int val;

	if ((fdshm = shm_open("/interprocess-producer-consumer-shared-memory", O_RDONLY, 0)) == -1)
		exit_sys("shm_open");

	if ((shmaddr = mmap(NULL, 4096, PROT_READ, MAP_SHARED, fdshm, 0)) == MAP_FAILED)
		exit_sys("mmap");

	pshared = (int *)shmaddr;

	if ((sem_producer = sem_open("/interprocess-producer-consumer-producer-semaphore", O_WRONLY)) == NULL)
		exit_sys("sem_open");

	if ((sem_consumer = sem_open("/interprocess-producer-consumer-consumer-semaphore", O_RDONLY)) == NULL)
		exit_sys("sem_open");

	for (;;) {
		usleep(rand() % 300000);
		sem_wait(sem_consumer);
		val = *pshared;
		sem_post(sem_producer);
		printf("%d ", val), fflush(stdout);
		if (val == 99)
			break;
	}
	putchar('\n');

	sem_destroy(sem_consumer);
	sem_destroy(sem_producer);

	if (munmap(shmaddr, 4096) == -1)
		exit_sys("munmap");

	close(fdshm);

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows'ta Üretici-Tüketici Probleminin Kuyruklu versiyonu
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define QUEUE_SIZE		10

void ExitSys(LPCSTR lpszMsg);
DWORD __stdcall ThreadProducer(LPVOID lpvParam);
DWORD __stdcall ThreadConsumer(LPVOID lpvParam);

HANDLE g_hSemProducer;
HANDLE g_hSemConsumer;

int g_queue[QUEUE_SIZE];
int g_head, g_tail;

int main(void)
{
	HANDLE hThreadProducer, hThreadConsumer;
	DWORD dwThreadIDProducer, dwThreadIDConsumer;

	srand(time(NULL));

	if ((g_hSemProducer = CreateSemaphore(NULL, QUEUE_SIZE, QUEUE_SIZE, NULL)) == NULL)
		ExitSys("CreateSemaphore");

	if ((g_hSemConsumer = CreateSemaphore(NULL, 0, QUEUE_SIZE, NULL)) == NULL)
		ExitSys("CreateSemaphore");

	if ((hThreadProducer = CreateThread(NULL, 0, ThreadProducer, NULL, 0, &dwThreadIDProducer)) == NULL)
		ExitSys("CreateThread");

	if ((hThreadConsumer = CreateThread(NULL, 0, ThreadConsumer, NULL, 0, &dwThreadIDConsumer)) == NULL)
		ExitSys("CreateThread");

	WaitForSingleObject(hThreadProducer, INFINITE);
	WaitForSingleObject(hThreadConsumer, INFINITE);

	CloseHandle(g_hSemProducer);
	CloseHandle(g_hSemConsumer);

	return 0;
}

DWORD __stdcall ThreadProducer(LPVOID lpvParam)
{
	int i;

	i = 0;
	for (;;) {
		Sleep(rand() % 300);

		WaitForSingleObject(g_hSemProducer, INFINITE);
		g_queue[g_head++] = i;
		g_head = g_head % QUEUE_SIZE;
		ReleaseSemaphore(g_hSemConsumer, 1, NULL);

		++i;
		if (i == 100)
			break;
	}
	return 0;
}

DWORD __stdcall ThreadConsumer(LPVOID lpvParam)
{
	int val;

	for (;;) {
		WaitForSingleObject(g_hSemConsumer, INFINITE);
		val = g_queue[g_tail++];
		g_tail = g_tail % QUEUE_SIZE;
		ReleaseSemaphore(g_hSemProducer, 1, NULL);

		Sleep(rand() % 200);
		printf("%d ", val);
		fflush(stdout);
		if (val == 99)
			break;
	}
	putchar('\n');
	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde Üretici-Tüketici Probleminin Kuyruklu versiyonu
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define QUEUE_SIZE		10

void *thread_producer(void* param);
void *thread_consumer(void* param);
void exit_sys(const char *msg);
void exit_errno(const char* msg, int result);

sem_t g_sem_producer;
sem_t g_sem_consumer;

int g_queue[QUEUE_SIZE];
int g_head, g_tail;

int main(int argc, char *argv[])
{
	int result;
	pthread_t tid_producer, tid_consumer;

	srand(time(NULL));

	if (sem_init(&g_sem_producer, 0, 1) == -1)
		exit_sys("sem_init");

	if (sem_init(&g_sem_consumer, 0, 0) == -1)
		exit_sys("sem_init");

	if ((result = pthread_create(&tid_producer, NULL, thread_producer, NULL)) != 0)
		exit_errno("pthread_create", result);

	if ((result = pthread_create(&tid_consumer, NULL, thread_consumer, NULL)) != 0)
		exit_errno("pthread_create", result);

	pthread_join(tid_producer, NULL);
	pthread_join(tid_consumer, NULL);

	sem_destroy(&g_sem_producer);
	sem_destroy(&g_sem_consumer);

	return 0;
}

void *thread_producer(void *param)
{
	int i;

	i = 0;
	for (;;) {
		usleep(rand() % 300000);

		sem_wait(&g_sem_producer);
		g_queue[g_head++] = i;
		g_head = g_head % QUEUE_SIZE;
		sem_post(&g_sem_consumer);

		++i;
		if (i == 100)
			break;
	}

	return NULL;
}

void *thread_consumer(void *param)
{
	int val;

	for (;;) {
		sem_wait(&g_sem_consumer);
		val = g_queue[g_tail++];
		g_tail = g_tail % QUEUE_SIZE;
		sem_post(&g_sem_producer);

		usleep(rand() % 200000);
		printf("%d ", val), fflush(stdout);
		if (val == 99)
			break;
	}
	putchar('\n');

	return NULL;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

void exit_errno(const char *msg, int result)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(result));

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows'ta Event nesneleri başka bir thread uyandırana kadar thread'i blokede bekletmek için kullanılmaktadır. 
	Bu nesnelerin UNIX(Linux sistemlerinde tam karşılığı yoktur ancak "durum değişkenleri (conditioned variables)" yaklaşık bu amaölarla 
	kullanılabilmektedir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);
DWORD __stdcall ThreadProc1(LPVOID lpvParam);
DWORD __stdcall ThreadProc2(LPVOID lpvParam);
DWORD __stdcall ThreadProc3(LPVOID lpvParam);

HANDLE g_hEvent;

int main(void)
{
	HANDLE hThread1, hThread2, hThread3;
	DWORD dwThreadID1, dwThreadID2, dwThreadID3;

	if ((g_hEvent = CreateEvent(NULL, TRUE, FALSE, NULL)) == NULL)
		ExitSys("CreateEvent");

	if ((hThread1 = CreateThread(NULL, 0, ThreadProc1, NULL, 0, &dwThreadID1)) == NULL)
		ExitSys("CreateThread");

	if ((hThread2 = CreateThread(NULL, 0, ThreadProc2, NULL, 0, &dwThreadID2)) == NULL)
		ExitSys("CreateThread");

	if ((hThread3 = CreateThread(NULL, 0, ThreadProc3, NULL, 0, &dwThreadID3)) == NULL)
		ExitSys("CreateThread");

	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);
	WaitForSingleObject(hThread3, INFINITE);

	CloseHandle(g_hEvent);

	return 0;
}

DWORD __stdcall ThreadProc1(LPVOID lpvParam)
{
	int i;

	for (i = 0; i < 10; ++i) {
		printf("Thread1 doing something: %d\n", i);
		Sleep(1000);
	}
	SetEvent(g_hEvent);

	return 0;
}

DWORD __stdcall ThreadProc2(LPVOID lpvParam)
{
	printf("Thread2 is waiting for thread-1...\n");
	WaitForSingleObject(g_hEvent, INFINITE);
	printf("Ok, Thread-2 continues...\n");

	return 0;
}

DWORD __stdcall ThreadProc3(LPVOID lpvParam)
{
	printf("Thread3 is waiting for thread-1...\n");
	WaitForSingleObject(g_hEvent, INFINITE);
	printf("Ok, Thread-3 continues...\n");

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Okuma YAzma Kilitleri (Read/Write Locks) bir kaynağa okuma ve yazma amaçlı erişen thread'lerin bulunduğu durumda etkin bir okuma işleminin 
	sağlanması için düşünülmüştür. Thread'lerden kaynağa yazma amaçlı erişirken diğer thread'ler kaynağa okuma ya da yazma amaçlı erişmemelidir. 
	Thread'lerden biri kaynağa okuma amaçlı erişirken diğer thread'ler kaynağa yazma amalı erişmemeli ancak okuma amaçlı erişebilmelidir. 
	Bu senkronizasyon biçimi yalnızca mutex ya da semaphore nesneleriyle çözülemez. 

	Aşağıda Windoes sistemlerinde Okuma Yazma kilitlerine bir örnek verilmiştir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define NTHREADS				30
#define MAX_THREAD_NAME			32

void ExitSys(LPCSTR lpszMsg);
DWORD __stdcall ThreadProc(LPVOID lpvParam);
void Read(LPCSTR lpszThreadName);
void Write(LPCSTR lpszThreadName);

SRWLOCK g_srwLock;

int main(void)
{
	HANDLE hThreads[NTHREADS];
	DWORD dwThreadIDs[NTHREADS];
	int i;
	LPCSTR lpszThreadName;

	srand(time(NULL));

	InitializeSRWLock(&g_srwLock);

	for (i = 0; i < NTHREADS; ++i) {
		if ((lpszThreadName = (LPCSTR)malloc(MAX_THREAD_NAME)) == NULL) {
			fprintf(stderr, "Cannot allocate memory!..\n");
			exit(EXIT_FAILURE);
		}
		sprintf(lpszThreadName, "Thread-%d", i + 1);

		if ((hThreads[i] = CreateThread(NULL, 0, ThreadProc, lpszThreadName, 0, &dwThreadIDs[i])) == NULL)
			ExitSys("CreateThread");
	}

	WaitForMultipleObjects(NTHREADS, hThreads, TRUE, INFINITE);

	return 0;
}


DWORD __stdcall ThreadProc(LPVOID lpvParam)
{
	int i;
	LPCSTR lpszThreadName = (LPCSTR)lpvParam;

	for (i = 0; i < 10; ++i) {
		if (rand() % 2 == 0)
			Write(lpvParam);
		else
			Read(lpvParam);
	}

	free(lpvParam);

	return 0;
}

void Read(LPCSTR lpszThreadName)
{
	AcquireSRWLockShared(&g_srwLock);
	printf("%s READING starts...\n", lpszThreadName);
	Sleep(rand() % 50);
	printf("%s READING ends...\n", lpszThreadName);
	ReleaseSRWLockShared(&g_srwLock);
}

void Write(LPCSTR lpszThreadName)
{
	AcquireSRWLockExclusive(&g_srwLock);
	printf("%s WRITING starts...\n", lpszThreadName);
	Sleep(rand() % 50);
	printf("%s WRINTING ends...\n", lpszThreadName);
	ReleaseSRWLockExclusive(&g_srwLock);
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	POSIX sistemlerinde okuma yazma kilitlerine örnek.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define NTHREADS				30
#define MAX_THREAD_NAME			32

void *thread_proc(void *param);
void read_resource(const char *name);
void write_resource(const char *name);
void exit_errno(const char* msg, int result);

pthread_rwlock_t g_rwlock;

int main(int argc, char *argv[])
{
	int result;
	pthread_t tids[NTHREADS];
	int i;
	char *name;

	srand(time(NULL));

	if ((result = pthread_rwlock_init(&g_rwlock, NULL)) != 0)
		exit_errno("pthread_rwlock_init", result);

	for (i = 0; i < NTHREADS; ++i) {
		if ((name = (char *)malloc(MAX_THREAD_NAME)) == NULL) {
			fprintf(stderr, "cannot allocate memory!..\n");
			exit(EXIT_FAILURE);
		}
		sprintf(name, "Thread-%d", i + 1);
		if ((result = pthread_create(&tids[i], NULL, thread_proc, name)) != 0)
			exit_errno("pthread_create", result);
	}

	for (i = 0; i < NTHREADS; ++i)
		pthread_join(tids[i], NULL);

	pthread_rwlock_destroy(&g_rwlock);

	return 0;
}

void *thread_proc(void *param)
{
	int i;

	for (i = 0; i < 10; ++i) {
		if (rand() % 2 == 0)
			write_resource(param);
		else
			read_resource(param);
	}

	free(param);

	return NULL;
}

void read_resource(const char *name)
{
	pthread_rwlock_rdlock(&g_rwlock);
	printf("%s READING starts...\n", name);
	usleep(rand() % 1000000);
	printf("%s READING ends...\n", name);
	pthread_rwlock_unlock(&g_rwlock);
}

void write_resource(const char *name)
{
	pthread_rwlock_wrlock(&g_rwlock);
	printf("%s WRITING starts...\n", name);
	usleep(rand() % 100000);
	printf("%s WRITING ends...\n", name);
	pthread_rwlock_unlock(&g_rwlock);
}

void exit_errno(const char *msg, int result)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(result));

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Liux sistemlerinde durum değişkenleri (condiitonal variable) belli bir koşiul sağlalanana kadar bloke oluşturmak için kullanılmaktadır. 
	Durum değişkenleri tek başlarına kullanılmazlar. Mutlaka mutex nesneleriyle birlikte kullanılırlar. 
	Tipik olarak kullanım kalıbı şöyledir:

	pthread_mutex_lock(&g_mutex);

	while (koşul sağlanmadığı sürece)
		pthread_cond_wait(&g_cond, g_mutex);

	pthread_mutex_unlock(&g_mutex);

	pthread_cond_wait uykuya dalmadan önce atomik bir biçimde mutex'in sahipliğini bırakmaktadır. Bu biçimde uykuya dalmış olan tthread'ler 
	pthread_cond_signal ya da pthread_cond_broadcast fonksiyonlarıyla uyandırılır. pthread_cond_signal tek bir thread'i (onun hangisi olacağı belli değildir)
	uyandırırken pthread_cond_broadcast uykuya dalmış olan tüm thread'leri uyandırır. Ancak pthread_cond_wait fonksiyonundan thread iki aşamda çıkmaktadır. 
	Önce uykudan uyanı. Bu uyanma işlemi durum değişkeni yoluyla gerçekleşir. Ancak thread uykudan uyandıktan sonra mutex'in sahipliğini pthread_mutex_lock 
	ile almaya çalışır. Mutex'in sahipliğini aldıktan sonra pthread_cond_wait geri döner. Böylece pthread_cond_broadcast yapıldığında durum değişkenini bekleyen
	tüm thread'ler uyansa da bunlardan yalnızca biri mutex sahipliğini alarak ptthread_cond_wait fonksiyonundan çıkar. Ancak thread'ler uyanmışlardır.
	Fakat pthread_mutex_lock yüzünden beklemektedirler. Tabii mutex'in sahipliğini alabilen thread pthread_mutex_unlock yağınca bu sefer bekleyenlerden biri 
	pthread_mutex_wait fonksiyonundan çıkar. Böylece aslında pthread_cond_broadcast sonrasında tüm thread'ler teker pthread_cond_wait'ten çıkmış olurlar.
	Ancak bir thread'in pthread_cond_wait fonksiyonundan çıkmış olması koşul sağlandığı anlamına gelmemektedir. Eğer koşul sağlanmamışsa while döngüsü yüzünden 
	thread yeniden durum değişkeni yoluyla uykuya dalar. Uyandırma işleminin yine mutex yoluyla yapılması tavsiye edilir. Örneğin:

	pthread_mutex_lock(&g_mutex);

	g_condition = 1;

	pthread_cond_broadcast(&g_cond);

	pthread_mutex_unlock(&g_mutex);

	Tabii bu işlemin her zaman kritik kod bloğu içeisinde yapılmasına gerek olmayabilir. Ancak koşul değişkeninin set edilmesiyle uyandırma işleminin
	kesilmeden yapılması gerekebilemketedir. Aşağıdaki örnekte thread'lerden biri g_condition == 1 durumunda diğeri g_condition == 2 durumunda yoluna
	devam etmektedir. 

	Maalesef durum değişkeni kullanan sistemlerde pthread_cond_wait gibi durum değişkenini bekleyen fonksiyonlar gereksiz durumlarda da uyandırılabilmektedir.
	Bu gereksiz uyandırmaya "spurious wakeup" denilmektedir. Bu gereksiz uyandırma bazen ptherad_cond_signal yapılması durumunda aslında tek bir thread'in değil de 
	birden fazla thread'in uyandırılması gibi de ortaya çıkmaktadır. Bazen de sistem başka bir nedenden dolayı thread'i gereksiz uyandırabilemketir. Bu nedenle
	mutlaka pthread_cond_wait fonksiyonunun while döngüsü içerisinde çağrılması önerilmektedir. 

-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *thread_proc1(void* param);
void *thread_proc2(void* param);
void exit_errno(const char* msg, int result);

pthread_cond_t g_cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;

int g_condition = 0;

int main(void)
{
	int result;
	pthread_t tid1, tid2;

	if ((result = pthread_create(&tid1, NULL, thread_proc1, NULL)) != 0)
		exit_errno("pthread_create", result);

	if ((result = pthread_create(&tid2, NULL, thread_proc2, NULL)) != 0)
		exit_errno("pthread_create", result);

	printf("press ENTER to continue...\n");
	getchar();

	if ((result = pthread_mutex_lock(&g_mutex)))
		exit_errno("pthread_mutex_lock", result);

	g_condition = 1;

	if ((result = pthread_cond_broadcast(&g_cond)) != 0)
		exit_errno("pthread_cond_signal", result);

	if ((result = pthread_mutex_unlock(&g_mutex)))
		exit_errno("pthread_mutex_unlock", result);


	printf("press ENTER to continue...\n");
	getchar();

	if ((result = pthread_mutex_lock(&g_mutex)))
		exit_errno("pthread_mutex_lock", result);

	g_condition = 2;

	if ((result = pthread_cond_broadcast(&g_cond)) != 0)
		exit_errno("pthread_cond_signal", result);

	if ((result = pthread_mutex_unlock(&g_mutex)))
		exit_errno("pthread_mutex_unlock", result);

	printf("press ENTER to exit...\n");
	getchar();

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	pthread_mutex_destroy(&g_mutex);
	pthread_cond_destroy(&g_cond);

	return 0;
}

void *thread_proc1(void *param)
{
	int result;

	if ((result = pthread_mutex_lock(&g_mutex)) != 0)
		exit_errno("pthread_mutex_lock", result);

	while (g_condition != 1)
		if ((result = pthread_cond_wait(&g_cond, &g_mutex)) != 0)
			exit_errno("pthread_cond_wait", result);

	printf("thread_proc1 ---> Koşul sağlandı...\n");

	if ((result = pthread_mutex_unlock(&g_mutex)) != 0)
		exit_errno("pthread_mutex_lock", result);

	return NULL;
}

void *thread_proc2(void *param)
{
	int result;

	if ((result = pthread_mutex_lock(&g_mutex)) != 0)
		exit_errno("pthread_mutex_lock", result);

	while (g_condition != 2)
		if ((result = pthread_cond_wait(&g_cond, &g_mutex)) != 0)
			exit_errno("pthread_cond_wait", result);

	printf("thread_proc2 ---> Koşul sağlandı...\n");

	if ((result = pthread_mutex_unlock(&g_mutex)) != 0)
		exit_errno("pthread_mutex_lock", result);

	return NULL;
}

void exit_errno(const char *msg, int result)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(result));

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde durumm değişkenleri daha çok aynı prosesin thread'leri arasında kullanılıyor olsa da aslında da kullanılabilir. 
	Tabii bu durumda durum değişkenin ve mutex nesnesinin paylaşılan bellek alanı üzerinde yatrılmaları ve yaratım sırasında attribute nesnesi ile 
	prosesler arası kullanım durumu set edilmelidir. Bu işlem mutex nesnelerindekine benzer biçimde yapılmaktadır:

	pthread_cond_t g_cond;
	...
	pthread_condattr_t attr;

	pthread_condattr_init(&attr);
	pthread_condattr_setpshared(&attr, 1);
	pthread_cond_init(&g_cond, &attr);
	pthread_condattr_destroy(&attr);

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	Belli bir zamand Windows sistemlerine de durum değişkenleri eklenmiştir. Windows sistemlerindeki durum değişkenleri mutex'lerle değil
	CRITICAL_SECTION ve Read/Write Lock nesneleriyle kullanılabilmektedir. Genel kullanım biçimi UNIX/Linux sistemlerindekine çok benzemektedir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	ÇOk işlemcili ya da çok çekirdekli sistemlerde bir işlemci ya da çekirdek bir makine komutunda bir RAM okuması ya da yazması yapıyorsa
	diğer işlemci ya da çekirdek aynı RAM adresinden okuma ya da yazma yaparsa belli koşullarda oradaki bilgi bozulabilir ya da bilgi yanlış 
	okunabilir. Yani örneğin Intel işlemcilerinde tel bir MOV makine komutu ile iki işlemci ya da çekirdek RAM'de aynı adrese yazma yaparsa 
	(ya da biri yazma yaparken diğeri okuma yaparsa) bus çakışması yüzünden okuma ya da yazma işleminde bozuk veriler oluşabilmektedir. Bunu engellemek için
	işlemcilerde özel makine komutları bulundurulmuştur. İşte bu tür basit işlemlerin gereksiz bir biçimde kritik kod altında yapılması yerine bu özel makine
	komutlarını kullanan birtakım fonksiyonlarla yapılması uygun olur. Microsoft Windows sistemlerinde InterlockedXXX biçiminde bir grup fonksiyon 
	blundurmuştur. 

	Aşağıdaki örnekte Windows'un InterlockedIncrement fonksiyonu ile global bir değişken iki thread'de çok çekirdekli ssitemler de dahil olmak üzere
	atomik bir biçimde artırılmıştır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);
DWORD __stdcall ThreadProc1(LPVOID lpvParam);
DWORD __stdcall ThreadProc2(LPVOID lpvParam);

long g_count;

int main(void)
{
	HANDLE hThread1, hThread2;
	DWORD dwThreadID1, dwThreadID2;

	if ((hThread1 = CreateThread(NULL, 0, ThreadProc1, NULL, 0, &dwThreadID1)) == NULL)
		ExitSys("CreateThread");

	if ((hThread2 = CreateThread(NULL, 0, ThreadProc2, NULL, 0, &dwThreadID2)) == NULL)
		ExitSys("CreateThread");

	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);

	printf("%ld\n", g_count);

	return 0;
}

DWORD __stdcall ThreadProc1(LPVOID lpvParam)
{
	long i;

	for (i = 0; i < 1000000; ++i)
		_InterlockedIncrement(&g_count);

	return 0;
}

DWORD __stdcall ThreadProc2(LPVOID lpvParam)
{
	long i;

	for (i = 0; i < 1000000; ++i)
		_InterlockedIncrement(&g_count);

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	C11 ile birlikte C'ye isteğe bağlı olarak _Atomic biçiminde bir tür belirleyicisi ve niteleyicisi eklenmiştir. _ATomic ile tanımlanan 
	nesnlerken derleyici tarafından çok işlemcili sistemlerde atomik işlem yapacak biçimde kod üretilir. Tabii _Atomic atomic yapılamayack işlemlerde
	bir etk,i göstermemektedir. Bir C11 derleyicisinin _Atomic belirleyicisini türünü destekleyip desteklemediği __STDC_NO_ATOMICS__  makrosuna
	bakılarak belirlenebilir. Microsoft C derleyicileri _Atomic belirleyicisini desteklememektedir. Ancak gcc derleyicileri belli bir sürümden
	sonra bu belirleyiciyi desteklemektedir. 

	Aşağıdaki örnekte g_count _Atomic ile tanımlandığı için zaten ++g_count işlemi derleyici tarafından atomik bir biçimde yapılacaktır. 
	Başka bir deyişle derleyici bu değişken işleme sokulurken onu tek bir makine komutuyla ve lock işlemi ile işleme sokmaktadır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *thread_proc1(void* param);
void *thread_proc2(void* param);
void exit_errno(const char* msg, int result);

_Atomic int g_count;

int main(void)
{
	int result;
	pthread_t tid1, tid2;

	if ((result = pthread_create(&tid1, NULL, thread_proc1, NULL)) != 0)
		exit_errno("pthread_create", result);

	if ((result = pthread_create(&tid2, NULL, thread_proc2, NULL)) != 0)
		exit_errno("pthread_create", result);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	printf("%d\n", g_count);

	return 0;
}

void *thread_proc1(void *param)
{
	int i;

	for (i = 0; i < 1000000; ++i)
		++g_count;

	return NULL;
}

void *thread_proc2(void *param)
{
	int i;

	for (i = 0; i < 1000000; ++i)
		++g_count;

	return NULL;
}

void exit_errno(const char *msg, int result)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(result));

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	C++'ta C'nin _Atomic beelirleyicisi yoktur. Atomik işlemler <atomic> başlık dosyasında bildirilen std::atomic<T> sınıfyla yapılmaktadır.
	Bu sınıfın operatör fonksiyonları gerçekten çok işlemcili sistemler için atomik işlemler yapmaktadır. Dolayısıyla C++'da yukarıdaki işlemlerin
	eşdeğerleri şöyle oluşturulabilir:
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <atomic>
#include <pthread.h>

void *thread_proc1(void* param);
void *thread_proc2(void* param);
void exit_errno(const char* msg, int result);

using namespace std;

atomic<int> g_count;

int main(void)
{
	int result;
	pthread_t tid1, tid2;

	if ((result = pthread_create(&tid1, NULL, thread_proc1, NULL)) != 0)
		exit_errno("pthread_create", result);

	if ((result = pthread_create(&tid2, NULL, thread_proc2, NULL)) != 0)
		exit_errno("pthread_create", result);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	printf("%d\n", static_cast<int>(g_count));

	return 0;
}

void *thread_proc1(void *param)
{
	int i;

	for (i = 0; i < 1000000; ++i)
		++g_count;

	return NULL;
}

void *thread_proc2(void *param)
{
	int i;

	for (i = 0; i < 1000000; ++i)
		++g_count;

	return NULL;
}

void exit_errno(const char *msg, int result)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(result));

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Genel olarak static data kullanan fonksiyonlar thread güvenli olmazlar. Bunları thread güvenli hale getirmek için static data kullanma durumunu
	ortadan kaldırmak gerekir. Aşağıdaki örnekte myitoa thread güvenli değildir ancak myitoa_tsafe thrad güvenlidir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

char *myitoa(int a)
{
	static char buf[32];

	sprintf(buf, "%d", a);

	return buf;
}

char *myitoa_tsafe(char *str, int a)
{
	sprintf(str, "%d", a);

	return str;
}

int main(void)
{
	char s[32];
	char *str;

	str = myitoa(1234);
	puts(str);

	myitoa_tsafe(s, 1234);
	puts(s);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Microsoft 2005 yılına kadar standart C kütüphanesinin thread güvenli olan ve thread güvenli olmayan iki farklı versiyonuu bulundurmaktaydı. 
	Ancak 2005'ten itibaren tek bir standart C kütüphanesi bulundurmaya başlamıştır. O da thread güvenli, kütüphanedir. POSIX sistemlerinde static data 
	kullanan sorunlu standart C fonksiyonlarının hepsinin xxxx_r isimli thread güvenli bir versiyonu bulundurulmuştur. Bu versiyonlar genel olarak 
	static data kullanmak yerine ekstra bir parametre ile static data için kullanılacak alanı fonksiyonu çağırandan istemeketdir. 

	Aşağıdaki örnekte ctime fonksiyonun thread güvenli versiyonu olan ctime_r fonksiyonu kullanılmıştır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

void *thread_proc1(void* param);
void *thread_proc2(void* param);
void foo(void);
void exit_errno(const char* msg, int result);

int main(void)
{
	int result;
	pthread_t tid1, tid2;

	if ((result = pthread_create(&tid1, NULL, thread_proc1, NULL)) != 0)
		exit_errno("pthread_create", result);

	if ((result = pthread_create(&tid2, NULL, thread_proc2, NULL)) != 0)
		exit_errno("pthread_create", result);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	return 0;
}

void foo(void)
{
	time_t t;
	char s[64];

	t = time(NULL);
	ctime_r(&t, s);

	printf("%s", s);
}

void *thread_proc1(void *param)
{
	foo();

	return NULL;
}

void *thread_proc2(void *param)
{
	foo();

	return NULL;
}

void exit_errno(const char *msg, int result)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(result));

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	C++'da C++11 ile birlikte standart zorunlu bir thread kütüphanesi oluşturulmuştur. Tabii aslında bu kütüphane Windows sistemlerinde Windows API
	fonksiyonlarını, UNIX/Linux sistemlerinde POSIX'in pthread fonksiyonalrını kullanmatadır. Yalnızca arayüz standart hale getirilmiştir. 

	Aşağıda C++'da thread yaratımına bir örnek verilmiştir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <thread>

using namespace std;

class Sample {
public:
	Sample(const char *name) : m_name(name)
	{}
	void operator()()
	{
		cout << m_name + "\n";
	}
private:
	string m_name;
};

void thread_proc1()
{
	cout << "thread-1 running...\n";
}

void thread_proc2()
{
	cout << "thread-2 running...\n";;
}

int main(void)
{
	Sample s1("thread-1"), s2("thread-2");

	thread t1(s1);
	thread t2(s2);
	thread t3(thread_proc1);
	thread t4(thread_proc1);

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Genel olarak C++'ın sınıfları aynı nesne üzerinde okuma konusunda thread güvenli ancak yazma konusunda thread güvenli değildir. 
	Fakat hem farklı nesneler üzerinde okuma ve yazma işlemleri thread güvenlidir. Bunların standartlarda bu anlamda thread güvenli versionları yoktur.
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	C'nin standart FILE stream işlemlerinin thread güvenli olup olmadığı hakkında da bir şey söylenmemiştir. Ancak hem Microsoft kütüphanesi hem de
	GNU kütüphanesi FILE stream işlemlerini thread güveli yapmaktadır. Yani iki ayrı tread global bir stream nesnesi üzerinde işlem yapıyorsa kullanılan
	tampon bu fonskiyonlar tarafından kritik kodlarla korunmuş durumdadır. İç içe geçme durumu oluşmamatadır. Benzer biçimde C++'ın <iostream> kürüphanesi de
	aynı dosya üzerinde işlem yapılırken bile thread güvenlidir. Ancak standartlar bunu garanti etmemktedir. 

	Aşağıdaki örnekte hem Windows hem de UNIX/Linux sistemlerinde stdio fonksiyonları kendi içerisinde tampona yazma sırasında kritik kod oluşturmaktadır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);
DWORD __stdcall ThreadProc1(LPVOID lpvParam);
DWORD __stdcall ThreadProc2(LPVOID lpvParam);

FILE *g_f;

int main(void)
{
	HANDLE hThread1, hThread2;
	DWORD dwThreadID1, dwThreadID2;

	if ((g_f = fopen("test.txt", "w")) == NULL) {
		fprintf(stderr, "cannot open file!..\n");
		exit(EXIT_FAILURE);
	}

	if ((hThread1 = CreateThread(NULL, 0, ThreadProc1, NULL, 0, &dwThreadID1)) == NULL)
		ExitSys("CreateThread");

	if ((hThread2 = CreateThread(NULL, 0, ThreadProc2, NULL, 0, &dwThreadID2)) == NULL)
		ExitSys("CreateThread");

	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);

	return 0;
}

DWORD __stdcall ThreadProc1(LPVOID lpvParam)
{
	int i;

	for (i = 0; i < 1000; ++i)
		fprintf(g_f, "Thread-1\n");

	return 0;
}

DWORD __stdcall ThreadProc2(LPVOID lpvParam)
{
	int i;

	for (i = 0; i < 1000; ++i)
		fprintf(g_f, "Thread-2\n");

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	C++'ın iostream kütüphanesi de genel olarak Microsoft ve UNIX/Linux sistemlerinde thread güvenli yazılmıştır. Ancak standartlar bağlamında 
	bunun için bir garanti bulunmamaktadır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <fstream>
#include <thread>

using namespace std;

fstream g_f;

void thread_proc1()
{
	for (int i = 0; i < 1000; ++i)
		g_f << "thread-1 running...\n";
}

void thread_proc2()
{
	for (int i = 0; i < 1000; ++i)
		g_f << "Thread-2 running...\n";
}

int main(void)
{
	g_f.open("test.txt", ios::out);

	thread t1(thread_proc1);
	thread t2(thread_proc2);

	t1.join();
	t2.join();

	g_f.close();

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Öte yandan Windows sistemlerindeki ReadFile ve WriteFile API fonksiyonları, UNIX/Linux sistemlerindeki read ve write POSIX fonksiyonları
	işletim sisteminin sistem fonksiyonlarını doğrudan çağırmaktadır. İşletim s,isteminin sistem fonksiyonalrı da okuma ve yazma bağlamında sistem 
	genelinde atomiltir. Bunun anlamı şudur: Biz iki farklı thread'ten ya da prosesten aynı dosyaya, dosyanın aynı yerine aynı anda yazma ya da okuma 
	yapsak bile iç içe geçme asla oluşmaz. Bu durum kernel tarafından senkronize edilmektedir. Örneğin thread ya da proseslerden biri tam bir dosyanın
	belli bir offset'ine WriteFile ya da write fonksiyonuyla 100 byte yazıyor olsun. Tam o sırada aynı offset'ten başka bir thread ya da proses 100 byte
	okuyaacak olsun. Bu durumda okuyan taraf ya 100 yazılmadan önceki 100 byte'ı okur ya da diğerinin yazdığı 100 byte'ı okur. Ancak asla yarısı eski 100
	byte'tan yarısı diğerinin yazdığı 100 byte'tan oluşan bir 100 byte okumaz. Benzer biçimde iki thread ya da proses WriteFile ya da write ile aynı dosyanın aynı offset'ine
	yazıyor bile olsa iç içe geçme olmaz. Nihai durumda ya birinin ya da diğerinin tam yazdığı şeyle dosyada gözükür. Tabii birden fazla read ya da write işlemi
	sırasında bu işlemler iç içe geçebilir. Örneğin:

	thread-1

	write(..)
	write(...)

	thread-2
	
	write(...)
	write(...)

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows'ta Thread Local Storage kullanımına bir örnek
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);
DWORD __stdcall ThreadProc1(LPVOID lpvParam);
DWORD __stdcall ThreadProc2(LPVOID lpvParam);
BOOL InitTls(int val, const char *buf);
void Foo(void);

DWORD g_tlsSlot;

typedef struct tagSTATIC_DATA {
	int val;
	char buf[32];
} STATIC_DATA;

int main(void)
{
	HANDLE hThread1, hThread2;
	DWORD dwThreadID1, dwThreadID2;

	if ((g_tlsSlot = TlsAlloc()) == TLS_OUT_OF_INDEXES)
		ExitSys("TlsAlloc");

	if ((hThread1 = CreateThread(NULL, 0, ThreadProc1, NULL, 0, &dwThreadID1)) == NULL)
		ExitSys("CreateThread");

	if ((hThread2 = CreateThread(NULL, 0, ThreadProc2, NULL, 0, &dwThreadID2)) == NULL)
		ExitSys("CreateThread");

	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);

	TlsFree(g_tlsSlot);

	return 0;
}

DWORD __stdcall ThreadProc1(LPVOID lpvParam)
{
	if (!InitTls(100, "Thread-1"))
		ExitSys("InitTls");

	Foo();

	return 0;
}

DWORD __stdcall ThreadProc2(LPVOID lpvParam)
{
	if (!InitTls(200, "Thread-2"))
		ExitSys("InitTls");

	Foo();

	return 0;
}

BOOL InitTls(int val, const char *buf)
{
	STATIC_DATA *psd;

	if ((psd = (STATIC_DATA *)malloc(sizeof(STATIC_DATA))) == NULL)
		return FALSE;

	psd->val = val;
	strcpy(psd->buf, buf);

	if (!TlsSetValue(g_tlsSlot, psd))
		return FALSE;

	return TRUE;
}

void Foo(void)
{
	STATIC_DATA *psd;

	if ((psd = (STATIC_DATA *)TlsGetValue(g_tlsSlot)) == NULL)
		ExitSys("TlsGetValue");

	printf("%d %s\n", psd->val, psd->buf);
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Standart C kütüphanesi fonksiyonların parametrik yapılarını değiştirmeden nasıl thread güvenli hale getirilir? 
	İşte böyle bir faaliyette bazı fonksiyonlar statik nesneleri kullanmak yerine TLS içerisindeki nesneleri kullanmalıdırlar. Aşağıdaki örnekte
	bu işlemin mantıksal olarak nasıl yapılabileceği gösterilmiştir. Bu örnekte thread güvenli kütüphanee için programın başında ve sonunda, her thread'in
	başında ve sonunda init ve exit fonksiyonların çağrılması gerekmektedir. Aslında bu çağrılar programcıdan gizlenebilir. Şöyle ki: Eğer dinamik kütüphane söz
	konusuysa dinamik kütüphanenin bazı fonksiyonları bu tür durumlarda otomatik olarak çağrılmaktadır. İşte programcı da bu kodları aslında kendi kütüphanesinin
	içerine alabilmektedir. Ancak statik kütüphanelerde böyle bir callback mekanizması yoktur. Microsoft bunun için standart C kütüphanesinin
	statik versiyonunu yazarken mecburen sarma thread fonksiyonları kullanmıştır. _beginthreadex fonksiyonu statik standart C kütüphanesi kullanılacaksa
	thread yaratmak için tercih edilmelidir.Bu fonksiyon aslında arka planda CreateThread API fonksiyonunı zaten çağırmaktadır. Ancak threda yaratılmadan önce ve
	thread sonlanırken aşağıdaki kodda bulunan init exit fonksiyonları bu sarma fonksiyon tarafından çağrılır. Benzer biçimde eğer Microsoft sistemlerinde
	eğer statik kütüphane kullanılıyorsa thread sonlanırken _endthreadex fonksiyonu çağrılmalıdır. Dinamik kütüphanelerde bu sarma fonksiyonların 
	kullanılmasına gerek yoktur. Ayrıca gcc derleyicilerinde standart C fonksiyonlarının thread güvenli olmadığını bunların thread güvenli versiyonlarının 
	farklı parametrik yapılarla statik nesne kullanamayack biçimde xxxxx_r ismiyle yazıldığını anımsayınız. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* cstdlib.h */

#ifndef CSTDLIB_H_
#define CSTDLIB_H_

#include <stddef.h>

/* Type Definitions */

typedef struct tagCSTDLIB_STATIC_DATA {
	char *strtok_pos;
	size_t rand_next;
} CSTDLIB_STATIC_DATA;

/* Function Prototypes */

int init_cstdlib(void);
void exit_cstdlib(void);
int init_csdlib_thread(void);
int exit_csdlib_thread(void);
char *csd_strtok(char *str, const char *delim);
void csd_srand(size_t seed);
int csd_rand(void);

#endif

/* cstdlib.c */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "cstdlib.h"

static DWORD g_cstdSlot;

int init_cstdlib(void)
{
	CSTDLIB_STATIC_DATA *clib;

	if ((g_cstdSlot = TlsAlloc()) == TLS_OUT_OF_INDEXES)
		return 0;

	return 1;
}

int init_csdlib_thread(void)
{
	CSTDLIB_STATIC_DATA *clib;

	if ((clib = (CSTDLIB_STATIC_DATA *)malloc(sizeof(CSTDLIB_STATIC_DATA))) == NULL) {
		TlsFree(g_cstdSlot);
		return 0;
	}

	clib->rand_next = 1;

	if (!TlsSetValue(g_cstdSlot, clib))
		return 0;
}

int exit_csdlib_thread(void)
{
	CSTDLIB_STATIC_DATA *clib;

	if ((clib = (CSTDLIB_STATIC_DATA *)malloc(sizeof(CSTDLIB_STATIC_DATA))) == NULL) {
		TlsFree(g_cstdSlot);
		return 0;
	}

	free(clib);
}

void exit_cstdlib(void)
{
	TlsFree(g_cstdSlot);
}

char *csd_strtok(char *str, const char *delim)
{
	CSTDLIB_STATIC_DATA *clib;
	char *beg;

	if ((clib = TlsGetValue(g_cstdSlot)) == NULL)
		return NULL;

	if (str != NULL)
		clib->strtok_pos = str;

	while (*clib->strtok_pos != '\0' && strchr(delim, *clib->strtok_pos) != NULL)
		++clib->strtok_pos;
	if (*clib->strtok_pos == '\0')
		return NULL;
	beg = clib->strtok_pos;
	while (*clib->strtok_pos != '\0' && strchr(delim, *clib->strtok_pos) == NULL)
		++clib->strtok_pos;
	if (*clib->strtok_pos != '\0')
		*clib->strtok_pos++ = '\0';

	return beg;
}

void csd_srand(size_t seed)
{
	CSTDLIB_STATIC_DATA *clib;

	if ((clib = TlsGetValue(g_cstdSlot)) == NULL)
		return NULL;

	clib->rand_next = seed;
}

int csd_rand(void)
{
	CSTDLIB_STATIC_DATA *clib;

	if ((clib = TlsGetValue(g_cstdSlot)) == NULL)
		return NULL;

	clib->rand_next = clib->rand_next * 1103515245 + 12345;

	return (unsigned int)(clib->rand_next / 65536) % 32768;
}

/* Sample.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "cstdlib.h"

void ExitSys(LPCSTR lpszMsg);
DWORD __stdcall ThreadProc1(LPVOID lpvParam);
DWORD __stdcall ThreadProc2(LPVOID lpvParam);

int main(void)
{
	HANDLE hThread1, hThread2;
	DWORD dwThreadID1, dwThreadID2;

	if (!init_cstdlib()) {
		fprintf(stderr, "cannot initialize CSD Standard C Library!..\n");
		exit(EXIT_FAILURE);
	}

	if ((hThread1 = CreateThread(NULL, 0, ThreadProc1, NULL, 0, &dwThreadID1)) == NULL)
		ExitSys("CreateThread");

	if ((hThread2 = CreateThread(NULL, 0, ThreadProc2, NULL, 0, &dwThreadID2)) == NULL)
		ExitSys("CreateThread");

	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);

	exit_cstdlib();

	return 0;
}

DWORD __stdcall ThreadProc1(LPVOID lpvParam)
{
	char s[] = "ali, veli, selami, ayşe, fatma";
	char *str;
	int i, val;

	if (!init_csdlib_thread()) {
		fprintf(stderr, "CSDLib initialization failed!..\n");
		exit(EXIT_FAILURE);
	}

	for (str = csd_strtok(s, ", "); str != NULL; str = csd_strtok(NULL, ", "))
		printf("threadproc1 --> %s\n", str);

	for (i = 0; i < 10; ++i) {
		val = csd_rand();
		printf("threadproc1_rand --> %d\n", val);
	}

	exit_csdlib_thread();

	return 0;
}

DWORD __stdcall ThreadProc2(LPVOID lpvParam)
{
	char s[] = "adana, izmir, balikesir, muğla";
	char *str;
	int i, val;

	if (!init_csdlib_thread()) {
		fprintf(stderr, "CSDLib initialization failed!..\n");
		exit(EXIT_FAILURE);
	}

	for (str = csd_strtok(s, ", "); str != NULL; str = csd_strtok(NULL, ", "))
		printf("threadproc2 --> %s\n", str);

	for (i = 0; i < 10; ++i) {
		val = csd_rand();
		printf("threadproc2_rand --> %d\n", val);
	}

	exit_csdlib_thread();

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde thread'e özgü statik alanlara Thread Specific Data (TSD) denilmektedir. Genel kullanım biçimi Windows sistemlerindekilere
	oldukça benzemektedir. Önce pthread_key_create fonksiyonu ile bir slot yaratılır. Burada slot yerine anahtar (key) terimni kullanılmaktadır.
	Sonra bu anahtar ile pthread_setspecific fonksiyonu ile set işlemi, pthread_getspecific fonksiyonu ile de get işlemi yapılır. En sonunda oluşturulan
	anahtar pthread_key_delete fonksiyonuyla yok edilir. pthread_key_create fonksiyonunda bir destructor fonksiyonu da verilebilmektedir. Bu fonksiyon
	thread yok edilirken anahtara set edilmiş olan değerle çağrılmaktadır. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void* thread_proc1(void* param);
void* thread_proc2(void* param);
void init_tsd(int val, const char* buf);
void foo(void);
void exit_errno(const char* msg, int result);
void key_destructor(void* value);

typedef struct tagSTATIC_DATA {
	int val;
	char buf[32];
} STATIC_DATA;

pthread_key_t g_tsdkey;

int main(void)
{
	int result;
	pthread_t tid1, tid2;

	if ((result = pthread_key_create(&g_tsdkey, key_destructor)) != 0)
		exit_errno("pthread_key_create", result);

	if ((result = pthread_create(&tid1, NULL, thread_proc1, NULL)) != 0)
		exit_errno("pthread_create", result);

	if ((result = pthread_create(&tid2, NULL, thread_proc2, NULL)) != 0)
		exit_errno("pthread_create", result);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	pthread_key_delete(g_tsdkey);

	return 0;
}

void* thread_proc1(void* param)
{
	init_tsd(100, "Thread-1");

	foo();

	return NULL;
}

void* thread_proc2(void* param)
{
	init_tsd(200, "Thread-2");;

	foo();

	return NULL;
}

void init_tsd(int val, const char* buf)
{
	STATIC_DATA* psd;
	int result;

	if ((psd = (STATIC_DATA*)malloc(sizeof(STATIC_DATA))) == NULL) {
		fprintf(stderr, "cannot allocate memory!..\n");
		exit(EXIT_FAILURE);
	}

	psd->val = val;
	strcpy(psd->buf, buf);

	if ((result = pthread_setspecific(g_tsdkey, psd)) != 0)
		exit_errno("pthread_setspecific", result);
}

void foo(void)
{
	STATIC_DATA* psd;

	if ((psd = (STATIC_DATA*)pthread_getspecific(g_tsdkey)) == NULL) {
		fprintf(stderr, "cannot get thread specific data!..\n");
		exit(EXIT_FAILURE);
	}

	printf("%d %s\n", psd->val, psd->buf);
}

void key_destructor(void* value)
{
	free(value);
}

void exit_errno(const char* msg, int result)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(result));

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows'ta bir thread'in [0-31] arasındaki önceliği iki değerin toplamıyla elde edilir. Taban değer prosesin önceli,k sınıfıyla belirlenir.
	Bu değere thread'in relative önceliği toplanır. Prosesin öncelik sınıfı GetPriorityClass API fonksiyonuyla alınıp SetPriorityClass API fonksiyonuyla
	set edilebilir. 

	Aşağıdaki örnekte prosesin öncelik sınıfı yazdırılmıştır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

LPCSTR GetPriorityClassName(DWORD dwPriority);
void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	DWORD dwPriorityClass;

	if ((dwPriorityClass = GetPriorityClass(GetCurrentProcess())) == 0)
		ExitSys("GetPriorityClass");

	puts(GetPriorityClassName(dwPriorityClass));

	return 0;
}

LPCSTR GetPriorityClassName(DWORD dwPriority)
{
	char* szName = "NONE";

	switch (dwPriority) {
	case ABOVE_NORMAL_PRIORITY_CLASS:
		szName = "ABOVE_NORMAL_PRIORITY_CLASS";
		break;
	case BELOW_NORMAL_PRIORITY_CLASS:
		szName = "BELOW_NORMAL_PRIORITY_CLASS";
		break;
	case HIGH_PRIORITY_CLASS:
		szName = "HIGH_PRIORITY_CLASS";
		break;
	case IDLE_PRIORITY_CLASS:
		szName = "IDLE_PRIORITY_CLASS";
		break;
	case NORMAL_PRIORITY_CLASS:
		szName = "NORMAL_PRIORITY_CLASS";
		break;
	case REALTIME_PRIORITY_CLASS:
		szName = "REALTIME_PRIORITY_CLASS";
		break;
	}

	return szName;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	GetThreadPriorty API fonksiyonu thread'in relative önceliğini elde etmek için kullanılır
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

LPCSTR GetThreadPriorityName(int threadPriority);
void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	int threadPriority;

	if ((threadPriority = GetThreadPriority(GetCurrentThread())) == THREAD_PRIORITY_ERROR_RETURN)
		ExitSys("GetPriorityClass");

	puts(GetThreadPriorityName(threadPriority));

	return 0;
}

LPCSTR GetThreadPriorityName(int threadPriority)
{
	char *szName = "NONE";

	switch (threadPriority) {
		case THREAD_PRIORITY_ABOVE_NORMAL:
			szName = "THREAD_PRIORITY_ABOVE_NORMAL";
			break;
		case THREAD_PRIORITY_BELOW_NORMAL:
			szName = "THREAD_PRIORITY_BELOW_NORMAL";
			break;
		case THREAD_PRIORITY_HIGHEST:
			szName = "THREAD_PRIORITY_HIGHEST";
			break;
		case THREAD_PRIORITY_IDLE:
			szName = "THREAD_PRIORITY_IDLE";
			break;
		case THREAD_PRIORITY_LOWEST:
			szName = "THREAD_PRIORITY_LOWEST";
			break;
		case THREAD_PRIORITY_NORMAL:
			szName = "THREAD_PRIORITY_NORMAL";
			break;
		case THREAD_PRIORITY_TIME_CRITICAL:
			szName = "THREAD_PRIORITY_TIME_CRITICAL";
			break;
	}
			
	return szName;	
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Aşağıdaki örnekte proesin ana thread'i maksimum öncelik olan 31 önceliğe çekilmiştir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	if (!SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS))
		ExitSys("SetPriorityClass");

	if (!SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL))
		ExitSys("SetThreadPriority");

	printf("Thread priority is 31\n");

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde tipik olarak SCHED_FIFO ve SCHED_RR politikalarının statik öncelik dereceleri [0, 99] arasındadır. SCHED_OTHER politikasının
	d,inamik öncelikleri ise [0, 39] arasındadır. Ancak bu değerler sched_get_priority_min ve sched_get_priority_max POSIX fonksiyonlarıyla
	alınabilmektedir. Linux SCHED_OTHER için bu işlemi yapmamakta ve 0 değeri vermektedir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void exit_sys(const char* msg);

int main(void)
{
	int prio;

	if ((prio = sched_get_priority_min(SCHED_RR)) == -1)
		exit_sys("sched_get_priority_min");

	printf("SCHED_RR Policy minimum static priority: %d\n", prio);

	if ((prio = sched_get_priority_max(SCHED_RR)) == -1)
		exit_sys("sched_get_priority_max");

	printf("SCHED_RR Policy maximum static priority: %d\n", prio);

	if ((prio = sched_get_priority_min(SCHED_FIFO)) == -1)
		exit_sys("sched_get_priority_min");

	printf("SCHED_FIFO Policy minimum static priority: %d\n", prio);

	if ((prio = sched_get_priority_max(SCHED_FIFO)) == -1)
		exit_sys("sched_get_priority_max");

	printf("SCHED_FIFO Policy maximum static priority: %d\n", prio);

	if ((prio = sched_get_priority_min(SCHED_OTHER)) == -1)
		exit_sys("sched_get_priority_min");

	printf("SCHED_OTHER Policy minimum static priority: %d\n", prio);

	if ((prio = sched_get_priority_max(SCHED_OTHER)) == -1)
		exit_sys("sched_get_priority_max");

	printf("SCHED_OTHER Policy maximum static priority: %d\n", prio);

	return 0;
}

void exit_sys(const char* msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde bir thread'in çizelgeleme politikasını ve önceliğini değiştirmek için pthread_setschedparam POSIX fonksiyonu kullanılmaktadır.
	Örneğin biz bir thread'in politikasını SCHED_FIFO yapıp onun statik önceliğini 99'a çekersek artık o thread ilgili CPU'yu tekeline alacaktır.
	Ancak bu durum yine de hard real time olayların izlenmesini garanti hale getirmemektedir. Her ne kadar o CPU'ya context switch yapılmayacaksa da 
	kesmeler akışı kısa sürelğine koparabilmektedir. 

	Aşağıdaki örnekte bir thread'in çizelgeleme politikası ve statik önceliği değiştirilmektedir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void* thread_proc(void* param);
void exit_errno(const char* msg, int result);

int main(void)
{
	int result;
	pthread_t tid;;

	if ((result = pthread_create(&tid, NULL, thread_proc, NULL)) != 0)
		exit_errno("pthread_create", result);

	pthread_join(tid, NULL);

	return 0;
}

void* thread_proc(void* param)
{
	struct sched_param sparam;
	int result;
	long i;

	sparam.sched_priority = 99;

	if ((result = pthread_setschedparam(pthread_self(), SCHED_FIFO, &sparam)) != 0)
		exit_errno("pthread_setschedparam", result);

	for (i = 0; i < 1000000000; ++i)
		;

	return NULL;
}

void exit_errno(const char* msg, int result)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(result));

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	SCHED_OTHER thread'lerin bir dinamik önceliği vardır. Bu dinamik öncelik onların ne kadar quanta süresi kullanacağı ile ilişkilendirilmiştir. 
	Pek çok UNIX türevi sistemde dinamik öncelikler [0-39] arasında bir değer almaktadır. Bir SCHED_OTHER prosesin dinamik önceliğini değiştirmek için
	nice isimli POSIX fonksiyonu kullanılır. Bu fonksiyonun thread'e özgü bir biçimi yoktur. POSIX standartlarına göre bir prosesin dinamik önceliği
	değiştirildiğinde o prosesin SCHED_OTHER çizelgeleme politikasına sahip tüm thread'lerinin dinamik önceliği değiştirilmektedir. nice fonksiyonunun
	int bir parametresi vardır. Bu parametre dinamik önceliğin ne kadar artırılıp eksiltileceğini belirtir. Ancak ters bir biçimde negatif değerler 
	artırma pozitif değerler eksiltme anlamına gelmektedir. Linux sistemlerinde bu fonksiyon [-20, +19] parametreleriyle çağrılır ve prosesinm default
	dinamik önceliği 19'dur. Fonksiyon set edilen yeni nice değerini vermektedir. -1 geri dönüş değeri hem geçerli bir değer hem de hata durumunu belirit.
	Bu nedenle önce errno değişkeni 0'a set edilmeli sonra başarısızlık durumunda 0 olup olmadığına bakılmalıdır. Linux sistemlerinde prosesin nice değeri
	değiştirildiğinde yalnızca prosesin ana thread'inin nice değeri değiştirilmektedir. Bu durum POSIX standartlarına uymamaktadır. 

	Aşağıdaki programda prosesin default değeri elde edilmiştir. Bu değer 0 olacaktır. Bu durumda dinamik öncelik 19 olur. Linux sistemlerinde tipik olarak
	her dinamik öncelik 10 mili saniye quanta'ya karşılık gelir. Bu durumda thread'lerin normal quanta süreleri 190 milisaniye olmaktadır. Bir prosesin dinamik önceliğini
	yükseltebilmesi için (yani nice fonksiyonunu negatif değerle çağırabilmesi için) proses id'sinin 0 olması gerekir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

void exit_sys(const char *msg);

int main(void)
{
	int result;

	errno = 0;
	if ((result = nice(0)) == -1 && errno != 0)
		exit_sys("nice");

	printf("%d\n", result);

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	getpriority fonksiyonun kullanımına bir örnek
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/resource.h>

void exit_sys(const char *msg);

int main(void)
{
	int result;

	errno = 0;
	if ((result = getpriority(PRIO_PROCESS, getpid())) == -1 && errno != 0)
		exit_sys("nice");

	printf("%d\n", result);

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	C'de Dinamk Dizi veri yapısının gerçekleştirimi
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* DynamicArray.h */

#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

/* Symbolic Constants */

#define DEF_CAPACITY	4
#define DARRAY_FAILED	((size_t)-1)

#include <stddef.h>

/* Type Declarations */

typedef int DATATYPE;

typedef struct tagDARRAY {
	DATATYPE *pArray;
	size_t size;
	size_t capacity;
} DARRAY, *HDARRAY;

/* Function Prototypes */

HDARRAY CreateDArray(void);
HDARRAY CreateDArrayWithCapacity(size_t capacity);
size_t AddItem(HDARRAY hDArray, DATATYPE val);
void DeleteItemIndex(HDARRAY hDArray, size_t index);
size_t DeleteItem(HDARRAY hDArray, DATATYPE val);
size_t InsertItem(HDARRAY hDArray, size_t index, DATATYPE val);
DATATYPE *FindItem(HDARRAY hDArray, DATATYPE val);
DATATYPE *FindItemLast(HDARRAY hDArray, DATATYPE val);
size_t SetCapacity(HDARRAY hDArray, size_t newCapacity);
void TrimToSize(HDARRAY hDArray);
void CloseDArray(HDARRAY hDArray);

/* Macros */

#define GetCapacity(hDArray)		((hDArray)->capacity)
#define GetSize(hDArray)			((hDArray)->size)
#define GetItem(hDArray, index)		((hDArray)->pArray[index])
#define Clear(hDArray)				((hDArray)->size = 0)

#endif

/* DynamicArray.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DynamicArray.h"

/* Function Definitions */

HDARRAY CreateDArray(void)
{
	return CreateDArrayWithCapacity(DEF_CAPACITY);
}

HDARRAY CreateDArrayWithCapacity(size_t capacity)
{
	HDARRAY hDArray;

	if ((hDArray = (HDARRAY)malloc(sizeof(DARRAY))) == NULL)
		return NULL;

	if ((hDArray->pArray = (DATATYPE *)malloc(sizeof(DATATYPE) * capacity)) == NULL) {
		free(hDArray);
		return NULL;
	}
	hDArray->capacity = capacity;
	hDArray->size = 0;

	return hDArray;
}

size_t AddItem(HDARRAY hDArray, DATATYPE val)
{
	if (hDArray->size == hDArray->capacity && SetCapacity(hDArray, hDArray->size * 2) == DARRAY_FAILED)
		return DARRAY_FAILED;

	hDArray->pArray[hDArray->size++] = val;

	return hDArray->size - 1;
}

size_t InsertItem(HDARRAY hDArray, size_t index, DATATYPE val)
{
	if (hDArray->size == hDArray->capacity && SetCapacity(hDArray, hDArray->size * 2) == DARRAY_FAILED)
		return DARRAY_FAILED;

	memmove(&hDArray->pArray[index + 1], &hDArray->pArray[index], (hDArray->size - index) * sizeof(DATATYPE));
	hDArray->pArray[index] = val;
	++hDArray->size;

	return index;
}

void DeleteItemIndex(HDARRAY hDArray, size_t index)
{
	memmove(&hDArray->pArray[index], &hDArray->pArray[index + 1], (hDArray->size - index - 1) * sizeof(DATATYPE));
	--hDArray->size;
}

size_t DeleteItem(HDARRAY hDArray, DATATYPE val)
{
	size_t i;

	for (i = 0; i < hDArray->size; ++i)
		if (hDArray->pArray[i] == val) {
			memmove(&hDArray->pArray[i], &hDArray->pArray[i + 1], (hDArray->size - i - 1) * sizeof(DATATYPE));
			--hDArray->size;
			return i;
		}

	return DARRAY_FAILED;
}

DATATYPE *FindItem(HDARRAY hDArray, DATATYPE val)
{
	size_t i;

	for (i = 0; i < hDArray->size; ++i)
		if (hDArray->pArray[i] == val)
			return &hDArray->pArray[i];

	return NULL;
}

DATATYPE *FindItemLast(HDARRAY hDArray, DATATYPE val)
{
	size_t i;

	for (i = hDArray->size - 1; ; ) {
		if (hDArray->pArray[i] == val)
			return &hDArray->pArray[i];
		if (i == 0)
			break;
	}

	return NULL;
}

size_t SetCapacity(HDARRAY hDArray, size_t newCapacity)
{
	DATATYPE *pArray;

	if (newCapacity < hDArray->size)
		return DARRAY_FAILED;

	if ((pArray = (DATATYPE *)realloc(hDArray->pArray, sizeof(DATATYPE) * newCapacity)) == NULL)
		return DARRAY_FAILED;
	hDArray->pArray = pArray;
	hDArray->capacity = newCapacity;

	return newCapacity;
}

void TrimToSize(HDARRAY hDArray)
{
	hDArray->pArray = realloc(hDArray->pArray, hDArray->size);

	hDArray->capacity = hDArray->size;
}

void CloseDArray(HDARRAY hDArray)
{
	free(hDArray->pArray);
	free(hDArray);
}

/* Test.c */

#include <stdio.h>
#include <stdlib.h>
#include "DynamicArray.h"

int main(void)
{
	HDARRAY hDArray;
	DATATYPE val;
	int i;

	if ((hDArray = CreateDArrayWithCapacity(30)) == NULL) {
		fprintf(stderr, "Cannot create dynamic array!..\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < 10; ++i)
		AddItem(hDArray, i);

	for (size_t i = 0; i < GetSize(hDArray); ++i)
		printf("%d ", GetItem(hDArray, i));
	printf("\n");

	DeleteItem(hDArray, 20);

	for (size_t i = 0; i < GetSize(hDArray); ++i)
		printf("%d ", GetItem(hDArray, i));
	printf("\n");

	printf("%d\n", *FindItem(hDArray, 7));

	printf("Capacity: %lu, Size: %lu\n", (unsigned long)GetCapacity(hDArray), (unsigned long)GetSize(hDArray));
	TrimToSize(hDArray);
	printf("Capacity: %lu, Size: %lu\n", (unsigned long)GetCapacity(hDArray), (unsigned long)GetSize(hDArray));
	Clear(hDArray);
	printf("Capacity: %lu, Size: %lu\n", (unsigned long)GetCapacity(hDArray), (unsigned long)GetSize(hDArray));

	CloseDArray(hDArray);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Çift bağlı liste (double linked list) gerçekleştirimi.
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* DoublyLinkedList.h */

#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_

#include <stddef.h>

/* Symbolic Constants */

#define FALSE		0
#define TRUE		1

/* Type Declarations */

typedef int BOOL;

typedef struct tagPERSON {
	char name[32];
	int no;
} PERSON;

typedef PERSON DATATYPE;

typedef struct tagNODE {
	DATATYPE val;
	struct tagNODE *pNext;
	struct tagNODE *pPrev;
} NODE;

typedef struct tagLLIST {
	NODE *pHead;
	NODE *pTail;
	size_t count;
} LLIST, *HLLIST;

/* Fuciton Prototypes */

HLLIST CreateLList(void);
NODE *AddItemHead(HLLIST hLList, const DATATYPE *pVal);
NODE *AddItemTail(HLLIST hLList, const DATATYPE *pVal);
NODE *InsertItemNext(HLLIST hLList, NODE *pInsertNode, const DATATYPE *pVal);
NODE *InsertItemPrev(HLLIST hLList, NODE *pInsertNode, const DATATYPE *pVal);
NODE *InsertItemIndex(HLLIST hLList, size_t index, const DATATYPE *pVal);
void DeleteItem(HLLIST hLList, NODE *pDeleteNode);
BOOL DeleteItemIndex(HLLIST hLList, size_t index);
void ClearList(HLLIST hLList);
void CloseList(HLLIST hLList);
DATATYPE *FindItem(HLLIST hLList, BOOL(*Compare)(const DATATYPE *));
NODE *FindItemNode(HLLIST hLList, BOOL(*Compare)(const DATATYPE *));
BOOL WalkList(HLLIST hLList, BOOL(*Proc) (DATATYPE *));
BOOL WalkListRev(HLLIST hLList, BOOL(*Proc) (DATATYPE *));

#endif

/* DoublyLinkedList.c */

#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

HLLIST CreateLList(void)
{
	HLLIST hLList;

	if ((hLList = (HLLIST)malloc(sizeof(LLIST))) == NULL)
		return NULL;

	hLList->pHead = hLList->pTail = NULL;
	hLList->count = 0;

	return hLList;
}

NODE *AddItemHead(HLLIST hLList, const DATATYPE *pVal)
{
	NODE *pNewNode;

	if ((pNewNode = (NODE *)malloc(sizeof(NODE))) == NULL)
		return NULL;
	pNewNode->val = *pVal;
	pNewNode->pPrev = NULL;

	pNewNode->pNext = hLList->pHead;
	if (hLList->pHead != NULL)
		hLList->pHead->pPrev = pNewNode;
	else
		hLList->pTail = pNewNode;
	hLList->pHead = pNewNode;

	++hLList->count;

	return pNewNode;
}

NODE *AddItemTail(HLLIST hLList, const DATATYPE *pVal)
{
	NODE *pNewNode;

	if ((pNewNode = (NODE *)malloc(sizeof(NODE))) == NULL)
		return NULL;
	pNewNode->val = *pVal;
	pNewNode->pNext = NULL;

	pNewNode->pPrev = hLList->pTail;
	if (hLList->pTail != NULL)
		hLList->pTail->pNext = pNewNode;
	else
		hLList->pHead = pNewNode;
	hLList->pTail = pNewNode;

	++hLList->count;

	return pNewNode;
}

NODE *InsertItemNext(HLLIST hLList, NODE *pInsertNode, const DATATYPE *pVal)
{
	NODE *pNewNode;

	if ((pNewNode = (NODE *)malloc(sizeof(NODE))) == NULL)
		return NULL;
	pNewNode->val = *pVal;

	pNewNode->pPrev = pInsertNode;
	pNewNode->pNext = pInsertNode->pNext;
	if (pInsertNode->pNext != NULL)
		pInsertNode->pNext->pPrev = pNewNode;
	else
		hLList->pTail = pNewNode;
	pInsertNode->pNext = pNewNode;

	return pNewNode;
}

NODE *InsertItemPrev(HLLIST hLList, NODE *pInsertNode, const DATATYPE *pVal)
{
	NODE *pNewNode;

	if ((pNewNode = (NODE *)malloc(sizeof(NODE))) == NULL)
		return NULL;
	pNewNode->val = *pVal;

	if (pInsertNode == hLList->pHead)
		hLList->pHead = pNewNode;
	else
		pInsertNode->pPrev->pNext = pNewNode;

	pNewNode->pNext = pInsertNode;
	pNewNode->pPrev = pInsertNode->pPrev;
	pInsertNode->pPrev = pNewNode;

	++hLList->count;

	return pNewNode;
}

NODE *InsertItemIndex(HLLIST hLList, size_t index, const DATATYPE *pVal)
{
	NODE *pNode;
	size_t i;

	if (index > hLList->count)
		return NULL;

	if (index == hLList->count)
		return AddItemTail(hLList, pVal);

	if (index == 0)
		return AddItemHead(hLList, pVal);

	pNode = hLList->pHead;
	for (i = 0; i < index; ++i)
		pNode = pNode->pNext;

	return InsertItemPrev(hLList, pNode, pVal);
}

void DeleteItem(HLLIST hLList, NODE *pDeleteNode)
{
	if (pDeleteNode == hLList->pHead)
		hLList->pHead = pDeleteNode->pNext;
	else
		pDeleteNode->pPrev->pNext = pDeleteNode->pNext;

	if (pDeleteNode == hLList->pTail)
		hLList->pTail = pDeleteNode->pPrev;
	else
		pDeleteNode->pNext->pPrev = pDeleteNode->pPrev;

	free(pDeleteNode);

	--hLList->count;
}

BOOL DeleteItemIndex(HLLIST hLList, size_t index)
{
	NODE *pNode;
	size_t i;

	if (index >= hLList->count)
		return FALSE;

	pNode = hLList->pHead;
	for (i = 0; i < index; ++i)
		pNode = pNode->pNext;

	DeleteItem(hLList, pNode);

	return TRUE;
}

void ClearList(HLLIST hLList)
{
	NODE *pNode, *pTempNode;

	pNode = hLList->pHead;
	while (pNode != NULL) {
		pTempNode = pNode->pNext;
		free(pNode);
		pNode = pTempNode;
	}

	hLList->pHead = hLList->pTail = NULL;
	hLList->count = 0;
}

void CloseList(HLLIST hLList)
{
	ClearList(hLList);

	free(hLList);
}

DATATYPE *FindItem(HLLIST hLList, BOOL(*Compare)(const DATATYPE *))
{
	NODE *pNode;

	for (pNode = hLList->pHead; pNode != NULL; pNode = pNode->pNext)
		if (Compare(&pNode->val))
			return &pNode->val;

	return NULL;
}

NODE *FindItemNode(HLLIST hLList, BOOL(*Compare)(const DATATYPE *))
{
	NODE *pNode;

	for (pNode = hLList->pHead; pNode != NULL; pNode = pNode->pNext)
		if (Compare(&pNode->val))
			return pNode;

	return NULL;
}

BOOL WalkList(HLLIST hLList, BOOL(*Proc) (DATATYPE *))
{
	NODE *pNode;

	for (pNode = hLList->pHead; pNode != NULL; pNode = pNode->pNext)
		if (!Proc(&pNode->val))
			return FALSE;

	return TRUE;
}

BOOL WalkListRev(HLLIST hLList, BOOL(*Proc) (DATATYPE *))
{
	NODE *pNode;

	for (pNode = hLList->pTail; pNode != NULL; pNode = pNode->pPrev)
		if (!Proc(&pNode->val))
			return FALSE;
	return TRUE;
}

/* Test.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoublyLinkedList.h"

BOOL Disp(PERSON *pPerson);

BOOL MyCompare(const PERSON *pPer)
{
	if (strcmp(pPer->name, "Fatih Ercan") == 0)
		return TRUE;

	return FALSE;
}

int main(void)
{
	HLLIST hLList;
	PERSON per, *pper;
	NODE *pNode;

	if ((hLList = CreateLList()) == NULL) {
		fprintf(stderr, "Cannot create linked list!..\n");
		exit(EXIT_FAILURE);
	}

	strcpy(per.name, "Kaan Aslan");
	per.no = 123;

	AddItemTail(hLList, &per);


	strcpy(per.name, "Ali Serçe");
	per.no = 678;

	AddItemTail(hLList, &per);

	strcpy(per.name, "Ayşe Er");
	per.no = 378;

	AddItemTail(hLList, &per);

	strcpy(per.name, "Fatih Ercan");
	per.no = 845;

	AddItemTail(hLList, &per);

	strcpy(per.name, "Hasan Kılıçaslan");
	per.no = 908;

	AddItemTail(hLList, &per);

	WalkList(hLList, Disp);

	printf("------------------------\n");

	strcpy(per.name, "Fatih Ercan");
	per.no = 845;

	if ((pper = FindItem(hLList, MyCompare)) != NULL)
		printf("Name: %s, No: %d\n", pper->name, pper->no);
	else
		printf("Cannot find!..\n");

	return 0;
}

BOOL Disp(PERSON *pPerson)
{
	printf("%s, %d\n", pPerson->name, pPerson->no);

	return TRUE;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Çift bağlı liste gerçekleştiriminde handle alanında pHead ve pTail göstericisi tutmak yerine NODE nesnesi tutulursa özel durumlar ortadan
	kaldırılır ve gerçekleştirim daha sade hale getirilebilir. Tabii bu durumda handle alanında tutulan NODE nesnesinin DATA kısmı kullanılmayacaktır.
	Bu gerçekleştirim programcılar tarafından daha fazla tercih edilmektedir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* DoublyLinkedList.h */

#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_

#include <stddef.h>

/* Symbolic Constants */

#define FALSE		0
#define TRUE		1

/* Type Declarations */

typedef int BOOL;

typedef struct tagPERSON {
	char name[32];
	int no;
} PERSON;

typedef PERSON DATATYPE;

typedef struct tagNODE {
	DATATYPE val;
	struct tagNODE *pNext;
	struct tagNODE *pPrev;
} NODE;

typedef struct tagLLIST {
	NODE head;
	size_t count;
} LLIST, *HLLIST;

/* Fuciton Prototypes */

HLLIST CreateLList(void);
NODE *AddItemHead(HLLIST hLList, const DATATYPE *pVal);
NODE *AddItemTail(HLLIST hLList, const DATATYPE *pVal);
NODE *InsertItemNext(HLLIST hLList, NODE *pInsertNode, const DATATYPE *pVal);
NODE *InsertItemPrev(HLLIST hLList, NODE *pInsertNode, const DATATYPE *pVal);
NODE *InsertItemIndex(HLLIST hLList, size_t index, const DATATYPE *pVal);
void DeleteItem(HLLIST hLList, NODE *pDeleteNode);
BOOL DeleteItemIndex(HLLIST hLList, size_t index);
void ClearList(HLLIST hLList);
void CloseList(HLLIST hLList);
DATATYPE *FindItem(HLLIST hLList, BOOL(*Compare)(const DATATYPE *));
NODE *FindItemNode(HLLIST hLList, BOOL(*Compare)(const DATATYPE *));
BOOL WalkList(HLLIST hLList, BOOL(*Proc) (DATATYPE *));
BOOL WalkListRev(HLLIST hLList, BOOL(*Proc) (DATATYPE *));

#endif

/* DoublyLinkedList.c */

#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

HLLIST CreateLList(void)
{
	HLLIST hLList;

	if ((hLList = (HLLIST)malloc(sizeof(LLIST))) == NULL)
		return NULL;

	hLList->head.pNext = &hLList->head;
	hLList->head.pPrev = &hLList->head;

	hLList->count = 0;

	return hLList;
}

NODE *AddItemHead(HLLIST hLList, const DATATYPE *pVal)
{
	return InsertItemNext(hLList, &hLList->head, pVal);
}

NODE *AddItemTail(HLLIST hLList, const DATATYPE *pVal)
{
	return InsertItemPrev(hLList, &hLList->head, pVal);
}

NODE *InsertItemNext(HLLIST hLList, NODE *pInsertNode, const DATATYPE *pVal)
{
	NODE *pNewNode;

	if ((pNewNode = (NODE *)malloc(sizeof(NODE))) == NULL)
		return NULL;
	pNewNode->val = *pVal;

	pNewNode->pPrev = pInsertNode;
	pNewNode->pNext = pInsertNode->pNext;
	pInsertNode->pNext->pPrev = pNewNode;
	pInsertNode->pNext = pNewNode;

	return pNewNode;
}

NODE *InsertItemPrev(HLLIST hLList, NODE *pInsertNode, const DATATYPE *pVal)
{
	NODE *pNewNode;

	if ((pNewNode = (NODE *)malloc(sizeof(NODE))) == NULL)
		return NULL;
	pNewNode->val = *pVal;

	pInsertNode->pPrev->pNext = pNewNode;
	pNewNode->pNext = pInsertNode;
	pNewNode->pPrev = pInsertNode->pPrev;
	pInsertNode->pPrev = pNewNode;

	++hLList->count;

	return pNewNode;
}

NODE *InsertItemIndex(HLLIST hLList, size_t index, const DATATYPE *pVal)
{
	NODE *pNode;
	size_t i;

	if (index > hLList->count)
		return NULL;

	if (index == hLList->count)
		return AddItemTail(hLList, pVal);

	if (index == 0)
		return AddItemHead(hLList, pVal);

	pNode = hLList->head.pNext;
	for (i = 0; i < index; ++i)
		pNode = pNode->pNext;

	return InsertItemPrev(hLList, pNode, pVal);
}

void DeleteItem(HLLIST hLList, NODE *pDeleteNode)
{
	pDeleteNode->pPrev->pNext = pDeleteNode->pNext;
	pDeleteNode->pNext->pPrev = pDeleteNode->pPrev;

	free(pDeleteNode);

	--hLList->count;
}

BOOL DeleteItemIndex(HLLIST hLList, size_t index)
{
	NODE *pNode;
	size_t i;

	if (index >= hLList->count)
		return FALSE;

	pNode = hLList->head.pNext;
	for (i = 0; i < index; ++i)
		pNode = pNode->pNext;

	DeleteItem(hLList, pNode);

	return TRUE;
}

void ClearList(HLLIST hLList)
{
	NODE *pNode, *pTempNode;

	pNode = hLList->head.pNext;
	while (pNode != &hLList->head) {
		pTempNode = pNode->pNext;
		free(pNode);
		pNode = pTempNode;
	}

	hLList->head.pNext = hLList->head.pPrev = &hLList->head;
	hLList->count = 0;
}

void CloseList(HLLIST hLList)
{
	ClearList(hLList);

	free(hLList);
}

DATATYPE *FindItem(HLLIST hLList, BOOL(*Compare)(const DATATYPE *))
{
	NODE *pNode;

	for (pNode = hLList->head.pNext; pNode != NULL; pNode = pNode->pNext)
		if (Compare(&pNode->val))
			return &pNode->val;

	return NULL;
}

NODE *FindItemNode(HLLIST hLList, BOOL(*Compare)(const DATATYPE *))
{
	NODE *pNode;

	for (pNode = hLList->head.pNext; pNode != &hLList->head; pNode = pNode->pNext)
		if (Compare(&pNode->val))
			return pNode;

	return NULL;
}

BOOL WalkList(HLLIST hLList, BOOL(*Proc) (DATATYPE *))
{
	NODE *pNode;

	for (pNode = hLList->head.pNext; pNode != &hLList->head; pNode = pNode->pNext)
		if (!Proc(&pNode->val))
			return FALSE;

	return TRUE;
}

BOOL WalkListRev(HLLIST hLList, BOOL(*Proc) (DATATYPE *))
{
	NODE *pNode;

	for (pNode = hLList->head.pPrev; pNode != &hLList->head; pNode = pNode->pPrev)
		if (!Proc(&pNode->val))
			return FALSE;
	return TRUE;
}

/* Test.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoublyLinkedList.h"

BOOL Disp(PERSON *pPerson);

BOOL MyCompare(const PERSON *pPer)
{
	if (strcmp(pPer->name, "Fatih Ercan") == 0)
		return TRUE;

	return FALSE;
}

int main(void)
{
	HLLIST hLList;
	PERSON per, *pper;
	NODE *pNode;

	if ((hLList = CreateLList()) == NULL) {
		fprintf(stderr, "Cannot create linked list!..\n");
		exit(EXIT_FAILURE);
	}

	strcpy(per.name, "Kaan Aslan");
	per.no = 123;

	AddItemTail(hLList, &per);

	strcpy(per.name, "Ali Serçe");
	per.no = 678;

	AddItemTail(hLList, &per);

	strcpy(per.name, "Ayşe Er");
	per.no = 378;

	AddItemTail(hLList, &per);

	strcpy(per.name, "Fatih Ercan");
	per.no = 845;

	AddItemTail(hLList, &per);

	strcpy(per.name, "Hasan Kılıçaslan");
	per.no = 908;

	pNode = AddItemTail(hLList, &per);

	WalkListRev(hLList, Disp);


	DeleteItem(hLList, pNode);

	printf("-----------------------\n");
	WalkList(hLList, Disp);


	return 0;
}

BOOL Disp(PERSON *pPerson)
{
	printf("%s, %d\n", pPerson->name, pPerson->no);

	return TRUE;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Tek bağlı liste gerçekleştirimi. Burada handle alanında NODE tutmak önemli bir fayda sağlamamaktadır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* SingleLinkedList.h */

#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_

#include <stddef.h>

/* Symbolic Constants */

#define FALSE		0
#define TRUE		1

/* Type Declarations */

typedef int BOOL;

typedef struct tagPERSON {
	char name[32];
	int no;
} PERSON;

typedef PERSON DATATYPE;

typedef struct tagNODE {
	DATATYPE val;
	struct tagNODE *pNext;
} NODE;

typedef struct tagLLIST {
	NODE *pHead;
	NODE *pTail;
	size_t count;
} LLIST, *HLLIST;

/* Fuciton Prototypes */

HLLIST CreateLList(void);
NODE *AddItemHead(HLLIST hLList, const DATATYPE *pVal);
NODE *AddItemTail(HLLIST hLList, const DATATYPE *pVal);
NODE *InsertItemNext(HLLIST hLList, NODE *pInsertNode, const DATATYPE *pVal);
NODE *InsertItemIndex(HLLIST hLList, size_t index, const DATATYPE *pVal);
void DeleteItemNext(HLLIST hLList, NODE *pNode);
void DeleteItemHead(HLLIST hLList);
BOOL DeleteItemIndex(HLLIST hLList, size_t index);
void ClearList(HLLIST hLList);
void CloseList(HLLIST hLList);
DATATYPE *FindItem(HLLIST hLList, BOOL(*Compare)(const DATATYPE *));
NODE *FindItemNode(HLLIST hLList, BOOL(*Compare)(const DATATYPE *));
BOOL WalkList(HLLIST hLList, BOOL(*Proc) (DATATYPE *));
BOOL IneffectiveWalkListRev(HLLIST hLList, BOOL(*Proc) (DATATYPE *));

#endif

/* SingleLinkedList.c */

#include <stdio.h>
#include <stdlib.h>
#include "SingleLinkedList.h"

static BOOL WalkListRevRecur(NODE *pNode, BOOL(*Proc) (DATATYPE *));

HLLIST CreateLList(void)
{
	HLLIST hLList;

	if ((hLList = (HLLIST)malloc(sizeof(LLIST))) == NULL)
		return NULL;

	hLList->pHead = hLList->pTail = NULL;
	hLList->count = 0;

	return hLList;
}

NODE *AddItemHead(HLLIST hLList, const DATATYPE *pVal)
{
	NODE *pNewNode;

	if ((pNewNode = (NODE *)malloc(sizeof(NODE))) == NULL)
		return NULL;
	pNewNode->val = *pVal;

	pNewNode->pNext = hLList->pHead;
	hLList->pHead = pNewNode;
	if (hLList->pTail == NULL)
		hLList->pTail = pNewNode;

	++hLList->count;

	return pNewNode;
}


NODE *AddItemTail(HLLIST hLList, const DATATYPE *pVal)
{
	NODE *pNewNode;

	if ((pNewNode = (NODE *)malloc(sizeof(NODE))) == NULL)
		return NULL;
	pNewNode->val = *pVal;
	pNewNode->pNext = NULL;

	if (hLList->pTail != NULL)
		hLList->pTail->pNext = pNewNode;
	else
		hLList->pHead = pNewNode;
	hLList->pTail = pNewNode;

	++hLList->count;

	return pNewNode;
}

NODE *InsertItemNext(HLLIST hLList, NODE *pInsertNode, const DATATYPE *pVal)
{
	NODE *pNewNode;

	if ((pNewNode = (NODE *)malloc(sizeof(NODE))) == NULL)
		return NULL;
	pNewNode->val = *pVal;

	pNewNode->pNext = pInsertNode->pNext;
	pInsertNode->pNext = pNewNode;
	if (hLList->pTail == pInsertNode)
		hLList->pTail = pNewNode;

	return pNewNode;
}

NODE *InsertItemIndex(HLLIST hLList, size_t index, const DATATYPE *pVal)
{
	NODE *pNode;
	size_t i;

	if (index > hLList->count)
		return NULL;

	if (index == hLList->count)
		return AddItemTail(hLList, pVal);

	if (index == 0)
		return AddItemHead(hLList, pVal);

	pNode = hLList->pHead;
	for (i = 0; i < index - 1; ++i)
		pNode = pNode->pNext;

	return InsertItemNext(hLList, pNode, pVal);
}

void DeleteItemNext(HLLIST hLList, NODE *pNode)
{
	NODE *pDeleteNode;

	pDeleteNode = pNode->pNext;
	pNode->pNext = pDeleteNode->pNext;

	if (hLList->pTail == pDeleteNode)
		hLList->pTail = pNode;

	free(pDeleteNode);

	--hLList->count;
}

void DeleteItemHead(HLLIST hLList)
{
	NODE *pDeleteNode;

	if (hLList->pHead == NULL)
		return;

	pDeleteNode = hLList->pHead;
	hLList->pHead = pDeleteNode->pNext;

	if (hLList->pTail == pDeleteNode)
		hLList->pTail = NULL;

	free(pDeleteNode);

	--hLList->count;
}

BOOL DeleteItemIndex(HLLIST hLList, size_t index)
{
	NODE *pNode;
	size_t i;

	if (index >= hLList->count)
		return FALSE;

	if (index == 0) {
		DeleteItemHead(hLList);
		return TRUE;
	}

	pNode = hLList->pHead;
	for (i = 0; i < index - 1; ++i)
		pNode = pNode->pNext;

	DeleteItemNext(hLList, pNode);

	return TRUE;
}

void ClearList(HLLIST hLList)
{
	NODE *pNode, *pTempNode;

	pNode = hLList->pHead;
	while (pNode != NULL) {
		pTempNode = pNode->pNext;
		free(pNode);
		pNode = pTempNode;
	}

	hLList->pHead = hLList->pTail = NULL;
	hLList->count = 0;
}

void CloseList(HLLIST hLList)
{
	ClearList(hLList);

	free(hLList);
}

DATATYPE *FindItem(HLLIST hLList, BOOL(*Compare)(const DATATYPE *))
{
	NODE *pNode;

	for (pNode = hLList->pHead; pNode != NULL; pNode = pNode->pNext)
		if (Compare(&pNode->val))
			return &pNode->val;

	return NULL;
}

NODE *FindItemNode(HLLIST hLList, BOOL(*Compare)(const DATATYPE *))
{
	NODE *pNode;

	for (pNode = hLList->pHead; pNode != NULL; pNode = pNode->pNext)
		if (Compare(&pNode->val))
			return pNode;

	return NULL;
}


BOOL WalkList(HLLIST hLList, BOOL(*Proc) (DATATYPE *))
{
	NODE *pNode;

	for (pNode = hLList->pHead; pNode != NULL; pNode = pNode->pNext)
		if (!Proc(&pNode->val))
			return FALSE;

	return TRUE;
}

BOOL IneffectiveWalkListRev(HLLIST hLList, BOOL(*Proc) (DATATYPE *))
{
	return WalkListRevRecur(hLList->pHead, Proc);
}

static BOOL WalkListRevRecur(NODE *pNode, BOOL(*Proc) (DATATYPE *))
{
	if (pNode == NULL)
		return;

	if (!WalkListRevRecur(pNode->pNext, Proc))
		return FALSE;
	if (!Proc(&pNode->val))
		return FALSE;
}

/* Test.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SingleLinkedList.h"

BOOL Disp(PERSON *pPerson);

int main(void)
{
	HLLIST hLList;
	PERSON per, *pper;
	NODE *pNode;

	if ((hLList = CreateLList()) == NULL) {
		fprintf(stderr, "Cannot create linked list!..\n");
		exit(EXIT_FAILURE);
	}

	strcpy(per.name, "Kaan Aslan");
	per.no = 123;

	AddItemTail(hLList, &per);


	strcpy(per.name, "Ali Serçe");
	per.no = 678;

	AddItemTail(hLList, &per);

	strcpy(per.name, "Ayşe Er");
	per.no = 378;

	AddItemTail(hLList, &per);

	strcpy(per.name, "Fatih Ercan");
	per.no = 845;

	AddItemTail(hLList, &per);

	strcpy(per.name, "Hasan Kılıçaslan");
	per.no = 908;

	AddItemTail(hLList, &per);

	WalkList(hLList, Disp);

	printf("------------------------\n");

	IneffectiveWalkListRev(hLList, Disp);

	return 0;
}

BOOL Disp(PERSON *pPerson)
{
	printf("%s, %d\n", pPerson->name, pPerson->no);

	return TRUE;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Kuyruk sistemlerinin algoritmik gerçekleştiriminin birisi index kaydırma ya da döngüsel kuyruk sistemi denilen yöntemdir. 
	Bu yöntemde head ve tail gibi iki gösterici ya da indeks kuyruğun başını ve sonunu tutar. Bu göstericiler dizinin sonuna geldiğinde
	yeniden başa çekilirler. 


	Aşağıda bu yöntemin gerçekleştirimi verilmektedir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* Queue.h */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stddef.h>

/* Symbolic Constants */

#define FALSE		0
#define TRUE		1

/* Type Declarations */

typedef int BOOL;

typedef struct tagPERSON {
	char name[32];
	int no;
} PERSON;

typedef PERSON DATATYPE;

typedef struct tagQUEUE {
	DATATYPE *pQueue;
	size_t qsize;
	size_t head;
	size_t tail;
	size_t count;
} QUEUE, *HQUEUE;

/* Function Prototypes */

HQUEUE CreateQueue(size_t qsize);
BOOL PutItem(HQUEUE hQueue, const DATATYPE *pVal);
BOOL GetItem(HQUEUE hQueue, DATATYPE *pVal);
void Clear(HQUEUE hQueue);
void CloseQueue(HQUEUE hQueue);

/* Macros */

#define GetCount(hQueue)	((hQueue)->count)
#define GetSize(hQueue)		((hQueue)->qsize)
#define IsEmpty(hQueue)		(!(hQueue)->count)

#endif

/* Queue.c */

#include <stdio.h>
#include "Queue.h"

HQUEUE CreateQueue(size_t qsize)
{
	HQUEUE hQueue;

	if ((hQueue = (HQUEUE)malloc(sizeof(QUEUE))) == NULL)
		return NULL;

	if ((hQueue->pQueue = (DATATYPE *)malloc(qsize * sizeof(DATATYPE))) == NULL) {
		free(hQueue);
		return NULL;
	}
	hQueue->head = hQueue->tail = hQueue->count = 0;
	hQueue->qsize = qsize;

	return hQueue;
}

BOOL PutItem(HQUEUE hQueue, const DATATYPE *pVal)
{
	if (hQueue->count == hQueue->qsize)
		return FALSE;

	hQueue->pQueue[hQueue->tail++] = *pVal;
	hQueue->tail = hQueue->tail % hQueue->qsize;
	++hQueue->count;

	return TRUE;
}

BOOL GetItem(HQUEUE hQueue, DATATYPE *pVal)
{
	if (hQueue->count == 0)
		return FALSE;

	*pVal = hQueue->pQueue[hQueue->head++];
	hQueue->head = hQueue->head % hQueue->qsize;
	--hQueue->count;

	return TRUE;
}

void Clear(HQUEUE hQueue)
{
	hQueue->head = hQueue->tail = hQueue->count = 0;
}

void CloseQueue(HQUEUE hQueue)
{
	free(hQueue->pQueue);
	free(hQueue);
}

/* Test.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Queue.h"

void GetRandomName(char *name, size_t size)
{
	size_t i;

	for (i = 0; i < size - 1; ++i)
		name[i] = 'A' + rand() % 26;
	name[i] = '\0';
}

int main(void)
{
	HQUEUE hQueue;
	int i;
	PERSON per;

	srand(time(NULL));

	if ((hQueue = CreateQueue(10)) == NULL) {
		fprintf(stderr, "Cannot create queue!..\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < 10; ++i) {
		GetRandomName(per.name, 32);
		per.no = i;
		PutItem(hQueue, &per);
	}

	for (i = 0; i < 5; ++i) {
		GetItem(hQueue, &per);
		printf("%d, %s\n", per.no, per.name);
	}

	printf("---------------\n");

	for (i = 0; i < 5; ++i) {
		GetRandomName(per.name, 32);
		per.no = i * 10;
		PutItem(hQueue, &per);
	}

	while (!IsEmpty(hQueue)) {
		GetItem(hQueue, &per);
		printf("%d, %s\n", per.no, per.name);
	}

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Bağlı Liste tekniği ile Kuyruk sisteminin gerçekleştirilmesinde bir tek bağlı liste oluşturulur. Elemanlar kuyruğun sonuna eklenir, başından alınır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* Queue.h */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stddef.h>

/* Symbolic Constants */

#define FALSE		0
#define TRUE		1

/* Type Declarations */

typedef int BOOL;

typedef struct tagPERSON {
	char name[32];
	int no;
} PERSON;

typedef PERSON DATATYPE;

typedef struct tagNODE {
	DATATYPE val;
	struct tagNODE *pNext;
} NODE;

typedef struct tagQUEUE {
	NODE *pHead;
	NODE *pTail;
	size_t count;
} QUEUE, *HQUEUE;

/* Function Prototypes */

HQUEUE CreateQueue(size_t qsize);
BOOL PutItem(HQUEUE hQueue, const DATATYPE *pVal);
BOOL GetItem(HQUEUE hQueue, DATATYPE *pVal);
void Clear(HQUEUE hQueue);
void CloseQueue(HQUEUE hQueue);

/* Macros */

#define GetCount(hQueue)	((hQueue)->count)
#define IsEmpty(hQueue)		(!(hQueue)->count)

#endif

/* Queue.c */

#include <stdio.h>
#include "Queue.h"

HQUEUE CreateQueue(size_t qsize)
{
	HQUEUE hQueue;

	if ((hQueue = (HQUEUE)malloc(sizeof(QUEUE))) == NULL)
		return NULL;

	hQueue->pHead = hQueue->pTail = NULL;
	hQueue->count = 0;

	return hQueue;
}

BOOL PutItem(HQUEUE hQueue, const DATATYPE *pVal)
{
	NODE *pNewNode;

	if ((pNewNode = (NODE *)malloc(sizeof(NODE))) == NULL)
		return FALSE;
	pNewNode->val = *pVal;
	pNewNode->pNext = NULL;

	if (hQueue->pTail != NULL)
		hQueue->pTail->pNext = pNewNode;
	else
		hQueue->pHead = pNewNode;
	hQueue->pTail = pNewNode;

	++hQueue->count;

	return TRUE;
}

BOOL GetItem(HQUEUE hQueue, DATATYPE *pVal)
{
	NODE *pNode;

	if (hQueue->pHead == NULL)
		return FALSE;

	pNode = hQueue->pHead;
	hQueue->pHead = pNode->pNext;
	if (hQueue->pHead == NULL)
		hQueue->pTail = NULL;

	*pVal = pNode->val;
	free(pNode);

	--hQueue->count;

	return TRUE;
}

void Clear(HQUEUE hQueue)
{
	NODE *pNode, *pTempNode;

	pNode = hQueue->pHead;
	while (pNode != NULL) {
		pTempNode = pNode->pNext;
		free(pNode);
		pNode = pTempNode;
	}

	hQueue->pHead = hQueue->pTail = NULL;
	hQueue->count = 0;
}

void CloseQueue(HQUEUE hQueue)
{
	Clear(hQueue);
	free(hQueue);
}

/* Test.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Queue.h"

void GetRandomName(char *name, size_t size)
{
	size_t i;

	for (i = 0; i < size - 1; ++i)
		name[i] = 'A' + rand() % 26;
	name[i] = '\0';
}

int main(void)
{
	HQUEUE hQueue;
	int i;
	PERSON per;

	srand(time(NULL));

	if ((hQueue = CreateQueue(10)) == NULL) {
		fprintf(stderr, "Cannot create queue!..\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < 10; ++i) {
		GetRandomName(per.name, 32);
		per.no = i;
		PutItem(hQueue, &per);
	}

	for (i = 0; i < 5; ++i) {
		GetItem(hQueue, &per);
		printf("%d, %s\n", per.no, per.name);
	}

	printf("---------------\n");

	for (i = 0; i < 5; ++i) {
		GetRandomName(per.name, 32);
		per.no = i * 10;
		PutItem(hQueue, &per);
	}

	while (!IsEmpty(hQueue)) {
		GetItem(hQueue, &per);
		printf("%d, %s\n", per.no, per.name);
	}

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Stack sistemi aslında LIFO prensibiyle çalışan bir kuyrul sistemidir. Tipik gerçekleştirimi stack pointer isimli bir göstericinin push
	işlemi sırasında eksiltilmesi pop işlemş sırasında artırılması ile yapılmaktadır. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* Stack.h */

#ifndef STACK_H_
#define STACK_H_

#include <stddef.h>

/* Symbolic Constants */

#define FALSE		0
#define TRUE		1

/* Type Declaration */

typedef int BOOL;

typedef struct tagPERSON {
	char name[32];
	int no;
} PERSON;

typedef PERSON DATATYPE;

typedef struct tagSTACK {
	DATATYPE *pStack;
	DATATYPE *SP;
	size_t size;
	size_t count;
} STACK, *HSTACK;

/* Function Prototypes */

HSTACK CreateStack(size_t size);
BOOL Push(HSTACK hStack, const DATATYPE *pVal);
BOOL Pop(HSTACK hStack, DATATYPE *pVal);
void Clear(HSTACK hStack);
void CloseStack(HSTACK hStack);

/* Macros */

#define GetCount(hStack)		((hStack)->count)
#define GetSize(hStack)			((hStack)->size)
#define IsEmpty(hStack)			((hStack)->count == 0)

#endif

/* Stack.c */

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

HSTACK CreateStack(size_t size)
{
	HSTACK hStack;

	if ((hStack = (HSTACK)malloc(sizeof(STACK))) == NULL)
		return NULL;

	if ((hStack->pStack = (DATATYPE *)malloc(sizeof(DATATYPE) * size)) == NULL) {
		free(hStack);
		return NULL;
	}
	hStack->SP = hStack->pStack + size;
	hStack->size = size;
	hStack->count = 0;

	return hStack;
}

BOOL Push(HSTACK hStack, const DATATYPE *pVal)
{
	if (hStack->SP == hStack->pStack)
		return FALSE;

	*--hStack->SP = *pVal;
	++hStack->count;

	return TRUE;
}

BOOL Pop(HSTACK hStack, DATATYPE *pVal)
{
	if (hStack->SP == hStack->pStack + hStack->size)		/* assert(hStack->count == 0) */
		return FALSE;

	*pVal = *hStack->SP++;
	--hStack->count;

	return TRUE;
}

void Clear(HSTACK hStack)
{
	hStack->SP = hStack->pStack + hStack->size;
	hStack->count = 0;
}

void CloseStack(HSTACK hStack)
{
	free(hStack->pStack);
	free(hStack);
}

/* Test.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

int main(void)
{
	HSTACK hStack;
	PERSON per;

	if ((hStack = CreateStack(10)) == NULL) {
		fprintf(stderr, "Cannot create stack!..\n");
		exit(EXIT_FAILURE);
	}

	strcpy(per.name, "Ali Serçe");
	per.no = 123;

	Push(hStack, &per);

	strcpy(per.name, "Sacit Ulu");
	per.no = 123;

	Push(hStack, &per);

	strcpy(per.name, "Ayşe Er");
	per.no = 976;

	Push(hStack, &per);

	strcpy(per.name, "Demir Büyüközkaya");
	per.no = 769;

	Push(hStack, &per);

	while (!IsEmpty(hStack)) {
		Pop(hStack, &per);
		printf("%s, %d\n", per.name, per.no);
	}

	CloseStack(hStack);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Stack veri yapısı bağlı liste ile de gerçekleştirilebilir. Bu durumda eleman bağlı listenin başına eklenir ve eleman bağlı listenin başından 
	alınır. Tek bağlı liste gerçekleştirim için yeterlidir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* Stack.h */

#ifndef STACK_H_
#define STACK_H_

#include <stddef.h>

/* Symbolic Constants */

#define FALSE		0
#define TRUE		1

/* Type Declaration */

typedef int BOOL;

typedef struct tagPERSON {
	char name[32];
	int no;
} PERSON;

typedef PERSON DATATYPE;

typedef struct tagNODE {
	DATATYPE val;
	struct tagNODE *pNext;
} NODE;

typedef struct tagQUEUE {
	NODE *pHead;
	size_t count;
} STACK, *HSTACK;

/* Function Prototypes */

HSTACK CreateStack(size_t size);
BOOL Push(HSTACK hStack, const DATATYPE *pVal);
BOOL Pop(HSTACK hStack, DATATYPE *pVal);
void Clear(HSTACK hStack);
void CloseStack(HSTACK hStack);

/* Macros */

#define GetCount(hStack)		((hStack)->count)
#define IsEmpty(hStack)			((hStack)->pHead == NULL)

#endif

/* Stack.c */

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

HSTACK CreateStack(size_t size)
{
	HSTACK hStack;

	if ((hStack = (HSTACK)malloc(sizeof(STACK))) == NULL)
		return NULL;

	hStack->pHead = NULL;
	hStack->count = 0;

	return hStack;
}

BOOL Push(HSTACK hStack, const DATATYPE *pVal)
{
	NODE *pNewNode;

	if ((pNewNode = (NODE *)malloc(sizeof(NODE))) == NULL)
		return FALSE;
	pNewNode->val = *pVal;

	pNewNode->pNext = hStack->pHead;
	hStack->pHead = pNewNode;

	++hStack->count;

	return TRUE;
}

BOOL Pop(HSTACK hStack, DATATYPE *pVal)
{
	NODE *pNode;

	if (hStack->pHead == NULL)
		return FALSE;

	pNode = hStack->pHead;
	hStack->pHead = pNode->pNext;

	*pVal = pNode->val;
	free(pNode);

	--hStack->count;

	return TRUE;
}

void Clear(HSTACK hStack)
{
	NODE *pNode, *pTempNode;

	pNode = hStack->pHead;
	while (pNode != NULL) {
		pTempNode = pNode->pNext;
		free(pNode);
		pNode = pTempNode;
	}

	hStack->pHead = NULL;
	hStack->count = 0;
}

void CloseStack(HSTACK hStack)
{
	Clear(hStack);
	free(hStack);
}

/* Test.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

int main(void)
{
	HSTACK hStack;
	PERSON per;

	if ((hStack = CreateStack(10)) == NULL) {
		fprintf(stderr, "Cannot create stack!..\n");
		exit(EXIT_FAILURE);
	}

	strcpy(per.name, "Ali Serçe");
	per.no = 123;

	Push(hStack, &per);

	strcpy(per.name, "Sacit Ulu");
	per.no = 123;

	Push(hStack, &per);

	strcpy(per.name, "Ayşe Er");
	per.no = 976;

	Push(hStack, &per);

	strcpy(per.name, "Demir Büyüközkaya");
	per.no = 769;

	Push(hStack, &per);

	while (!IsEmpty(hStack)) {
		Pop(hStack, &per);
		printf("%s, %d\n", per.name, per.no);
	}

	CloseStack(hStack);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Başa ve sona eleman eklemeninsabit zamanlı olduğu dinamik büyütülen dizilere "Double Ended Queue (Deque)" denilmektedir. Deque tipik olarak
	iki biçimde gerçekleştirilmektedir: Kuyruk sistemi biçiminde ve blok listesi biçiminde. Aşağıda kuyruk sistemi biçiminde deque gerçekleştirimi
	görülmektedir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* Deque.h */

#ifndef DEQUE_H_
#define DEQUE_H_

#include <stddef.h>

#define DEF_CAPACITY	8
#define DEQUE_FAILED	((size_t)-1)

/* Type Declarations */

typedef struct tagPERSON {
	char name[32];
	int no;
} PERSON;

typedef PERSON DATATYPE;

typedef struct tagNODE {
	DATATYPE val;
	struct tagNODE *pNext;
} NODE;

typedef struct tagDEQUE {
	DATATYPE *pDeque;
	size_t head;
	size_t tail;
	size_t capacity;
	size_t size;
} DEQUE, *HDEQUE;

/* Function Prototypes */

HDEQUE CreateDeque(void);
HDEQUE CreateDequeWithCapacity(size_t capacity);
size_t AddItem(HDEQUE hDeque, const DATATYPE *pVal);
size_t AddItemFront(HDEQUE hDeque, const DATATYPE *pVal);
size_t SetCapacity(HDEQUE hDeque, size_t newCapacity);

/* Macros */

#define GetItem(hDeque, index, pVal)	(*(pVal) = (hDeque)->pDeque[((hDeque)->head + (index)) % (hDeque)->capacity])
#define Getsize(hDeque)					((hDeque)->size)
#define GetCapacitysize(hDeque)			((hDeque)->capacity)

#endif

/* Deque.c */

#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

#define MIN(a, b)	((a) < (b) ? (a) : (b))

HDEQUE CreateDeque(void)
{
	return CreateDequeWithCapacity(DEF_CAPACITY);
}

HDEQUE CreateDequeWithCapacity(size_t capacity)
{
	HDEQUE hDeque;

	if ((hDeque = (HDEQUE)malloc(sizeof(DEQUE))) == NULL)
		return NULL;

	if ((hDeque->pDeque = (DATATYPE *)malloc(sizeof(DATATYPE) * capacity)) == NULL) {
		free(hDeque);
		return NULL;
	}
	hDeque->head = hDeque->tail = hDeque->size = 0;
	hDeque->capacity = capacity;

	return hDeque;
}

size_t AddItem(HDEQUE hDeque, const DATATYPE *pVal)
{
	if (hDeque->size == hDeque->capacity)
		if (SetCapacity(hDeque, hDeque->capacity * 2) == DEQUE_FAILED)
			return DEQUE_FAILED;
	hDeque->pDeque[hDeque->tail++] = *pVal;
	hDeque->tail = hDeque->tail % hDeque->capacity;
	++hDeque->size;

	return hDeque->size - 1;
}

size_t AddItemFront(HDEQUE hDeque, const DATATYPE *pVal)
{
	if (hDeque->size == hDeque->capacity)
		if (SetCapacity(hDeque, hDeque->capacity * 2) == DEQUE_FAILED)
			return DEQUE_FAILED;

	if (hDeque->head == 0)
		hDeque->head = hDeque->capacity - 1;
	else
		--hDeque->head;

	hDeque->pDeque[hDeque->head] = *pVal;
	++hDeque->size;

	return 0;
}

size_t SetCapacity(HDEQUE hDeque, size_t newCapacity)
{
	DATATYPE *pDeque;
	size_t size1, size2;

	if (newCapacity < hDeque->size)
		return DEQUE_FAILED;

	if ((pDeque = (DATATYPE *)malloc(sizeof(DATATYPE) * newCapacity)) == NULL)
		return DEQUE_FAILED;

	size1 = MIN(hDeque->capacity - hDeque->head, hDeque->size);
	size2 = hDeque->size - size1;

	memcpy(pDeque, &hDeque->pDeque[hDeque->head], size1 * sizeof(DATATYPE));
	memcpy(pDeque + size1, &hDeque->pDeque, size2 * sizeof(DATATYPE));

	free(hDeque->pDeque);
	hDeque->pDeque = pDeque;

	hDeque->head = 0;
	hDeque->tail = hDeque->size;
	hDeque->capacity = newCapacity;

	return newCapacity;
}

/* Test.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Deque.h"

int main(void)
{
	HDEQUE hDeque;
	PERSON per;
	int i;

	if ((hDeque = CreateDequeWithCapacity(2)) == NULL) {
		fprintf(stderr, "Cannot create deque!..\n");
		exit(EXIT_FAILURE);
	}

	strcpy(per.name, "Kaan Aslan");
	per.no = 123;

	AddItem(hDeque, &per);

	strcpy(per.name, "Ali Serce");
	per.no = 456;

	AddItem(hDeque, &per);

	strcpy(per.name, "Sacit Bulut");
	per.no = 456;

	AddItem(hDeque, &per);

	strcpy(per.name, "Burhan Kuzu");
	per.no = 965;

	AddItemFront(hDeque, &per);

	for (i = 0; i < hDeque->size; ++i) {
		GetItem(hDeque, i, &per);
		printf("%s, %d\n", per.name, per.no);
	}

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Arama sırasında belli bir listedeki elemanlara tek tek bakılıyorsa bu yönteme "sıralı arama (sequential search)" denilmektedir. Sırala arama
	20'ye kadar eleman için çok güçlü bir yöntemdir. Ancak yüksek sayıda eleman söz konusu olduğunda O(N) karmaşıklıktan dolayı zayıf bir
	yöntem haline gelmektedir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

typedef int DATATYPE;

DATATYPE *SequentialSearch(DATATYPE *pArray, size_t size, DATATYPE val)
{
	size_t i;

	for (i = 0; i < size; ++i)
		if (pArray[i] == val)
			return &pArray[i];

	return NULL;
}

int main(void)
{
	int a[10] = { 4, 67, 34, 12, 21, 89, 34, 19, 90, 59 };
	int *pi;

	if ((pi = SequentialSearch(a, 10, 89)) == NULL) {
		fprintf(stderr, "Cannot find!..\n");
		exit(EXIT_FAILURE);
	}

	printf("Found: %d\n", *pi);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Aslında sıralı arama aranacak elemanı dizinin sonuna yerleştirek (tabii böyle bir imkanımız varsa) daha uygun hale getirilebilir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

typedef int DATATYPE;

DATATYPE *SequentialSearch(DATATYPE *pArray, size_t size, DATATYPE val)
{
	size_t i;

	pArray[size] = val;

	for (i = 0;; ++i)
		if (pArray[i] == val)
			break;

	return i < size ? &pArray[i] : NULL;
}

int main(void)
{
	int a[10 + 1] = { 4, 67, 34, 12, 21, 89, 34, 19, 90, 59 };
	int *pi;

	if ((pi = SequentialSearch(a, 10, 100)) == NULL) {
		fprintf(stderr, "Cannot find!..\n");
		exit(EXIT_FAILURE);
	}

	printf("Found: %d\n", *pi);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Arama işleminde eğer dizi sıraya diziliyse ikili arama (binary search) uygun bir yöntemdir. Yöntemin karmaşıklığı en kötü durum için
	O(Log N)'dir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

typedef int DATATYPE;

DATATYPE *BinarySearch(DATATYPE *pArray, size_t size, DATATYPE val)
{
	size_t left, right, mid;

	left = 0;
	right = size - 1;

	while (left <= right) {
		mid = (left + right) / 2;
		if (pArray[mid] < val)
			left = mid + 1;
		else if (pArray[mid] > val) {
			if (right == 0)
				break;
			right = mid - 1;
		}
		else
			return &pArray[mid];
	}

	return NULL;
}

int main(void)
{
	int a[10] = { 3, 9, 15, 26, 38, 45, 59, 65, 80, 94 };
	int *pi;

	if ((pi = BinarySearch(a, 10, 2)) == NULL) {
		fprintf(stderr, "Cannot find!..\n");
		exit(EXIT_FAILURE);
	}

	printf("Found: %d\n", *pi);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Eğer sıralı dizinin eleman sayısı bilinmiyorse (unbounded array) bu durumda önce elemanın bulunduğu bölge üstel bir biçimde (2 ile
	çarpılarak) belirlenir. Sonra o bölgede ikili arama uygulanır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

typedef int DATATYPE;

DATATYPE *BinarySearch(DATATYPE *pArray, size_t size, DATATYPE val)
{
	size_t left, right, mid;

	left = 0;
	right = size - 1;

	while (left <= right) {
		mid = (left + right) / 2;
		if (pArray[mid] < val)
			left = mid + 1;
		else if (pArray[mid] > val) {
			if (right == 0)
				break;
			right = mid - 1;
		}
		else
			return &pArray[mid];
	}

	return NULL;
}

DATATYPE *ExponentialSearch(DATATYPE *pArray, size_t size, DATATYPE val)
{
	size_t i, left;

	if (val < pArray[0])
		return NULL;

	i = 1;
	while (pArray[i] < val && i < size)
		i *= 2;
	left = i / 2;

	return BinarySearch(pArray + left, i - left + 1, val);
}

int main(void)
{
	int a[10] = { 3, 9, 15, 26, 38, 45, 59, 65, 80, 94 };
	int *pi;

	if ((pi = ExponentialSearch(a, 10, 1)) == NULL) {
		fprintf(stderr, "Cannot find!..\n");
		exit(EXIT_FAILURE);
	}

	printf("Found: %d\n", *pi);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Hash Tablosunun "Ayrı Zincir Oluşturma (Seperate Chaining)" yönteminin gerçekleştirimi.
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* HashTable.h */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <stddef.h>

/* Symbolic Connstants */

#define FALSE		0
#define TRUE		1

/* Type Declarations */

typedef int BOOL;

typedef struct tagPERSON {
	char name[32];
	/* other stuff */
} PERSON;

typedef PERSON VALUE;
typedef int KEY;

typedef struct tagNODE {
	KEY key;
	VALUE val;
	struct NODE *pNext;
} NODE;

typedef struct tagHTABLE {
	NODE **pTable;
	size_t tableSize;
	size_t count;
} HTABLE, *HHTABLE;

/* Function Prototypes */

HHTABLE CreateHashTable(size_t tableSize);
BOOL InsertItem(HHTABLE hHTable, KEY key, const VALUE *pVal);
VALUE *FindItem(HHTABLE hHTable, KEY key);
BOOL DeleteItem(HHTABLE hHTable, KEY key);
BOOL WalkHashTable(HHTABLE hHTable, BOOL(*Proc)(const KEY *pKey, VALUE *pVal));
void ClearHashTable(HHTABLE hHTable);
void CloseHashTable(HHTABLE hHTable);

#endif

/* HashTable.c */

#include <stdio.h>
#include <stdlib.h>
#include "HashTable.h"

static size_t HashFunc(KEY key, size_t tableSize);

HHTABLE CreateHashTable(size_t tableSize)
{
	HHTABLE hHTable;
	size_t i;

	if ((hHTable = (HHTABLE)malloc(sizeof(HTABLE))) == NULL)
		return NULL;

	if ((hHTable->pTable = (NODE **)malloc(tableSize * sizeof(NODE *))) == NULL) {
		free(hHTable);
		return NULL;
	}

	for (i = 0; i < tableSize; ++i)
		hHTable->pTable[i] = NULL;

	hHTable->tableSize = tableSize;
	hHTable->count = 0;

	return hHTable;
}

BOOL InsertItem(HHTABLE hHTable, KEY key, const VALUE *pVal)
{
	size_t hash;
	NODE *pNode, *pNewNode;
	NODE *pHead;

	hash = HashFunc(key, hHTable->tableSize);

	for (pNode = hHTable->pTable[hash]; pNode != NULL; pNode = pNode->pNext)
		if (key == pNode->key) {
			pNode->val = *pVal;
			return TRUE;
		}

	if ((pNewNode = (NODE *)malloc(sizeof(NODE))) == NULL)
		return FALSE;
	pNewNode->key = key;
	pNewNode->val = *pVal;

	pHead = hHTable->pTable[hash];
	pNewNode->pNext = hHTable->pTable[hash];
	hHTable->pTable[hash] = pNewNode;

	++hHTable->count;

	return TRUE;
}

VALUE *FindItem(HHTABLE hHTable, KEY key)
{
	NODE *pNode;
	size_t hash;

	hash = HashFunc(key, hHTable->tableSize);

	for (pNode = hHTable->pTable[hash]; pNode != NULL; pNode = pNode->pNext)
		if (key == pNode->key)
			return &pNode->val;

	return NULL;
}

BOOL DeleteItem(HHTABLE hHTable, KEY key)
{
	NODE *pNode, *pPrevNode;
	size_t hash;

	hash = HashFunc(key, hHTable->tableSize);
	pPrevNode = NULL;
	for (pNode = hHTable->pTable[hash]; pNode != NULL; pPrevNode = pNode, pNode = pNode->pNext)
		if (pNode->key == key) {
			if (pNode == hHTable->pTable[hash])
				hHTable->pTable[hash] = NULL;
			else
				pPrevNode->pNext = pNode->pNext;
			free(pNode);
			--hHTable->count;
			return TRUE;
		}

	return FALSE;
}

BOOL WalkHashTable(HHTABLE hHTable, BOOL(*Proc)(const KEY *pKey, VALUE *pVal))
{
	size_t i;
	NODE *pNode;

	for (i = 0; hHTable->tableSize; ++i)
		for (pNode = hHTable->pTable[i]; pNode != NULL; pNode = pNode->pNext)
			if (!Proc(&pNode->key, &pNode->val))
				return FALSE;
	return TRUE;
}

void ClearHashTable(HHTABLE hHTable)
{
	size_t i;
	NODE *pNode, *pTempNode;

	for (i = 0; hHTable->tableSize; ++i) {
		pNode = hHTable->pTable[i];
		while (pNode != NULL) {
			pTempNode = pNode->pNext;
			free(pNode);
			pNode = pTempNode;
		}
		hHTable->pTable[i] = NULL;
	}
	hHTable->count = 0;
}

void CloseHashTable(HHTABLE hHTable)
{
	ClearHashTable(hHTable);
	free(hHTable->pTable);
	free(hHTable);
}

static size_t HashFunc(KEY key, size_t tableSize)
{
	return key % tableSize;
}

/* Test.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "HashTable.h"

BOOL Disp(const KEY *pKey, VALUE *pValue)
{
	printf("Key: %d, Value: %s\n", *pKey, pValue->name);

	return TRUE;
}

void GetRandomKeyVal(VALUE *pVal, KEY *pKey)
{
	int i;

	for (i = 0; i < 31; ++i)
		pVal->name[i] = 'A' + rand() % 26;
	pVal->name[i] = '\0';

	*pKey = rand() % 100000;
}

int main(void)
{
	HHTABLE hHTable;
	KEY key;
	VALUE val;
	VALUE *pVal;
	int i;

	srand(time(NULL));

	if ((hHTable = CreateHashTable(1001)) == NULL) {
		fprintf(stderr, "Cannot create hash table!..\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < 50; ++i) {
		GetRandomKeyVal(&val, &key);
		if (!InsertItem(hHTable, key, &val)) {
			fprintf(stderr, "Cannot insert item!..\n");
			exit(EXIT_FAILURE);
		}
	}

	strcpy(val.name, "Kaan Aslan");
	key = 12345;

	if (!InsertItem(hHTable, key, &val)) {
		fprintf(stderr, "Cannot insert item!..\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < 50; ++i) {
		GetRandomKeyVal(&val, &key);
		if (!InsertItem(hHTable, key, &val)) {
			fprintf(stderr, "Cannot insert item!..\n");
			exit(EXIT_FAILURE);
		}
	}

	WalkHashTable(hHTable, Disp);
	CloseHashTable(hHTable);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Hash Tablosunun "Linear Probing" Yöntemiyle gerçekleştirilmesi
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* HashTable.h */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <stddef.h>

/* Symbolic Connstants */

#define FALSE		0
#define TRUE		1

/* Type Declarations */

typedef int BOOL;

typedef struct tagPERSON {
	char name[32];
	/* other stuff */
} PERSON;

typedef PERSON VALUE;
typedef int KEY;

typedef struct tagHITEM {
	BOOL empty;
	KEY key;
	VALUE val;
} HITEM;

typedef struct tagHTABLE {
	HITEM *pTable;
	size_t tableSize;
	size_t count;
} HTABLE, *HHTABLE;

/* Function Prototypes */

HHTABLE CreateHashTable(size_t tableSize);
BOOL InsertItem(HHTABLE hHTable, KEY key, const VALUE *pVal);
VALUE *FindItem(HHTABLE hHTable, KEY key);
BOOL DeleteItem(HHTABLE hHTable, KEY key);
BOOL WalkHashTable(HHTABLE hHTable, BOOL(*Proc)(const KEY *pKey, VALUE *pVal));
void ClearHashTable(HHTABLE hHTable);
void CloseHashTable(HHTABLE hHTable);

#define GetTableSize(hHTable)		((hHTable)->tableSize)
#define GetCount(hHTable)			((hHTable)->count)

#endif

/* HashTable.c */

#include <stdio.h>
#include <stdlib.h>
#include "HashTable.h"

static size_t HashFunc(KEY key, size_t tableSize);

HHTABLE CreateHashTable(size_t tableSize)
{
	HHTABLE hHTable;
	size_t i;

	if ((hHTable = (HHTABLE)malloc(sizeof(HTABLE))) == NULL)
		return NULL;

	if ((hHTable->pTable = (HITEM *)malloc(tableSize * sizeof(HITEM))) == NULL) {
		free(hHTable);
		return NULL;
	}

	for (i = 0; i < tableSize; ++i)
		hHTable->pTable[i].empty = TRUE;

	hHTable->tableSize = tableSize;
	hHTable->count = 0;

	return hHTable;
}

BOOL InsertItem(HHTABLE hHTable, KEY key, const VALUE *pVal)
{
	size_t index;

	if (hHTable->count >= hHTable->tableSize)
		return FALSE;

	index = HashFunc(key, hHTable->tableSize);
	while (!hHTable->pTable[index].empty)
		index = (index + 1) % hHTable->tableSize;

	hHTable->pTable[index].key = key;
	hHTable->pTable[index].val = *pVal;
	hHTable->pTable[index].empty = FALSE;

	++hHTable->count;

	return TRUE;
}

VALUE *FindItem(HHTABLE hHTable, KEY key)
{
	size_t hash, index;

	hash = index = HashFunc(key, hHTable->tableSize);

	while (!hHTable->pTable[index].empty) {
		if (hHTable->pTable[index].key == key)
			return &hHTable->pTable[index].val;
		index = (index + 1) % hHTable->tableSize;
		if (index == hash)
			break;
	}

	return NULL;
}

BOOL DeleteItem(HHTABLE hHTable, KEY key)
{
	size_t hash, index;

	hash = index = HashFunc(key, hHTable->tableSize);

	while (!hHTable->pTable[index].empty) {
		if (hHTable->pTable[index].key == key) {
			hHTable->pTable[index].empty = TRUE;
			--hHTable->count;
			return TRUE;
		}
		index = (index + 1) % hHTable->tableSize;
		if (index == hash)
			break;
	}

	return FALSE;
}

BOOL WalkHashTable(HHTABLE hHTable, BOOL(*Proc)(const KEY *pKey, VALUE *pVal))
{
	size_t i;

	for (i = 0; i < hHTable->tableSize; ++i)
		if (!hHTable->pTable[i].empty)
			if (!Proc(&hHTable->pTable[i].key, &hHTable->pTable[i].val))
				return FALSE;

	return TRUE;
}

void ClearHashTable(HHTABLE hHTable)
{
	size_t i;

	for (i = 0; hHTable->tableSize; ++i)
		hHTable->pTable[i].empty = TRUE;

	hHTable->count = 0;
}

void CloseHashTable(HHTABLE hHTable)
{
	free(hHTable->pTable);
	free(hHTable);
}

static size_t HashFunc(KEY key, size_t tableSize)
{
	return (key * 2654435761u) % tableSize;
}

/* Test.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "HashTable.h"

BOOL Disp(const KEY *pKey, VALUE *pValue)
{
	printf("Key: %d, Value: %s\n", *pKey, pValue->name);

	return TRUE;
}

void GetRandomKeyVal(VALUE *pVal, KEY *pKey)
{
	int i;

	for (i = 0; i < 31; ++i)
		pVal->name[i] = 'A' + rand() % 26;
	pVal->name[i] = '\0';

	*pKey = rand() % 100000;
}

int main(void)
{
	HHTABLE hHTable;
	KEY key;
	VALUE val;
	VALUE *pVal;
	int i;

	srand(time(NULL));

	if ((hHTable = CreateHashTable(1001)) == NULL) {
		fprintf(stderr, "Cannot create hash table!..\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < 50; ++i) {
		GetRandomKeyVal(&val, &key);
		if (!InsertItem(hHTable, key, &val)) {
			fprintf(stderr, "Cannot insert item!..\n");
			exit(EXIT_FAILURE);
		}
	}

	strcpy(val.name, "Kaan Aslan");
	key = 12345;

	if (!InsertItem(hHTable, key, &val)) {
		fprintf(stderr, "Cannot insert item!..\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < 50; ++i) {
		GetRandomKeyVal(&val, &key);
		if (!InsertItem(hHTable, key, &val)) {
			fprintf(stderr, "Cannot insert item!..\n");
			exit(EXIT_FAILURE);
		}
	}

	WalkHashTable(hHTable, Disp);
	CloseHashTable(hHTable);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	İkili Arama Ağacının gerçekleştirilmesi.
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* BinaryTree. h */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <stddef.h>

/* Symbolic Constants */

#define FALSE		0
#define TRUE		1

/* Type Declaraions */

typedef int BOOL;

typedef struct tagPERSON {
	char name[32];
	/* */
} PERSON;

typedef int KEY;
typedef PERSON VALUE;

typedef struct tagNODE {
	struct tagNODE *pLeft;
	struct tagNODE *pRight;
	KEY key;
	VALUE value;
} NODE;

typedef struct tagQUEUE_NODE {
	NODE *pNode;
	struct tagQUEUE_NODE *pNext;
} QUEUE_NODE;

typedef struct tagBINARY_TREE {
	NODE *pRoot;
	size_t count;
	QUEUE_NODE *pHead;			/* Breadt First Traverve Queue Head Pointer */
	QUEUE_NODE *pTail;			/* Breadt First Traverve Queue Tail Pointer */
} BINARY_TREE, *HBINARY_TREE;

/* Function prototypes */

HBINARY_TREE CreateBinaryTree(void);
BOOL InsertItem(HBINARY_TREE hBTree, KEY key, const VALUE *pValue);
BOOL InsertItemAlternativeWay(HBINARY_TREE hBTree, KEY key, const VALUE *pValue);
VALUE *FindItem(HBINARY_TREE hBTree, KEY key);
BOOL WalkInOrderAscending(HBINARY_TREE hBTree, BOOL(*Proc)(const KEY *key, VALUE *value));
BOOL WalkInOrderDescending(HBINARY_TREE hBTree, BOOL(*Proc)(const KEY *key, VALUE *value));
BOOL WalkPreOrderLeft(HBINARY_TREE hBTree, BOOL(*Proc)(const KEY *key, VALUE *value));
BOOL WalkPreOrderRight(HBINARY_TREE hBTree, BOOL(*Proc)(const KEY *key, VALUE *value));
BOOL WalkPostOrderLeft(HBINARY_TREE hBTree, BOOL(*Proc)(const KEY *key, VALUE *value));
BOOL WalkPostOrderRight(HBINARY_TREE hBTree, BOOL(*Proc)(const KEY *key, VALUE *value));
BOOL WalkBreadthFirst(HBINARY_TREE hBTree, BOOL(*Proc)(const KEY *key, VALUE *value));
BOOL DeleteItem(HBINARY_TREE hBTree, KEY key);
void ClearBinaryTree(HBINARY_TREE hBTree);
void CloseBinaryTree(HBINARY_TREE hBTree);

/* Macros */

#define GetCount(hBTree)		((hBTree)->count)

#endif

/* BinaryTree.c */

#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

static BOOL WalkInOrderAscendingRecur(NODE *pNode, BOOL(*Proc)(const KEY *key, VALUE *value));
static BOOL WalkInOrderDescendingRecur(NODE *pNode, BOOL(*Proc)(const KEY *key, VALUE *value));
static BOOL WalkPreOrderLeftRecur(NODE *pNode, BOOL(*Proc)(const KEY *key, VALUE *value));
static BOOL WalkPreOrderRightRecur(NODE *pNode, BOOL(*Proc)(const KEY *key, VALUE *value));
static BOOL WalkPostOrderLeftRecur(NODE *pNode, BOOL(*Proc)(const KEY *key, VALUE *value));
static BOOL WalkPostOrderRightRecur(NODE *pNode, BOOL(*Proc)(const KEY *key, VALUE *value));
static BOOL PutItem(HBINARY_TREE hBTree, NODE *pNode);
static NODE *GetItem(HBINARY_TREE hBTree);
static void SubTreeShift(HBINARY_TREE hBTree, NODE *pUpParentNode, NODE *pUpNode, NODE *pDownNode);
static void ClearBinaryTreeRecur(NODE *pNode);
void ClearQueue(HBINARY_TREE hBTree);

HBINARY_TREE CreateBinaryTree(void)
{
	HBINARY_TREE hBTree;

	if ((hBTree = (HBINARY_TREE)malloc(sizeof(BINARY_TREE))) == NULL)
		return NULL;

	hBTree->pRoot = NULL;
	hBTree->count = 0;
	hBTree->pTail = hBTree->pHead = NULL;

	return hBTree;
}

BOOL InsertItem(HBINARY_TREE hBTree, KEY key, const VALUE *pValue)
{
	NODE *pNewNode, *pNode, *pParentNode;

	if ((pNewNode = (NODE *)malloc(sizeof(NODE))) == NULL)
		return FALSE;
	pNewNode->pLeft = pNewNode->pRight = NULL;
	pNewNode->key = key;
	pNewNode->value = *pValue;

	if (hBTree->pRoot == NULL) {
		hBTree->pRoot = pNewNode;
		++hBTree->count;
		return TRUE;
	}

	pNode = hBTree->pRoot;

	while (pNode != NULL) {
		pParentNode = pNode;
		if (key < pNode->key)
			pNode = pNode->pLeft;
		else if (key > pNode->key)
			pNode = pNode->pRight;
		else {
			pNode->value = *pValue;
			return TRUE;
		}
	}

	if (key > pParentNode->key)
		pParentNode->pRight = pNewNode;
	else
		pParentNode->pLeft = pNewNode;

	++hBTree->count;

	return TRUE;
}

BOOL InsertItemAlternativeWay(HBINARY_TREE hBTree, KEY key, const VALUE *pValue)
{
	NODE *pNewNode, *pNode;

	if ((pNewNode = (NODE *)malloc(sizeof(NODE))) == NULL)
		return FALSE;
	pNewNode->pLeft = pNewNode->pRight = NULL;
	pNewNode->key = key;
	pNewNode->value = *pValue;

	if (hBTree->pRoot == NULL) {
		hBTree->pRoot = pNewNode;
		++hBTree->count;
		return TRUE;
	}

	pNode = hBTree->pRoot;

	for (;;) {
		if (key < pNode->key)
			if (pNode->pLeft == NULL) {
				pNode->pLeft = pNewNode;
				break;
			}
			else
				pNode = pNode->pLeft;
		else if (key > pNode->key)
			if (pNode->pRight == NULL) {
				pNode->pRight = pNewNode;
				break;
			}
			else
				pNode = pNode->pRight;
		else {
			pNode->value = *pValue;
			return TRUE;
		}
	}

	++hBTree->count;

	return TRUE;
}

VALUE *FindItem(HBINARY_TREE hBTree, KEY key)
{
	NODE *pNode;

	pNode = hBTree->pRoot;

	while (pNode != NULL) {
		if (key > pNode->key)
			pNode = pNode->pRight;
		else if (key < pNode->key)
			pNode = pNode->pLeft;
		else
			return &pNode->value;
	}

	return NULL;
}

static BOOL WalkInOrderAscendingRecur(NODE *pNode, BOOL(*Proc)(const KEY *key, VALUE *value))
{
	if (pNode->pLeft != NULL)
		if (!WalkInOrderAscendingRecur(pNode->pLeft, Proc))
			return FALSE;
	if (!Proc(&pNode->key, &pNode->value))
		return FALSE;
	if (pNode->pRight != NULL)
		if (!WalkInOrderAscendingRecur(pNode->pRight, Proc))
			return FALSE;

	return TRUE;
}

BOOL WalkInOrderAscending(HBINARY_TREE hBTree, BOOL(*Proc)(const KEY *key, VALUE *value))
{
	if (hBTree->pRoot != NULL)
		return WalkInOrderAscendingRecur(hBTree->pRoot, Proc);

	return TRUE;
}

static BOOL WalkInOrderDescendingRecur(NODE *pNode, BOOL(*Proc)(const KEY *key, VALUE *value))
{
	if (pNode->pRight != NULL)
		if (!WalkInOrderDescendingRecur(pNode->pRight, Proc))
			return FALSE;
	if (!Proc(&pNode->key, &pNode->value))
		return FALSE;
	if (pNode->pLeft != NULL)
		if (!WalkInOrderDescendingRecur(pNode->pLeft, Proc))
			return FALSE;

	return TRUE;
}

BOOL WalkInOrderDescending(HBINARY_TREE hBTree, BOOL(*Proc)(const KEY *key, VALUE *value))
{
	if (hBTree->pRoot != NULL)
		return WalkInOrderDescendingRecur(hBTree->pRoot, Proc);

	return TRUE;
}

static BOOL WalkPreOrderLeftRecur(NODE *pNode, BOOL(*Proc)(const KEY *key, VALUE *value))
{
	if (!Proc(&pNode->key, &pNode->value))
		return FALSE;

	if (pNode->pLeft != NULL)
		if (!WalkPreOrderLeftRecur(pNode->pLeft, Proc))
			return FALSE;

	if (pNode->pRight != NULL)
		if (!WalkPreOrderLeftRecur(pNode->pRight, Proc))
			return FALSE;

	return TRUE;
}

BOOL WalkPreOrderLeft(HBINARY_TREE hBTree, BOOL(*Proc)(const KEY *key, VALUE *value))
{
	if (hBTree->pRoot != NULL)
		return WalkPreOrderLeftRecur(hBTree->pRoot, Proc);

	return TRUE;
}

static BOOL WalkPreOrderRightRecur(NODE *pNode, BOOL(*Proc)(const KEY *key, VALUE *value))
{
	if (!Proc(&pNode->key, &pNode->value))
		return FALSE;

	if (pNode->pRight != NULL)
		if (!WalkPreOrderRightRecur(pNode->pRight, Proc))
			return FALSE;

	if (pNode->pLeft != NULL)
		if (!WalkPreOrderRightRecur(pNode->pLeft, Proc))
			return FALSE;

	return TRUE;
}

BOOL WalkPreOrderRight(HBINARY_TREE hBTree, BOOL(*Proc)(const KEY *key, VALUE *value))
{
	if (hBTree->pRoot != NULL)
		return WalkPreOrderRightRecur(hBTree->pRoot, Proc);

	return TRUE;
}

static BOOL WalkPostOrderLeftRecur(NODE *pNode, BOOL(*Proc)(const KEY *key, VALUE *value))
{
	if (pNode->pLeft != NULL)
		if (!WalkPostOrderLeftRecur(pNode->pLeft, Proc))
			return FALSE;

	if (pNode->pRight != NULL)
		if (!WalkPostOrderLeftRecur(pNode->pRight, Proc))
			return FALSE;

	if (!Proc(&pNode->key, &pNode->value))
		return FALSE;

	return TRUE;
}

BOOL WalkPostOrderLeft(HBINARY_TREE hBTree, BOOL(*Proc)(const KEY *key, VALUE *value))
{
	if (hBTree->pRoot != NULL)
		return WalkPostOrderLeftRecur(hBTree->pRoot, Proc);

	return TRUE;
}

static BOOL WalkPostOrderRightRecur(NODE *pNode, BOOL(*Proc)(const KEY *key, VALUE *value))
{
	if (pNode->pRight != NULL)
		if (!WalkPostOrderRightRecur(pNode->pRight, Proc))
			return FALSE;

	if (pNode->pLeft != NULL)
		if (!WalkPostOrderRightRecur(pNode->pLeft, Proc))
			return FALSE;

	if (!Proc(&pNode->key, &pNode->value))
		return FALSE;

	return TRUE;
}

BOOL WalkPostOrderRight(HBINARY_TREE hBTree, BOOL(*Proc)(const KEY *key, VALUE *value))
{
	if (hBTree->pRoot != NULL)
		return WalkPostOrderRightRecur(hBTree->pRoot, Proc);

	return TRUE;
}

BOOL WalkBreadthFirst(HBINARY_TREE hBTree, BOOL(*Proc)(const KEY *key, VALUE *value))
{
	NODE *pNode;
	BOOL result;

	result = TRUE;

	if (hBTree->pRoot != NULL && !PutItem(hBTree, hBTree->pRoot))
		return FALSE;

	while ((pNode = GetItem(hBTree)) != NULL) {
		if (!Proc(&pNode->key, &pNode->value)) {
			result = FALSE;
			break;
		}
		if (pNode->pLeft != NULL && !PutItem(hBTree, pNode->pLeft)) {
			result = FALSE;
			break;
		}
		if (pNode->pRight != NULL && !PutItem(hBTree, pNode->pRight)) {
			result = FALSE;
			break;
		}
	}

	ClearQueue(hBTree);

	return result;
}

static void SubTreeShift(HBINARY_TREE hBTree, NODE *pUpParentNode, NODE *pUpNode, NODE *pDownNode)
{
	if (pUpParentNode == NULL)
		hBTree->pRoot = pDownNode;
	else if (pUpParentNode->pLeft == pUpNode)
		pUpParentNode->pLeft = pDownNode;
	else
		pUpParentNode->pRight = pDownNode;
}

BOOL DeleteItem(HBINARY_TREE hBTree, KEY key)
{
	NODE *pDeleteNode, *pDeleteParentNode, *pReplaceParentNode, *pReplaceNode;

	pDeleteNode = hBTree->pRoot;
	pDeleteParentNode = NULL;

	while (pDeleteNode != NULL) {
		if (pDeleteNode->key == key)
			break;
		pDeleteParentNode = pDeleteNode;
		if (pDeleteNode->key > key)
			pDeleteNode = pDeleteNode->pLeft;
		else if (pDeleteNode->key < key)
			pDeleteNode = pDeleteNode->pRight;
	}

	if (pDeleteNode == NULL)
		return FALSE;

	if (pDeleteNode->pLeft == NULL)
		SubTreeShift(hBTree, pDeleteParentNode, pDeleteNode, pDeleteNode->pRight);
	else if (pDeleteNode->pRight == NULL)
		SubTreeShift(hBTree, pDeleteParentNode, pDeleteNode, pDeleteNode->pLeft);
	else {
		pReplaceParentNode = pDeleteNode;
		pReplaceNode = pDeleteNode->pRight;
		while (pReplaceNode->pLeft != NULL) {
			pReplaceParentNode = pReplaceNode;
			pReplaceNode = pReplaceNode->pLeft;
		}
		if (pReplaceParentNode != pDeleteNode) {
			SubTreeShift(hBTree, pReplaceParentNode, pReplaceNode, pReplaceNode->pRight);
			pReplaceNode->pRight = pDeleteNode->pRight;
		}
		SubTreeShift(hBTree, pDeleteParentNode, pDeleteNode, pReplaceNode);
		pReplaceNode->pLeft = pDeleteNode->pLeft;
	}

	return TRUE;
}

static void ClearBinaryTreeRecur(NODE *pNode)
{
	if (pNode->pLeft != NULL)
		ClearBinaryTreeRecur(pNode->pLeft);
	if (pNode->pRight != NULL)
		ClearBinaryTreeRecur(pNode->pRight);

	free(pNode);
}

void ClearBinaryTree(HBINARY_TREE hBTree)
{
	if (hBTree->pRoot != NULL) {
		ClearBinaryTreeRecur(hBTree->pRoot);
		ClearQueue(hBTree);
		hBTree->pRoot = NULL;
		hBTree->count = 0;
	}
}

static BOOL PutItem(HBINARY_TREE hBTree, NODE *pNode)
{
	QUEUE_NODE *pNewNode;

	if ((pNewNode = (QUEUE_NODE *)malloc(sizeof(QUEUE_NODE))) == NULL)
		return FALSE;
	pNewNode->pNode = pNode;
	pNewNode->pNext = NULL;

	if (hBTree->pTail != NULL)
		hBTree->pTail->pNext = pNewNode;
	else
		hBTree->pHead = pNewNode;
	hBTree->pTail = pNewNode;

	return TRUE;
}

static NODE *GetItem(HBINARY_TREE hBTree)
{
	QUEUE_NODE *pQueueNode;
	NODE *pNode = NULL;

	if (hBTree->pHead == NULL)
		return NULL;

	pQueueNode = hBTree->pHead;
	hBTree->pHead = pQueueNode->pNext;
	if (hBTree->pHead == NULL)
		hBTree->pTail = NULL;

	pNode = pQueueNode->pNode;
	free(pQueueNode);

	return pNode;
}

static void ClearQueue(HBINARY_TREE hBTree)
{
	QUEUE_NODE *pQueueNode, *pTempNode;

	pQueueNode = hBTree->pHead;
	while (pQueueNode != NULL) {
		pTempNode = pQueueNode->pNext;
		free(pQueueNode);
		pQueueNode = pTempNode;
	}

	hBTree->pHead = hBTree->pTail = NULL;
}

void CloseBinaryTree(HBINARY_TREE hBTree)
{
	ClearBinaryTree(hBTree);
	free(hBTree);
}

/* Test.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "BinaryTree.h"

void GetRandomKeyVal(KEY *pKey, VALUE *pVal)
{
	int i;

	for (i = 0; i < 31; ++i)
		pVal->name[i] = 'A' + rand() % 26;
	pVal->name[i] = '\0';

	*pKey = rand() % 1000;
}

BOOL Disp(const KEY *key, VALUE *value)
{
	printf("%d ---> %s\n", *key, value->name);

	return TRUE;
}

int main(void)
{
	HBINARY_TREE hBTree;
	int i;
	KEY key;
	VALUE value;
	KEY keys[] = { 100, 50, 120, 25, 75, 115, 150, 10, 30, 60, 80, 145, 200 };
	VALUE values[] = { {"Sacit Erol"}, {"Ayşe Er"}, {"Demir Büyüközkaya"}, {"Harun Şanlı"},
		{"Fehmi Sakin"}, {"Olcay Torun" }, {"Kaan Aslan"}, {"Güray Sönmez"}, {"Bulut Hakkı"},
		{"Defne Yılmaz"}, {"Timur Selçuk"}, {"Kazım Koç"}, {"Gül Koca"} };

	srand(time(NULL));

	if ((hBTree = CreateBinaryTree()) == NULL) {
		fprintf(stderr, "Cannot create binary tree!..\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < 20; ++i) {
		GetRandomKeyVal(&key, &value);
		if (!InsertItem(hBTree, key, &value)) {
			fprintf(stderr, "cannot insert item!..\n");
			exit(EXIT_FAILURE);
		}
		printf("%d --> %s\n", key, value.name);
	}

	for (i = 0; i < sizeof(keys) / sizeof(*keys); ++i) {
		if (!InsertItem(hBTree, keys[i], &values[i])) {
			fprintf(stderr, "cannot insert item!..\n");
			exit(EXIT_FAILURE);
		}
		printf("%d --> %s\n", keys[i], values[i].name);
	}

	printf("------------------------\n");
	printf("Inorder Ascending\n\n");
	WalkInOrderAscending(hBTree, Disp);
	printf("--------------------------\n");
	printf("Inorder Descending\n\n");
	WalkInOrderDescending(hBTree, Disp);
	printf("--------------------------\n");
	printf("Preorder Left\n\n");
	WalkPreOrderLeft(hBTree, Disp);
	printf("--------------------------\n");
	printf("Preorder Right\n\n");
	WalkPreOrderRight(hBTree, Disp);
	printf("--------------------------\n");
	printf("Postorder Left\n\n");
	WalkPostOrderLeft(hBTree, Disp);
	printf("--------------------------\n");
	printf("Postorder Right\n\n");
	WalkPostOrderRight(hBTree, Disp);

	ClearBinaryTree(hBTree);

	for (i = 0; i < sizeof(keys) / sizeof(*keys); ++i) {
		if (!InsertItemAlternativeWay(hBTree, keys[i], &values[i])) {
			fprintf(stderr, "cannot insert item!..\n");
			exit(EXIT_FAILURE);
		}
	}

	printf("------------------------\n");
	printf("Breadth First\n\n");

	WalkBreadthFirst(hBTree, Disp);

	if (!DeleteItem(hBTree, 100)) {
		fprintf(stderr, "Cannot delete item!..\n");
		exit(EXIT_FAILURE);
	}

	printf("------------------------\n");
	printf("Breadth First\n\n");

	WalkBreadthFirst(hBTree, Disp);

	CloseBinaryTree(hBTree);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Heap ağaçlarıyla Öncelik kutruklarının (priority queues) gerçekleştirimi.

-------------------------------------------------------------------------------------------------------------------------------------------*/

/* PriorityQueue.h */

#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include <stddef.h>

/* Symbolic Constants */

#define FALSE				0
#define TRUE				1

#define DEF_CAPACITY		8


/* Type Declarations */

typedef int BOOL;

typedef struct tagPERSON {
	char name[32];
	/* ... */
} PERSON;

typedef PERSON VALUE;
typedef int PRIORITY;

typedef struct tagHEAP_ITEM {
	PRIORITY prio;
	VALUE value;
} HEAP_ITEM;

typedef struct tagPRIORITY_QUEUE {
	HEAP_ITEM *pItems;
	size_t capacity;
	size_t count;
} PRIORITY_QUEUE, *HPRIORITY_QUEUE;

/* Function Prototypes */

HPRIORITY_QUEUE CreatePriorityQueue(void);
HPRIORITY_QUEUE CreatePriorityQueueWithCapacity(size_t capacity);
BOOL Put(HPRIORITY_QUEUE hPQueue, PRIORITY prio, const VALUE *pValue);
BOOL Get(HPRIORITY_QUEUE hPQueue, PRIORITY *prio, VALUE *pValue);

/* Macros */

#define GetCount(hPQueue)		((hPQueue)->count)
#define GetCapacity(hPQueue)	((hPQueue)->capacity)
#define IsEmpty(hPQueue)		((hPQueue)->count == 0)

#endif

/* PriorityQueue.c */

#include <stdio.h>
#include <stdlib.h>
#include "PriorityQueue.h"

HPRIORITY_QUEUE CreatePriorityQueueWithCapacity(size_t capacity)
{
	HPRIORITY_QUEUE hPQueue;

	if ((hPQueue = (HPRIORITY_QUEUE)malloc(sizeof(PRIORITY_QUEUE))) == NULL)
		return NULL;
	if ((hPQueue->pItems = (HEAP_ITEM *)malloc(capacity * sizeof(HEAP_ITEM))) == NULL) {
		free(hPQueue);
		return NULL;
	}
	hPQueue->capacity = capacity;
	hPQueue->count = 0;

	return hPQueue;
}

HPRIORITY_QUEUE CreatePriorityQueue(void)
{
	return CreatePriorityQueueWithCapacity(DEF_CAPACITY);
}

BOOL Put(HPRIORITY_QUEUE hPQueue, PRIORITY prio, const VALUE *pValue)
{
	HEAP_ITEM *items;
	size_t i;

	if ((hPQueue->count + 1) == hPQueue->capacity) {
		if ((items = (HEAP_ITEM *)realloc(hPQueue->pItems, hPQueue->capacity * sizeof(HEAP_ITEM) * 2)) == NULL)
			return FALSE;
		hPQueue->pItems = items;
		hPQueue->capacity *= 2;
	}

	i = hPQueue->count + 1;
	if (i != 1)
		while (prio > hPQueue->pItems[i / 2].prio && i > 1) {
			hPQueue->pItems[i] = hPQueue->pItems[i / 2];
			i /= 2;
		}

	hPQueue->pItems[i].prio = prio;
	hPQueue->pItems[i].value = *pValue;
	++hPQueue->count;

	return TRUE;
}

BOOL Get(HPRIORITY_QUEUE hPQueue, PRIORITY *prio, VALUE *pValue)
{
	HEAP_ITEM lastItem;
	size_t i, ci;

	if (hPQueue->count == 0)
		return FALSE;

	*prio = hPQueue->pItems[1].prio;
	*pValue = hPQueue->pItems[1].value;

	lastItem = hPQueue->pItems[hPQueue->count];

	i = 1;
	ci = 2;

	while (ci < hPQueue->count) {
		if (ci + 1 < hPQueue->count && hPQueue->pItems[ci].prio < hPQueue->pItems[ci + 1].prio)
			++ci;
		if (lastItem.prio > hPQueue->pItems[ci].prio)
			break;
		hPQueue->pItems[i] = hPQueue->pItems[ci];
		i = ci;
		ci *= 2;
	}
	hPQueue->pItems[i] = lastItem;

	--hPQueue->count;
}

/* Test.c */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "PriorityQueue.h"

int main(void)
{
	HPRIORITY_QUEUE hPQueue;
	PRIORITY priorities[] = { 100, 80, 89, 34, 23, 90, 68, 120, 85, 77 };
	VALUE values[] = { {"Ali Serçe"}, {"Kaan Aslan"}, {"Sacit Ünlü"}, {"Hasan Kılıçaslan"}, {"Mustafa Yılmaz"},
		{"Gülümser Yılmaz"}, {"Jale Kanlıdere"}, {"Yücel Gündüz"}, {"Kazım Tanış"}, {"Rıza Bozkurt"} };
	PRIORITY prio;
	VALUE value;
	int i;

	if ((hPQueue = CreatePriorityQueue()) == NULL) {
		fprintf(stderr, "Cannot create priority queue!..\n");
		exit(EXIT_FAILURE);
	}

#define SIZE	(sizeof(priorities) / sizeof(*priorities))

	for (i = 0; i < SIZE; ++i) {
		if (!Put(hPQueue, priorities[i], &values[i])) {
			fprintf(stderr, "cannot put priority queue!..\n");
			exit(EXIT_FAILURE);
		}
	}

	for (i = 1; i < hPQueue->count + 1; ++i)
		printf("%d ", hPQueue->pItems[i].prio);
	printf("\n");

	while (!IsEmpty(hPQueue)) {
		Get(hPQueue, &prio, &value);
		printf("Priority: %d, Value=%s\n", prio, value.name);
	}

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Veri yapılarının genelleştirilmesinin bir yolu fonksiyonların her tür için çalışabilir hale getirilmesidir. Bunun fonksiyonlar void gösterici 
	parametreleri alır. Karşılaştırma işlemleri karşılaştırma fonksiyonlarına yaptırılır. 

	Aşağıdaki örnekte ikilci ağaç bu biçimde türden bağımsız bir biçimde oluşturulmaktadır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* BinaryTree.h */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <stddef.h>

/* Symbolic Constants */

#define FALSE		0
#define TRUE		1

/* Type Declaraions */

typedef int BOOL;
typedef int (*COMPARE)(const void *, const void *);

typedef struct tagNODE {
	struct tagNODE *pLeft;
	struct tagNODE *pRight;
	char key[];
	/* key ....*/
	/* value .... */
} NODE;

typedef struct tagBINARY_TREE {
	NODE *pRoot;
	size_t keySize;
	size_t valueSize;
	size_t count;
	COMPARE compare;

} BINARY_TREE, *HBINARY_TREE;

/* Function prototypes */

HBINARY_TREE CreateBinaryTree(size_t keySize, size_t valueSize, COMPARE compare);
BOOL InsertItem(HBINARY_TREE hBTree, const void *pKey, const void *pValue);
BOOL DeleteItem(HBINARY_TREE hBTree, const void *pKey);
BOOL WalkInOrderAscending(HBINARY_TREE hBTree, BOOL(*Proc)(const void *pKey, void *pValue));
BOOL WalkInOrderDescending(HBINARY_TREE hBTree, BOOL(*Proc)(const void *pKey, void *pValue));
void ClearBinaryTree(HBINARY_TREE hBTree);

/* Macros */

#define GetCount(hBTree)		((hBTree)->count)

#endif

/* BinaryTree.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTree.h"

static NODE *CreateNode(HBINARY_TREE hBTree, const void *pKey, const void *pValue);
static BOOL WalkInOrderAscendingRecur(NODE *pNode, size_t keySize, BOOL(*Proc)(const void *pKey, void *pValue));
static void ClearBinaryTreeRecur(NODE *pNode);
static void SubTreeShift(HBINARY_TREE hBTree, NODE *pUpParentNode, NODE *pUpNode, NODE *pDownNode);
static BOOL WalkInOrderDescendingRecur(NODE *pNode, size_t keySize, BOOL(*Proc)(const void *pKey, void *pValue));

HBINARY_TREE CreateBinaryTree(size_t keySize, size_t valueSize, COMPARE compare)
{
	HBINARY_TREE hBTree;

	if ((hBTree = (HBINARY_TREE)malloc(sizeof(BINARY_TREE))) == NULL)
		return NULL;

	hBTree->pRoot = NULL;
	hBTree->keySize = keySize;
	hBTree->valueSize = valueSize;
	hBTree->count = 0;
	hBTree->compare = compare;

	return hBTree;
}

BOOL InsertItem(HBINARY_TREE hBTree, const void *pKey, const void *pValue)
{
	NODE *pNewNode, *pNode, *pParentNode;
	int compResult;

	if ((pNewNode = CreateNode(hBTree, pKey, pValue)) == NULL)
		return FALSE;

	if (hBTree->pRoot == NULL) {
		hBTree->pRoot = pNewNode;
		++hBTree->count;
		return TRUE;
	}

	pNode = hBTree->pRoot;

	while (pNode != NULL) {
		pParentNode = pNode;
		compResult = hBTree->compare(pKey, &pNode->key);
		if (compResult < 0)
			pNode = pNode->pLeft;
		else if (compResult > 0)
			pNode = pNode->pRight;
		else {
			memcpy(pNode->key + hBTree->keySize, pValue, hBTree->valueSize);
			return TRUE;
		}
	}

	if (hBTree->compare(pKey, pParentNode->key) > 0)
		pParentNode->pRight = pNewNode;
	else
		pParentNode->pLeft = pNewNode;

	++hBTree->count;

	return TRUE;
}

static void SubTreeShift(HBINARY_TREE hBTree, NODE *pUpParentNode, NODE *pUpNode, NODE *pDownNode)
{
	if (pUpParentNode == NULL)
		hBTree->pRoot = pDownNode;
	else if (pUpParentNode->pLeft == pUpNode)
		pUpParentNode->pLeft = pDownNode;
	else
		pUpParentNode->pRight = pDownNode;
}

BOOL DeleteItem(HBINARY_TREE hBTree, const void *pKey)
{
	NODE *pDeleteNode, *pDeleteParentNode, *pReplaceParentNode, *pReplaceNode;
	int result;

	pDeleteNode = hBTree->pRoot;
	pDeleteParentNode = NULL;

	while (pDeleteNode != NULL) {
		result = hBTree->compare(pDeleteNode->key, pKey);
		if (result == 0)
			break;
		pDeleteParentNode = pDeleteNode;
		if (result > 0)
			pDeleteNode = pDeleteNode->pLeft;
		else if (result < 0)
			pDeleteNode = pDeleteNode->pRight;
	}

	if (pDeleteNode == NULL)
		return FALSE;

	if (pDeleteNode->pLeft == NULL)
		SubTreeShift(hBTree, pDeleteParentNode, pDeleteNode, pDeleteNode->pRight);
	else if (pDeleteNode->pRight == NULL)
		SubTreeShift(hBTree, pDeleteParentNode, pDeleteNode, pDeleteNode->pLeft);
	else {
		pReplaceParentNode = pDeleteNode;
		pReplaceNode = pDeleteNode->pRight;
		while (pReplaceNode->pLeft != NULL) {
			pReplaceParentNode = pReplaceNode;
			pReplaceNode = pReplaceNode->pLeft;
		}
		if (pReplaceParentNode != pDeleteNode) {
			SubTreeShift(hBTree, pReplaceParentNode, pReplaceNode, pReplaceNode->pRight);
			pReplaceNode->pRight = pDeleteNode->pRight;
		}
		SubTreeShift(hBTree, pDeleteParentNode, pDeleteNode, pReplaceNode);
		pReplaceNode->pLeft = pDeleteNode->pLeft;
	}

	return TRUE;
}

static NODE *CreateNode(HBINARY_TREE hBTree, const void *pKey, const void *pValue)
{
	NODE *pNode;
	size_t size;

	size = sizeof(NODE) + hBTree->keySize + hBTree->valueSize;
	if ((pNode = malloc(size)) == NULL)
		return NULL;

	pNode->pLeft = pNode->pRight = NULL;
	memcpy(pNode->key, pKey, hBTree->keySize);
	memcpy(pNode->key + hBTree->keySize, pValue, hBTree->valueSize);

	return pNode;
}

static BOOL WalkInOrderAscendingRecur(NODE *pNode, size_t keySize, BOOL(*Proc)(const void *pKey, void *pValue))
{
	if (pNode->pLeft != NULL)
		if (!WalkInOrderAscendingRecur(pNode->pLeft, keySize, Proc))
			return FALSE;
	if (!Proc(pNode->key, pNode->key + keySize))
		return FALSE;
	if (pNode->pRight != NULL)
		if (!WalkInOrderAscendingRecur(pNode->pRight, keySize, Proc))
			return FALSE;

	return TRUE;
}

BOOL WalkInOrderAscending(HBINARY_TREE hBTree, BOOL(*Proc)(const void *pKey, void *pValue))
{
	if (hBTree->pRoot != NULL)
		return WalkInOrderAscendingRecur(hBTree->pRoot, hBTree->keySize, Proc);

	return TRUE;
}


static BOOL WalkInOrderDescendingRecur(NODE *pNode, size_t keySize, BOOL(*Proc)(const void *pKey, void *pValue))
{
	if (pNode->pRight != NULL)
		if (!WalkInOrderDescendingRecur(pNode->pRight, keySize, Proc))
			return FALSE;
	if (!Proc(pNode->key, pNode->key + keySize))
		return FALSE;
	if (pNode->pLeft != NULL)
		if (!WalkInOrderDescendingRecur(pNode->pLeft, keySize, Proc))
			return FALSE;

	return TRUE;
}

BOOL WalkInOrderDescending(HBINARY_TREE hBTree, BOOL(*Proc)(const void *pKey, void *pValue))
{
	if (hBTree->pRoot != NULL)
		return WalkInOrderDescendingRecur(hBTree->pRoot, hBTree->keySize, Proc);

	return TRUE;
}

static void ClearBinaryTreeRecur(NODE *pNode)
{
	if (pNode->pLeft != NULL)
		ClearBinaryTreeRecur(pNode->pLeft);
	if (pNode->pRight != NULL)
		ClearBinaryTreeRecur(pNode->pRight);

	free(pNode);
}

void ClearBinaryTree(HBINARY_TREE hBTree)
{
	if (hBTree->pRoot != NULL) {
		ClearBinaryTreeRecur(hBTree->pRoot);

		hBTree->pRoot = NULL;
		hBTree->count = 0;
	}
}

/* Test.c */

#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

/* Anahtar int, değerler PERSON */

typedef struct tagPERSON {
	char name[32];
} PERSON;

int KeyCompare(const void *pKey1, const void *pKey2)
{
	const int *pi1 = (const int *)pKey1;
	const int *pi2 = (const int *)pKey2;

	return *pi1 - *pi2;
}

BOOL Disp(const void *pKey, void *pValue)
{
	const int *pNo;
	PERSON *pPerson;

	pNo = (int *)pKey;
	pPerson = (PERSON *)pValue;

	printf("%d ---> %s\n", *pNo, pPerson->name);

	return TRUE;
}

int main(void)
{
	HBINARY_TREE hBTree;
	int keys[] = { 100, 50, 120, 25, 75, 115, 150, 10, 30, 60, 80, 145, 200 };
	PERSON persons[] = { {"Sacit Erol"}, {"Ayşe Er"}, {"Demir Büyüközkaya"}, {"Harun Şanlı"},
		{"Fehmi Sakin"}, {"Olcay Torun" }, {"Kaan Aslan"}, {"Güray Sönmez"}, {"Bulut Hakkı"},
		{"Defne Yılmaz"}, {"Timur Selçuk"}, {"Kazım Koç"}, {"Gül Koca"} };
	int i;
	int key = 80;

	if ((hBTree = CreateBinaryTree(sizeof(int), sizeof(PERSON), KeyCompare)) == NULL) {
		fprintf(stderr, "Cannot create binary tree!..\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < sizeof(keys) / sizeof(*keys); ++i) {
		if (!InsertItem(hBTree, &keys[i], &persons[i])) {
			fprintf(stderr, "cannot insert item!..\n");
			exit(EXIT_FAILURE);
		}
	}

	WalkInOrderAscending(hBTree, Disp);

	if (!DeleteItem(hBTree, &key)) {
		fprintf(stderr, "cannot find item!..\n");
		exit(EXIT_FAILURE);
	}

	printf("---------------------------\n");

	WalkInOrderDescending(hBTree, Disp);

	ClearBinaryTree(hBTree);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	C'nin <stddef.h> içeriisnde bildirilmiş olan offsetof makrosu yapının tür ismini ve yapıdaki bir eleman ismini parametre olarak alır, o elemanın 
	yapının başından itibaren kaçıncı offsette olduğunu verir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/* #define offsetof(type, member)	 */

struct SAMPLE {
	int a;
	char b;
	int c;
	char d;
	double e;
	int f;
};

int main(void)
{
	int result;

	result = offsetof(struct SAMPLE, e);
	printf("%lu\n", (unsigned long)result);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	offsetof makrosu klasik biçimde aşağıdaki gibi yazılmaktadır:
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stddef.h>

#define myoffsetof(type, member)	 ((size_t) &((type *)0)->member)

struct SAMPLE {
	int a;
	char b;
	int c;
	char d;
	double e;
	int f;
};

int main(void)
{
	int result;

	result = myoffsetof(struct SAMPLE, e);
	printf("%lu\n", (unsigned long)result);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
		Bir yapı içerisindeki bir elemanınadresini, o elemanın ismini ve yapının türünü bildiğimizi varsayalım. Bu durumda elemaın adresine ilişkin yapuı nesnessinin
		başlangıç adresini veren container_of biçiminde bir makro yazabiliriz. Bu makro standart değildir. 

		#define container_of(ptr, type, member)			((type *) ((char *) (ptr) - offsetof(type, member)))

		Makronun birinci parametresi nesne içerisindeki elemanın adresi, ikinci parametresi yapının tür ismi ve üçüncü parametresi elemanın ismini almaktadır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stddef.h>

#define container_of(ptr, type, member)			((type *) ((char *) (ptr) - offsetof(type, member)))

struct SAMPLE {
	int a;
	char b;
	int c;
	char d;
	double e;
	int f;
};

int main(void)
{
	struct SAMPLE s = { 10, 'x', 20, 'y', 12.4, 100 };
	double *pd = &s.e;
	struct SAMPLE *ps;

	ps = container_of(pd, struct SAMPLE, e);
	printf("%d, %f\n", ps->a, ps->e);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Veri yapılarını genelleştirmenin diğer bir yolu da asıl türü değil, meta data alanları üzerinde veri yapısını oluşturmaktır. 
	Örneğin aslında NODE'ları birbirine bağlayan bir bağlı liste söz konusu olabilir. Bu node'lar da başka bir yapının içerisinde bulunabilir. 
	Bu durumda biz aslında bu yapıları biribirine bağlamış oluruz. Örneğin Linux kernel kodlarında veri yapılarının genelleşirilmesi bu teknikle 
	gerçekleştirilmektedir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* GenericList.h */

#ifndef GENERICLIST_H_
#define GENERICLIST_H_

#include <stddef.h>

/* Symbolic Constants */

#define FALSE		0
#define TRUE		1

/* Type Declarations */

typedef int BOOL;

typedef struct tagNODE {
	struct tagNODE *pNext;
	struct tagNODE *pPrev;
} NODE;

/* Fuciton Prototypes */

NODE *AddItemHead(NODE *pList, NODE *pNewNode);
NODE *AddItemTail(NODE *pList, NODE *pNewNode);
NODE *InsertItemNext(NODE *pInsertNode, NODE *pNewNode);
NODE *InsertItemPrev(NODE *pInsertNode, NODE *pNewNode);
void DeleteItem(NODE *pDeleteNode);
BOOL WalkList(NODE *pList, BOOL(*Proc) (NODE *));
BOOL WalkListRev(NODE *pList, BOOL(*Proc) (NODE *));

/* Macros */

#define container_of(ptr, type, member)			((type *) ((char *) (ptr) - offsetof(type, member)))

#endif

/* GenericList.c */

#include <stdio.h>
#include <stdlib.h>
#include "GenericList.h"

NODE *AddItemHead(NODE *pList, NODE *pNewNode)
{
	return InsertItemNext(pList, pNewNode);
}

NODE *AddItemTail(NODE *pList, NODE *pNewNode)
{
	return InsertItemPrev(pList, pNewNode);
}

NODE *InsertItemNext(NODE *pInsertNode, NODE *pNewNode)
{
	pNewNode->pPrev = pInsertNode;
	pNewNode->pNext = pInsertNode->pNext;
	pInsertNode->pNext->pPrev = pNewNode;
	pInsertNode->pNext = pNewNode;

	return pNewNode;
}

NODE *InsertItemPrev(NODE *pInsertNode, NODE *pNewNode)
{
	pInsertNode->pPrev->pNext = pNewNode;
	pNewNode->pNext = pInsertNode;
	pNewNode->pPrev = pInsertNode->pPrev;
	pInsertNode->pPrev = pNewNode;

	return pNewNode;
}

void DeleteItem(NODE *pDeleteNode)
{
	pDeleteNode->pPrev->pNext = pDeleteNode->pNext;
	pDeleteNode->pNext->pPrev = pDeleteNode->pPrev;
}

BOOL WalkList(NODE *pList, BOOL(*Proc) (NODE *))
{
	NODE *pNode;

	for (pNode = pList->pNext; pNode != pList; pNode = pNode->pNext)
		if (!Proc(pNode))
			return FALSE;

	return TRUE;
}

BOOL WalkListRev(NODE *pList, BOOL(*Proc) (NODE *))
{
	NODE *pNode;

	for (pNode = pList->pPrev; pNode != pList; pNode = pNode->pPrev)
		if (!Proc(pNode))
			return FALSE;

	return TRUE;
}

/* Test.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GenericList.h"

struct PERSON {
	char name[32];
	int no;
	NODE node;
};

NODE g_listPerson = { &g_listPerson, &g_listPerson };

struct CITY {
	char city[64];
	NODE node;
	int plate;
};

NODE g_listCity = { &g_listCity, &g_listCity };

BOOL DispPerson(NODE *pNode)
{
	struct PERSON *pperson;

	pperson = container_of(pNode, struct PERSON, node);
	printf("%s, %d\n", pperson->name, pperson->no);

	return TRUE;
}

BOOL DispCity(NODE *pNode)
{
	struct CITY *pcity;

	pcity = container_of(pNode, struct CITY, node);
	printf("%s, %d\n", pcity->city, pcity->plate);

	return TRUE;
}

int main(void)
{
	struct PERSON persons[] = { {"Sacit Erol", 10}, {"Ayşe Er", 20}, {"Demir Büyüközkaya", 30}, {"Harun Şanlı", 40},
	{"Fehmi Sakin", 50}, {"Olcay Torun", 60 }, {"Kaan Aslan", 70}, {"Güray Sönmez", 80}, {"Bulut Hakkı", 90},
	{"Defne Yılmaz", 100}, {"Timur Selçuk", 110}, {"Kazım Koç", 120}, {"Gül Koca", 130} };

	struct CITY cities[] = { {.city = "Adana", .plate = 1}, {.city = "Eskişehir", .plate = 26}, {.city = "İzmir", .plate = 35}, {.city = "İstanbul", .plate = 34} };
	int i;

	for (i = 0; i < 13; ++i)
		AddItemTail(&g_listPerson, &persons[i].node);

	WalkList(&g_listPerson, DispPerson);

	printf("---------------------\n");

	for (i = 0; i < 4; ++i)
		AddItemTail(&g_listCity, &cities[i].node);

	WalkList(&g_listCity, DispCity);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Bu teknikle biz bir yapı nesnesini iki ayrı bağlı listenin elemanı haline getirebiliriz. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

struct STUDENT {
	char name[32];
	int no;
	NODE nodeClass;
	NODE nodeLibrary;
};

/*------------------------------------------------------------------------------------------------------------------------------------------
	Aslında yukarıdaki genelleştirme bir handle sistemi biçiminde de gerçekleştirilebilir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* GenericList.h */

#ifndef GENERICLIST_H_
#define GENERICLIST_H_

#include <stddef.h>

/* Symbolic Constants */

#define FALSE		0
#define TRUE		1

/* Type Declarations */

typedef int BOOL;

typedef struct tagNODE {
	struct tagNODE *pNext;
	struct tagNODE *pPrev;
} NODE;

typedef struct tagLIST {
	NODE head;
	size_t count;
} LIST, *HLIST;

/* Fuciton Prototypes */

HLIST CreateList(void);
NODE *AddItemHead(HLIST hList, NODE *pNewNode);
NODE *AddItemTail(HLIST hList, NODE *pNewNode);
NODE *InsertItemNext(HLIST hList, NODE *pInsertNode, NODE *pNewNode);
NODE *InsertItemPrev(HLIST hList, NODE *pInsertNode, NODE *pNewNode);
void DeleteItem(HLIST hList, NODE *pDeleteNode);
BOOL WalkList(HLIST hList, BOOL(*Proc) (NODE *));
BOOL WalkListRev(HLIST hList, BOOL(*Proc) (NODE *));
void CloseList(HLIST hList);

/* Macros */

#define GetCount(hList)			((hList)->count)
#define container_of(ptr, type, member)			((type *) ((char *) (ptr) - offsetof(type, member)))

#endif

/* GenericList.c */

#include <stdio.h>
#include <stdlib.h>
#include "GenericList.h"

HLIST CreateList(void)
{
	HLIST hList;

	if ((hList = (HLIST)malloc(sizeof(LIST))) == NULL)
		return NULL;

	hList->head.pNext = &hList->head;
	hList->head.pPrev = &hList->head;
	hList->count = 0;

	return hList;
}

NODE *AddItemHead(HLIST hList, NODE *pNewNode)
{
	return InsertItemNext(hList, &hList->head, pNewNode);
}

NODE *AddItemTail(HLIST hList, NODE *pNewNode)
{
	return InsertItemPrev(hList, &hList->head, pNewNode);
}

NODE *InsertItemNext(HLIST hList, NODE *pInsertNode, NODE *pNewNode)
{
	pNewNode->pPrev = pInsertNode;
	pNewNode->pNext = pInsertNode->pNext;
	pInsertNode->pNext->pPrev = pNewNode;
	pInsertNode->pNext = pNewNode;

	++hList->count;

	return pNewNode;
}

NODE *InsertItemPrev(HLIST hList, NODE *pInsertNode, NODE *pNewNode)
{
	pInsertNode->pPrev->pNext = pNewNode;
	pNewNode->pNext = pInsertNode;
	pNewNode->pPrev = pInsertNode->pPrev;
	pInsertNode->pPrev = pNewNode;

	++hList->count;

	return pNewNode;
}

void DeleteItem(HLIST hList, NODE *pDeleteNode)
{
	pDeleteNode->pPrev->pNext = pDeleteNode->pNext;
	pDeleteNode->pNext->pPrev = pDeleteNode->pPrev;

	--hList->count;
}

BOOL WalkList(HLIST hList, BOOL(*Proc) (NODE *))
{
	NODE *pNode;

	for (pNode = hList->head.pNext; pNode != &hList->head; pNode = pNode->pNext)
		if (!Proc(pNode))
			return FALSE;

	return TRUE;
}

BOOL WalkListRev(HLIST hList, BOOL(*Proc) (NODE *))
{
	NODE *pNode;

	for (pNode = hList->head.pPrev; pNode != &hList->head; pNode = pNode->pPrev)
		if (!Proc(pNode))
			return FALSE;

	return TRUE;
}

void CloseList(HLIST hList)
{
	free(hList);
}

/* Test.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GenericList.h"

struct PERSON {
	char name[32];
	int no;
	NODE node;
};

struct CITY {
	char city[64];
	NODE node;
	int plate;
};
BOOL DispPerson(NODE *pNode)
{
	struct PERSON *pperson;

	pperson = container_of(pNode, struct PERSON, node);
	printf("%s, %d\n", pperson->name, pperson->no);

	return TRUE;
}

BOOL DispCity(NODE *pNode)
{
	struct CITY *pcity;

	pcity = container_of(pNode, struct CITY, node);
	printf("%s, %d\n", pcity->city, pcity->plate);

	return TRUE;
}

int main(void)
{
	struct PERSON persons[] = { {"Sacit Erol", 10}, {"Ayşe Er", 20}, {"Demir Büyüközkaya", 30}, {"Harun Şanlı", 40},
	{"Fehmi Sakin", 50}, {"Olcay Torun", 60 }, {"Kaan Aslan", 70}, {"Güray Sönmez", 80}, {"Bulut Hakkı", 90},
	{"Defne Yılmaz", 100}, {"Timur Selçuk", 110}, {"Kazım Koç", 120}, {"Gül Koca", 130} };

	struct CITY cities[] = { {.city = "Adana", .plate = 1}, {.city = "Eskişehir", .plate = 26}, {.city = "İzmir", .plate = 35}, {.city = "İstanbul", .plate = 34} };
	int i;

	HLIST hPersonList, hCityList;


	if ((hPersonList = CreateList()) == NULL) {
		fprintf(stderr, "cannot create list!..\n");
		exit(EXIT_FAILURE);
	}

	if ((hCityList = CreateList()) == NULL) {
		fprintf(stderr, "cannot create list!..\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < 13; ++i)
		AddItemTail(hPersonList, &persons[i].node);

	WalkList(hPersonList, DispPerson);

	printf("---------------------\n");

	for (i = 0; i < 4; ++i)
		AddItemTail(hCityList, &cities[i].node);

	WalkList(hCityList, DispCity);

	CloseList(hPersonList);
	CloseList(hCityList);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Graf veri yapısı için iki yöntem sık kullanılmaktadır:

	1) Komşuluk Matrisi (Adjacency Matrix) Yöntemi
	2) Komşuluk Listesi (Adjacency List) Yöntemi

	Komşuluk matrisi yönteminde her vertx'ten hagi vertex'lere gidilebildiği bir matriste tutulur. Komşuluk listesi yönteminde bir her vertex'ten 
	hangi vertex'lere gidilebildiği bir listede tutulmaktadır. Genellikle komşuluk listesi yöntemi tercih edilmektedir. Tabii bu yöntemde bir vertex'ten 
	belli bir vertex'e edge olup olmadığı sıralı aramayla belirlenmektedir. Buradaki aramayı iyileştirmek için hash tabloları ya da arama ağaçları kullanılabilmektedir. 

	Graf veri yapısını genel hale getirmek oldukça zordur. Genellikle uygulamacılar özel problemleri için ona özgü bir graf veri yapısı oluştururlar. Pek çok graph 
	kütüphanesi bulunmaktadır. Bunların en ünlüsü C++ boost graph kütüphanesidir. Pek çok graf kütüphanesi tasarım olarak boost kütüphanesini temel almıştır. 

	Graph veri yapısındaki bir problem vertex'lerde ve edge'lerde bilgi tutmaktır. Bu bilginin genel olarak tutulması biraz zor bir işlem olmaktadır. 
	Aşağıdaki örnekte graph'taki tüm vertexlerin adresleri dinamik büyütülen bir gösterici dizinde tutulmuştur. Her vertex içerisinde yine o vertexten
	gidilebilecek edge'ler dinamik dizide tutulmuştur. Yani veri yapısı bir vertex dizisinden ve vertex'lerde edge dizilerinden oluşmaktadır. Veri yapısı oluşturulduktan sonra
	bu veri yapısı üzerinde "depth first" vertex dolaşım algoritması uygulanmış ve aynı zamanda iki vertex arasında mümkün yol bulunmaya çalışılmıştır. 
-------------------------------------------------------------------------------------------------------------------------------------------*/
/* Graph.h */


#ifndef GRAPH_H_
#define GRAPH_H_

#define DEF_VERTEX_CAPACITY		4
#define DEF_EDGE_CAPACITY		4

#define FALSE					0
#define TRUE					1

#include <stddef.h>

/* Type Declarations */

typedef int BOOL;

typedef struct tagEDGE {
	struct tagVERTEX *pFirst;
	struct tagVERTEX *pSecond;
	/* other stuff */
	int length;
} EDGE;

typedef struct tagVERTEX {
	EDGE **pEdges;
	size_t size;
	size_t capacity;
	
	char name[32];
	int index;
	/* other stuff */

} VERTEX;

typedef struct tagDGRAPH {
	VERTEX **pVertices;
	size_t size;
	size_t capacity;
} DGRAPH, *HDGRAPH;

/* Function Prototypes */

HDGRAPH CreateGraph(void);
VERTEX *AddVertex(HDGRAPH hGraph, const char *name);
EDGE *AddEdge(HDGRAPH hDGraph, VERTEX *pFirst, VERTEX *pSecond, int length);
EDGE *AddEdgeWithName(HDGRAPH hDGraph, const char *nameFirst, const char *nameSecond, int length);
VERTEX *FindVertex(HDGRAPH hDGraph, const char *name);
BOOL DepthFirstTraverse(HDGRAPH hDGraph, const char *name, BOOL(*Proc)(const VERTEX *));
VERTEX **FindPath(HDGRAPH hDGraph, const char *name1, const char *name2);
void ClearDGraph(HDGRAPH hDGraph);
void CloseDGraph(HDGRAPH hDGraph);

#endif

/* Graph.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"

HDGRAPH CreateGraph(void)
{
	HDGRAPH hDGraph;

	if ((hDGraph = (HDGRAPH)malloc(sizeof(DGRAPH))) == NULL)
		return NULL;

	if ((hDGraph->pVertices = (VERTEX **)malloc(DEF_VERTEX_CAPACITY * sizeof(VERTEX *))) == NULL) {
		free(hDGraph);
		return NULL;
	}
	hDGraph->capacity = DEF_VERTEX_CAPACITY;
	hDGraph->size = 0;

	return hDGraph;
}

VERTEX *AddVertex(HDGRAPH hDGraph, const char *name)
{
	VERTEX *pVertex;
	VERTEX **pVertices;

	if (FindVertex(hDGraph, name) != NULL)
		return NULL;

	if ((pVertex = (VERTEX *)malloc(sizeof(VERTEX))) == NULL)
		return NULL;

	strcpy(pVertex->name, name);

	if ((pVertex->pEdges = (EDGE **)malloc(DEF_EDGE_CAPACITY * sizeof(EDGE *))) == NULL) {
		free(pVertex);
		return NULL;
	}
	pVertex->capacity = DEF_EDGE_CAPACITY;
	pVertex->size = 0;

	if (hDGraph->size == hDGraph->capacity) {
		if ((pVertices = (VERTEX **)realloc(hDGraph->pVertices, hDGraph->capacity * 2 * sizeof(VERTEX *))) == NULL) {
			free(pVertex->pEdges);
			free(pVertex);
			return NULL;
		}
		hDGraph->pVertices = pVertices;
		hDGraph->capacity *= 2;
	}
	pVertex->index = hDGraph->size;
	hDGraph->pVertices[hDGraph->size++] = pVertex;

	return pVertex;
}

EDGE *AddEdge(HDGRAPH hDGraph, VERTEX *pFirst, VERTEX *pSecond, int length)
{
	EDGE *pEdge;
	EDGE **pEdges;

	if ((pEdge = (EDGE *)malloc(sizeof(EDGE))) == NULL)
		return NULL;

	pEdge->pFirst = pFirst;
	pEdge->pSecond = pSecond;
	pEdge->length = length;

	if (pFirst->size == pFirst->capacity) {
		if ((pEdges = (EDGE **)realloc(pFirst->pEdges, pFirst->capacity * 2 * sizeof(EDGE *))) == NULL) {
			free(pEdge);
			return NULL;
		}
		pFirst->pEdges = pEdges;
		pFirst->capacity *= 2;
	}
	pFirst->pEdges[pFirst->size++] = pEdge;

	return pEdge;
}

EDGE *AddEdgeWithName(HDGRAPH hDGraph, const char *nameFirst, const char *nameSecond, int length)
{
	VERTEX *pVertex1, *pVertex2;
	EDGE *pEdge;

	if ((pVertex1 = FindVertex(hDGraph, nameFirst)) == NULL && (pVertex1 = AddVertex(hDGraph, nameFirst)) == NULL)
		return NULL;

	if ((pVertex2 = FindVertex(hDGraph, nameSecond)) == NULL && (pVertex2 = AddVertex(hDGraph, nameSecond)) == NULL)
		return NULL;

	if ((pEdge = AddEdge(hDGraph, pVertex1, pVertex2, length)) == NULL)
		return NULL;

	return pEdge;
}

VERTEX *FindVertex(HDGRAPH hDGraph, const char *name)
{
	size_t i;

	for (i = 0; i < hDGraph->size; ++i)
		if (!strcmp(hDGraph->pVertices[i]->name, name))
			return hDGraph->pVertices[i];

	return NULL;
}

static BOOL DepthFirstTraverseRecur(HDGRAPH hDGraph, VERTEX *pVertex, int *pVisited, BOOL(*Proc)(const VERTEX *))
{
	size_t i;
	EDGE *pEdge;
	VERTEX *pSecond;

	pVisited[pVertex->index] = 1;

	for (i = 0; i < pVertex->size; ++i) {
		pEdge = pVertex->pEdges[i];
		pSecond = pEdge->pSecond;

		if (!pVisited[pSecond->index]) {
			if (!Proc(pSecond))
				return FALSE;
			if (!DepthFirstTraverseRecur(hDGraph, pSecond, pVisited, Proc))
				return FALSE;
		}
	}

	return TRUE;
}

BOOL DepthFirstTraverse(HDGRAPH hDGraph, const char *name, BOOL(*Proc)(const VERTEX *))
{
	VERTEX *pVertex;
	int *pVisited;
	BOOL result;

	if ((pVisited = (int *)calloc(hDGraph->size, sizeof(int))) == NULL)
		return FALSE;

	if ((pVertex = FindVertex(hDGraph, name)) == NULL)
		return FALSE;

	result = DepthFirstTraverseRecur(hDGraph, pVertex, pVisited, Proc);

	free(pVisited);

	return result;
}

static void DepthFirstFindPathRecur(HDGRAPH hDGraph, VERTEX *pVertex, int *pVisited, int *pIndices)
{
	size_t i;
	EDGE *pEdge;
	VERTEX *pSecond;

	pVisited[pVertex->index] = 1;

	for (i = 0; i < pVertex->size; ++i) {
		pEdge = pVertex->pEdges[i];
		pSecond = pEdge->pSecond;

		if (!pVisited[pSecond->index]) {
			pIndices[pSecond->index] = pEdge->pFirst->index;
			DepthFirstFindPathRecur(hDGraph, pSecond, pVisited, pIndices);
		}
	}
}

VERTEX **FindPath(HDGRAPH hDGraph, const char *name1, const char *name2)
{
	int *pIndices;
	int *pVisited;
	VERTEX *pVertex1, *pVertex2;
	VERTEX **pPath;
	size_t i, n, index;

	if ((pVertex1 = FindVertex(hDGraph, name1)) == NULL)
		return NULL;

	if ((pVertex2 = FindVertex(hDGraph, name2)) == NULL)
		return NULL;

	if ((pIndices = (int *)malloc(sizeof(int) * hDGraph->size)) == NULL)
		return NULL;


	for (i = 0; i < hDGraph->size; ++i)
		pIndices[i] = -1;

	if ((pVisited = (int *)calloc(hDGraph->size, sizeof(int))) == NULL) {
		free(pIndices);
		return NULL;
	}

	if ((pPath = (VERTEX **)malloc(hDGraph->size * sizeof(VERTEX *))) == NULL) {
		free(pVisited);
		free(pIndices);
		return NULL;
	}

	DepthFirstFindPathRecur(hDGraph, pVertex1, pVisited, pIndices);

	for (i = 0; i < hDGraph->size; ++i)
		printf("%d ", pIndices[i]);
	printf("\n");

	n = 0;
	pPath[n++] = pVertex2;
	index = pVertex2->index;
	while (index != pVertex1->index) {
		if (index == -1) {
			free(pIndices);
			free(pVisited);
			free(pPath);
			return NULL;
		}
		index = pIndices[index];
		pPath[n++] = hDGraph->pVertices[index];
	}
	pPath[n] = NULL;

	for (i = 0; i < n / 2; ++i) {
		VERTEX *temp = pPath[i];
		pPath[i] = pPath[n - i - 1];
		pPath[n - i - 1] = temp;
	}
	free(pIndices);
	free(pVisited);

	return pPath;
}

void ClearDGraph(HDGRAPH hDGraph)
{
	size_t i, k;
	VERTEX *pVertex;

	for (i = 0; i < hDGraph->size; ++i) {
		pVertex = hDGraph->pVertices[i];
		for (k = 0; k < pVertex->size; ++k)
			free(pVertex->pEdges[k]);
		free(pVertex->pEdges);
		free(pVertex);
	}
	hDGraph->size = 0;
}

void CloseDGraph(HDGRAPH hDGraph)
{
	ClearDGraph(hDGraph);
	free(hDGraph->pVertices);
	free(hDGraph);
}

/* Test.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "Graph.h"

#define MAX_LINE_LENGTH		1024

typedef struct tagEDGE_INFO {
	char nameFirst[32];
	char nameSecond[32];
	int length;
} EDGE_INFO;

EDGE_INFO *ReadEdge(FILE *f)
{
	char buf[MAX_LINE_LENGTH];
	static EDGE_INFO edgeInfo;
	char *str;

	do {
		if (fgets(buf, MAX_LINE_LENGTH, f) == NULL)
			return NULL;
		if ((str = strchr(buf, '\n')) != NULL)
			*str = '\0';
	} while ((str = strtok(buf, " \t,")) == NULL);

	strcpy(edgeInfo.nameFirst, str);

	if ((str = strtok(NULL, " \t,")) == NULL)
		return NULL;
	strcpy(edgeInfo.nameSecond, str);

	if ((str = strtok(NULL, " \t,")) == NULL)
		return NULL;

	edgeInfo.length = strtol(str, NULL, 10);

	return &edgeInfo;
}

BOOL GenerateDot2Png(const char *dotName, const char *pngName)
{
	char cmdLine[1024];
	STARTUPINFO si = { sizeof(STARTUPINFO) };
	PROCESS_INFORMATION pi;

	sprintf(cmdLine, "dot -Tpng %s -o %s", dotName, pngName);

	if (!CreateProcess(NULL, cmdLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
		return FALSE;

	return TRUE;
}

BOOL Disp(VERTEX *pVertex)
{
	printf("%s\n", pVertex->name);

	return TRUE;
}

int main(void)
{
	HDGRAPH hDGraph;
	EDGE_INFO *pInfo;
	FILE *fin, *fdot;
	int indexFirst, indexSecond;
	VERTEX **pPath;
	size_t i;

	if ((fin = fopen("dgraph.csv", "r")) == NULL) {
		fprintf(stderr, "Cannot open file!..\n");
		exit(EXIT_FAILURE);
	}

	if ((fdot = fopen("dgraph.dot", "w")) == NULL) {
		fprintf(stderr, "Cannot open file!..\n");
		exit(EXIT_FAILURE);
	}
	fprintf(fdot, "digraph {\n");

	if ((hDGraph = CreateGraph()) == NULL) {
		fprintf(stderr, "Cannot create graph!..\n");
		exit(EXIT_FAILURE);
	}

	while ((pInfo = ReadEdge(fin)) != NULL) {
		printf("%s ----> %s : %d \n", pInfo->nameFirst, pInfo->nameSecond, pInfo->length);
		if (AddEdgeWithName(hDGraph, pInfo->nameFirst, pInfo->nameSecond, pInfo->length) == NULL) {
			fprintf(stderr, "cannot add vertex!..\n");
			exit(EXIT_FAILURE);
		}
		indexFirst = FindVertex(hDGraph, pInfo->nameFirst)->index;
		indexSecond = FindVertex(hDGraph, pInfo->nameSecond)->index;

		/*fprintf(fdot, "\t%d -> %d[label=\"%d\"]\n", indexFirst, indexSecond, pInfo->length); */

		fprintf(fdot, "\t%s_%d -> %s_%d[label=\"%d\"]\n", pInfo->nameFirst, indexFirst, pInfo->nameSecond, indexSecond, pInfo->length);
	}

	fprintf(fdot, "}\n");

	printf("----------------------------\n");

	fclose(fin);
	fclose(fdot);

	if (!GenerateDot2Png("dgraph.dot", "dgraph.png")) {
		fprintf(stderr, "Cannot generate png!..\n");
		exit(EXIT_FAILURE);
	}

	DepthFirstTraverse(hDGraph, "Eskişehir", Disp);

	if ((pPath = FindPath(hDGraph, "Diyarbakır", "Samsun")) == NULL) {
		fprintf(stderr, "Cannot find path!..\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; pPath[i] != NULL; ++i)
		printf("%s ", pPath[i]->name);
	printf("\n");

	free(pPath);

	CloseDGraph(hDGraph);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Aşağıdaki iskelet bir TCP/IP client-server uugulama verilmiştir. Burada client klavyeden birtakım yazılar girer. Bunu server'a gönderir. 
	Server da bu yazının tersini client'a geri yollamaktadır. Client "exit" yazdığında her iki taraf da işlemini sonlandırmaktadır.
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* Server.c */

#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

#define SERVER_PORTNO			55000
#define BUFFER_SIZE				1024

void ExitSys(LPCSTR lpszMsg, DWORD dwLastErr);

int main(void)
{
	WSADATA wsaData;
	DWORD dwResult;
	SOCKET serverSock, clientSock;
	struct sockaddr_in sinServer, sinClient;
	int addrLen;
	char buf[BUFFER_SIZE];
	char *str;
	int result;

	if ((dwResult = WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0)
		ExitSys("WSAStartup", dwResult);

	if ((serverSock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) 	/* third parameter IPPROTO_TCP */
		ExitSys("socket", WSAGetLastError());

	sinServer.sin_family = AF_INET;
	sinServer.sin_port = htons(SERVER_PORTNO);
	sinServer.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(serverSock, (struct sockaddr *)&sinServer, sizeof(sinServer)) == SOCKET_ERROR)
		ExitSys("bind", WSAGetLastError());

	if (listen(serverSock, 8) == SOCKET_ERROR)
		ExitSys("listen", WSAGetLastError());

	printf("Waiting for client connection....\n");

	addrLen = sizeof(sinClient);
	
	if ((clientSock = accept(serverSock, (struct sockaddr *)&sinClient, &addrLen)) == INVALID_SOCKET)
		ExitSys("accept", WSAGetLastError());

	printf("Connected: %s:%d\n", inet_ntoa(sinClient.sin_addr), ntohs(sinClient.sin_port));

	for (;;) {
		if ((result = recv(clientSock, buf, BUFFER_SIZE - 1, 0)) == SOCKET_ERROR)
			ExitSys("recv", WSAGetLastError());
		if (result == 0)
			break;

		buf[result] = '\0';
		if (!strcmp(buf, "exit"))
			break;
		printf("%d bytes received: %s\n", result, buf);
		_strrev(buf);
		if (send(clientSock, buf, strlen(buf), 0) == SOCKET_ERROR)
			ExitSys("send", WSAGetLastError());
	}
	
	shutdown(clientSock, SD_BOTH);
	closesocket(clientSock);
	closesocket(serverSock);

	WSACleanup();

	return 0;
}

void ExitSys(LPCSTR lpszMsg, DWORD dwLastErr)
{
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/* Client.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define SERVER_PORTNO			55000
#define CLIENT_PORTNO			62000
#define BUFFER_SIZE				1024
#define SERVER_NAME				"127.0.0.1" 

void ExitSys(LPCSTR lpszMsg, DWORD dwLastErr);

int main(void)
{
	WSADATA wsaData;
	DWORD dwResult;
	SOCKET clientSock;
	struct sockaddr_in sinServer;
	struct hostent *hostEnt;
	char buf[BUFFER_SIZE];
	char *str;
	int result;

	if ((dwResult = WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0)
		ExitSys("WSAStartup", dwResult);

	if ((clientSock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
		ExitSys("socket", WSAGetLastError());
	/*
	{
		struct sockaddr_in sinClient;

		sinClient.sin_family = AF_INET;
		sinClient.sin_port = htons(CLIENT_PORTNO);
		sinClient.sin_addr.s_addr = htonl(INADDR_ANY);

		if (bind(clientSock, (struct sockaddr *)&sinClient, sizeof(sinClient)) == SOCKET_ERROR)
			ExitSys("bind", WSAGetLastError());
	}
	*/

	sinServer.sin_family = AF_INET;
	sinServer.sin_port = htons(SERVER_PORTNO);

	sinServer.sin_addr.s_addr = inet_addr(SERVER_NAME);
	if (sinServer.sin_addr.s_addr == INADDR_NONE) {
		if ((hostEnt = gethostbyname(SERVER_NAME)) == NULL) 
			ExitSys("gethostbyname", WSAGetLastError());

		memcpy(&sinServer.sin_addr.s_addr, hostEnt->h_addr_list[0], hostEnt->h_length);
	}
	if (connect(clientSock, (struct sockaddr *)&sinServer, sizeof(sinServer)) == SOCKET_ERROR)
		ExitSys("connect", WSAGetLastError());

	printf("Connected...\n");
	for (;;) {
		printf("Text:");
	
		fgets(buf, BUFFER_SIZE, stdin);
		if ((str = strchr(buf, '\n')) != NULL)
			*str = '\0';
	
		if (send(clientSock, buf, strlen(buf), 0) == SOCKET_ERROR)
			ExitSys("send", WSAGetLastError());

		if (!strcmp(buf, "exit"))
			break;

		if ((result = recv(clientSock, buf, BUFFER_SIZE - 1, 0)) == SOCKET_ERROR)
			ExitSys("recv", WSAGetLastError());
		if (result == 0)
			break;

		buf[result] = '\0';

		printf("%d bytes received: %s\n", result, buf);
	}

	shutdown(clientSock, SD_BOTH);
	closesocket(clientSock);

	WSACleanup();

	return 0;
}

void ExitSys(LPCSTR lpszMsg, DWORD dwLastErr)
{
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Yukarıdaki iskelet client/server programın UNIX/Linux sistemlerindeki eşdeğeri aşağıdaki verilmiştir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* server.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORTNO			55000
#define BUFFER_SIZE				1024

void exit_sys(const char *msg);
void reverse_str(char *str);

int main(void)
{
	int server_sock, client_sock;
    struct sockaddr_in sin_server, sin_client;
    socklen_t addrlen;
    char buf[BUFFER_SIZE];
	char *str;
	int result;
    
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        exit_sys("socket");

    sin_server.sin_family = AF_INET;
    sin_server.sin_port = htons(SERVER_PORTNO);
    sin_server.sin_addr.s_addr = htonl(INADDR_ANY);
    
    if (bind(server_sock, (struct sockaddr *)&sin_server, sizeof(sin_server)) == -1)
        exit_sys("bind");

    if (listen(server_sock, 8) == -1)
        exit_sys("listen");

    printf("Waiting for client connection....\n");

	addrlen = sizeof(sin_client);
	if ((client_sock = accept(server_sock, (struct sockaddr *)&sin_client, &addrlen)) == -1)
        exit_sys("accept");
		
	printf("Connected: %s:%d\n", inet_ntoa(sin_client.sin_addr), ntohs(sin_client.sin_port));

	for (;;) {
		if ((result = recv(client_sock, buf, BUFFER_SIZE - 1, 0)) == -1)
			exit_sys("recv");
		if (result == 0)
			break;
		buf[result] = '\0';
		if (!strcmp(buf, "exit"))
			break;
		printf("%d bytes received: %s\n", result, buf);
		reverse_str(buf);
		if (send(client_sock, buf, strlen(buf), 0) == -1)
			exit_sys("recv");
	}

    shutdown(client_sock, SHUT_RDWR);
	close(client_sock);
    close(server_sock);

    return 0;
}

void reverse_str(char *str)
{
    size_t len, i;
    char temp;

    for (len = 0; str[len] != '\0'; ++len)
        ;

    for (i = 0; i < len / 2; ++i) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void exit_sys(const char *msg)
{
    perror(msg);

    exit(EXIT_FAILURE);
}

/* client.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_PORTNO			55000
#define CLIENT_PORTNO			62000
#define BUFFER_SIZE				1024
#define SERVER_NAME				"127.0.0.1" 

void exit_sys(const char *msg);

int main(void)
{
    int client_sock;
    struct sockaddr_in sin_server;
    struct hostent *hostent;
    char *str;
    char buf[BUFFER_SIZE];
    int result;

    if ((client_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        exit_sys("socket");

    /*
    struct sockaddr_in sin_client;

    sin_client.sin_family = AF_INET;
	sin_client.sin_port = htons(CLIENT_PORTNO);
	sin_client.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(client_sock, (struct sockaddr *)&sin_client, sizeof(sin_client)) == -1)
        exit_sys("socket");
    */

   	sin_server.sin_family = AF_INET;
	sin_server.sin_port = htons(SERVER_PORTNO);
	
    sin_server.sin_addr.s_addr = inet_addr(SERVER_NAME);
    if (sin_server.sin_addr.s_addr == INADDR_NONE) {
		if ((hostent = gethostbyname(SERVER_NAME)) == NULL) 
			exit_sys("gethostbyname");  

		memcpy(&sin_server.sin_addr.s_addr, hostent->h_addr_list[0], hostent->h_length);
	}

    if (connect(client_sock, (struct sockaddr *)&sin_server, sizeof(sin_server)) == -1)
		exit_sys("gethostbyname");

	printf("Connected...\n");

    for (;;) {
		printf("Text:");
	
		fgets(buf, BUFFER_SIZE, stdin);
		if ((str = strchr(buf, '\n')) != NULL)
			*str = '\0';
	
		if (send(client_sock, buf, strlen(buf), 0) == -1)
			exit_sys("send");

		if (!strcmp(buf, "exit"))
			break;

		if ((result = recv(client_sock, buf, BUFFER_SIZE - 1, 0)) == -1)
			exit_sys("recv");
		if (result == 0)
			break;

		buf[result] = '\0';

		printf("%d bytes received: %s\n", result, buf);
	}

	shutdown(client_sock, SHUT_RDWR);
	close(client_sock);
    
    return 0;
}

void exit_sys(const char *msg)
{
    perror(msg);

    exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows'ta çok client'lı server uygulaması. Bu örnekte thread modeli kullanılmıştır. Server her client bağlantısında bir thread yaratmış ve 
	o thread'in bağlanılan client konuşmasını sağlamıştır. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* Server.c */

#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

#define SERVER_PORTNO			55000
#define BUFFER_SIZE				1024

void ExitSys(LPCSTR lpszMsg, DWORD dwLastErr);
DWORD __stdcall ClientThreadProc(LPVOID lpParam);

struct CLIENT_INFO {
	SOCKET sock;
	char addr[16];
	int port;
};

int main(void)
{
	WSADATA wsaData;
	DWORD dwResult;
	SOCKET serverSock, clientSock;
	struct sockaddr_in sinServer, sinClient;
	int addrLen;
	HANDLE hThread;
	DWORD dwThreadId;
	struct CLIENT_INFO *ci;

	if ((dwResult = WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0)
		ExitSys("WSAStartup", dwResult);

	if ((serverSock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) 	/* third parameter IPPROTO_TCP */
		ExitSys("socket", WSAGetLastError());

	sinServer.sin_family = AF_INET;
	sinServer.sin_port = htons(SERVER_PORTNO);
	sinServer.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(serverSock, (struct sockaddr *)&sinServer, sizeof(sinServer)) == SOCKET_ERROR)
		ExitSys("bind", WSAGetLastError());

	if (listen(serverSock, 8) == SOCKET_ERROR)
		ExitSys("listen", WSAGetLastError());

	printf("Waiting for client connection....\n");
	for (;;) {
		addrLen = sizeof(sinClient);
		if ((clientSock = accept(serverSock, (struct sockaddr *)&sinClient, &addrLen)) == INVALID_SOCKET)
			ExitSys("accept", WSAGetLastError());

		if ((ci = (struct CLIENT_INFO *)malloc(sizeof(struct CLIENT_INFO))) == NULL) {
			fprintf(stderr, "Cannot allocate memory!..\n");
			exit(EXIT_FAILURE);
		}
		ci->sock = clientSock;
		strcpy(ci->addr, inet_ntoa(sinClient.sin_addr));
		ci->port = ntohs(sinClient.sin_port);

		printf("Connected: %s:%d\n", ci->addr, ci->port);

		if ((hThread = CreateThread(NULL, 0, ClientThreadProc, ci, 0, &dwThreadId)) == NULL)
			ExitSys("CreateThread", WSAGetLastError());

		CloseHandle(hThread);
	}
	
	closesocket(serverSock);

	WSACleanup();

	return 0;
}

DWORD __stdcall ClientThreadProc(LPVOID lpParam)
{
	struct CLIENT_INFO *ci = (struct CLIENT_INFO *)lpParam;
	int result;
	char buf[BUFFER_SIZE];
	
	for (;;) {
		if ((result = recv(ci->sock, buf, BUFFER_SIZE - 1, 0)) == SOCKET_ERROR)
			goto FAILED;
		if (result == 0)
			break;

		buf[result] = '\0';
		if (!strcmp(buf, "exit"))
			break;
		printf("%d bytes received from %s:%d => \"%s\"\n", result, ci->addr, ci->port, buf);
		_strrev(buf);
		if (send(ci->sock, buf, strlen(buf), 0) == SOCKET_ERROR)
			goto FAILED;
	}
FAILED:
	printf("Client %s:%d exits...\n", ci->addr, ci->port);

	shutdown(ci->sock, SD_BOTH);
	closesocket(ci->sock);
	free(ci);

	return 0;
}

void ExitSys(LPCSTR lpszMsg, DWORD dwLastErr)
{
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/* Client.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define SERVER_PORTNO			55000
#define CLIENT_PORTNO			62000
#define BUFFER_SIZE				1024
#define SERVER_NAME				"127.0.0.1"

void ExitSys(LPCSTR lpszMsg, DWORD dwLastErr);

int main(void)
{
	WSADATA wsaData;
	DWORD dwResult;
	SOCKET clientSock;
	struct sockaddr_in sinServer;
	struct hostent *hostEnt;
	char buf[BUFFER_SIZE];
	char *str;
	int result;

	if ((dwResult = WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0)
		ExitSys("WSAStartup", dwResult);

	if ((clientSock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
		ExitSys("socket", WSAGetLastError());
	/*
	{
		struct sockaddr_in sinClient;

		sinClient.sin_family = AF_INET;
		sinClient.sin_port = htons(CLIENT_PORTNO);
		sinClient.sin_addr.s_addr = htonl(INADDR_ANY);

		if (bind(clientSock, (struct sockaddr *)&sinClient, sizeof(sinClient)) == SOCKET_ERROR)
			ExitSys("bind", WSAGetLastError());
	}
	*/

	sinServer.sin_family = AF_INET;
	sinServer.sin_port = htons(SERVER_PORTNO);

	sinServer.sin_addr.s_addr = inet_addr(SERVER_NAME);
	if (sinServer.sin_addr.s_addr == INADDR_NONE) {
		if ((hostEnt = gethostbyname(SERVER_NAME)) == NULL) 
			ExitSys("gethostbyname", WSAGetLastError());

		memcpy(&sinServer.sin_addr.s_addr, hostEnt->h_addr_list[0], hostEnt->h_length);
	}
	if (connect(clientSock, (struct sockaddr *)&sinServer, sizeof(sinServer)) == SOCKET_ERROR)
		ExitSys("connect", WSAGetLastError());

	printf("Connected...\n");
	for (;;) {
		printf("Text:");
	
		fgets(buf, BUFFER_SIZE, stdin);
		if ((str = strchr(buf, '\n')) != NULL)
			*str = '\0';
	
		if (send(clientSock, buf, strlen(buf), 0) == SOCKET_ERROR)
			ExitSys("send", WSAGetLastError());

		if (!strcmp(buf, "exit"))
			break;

		if ((result = recv(clientSock, buf, BUFFER_SIZE - 1, 0)) == SOCKET_ERROR)
			ExitSys("recv", WSAGetLastError());

		if (result == 0)
			break;

		buf[result] = '\0';

		printf("%d bytes received: %s\n", result, buf);
	}

	shutdown(clientSock, SD_BOTH);
	closesocket(clientSock);

	WSACleanup();

	return 0;
}

void ExitSys(LPCSTR lpszMsg, DWORD dwLastErr)
{
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Yukarıdaki programın UNIX/Linux sistemlerindeki karşılığı
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* server.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORTNO			55000
#define BUFFER_SIZE				1024

struct CLIENT_INFO {
	int sock;
	char addr[16];
	int port;
};

void exit_sys(const char *msg);
void *client_thread_proc(void *param);
void reverse_str(char *str);

int main(void)
{
	int server_sock, client_sock;
	struct sockaddr_in sin_server, sin_client;
	socklen_t addrlen;
	struct CLIENT_INFO *ci;
    pthread_t tid;
    int result;
    
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        exit_sys("socket");

    sin_server.sin_family = AF_INET;
    sin_server.sin_port = htons(SERVER_PORTNO);
    sin_server.sin_addr.s_addr = htonl(INADDR_ANY);
    
    if (bind(server_sock, (struct sockaddr *)&sin_server, sizeof(sin_server)) == -1)
        exit_sys("bind");

    if (listen(server_sock, 8) == -1)
        exit_sys("listen");

    printf("Waiting for client connection....\n");

	for (;;) {
		addrlen = sizeof(sin_client);
		if ((client_sock = accept(server_sock, (struct sockaddr *)&sin_client, &addrlen)) == -1)
			exit_sys("accept");

		if ((ci = (struct CLIENT_INFO *)malloc(sizeof(struct CLIENT_INFO))) == NULL) {
			fprintf(stderr, "Cannot allocate memory!..\n");
			exit(EXIT_FAILURE);
		}
		ci->sock = client_sock;
		strcpy(ci->addr, inet_ntoa(sin_client.sin_addr));
		ci->port = ntohs(sin_client.sin_port);

		printf("Connected: %s:%d\n", ci->addr, ci->port);

        if ((result = pthread_create(&tid, NULL, client_thread_proc, ci)) != 0) {
            fprintf(stderr, "pthread_create: %s\n", strerror(result));
            exit(EXIT_FAILURE);
        }
        if ((result = pthread_detach(tid)) != 0) {
            fprintf(stderr, "pthread_create: %s\n", strerror(result));
            exit(EXIT_FAILURE);
        }
	}
	
    shutdown(server_sock, SHUT_RDWR);
    close(server_sock);

    return 0;
}

void *client_thread_proc(void *param)
{
    struct CLIENT_INFO *ci = (struct CLIENT_INFO *)param;
	int result;
	char buf[BUFFER_SIZE];
	
	for (;;) {
		if ((result = recv(ci->sock, buf, BUFFER_SIZE - 1, 0)) == -1)
			goto FAILED;
		if (result == 0)
			break;

		buf[result] = '\0';
		if (!strcmp(buf, "exit"))
			break;
		printf("%d bytes received from %s:%d => \"%s\"\n", result, ci->addr, ci->port, buf);
		reverse_str(buf);
		if (send(ci->sock, buf, strlen(buf), 0) == -1)
			goto FAILED;
	}
FAILED:
	printf("Client %s:%d exits...\n", ci->addr, ci->port);

	shutdown(ci->sock, SHUT_RDWR);
	close(ci->sock);
	free(ci);

    return NULL;
}

void reverse_str(char *str)
{
    size_t len, i;
    char temp;

    for (len = 0; str[len] != '\0'; ++len)
        ;

    for (i = 0; i < len / 2; ++i) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void exit_sys(const char *msg)
{
    perror(msg);

    exit(EXIT_FAILURE);
}

/* client.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_PORTNO			55000
#define CLIENT_PORTNO			62000
#define BUFFER_SIZE				1024
#define SERVER_NAME				"127.0.0.1"  

void exit_sys(const char *msg);

int main(void)
{
    int client_sock;
    struct sockaddr_in sin_server;
    struct hostent *hostent;
    char *str;
    char buf[BUFFER_SIZE];
    int result;

    if ((client_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        exit_sys("socket");

    /*
    struct sockaddr_in sin_client;

    sin_client.sin_family = AF_INET;
	sin_client.sin_port = htons(CLIENT_PORTNO);
	sin_client.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(client_sock, (struct sockaddr *)&sin_client, sizeof(sin_client)) == -1)
        exit_sys("socket");
    */

   	sin_server.sin_family = AF_INET;
	sin_server.sin_port = htons(SERVER_PORTNO);
	
    sin_server.sin_addr.s_addr = inet_addr(SERVER_NAME);
    if (sin_server.sin_addr.s_addr == INADDR_NONE) {
		if ((hostent = gethostbyname(SERVER_NAME)) == NULL) 
			exit_sys("gethostbyname");  

		memcpy(&sin_server.sin_addr.s_addr, hostent->h_addr_list[0], hostent->h_length);
	}

    if (connect(client_sock, (struct sockaddr *)&sin_server, sizeof(sin_server)) == -1)
		exit_sys("gethostbyname");

	printf("Connected...\n");

    for (;;) {
		printf("Text:");
	
		fgets(buf, BUFFER_SIZE, stdin);
		if ((str = strchr(buf, '\n')) != NULL)
			*str = '\0';
	
		if (send(client_sock, buf, strlen(buf), 0) == -1)
			exit_sys("send");

		if (!strcmp(buf, "exit"))
			break;

		if ((result = recv(client_sock, buf, BUFFER_SIZE - 1, 0)) == -1)
			exit_sys("recv");
        if (result == 0)
            break;

		buf[result] = '\0';

		printf("%d bytes received: %s\n", result, buf);
	}

	shutdown(client_sock, SHUT_RDWR);
	close(client_sock);
    
    return 0;
}

void exit_sys(const char *msg)
{
    perror(msg);

    exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Aslında UNIX/Linux sistemlerinde her client bağlantısında o client ile yeni bir proses yaratılıp o prosesin konuşması da sağlanabilir. Yani server
	client ile bağlantı yaptığında fork yapar. Sonra alt proseste client ile konuşur. Bu tür uygulamalarda hortlak (zombie) oluşumun engellenmesi gerekir. 
	Aşağıdaki kodda sigaction fonksiyonuyla hortlak proses oluşması engellenmiştir. Tabii fork modeli aslında thread modeline göre daha kötü bir modeldir. 
	Ancak daha pratiktir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* fork-server.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORTNO			55000
#define BUFFER_SIZE				1024

void exit_sys(const char *msg);
void client_proc(int sock, const char *addr, int port);
void reverse_str(char *str);

int main(void)
{
	int server_sock, client_sock;
	struct sockaddr_in sin_server, sin_client;
	socklen_t addrlen;
    pid_t pid;
    char *addr;
    int port;
    struct sigaction act;
    
    act.sa_handler = SIG_IGN;
    act.sa_flags = SA_NOCLDWAIT;
    if (sigaction(SIGCHLD, &act, NULL) == -1)
        exit_sys("sigaction");
    
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        exit_sys("socket");

    sin_server.sin_family = AF_INET;
    sin_server.sin_port = htons(SERVER_PORTNO);
    sin_server.sin_addr.s_addr = htonl(INADDR_ANY);
    
    if (bind(server_sock, (struct sockaddr *)&sin_server, sizeof(sin_server)) == -1)
        exit_sys("bind");

    if (listen(server_sock, 8) == -1)
        exit_sys("listen");

    printf("Waiting for client connection....\n");

	for (;;) {
		addrlen = sizeof(sin_client);
		if ((client_sock = accept(server_sock, (struct sockaddr *)&sin_client, &addrlen)) == -1)
			exit_sys("accept");

        addr = inet_ntoa(sin_client.sin_addr);
        port = ntohs(sin_client.sin_port);
		printf("Connected: %s:%d\n", addr, port);

        if ((pid = fork()) == -1)
            exit_sys("fork");

        if (pid == 0) {
            client_proc(client_sock, addr, port);
            exit(EXIT_SUCCESS);
        }
	}
	
    shutdown(server_sock, SHUT_RDWR);
    close(server_sock);

    return 0;
}

void client_proc(int sock, const char *addr, int port)
{
	int result;
	char buf[BUFFER_SIZE];
	
	for (;;) {
		if ((result = recv(sock, buf, BUFFER_SIZE - 1, 0)) == -1)
			goto FAILED;
		if (result == 0)
			break;

		buf[result] = '\0';
		if (!strcmp(buf, "exit"))
			break;
		printf("%d bytes received from %s:%d => \"%s\"\n", result, addr, port, buf);
		reverse_str(buf);
		if (send(sock, buf, strlen(buf), 0) == -1)
			goto FAILED;
	}
FAILED:
	printf("Client %s:%d exits...\n", addr, port);

	shutdown(sock, SHUT_RDWR);
	close(sock);
}

void reverse_str(char *str)
{
    size_t len, i;
    char temp;

    for (len = 0; str[len] != '\0'; ++len)
        ;

    for (i = 0; i < len / 2; ++i) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void exit_sys(const char *msg)
{
    perror(msg);

    exit(EXIT_FAILURE);
}

/* client.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_PORTNO			55000
#define CLIENT_PORTNO			62000
#define BUFFER_SIZE				1024
#define SERVER_NAME				"127.0.0.1"  

void exit_sys(const char *msg);

int main(void)
{
    int client_sock;
    struct sockaddr_in sin_server;
    struct hostent *hostent;
    char *str;
    char buf[BUFFER_SIZE];
    int result;

    if ((client_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        exit_sys("socket");

    /*
    struct sockaddr_in sin_client;

    sin_client.sin_family = AF_INET;
	sin_client.sin_port = htons(CLIENT_PORTNO);
	sin_client.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(client_sock, (struct sockaddr *)&sin_client, sizeof(sin_client)) == -1)
        exit_sys("socket");
    */

   	sin_server.sin_family = AF_INET;
	sin_server.sin_port = htons(SERVER_PORTNO);
	
    sin_server.sin_addr.s_addr = inet_addr(SERVER_NAME);
    if (sin_server.sin_addr.s_addr == INADDR_NONE) {
		if ((hostent = gethostbyname(SERVER_NAME)) == NULL) 
			exit_sys("gethostbyname");  

		memcpy(&sin_server.sin_addr.s_addr, hostent->h_addr_list[0], hostent->h_length);
	}

    if (connect(client_sock, (struct sockaddr *)&sin_server, sizeof(sin_server)) == -1)
		exit_sys("gethostbyname");

	printf("Connected...\n");

    for (;;) {
		printf("Text:");
	
		fgets(buf, BUFFER_SIZE, stdin);
		if ((str = strchr(buf, '\n')) != NULL)
			*str = '\0';
	
		if (send(client_sock, buf, strlen(buf), 0) == -1)
			exit_sys("send");

		if (!strcmp(buf, "exit"))
			break;

		if ((result = recv(client_sock, buf, BUFFER_SIZE - 1, 0)) == -1)
			exit_sys("recv");
        if (result == 0)
            break;

		buf[result] = '\0';

		printf("%d bytes received: %s\n", result, buf);
	}

	shutdown(client_sock, SHUT_RDWR);
	close(client_sock);
    
    return 0;
}

void exit_sys(const char *msg)
{
    perror(msg);

    exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Şüphesiz TCP/IP uygulamalarında client ve server programların hangi dille ve hangi işletim sisteminde yazıldığının bir önemi yoktur. Önemli olan 
	bizim programımızda uyguladığımız "uygulama katmanı protokolüne" uygunluktur. 

	Aşağıdaki örnekte yukarıdaki programın client kısmının C# karşılığı verilmiştir. Bu tür dillerde kendi içerisindkei sınıflar yoluyla pek çok işlem
	arka planda otomatik yapılabilmektedir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

using System;
using System.Net.Sockets;
using System.Text;

namespace CSD
{
    class App
    {
        public const int SERVER_PORTNO = 55000;
        
        public static void Main()
        {
            try
            {
                TcpClient tcpClient = new TcpClient("127.0.0.1", SERVER_PORTNO);
                string text;
                byte[] buf;
                int result;

                for (; ; )
                {
                    Console.Write("Text:");
                    text = Console.ReadLine();
                    if (text == "exit")
                        break;
                    buf = Encoding.UTF8.GetBytes(text);
                    tcpClient.Client.Send(buf);

                    buf = new byte[1024];
                    result = tcpClient.Client.Receive(buf);
                    text = Encoding.UTF8.GetString(buf, 0, result);
                    Console.WriteLine(text);
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }
    }
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Bir soketten garantili biçimde n byte okumak ve sokete garantili biçimde n byte yamakiçin aşağıdaki gibi iki fonksiyon kullanılabilir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

int ReadSocket(SOCKET sock, char *buf, int size)
{
	int left, count;
	int result;

	left = size;
	count = 0;

	while (left > 0) {
		if ((result = recv(sock, buf + count, left, 0)) == SOCKET_ERROR)
			return SOCKET_ERROR;
		if (result == 0)
			break;
		left -= result;
		count += result;
	}

	return count;
}

int WriteSocket(SOCKET sock, const char *buf, int size)
{
	int left, count;
	int result;

	left = size;
	count = 0;

	while (left > 0) {
		if ((result = send(sock, buf + count, left, 0)) == SOCKET_ERROR)
			return SOCKET_ERROR;
		if (result == 0)
			break;
		left -= result;
		count += result;
	}

	return count;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Garantili n byte okumak için UNIX/Linux sistemlerinde aşağdaki gibi bir fonksiyon yazılabilir. Bu sistemlerde blokeli modda zaten send fonksiyonu
	tüm bilgi network tampouna yazılana kadar bloke oluşturmaktadır. Windows sistemleri (Winsock) bunun garantisini vermemektedir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

int read_socket(int sock, char *buf, int size)
{
    int left, count;
	int result;

	left = size;
	count = 0;

	while (left > 0) {
		if ((result = recv(sock, buf + count, left, 0)) == -1)
			return -1;
		if (result == 0)
			break;
		
		left -= result;
		count += result;
	}

	return count;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Text tabanlı mesajlaşmada bir taraf diğerine sonu \n ile biten ya da \r\n ile biten bir satırlık yazı gönderir. Karşı taraf bu yazıyı parse eder
	ve gerekeni yapar. Ancak soketten bir satırlık bilginin okunması o kadar kolay değildir. Soketten karakter karakter okuma yapmak kötü bir tekniktir. 
	Onun yerine bir grup byte bir tampona yerleştirilip o tampondan '\n' ya da '\r\n' görünene kadar ilerlenir. Aşağıda Effective TCP/IP kitabında da
	benzeri bulunan soketten bir satır okuyan bir fonksiyon örneği verilmiştir. Bu fonksiyon karşı taraf bir satır okunmadan soketi kapatmışsa 0 değerine geri döner. 
	Normal durumda satırdaki byte sayısına geri dönmektedir. Soket hatasında ise fonksiyon -1 değerine geri dönmektedir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

int ReadLineSocket(SOCKET sock, char *buf, int size)
{
	char *bufx = buf;
	static char *bp;
	static int count = 0;
	static char b[2048];
	char ch;

	while (--size > 0) {
		if (--count <= 0) {
			count = recv(sock, b, sizeof(b), 0);
			if (count == SOCKET_ERROR)
				return SOCKET_ERROR;
			if (count == 0)
				return 0;
			bp = b;
		}
		ch = *bp++;
		*buf++ = ch;
		if (ch == '\n') {
			*buf = '\0';
			return buf - bufx;
		}
	}

	return SOCKET_ERROR;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Yukardaki fonksiyonun UNIX/Linux sistemlerindeki karşılığı olan fonksiyon şöyle yazılabilir:
-------------------------------------------------------------------------------------------------------------------------------------------*/

int readline_socket(int sock, char *buf, int size)
{
	char *bufx = buf;
	static char *bp;
	static int count = 0;
	static char b[2048];
	char ch;

	while (--size > 0) {
		if (--count <= 0) {
			count = recv(sock, b, sizeof(b), 0);
			if (count == -1)
				return -1;
			if (count == 0)
				return 0;
			bp = b;
		}
		ch = *bp++;
		*buf++ = ch;
		if (ch == '\n') {
			*buf = '\0';
			return buf - bufx;
		}
	}

	return -1;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Yazısal biçimde komutlar alarak dört işlem yapan örnek bir client/server TCP uygulaması aşaüıda verilmiştir. Uygulamada server için 
	thread modeli, kullanılmıştır. Yani her client bağlandıkça server bir thread yaratır ve client ile o thread konuşur. Buradaki uygulama katmanı protokolü şöyledir:

	- Client server'a fiziksel olarak bağlandıktan sonra mantıksal bağlantı oluşturmak için ona LOGIN komutunu gönderir. Komutun genel biçimi şöyledir:

	LOGIN user_name password\n

	Server kendisine kayıtlı olan kullanıcıları gözden geçirip bu istedği kabul eder ya da etmez. Eğer server bağlantı isteğini kabul ederse client'a
	LOGIN_ACCEPTED mesajı göndermktedir. Bu mesaj şöyledir:

	LOGIN_ACCEPTED\n

	Bundan sonra client server'a aşağıdaki komutları gönderir:

	ADD op1 ope\n
	SUB op1 op2\n
	MUL op1 op2\n
	DIV op1 op2\n

	Server'da bu hesaplamaları yaparak client'a sonucu RESULT mesajı ile göndermektedir:

	RESULT result\n

	Eğer client server'a uygun bir komnut göndermezse server client'a ERROR mesajı ile yanıt vermektedir:

	ERROR mesaj\n

	Client server'a gönderdiği her mesaj için server da client'a bir mesaj göndermektedir. İletişim yine el sıkışmayla sonlandırılmaktadır. Bunun için
	client server'a LOGOUT komutunu gönderir. Server kabul ederse client'a LOGOUT_ACCEPTED mesajıyla yanıt verir. Artık ikiş taraf soketlerini kapatarak
	iletişimi sonlandırırlar.

-------------------------------------------------------------------------------------------------------------------------------------------*/

/* Server.c */

#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

#define SERVER_PORTNO			55000
#define BUFFER_SIZE				2048
#define MAX_PARAMS				32	

typedef struct tagCLIENT_REQUEST {
	char buf[BUFFER_SIZE];
	char *params[MAX_PARAMS + 1];
	int nparams;
} CLIENT_REQUEST;

typedef struct tagCLIENT_INFO {
	SOCKET sock;
	char addr[16];
	int port;
} CLIENT_INFO;

typedef struct tagUSER_INFO {
	char *userName;
	char *password;
} USER_INFO;

enum COMMANDS {
	LOGIN_COMMAND,
	ADD_COMMAND,
	SUB_COMMAND, 
	MUL_COMMAND, 
	DIV_COMMAND,
	LOGOUT_COMMAND,
};

void ExitSys(LPCSTR lpszMsg, DWORD dwLastErr);
DWORD __stdcall ClientThreadProc(LPVOID lpParam);
int ReadLineSocket(SOCKET sock, char *buf, int size);
int WriteSocket(SOCKET sock, const char *buf, int size);
void ParseCommand(char *buf, CLIENT_REQUEST *clientRequest);
BOOL ProcessCommand(const CLIENT_INFO *clientInfo, const CLIENT_REQUEST *clientRequest);

BOOL LoginCommandProc(const CLIENT_REQUEST *clientRequest, char *buf);
void OpCommandProc(const CLIENT_REQUEST *clientRequest, int commandCode, char *buf);
void LogoutCommandProc(const CLIENT_REQUEST *clientRequest, char *buf);

USER_INFO g_users[] = {
	{"student", "12345"},
	{"kaan", "xxxxx"},
	{NULL, NULL}
};

int main(void)
{
	WSADATA wsaData;
	DWORD dwResult;
	SOCKET serverSock, clientSock;
	struct sockaddr_in sinServer, sinClient;
	int addrLen;
	HANDLE hThread;
	DWORD dwThreadId;
	CLIENT_INFO *clientInfo;

	if ((dwResult = WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0)
		ExitSys("WSAStartup", dwResult);

	if ((serverSock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) 	/* third parameter IPPROTO_TCP */
		ExitSys("socket", WSAGetLastError());

	sinServer.sin_family = AF_INET;
	sinServer.sin_port = htons(SERVER_PORTNO);
	sinServer.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(serverSock, (struct sockaddr *)&sinServer, sizeof(sinServer)) == SOCKET_ERROR)
		ExitSys("bind", WSAGetLastError());

	if (listen(serverSock, 8) == SOCKET_ERROR)
		ExitSys("listen", WSAGetLastError());

	printf("Waiting for client connection....\n");
	for (;;) {
		addrLen = sizeof(sinClient);
		if ((clientSock = accept(serverSock, (struct sockaddr *)&sinClient, &addrLen)) == INVALID_SOCKET)
			ExitSys("accept", WSAGetLastError());

		if ((clientInfo = (CLIENT_INFO *)malloc(sizeof(CLIENT_INFO))) == NULL) {
			fprintf(stderr, "Cannot allocate memory!..\n");
			exit(EXIT_FAILURE);
		}
		clientInfo->sock = clientSock;
		strcpy(clientInfo->addr, inet_ntoa(sinClient.sin_addr));
		clientInfo->port = ntohs(sinClient.sin_port);

		printf("Connected client %s:%d\n", clientInfo->addr, clientInfo->port);

		if ((hThread = CreateThread(NULL, 0, ClientThreadProc, clientInfo, 0, &dwThreadId)) == NULL)
			ExitSys("CreateThread", WSAGetLastError());

		CloseHandle(hThread);
	}
	
	closesocket(serverSock);

	WSACleanup();

	return 0;
}

DWORD __stdcall ClientThreadProc(LPVOID lpParam)
{
	CLIENT_INFO *clientInfo = (CLIENT_INFO *)lpParam;
	char buf[BUFFER_SIZE];
	int result;
	CLIENT_REQUEST clientRequest;
	
	for (;;) {
		if ((result = ReadLineSocket(clientInfo->sock, buf, BUFFER_SIZE)) == SOCKET_ERROR) {
			fprintf(stderr, "Error: ReadLineSocket, ClientConnection is closing...\n");
			break;
		}
	
		if (result == 0)
			break;
		printf("Client request: %s", buf);
		ParseCommand(buf, &clientRequest);
		if (!ProcessCommand(clientInfo, &clientRequest))
			break;
	}

	shutdown(clientInfo->sock, SD_BOTH);
	closesocket(clientInfo->sock);
	free(clientInfo);

	return 0;
}

int ReadLineSocket(SOCKET sock, char *buf, int size)
{
	char *bufx = buf;
	static char *bp;
	static int count = 0;
	static char b[2048];
	char ch;

	while (--size > 0) {
		if (--count <= 0) {
			count = recv(sock, b, sizeof(b), 0);
			if (count == SOCKET_ERROR)
				return SOCKET_ERROR;
			if (count == 0)
				return 0;
			bp = b;
		}
		ch = *bp++;
		*buf++ = ch;
		if (ch == '\n') {
			*buf = '\0';
			return (int)(buf - bufx);
		}
	}

	return SOCKET_ERROR;
}

int WriteSocket(SOCKET sock, const char *buf, int size)
{
	int left, count;
	int result;

	left = size;
	count = 0;

	while (left > 0) {
		if ((result = send(sock, buf + count, left, 0)) == SOCKET_ERROR)
			return SOCKET_ERROR;
		if (result == 0)
			break;
		left -= result;
		count += result;
	}

	return count;
}

void ParseCommand(char *buf, CLIENT_REQUEST *clientRequest)
{
	char *str;
	int count;

	strcpy(clientRequest->buf, buf);
	for (count = 0, str = strtok(buf, " \t\n"); str != NULL && count < MAX_PARAMS; str = strtok(NULL, " \t\n"), ++count)
		clientRequest->params[count] = str;
	clientRequest->nparams = count;
}

BOOL ProcessCommand(const CLIENT_INFO *clientInfo, const CLIENT_REQUEST *clientRequest)
{
	static char *clientRequests[] = { "LOGIN", "ADD", "SUB", "MUL", "DIV", "LOGOUT", NULL};
	int i;
	int result;
	char buf[BUFFER_SIZE];
	BOOL retVal = TRUE;

	if (clientRequest->nparams == 0) {
		sprintf(buf, "ERROR Empty command\n", clientRequest->params[0]);
		if ((result = WriteSocket(clientInfo->sock, buf, (int)strlen(buf))) == SOCKET_ERROR)
			fprintf(stderr, "Error: WriteSocket\n");
		return retVal;
	}

	for (i = 0; clientRequests[i] != NULL; ++i)
		if (!strcmp(clientRequests[i], clientRequest->params[0]))
			break;

	if (clientRequests[i] == NULL) {
		sprintf(buf, "ERROR Command not found \"%s\"\n", clientRequest->params[0]);
		if ((result = WriteSocket(clientInfo->sock, buf, (int)strlen(buf))) == SOCKET_ERROR)
			fprintf(stderr, "Error: WriteSocket\n");
		return retVal;
	}
		
	switch (i) {
		case LOGIN_COMMAND:
			if (!LoginCommandProc(clientRequest, buf)) {
				retVal = FALSE;
				break;
			}
		break;
		case ADD_COMMAND:
			OpCommandProc(clientRequest, ADD_COMMAND, buf);
			break;
		case SUB_COMMAND:
			OpCommandProc(clientRequest, SUB_COMMAND, buf);
			break;
		case MUL_COMMAND:
			OpCommandProc(clientRequest, MUL_COMMAND, buf);
			break;
		case DIV_COMMAND:
			OpCommandProc(clientRequest, DIV_COMMAND, buf);
			break;
		case LOGOUT_COMMAND:
			LogoutCommandProc(clientRequest, buf);
			retVal = FALSE;
			break;
	}	
	if ((result = WriteSocket(clientInfo->sock, buf, (int)strlen(buf))) == SOCKET_ERROR) {
		fprintf(stderr, "Error: WriteSocket\n");
		retVal = FALSE;
	}

	return retVal;
}

void OpCommandProc(const CLIENT_REQUEST *clientRequest, int commandCode, char *buf)
{
	double op1, op2, opResult;
	
	if (clientRequest->nparams == 3)
		if (sscanf(clientRequest->params[1], "%lf", &op1) == 1)
			if (sscanf(clientRequest->params[2], "%lf", &op2) == 1) {
				switch (commandCode) {
					case ADD_COMMAND:
						opResult = op1 + op2;
						break;
					case SUB_COMMAND:
						opResult = op1 - op2;
						break;
					case MUL_COMMAND:
						opResult = op1 * op2;
						break;
					case DIV_COMMAND:
						opResult = op1 / op2;
						break;
				}
				sprintf(buf, "RESULT %f\n", opResult);
			}
			else
				sprintf(buf, "ERROR Invalid command operand\n");
		else
			sprintf(buf, "ERROR Invalid command operand\n");
	else
		sprintf(buf, "ERROR Invalid command operand\n");
}

BOOL LoginCommandProc(const CLIENT_REQUEST *clientRequest, char *buf)
{
	int i;

	for (i = 0; g_users[i].userName != NULL; ++i) {
		if (!strcmp(g_users[i].userName, clientRequest->params[1]) && !strcmp(g_users[i].password, clientRequest->params[2])) {
			sprintf(buf, "LOGIN_ACCEPTED\n");
			return TRUE;
		}
	}
	sprintf(buf, "ERROR Invalid user name or password\n");
	
	return FALSE;	
}

void LogoutCommandProc(const CLIENT_REQUEST *clientRequest, char *buf)
{
	if (clientRequest->nparams == 1) 
		sprintf(buf, "LOGOUT_ACCEPTED Logout Accepted\n");
	else
		sprintf(buf, "ERROR Invalid command operand\n");
}

void ExitSys(LPCSTR lpszMsg, DWORD dwLastErr)
{
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/* Client.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define SERVER_PORTNO			55000
#define CLIENT_PORTNO			62000
#define SERVER_NAME				"185.86.155.34"
#define BUFFER_SIZE				2048
#define MAX_USER_NAME			32
#define MAX_PASSWORD			32

typedef struct tagSERVER_RESPONSE {
	char *command;
	char *text;
} SERVER_RESPONSE;

enum COMMANDS {
	LOGIN_ACCEPTED_COMMAND,
	RESULT_COMMAND,
	ERROR_COMMAND,
	LOGOUT_ACCEPTED_COMMAND,
};

int ReadLineSocket(SOCKET sock, char *buf, int size);
int WriteSocket(SOCKET sock, const char *buf, int size);
BOOL LoginProc(SOCKET clientSock, char *buf, SERVER_RESPONSE *serverResponse);
void ParseCommand(char *buf, SERVER_RESPONSE *serverResponse);
BOOL ProcessCommand(const SERVER_RESPONSE *serverResponse);
void ExitSys(LPCSTR lpszMsg, DWORD dwLastErr);

int main(void)
{
	WSADATA wsaData;
	DWORD dwResult;
	SOCKET clientSock;
	struct sockaddr_in sinServer;
	struct hostent *hostEnt;
	char buf[BUFFER_SIZE];
	int result;
	SERVER_RESPONSE serverResponse;

	if ((dwResult = WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0)
		ExitSys("WSAStartup", dwResult);

	if ((clientSock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
		ExitSys("socket", WSAGetLastError());
	/*
	{
		struct sockaddr_in sinClient;

		sinClient.sin_family = AF_INET;
		sinClient.sin_port = htons(CLIENT_PORTNO);
		sinClient.sin_addr.s_addr = htonl(INADDR_ANY);

		if (bind(clientSock, (struct sockaddr *)&sinClient, sizeof(sinClient)) == SOCKET_ERROR)
			ExitSys("bind", WSAGetLastError());
	}
	*/

	sinServer.sin_family = AF_INET;
	sinServer.sin_port = htons(SERVER_PORTNO);

	sinServer.sin_addr.s_addr = inet_addr(SERVER_NAME);
	if (sinServer.sin_addr.s_addr == INADDR_NONE) {
		if ((hostEnt = gethostbyname(SERVER_NAME)) == NULL) 
			ExitSys("gethostbyname", WSAGetLastError());

		memcpy(&sinServer.sin_addr.s_addr, hostEnt->h_addr_list[0], hostEnt->h_length);
	}
	if (connect(clientSock, (struct sockaddr *)&sinServer, sizeof(sinServer)) == SOCKET_ERROR)
		ExitSys("connect", WSAGetLastError());

	printf("Connected...\n");

	if (!LoginProc(clientSock, buf, &serverResponse))
		goto FAILED;

	printf("Client connected...\n");

	for (;;) {
		printf("Calculator>");
		fflush(stdout);
		fgets(buf, BUFFER_SIZE, stdin);
		if ((result = WriteSocket(clientSock, buf, (int)strlen(buf))) == SOCKET_ERROR)
			ExitSys("WriteSocket", WSAGetLastError());
		if (result == 0)
			break;
		if ((result = ReadLineSocket(clientSock, buf, BUFFER_SIZE)) == SOCKET_ERROR)
			ExitSys("ReadLineSocket", WSAGetLastError());
		if (result == 0)
			break;

		ParseCommand(buf, &serverResponse);
		if (!ProcessCommand(&serverResponse))
			break;
	}
FAILED:
	shutdown(clientSock, SD_BOTH);
	closesocket(clientSock);

	WSACleanup();

	return 0;
}

int ReadLineSocket(SOCKET sock, char *buf, int size)
{
	char *bufx = buf;
	static char *bp;
	static int count = 0;
	static char b[2048];
	char ch;

	while (--size > 0) {
		if (--count <= 0) {
			count = recv(sock, b, sizeof(b), 0);
			if (count == SOCKET_ERROR)
				return SOCKET_ERROR;
			if (count == 0)
				return 0;
			bp = b;
		}
		ch = *bp++;
		*buf++ = ch;
		if (ch == '\n') {
			*buf = '\0';
			return (int) (buf - bufx);
		}
	}

	return SOCKET_ERROR;
}

int WriteSocket(SOCKET sock, const char *buf, int size)
{
	int left, count;
	int result;

	left = size;
	count = 0;

	while (left > 0) {
		if ((result = send(sock, buf + count, left, 0)) == SOCKET_ERROR)
			return SOCKET_ERROR;
		if (result == 0)
			break;
		left -= result;
		count += result;
	}

	return count;
}

BOOL LoginProc(SOCKET clientSock, char *buf, SERVER_RESPONSE *serverResponse)
{
	char userName[MAX_USER_NAME];
	char password[MAX_PASSWORD];
	
	int result;
	char *str;

	printf("User name:");
	fgets(userName, MAX_USER_NAME, stdin);
	if ((str = strchr(userName, '\n')) != NULL)
		*str = '\0';
	printf("Password:");
	fgets(password, MAX_PASSWORD, stdin);
	if ((str = strchr(password, '\n')) != NULL)
		*str = '\0';

	sprintf(buf, "LOGIN %s %s\n", userName, password);

	if ((result = WriteSocket(clientSock, buf, (int)strlen(buf))) == SOCKET_ERROR || result == 0) {
		fprintf(stderr, "Error WriteSocket!..\n");
		return FALSE;
	}

	/* buffer problem */
	if ((result = ReadLineSocket(clientSock, buf, BUFFER_SIZE)) == SOCKET_ERROR || result == 0) {
		fprintf(stderr, "Error ReadLineSocket!..\n");
		return FALSE;
	}
	
	ParseCommand(buf, serverResponse);

	if (strcmp(serverResponse->command, "LOGIN_ACCEPTED") != 0) {
		printf("%s\n", serverResponse->text);
		return FALSE;
	}

	return TRUE;
}

void ParseCommand(char *buf, SERVER_RESPONSE *serverResponse)
{
	char *str = buf;

	str = buf;
	serverResponse->command = str;

	while (*buf != ' ' && *buf != '\n')
		++buf;
	if (*buf == '\n') {
		*buf = '\0';
		serverResponse->text = NULL;
		return;
	}
	*buf++ = '\0';
	
	str = buf;
	while (*buf != '\n')
		++buf;
	*buf = '\0';
	serverResponse->text = str;
}

BOOL ProcessCommand(const SERVER_RESPONSE *serverResponse)
{
	static char *serverCommands[] = { "LOGIN_ACCEPTED", "RESULT", "ERROR", "LOGOUT_ACCEPTED", NULL};
	int i;
	BOOL retVal = TRUE;

	for (i = 0; serverCommands[i] != NULL; ++i)
		if (!strcmp(serverCommands[i], serverResponse->command))
			break;

	switch (i) {
		case RESULT_COMMAND:
		case ERROR_COMMAND:
			printf("%s\n", serverResponse->text);
			break;
		case LOGOUT_ACCEPTED_COMMAND:
			printf("%s\n", serverResponse->text);
			retVal = FALSE;
			break;
		default:
			printf("Unknown server command: %s\n", serverResponse->text);
	}

	return retVal;
}

void ExitSys(LPCSTR lpszMsg, DWORD dwLastErr)
{
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Aslında IP ailesinin uygulama katmanındaki protokollerin büyük çoğunluğu aslında yazısal kıomutlarla yukarıdakşi örnekte olduğu gibi
	haberleşme yapmaktadır. Örneğin POP3 protokolünde çnce client server'a kendini aşaüıdaki komut ile tanıtır:

	USER user_name\r\n
	PASS password\r\n

	Sonra client server'daki posta kutusundaki postalar hakkında bilgiyi LIST komutuyla elde eder. Her postanın bir indeks numarası vardır. Client
	RETR komutuyla indeks numarasını belirterek server'dan posta kutusundaki belli bir postayı istemektedir. Belli bir postayı silmek için client 
	server'a DELE komutunu gönderir. Tüm komutlar yazısal olarak sonu CR/LF ile bitecek biçimde gönderilmktedir. Server her komut için client'a bir 
	yanıt göndermektedir. Olumlu yanıtlar için +OK, olumsuz yanıtlar için -ERR mesaj komutları kullanılmaktadır. Protokolün detayları için RFC-1939
	dokümanına başvurabilirsiniz. 

	Aşağıdaki örnekte komut satırından girilen komutlar POP3 server'a gönderilip oradaki yanıtlar alınarak ekrana yazdırılmıştır. Bıu işlemi telnet 
	denilen hazır programla da yapabilirsiniz. 

-------------------------------------------------------------------------------------------------------------------------------------------*/

/* pop3.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define SERVER_PORTNO			110
#define BUFFER_SIZE				2048
#define SERVER_NAME				"mail.csystem.org"

int ReadLineSocket(SOCKET sock, char *buf, int size);
int WriteSocket(SOCKET sock, const char *buf, int size);
DWORD __stdcall Pop3ReadThreadProc(LPVOID lpvParam);
void ExitSys(LPCSTR lpszMsg, DWORD dwLastErr);

int main(void)
{
	WSADATA wsaData;
	DWORD dwResult;
	SOCKET clientSock;
	struct sockaddr_in sinServer;
	struct hostent *hostEnt;
	char buf[BUFFER_SIZE + 1];
	int result;
	char *str;
	HANDLE hThread;
	DWORD dwThreadId;

	if ((dwResult = WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0)
		ExitSys("WSAStartup", dwResult);

	if ((clientSock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
		ExitSys("socket", WSAGetLastError());
	/*
	{
		struct sockaddr_in sinClient;

		sinClient.sin_family = AF_INET;
		sinClient.sin_port = htons(CLIENT_PORTNO);
		sinClient.sin_addr.s_addr = htonl(INADDR_ANY);

		if (bind(clientSock, (struct sockaddr *)&sinClient, sizeof(sinClient)) == SOCKET_ERROR)
			ExitSys("bind", WSAGetLastError());
	}
	*/

	sinServer.sin_family = AF_INET;
	sinServer.sin_port = htons(SERVER_PORTNO);

	sinServer.sin_addr.s_addr = inet_addr(SERVER_NAME);
	if (sinServer.sin_addr.s_addr == INADDR_NONE) {
		if ((hostEnt = gethostbyname(SERVER_NAME)) == NULL)
			ExitSys("gethostbyname", WSAGetLastError());

		memcpy(&sinServer.sin_addr.s_addr, hostEnt->h_addr_list[0], hostEnt->h_length);
	}
	if (connect(clientSock, (struct sockaddr *)&sinServer, sizeof(sinServer)) == SOCKET_ERROR)
		ExitSys("connect", WSAGetLastError());

	if ((hThread = CreateThread(NULL, 0, Pop3ReadThreadProc, (LPVOID)clientSock, 0, &dwThreadId)) == NULL)
		ExitSys("CreateThread", GetLastError());

	for (;;) {
		Sleep(500);

		printf("POP3>");
		fflush(stdout);
		fgets(buf, BUFFER_SIZE, stdin);
		if ((str = strchr(buf, '\n')) != NULL)
			*str = '\0';

		strcat(buf, "\r\n");
		if ((result = WriteSocket(clientSock, buf, (int)strlen(buf))) == SOCKET_ERROR)
			ExitSys("WriteSocket", WSAGetLastError());
		if (result == 0) {
			printf("Other side closed connection...\n");
			break;
		}
		if (!strcmp(buf, "QUIT\r\n"))
			break;

	}
	shutdown(clientSock, SD_BOTH);
	closesocket(clientSock);
	CloseHandle(hThread);

	WSACleanup();

	return 0;
}

int ReadLineSocket(SOCKET sock, char *buf, int size)
{
	char *bufx = buf;
	static char *bp;
	static int count = 0;
	static char b[2048];
	char ch;

	while (--size > 0) {
		if (--count <= 0) {
			count = recv(sock, b, sizeof(b), 0);
			if (count == SOCKET_ERROR)
				return SOCKET_ERROR;
			if (count == 0)
				return 0;
			bp = b;
		}
		ch = *bp++;
		*buf++ = ch;
		if (ch == '\n') {
			buf[-2] = '\0';
			return (int)(buf - bufx);
		}
	}

	return SOCKET_ERROR;
}

int WriteSocket(SOCKET sock, const char *buf, int size)
{
	int left, count;
	int result;

	left = size;
	count = 0;

	while (left > 0) {
		if ((result = send(sock, buf + count, left, 0)) == SOCKET_ERROR)
			return SOCKET_ERROR;
		if (result == 0)
			break;
		left -= result;
		count += result;
	}

	return count;
}

DWORD __stdcall Pop3ReadThreadProc(LPVOID lpvParam)
{
	char buf[BUFFER_SIZE + 1];
	int result;
	SOCKET sock = (SOCKET)lpvParam;

	for (;;) {
		if ((result = recv(sock, buf, BUFFER_SIZE, 0)) == SOCKET_ERROR)
			ExitSys("recv", WSAGetLastError());
		buf[result] = '\0';
		printf("%s", buf);
	}

	return 0;
}

void ExitSys(LPCSTR lpszMsg, DWORD dwLastErr)
{
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UDP bağlantısız (connectionless), datagram tabanlı, güvenli olmayan hızlı bir protokoldür. Aslında IP protokolünün kendisine çok benzemektedir. 
	Bilgileri paket halinde gönderir. Hiç bağlantı yapmadan bilgi gönderimşi ve alımı mümkündür. Server taraf soketi yarattıktan sonra yine bind eder. 
	Sonra da döngü içerisinde recvfrom fonksiyonu ile datagram paketlerini okur. Clieng taraf bilgi alımı yapmayacaksa bind uygulamaz. Doğrudan
	soketi yaratıp sendto fonksiyonu ile gönderimi yapar. Genellikle UDP'de alan tarafa server, gönderen tarafa client denilmektedir. Ancak client ve 
	server rolleri bu protokolde çok belli değildir. Bir server'a hiç bağlantı yapmadan pek çok cliengt bilgi gönderebilir. recvfrom fonksiyonu
	datagram paketini alırken aynı zamanda onun kişmden geldiğini de elde etmektedir. 

	Aşağıdaki programda tipik bir UDP server örneği verilmiştir.  

-------------------------------------------------------------------------------------------------------------------------------------------*/

/* Server.c */

#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

#define SERVER_PORTNO			55000
#define BUFFER_SIZE				1024

void ExitSys(LPCSTR lpszMsg, DWORD dwLastErr);

int main(void)
{
	WSADATA wsaData;
	DWORD dwResult;
	SOCKET serverSock;
	struct sockaddr_in sinServer, sinClient;
	int addrLen;
	char buf[BUFFER_SIZE + 1];
	int result;

	if ((dwResult = WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0)
		ExitSys("WSAStartup", dwResult);

	if ((serverSock = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) 	/* third parameter IPPROTO_UDP */
		ExitSys("socket", WSAGetLastError());

	sinServer.sin_family = AF_INET;
	sinServer.sin_port = htons(SERVER_PORTNO);
	sinServer.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(serverSock, (struct sockaddr*)&sinServer, sizeof(sinServer)) == SOCKET_ERROR)
		ExitSys("bind", WSAGetLastError());

	printf("Waiting for messages...\n");
	for (;;) {
		addrLen = sizeof(sinClient);
		if ((result = recvfrom(serverSock, buf, BUFFER_SIZE, 0, (struct sockaddr*)&sinClient, &addrLen)) == SOCKET_ERROR)
			ExitSys("recvfrom", GetLastError());
		buf[result] = '\0';
		printf("%d bytes received from %s:%d \"%s\"\n", result, inet_ntoa(sinClient.sin_addr), ntohs(sinClient.sin_port), buf);
	}

	closesocket(serverSock);

	WSACleanup();

	return 0;
}

void ExitSys(LPCSTR lpszMsg, DWORD dwLastErr)
{
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/* Client.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define SERVER_PORTNO			55000
#define BUFFER_SIZE				1024
#define SERVER_NAME				"127.0.0.1" 

void ExitSys(LPCSTR lpszMsg, DWORD dwLastErr);

int main(void)
{
	WSADATA wsaData;
	DWORD dwResult;
	SOCKET clientSock;
	struct sockaddr_in sinServer;
	struct hostent *hostEnt;
	char buf[BUFFER_SIZE];
	char *str;

	if ((dwResult = WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0)
		ExitSys("WSAStartup", dwResult);

	if ((clientSock = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
		ExitSys("socket", WSAGetLastError());
	
	sinServer.sin_family = AF_INET;
	sinServer.sin_port = htons(SERVER_PORTNO);

	sinServer.sin_addr.s_addr = inet_addr(SERVER_NAME);
	if (sinServer.sin_addr.s_addr == INADDR_NONE) {
		if ((hostEnt = gethostbyname(SERVER_NAME)) == NULL)
			ExitSys("gethostbyname", WSAGetLastError());

		memcpy(&sinServer.sin_addr.s_addr, hostEnt->h_addr_list[0], hostEnt->h_length);
	}

	for (;;) {
		printf("Text:");

		fgets(buf, BUFFER_SIZE, stdin);
		if ((str = strchr(buf, '\n')) != NULL)
			*str = '\0';
		if (!strcmp(buf, "exit"))
			break;

		if (sendto(clientSock, buf, (int)strlen(buf), 0, (struct sockaddr *) &sinServer, sizeof(sinServer)) == SOCKET_ERROR)
			ExitSys("send", WSAGetLastError());
	}
	closesocket(clientSock);

	WSACleanup();

	return 0;
}

void ExitSys(LPCSTR lpszMsg, DWORD dwLastErr)
{
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Yukarıdaki programın UNIX/Linuz sistemlerindeki karşılığı aşağıdaki gibi oluşturulabilir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* udp-server.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORTNO			55000
#define BUFFER_SIZE				1024

void exit_sys(const char *msg);

int main(void)
{
    int server_sock;
    struct sockaddr_in sin_server, sin_client;
    socklen_t addrlen;
    char buf[BUFFER_SIZE + 1];
	int result;

	if ((server_sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
        exit_sys("socket");

    sin_server.sin_family = AF_INET;
    sin_server.sin_port = htons(SERVER_PORTNO);
    sin_server.sin_addr.s_addr = htonl(INADDR_ANY);
    
    if (bind(server_sock, (struct sockaddr *)&sin_server, sizeof(sin_server)) == -1)
        exit_sys("bind");

    printf("Waiting for messages...\n");
	for (;;) {
		addrlen = sizeof(sin_server);
		if ((result = recvfrom(server_sock, buf, BUFFER_SIZE, 0, (struct sockaddr*)&sin_client, &addrlen)) == -1)
			exit_sys("recvfrom");
		buf[result] = '\0';
		printf("%d bytes received from %s:%d \"%s\"\n", result, inet_ntoa(sin_client.sin_addr), ntohs(sin_client.sin_port), buf);
	}

	close(server_sock);

	return 0;
}

void exit_sys(const char *msg)
{
    perror(msg);

    exit(EXIT_FAILURE);
}

/* udp-client.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_PORTNO			55000
#define BUFFER_SIZE				1024
#define SERVER_NAME				"127.0.0.1" 

void exit_sys(const char *msg);

int main(void)
{
	int client_sock;
	struct sockaddr_in sin_server;
	struct hostent *hoste;
	char buf[BUFFER_SIZE];
	char *str;

	if ((client_sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
		exit_sys("socket");
	
	sin_server.sin_family = AF_INET;
	sin_server.sin_port = htons(SERVER_PORTNO);

	sin_server.sin_addr.s_addr = inet_addr(SERVER_NAME);
	if (sin_server.sin_addr.s_addr == INADDR_NONE) {
		if ((hoste = gethostbyname(SERVER_NAME)) == NULL)
			exit_sys("gethostbyname");

		memcpy(&sin_server.sin_addr.s_addr, hoste->h_addr_list[0], hoste->h_length);
	}

	for (;;) {
		printf("Text:");

		fgets(buf, BUFFER_SIZE, stdin);
		if ((str = strchr(buf, '\n')) != NULL)
			*str = '\0';
		if (!strcmp(buf, "exit"))
			break;

		if (sendto(client_sock, buf, (int)strlen(buf), 0, (struct sockaddr *) &sin_server, sizeof(sin_server)) == -1)
			exit_sys("sendto");
	}
	close(client_sock);

	return 0;
}

void exit_sys(const char *msg)
{
    perror(msg);

    exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	İçerisinde derlenmiş bir biçimde fonksiyonların (ve sınıfların) bulunduğu dosyalara kütüphaner (library) denilmektedir. (Yorumlayıcı temelli
	kullanımda kütüphanelerin içerisindeki kodalr derlenmiş bir biçimde değillerdir.) Kütüphaneler statik ve dinamik olmak üzere ikiye ayrılmaktadır. 
	Statik kütüphanelerin Windows sistemlerinde uzantıları .lib, UNIX/Linux sistemlerinde uzantıları .a biçimindedir. Dinamik kütüphanelerin Windows
	sistemlerindeki uzantıları .dll UNIX/Linux sistemlerindeki uzantıları ise .so biçimindedir. 

	Statik kütüphaneler amaç dosyalardan (object files) oluşan bir dizin gibidir. Yani statik kütüphaneler doğrudan fonksiyon içermezler. Onların içerisinde
	amaç dosyalar vardır. Fonksiyonlar ve global nesneler o amaç dosyaların içerisinde bulunurlar. Amaç dosyaların Windows sistemlerindeki uzantıları 
	.obj UNIX/Linux sistemlerindeki uzantıları ise .o biçimindedir. Amaç dosyalar fonksiyonların makine diline çevrilmiş biçimlerini tutmanın yanı sıra
	linker için bazı bilgileri de barındırmaktadır. 32 bit 64 bit Windows sistemlerinde kullanılam amaç dosya formatına COFF (Common Object File Format) 
	denilmektedir. UNIX/Linux sistemleri amaç dosya formatı olarak ELF (Executable and Linkable Format) formatınuı kullanmaktadır. Mac OS X sistemlerinde ise
	amaç dosya formatı olarak Mach-O isimli formatı kullanmaktadır.

	Derleyici bir .c dosyasını derlerken extern bir nesne ile ya da tanımlaması o C dosyasında yapılmamış bir fonksiyon çağrısıyla karşılaştığında
	amaç dosyasının belli bir bölümüne linker için notlar yazmaktadır. Bu not şöyle düşünülebilir. "Linker ben foo ve bar fonksiyonlarını buşamadım. 
	Ama onların çağrıldı yerlerde CALL makine komutlarını oluşturdum. Ancak bunların nerede olduğunu bilmediğim için CALL makine komutlarının hedef 
	adreslerini boş bıraktım. Sen bir zahmet diğer modüllere ve statik kütüphanelere bakarak bu fonksiyonları bul ve kodda belirttiğim CALL komutlarının
	hedef adreslerini doğru bir biçimde yaz". Görüldüğü gibi linker yalnızca amaç dosyaları birleştirmemekte aynı zamanda kodlarda düzeltmeler de 
	yapmaktadır. 

	Microsoft'un linker programı "link.exe" isimli programdır. UNIX/Linux sistemlerinde ağırlıklı biçimde GNU'nun "ld" isimli linker programı 
	kullanılmaktadır. Bu linker programları amaç dosyaları ve kütüphane dosyalarını komut satırı argümanı olarak alırlar ve çalıştırılabilen (executable) 
	dosyasyı üretirler. Genel olarak bir amaç dosyada bulunamayan öğeler önce diğer amaç dosyalarda aranır. Eğer diğer amaç dosyalarda bulunamazlarsa statik 
	kütüphane dosyalarında aranmaktadırlar. Linker'lar genel olarak default durumda standart C fonksiyonlarının bulunduğu kütüphanelere ve bazı temel kütüphanelere
	komut satırı argümanlarında belirtilmiş olmasa da bakarlar. Linker statik kütüphane içerisinde bir fonksiyonu bulduğunda yalnızca o fonksiyonun kodunu
	çalıştırılabilen dosyaya yazamaz. O fonksiyonun bulunduğu amaç dosyanın tamamını çalıştırılabilen dosyaya yazar. 

	Aşağıdaki "test.c" dosyası derlendiğinde derleyici linker için bulunamayan sembolerin neler olduğunu (g_x ve bar) ve kodda nerelerin düzeltileceğini amaç dosya içerisine 
	yazmaktadır. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* test.c */

extern int g_a;
void bar(void);

void foo(void)
{
	g_a = 10;		/* MOV [xxxx], 10 */
	bar();			/* CALL yyyy */
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Yukarıdaki programı Microsoft derleyicilerinde aşağıdaki gibi "only compile" yapabilirsiniz:

	cl /c test.c

	Sonra bu object dosyanın içeriği okunabilir bir biçimde dumpbin programı ile görüntülenebilir:

	dumpbin /ALL test.obj

	Buradan elde edilen çıktı aşağıdaki gibidir:

	Microsoft (R) COFF/PE Dumper Version 14.29.30138.0
Copyright (C) Microsoft Corporation.  All rights reserved.


Dump of file test.obj

File Type: COFF OBJECT

FILE HEADER VALUES
			 14C machine (x86)
			   4 number of sections
		620FE241 time date stamp Fri Feb 18 21:15:29 2022
			 1A7 file pointer to symbol table
			   E number of symbols
			   0 size of optional header
			   0 characteristics

SECTION HEADER #1
.drectve name
	   0 physical address
	   0 virtual address
	  2F size of raw data
	  B4 file pointer to raw data (000000B4 to 000000E2)
	   0 file pointer to relocation table
	   0 file pointer to line numbers
	   0 number of relocations
	   0 number of line numbers
  100A00 flags
		 Info
		 Remove
		 1 byte align

RAW DATA #1
  00000000: 20 20 20 2F 44 45 46 41 55 4C 54 4C 49 42 3A 22     /DEFAULTLIB:"
  00000010: 4C 49 42 43 4D 54 22 20 2F 44 45 46 41 55 4C 54  LIBCMT" /DEFAULT
  00000020: 4C 49 42 3A 22 4F 4C 44 4E 41 4D 45 53 22 20     LIB:"OLDNAMES"

   Linker Directives
   -----------------
   /DEFAULTLIB:LIBCMT
   /DEFAULTLIB:OLDNAMES

SECTION HEADER #2
.debug$S name
	   0 physical address
	   0 virtual address
	  7C size of raw data
	  E3 file pointer to raw data (000000E3 to 0000015E)
	   0 file pointer to relocation table
	   0 file pointer to line numbers
	   0 number of relocations
	   0 number of line numbers
42100040 flags
		 Initialized Data
		 Discardable
		 1 byte align
		 Read Only

RAW DATA #2
  00000000: 04 00 00 00 F1 00 00 00 6E 00 00 00 30 00 01 11  ....�...n...0...
  00000010: 00 00 00 00 46 3A 5C 44 72 6F 70 62 6F 78 5C 4B  ....F:\Dropbox\K
  00000020: 75 72 73 6C 61 72 5C 53 79 73 50 72 6F 67 2D 31  urslar\SysProg-1
  00000030: 5C 53 72 63 5C 74 65 73 74 2E 6F 62 6A 00 3A 00  \Src\test.obj.:.
  00000040: 3C 11 00 22 00 00 07 00 13 00 1D 00 BA 75 00 00  <.."........�u..
  00000050: 13 00 1D 00 BA 75 00 00 4D 69 63 72 6F 73 6F 66  ....�u..Microsof
  00000060: 74 20 28 52 29 20 4F 70 74 69 6D 69 7A 69 6E 67  t (R) Optimizing
  00000070: 20 43 6F 6D 70 69 6C 65 72 00 00 00               Compiler...

SECTION HEADER #3
.text$mn name
	   0 physical address
	   0 virtual address
	  14 size of raw data
	 15F file pointer to raw data (0000015F to 00000172)
	 173 file pointer to relocation table
	   0 file pointer to line numbers
	   2 number of relocations
	   0 number of line numbers
60500020 flags
		 Code
		 16 byte align
		 Execute Read

RAW DATA #3
  00000000: 55 8B EC C7 05 00 00 00 00 0A 00 00 00 E8 00 00  U.��.........�..
  00000010: 00 00 5D C3                                      ..]�

RELOCATIONS #3
												Symbol    Symbol
 Offset    Type              Applied To         Index     Name
 --------  ----------------  -----------------  --------  ------
 00000005  DIR32                      00000000         B  _g_x
 0000000E  REL32                      00000000         9  _bar

SECTION HEADER #4
 .chks64 name
	   0 physical address
	   0 virtual address
	  20 size of raw data
	 187 file pointer to raw data (00000187 to 000001A6)
	   0 file pointer to relocation table
	   0 file pointer to line numbers
	   0 number of relocations
	   0 number of line numbers
	 A00 flags
		 Info
		 Remove
		 (no align specified)

RAW DATA #4
  00000000: 23 07 66 15 27 1A BF 1A 3D 06 59 43 13 8C 8E CC  #.f.'.�.=.YC...�
  00000010: 36 68 66 95 5C 95 74 57 00 00 00 00 00 00 00 00  6hf.\.tW........

COFF SYMBOL TABLE
000 010475BA ABS    notype       Static       | @comp.id
001 80010191 ABS    notype       Static       | @feat.00
002 00000002 ABS    notype       Static       | @vol.md
003 00000000 SECT1  notype       Static       | .drectve
	Section length   2F, #relocs    0, #linenums    0, checksum        0
005 00000000 SECT2  notype       Static       | .debug$S
	Section length   7C, #relocs    0, #linenums    0, checksum        0
007 00000000 SECT3  notype       Static       | .text$mn
	Section length   14, #relocs    2, #linenums    0, checksum F992C02D
009 00000000 UNDEF  notype ()    External     | _bar
00A 00000000 SECT3  notype ()    External     | _foo
00B 00000000 UNDEF  notype       External     | _g_x
00C 00000000 SECT4  notype       Static       | .chks64
	Section length   20, #relocs    0, #linenums    0, checksum        0

String Table Size = 0x0 bytes

  Summary

		  20 .chks64
		  7C .debug$S
		  2F .drectve
		  14 .text$mn


Burada derleyici amaç dosyanın "relocation tablosunda" linker'ın düzelteceği offset'leri listelemiştir. 

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	Microsoft Windows sistemlerinde statik kütüphane dosyaları özel bir formata sahiptir. Bunu oluşturmak için Microsoft "lib.exe" isimli 
	yardımcı bir program bulundurmuştur. lib.exe programının en önemli birkaç kullanımı şöyledir:

	lib OUT:mylib.lib a.obj b.obj

	Burada mylib.lib dosyası yendeiden yaratılır ve onun içerisine a.obj ve b.obj dosyaları eklenir. 

	lib mylib.lib c.obj

	Burada mylib.lib dosyasının var olması gerekir. Onun içerisine c.obj dosyası eklenir. 

	lib /LIST mylib.lib

	Burada mylib.lib içerisindeki amaç dosyalar görüntülenir. 

	lib /REMOVE:a.obj mylib.lib

	Burada mylib.lib içerisinden a.obj dosyası silinir. 

	lib mylib.lib /EXTRACT:a.obj 

	Burada mylib.lib içerisindeki a.obj dosyası dışarıda a.obj olarak save edilir. Fakat kütüphanenin içeriisnden silinmez.
		
	Aşağıdaki örnekte "a.c" ve "b.c" dosyaları aşağıdaki gibi derlenip "mylib.lib" isimli bir statik kütüphane dosyası oluşturulmuştur:

	cl /c a.c
	cl /c b.c
	lib /OUT:mylib.lib a.obj b.obj

-------------------------------------------------------------------------------------------------------------------------------------------*/
/* a.c */

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

/* b.c */

int multiply(int a, int b)
{
	return a * b;
}

int divide(int a, int b)
{
	return a / b;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Şimdi yukarıda oluşturduğumuz mylib.lib statik kütüphanesindeki fonksiyonları kullanan aşağıdaki "app.c" programını derleyip link edelim.
	Bunu iki biçimde yapabiliriz. En basit biçim şöyledir:

	cl /OUT:app.exe app.c mylib.lib

	Burada cl derleyicisi /c belirtilmediği için link.exe linker'ını kendisi çağıracaktır. cl derleyicisi .lib ve .obj uzantılı dosyaları zaten 
	linker'ı çalıştırırken link.exe programına vermektedir. Dolayısıyla yukarıdaki çalıştırmada bir sorun çıkmayacaktır. İkinci yöntemde bu işlem 
	ayrı ayrı da yapılabilir:

	cl /c app.c 
	link OUT:app.exe app.obj mylib.lib

	Burada link.exe programı zaten standart C fonksiyonlarının bulunduğu kütüphaneye de otomatik bakmaktadır. 

-------------------------------------------------------------------------------------------------------------------------------------------*/

/* app.c */

#include <stdio.h>

int add(int a, int b);
int sub(int a, int b);
int multiply(int a, int b);
int div(int a, int b);

int main(void)
{
	printf("%d\n", add(20, 10));
	printf("%d\n", sub(20, 10));
	printf("%d\n", multiply(20, 10));
	printf("%d\n", divide(20, 10));

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Visual Studio IDE'sinde bir static kütüphaneyi projemizde kullanabilmemiz için proje ayarlarından Linker/Input sekmesinde Additional Depndencies
	seçilir ve statik kütüphane dosyası o listenin sonuna ';' konularak eklenir. Aslında IDE'de aynı işlem .LIB dosyasının proje içerisine eklenmesiyle de
	yapılabilmektedir. 

	Visual Studio derleyicisi default durumda standart C kütüphanesinin dinamik versiyonunu kullanmaktadır. Eğer projenizde standart C kütüphanesinin statik
	cersyionunu kullanmak istiyorsanız komut satırında /MT seçeneği eklenmelidir. Aynı işlem proje seneklerinde C-C++/Code Generation/Runtime Library 
	sekmesinden de ayarlanabilmektedir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde statik kütüphane dosyalarını oluşturmak için "ar" isimli program bulunmaktadır. Bu ar programının en önemli iki komut satırı 
	argmanı "c" ve "r" dir. "c" her zaman kütüphaner dosyasının yeniden yaratılmasını sağlar. "r" ise mevcut bir objecy modülü kütüphaneye ekler. Örneğin:

	gcc -c a.c
	gcc -c b.c 
	ar cr mystaticlib.a a.o b.o

	UNIX/Linux sistemlerindeki "ar" programı aslında Microsoft sistemlerindeki "LIB" programının bir karşılığıdır. Windows sistemlerindeki DUMPBIN programının 
	UNIX/Linux sistemlerindeki karşılığı ise readelf ve objdump gibi programlardır. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistelerinde bir statik kütüphaneye başvuru işlemi gcc komut satırında .a dosyasının belirtilmesi yoluyla yapılabilmektedir. Örneğin:

	gcc -o app app.c mystaticlib.a

	Vurada gcc programı .a uzantılı dosyaları ld bağlayıcısını çalıştırırken ona geöirmektedir. Aynı işlem iki parça haline şöyle de yapılabilirdi:

	gcc -c app.c
	gcc -o app app.o mystaticlib.a

	ld bağlayıcının kullanılması sırasında standart kütüphanelerin programcı tarafından belirtilmesi gerekmektedir. Aynı programcının startup dosyalarını da
	link aşamasına katması gerekir. Bağlama işlemi gcc ile yapıldığında gcc programı ld bağlayıcısını uygun biçimde çalıştırmaktadır. 

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde default durumda standart C kütüphanesinin ve POSIX kütüphanesinin dinamik versiyonları kullanılmaktadır. Programcı 
	bu kütüphanelerin statik versiyonlarını kullanmak için -static komut satırı argümanını geçirmelidir. gcc programı bu durumda ld linker'ına durumu
	bildirmektedir. (Yani aslında -static bir ld komut satırı argğmanıdır.) Örneğin:

	gcc -o app app.c -static

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde statik kütüphane dosyası başka bir dizindeyse bu durumda o dosyaya referans ederken yol ifadesi kullanılabilir. Öneğin:

	gcc -o app app.c xxx/mystaticlib.a

	Aslında bu sistemlerde genel olarak kütüphane dosyalarının başı lib önekiyle başlatılmaktadır. Bu durumda -l seçeneği ile bu lib öneki ve uzantı kullanılmadan
	kütüphane belirtilebilmektedir. Ancak -l seçeneği kütüphane dosyalarını bazı dizinlerde aramaktadır. İşte programcı -L seçeneği ile arama dizinine ek yapabilir. 
	Örneğin:

	gcc -o app app.c -L xxx -l mystatic

	Bu durumda linker xxx dizininde libmystatic.a ya da libmystatic.so dosyalarını arayacaktır. Örneğin biz thread işlemleri için thread kütüphanesini 
	şöyle link ediyorduk:

	gcc -o sample sample.c -lpthread 

	Aslında burada libpthread.so ya da libpthread.a kütüphaneleri link işlemine sokulmaktadır. Tabii bu kütüphaneler -l ile aranan özel dizinlerde 
	zaten bulunmaktadır. 

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	Dinamik küüphaneler Windows sistemlerinde .DLL uzantısıyla UNIX/Linux sistemlerinde .so uzantısıyla bulunmaktadır. Bir dinamik kütüphaneden bir 
	çağrı yapıldığında linker dinamik kütüphane içerisindeki fonksiyonu çalıştırılabilen dosyaya yazmaz. Çalıştırılabilen dosyaya yalnızca 
	hangi dinamik kütüphaneden hangi fonksiyonun çağrıldığı bilgisini yazar. Dinamik kütüphane kullanan bir program çalıştırılmak istendiğinde 
	işletim sistemi çalıştırılmak istenen programın hangi dinamik kütüphaneleri kullandığını belirler. Sonra çalıştırılabilen dosyayla birlikte o dinamik 
	kütüphaneleri de sanal bellek alanına yükler. Artık programın akışı dinamik kütüphanedeki fonksiyonun çağrılma noktasına geldiğinde akış bellekte
	yüklenmiş olan dinamik kütüphane kodlarının içerisine atlayarak fonksiyon çalıştırılacaktır. Tabii dinamik kütüphane kullanan bir program
	başka bir makineye yükleneceği zaman yalnızca çalıştırılabilen dosyanın değil onun kullandığı dinamik kütüphane dosyalarının da hedef makineye taşınması 
	gerekir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	Microsoft Windows sistemlerinde bir DLL oluşturmak için tek yapılacak şey link aşamasında /DLL seçeneğini kullanmaktır. Örneğin a.c ve b.c
	dosyalarını derleyerek bunlardan DLL yapmak isteyelim. Bu işlemi parça paça şöyle gerçekleştirebiliriz:

	cl /c a.c
	cl /c b.c
	link /DLL a.obj b.obj

	Buradan ilk dosyanın ismine ilişkin a.dll dosyası elde edilecektir. Tabii /DLL seçeneği kullanılmasaydı default durumda bu dosyalardan 
	.exe dosyası oluşturulmaya çalıştırılacaktı. Tabii bu durumda bir main fonksiyonun buluması gerekecekti. Yukarıdaki işlem aslında tek hamlede 
	/LD seçeneği ile aşağıda gibi de yapılabilmektedir:

	cl /LD a.c b.c 

	Normal olarak çalıştırılabilen dosyası ya da DLL dosyasını linker oluşturduğuna göre bu dosyaya linker isim vermektedir. Eğer özel bir isim seçilmemişse
	linker ilk komut satırı argümanı ile belirtilen bject dosyası isim olarak verir. Örneğin:

	link a.obj b.obj

	Buradan a.exe dosyası elde edilecektir. Ancak /OUT seçeneği ile bu dosyanın ismi değiştirilebilmektedir:

	link /OUT:x.exe a.obj b.obj

	Artık bu link işleminden x.exe dsoaya elde edilecektir. Aynı durum DLL dosyaları için de geçerlidir. Örneğin:

	link /DLL a.obj b.obj

	Buradan a.dll dosyası elde edilir. Ancak:

	link /OUT:x.dll /DLL a.obj b.obj

	Buradan x.dll dosyası elde edilecektir. 

	cl derleyicisinin /c seçeneği kullanılmamışsa link programını çalıştırdığını anımsayınız. Bu durumda yine hedef dosya ilk dosyanın ismi 
	ile oluşturulacaktır. Örneğin:

	cl a.c b.c

	Buradan a.exe dosyası elde edilecektir. cl derleyicisinde hedef dosyanın ismini değiştirmek için /Fe seçeneği kullanılmaktadır. (Aslında bu 
	seçenek link programını /OUT ile çağırmaktadır.) Örneğin:

	cl /Fe:x.exe a.c b.c 

	Buradan x.exe dosyası elde edilecektir. Örneğin:

	cl /Fe:x.dll /LD a.c b.c 

	Buradan x.dll dosyası elde edilecektir. 

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	Teknik anlamda Microsoft Wİndows sistemlerinde .EXE dosyası ile .DLL dosyası arasında format bakımından farklılık yoktur. He riki dosya da 
	PE (Portable Executable) dosya formaına ilişkindir. .EXE doaysının .DLL dosyasından tek farkı bir "entry point" yani main fonksiyonuna sahip olmasıdır. 
	Bir DLL içerisinde main fonksiyonunun olması o DLL dosyasını EXE dosya yapmaz. DLL dosyasının içerisindeki main fonksiyonu sıradan bir fonksiyon gibi
	DLL'in içerisinde bulunur. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows'ta bir DLL içerisindeki fonksiyonun ya da global nesnenin dışarıdan kullanılabilmesi için o fonksiyonun ya da global nesnenin adresinin 
	PE formatının "export tablosu" denilen bir yerinde bulunması gerekir. İşte DLL içerisindeki bir global nesnenin ya da fonksiyonun adresinin 
	export tablosuna yazılması için Micrososft derleyicilerine özgü __declspec(dllexport) belirleyicisinin kullanılması gerekmektedir. Aksi takdirde
	o nesneler ve fonksiyonlar başka bir modülden kullanılamazlar. Aşağıdaki örnekte DLL içerisinde foo ve g_a dışarıdan kullanılbilir ancak bar g_b dışarıdan 
	kullanılmaz. Tabii bu bar ve g_b DLL'in kendi içeriisndeki fonksiyonlardan kullanılabilir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void bar(void);

__declspec(dllexport) int  g_a;
int g_b;

__declspec(dllexport) void  foo(void)
{
	printf("foo\n");
}

void bar(void)
{
	printf("bar\n");
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Aslında sınıf (class) kavramı yapay ve mantıksal bir kavramdır. Aşağı seviyeli dünyada sınıf diye bir kavram yoktur. Aslında C++'taki sınıflardaki
	üye fonksiyonlar global fonksiyonlar gibi derlenirler. Dolayısıyla C++'ta bir sınıfı DLL'e yerleştirmek için yine üye fonksiyonların önünde 
	hangi üye fonksiyonlar dışarıdan kullanılacaksa __declspec(dllexport) bildirimlerinin yapılması gerekir. 

	Aşağıdaki örnekte yalnızca sınıfın yapıcı fonksiyonu ve disp fonksiyonu DLL dışındna kullanılabilir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <iostream>

using namespace std;

class Sample {
public:
    __declspec(dllexport) Sample(int a);
    void foo() const;
    void disp() const;
private:
    void bar() const;
    int m_a;
};

Sample::Sample(int a)
{
    m_a = a;
}

void Sample::foo() const
{
    cout << "foo" << endl;
}

void Sample::disp() const
{
    cout << m_a << endl;
}

void Sample::bar() const
{
    cout << "bar" << endl;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Eğer __declspec(dllexport) belirleyicisi class anahtar sözcüğü ile sınıf ismi arasına getirilirse bu durumda sınıfın bütün üye fonksiyonları 
	export tablosuna yazılmaktadır. private fonksiyonlar da yine expot tablosuna yazılacaktır. Çünkü private fonksiyonlar frien bildirimi ile
	başka yerlerden çağrılabilmektedir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <iostream>

using namespace std;

class __declspec(dllexport) Sample {
public:
    Sample(int a);
    void foo() const;
    void disp() const;
private:
    void bar() const;
    int m_a;
};

Sample::Sample(int a)
{
    m_a = a;
}

void Sample::foo() const
{
    cout << "foo" << endl;
}

void Sample::disp() const
{
    cout << m_a << endl;
}

void Sample::bar() const
{
    cout << "bar" << endl;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows'ta bir DLL içerisindeki fonksiyonlar dışarıdan kullanılırken yalnızca prototip yazılması aslında yeterlidir. Benzer biçimde 
	bir DLL içerisindeki global nesneler dışarıdan kullanılırken extern bildirimi yeterlidir. Ancak ilgili fonksiyonun
	ve global nesnenin DLL içerisinde olduğu derleyiciye bildirilirse derleyici daha etkin kod üretebilmektedir. (Bu konudaki detaylar Windows Sistem Programlama) 
	kursu içerisinde ele alınmaktadır. İşte derleyiciye ilgili global nesnenin ya fonksiyonun bir DLL içeirisinde olduğunu anşlatabilmek için 
	__declspec(dllimport) bildirimi yapılır Örneğin yukarıdaki DLL'deki nesneyi fonksiyonu kullanırken aşağıdaki gibi __declspec(dllimport) bildirimi 
	yapmalıyız.
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

__declspec(dllimport) void foo(void);
__declspec(dllimport) extern int g_a;

int main(void)
{
    g_a = 10;
    foo();
    printf("%d\n", g_a);

    return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Tabii aslında her kürüphane için kütüphaneyi oluşturanın bir başlık dosyası oluşturması gerekir. Pekiyi bu başlık dosyasında __declspec(dllexport) 
	mu yoksa declspec(dllimport) mu bulunacaktır? İşte bu durum genellikle programcılar tarafından önişlemci komutlarıyla gerçekleştirilir. 

	Aşağıdaki örnekte "x.h" dosyası hem DLL build edilirken hem de DLL kullanılırken include edilecek biçimde oluşturulmuştur. Eğer DLLBUILD isimli
	sembolik sabit daha önce define edilmişse aslında __declspec(dllexport) denilmiş olmaktadır. Eğer bu sembolik sabit daha önce define edilmemişse 
	bu durumda __declspec(dllimport) denmiş olmaktadır. Tabii buradaki DLLBUILD ve DLLSYMBOL isimleri herhangi bir biçimde programcı tarafından seçilebilir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* x.h */

#ifndef X_H_
#define X_H_

#ifdef DLLBUILD
#define DLLSYMBOL   __declspec(dllexport)
#else
#define DLLSYMBOL   __declspec(dllimport)
#endif 

extern DLLSYMBOL int g_a;
DLLSYMBOL void  foo(void);

#endif

/* x.c */

#define DLLBUILD

#include <stdio.h>
#include "x.h"

void bar(void);

int g_a;
int g_b;

void  foo(void)
{
	printf("foo\n");
}

void bar(void)
{
	printf("bar\n");
}

/* app.c */

#include <stdio.h>

__declspec(dllimport) void foo(void);
__declspec(dllimport) extern int g_a;

int main(void)
{
    g_a = 10;
    foo();
    printf("%d\n", g_a);

    return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows sistemlerinde Bir DLL bir uygulamadna kullanılırken ilgili DLL fonksiyonlarınıun hangi DLL içerisindeki fonksiyonlar olduğunu ve bazı teknik bilgileri 
	linker programının bilmesi gerekmektedir. İşte bir DLL oluşturulurken linker aslında .DLL dosyasının yanı sıra DLL import kütüphanesi denilen
	bir .LIB dosyası da oluşturmaktadır. Bu .LIB dosyası bir statik kütüphane dosyası değildir. DLL'i kullanacak programın link aşamasında kullanacağı
	bir dosyadır. Yani bizim bir DLL'i kullanabilmemiz için o DLL'in yanı sıra bir de o DLL'in import kütüphanesine gereksinimimiz vardır. Tabii DLL'in
	import kütüphanesi yalnızca DLL'i kullanan program link edilirken devreye girer. Bu program başka makineye taşınırken import kütüphanesinin 
	oraya taşınmasına gerek yoktur. Bu durumda x.dll'deki fonksiyonları kullanan app.c programının komut satırından şöyle derlenmesi gerekir:

	cl app.c x.lib

	Buradaki x.lib x.dll dosyasının import kütüphanesidir. Bu işlem ayrı ayrı şöyle de yapılabilirdi:

	cl /c app.c
	link app.obj x.lib

	Aşağıdaki örnekte bir DLL oluşturulup o DLL kullanılmıştır. Burada DLL uygulaması "TestDll.c" dosyasından, onu kullanan uygulama da "App.c" dosyasından
	oluşmaktadır. Bu iki dosya da ortak biçimde "TestDll.h" dosyasını include etmektedir.  Bu tür uygulamalar Visual Studio IDE'si kullanılarak 
	bir solution içerisinde bir DLL projesi bir de uygulama prrojesi oluşturmak yoluyla yapılabilir. Aşağıdaki kodun komut satırında derlenip kullanılması 
	için aşama aşama şunların yapılması gerekir. 

	cl /c -D DLLBUILD TestDll.c 
	link /DLL TestDll.obj
	cl /c app.c
	link app.obj TestDll.lib

	Yukarıdaki işlem aşağıdaki gibi bir arada da yapılabilirdi:

	cl -D DLLBUILD /LD TestDll.c
	cl app.c TestDll.lib

-------------------------------------------------------------------------------------------------------------------------------------------*/

/* TestDll.h */

#ifndef TESTDLL_H_
#define TESTDLL_H_

#ifdef DLLBUILD 
#define DLLSYMBOL __declspec(dllexport)
#else
#define DLLSYMBOL __declspec(dllimport)
#endif

DLLSYMBOL extern int g_a;
DLLSYMBOL void foo(void);
DLLSYMBOL void bar(void);

#endif

/* TestDll.c */

#include <stdio.h>
#include "TestDll.h"

int g_a;

void foo(void)
{
	printf("foo\n");
}

void bar(void)
{
	printf("bar\n");
}

/* App.c */

#include <stdio.h>
#include "TestDll.h"

int main(void)
{
	foo();
	bar();

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows'ta DLL kullanan bir program çalıştırılmak istendiğinde işletim sistemi o programın kullandığı DLL dosyalarını sırasıyla bazı dizinlerde 
	aramaktadır. Bu dizinler tipik olarak şunlardır:

	1) Exe programın bulunduğu dizin
	2) Windows/System32 dizini
	3) Window/System dizini
	4) Windows dizininin kendisi
	5) Programı çalıştırmak isteyen prosesin çalışma dizini
	6) PATH çevre değişkeni ile belirtilen dizinler 
	
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde dinamik kütüphane oluşturmak için önce dinamik kütüphane oluşturulacak .c dosyaları "position indepenedent code"
	tekniğiile derlenmek zorundadır. "Position Independent Code" ilgili dinamik kütüphanenin yüklenme yerinden bağımsız çalışabilmesini sağşamaktadır. 
	Windows bu tekniği tercih etmemiştir. Windows'un yükleyicisi "relocation" işlemi ile DLL'leri farklı yerlere yükleyebilmektedir. Position
	Independent Code tekniği ile derlenmiş olan dosyalar -shared bağlama seçeneği ile bağlanırsa dinamik kütüphane oluşturulabilmektedir. UNUX/Linux sistemlerinde 
	kütüphane içerisindeki global sembollerin hepsi otomatik olarak export edilmektedir. Dolayısıyla bu sistemlerde Windows sistemlerinde olduğu gibi __declspec(dllexport)
	ve __declspec(dllimport) biçiminde bildirimler yoktur. Bu konuda bazı ayrıntılar bulunmaktadır.
		
	Aşağıdaki örnekte myso.c dosyası dinamik kütüphane yapılmak istenmektedir. Bu işlem komut satırında şöyle gerçekleştirilir:

	gcc -c -fPIC myso.c
	gcc -o myso.so -shared myso.o 

	Aslında bu işlem tek aşamada şöyle de gerçekleştirilebilmektedir:

	gcc -fPIC -shared myso.c

	Bu durumda -shared seçeneğini derleyici zaten linker'a pass etmektedir. 

-------------------------------------------------------------------------------------------------------------------------------------------*/

/* myso.h */

#ifndef MYSO_H_
#define MYSO_H_

void foo(void);
void bar(void);

#endif

/* myso.c */

#include <stdio.h>
#include "myso.h"

void foo(void)
{
    printf("foo\n");
}

void bar(void)
{
    printf("bar\n");
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde dinamik kütüphane kullanılırken link işleminde so dosyasının kendisi kullanılmaktadır. Yani bu sistemlerde ayrıca
	bir import kütüphanesi yoktur. Link işlemi de so dosyasının kendisi kullanılarak yapılmaktadır.Aşağıdaki programın "myso.so" dinamik kütüphanesini
	kullanacağını düşünelim. Bu işlem şöyle yapılmaktadır:

	gcc -c app.c
	gcc -o app app.o myso.so

	Aynı işlem tek aşamada şöyle de yapılabilirdir:

	gcc -o app app.c myso.so
	
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include "myso.h"

int main(void)
{
    foo();
    bar();

    return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde dinamik kütüphane kullanan bir program yükleenirken yine işletim sistemi o dinamik kütüphaneyi sırasıyla bazı dizinlerde
	aramaktadır. Ancak aranan bu dizinler Windows'takilerden farklıdır. Örneğin UNIX/Linux sistemlerinde çalıştırılabilen dosyanın dizininie ya da 
	o andaki çalışma dizinine hiç bakılmamaktadır. Bu sistemlerdeki dinamik kütüphane arama sırası şöyledir:

	1) Programı çalıştıran (yani exec yapan) prosesin LD_LIBRARY_PATH çevre değişkeni ile belirtilen dizinlerinde tek tek arama yapılmaktadır.
	2) Çalıştırılacak programın sinamik bölümnde DT_RUNPATH özelliği varsa oradaki dizinde aranmaktadır.
	3) /lib ve /usr/lib dizinlerine bakılır. Bazı 64 bit Linux dağıtımlarında /lib64 ve /usr/lib64 dizinlerine de bakılmaktadır. 

	Eğer bu sistemlerde oluşturduğumuz DLL başka programlar tarafından da kullanılıyorsa onun için en doğal yer /usr/lin dizinidir. /lib dizini 
	daha aşağı seviyeli işletim sistemi tarafıdan kullanılan dinamik kütüphanelere ayrılmıştır. Eğer programcı dinamik kütüphanesini çalıştırılabilen dosya ile
	aynı dizine yerleştirmişse bu durumda LD_LIBRARY_PATH çevre değişkeni aşağıdaki gibi set edilebilir:

	export LD_LIBRARY_PATH=.

	Buradaki '.' prosin çalışma dizin anlamındadır. LD_LIBRARY_PATH çevre değişkenine exec işlemi sırasında bakılmaktadır. 
	
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	Dinamik kütüphaneler programın çalışma zamanı sırasında programcının istediği bir noktada programcı tarafından da yüklenebilmektedir. 
	Bu duruma "dinamik kütüphanelerin dinamik yüklenmesi" denilmektedir. Bu işelm Windows'ta şöyle yapılmaktadır:

	1) Önce LoadLibrary API fonksiyonuyla yüüklenecek DLL ismi belirtilerek DLL yüklenir. Bu fonksiyonun parametresinde eğer en az bir '\' karakteri
	girilirse DLL yalnızca o dizinde aranmaktadır. Eğer dosya isminde hiçbir '\' karakteri yoksa bu durumda DLL yukarıda belirtilen dizinlerde sırasıyla
	aranır. Bu fonksiyon dinamik kütüphaneyi yükleyerek yüklenen adrese geri döner. Geri dönüş değeri HMODULE türündendir. Bu tür de aslında void * 
	olarak typedef edilmiştir. 

	2) DLL içerisinden çağrılacak fonksiyonun adresi GetProcAddress fonksiyonuyla elde edilir. Bu fonksiyon başarıdurumunda fonksiyon adresini 
	FARPROC türünden genel bir fonksiyon adresi biçiminde vermektedir. Bu fonkisyon adresini uygun bir fonksiyon gösterici adresine dönüştürüp fonksiyon
	çağrılabilir. 

	3) İşlem bittikten sonra LoadLibrary API fonksiyonu ile yüklenmiş olan DLL FreeLibrary API fonksiyonu ile boşaltılır. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* DynamicLoad.c */

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	HMODULE hModule;
	void (*foo)(void);
	void (*bar)(void);
	int *ga;

	if ((hModule = LoadLibrary("TestDll.dll")) == NULL)
		ExitSys("LoadLibrary");

	if ((foo = (void (*)(void)) GetProcAddress(hModule, "foo")) == NULL)
		ExitSys("GetProcAddress");

	if ((bar = (void (*)(void)) GetProcAddress(hModule, "bar")) == NULL)
		ExitSys("GetProcAddress");

	if ((ga = (int *) GetProcAddress(hModule, "g_a")) == NULL)
		ExitSys("GetProcAddress");

	foo();
	bar();
	printf("%d\n", *ga);

	FreeLibrary(hModule);

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/* TestDll.h */

#ifndef TESTDLL_H_
#define TESTDLL_H_

#ifdef DLLBUILD 
#define DLLSYMBOL __declspec(dllexport)
#else
#define DLLSYMBOL __declspec(dllimport)
#endif

DLLSYMBOL extern int g_a;
DLLSYMBOL void foo(void);
DLLSYMBOL void bar(void);

#endif

/* TestDll.c */

#include <stdio.h>
#include "TestDll.h"

int g_a = 100;

void foo(void)
{
	printf("foo\n");
}

void bar(void)
{
	printf("bar\n");
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Dinamik kütüphanelerin UNIX/Linux sistemlerinde dinamik yüklenmesi aslında Windows sistemlerindekine benzemektedir. İşlemler sırasıyla şöyle yürütülür:
	
	1) Önce dinamik kütüphane ldopen fonksiyonuyla adres alanına yüklenir. Yine bu fonksiyon yükleme adresine geri dönmektedir. Fonksiyonun prototipi şöyledir:

	 #include <dlfcn.h>

    void *dlopen(const char *filename, int flags);

	Fonksiyonun birinci parametresi yüklenecek so dosyasının yol ifadesini belirtir. Burada yol ifadesinde hiçbir '/' karakteri kullanılmazsa dosya 
	yukarıda belirtilen dizinlerde sırasıyla aranmaktadır. Ancak buradaki yol ifadesinde en az bir '/' kullanılırsa dosya yalnızca o yol  ifadesinde belirtilen 
	dizinde aranır. İkinci parametre sembol çözümlemesinin ne zaman yapılacağını belirtir. Bu parametre RTLD_LAZY ya da RTLD_NOW parametrelerinden biri biçiminde 
	girilebilir. RTLD_LAZY sembol çözümlemesinin başvuru sırasında yapılacağını RTLD_NOW ise yükleme sırasında yapılacağını belirtmektedir. Diğer değerler
	için dokümanalara başvurulabilir. Fonksiyon başarı durumunda yükleme adresine, başarısızlık durumunda NULL adrese geri döner. Başarısızlık nedeni için errno 
	değişkeni set edilmez. Başarısızlk nedeni yazısal olarak dlerror fonksiyonuyla elde edilmelidir. 


	2) dlsym fonksiyonuyla dinamik kütüpahane içerisindeki herhangi bir fonksiyon ya da nesnenin adresini elde edebiliriz. Fonksiyonun prototipi şöyledir:


 	#include <dlfcn.h>
	
	void *dlsym(void *handle, const char *symbol);

	Fonksiyonun birinci parametresi dlopen fonksiyonundan elde edilen adrestir. İkinci parametre adresi elde edilecek fonksiyon ya da global nesnenin ismini 
	belirtir. Fonksiyon başarı dıurumunda ilgili nesnenin adresine başarısızlık durumunda NULL adrese geri dönmektedir. C'de data adreslerinden 
	fonksiyon adreslerine, fonksiyon adreslerinden data adreslerine tür dönüştürme operatör ile bile dönüştürme tanımlı değildir. (Ancak derleyicilerin çoğu
	buna izin vermektedir.)

	3) Dinamik kütüphanenin kullanımı bittiğinde kütüphane dlclose fonksiyonuyla boşaltılır. 

	Aşağıdaki örneği şöyle derleyerek çalıştırınız:



-------------------------------------------------------------------------------------------------------------------------------------------*/

/* app.c */

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(void)
{
    void *dl;
    void (*foo)(void);
    void (*bar)(void);
    int *gx;

    if ((dl = dlopen("./myso.so",  RTLD_LAZY)) == NULL) {
        fprintf(stderr, "dlopen: %s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    if ((*(void **) &foo =  dlsym(dl, "foo")) == NULL) {
        fprintf(stderr, "dlsym: %s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    if ((*(void **) &bar =  dlsym(dl, "bar")) == NULL) {
        fprintf(stderr, "dlsym: %s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    if ((gx = (int *)dlsym(dl, "g_x")) == NULL) {
        fprintf(stderr, "dlsym: %s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    foo();
    bar();
    printf("%d\n", *gx);

    dlclose(dl);

    return 0;
}

/* myso.h */

#ifndef MYSO_H_
#define MYSO_H_

void foo(void);
void bar(void);

extern int g_x;

#endif

/* myso.c */

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(void)
{
    void *dl;
    void (*foo)(void);
    void (*bar)(void);
    int *gx;

    if ((dl = dlopen("./myso.so",  RTLD_LAZY)) == NULL) {
        fprintf(stderr, "dlopen: %s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    if ((*(void **) &foo =  dlsym(dl, "foo")) == NULL) {
        fprintf(stderr, "dlsym: %s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    if ((*(void **) &bar =  dlsym(dl, "bar")) == NULL) {
        fprintf(stderr, "dlsym: %s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    if ((gx = (int *)dlsym(dl, "g_x")) == NULL) {
        fprintf(stderr, "dlsym: %s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    foo();
    bar();
    printf("%d\n", *gx);

    dlclose(dl);

    return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Eskiden diskler elektromekanik bir birim olarak üretiliyordu. Bunlara "hard disk" denilmektedir. Ancak artık son 10 senedir elektromekanik 
	harddisk kullanımı oldukça azalmıştır. Artık SSD denilen tamamen yarıiletken EEPROM teknolojisiyle üretilen bellekler disk olarak kullanılmaktadır.
	İster hard disk olsun isterse SSD disk olsun bir diskten okunabilen ya da yazılabilen en küçük birime "sektör (sector)" denilmektedir. Yani örneğin biz diskten
	1 byte okumak istersek aslında bu byte'ın içinde bulunduğu sektörü okumak durumunda kalırız. Benzer biçimde diskte 1 byte değiştirmek için önce 
	onun bulunduğu sektörü okuruz. Değişikliği ana bellek üzerinde yaparız. Sonra o sektörü yeniden diske yazarız. Bir sektör 512 byte uzunluğundadır. 

	Diskteki sektörleri görüntülemek ve güncellemek için kullanılan araçlara "disk editörleri" denilmektedir. Windows, UNIX/Linux ve Mac OS X için 
	çeşitli disk editörleri bulunmaktadır. Windows için bedava en iyi seçeneklerden biri HxD isimli programdır. Linux'ta komut satırından görüntüleme 
	yapan od gibi hd gibi programlar kullanılmaktadır. İyi bir GUI seçenek de wxHexEditor isimli programdır. 

	Donanımsal olarak nasıl RAM'deki her byte'ın bir adresi varsa disk biriminde de her sektörün bir numarası vardır. Numaralandırma ilk sektör 0 olmak üzere
	artan sırada sayılarla yapılmaktadır. Sistem programcısı olarak bu alanda yapılacak ilk şey nasıl disk editörler sektörleri okuyup görüntüleyebiliyorsa 
	onların yaptığı gibi sektörleri okuyup yazabilmektir. Sektör okuyup yazabilmek için işletim sistemlerinde "aygıt sürücüler" bulundurulmuştur. Yani programcı 
	bu aygıt sürücüleri kullanarak sektör okuma yazma işlemlerini yapar. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	Windows'ta diski bir bütün olarak ele alan aygıt sürücünün ismi \\.\PhysicalDriveN ismindedir. Buradaki N değeri birinci  disk için 0, ikinci disk için 1
	biçiminde artan sırada bir sayı belirtmektedir. Disk disk bölümlerinden (disk partitions) oluşmaktadır. Bir disk bölümüne "manıksal sürücü (logical drive)" da
	denilmektedir. Disk bölümleri aslında bir diskin içerisindeki ardışıl N tane sektörden oluşmaktadır. Her disk bölümü kendi içerisinde sanki ayrı bir diskmiş gibi 
	davranabilmektedir. Bu biçimde disk bölümünü sanaki ayrı bir diskmiş gibi ele almak için \\.\X:" ismindeki aygıt sürücüler kullanılmaktadır.Burada X harfi sürücünün 
	harfini belirtmektedir. 

	Aşağıdaki örnekte Windows'ta aygıt sürücü kullanarak sektör okuması ve yazması yapan fonksiyonlar oluşturulmuştur. 
-------------------------------------------------------------------------------------------------------------------------------------------*/
/* DiskIO.h */

/* DiskIO.h */

#ifndef DISKIO_H_
#define DISKIO_H_

#include <Windows.h>

/* Symbolic Constants */

#define BYTES_PER_SECTOR		512

/* Function Prototypes */

HANDLE OpenDisk(int disk, DWORD dwDesiredAccess);
HANDLE OpenVolume(int drive, DWORD dwDesiredAccess);
BOOL ReadSector(HANDLE hDrive, long long sector, DWORD count, void *buf);
BOOL WriteSector(HANDLE hDrive, long long sector, DWORD count, const void *buf);

#endif

/* DiskIO.c */

#include <stdio.h>
#include <Windows.h>
#include "DiskIO.h"

/* static Function Prototypes */

static BOOL SetFilePosition(HANDLE hDrive, long long distance, DWORD MoveMethod);

/* Function definitions */

HANDLE OpenDisk(int disk, DWORD dwDesiredAccess)
{
	char driverName[32];
	DWORD shareMode = 0;

	sprintf(driverName, "\\\\.\\PhysicalDrive%d", disk);

	if (dwDesiredAccess & GENERIC_READ)
		shareMode |= FILE_SHARE_READ;
	if (dwDesiredAccess & GENERIC_WRITE)
		shareMode |= FILE_SHARE_WRITE;

	return CreateFile(driverName, dwDesiredAccess, shareMode, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
}

HANDLE OpenVolume(int drive, DWORD dwDesiredAccess)
{
	char driverName[32];
	DWORD shareMode = 0;

	sprintf(driverName, "\\\\.\\%c:", drive + 'A');

	if (dwDesiredAccess & GENERIC_READ)
		shareMode |= FILE_SHARE_READ;
	if (dwDesiredAccess & GENERIC_WRITE)
		shareMode |= FILE_SHARE_WRITE;

	return CreateFile(driverName, dwDesiredAccess, shareMode, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
}

BOOL ReadSector(HANDLE hDrive, long long sector, DWORD count, void *buf)
{
	long long location = (long long)sector * BYTES_PER_SECTOR;
	DWORD dwBytes = count * BYTES_PER_SECTOR;
	DWORD dwRead;

	if (!SetFilePosition(hDrive, location, FILE_BEGIN))
		return FALSE;

	if (!ReadFile(hDrive, buf, dwBytes, &dwRead, NULL))
		return FALSE;

	return TRUE;
}

BOOL WriteSector(HANDLE hDrive, __int64 sector, DWORD count, void *buf)
{
	long long location = (long long)sector * BYTES_PER_SECTOR;
	DWORD dwBytes = count * BYTES_PER_SECTOR;
	DWORD dwRead, status;

	if (!SetFilePosition(hDrive, location, FILE_BEGIN))
		return FALSE;

	if (!DeviceIoControl(hDrive, FSCTL_DISMOUNT_VOLUME, NULL, 0, NULL, 0, &status, NULL))
		return FALSE;

	if (!WriteFile(hDrive, buf, dwBytes, &dwRead, NULL))
		return FALSE;


	return TRUE;
}

static BOOL SetFilePosition(HANDLE hDrive, __int64 distance, DWORD MoveMethod)
{
	LARGE_INTEGER li;

	li.QuadPart = distance;
	li.LowPart = SetFilePointer(hDrive, li.LowPart, &li.HighPart, MoveMethod);

	if (li.LowPart == 0xFFFFFFFF && GetLastError() != NO_ERROR)
		return FALSE;

	return TRUE;
}

/* Test.c */

#include <stdio.h>
#include <windows.h>
#include "DiskIO.h"

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	HANDLE hDisk;
	HANDLE hVolume;
	unsigned char buf[BYTES_PER_SECTOR];
	int i;

	if ((hDisk = OpenDisk(1, GENERIC_READ)) == INVALID_HANDLE_VALUE)
		ExitSys("OpenDisk");

	if (!ReadSector(hDisk, 409966399, 1, buf)) 
		ExitSys("ReadSector");

	for (i = 0; i < 512; ++i)
		printf("%02X%c", buf[i], i % 16 == 15 ? '\n' : ' ');

	CloseHandle(hDisk);

	printf("-------------------------------------------------------\n");

	if ((hVolume = OpenVolume('H' - 'A', GENERIC_READ)) == INVALID_HANDLE_VALUE)
		ExitSys("OpenDisk");

	if (!ReadSector(hVolume, 0, 1, buf))
		ExitSys("ReadSector");

	for (i = 0; i < 512; ++i)
		printf("%02X%c", buf[i], i % 16 == 15 ? '\n' : ' ');

	CloseHandle(hVolume);

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Linux sistemlerinde yine disk sektörlerini okumak ve yazmak için aygıt sürücüler bulundurulmuştur. /dev/sda aygıt sürücüsü birinci diski bütün olarak
	temsil etmektedir. Bu diskteki disk bölümler /dev/sda1, /dev/sda2 vs. biçimindedir. Diskin bölüm yapısını görmekl için df komutunu ya da fdisk --list 
	komutunu kullanabilirsiniz. Yine bu aygıt sürücler open fonksiyonuyla açılıp lseek fonksiyonuyla konumlandırma yapılıp read ve write fonksiyonlarıyla okuma ve yazma 
	işlemlerine sokulabilmektedir. 

	Aşağıdaki  Linux sektör okumasına bir örnek verilmiştir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* diskio.h */

#ifndef DISKIO_H_
#define DISKIO_H_

/* Symbolic Constants */

#define BYTES_PER_SECTOR        512

/* Function Prototypes */

int read_sector(int fd, size_t sector, size_t count, void *buf);
int write_sector(int fd, size_t sector, size_t count, const void *buf);

#endif

/* diskio.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "diskio.h"

int read_sector(int fd, size_t sector, size_t count, void *buf)
{
	if (lseek(fd, sector * BYTES_PER_SECTOR, SEEK_SET) == -1)
		return -1;

	if (read(fd, buf, BYTES_PER_SECTOR * count) != BYTES_PER_SECTOR * count)
		return -1;

	return 0;
}

int write_sector(int fd, size_t sector, size_t count, const void *buf)
{
	if (lseek(fd, sector * BYTES_PER_SECTOR, SEEK_SET) == -1)
		return -1;

	if (write(fd, buf, BYTES_PER_SECTOR * count) != BYTES_PER_SECTOR * count)
		return -1;

	return 0;
}

/* app.c */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "diskio.h"

void exit_sys(const char *msg);

int main(void)
{
	int fd;
	unsigned char buf[BYTES_PER_SECTOR];
	int i;

	if ((fd = open("/dev/sda", O_RDONLY)) == -1)
		exit_sys("open");

	if (read_sector(fd, 24065464, 1, buf) == -1)
		exit_sys("read_sector");

	for (i = 0; i < BYTES_PER_SECTOR; ++i)
		printf("%02X%c", buf[i], i % 16 == 15 ? '\n' : ' ');

	close(fd);

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	FAT12 ve FAT16 sistemlerinde boot sektör içerisindeki BPB (Bios Parameter Block) bilgilerini boot sektörden okuyarak onu bir yapıya yerleştiren
	GetBPB isimli bir fonksiyon aşağıda verilmiştir. Buradaki BPB yapısında (A) ile belirtilen yapı elemanları doğrudan BPB'de karşılığı olan elemanlardır. 
	Yanında (A) olmayan elemanlar mevcut bilgilerden hareketle elde edilen bilgileri belirtir. Örneğin BPB alanın içerisinde doğrudan daata bölümünün
	hangi sektörden başladığı bilgisi yoktur. Ancak mevcut bilgilerden hareketle bu bilgi elde edilebilmektedir. GetBPB fonksiyonu sayesinde biz
	artık FAT12 ve FAT16 volümlerine ilişkin bütün bilgileri elde etmiş oluruz. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* FatSys.h */

#ifndef FATSYS_H_
#define FATSYS_H_

#include <Windows.h>

/* Symbolic contants */

#define FILE_INFO_LENGTH    32

/* Type Declaration */

typedef struct tagBPB {
	HANDLE hVolume;			/* volume */
	WORD fatLen;			/* number of sectors of FAT (A) */
	WORD rootLen;			/* number of sectors of ROOT */
	WORD fatCopyNum;		/* number of copies of FAT (A) */
	DWORD totalSec;			/* total sector (A) */
	WORD bps;				/* byte per sector(A) */
	WORD spc;				/* sector per cluster(A) */
	WORD reservedSect;		/* reserved sector(A) */
	BYTE medDes;			/* media descriptor byte(A) */
	WORD spt;				/* sector per track(A) */
	WORD rootEntryNum;		/* root entry(A) */
	WORD headNum;			/* number of heads(A) */
	WORD hidNum;			/* number of hidden sector(A)*/
	WORD tph;				/* track per head */
	WORD fatOrigin;			/* fat directory location */
	WORD rootOrigin;		/* root directory location */
	WORD dataOrigin;		/* first data sector location */
	DWORD serialNumber;		/* Volume Serial Number (A) */
	BYTE volumeName[12];    /* Volume Name (A) */
} BPB;

/* Function Prototypes */

BOOL GetBPB(HANDLE hVolume, BPB *pBPB);

#endif

/* FatSys.c */

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "DiskIo.h"
#include "FatSys.h"

BOOL GetBPB(HANDLE hVolume, BPB *pBPB)
{
	BYTE bootSect[BYTES_PER_SECTOR];

	if (!ReadSector(hVolume, 0, 1, bootSect))
		return FALSE;

	pBPB->hVolume = hVolume;
	pBPB->bps = *(WORD *)(bootSect + 0x0B);
	pBPB->spc = *(BYTE *)(bootSect + 0x0D);
	pBPB->reservedSect = *(WORD *)(bootSect + 0x0E);
	pBPB->fatLen = *(WORD *)(bootSect + 0x16);
	pBPB->rootLen = *(WORD *)(bootSect + 0x11) * FILE_INFO_LENGTH / pBPB->bps;
	pBPB->fatCopyNum = *(BYTE *)(bootSect + 0x10);
	if (*(WORD *)(bootSect + 0x13))
		pBPB->totalSec = *(WORD *)(bootSect + 0x13);
	else
		pBPB->totalSec = *(DWORD *)(bootSect + 0x20);
	pBPB->medDes = *(bootSect + 0x15);
	pBPB->spt = *(WORD *)(bootSect + 0x18);
	pBPB->rootEntryNum = *(WORD *)(bootSect + 0x11);
	pBPB->headNum = *(WORD *)(bootSect + 0x1A);
	pBPB->hidNum = *(WORD *)(bootSect + 0x1C);
	pBPB->tph = (WORD)(pBPB->totalSec / pBPB->spt / pBPB->headNum);
	pBPB->fatOrigin = pBPB->reservedSect;
	pBPB->rootOrigin = pBPB->reservedSect + pBPB->fatLen * pBPB->fatCopyNum;
	pBPB->dataOrigin = pBPB->rootOrigin + pBPB->rootLen;
	pBPB->serialNumber = *(DWORD *)(bootSect + 0x27);
	memcpy(pBPB->volumeName, bootSect + 0x2B, 11);
	pBPB->volumeName[11] = '\0';

	return TRUE;
}

/* Test.c */

#include <stdio.h>
#include <windows.h>
#include "DiskIO.h"
#include "FatSys.h"

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	HANDLE hVolume;
	BPB bpb;

	if ((hVolume = OpenVolume('H' - 'A', GENERIC_READ)) == INVALID_HANDLE_VALUE)
		ExitSys("OpenDisk");

	if (!GetBPB(hVolume, &bpb))
		ExitSys("GetBPB");

	printf("Success...\n");

	printf("Fat'in başlangıç sektör numarası: %u\n", bpb.fatOrigin);
	printf("Fat'in sektör uzunluğu: %u\n", bpb.fatLen);
	printf("Root Dir bölümünün başlangıç sektör numarası: %u\n", bpb.rootOrigin);
	printf("Root Dir bölümünün sektör uzunluğu: %u\n", bpb.rootLen);
	printf("Data bölümünün başlangıç sektör numarası: %u\n", bpb.dataOrigin);
	printf("Volümdeki toplam sektör sayısı: %lu\n", bpb.totalSec);
	printf("Bir cluster'ın kaç sektörden oluştuğu: %u\n", bpb.spc);

	CloseHandle(hVolume);

	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Boot Sektör BPB bilgileri okunduktan sonra artık bir cluster okuyan ve yazan fonksiyonlar yazılabilir. Data bölümünün ilk clusetr'ı 2'den başladığına göre
	okunacak cluster numarası clu olmak üzere bu cluster'ın bşlangıç sektör numarası bpb.dataOrigin + (clu - 2) * bpb.spc  ifadesi ile elde edilebilir. 
	O halde ReadClutser ve WriteCluster fonksiyonları şöyle yazılabilir.
-------------------------------------------------------------------------------------------------------------------------------------------*/

BOOL ReadCluster(const BPB *pBPB, WORD clu, void *pData)
{
	return ReadSector(pBPB->hVolume, pBPB->dataOrigin + (clu - 2) * pBPB->spc, pBPB->spc, pData);
}

BOOL WriteCluster(const BPB *pBPB, WORD clu, const void *pData)
{
	return WriteSector(pBPB->hVolume, pBPB->dataOrigin + (clu - 2) * pBPB->spc, pBPB->spc, pData);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Yukarıdaki işlemler UNIX/Linux sistemlerinde aşağıdaki gibi yapılabilir. Bu örnekte aygıt olarak /dev/loop0 kullanılmıştır. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* fatsys.h */

#ifndef FATSYS_H_
#define FATSYS_H_

#include <stdint.h>
#include <stdbool.h>

/* Symbolic contants */

#define FILE_INFO_LENGTH    32

/* Type Declaration */

typedef struct tagBPB {
	int volume;			        /* volume */
	uint16_t fatLen;		    /* number of sectors of FAT (A) */
	uint16_t rootLen;			/* number of sectors of ROOT */
	uint16_t fatCopyNum;		/* number of copies of FAT (A) */
	uint32_t totalSec;			/* total sector (A) */
	uint16_t bps;				/* byte per sector(A) */
	uint16_t spc;				/* sector per cluster(A) */
	uint16_t reservedSect;		/* reserved sector(A) */
	uint8_t medDes;			/* media descriptor byte(A) */
	uint16_t spt;				/* sector per track(A) */
	uint16_t rootEntryNum;		/* root entry(A) */
	uint16_t headNum;			/* number of heads(A) */
	uint16_t hidNum;			/* number of hidden sector(A)*/
	uint16_t tph;				/* track per head */
	uint16_t fatOrigin;			/* fat directory location */
	uint16_t rootOrigin;		/* root directory location */
	uint16_t dataOrigin;		/* first data sector location */
	uint32_t serialNumber;		/* Volume Serial Number (A) */
	uint8_t volumeName[12];    /* Volume Name (A) */
} BPB;

/* Function Prototypes */

bool get_bpb(int volume, BPB *bpb);
bool read_cluster(const BPB *bpb, uint16_t clu, void *data);

#endif

/* fatsys. c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "diskio.h"
#include "fatsys.h"

bool get_bpb(int volume, BPB *bpb)
{
	uint8_t bootSect[BYTES_PER_SECTOR];

	if (read_sector(volume, 0, 1, bootSect) == -1)
		return false;

	bpb->volume = volume;
	bpb->bps = *(uint16_t *)(bootSect + 0x0B);
	bpb->spc = *(uint8_t *)(bootSect + 0x0D);
	bpb->reservedSect = *(uint16_t *)(bootSect + 0x0E);
	bpb->fatLen = *(uint16_t *)(bootSect + 0x16);
	bpb->rootLen = *(uint16_t *)(bootSect + 0x11) * FILE_INFO_LENGTH / bpb->bps;
	bpb->fatCopyNum = *(uint8_t *)(bootSect + 0x10);
	if (*(uint16_t *)(bootSect + 0x13))
		bpb->totalSec = *(uint16_t *)(bootSect + 0x13);
	else
		bpb->totalSec = *(uint16_t *)(bootSect + 0x20);
	bpb->medDes = *(bootSect + 0x15);
	bpb->spt = *(uint16_t *)(bootSect + 0x18);
	bpb->rootEntryNum = *(uint16_t *)(bootSect + 0x11);
	bpb->headNum = *(uint16_t *)(bootSect + 0x1A);
	bpb->hidNum = *(uint16_t *)(bootSect + 0x1C);
	bpb->tph = (uint16_t)(bpb->totalSec / bpb->spt / bpb->headNum);
	bpb->fatOrigin = bpb->reservedSect;
	bpb->rootOrigin = bpb->reservedSect + bpb->fatLen * bpb->fatCopyNum;
	bpb->dataOrigin = bpb->rootOrigin + bpb->rootLen;
	bpb->serialNumber = *(uint32_t *)(bootSect + 0x27);
	memcpy(bpb->volumeName, bootSect + 0x2B, 11);
	bpb->volumeName[11] = '\0';

	return true;
}

bool read_cluster(const BPB *bpb, uint16_t clu, void *data)
{
	return read_sector(bpb->volume, bpb->dataOrigin + (clu - 2) * bpb->spc, bpb->spc, data) == 0;
}

bool write_cluster(const BPB *bpb, uint16_t clu, const void *data)
{
	return write_sector(bpb->volume, bpb->dataOrigin + (clu - 2) * bpb->spc, bpb->spc, data) == 0;
}

/* app.c */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include "diskio.h"
#include "fatsys.h"

void exit_sys(const char *msg);

int main(void)
{
	int volume;
	BPB bpb;
	uint8_t *buf;
	int i, k;

	if ((volume = open("/dev/loop0", O_RDONLY)) == -1)
		exit_sys("open");


	if (!get_bpb(volume, &bpb))
		exit_sys("getbpb");

	printf("Fat'in başlangıç sektör numarası: %u\n", bpb.fatOrigin);
	printf("Fat'in sektör uzunluğu: %u\n", bpb.fatLen);
	printf("Root Dir bölümünün başlangıç sektör numarası: %u\n", bpb.rootOrigin);
	printf("Root Dir bölümünün sektör uzunluğu: %u\n", bpb.rootLen);
	printf("Data bölümünün başlangıç sektör numarası: %u\n", bpb.dataOrigin);
	printf("Volümdeki toplam sektör sayısı: %u\n", bpb.totalSec);
	printf("Bir cluster'ın kaç sektörden oluştuğu: %u\n\n", bpb.spc);

	if ((buf = (uint8_t *)calloc(bpb.spc * bpb.bps, 1)) == NULL) {
		fprintf(stderr, "Cannot allocate memory!..\n");
		exit(EXIT_FAILURE);
	}

	if (!read_cluster(&bpb, 3, buf))
		exit_sys("WriteCluster");

	for (i = 0; i < 1024; ++i) {
		printf("%02X ", buf[i]);
		if (i % 16 == 15) {
			for (k = 0; k < 16; ++k)
				putchar(isalnum(buf[i - 15 + k]) ? buf[i - 15 + k] : '.');
			putchar('\n');
		}
	}

	free(buf);
	close(volume);

	return 0;
}

void exit_sys(const char *msg)
{
	perror(msg);

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	FAT bölümü bir bağlı liste biçimindedir. Bir dosyanın ilk clutser numarası 32!lik dizin girişlerinde tutulur. Sonra FAT zinciri izlenerek 
	dosyanın cluster zinciri elde edilir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/* fatsys.h */

#ifndef FATSYS_H_
#define FATSYS_H_

#include <Windows.h>

/* Symbolic contants */

#define FILE_INFO_LENGTH		32
#define MAX_CLUSTER_CHAIN		65536

/* Type Declaration */

typedef struct tagBPB {
	HANDLE hVolume;			/* volume */
	WORD fatLen;			/* number of sectors of FAT (A) */
	WORD rootLen;			/* number of sectors of ROOT */
	WORD fatCopyNum;		/* number of copies of FAT (A) */
	DWORD totalSec;			/* total sector (A) */
	WORD bps;				/* byte per sector(A) */
	WORD spc;				/* sector per cluster(A) */
	WORD reservedSect;		/* reserved sector(A) */
	BYTE medDes;			/* media descriptor byte(A) */
	WORD spt;				/* sector per track(A) */
	WORD rootEntryNum;		/* root entry(A) */
	WORD headNum;			/* number of heads(A) */
	WORD hidNum;			/* number of hidden sector(A)*/
	WORD tph;				/* track per head */
	WORD fatOrigin;			/* fat directory location */
	WORD rootOrigin;		/* root directory location */
	WORD dataOrigin;		/* first data sector location */
	DWORD serialNumber;		/* Volume Serial Number (A) */
	BYTE volumeName[12];    /* Volume Name (A) */
} BPB;

/* Function Prototypes */

BOOL GetBPB(HANDLE hVolume, BPB *pBPB);
BOOL ReadCluster(const BPB *pBPB, WORD clu, void *pData);
BOOL WriteCluster(const BPB *pBPB, WORD clu, const void *pData);
WORD *GetClusterChain16(BYTE *pFat, WORD firstCluster, WORD *pCount);
WORD *GetClusterChain12(BYTE *pFat, WORD firstCluster, WORD *pCount);

#endif

/* fatsys.c */

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "DiskIo.h"
#include "FatSys.h"

BOOL GetBPB(HANDLE hVolume, BPB *pBPB)
{
	BYTE bootSect[BYTES_PER_SECTOR];

	if (!ReadSector(hVolume, 0, 1, bootSect))
		return FALSE;

	pBPB->hVolume = hVolume;
	pBPB->bps = *(WORD *)(bootSect + 0x0B);
	pBPB->spc = *(BYTE *)(bootSect + 0x0D);
	pBPB->reservedSect = *(WORD *)(bootSect + 0x0E);
	pBPB->fatLen = *(WORD *)(bootSect + 0x16);
	pBPB->rootLen = *(WORD *)(bootSect + 0x11) * FILE_INFO_LENGTH / pBPB->bps;
	pBPB->fatCopyNum = *(BYTE *)(bootSect + 0x10);
	if (*(WORD *)(bootSect + 0x13))
		pBPB->totalSec = *(WORD *)(bootSect + 0x13);
	else
		pBPB->totalSec = *(DWORD *)(bootSect + 0x20);
	pBPB->medDes = *(bootSect + 0x15);
	pBPB->spt = *(WORD *)(bootSect + 0x18);
	pBPB->rootEntryNum = *(WORD *)(bootSect + 0x11);
	pBPB->headNum = *(WORD *)(bootSect + 0x1A);
	pBPB->hidNum = *(WORD *)(bootSect + 0x1C);
	pBPB->tph = (WORD)(pBPB->totalSec / pBPB->spt / pBPB->headNum);
	pBPB->fatOrigin = pBPB->reservedSect;
	pBPB->rootOrigin = pBPB->reservedSect + pBPB->fatLen * pBPB->fatCopyNum;
	pBPB->dataOrigin = pBPB->rootOrigin + pBPB->rootLen;
	pBPB->serialNumber = *(DWORD *)(bootSect + 0x27);
	memcpy(pBPB->volumeName, bootSect + 0x2B, 11);
	pBPB->volumeName[11] = '\0';

	return TRUE;
}

BOOL ReadCluster(const BPB *pBPB, WORD clu, void *pData)
{
	return ReadSector(pBPB->hVolume, pBPB->dataOrigin + (clu - 2) * pBPB->spc, pBPB->spc, pData);
}

BOOL WriteCluster(const BPB *pBPB, WORD clu, const void *pData)
{
	return WriteSector(pBPB->hVolume, pBPB->dataOrigin + (clu - 2) * pBPB->spc, pBPB->spc, pData);
}

WORD *GetClusterChain16(BYTE *pFat, WORD firstCluster, WORD *pCount)
{
	static WORD chain[MAX_CLUSTER_CHAIN];
	WORD cluster;
	int count;

	cluster = firstCluster;
	count = 0;
	
	while (cluster < 0xFFF8) {
		chain[count++] = cluster;
		cluster = *(WORD *)(pFat + cluster * 2);
	}

	*pCount = count;

	return chain;
}

WORD *GetClusterChain12(BYTE *pFat, WORD firstCluster, WORD *pCount)
{
	static WORD chain[MAX_CLUSTER_CHAIN];
	WORD cluster;
	int count;

	cluster = firstCluster;
	count = 0;

	while (cluster < 0xFF8) {
		chain[count++] = cluster;
		if (cluster % 2 == 0)
			cluster = *(WORD *)(pFat + cluster * 3 / 2) & 0x0FFF;
		else
			cluster = *(WORD *)(pFat + cluster * 3 / 2) >> 4;
	}

	*pCount = count;

	return chain;
}

/* app.c */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include "DiskIO.h"
#include "FatSys.h"

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	HANDLE hVolume;
	BPB bpb;
	BYTE *pFat;
	WORD *pClusterChain;
	WORD nclusters;
	int i;

	if ((hVolume = OpenVolume('H' - 'A', GENERIC_READ)) == INVALID_HANDLE_VALUE)
		ExitSys("OpenDisk");

	if (!GetBPB(hVolume, &bpb))
		ExitSys("GetBPB");

	printf("Fat'in başlangıç sektör numarası: %u\n", bpb.fatOrigin);
	printf("Fat'in sektör uzunluğu: %u\n", bpb.fatLen);
	printf("Root Dir bölümünün başlangıç sektör numarası: %u\n", bpb.rootOrigin);
	printf("Root Dir bölümünün sektör uzunluğu: %u\n", bpb.rootLen);
	printf("Data bölümünün başlangıç sektör numarası: %u\n", bpb.dataOrigin);
	printf("Volümdeki toplam sektör sayısı: %lu\n", bpb.totalSec);
	printf("Bir cluster'ın kaç sektörden oluştuğu: %u\n\n", bpb.spc);
	
	if ((pFat = (BYTE *)malloc(bpb.fatLen * bpb.bps)) == NULL) {
		fprintf(stderr, "Cannot allocate memory!..\n");
		exit(EXIT_FAILURE);
	}

	if (!ReadSector(hVolume, bpb.fatOrigin, bpb.fatLen, pFat)) 
		ExitSys("ReadSector");

	pClusterChain = GetClusterChain12(pFat, 10, &nclusters);
	for (i = 0; i < nclusters; ++i)
		printf("%d ", pClusterChain[i]);
	printf("\n");

	CloseHandle(hVolume);
	
	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastErr = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastErr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}

/*------------------------------------------------------------------------------------------------------------------------------------------
	Alt dizinler tamamen bir dosya gibi organize edilmektedir. Nasıl dosyaları oluşturan cluster'larda dosya bilgileri varsa dizinleri oluşturan cluster'larda da
	o dizin içerisindeki dosyalara ilişkin bilgiler vardır. Bir dosya bilgisi 32 byte uzunluğunda dizin girişlerinde saklanır. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	FAT12 ve FAT16 sistemlerinde FAT elemanları 12 bit 16 bit olduğu için bu dosya sistemleriyle formatlanacak diskin kapasitesi de oldukça sınırlıdır. 
	Bir cluster en fazla 64 sektör olabilmektedir. Bu nedenle FAT16 volümlerinin de maksimum kapasitesi 2GB olabilir. Microsoft FAT32 ile birlikte 
	FAT dosya sistemine şu eklemeleri yapmıştır:

	1) Boot sektör içerisindeki BPB alanını büyütmüştür.
	2) FAT elemanlarını 28 bite çıkartmiştır. Ancak FAT elemanları 32 bit yer kaplar yüksek anlamlı 4 bit kullanılmamaktadır. 
	3) Kök dizin alt dizinler gibi DATA bölümünün içerisine alınmıştır. Kök dizinin hangi cluster'dan başladığı da BPB içerisinde tutulmaktadır.
	Dolayısıyla kök dizin artık istenildiği kadar büyük olabilir. 

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	UNIX/Linux sistemlerinde kullanılan dosya sistemleri birbirlerinden farklı olabilse de bunlar bir aile olarak genel yapı bakımından birbirlerine
	benzemektedir. Bu aileye "I-Node Tabanlı Dosya Sistemleri" denilmektedir. Bugün bu ailenin en yaygın kullanılan dosya sistemleri ext-2, ext-3
	gibi sistemlerdir. Linux sistemleri ağırlıklı Ext-2 dosya sistemini kullanmaktadır. 

	I-Node Tabanlı dosya sistemlerinde volüm dört mantıksal bölüme ayrılmıştır:

	1) Boot Block
	2) Super Block
	3) I-Node Block
	4) Data Block

	Boot Block volümün ilk iki sektörünü oluşturur. 1024 byte uzunluktadır. Burada işletim sistemini yükleyen program kodu bulundurulur. Bu anlamda
	Boot Block FAT dosya sistemlerindeki Boot sektöre işlevsel olarak benzetilebilir. Boot bloğunu I-Node Block denilen yine 1024 byte uzunlukta olan
	Super Block izler. Super Block FAT dosya sistemindeki BPB bölümüne benzetilebilir. Dosya sistemin tüm parametrik bilgileri Super blokta tutulmaktadır.
	I-Node blok I-Node elemanlarından oluşmaktadır. Bir dosyanın bütün bilgileri i-node elemanında saklanmaktadır. Gerçekten de stat, fstat gibi fonksiyonlar
	dosya bilgilerini bu dosya için ayrılmış olan i-node elemanının içerisinden alırlar. Her dosya için I-Node Block içerisinde bir i-node elemanı bulunmaktadır. 
	I-Node bloktaki i-node elemanlarının ilk eleman 0 olmak üzere birer indeks numarası vardır. ls komutunda -i seçeneği dosyaların i-node numaralarını da göstermektedir. 
	Data Block FAT dosya sistemindeki Data Block ile aynı anlamdadır. Yani dosyaların parçalarının turulduğu en geniş mantıksal bölümdür. Ancak terminolojide 
	küçük farklılık vardır. Anımsanacağı gibi FAT dosya sistemlerinde dosyanın parçası olabilecek en küçük birime "cluster" deniyordu. Halbuki I-Node tabanlı dosya 
	sistemlerinde "cluster" sözcüğü yerine "block" sözcüğü kullanılmaktadır. Bir bloğun kaç byte'tan oluştuğu bilgisi Super blokta tutulmaktadır. Data Block içerisindeki
	her bloğa ilki 0 olmak üzere bir blok numarası karşı getirilmiştir. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------
	Ext-2 Dosya sistemi bazı ayrıntılar içeren I-Node tabanlı bir dosya sistemidir. Bu dosya sisteminde yine volümün ilk 1024 byte'ında 
	Boot Block bulunur. Onu yine 1024 byte uzunluğunda Super Block izler. Ancak Ext-2'de Super Bloğu I-Node Block izlemez. Çünkü Ext-2 adeta
	küçük bölümlerin toplamından oluşan bir dosya sistemi sunmaktadır. Bu bölümlere "Block Group" denilmektedir. Block Group'lar hakkında önemli bazı 
	bilgiler "Block Group Descriptor Table" isimli bir veri yapısında saklanır. Bu veri yapısı 1K blok yapısından oluşan volümlerde 3K (3072) sınırından, 
	1K'dan daha büyük blok yapısındna oluşan volümlerde 4K sınırından (4096) başlamaktadır.Block Group Descriptor Table denilen veri yapısı her biri 32 byte 
	uzunlupunda olan "Block Group Descriptor" denilen ve bir block group hakkında bilgi veren yapılardan oluşan bir dizidir. Örneğin volümümüzde
	üç block group varsa Block Group Descriptor Table'da her biri 32 byte'tan oluşan 3 tane Block Group Descriptor.

	Pekiyi Group Block'lar içerisinde ne vardır? İşte group block'ların başında Super Block'un ve Grooup Block Descriptor Table'ın birer kopyası bulunur. 
	Bu kopyalardan sonra DataBlcok Bitmap ve I-Node bitmap denilen iki bit tablosu bulunmaktadır. Bu bit tablolarından sonra da her block group için 
	I-Node Block ve Data Block bulunmaktadır. Görüldüğü gibi aslında ı_Node block ve Data Block volümde toplamda bir tane değildir. Her Block Group'ta 
	ayrı bir I-Node Block ve Data Block bulunmaktadır. 
-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------*/

