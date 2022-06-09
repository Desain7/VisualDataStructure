#define WINVER 0x0A00
#define _WIN32_WINNT 0x0A00

#include <graphics.h>              // 引用图形库头文件
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
////////////////////////////////结构体/////////////////////////////////////
typedef struct REC   // 排序部分使用顺序存储
{
	int r[4];
	int data;
	int len;
	int color;
}rec;

typedef struct RECN // 线性结构部分使用链式存储
{
	int r[3];
	int data;
	int len;
	struct RECN* next;
}recn;

///////////////////////////////函数声明///////////////////////////////////

void SetText();  // 设置窗口名

/* 界面函数 */
		/*开始界面*/
void StartInterFace();
void StartButton();
void StartGetMouse();
/* 选择界面*/
void Choose();
void ChooseGetMouse();
/* 线性结构模块*/
recn* InitList(); // 随机初始化链表

 ///////链表////////
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
void LinkedList(recn* list);  // 初始创建链表
recn* InsertNode(recn* list); // 插入节点
recn* SerachNode(recn* list, int); // 查找结点
recn* DeleteNode(recn* list, int n); // 删除节点
recn* Pop(recn* list); // 弹出栈顶元素
recn* Push(recn* list); // 压入栈顶元素
void Top(recn* list);  // 显示栈顶元素
recn* Add(recn* list);
recn* Out(recn* list);
void First(recn* list);
/* 排序 */
void Sort(rec* num);
void SortFace();
void SortGetMouse(rec* num, rec**);
rec* RandCreat(); // 随机生成一个数组
void BubbleSort(rec*); // 冒泡排序
void SelectionSort(rec*); // 选择排序
void QuickSort(rec*, int left, int right); // 快速排序
void InsertionSort(rec*); // 插入排序
void QuickSort(rec* num, int left, int right);
void QS(rec* num, int left, int right);
void MergeSort(rec* num, int len);
/*鼠标相关函数*/
void MouseClick(); // 鼠标单击特效
/*自定绘制函数*/
void RectangleButton(int, int, int, int, LPCSTR); // 矩形按钮
void Arrowhead(int x1, int y1, int x2, int y2); // 箭头
void EllipseButton(int x1, int y1, int x2, int y2, LPCSTR str); // 椭圆按钮
void SortRectangle(int x1, int y1, int x2, int y2, int n, int color); // 排序矩形
void LinkedListCircle(int x, int y, int r, int num);  // 链表圆形
/*图形变化函数*/
void ColorLine(int x1, int y1, int x2, int y2, int color); // 线变色
void BlockMove(rec*, int p1, int* R1, int n1, int p2, int* R2, int n2, int n); //块移动
/* 数据相关 */
void DataSwap(rec* num1, rec* num2);
int Min(int x, int y);
void ShowMsg(LPCSTR msg);
void DoubleBuf();

void ClearRectangle(int x1, int y1, int x2, int y2, int n);
///////////////////////////////全局变量///////////////////////////////////
/* 全局图形坐标 */
int start[3][4] = { {700,360,900,420},{700,505,900,565},{700,650,900,710} };
int position[10][3] = { {205, 450, 35}, {345, 450, 35}, // 链表坐标
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
int back[4] = { 50, 30, 100, 80 };  // 返回按钮
int game = 0, sorted = 0, ret = 0;
