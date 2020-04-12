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
printf("\n");
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


void SaveData(product s[],int count){
    if(count==0){printf("데이터 없음!\n\n");return;}
    FILE *fp1;
    FILE *fp2;

    fp1 = fopen("product_name.txt","wt");
    fp2 = fopen("product.txt","wt");

    for(int i = 0; i<count;i++){
        fprintf(fp1,"%s\n",s[i].name);
         fprintf(fp2,"%d %d %f %f\n",s[i].weight,s[i].price,s[i].weight_per_price,s[i].reputation);
    }
    printf("저장완료!\n");
    fclose(fp1);
    fclose(fp2);

printf("\n");

}

int loadData(product s[]){
       FILE *fp1;
    FILE *fp2;

    fp1 = fopen("product_name.txt","rt");
    fp2 = fopen("product.txt","rt");
    if(fp1==NULL || fp2 == NULL) {
        printf("파일이 없습니다!\n\n");return 0;
    }
    int i = 0;
    while(feof(fp1)==0&&feof(fp2)==0){
    fgets(s[i].name,30,fp1);
     s[i].name[strlen(s[i].name)-1]='\0';
    fscanf(fp2,"%d %d %f %f\n",&s[i].weight,&s[i].price,&s[i].weight_per_price,&s[i].reputation);
    i++;
    }
	printf("Load 성공!\n\n");
    return i;
}

void SearchName(product s[],int count){
 printf("찾고자 하는 아이템의 이름을 적어주세요!\n");
        int y_n = 0;
        char name[30];
        int enter;
        enter = getchar();
        fgets(name,30,stdin);
    printf("No.      이름      중량    가격     표준가격     평점\n");
	name[strlen(name)-1] = '\0';
        for(int i = 0; i<count;i++){
            if(strstr(s[i].name,name)){ 
        printf("%d %15s%5dg%6d원   %5.0f원     %5.1f점\n",i+1,s[i].name,s[i].weight,s[i].price,s[i].weight_per_price,s[i].reputation);
            y_n++;
            }
        }
        if(y_n == 0)printf("%s의 검색결과가 없습니다!\n",name);
	printf("\n");
}


void SearchReputaion(product s[],int count){

        printf("평점을 입력해주세요!\n");
        float reputation;
       int y_n = 0;
        scanf("%f",&reputation);
    printf("No.      이름      중량    가격     표준가격     평점\n");
        for(int i = 0; i<count; i++){
            if(reputation <= s[i].reputation){
        printf("%d %15s%5dg%6d원   %5.0f원     %5.1f점\n",i+1,s[i].name,s[i].weight,s[i].price,s[i].weight_per_price,s[i].reputation);
            y_n++;
        }
        }

        if(y_n == 0)printf("%.1f보다 평점이 높은 아이템의 검색결과가 없습니다!\n",reputation);
	printf("\n");
}

void SearchPrice(product s[],int count){
  printf("가격 입력해주세요!\n");
        int price;
       int y_n = 0;
        scanf("%d",&price);
    printf("No.      이름      중량    가격     표준가격     평점\n");
        for(int i = 0; i<count; i++){
            if(price >= s[i].price){
        printf("%d %15s%5dg%6d원   %5.0f원     %5.1f점\n",i+1,s[i].name,s[i].weight,s[i].price,s[i].weight_per_price,s[i].reputation);
            y_n++;
        }

        if(y_n == 0)printf("%d보다 가격이 낮은 아이템의 검색결과가 없습니다!\n",price);
	printf("\n");
}
}

void Search(product s[],int count){
    if(count == 0) {printf("데이터가 없습니다!\n\n");return;}

while(1){

   printf("검색모드를 선택해주세요!\
    \n\n1.이름으로 찾기\
    \n2.평점으로 찾기\
    \n3.가격으로 찾기\
    \n4.메인메뉴로 가기\n");

    int select;
    scanf("%d",&select);
    if(select == 1){
      SearchName(s,count);
    }


    if(select == 2) {
             SearchReputaion(s,count);

}

 if(select == 3) {
    SearchPrice(s,count);
}

if(select == 4){
    printf("검색을 종료합니다\n\n");
    break;
}

}

}
