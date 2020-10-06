#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	wchar_t str[] = L"ABC";
	int size = sizeof(str);
	int len = wcslen(str);
	/** unicode¹æ½ÄÀÇ printf */
	wprintf(L"Array Size : %d\r\n", size);
	wprintf(L"String Length : %d \r\n", len);
	return 0;
}