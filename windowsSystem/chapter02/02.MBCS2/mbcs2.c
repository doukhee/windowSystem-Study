#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	char str[] = "한글입니다.";
	int i;

	for (i = 0; i < 5; i++) {
		/** char형을 하나 stdout console에 넣어서 보여준다. */
		fputc(str[i], stdout);
	}

	fputc('\n', stdout);

	for (i = 0; i < 10; i++) {
		fputc(str[i], stdout);
	}
	fputc('\n', stdout);

	return 0;
}