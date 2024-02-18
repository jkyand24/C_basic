#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

// 1.

void function1(int array[][5]) {
	printf("\n<1>\n");
	for (int row = 0; row < 5; row++) {
		for (int col = 0; col < row; col++) {
			array[row][col] = 0;
		}
	}
}

// 2-1.

typedef struct _StudentInfo2_1 {
	char name[10];
	int score;
} StudentInfo2_1;

void function2_1(StudentInfo2_1 students[]) {
	printf("\n<2-1>\n");
	float score_sum = 0.0;

	for (int i = 0; i < 5; i++) {
		printf("학생 #%d의 이름과 점수를 입력하세요: ", i + 1);
		scanf_s("%s %d", students[i].name, (unsigned)_countof(students[i].name), &students[i].score);

		score_sum += students[i].score;
	}

	float score_avg = score_sum / (float)5;

	for (int i = 0; i < 5; i++) {
		if (students[i].score <= score_avg) {
			printf("%s\n", students[i].name);
		}
	}
}

// 2-2.

typedef struct _StudentInfo2_2 {
	char name[20];
	int score1;
	int score2;
	int score3;
	float score_avg;
	char grade;
} StudentInfo2_2;

void function2_2 () {
	printf("\n<2-2>\n");

	int N;
	int N_min = 1;
	int N_max = 20;
	do {
		printf("학생은 몇 명인가요?: ");
		scanf_s("%d", &N);

		if (N < N_min || N > N_max) {
			printf("입력한 값이 범위 바깥입니다. 다시 입력해 주세요.\n");
		}
	} while (N < N_min || N > N_max);

	printf("입력한 N은 %d입니다.\n", N);

	StudentInfo2_2* students;

	students = (StudentInfo2_2*)malloc(sizeof(StudentInfo2_2) * N);

	for (int i = 0; i < N; i++) {
		printf("학생 #%d의 이름과 세 번의 점수를 입력하세요: ", i + 1);
		scanf_s("%s %d %d %d", students[i].name, (unsigned)_countof(students[i].name), &students[i].score1, &students[i].score2, &students[i].score3);

		students[i].score_avg = (students[i].score1 + students[i].score2 + students[i].score3) / (float)3;

		if (students[i].score_avg >= 90) students[i].grade = 'A';
		else if (students[i].score_avg >= 80) students[i].grade = 'B';
		else if (students[i].score_avg >= 70) students[i].grade = 'C';
		else students[i].grade = 'F';
	}

	for (int i = 0; i < N; i++) {
		printf("학생 #%d의 이름, 평균점수, 학점: %s %.1f %c\n", i+1, students[i].name, students[i].score_avg, students[i].grade);
	}
}

// main

int main() {
	// 1.

	int array1[5][5] = {
		{1, 2, 3, 4, 5},
		{10, 20, 30, 40, 50},
		{100, 200, 300, 400, 500},
		{1000, 2000, 3000, 4000, 5000},
		{10000, 20000, 30000, 40000, 50000}
	};

	function1(array1);

	printf("대각선 아래 요소를 0으로 설정한 후:\n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d ", array1[i][j]);
		}
		printf("\n");
	}

	// 2-1.

	StudentInfo2_1 students[5];

	function2_1(students);

	// 2-2.

	function2_2();

	//

	return 0;
}