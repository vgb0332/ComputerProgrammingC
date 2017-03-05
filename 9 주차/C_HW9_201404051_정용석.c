#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

void arrayRotation()  
{
	int input;
	int set[MAX_SIZE][MAX_SIZE];
	int i, j;
	int value = 1;

	scanf("%d", &input);

	for (i = 0; i < input; i++) {
		for (j = 0; j < input; j++)
			set[i][j] = value++;
	}

	for (i = 0; i < input; i++) {
		for (j = 0; j < input; j++)
			printf("%d ", set[i][j]);
		printf("\n");
	}

	printf("\n");

	for (i = 0; i < input; i++) {
		for (j = input-1; j >= 0; j--)
			printf("%d ", set[j][i]);
		printf("\n");
	}
}
void arrayReverse()
{
	int M, N;
	int i, j;
	int set[MAX_SIZE][MAX_SIZE];
	int value = 1;

	scanf("%d %d", &M, &N);

	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			set[i][j] = value++;

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++)
			printf("%d ", set[i][j]);
		printf("\n");
	}
	printf("\n");

	for (i = M - 1; i >= 0; i--) {
		for (j = N - 1; j >= 0; j--)
			printf("%d ", set[i][j]);
		printf("\n");
	}
}
void diamondArray()  // ¹®Á¦3. ¸¶¸§¸ð ¸ð¾çÀÇ ¹è¿­ Ãâ·Â
{
	int set[MAX_SIZE][MAX_SIZE] = { 0 };
	int i, j;
	int M;
	int value = 1;
	int begin;
	int count = 0;

	scanf("%d", &M);

	if(M % 2 == 0)
		while (M % 2 == 0) {
			printf("Odd Number Only plz\n");
			scanf("%d", &M);
		}
	
	begin = M / 2;
	for (j = 0; j < M; j++) {
		for (i = begin - count; i <= begin + count; i ++) {
			set[i][j] = value;
			value += 2;			
		}
		if (j >= begin)count--;
		else count++;		
	}

	for (j = 0; j < M; j++)
	{
		for (i = 0; i < M; i++) {
			if (set[i][j] == 0) printf("   ");
			else printf("%2d ", set[i][j]);
		}
		printf("\n");
	}
	
}
void arraySum() // 행렬의 합 출력
{
	int m, n; //m: 행, n: 열
	int setA[MAX_SIZE][MAX_SIZE]; //행렬 A
	int setB[MAX_SIZE][MAX_SIZE]; //행렬 B
	int value = 1;
	int i, j;

	scanf("%d %d", &m, &n);

	//행렬 A에는 1~m*n을 차례대로 대입
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			setA[i][j] = value++;

	value = 1;
	//행렬 B에는 1부터 +2 증가하는 값을 차례대로 대입
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++) {
			setB[i][j] = value;
			value += 2;
		}
	//행렬A+행렬B 출력
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++)
			printf("%d ", setA[i][j] + setB[i][j]);
		printf("\n");
	}
}
void arrayMul()  // 행렬의 곱을 출력
{
	int m, n; //m: 행, n: 열
	int set1[MAX_SIZE][MAX_SIZE]; //행렬 A
	int set2[MAX_SIZE][MAX_SIZE]; //행렬 B
	int i, j, k;
	int value = 1;

	scanf("%d %d", &m, &n);

	// m X n 행렬
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			set1[i][j] = value++;

	value = 1;

	// n X m 행렬
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			set2[i][j] = value++;
	}

	value = 0;
	k = 0;

	// 행렬 A X 행렬 B 출력
	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			while (k != n) {
				//행렬 A의 각각의 행의 원소 X 행렬 B의 각각의 열의 원소
				value += set1[i][k] * set2[k][j];
				k++;
			}
			//출력 및 변수 초기화
			printf("%d ", value);
			value = 0;
			k = 0;
		}
		printf("\n");
	}
}
void spiralArray()  // 나선형 모양 행렬
{
	int m; //m: 열과 행
	int i, j;
	int set[MAX_SIZE][MAX_SIZE];
	int value = 1;
	int x, y;	//x: 열 이동, y: 행 이동
	int begin;	//시작점
	int end;	//끝점
	int repeat;	//반복 횟수

	scanf("%d", &m);
	
	//행렬 생성
	for (i = 0; i < m; i++)
		for (j = 0; j < m; j++)
			set[i][j] = value++;
	//변수들 초기화
	i = 0;
	x = 0;
	y = 0;
	begin = 0;
	end = m - 1;
	//행의 길이 보다 1 작게 반복
	repeat = m - 1;

	while (1) {
		//반복 횟수 0 혹은 -1 이면 
		//홀수 일시, 마지막 원소 출력 후 종료
		//짝수 일시, 그냥 종료
		if (repeat <= 0) {
			if (m % 2 == 0) break;
			else {
				printf("%d ", set[y][x]);
				break;
			}
		}
		
		for (i = 0; i < repeat; i++) //행렬의 좌상->우상
			printf("%d ", set[begin][x++]);
		for (i = 0; i < repeat; i++) //행렬의 우상->우하
			printf("%d ", set[y++][end]);
		for (i = 0; i < repeat; i++) //행렬의 우하->좌하
			printf("%d ", set[end][x--]);
		for (i = 0; i < repeat; i++) //행렬의 좌하->좌상
			printf("%d ", set[y--][begin]);
		//변수들 증가 및 감소, 초기화
		y++;
		x++;
		begin++;
		end--;
		repeat -= 2;
	}
	printf("\n");
}
void totalPath()  // 가능한 Path의 개수
{
	int set[MAX_SIZE][MAX_SIZE];
	int m, n; //행: m, 열: n
	
	scanf("%d %d", &m, &n);
	printf("%d\n", RecursivePath(m, n));
}
int RecursivePath(int m, int n) // Path개수를 찾기 위한 재귀함수
{
	if (m == 1 || n == 1) //행이나 열의 끝에 도달하면 리턴 1
		return 1;
	return RecursivePath(m - 1, n) + RecursivePath(m, n - 1);
}
void LongestPath()  // Longest path의 값 출력
{
	srand(1); //랜덤 시드값 1
	int set[MAX_SIZE][MAX_SIZE]; //랜덤 행렬
	int d[MAX_SIZE][MAX_SIZE];	 //점화식 행렬
	int m, n; //행: m, 열: n
	int i, j;
	int add;

	scanf("%d %d", &m, &n);
	
	//랜덤 행렬 생성 및 출력
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			set[i][j] = rand() % 29 + 1;
	/*
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++)
			printf("%d ", set[i][j]);
		printf("\n");
	}
	*/
	//점화식 행렬 생성
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (i == 0 && j == 0) //첫 번째 [0, 0] 원소
				d[i][j] = set[i][j];
			else if (i == 0 && j != 0) {//열 번호가 0일때
				d[i][j] = d[i][j - 1] + set[i][j];
			}
			else if (i != 0 && j == 0) {//행 번호가 0일때
				d[i][j] = d[i - 1][j] + set[i][j];
			}
			else {//위와 왼쪽의 원소를 비교 큰 대상과 합
				if (d[i - 1][j] > d[i][j - 1]) 
					add = d[i - 1][j];
				else
					add = d[i][j - 1];
				d[i][j] = add + set[i][j];
			}
		}
	}
	/*
	printf("\n\n");
	//점화식 출력
	for (i = 0; i < m; i ++) {
		for (j= 0; j < n; j++)
			printf("%d ", d[i][j]);
		printf("\n");
	}
	*/
	printf("%d\n", d[m-1][n-1]);
}

int main()
{
	int i = 0;
	while (i++ != 5) {
		//arrayRotation();  
		//arrayReverse();   
		//diamondArray();  
		//arraySum();
		//arrayMul();      
		//spiralArray();   
		//totalPath();     
		LongestPath();
		printf("\n");
	}

	return 0;
}