#include <stdio.h>

int getParity(int n)
{
    int parity = 0;
    while (n)
    {
        parity = !parity;
        n = n & (n - 1);
    }        
    return parity;
}

int convert(int dec){

    if (dec == 0)
        return 0;
    else
        return (dec % 2 + 10 * convert(dec / 2));
}

int sender(){
    int num;
    printf("Enter a number for parity check\n");
    printf("-----------------------------\n");
    scanf("%d", &num);
    return num;
}

void receiver(int m){
    int result = getParity(m);
    printf("-----------------------------\n");
    printf("Binary equivalent of %d = %d\n", m, convert(m));
    printf("-----------------------------\n");
    if(result == 1)
        printf("Parity of %d = odd\n", m);
    else
        printf("Parity of %d = even\n", m);
}

int main(){
    int sender_val = sender();
    receiver(sender_val);
    printf("-----------------------------\n");
    return 0;
}