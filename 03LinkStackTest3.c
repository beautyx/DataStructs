#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "LinkStack.h "




/*

  模仿编译器完成计算后缀表达式的结果.
  算法简单描述:
  从左只有扫描表达式字符串,如果是数字则入栈;如果是运算符则依次弹出右操作数和左操作数,计算结果后再入栈;
  直到遍历完毕栈中唯一的一个元素即为结果

*/

int isDigit(const char ch){


	return (ch >= '0') && (ch <= '9');

}

int isOperate(const char ch){

	return (ch == '+') || (ch == '-')||(ch == '*') || (ch == '/');

}

int express(int left, int right, char op){

	int ret = 0;

	switch (op)
	{
	case '+':
		
		ret = left + right;
		break;
	case '-':

		ret = left - right ;
		break;
	case '*':
	
		ret = left * right;
		break;
	case '/':
	
		ret = left / right;
		break;
	default:
		break;
	}

	return ret;
}

int value(char ch)
{

	return (ch - '0');
}



int  computer(const char *exp){
	
	int i = 0,res,num;

	LinkStack *stack = LinkStackCreate();

	while ( exp[i] != '\0')
	{
		
		if (isDigit(exp[i]))
		{
			//把char转换成int入栈便于计算结果
			num = value(exp[i]);

			linkStackPush(stack,(void *)num);
			if (LinkStackSize(stack) > 0)
			{
				int temp = (int)LinkStackTop(stack);

			}
		}
		else if (isOperate(exp[i]))
		{

			int right = (int)LinkStackPop(stack);
			int left = (int)LinkStackPop(stack);

			res = express(left, right, exp[i]);
			linkStackPush(stack, (void *)res);


		}
		else{
		
			printf("Invalid expression.\n");
			break;
		}

		i++;
	}
	
	if (LinkStackSize(stack) != 1 || exp[i] != '\0')
	{
		printf("Invalid expression.\n");
		return -1;
	}

	res = (int )LinkStackPop(stack);

	LinkStackDestroy(stack);

	return res;

}

int main(){


	int result = computer("831-5*+");

	printf("8+(3-1)*5 = %d\n",result);

	system("pause");  
	return EXIT_SUCCESS;
}
