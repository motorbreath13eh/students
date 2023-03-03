#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_SIZE 50
//#define ARITHMOS_MATHITWN 1
#define ARITHMOS_MATHITWN 10

/* Ν.γ πρόγραμμα σε C το οποίο να ζητάει από το χρήστη να δώσει για 10 μαθητές μιας τάξης τα εξής:
το όνομα μαθητή, το επώνυμο, το βαθμό προόδου(με βαρύτητα 40%) και τον τελικό βαθμό(με βαρύτητα 60%).
Η εφαρμογή θα πρέπει να εκτυπώνει όλα τα δεδομένα σε κατακόρυφους πίνακες ο ένας δίπλα από τον άλλο.
Θα πρέπει να εκτυπωθεί κι ένας πίνακας με το μέσο όρο κάθε μαθητή(με τις βαρύτητες).
Τέλος η εφαρμογή θα εκτυπώνει το ονοματεπώνυμο και το μέσο όρο των καλύτερων και των "μαθητών που
θέλουν φροντιστήριο".*/

int main()
{
	system("CHCP 1253>nul");
	
	char onoma_mathiti[ARITHMOS_MATHITWN][STR_SIZE], epwnumo_mathiti[ARITHMOS_MATHITWN][STR_SIZE];
	float vathmos_proodou[ARITHMOS_MATHITWN], telikos_vathmos[ARITHMOS_MATHITWN], mesos_oros[ARITHMOS_MATHITWN], max, min;
	int i, j =0, k=0, count_max = 0, count_min= 0, max_i[ARITHMOS_MATHITWN], min_i[ARITHMOS_MATHITWN];
	
	printf("Καλως ήρθατε στο πρόγραμμα εισαγωγής καρτελών των %d μαθητών της τάξης.\n\n", ARITHMOS_MATHITWN);
	
	for(i=0; i<ARITHMOS_MATHITWN; i++)
	{
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("Παρακαλώ πληκτρολογείστε το όνομα του %dου μαθητή: ", i+1);
		scanf("%s", onoma_mathiti[i]);
		printf("\nΠαρακαλώ πληκτρολογείστε το επώνυμο του %dου μαθητή: ", i+1);
		scanf("%s", epwnumo_mathiti[i]);
		getchar();
		//fflush(stdin);
		printf("\nΠαρακαλώ πληκτρολογείστε το βαθμό προόδου του %dου μαθητή: ", i+1);
		scanf("%f", &vathmos_proodou[i]);
		printf("\nΠαρακαλώ πληκτρολογείστε τον τελικό βαθμό του %dου μαθητή: ", i+1);
		scanf("%f", &telikos_vathmos[i]);
		getchar();
		mesos_oros[i] = (vathmos_proodou[i]*0.4) + (telikos_vathmos[i]*0.6);
	}
	
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	fflush(stdin);
	printf("\nΤα στοιχεία των %d μαθητών που πληκτρολογήσατε είναι:\n", ARITHMOS_MATHITWN);
	//όνομα μαθητή, το επώνυμο, το βαθμό προόδου(με βαρύτητα 40%) και τον τελικό βαθμό
	printf("α/α μαθητή\t\tΌνομα μαθητή\t\tΕπώνυμο μαθητή\t\tΒαθμός προόδου\tΤελικός βαθμός\tΜέσος όρος\n");
	for(int i=0;i<ARITHMOS_MATHITWN;i++)
	{
		if(strlen(epwnumo_mathiti[i])<=7)
			printf("%4dος\t\t\t%s\t\t\t%s\t\t\t%.2f\t\t%.2f\t\t%.2f\n", i+1, onoma_mathiti[i], epwnumo_mathiti[i], vathmos_proodou[i],telikos_vathmos[i], mesos_oros[i]);
		else if(strlen(epwnumo_mathiti[i])>7)	
			printf("%4dος\t\t\t%s\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\n", i+1, onoma_mathiti[i], epwnumo_mathiti[i], vathmos_proodou[i],telikos_vathmos[i], mesos_oros[i]);
	}
	
	max = min = mesos_oros[0];
	for(i=1;i<ARITHMOS_MATHITWN;i++)
	{
		max = (mesos_oros[i]>max)? mesos_oros[i] : max;
		min = (mesos_oros[i]<min)? mesos_oros[i] : min;
	}
	
	for(i=0;i<ARITHMOS_MATHITWN;i++)
	{
		if(mesos_oros[i]==max)
		{
			max_i[j] = i;
			count_max++;
			j++;
		}

		if(mesos_oros[i]==min)
		{
			min_i[k] = i;
			count_min++;
			k++;
		}
	}

	if(count_max==1)
	{
		if(strlen(epwnumo_mathiti[max_i[j-1]])<=7)
		{
			printf("\nΟ καλύτερος μαθητής με το μέσο όρο του είναι ο:\n");
			printf("Όνομα μαθητή\tΕπώνυμο μαθητή\tΜέσος όρος\n");
			printf("%s\t\t%s\t\t%.2f\n\n", onoma_mathiti[max_i[j-1]], epwnumo_mathiti[max_i[j-1]], max);
		}
			
		else if(strlen(epwnumo_mathiti[max_i[j-1]])>7)
		{
			printf("\nΟ καλύτερος μαθητής με το μέσο όρο του είναι ο:\n");
			printf("Όνομα μαθητή\t\tΕπώνυμο μαθητή\t\tΜέσος όρος\n");
			printf("%s\t\t%s\t\t%.2f\n\n", onoma_mathiti[max_i[j-1]], epwnumo_mathiti[max_i[j-1]], max);
		}
	}
	else if(count_max>1)
	{
		printf("\nΟι %d καλύτεροι μαθητές με το μέσο όρο τους είναι οι:\n",count_max);
		printf("Όνομα μαθητή\tΕπώνυμο μαθητή\tΜέσος όρος\n");
		for(j=0;j<count_max;j++)
			printf("%s\t\t%s\t\t%.2f\n", onoma_mathiti[max_i[j]], epwnumo_mathiti[max_i[j]], max);
	}
	
	if(count_min==1)
	{
		if(strlen(epwnumo_mathiti[min_i[j-1]])<=7)
		{
			printf("Ο \"μαθητής που θέλει φροντιστήριο\" με το μέσο όρο του είναι ο:\n");
			printf("Όνομα μαθητή\t\tΕπώνυμο μαθητή\tΜέσος όρος\n");
			printf("%s\t%s\t\t%.2f\n\n", onoma_mathiti[min_i[k-1]], epwnumo_mathiti[min_i[k-1]], min);
		}
		
		else if(strlen(epwnumo_mathiti[min_i[j-1]])>7)
		{
			printf("Ο \"μαθητής που θέλει φροντιστήριο\" με το μέσο όρο του είναι ο:\n");
			printf("Όνομα μαθητή\t\tΕπώνυμο μαθητή\t\tΜέσος όρος\n");
			printf("%s\t\t%s\t\t%.2f\n\n", onoma_mathiti[min_i[k-1]], epwnumo_mathiti[min_i[k-1]], min);
		}
	}
	
	else if(count_min>1)
	{
		printf("Οι %d \"μαθητές που θέλουν φροντιστήριο\" με το μέσο όρο τους είναι οι:\n\n", count_min);
		printf("Όνομα μαθητή\tΕπώνυμο μαθητή\tΜέσος όρος\n");
		for(k=0;k<count_min;k++)
			printf("%s\t\t%s\t\t%.2f\n", onoma_mathiti[min_i[k]], epwnumo_mathiti[min_i[k]], min);
	}
	
	printf("\n");
	system("pause");
	return 0;
}
