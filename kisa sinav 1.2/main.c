#include <stdio.h>
#include <stdlib.h>

//�ncelikle bizden istenilenin sezar �ifreleme oldu�unun fark�na vard�m. Ve sezar �ifreleme fonksiyonunu yaz�yoruz. 
void sezarSifreleme(char metin[],int anahtar) {
 	
 	for (int i=0; metin[i] != '\0'; ++i) {
 		//her seferinde metin dizisinden bir karaketer al�n�r//
 		char karakter=metin[i];
 		//burada karakterin asc�� de�eri kontrol edilir ve e�er karakter alfabetik ise �ifreleme yap�l�r e�er de�ilse �ifreleme yap�lmaz.//
 		if (karakter >= 'a' && karakter <= 'z'){
 			
 			metin[i] = 'a' +(karakter -'a'+anahtar)%26;
 			// k���k harfler i�in e�er blo�u �al��t�r�l�r. �rnek a harfinin asc�� de�eri bulunur. Ard�ndan anahtar eklenir ve 26ya b�l�n�r.Sonu� a harfinin 
 			// yerine ge�ecek asc�� de�erini verir. (ayr�ca 26ya b�l�nmesinin sebebi 26 tane harf olmas�ndan kaynakl�d�r.)
		 }
 		
 		else if (karakter >= 'A' && karakter <= 'Z') {
 			
 			metin[i]='A'+(karakter-'A' + anahtar)%26;
 			// bu da b�y�k harfler i�in 
		 }
 		
 		
	 }
 	
 }
      
	void sezarDesifreleme(char metin[], int anahtar) {
		
		sezarSifreleme(metin, 26-anahtar);
		// sezar �ifreleme fonksiyonunun de�ifre etmek i�in kullan�l�r. 26ya mod al�nd��� i�in 26 - anahtar yani anahtar�n tersini vermektedir
	}
	
int main() {
		
		char metin[100];
		
		int anahtar;
		
		// kullan�c�dan verileri girmesini isteyerek �ifreleme ve de�ifreleme i�lemlerinin yap�lmas�n� ve kullan�c�ya ��kt� olarak g�stermesini sa�l�yoruz.
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
