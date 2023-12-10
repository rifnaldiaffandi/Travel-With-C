#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>
#define TRUE    1
#define FALSE   0
#define LEN 150

char pil = '\n';

int days_in_month[100]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char months[100][100]=
{
	" ",
	"\n\n\nJanuary",
	"\n\n\nFebruary",
	"\n\n\nMarch",
	"\n\n\nApril",
	"\n\n\nMay",
	"\n\n\nJune",
	"\n\n\nJuly",
	"\n\n\nAugust",
	"\n\n\nSeptember",
	"\n\n\nOctober",
	"\n\n\nNovember",
	"\n\n\nDecember"
};


int inputyear(void)
{
	int year;
	
	printf("\n\nEnter 0 to go back... ");
	printf("\nSebelum lanjut Cek kalender dulu yuk (Contoh: 2022) : ");
	scanf("%d", &year);
	return year;
}

int determinedaycode(int year)
{
	int daycode;
	int d1, d2, d3;
	
	d1 = (year - 1.)/ 4.0;
	d2 = (year - 1.)/ 100.;
	d3 = (year - 1.)/ 400.;
	daycode = (year + d1 - d2 + d3) %7;
	return daycode;
}


int determineleapyear(int year)
{
	if(year% 4 == FALSE && year%100 != FALSE || year%400 == FALSE)
	{
		days_in_month[2] = 29;
		return TRUE;
	}
	else
	{
		days_in_month[2] = 28;
		return FALSE;
	}
}

void calendar(int year, int daycode)
{
	int month, day;
	for ( month = 1; month <= 12; month++ )
	{
		printf("%s", months[month]);
		printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );
		
		for ( day = 1; day <= 1 + daycode * 5; day++ )
		{
			printf(" ");
		}
		
		for ( day = 1; day <= days_in_month[month]; day++ )
		{
			printf("%2d", day );
			
			if ( ( day + daycode ) % 7 > 0 )
				printf("   " );
			else
				printf("\n " );
		}
			daycode = ( daycode + days_in_month[month] ) % 7;
	}
}

void menu_pembayaran(){
	printf("Jenis Pembayaran\n\n");
	printf("1. Kredit -> PPN 15%%\n");
	printf("2. Debit -> PPN 10%%\n");
}

void menu_interface(){
			printf("\n||===========================================================================||\n");
			printf("||---------------------------------Welcome to--------------------------------||\n");
			printf("||===========================================================================||\n");
			printf("||   _________ ______   ______ ___  __ ______  ___  _   __   __    __     __ ||\n");
			printf("||  /___  ___//      \\ / __  //  / / //  ___/ /  / | | / /  / /   / /    / / || \n");
			printf("||     / /   / _  ___// /_/ //  / / //  /__  /  /  | |/ /  / /   / //\\  / /  ||\n");
			printf("||    / /   / / \\ \\  / __  //  / / //   __/ /  /   |    \\ / /   / / \\ \\/ /   || \n");
			printf("||   / /   / /   \\_\\/ / / / \\  \\/ //   /__ /  /___ |  /\\ \\\\ \\_ / /   \\  /    ||\n");
			printf("||  /_/   /_/      /_/ /_/   \\___//______//______/ |_|  \\_\\\\____/    / /     ||\n");
			printf("||                                                                  /_/      ||\n");
			printf("||===========================================================================||\n");	
			printf("||-----------YOU MUST SIGN UP/LOG IN BEFORE YOU GO TO THE MAIN MENU----------||\n");
			printf("||===========================================================================||\n\n");
}

void menu_order(){
				printf("   _________ ______   ______ ___  __ ______  ___  _   __   __    __     __ \n");
				printf("  /___  ___//      \\ / __  //  / / //  ___/ /  / | | / /  / /   / /    / /  \n");
				printf("     / /   / _  ___// /_/ //  / / //  /__  /  /  | |/ /  / /   / //\\  / /  \n");
				printf("    / /   / / \\ \\  / __  //  / / //   __/ /  /   |    \\ / /   / / \\ \\/ /    \n");
				printf("   / /   / /   \\_\\/ / / / \\  \\/ //   /__ /  /___ |  /\\ \\\\ \\_ / /   \\  /    \n");
				printf("  /_/   /_/      /_/ /_/   \\___//______//______/ |_|  \\_\\\\____/    / /     \n");
				printf("                                                                  /_/      \n");
				printf("\n||===========================================================================||\n");
				printf("||                        READY TO ORDER YOUR TICKETS?                       ||\n");
				printf("||===========================================================================||\n");
				printf("||                               1. BELI TIKET                               ||\n");
				printf("||                               2. CEK TIKET                                ||\n");
				printf("||                               3. EXIT                                     ||\n");
				printf("||===========================================================================||\n");
}

void main_menu(){
	printf("____________________________________________________________________________");
	printf("\n|                                                                          |\n");	
	printf("|                                  WELCOME                                 |\n");
	printf("|                                PASSENGER's                               |\n");
	printf("|                                 CANDIDATE                                |\n");
	printf("|                                                                          |\n");
	printf("|==========================================================================|\n");
	printf("|                                                                          |\n");	
	printf("| > Tekan '1' Dulu dan pilih Tanggal Keberangkatan mu yuk!                 |\n");
	printf("| > Tekan '2' Untuk Tentuin Maskapai Favorit kamu!                         |\n");
	printf("| > Tekan '3' mau berangkat darimana nih? (Kota Asal kamu)                 |\n");
	printf("| > Tekan '4' Buat nentuin mau jalan jalan kemana sih sekarang kamu?       |\n");
	printf("| > Tekan '5' Tentuin dulu yuk siapa aja yang mau ikut :)                  |\n");
	printf("| > Tekan '6' Mau bayar pakai apa?                                         |\n");
	printf("| > Tekan '7' Kalau kamu sudah selesai membuat pesanan :)                  |\n");
	printf("|                                                                          |\n");
	printf("|==========================================================================|\n");
	printf("| CS : (+62) 863-09813-6754|  ---                                          |\n");
	printf("|==========================| | o'| @travelkuy                              |\n");
	printf("| CS : (+62) 22-4214-214   |  ---                                          |\n");
	printf("|==========================|_______________________________________________|\n");
}

struct list{
	char account[100];
	char password[100];
	char account1[100];
	char password1[100];
} user_data[100];

struct list_kelas{
	char kelas[100];
}kelass[100];

struct list_bisnis{
    char maskapai[1000];
    long long bisnis;
}bisniss[100];

struct list_ekonomi{
    char maskapai[1000];
    long long ekonomi;
}ekonomii[100];

struct list_eksekutif{
    char maskapai[1000];
    long long eksekutif;
}eksekutiff[100];

struct list_asal{
    char kota[1000];
    char bandara[1000];
}asall[100];

struct list_tujuan{
    char kota[1000];
    char jam[1000];
}tujuann[100];

struct list_tanggal{
	char keberangkatan[100];
}tanggall[100];

struct list_usia{
    char usia[1000];
    char umur[1000];
}penumpangg[100];

struct list_jam{
    char jam[1000];
    char keberangkatan[1000];
}jamm[100];

struct user{
	int tanggal; 
	int bulan;
	char maskapai[100];
	long long harga;
	char kota_asal[100];
	char kota_tujuan[100];
	int jumlah_dewasa;
	int jumlah_anakanak;
	int jumlah_balita;
	char pembayaran[100];
	char jam_tujuan[100];
	char usia_dewasa[100];
	char usia_anakanak[100];
	char usia_balita[100];
}ticket[1000];

struct cek{
	char account2[100];
	int tanggal1; 
	int bulan1;
	char maskapai1[100];
	long long harga1;
	char kota_asal1[100];
	char kota_tujuan1[100];
	int jumlah_dewasa1;
	int jumlah_anakanak1;
	int jumlah_balita1;
	char pembayaran1[100];
	char jam_tujuan1[100];
	char usia_dewasa1[100];
	char usia_anakanak1[100];
	char usia_balita1[100];
	int check;
}ticket1[1000];

void insertionSort(list_ekonomi *data, int len){
	list_ekonomi temp[100];
	int x;
    for (int i = 1; i < len; i++) {
        temp[i] = data[i];
        x = i - 1;
 
        while (x >= 0 && data[x].ekonomi > temp[i].ekonomi) {
            data[x + 1] = data[x];
            x--;
        }
        data[x + 1] = temp[i];
    }
}

void insertionSort1(list_bisnis *data, int len){
	list_bisnis temp[100];
	int x;
    for (int i = 1; i < len; i++) {
        temp[i] = data[i];
        x = i - 1;
 
        while (x >= 0 && data[x].bisnis > temp[i].bisnis) {
            data[x + 1] = data[x];
            x--;
        }
        data[x + 1] = temp[i];
    }
}

void insertionSort2(list_eksekutif *data, int len){
	list_eksekutif temp[100];
	int x;
    for (int i = 1; i < len; i++) {
        temp[i] = data[i];
        x = i - 1;

        while (x >= 0 && data[x].eksekutif > temp[i].eksekutif) {
            data[x + 1] = data[x];
            x--;
        }
        data[x + 1] = temp[i];
    }
}

int main (){
	
	int len = 5;
	int check1 = 0;
	int check2 = 0;
	int check3 = 0;
	int check4 = 0;
	int check5 = 0;
	int check6 = 0;
	int check7 = 0;
	int check8 = 0;
	int check = 0;
	int ekonomicheck = 0;
	int bisnischeck = 0;
	int eksekutifcheck = 0;
	float ppnkredit = 0.15;
	float ppndebit = 0.10;
	long long hargadewasa;
	long long hargadewasa1;
	long long hargaanak;
	long long hargaanak1;
	long long hargabalita;
	long long hargabalita1;
	long long ppn;
	long long totalharga;
	
	FILE *ftiket;
	ftiket = fopen("ticket.txt", "a+");
	
   	char buf[LEN];
   	time_t curtime;
  	struct tm *loc_time;
 
  	curtime = time (NULL);
 
  	loc_time = localtime (&curtime);
 
 	printf("%s", asctime (loc_time));
 	
 	strftime (buf, LEN, "Today is %A, %b %d.\n", loc_time);
  	fputs (buf, stdout);
  	strftime (buf, LEN, "Time is %I:%M %p.\n", loc_time);
  	fputs (buf, stdout);
	
	menu_interface();	
	switch (pil){
	case '\n' : 
	begin_login:
	int index = 0;
	FILE *flogin;
	flogin = fopen("login_account.txt", "a+");
	char acc_check[4];
	
	printf("Do you already have an account (Yes/No) : ");
	scanf("%s", &acc_check); getchar();
	for(int acc_for = 0; acc_for < 3; acc_for++){
		acc_check[acc_for] = tolower(acc_check[acc_for]);
	}
	
	if(acc_check[0] == 'n' && acc_check[1] == 'o'){
		acc1:
		printf("Please register your name and password!\n\n");
		printf("NOTE: username and password cannot contain any whitespace or symbols!\n");
		printf("Username: ");
		scanf("%[^\n]", &user_data[index].account); getchar();
		int var = strlen(user_data[index].account);
		for(int i=0; i<var; i++){
			int matt = user_data[0].account[i];
			if(matt == 32){
				system("cls");
				printf("NOTE: username and password cannot contain any whitespace or symbols!\n");
				sleep(2);
				system("cls");
				goto acc1;
			}
		}
		fprintf(flogin, "%s ", user_data[index].account);
		printf("Password: ");
		scanf("%[^\n]", &user_data[index].password); getchar();
		var = strlen(user_data[index].password);
		for(int i=0; i<var; i++){
			int hew = user_data[0].password[i];
			if(hew == 32){
				system("cls");
				printf("NOTE: username and password cannot contain any whitespace or symbols!\n");
				sleep(2);
				system("cls");
				goto acc1;
			}
		}
		fprintf(flogin, "%s\n", user_data[index].password);
		printf("\nCongratulations, your account has been made!\n\n");
		fclose(flogin);
		goto begin_login;
	}
	else if(acc_check[0] == 'y' && acc_check[1] == 'e' && acc_check[2] == 's'){
		int user_acc = 0;
		int z = -1;
		while(!feof(flogin)){
			z++;
			fscanf(flogin, "%s %s", &user_data[z].account, &user_data[z].password);
		}
		printf("Username: ");
		scanf("%s", &user_data[0].account1); getchar();
		printf("Password: ");
		scanf("%s", &user_data[0].password1); getchar();
		int user_check = 0;
		for(user_acc=0; user_acc < z; user_acc++){
			if(strcmp(user_data[0].account1, user_data[user_acc].account) == 0 && (strcmp(user_data[0].password1, user_data[user_acc].password)) == 0){
				user_check = 1;
			}	
		}
		system("cls");
		if(user_check == 1){
			goto begin_1;
		}
		else{
				menu_interface();
				printf("\t     _____   ____ __________________________  _____   ________________\n");
				printf("\t    /    /  /   //    /  ___    \\            \\     \\ |   |            \\ \n");
				printf("\t   /    /  /   //    /  /   /    | ______     |    | |   |   __________|\n");
				printf("\t  /    /  /   //    /     ______/ |      |    |    | |   |  /     ____\n");
				printf("\t /    /  /   //    /      \\   |   |      |    |    | /   |  |    /_   \\ \n");
				printf("\t/     \\_/  _      /    /\\  \\  |   |______|    |    |/    |  \\______|   | \n");
				printf("\t\\         / \\    /    /  \\  \\ |               | |\\       |             | \n");
				printf("\t \\_______/   \\__/    /    \\__\\ \\ ___________ /__| \\ ____/ \\___________/\n");
				printf("\t\n\nYou have entered the wrong username or password!\n");
				goto begin_login;
		}
	}
	else{
		system("cls");
		menu_interface();
				printf("\t     _____   ____ __________________________  _____   ________________\n");
				printf("\t    /    /  /   //    /  ___    \\            \\     \\ |   |            \\ \n");
				printf("\t   /    /  /   //    /  /   /    | ______     |    | |   |   __________|\n");
				printf("\t  /    /  /   //    /     ______/ |      |    |    | |   |  /     ____\n");
				printf("\t /    /  /   //    /      \\   |   |      |    |    | /   |  |    /_   \\ \n");
				printf("\t/     \\_/  _      /    /\\  \\  |   |______|    |    |/    |  \\______|   | \n");
				printf("\t\\         / \\    /    /  \\  \\ |               | |\\       |             | \n");
				printf("\t \\_______/   \\__/    /    \\__\\ \\ ___________ /__| \\ ____/ \\___________/\n");
		printf("\t\nYou have entered the wrong answer! Please try again!\n\n");
		goto begin_login;
	}
	
	fclose(flogin);
	}
	
	begin_1:
	menu_order();
	int menu_pil;
	printf("Pilih: ");
	while(1){
	
	scanf("%d", &menu_pil); getchar();
	
	if(menu_pil == 3){
		system("cls");
		printf("                                                                ____\n");
		printf("                                  -  -  -  -    ____ - - - -   /   /\n");
		printf("                                    -  -  -  - /   /  - - -   /  _/__\n");
		printf("                                   ___________/__ /__________/  //__/\n");
		printf("                                  // -  ----   ---  ----        ) - -\n");
		printf("                                 ()_   ||     \\   \\            ) - -\n");
		printf("                                   (-----------\\---\\-------------\n");
		printf("                                                \\___\\   \n");
		printf("Selamat menikmati penerbangan anda!\n");
		return 0;
	}
	if(menu_pil == 2){
		system("cls");
		int c = 0;
		FILE *fopencek;
		fopencek = fopen("ticket.txt", "r");
		while(!feof(fopencek)){
			fscanf(fopencek, "%[^#]#%d#%d#%[^#]#%lld#%[^#]#%[^#]#%[^#]#%d#%[^#]#%d#%[^#]#%d#%[^#]#%[^#]#%d\n", 
			ticket1[c].account2, &ticket1[c].tanggal1, &ticket1[c].bulan1, ticket1[c].maskapai1, 
			&ticket1[c].harga1, ticket1[c].kota_asal1, ticket1[c].kota_tujuan1,ticket1[c].jam_tujuan1, 
			&ticket1[c].jumlah_dewasa1, ticket1[c].usia_dewasa1, &ticket1[c].jumlah_anakanak1, 
			ticket1[c].usia_anakanak1, &ticket1[c].jumlah_balita1, ticket1[c].usia_balita1, ticket1[c].pembayaran1, &ticket1[c].check);
			c++;
		}
	
		
		int ceking = 0;
		for(int i=0; i<c; i++){
			if(strcmp(ticket1[i].account2, user_data[0].account1) == 0){				
				printf("            ________________________________________________________\n");
				printf("           _)                                                       \n");
				printf("        ___)   Tanggal Keberangkatan: %d/%d/2022                    \n", ticket1[i].tanggal1, ticket1[i].bulan1);
				printf(" _______)      Maskapai: %s                                                     \n", ticket1[i].maskapai1);
				printf("/              Total Harga: Rp.%lld                                               \n", ticket1[i].harga1);
				printf("\\              Kota Asal: %s                                    \n", ticket1[i].kota_asal1 );
				printf(" )                                                                               \n");
				printf("/              Kota Tujuan: %s                                                     \n", ticket1[i].kota_tujuan1);
				printf("\\______        Jam Keberangkatan: %s                               \n", ticket1[i].jam_tujuan1);
				printf("        )__    Total Penumpang: %d Dewasa, %d Anak - anak, %d Balita                   \n", ticket1[i].jumlah_dewasa1, ticket1[i].jumlah_anakanak1, ticket1[i].jumlah_balita1);
				printf("           )_  Jenis Pembayaran: %s                                            \n", ticket1[i].pembayaran1);
				printf("             )______________________________________________________\n");
				printf("                                                               ___________________\n");
				printf("                                                              /                   (_\n");
				printf("                                                              \\                    (___\n");
				printf("                                                              /                       (_______\n");
				printf("                                                              \\   E | Y | T                   \\ \n");
				printf("                                                              /   N | O | R   ---             /\n");
				printf("                                                              \\   J | U | I  | o'| @travelkuy( \n");
				printf("                                                              /   O | R | P   ---             \\ \n");
				printf("                                                              \\   Y |   | !            _______/\n");
				printf("                                                              /                     __(\n");
				printf("                                                              \\                    _( \n");
				printf("                                                              /____________________(\n");
				ceking = 1;
				printf("\n(Enter 0 to go back)\n");
				getch();
				system("cls");
				goto begin_1;
			}
		}
		if(ceking == 0){
				system("cls");
				printf("You have to book your flight order first!\n");
				sleep(2);
				system("cls");
				goto begin_1;
			}
	}
	if(menu_pil == 1){
		int c = 0;
		FILE *fopencek;
		fopencek = fopen("ticket.txt", "r");
		while(!feof(fopencek)){
			fscanf(fopencek, "%[^#]#%d#%d#%[^#]#%lld#%[^#]#%[^#]#%[^#]#%d#%[^#]#%d#%[^#]#%d#%[^#]#%[^#]#%d\n", 
			ticket1[c].account2, &ticket1[c].tanggal1, &ticket1[c].bulan1, ticket1[c].maskapai1, 
			&ticket1[c].harga1, ticket1[c].kota_asal1, ticket1[c].kota_tujuan1,ticket1[c].jam_tujuan1, 
			&ticket1[c].jumlah_dewasa1, ticket1[c].usia_dewasa1, &ticket1[c].jumlah_anakanak1, 
			ticket1[c].usia_anakanak1, &ticket1[c].jumlah_balita1, ticket1[c].usia_balita1, ticket1[c].pembayaran1, &ticket1[c].check);
			c++;
		}
	int ten;
	for(int y=0;y<c;y++){
	if(strcmp(ticket1[y].account2, user_data[0].account1) == 0){
	 ten = ticket1[y].check;
	}
}
		
		if(ten == 1){
		system("cls");
		printf("You've already book your flight order! Please use a different account to order your next flight!\n");
		sleep(2);
		system("cls");
		goto begin_1;
		}	
	begin_menu:
	int menu_tujuan;
	system("cls");
	main_menu();
	printf("Pilihan kamu: ");
	scanf("%d", &menu_tujuan); getchar();
	
	if(menu_tujuan == 1){
		while(check1 != 1){
		back:
		system("cls");
		char buf[LEN];
   		time_t curtime;
   		struct tm *loc_time;
   		curtime = time (NULL);
	    loc_time = localtime (&curtime);
	    
   		printf("%s", asctime (loc_time));
	    strftime (buf, LEN, "Today is %A, %b %d.\n", loc_time);
   	 	fputs (buf, stdout);
   		strftime (buf, LEN, "Time is %I:%M %p.\n", loc_time);
   		fputs (buf, stdout);
   		
   		calendar:
   		int year, daycode, leapyear;
	year = inputyear();
	if(year == 0){
		goto begin_menu;
	}
	daycode = determinedaycode(year);
	determineleapyear(year);
	calendar(year, daycode);
	printf("\npress any key to continue...");
	printf("\n");
   		getch();
   		system("cls");
   		printf("\n(Enter 0 to go back)\n");
   		printf("_______________________________\n");
		printf("|Choose a date between 1 to 31: ");
		scanf("%d", &ticket[0].tanggal); getchar();
		if(ticket[0].tanggal == 0){
			system("cls");
			goto calendar;
		}
		system("cls");
		printf("|-----------------------------------|\n");
		printf("|         Select your month         |\n");
		printf("|-----------------------------------|\n");
		printf("| (1)January           (7)July      |\n");
		printf("| (2)February          (8)August    |\n");
		printf("| (3)March             (9)September |\n");
		printf("| (4)April             (10)October  |\n");
		printf("| (5)May               (11)November |\n");
		printf("| (6)June              (12)December |\n");
		printf("|-----------------------------------|\n");
		printf("\nChoose a month between 1 to 12: ");
		scanf("%d", &ticket[0].bulan); getchar();
		
		if(ticket[0].tanggal > 0 && ticket[0].tanggal <= 31 && ticket[0].bulan > 0 && ticket[0].bulan <= 12) {
			check1 = 1;
		}
		else{
			system("cls");
				printf("\t     _____   ____ __________________________  _____   ________________\n");
				printf("\t    /    /  /   //    /  ___    \\            \\     \\ |   |            \\ \n");
				printf("\t   /    /  /   //    /  /   /    | ______     |    | |   |   __________|\n");
				printf("\t  /    /  /   //    /     ______/ |      |    |    | |   |  /     ____\n");
				printf("\t /    /  /   //    /      \\   |   |      |    |    | /   |  |    /_   \\ \n");
				printf("\t/     \\_/  _      /    /\\  \\  |   |______|    |    |/    |  \\______|   | \n");
				printf("\t\\         / \\    /    /  \\  \\ |               | |\\       |             | \n");
				printf("\t \\_______/   \\__/    /    \\__\\ \\ ___________ /__| \\ ____/ \\___________/\n");			
			printf("Wrong input, Please double check your date and month!\n");
			sleep(2);
			system("cls");
			goto back;
		}
	}
	if(check1 == 1){
				system("cls");
			printf("\t||===========================================================================||\n");
			printf("\t||   _________ ______   ______ ___  __ ______  ___  _   __   __    __     __ ||\n");
			printf("\t||  /___  ___//      \\ / __  //  / / //  ___/ /  / | | / /  / /   / /    / / || \n");
			printf("\t||     / /   / _  ___// /_/ //  / / //  /__  /  /  | |/ /  / /   / //\\  / /  ||\n");
			printf("\t||    / /   / / \\ \\  / __  //  / / //   __/ /  /   |    \\ / /   / / \\ \\/ /   || \n");
			printf("\t||   / /   / /   \\_\\/ / / / \\  \\/ //   /__ /  /___ |  /\\ \\\\ \\_ / /   \\  /    ||\n");
			printf("\t||  /_/   /_/      /_/ /_/   \\___//______//______/ |_|  \\_\\\\____/    / /     ||\n");
			printf("\t||                                                                  /_/      ||\n");
			printf("\t||===========================================================================||\n");				
			printf("\n\n\tYou have chosen your departure date! Please proceed to the next section!\n");
				sleep(2);
				system("cls");
				goto begin_menu;
	}
	}
	if(menu_tujuan == 2){
		if(check2 == 1){
				system("cls");
			printf("\t||===========================================================================||\n");
			printf("\t||   _________ ______   ______ ___  __ ______  ___  _   __   __    __     __ ||\n");
			printf("\t||  /___  ___//      \\ / __  //  / / //  ___/ /  / | | / /  / /   / /    / / || \n");
			printf("\t||     / /   / _  ___// /_/ //  / / //  /__  /  /  | |/ /  / /   / //\\  / /  ||\n");
			printf("\t||    / /   / / \\ \\  / __  //  / / //   __/ /  /   |    \\ / /   / / \\ \\/ /   || \n");
			printf("\t||   / /   / /   \\_\\/ / / / \\  \\/ //   /__ /  /___ |  /\\ \\\\ \\_ / /   \\  /    ||\n");
			printf("\t||  /_/   /_/      /_/ /_/   \\___//______//______/ |_|  \\_\\\\____/    / /     ||\n");
			printf("\t||                                                                  /_/      ||\n");
			printf("\t||===========================================================================||\n");				
				printf("\n\nYou have chosen your class and airline! Please proceed to the next section!\n");
				sleep(2);
				system("cls");
				goto begin_menu;
	}
		begin_maskapai:
		system("cls");
		int menu_kelas;
		int kelas = 0;
		FILE *fkelas;
		fkelas = fopen("kelas_maskapai.txt", "r");
		while(!feof(fkelas)){
			fscanf(fkelas, "%[^\n]\n", &kelass[kelas].kelas);
			kelas++;
		}
		fclose(fkelas);
		while(1){
		for(int i=0; i<kelas; i++){
			printf("\t%s\n", kelass[i].kelas);
		}
		printf("\n\tPilih 1/2/3/0: ");
		scanf("%d", &menu_kelas); getchar();
		if(menu_kelas == 0){
			goto begin_menu;
		}
		if(menu_kelas == 1){
			system("cls");
			int ekonomi = 0;
			FILE *it=fopen("maskapai_ekonomi.txt","r");
			while(!feof(it)){
    			fscanf(it,"%[^#]#%lld\n",&ekonomii[ekonomi].maskapai,&ekonomii[ekonomi].ekonomi);
    			ekonomi++;
			}
			fclose(it);
			while(1){
				maskapai:
			printf("================================================\n");
			printf("||-----Maskapai Penerbangan Kelas Ekonomi-----||\n");
			printf("================================================\n");
//			insertionSort(ekonomii, len);
			for(int a=0;a<ekonomi;a++){
				printf("%d.%s  Rp %lld\n", a+1, ekonomii[a].maskapai,ekonomii[a].ekonomi);
			}
			printf("================================================\n");
			printf("\n(Enter 1 two times to sort by price)\n");
			printf("(Enter 0 two times to go back)\n");
			printf("Masukkan nama maskapai yang ingin anda pilih: ");
			scanf("%[^\n]", ticket[0].maskapai); getchar();
			printf("Masukkan juga harga dari maskapai tersebut: ");
			scanf("%lld", &ticket[0].harga); getchar();
			if(strcmp(ticket[0].maskapai, "0") == 0){
			strcpy(ticket[0].maskapai, "");
			goto begin_maskapai;
			}
			else if(strcmp(ticket[0].maskapai, "1") == 0){
				system("cls");
				insertionSort(ekonomii, len);
				strcpy(ticket[0].maskapai, "");
			}
			else{
				for(int i=0; i<5; i++){
					if(strcmp(ekonomii[i].maskapai, ticket[0].maskapai) == 0 && ekonomii[i].ekonomi == ticket[0].harga){
						check2 = 1;
						ekonomicheck = 1;
						goto begin_menu;
					}
				}
				system("cls");
				printf("\t     _____   ____ __________________________  _____   ________________\n");
				printf("\t    /    /  /   //    /  ___    \\            \\     \\ |   |            \\ \n");
				printf("\t   /    /  /   //    /  /   /    | ______     |    | |   |   __________|\n");
				printf("\t  /    /  /   //    /     ______/ |      |    |    | |   |  /     ____\n");
				printf("\t /    /  /   //    /      \\   |   |      |    |    | /   |  |    /_   \\ \n");
				printf("\t/     \\_/  _      /    /\\  \\  |   |______|    |    |/    |  \\______|   | \n");
				printf("\t\\         / \\    /    /  \\  \\ |               | |\\       |             | \n");
				printf("\t \\_______/   \\__/    /    \\__\\ \\ ___________ /__| \\ ____/ \\___________/\n");				
				printf("Wrong Input! You have to enter the name or price correctly!\n");
				sleep(2);
				system("cls");
				goto maskapai;
			}
//			ticket[0].maskapai[0] = toupper(ticket[0].maskapai[0]);
		}
		}	
		else if(menu_kelas == 2){
			system("cls");
			int bisnis = 0;
			FILE *it=fopen("maskapai_bisnis.txt","r");
			while(!feof(it)){
    			fscanf(it,"%[^#]#%lld\n",&bisniss[bisnis].maskapai,&bisniss[bisnis].bisnis);
    			bisnis++;
			}
			fclose(it);
			while(1){
			printf("================================================\n");
			printf("||-----Maskapai Penerbangan Kelas Bisnis------||\n");
			printf("================================================\n");
			for(int a=0;a<bisnis;a++){
				printf("||%d.%s  Rp %lld\n",a+1, bisniss[a].maskapai,bisniss[a].bisnis);
			}
			printf("================================================\n");
			printf("\n(Enter 1 two times to sort by price)\n");
			printf("(Enter 0 two times to go back)\n");
			printf("Masukkan nama maskapai yang ingin anda pilih: ");
			scanf("%[^\n]", ticket[0].maskapai); getchar();
			printf("Masukkan juga harga dari maskapai tersebut: ");
			scanf("%lld", &ticket[0].harga); getchar();
			if(strcmp(ticket[0].maskapai, "0") == 0){
			strcpy(ticket[0].maskapai, "");
			goto begin_maskapai;
			}
			else if(strcmp(ticket[0].maskapai, "1") == 0){
				system("cls");
				insertionSort1(bisniss, len);
				strcpy(ticket[0].maskapai, "");
			}
			else{
				for(int i=0; i<5; i++){
					if(strcmp(bisniss[i].maskapai, ticket[0].maskapai) == 0 && bisniss[i].bisnis == ticket[0].harga){
						check2 = 1;
						bisnischeck = 1;
						goto begin_menu;
					}
				}
				system("cls");
				printf("\t     _____   ____ __________________________  _____   ________________\n");
				printf("\t    /    /  /   //    /  ___    \\            \\     \\ |   |            \\ \n");
				printf("\t   /    /  /   //    /  /   /    | ______     |    | |   |   __________|\n");
				printf("\t  /    /  /   //    /     ______/ |      |    |    | |   |  /     ____\n");
				printf("\t /    /  /   //    /      \\   |   |      |    |    | /   |  |    /_   \\ \n");
				printf("\t/     \\_/  _      /    /\\  \\  |   |______|    |    |/    |  \\______|   | \n");
				printf("\t\\         / \\    /    /  \\  \\ |               | |\\       |             | \n");
				printf("\t \\_______/   \\__/    /    \\__\\ \\ ___________ /__| \\ ____/ \\___________/\n");				
				printf("Wrong Input! You have to enter the name or price correctly!\n");
				sleep(2);
				system("cls");
			}
		}
		}
		else if(menu_kelas == 3){
			system("cls");
			int eksekutif = 0;
			FILE *it=fopen("maskapai_eksekutif.txt","r");
			while(!feof(it)){
    			fscanf(it,"%[^#]#%lld\n",&eksekutiff[eksekutif].maskapai,&eksekutiff[eksekutif].eksekutif);
    			eksekutif++;
			}
			fclose(it);
			while(1){
			printf("================================================\n");
			printf("||----Maskapai Penerbangan Kelas Eksekutif----||\n");
			printf("================================================\n");
			for(int a=0;a<eksekutif;a++){
				printf("||%d.%s Rp %lld\n",a+1, eksekutiff[a].maskapai,eksekutiff[a].eksekutif);
			}
			printf("================================================\n");
			printf("\n(Enter 1 two times to sort by price)\n");
			printf("(Enter 0 two times to go back)\n");
			printf("Masukkan nama maskapai yang ingin anda pilih: ");
			scanf("%[^\n]", ticket[0].maskapai); getchar();
			printf("Masukkan juga harga dari maskapai tersebut: ");
			scanf("%lld", &ticket[0].harga); getchar();
			if(strcmp(ticket[0].maskapai, "0") == 0){
			strcpy(ticket[0].maskapai, "");
			goto begin_maskapai;
			}
			else if(strcmp(ticket[0].maskapai, "1") == 0){
				system("cls");
				insertionSort2(eksekutiff, len);
				strcpy(ticket[0].maskapai, "");
			}
			else{
				for(int i=0; i<5; i++){
					if(strcmp(eksekutiff[i].maskapai, ticket[0].maskapai) == 0 && eksekutiff[i].eksekutif == ticket[0].harga){
						check2 = 1;
						eksekutifcheck = 1;
						goto begin_menu;
					}
				}
				system("cls");
				printf("\t     _____   ____ __________________________  _____   ________________\n");
				printf("\t    /    /  /   //    /  ___    \\            \\     \\ |   |            \\ \n");
				printf("\t   /    /  /   //    /  /   /    | ______     |    | |   |   __________|\n");
				printf("\t  /    /  /   //    /     ______/ |      |    |    | |   |  /     ____\n");
				printf("\t /    /  /   //    /      \\   |   |      |    |    | /   |  |    /_   \\ \n");
				printf("\t/     \\_/  _      /    /\\  \\  |   |______|    |    |/    |  \\______|   | \n");
				printf("\t\\         / \\    /    /  \\  \\ |               | |\\       |             | \n");
				printf("\t \\_______/   \\__/    /    \\__\\ \\ ___________ /__| \\ ____/ \\___________/\n");				
				printf("Wrong Input! You have to enter the name or price correctly!\n");
				sleep(2);
				system("cls");
			}
		}
		}
		else{
				system("cls");
				printf("\t     _____   ____ __________________________  _____   ________________\n");
				printf("\t    /    /  /   //    /  ___    \\            \\     \\ |   |            \\ \n");
				printf("\t   /    /  /   //    /  /   /    | ______     |    | |   |   __________|\n");
				printf("\t  /    /  /   //    /     ______/ |      |    |    | |   |  /     ____\n");
				printf("\t /    /  /   //    /      \\   |   |      |    |    | /   |  |    /_   \\ \n");
				printf("\t/     \\_/  _      /    /\\  \\  |   |______|    |    |/    |  \\______|   | \n");
				printf("\t\\         / \\    /    /  \\  \\ |               | |\\       |             | \n");
				printf("\t \\_______/   \\__/    /    \\__\\ \\ ___________ /__| \\ ____/ \\___________/\n");				
				printf("Wrong Input! You have to enter the correct number to choose!\n");
				sleep(2);
				system("cls");
		}
		}
		check2 = 1;
	}
	else if(menu_tujuan == 3){
		if(check3 == 1){
				system("cls");
			printf("\t||===========================================================================||\n");
			printf("\t||   _________ ______   ______ ___  __ ______  ___  _   __   __    __     __ ||\n");
			printf("\t||  /___  ___//      \\ / __  //  / / //  ___/ /  / | | / /  / /   / /    / / || \n");
			printf("\t||     / /   / _  ___// /_/ //  / / //  /__  /  /  | |/ /  / /   / //\\  / /  ||\n");
			printf("\t||    / /   / / \\ \\  / __  //  / / //   __/ /  /   |    \\ / /   / / \\ \\/ /   || \n");
			printf("\t||   / /   / /   \\_\\/ / / / \\  \\/ //   /__ /  /___ |  /\\ \\\\ \\_ / /   \\  /    ||\n");
			printf("\t||  /_/   /_/      /_/ /_/   \\___//______//______/ |_|  \\_\\\\____/    / /     ||\n");
			printf("\t||                                                                  /_/      ||\n");
			printf("\t||===========================================================================||\n");					
				printf("\n\n\tYou have chosen your departure city! Please proceed to the next section!\n");
				sleep(2);
				system("cls");
				goto begin_menu;
		}
		system("cls");
		int asal = 0;
		FILE *it=fopen("asal_kota.txt","r");
		while(!feof(it)){
    		fscanf(it,"%[^#]#%[^\n]\n",&asall[asal].kota,&asall[asal].bandara);
    		asal++;
		}
		fclose(it);
		while(1){
		printf("=====================================================================================\n");
		printf("||------------------------------Asal Kota Penerbangan------------------------------||\n");
		printf("=====================================================================================\n");
		for(int a=0;a<asal;a++){
			printf("%d. %s - %s\n",a+1, asall[a].kota,asall[a].bandara);
		}
		printf("=====================================================================================\n");
		printf("\n(Enter 0 to go back)\n");
		printf("Masukkan asal kota tempat anda berada: ");
		scanf("%[^\n]", ticket[0].kota_asal); getchar();
		if(strcmp(ticket[0].kota_asal, "0") == 0){
			strcpy(ticket[0].kota_asal, "");
			goto begin_menu;
		}
//		ticket[0].kota_asal[0] = toupper(ticket[0].kota_asal[0]);
		else{
				for(int i=0; i<7; i++){
					if(strcmp(asall[i].kota, ticket[0].kota_asal) == 0){
						check3 = 1;
						goto begin_menu;
					}
				}
				system("cls");
				printf("\t     _____   ____ __________________________  _____   ________________\n");
				printf("\t    /    /  /   //    /  ___    \\            \\     \\ |   |            \\ \n");
				printf("\t   /    /  /   //    /  /   /    | ______     |    | |   |   __________|\n");
				printf("\t  /    /  /   //    /     ______/ |      |    |    | |   |  /     ____\n");
				printf("\t /    /  /   //    /      \\   |   |      |    |    | /   |  |    /_   \\ \n");
				printf("\t/     \\_/  _      /    /\\  \\  |   |______|    |    |/    |  \\______|   | \n");
				printf("\t\\         / \\    /    /  \\  \\ |               | |\\       |             | \n");
				printf("\t \\_______/   \\__/    /    \\__\\ \\ ___________ /__| \\ ____/ \\___________/\n");				
				printf("\n\tWrong Input! You have to enter the city name correctly!\n");
				sleep(2);
				system("cls");
			}
		}
	}
	else if(menu_tujuan == 4){
		if(check3 != 1){
				system("cls");
				printf("\t     _____   ____ __________________________  _____   ________________\n");
				printf("\t    /    /  /   //    /  ___    \\            \\     \\ |   |            \\ \n");
				printf("\t   /    /  /   //    /  /   /    | ______     |    | |   |   __________|\n");
				printf("\t  /    /  /   //    /     ______/ |      |    |    | |   |  /     ____\n");
				printf("\t /    /  /   //    /      \\   |   |      |    |    | /   |  |    /_   \\ \n");
				printf("\t/     \\_/  _      /    /\\  \\  |   |______|    |    |/    |  \\______|   | \n");
				printf("\t\\         / \\    /    /  \\  \\ |               | |\\       |             | \n");
				printf("\t \\_______/   \\__/    /    \\__\\ \\ ___________ /__| \\ ____/ \\___________/\n");				
				printf("\n\tPlease select your departure city first, then you can select your destination city!\n");
				sleep(2);
				system("cls");
				goto begin_menu;
		}
		else if(check4 == 1){
				system("cls");
			printf("\t||===========================================================================||\n");
			printf("\t||   _________ ______   ______ ___  __ ______  ___  _   __   __    __     __ ||\n");
			printf("\t||  /___  ___//      \\ / __  //  / / //  ___/ /  / | | / /  / /   / /    / / || \n");
			printf("\t||     / /   / _  ___// /_/ //  / / //  /__  /  /  | |/ /  / /   / //\\  / /  ||\n");
			printf("\t||    / /   / / \\ \\  / __  //  / / //   __/ /  /   |    \\ / /   / / \\ \\/ /   || \n");
			printf("\t||   / /   / /   \\_\\/ / / / \\  \\/ //   /__ /  /___ |  /\\ \\\\ \\_ / /   \\  /    ||\n");
			printf("\t||  /_/   /_/      /_/ /_/   \\___//______//______/ |_|  \\_\\\\____/    / /     ||\n");
			printf("\t||                                                                  /_/      ||\n");
			printf("\t||===========================================================================||\n");					
				printf("\n\n\tYou have chosen your destination city! Please proceed to the next section!\n");
				sleep(2);
				system("cls");
				goto begin_menu;
		}
		system("cls");
		if(strcmp(ticket[0].kota_asal, "Jakarta") == 0){
		int tujuan = 0;
		FILE *it=fopen("jam_keberangkatan_jakarta.txt","r");
		while(!feof(it)){
    		fscanf(it,"%[^#]#%[^\n]\n",&tujuann[tujuan].kota,&tujuann[tujuan].jam);
    		tujuan++;
		}
		fclose(it);
		while(1){
		printf("=================================================\n");
		printf("||----------Jam Keberangkatan Jakarta----------||\n");
		printf("=================================================\n");
		for(int a=0;a<tujuan;a++){
			printf("%s -> %s (%s)\n",ticket[0].kota_asal,tujuann[a].kota, tujuann[a].jam);
		}
		printf("=================================================\n");
		printf("(Enter 0 two times to go back)\n");
		printf("Contoh format input tujuan kota: Jakarta 08.35 - 10.20\n");
		printf("Masukkan nama kota tujuan yang anda inginkan: ");
		scanf("%s %[^\n]", ticket[0].kota_tujuan, ticket[0].jam_tujuan); getchar();
		if(strcmp(ticket[0].kota_tujuan, "0") == 0){
			strcpy(ticket[0].kota_tujuan, "");
			goto begin_menu;
		}
		else{
				for(int i=0; i<6; i++){
					if(strcmp(tujuann[i].kota, ticket[0].kota_tujuan) == 0 && strcmp(tujuann[i].jam, ticket[0].jam_tujuan) == 0){
						check4 = 1;
						goto begin_menu;
					}
				}
				system("cls");
				printf("\t     _____   ____ __________________________  _____   ________________\n");
				printf("\t    /    /  /   //    /  ___    \\            \\     \\ |   |            \\ \n");
				printf("\t   /    /  /   //    /  /   /    | ______     |    | |   |   __________|\n");
				printf("\t  /    /  /   //    /     ______/ |      |    |    | |   |  /     ____\n");
				printf("\t /    /  /   //    /      \\   |   |      |    |    | /   |  |    /_   \\ \n");
				printf("\t/     \\_/  _      /    /\\  \\  |   |______|    |    |/    |  \\______|   | \n");
				printf("\t\\         / \\    /    /  \\  \\ |               | |\\       |             | \n");
				printf("\t \\_______/   \\__/    /    \\__\\ \\ ___________ /__| \\ ____/ \\___________/\n");				
				printf("\n\tWrong Input! You have to enter the city name correctly!\n");
				sleep(2);
				system("cls");
			}
		}
		}
		if(strcmp(ticket[0].kota_asal, "Surabaya") == 0){
			int tujuan = 0;
		FILE *it=fopen("jam_keberangkatan_surabaya.txt","r");
		while(!feof(it)){
    		fscanf(it,"%[^#]#%[^\n]\n",&tujuann[tujuan].kota,&tujuann[tujuan].jam);
    		tujuan++;
		}
		fclose(it);
		while(1){
		printf("=================================================\n");
		printf("||---------Jam Keberangkatan Surabaya----------||\n");
		printf("=================================================\n");
		for(int a=0;a<tujuan;a++){
			printf("%s -> %s (%s)\n",ticket[0].kota_asal,tujuann[a].kota, tujuann[a].jam);
		}
		printf("=================================================\n");
		printf("(Enter 0 two times to go back)\n");
		printf("Contoh format input tujuan kota: Jakarta 08.35 - 10.20\n");
		printf("Masukkan nama kota tujuan yang anda inginkan: ");
		scanf("%s %[^\n]", ticket[0].kota_tujuan, ticket[0].jam_tujuan); getchar();
		if(strcmp(ticket[0].kota_tujuan, "0") == 0){
			strcpy(ticket[0].kota_tujuan, "");
			goto begin_menu;
		}
		else{
				for(int i=0; i<6; i++){
					if(strcmp(tujuann[i].kota, ticket[0].kota_tujuan) == 0 && strcmp(tujuann[i].jam, ticket[0].jam_tujuan) == 0){
						check4 = 1;
						goto begin_menu;
					}
				}
				system("cls");
				printf("\t     _____   ____ __________________________  _____   ________________\n");
				printf("\t    /    /  /   //    /  ___    \\            \\     \\ |   |            \\ \n");
				printf("\t   /    /  /   //    /  /   /    | ______     |    | |   |   __________|\n");
				printf("\t  /    /  /   //    /     ______/ |      |    |    | |   |  /     ____\n");
				printf("\t /    /  /   //    /      \\   |   |      |    |    | /   |  |    /_   \\ \n");
				printf("\t/     \\_/  _      /    /\\  \\  |   |______|    |    |/    |  \\______|   | \n");
				printf("\t\\         / \\    /    /  \\  \\ |               | |\\       |             | \n");
				printf("\t \\_______/   \\__/    /    \\__\\ \\ ___________ /__| \\ ____/ \\___________/\n");				
				printf("\n\tWrong Input! You have to enter the city name correctly!\n");
				sleep(2);
				system("cls");
			}
		}
		}
		if(strcmp(ticket[0].kota_asal, "Medan") == 0){
			int tujuan = 0;
		FILE *it=fopen("jam_keberangkatan_medan.txt","r");
		while(!feof(it)){
    		fscanf(it,"%[^#]#%[^\n]\n",&tujuann[tujuan].kota,&tujuann[tujuan].jam);
    		tujuan++;
		}
		fclose(it);
		while(1){
		printf("=================================================\n");
		printf("||-----------Jam Keberangkatan Medan-----------||\n");
		printf("=================================================\n");
		for(int a=0;a<tujuan;a++){
			printf("%s -> %s (%s)\n",ticket[0].kota_asal,tujuann[a].kota, tujuann[a].jam);
		}
		printf("=================================================\n");
		printf("(Enter 0 two times to go back)\n");
		printf("Contoh format input tujuan kota: Jakarta 08.35 - 10.20\n");
		printf("Masukkan nama kota tujuan yang anda inginkan: ");
		scanf("%s %[^\n]", ticket[0].kota_tujuan, ticket[0].jam_tujuan); getchar();
		if(strcmp(ticket[0].kota_tujuan, "0") == 0){
			strcpy(ticket[0].kota_tujuan, "");
			goto begin_menu;
		}
		else{
				for(int i=0; i<4; i++){
					if(strcmp(tujuann[i].kota, ticket[0].kota_tujuan) == 0 && strcmp(tujuann[i].jam, ticket[0].jam_tujuan) == 0){
						check4 = 1;
						goto begin_menu;
					}
				}
				system("cls");
				printf("\t     _____   ____ __________________________  _____   ________________\n");
				printf("\t    /    /  /   //    /  ___    \\            \\     \\ |   |            \\ \n");
				printf("\t   /    /  /   //    /  /   /    | ______     |    | |   |   __________|\n");
				printf("\t  /    /  /   //    /     ______/ |      |    |    | |   |  /     ____\n");
				printf("\t /    /  /   //    /      \\   |   |      |    |    | /   |  |    /_   \\ \n");
				printf("\t/     \\_/  _      /    /\\  \\  |   |______|    |    |/    |  \\______|   | \n");
				printf("\t\\         / \\    /    /  \\  \\ |               | |\\       |             | \n");
				printf("\t \\_______/   \\__/    /    \\__\\ \\ ___________ /__| \\ ____/ \\___________/\n");				
				printf("\n\tWrong Input! You have to enter the city name correctly!\n");
				sleep(2);
				system("cls");
			}
		}
		}
		if(strcmp(ticket[0].kota_asal, "Makassar") == 0){
			int tujuan = 0;
		FILE *it=fopen("jam_keberangkatan_makassar.txt","r");
		while(!feof(it)){
    		fscanf(it,"%[^#]#%[^\n]\n",&tujuann[tujuan].kota,&tujuann[tujuan].jam);
    		tujuan++;
		}
		fclose(it);
		while(1){
		printf("=================================================\n");
		printf("||----------Jam Keberangkatan Makassar----------||\n");
		printf("=================================================\n");
		for(int a=0;a<tujuan;a++){
			printf("%s -> %s (%s)\n",ticket[0].kota_asal,tujuann[a].kota, tujuann[a].jam);
		}
		printf("=================================================\n");
		printf("(Enter 0 two times to go back)\n");
		printf("Contoh format input tujuan kota: Jakarta 08.35 - 10.20\n");
		printf("Masukkan nama kota tujuan yang anda inginkan: ");
		scanf("%s %[^\n]", ticket[0].kota_tujuan, ticket[0].jam_tujuan); getchar();
		if(strcmp(ticket[0].kota_tujuan, "0") == 0){
			strcpy(ticket[0].kota_tujuan, "");
			goto begin_menu;
		}
		else{
				for(int i=0; i<6; i++){
					if(strcmp(tujuann[i].kota, ticket[0].kota_tujuan) == 0 && strcmp(tujuann[i].jam, ticket[0].jam_tujuan) == 0){
						check4 = 1;
						goto begin_menu;
					}
				}
				system("cls");
				printf("\t     _____   ____ __________________________  _____   ________________\n");
				printf("\t    /    /  /   //    /  ___    \\            \\     \\ |   |            \\ \n");
				printf("\t   /    /  /   //    /  /   /    | ______     |    | |   |   __________|\n");
				printf("\t  /    /  /   //    /     ______/ |      |    |    | |   |  /     ____\n");
				printf("\t /    /  /   //    /      \\   |   |      |    |    | /   |  |    /_   \\ \n");
				printf("\t/     \\_/  _      /    /\\  \\  |   |______|    |    |/    |  \\______|   | \n");
				printf("\t\\         / \\    /    /  \\  \\ |               | |\\       |             | \n");
				printf("\t \\_______/   \\__/    /    \\__\\ \\ ___________ /__| \\ ____/ \\___________/\n");				
				printf("\n\tWrong Input! You have to enter the city name correctly!\n");
				sleep(2);
				system("cls");
			}
		}
		}
		if(strcmp(ticket[0].kota_asal, "Denpasar") == 0){
			int tujuan = 0;
		FILE *it=fopen("jam_keberangkatan_denpasar.txt","r");
		while(!feof(it)){
    		fscanf(it,"%[^#]#%[^\n]\n",&tujuann[tujuan].kota,&tujuann[tujuan].jam);
    		tujuan++;
		}
		fclose(it);
		while(1){
		printf("=================================================\n");
		printf("||---------Jam Keberangkatan Denpasar----------||\n");
		printf("=================================================\n");
		for(int a=0;a<tujuan;a++){
			printf("%s -> %s (%s)\n",ticket[0].kota_asal,tujuann[a].kota, tujuann[a].jam);
		}
		printf("=================================================\n");
		printf("(Enter 0 two times to go back)\n");
		printf("Contoh format input tujuan kota: Jakarta 08.35 - 10.20\n");
		printf("Masukkan nama kota tujuan yang anda inginkan: ");
		scanf("%s %[^\n]", ticket[0].kota_tujuan, ticket[0].jam_tujuan); getchar();
		if(strcmp(ticket[0].kota_tujuan, "0") == 0){
			strcpy(ticket[0].kota_tujuan, "");
			goto begin_menu;
		}
		else{
				for(int i=0; i<5; i++){
					if(strcmp(tujuann[i].kota, ticket[0].kota_tujuan) == 0 && strcmp(tujuann[i].jam, ticket[0].jam_tujuan) == 0){
						check4 = 1;
						goto begin_menu;
					}
				}
				system("cls");
				printf("\t     _____   ____ __________________________  _____   ________________\n");
				printf("\t    /    /  /   //    /  ___    \\            \\     \\ |   |            \\ \n");
				printf("\t   /    /  /   //    /  /   /    | ______     |    | |   |   __________|\n");
				printf("\t  /    /  /   //    /     ______/ |      |    |    | |   |  /     ____\n");
				printf("\t /    /  /   //    /      \\   |   |      |    |    | /   |  |    /_   \\ \n");
				printf("\t/     \\_/  _      /    /\\  \\  |   |______|    |    |/    |  \\______|   | \n");
				printf("\t\\         / \\    /    /  \\  \\ |               | |\\       |             | \n");
				printf("\t \\_______/   \\__/    /    \\__\\ \\ ___________ /__| \\ ____/ \\___________/\n");				
				printf("\t\nWrong Input! You have to enter the city name correctly!\n");
				sleep(2);
				system("cls");
			}
		}
		}
		if(strcmp(ticket[0].kota_asal, "Padang") == 0){
			int tujuan = 0;
		FILE *it=fopen("jam_keberangkatan_padang.txt","r");
		while(!feof(it)){
    		fscanf(it,"%[^#]#%[^\n]\n",&tujuann[tujuan].kota,&tujuann[tujuan].jam);
    		tujuan++;
		}
		fclose(it);
		while(1){
		printf("=================================================\n");
		printf("||----------Jam Keberangkatan Padang-----------||\n");
		printf("=================================================\n");
		for(int a=0;a<tujuan;a++){
			printf("%s -> %s (%s)\n",ticket[0].kota_asal,tujuann[a].kota, tujuann[a].jam);
		}
		printf("=================================================\n");
		printf("(Enter 0 two times to go back)\n");
		printf("Contoh format input tujuan kota: Jakarta 08.35 - 10.20\n");
		printf("Masukkan nama kota tujuan yang anda inginkan: ");
		scanf("%s %[^\n]", ticket[0].kota_tujuan, ticket[0].jam_tujuan); getchar();
		if(strcmp(ticket[0].kota_tujuan, "0") == 0){
			strcpy(ticket[0].kota_tujuan, "");
			goto begin_menu;
		}
		else{
				for(int i=0; i<4; i++){
					if(strcmp(tujuann[i].kota, ticket[0].kota_tujuan) == 0 && strcmp(tujuann[i].jam, ticket[0].jam_tujuan) == 0){
						check4 = 1;
						goto begin_menu;
					}
				}
				system("cls");
				printf("\t     _____   ____ __________________________  _____   ________________\n");
				printf("\t    /    /  /   //    /  ___    \\            \\     \\ |   |            \\ \n");
				printf("\t   /    /  /   //    /  /   /    | ______     |    | |   |   __________|\n");
				printf("\t  /    /  /   //    /     ______/ |      |    |    | |   |  /     ____\n");
				printf("\t /    /  /   //    /      \\   |   |      |    |    | /   |  |    /_   \\ \n");
				printf("\t/     \\_/  _      /    /\\  \\  |   |______|    |    |/    |  \\______|   | \n");
				printf("\t\\         / \\    /    /  \\  \\ |               | |\\       |             | \n");
				printf("\t \\_______/   \\__/    /    \\__\\ \\ ___________ /__| \\ ____/ \\___________/\n");				
				printf("\n\tWrong Input! You have to enter the city name correctly!\n");
				sleep(2);
				system("cls");
			}
		}
		}
		if(strcmp(ticket[0].kota_asal, "Palembang") == 0){
			int tujuan = 0;
		FILE *it=fopen("jam_keberangkatan_palembang.txt","r");
		while(!feof(it)){
    		fscanf(it,"%[^#]#%[^\n]\n",&tujuann[tujuan].kota,&tujuann[tujuan].jam);
    		tujuan++;
		}
		fclose(it);
		while(1){
		printf("=================================================\n");
		printf("||---------Jam Keberangkatan Palembang---------||\n");
		printf("=================================================\n");
		for(int a=0;a<tujuan;a++){
			printf("%s -> %s (%s)\n",ticket[0].kota_asal,tujuann[a].kota, tujuann[a].jam);
		}
		printf("=================================================\n");
		printf("(Enter 0 two times to go back)\n");
		printf("Contoh format input tujuan kota: Jakarta 08.35 - 10.20\n");
		printf("Masukkan nama kota tujuan yang anda inginkan: ");
		scanf("%s %[^\n]", ticket[0].kota_tujuan, ticket[0].jam_tujuan); getchar();
		if(strcmp(ticket[0].kota_tujuan, "0") == 0){
			strcpy(ticket[0].kota_tujuan, "");
			goto begin_menu;
		}
		else{
				for(int i=0; i<4; i++){
					if(strcmp(tujuann[i].kota, ticket[0].kota_tujuan) == 0 && strcmp(tujuann[i].jam, ticket[0].jam_tujuan) == 0){
						check4 = 1;
						goto begin_menu;
					}
				}
				system("cls");
				printf("\t     _____   ____ __________________________  _____   ________________\n");
				printf("\t    /    /  /   //    /  ___    \\            \\     \\ |   |            \\ \n");
				printf("\t   /    /  /   //    /  /   /    | ______     |    | |   |   __________|\n");
				printf("\t  /    /  /   //    /     ______/ |      |    |    | |   |  /     ____\n");
				printf("\t /    /  /   //    /      \\   |   |      |    |    | /   |  |    /_   \\ \n");
				printf("\t/     \\_/  _      /    /\\  \\  |   |______|    |    |/    |  \\______|   | \n");
				printf("\t\\         / \\    /    /  \\  \\ |               | |\\       |             | \n");
				printf("\t \\_______/   \\__/    /    \\__\\ \\ ___________ /__| \\ ____/ \\___________/\n");				
				printf("\n\tWrong Input! You have to enter the city name correctly!\n");
				sleep(2);
				system("cls");
			}
		}
		}
	}	
	else if(menu_tujuan == 5){
		if(check5 == 1){
				system("cls");
			printf("\t||===========================================================================||\n");
			printf("\t||   _________ ______   ______ ___  __ ______  ___  _   __   __    __     __ ||\n");
			printf("\t||  /___  ___//      \\ / __  //  / / //  ___/ /  / | | / /  / /   / /    / / || \n");
			printf("\t||     / /   / _  ___// /_/ //  / / //  /__  /  /  | |/ /  / /   / //\\  / /  ||\n");
			printf("\t||    / /   / / \\ \\  / __  //  / / //   __/ /  /   |    \\ / /   / / \\ \\/ /   || \n");
			printf("\t||   / /   / /   \\_\\/ / / / \\  \\/ //   /__ /  /___ |  /\\ \\\\ \\_ / /   \\  /    ||\n");
			printf("\t||  /_/   /_/      /_/ /_/   \\___//______//______/ |_|  \\_\\\\____/    / /     ||\n");
			printf("\t||                                                                  /_/      ||\n");
			printf("\t||===========================================================================||\n");					
				printf("\n\n\tYou have chosen your amount of passengers! Please proceed to the next section!\n");
				sleep(2);
				system("cls");
				goto begin_menu;
		}
		int menu_usia;
		system("cls");
		int penumpang=0;
		FILE *it=fopen("usia_penumpang.txt","r");
		while(!feof(it)){
    		fscanf(it,"%[^#]#%[^\n]\n",&penumpangg[penumpang].usia,&penumpangg[penumpang].umur);
    		penumpang++;
		}
		fclose(it);
		while(1){
		printf("======================================\n");
		printf("||----------Usia Penumpang----------||\n");
		printf("======================================\n");
		printf("||----------Kategori Usia-----------||\n");
		for(int a=0;a<penumpang;a++){
			printf("|| %d. %s %s\n",a+1, penumpangg[a].usia, penumpangg[a].umur);
		}
		printf("======================================\n");
		printf("\n(Enter 0 two times to go back)\n");
		printf("Contoh format input jumlah penumpang: 3 Dewasa\n");
		printf("Berapa banyak orang dewasa yang ikut (Minimal 1 orang dewasa): ");
		scanf("%d %s", &ticket[0].jumlah_dewasa, ticket[0].usia_dewasa); getchar();
		if(ticket[0].jumlah_dewasa == 0){
			goto begin_menu;
		}
		printf("Berapa banyak anak - anak yang ikut: ");
		scanf("%d %[^\n]", &ticket[0].jumlah_anakanak, ticket[0].usia_anakanak); getchar();
		printf("Berapa banyak balita yang ikut: ");
		scanf("%d %s", &ticket[0].jumlah_balita, ticket[0].usia_balita); getchar();
		if(ticket[0].jumlah_dewasa != 0){
				for(int i=0; i<3; i++){
					if(strcmp("Dewasa", ticket[0].usia_dewasa) == 0 
					&& strcmp("Anak - anak", ticket[0].usia_anakanak) == 0 
					&& strcmp("Balita", ticket[0].usia_balita) == 0){
						check5 = 1;
						goto begin_menu;
					}
				}
				system("cls");
				printf("\t     _____   ____ __________________________  _____   ________________\n");
				printf("\t    /    /  /   //    /  ___    \\            \\     \\ |   |            \\ \n");
				printf("\t   /    /  /   //    /  /   /    | ______     |    | |   |   __________|\n");
				printf("\t  /    /  /   //    /     ______/ |      |    |    | |   |  /     ____\n");
				printf("\t /    /  /   //    /      \\   |   |      |    |    | /   |  |    /_   \\ \n");
				printf("\t/     \\_/  _      /    /\\  \\  |   |______|    |    |/    |  \\______|   | \n");
				printf("\t\\         / \\    /    /  \\  \\ |               | |\\       |             | \n");
				printf("\t \\_______/   \\__/    /    \\__\\ \\ ___________ /__| \\ ____/ \\___________/\n");				
				printf("\n\tWrong Input! You have to enter the amount of passengers correctly!\n");
				sleep(2);
				system("cls");
			}
		}
	}
	else if(menu_tujuan == 6){
		int jumlahdewasa = ticket[0].jumlah_dewasa;
		int jumlahanak = ticket[0].jumlah_anakanak;
		int jumlahbalita = ticket[0].jumlah_balita;
		if(check6 == 1){
				system("cls");
			printf("\t||===========================================================================||\n");
			printf("\t||   _________ ______   ______ ___  __ ______  ___  _   __   __    __     __ ||\n");
			printf("\t||  /___  ___//      \\ / __  //  / / //  ___/ /  / | | / /  / /   / /    / / || \n");
			printf("\t||     / /   / _  ___// /_/ //  / / //  /__  /  /  | |/ /  / /   / //\\  / /  ||\n");
			printf("\t||    / /   / / \\ \\  / __  //  / / //   __/ /  /   |    \\ / /   / / \\ \\/ /   || \n");
			printf("\t||   / /   / /   \\_\\/ / / / \\  \\/ //   /__ /  /___ |  /\\ \\\\ \\_ / /   \\  /    ||\n");
			printf("\t||  /_/   /_/      /_/ /_/   \\___//______//______/ |_|  \\_\\\\____/    / /     ||\n");
			printf("\t||                                                                  /_/      ||\n");
			printf("\t||===========================================================================||\n");	
				printf("\n\n\tYou have chosen your payment choice! Please proceed to the next section!\n");
				sleep(2);
				system("cls");
				goto begin_menu;
		}
		system("cls");
		while(1){
		menu_pembayaran();
		printf("\n(Enter 0 to go back)\n");
		printf("Masukkan nama jenis pembayaran yang anda inginkan: ");
		scanf("%[^\n]", ticket[0].pembayaran); getchar();
		if(strcmp(ticket[0].pembayaran, "0") == 0){
			strcpy(ticket[0].pembayaran, "");
			goto begin_menu;
		}
		else{
				for(int i=0; i<2; i++){
					if(strcmp("Kredit", ticket[0].pembayaran) == 0){
						system("cls");
						printf("----------- Total Pembayaran -----------\n\n");
						if(ekonomicheck == 1){
							hargadewasa1 = ticket[0].harga;
							printf("%lld", hargadewasa1);
							printf("Tiket Penerbangan Maskapai Ekonomi\n");
						}
						else if(bisnischeck == 1){
							hargadewasa1 = ticket[0].harga;
							printf("Tiket Penerbangan Maskapai Bisnis\n");
						}
						else if(eksekutifcheck == 1){
							hargadewasa1 = ticket[0].harga;
							printf("Tiket Penerbangan Maskapai Eksekutif\n");
						}
						hargadewasa = hargadewasa1 * jumlahdewasa;
							hargaanak1 = hargadewasa1 * 0.7;
							hargaanak = hargaanak1 * jumlahanak;
							hargabalita1 = hargadewasa1* 0.5;
							hargabalita = hargabalita1 * jumlahbalita;
							ppn =  (hargadewasa + hargaanak + hargabalita) * ppnkredit;
							totalharga = hargadewasa + hargaanak + hargabalita + ppn;
							ticket[0].harga = totalharga;
							printf("Dewasa: %d \t\t\t\t Rp.%lld\n", jumlahdewasa, hargadewasa);
							printf("Anak - anak: %d \t\t\t\t Rp.%lld\n", jumlahanak, hargaanak);
							printf("Balita: %d \t\t\t\t Rp.%lld\n", jumlahbalita, hargabalita);
							printf("PPN: 15%% \t\t\t\t Rp.%lld\n", ppn);
							printf("Total Harga: \t\t\t\t Rp.%lld\n", totalharga);
							printf("\nPress anything to continue...\n");
							getch();
						check6 = 1;
						goto begin_menu;
					}
					else if(strcmp("Debit", ticket[0].pembayaran) == 0){
						system("cls");
						printf("----------- Total Pembayaran -----------\n\n");
						if(ekonomicheck == 1){
							hargadewasa1 = ticket[0].harga;
							printf("Tiket Penerbangan Maskapai Ekonomi\n");
						}
						else if(bisnischeck == 1){
							hargadewasa1 = ticket[0].harga;
							printf("Tiket Penerbangan Maskapai Bisnis\n");
						}
						else if(eksekutifcheck == 1){
							hargadewasa1 = ticket[0].harga;
							printf("Tiket Penerbangan Maskapai Eksekutif\n");
						}
						hargadewasa = hargadewasa1 * jumlahdewasa;
							hargaanak1 = hargadewasa1 * 0.7;
							hargaanak = hargaanak1 * jumlahanak;
							hargabalita1 = hargadewasa1* 0.5;
							hargabalita = hargabalita1 * jumlahbalita;
							ppn =  (hargadewasa + hargaanak + hargabalita) * ppndebit;
							totalharga = hargadewasa + hargaanak + hargabalita + ppn;
							ticket[0].harga = totalharga;
							printf("Dewasa: %d \t\t\t\t Rp.%lld\n", jumlahdewasa, hargadewasa);
							printf("Anak - anak: %d \t\t\t\t Rp.%lld\n", jumlahanak, hargaanak);
							printf("Balita: %d \t\t\t\t Rp.%lld\n", jumlahbalita, hargabalita);
							printf("PPN: 10%% \t\t\t\t Rp.%lld\n", ppn);
							printf("Total Harga: \t\t\t\t Rp.%lld\n", totalharga);
							printf("\nPress anything to continue...\n");
							getch();
						check6 = 1;
						goto begin_menu;
					}
				}
				system("cls");
				printf("\t     _____   ____ __________________________  _____   ________________\n");
				printf("\t    /    /  /   //    /  ___    \\            \\     \\ |   |            \\ \n");
				printf("\t   /    /  /   //    /  /   /    | ______     |    | |   |   __________|\n");
				printf("\t  /    /  /   //    /     ______/ |      |    |    | |   |  /     ____\n");
				printf("\t /    /  /   //    /      \\   |   |      |    |    | /   |  |    /_   \\ \n");
				printf("\t/     \\_/  _      /    /\\  \\  |   |______|    |    |/    |  \\______|   | \n");
				printf("\t\\         / \\    /    /  \\  \\ |               | |\\       |             | \n");
				printf("\t \\_______/   \\__/    /    \\__\\ \\ ___________ /__| \\ ____/ \\___________/\n");				
				printf("\n\tWrong Input! You have to enter the payment choice correctly!\n");
				sleep(2);
				system("cls");
			}
		}
	}
	else if(menu_tujuan == 7){
		if(check1 == 1 && check2 == 1 && check3 == 1 && check4 == 1 && check5 ==1 && check6 == 1){
		ticket1[0].check= 1;
		FILE *fcek;
		fcek = fopen("ticket.txt", "a+");
		fprintf(fcek, "%s#%d#%d#%s#%lld#%s#%s#%s#%d#%s#%d#%s#%d#%s#%s#%d\n", user_data[0].account1, ticket[0].tanggal, ticket[0].bulan, 
														  ticket[0].maskapai, ticket[0].harga, ticket[0].kota_asal, 
														  ticket[0].kota_tujuan, ticket[0].jam_tujuan, ticket[0].jumlah_dewasa, 
														  ticket[0].usia_dewasa, ticket[0].jumlah_anakanak, ticket[0].usia_anakanak, 
														  ticket[0].jumlah_balita, ticket[0].usia_balita, ticket[0].pembayaran, ticket1[0].check);
		fclose(fcek);
		system("cls");
		printf("\n----------------------------------------------------\n");
		printf("                   CONGRATULATIONS!                \n");
		printf("----------------------------------------------------\n");
		printf("                        WELCOME                     \n");
		printf("                        ABOARD                      \n");
		printf("                      PASSENGER's!                  \n");
		printf("----------------------------------------------------\n");
		printf("      You have succesfully bought your tickets!     \n");
		printf("\n");
		printf("You can check your ticket in the start menu section!\n");
		printf("----------------------------------------------------\n");
		sleep(2);
		system("cls");
		goto begin_1;
		}
		else{
			system("cls");
				printf("\t     _____   ____ __________________________  _____   ________________\n");
				printf("\t    /    /  /   //    /  ___    \\            \\     \\ |   |            \\ \n");
				printf("\t   /    /  /   //    /  /   /    | ______     |    | |   |   __________|\n");
				printf("\t  /    /  /   //    /     ______/ |      |    |    | |   |  /     ____\n");
				printf("\t /    /  /   //    /      \\   |   |      |    |    | /   |  |    /_   \\ \n");
				printf("\t/     \\_/  _      /    /\\  \\  |   |______|    |    |/    |  \\______|   | \n");
				printf("\t\\         / \\    /    /  \\  \\ |               | |\\       |             | \n");
				printf("\t \\_______/   \\__/    /    \\__\\ \\ ___________ /__| \\ ____/ \\___________/\n");			
				printf("\n\tYou haven't finished your order, please complete it first!\n");
				sleep(2);
				system("cls");
				goto begin_menu;
		}
	}
	else if(menu_tujuan != 1 && menu_tujuan != 2 && menu_tujuan != 3 && 
			menu_tujuan != 4 && menu_tujuan != 5 && menu_tujuan != 6 && 
			menu_tujuan != 7 && menu_tujuan != 8){
			goto begin_menu;
	}
	}
	else{
		system("cls");
				printf("\t     _____   ____ __________________________  _____   ________________\n");
				printf("\t    /    /  /   //    /  ___    \\            \\     \\ |   |            \\ \n");
				printf("\t   /    /  /   //    /  /   /    | ______     |    | |   |   __________|\n");
				printf("\t  /    /  /   //    /     ______/ |      |    |    | |   |  /     ____\n");
				printf("\t /    /  /   //    /      \\   |   |      |    |    | /   |  |    /_   \\ \n");
				printf("\t/     \\_/  _      /    /\\  \\  |   |______|    |    |/    |  \\______|   | \n");
				printf("\t\\         / \\    /    /  \\  \\ |               | |\\       |             | \n");
				printf("\t \\_______/   \\__/    /    \\__\\ \\ ___________ /__| \\ ____/ \\___________/\n");		
		printf("\n\tWrong Input\n");
		sleep(2);
		system("cls");
		goto begin_1;	}
}
	
	return 0;
}
