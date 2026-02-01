#include <windows.h>
#include <stdio.h>
#include "smartlab.h"
#define ID_MATHS   101
#define ID_INFO    102
#define ID_PHYS    103
#define ID_CHIM    104
#define ID_QUIT    105

HWND hZone;   // Zone graphique

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch(msg) {

    case WM_CREATE: {
        // ----- Boutons Menu -----
        CreateWindow("BUTTON", "Maths",
            WS_VISIBLE | WS_CHILD,
            20, 60, 160, 35,
            hwnd, (HMENU)ID_MATHS, NULL, NULL);

        CreateWindow("BUTTON", "Informatique",
            WS_VISIBLE | WS_CHILD,
            20, 110, 160, 35,
            hwnd, (HMENU)ID_INFO, NULL, NULL);

        CreateWindow("BUTTON", "Physique",
            WS_VISIBLE | WS_CHILD,
            20, 160, 160, 35,
            hwnd, (HMENU)ID_PHYS, NULL, NULL);

        CreateWindow("BUTTON", "Chimie",
            WS_VISIBLE | WS_CHILD,
            20, 210, 160, 35,
            hwnd, (HMENU)ID_CHIM, NULL, NULL);

        CreateWindow("BUTTON", "Quitter",
            WS_VISIBLE | WS_CHILD,
            20, 280, 160, 35,
            hwnd, (HMENU)ID_QUIT, NULL, NULL);

        // ----- Zone Graphique -----
        hZone = CreateWindow(
            "STATIC", "",
            WS_VISIBLE | WS_CHILD | SS_BLACKFRAME,
            200, 60, 560, 460,
            hwnd, NULL, NULL, NULL
        );
        break;
    }

    case WM_COMMAND:
        switch(LOWORD(wParam)) {

        case ID_MATHS:
            SetWindowText(hZone, "Module Maths sélectionné");
            MessageBox(hwnd, "Module Maths ouvert", "SmartLab", MB_OK);
            break;

        case ID_INFO:
            SetWindowText(hZone, "Module Informatique sélectionné");
            MessageBox(hwnd, "Module Informatique ouvert", "SmartLab", MB_OK);
            break;

        case ID_PHYS:
            SetWindowText(hZone, "Module Physique sélectionné");
            MessageBox(hwnd, "Module Physique ouvert", "SmartLab", MB_OK);
            break;

        case ID_CHIM:
            SetWindowText(hZone, "Module Chimie sélectionné");
            MessageBox(hwnd, "Module Chimie ouvert", "SmartLab", MB_OK);
            break;

        case ID_QUIT:
            PostQuitMessage(0);
            break;
        }
        break;

    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        TextOut(hdc, 20, 20, "SMARTLAB - Application Educative", 30);

        EndPaint(hwnd, &ps);
        break;
    }

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow) {

    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInst;
    wc.lpszClassName = "SmartLabMain";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    RegisterClass(&wc);

    HWND hwnd = CreateWindow(
        "SmartLabMain",
        "SmartLab Education v1.0",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        800, 600,
        NULL, NULL, hInst, NULL
    );

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg;
    while(GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}