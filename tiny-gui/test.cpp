#include"tgui.h"
#include<iostream>
using namespace std;
using namespace tgui;
edit e(100,100,200,200,"",2);
void click(EPARA p) {
	int id = transepara<int>(p);
	if(id != 1 && id != 2) return;
	if(id == 1) MessageBox(NULL,"button clicked","Button",MB_OK);
	//else        MessageBox(NULL,(e.get_text()).c_str(),"Edit",MB_OK);
	return;
}
void everyloop(EPARA p) {
	/*printf("pos:%d,%d\n",get_mouse_pos().first,get_mouse_pos().second);
	if(KEY_DOWN(VK_LBUTTON)) {
		draw_rect(TRECT(get_mouse_pos().first - 3,get_mouse_pos().second - 3,get_mouse_pos().first + 3,get_mouse_pos().second + 3),(HBRUSH) (COLOR_HOTLIGHT + 1));
	}*/
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	setup(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	//draw_rect(make_rect(0,0,500,500),(HBRUSH) (COLOR_HOTLIGHT + 1));
	TRECT r(0,0,500,500);
	//r.left = 0;
	//r.top = 0;
	//r.right = 500;
	//r.bottom = 500;
	//hdc = GetDC(hwnd);
	//FillRect(hdc,&r,(HBRUSH) (COLOR_HOTLIGHT + 1));
	//ReleaseDC(hwnd,hdc);
	//draw_rect(r,(HBRUSH) (COLOR_HOTLIGHT + 1));
	button b(1,1,100,100,"button",1);
	show(b);
	e = edit(100,100,200,200,"",2);
	show(e);
	bind("command",click);
	bind("messageloop",everyloop);
	return mainloop();
}
