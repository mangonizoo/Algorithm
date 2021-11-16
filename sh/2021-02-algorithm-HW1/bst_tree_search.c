#include<stdio.h>
#include <malloc.h>

//bool타입 생성
typedef int bool;
enum { false, true };

//노드 구조체 생성
typedef struct node {
	int key;
	struct node* left;//left child
	struct node* right;//right child
	struct node* p;
}NODE;

NODE* search_node(NODE*, int);
void insert_node(NODE**, int);

int main(void)
{


	FILE* pFile = fopen("test.txt", "r"); //read mode 
	int intTemp = -1;
    int search_key = 0;//찾을 key값

    //파일이 없을때
	if (pFile == NULL)
	{
		printf("File does not exist.\n");
		return 0;
	}

	NODE* root = NULL;
    NODE* exist = NULL;

	// 파일 읽기 성공
	while (true) {
      
		fscanf(pFile, "%d", &intTemp);//key값들 읽기
		if (intTemp < 0) break;
		// 트리생성
        insert_node(&root, intTemp);
	}
    //찾을 key값 입력
    scanf("%d", &search_key);
    // 생성된 트리에서 키 검색
    exist = search_node(root, search_key);
    //key값이 존재할 경우
    if (exist != NULL) {
        printf("%d는 존재함\n",search_key);
    }
    //key값이 존재하지 않을 경우
    else {
        printf("%d는 존재하지 않음\n", search_key);
    }
	fclose(pFile);          //close file

	return 0;
}

//키 값을 가진 노드를 생성해주는 함수
void insert_node(NODE** t, int key)
{
    NODE* n = (NODE*)malloc(sizeof(NODE));
    NODE* temp = *t; // 임시 노드

    n->key = key;
    n->p = NULL;
    n->left = NULL;//트리의 왼쪽
    n->right = NULL;//트리의 오른쪽

    // 노드가 없는 경우
    if (temp == NULL)
    {
        *t = n;

        return;
    }

    // 새로운 노드가 삽입될 위치 찾기
    while (temp != NULL)//트리가 공백이 아닐때
    {
        n->p = temp;

        //트리 내려가기
        if (temp->key > key)//root-key보다 삽입할 key가 작은 경우
        {
            temp = temp->left;//왼쪽으로 이동
        }
        else//root-key보다 삽입할 key가 큰 경우
        {
            temp = temp->right;//오른쪽으로 이동
        }
    }

    // 트리에 새 노드 삽입
    if ((n->p)->key > key)//root-key보다 삽입할 key가 작은 경우
    {
        (n->p)->left = n;//왼쪽에 삽입
    }
    else//root-key보다 삽입할 key가 큰 경우
    {
        (n->p)->right = n;//오른쪽에 삽입
    }

}

//key 값을 가진 노드를 탐색하여 반환해주는 함수
NODE* search_node(NODE* t, int key)
{
    //root가 null이거나 key가 root에 있는 경우 제외하고
    while (t != NULL && t->key != key)
    {
        if (t->key > key)//key보다 root-key값이 큰 경우
        {
            t = t->left;//왼쪽 서브트리로 이동
        }
        else//key 보다 root-key값이 작은 경우
        {
            t = t->right;//오른쪽 서브트리로 이동
        }
    }

    return t;//root 반환
}

