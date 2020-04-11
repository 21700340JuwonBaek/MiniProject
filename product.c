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

void SaveData(product s[],int count){
    if(count==0){printf("데이터 없음!");return;}
    FILE *fp1;
    FILE *fp2;

    fp1 = fopen("product_name.txt","wt");
    fp2 = fopen("product.txt","wt");

    for(int i = 0; i<count;i++){
        fprintf(fp1,"%s\n",s[i].name);
         fprintf(fp2,"%d %d %f %f\n",s[i].weight,s[i].price,\
	s[i].weight_per_price,s[i].reputation);
    }
    printf("저장완료!\n");
    fclose(fp1);
    fclose(fp2);

}

