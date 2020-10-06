#include <stdio.h>
#include <string.h>

/** 인자를 일반 방식으로 받아서 출력이 안된다. */
int main(int argc, char* argv[]) {
	int i;
	for (i = 0; i < argc; i++) {
		/** unicode 방식의 출력 */
		fputws(argv[i], stdout);
	}
	return 0;
}