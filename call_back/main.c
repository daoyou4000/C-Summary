#include<stdio.h>
#include<stdlib.h>

// declare a call back function without arguement.
typedef int (*p_callBackFunc)();
// declare a call back function 1 arguement.
typedef int (*p_callBackFunc_1)(char * num);

// declare a call back function 2 arguement.
typedef int (*p_callBackFunc_2)(int num_1, int num_2);

int i_playBegin(char* name)
{
	printf("the video starts playing .....\n");
	return 1;
}

int i_playEnd(char* name)
{
	printf("the video ends playing..............\n");
	return 1;
}

int play(p_callBackFunc_1 fn, char* name)
{
	return fn(name);
}

typedef struct
{
	int status;
	// it is able to register any call back function with multiple arguement.
	void (*statusChange)();

}T_Device;


T_Device g_Device;

void addCallBack(void(*pstatusChange)(int status))
{
	g_Device.statusChange = pstatusChange;
}


int getStatus()
{
	return g_Device.status;
}

void callBack(int status)
{
	printf("callback\n");
	printf("status = %d \n", status);
}

void callback_1(int status_1, int status_2)
{
	printf("this is call back 1\n");

	printf("status 1 = %d \n", status_1);
	printf("status 2 = %d \n", 0);
}

void run()
{
	g_Device.status = 10;
	if (g_Device.status == 10)
	{
		if (g_Device.status != NULL)
		{
			g_Device.statusChange(g_Device.status);
		}
	}

}

int main()
{
	char pName[1020] = "sejishikong";
	
	//1,  register the call back function
	addCallBack(callBack);
	// enable the call back function 
	run();

	//2,  another way to register the call back function
	g_Device.statusChange = &callback_1;
	// enable the call back function 
	g_Device.statusChange(g_Device.status, g_Device.status);

	//3, 3rd way to use the call back function
	play(i_playBegin, pName);
	play(i_playEnd,pName);

	return 1;
}