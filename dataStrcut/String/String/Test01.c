#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
typedef int Status;
#define MAXSIZE 20

/*
	基于字符数组实现的字符串
*/
typedef char String[MAXSIZE];

Status  StrAssign(String str, char* s);
int StrLenght(String str);
Status StrCopy(String str, String t);
int StrCompare(String str, String s2);
Status Conact(String str, String s1, String s2);
Status SubString(String str, String s, int pos, int len);
int Index(String str, String s, int pos);
int Test01(){
//	char s[] = "read";
//	String str ="ack";
//	StrAssign(str, s);

//	String s2 ="ouid";
//	int i = StrCopy(s2, str);
//	printf("%s\n", s2);
	//printf("%d\n", i);

//	printf("%d\n", StrCompare(str,s2));

	//String s3 = "";
	//int i = Conact(s3, str, s2);
	//printf("%s\n", s3);
	//printf("%d\n", i);

	/*String str = "Chinese";
	String s = "";
	int i = SubString(str, s, 5, 3);
	printf("%s\n", s);
	printf("%d\n", i);*/

	String str = "doyoulikemeof";
	String s = "like";
	int i = Index(str, s, 1);
	printf("%d\n", i);
	return 0;
}
Status  StrAssign(String str, char* s){
	if (StrLenght(s) > MAXSIZE)return ERROR;
	int i = 0;
	while (s[i] != '\0'){
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return OK;
}
Status StrCopy(String str, String t){
	//若串t 存在 由t则复制串str
	int i = 0;
	if ( StrLenght(t) > MAXSIZE)return ERROR;
	while (t[i] != '\0' && !(i>MAXSIZE - 2)){
		str[i] = t[i];
		i++;
	}
	str[i] = '\0';
	return OK;
}
int StrLenght(String str){
	int i = 0;
	while (str[i] != '\0'){
		i++;
	}
	return i;
}
int StrCompare(String str, String s2){
	int i,x=0;
	if (StrLenght(str) < StrLenght(s2)){
		for (i = 0; i < StrLenght(str); i++){
			if (str[i]>s2[i]){
				x = 1;
				break;
			}
		}
		if (x == 0)x = -1;
	}else if (StrLenght(str) > StrLenght(s2)){
		for (i = 0; i < StrLenght(s2); i++){
			if (s2[i]>str[i]){
				x = -1;
				break;
			}
		}
		if (x == 0)x = 1;
	}else{
		for (i = 0; i < StrLenght(s2); i++){
			if (s2[i]>str[i]){
				x = -1;
				break;
			}
			if (s2[i]<str[i]){
				x = 1;
				break;
			}
		}
	}
	return x;
}
Status Conact(String str, String s1, String s2){
	int x = StrLenght(s1);
	int y = StrLenght(s2);
	if (( x + y ) > MAXSIZE - 1)return ERROR;

	int i,j;
	for (i = 0; i < x; i++){
		str[i] = s1[i];
	}
	for (j = 0; j < y; j++){
		str[i++] = s2[j];
	}
	str[i] = '\0';
	return OK;

}
Status SubString(String str,String s, int pos, int len){
	if (str[0] == '\0' || StrLenght(str)>MAXSIZE - 1)return ERROR;
	int i;
	int j = pos-1;
	for (i = 0; i < len; i++){
		s[i] = str[j++];
	}
	s[i] = '\0';
	return OK;

}
int Index(String str, String s, int pos){
	int n, m, i;
	String sub;

	if (pos > 0){
		n = StrLenght(str);
		m = StrLenght(s);
		i = pos;
		while (i <= n - m + 1){
			SubString(str,sub, i, m);

			if (StrCompare(sub, s) != 0){
				++i;
			}else{
				return i;
			}
		}
	}
	return 0;

		    	
}
