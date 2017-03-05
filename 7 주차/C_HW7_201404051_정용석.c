#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_Sum();
long long sum_recursion(long long n);

void print_oddSum();
long long oddSum_recursion(long long n);

void print_fibbonacci();
long long fib_recursion(long long n);

void print_exp();
long long exp_recursion(long long n);

void print_reverseN();
long reverse_Number(int n);

void print_sumDigit();
int digitSum_recursion(int n);

void print_binaryNumber();
int binaryNum_recursion(long long n);

void print_stair();
long long stair_recursion(long long n);


void printCard(int num);
void throwCard();


void findTriangleNumber();

void findNumofSunday();


int main()
{
	while (1) {
		//print_Sum();
		//print_oddSum();
		//print_exp();
		//print_fibbonacci();
		//print_stair();
		//print_reverseN();
		//print_sumDigit();
		//print_binaryNumber();
		print_stair();
		//throwCard();
		//findTriangleNumber();
		//findNumofSunday();
		printf("\n");
		//break;
	}

	return 0;
}

void print_Sum() //사용자에게 입력 받은 수의 합 출력
{
	long long n;
	scanf("%lld", &n);
	printf("%lld\n", sum_recursion(n));
}
long long sum_recursion(long long n) //수의 합 재귀함수
{
	//재귀 함수 종료 조건 n == 1
	if (n == 1)
		return n;
	return n + sum_recursion(n - 1);
}

void print_oddSum()
{
	long long n;
	scanf("%lld", &n);
	printf("%lld\n", oddSum_recursion(n));
}
long long oddSum_recursion(long long n)
{
	//n == 1일 때(즉, 시작 n이 홀 수일 때 가능) 재귀함수 종료
	if (n == 1)
		return n;
	//n < 1일 때(n이 짝수일 때) 재귀 함수 종료
	else if (n < 1)
		return 0;
	//시작 n이 짝수일 때 1을 빼서 홀수로 만들기
	if (n % 2 == 0)
		return (n - 1) + oddSum_recursion(n - 3);
	return n + oddSum_recursion(n - 2);
}

void print_exp()
{
	long long i, n = 30;
	for (i = 1; i <= n; i++)
	{
		printf("%lld\n", exp_recursion(i));
	}
}
long long exp_recursion(long long n)
{
	//2^0일 경우 재귀 종료,  2^0 == 1
	if (n == 0)
		return 1;
	return 2 * exp_recursion(n - 1);
}

void print_fibbonacci()
{
	long long i, n = 30;
	for (i = 1; i <= n; i++)
	{
		printf("%lld\n", fib_recursion(i));
	}
}
long long fib_recursion(long long n)
{
	//피보나치 수열의 첫번쨰와 2번째 수의 값
	if (n == 1 || n == 2)
		return 1;
	return fib_recursion(n - 1) + fib_recursion(n - 2);
}

void print_reverseN()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", reverse_Number(n));
}
int reverse_Number(int n) {
	int add;
	int temp = n;
	int base = 1;

	//각 자리별 자리 수 구하기
	while (temp > 10) {
		temp = temp / 10;
		base *= 10;
	}
	//종료문
	if (n == 0)
		return 0;

	//n이 일의 자리 수 일때는 그대로 더한다.
	else if (n < 10)
		add = n;
	//n의 현재 자리를 반대 쪽 자리의 수로 변환
	else
		add = (n % 10) * base;;
	return add + reverse_Number(n / 10);		
}

void print_sumDigit(){
	int n;
	scanf("%d", &n);
	printf("%d\n", digitSum_recursion(n));
}
int digitSum_recursion(int n){
	int temp = n;
	int add;
	//각 자리수 구하기
	add = temp % 10;
	//종료문
	if (n == 0)
		return 0;
	return add + digitSum_recursion(n / 10);
}

void print_binaryNumber() {
	long long n;
	scanf("%lld", &n);
	printf("%d\n", binaryNum_recursion(n));
}
int binaryNum_recursion(long long n) {
	int add;
	long long temp = n;
	//종료문
	if (n == 0)
		return 0;
	//이진수의 자리수가 0이면 0 리턴, 1이면 1 리턴
	if (temp % 10 == 1)
		add = 1;
	else
		add = 0;
	return add + binaryNum_recursion(n / 10);
}

void print_stair()
{
	long long n;
	scanf("%lld", &n);
	printf("%lld\n", stair_recursion(n));
}
long long stair_recursion(long long n)
{
	//계단 수가 1일 때 경우의 수 1, 2일 때 경우의 수 2
	// *3부터는 계단 수가 1일 때와 2일 때 경우의 수의 합이다.
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else
		return stair_recursion(n - 1) + stair_recursion(n - 2);
}


void printCard(int num)
{
	/////////////////////////////////////////////////////////////
	// ¼Ò½º ÄÚµå¸¦ ±¸ÇöÇÏ¼¼¿ä.


	/////////////////////////////////////////////////////////////
}

void throwCard()
{
	int i, j;

	printf("¼¯Áö ¾ÊÀº »óÅÂÀÇ Ä«µå\n");


	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 13; j++)
			printCard(i * 13 + j);
		printf("\n");
	}

	printf("¼±ÅÃÇÑ 10ÀåÀÇ Ä«µå\n");
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		printCard(rand() % 52);
	}
	printf("\n");
}

void findTriangleNumber()
{
	/////////////////////////////////////////////////////////////
	// ¼Ò½º ÄÚµå¸¦ ±¸ÇöÇÏ¼¼¿ä.


	/////////////////////////////////////////////////////////////
}

void findNumofSunday()
{
	/////////////////////////////////////////////////////////////
	// ¼Ò½º ÄÚµå¸¦ ±¸ÇöÇÏ¼¼¿ä.


	/////////////////////////////////////////////////////////////
}
