#include<stdio.h>
#include <windows.h>
struct st{
	int num;          //для определения порядка вывода
	int long1;        //длина строк
	char* massofchar; //строка
};
typedef struct st string;
void Sort(string* str, int size){
	int max = 0;
	for (int i = 0; i < size; i++) {
		if (str[i].long1 > max) {
			max = str[i].long1;
		}
	}
	int k = 0;
	for (int j = 0; j <= max; j++) {
	    for (int i = 0; i < size; i++) {
			if (str[i].long1 == j) {
				str[i].num = k;
				k++;
			}
		}
	}
	return;
}
int main() {
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	FILE* A;
	fopen_s(&A, "book.txt", "r");
	int c,n=0;
	c = getc(A);
	while (c!=-1) {
		if (c == 10) {
			n++;
		}
		c = getc(A);
	}
	string* str;
	str = (string*)malloc(sizeof(string)*(n+1));
	fseek(A,SEEK_SET, SEEK_SET);
	c = getc(A);
	for (int i = 0; i < (n + 1); i++) {
		int k = 0;
		while ((c != 10)&&(c!=-1)) {
			k++;
			c = getc(A);
		}
		c = getc(A);
		str[i].long1 = k;
		str[i].massofchar = (char*)malloc(sizeof(char) * (k+1));
	}
	fseek(A, SEEK_SET, SEEK_SET);
	c = getc(A);
	for (int i = 0; i < (n + 1); i++) {
		int k = 0;
		while ((c != 10)&&(c!=-1)) {
			str[i].massofchar[k] = c;
			c = getc(A);
			k++;
		}
		str[i].massofchar[k] = '\0';
		c = getc(A);
	}
	fclose(A);
    Sort(str, n+1);
	for (int i = 0; i < n+1; i++) {
		for (int j = 0; j < n+1; j++) {
			if (str[j].num==i) {
				for (int k = 0; k < str[j].long1; k++) {
					printf("%c", str[j].massofchar[k]);
				}
				printf("\n");
			}
		}
	}
	for (int i = 0; i < n + 1; i++) {
		free(str[i].massofchar);
	}
	free(str);
	return 0;
}