int shopdp(int m, int n, int *k, int **c){ 
int **pb, i, j; //δημιουργω πινακα που θα αποθηκευει 0,1 
pb=malloc(n*sizeof(int*));
if (pb==NULL) return -1;
for(i=0; i<n; i++){
	*(pb+i)=malloc((m+1)*sizeof(int));
	if(*(pb+i)==NULL) return -1;
}
int l=0; //βοηθητικη μεταβλητη
for(i=0; i<n; i++){
	for(j=0; j<(m+1); j++){
		pb[i][j]=0; //αρχικοποιω τον πινακα pb με 0
		if(i==0 && j>=1 && j<=k[i]){
			pb[1][m-c[i][j]]=1;
		}
		else if(pb[i-1][j]==1){
			for(l=0; l<=k[i]; l++)
				pb[i][j-c[i][l]]=1; 
		}
	}
}
int max=0;  
for(j=0; j<(m+1); j++){ //βρισκω το μεγιστο ποσο
	if(pb[n-1][j]==1){
		max=m-pb[n-1][j];
		break;
	}
}
for(i=0; i<n; i++){
	free(*(pb+i));
}
free(pb);
return max; //επιστρεφω το μεγισοτ ποσο (αν υπαρχει) ή 0
}