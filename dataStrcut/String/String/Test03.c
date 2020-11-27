#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 20
typedef int Status;
typedef char String[MAXSIZE];

void get_next(String T, int* next);
int Index_KMP(String S, String T, int pos);
void get_nextval(String T, int* next);
int main(){
	
	String s=" goodgooles";
	s[0] = 10;

	String s2 = " goole";
	s2[0] = 5;
	

	int i = Index_KMP(s,s2, 1);
	printf("%d\n", i);
	
	
	return 0;
}
int Index_KMP(String S, String T, int pos){
	int i = pos;
	int j = 1;
	
	int next[255];
	//get_next(T, next);
	get_nextval(T, next);

	while (i <= S[0] && j <= T[0]){
		if (j == 0 || S[i] == T[j]){
			//0 goodgooles   
			//0 0111123411
			//      goole
			++i;
			++j;
		}
		else{
			j = next[j];
		}
	}
	if (j > T[0]){
		return i - T[0];
	}
	else
		return 0;

}
void get_next(String T, int* next){
	int i = 1;
	int j = 0;
	next[1] = 0;
//	"0 aaaaax";
   //0 012345 
	while (i < T[0]){
		if (j == 0 || T[i] == T[j]){
			++i;
			++j;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
	//for (int i = 0; i < 10; i++){
	//	printf("%d	", next[i]);
	//}
	
}

void get_nextval(String T, int* next){
	/* KMP¸ÄÁ¼*/
	int i = 1;
	int j = 0;
	next[1] = 0;
//	"0 aaaaax";
//   0 000005 
	while (i < T[0]){
		if (j == 0 || T[i] == T[j]){
			++i;
			++j;
			if (T[i]!=T[j]){
				next[i] = j;
			}
			else
			{
				next[i] = next[j];
			}
		}
		else
		{
			j = next[j];
		}
	}
	//for (int i = 0; i < 10; i++){
	//	printf("%d	", next[i]);
	//}

}