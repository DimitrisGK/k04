#include <stdio.h>
#include <stdlib.h>
#include "shopdp.h"

int main(void){
int m, n, *k, **c, i, j;
if (getchar()!=EOF) m=getchar();
if (getchar()!=EOF) n=getchar(); //παιρνω το n απο την εισοδο
k=malloc(n*sizeof(int));  //βρισκω μεγεθος για τον *k μεσω του n
if(k==NULL) return -1; //ελεγχω αν δεσμευτηκε
c=malloc(n*sizeof(int*));  //βρισκω την μια διαστηση του **c απο το k
if(c==NULL) return -1;
for (i=0; i<n; i++){
	if (getchar()!=EOF) k[i]=getchar();  //προσθετω τιμες στον πινακα *k
	*(c+i)=malloc(k[i]*sizeof(int)); //βρισκω την δευτερη διασταση του **c
	if(*(c+i)==NULL) return -1;
	for(j=0; j<=k[i]; j++){
		if (getchar()!=EOF) c[i][j]=getchar(); //προσθετω τον πινακα c**
	}
}
int max_amount;
max_amount=shopdp(m, n, k, c);
printf("Maximum amount spent is:%d\n",max_amount);
free(k);
for (i=0; i<n; i++){
	free(*(c+i));
}
free(c);
}