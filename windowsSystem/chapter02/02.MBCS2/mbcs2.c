#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	char str[] = "�ѱ��Դϴ�.";
	int i;

	for (i = 0; i < 5; i++) {
		/** char���� �ϳ� stdout console�� �־ �����ش�. */
		fputc(str[i], stdout);
	}

	fputc('\n', stdout);

	for (i = 0; i < 10; i++) {
		fputc(str[i], stdout);
	}
	fputc('\n', stdout);

	return 0;
}