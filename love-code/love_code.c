#include<stdio.h>
#include<Windows.h>
#include <locale.h>  // 新增locale头文件

int main()
{
    setlocale(LC_ALL, "chs");  // 设置本地化支持
    system("chcp 936");       // 设置控制台代码页为简体中文
    system(" color 0c");
	//printf("遇见你是一件很开心的事情,爱你哟！！！\n");//打印文字 
	
	float x,y,a;//定义变量x,y,a 
	
	for(y=1.5f;y>-1;y-=0.1f)
	{
		for(x=-1.5f;x<1.5f;x+=.05f){
			a=x*x+y*y-1;
			putchar(a*a*a-x*x*y*y*y<0.0f?'x':' ');
		} 
		
		Sleep(100);//停顿函数（1.5秒钟） 
		putchar('\n'); //换行 
	}
	putchar('\n'); //换行 
	printf("遇见你是一件很开心的事情，爱你哟！！！\n"); // 使用标准中文标点
	while(1){
		//死等直到输入回车
		if(getchar()=='\n'){
		break;	
		}
	}//死循环，防止程序关闭，导致爱心消失
	return 0;
}
