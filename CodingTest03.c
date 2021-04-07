#include <stdio.h>

int main() {
	int n, bubble, idx, Temp;
	scanf("%d",&n);
	int Numbers[n];
	//printf("디버그: %d", n);
	for(int i=0; i<n; i++) {
		scanf("%d", &Numbers[i]);	
	}
	for(bubble=0; bubble<n; bubble++) {
		for(idx=0; idx<n-1; idx++) {
			if(Numbers[idx] > Numbers[idx+1]) {
				Temp = Numbers[idx];
				Numbers[idx] = Numbers[idx+1];
				Numbers[idx+1] = Temp;
			}
		}
	}
	for(int i=0; i<n; i++) {
		printf("%d ",Numbers[i]);
	}
	return 0;
}