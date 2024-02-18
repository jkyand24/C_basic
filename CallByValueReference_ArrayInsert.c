#include <stdio.h>

// SquareByValue: �Լ� ȣ�� ��, �Ѱ����� ������ "��"�� �Ű������� �����.
// ����, �Լ� ������ � ó���� �Ͼ����, ������ ���� �ݿ����� ����.

void SquareByValue(int num) {
	num = num * num;
	printf("������ ��� (SquareByValue): %d\n", num);
}

// SquareByReference: �Լ� ȣ�� ��, �Ѱ����� ������ "�ּ�"�� �����.
// �� ���� �����̹Ƿ�, �Լ� ���� ó���� ������ ���� �ݿ���.

void SquareByReference(int *pt) {
	*pt = (*pt) * (*pt);
	printf("������ ��� (SquareByReference): %d\n", *pt);
}

// Insert �Լ�: num���� element�� ���� myarr�� pos ��ġ�� val�� insert��.

void Insert(int myarr[], int num, int pos, int val) {
	// pos ��ġ �ڿ� �ִ� element���� �� index �ڷ� �ű�
	for (int i = num - 1; i >= pos; i--)
		myarr[i + 1] = myarr[i];

	// pos ��ġ�� val�� �Ҵ�
	myarr[pos] = val;

	// ���� ��� Ȯ��
	printf("���� array: ");
	for (int i = 0; i <= num; i++) printf("%d ", myarr[i]);
}

// main

void main() {
	// SquareByValue�� ����� num1, SquareByReference�� ����� num2�� ����ڷκ��� �Է¹��� ��
	// SquareByValue, SquareByReference ����

	int num1, num2;
	printf("�ڿ����� �Է��Ͻʽÿ� (SquareByValue): ");
	scanf_s("%d", &num1);
	printf("�ڿ����� �Է��Ͻʽÿ� (SquareByReference): ");
	scanf_s("%d", &num2);

	SquareByValue(num1);
	printf("num1: %d\n", num1);
	SquareByReference(&num2);
	printf("num2: %d\n", num2);

	// Insert�� ����� parameter���� ����ڷκ��� �Է¹��� �� 
	// Insert ����

	int myarr[30] = { 0, }; // ���Ƿ� 30���� 0���� �ʱ�ȭ�� int array ����, ����
	int num, pos, val;
	printf("array �� element�� ������ �����ּ���: ");
	scanf_s("%d", &num);
	for (int i = 0; i < num; i++) myarr[i] = i; // array �� ��Ҹ� 0, 1, 2, ..���� �ʱ�ȭ
	printf("insert�� index�� �����ּ���: ");
	scanf_s("%d", &pos);
	printf("insert�� ���� �����ּ���: ");
	scanf_s("%d", &val);

	Insert(myarr, num, pos, val);
}