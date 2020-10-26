#include <stdio.h>
#include <string.h>
#define MAX_TERMS 101

//기본 행렬 곱
void multiplyTwoArrays(int** res, int** a, int** b, int m, int n, int q) {
	for (int i; i < m; i++) {
		for (int j; j < q; j++) {
			int sum = 0;
			for (int k; k < n; k++)
				sum += a[i][n] * b[n][j];
			res[i][j] = sum;
		}
	}
}
//희소 행렬 
typedef struct {
	int col;
	int row;
	int value;
}MATRIX;
MATRIX s[MAX_TERMS];
//희소 행렬 전치 
void transpose(MATRIX* a, MATRIX* b) {
	int current = 1;
	b[0].col = a[0].col;
	b[0].row = a[0].row;
	b[0].value = a[0].value;
	for (int i = 0; i < a[0].col; i++) {
		for (int j = 1; j < a[0].value; j++) {
			if (i == a[j].col) {
				b[current].row = i;
				b[current].col = a[j].row;
				b[current].value = a[j].value;
				current++;
			}
		}
		
	}
}
//희소행렬 값 구하기
int getValue(int r, int c, MATRIX* s) {
	int k;
	if (r < 0 || r >= s[0].row || c < 0 || c >= s[0].col) {
		printf("r or c index is out of range\n");
		return -1;
	}
	for (k = 1; k < s[0].value; k++) {
		if (s[k].row == r && s[k].col == c)
			return s[k].value;
		else
			return 0;
	}
}
//희소행렬 곱
void multiplyTwoSparses(int** res, MATRIX* A, MATRIX* B) {
	for (int r = 0; r < A[0].row; r++) {
		for (int c = 0; c < B[0].col; c++) {
			int sum = 0;
			for (int n = 0; n < A[0].col; n++) {
				sum = getValue(r, n, A) * getValue(n, c, B);
			}
			res[r][c] = sum;
		}
	}
}

//문자열속 원하는 문자열 찾기
int stringMatching(const char* str, const char* pat) {
	int str_len = strlen(str);
	int pat_len = strlen(pat);
	int j, q;
	for (int i = 0; i < str_len; i++) {
		for (j = 0,q=i; q < str_len && pat[j] == str[q]; j++,q++)
			continue;
		if (j == pat_len)
			return i;
	}
	return -1;
}
//문자열속 원하는 문자열 찾기 업그래이드
int stringMatching2(const char* str, const char* pat) {
	int lastpat_len = strlen(pat) - 1;
	int laststr_len = strlen(str) - 1;
	int j, q;
	printf("%d   %c\n", lastpat_len, pat[lastpat_len]);
	for (int i = 0; i < laststr_len; i++) {
		if (pat[lastpat_len + i] == str[lastpat_len]) {
			for (j = 0, q = i; j < lastpat_len  && pat[j] == str[q]; j++, q++)
				continue;
			if (j == lastpat_len)
				return i;
		}
	}
	return -1;
}

int main(void) {
	
	printf("%d\n", stringMatching("abcdefghijklmnopqrstuvwxyz", "efg"));
	printf("%d", stringMatching2("abcdefghijklmnopqrstuvwxyz", "efg"));
	return 0;
}
