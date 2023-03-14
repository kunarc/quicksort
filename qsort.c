#include <stdio.h>
int cmp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;//这里以int 类型为例
}
void my_swap(char*a,char*b,int size){
	while (size--) {//共有size个字节
		*a ^= *a ^ *b;
		*b ^= *b ^ *a;//通过异或运算来交换每个字节的数据
		*a ^= *a ^ *b;
		a++;  //到下一个字节进行交换
		b++;
	}
}
void my_qsort(void* base, int len, int size, int(*cmp)(const void*, const void*)) {//对于未知指针都用void*来接收
	int i = 0; int j = 0;
	int flag = 0;//用来标记该数组是否原本为有序的
	for (i = 0; i < len - 1; i++) {
		for (j = 0; j < len - 1 - i; j++) {
			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size)) {//因为不知道传入的指针是什么类型的所以将其转化为char*类型的指针，将其步长控制为1。
				flag = 1;//无序
				my_swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
			}
		}
		if (flag == 0) {//有序则直接跳出循环 无须排序
			break;
		}
	}
}