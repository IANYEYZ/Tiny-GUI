#ifndef __TUI_H_
#define __TUI_H_
HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
HINSTANCE hInst;
class basicui{
	public:
		HWND hwnd_;
	public:
		virtual void draw() = 0;
		virtual void destroy() = 0;
};
class button{
	private:
		int ID;
		HWND hwnd_;
	public:
		button(int x,int y,int w,int h,string text,int id) {
			ID = id;
			hwnd_ = CreateWindow("BUTTON", (LPCSTR)(text.c_str()), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            x, y, w, h, hwnd, (HMENU)ID, hInst, NULL);
		}
		void draw() {
			ShowWindow(hwnd_,SW_SHOW);
		}
		void destroy() {
			DestroyWindow(hwnd_);
		}
};
class edit{
	private:
		int ID;
		HWND hwnd_;
		char buff[2048] = {};
		int x_,y_,w_,h_;
	public:
		edit(int x,int y,int w,int h,string text,int id) {
			ID = id;
			x_ = x;
			y_ = y;
			w_ = w;
			h_ = h;
			hwnd_ = CreateWindow("EDIT", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE,
            x, y, w, h, hwnd, (HMENU)ID, hInst, NULL);
		}
		void draw() {
			ShowWindow(hwnd_,SW_SHOW);
		}
		void destroy() {
			DestroyWindow(hwnd_);
		}
		string get_text() {
			GetWindowText(hwnd_,buff,2048);
			return string(buff);
		}
		void operator=(edit o) {
			ID = o.ID;
			x_ = o.x_;
			y_ = o.y_;
			w_ = o.w_;
			h_ = o.h_;
			hwnd_ = CreateWindow("EDIT", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE,
            x_, y_, w_, h_, hwnd, (HMENU)ID, hInst, NULL);
		}
};
void show(button b) {
	b.draw();
}
void show(edit b) {
	b.draw();
}
#endif
