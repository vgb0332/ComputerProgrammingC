#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

void generateRandomSet()
{
	//중복되지 않는 난수 생성 함수
	int i, j;
	int set[SIZE];
	int check;

	for (i = 0; i < SIZE; i++)
	{
		while (1) {
			set[i] = rand() % 100 + 1;
			check = 0;
			for (j = 0; j < i; j++) {
				//중복되는 원소가 있을 시 for문 중단
				if (set[j] == set[i]) {
					check = 1;
					break;
				}
			}
			//중복되는 원소가 없을 시 while문 중단
			if (!check)
				break;
		}
	}
	//출력
	for (i = 0; i < SIZE; i++)
		printf("%d ", set[i]);
}
void findMinMaxV()
{
	//10개의 난수로 이루어진 배열 원소에서 최소값과 최대값 출력
	int max, min;
	int i, j;
	int set[SIZE];
	int check;
	//generateRandomSet함수와 동일
	for (i = 0; i < SIZE; i++)
	{
		while (1) {
			set[i] = rand() % 100 + 1;
			check = 0;
			for (j = 0; j < i; j++) {
				if (set[j] == set[i]) {
					check = 1;
					break;
				}
			}
			if (!check)
				break;
		}
	}

	//배열의 첫 번째 원소를 기준으로 최대값과 최소값 구하기
	max = min = set[0];
	for (i = 0; i < SIZE; i++) {
		if (max < set[i])
			max = set[i];
		if (min > set[i])
			min = set[i];
	}
	//출력
	for (i = 0; i < SIZE; i++)
		printf("%d ", set[i]);
	printf("\n");
	printf("%d %d\n", min, max);

}
void findIntersectionSealuet()
{
	//중복되지 않는 난수로 이루어진 2개의 집합의 교집합의 합
	int set1[SIZE];
	int set2[SIZE];
	int i, j, check;
	int sum = 0;
	//generateRandomSet함수와 동일
	for (i = 0; i < SIZE; i++)
	{
		while (1) {
			set1[i] = rand() % 100 + 1;
			set2[i] = rand() % 100 + 1;
			check = 0;
			for (j = 0; j < i; j++) {
				if ((set1[j] == set1[i]) || (set2[j] == set2[i])) {
					check = 1;
					break;
				}
			}
			if (!check)
				break;
		}
	}
	//2개의 원소를 비교하여 동일하면 합
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++)
			if (set1[i] == set2[j])
				sum += set1[i];
	}
	//출력
	for (i = 0; i < SIZE; i++)
		printf("%d ", set1[i]);
	printf("\n");
	for (i = 0; i < SIZE; i++)
		printf("%d ", set2[i]);
	printf("\n");
	printf("%d\n", sum);
}
void findUnionSet()	{
	//2개의 합집합의 합 출력
	int set1[SIZE];
	int set2[SIZE];
	int i, j, check;
	int sum = 0;
	//generateRandomSet함수와 동일
	for (i = 0; i < SIZE; i++)
	{
		while (1) {
			set1[i] = rand() % 100 + 1;
			set2[i] = rand() % 100 + 1;
			check = 0;
			for (j = 0; j < i; j++) {
				if ((set1[j] == set1[i]) || (set2[j] == set2[i])) {
					check = 1;
					break;
				}
			}
			if (!check)
				break;
		}
	}
	//배열의 첫번째 원소들로부터 한개 씩 더한다.
	for (i = 0; i < SIZE; i++)
		sum += set1[i] + set2[i];
	//출력
	for (i = 0; i < SIZE; i++)
			printf("%d ", set1[i]);
	printf("\n");
	for (i = 0; i < SIZE; i++)
		printf("%d ", set2[i]);
	printf("\n");
	printf("%d\n", sum);
}
void printHistogram(){
	//Histogram 출력
	int frequency = 0; //빈도수
	int freqSet[20];
	int randNumber[1000];
	int i, j;
	int sum = 0;
	//1000개의 난수 생성 후 배열에 삽입
	for (i = 0; i < 1000; i++)
		randNumber[i] = rand() % 20 + 1;
	//1부터 20까지 난수 배열과 비교하여 빈도 수 계싼
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 1000; j ++)
			if (randNumber[j] == i + 1) {
				frequency++;
			}
		//빈도 수 계산 후 빈도 수 배열에 삽입
		freqSet[i] = frequency;
		frequency = 0;
	}
	//각 숫자별 빈도 수 *로 출력
	for (i = 0; i < 20; i++) {
		printf("%d ", i + 1);
		for (j = 0; j < freqSet[i]; j++) {
			printf("*");
		}
		printf(" %d\n", freqSet[i]);
	}
}
void printScoreReport(){
	//배열을 이용한 성적표 출력
	int sum = 0;
	double average; //총합, 평균
	int ID[5]; //ID 5개
	int score[4][5]; //과목 4개 X 학생 수 5명
	int i, j;

	//배열의 첫 행에 ID 값을 저장
	//배열의 각 열에 각 과목에 대한 점수 저장
	for (i = 0; i < 5; i++) {
		printf("Input ID: ");
		scanf("%d", &ID[i]);
		
		printf("Input Scores: ");
		scanf("%d %d %d %d", &score[0][i], &score[1][i], &score[2][i], &score[3][i]);
	}

	//ID와 ID별 과목 점수 출력과 동시에 총합과 평균 계산 및 출력
	printf("ID\tKOR\tENG\tMATH\tC++\tTOTAL\tAVG\n");
	for (i = 0; i < 5; i++) {
		printf("%d\t", ID[i]);
		for (j = 0; j < 4; j++) {
			printf("%d\t", score[j][i]);
			sum += score[j][i];
		}
		average = sum / 4.0;
		printf("%d\t%.2lf\n", sum, average);
		sum = 0;
	}
}
void mabangjin()
{
	//마방진 출력
	int jin[10 * 10] = { 0 }; //최대 넓이 100
	int N, i;
	int index;

	scanf("%d", &N);
	//입력 값이 짝수이면 N+1
	if (N % 2 == 0)
		N = N + 1;
	//입력 값이 범위를 넘어가면 오류 문 출력
	while (N > 10){
		printf("N should be a number between 1 to 9\n");
		printf("Try Again\n");
		scanf("%d", &N);
	}

	//첫 value인 1의 index 계산
	index = N*N - (N / 2) - 1;

	for (i = 1; i <= N*N; i++) {
		jin[index] = i;
		//다음 index 값 계산
		/* 1.index+1의 값이 boundary일 시,
			a) 배열의 첫번째 자리가 비어있을 때,
				index는 0이 된다.
			b) 배열의 첫번쨰 자리가 안비어있으면
				index는 그림 상 그 윗칸(index - N)
			c) 둘 다 해당사항 없으면 index + 1;
		   2. 다음 index값이 비어있는 공간이 아니면 index-N
		   3. default는 오른쪽 한칸 이동 후 밑으로 한 칸
		*/
		if ((index + 1) % N == 0){
			if ((index + 1 == N*N)) {
				if (jin[0] == 0)
					index = 0;
				else
					index = index - N;
			}
			else
				index = index + 1;
		}
		else if (jin[((index + 1) + N) % (N*N)] != 0)
			index = index - N;
		else
			index = ((index + 1) + N) % (N*N);
	}
	//출력
	for (i = 0; i < N*N; i++) {
		if (i%N == 0 && i != 0)
			printf("\n");
		printf("%d ", jin[i]);
	}
	printf("\n");
}
void SameNumberGame()
{
	int set[10 * 10] = { 0 }; //100넓이로 초기화(최대)
	int width, height;
	int area;
	int index, i;

	printf("Input width, height: ");
	scanf("%d %d", &width, &height);
	area = width * height;
	//넓이가 홀수 이면 오류 문 출력
	if (area % 2 != 0)
	{
		while (1) {
			printf("Area of the table should be even. Try Again\n");
			printf("Input width, height: ");
			scanf("%d %d", &width, &height);
			area = width * height;
			if (area % 2 == 0)
				break;
		}
	}

	//1~전체 배열 원소 개수/2 까지 random index 2곳에 저장
	for (i = 1; i <= area/2; i++) {
		index = rand() % area;
		if (set[index] != 0) {
			//index값이 비어있지 않으면 빌 때까지 난수 생성
			while (set[index] != 0)
				index = rand() % area;
		}
		set[index] = i;
		index = rand() % area;
		if (set[index] != 0) {
			//index값이 비어있지 않으면 빌 때까지 난수 생성
			while (set[index] != 0)
				index = rand() % area;
		}
		set[index] = i;
	}

	//출력
	for (i = 0; i < area; i++)
	{
		if (i % width == 0 && i != 0)
			printf("\n");
		printf("%d ", set[i]);
	}
	printf("\n");
}



int main()
{
	int i;
	srand(1);
		//generateRandomSet();
		//findMinMaxValue();
		//findIntersectionSet();
		//findUnionSet();
		//printHistogram();
		//printScoreReport();
		//mabangjin();
		//SameNumberGame();
		//printScoreReport();
		//printHistogram();
	return 0;
}