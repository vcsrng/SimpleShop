#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int item=0;
	char name[20][10], buy[20][10];
	int choice;
	int buyqty[1001], qty[1001];
	int buyprice[100001], price[100001];
	int beli=0;
	
	do{
		system("cls");
		printf(" ___________________\n");
		printf("|                   |\n");
		printf("|--- Simple Shop ---|\n");
		printf("|___________________|\n\n");
		printf("1. Show item\n");
		printf("2. Register new item\n");
		printf("3. Buy item\n");
		printf("4. Check out and Exit\n");
		printf("Input[1-4] : ");
		scanf("%d", &choice);
	switch(choice){
		case 1:
			if(item==0){
				printf("There is no item...");
			}else if(item>=0  && item<=9){
				for(int a=0;a<item;a++){
					for(int b=0;b<1;b++){
					printf("%d. %s %d %d\n", a+1, &name[a][b], qty[a], price[a]);
					}
				}
			}
			getch();
			break;
		case 2:
			if(item>=0 && item<=9){
				printf("Item name[without space]: ");
        		scanf("%s", &name[item]);
        		printf("Quantity[1-1000]: ");
        		scanf("%d", &qty[item]);
        		printf("Price[1-100000]: ");
        		scanf("%d", &price[item]);
				printf("Item registered...");
				item+=1;
			}else{
				printf("Oh no, in this case you cannot input more item...");
			}
			getch();
			break;
		case 3:
			if(item>0){
			printf("Input item name[without space]: ");
			scanf("%s", buy[beli]);
			for(int a=0;a<item;a++){
				for(int b=beli;b<=beli;b++){
					if(strcmp(buy[b],name[a])==0){
						printf("Input quantity to buy[Max.%d]: ", qty[a]);
						scanf("%d", &buyqty[b]);
						if(buyqty[b]>qty[a]){
							printf("Oh sorry, you can't buy more than stock...");
						}else{
							printf("Item added to cart");
							qty[a]=qty[a]-buyqty[b];
							buyprice[b]=buyqty[b]*price[a];
							beli+=1;
						}
					}
				}
			}
			}else{
				printf("There is no item...");
			}
			getch();
			break;
		case 4:
			if(item>0){
			printf(" ___________________\n");
			printf("|                   |\n");
			printf("|---- Check Out ----|\n");
			printf("|___________________|\n\n");
			for(int e=0;e<beli;e++){
					printf("%d.  Item name\t : %s\n    Quantity\t : %d\n    You must pay : %d\n", e+1, &buy[e], buyqty[e], buyprice[e]);
				}
			}else{
				return 0;
			}
			getch();
			break;
		default:
			printf("No options hey...\n");
			getch();
	}
	}while(choice!=4);
	return 0;
}
