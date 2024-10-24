/*kalmpr.c*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define MINNUM 100
#define MAXNUM 100000
#define MAXK 5
#define COMPUTATIONS 20

int main(){
	int n; // n ειναι ο υποψηφιος αριθμος
    int plk=0; //plk ειναι το πληθος των k-οστων αριθμων
	int plsp=0; //plsp ειναι το πληθος tων semiprime
    int y, x, z; // απλες μεταβλητες
    int i; //i ειναι ο διαιρετης 
    int exp; //exp ειναι το πληθος των παραγοντων
	long curtime;
	curtime = time(NULL); 
	srand(curtime);
    printf("Cheking numbers in [%d , %d]\n\n", MINNUM, MAXNUM);
    for (n=MINNUM; n<=MAXNUM; n++){
        x=n; //κανω τον n ισο με x για να μπορω να τον 'θυμαμαι'
        exp=0;
        i=3;
        int exp1=0, exp2=0; //ειναι οι δυο πρωτοι παραγοντες
        while(x%2==0 && x!=0){
            x=x/2;  //βρισκω αν το 2 ειναι πρωτος παραγοντας και ποσες φορες
            exp++;  //ωστε μετα να κινουμε στους περιττους αριθμους
            exp1=2;
        }
        while(i<=n/2 && exp<=MAXK){  
            if(x%i==0){
                x=x/i;
                exp++;
                if(exp1!=exp2 && exp1!=0)
                    exp2=i;
                else 
                    exp1=i;
            }
            else{
                i+=2;
                continue;
            }
            if(exp>=MAXK)
                break;
        }
        if(exp==2){   
            plsp+=1; 
            int diafexp;
            int max=0, min=0;
            if(exp1>exp2){ //βρισκω αν ο μικροτερος exp απεχει περισσοτερο απο 1% 
                max=exp1;
                min=exp2;
            }
            else if(exp2>exp1){
                max=exp2;
                min=exp1;
            }
            else if(exp1==exp2){
                continue;
            }
            diafexp=max-min;
            double d1; //d1 ειναι το 1% του max
            d1=max/100;
            if (diafexp<=d1){
                printf("%d * %d = %d is an interesting semiprime\n", min, max, n);
            }
        }
        if(exp>1 && exp<=MAXK){
            plk+=1;
        }    
    }
    printf("Found %d k-almost prime numbers (2<=k<=%d)\n", plk, MAXK);
    printf("Found %d semiprimes\n\n", plsp); 
    printf("Current time is %ld\n\n", curtime);
    printf("Cheking %d random numbers\n\n", COMPUTATIONS);
    for (int p=1; p<=COMPUTATIONS;){
        y = rand()%MAXNUM+1;
        z = rand()% MAXNUM+1;   
        x = ((y%32768)+1)*((z%32768)+1)+1;
        n=x; //κανω τον n ισο με x για να μπορω να τον 'θυμαμαι'
        exp=0;
        i=3;
        while(x%2==0 && x!=0 && exp<=MAXK){
            x=x/2;
            exp+=1;
        }
        while(i<=n && exp<=MAXK){
            if(x%i==0){
                x=x/i;
                exp++;
            }
            else{
                i+=2;
                continue;
            }
        }
        if(exp!=0 && exp!=1){
            printf("%d is an %d-almost prime number\n", n, exp); 
            p++;
        }
    }           
}