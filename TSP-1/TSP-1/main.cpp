#define _CRT_SECURE_NO_WARNINGS
#include "TSP.h"
#include <windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("Traveling Saleman Problem-local optimization");


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
    HWND hWnd;
    MSG Message;
    WNDCLASS WndClass;
    g_hInst = hInstance;
    
    WndClass.cbClsExtra = 0;
    WndClass.cbWndExtra = 0;
    WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    WndClass.hInstance = hInstance;
    WndClass.lpfnWndProc = WndProc;
    WndClass.lpszClassName = lpszClass;
    WndClass.lpszMenuName = NULL;
    WndClass.style = CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&WndClass);
    
    hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);
    ShowWindow(hWnd, nCmdShow);
    
    while (GetMessage(&Message, NULL, 0, 0))
    {
        TranslateMessage(&Message);
        DispatchMessage(&Message);
    }
    return (int)Message.wParam;
}

City spt = City(10, 10);
City ept = City(500, 500);
City gp1 = City(510, 10);
City gp2 = City(910, 370);
City gp_O = City(520, 360);
City gp_X = City(900, 360);
City gp_Y = City(520, 20);

void pc_LineTo(HDC hdc, City p1, City p2)
{
    MoveToEx(hdc, p1.x, p1.y, NULL);
    LineTo(hdc, p2.x, p2.y);
}

void DrawGraph(HDC hdc, int p)
{
    City be;
    City af = gp_O;
    for (int i = 0; i <= p; i++)
    {
        double x = (double)i / (double)p * (double)(gp_X.x - gp_O.x) + (double)gp_O.x;
        double y = gp_Y.y + (double)(record[i].dis - min_dis[p]) / (double)(max_dis[p] - min_dis[p]) * (double)(gp_O.y - gp_Y.y-10);
        be = af;
        af = City((int)x, (int)y);
        pc_LineTo(hdc, be, af);
    }
}

#define ID_EDIT 100
HWND hEdit;
int now;
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    TCHAR str[128] = { 0, };
    static RECT rt = { spt.x, spt.y, ept.x, ept.y };
    static RECT gh = { gp1.x, gp1.y, gp2.x, gp2.y };
    static RECT wrd = { 550, 425, 650, 450 };
    static RECT dis = { 600, 370, 700, 425 };
    switch (iMessage)
    {
        case WM_CREATE:
            hEdit = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 570, 450, 100, 25, hWnd, (HMENU)ID_EDIT, g_hInst, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("Next Age"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 620, 475, 100, 25, hWnd, (HMENU)0, g_hInst, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("restart"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 730, 475, 100, 25, hWnd, (HMENU)3, g_hInst, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("Prev Age"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 510, 475, 100, 25, hWnd, (HMENU)1, g_hInst, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("Go"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 680, 450, 30, 25, hWnd, (HMENU)2, g_hInst, NULL);
            submain();
            return 0;
        case WM_COMMAND:
            switch (LOWORD(wParam))
        {
            case 0://next age
                InvalidateRect(hWnd, &rt, TRUE);
                InvalidateRect(hWnd, &wrd, TRUE);
                InvalidateRect(hWnd, &dis, TRUE);
                InvalidateRect(hWnd, &gh, TRUE);
                now++;
                if (now >= age)
                    now = now%age;
                break;
            case 1://prev age
                InvalidateRect(hWnd, &rt, TRUE);
                InvalidateRect(hWnd, &wrd, TRUE);
                InvalidateRect(hWnd, &dis, TRUE);
                InvalidateRect(hWnd, &gh, TRUE);
                now--;
                if (now < 0)
                    now = age - 1;
                break;
            case 2://age to
                GetWindowText(hEdit, str, 10);
                SetWindowText(hEdit, TEXT(""));
                InvalidateRect(hWnd, &rt, TRUE);
                InvalidateRect(hWnd, &wrd, TRUE);
                InvalidateRect(hWnd, &dis, TRUE);
                InvalidateRect(hWnd, &gh, TRUE);
                now = _ttoi(str);
                if (now >= age)
                    now = now%age;
                break;
            case 3://restart
                SetWindowText(hEdit, TEXT(""));
                InvalidateRect(hWnd, &rt, TRUE);
                InvalidateRect(hWnd, &wrd, TRUE);
                InvalidateRect(hWnd, &dis, TRUE);
                InvalidateRect(hWnd, &gh, TRUE);
                now = 0;
                restart();
                break;
        }
            return 0;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_PAINT:
            hdc = BeginPaint(hWnd, &ps);
            TextOut(hdc, 510, 375, TEXT("time : "), 7);
            wsprintf(str, TEXT("%dms"), time_n);
            TextOut(hdc, 600, 375, str, lstrlen(str));
            TextOut(hdc, 510, 400, TEXT("Distance : "), 11);
            wsprintf(str, TEXT("%d"), record[now].dis);
            TextOut(hdc, 600, 400, str, lstrlen(str));
            TextOut(hdc, 510, 425, TEXT("Age : "), 6);
            wsprintf(str, TEXT("%d"), now);
            TextOut(hdc, 550, 425, str, lstrlen(str));
            TextOut(hdc, 510, 450, TEXT("Age To : "), 9);
            Rectangle(hdc, spt.x, spt.y, ept.x, ept.y);//Map
            Rectangle(hdc, gp1.x, gp1.y, gp2.x, gp2.y);//Graph
            pc_LineTo(hdc, gp_O, gp_X);
            pc_LineTo(hdc, gp_O, gp_Y);
            DrawGraph(hdc, now);
            for (int i = 0; i < city; i++)
            {
                int x = Pt[i].x;
                int y = Pt[i].y;
                Ellipse(hdc, x - 5, y - 5, x + 5, y + 5);
            }
            for (int i = 0; i < city; i++)
            {
                int sx = Pt[record[now].gene[i]].x;
                int sy = Pt[record[now].gene[i]].y;
                int ex = Pt[record[now].gene[(i + 1) % city]].x;
                int ey = Pt[record[now].gene[(i + 1) % city]].y;
                MoveToEx(hdc, sx, sy, NULL);
                LineTo(hdc, ex, ey);
            }
            EndPaint(hWnd, &ps);
            return 0;
    }
    return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
