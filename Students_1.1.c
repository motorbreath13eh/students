#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_SIZE 50
//#define ARITHMOS_MATHITWN 1
#define ARITHMOS_MATHITWN 10

/* �.� ��������� �� C �� ����� �� ������ ��� �� ������ �� ����� ��� 10 ������� ���� ����� �� ����:
�� ����� ������, �� �������, �� ����� �������(�� �������� 40%) ��� ��� ������ �����(�� �������� 60%).
� �������� �� ������ �� ��������� ��� �� �������� �� ������������ ������� � ���� ����� ��� ��� ����.
�� ������ �� ��������� �� ���� ������� �� �� ���� ��� ���� ������(�� ��� ���������).
����� � �������� �� ��������� �� ������������� ��� �� ���� ��� ��� ��������� ��� ��� "������� ���
������ ������������".*/

int main()
{
	system("CHCP 1253>nul");
	
	char onoma_mathiti[ARITHMOS_MATHITWN][STR_SIZE], epwnumo_mathiti[ARITHMOS_MATHITWN][STR_SIZE];
	float vathmos_proodou[ARITHMOS_MATHITWN], telikos_vathmos[ARITHMOS_MATHITWN], mesos_oros[ARITHMOS_MATHITWN], max, min;
	int i, j =0, k=0, count_max = 0, count_min= 0, max_i[ARITHMOS_MATHITWN], min_i[ARITHMOS_MATHITWN];
	
	printf("����� ������ ��� ��������� ��������� �������� ��� %d ������� ��� �����.\n\n", ARITHMOS_MATHITWN);
	
	for(i=0; i<ARITHMOS_MATHITWN; i++)
	{
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("�������� ��������������� �� ����� ��� %d�� ������: ", i+1);
		scanf("%s", onoma_mathiti[i]);
		printf("\n�������� ��������������� �� ������� ��� %d�� ������: ", i+1);
		scanf("%s", epwnumo_mathiti[i]);
		getchar();
		//fflush(stdin);
		printf("\n�������� ��������������� �� ����� ������� ��� %d�� ������: ", i+1);
		scanf("%f", &vathmos_proodou[i]);
		printf("\n�������� ��������������� ��� ������ ����� ��� %d�� ������: ", i+1);
		scanf("%f", &telikos_vathmos[i]);
		getchar();
		mesos_oros[i] = (vathmos_proodou[i]*0.4) + (telikos_vathmos[i]*0.6);
	}
	
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	fflush(stdin);
	printf("\n�� �������� ��� %d ������� ��� ��������������� �����:\n", ARITHMOS_MATHITWN);
	//����� ������, �� �������, �� ����� �������(�� �������� 40%) ��� ��� ������ �����
	printf("�/� ������\t\t����� ������\t\t������� ������\t\t������ �������\t������� ������\t����� ����\n");
	for(int i=0;i<ARITHMOS_MATHITWN;i++)
	{
		if(strlen(epwnumo_mathiti[i])<=7)
			printf("%4d��\t\t\t%s\t\t\t%s\t\t\t%.2f\t\t%.2f\t\t%.2f\n", i+1, onoma_mathiti[i], epwnumo_mathiti[i], vathmos_proodou[i],telikos_vathmos[i], mesos_oros[i]);
		else if(strlen(epwnumo_mathiti[i])>7)	
			printf("%4d��\t\t\t%s\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\n", i+1, onoma_mathiti[i], epwnumo_mathiti[i], vathmos_proodou[i],telikos_vathmos[i], mesos_oros[i]);
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
			printf("\n� ��������� ������� �� �� ���� ��� ��� ����� �:\n");
			printf("����� ������\t������� ������\t����� ����\n");
			printf("%s\t\t%s\t\t%.2f\n\n", onoma_mathiti[max_i[j-1]], epwnumo_mathiti[max_i[j-1]], max);
		}
			
		else if(strlen(epwnumo_mathiti[max_i[j-1]])>7)
		{
			printf("\n� ��������� ������� �� �� ���� ��� ��� ����� �:\n");
			printf("����� ������\t\t������� ������\t\t����� ����\n");
			printf("%s\t\t%s\t\t%.2f\n\n", onoma_mathiti[max_i[j-1]], epwnumo_mathiti[max_i[j-1]], max);
		}
	}
	else if(count_max>1)
	{
		printf("\n�� %d ��������� ������� �� �� ���� ��� ���� ����� ��:\n",count_max);
		printf("����� ������\t������� ������\t����� ����\n");
		for(j=0;j<count_max;j++)
			printf("%s\t\t%s\t\t%.2f\n", onoma_mathiti[max_i[j]], epwnumo_mathiti[max_i[j]], max);
	}
	
	if(count_min==1)
	{
		if(strlen(epwnumo_mathiti[min_i[j-1]])<=7)
		{
			printf("� \"������� ��� ����� ������������\" �� �� ���� ��� ��� ����� �:\n");
			printf("����� ������\t\t������� ������\t����� ����\n");
			printf("%s\t%s\t\t%.2f\n\n", onoma_mathiti[min_i[k-1]], epwnumo_mathiti[min_i[k-1]], min);
		}
		
		else if(strlen(epwnumo_mathiti[min_i[j-1]])>7)
		{
			printf("� \"������� ��� ����� ������������\" �� �� ���� ��� ��� ����� �:\n");
			printf("����� ������\t\t������� ������\t\t����� ����\n");
			printf("%s\t\t%s\t\t%.2f\n\n", onoma_mathiti[min_i[k-1]], epwnumo_mathiti[min_i[k-1]], min);
		}
	}
	
	else if(count_min>1)
	{
		printf("�� %d \"������� ��� ������ ������������\" �� �� ���� ��� ���� ����� ��:\n\n", count_min);
		printf("����� ������\t������� ������\t����� ����\n");
		for(k=0;k<count_min;k++)
			printf("%s\t\t%s\t\t%.2f\n", onoma_mathiti[min_i[k]], epwnumo_mathiti[min_i[k]], min);
	}
	
	printf("\n");
	system("pause");
	return 0;
}
