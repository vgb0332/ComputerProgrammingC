

#include <stdio.h>


void computeDivision()
{
	int A,B;

	printf("�� ������ �Է��ϼ���: ");
	fflush(stdout);
	scanf("%d %d", &A, &B);

	printf("%d / %d �� ���� %d �Դϴ�. \n", A, B, A/B);
	printf("%d / %d �� �������� %d �Դϴ�. \n", A, B, A%B);
}
void computeTemperature()
{
	float F, C;

	printf("ȭ�� �µ��� �Է��Ͻÿ�: ");
	fflush(stdout);
	scanf("%f" , &F);
	C = (F-32)/(1.8); //������ ���Ѵ�
	printf("ȭ�� �µ� %.0f�� ���� �µ� %.2f �Դϴ�.\n", F, C);

	printf("���� �µ��� �Է��Ͻÿ�: ");
	fflush(stdout);
	scanf("%f" , &C);
	F = (C * 1.8) + 32; //ȭ���� ���Ѵ�
	printf("���� �µ� %.2f�� ȭ�� �µ� %.2f �Դϴ�.\n", C, F);
}
void computeHoursforMars()
{
	const int earthToMars = 75000000; //ȭ�������� �Ÿ� 75000000 km
	//������ ���� �ӵ�(11.9km/s - > (11.9 * 3600 km/h)
	const float rocketSpeed = (11.9 * 3600);
	const float plane = 850; //�ΰ� �װ��� �ӵ� 850km/h
	const float F1 = 350;    //���ֿ� �ڵ���(F1) �ӵ� 350km/h
	const float KTX = 300;   //KTX ���� �ӵ� 300km/h

	float time; //�ɸ��� �ð�

	time  = earthToMars / rocketSpeed;
	printf("������ ������ �̿������� ȭ������ �ɸ��� �ð�: %.2f\n" , time);

	time  = earthToMars / plane;
	printf("�ΰ� �װ��⸦ �̿������� ȭ������ �ɸ��� �ð�: %.2f\n" , time);

	time  = earthToMars / F1;
	printf("���ֿ� �ڵ���<F1>�� �̿������� ȭ������ �ɸ��� �ð�: %.2f\n" , time);

	time  = earthToMars / KTX;
	printf("KTX ������ �̿������� ȭ������ �ɸ��� �ð�: %.2f\n" , time);
}
void computeDigitSum()
{
	int num, sum;

	printf("���� <0 <= num <= 10000> �� �Է��Ͻÿ�: ");
	fflush(stdout);
	scanf("%d" , &num);

	//�� �ڸ����� �� = 1000�� �ڸ� + 100�� �ڸ� + 10�� �ڸ� + 1�� �ڸ�
	sum = (num/1000)+((num%1000)/100)+(num%1000%100/10)+(num%1000%100%10);
	printf("�� �ڸ��� ����: %d\n" , sum);

	//7�� ��� ���ǹ�
	((sum%7)==0) ? printf("%d�� 7�� ����Դϴ�", sum):printf("%d�� 7�� ����� �ƴմϴ�", sum);
}
void checkQuadrant()
{
	int x, y;
	printf("2���� ������ ��ǥ <x,y>�� �Է��ϼ���: ");
	fflush(stdout);
	scanf("%d %d", &x, &y);

	//<x, y>���� ��
	((x>0) && (y>0)) ? printf("<%d, %d>�� 1 ��и鿡 ���մϴ�\n", x,y):printf("<%d, %d>�� 1 ��и鿡 ������ �ʽ��ϴ�\n", x,y);
	((x<0) && (y>0)) ? printf("<%d, %d>�� 2 ��и鿡 ���մϴ�\n", x,y):printf("<%d, %d>�� 2 ��и鿡 ������ �ʽ��ϴ�\n", x,y);
	((x<0) && (y<0)) ? printf("<%d, %d>�� 3 ��и鿡 ���մϴ�\n", x,y):printf("<%d, %d>�� 3 ��и鿡 ������ �ʽ��ϴ�\n", x,y);
	((x>0) && (y<0)) ? printf("<%d, %d>�� 4 ��и鿡 ���մϴ�\n", x,y):printf("<%d, %d>�� 4 ��и鿡 ������ �ʽ��ϴ�\n", x,y);
}
void checkParallelLine()
{
	int x1, x2, x3, x4, y1, y2, y3, y4;
	float slope1, slope2;

	printf("ù ��° 2���� ������ �� �� <x1, y1>, <x2, y2>�� �Է��ϼ���: ");
	fflush(stdout);
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

	printf("�� ��° 2���� ������ �� �� <x3, y3>, <x4, y4>�� �Է��ϼ���: ");
	fflush(stdout);
	scanf("%d %d %d %d", &x3, &y3, &x4, &y4);

	printf("<x1, y1>, <x2, y2>�� ���� <%d, %d>, <%d, %d>\n", x1, y1, x2, y2);
	printf("<x3, y3>, <x4, y4>�� ���� <%d, %d>, <%d, %d>\n", x3, y3, x4, y4);

	//�� ������ ���� ���
	slope1 = (y2-y1)/(x2-x1);
	slope2 = (y4-y3)/(x4-x3);

	//���� ���ǹ�
	(slope1 == slope2) ? printf("�� ������ �����մϴ�.\n"):printf("�� ������ �������� �ʽ��ϴ�.\n");
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

