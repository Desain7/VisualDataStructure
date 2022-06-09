#define WINVER 0x0A00
#define _WIN32_WINNT 0x0A00

#include <graphics.h>              // ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <ShellScalingApi.h>
#pragma comment(lib, "Shcore.lib")
#pragma warning(push)
#pragma warning(disable:6385)
#pragma warning(disable:6386)
#pragma   warning(pop)
////////////////////////////////�ṹ��/////////////////////////////////////
typedef struct REC   // ���򲿷�ʹ��˳��洢
{
	int r[4];
	int data;
	int len;
	int color;
}rec;

typedef struct RECN // ���Խṹ����ʹ����ʽ�洢
{
	int r[3];
	int data;
	int len;
	struct RECN* next;
}recn;

///////////////////////////////��������///////////////////////////////////

void SetText();  // ���ô�����

/* ���溯�� */
		/*��ʼ����*/
void StartInterFace();
void StartButton();
void StartGetMouse();
/* ѡ�����*/
void Choose();
void ChooseGetMouse();
/* ���Խṹģ��*/
recn* InitList(); // �����ʼ������

 ///////����////////
void LL();
void Stack();
void Queue();
void StackFace();
void LLFace();
void QueueFace();
void LLGetMouse(recn* list);
void LinkedListFace();
void StackGetMouse(recn* list);
void LinkedListGetMouse(recn* list);
void QueueGetMouse(recn* list);
void LinkedList(recn* list);  // ��ʼ��������
recn* InsertNode(recn* list); // ����ڵ�
recn* SerachNode(recn* list, int); // ���ҽ��
recn* DeleteNode(recn* list, int n); // ɾ���ڵ�
recn* Pop(recn* list); // ����ջ��Ԫ��
recn* Push(recn* list); // ѹ��ջ��Ԫ��
void Top(recn* list);  // ��ʾջ��Ԫ��
recn* Add(recn* list);
recn* Out(recn* list);
void First(recn* list);
/* ���� */
void Sort(rec* num);
void SortFace();
void SortGetMouse(rec* num, rec**);
rec* RandCreat(); // �������һ������
void BubbleSort(rec*); // ð������
void SelectionSort(rec*); // ѡ������
void QuickSort(rec*, int left, int right); // ��������
void InsertionSort(rec*); // ��������
void QuickSort(rec* num, int left, int right);
void QS(rec* num, int left, int right);
void MergeSort(rec* num, int len);
/*�����غ���*/
void MouseClick(); // ��굥����Ч
/*�Զ����ƺ���*/
void RectangleButton(int, int, int, int, LPCSTR); // ���ΰ�ť
void Arrowhead(int x1, int y1, int x2, int y2); // ��ͷ
void EllipseButton(int x1, int y1, int x2, int y2, LPCSTR str); // ��Բ��ť
void SortRectangle(int x1, int y1, int x2, int y2, int n, int color); // �������
void LinkedListCircle(int x, int y, int r, int num);  // ����Բ��
/*ͼ�α仯����*/
void ColorLine(int x1, int y1, int x2, int y2, int color); // �߱�ɫ
void BlockMove(rec*, int p1, int* R1, int n1, int p2, int* R2, int n2, int n); //���ƶ�
/* ������� */
void DataSwap(rec* num1, rec* num2);
int Min(int x, int y);
void ShowMsg(LPCSTR msg);
void DoubleBuf();

void ClearRectangle(int x1, int y1, int x2, int y2, int n);
///////////////////////////////ȫ�ֱ���///////////////////////////////////
/* ȫ��ͼ������ */
int start[3][4] = { {700,360,900,420},{700,505,900,565},{700,650,900,710} };
int position[10][3] = { {205, 450, 35}, {345, 450, 35}, // ��������
						{485, 450, 35}, {625, 450, 35},
						{765, 450, 35}, {905, 450, 35},
						{1045,450, 35}, {1185,450, 35},
						{1325,450, 35}, {1465,450, 35} };
int temP[14][4] = { {315, 880, 375, 900},{380, 880, 440, 900},
					{445, 880, 505, 900},{510, 880, 570, 900},
					{575, 880, 635, 900},{640, 880, 700, 900},
					{705, 880, 765, 900},{770, 880, 830, 900},
					{835, 880, 895, 900},{900, 880, 960, 900},
					{965, 880, 1025,900},{1030,880, 1090,900},
					{1095,880, 1155,900},{1160,880, 1220,900} };
int Tposition[14][4] = { {315, 430, 375, 450},{380, 430, 440, 450},
						{445, 430, 505, 450},{510, 430, 570, 450},
						{575, 430, 635, 450},{640, 430, 700, 450},
						{705, 430, 765, 450},{770, 430, 830, 450},
						{835, 430, 895, 450},{900, 430, 960, 450},
						{965, 430, 1025,450},{1030,430, 1090,450},
						{1095,430, 1155,450},{1160,430, 1220,450} };
int arrow[9][4] = { {245, 450, 305, 450}, {385, 450, 445, 450}, {525, 450, 585, 450},
					{665, 450, 725, 450}, {805, 450, 865, 450}, {945, 450, 1005,450},
					{1085,450, 1145,450}, {1225,450, 1285,450}, {1365,450, 1425,450} };
int choose[3][4] = { {385, 210, 635, 690},
					{675, 210, 925, 690},
					{965, 210, 1215,690} };
int sortbutton[5][4] = { {10, 200, 110, 250}, {10, 320, 110, 370},
						{10, 440, 110, 490}, {10, 560, 110, 610},
						{10, 680, 110, 730} };
int ControlButton[6][4] = { {230, 10, 280, 60}, {370, 10, 420, 60}, {510, 10, 560, 60},{650, 10, 700, 60},
							{1330, 10, 1380, 60}, {1470, 10, 1520, 60} };
int back[4] = { 50, 30, 100, 80 };  // ���ذ�ť
int game = 0, sorted = 0, ret = 0;
