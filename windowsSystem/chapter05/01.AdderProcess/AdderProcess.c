#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

int _tmain(int argc, TCHAR** argv) {
	
	DWORD val1, val2;
	/** _ttoi() 문자열 데이터를 정수형 데이터로 변경시키는 atoi()함수와 유니코드 기반의 _wtoi()를 동시 지원하기 위한 매크로 */
	val1 = _ttoi(argv[1]);
	val2 = _ttoi(argv[2]);

	_tprintf(_T("%d + %d = %d \rn"), val1, val2, val1 + val2);
	/** getchar 함수와 유니코드 기반의 getwchar 함수를 동시 지원하기 위한 매크로 */
	//_gettchar();
	return 0;
}