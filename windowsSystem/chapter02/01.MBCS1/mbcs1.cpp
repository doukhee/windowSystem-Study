#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	/** �ѱ��� 2bit ������ 1bit�� ũ�⸦ ������. */
	char str[] = "ABC�ѱ�";
	int size = sizeof(str);
	int len = strlen(str);

	printf("�迭�� ũ�� : %d\r\n", size);
	printf("�迭�� ���� : %d\r\n", len);
	return 0;
}
