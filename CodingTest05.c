#include <stdio.h>

int main() {
	int Bin[100];
	int Dec, idx=0, Mok, Nmg;
	scanf("%d", &Dec);
	while(1) {
		Mok = (int)Dec/2;
		//printf("%d", Mok);
		Nmg = Dec - (Mok*2);
		Bin[idx] = Nmg;
		idx = idx + 1;
		if(Mok==0) {break; }
		Dec = Mok;
	}
	for(int i=idx-1; i>=0; i--) {
		printf("%d", Bin[i]);
	}
	return 0;
}
