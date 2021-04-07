#include <stdio.h>

int main() {
	int n=0, MaxCnt=0, Top=0, Max=0;
	scanf("%d", &n);
	int Vote[n];
	for(int i=0; i<n; i++) {
		scanf("%d", &Vote[i]);
		if(Vote[i] > Max) {
			Max = Vote[i];
		}
	}
	int Index[Max+1];//C언어는 배열크기 초기화 하는 부분이 자바와 틀림
	for(int i=0; i<=Max+1; i++) {
		Index[i] = 0;//변수에 초기값 0 입력합니다.
	}
	//핵심로직(아래)
	for(int i=0; i<n; i++) {
		Index[Vote[i]] = Index[Vote[i]] + 1;//중복값이 존재하면 카운팅이 발생
		//printf("%d, %d\n", Vote[i], Index[Vote[i]]); 디버그용 출력
	}
	//최고값과 반복횟수 구하기(아래)
	for(int i=0; i<Max+1; i++) {
		if(Index[i] > MaxCnt) {
			MaxCnt = Index[i];
			Top = i;
		}
	}
	printf("최다 선택값: %d, 선택한 횟수: %d", Top, MaxCnt);
	return 0;
}