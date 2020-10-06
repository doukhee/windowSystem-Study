#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	wchar_t str[] = L"ABC";
	int size = sizeof(str);
	/** wchar_t의 길이를 구하기 위해서 사용하는 배열의 길이 구하는 함수 wcslen() str대신 wcs를 사용 */
	int len = wcslen(str);

	printf("배열의 크기 : %d\r\n", size);
	printf("문자열의 길이 : %d\r\n", len);

	return 0;
}