#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	wchar_t str[] = L"ABC";
	int size = sizeof(str);
	/** wchar_t�� ���̸� ���ϱ� ���ؼ� ����ϴ� �迭�� ���� ���ϴ� �Լ� wcslen() str��� wcs�� ��� */
	int len = wcslen(str);

	printf("�迭�� ũ�� : %d\r\n", size);
	printf("���ڿ��� ���� : %d\r\n", len);

	return 0;
}