

#include <stdio.h>


void computeDivision()
{
	int A,B;

	printf("두 정수를 입력하세요: ");
	fflush(stdout);
	scanf("%d %d", &A, &B);

	printf("%d / %d 의 몫은 %d 입니다. \n", A, B, A/B);
	printf("%d / %d 의 나머지은 %d 입니다. \n", A, B, A%B);
}
void computeTemperature()
{
	float F, C;

	printf("화씨 온도를 입력하시오: ");
	fflush(stdout);
	scanf("%f" , &F);
	C = (F-32)/(1.8); //섭씨를 구한다
	printf("화씨 온도 %.0f는 섭씨 온도 %.2f 입니다.\n", F, C);

	printf("섭씨 온도를 입력하시오: ");
	fflush(stdout);
	scanf("%f" , &C);
	F = (C * 1.8) + 32; //화씨를 구한다
	printf("섭씨 온도 %.2f는 화씨 온도 %.2f 입니다.\n", C, F);
}
void computeHoursforMars()
{
	const int earthToMars = 75000000; //화성까지의 거리 75000000 km
	//역추진 로켓 속도(11.9km/s - > (11.9 * 3600 km/h)
	const float rocketSpeed = (11.9 * 3600);
	const float plane = 850; //민간 항공기 속도 850km/h
	const float F1 = 350;    //경주용 자동차(F1) 속도 350km/h
	const float KTX = 300;   //KTX 열차 속도 300km/h

	float time; //걸리는 시간

	time  = earthToMars / rocketSpeed;
	printf("역추진 로켓을 이용했을때 화성까지 걸리는 시간: %.2f\n" , time);

	time  = earthToMars / plane;
	printf("민간 항공기를 이용했을때 화성까지 걸리는 시간: %.2f\n" , time);

	time  = earthToMars / F1;
	printf("경주용 자동차<F1>을 이용했을때 화성까지 걸리는 시간: %.2f\n" , time);

	time  = earthToMars / KTX;
	printf("KTX 열차를 이용했을때 화성까지 걸리는 시간: %.2f\n" , time);
}
void computeDigitSum()
{
	int num, sum;

	printf("숫자 <0 <= num <= 10000> 를 입력하시오: ");
	fflush(stdout);
	scanf("%d" , &num);

	//각 자리수의 합 = 1000의 자리 + 100의 자리 + 10의 자리 + 1의 자리
	sum = (num/1000)+((num%1000)/100)+(num%1000%100/10)+(num%1000%100%10);
	printf("각 자리의 합은: %d\n" , sum);

	//7의 배수 조건문
	((sum%7)==0) ? printf("%d는 7의 배수입니다", sum):printf("%d는 7의 배수가 아닙니다", sum);
}
void checkQuadrant()
{
	int x, y;
	printf("2차원 공간읭 좌표 <x,y>를 입력하세요: ");
	fflush(stdout);
	scanf("%d %d", &x, &y);

	//<x, y>조건 문
	((x>0) && (y>0)) ? printf("<%d, %d>는 1 사분면에 속합니다\n", x,y):printf("<%d, %d>는 1 사분면에 속하지 않습니다\n", x,y);
	((x<0) && (y>0)) ? printf("<%d, %d>는 2 사분면에 속합니다\n", x,y):printf("<%d, %d>는 2 사분면에 속하지 않습니다\n", x,y);
	((x<0) && (y<0)) ? printf("<%d, %d>는 3 사분면에 속합니다\n", x,y):printf("<%d, %d>는 3 사분면에 속하지 않습니다\n", x,y);
	((x>0) && (y<0)) ? printf("<%d, %d>는 4 사분면에 속합니다\n", x,y):printf("<%d, %d>는 4 사분면에 속하지 않습니다\n", x,y);
}
void checkParallelLine()
{
	int x1, x2, x3, x4, y1, y2, y3, y4;
	float slope1, slope2;

	printf("첫 번째 2차원 공간의 두 점 <x1, y1>, <x2, y2>를 입력하세요: ");
	fflush(stdout);
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

	printf("두 번째 2차원 공간의 두 점 <x3, y3>, <x4, y4>를 입력하세요: ");
	fflush(stdout);
	scanf("%d %d %d %d", &x3, &y3, &x4, &y4);

	printf("<x1, y1>, <x2, y2>의 값은 <%d, %d>, <%d, %d>\n", x1, y1, x2, y2);
	printf("<x3, y3>, <x4, y4>의 값은 <%d, %d>, <%d, %d>\n", x3, y3, x4, y4);

	//각 직선의 기울기 계산
	slope1 = (y2-y1)/(x2-x1);
	slope2 = (y4-y3)/(x4-x3);

	//평행 조건문
	(slope1 == slope2) ? printf("두 직선은 평행합니다.\n"):printf("두 직선은 평행하지 않습니다.\n");
}

int main()
{

	//computeDivision();
	//computeTemperature();
	//computeDigitSum();
	//checkQuadrant();
	//checkParallelLine();
	//computeHoursforMars();

	return 0;
}

