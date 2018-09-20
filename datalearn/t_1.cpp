#include <stdio.h>

void PrintN(int N)
{
	int i;
	for (i = 1; i <= N; ++i)
		printf("%d\n", i);
	return;
}

void PrintNN(int N)
{
	if (N) {
		PrintNN(N - 1);
		printf("%d\n", N);
	}
	return;
}

int main()
{
	int N;
	scanf("%d", &N);
	PrintNN(N);
	return 0;
}
