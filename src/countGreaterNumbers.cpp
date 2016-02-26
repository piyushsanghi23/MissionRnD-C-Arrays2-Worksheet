/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/


#include<stdio.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int stringCompare(char str1[], char str2[]){
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
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i = 0, c = -1;
	if (date != NULL && len > 0 && Arr != NULL){
		for (i = 0; i < len; i++)
		{
			if (stringCompare(Arr[i].date, date))
				c = i;
		}
		if (c != -1)
			return len - c - 1;
		else
			return 0;

	}
	else
		return -1;
}
