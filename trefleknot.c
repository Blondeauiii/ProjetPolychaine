#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


// Fonction principale
int main(){
	srand(time(NULL));
	// Déclaration des variables
	FILE *pf1;
	
	int k, i;
	int nat;
	pf1 = fopen("ctrl.in", "r");
	fscanf(pf1, "%d \n", &nat);
	fclose(pf1);
	
	double rx[nat], ry[nat], rz[nat];
	
	int div = nat/10;
	
	for(k=0; k<(3*div); k++){
	rx[k] = k; 
	ry[k] = 0.0;
	rz[k] = 0.0;
	}
	for(k=0; k<(2*div); k++){
	rx[k+3*div] = 2*div + div*cos(k*5*M_PI/(2*6*div)); 
	ry[k+3*div] = div*sin(5*k*M_PI/(2*6*div));
	rz[k+3*div] = 0.0;
	}
	for(k=0; k<(2*div); k++){
	rx[k+5*div] = rx[5*div-1]+ k*0.5; 
	ry[k+5*div] = 0.5*div*cos(k*2.5*M_PI/(2*div));
	rz[k+5*div] = 0.5*div*sin(k*2.5*M_PI/(2*div));
	}
		for(k=0; k<(3*div); k++){
	rx[k+7*div] = rx[7*div-1]+k; 
	ry[k+7*div] = ry[7*div-1];
	rz[k+7*div] = rz[7*div-1];
	}
	
	// Écriture des fichiers de sortie
	pf1 = fopen("chaine.dat", "w");
	for(i=0; i<nat; i++){
		fprintf(pf1, "%lf %lf %lf\n", rx[i], ry[i], rz[i]);
	}
	fclose(pf1);
	
	pf1 = fopen("chaine.xyz", "w");
	fprintf(pf1, "%d\npolymère\n", nat);
	for(i=0; i<nat; i++){
		fprintf(pf1, "C %lf %lf %lf\n", rx[i], ry[i], rz[i]);
	}
	fclose(pf1);
	
} // Fin du main
