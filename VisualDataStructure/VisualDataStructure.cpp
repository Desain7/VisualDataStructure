///////////////////////////////////////////////////
// 程序名称：数据结构可视化
// 编译环境：Visual Studio 2019 + easyx
// 最后修改：2021年12月
//
#include "head.h"
#include "Snake.cpp"
///////////////////////////////主函数/////////////////////////////////////
int main() {
	SetProcessDpiAwareness(PROCESS_PER_MONITOR_DPI_AWARE); // 使窗口不受系统缩放设置（DPI）影响
	StartInterFace();
	return 0;
}

/////////////////////////////函数区域////////////////////////////////////
/* 界面函数 */
		/* 开始界面 */
void StartInterFace()
{
	IMAGE stbk;
	loadimage(&stbk, "../startbk1.jpg", 1600, 900);
	short win_width, win_height;
	win_width = 1600; win_height = 900;
	initgraph(win_width, win_height);
	SetText();
	putimage(0, 0, &stbk);
	Sleep(30);
	StartButton();
	while (1)
	{
		if (game == 0) {
			StartGetMouse();
		}
		else break;
	}
	game = 1;
	Choose();
	
}
void StartButton() {     //开始界面按钮
	RECT R1{ start[0][0], start[0][1], start[0][2], start[0][3] };
	RECT R2{ start[1][0], start[1][1], start[1][2], start[1][3] };
	RECT R3{ start[2][0], start[2][1], start[2][2], start[2][3] };
	setbkmode(TRANSPARENT);
	settextcolor(RGB(55, 60, 94));
	settextstyle(25, 0, "华文琥珀");
	setlinestyle(PS_SOLID | PS_ENDCAP_ROUND | PS_JOIN_ROUND, 3);
	setlinecolor(RGB(49, 55, 52));
	Sleep(100);
	RectangleButton(start[0][0], start[0][1], start[0][2], start[0][3], "开始学习");
	Sleep(100);
	RectangleButton(start[1][0], start[1][1], start[1][2], start[1][3], "程序说明");
	Sleep(100);
	RectangleButton(start[2][0], start[2][1], start[2][2], start[2][3], "退出程序");

}
void StartGetMouse() {     // 开始界面的鼠标操作
	int i, event = 0;
	ExMessage m;
	peekmessage(&m, EM_MOUSE);//获取一条鼠标消息
	switch (m.message) {
	case  WM_LBUTTONDOWN:
		setlinestyle(PS_SOLID, 1);
		setrop2(R2_NOTXORPEN);
		for (i = 0; i <= 10; i++)
		{
			setlinecolor(RGB(25 * i, 25 * 2 * i, 25 * 4 * i));//设置圆颜色
			circle(m.x, m.y, 3 * i);
			Sleep(25);
			circle(m.x, m.y, 3 * i);
			if (m.x > start[2][0] && m.x < start[2][2] && m.y > start[2][1] && m.y < start[2][3]) {
				fillrectangle(start[2][0], start[2][1], start[2][2], start[2][3]);
				Sleep(25);
				closegraph();
				printf("Bye Bye ~");
				break;
			}
			if (m.x > start[0][0] && m.x < start[0][2] && m.y > start[0][1] && m.y < start[0][3]) {
				fillrectangle(start[0][0], start[0][1], start[0][2], start[0][3]);
				Sleep(25);
				game = 1;
				break;
			}
			if (m.x > start[1][0] && m.x < start[1][2] && m.y > start[1][1] && m.y < start[1][3]) {
				fillrectangle(start[0][0], start[0][1], start[0][2], start[0][3]);
				Sleep(25);
				HWND hwnd = GetHWnd(); 
				MessageBox(hwnd, "本程序通过图形化界面，实现了五大排序及线性表的可视化，将具体过程展现出来，便于学习与理解其中的原理.", "程序说明", MB_OK);
				return;
			}
		}
		flushmessage();
		break;

	case WM_MOUSEMOVE:
		//
		break;
	}

}
		/* 选择界面*/
void Choose() {
	IMAGE bk;
	IMAGE sort;
	IMAGE list;
	IMAGE snake;
	loadimage(&bk, "../cbk.jpg", 1600, 900);
	loadimage(&sort, "../sort.jpg", 250, 480);
	loadimage(&list, "../list.jpg", 250, 480);
	loadimage(&snake, "../snake.jpg", 250, 480);
	initgraph(1600, 900);
	SetText();
	setbkcolor(WHITE);
	setlinecolor(BLACK);
	settextcolor(BLUE);
	setlinestyle(PS_SOLID, 2);
	BeginBatchDraw();
	cleardevice();
	putimage(0, 0, &bk);
	rectangle(choose[0][0], choose[0][1], choose[0][2], choose[0][3]);
	putimage(choose[0][0], choose[0][1], &sort);
	rectangle(choose[1][0], choose[1][1], choose[1][2], choose[1][3]);
	putimage(choose[1][0], choose[1][1], &list);
	rectangle(choose[2][0], choose[2][1], choose[2][2], choose[2][3]);
	putimage(choose[2][0], choose[2][1], &snake);
	FlushBatchDraw();
	EndBatchDraw();
	while (1) {
		if (game == 1)
			ChooseGetMouse();
		else break;
	}
}
void ChooseGetMouse() {     // 选择界面的鼠标操作
	int i, event = 0;
	ExMessage m;
	peekmessage(&m, EM_MOUSE);//获取一条鼠标消息
	switch (m.message) {
	case  WM_LBUTTONDOWN:
		setlinestyle(PS_SOLID, 1);
		setrop2(R2_NOTXORPEN);
		for (i = 0; i <= 10; i++)
		{
			setlinecolor(RGB(25 * i, 25 * 2 * i, 25 * 4 * i));//设置圆颜色
			circle(m.x, m.y, 3 * i);
			Sleep(25);
			circle(m.x, m.y, 3 * i);
		}
			if (m.x > choose[0][0] && m.x < choose[0][2] && m.y > choose[0][1] && m.y < choose[0][3]) {
				game = 0;
				fillrectangle(choose[0][0], choose[0][1], choose[0][2], choose[0][3]);
				Sleep(100);
				fflush(stdin);
				Sort(RandCreat());
			}
			if (m.x > choose[1][0] && m.x < choose[1][2] && m.y > choose[1][1] && m.y < choose[1][3]) {
				game = 0;
				fillrectangle(choose[0][0], choose[0][1], choose[0][2], choose[0][3]);
				Sleep(100);
				fflush(stdin);
				LL();
			}
			if (m.x > choose[2][0] && m.x < choose[2][2] && m.y > choose[2][1] && m.y < choose[2][3]) {
				game = 0;
				fillrectangle(choose[0][0], choose[0][1], choose[0][2], choose[0][3]);
				Sleep(100);
				HWND hwnd = GetHWnd();//获取窗口句柄
				MessageBox(hwnd, "贪吃蛇是一个数据结构的典型用例，我们可以通过链表来实现这个小游戏，希望在游玩过程中你能找到其中的关联，祝您玩的开心！",
				"游戏即将开始", MB_OK);
				MessageBox(hwnd, "使用小键盘的↑↓←→键控制方向，尽可能吃掉更多的食物，拿取高分！","具体操作", MB_OK);
				Snake();
				game = 1;
				Choose();
			}
		flushmessage();
		break;
	case WM_MOUSEMOVE:
		break;
		flushmessage();
	}

}
/* 线性结构模块 */

////////////////链表////////////////////
recn* InitList() {
	int n = 0, cnt, cnt1;
	recn* p, * q, * num = NULL;
	srand(time(NULL));
	while (n > 9 || n < 2) {
		n = rand() % 10;
	}
	num = (recn*)malloc(sizeof(recn));
	if (num == NULL) {
		exit(1);
	}
	num->len = n;
	p = q = num;
	num->next = NULL;
	for (cnt = 0; cnt < n; cnt++) {
		p = (recn*)malloc(sizeof(recn));
		if (p == NULL) {
			exit(1);
		}
		for (cnt1 = 0; cnt1 < 3; cnt1++) {
			p->r[cnt1] = position[cnt][cnt1];

		}
		while (p->data < 1 || p->data > 100) {
			p->data = rand() % 100;
		}
		q->next = p;
		q = p;

	}
	p->next = NULL;
	return num;

}
void LL() {
	initgraph(1600, 900);
	SetText();
	recn* list = InitList();
	setbkcolor(WHITE);
	cleardevice();
	LinkedList(list);
	LinkedListFace();
	LLFace();
	while (1) {
		LinkedListGetMouse(list);
		if (game == 1) {
			return;
		}
	}
}
void Stack() {
	initgraph(1600, 900);
	SetText();
	recn* list = InitList();
	setbkcolor(WHITE);
	cleardevice();
	LinkedList(list);
	StackFace();
	LLFace();
	while (1) {
		StackGetMouse(list);
		if (game == 1) {
			return;
		}
	}
}
void Queue() {
	initgraph(1600, 900);
	SetText();
	recn* list = InitList();
	setbkcolor(WHITE);
	cleardevice();
	LinkedList(list);
	QueueFace();
	LLFace();
	while (1) {
		QueueGetMouse(list);
		if (game == 1) {
			return;
		}
	}
}
void StackFace() {
	IMAGE btbk;
	IMAGE btbk1;
	setlinecolor(BLACK);
	setfillcolor(RGB(173, 216, 230));
	setbkmode(TRANSPARENT);
	settextcolor(RGB(55, 60, 94));
	settextstyle(20, 0, "微软雅黑");
	setlinestyle(PS_SOLID | PS_ENDCAP_ROUND | PS_JOIN_ROUND, 3);
	setlinecolor(RGB(49, 55, 52));
	loadimage(&btbk, "../btbk.png", 100, 50);
	loadimage(&btbk1, "../btbk.png", 50, 50);
	BeginBatchDraw();
	putimage(ControlButton[0][0], ControlButton[0][1], &btbk1);
	putimage(ControlButton[1][0], ControlButton[1][1], &btbk1);
	putimage(ControlButton[2][0], ControlButton[2][1], &btbk1);
	RectangleButton(ControlButton[0][0], ControlButton[0][1], ControlButton[0][2], ControlButton[0][3], "压入");
	RectangleButton(ControlButton[1][0], ControlButton[1][1], ControlButton[1][2], ControlButton[1][3], "弹出");
	RectangleButton(ControlButton[2][0], ControlButton[2][1], ControlButton[2][2], ControlButton[2][3], "栈顶");
	FlushBatchDraw();
	EndBatchDraw();
}
void LLFace() {
	IMAGE btbk;
	IMAGE back;
	IMAGE btbk1;
	loadimage(&back, "../back.png", 100, 50);
	loadimage(&btbk, "../btbk.png", 100, 50);
	loadimage(&btbk1, "../btbk.png", 50, 50);
	setlinecolor(BLACK);
	setfillcolor(RGB(173, 216, 230));
	setbkmode(TRANSPARENT);
	settextcolor(RGB(55, 60, 94));
	settextstyle(20, 0, "微软雅黑");
	setlinestyle(PS_SOLID | PS_ENDCAP_ROUND | PS_JOIN_ROUND, 3);
	setlinecolor(RGB(49, 55, 52));
	putimage(10, 20, &back);
	putimage(10, 680, &btbk);
	putimage(10, 440, &btbk);
	putimage(10, 560, &btbk);
	RectangleButton(sortbutton[2][0], sortbutton[2][1], sortbutton[2][2], sortbutton[2][3], "链表");
	RectangleButton(sortbutton[3][0], sortbutton[3][1], sortbutton[3][2], sortbutton[3][3], "栈");
	RectangleButton(sortbutton[4][0], sortbutton[4][1], sortbutton[4][2], sortbutton[4][3], "队列");
}
void LinkedListFace() {
	IMAGE btbk;
	IMAGE btbk1;
	setlinecolor(BLACK);
	setfillcolor(RGB(173, 216, 230));
	setbkmode(TRANSPARENT);
	settextcolor(RGB(55, 60, 94));
	settextstyle(20, 0, "微软雅黑");
	setlinestyle(PS_SOLID | PS_ENDCAP_ROUND | PS_JOIN_ROUND, 3);
	setlinecolor(RGB(49, 55, 52));
	loadimage(&btbk, "../btbk.png", 100, 50);
	loadimage(&btbk1, "../btbk.png", 50, 50);
	putimage(ControlButton[0][0], ControlButton[0][1], &btbk1);
	putimage(ControlButton[1][0], ControlButton[1][1], &btbk1);
	putimage(ControlButton[2][0], ControlButton[2][1], &btbk1);
	RectangleButton(ControlButton[0][0], ControlButton[0][1], ControlButton[0][2], ControlButton[0][3], "插入");
	RectangleButton(ControlButton[1][0], ControlButton[1][1], ControlButton[1][2], ControlButton[1][3], "查找");
	RectangleButton(ControlButton[2][0], ControlButton[2][1], ControlButton[2][2], ControlButton[2][3], "删除");
}
void QueueFace() {
	IMAGE btbk;
	IMAGE btbk1;
	setlinecolor(BLACK);
	setfillcolor(RGB(173, 216, 230));
	setbkmode(TRANSPARENT);
	settextcolor(RGB(55, 60, 94));
	settextstyle(20, 0, "微软雅黑");
	setlinestyle(PS_SOLID | PS_ENDCAP_ROUND | PS_JOIN_ROUND, 3);
	setlinecolor(RGB(49, 55, 52));
	loadimage(&btbk, "../btbk.png", 100, 50);
	loadimage(&btbk1, "../btbk.png", 50, 50);
	BeginBatchDraw();
	putimage(ControlButton[0][0], ControlButton[0][1], &btbk1);
	putimage(ControlButton[1][0], ControlButton[1][1], &btbk1);
	putimage(ControlButton[2][0], ControlButton[2][1], &btbk1);
	RectangleButton(ControlButton[0][0], ControlButton[0][1], ControlButton[0][2], ControlButton[0][3], "入列");
	RectangleButton(ControlButton[1][0], ControlButton[1][1], ControlButton[1][2], ControlButton[1][3], "出列");
	RectangleButton(ControlButton[2][0], ControlButton[2][1], ControlButton[2][2], ControlButton[2][3], "列首");
	FlushBatchDraw();
	EndBatchDraw();
}
void StackGetMouse(recn* list) {
	int flag = 0;
	recn *p, * q;
	p = q = list;
	if (p == NULL) {
		exit(1);
	}
	while (p->next != NULL) {
		q = p;
		p = p->next;
	}
	DoubleBuf();
	setfillcolor(RGB(173, 216, 230));
	ExMessage m;
	peekmessage(&m, EM_MOUSE);//获取一条鼠标消息
	switch (m.message) {
	case  WM_LBUTTONDOWN:
		setlinestyle(PS_SOLID, 1);
		setrop2(R2_NOTXORPEN);
		if (m.x > ControlButton[0][0] && m.x <  ControlButton[0][2] && m.y > ControlButton[0][1] && m.y < ControlButton[0][3] && list->len < 10) {
			fillrectangle(ControlButton[0][0], ControlButton[0][1], ControlButton[0][2], ControlButton[0][3]);
			if (list->len == 0) {
				ShowMsg("当前栈为空!");
				Sleep(1000);
				clearrectangle(1400, 800, 1600, 900);
			}
			else {
				Push(list);
				Sleep(100);
				StackFace();
			}
		}
		if (m.x > ControlButton[1][0] && m.x <  ControlButton[1][2] && m.y > ControlButton[1][1] && m.y < ControlButton[1][3]) {
			fillrectangle(ControlButton[1][0], ControlButton[1][1], ControlButton[1][2], ControlButton[1][3]);
			if (list->len == 0) {
				ShowMsg("当前栈为空!");
				Sleep(1000);
				clearrectangle(1400, 800, 1600, 900);
			}
			else {
				Pop(list);
				Sleep(100);
				StackFace();
			}
		}
		if (m.x > ControlButton[2][0] && m.x <  ControlButton[2][2] && m.y > ControlButton[2][1] && m.y < ControlButton[2][3]) {
			fillrectangle(ControlButton[2][0], ControlButton[2][1], ControlButton[2][2], ControlButton[2][3]);
			if (list->len == 0) {
				ShowMsg("当前栈为空!");
				Sleep(1000);
				clearrectangle(1400, 800, 1600, 900);
			}
			else {
				Top(list);
				Sleep(100);
				StackFace();
			}
		}
		if (m.x > sortbutton[2][0] && m.x <  sortbutton[2][2] && m.y > sortbutton[2][1] && m.y < sortbutton[2][3]) {
			if (flag != 1) {
				closegraph();
				LL();
			}
			flag = 1;
		}
		if (m.x > sortbutton[3][0] && m.x < sortbutton[3][2] && m.y > sortbutton[3][1] && m.y < sortbutton[3][3]) {
			if (flag != 2) {
				closegraph();
				Stack();
			}
			flag = 2;
		}
		if (m.x > sortbutton[4][0] && m.x <  sortbutton[4][2] && m.y > sortbutton[4][1] && m.y < sortbutton[4][3]) {
			if (flag != 3) {
				closegraph();
				Queue();
			}
			flag = 3;
		}
		if (m.x > 10 && m.x < 110 && m.y >20 && m.y < 70) {
			fillrectangle(10, 20, 110, 70);
			Sleep(100);
			recn* p, * q;
			p = q = list;
			if (p == NULL) {
				exit(1);
			}
			while (p != NULL) {
				q = p;
				p = p->next;
				free(q);
			}
			fflush(stdin);
			game = 1;
			Choose();
		}

		flushmessage();
		break;
	case WM_MOUSEMOVE:
		break;
		flushmessage();
	}
}
void LinkedListGetMouse(recn* list) {
	int flag = 0;
	char num[10];
	ExMessage m;
	peekmessage(&m, EM_MOUSE);//获取一条鼠标消息
	switch (m.message) {
	case  WM_LBUTTONDOWN:
		setlinestyle(PS_SOLID, 1);
		setrop2(R2_NOTXORPEN);
		if (m.x > ControlButton[0][0] && m.x <  ControlButton[0][2] && m.y > ControlButton[0][1] && m.y < ControlButton[0][3] && list->len < 10) {
			fillrectangle(ControlButton[0][0], ControlButton[0][1], ControlButton[0][2], ControlButton[0][3]);
			if (list->len == 0) {
				ShowMsg("当前链表为空!");
				Sleep(1000);
				clearrectangle(1400, 800, 1600, 900);
			}
			else {
				InsertNode(list);
				BeginBatchDraw();
				LinkedList(list);
				LinkedListFace();
				LLFace();
				FlushBatchDraw();
				EndBatchDraw();
			}
		}
		if (m.x > ControlButton[1][0] && m.x <  ControlButton[1][2] && m.y > ControlButton[1][1] && m.y < ControlButton[1][3]) {
			fillrectangle(ControlButton[1][0], ControlButton[1][1], ControlButton[1][2], ControlButton[1][3]);
			if (list->len == 0) {
				ShowMsg("当前链表为空!");
				Sleep(1000);
				clearrectangle(1400, 800, 1600, 900);
			}
			else {
				InputBox(num, 10, "请输入查找的数字");
				int n = atoi(num);
				SerachNode(list, n);
			}
		}
		if (m.x > ControlButton[2][0] && m.x <  ControlButton[2][2] && m.y > ControlButton[2][1] && m.y < ControlButton[2][3]) {
			fillrectangle(ControlButton[2][0], ControlButton[2][1], ControlButton[2][2], ControlButton[2][3]);
			if (list->len == 0) {
				ShowMsg("当前链表为空!");
				Sleep(1000);
				clearrectangle(1400, 800, 1600, 900);
			}
			else {
				InputBox(num, 10, "请输入删除的数字");
				int n = atoi(num);
				DeleteNode(list, n);
			}
		}
		if (m.x > sortbutton[2][0] && m.x <  sortbutton[2][2] && m.y > sortbutton[2][1] && m.y < sortbutton[2][3]) {
			if (flag != 1) {
				closegraph();
				LL();
			}
			flag = 1;
		}
		if (m.x > sortbutton[3][0] && m.x < sortbutton[3][2] && m.y > sortbutton[3][1] && m.y < sortbutton[3][3]) {
			if (flag != 2) {
				closegraph();
				Stack();
			}
			flag = 2;
		}
		if (m.x > sortbutton[4][0] && m.x <  sortbutton[4][2] && m.y > sortbutton[4][1] && m.y < sortbutton[4][3]) {
			if (flag != 3) {
				closegraph();
				Queue();
			}
			flag = 3;
		}
		if (m.x > 10 && m.x < 110 && m.y >20 && m.y < 70) {
			fillrectangle(10, 20, 110, 70);
			Sleep(100);
			recn* p, * q;
			p = q = list;
			if (p == NULL) {
				exit(1);
			}
			while (p != NULL) {
				q = p;
				p = p->next;
				free(q);
			}
			fflush(stdin);
			game = 1;
			Choose();
		}

		flushmessage();
		break;
	case WM_MOUSEMOVE:
		break;
		flushmessage();
	}
}
void QueueGetMouse(recn* list) {
	int flag = 0;
	recn* p, * q;
	p = q = list;
	if (p == NULL) {
		exit(1);
	}
	while (p->next != NULL) {
		q = p;
		p = p->next;
	}
	DoubleBuf();
	setfillcolor(RGB(173, 216, 230));
	ExMessage m;
	peekmessage(&m, EM_MOUSE);//获取一条鼠标消息
	switch (m.message) {
	case  WM_LBUTTONDOWN:
		setlinestyle(PS_SOLID, 1);
		setrop2(R2_NOTXORPEN);
		if (m.x > ControlButton[0][0] && m.x <  ControlButton[0][2] && m.y > ControlButton[0][1] && m.y < ControlButton[0][3] && list->len < 10) {
			fillrectangle(ControlButton[0][0], ControlButton[0][1], ControlButton[0][2], ControlButton[0][3]);
			Add(list);
			Sleep(100);
			QueueFace();
		}
		if (m.x > ControlButton[1][0] && m.x <  ControlButton[1][2] && m.y > ControlButton[1][1] && m.y < ControlButton[1][3]) {
			fillrectangle(ControlButton[1][0], ControlButton[1][1], ControlButton[1][2], ControlButton[1][3]);
			Out(list);
			Sleep(100);
			QueueFace();
		}
		if (m.x > ControlButton[2][0] && m.x <  ControlButton[2][2] && m.y > ControlButton[2][1] && m.y < ControlButton[2][3]) {
			fillrectangle(ControlButton[2][0], ControlButton[2][1], ControlButton[2][2], ControlButton[2][3]);
			First(list);
			Sleep(100);
			QueueFace();

		}
		if (m.x > sortbutton[2][0] && m.x <  sortbutton[2][2] && m.y > sortbutton[2][1] && m.y < sortbutton[2][3]) {
			if (flag != 1) {
				closegraph();
				LL();
			}
			flag = 1;
		}
		if (m.x > sortbutton[3][0] && m.x < sortbutton[3][2] && m.y > sortbutton[3][1] && m.y < sortbutton[3][3]) {
			if (flag != 2) {
				closegraph();
				Stack();
			}
			flag = 2;
		}
		if (m.x > sortbutton[4][0] && m.x <  sortbutton[4][2] && m.y > sortbutton[4][1] && m.y < sortbutton[4][3]) {
			if (flag != 3) {
				closegraph();
				Queue();
			}
			flag = 3;
		}
		if (m.x > 10 && m.x < 110 && m.y >20 && m.y < 70) {
			fillrectangle(10, 20, 110, 70);
			Sleep(100);
			recn* p, * q;
			p = q = list;
			if (p == NULL) {
				exit(1);
			}
			while (p != NULL) {
				q = p;
				p = p->next;
				free(q);
			}
			fflush(stdin);
			game = 1;
			Choose();
		}

		flushmessage();
		break;
	case WM_MOUSEMOVE:
		break;
		flushmessage();
	}
}
void LLGetMouse(recn* list) {
	int flag = 0;
	ExMessage m;
	peekmessage(&m, EM_MOUSE);//获取一条鼠标消息
	switch (m.message) {
	case  WM_LBUTTONDOWN:
		setlinestyle(PS_SOLID, 1);
		setrop2(R2_NOTXORPEN);
		if (m.x > sortbutton[2][0] && m.x <  sortbutton[2][2] && m.y > sortbutton[2][1] && m.y < sortbutton[2][3]) {
			flag = 1;
			if (flag != 1) {
				closegraph();
				LL();
			}
		}
		if (m.x > sortbutton[3][0] && m.x < sortbutton[3][2] && m.y > sortbutton[3][1] && m.y < sortbutton[3][3]) {
			flag = 2;
			if (flag != 2) {
				closegraph();
				Stack();
			}
		}
		if (m.x > sortbutton[4][0] && m.x <  sortbutton[4][2] && m.y > sortbutton[4][1] && m.y < sortbutton[4][3]) {
			flag = 3;
			if (flag != 3) {
				closegraph();
				Queue();
			}
		}

		flushmessage();
		break;
	case WM_MOUSEMOVE:
		break;
		flushmessage();
	}
}
void LinkedList(recn* list) {
	int cnt = -1;
	setbkcolor(WHITE);
	settextcolor(BLACK);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 1);
	settextstyle(30, 10, "微软雅黑");
	BeginBatchDraw();
	clearrectangle(150, 400, 1800, 500);
	recn* p, * q;
	p = q = list->next;
	while (p != NULL) {
		LinkedListCircle(p->r[0], p->r[1], p->r[2], p->data);
		p = p->next;
		if (cnt >= 0)
			Arrowhead(arrow[cnt][0], arrow[cnt][1], arrow[cnt][2], arrow[cnt][3]);
		cnt++;
	}
	FlushBatchDraw();
	EndBatchDraw();
	cnt--;

}
recn *InsertNode(recn* list) {
	int flag = 50;
	setbkcolor(WHITE);
	settextcolor(BLACK);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 1);
	settextstyle(30, 10, "微软雅黑");
	recn* p, * q, * node;
	int n = 0, cnt;
	srand(time(NULL));
	while (n < 1 || n > 100) {
		n = rand() % 100;
	}
	p = q = list;
	while (p != NULL) {
		q = p;
		p = p->next;
	}
	if (p == NULL && list->len != 0) {
		if (list == NULL) {
			exit(1);
		}
		while (flag >= 0) {
			BeginBatchDraw();
			clearcircle(position[list->len][0] - flag, position[list->len][1] - flag, position[list->len][2] + 10);
			LinkedListCircle(position[list->len][0] - flag, position[list->len][1] - flag, position[list->len][2], n);
			ShowMsg("插入元素");
			FlushBatchDraw();
			EndBatchDraw();
			Sleep(15);
			flag -= 5;
		}
		Sleep(100);
		ColorLine(arrow[list->len - 1][0], arrow[list->len - 1][1], arrow[list->len - 1][2], arrow[list->len - 1][3], BLUE);
		node = (recn*)malloc(sizeof(recn));
		if (node == NULL) {
			exit(1);
		}
		node->data = n;
		for (cnt = 0; cnt < 3; cnt++) {
			node->r[cnt] = position[list->len][cnt];
		}
		q->next = node;
		node->next = NULL;
		list->len++;
	}
	Sleep(100);
	LinkedList(list);
	clearrectangle(1400, 800, 1600, 900);
	return list;
	}
recn* SerachNode(recn* list, int n) {
	int cnt = -1;
	setbkcolor(WHITE);
	settextcolor(BLACK);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 1);
	settextstyle(30, 10, "微软雅黑");
	recn* p, * q;
	p = q = list;
	if (p == NULL) {
		exit(1);
	}
	ShowMsg("正在遍历查找元素");
	while (p != NULL && p->data != n) {
		q = p;
		p = p->next;
		if (cnt >= 0 && cnt < 9)
			ColorLine(arrow[cnt][0], arrow[cnt][1], arrow[cnt][2], arrow[cnt][3], BLUE);
		Sleep(200);
		cnt++;
	}
	Sleep(100);
	clearrectangle(1400, 800, 1600, 900);
	if (p == NULL) {
		BeginBatchDraw();
		LinkedList(list);
		LinkedListFace();
		LLFace();
		FlushBatchDraw();
		EndBatchDraw();
		return list;
	}
	setfillcolor(BLUE);
	for (int i = 0; i < 10; i++) {
		ShowMsg("高亮显示该元素");
		fillcircle(p->r[0], p->r[1], p->r[2]);
		Sleep(200);
	}
	clearrectangle(1400, 800, 1600, 900);
	BeginBatchDraw();
	LinkedList(list);
	LinkedListFace();
	LLFace();
	FlushBatchDraw();
	EndBatchDraw();
	clearrectangle(1400, 800, 1600, 900);
	return list;
}
recn* DeleteNode(recn* list, int n) {
	int cnt = -1, flag;
	setbkcolor(WHITE);
	settextcolor(BLACK);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 1);
	settextstyle(30, 10, "微软雅黑");
	recn* p, * q;
	p = q = list;
	if (p == NULL) {
		exit(1);
	}
	while (p != NULL && p->data != n) {
		ShowMsg("查找删除元素");
		q = p;
		p = p->next;
		if (cnt >= 0)
			ColorLine(arrow[cnt][0], arrow[cnt][1], arrow[cnt][2], arrow[cnt][3], BLUE);
		Sleep(200);
		cnt++;
	}
	clearrectangle(1400, 800, 1600, 900);
	if (p == NULL) {
		BeginBatchDraw();
		LinkedList(list);
		LinkedListFace();
		LLFace();
		FlushBatchDraw();
		EndBatchDraw();
		return list;
	}
	if (p->data == n) {
		ShowMsg("删除元素");
		flag = p->r[0];
		setfillcolor(YELLOW);
		fillcircle(p->r[0], p->r[1], p->r[2]);
		Sleep(1000);
		q->next = p->next;
		free(p);
		p = NULL;
	}
		p = q->next;
		while (p != NULL) {
			p->r[0] -= 140;
			p = p->next;
			if (cnt >= 0)
			cnt++;
		}
		list->len--;
		clearrectangle(1400, 800, 1600, 900);
	BeginBatchDraw();
	LinkedList(list);
	LinkedListFace();
	LLFace();
	FlushBatchDraw();
	EndBatchDraw();
	return list;
}
recn* Push(recn *list) {
	int flag = 50;
	setbkcolor(WHITE);
	settextcolor(BLACK);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 1);
	settextstyle(30, 10, "微软雅黑");
	recn* p, * q, * node;
	int n = 0, cnt;
	srand(time(NULL));
	while (n < 1 || n > 100) {
		n = rand() % 100;
	}
	p = q = list;
	while (p != NULL) {
		q = p;
		p = p->next;
	}
	if (p == NULL && list->len != 0) {
		if (list == NULL) {
			exit(1);
		}
		while (flag >= 0) {
			BeginBatchDraw();
			clearcircle(position[list->len][0] - flag, position[list->len][1] - flag, position[list->len][2] + 10);
			LinkedListCircle(position[list->len][0] - flag, position[list->len][1] - flag, position[list->len][2], n);
			ShowMsg("元素压栈...");
			FlushBatchDraw();
			EndBatchDraw();
			Sleep(15);
			flag -= 5;
		}
		Sleep(100);
		ColorLine(arrow[list->len - 1][0], arrow[list->len - 1][1], arrow[list->len - 1][2], arrow[list->len - 1][3], BLUE);
		node = (recn*)malloc(sizeof(recn));
		if (node == NULL) {
			exit(1);
		}
		node->data = n;
		for (cnt = 0; cnt < 3; cnt++) {
			node->r[cnt] = position[list->len][cnt];
		}
		q->next = node;
		node->next = NULL;
		list->len++;
	}
	Sleep(100);
	clearrectangle(1400, 800, 1600, 900);
	LinkedList(list);
	return list;
}
recn* Pop(recn* list) {
	recn* p, * q;
	p = q = list;
	DoubleBuf();
	int cnt = -1, flag = 0;
	setbkcolor(WHITE);
	settextcolor(BLACK);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 1);
	settextstyle(30, 10, "微软雅黑");
	fillcircle(list->r[0], list->r[1], list->r[2]);
	Sleep(100);
	fillcircle(list->r[0], list->r[1], list->r[2]);
	while (p->next != NULL) {
		q = p;
		p = p->next;
	}
	if (list == NULL) {
		exit(1);
	}
	while (flag <= 100) {
		BeginBatchDraw();
		clearcircle(position[list->len - 1][0] - flag, position[list->len - 1][1] - flag, position[list->len - 1][2] + 10);
		LinkedListCircle(position[list->len - 1][0] - flag, position[list->len - 1][1] - flag, position[list->len - 1][2], p->data);
		ShowMsg("元素弹出栈...");
		FlushBatchDraw();
		EndBatchDraw();
		Sleep(15);
		flag += 5;
	}
	clearcircle(position[list->len - 1][0] - flag, position[list->len - 1][1] - flag, position[list->len - 1][2] + 10);
	free(p);
	q->next = NULL;
	Sleep(200);
	clearrectangle(1400, 800, 1600, 900);
	LinkedList(list);
	list->len--;
	return list;
}
void Top(recn* list) {
	setfillcolor(YELLOW);
	recn* p, * q;
	p = q = list;
	while (p->next != NULL) {
		q = p;
		p = p->next;
	}
	if (list == NULL) {
		exit(1);
	}
	ShowMsg("已高亮显示栈顶元素");
	for (int i = 0; i < 10; i++) {
		fillcircle(p->r[0], p->r[1], p->r[2]);
		Sleep(300);
	}
	clearrectangle(1400, 800, 1600, 900);
}
recn* Add(recn* list) {
	int flag = 50;
	setbkcolor(WHITE);
	settextcolor(BLACK);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 1);
	settextstyle(30, 10, "微软雅黑");
	recn* p, * q, * node;
	int n = 0, cnt;
	srand(time(NULL));
	while (n < 1 || n > 100) {
		n = rand() % 100;
	}
	p = q = list;
	while (p != NULL) {
		q = p;
		p = p->next;
	}
	if (p == NULL && list->len != 0) {
		if (list == NULL) {
			exit(1);
		}
		while (flag >= 0) {
			BeginBatchDraw();
			clearcircle(position[list->len][0] - flag, position[list->len][1] - flag, position[list->len][2] + 10);
			LinkedListCircle(position[list->len][0] - flag, position[list->len][1] - flag, position[list->len][2], n);
			FlushBatchDraw();
			EndBatchDraw();
			Sleep(15);
			flag -= 5;
			ShowMsg("元素插入列尾...");
		}
		Sleep(100);
		ColorLine(arrow[list->len - 1][0], arrow[list->len - 1][1], arrow[list->len - 1][2], arrow[list->len - 1][3], BLUE);

		node = (recn*)malloc(sizeof(recn));
		if (node == NULL) {
			exit(1);
		}
		node->data = n;
		for (cnt = 0; cnt < 3; cnt++) {
			node->r[cnt] = position[list->len][cnt];
		}
		q->next = node;
		node->next = NULL;
		list->len++;
	}
	Sleep(100);
	LinkedList(list);
	clearrectangle(1400, 800, 1600, 900);
	return list;
}
recn* Out(recn* list) {
	int cnt = 0;
	setbkcolor(WHITE);
	settextcolor(BLACK);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 1);
	settextstyle(30, 10, "微软雅黑");
	int flag = 0;
	recn* p, *q;
	p = list->next;
	while (flag <= 100) {
		BeginBatchDraw();
		clearcircle(position[0][0] - flag, position[0][1] - flag, position[0][2] + 10);
		LinkedListCircle(position[0][0] - flag,position[0][1] - flag, position[0][2], p->data);
		ShowMsg("元素从队首出列...");
		FlushBatchDraw();
		EndBatchDraw();
		Sleep(15);
		flag += 5;
	}
	clearrectangle(1400, 800, 1600, 900);
	clearcircle(position[0][0] - flag, position[0][1] - flag, position[0][2] + 10);
	list->next = p->next;
	free(p);
	list->len--;
	flag = 0;
	while (flag <= 140) {
		BeginBatchDraw();
		clearrectangle(150, 400, 1800, 500);
		p = q = list->next;
		while (p != NULL) {
			LinkedListCircle(p->r[0] - flag, p->r[1], p->r[2], p->data);
			p = p->next;
			flag += 1;
			Sleep(5);
			ShowMsg("后面的元素前进...");
		}
		FlushBatchDraw();
		EndBatchDraw();
	}
		p = list->next;
		if (p == NULL) {
			exit(1);
		}
		while (p != NULL) {
			for (int cnt1 = 0; cnt1 < 3; cnt1++) {
				p->r[cnt1] = position[cnt][cnt1];
			}
			cnt++;
			p = p->next;
		}
		LinkedList(list);
		clearrectangle(1400, 800, 1600, 900);
	return list;
}
void First(recn* list) {
	recn* p;
	p = list->next;
	setfillcolor(YELLOW);
	ShowMsg("已高亮显示队列首元素");
	for (int i = 0; i < 10; i++) {
		fillcircle(p->r[0], p->r[1], p->r[2]);
		Sleep(300);
	}
	clearrectangle(1400, 800, 1600, 900);
}
/* 排序 */
void Sort(rec* num) {
	DoubleBuf();
	IMAGE back;
	IMAGE btbk;
	int cnt;
	setfillcolor(RGB(173, 216, 230));
	initgraph(1600, 900);
	SetText();
	loadimage(&back, "../back.png", 100, 50);
	loadimage(&btbk, "../btbk.png", 100, 50);
	setbkcolor(WHITE);
	BeginBatchDraw();
	cleardevice();
	setlinecolor(BLACK);
	setfillcolor(RGB(173, 216, 230));
	setbkmode(TRANSPARENT);
	settextcolor(RGB(55, 60, 94));
	settextstyle(20, 0, "微软雅黑");
	setlinestyle(PS_SOLID | PS_ENDCAP_ROUND | PS_JOIN_ROUND, 3);
	setlinecolor(RGB(49, 55, 52));
	for (cnt = 0; cnt < num[0].len; cnt++) {
		SortRectangle(num[cnt].r[0], num[cnt].r[1], num[cnt].r[2], num[cnt].r[3], num[cnt].data, num[cnt].color);
	}
	SortFace();
	FlushBatchDraw();
	EndBatchDraw();
	while (1) {
		SortGetMouse(num, &num);
		if (game == 1) {
			fflush(stdin);
			return;
		}	
	}
}
void SortFace() {
	DoubleBuf();
	IMAGE back;
	IMAGE btbk;
	IMAGE btbk1;
	loadimage(&back, "../back.png", 100, 50);
	loadimage(&btbk, "../btbk.png", 100, 50);
	loadimage(&btbk1, "../btbk.png", 50, 50);
	setbkcolor(WHITE);
	setlinecolor(BLACK);
	setfillcolor(RGB(173, 216, 230));
	setbkmode(TRANSPARENT);
	settextcolor(RGB(55, 60, 94));
	settextstyle(20, 0, "微软雅黑");
	setlinestyle(PS_SOLID | PS_ENDCAP_ROUND | PS_JOIN_ROUND, 3);
	setlinecolor(RGB(49, 55, 52));
	putimage(10, 20, &back);
	putimage(10, 200, &btbk);
	putimage(10, 320, &btbk);
	putimage(10, 440, &btbk);
	putimage(10, 560, &btbk);
	putimage(10, 680, &btbk);
	putimage(1470, 10, &btbk1);
	RectangleButton(sortbutton[0][0], sortbutton[0][1], sortbutton[0][2], sortbutton[0][3], "冒泡排序");
	RectangleButton(sortbutton[1][0], sortbutton[1][1], sortbutton[1][2], sortbutton[1][3], "选择排序");
	RectangleButton(sortbutton[2][0], sortbutton[2][1], sortbutton[2][2], sortbutton[2][3], "插入排序");
	RectangleButton(sortbutton[3][0], sortbutton[3][1], sortbutton[3][2], sortbutton[3][3], "快速排序");
	RectangleButton(sortbutton[4][0], sortbutton[4][1], sortbutton[4][2], sortbutton[4][3], "归并排序");
	RectangleButton(ControlButton[5][0], ControlButton[5][1], ControlButton[5][2], ControlButton[5][3], "随机");
}
void SortGetMouse(rec * num, rec **pnum) {
	int cnt;
	ExMessage m;
	peekmessage(&m, EM_MOUSE);//获取一条鼠标消息
	switch (m.message) {
	case  WM_LBUTTONDOWN:
		setlinestyle(PS_SOLID, 1);
		setrop2(R2_NOTXORPEN);
		setfillcolor(RGB(173, 216, 230));
		if (m.x > sortbutton[0][0] && m.x < sortbutton[0][2] && m.y > sortbutton[0][1] && m.y < sortbutton[0][3]) {
			fillrectangle(sortbutton[0][0], sortbutton[0][1], sortbutton[0][2], sortbutton[0][3]);
			BubbleSort(num);
		}
		if (m.x > sortbutton[1][0] && m.x < sortbutton[1][2] && m.y >sortbutton[1][1] && m.y < sortbutton[1][3]) {
			fillrectangle(sortbutton[1][0], sortbutton[1][1], sortbutton[1][2], sortbutton[1][3]);
			SelectionSort(num);
		}
		if (m.x > sortbutton[2][0] && m.x <sortbutton[2][2] && m.y > sortbutton[2][1] && m.y < sortbutton[2][3]) {
			fillrectangle(sortbutton[2][0], sortbutton[2][1], sortbutton[2][2], sortbutton[2][3]);
			InsertionSort(num);
		}
		if (m.x > sortbutton[3][0] && m.x < sortbutton[3][2] && m.y > sortbutton[3][1] && m.y < sortbutton[3][3]){
			fillrectangle(sortbutton[3][0], sortbutton[3][1], sortbutton[3][2], sortbutton[3][3]);
			QuickSort(num, 0, num[0].len);
		}
		if (m.x > sortbutton[4][0] && m.x < sortbutton[4][2] && m.y >sortbutton[4][1] && m.y < sortbutton[4][3]) {
			fillrectangle(sortbutton[4][0], sortbutton[4][1], sortbutton[4][2], sortbutton[4][3]);
			MergeSort(num, num[0].len);
		}
		if (m.x > ControlButton[5][0] && m.x < ControlButton[5][2] && m.y >ControlButton[5][1] && m.y < ControlButton[5][3]) {
			fillrectangle(ControlButton[5][0], ControlButton[5][1], ControlButton[5][2], ControlButton[5][3]);
			Sleep(100);
			sorted = 0;
			*pnum = RandCreat();
			BeginBatchDraw();
			cleardevice();
			SortFace();
			for (cnt = 0; cnt < (*pnum)[0].len; cnt++) {
				SortRectangle((*pnum)[cnt].r[0], (*pnum)[cnt].r[1], (*pnum)[cnt].r[2], (*pnum)[cnt].r[3], (*pnum)[cnt].data, (*pnum)[cnt].color);
			}
			FlushBatchDraw();
			EndBatchDraw();
		}
		if (m.x > 10 && m.x < 110 && m.y >20 && m.y < 70) {
			fillrectangle(10, 20, 110, 70);
			Sleep(100);
			free(num);
			fflush(stdin);
			game = 1;
			sorted = 0;
			Choose();
		}
		if (m.x > ControlButton[4][0] && m.x < ControlButton[4][2] && m.y >ControlButton[4][1] && m.y < ControlButton[4][3]) {
			fillrectangle(ControlButton[4][0], ControlButton[4][1], ControlButton[4][2], ControlButton[4][3]);

		}
		flushmessage();
		break;
	case WM_MOUSEMOVE:
		break;
		flushmessage();
	}
}
rec *RandCreat() {
	rec *num;
	int position[14][4] = { {315, 430, 375, 450},{380, 430, 440, 450},
							{445, 430, 505, 450},{510, 430, 570, 450},
							{575, 430, 635, 450},{640, 430, 700, 450},
							{705, 430, 765, 450},{770, 430, 830, 450},
							{835, 430, 895, 450},{900, 430, 960, 450},
							{965, 430, 1025,450},{1030,430, 1090,450},
							{1095,430, 1155,450},{1160,430, 1220,450} };
	int n = 0, cnt = 0, cnt1 = 0;
	srand(time(NULL));
	while (n < 5 || n > 14) {
		n = rand() % 100;
	}
	num = (rec*)malloc(sizeof(rec) * n);
	for (cnt = 0; cnt < n; cnt++) {
		if (num == NULL) {
			exit(1);
		}
		if (cnt < n) {
			num[cnt].data = (rand() % 100);
		}
		if (num[cnt].data == 0) {
			cnt--;
		}
	}
	for (cnt = 0; cnt < n; cnt++) {
		for (cnt1 = 0; cnt1 < 4; cnt1++) {
			num[cnt].r[cnt1] = position[cnt][cnt1];
		}
	}
	for (cnt = 0; cnt < n; cnt++) {
		num[cnt].color = 1;
	}
	if (num == NULL) {
		exit(1);
	}
	num[0].len = n;
	return num;
}
void BubbleSort(rec *num) {
	DoubleBuf();
	Sleep(100);
	if (sorted == 1)
		return;
	int cnt, cnt1;
	setbkcolor(WHITE);
	BeginBatchDraw();
	cleardevice();
	setlinestyle(PS_SOLID | PS_ENDCAP_ROUND | PS_JOIN_ROUND, 3);
	for (cnt = 0; cnt < num[0].len; cnt++) {
		SortRectangle(num[cnt].r[0], num[cnt].r[1], num[cnt].r[2], num[cnt].r[3], num[cnt].data, num[cnt].color);
	}
	SortFace();
	FlushBatchDraw();
	EndBatchDraw();
	for (cnt = 0; cnt < num[0].len; cnt++) {
		for (cnt1 = 0; cnt1 < num[0].len - cnt - 1; cnt1++) {
			settextstyle(20, 0, "微软雅黑");
			if (num[cnt1].data > num[cnt1 + 1].data) {
				BlockMove(num, cnt1, num[cnt1].r, num[cnt1].data, cnt1 + 1, num[cnt1 + 1].r, num[cnt1 + 1].data, num[0].len);
				DataSwap(&num[cnt1], &num[cnt1 + 1]);
			}
			Sleep(250);
		}
		num[cnt1].color = 3;
	}
	BeginBatchDraw();
	cleardevice();
	SortFace();
	for (cnt = 0; cnt < num[0].len; cnt++) {
		SortRectangle(num[cnt].r[0], num[cnt].r[1], num[cnt].r[2], num[cnt].r[3], num[cnt].data, num[cnt].color);
	}
	ShowMsg("排序完成！");
	FlushBatchDraw();
	EndBatchDraw();
	sorted = 1;
}
void SelectionSort(rec *num) {
	DoubleBuf();
	Sleep(100);
	if (sorted == 1)
		return;
	int cnt, cnt1, cnt2;
	int min = 0;
	setbkcolor(WHITE);
	setlinecolor(BLACK);
	for (cnt = 0; cnt < num[0].len; cnt++) {
		min = cnt;
		for (cnt1 = cnt + 1; cnt1 < num[0].len; cnt1++) {
			if (num[cnt1].data < num[min].data) {
				min = cnt1;
			}
			Sleep(150);
			BeginBatchDraw();
			cleardevice();
			SortFace();
			for (cnt2 = 0; cnt2 < num[0].len; cnt2++) {
				if (cnt2 == min) {
					setfillcolor(RGB(220, 20, 60));
					SortRectangle(num[cnt2].r[0], num[cnt2].r[1], num[cnt2].r[2], num[cnt2].r[3], num[cnt2].data, 0);
				}
				else {
					SortRectangle(num[cnt2].r[0], num[cnt2].r[1], num[cnt2].r[2], num[cnt2].r[3], num[cnt2].data, num[cnt2].color);
				}
			}
			ShowMsg("正在寻找本轮最小数");
			FlushBatchDraw();
			EndBatchDraw();
		}
		Sleep(500);
		if (cnt != min) {
			BlockMove(num, cnt, num[cnt].r, num[cnt].data, min, num[min].r, num[min].data, num[0].len);
			DataSwap(&num[cnt], &num[min]);
			num[cnt].color = 4;
		}
		else {
			num[min].color = 4;
		}
	}
	setfillcolor(RGB(173, 216, 230));
	BeginBatchDraw();
	cleardevice();
	SortFace();
	for (cnt = 0; cnt < num[0].len; cnt++) {
		SortRectangle(num[cnt].r[0], num[cnt].r[1], num[cnt].r[2], num[cnt].r[3], num[cnt].data, num[cnt].color);
	}
	ShowMsg("排序完成！");
	FlushBatchDraw();
	EndBatchDraw();
	sorted = 1;
}
void InsertionSort(rec* num) {
	settextstyle(30, 10, "微软雅黑");
	DoubleBuf();
	Sleep(100);
	if (sorted == 1)
		return;
	setfillcolor(RGB(173, 216, 230));
	int cnt, cnt1, swap, flag = 1;
	num[0].color = 5;
	for (cnt = 0; cnt < num[0].len - 1; ++cnt)
	{
		int end = cnt, y1, y2, x1, x2, tx1, ty1;
		//待插入的元素
		int tem = num[end + 1].data;
		y1 = num[end + 1].r[1];
		y2 = 450;
		while (y2 < 900) {
			BeginBatchDraw();
			cleardevice();
			SortFace();
			setfillcolor(RED);
			SortRectangle(num[end + 1].r[0], y1, num[end + 1].r[2], y2, num[end + 1].data, 0);
			for (cnt1 = 0; cnt1 < num[0].len; cnt1++) {
				setfillcolor(RGB(173, 216, 230));
				if (cnt1 != end + 1)
					SortRectangle(num[cnt1].r[0], num[cnt1].r[1], num[cnt1].r[2], num[cnt1].r[3], num[cnt1].data, num[cnt1].color);
			}
			ShowMsg("未排序元素下移..");
			FlushBatchDraw();
			EndBatchDraw();
			y1 += 10;
			y2 += 10;  //红块下移
			Sleep(10);
		}
		Sleep(200);
		clearrectangle(1400, 800, 1600, 900);
		while (end >= 0) {
			//比插入的数大就向后移
			x1 = num[end].r[0];
			x2 = num[end].r[2];
			if (tem < num[end].data) {
				while (x2 < num[end + 1].r[2]) {
					x1 += 5; //蓝块右移
					x2 += 5;
					BeginBatchDraw();
					cleardevice();
					SortFace();
					setfillcolor(RGB(173, 216, 230));
					SortRectangle(x1, num[end].r[1], x2, num[end].r[3], num[end].data, num[cnt].color);
					setfillcolor(RED);
					SortRectangle(num[end + 1].r[0], y1, num[end + 1].r[2], y2, num[end + 1].data, 0);
					for (cnt1 = 0; cnt1 < num[0].len; cnt1++) {
						setfillcolor(RGB(173, 216, 230));
						if (cnt1 != end + 1 && cnt1 != end)
							SortRectangle(num[cnt1].r[0], num[cnt1].r[1], num[cnt1].r[2], num[cnt1].r[3], num[cnt1].data, num[cnt1].color);
					}
					ShowMsg("与已排序元素比较...");
					FlushBatchDraw();
					EndBatchDraw();
					Sleep(15);
				}
				Sleep(200);
				x1 = num[end + 1].r[0];
				x2 = num[end + 1].r[2];
				tx1 = num[end].r[0];
				ty1 = num[end].r[1];
				swap = num[end + 1].data;
				num[end + 1].data = num[end].data;
				num[end].data = swap;
				end--;
				while (x1 > tx1) { // 红块左移
					BeginBatchDraw();
					cleardevice();
					SortFace();
					setfillcolor(RGB(173, 216, 230));
					SortRectangle(num[end].r[0], num[end].r[1], num[end].r[2], num[end].r[3], num[end].data, num[end].color);
					setfillcolor(RED);
					SortRectangle(x1, y1, x2, y2, num[end + 1].data, 0);
					for (cnt1 = 0; cnt1 < num[0].len; cnt1++) {
						setfillcolor(RGB(173, 216, 230));
						if (cnt1 != end + 1 && cnt1 != end)
							SortRectangle(num[cnt1].r[0], num[cnt1].r[1], num[cnt1].r[2], num[cnt1].r[3], num[cnt1].data, num[cnt1].color);
					}
					ShowMsg("交换位置...");
					FlushBatchDraw();
					EndBatchDraw();
					x1 -= 5;
					x2 -= 5;
					Sleep(15);
				}
				Sleep(200);
	}
			else if (tem >= num[end].data){
				while (y1 >= 425) { // 红块上移
					BeginBatchDraw();
					cleardevice();
					SortFace();
					setfillcolor(RGB(173, 216, 230));
					SortRectangle(num[end].r[0], num[end].r[1], num[end].r[2], num[end].r[3], num[end].data, num[end].color);
					setfillcolor(RED);
					SortRectangle(num[end + 1].r[0], y1, num[end + 1].r[2], y2, num[end + 1].data, 0);
					for (cnt1 = 0; cnt1 < num[0].len; cnt1++) {
						setfillcolor(RGB(173, 216, 230));
						if (cnt1 != end + 1 && cnt1 != end)
							SortRectangle(num[cnt1].r[0], num[cnt1].r[1], num[cnt1].r[2], num[cnt1].r[3], num[cnt1].data, num[cnt1].color);
					}
					ShowMsg("插入当前位置...");
					FlushBatchDraw();
					EndBatchDraw();
					y1 -= 5;
					y2 -= 5;
					Sleep(1);
				}
				Sleep(250);
				num[end + 1].color = 5;
				break;
			}
	}		
		if (end == -1) {
			while (y1 >= 425) { // 红块上移
				BeginBatchDraw();
				cleardevice();
				SortFace();
				setfillcolor(RGB(173, 216, 230));
				SortRectangle(num[end].r[0], num[end].r[1], num[end].r[2], num[end].r[3], num[end].data, num[end].color);
				setfillcolor(RED);
				SortRectangle(num[end + 1].r[0], y1, num[end + 1].r[2], y2, num[end + 1].data, 0);
				for (cnt1 = 0; cnt1 < num[0].len; cnt1++) {
					setfillcolor(RGB(173, 216, 230));
					if (cnt1 != end + 1 && cnt1 != end)
						SortRectangle(num[cnt1].r[0], num[cnt1].r[1], num[cnt1].r[2], num[cnt1].r[3], num[cnt1].data, num[cnt1].color);
				}
				ShowMsg("插入当前位置...");
				FlushBatchDraw();
				EndBatchDraw();
				y1 -= 5;
				y2 -= 5;
				Sleep(5);
			}
			Sleep(250);
		}
		num[flag++].color = 5;
}
	setbkcolor(WHITE);
	BeginBatchDraw();
	cleardevice();
	SortFace();
	setlinecolor(BLACK);
	setfillcolor(RGB(173, 216, 230));
	for (cnt = 0; cnt < num[0].len; cnt++) {
		SortRectangle(num[cnt].r[0], num[cnt].r[1], num[cnt].r[2], num[cnt].r[3], num[cnt].data, num[cnt].color);
	}
	ShowMsg("排序完成！");
	FlushBatchDraw();
	EndBatchDraw();
	sorted = 1;
}
void QuickSort(rec* num, int left, int right) {
	Sleep(100);
	DoubleBuf();
	if (sorted == 1)
		return;
	int cnt;
	setbkcolor(WHITE);
	setlinecolor(BLACK);
	BeginBatchDraw();
	cleardevice();
	SortFace();
	setfillcolor(RGB(173, 216, 230));
	for (cnt = 0; cnt < num[0].len; cnt++) {
		SortRectangle(num[cnt].r[0], num[cnt].r[1], num[cnt].r[2], num[cnt].r[3], num[cnt].data, num[cnt].color);
	}
	FlushBatchDraw();
	EndBatchDraw();
	QS(num, left, right);
	setfillcolor(RGB(173, 216, 230));
	BeginBatchDraw();
	cleardevice();
	SortFace();
	for (cnt = 0; cnt < num[0].len; cnt++) {
		SortRectangle(num[cnt].r[0], num[cnt].r[1], num[cnt].r[2], num[cnt].r[3], num[cnt].data, num[cnt].color);
	}
	FlushBatchDraw();
	EndBatchDraw();
	sorted = 1;
}
void QS(rec* num, int left, int right) {
	if (left > right)
		return;
	//_getch();
	int begin, end;
	for (begin = left, end = right; begin != end;) {
		num[left].color = 2;
		while (num[end].data >= num[left].data && begin < end) {
			num[end].color = 3;
			BeginBatchDraw();
			cleardevice();
			setlinestyle(PS_SOLID | PS_ENDCAP_ROUND | PS_JOIN_ROUND, 3);
			for (int cnt = 0; cnt < num[0].len; cnt++) {
				SortRectangle(num[cnt].r[0], num[cnt].r[1], num[cnt].r[2], num[cnt].r[3], num[cnt].data, num[cnt].color);
			}
			SortFace();
			clearrectangle(1400, 800, 1600, 900);
			ShowMsg("寻找右边小值");
			FlushBatchDraw();
			EndBatchDraw();
			Sleep(250);
			num[end].color = 1;
			BeginBatchDraw();
			cleardevice();
			setlinestyle(PS_SOLID | PS_ENDCAP_ROUND | PS_JOIN_ROUND, 3);
			for (int cnt = 0; cnt < num[0].len; cnt++) {
				SortRectangle(num[cnt].r[0], num[cnt].r[1], num[cnt].r[2], num[cnt].r[3], num[cnt].data, num[cnt].color);
			}
			SortFace();
			clearrectangle(1400, 800, 1600, 900);
			ShowMsg("寻找右边小值");
			FlushBatchDraw();
			EndBatchDraw();
			end--;
		}
		num[end].color = 4;
		SortRectangle(num[end].r[0], num[end].r[1], num[end].r[2], num[end].r[3], num[end].data, num[end].color);
		Sleep(200);
		while (num[begin].data <= num[left].data && begin < end) {
			num[begin].color = 5;
			BeginBatchDraw();
			cleardevice();
			setlinestyle(PS_SOLID | PS_ENDCAP_ROUND | PS_JOIN_ROUND, 3);
			for (int cnt = 0; cnt < num[0].len; cnt++) {
				SortRectangle(num[cnt].r[0], num[cnt].r[1], num[cnt].r[2], num[cnt].r[3], num[cnt].data, num[cnt].color);
			}
			SortFace();
			ShowMsg("寻找左边大值");
			FlushBatchDraw();
			EndBatchDraw();
			Sleep(250);
			num[begin].color = 1;
			BeginBatchDraw();
			cleardevice();
			setlinestyle(PS_SOLID | PS_ENDCAP_ROUND | PS_JOIN_ROUND, 3);
			for (int cnt = 0; cnt < num[0].len; cnt++) {
				SortRectangle(num[cnt].r[0], num[cnt].r[1], num[cnt].r[2], num[cnt].r[3], num[cnt].data, num[cnt].color);
			}
			SortFace();
			ShowMsg("寻找左边大值");
			FlushBatchDraw();
			EndBatchDraw();
			begin++;
		}
		num[begin].color = 5;
		SortRectangle(num[begin].r[0], num[begin].r[1], num[begin].r[2], num[begin].r[3], num[begin].data, num[begin].color);
		Sleep(200);
		num[end].color = 1;
		num[begin].color = 1;
		if (begin < end) {
			cleardevice();
			BlockMove(num, begin, num[begin].r, num[begin].data, end, num[end].r, num[end].data, num[0].len);
			DataSwap(&num[begin], &num[end]);
		}
		num[left].color = 1;
	}

	BlockMove(num, left, num[left].r, num[left].data, begin, num[begin].r, num[begin].data, num[0].len);
	DataSwap(&num[begin], &num[left]);
	QS(num, left, begin - 1);
	QS(num, begin + 1, right);

}
void MergeSort(rec* num, int len) {
	Sleep(100);
	if (sorted == 1) {
		return;
	}
	rec* a = num;
	rec* b = (rec*)malloc(len * sizeof(rec));
	for (int cnt = 0; cnt < len; cnt++) {
		for (int cnt1 = 0; cnt1 < 4; cnt1++) {
			b[cnt].r[cnt1] = temP[cnt][cnt1];
		}
	}
	cleardevice();
	SortFace();
	setlinestyle(PS_SOLID | PS_ENDCAP_ROUND | PS_JOIN_ROUND, 3);
	for (int cnt = 0; cnt < num[0].len; cnt++) {
		SortRectangle(num[cnt].r[0], num[cnt].r[1], num[cnt].r[2], num[cnt].r[3], num[cnt].data, cnt + 2);
		Sleep(200);
		ShowMsg("数组细分...");
	}
	clearrectangle(1400, 800, 1600, 900);
	int seg, start, color = 2, clear = 1;
	for (seg = 1; seg < len; seg += seg) {
		color = 2;
		ShowMsg("由小到大递归合并...");
		for (start = 0; start < len; start += seg * 2) {
			setlinestyle(PS_SOLID | PS_ENDCAP_ROUND | PS_JOIN_ROUND, 3);
			int left = start, mid = Min(start + seg, len), right = Min(start + seg * 2, len);
			int k = left;
			int start1 = left, end1 = mid;
			int start2 = mid, end2 = right;
			while (start1 < end1 && start2 < end2) {
				b[k++].data = a[start1].data < a[start2].data ? a[start1++].data : a[start2++].data;
				Sleep(500);
				SortRectangle(b[k - 1].r[0], b[k - 1].r[1], b[k - 1].r[2], b[k - 1].r[3], b[k - 1].data, color);
			}
			while (start1 < end1) {
				b[k++].data = a[start1++].data;
				Sleep(500);
				SortRectangle(b[k - 1].r[0], b[k - 1].r[1], b[k - 1].r[2], b[k - 1].r[3], b[k - 1].data, color);
			}
			while (start2 < end2) {
				b[k++].data = a[start2++].data;
				Sleep(500);
				SortRectangle(b[k - 1].r[0], b[k - 1].r[1], b[k - 1].r[2], b[k - 1].r[3], b[k - 1].data, color);
			}
			color++;
		}
		Sleep(500);
		if (clear) {
			clearrectangle(314, 0, 1221, 452);
			clear = 0;
		}
		else {
			clearrectangle(314, 452, 1221, 900);
			clear = 1;
		}
		rec* temp = a;
		a = b;
		b = temp;
	}
	if (a != num) {
		int i;
		for (i = 0; i < len; i++) {
			b[i].data = a[i].data;
		}
		b = a;
	}
	clearrectangle(1400, 800, 1600, 900);
	BeginBatchDraw();
	cleardevice();
	SortFace();
	for (int i = 0; i < len; i++) {
		SortRectangle(Tposition[i][0], Tposition[i][1], Tposition[i][2], Tposition[i][3], a[i].data, 1);
	}
	ShowMsg("排序完成！");
	FlushBatchDraw();
	EndBatchDraw();
	
	sorted = 1;
	free(b);
}
/* 自定绘图函数 */
void EllipseButton(int x1, int y1, int x2, int y2, LPCSTR str) {
	RECT R = { x1, y1, x2, y2 };
	ellipse(x1, y1, x2, y2);
	drawtext(str, &R, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
void Arrowhead(int x1, int y1, int x2, int y2) {
	setlinecolor(BLACK);
	setrop2(R2_NOTXORPEN);
	line(x1, y1, x2, y2);
	double distance = sqrt((y1 - y2) * (y1 - y2) + (x1 - x2) * (x1 - x2));
	double tmpx = double(x1 + (x2 - x1) * (1 - (12 * sqrt(3) / 2) / distance));
	double tmpy = double(y1 + (y2 - y1) * (1 - (12 * sqrt(3) / 2) / distance));
	if (y1 == y2)
	{
		line(x2, y2, int(tmpx), int(tmpy + 6));
		line(x2, y2, int(tmpx), int(tmpy - 6));
	}
	else
	{
		double k = (double(x2) - double(x1)) / (double(y1) - double(y2));
		double increX = 6 / sqrt(k * k + 1);
		double increY = 6 * k / sqrt(k * k + 1);
		line(x2, y2, int(tmpx + increX), int(tmpy + increY));
		line(x2, y2, int(tmpx - increX), int(tmpy - increY));
	}
}
void RectangleButton(int x1, int y1, int x2, int y2, LPCSTR str) {
	RECT R = { x1, y1, x2, y2 };
	rectangle(x1, y1, x2, y2);
	drawtext(str, &R, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
void CircleButton(int x, int y, int r, LPCTSTR str) {
	RECT R;
	settextcolor(BLACK);
	R = { x - r, y - r, x + r, y + r };
	circle(x, y, r);
	drawtext(str, &R, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
void SortRectangle(int x1, int y1, int x2, int y2, int n, int c) {
	int cnt;
	char num[20];
	RECT Text = { x1, y1, x2, y2 };
	settextcolor(BLACK);
	sprintf_s(num, "%d", n);
	drawtext(num, &Text, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	for (cnt = 0; cnt < n; cnt++) {
		y1 -= 4;
	}
	switch (c) {
	case 1:
		setfillcolor(RGB(173, 216, 230)); break;
	case 2:
		setfillcolor(RGB(255, 0, 0)); break;
	case 3:
		setfillcolor(RGB(255, 128, 0)); break;
	case 4:
		setfillcolor(RGB(255, 191, 0)); break;
	case 5:
		setfillcolor(RGB(255, 255, 0)); break;
	case 6:
		setfillcolor(RGB(191, 255, 0)); break;
	case 7:
		setfillcolor(RGB(0, 255, 128)); break;
	case 8:
		setfillcolor(RGB(0, 255, 191)); break;
	case 9:
		setfillcolor(RGB(0, 255, 255)); break;
	case 10:
		setfillcolor(RGB(0, 191, 255)); break;
	case 11:
		setfillcolor(RGB(0, 128, 255)); break;
	case 12:
		setfillcolor(RGB(0, 64, 255)); break;
	case 13:
		setfillcolor(RGB(64, 0, 255)); break;
	case 14:
		setfillcolor(RGB(128, 0, 255)); break;
	case 15:
		setfillcolor(RGB(191, 0, 255)); break;
	}
	fillrectangle(x1, y1, x2, y2);
}
void LinkedListCircle(int x, int y, int r, int num) {

	char s[20];
	sprintf_s(s, "%d", num);
	outtextxy(x - 10, y - 12, s);
	setfillcolor(RGB(46, 186, 209));
	fillcircle(x, y, r);
}
void ClearRectangle(int x1, int y1, int x2, int y2, int n) {
	int cnt;
	for (cnt = 0; cnt < n; cnt++) {
		y1 -= 4;
	}
	clearrectangle(x1, y1, x2, y2);
}

/*图形变化函数*/
void ColorLine(int x1, int y1, int x2, int y2, int color) {
	int tempx = x1, tempy = y1;
	double ang = (y1 - y2) / (x1 - x2);
	setlinecolor(color);
	setlinestyle(PS_SOLID, 8);
	while (abs(x2 - tempx) > 2) {
		if (tempx > x2) {
			tempx -= 10;
			tempy -= 10 * ang;

		}
		else {
			tempx += 10;
			tempy += 10 * ang;

		}
		line(x1, y1, tempx, tempy);
		Sleep(1);

	}
	setlinestyle(PS_SOLID, 2);
	line(x1, y1, x2, y2);
}// 线段变色
void BlockMove(rec* num, int p1, int* R1, int n1, int p2, int* R2, int n2, int n) {
	DoubleBuf();
	int end = R2[0];
	int cnt;
	int x1 = R1[0], x2 = R1[2], x3 = R2[0], x4 = R2[2];
	setrop2(R2_NOTXORPEN);
	setfillcolor(GREEN);
	while (x1 < end) {
		x1 += 5;
		x2 += 5;
		x3 -= 5;
		x4 -= 5;
		BeginBatchDraw();
		cleardevice();
		SortFace();
		for (cnt = 0; cnt < n; cnt++) {
			if (cnt != p1 && cnt != p2) {
				SortRectangle(num[cnt].r[0], num[cnt].r[1], num[cnt].r[2], num[cnt].r[3], num[cnt].data, num[cnt].color);
				settextstyle(20, 0, "微软雅黑");
				ShowMsg("正在交换");
			};
		}
		setrop2(R2_NOTXORPEN);
		setfillcolor(GREEN);
		SortRectangle(x1, R1[1], x2, R1[3], n1, 0);
		SortRectangle(x3, R2[1], x4, R2[3], n2, 0);
		setfillcolor(RGB(173, 216, 230));
		FlushBatchDraw();
		EndBatchDraw();
		Sleep(15);
	};
}
/* 窗口相关函数*/
void SetText() {
	HWND hw = GetHWnd();
	SetWindowText(hw, "数据结构可视化");
}  // 设置窗口名
/* 鼠标相关函数*/
void MouseClick() {
	int i, event = 0;
	ExMessage m;//鼠标指针
	peekmessage(&m, EM_MOUSE);//获取一条鼠标消息
	switch (m.message) {
	case  WM_LBUTTONDOWN:
		setlinestyle(PS_SOLID, 1);
		setrop2(R2_NOTXORPEN);
		for (i = 0; i <= 10; i++)
		{
			setlinecolor(RGB(25 * i, 25 * 2 * i, 25 * 4 * i));//设置圆颜色
			circle(m.x, m.y, 3 * i);
			Sleep(15);
			circle(m.x, m.y, 3 * i);

		}
		flushmessage();
		setrop2(R2_COPYPEN);
		break;

	}
}//鼠标单击特效
/* 数据相关 */
void DataSwap(rec* num1, rec* num2) {
	int tem, cnt;
	tem = num1->data;
	num1->data = num2->data;
	num2->data = tem;
	for (cnt = 1; cnt < 4; cnt += 2) {
		tem = num1->r[cnt];
		num1->r[cnt] = num2->r[cnt];
		num2->r[cnt] = tem;
	}
}
void ShowMsg(LPCSTR msg) {
	RECT m;
	m = {1400, 800, 1600, 900};
	drawtext(msg, &m, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
void DoubleBuf() {
	HANDLE hOutput;
	COORD coord = { 0,0 };
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hOutBuf = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);

	SetConsoleActiveScreenBuffer(hOutBuf);

	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = 0;
	cci.dwSize = 1;
	SetConsoleCursorInfo(hOutput, &cci);
	SetConsoleCursorInfo(hOutBuf, &cci);

	DWORD bytes = 0;
}
int Min(int x, int y) {
	return x < y ? x : y;
}