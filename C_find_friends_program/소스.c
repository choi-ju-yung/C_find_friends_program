#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#pragma warning(disable:4996)
#define MAX 200 
#define LANGTH_MAX 50

struct person {

    char name[LANGTH_MAX];
    char address[LANGTH_MAX];
    char mobilephone[LANGTH_MAX];
    char desc[LANGTH_MAX];
    int primary_key;

} PERSON[MAX];

FILE* fp;

int findIndex() {

    int i;

    for (i = 0; i < MAX; i++) {
        if (PERSON[i].primary_key == -1)      //책의 가격이 -1이면 비어있다고 판단하고 해당 인덱스를 반환한다.
            return i;
    }
    return -1;
}

void add_record() {

    int i = findIndex();         //데이터를 넣을 위치(인덱스)를 찾는다.

    printf("추가할 친구 이름을 입력하세요 : ");
    scanf_s("%s", PERSON[i].name, 50);

    printf("\n추가할 친구 주소를 입력하세요 : ");
    scanf_s("%s", PERSON[i].address, 50);

    printf("\n추가할 친구 번호를 입력하세요 : ");
    scanf_s("%s", PERSON[i].mobilephone, 50);

    printf("\n추가할 친구 특징을 입력하세요 : ");
    scanf_s("%s", PERSON[i].desc, 50);

    printf("\n추가할 친구 주민번호 앞자리를 입력하세요 : "); //정수로 입력해야함
    scanf_s("%d", &PERSON[i].primary_key);

    printf("\n 친구 추가가 완료되었습니다. (3초뒤 메인화면으로 갑니다)");
    Sleep(3000);
    return;
}


void search_record() {

    int b, i, have, key; // b = 찾을방법 , have = 참 거짓 플래그 , key = 찾을 친구 주민번호
    char s[LANGTH_MAX];

    have = 0;
    printf("\n [1.이름 검색] \n [2.주민번호 검색]\n");
    printf("\n 검색방법을 선택하세요: ");

    scanf("%d", &b);

    if (b == 1)
    {
        printf("\n 찾을 친구 이름을 입력하세요: ");
        scanf_s("%s", s, LANGTH_MAX);
        for (i = 0; i < MAX; i++)
        {
            if (strcmp(PERSON[i].name, s) == 0)
            {
                printf("\n\n 친구 이름 : %s\n", PERSON[i].name);
                printf(" 친구 주소 : %s\n", PERSON[i].address);
                printf(" 친구 번호 : %s\n", PERSON[i].mobilephone);
                printf(" 친구 특징 : %s\n", PERSON[i].desc);
                printf(" 주민번호 앞자리 : %d\n", PERSON[i].primary_key);
                have = 1;
            }
        }

        if (i == MAX && have == 0)      //해당 친구가 존재하지 않을 경우
            printf("해당 친구는 존재하지 않습니다.\n");
    }

    else if (b == 2)
    {
        printf("\n 찾을 친구 주민번호 앞자리를 입력하세요: ");
        scanf_s("%d", &key);
        for (i = 0; i < MAX; i++)
        {
            if (PERSON[i].primary_key == key)
            {
                printf("\n\n 친구 이름 : %s\n", PERSON[i].name);
                printf(" 친구 주소 : %s\n", PERSON[i].address);
                printf(" 친구 번호 : %s\n", PERSON[i].mobilephone);
                printf(" 친구 특징 : %s\n", PERSON[i].desc);
                printf(" 주민번호 앞자리 : %d\n", PERSON[i].primary_key);

                have = 1;
            }
        }

        if (i == MAX && have == 0)      //해당 친구가 존재하지 않을경우
        {
            printf("\n----->해당 주민번호는 존재하지 않습니다.\n");
        }
    }

    else
        printf("\n 잘못 입력하셨습니다. 올바른 번호를 입력해주세요.\n\n");

    //엔터를 눌러야 메인화면으로 나간다.

    while (getchar() != '\n');
    printf("\n엔터를 눌러주세요");
    while (getchar() != '\n');
}



void del_record() {

    int i, have;
    char de[LANGTH_MAX];

    have = 0;
    printf("\n삭제할 친구 이름을 입력해 주세요 : ");
    scanf_s("%s", de, LANGTH_MAX);

    for (i = 0; i < MAX; i++)
    {
        if (strcmp(PERSON[i].name, de) == 0) {

            strcpy(PERSON[i].name, "");
            strcpy(PERSON[i].address, "");
            strcpy(PERSON[i].mobilephone, "");
            strcpy(PERSON[i].desc, "");
            PERSON[i].primary_key = -1;

            printf("\n친구 삭제가 완료되었습니다. (3초뒤 메인화면으로 갑니다)");
            Sleep(3000);
            have = 1;
            break;
        }
    }

    if (i == MAX && have == 0) {   //해당 도서가 존재하지 않을 경우
        printf("해당 친구는 존재하지 않습니다.\n");
    }
    return;
}


void list_record() {

    int i;
    printf("%-20s%-20s%-20s%-20s%-20s\n", "이름", "주소", "번호", "특징", "주민번호 앞자리");
    printf("===============================================================================================\n");

    for (i = 0; i < MAX; i++) {
        if (PERSON[i].primary_key != -1) {
            printf("%-20s%-20s%-20s%-20s%-20d\n\n", PERSON[i].name, PERSON[i].address, PERSON[i].mobilephone, PERSON[i].desc, PERSON[i].primary_key);
        }
    }
    while (getchar() != '\n');
    printf("\n\n메인화면으로 가시려면 엔터를 눌러주세요");
    while (getchar() != '\n');
}

void init() {  //파일에 있는 데이터를 구조체 배열에 넣는다.

    int i;
    for (i = 0; i < MAX; i++)
        PERSON[i].primary_key = -1;  //구조체 배열의 주번을 -1로 설정한다.

    fopen_s(&fp, "datatxt.txt", "a+");
    i = 0;

    while (!feof(fp)) {
        fscanf_s(fp, "%s\t", PERSON[i].name, LANGTH_MAX);
        fscanf_s(fp, "%s\t", PERSON[i].address, LANGTH_MAX);
        fscanf_s(fp, "%s\t", PERSON[i].mobilephone, LANGTH_MAX);
        fscanf_s(fp, "%s\t", PERSON[i].desc, LANGTH_MAX);
        fscanf_s(fp, "%d\n", &PERSON[i].primary_key);
        i++;
    }
    fclose(fp);
}



void backup() {

    int i;
    fopen_s(&fp, "datatxt.txt", "a+");

    for (i = 0; i < MAX; i++) {

        if (PERSON[i].primary_key != -1) {
            fprintf_s(fp, "%s\t", PERSON[i].name, LANGTH_MAX);
            fprintf_s(fp, "%s\t", PERSON[i].address, LANGTH_MAX);
            fprintf_s(fp, "%s\t", PERSON[i].mobilephone, LANGTH_MAX);
            fprintf_s(fp, "%s\t", PERSON[i].desc, LANGTH_MAX);
            fprintf_s(fp, "%d\n", PERSON[i].primary_key);
        }
    }
    fclose(fp);
}



void update_record() {
    int i, have, update;
    char update_stirng[LANGTH_MAX]; // 변경할 문자열
    int update_key; //변경할 정수
    char name[LANGTH_MAX]; //찾는 친구 이름
    have = 0;
    printf("\n 찾는 친구 이름 : ");
    scanf_s("%s", name, LANGTH_MAX);
    for (i = 0; i < MAX; i++) {
        if (strcmp(PERSON[i].name, name) == 0) {
            while (1)
            {
                printf("\n수정할 목록을 입력하시오 [1.이름] [2.주소] [3.번호] [4.특징] [5.주민번호 앞자리] : ");
                scanf_s("%d", &update);
                if (update == 1)
                {
                    printf("\n 변경할 친구 이름 입력 : ");
                    scanf_s("%s", update_stirng, LANGTH_MAX);
                    strcpy_s(PERSON[i].name, LANGTH_MAX, update_stirng);
                    break;
                }
                if (update == 2)
                {
                    printf("\n 변경할 친구 주소 입력 : ");
                    scanf_s("%s", update_stirng, LANGTH_MAX);
                    strcpy_s(PERSON[i].address, LANGTH_MAX, update_stirng);
                    break;
                }
                if (update == 3)
                {
                    printf("\n 변경할 친구 번호 입력 : ");
                    scanf_s("%s", update_stirng, LANGTH_MAX);
                    strcpy_s(PERSON[i].mobilephone, LANGTH_MAX, update_stirng);
                    break;
                }
                if (update == 4)
                {
                    printf("\n 변경할 친구 특징 입력 : ");
                    scanf_s("%s", update_stirng, LANGTH_MAX);
                    strcpy_s(PERSON[i].desc, LANGTH_MAX, update_stirng);
                    break;
                }
                if (update == 5)
                {
                    printf("\n 변경할 친구 주민번호 앞자리 입력: ");
                    scanf_s("%d", &update_key);
                    PERSON[i].primary_key = update_key;
                    break;
                }
            }
        }
    }
    while (getchar() != '\n');
    printf("\n메인화면으로 가려면 엔터를 눌러주세요");
    while (getchar() != '\n');
}




void menu()
{
    printf("<< 나의 좋은 친구들 >>\n");
    printf("======================\n");
    printf("  1. 친구 추가 \n");
    printf("  2. 친구 삭제 \n");
    printf("  3. 친구 검색 \n");
    printf("  4. 친구 목록 \n");
    printf("  5. 친구 수정 \n");
    printf("  6. 프로그램 종료\n");
    printf("======================\n");
}

int main(void)
{
    int action;
    init();   //파일에서 읽기

    while (1) {

        menu();

        printf("실행할 항목의 번호를 입력하시오 : ");

        scanf_s("%d", &action);

        system("cls");

        if (action == 1)
            add_record();

        else if (action == 2)
            del_record();

        else if (action == 3)
            search_record();

        else if (action == 4)
            list_record();

        else if (action == 5)
            update_record();

        else if (action == 6) {
            backup();//종료직전 파일에 쓰기
            break;
        }
        system("cls");
    }
    printf("작성자 : 2017E7043 최주영");
    exit(0);
    return 0;
}
