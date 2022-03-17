#include <stdio.h>
#define f 19

int a[f];
int parity;
int i;

void getData(){
	printf("Enter the values to be sent to receiver (Only 10 bits)\n");
	printf("---------------------------------------------\n");
	for(i=8;i<18;i++)
		scanf("%d", &a[i]);
}
/*	Grouping is done. 
	Error control <-- left
	Address is also added. <-- right 
	*/
void enterAddress(){
	printf("Enter address for the data (Only 8 bits)\n");
	printf("----------------------------------------------\n");
	for(i=0;i<8;i++){
		scanf("%d", &a[i]);
	}
}

void makeFrame(){
	printf("-----------------------------------------------\n");
	printf("Enter the parity bit (Either '0' or '1'\n");
	scanf("%d", &parity);
}

void sendFrame(){
	a[18] = parity;
}

void receiveFrame(){
	printf("-----------------------------------\n");
	printf("Received frame is as follows: \n\n");
	printf("-------------------------------------------------------------\n");
	for(i=0;i<f;i++){
		printf("%d  ", a[i]);
	}

	printf("\n");
	printf("-------------------------------------------------------------\n");
}

void extractData(){
	printf("The data part from the frame is as follows: \n\n");
	printf("----------------------------------------------------\n");
	for(i=8;i<18;i++){
		printf("%d  ", a[i]);
	}

	printf("\n");
	printf("----------------------------------------------------\n");
}

int main(){
	getData();
	enterAddress();
	makeFrame();
	sendFrame();
	receiveFrame();
	extractData();

	return 0;
}