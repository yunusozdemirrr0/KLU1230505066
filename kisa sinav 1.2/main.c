#include <stdio.h>
#include <stdlib.h>

//Öncelikle bizden istenilenin sezar şifreleme olduğunun farkına vardım. Ve sezar şifreleme fonksiyonunu yazıyoruz. 
void sezarSifreleme(char metin[],int anahtar) {
 	
 	for (int i=0; metin[i] != '\0'; ++i) {
 		//her seferinde metin dizisinden bir karaketer alınır//
 		char karakter=metin[i];
 		//burada karakterin ascıı değeri kontrol edilir ve eğer karakter alfabetik ise şifreleme yapılır eğer değilse şifreleme yapılmaz.//
 		if (karakter >= 'a' && karakter <= 'z'){
 			
 			metin[i] = 'a' +(karakter -'a'+anahtar)%26;
 			// küçük harfler için eğer bloğu çalıştırılır. örnek a harfinin ascıı değeri bulunur. Ardından anahtar eklenir ve 26ya bölünür.Sonuç a harfinin 
 			// yerine geçecek ascıı değerini verir. (ayrıca 26ya bölünmesinin sebebi 26 tane harf olmasından kaynaklıdır.)
		 }
 		
 		else if (karakter >= 'A' && karakter <= 'Z') {
 			
 			metin[i]='A'+(karakter-'A' + anahtar)%26;
 			// bu da büyük harfler için 
		 }
 		
 		
	 }
 	
 }
      
	void sezarDesifreleme(char metin[], int anahtar) {
		
		sezarSifreleme(metin, 26-anahtar);
		// sezar şifreleme fonksiyonunun deşifre etmek için kullanılır. 26ya mod alındığı için 26 - anahtar yani anahtarın tersini vermektedir
	}
	
int main() {
		
		char metin[100];
		
		int anahtar;
		
		// kullanıcıdan verileri girmesini isteyerek şifreleme ve deşifreleme işlemlerinin yapılmasını ve kullanıcıya çıktı olarak göstermesini sağlıyoruz.
		printf("lutfen metni giriniz:");
		
		fgets(metin,sizeof(metin),stdin); 
		printf("lutfen anahtari giriniz:");
		scanf("%d",&anahtar);
		
		
		sezarSifreleme(metin,anahtar);
		
		printf("sifrelenmis metin: %s",metin);
		
		sezarDesifreleme(metin,anahtar);
		
		printf("\ndesifre edilmis metin:%s",metin);
	
	
	
	
	
	
	
	
	
	
	return 0;
}
