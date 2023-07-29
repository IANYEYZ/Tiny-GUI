#ifndef _TEVENT_H_
#define _TEVENT_H_

typedef string EVENT;
typedef void *EPARA;
typedef void(*EFUNC)(EPARA);
typedef void(*EFUNC_NOPARA)();
typedef queue<EFUNC> EQUEUE;
struct EVENTINFO{
	EVENT ev;
	EPARA pa;
	EVENTINFO(){}
	EVENTINFO(const EVENT &_e,const EPARA _p):
		ev(_e),pa(_p){} 
};
 
map<EVENT,EQUEUE> events;

template <typename T>
T transepara(EPARA ep){
	return (T)((long long)(ep));
}
void syncevent(EVENT ev,EPARA para){
	EQUEUE eq=events[ev];
	while(!eq.empty()){
		EFUNC ef=eq.front();
		ef(para);
		eq.pop();
	}
}//ͬ��(����) 
unsigned __stdcall evthread(void *info){
	EVENTINFO *ei=(EVENTINFO*)info;
	syncevent(ei->ev,ei->pa);
	delete ei;
	return 0;
}
void asyncevent(EVENT ev,EPARA para){
	unsigned tID;
	EVENTINFO *ei=new EVENTINFO(ev,para);
	_beginthreadex(NULL,0,evthread,ei,0,&tID);
}//�첽(����) 

void dbind(EVENT ev,EFUNC fun){
	events[ev].push(fun);
}
void bind(EVENT ev,EFUNC fun){
	dbind(ev,fun);
}

#endif
