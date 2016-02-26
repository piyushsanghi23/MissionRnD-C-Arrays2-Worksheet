/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int stringCompare1(char str1[], char str2[]){
	int i = 0, flag = 0;

	while (str1[i] != '\0' && str2[i] != '\0'){
		if (str1[i] != str2[i]){
			flag = 1;
			break;
		}
		i++;
	}

	if (flag == 0 && str1[i] == '\0' && str2[i] == '\0')
		return 1;
	else
		return 0;

}
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i = 0, j = 0, k = 0, flag = 0;
	struct transaction *c = NULL;
	c = (struct transaction*)malloc(sizeof(transaction));



	if (A != NULL && B != NULL  && ALen > 0 && BLen > 0){
		for (i = 0; i < ALen; i++)
		{
			for (j = 0; j < BLen; j++)
			{
				if (stringCompare1(A[i].date, B[j].date))
				{
					flag = 1;
					c[k] = A[i];
					k++;
					//printf("comapred both were equal , k is %d , a = %d",k,A[i].amount);
				}
			}
		}
		return flag ? c : NULL;
	}
	else
		return NULL;
}