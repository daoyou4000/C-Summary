## 回调函数
在介绍回调函数时首先要介绍两个概念 **函数指针** 和 **指针函数**
函数指针是函数的指针，意思是指向函数的指针意思是使用该地址即会调用函数。
指针函数是使用函数时会返回指针。

回调函数其实是通过函数指针调用函数。假如把A函数的指针当做参数穿给B函数，然后B函数通过A函数传进来的这个指针调用A，那么这就是回调机制，
A函数就是回调函数。

### 回调函数定义


````
// 可以声明在结构体里面
typedef struct
{
	int status;
	// it is able to register any call back function with multiple arguement.
	void (*statusChange)();

}T_Device;

````
也可以使用typedef 进行声明
````

// declare a call back function without arguement.
typedef int (*p_callBackFunc)();
// declare a call back function 1 arguement.
typedef int (*p_callBackFunc_1)(char * num);

// declare a call back function 2 arguement.
typedef int (*p_callBackFunc_2)(int num_1, int num_2);
````

如何注册或者调用回调函数，注册回调函数其实是获取函数指针的过程。
````
void v_RegisterCallBack(void(*pStatusChange)(int status))
{
	g_Device.statusChange = pStatusChange;
}

// another is way is use the address directly
g_Device.statusChange = &callBack();

// make the function pointer as the arguement

int play(p_callBackFunc_1 fn, char * name)
{
	return fn(name);
}

````
