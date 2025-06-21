#include<stdio.h>
#include<Windows.h>
#include <locale.h>  // ����localeͷ�ļ�
 
int main()
{
    setlocale(LC_ALL, "chs");  // ���ñ��ػ�֧��
    system("chcp 936");       // ���ÿ���̨����ҳΪ��������
    system(" color 0c");
	//printf("��������һ���ܿ��ĵ�����,����Ӵ������\n");//��ӡ���� 
	
	float x,y,a;//�������x,y,a 
	
	for(y=1.5f;y>-1;y-=0.1f)
	{
		for(x=-1.5f;x<1.5f;x+=.05f){
			a=x*x+y*y-1;
			putchar(a*a*a-x*x*y*y*y<0.0f?'x':' ');
		}
		Sleep(100);//ͣ�ٺ�����1���ӣ� 
		putchar('\n'); //���� 
	}
	putchar('\n'); //���� 
	printf("��������һ���ܿ��ĵ����飬����Ӵ������\n"); // ʹ�ñ�׼���ı��
	while(1){
		//����ֱ������س�
		if(getchar()=='\n'){
		break;	
		}
	}//��ѭ������ֹ����رգ����°�����ʧ
	return 0;
}
