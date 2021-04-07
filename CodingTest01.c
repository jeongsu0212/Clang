#include <stdio.h>

int main() {
	int MONEY=0;//키보드로 입력받는 값
	int UNIT=50000,NUM=0,SW=0;
	scanf("%d",&MONEY);
	//printf("입력받은 값은 %d 입니다.",MONEY);
	while(1){
		NUM=(int)(MONEY/UNIT);
		if(NUM>0){
			printf("화폐단위 %d 원의 개수는 %d\n",UNIT,NUM);
		}
		if(UNIT>1){
			MONEY=MONEY-(UNIT*NUM);
			if(SW==0){
				UNIT=UNIT/5;
				SW=1;
			}else{
				UNIT=UNIT/2;
				SW=0;
			}
		}else{
			break;
		}
	}
	return 0;
}