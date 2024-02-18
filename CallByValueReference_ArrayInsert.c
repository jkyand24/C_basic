#include <stdio.h>

// SquareByValue: 함수 호출 시, 넘겨지는 인자의 "값"이 매개변수에 복사됨.
// 따라서, 함수 내에서 어떤 처리가 일어나더라도, 원래의 값에 반영되지 않음.

void SquareByValue(int num) {
	num = num * num;
	printf("제곱된 결과 (SquareByValue): %d\n", num);
}

// SquareByReference: 함수 호출 시, 넘겨지는 인자의 "주소"가 복사됨.
// 즉 직접 참조이므로, 함수 내의 처리가 원래의 값에 반영됨.

void SquareByReference(int *pt) {
	*pt = (*pt) * (*pt);
	printf("제곱된 결과 (SquareByReference): %d\n", *pt);
}

// Insert 함수: num개의 element를 가진 myarr의 pos 위치에 val이 insert됨.

void Insert(int myarr[], int num, int pos, int val) {
	// pos 위치 뒤에 있는 element들은 한 index 뒤로 옮김
	for (int i = num - 1; i >= pos; i--)
		myarr[i + 1] = myarr[i];

	// pos 위치에 val을 할당
	myarr[pos] = val;

	// 최종 결과 확인
	printf("최종 array: ");
	for (int i = 0; i <= num; i++) printf("%d ", myarr[i]);
}

// main

void main() {
	// SquareByValue에 사용할 num1, SquareByReference에 사용할 num2를 사용자로부터 입력받은 뒤
	// SquareByValue, SquareByReference 실행

	int num1, num2;
	printf("자연수를 입력하십시오 (SquareByValue): ");
	scanf_s("%d", &num1);
	printf("자연수를 입력하십시오 (SquareByReference): ");
	scanf_s("%d", &num2);

	SquareByValue(num1);
	printf("num1: %d\n", num1);
	SquareByReference(&num2);
	printf("num2: %d\n", num2);

	// Insert에 사용할 parameter들을 사용자로부터 입력받은 뒤 
	// Insert 실행

	int myarr[30] = { 0, }; // 임의로 30개의 0으로 초기화된 int array 선언, 정의
	int num, pos, val;
	printf("array 내 element의 개수를 정해주세요: ");
	scanf_s("%d", &num);
	for (int i = 0; i < num; i++) myarr[i] = i; // array 내 요소를 0, 1, 2, ..으로 초기화
	printf("insert할 index를 정해주세요: ");
	scanf_s("%d", &pos);
	printf("insert할 값을 정해주세요: ");
	scanf_s("%d", &val);

	Insert(myarr, num, pos, val);
}