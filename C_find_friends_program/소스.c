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
        if (PERSON[i].primary_key == -1)      //å�� ������ -1�̸� ����ִٰ� �Ǵ��ϰ� �ش� �ε����� ��ȯ�Ѵ�.
            return i;
    }
    return -1;
}

void add_record() {

    int i = findIndex();         //�����͸� ���� ��ġ(�ε���)�� ã�´�.

    printf("�߰��� ģ�� �̸��� �Է��ϼ��� : ");
    scanf_s("%s", PERSON[i].name, 50);

    printf("\n�߰��� ģ�� �ּҸ� �Է��ϼ��� : ");
    scanf_s("%s", PERSON[i].address, 50);

    printf("\n�߰��� ģ�� ��ȣ�� �Է��ϼ��� : ");
    scanf_s("%s", PERSON[i].mobilephone, 50);

    printf("\n�߰��� ģ�� Ư¡�� �Է��ϼ��� : ");
    scanf_s("%s", PERSON[i].desc, 50);

    printf("\n�߰��� ģ�� �ֹι�ȣ ���ڸ��� �Է��ϼ��� : "); //������ �Է��ؾ���
    scanf_s("%d", &PERSON[i].primary_key);

    printf("\n ģ�� �߰��� �Ϸ�Ǿ����ϴ�. (3�ʵ� ����ȭ������ ���ϴ�)");
    Sleep(3000);
    return;
}


void search_record() {

    int b, i, have, key; // b = ã����� , have = �� ���� �÷��� , key = ã�� ģ�� �ֹι�ȣ
    char s[LANGTH_MAX];

    have = 0;
    printf("\n [1.�̸� �˻�] \n [2.�ֹι�ȣ �˻�]\n");
    printf("\n �˻������ �����ϼ���: ");

    scanf("%d", &b);

    if (b == 1)
    {
        printf("\n ã�� ģ�� �̸��� �Է��ϼ���: ");
        scanf_s("%s", s, LANGTH_MAX);
        for (i = 0; i < MAX; i++)
        {
            if (strcmp(PERSON[i].name, s) == 0)
            {
                printf("\n\n ģ�� �̸� : %s\n", PERSON[i].name);
                printf(" ģ�� �ּ� : %s\n", PERSON[i].address);
                printf(" ģ�� ��ȣ : %s\n", PERSON[i].mobilephone);
                printf(" ģ�� Ư¡ : %s\n", PERSON[i].desc);
                printf(" �ֹι�ȣ ���ڸ� : %d\n", PERSON[i].primary_key);
                have = 1;
            }
        }

        if (i == MAX && have == 0)      //�ش� ģ���� �������� ���� ���
            printf("�ش� ģ���� �������� �ʽ��ϴ�.\n");
    }

    else if (b == 2)
    {
        printf("\n ã�� ģ�� �ֹι�ȣ ���ڸ��� �Է��ϼ���: ");
        scanf_s("%d", &key);
        for (i = 0; i < MAX; i++)
        {
            if (PERSON[i].primary_key == key)
            {
                printf("\n\n ģ�� �̸� : %s\n", PERSON[i].name);
                printf(" ģ�� �ּ� : %s\n", PERSON[i].address);
                printf(" ģ�� ��ȣ : %s\n", PERSON[i].mobilephone);
                printf(" ģ�� Ư¡ : %s\n", PERSON[i].desc);
                printf(" �ֹι�ȣ ���ڸ� : %d\n", PERSON[i].primary_key);

                have = 1;
            }
        }

        if (i == MAX && have == 0)      //�ش� ģ���� �������� �������
        {
            printf("\n----->�ش� �ֹι�ȣ�� �������� �ʽ��ϴ�.\n");
        }
    }

    else
        printf("\n �߸� �Է��ϼ̽��ϴ�. �ùٸ� ��ȣ�� �Է����ּ���.\n\n");

    //���͸� ������ ����ȭ������ ������.

    while (getchar() != '\n');
    printf("\n���͸� �����ּ���");
    while (getchar() != '\n');
}



void del_record() {

    int i, have;
    char de[LANGTH_MAX];

    have = 0;
    printf("\n������ ģ�� �̸��� �Է��� �ּ��� : ");
    scanf_s("%s", de, LANGTH_MAX);

    for (i = 0; i < MAX; i++)
    {
        if (strcmp(PERSON[i].name, de) == 0) {

            strcpy(PERSON[i].name, "");
            strcpy(PERSON[i].address, "");
            strcpy(PERSON[i].mobilephone, "");
            strcpy(PERSON[i].desc, "");
            PERSON[i].primary_key = -1;

            printf("\nģ�� ������ �Ϸ�Ǿ����ϴ�. (3�ʵ� ����ȭ������ ���ϴ�)");
            Sleep(3000);
            have = 1;
            break;
        }
    }

    if (i == MAX && have == 0) {   //�ش� ������ �������� ���� ���
        printf("�ش� ģ���� �������� �ʽ��ϴ�.\n");
    }
    return;
}


void list_record() {

    int i;
    printf("%-20s%-20s%-20s%-20s%-20s\n", "�̸�", "�ּ�", "��ȣ", "Ư¡", "�ֹι�ȣ ���ڸ�");
    printf("===============================================================================================\n");

    for (i = 0; i < MAX; i++) {
        if (PERSON[i].primary_key != -1) {
            printf("%-20s%-20s%-20s%-20s%-20d\n\n", PERSON[i].name, PERSON[i].address, PERSON[i].mobilephone, PERSON[i].desc, PERSON[i].primary_key);
        }
    }
    while (getchar() != '\n');
    printf("\n\n����ȭ������ ���÷��� ���͸� �����ּ���");
    while (getchar() != '\n');
}

void init() {  //���Ͽ� �ִ� �����͸� ����ü �迭�� �ִ´�.

    int i;
    for (i = 0; i < MAX; i++)
        PERSON[i].primary_key = -1;  //����ü �迭�� �ֹ��� -1�� �����Ѵ�.

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
    char update_stirng[LANGTH_MAX]; // ������ ���ڿ�
    int update_key; //������ ����
    char name[LANGTH_MAX]; //ã�� ģ�� �̸�
    have = 0;
    printf("\n ã�� ģ�� �̸� : ");
    scanf_s("%s", name, LANGTH_MAX);
    for (i = 0; i < MAX; i++) {
        if (strcmp(PERSON[i].name, name) == 0) {
            while (1)
            {
                printf("\n������ ����� �Է��Ͻÿ� [1.�̸�] [2.�ּ�] [3.��ȣ] [4.Ư¡] [5.�ֹι�ȣ ���ڸ�] : ");
                scanf_s("%d", &update);
                if (update == 1)
                {
                    printf("\n ������ ģ�� �̸� �Է� : ");
                    scanf_s("%s", update_stirng, LANGTH_MAX);
                    strcpy_s(PERSON[i].name, LANGTH_MAX, update_stirng);
                    break;
                }
                if (update == 2)
                {
                    printf("\n ������ ģ�� �ּ� �Է� : ");
                    scanf_s("%s", update_stirng, LANGTH_MAX);
                    strcpy_s(PERSON[i].address, LANGTH_MAX, update_stirng);
                    break;
                }
                if (update == 3)
                {
                    printf("\n ������ ģ�� ��ȣ �Է� : ");
                    scanf_s("%s", update_stirng, LANGTH_MAX);
                    strcpy_s(PERSON[i].mobilephone, LANGTH_MAX, update_stirng);
                    break;
                }
                if (update == 4)
                {
                    printf("\n ������ ģ�� Ư¡ �Է� : ");
                    scanf_s("%s", update_stirng, LANGTH_MAX);
                    strcpy_s(PERSON[i].desc, LANGTH_MAX, update_stirng);
                    break;
                }
                if (update == 5)
                {
                    printf("\n ������ ģ�� �ֹι�ȣ ���ڸ� �Է�: ");
                    scanf_s("%d", &update_key);
                    PERSON[i].primary_key = update_key;
                    break;
                }
            }
        }
    }
    while (getchar() != '\n');
    printf("\n����ȭ������ ������ ���͸� �����ּ���");
    while (getchar() != '\n');
}




void menu()
{
    printf("<< ���� ���� ģ���� >>\n");
    printf("======================\n");
    printf("  1. ģ�� �߰� \n");
    printf("  2. ģ�� ���� \n");
    printf("  3. ģ�� �˻� \n");
    printf("  4. ģ�� ��� \n");
    printf("  5. ģ�� ���� \n");
    printf("  6. ���α׷� ����\n");
    printf("======================\n");
}

int main(void)
{
    int action;
    init();   //���Ͽ��� �б�

    while (1) {

        menu();

        printf("������ �׸��� ��ȣ�� �Է��Ͻÿ� : ");

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
            backup();//�������� ���Ͽ� ����
            break;
        }
        system("cls");
    }
    printf("�ۼ��� : 2017E7043 ���ֿ�");
    exit(0);
    return 0;
}
