#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *kitapkayit,*kitapyedek1,*yazarkayit,*yazaryedek1,*yazarkitap,*yazarkitapyedek1;
struct kitapislemleri{
    char kitapkategori[50];
    char kitapkodu[20];
	char kitapadi[50];
	int kitapuygun;
	int kitapsayfa;
	int kitapbasim;
}kitap[20],yedek[20];

struct yazarislemleri{
    
    char yazarkodu[20];
    char yazaradi[50];
    char yazarsoyadi[50];
    int yazardogum;
    char yazarozgecmis[150];
}yazar[20],yazaryedek[20];

struct kitapyazarislemleri{
    int sira;
    char kitapkitapkodu[20];
    char yazaryazarkodu[20];
    
}kitapyazar2[20],kitapyazar2yedek[20];


void kitapyazar1(){
    int i;
    int sira;
    int istenensayi;
    int y;
    char istenenkitap[20];
    char istenenyazar[20];
   
    yazarkitap = fopen("yazarkitapkayitlari.txt","a+");
    if(yazarkitap==NULL){
        printf("Dosyaniz acilmadi");
        exit(1);
        
    }
     
    printf("Kac tane kitabin yazarini kaydetmek istiyorsanýz lutfen sayisini giriniz: \n");
    scanf("%d",&istenensayi);
    for(i=0; i<istenensayi; i++){
    	
    	 yazarkayit = fopen("yazarkayitlari.txt","r");
    kitapkayit = fopen("kitapkayitlari.txt","r");
    	y=0;   
     kitapyazar2[i].sira=i+1;
      
    printf("Lutfen yazarini kaydetmek istediginiz %d.kitabin kodunu giriniz : \n",i+1);
    scanf("%s",istenenkitap);
    
	 while(!feof(kitapkayit)){
		fscanf(kitapkayit," Kitap Kategorisi:%s \n Kitap Kodu:%s \n Kitap adi:%s \n Kitap sayfa sayisi:%d \n Uygun kitap sayisi:%d \n Basim yili:%d\n \n",kitap[y].kitapkategori,kitap[y].kitapkodu,kitap[y].kitapadi,&kitap[y].kitapsayfa,&kitap[y].kitapuygun,&kitap[y].kitapbasim);
		if(strcmp(istenenkitap,kitap[y].kitapkodu)==0){
		   strcpy(kitapyazar2[i].kitapkitapkodu,kitap[y].kitapkodu);
		    
		    
		}
		
            y++;    
	 }
	 fclose(kitapkayit);
	y=0;  
	
    printf("Lutfen %d.kitabin yazarinin kodunu giriniz : \n",i+1);
    scanf("%s",istenenyazar);
    
    	 while(!feof(yazarkayit)){
		fscanf(yazarkayit," Yazar Kodu:%s\n Yazar adi:%s\n Yazar soyadi:%s\n Dogum yili:%d\n Ozgecmisi:%s\n \n",yazar[y].yazarkodu,yazar[y].yazaradi,yazar[y].yazarsoyadi,&yazar[y].yazardogum,yazar[y].yazarozgecmis);
		if(strcmp(istenenyazar,yazar[y].yazarkodu)==0){
		  
		  		   strcpy(kitapyazar2[i].yazaryazarkodu,yazar[y].yazarkodu);
       
		}
		y++;
	 } 
	 fclose(yazarkayit);
    fprintf(yazarkitap," Sira no :%d Kitap Kodu:%s Yazar kodu: %s \n",kitapyazar2[i].sira,kitapyazar2[i].kitapkitapkodu,kitapyazar2[i].yazaryazarkodu);	 
    printf("\n");
	 }
    
    printf("Kitap ve yazar baþarýyla eþleþtirildi \n");
    fclose(yazarkitap);
    
    }
    
    
void YazarKayit(){
int x,y,a;
int istenilenkayitsayisi;

	yazarkayit=fopen("yazarkayitlari.txt","a+");
	if(yazarkayit == NULL){
  printf("Dosya acilamadi");
  exit(1);
 } 
	
    printf("Kac tane yazar kaydetmek istiyorsunuz\n");
	scanf("%d",&istenilenkayitsayisi);
	for(y=0;y<istenilenkayitsayisi;y++){
        
        printf("Kayýt edilen %d. yazar \n\n",y+1);
		printf("Yazarin kodunu giriniz:\n");
		scanf("%s",yazar[y].yazarkodu);
		printf("Yazarin adini giriniz:\n");
		scanf("%s",yazar[y].yazaradi);
		printf("Yazarin soyadini giriniz:\n");
		scanf("%s",yazar[y].yazarsoyadi);
		printf("Yazarým dogum yilini giriniz:\n");
		scanf("%d",&yazar[y].yazardogum);
		printf("Yazarin özgecmisini giriniz:\n");
		scanf("%s",yazar[y].yazarozgecmis);
		printf("\n");
fprintf(yazarkayit," Yazar Kodu:%s\n Yazar adi:%s\n Yazar soyadi:%s\n Dogum yili:%d\n Ozgecmisi:%s\n \n",yazar[y].yazarkodu,yazar[y].yazaradi,yazar[y].yazarsoyadi,yazar[y].yazardogum,yazar[y].yazarozgecmis);

	}
	fclose(yazarkayit);
    
}


void YazarListeleme(){
    int x;
	int y=0;
	yazarkayit=fopen("yazarkayitlari.txt","r");
	if(yazarkayit==NULL){
	    
	    printf("Listelencek yazar maalesef bulunamadi\n");
	    exit(1);
	}

	    while(!feof(yazarkayit)){
		fscanf(yazarkayit," Yazar Kodu:%s\n Yazar adi:%s\n Yazar soyadi:%s\n Dogum yili:%d\n Ozgecmisi:%s\n \n",yazar[y].yazarkodu,yazar[y].yazaradi,yazar[y].yazarsoyadi,&yazar[y].yazardogum,yazar[y].yazarozgecmis);
		printf("KAYDETTIGINIZ %d .YAZARIN BILGILERI ASAGIDADIR\n",y+1);
        printf("-------------------------------------------\n");
        printf("Yazarin kodu : %s\n",yazar[y].yazarkodu);
		printf("Yazarin adi : %s\n",yazar[y].yazaradi);
		printf("Yazarin soyadi : %s\n",yazar[y].yazarsoyadi);
		printf("Yazarin dogum yili : %d\n",yazar[y].yazardogum);
		printf("Yazarin özgecmisi: %s\n",yazar[y].yazarozgecmis);
		printf("\n");
		y++;
	    }

	fclose(yazarkayit);
    
}

void yazarArama(){
     
 char aranan[20];
 int durum=0;
 int y=0;
 
 printf("Aratmak istediðiniz yazarin adini giriniz: ");
 scanf("%s",aranan);
 yazarkayit=fopen("yazarkayitlari.txt","r");
 if( yazarkayit==NULL ){
  printf("Dosya acilamadi");
  exit(1);
 }
 
	 while(!feof(yazarkayit)){
		fscanf(yazarkayit," Yazar Kodu:%s\n Yazar adi:%s\n Yazar soyadi:%s\n Dogum yili:%d\n Ozgecmisi:%s\n \n",yazar[y].yazarkodu,yazar[y].yazaradi,yazar[y].yazarsoyadi,&yazar[y].yazardogum,yazar[y].yazarozgecmis);
		if(strcmp(aranan,yazar[y].yazaradi)==0){
			printf("%s %s %s %d %s\n",yazar[y].yazarkodu,yazar[y].yazaradi,yazar[y].yazarsoyadi,yazar[y].yazardogum,yazar[y].yazarozgecmis);
        durum=1;
        y++;
		}
	 }
 
  fclose(yazarkayit);
  if(durum == 0){ 
   printf(" Yazar Kayiti bulunamadi devam etmek icin bir tusa basiniz...\n");
  }
     
 }

void yazarGuncelleme(){
    int x;
int y=0;
int z;
 int numara,durum=0;
 char aranan[20];
 printf("\nGuncellemek istediginiz yazarin kodunu giriniz: ");
 scanf("%s",aranan);
 yazarkayit = fopen("yazarkayitlari.txt","r");
 yazaryedek1 = fopen("yazaryedek.txt","w");
 if(yazarkayit == NULL){
  printf("Dosya acilamadi");
  exit(1);
 } 
 
 while(!feof(yazarkayit)){
		fscanf(yazarkayit," Yazar Kodu:%s\n Yazar adi:%s\n Yazar soyadi:%s\n Dogum yili:%d\n Ozgecmisi:%s\n \n",yazar[y].yazarkodu,yazar[y].yazaradi,yazar[y].yazarsoyadi,&yazar[y].yazardogum,yazar[y].yazarozgecmis);
		if(strcmp(aranan,yazar[y].yazarkodu)!=0){
			fprintf(yazaryedek1," Yazar Kodu:%s\n Yazar adi:%s\n Yazar soyadi:%s\n Dogum yili:%d\n Ozgecmisi:%s\n \n",yazar[y].yazarkodu,yazar[y].yazaradi,yazar[y].yazarsoyadi,yazar[y].yazardogum,yazar[y].yazarozgecmis);
		}
		else {
			z=y;  //budeðiþikliliði unutma
		       fflush(stdin);
		 
		printf("Yazarin kodunu giriniz:\n");
		scanf("%s",yazar[y].yazarkodu);
		printf("Yazarin adini giriniz:\n");
		scanf("%s",yazar[y].yazaradi);
		printf("Yazarin soyadini giriniz:\n");
		scanf("%s",yazar[y].yazarsoyadi);
		printf("Yazarým dogum yilini giriniz:\n");
		scanf("%d",&yazar[y].yazardogum);
		printf("Yazarin özgecmisini giriniz:\n");
		scanf("%s",yazar[y].yazarozgecmis);
		printf("\n");
	fprintf(yazaryedek1," Yazar Kodu:%s\n Yazar adi:%s\n Yazar soyadi:%s\n Dogum yili:%d\n Ozgecmisi:%s\n \n",yazar[y].yazarkodu,yazar[y].yazaradi,yazar[y].yazarsoyadi,yazar[y].yazardogum,yazar[y].yazarozgecmis);
	durum = 1;
	y++;
		}
 }
 
 fclose(yazarkayit);
 fclose(yazaryedek1);
 if(durum == 1){ 
  remove("yazarkayitlari.txt");
  rename("yazaryedek.txt","yazarkayitlari.txt");
  printf("yazarin bilgileri guncellestirildi devam etmek icin bir tusa basin... \n");
  
  int durum2;
  
  
     yazarkayit = fopen("yazarkayitlari.txt","r");
    yazarkitapyedek1 = fopen("yazarkitapkayitlariyedek.txt","w");
    yazarkitap = fopen("yazarkitapkayitlari.txt","r");
    if(yazarkitap==NULL){
        printf("Dosyaniz acilmadi");
        exit(1);
        
    }
          
          
          while(!feof(yazarkayit)){
          	fscanf(yazarkayit," Yazar Kodu:%s\n Yazar adi:%s\n Yazar soyadi:%s\n Dogum yili:%d\n Ozgecmisi:%s\n \n",yazar[y].yazarkodu,yazar[y].yazaradi,yazar[y].yazarsoyadi,&yazar[y].yazardogum,yazar[y].yazarozgecmis);
          	y++;
		  }
    
    
    	 while(!feof(yazarkitap)){
		 fscanf(yazarkitap," Sira no :%d Kitap Kodu:%s Yazar kodu: %s ",&kitapyazar2[y].sira,kitapyazar2[y].kitapkitapkodu,kitapyazar2[y].yazaryazarkodu);
		 
		if(strcmp(aranan,kitapyazar2[y].yazaryazarkodu)!=0){
		   
		    fprintf(yazarkitapyedek1," Sira no :%d Kitap Kodu:%s Yazar kodu: %s \n",kitapyazar2[y].sira,kitapyazar2[y].kitapkitapkodu,kitapyazar2[y].yazaryazarkodu);
		    
		}
		    else { 
		            
		        
		        strcpy(kitapyazar2[y].yazaryazarkodu,yazar[z].yazarkodu);
		        fprintf(yazarkitapyedek1," Sira no :%d Kitap Kodu:%s Yazar kodu: %s \n",kitapyazar2[y].sira,kitapyazar2[y].kitapkitapkodu,kitapyazar2[y].yazaryazarkodu);
		        
		        y++;
		        durum2=1;
		        	        
		        
		    }
		}      
       
    
    fclose(yazarkayit);
    fclose(yazarkitapyedek1);
    fclose(yazarkitap);
    
    
    if(durum2==1){
         remove("yazarkitapkayitlari.txt");
  rename("yazarkitapkayitlariyedek.txt","yazarkitapkayitlari.txt");
        
    }
    else {
        remove("yazarkitapkayitlariyedek.txt");
        
    }
    
  
 }
 else{
  remove("yazaryedek.txt");
  printf("Ilgili yazar bulunamadi devam etmek icin bir tusa basin...\n");
 }
 
}

void yazarkayitSilme(){
    
   	int numara,durum=0;
	int istenilen;
	int y=0;
	int x;
	char aranan[20];
 printf("\n Sileceginiz yazarin kodunu giriniz: ");
 scanf("%s",aranan);
 printf("\n");
    yazarkayit = fopen("yazarkayitlari.txt","r");
    yazaryedek1 = fopen("yazaryedek.txt","w");
    if(yazarkayit == NULL){
    printf("Dosya acilamadi");
        exit(1);
    }

	 while(!feof(yazarkayit)){
		fscanf(yazarkayit," Yazar Kodu:%s\n Yazar adi:%s\n Yazar soyadi:%s\n Dogum yili:%d\n Ozgecmisi:%s\n \n",yazar[y].yazarkodu,yazar[y].yazaradi,yazar[y].yazarsoyadi,&yazar[y].yazardogum,yazar[y].yazarozgecmis);
		if(strcmp(aranan,yazar[y].yazarkodu)!=0){
			fprintf(yazaryedek1," Yazar Kodu:%s\n Yazar adi:%s\n Yazar soyadi:%s\n Dogum yili:%d\n Ozgecmisi:%s\n \n",yazar[y].yazarkodu,yazar[y].yazaradi,yazar[y].yazarsoyadi,yazar[y].yazardogum,yazar[y].yazarozgecmis);
		y++;	
		}
		
		else durum =1;
	 }

	fclose(yazarkayit);
	fclose(yazaryedek1);
	
	if(durum==1){
		
	remove("yazarkayitlari.txt");
	rename("yazaryedek.txt","yazarkayitlari.txt");
	printf("Silme iþlemi tamamlandi \n ");
	
	
	 int durum2;
  
  
    yazarkayit = fopen("yazarkayitlari.txt","r");
    yazarkitapyedek1 = fopen("yazarkitapkayitlariyedek.txt","w");
    yazarkitap = fopen("yazarkitapkayitlari.txt","r");
    if(yazarkitap==NULL){
        printf("Dosyaniz acilmadi");
        exit(1);
        
    }
    
    while(!feof(yazarkayit)){
          	fscanf(yazarkayit," Yazar Kodu:%s\n Yazar adi:%s\n Yazar soyadi:%s\n Dogum yili:%d\n Ozgecmisi:%s\n \n",yazar[y].yazarkodu,yazar[y].yazaradi,yazar[y].yazarsoyadi,&yazar[y].yazardogum,yazar[y].yazarozgecmis);
          	y++;
		  }
		  
		  
		  
		  while(!feof(yazarkitap)){
		 fscanf(yazarkitap," Sira no :%d Kitap Kodu:%s Yazar kodu: %s ",&kitapyazar2[y].sira,kitapyazar2[y].kitapkitapkodu,kitapyazar2[y].yazaryazarkodu);
		 
		if(strcmp(aranan,kitapyazar2[y].yazaryazarkodu)!=0){
		   
		    fprintf(yazarkitapyedek1," Sira no :%d Kitap Kodu:%s Yazar kodu: %s \n",kitapyazar2[y].sira,kitapyazar2[y].kitapkitapkodu,kitapyazar2[y].yazaryazarkodu);
	        y++;
		}
	    else {
	        durum2 =1;
	    }
	
		  }
	
	
	fclose(yazarkayit);
    fclose(yazarkitapyedek1);
    fclose(yazarkitap);
    
    
    if(durum2==1){
        
               remove("yazarkitapkayitlari.txt");
  rename("yazarkitapkayitlariyedek.txt","yazarkitapkayitlari.txt");
        
    }
    
    else {
        
        remove("yazarkitapkayitlariyedek.txt");
    }
	
	
		
	}
	
	else {
		remove("yazaryedek.txt");
		printf("%s adýnda yazar bulunamadý \n",aranan);
	}
	
	
}

void KitapKayit(){

int sayisi,x,y,a;
int istenilenkayitsayisi;
int i;
	kitapkayit=fopen("kitapkayitlari.txt","a+");
	if(kitapkayit == NULL){
  printf("Dosya acilamadi");
  exit(1);
 } 
	
    printf("kaç kitap kaydetmek istiyorsunuz\n");
	scanf("%d",&istenilenkayitsayisi);
	for(y=0;y<istenilenkayitsayisi;y++){

 for (a=0;a<99;a++) {
		printf("Lutfen Kitabin kategorisini giriniz:\n");
		printf("Roman icin = 1\n Masal icin=2\n Siir icin =3\n ");
		scanf("%d",&x);
		if (0<x && x<4) break;
	    else
	  printf("Lutfen gecerli bir kategori giriniz:\n\n");

 }
		if(x==1)
		strcpy(kitap[y].kitapkategori,"Roman"); 
		else if (x==2)
	    strcpy(kitap[y].kitapkategori,"Masal");
		else if (x==3)
	    strcpy(kitap[y].kitapkategori,"Siir");
	    else
	    printf("Lütfen geçerli bir kategori giriniz!");

		printf("Kitabin kodunu giriniz:\n");
		scanf("%s",kitap[y].kitapkodu);
		printf("Kitabin adini giriniz:\n");
		scanf("%s",kitap[y].kitapadi);
		printf("Kitabin sayfa sayisini giriniz:\n");
		scanf("%d",&kitap[y].kitapsayfa);
		printf("Uygun Kitap sayisini giriniz:\n");
		scanf("%d",&kitap[y].kitapuygun);
		printf("Kitabin basim yilini giriniz:\n");
		scanf("%d",&kitap[y].kitapbasim);
		printf("\n \n");

fprintf(kitapkayit," Kitap Kategorisi:%s \n Kitap Kodu:%s \n Kitap adi:%s \n Kitap sayfa sayisi:%d \n Uygun kitap sayisi:%d \n Basim yili:%d\n \n",kitap[y].kitapkategori,kitap[y].kitapkodu,kitap[y].kitapadi,kitap[y].kitapsayfa,kitap[y].kitapuygun,kitap[y].kitapbasim);
       printf("\n ");
	}
	fclose(kitapkayit);
}

void kitapGuncelleme(){
int x;
int y=0;
int z;
int istenilen;
 int numara,durum=0;
 char aranan[20];
 printf("\nGuncellemek istediginiz kitabin kodunu giriniz: ");
 scanf("%s",aranan);
 kitapkayit = fopen("kitapkayitlari.txt","r");
 kitapyedek1 = fopen("yedek.txt","w");
 if(kitapkayit == NULL){
  printf("Dosya acilamadi");
  exit(1);
 } 
 
 while(!feof(kitapkayit)){
		fscanf(kitapkayit," Kitap Kategorisi:%s \n Kitap Kodu:%s \n Kitap adi:%s \n Kitap sayfa sayisi:%d \n Uygun kitap sayisi:%d \n Basim yili:%d\n \n",kitap[y].kitapkategori,kitap[y].kitapkodu,kitap[y].kitapadi,&kitap[y].kitapsayfa,&kitap[y].kitapuygun,&kitap[y].kitapbasim);
		if(strcmp(aranan,kitap[y].kitapkodu)!=0){
			fprintf(kitapyedek1," Kitap Kategorisi:%s \n Kitap Kodu:%s \n Kitap adi:%s \n Kitap sayfa sayisi:%d \n Uygun kitap sayisi:%d \n Basim yili:%d\n \n",kitap[y].kitapkategori,kitap[y].kitapkodu,kitap[y].kitapadi,kitap[y].kitapsayfa,kitap[y].kitapuygun,kitap[y].kitapbasim);
		}
		else {
		       fflush(stdin);
		       z=y;
		       
		printf("Lutfen güncellemek  istediginiz Kitabin kategorisini giriniz:\n");
		printf("Roman icin = 1\n Masal icin=2\n Siir icin =3\n ");
		scanf("%d",&x);
 
		if(x==1)
		strcpy(kitap[y].kitapkategori,"Roman"); 
		else if (x==2)
	    strcpy(kitap[y].kitapkategori,"Masal");
		else if (x==3)
	    strcpy(kitap[y].kitapkategori,"Siir");
	    
		printf("Kitabin kodunu giriniz:\n");
		scanf("%s",kitap[y].kitapkodu);
		printf("Kitabin adini giriniz:\n");
		scanf("%s",kitap[y].kitapadi);
		printf("Kitabin sayfa sayisini giriniz:\n");
		scanf("%d",&kitap[y].kitapsayfa);
		printf("Uygun Kitap sayisini giriniz:\n");
		scanf("%d",&kitap[y].kitapuygun);
		printf("Kitabin basim yilini giriniz:\n");
		scanf("%d",&kitap[y].kitapbasim);
	fprintf(kitapyedek1," Kitap Kategorisi:%s \n Kitap Kodu:%s \n Kitap adi:%s \n Kitap sayfa sayisi:%d \n Uygun kitap sayisi:%d \n Basim yili:%d\n \n",kitap[y].kitapkategori,kitap[y].kitapkodu,kitap[y].kitapadi,kitap[y].kitapsayfa,kitap[y].kitapuygun,kitap[y].kitapbasim);
	durum = 1;
	y++;
		}
 }
 fclose(kitapkayit);
 fclose(kitapyedek1);
 if(durum == 1){ 
  remove("kitapkayitlari.txt");
  rename("yedek.txt","kitapkayitlari.txt");
  printf("kitap bilgileri guncellestirildi devam etmek icin bir tusa basin... \n");
  
  
  int durum2;
    
    kitapkayit = fopen("kitapkayitlari.txt","r");
    yazarkitapyedek1 = fopen("yazarkitapkayitlariyedek.txt","w");
    yazarkitap = fopen("yazarkitapkayitlari.txt","r");
    if(yazarkitap==NULL){
        printf("Dosyaniz acilmadi");
        exit(1);
        
    }      
    
    
    while(!feof(kitapkayit)){
    	
    	
    	fscanf(kitapkayit," Kitap Kategorisi:%s \n Kitap Kodu:%s \n Kitap adi:%s \n Kitap sayfa sayisi:%d \n Uygun kitap sayisi:%d \n Basim yili:%d\n \n",kitap[y].kitapkategori,kitap[y].kitapkodu,kitap[y].kitapadi,&kitap[y].kitapsayfa,&kitap[y].kitapuygun,&kitap[y].kitapbasim);
    	
    	y++;
	}
    
    y=0;
    
    
    
    
    	 while(!feof(yazarkitap)){
		 fscanf(yazarkitap," Sira no :%d Kitap Kodu:%s Yazar kodu: %s ",&kitapyazar2[y].sira,kitapyazar2[y].kitapkitapkodu,kitapyazar2[y].yazaryazarkodu);
		 
		if(strcmp(aranan,kitapyazar2[y].kitapkitapkodu)!=0){
		   
		    fprintf(yazarkitapyedek1," Sira no :%d Kitap Kodu:%s Yazar kodu: %s \n",kitapyazar2[y].sira,kitapyazar2[y].kitapkitapkodu,kitapyazar2[y].yazaryazarkodu);
		    
		}
		    else { 
		            
		        
		        strcpy(kitapyazar2[y].kitapkitapkodu,kitap[z].kitapkodu);
		        fprintf(yazarkitapyedek1," Sira no :%d Kitap Kodu:%s Yazar kodu: %s \n",kitapyazar2[y].sira,kitapyazar2[y].kitapkitapkodu,kitapyazar2[y].yazaryazarkodu);
		        
		        y++;
		        durum2=1;
		        
		        
		    }
		
               
	 }
    
    fclose(kitapkayit);
    fclose(yazarkitapyedek1);
    fclose(yazarkitap);
    
    
    if(durum2==1){
         remove("yazarkitapkayitlari.txt");
  rename("yazarkitapkayitlariyedek.txt","yazarkitapkayitlari.txt");
        
    }
    else {
        remove("yazarkitapkayitlariyedek.txt");
        
    }
    
 }
 else{
  remove("yedek.txt");
  printf("Ilgili kitap bulunamadi devam etmek icin bir tusa basin...\n");
 }
 



}

void kitapArama(){ 
    int istenilen;
 char aranan[20];
 int durum=0;
 int y=0;
 fflush(stdin);
 printf("Aratmak istediðiniz kitabýn adini giriniz: ");
 scanf("%s",aranan);
 kitapkayit=fopen("kitapkayitlari.txt","r");
 if( kitapkayit==NULL ){
  printf("Dosya acilamadi");
  exit(1);
 }
 
	 while(!feof(kitapkayit)){
		fscanf(kitapkayit," Kitap Kategorisi:%s \n Kitap Kodu:%s \n Kitap adi:%s \n Kitap sayfa sayisi:%d \n Uygun kitap sayisi:%d \n Basim yili:%d\n \n",kitap[y].kitapkategori,kitap[y].kitapkodu,kitap[y].kitapadi,&kitap[y].kitapsayfa,&kitap[y].kitapuygun,&kitap[y].kitapbasim);
		if(strcmp(aranan,kitap[y].kitapadi)==0){
			printf("%s %s %s %d %d %d\n",kitap[y].kitapkategori,kitap[y].kitapkodu,kitap[y].kitapadi,kitap[y].kitapsayfa,kitap[y].kitapuygun,kitap[y].kitapbasim);
        durum=1;
        y++;
		}
	 }
	
  fclose(kitapkayit);
  if(durum == 0){ 
   printf("Kayit bulunamadi devam etmek icin bir tusa basiniz...\n");
  }
 
}


void KitapListele(){
	
	int i,x;
	int y=0;
	int istenilen;
	kitapkayit=fopen("kitapkayitlari.txt","r");
	if(kitapkayit==NULL){
	    
	    printf("Listelencek kitap maalesef yoktur\n");
	    exit(1);
	}
	
	    while(!feof(kitapkayit)){
		fscanf(kitapkayit," Kitap Kategorisi:%s \n Kitap Kodu:%s \n Kitap adi:%s \n Kitap sayfa sayisi:%d \n Uygun kitap sayisi:%d \n Basim yili:%d\n \n",kitap[y].kitapkategori,kitap[y].kitapkodu,kitap[y].kitapadi,&kitap[y].kitapsayfa,&kitap[y].kitapuygun,&kitap[y].kitapbasim);
		printf("KAYDETTIGINIZ %d .KITABIN BILGILERI ASAGIDADIR\n",y+1);
        printf("-------------------------------------------\n");
        printf("Kitabin kategorisi : %s\n",kitap[y].kitapkategori);
		printf("Kitabin kodu : %s\n",kitap[y].kitapkodu);
		printf("Kitabin adi : %s\n",kitap[y].kitapadi);
		printf("Kitabin sayfa sayisi : %d\n",kitap[y].kitapsayfa);
		printf("Uygun Kitap sayisi : %d\n",kitap[y].kitapuygun);
		printf("Kitabin basim yili: %d\n",kitap[y].kitapbasim);
		
		printf("\n");
		y++;
	    }


	fclose(kitapkayit);
	}

void kitapkayitSilme(){
	int numara,durum=0;
	int istenilen;
	int y=0;
	int x;
	char aranan[20];
 printf("\n Sileceginiz kitapin kodunu giriniz: ");
 scanf("%s",aranan);
 printf("\n");
    kitapkayit = fopen("kitapkayitlari.txt","r");
    kitapyedek1 = fopen("yedek.txt","w");
    if(kitapkayit == NULL){
    printf("Dosya acilamadi");
        exit(1);
    }
	
	 while(!feof(kitapkayit)){
		fscanf(kitapkayit," Kitap Kategorisi:%s \n Kitap Kodu:%s \n Kitap adi:%s \n Kitap sayfa sayisi:%d \n Uygun kitap sayisi:%d \n Basim yili:%d\n \n",kitap[y].kitapkategori,kitap[y].kitapkodu,kitap[y].kitapadi,&kitap[y].kitapsayfa,&kitap[y].kitapuygun,&kitap[y].kitapbasim);
	    if(strcmp(aranan,kitap[y].kitapkodu)!=0){
			fprintf(kitapyedek1," Kitap Kategorisi:%s \n Kitap Kodu:%s \n Kitap adi:%s \n Kitap sayfa sayisi:%d \n Uygun kitap sayisi:%d \n Basim yili:%d\n \n",kitap[y].kitapkategori,kitap[y].kitapkodu,kitap[y].kitapadi,kitap[y].kitapsayfa,kitap[y].kitapuygun,kitap[y].kitapbasim);
		y++;	
		}
		
		else durum =1;
	 }

	 
	fclose(kitapkayit);
	fclose(kitapyedek1);
	
	
	if(durum==1){
		
	remove("kitapkayitlari.txt");
	rename("yedek.txt","kitapkayitlari.txt");
	printf("Silme islemi tamamlandi \n ");
	printf("\n");
	printf("--------------------------------- \n");
	
	
	
	  int durum2;
    
    kitapkayit = fopen("kitapkayitlari.txt","r");
    yazarkitapyedek1 = fopen("yazarkitapkayitlariyedek.txt","w");
    yazarkitap = fopen("yazarkitapkayitlari.txt","r");
    if(yazarkitap==NULL){
        printf("Dosyaniz acilmadi");
        exit(1);
        
    }      
    
    
    while(!feof(kitapkayit)){
    	
    	
    	fscanf(kitapkayit," Kitap Kategorisi:%s \n Kitap Kodu:%s \n Kitap adi:%s \n Kitap sayfa sayisi:%d \n Uygun kitap sayisi:%d \n Basim yili:%d\n \n",kitap[y].kitapkategori,kitap[y].kitapkodu,kitap[y].kitapadi,&kitap[y].kitapsayfa,&kitap[y].kitapuygun,&kitap[y].kitapbasim);
    	
    	y++;
	}
    
    
    
    y=0;
    
    while(!feof(yazarkitap)){
		 fscanf(yazarkitap," Sira no :%d Kitap Kodu:%s Yazar kodu: %s ",&kitapyazar2[y].sira,kitapyazar2[y].kitapkitapkodu,kitapyazar2[y].yazaryazarkodu);
		 
		if(strcmp(aranan,kitapyazar2[y].kitapkitapkodu)!=0){
		   
		    fprintf(yazarkitapyedek1," Sira no :%d Kitap Kodu:%s Yazar kodu: %s \n",kitapyazar2[y].sira,kitapyazar2[y].kitapkitapkodu,kitapyazar2[y].yazaryazarkodu);
            y++;
		}
		else durum2=1;
	
    }
    
    fclose(kitapkayit);
    fclose(yazarkitapyedek1);
    fclose(yazarkitap);
    
    if(durum2==1){
        remove("yazarkitapkayitlari.txt");
  rename("yazarkitapkayitlariyedek.txt","yazarkitapkayitlari.txt");
    }
	
	else{
	    
	    remove("yazarkitapkayitlariyedek.txt");
	}
	
		
	}
	
	else {
		remove("yedek.txt");
		printf("%s adýnda kitap bulunamadý \n",aranan);
		
		
		
	}
	
	
}

int main() {
    
    
    int secim1;
    while ( secim1 != 3 ){
	int secim2 = 0;
    printf("KUTUPHANE ENVANTER OTOMASYONU SISTEMINE HOSGELDINIZ\n");
    printf("---------------------------------------------------\n");
    printf("Lutfen yapmak istediginiz islemi tiklayiniz\n");
    printf("1-)Kitap islemleri\n2-)Yazar islemleri \n3-)Cikis\n");
    printf("-> ");
    scanf("%d",&secim1);
    printf("\n  ");
    
    printf("\n\n");
    if(secim1==1){
        while(secim2 != 7){
            
    printf("KITAP ISLEMLERI MENUSU \n");
    printf("----------------------\n");
	printf(" --> Kitap kayit etmek icin 1 e basiniz\n");
	printf(" --> Kitaplari listelemek icin 2 e basiniz\n");
	printf(" --> Kitap aratmak icin 3 e basiniz\n");
	printf(" --> Kitaplari guncellemek icin 4 e basiniz\n");
	printf(" --> Kitap silmek icin 5 e basiniz\n");
	printf(" --> Kitaplara yazar eklemek 6 ya basiniz\n");
	printf(" --> Cikis icin 7 ye basin\n");
	printf(" -> ");
	scanf("%d",&secim2);
	printf("\n");
	if(secim2 == 1){
		KitapKayit();
	}
	else if (secim2 ==2) {
		KitapListele();
	}
else if (secim2 ==3) {
		kitapArama();
	}
else if (secim2 ==4) {
		kitapGuncelleme();
	}
else if (secim2 ==5) {
		kitapkayitSilme();
	}
	else if (secim2 ==6) {
		 kitapyazar1();
    }
    }
    }
        else if (secim1==2){
        while(secim2 != 6){
            
    printf("YAZAR ISLEMLERI MENUSU \n");
    printf("----------------------\n");
	printf(" --> Yazar kayit etmek icin 1 e basiniz\n");
	printf(" --> Yazarlari listelemek icin 2 e basiniz\n");
	printf(" --> Yazar aratmak icin 3 e basiniz\n");
	printf(" --> Yazar guncellemek icin 4 e basiniz\n");
	printf(" --> Yazar silmek icin 5 e basiniz\n");
	printf(" --> Cikis icin 6 ya basiniz\n");
	printf(" -> ");
	scanf("%d",&secim2);
	printf("\n");
	if(secim2 == 1){
		YazarKayit();
	}
	else if (secim2 ==2) {
	YazarListeleme();
	}
else if (secim2 ==3) {
	yazarArama();
	}
else if (secim2 ==4) {
		yazarGuncelleme();
	}
else if (secim2 ==5) {
		yazarkayitSilme();
	}

    }
        
    }
  


    }
    
    printf("***Developed by Ali Berke Kara");
    
	return 0;
}

