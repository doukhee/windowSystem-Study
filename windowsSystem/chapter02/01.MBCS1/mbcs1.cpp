#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	/** 한글은 2bit 영문은 1bit의 크기를 가진다. */
	char str[] = "ABC한글";
	int size = sizeof(str);
	int len = strlen(str);

	printf("배열의 크기 : %d\r\n", size);
	printf("배열의 길이 : %d\r\n", len);
	return 0;
}
