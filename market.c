#include <stdio.h>
#include "manager.h"

void selectMenu(){
    printf("1.아이템 추가\
    \n2.아이템 조회\
    \n3.아이템 업데이트\
    \n4.아이템 삭제\
    \n5.Save!\
    \n0.종료\n");

}


int UserSelect(){
int select;
scanf("%d",&select);
return select;}


int main(void){

        product s[100];
    int count = 0;
    while(1){
        selectMenu();
	int select=UserSelect();
	#ifdef DEBUG
	printf("Debug : %s %s %s %d. variable select get %d by UserSelect().\n\n"\
, __DATE__, __TIME__ , __FILE__, __LINE__, select);
	#endif

        if(select ==1){
            if(addproduct(&s[count])==0)count++;
	#ifdef DEBUG
	printf("Debug : %s %s %s %d.Variable count initialized to %d.\
 addproduct(&s[count]) used.\n\n ", __DATE__, __TIME__ , __FILE__, __LINE__, count);
	#endif
        }
        else if(select == 2){
            multi_readProduct(s,count);
	#ifdef DEBUG
	printf("Debug : %s %s %s %d. readProduct(s,count) used.\n\n ", __DATE__, __TIME__, __FILE__, __LINE__);
	#endif
        }

        else if(select == 3){
           multi_updateProduct(s,count);
	#ifdef DEBUG
	printf("Debug : %s %s %s %d. updateProduct(s,count) used.\n\n ", __DATE__, __TIME__, __FILE__, __LINE__);
	#endif
        }

         else if(select == 4){
          count = multi_deleteProduct(s,count);
	#ifdef DEBUG
	printf("Debug : %s %s %s %d.\
 deleteProduct(s,count) used. Variable count is newly initialized to %d\n\n ", __DATE__, __TIME__, __FILE__, __LINE__,count);
	#endif
        }
	else if(select == 5){
	SaveData(s,count);
	#ifdef DEBUG
	printf("Debug : %s %s %s %d.\ SaveData(s,count) used. Number of saved datus are %d", __DATE__, __TIME__, __FILE__, __LINE__,count);
	#endif
	}

        if(select == 0){
	#ifdef DEBUG
	printf("Debug : %s %s %s %d.  Program closed.\n\n ", __DATE__, __TIME__, __FILE__, __LINE__);
	#endif
        break;}

}
}

