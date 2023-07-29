#ifndef __TDS_H_
#define __TDS_H_
struct TRECT {
	RECT r;
	TRECT(int left,int top,int right,int bottom) {
		r.left = left;
		r.top = top;
		r.right = right;
		r.bottom = bottom;
	}
	RECT get_rect() {
		return r;
	}
};
#endif
