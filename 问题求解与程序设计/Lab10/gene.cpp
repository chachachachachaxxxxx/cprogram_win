#include <stdio.h>
#include <string.h>
const int MAXN = 1e6+10;
char genecode[64];
char gene[MAXN];
char protein[MAXN];
char reprotein[MAXN];

int id(char x)
{
	switch (x)
	{
		case 'A': return 0;
		case 'C': return 1;
		case 'T': return 2;
		case 'G': return 3;
		default: return -1;
	}
}

int hash(char *p) {
	// for (int i = 0; i < 3; i++)
	// {
	// 	s *= 4;
	// 	if (p[i] == 'A')
	// 		;
	// 	else if (p[i] == 'C')
	// 		s += 1;
	// 	else if (p[i] == 'T')
	// 		s += 2;
	// 	else
	// 		s += 3;
	// }
	int s = id(p[0]) * 16 + id(p[1]) * 4 + id(p[2]);
	return s;
	/* return a 6-bit number for the 3-character encoding p */ }

void unhash(int x) {
	char key[4];
	key[3] = '\0';
	int i = 2;
	while (i >= 0)
	{
		int k = x % 4;
		if (k == 3)
			key[i] = 'g';
		else if (k == 2)
			key[i] = 't';
		else if (k == 1)
			key[i] = 'c';
		else
			key[i] = 'a';
		x /= 4;
		i--;
	}
	printf("%s", key);
	/* print the 3-character encoding corresponding
	   to the 6-bit number x */ }

int match(char *protein)
{
	int plen = strlen(protein);
	int maxpos = strlen(gene) - 3 * plen;
	int flag = 0;
	for (int pos = 0; pos <= maxpos; pos++)
	{
		flag = 1;
		for (int i = 0; i < 64; i++)
			genecode[i] = '.';

		for (int j = 0; j < plen; j++)
		{
			int key = hash(gene + pos + 3 * j);

			if (genecode[key] == '.')
				genecode[key] = protein[j];

			else if (genecode[key] == protein[j])
				continue;
			else
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			return pos;
	}

	return -1;
}

int main() {
	scanf("%s\n", gene);
	scanf("%s\n", protein);

	int len = strlen(protein);
	for (int i = 0; i < len; i++)
		reprotein[i] = protein[len - i - 1];
	reprotein[len] = '\0';
	/* read the contents of argv[1] into protein[0...] */
	/* read the contents of argv[2] into gene[0...] */

	/* find an encoding for protein[0...] in gene[0...]
	   and record the encoding in gencode[0..63] */
	int position = match(protein);
	if (position == -1)
		position = match(reprotein);
	printf("Match found at gene position %d\n", position);

	for (int j = 0; j < 64; j++) {
		unhash(j);
		printf(" %c    ", genecode[j]); 
		if ((j + 1)%4 == 0)
			printf("\n");
	}
	return 0;
}