#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "product.h"

int addproduct(product *s){
    printf("아이템의 이름을 입력해주세요\n");
    char enter;
    enter = getchar();

    fgets(s->name,30,stdin);
    s->name[strlen(s->name)-1] = '\0';
    do{
    printf("아이템의 중량을 입력해주세요\n");
    scanf("%d",&s->weight);
    if(s->weight<0)printf("다시입력해주세요!\n");
    } while(s->weight<=0);

   do{
    printf("아이템의 가격을 입력해주세요\n");
    scanf("%d",&s->price);
    if(s->price<=0)printf("다시입력해주세요!\n");
    }while(s->price<=0);

    do{
    printf("아이템의 평점을 입력해주세요(0~5까지 소수점 입력 가능!)\n");
    scanf("%f",&s->reputation);
    if(s->reputation>5||s->reputation<0)printf("다시입력해주세요!\n");
    }while(s->reputation>5||s->reputation<0);

    s->weight_per_price = (float)s->price/s->weight*10;

    printf("아이템이 추가되었습니다!\n\n");
    return 0;
    
}


void readProduct(product s[], int count){
    if(count == 0) {printf("데이터가 없습니다!\n\n");return;}

    printf("No.      이름      중량    가격     표준가격     평점\n");
    for(int i=0; i<count;i++){
        printf("%d %15s%5dg%6d원   %5.0f원     %5.1f점\n",i+1,s[i].name,s[i].weight,s[i].price,s[i].weight_per_price,s[i].reputation);
    }
    }

int updateProduct(product s[], int count){
    if(count == 0) {printf("데이터가 없습니다!\n\n");return -1;}
    readProduct(s,count);

    printf("새 아이템의 이름은?\n");
      char enter;
    enter = getchar();

   fgets(s[0].name,30,stdin);
    s->name[strlen(s->name)-1] = '\0';

    do{
    printf("아이템의 중량을 입력해주세요\n");
    scanf("%d",&s[0 ].weight);
    if(s[0 ].weight<0)printf("다시입력해주세요!\n");
    } while(s[0 ].weight<=0);

   do{
    printf("아이템의 가격을 입력해주세요\n");
    scanf("%d",&s[0 ].price);
    if(s[0 ].price<=0)printf("다시입력해주세요!\n");
    }while(s[0 ].price<=0);

    do{
    printf("아이템의 평점을 입력해주세요(0~5까지 소수점 입력 가능!)\n");
    scanf("%f",&s[0 ].reputation);
    if(s[0 ].reputation>5||s[0 ].reputation<0)printf("다시입력해주세요!\n");
    }while(s[0 ].reputation>5||s[0 ].reputation<0);

    s[0 ].weight_per_price = (float)s[0 ].price/s[0 ].weight*10;
    
    printf("수정성공!\n\n");

return 0;
}


int deleteProduct(product s[], int count){
    if(count == 0){printf("데이터없음!\n");return count;}

    printf("삭제완료!\n\n");
    return --count;
}



	
