#include <stdio.h>
#include <stdlib.h>
/*
	栈的应用
*/
typedef struct {
	char arr[20];
	int top;
}StackNum;
void t1();
int t2(int i);
void  t3(char arr[],char t[]);
void t4(char arr[]);
int main(){
	//t1();
	//int i;
	//for (i = 1; i <= 40; i++){
	//	printf("%d\n", t2(i));
	//}

	char arr[20] ;
	scanf_s("%s", arr, 20);
	char t[20] ; 
	t3(arr,t);
	printf("%s\n", t);
	t4(t);
	
	return 0;
}

void t1(){
	/*雯波那锲数列的数组实现*/
	int arr[40];
	arr[0] = 1;
	arr[1] = 1;
	int i;
	for (i = 2; i < 40; i++){
		arr[i] = arr[i - 1] + arr[i - 2];
		printf("%d\n", arr[i]);
	}
}

int t2(int i){
	/*雯波那锲数列的递归实现*/
	if (i < 2){
		return i == 0 ? 0 : 1;
	}

	return  t2(i - 1)+t2(i-2);
}

void t3(char arr[],char t[]){
	/*利用栈将中缀表达式变为后缀表达式输出*/
	StackNum s = { { 0 }, -1 };

	int i = 0;
	int j = 0;
	while (arr[i] != '\0'){
		if (arr[i] >= '0'&&arr[i] <= '9'){
			//printf("%c ", arr[i]);
			t[j++] = arr[i];
		}
		else if (s.top == -1){
			s.arr[++s.top] = arr[i];
		}
		else if (arr[i] == 43 || arr[i] == 45){
			if (s.arr[s.top] == 42 || s.arr[s.top] == 47){
				while (s.top != -1)
				{
					//printf("%c ", s.arr[s.top--]);
					t[j++] = s.arr[s.top--];
				}
				s.arr[++s.top] = arr[i];
			}
			else{
				s.arr[++s.top] = arr[i];
			}
		}
		else if (arr[i] == 41)
		{
			while (s.arr[s.top] != 40)
			{
				//printf("%c ", s.arr[s.top--]);
				t[j++] = s.arr[s.top--];
			}

			s.top--;
		}
		else{
			s.arr[++s.top] = arr[i];
		}
		i++;
	}

	while (s.top != -1){
		//printf("%c ", s.arr[s.top--]);
		t[j++] = s.arr[s.top--];
	}
	t[j] = '\0';
}
float s(char c){
	/*传入字符返回数字*/
	float i = -1;
	switch (c)
	{
	case 48: i = 0; break;
	case 49: i = 1; break;
	case 50: i = 2; break;
	case 51: i = 3; break;
	case 52: i = 4; break;
	case 53: i = 5; break;
	case 54: i = 6; break;
	case 55: i = 7; break;
	case 56: i = 8; break;
	case 57: i = 9; break;
	default:
		break;
	}
	return i;
}

typedef struct{
	float data[20];
	int top;
}Stack02;
void t4(char arr[]){
	/*通过后缀表达式计算结果*/
	Stack02 Sta = { { 0 }, -1 };

	int i = 0;
	float  t,k,l;
	while (arr[i]!='\0')
	{
		t = s(arr[i]);
		if (t != -1){
			Sta.data[++Sta.top] = t;
		}
		else{
			switch (arr[i])
			{
			case 42:
				k = Sta.data[Sta.top--];
				l = Sta.data[Sta.top--];
				Sta.data[++Sta.top] = k*l;
				break;
			case 43:
				k = Sta.data[Sta.top--];
				l = Sta.data[Sta.top--];
				Sta.data[++Sta.top] = k + l;
				break;
			case 45:
				k = Sta.data[Sta.top--];
				l = Sta.data[Sta.top--];
				Sta.data[++Sta.top] = l - k;
				break;
			case 47:
				k = Sta.data[Sta.top--];
				l = Sta.data[Sta.top--];
				Sta.data[++Sta.top] = l / k;
				break;
			default:
				break;
			}
		}
		i++;
	}
	printf("%0.2f\n", Sta.data[Sta.top--]);
}