#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int get_integer();
long long factorial(int n);
long long combination(int n, int r);
void computeCombination();


// ¿ÏÀü¼ö °è»êÀ» À§ÇÑ ÇÔ¼ö
int checkPerfect(int n);
void findPerfectNumber();


// Ä£È­¼ö °è»êÀ» À§ÇÑ ÇÔ¼ö
int checkFrindNumber(int n1, int n2);
void findFrindNumber();


// ¼ýÀÚ ¾ß±¸ °ÔÀÓ ÇÔ¼ö
void DigitBaseballGame();


// ¹ÙÀÌ¿À¸®µë °è»êÀ» À§ÇÑ ÇÔ¼ö
int checkLeapYear(int year);
int checkMonth(int month, int leap_year);
int countDate(int birth_year, int birth_month, int birth_day, int year, int month);
void printBiorhythm(int date, int year, int month);
void computeBiorhythm();


int main()
{
	//computeCombination();
	//findPerfectNumber();
	//findFrindNumber();
	//computeSumSquare();
	//DigitBaseballGame();
	computeBiorhythm();

}


// 정수값을 입력받고 출력하는 함수
int get_integer()
{
	///////////////////////////////////////
	int input;
	scanf("%d", &input);
	return input;
}

// n! 계산하여 반환하는 함수
long long factorial(int n)
{
	///////////////////////////////////////
	int i;
	long long result = 1;
	for (i = 1; i <= n; i++)
		result *= i;
	return result;
}

//정수 n과 r의 조합값을 반환하는 함수
long long combination(int n, int r)
{
	///////////////////////////////////////
	return factorial(n) / (factorial(r)*factorial(n - r));
}

// 결과 값 출력
void computeCombination()
{
	int n = get_integer();
	int r = get_integer();

	printf("C(%d, %d) = %lld\n", n, r, combination(n, r));
}


// 완전수이면 1, 아니면 0을 반환
int checkPerfect(int n)
{
	///////////////////////////////////////
	int sum = 0;
	int i;
	for (i = 1; i< n; i++)
		if (n % i == 0)
			sum += i;
	if (sum == n)
		return 1;
	else
		return 0;
}

// 2~10000 완전수를 출력
void findPerfectNumber()
{
	int i;
	for (i = 2; i <= 10000; i++)
		if (checkPerfect(i))
			printf("%d ", i);
	printf("\n");
}


// 두 수 n1과 n2가 친화수이면 1, 아니면 0
int checkFrindNumber(int n1, int n2)
{
	///////////////////////////////////////
	int sum1 = 0; //n1의 약수의 총합
	int sum2 = 0; //n2의 약수의 총합
	int i;
	for (i = 1; i < n1; i++)
		if (n1 % i == 0)
			sum1 += i;
	for (i = 1; i < n2; i++)
		if (n2 % i == 0)
			sum2 += i;

	//n1과 n2의 약수의 총합이 서로의 값과 같으면 1
	if ((sum1 == n2) && (sum2 == n1)) 
		return 1;
	else
		return 0;
}


// 2~1000 친화수를 찾는다
void findFrindNumber()
{
	int i, j;
	for (i = 2; i <= 10000; i++)
	{
		for (j = i + 1; j <= 10000; j++)
			if (checkFrindNumber(i, j))
				printf("(%d, %d) ", i, j);
	}
	printf("\n");
}


// 숫자 야구게임
void DigitBaseballGame()
{
	///////////////////////////////////////
	char start;			//시작여부
	int count = 1;      //라운드 횟수
	int n1, n2, n3;     //컴퓨터 난수 3개
	int i1, i2, i3;     //사용자 입력 3개
	int strike = 0;     //스트라이크
	int ball = 0;		//볼

	while (1) {
		printf("Play game ? <y/n> :");
		scanf("%c", &start);
		if (start != 'y') {
			printf("Program Closes\n");
			break;
		}

		srand((unsigned)time(NULL));
		while (1) //난수 3개 생성, 중복되면 다시
		{
			n1 = rand() % 10;
			n2 = rand() % 10;
			n3 = rand() % 10;
			if (n1 != n2 && n1 != n3 && n2 != n3)
				break;
		}
		//테스트용 출력
		printf("%d %d %d\n", n1, n2, n3);
		
		while (1)
		{
			printf("**** BASEBALL GAME ****   ROUND: %d\n", count++);
			printf("USER: ");
			scanf("%d %d %d", &i1, &i2, &i3);

			//if문을 각각의 일력 수 차례로 비교해서 스트라이크와 볼을 구분해야한다.
			//if문 하나에 다 넣게 되면 모든 경우의 수를 뽑아낼 수 없다.
			if (n1 == i1)
				strike++;
			else if (n1 == i2 || n1 == i3)
				ball++;

			if (n2 == i2)
				strike++;
			else if (n2 == i1 || n2 == i3)
				ball++;

			if (n3 == i3)
				strike++;
			else if (n3 == i1 || n3 == i2)
				ball++;

			//스트라이크 3개면 사용자의 승리 및 게임 종료
			if (strike == 3) {
				printf("USER WINNER !!!\n");
				printf("The numbers are %d %d %d\n", n1, n2, n3);
				//다음 게임을 위한 변수 초기화
				strike = 0;
				ball = 0;
				count = 1;
				break;
			}

			//스트라이크와 볼이 모두 있을 때,
			if (strike != 0 && ball != 0)
				printf("COMPUTER: %d STRIKE, %d BALL !!!!\n", strike, ball);
			//스트라이크만 있을 때
			else if (strike != 0 && ball == 0)
				printf("COMPUTER: %d STRIKE !!!!\n", strike);
			//볼만 있을 때
			else if (ball != 0 && strike == 0)
				printf("COMPUTER: %d BALL !!!!\n", ball);
			//하나도 못 맞추면 OUT
			else
				printf("COMPUTER: O U T !!!!\n");

			//라운드가 끝나면 컴퓨터 승리 및 정답 제공, 프로그램 종료
			if (count == 10)
			{
				printf("\nCOMPUTER WINNER !!!!\n");
				printf("The numbers are %d %d %d\n", n1, n2, n3);
				//변수 초기화
				strike = 0;
				ball = 0;
				count = 1;
				break;
			}
			printf("\n");
			strike = 0;
			ball = 0;
		}
		//버퍼에 있는 ENTER 키를 없애기 위한 함수
		getchar();
	}
}


// 주어진 연도가 윤년인지 아닌지 판별하는 함수
int checkLeapYear(int year)
{
	///////////////////////////////////////
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 1;
	else
		return 0;
}


// 주어진 달이 며칠까지 있는지 판별하는 함수
int checkMonth(int month, int leap_year)
{
	switch (month) {
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	case 2:
		if (checkLeapYear(leap_year))
			return 29;
		else
			return 28;
		break;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
		break;
	}
}

// 생년월일과 년과 월을 입력하였을 때 총 날짜 수 계산
int countDate(int birth_year, int birth_month, int birth_day, int year, int month)
{
	///////////////////////////////////////
	int i;
	int totalDays = 0;
	//일단 그 달의 일수 더하기
	totalDays += checkMonth(birth_month, birth_year) - birth_day;
	//다음달 부터 12월까지 일수 더하기
	for (i = birth_month + 1; i <= 12; i++)
		totalDays += checkMonth(i, birth_year);
	//다음해부터 입력된 해 전까지의 일수 더하기
	for (i = birth_year + 1; i < year; i++)
	{
		if (checkLeapYear(i))
			totalDays += 366;
		else
			totalDays += 365;
	}
	return totalDays;
}

// 총 날짜 수와 연과 월 입력시 바이오리듬 출력
void printBiorhythm(int date, int year, int month)
{
	///////////////////////////////////////
	char phys;
	char ment;
	char intel;
	int physP;
	int mentP;
	int intelP;
	int i;
	int days = checkMonth(month, year);

	printf("Biorhythm Result:\n");
	printf("Low(-), High(*), Danger(D)\n");
	for (i = 1; i <= days; i++)
	{
		physP = (date+ i - 1) % 23;
		mentP = (date + i - 1) % 28;
		intelP = (date + i - 1) % 33;

		if (physP >= 1 && physP <= 10)
			phys = '+';
		else if (physP >= 13 && physP <= 21)
			phys = '-';
		else if (physP == 0 || physP == 11 || physP == 12 || physP == 22)
			phys = 'D';

		if (mentP >= 1 && mentP <= 12)
			ment = '+';
		else if (mentP >= 15 && mentP <= 26)
			ment = '-';
		else if (mentP == 0 || mentP == 13 || mentP == 14 || mentP == 27)
			ment = 'D';

		if (intelP >= 1 && intelP <= 15)
			intel = '+';
		else if (intelP >= 18 && intelP <= 31)
			intel = '-';
		else if (intelP == 0 || intelP == 16 || intelP == 17 || intelP == 32)
			intel = 'D';
		
		printf("%dM  %2dD P: %3d %c\t", month, i,  physP, phys);
		printf("M: %3d %c\t", mentP, ment);
		printf("I: %3d %c\n", intelP, intel);
		//date++;
	}


}

// 바이오리듬 계산하기
void computeBiorhythm()
{
	int birth_year, birth_month, birth_day;
	int year, month, date;

	printf("Input a birthdate (ex: 1983 5 21)\n");
	scanf("%d %d %d", &birth_year, &birth_month, &birth_day);

	printf("Insert wanted year and month. (ex: 2004 11)\n");
	scanf("%d %d", &year, &month);

	date = countDate(birth_year, birth_month, birth_day, year, month);
	printf("\n%d Y %d M %d D and %d Y %d M 1 D has %d days.\n\n", birth_year, birth_month, birth_day, year, month, date + 1);

	printBiorhythm(date, year, month);
}