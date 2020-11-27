#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 20
typedef int Status;
typedef char String[MAXSIZE];


int t1(String s, String t, int pos);
int test02(){
	String s = " goodgooles";
	s[0] = 10;

	String s2 = " goole";
	s2[0] = 5;

	int i = t1(s, s2, 1);
	printf("%d\n", i);
	return 0;
}

int t1(String s,String t,int pos){
	/*
		数组实现index
	*/
	int i = pos;
	int j = 1;

	while (i <= s[0] && j <= t[0]){
		if (s[i] == t[j])
		{
			i++;
			j++;
		}
		else{
			i = i - j + 2;
			j = 1;
		}
	}
	if (j>t[0])
	{
		return i - t[0];
	}
	else{
		return 0;
	}
}

