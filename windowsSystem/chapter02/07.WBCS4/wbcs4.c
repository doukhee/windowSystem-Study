#include <stdio.h>
#include <string.h>

/** 전달 받은 인자가 unicode라는 설정 및 unicode 기반 main 설정 */
int wmain(int argc, wchar_t** argv) {
	for (int i = 0; i < argc; i++) {
		/** unicode 기반 문자열 console에 출력하는 함수 fputws() */
		fputws(argv[i], stdout);
		fputws(L"\n", stdout);
	}

	return 0;
}