#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "LinkStack.h"


int isLeft(char c){

	int ret = 0;

	switch (c){
	
		case '<':
		case '(':
		case '[':
		case '{':
		case '\'':
		case '\"':
			ret = 1;
			break;
		default:
			ret = 0;
			break;

	}

	return ret;

}

int isRight(char c){

	int ret = 0;

	switch (c){

	case '>':
	case ')':
	case ']':
	case '}':
	case '\'':
	case '\"':
		ret = 1;
		break;
	default:
		ret = 0;
		break;

	}

	return ret;

}

int match(char left, char right){

	int ret = 0;

	switch (left){
	
	case '<':
		ret = (right == '>');
		break;

	case '(':
		ret = (right == ')');
		break;

	case '[':
		ret = (right == ']');
		break;

	case '{':
		ret = (right == '}');
		break;

	case '\'':
		ret = (right == '\'');
		break;

	case '\"':
		ret = (right == '\"');
		break;
	}

}

void scanner(const char *code){

	LinkStack *stack = LinkStackCreate();
	int ret = 0, i = 0;

	while (code[i] != '\0')
	{
		//1.从左至右遍历字符串数组,如果是左字符则入栈
		if (isLeft(code[i]))
		{
			linkStackPush(stack, (void *)&code[i]);
		}
		//2.如果是右字符则pop出栈顶元素与右字符比较,如果匹配则栈空继续遍历下一个字符,如果不匹配则报错
		if (isRight(code[i]))
		{
			char *c = LinkStackPop(stack);

			if ((c == NULL) || !match(*c,code[i]))
			{
				printf(" code[%d] = %c does not match!\n",i,code[i]);
				ret = 0;
				break;
			}
		}
		i++;

	}
	//3.遍历完成所有字符后,如果栈空则匹配成功,否则失败
	if (LinkStackSize(stack) == 0 && (code[i] == '\0'))
	{
		printf("Succeed!\n");
		ret = 1;
	}
	else {
		
		printf("Invalid code!\n");

		printf("size = %d\n",LinkStackSize(stack));
		
		if (LinkStackSize(stack) >0)
		{
			char top = *(char *)LinkStackTop(stack);
			printf("top = %c\n", top);
		}


		while (LinkStackSize(stack))
		{
			char temp = *(char *)LinkStackPop(stack);
			printf("temp = %c\n",temp );
		}


		ret = 0;
	
	}

	LinkStackDestroy(stack);

	return ret;
}


int main(){

	//const char *code = "#include<stdio.h> int main(){ int a[4][4](;int (*p)[4];p=a[0];return 0;}";
	const char *code = "#in{<s.h> in(){r 0;}";

	scanner(code);
	
	system("pause");
	return EXIT_SUCCESS;
}
