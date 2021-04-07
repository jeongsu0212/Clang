#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//전역변수특이사항: 배열의 리턴값(변수=값)을 사용할 경우 포인터변수로 만들어야 함.
//char endString[];//전역변수 사용시 포인터 변수로 해야 함.
//char endString[]={'K','i','t','t','y'};
char* endString="";//전역변수 사용시 포인터 변수로 해야 함.
char* resutlString="";//전역변수 사용시 포인터 변수로 해야 함.
char* resutlString2="";
//인터페이스=함수정의 3개
char* recursive(char w[]);
int getBalancedIndex(char w[]);
bool isValidString(char u[]);
char* reArrange(char u[]);
int main() {
	int n;//배열크기를 지정하는 변수
	char w[n];//초기 코드소스 입력값
  	char* r;//최종 리턴값은 포인터로 변경
	scanf("%s", w);//특이사항. 배열변수는 &가 붙지 않음.
	r = recursive(w);
	//printf("디버그 %s\n", r);
	if(strcmp(w,r)==0) {
		printf("올바른 괄호문자열 입니다. %s", r);
	}else{
		printf("잘못된 괄호문자열 입니다. 입력값 %s, 출력값 %s", w, r);
	}
	return 0;
}
char* recursive(char w[]) {
	if(w == NULL || strlen(w)==0) {
		resutlString = strcat(w,endString);
		printf("여기3 %s\n", resutlString);
		return resutlString;
	}
	int balacedIndex = getBalancedIndex(w);
	int n;
	char *u = malloc(strlen(w) + 1);
	char *v = malloc(strlen(w) + 1);
	strncpy(u, w, balacedIndex+1);
	printf("여기1 %d\n", strlen(w)-1);
	printf("여기2 %d\n", balacedIndex);
	
	if(strlen(u)>1) {
		strncpy(v, w+balacedIndex+1, strlen(w)-1);
	}
	
	bool isValidCheck = isValidString(u);
	
	if(isValidCheck) {
		//Unit값이 ( 문자 하나라면 균형문자 추가 20210407(수) 문자열처리 문제있음.
		if(strcmp("(",u)==0) { endString = strcat(endString,")"); }
		recursive(v);
		printf("%s\n", u);
		resutlString = strcat(u,resutlString);
		printf("여기2 %s\n", resutlString);
		if(strlen(resutlString2)>0){
			return strcat(resutlString2,resutlString);
		}else{
			return resutlString;
		}
	}else{
		//char *createString = malloc(strlen(w) + 1);
		if(strlen(u)>1) {
			resutlString2 = strcat(resutlString2,recursive(v));
		}
		resutlString2 = reArrange(u);
		printf("여기1 %s\n", resutlString2);
		return resutlString2;	
	}
}
char* reArrange(char u[]) {
	//char* arrangeString;
	char* arrangeString = malloc(strlen(u) + 1);
	for(int i=1; i<strlen(u)-1; i++) {
		if(u[i] == '(') {
			strcat(arrangeString,")");
		}else if(u[i] == ')') {
			strcat(arrangeString,"(");
		}
	}
	arrangeString = strcat(arrangeString,"()");
	return arrangeString;
}
bool isValidString(char u[]) {
	int balancedCount = 0;
	for(int i=0; i<strlen(u); i++) {
		if(u[i] == '(') {
			balancedCount++;
		}else if(u[i] == ')') {
			balancedCount--;
		}
		if(balancedCount < 0) {
			return false;
		}
	}
	return true;
}
int getBalancedIndex(char w[]) {
	int index = 0, balancedCount = 0;
	for(int i=0; i<strlen(w); i++) {
		//printf("%c\n", w[i]);
		if(w[i] == '(') {
			balancedCount++;
		}else if(w[i] == ')') {
			balancedCount--;
		}
		if(balancedCount == 0) {
			index = i;
			break;
		}
	}
	return index;
}