## 回调函数
在介绍回调函数时首先要介绍两个概念 **函数指针** 和 **指针函数**
函数指针是函数的指针，意思是指向函数的指针意思是使用该地址即会调用函数。
指针函数是使用函数时会返回指针。

回调函数其实是通过函数指针调用函数。假如把A函数的指针当做参数穿给B函数，然后B函数通过A函数传进来的这个指针调用A，那么这就是回调机制，
A函数就是回调函数。

### 回调函数定义

´´´´
// 可以声明在结构体里面
typedef struct
{
	int status;
	// it is able to register any call back function with multiple arguement.
	void (*statusChange)();

}T_Device;
´´´´
