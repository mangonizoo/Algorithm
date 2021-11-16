#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define ALPHNUM 54

//트리 노드
typedef struct node
{
	char ALPA;  //알파벳
	int FREQENCY;//빈도수
	struct node* left; //왼쪽 자식 노드
	struct node* right; //오른쪽 자식 노드
}node;

node* make_Huffman_tree(char arr[]);  //압축하고자 하는 문자열의 허프만 코드 트리 생성
node* makenode(char ALPA, int FREQENCY, struct node* left, struct node* right); //노드 생성(new)
void make_table(node* n, char str[], int len, char* table[]); //각 알파벳(대,소문자) 별 가변길이 코드 배열 생성
void decode(char* str, node* root); //디코딩 함수
node node_arr[ALPHNUM] = { NULL };
int ind = 0;//문자 갯수

//새 노드 생성(알파벳,빈도수,왼쪽 자식 노드,오른쪽 자식 노드) 
node* makenode(char ALPA, int FREQENCY, struct node* left, struct node* right)
{
	node* new_node = (node*)malloc(sizeof(node));
	new_node->ALPA = ALPA;
	new_node->FREQENCY = FREQENCY;
	new_node->left = left;
	new_node->right = right;
	return new_node;
}

//압축하고자 하는 문자열의 허프만 코드 트리 생성
node* make_Huffman_tree(char arr[])
{
	int i = 0,j;
	int min_idx = 0,second_min_idx = 0; //첫번째, 두 번째로 빈도수가 작은 index
	int fre[ALPHNUM] = { 0, };  //알파벳(A~Z,a~z) 빈도 수
	int check[ALPHNUM] = { 0, };  //합쳐졌는지 확인(합쳐져서 살펴 볼 필요가 없으면 -1)
	node* tree[ALPHNUM] = { NULL };  //비교할 노드 배열
	node* new_node; //새 노드

	while (arr[i] != NULL)//배열전부탐색
	{
		//빈도수 구하기
		if (arr[i] < 'a') {
			fre[arr[i] - 'A']++;
		}
		else {
			fre[arr[i] - 'a'+26]++;
		}
		i++;
	}
	for (int i = 0; i < ALPHNUM; i++)
	{
		//알파벳이 존재하면
		if (fre[i] != 0)
		{
			//대문자이면
			if (i < 26) {
				node_arr[ind] = *makenode(i + 'A', fre[i], NULL, NULL);
				tree[ind++] = makenode(i + 'A', fre[i], NULL, NULL); //노드 생성
			}
			//소문자이면
			else {
				node_arr[ind] = *makenode(i + 'a'-26, fre[i], NULL, NULL);
				tree[ind++] = makenode(i + 'a'-26, fre[i], NULL, NULL); //노드 생성
			}

		}
	}
	for (i = 0; i < ind - 1; i++)
	{
		//가장 작은 수 찾기
		j = 0;
		while (check[j] == -1)	j++; //합쳐진 노드를 제외한 배열 중 가장 앞 index
		min_idx = j; //최솟값이라고 가정

		for (j = min_idx; j < ind - 1; j++) //모든 배열을 검사
			if (check[j] != -1) //합쳐진 노드가 아니면(검사해볼 필요가 있으면)
				if (tree[min_idx]->FREQENCY > tree[j]->FREQENCY)
					//min_idx인덱스 빈도수 보다 빈도수가 작은 경우
					min_idx = j;

		//두번째로 작은 수 찾기
		j = 0;
		while (check[j] == -1 || j == min_idx) j++;
		//합쳐진 노드와 최소 노드 제외한 배열 중 가장 앞 index
		second_min_idx = j;  //두번째로 작다고 가정

		for (j = second_min_idx; j < ind; j++)
			if (check[j] != -1) //이미 합쳐진 노드가 아니면
				if (tree[second_min_idx]->FREQENCY > tree[j]->FREQENCY)
					//second_min_idx인덱스 빈도수 보다 빈도수가 작은 경우
					if (j != min_idx) //가장 작은 index가 아닌 경우
						second_min_idx = j;

		tree[min_idx] = makenode(NULL, tree[min_idx]->FREQENCY + tree[second_min_idx]->FREQENCY, tree[min_idx], tree[second_min_idx]);
		//min_idx과 second_min_idx인덱스의 빈도수를 합친 빈도수로 새 노드 생성
		//새로 만든 노드를 min_idx인덱스 자리에 넣는다.

		check[second_min_idx] = -1;
		//second_min_idx인덱스는 min_idx인덱스 자리의 노드에 합쳐졌으므로 check[second_min_idx]<-=1
	}
	return tree[min_idx]; //만들어진 트리의 루트 노드 반환
}

//알파벳 별 가변길이 코드 배열 생성
//(트리 루트 노드,가변 길이 코드 문자열,문자열에 들어갈 위치, 저장 될 배열)
void make_table(node* n, char str[], int len, char* table[])
{
	if (n->left == NULL && n->right == NULL) //n이 단노드인 경우
	{
		str[len] = '\0'; //문장의 끝을 str끝에 넣어주고
						 //단 노드의 알파벳을 확인하여 table의 적절한 위치에 str문자열을 넣는다.
		//대문자일때
		if ((n->ALPA) < 'a') {
			strcpy(table[(n->ALPA) - 'A'], str);
		}
		//소문자일때
		else {
			strcpy(table[((n->ALPA) - 'a')+26], str);
		}

	}
	else //단 노드가 아닌 경우
	{
		if (n->left != NULL) //왼쪽 자식이 있는 경우
		{
			str[len] = '0'; //문자열에 0 삽입
			make_table(n->left, str, len + 1, table);
			//재귀호출(문자열에 들어갈 위치에 +1)
		}
		if (n->right != NULL) //오른쪽 자식이 있는 경우
		{
			str[len] = '1'; //문자열에 1 삽입
			make_table(n->right, str, len + 1, table);
			//재귀호출(문자열에 들어갈 위치에 +1)
		}
	}
}

//디코드함수(디코딩 하고 싶은 문자열, 트리 루트 노드)
void decode(char* str, node* root)
{
	int i = 0;
	node* j = root;
	while (str[i] != '\0') //문자의 끝이 아닌 경우
	{
		if (str[i] == '0') //문자가 0인 경우
			j = j->left; //왼쪽 자식으로 이동
		else if (str[i] == '1') //문자가 1인 경우
			j = j->right; //오른쪽 자식으로 이동
		if (j->left == NULL && j->right == NULL) //단 노드인 경우
		{
			printf("%c", j->ALPA); //단 노드의 알파벳 출력
			j = root;
		}
		i++;
	}
	printf("\n");
}

//메인 함수
int main()
{
	char arr[MAX]; //압축하고자 하는 문자열
	char* code[ALPHNUM]; //각 알파벳에 대한 가변길이 코드 배열
	char str[MAX]; //문자열 변수
	char encoding[MAX] = ""; //인코딩해서 나온 이진수 배열
	int i; //반복문 변수
	char answer; //디코딩 원하는가에 대한 대답 변수
	node* root;//트리의 루트

	for (i = 0; i < ALPHNUM; i++)
		code[i] = (char*)malloc(sizeof(char));
	printf("Put the string to encode : ");
	scanf("%s", arr); //압축하고자 하는 문자열 입력
	getchar();

	root = make_Huffman_tree(arr); //허프만코드를 이용한 트리 생성
	make_table(root, str, 0, code); //트리를 사용한 알파벳 별 가변길이 코드 생성

	i = 0;
	while (arr[i] != NULL) { //입력받은 문자열이 끝날때까지
		//대문자일때
		if (arr[i] < 'a') {
			strcat(encoding, code[arr[i] - 'A']); //문자별 코드 인코딩 문자열 뒤에 넣기
			strcat(encoding, " ");
		}
		else {//소문자일때
			strcat(encoding, code[(arr[i] - 'a')+26]); //문자별 코드 인코딩 문자열 뒤에 넣기
			strcat(encoding, " ");
		}
		i++;
	}

	for (i = 0; i < ind; i++) {
		//대문자이면
		if (node_arr[i].ALPA < 'a') {
			printf("%c : %s\n", node_arr[i].ALPA, code[node_arr[i].ALPA - 'A']);
		}
		else {//소문자이면
			printf("%c : %s\n", node_arr[i].ALPA, code[(node_arr[i].ALPA - 'a')+26]);
		}

	}


	printf("Encoded Result : %s\n", encoding); //인코딩 한 이진수 배열 출력

	printf("Decoded Result : ");
	decode(encoding, root); //디코딩 함수 호출
	return 0;
}
