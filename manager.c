#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "manager.h"


void multi_readProduct(product s[], int count){
    if(count == 0) {printf("데이터가 없습니다!\n\n");return;}

    printf("No.      이름      중량    가격     표준가격     평점\n");
    for(int i=0; i<count;i++){
        printf("%d %15s%5dg%6d원   %5.0f원     %5.1f점\n",i+1,s[i].name,s[i].weight,s[i].price,s[i].weight_per_price,s[i].reputation);
    }
    }

int multi_updateProduct(product s[], int count){
    if(count == 0) {printf("데이터가 없습니다!\n\n");return -1;}
   multi_readProduct(s,count);
    int select;
    printf("수정할 아이템의 번호를 입력해주세요");
    scanf("%d",&select);
    if(select< 1 || select > count) {
    printf("잘못된 입력입니다!\n");
    return -1;

}
   printf("새 아이템의 이름은?\n");
      char enter;
    enter = getchar();
   fgets(s[select-1].name,30,stdin);
    s[select-1].name[strlen(s[select-1].name)-1] = '\0';

    do{
    printf("아이템의 중량을 입력해주세요\n");
    scanf("%d",&s[select-1  ].weight);
    if(s[select-1  ].weight<0)printf("다시입력해주세요!\n");
    } while(s[select-1  ].weight<=0);

   do{
    printf("아이템의 가격을 입력해주세요\n");
    scanf("%d",&s[select-1  ].price);
    if(s[select-1  ].price<=0)printf("다시입력해주세요!\n");
    }while(s[select-1  ].price<=0);

    do{
    printf("아이템의 평점을 입력해주세요(0~5까지 소수점 입력 가능!)\n");
    scanf("%f",&s[select-1  ].reputation);
    if(s[select-1  ].reputation>5||s[select-1  ].reputation<0)printf("다시입력해주세요!\n");
    }while(s[select-1  ].reputation>5||s[select-1  ].reputation<0);

    s[select-1  ].weight_per_price = (float)s[select-1  ].price/s[select-1  ].weight*10;

    printf("수정성공!\n\n");

return 0;
}


int multi_deleteProduct(product s[], int count){
    if(count == 0){printf("데이터없음!\n\n");return count;}
    multi_readProduct(s,count);
    int select;
    printf("수정할 아이템의 번호를 입력해주세요");
    scanf("%d",&select);
    if(select< 1 || select > count) {
    printf("잘못된 입력입니다!\n\n");
    return -1;
}

    for(int i  = select-1; i<count; i++){
	s[i]=s[i+1];
}
    printf("삭제완료!\n\n");
    return --count;
}



