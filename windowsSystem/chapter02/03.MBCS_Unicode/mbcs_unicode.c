#include <stdio.h>
#include <string.h>


int main(int argc, char** argv) {
	/** ���̵� ���ڸ� �����ϱ� ���� �ڷ��� �����ڵ�� 2bit�̻����� ǥ���ϱ� ������ wchar_t�� �����ؾ��Ѵ�. */
	wchar_t str[] = L"ABC";
	int size = sizeof(str);
	int len = strlen(str);

	printf("�迭�� ũ�� : %d \r\n", size);
	printf("���ڿ��� ���� : %d\r\n", len);
	return 0;
}