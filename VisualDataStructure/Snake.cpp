typedef struct xy
{
    int x;
    int y;
}mysnake, myfood;
struct Snake
{
    mysnake xy[1000];
    int pich;//蛇的节数
    char postion;//蛇的方向
}snake;
struct food
{
    myfood xy;//食物坐标
    int point;//食物分数
    int flag;
}food;
enum snakepostion { right = 77, left = 75, up = 72, down = 80 };
void initsnake()
{
    snake.xy[2].x = 100;
    snake.xy[2].y = 100;

    snake.xy[1].x = 110;
    snake.xy[1].y = 100;

    snake.xy[0].x = 120;
    snake.xy[0].y = 100;

    snake.pich = 3;
    snake.postion = right;

    for (int i = 3; i < 1000; i++)
    {
        snake.xy[i].x = -120;
        snake.xy[i].y = -100;
    }

}
void drawsnake()
{
    for (int i = 0; i < snake.pich; i++)
    {
        setlinecolor(BLACK);
        setfillcolor(BLUE);
        fillrectangle(snake.xy[i].x, snake.xy[i].y, snake.xy[i].x + 20, snake.xy[i].y + 20);
    }

}
void movesnake()
{
    //除第一节外其他节的移动情况
    for (int i = snake.pich - 1; i > 0; i--)
    {
        snake.xy[i].x = snake.xy[i - 1].x;
        snake.xy[i].y = snake.xy[i - 1].y;
    }
    //第一节的处理
    switch (snake.postion)
    {
    case right:
        snake.xy[0].x += 20;
        break;
    case left:
        snake.xy[0].x -= 20;
        break;
    case up:
        snake.xy[0].y -= 20;
        break;
    case down:
        snake.xy[0].y += 20;
        break;
    default:
        break;
    }
}
void keydown()
{
    if (_kbhit())
    {
        char c = _getch();
        switch (c)
        {
        case right:
            if (snake.postion != left)
                snake.postion = right;
            break;
        case left:
            if (snake.postion != right)
                snake.postion = left;
            break;
        case up:
            if (snake.postion != down)
                snake.postion = up;
            break;
        case down:
            if (snake.postion != up)
                snake.postion = down;
            break;
        case ' ':
            while (1)
            {
                char d = _getch();
                if (d == ' ')
                    break;

            }
        default:
            break;

        }

    }
}
void initfood()
{
    srand((unsigned int)time(NULL));
    food.xy.y = food.xy.x = 2000;
    while (food.xy.y > 900 || food.xy.y % 20 != 0 || food.xy.y == 100) {
        food.xy.y = rand() % 1000;
    }
    while (food.xy.x > 1600 || food.xy.x % 20 != 0) {
        food.xy.x = rand() % 1000;
    }
    food.flag = 1;
    food.point = 0;
}
void drawfood()
{
    srand((unsigned int)time(NULL));
    if (food.flag == 0)
    {
        food.xy.y = food.xy.x = 2000;
        while (food.xy.y > 900 || food.xy.y % 20 != 0) {
            food.xy.y = rand() % 1000;
        }
        while (food.xy.x > 1600 || food.xy.x % 20 != 0) {
            food.xy.x = rand() % 1000;
        }

        food.flag = 1;

    }
    setfillcolor(RED);
    fillrectangle(food.xy.x, food.xy.y, food.xy.x + 20, food.xy.y + 20);
    settextcolor(BLACK);
    settextstyle(30, 0, "微软雅黑");
    char gamepoint[20] = "0";
    sprintf_s(gamepoint, "%d", food.point);
    outtextxy(800, 0, "分数：");
    outtextxy(860, 0, gamepoint);
}
void eatfood()
{
    if (snake.xy[0].x == food.xy.x && snake.xy[0].y == food.xy.y)
    {
        snake.pich++;
        food.flag = 0;
        food.point += 10;
    }
}
int snakedie()
{
    HWND hwnd = GetHWnd();  
    if (snake.xy[0].x + 20 < 0 || snake.xy[0].y + 20 < 0 || snake.xy[0].x == 1600 || snake.xy[0].y == 900)
    {
        MessageBox(hwnd, "你撞墙了", "游戏结束", MB_OK);
        return 1;
    }
    for (int i = 1; i < snake.pich; i++)
    {
        if (snake.xy[i].x == snake.xy[0].x && snake.xy[i].y == snake.xy[0].y)
        {
            MessageBox(hwnd, "你咬到自己了", "游戏结束", MB_OK);
            return 1;
        }
    }


}
int Timer(time_t time, int id)
{
    static time_t start[5];
    int end = clock();
    if (end - start[id] >= time)
    {
        start[id] = end;
        return 1;
    }
    return 0;

}
void Snake()
{
    initgraph(1600, 900);
    BeginBatchDraw();
    setbkcolor(WHITE);
    cleardevice();
    initsnake();
    initfood();
    while (1)
    {
        cleardevice();
        keydown();
        drawfood();
        drawsnake();
        if (snakedie() == 1)
        {
            break;
        }

        if (Timer(80 - (snake.pich / 10) * 5, 0))
        {
            movesnake();
        }
        eatfood();
        FlushBatchDraw();
    }
    EndBatchDraw();
}
