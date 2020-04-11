typedef struct product{
    char name[30];
    int weight;
    int price;
    float weight_per_price;
    float reputation;
}product;
/*proudct라는 구조체 변수를 선언하였고
내부에는 위에서부터 무게, 가격, 표준가격, 평점을 
저장하는 변수를 선언했습니다. 표준변수와 평점의 변수형을
float로 선언했는데, 표준가격을 정확하게 계산하고 평점을 소수점까지
입력받을 수 있게하기 위해서 그렇게 했습니다.
*/

int addproduct(product *s);
//상품을 추가할 때에 사용할 함수입니다.

void readProduct(product s[], int count);
//구조체 배열에 저장된 모든 상품을 출력할 때 사용할 함수입니다.

int updateProduct(product s[], int count);
//상품내용을 수정할 때에 사용할 함수입니다.

int deleteProduct(product s[], int count);
//구조체 배열에 저장된 상품중에서 삭제할 상품이 있을 시 사용할 함수입니다.

void SaveData(product s[],int count);
//상품의 리스트를 컴퓨터에 저장합니다.

int loadData(product s[]);
//컴퓨터에 저장된 상품의 리스트를 불러옵니다.

void Search(product s[], int count);
//사용자로부터 숫자를 입력받아 이름, 평점, 가격을 입력할 수 있는 검색모드를 불러옵니다.
//이렇게 한 이유는 메인메뉴가 너무 길어지는 것을 원하지 않기 때문입니다.

void SearchName(product s[],int count);
/*문자열을 입력받아, 그 문자열이 포함된 상품을 모두 출력해주는 함수입니다.*/

void SearchReputaion(product s[],int count);
//평점을 입력받아 입력받은 평점 이상의 상품을 모두 출력해주는 함수입니다.

void SearchPrice(product s[],int count);
//가격을 입력받아, 입력받은 가격 이하의 상품을 출력해줍니다.

void selectMenu();
//사용자에게 선택지를 보여주는 함수입니다.

void User_Select();
//사용자가 선택을 할 수 있게 하는 함수
