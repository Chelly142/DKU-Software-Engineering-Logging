#include <stdio.h>
#include <string.h>

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
