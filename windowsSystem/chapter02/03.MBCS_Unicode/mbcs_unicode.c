#include <stdio.h>
#include <string.h>


int main(int argc, char** argv) {
	/** 와이드 문자를 저장하기 위한 자료형 유니코드는 2bit이상으로 표현하기 때문에 wchar_t에 지정해야한다. */
	wchar_t str[] = L"ABC";
	int size = sizeof(str);
	int len = strlen(str);

	printf("배열의 크기 : %d \r\n", size);
	printf("문자열의 길이 : %d\r\n", len);
	return 0;
}