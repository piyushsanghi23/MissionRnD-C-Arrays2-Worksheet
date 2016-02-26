/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/

#include<iostream>

int findSingleOccurenceNumber(int *A, int len) {
	int i = 0;
	if (A != NULL&&len > 0)
	{
		int c = 0, d = 0, t = 0;
		for (c = 0; c < (len - 1); c++)
		{
			for (d = 0; d < len - c - 1; d++)
			{
				if (A[d] > A[d + 1]) /* For decreasing order use < */
				{
					t = A[d];
					A[d] = A[d + 1];
					A[d + 1] = t;
				}
			}
		}
		for (i = 0; i < len; i += 3)
		{
			if (A[i] != A[i + 1])
				return A[i];

		}
	}
	return -1;
}