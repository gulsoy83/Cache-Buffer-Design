#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
static int capacity,esik;

struct tamponbellek {
    struct tamponbellek	*previous;
    struct tamponbellek	*next;
    int sayac;
    char adres[SIZE];
};

typedef struct tamponbellek BUFFR;

static BUFFR *head,*last;


//fonksiyon aliasingleri

int kapasite();
void girdiisle(char *);
void yazdir();

BUFFR* create_el();
void listeninbasinabagla(BUFFR*);
void listeninsonunabagla(BUFFR*);
void listeninbasindansil();
void listeninsonundansil();
void sunusil(BUFFR*);



int main() {
    int secim1,masterflag=1,secim2;
	int clear=1;
	
	FILE *fp;
    char finput[SIZE],c;   
	char input[SIZE];
	
	printf("Buffer Programi.\n");  
    
	printf("\nDosyadan okuma icin 1,klavyeden giris icin 2 girin.\n\n");
    scanf("%d",&secim1);
    fflush(stdin);
    
	while(masterflag){
	  
        switch (secim1){
    	
		case 1:
		fp=fopen("input.txt","r");
		if (fp==NULL){
		    printf("Dosya acilamadi. Dosyanizin ismi input.txt olmalidir.\n");
			exit(0);	
		}
		
		fscanf(fp,"%c",&c);
		if (c!='T'){
			printf("Dosyaniz hatali hazirlanmis.\n");
			exit(0);
		}
		
	    
		fscanf(fp,"%c",&c);
		if (c!='='){
			printf("Dosyaniz hatali hazirlanmis.\n");
			exit(0);
		}
	    
		
		fscanf(fp,"%d",&esik);
		
		fscanf(fp,"%c",&c);
		if (c!=','){
			printf("Dosyaniz hatali hazirlanmis.\n");
			exit(0);
		}
		fscanf(fp,"%c",&c);  //Bosluk karakterini atlariz.
		
		fscanf(fp,"%c",&c);
 	    if (c!='L'){
			printf("Dosyaniz hatali hazirlanmis.\n");
			exit(0);
		}
		
		
		fscanf(fp,"%c",&c);
		if (c!='='){
			printf("Dosyaniz hatali hazirlanmis.\n");
			exit(0);
		}
		
		fscanf(fp,"%d",&capacity);
		printf("\nEsik: %d\t Kapasite: %d\n\n",esik,capacity);
		
		while (fscanf(fp,"%s",finput)!=EOF){
		    girdiisle(finput);
		    yazdir();
		}
		    girdiisle(finput);
		    yazdir();
    	
		printf("\n\nGirdiler islendi. Buffer'in final hali:\n");
		yazdir();
    	fclose(fp);
    	masterflag=0;
    	break;
    	
		case 2:
			printf("\nBuffer'i doldurmak icin 1 girin. Buffer icerigi icin 3 girin.\nCikmak icin 0 girin.\n\n");
			scanf("%d",&secim2);
			fflush(stdin);
			
			switch(secim2){
		        case 0:
    	        system("@cls||clear");
		        printf("\nGule gule.\n");
    	        masterflag=0;	
       	        break;
			
			    case 1:
			    if (head==NULL){
	                printf("Buffer su anda bos. Lutfen parametreleri giriniz.\n");
					printf("Buffer kapasitesini girin.\n");
	                scanf("%d",&capacity);
	                fflush(stdin);
 	                printf("Sayac esik degerini girin.\n");
                    scanf("%d",&esik);
	                fflush(stdin);
                }  	
    	        printf("Eleman giriniz.\n");
		        scanf("%s",input);
    	        girdiisle(input);
		        printf("Girdi islendi.\n");
    	        break;
    	
    	
		        case 3:
    	        printf("Buffer icerigi:\n");
				yazdir();
    	        if (head!=NULL){
		            printf("\nBuffer'i temizlemek icin 0'a basabilirsiniz.\n");
    	            scanf("%d",&clear);
    	            fflush(stdin);
    	            if (clear==0){
					
    	                while (head->next!=NULL){
			                listeninsonundansil();
		                }
		                sunusil(head);
		                system("@cls||clear");
		                printf("Buffer temizlendi. Yeni kapasite ve esik girisi yapabilirsiniz.\n");
					}
	            }
	            
    	        break;	
    	    }
			
        break;
       
	    }
	    
  }
	return 0;
}




// KULLANILAN FONKSIYONLAR

void girdiisle (char *girdi){
	BUFFR *b,*tmp,*sakla;
	char tm[SIZE];
	int flag=1;
	
	for (b=head;b!=NULL;b=b->next){
			if (0==strcmp(b->adres,girdi)){
			flag=0;
			sakla=b;
	    }
	}
	
  
 	if (flag==1){
    	listeninbasinabagla(create_el());
        b=head;
        b->sayac=1;
		strcpy(b->adres,girdi);	
	} 

	else if (flag==0) {
	
		sakla->sayac=sakla->sayac+1;
		
		int deger;
		deger=sakla->sayac;
		
		if (deger>= esik){
			//esik degeri gecerse head node olarak atanir.
		    listeninbasinabagla(create_el());
		    strcpy(head->adres,sakla->adres);
		    head->sayac=sakla->sayac;
		    
		sunusil(sakla);		
		}
	}

if (kapasite()> capacity){
		printf("\n\n^^^^");
		printf("\nKapasite asildi.(%d)\n",kapasite());
		
		printf("\nSilme isleminden onceki icerik:\n");
		yazdir();
		printf("\nSondaki eleman siliniyor.\n");
		
		//printf("\nGuncel icerik:\n");
		listeninsonundansil();
		//yazdir();
		printf("####\n\n");
	}
}


//baglama fonksiyonlari

BUFFR* create_el(){
	BUFFR *b;
	b=(BUFFR*)malloc(sizeof(BUFFR));
	if (b==NULL){
	  printf("Allocation failed");
	  exit(0);
    } 
   
    b->next=NULL;
    b->previous=NULL;
    
	return b;
}

void listeninbasinabagla(BUFFR *p){
	if (head==NULL){
		p->next=NULL;
		p->previous=NULL;
		head=p;
		last=p;
	}
	else{
		p->previous=NULL;
		p->next=head;
		head->previous=p;
		head=p;
		
		for(;p->next!=NULL;p=p->next);
		last=p;
	}
	return;
}

void listeninsonunabagla(BUFFR *p){
	if (head==NULL){
		p->previous=NULL;
		p->next=NULL;
		head=p;
		last=p;
	}
	else{
		if(last==NULL){
		 printf("Error, last nonexist.\n");
		 return;	
		}
		last->next=p;
		p->previous=last;
		p->next=NULL;
		last=p;
	}
	
}

// silme fonksiyonlari
void listeninbasindansil(){
	BUFFR *b;
	b=head;
	
	if (head==NULL) {
		printf("Error, head cannot be NULL\n");
		exit(0);
	}
	
	head=head->next;
	head->previous=NULL;
	free(b);
	
	for(b=head;b->next!=NULL;b=b->next);
	last=b;
}

void listeninsonundansil(){
	BUFFR *b,*tmp;
	
	if (head==NULL) {
		printf("Error, head cannot be NULL\n");
		exit(0);
	}
    
	tmp=last;
	b=last->previous;
	b->next=NULL;
	free(tmp);
	last=b;
	
}

void sunusil(BUFFR *e){
	BUFFR *tmp1,*tmp2,*b;
	
	if ((head==last)&&(e==head)){
     	free(e);
        head=NULL;
	    last=NULL;
	    return;
    }
    
   if(e==head){
   	   listeninbasindansil();
       return;
   }
   
   if(e==last){
   	   listeninsonundansil();
       return;
   } 
   	
	tmp1=e->previous;
	tmp2=e->next;	
	tmp1->next=tmp2;
	tmp2->previous=tmp1;
    free(e);
	
	for(b=head;b->next!=NULL;b=b->next);
	last=b;			
}
// Ek Araclar
int kapasite (){
	BUFFR *b;
	int i=0;
	
	if(head==NULL) 
	return 0;
	
	for(b=head;b!=NULL;b=b->next)
	i++;
	
	return i;
}

void yazdir (){
	BUFFR *b;
	if (head==NULL){
		printf("Su anda cache bos. Bilgi girdikten sonra sorgulama yapabilirsiniz.\n");
		return;
	}
	
	for (b=head;b!=NULL;b=b->next){
		printf("%s, ",b->adres);
		printf("%d ",b->sayac);
		if (b->next!=NULL) printf("<-> ");
		else printf("\n");
	}		
}
