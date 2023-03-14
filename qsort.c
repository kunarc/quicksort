#include <stdio.h>
int cmp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;//������int ����Ϊ��
}
void my_swap(char*a,char*b,int size){
	while (size--) {//����size���ֽ�
		*a ^= *a ^ *b;
		*b ^= *b ^ *a;//ͨ���������������ÿ���ֽڵ�����
		*a ^= *a ^ *b;
		a++;  //����һ���ֽڽ��н���
		b++;
	}
}
void my_qsort(void* base, int len, int size, int(*cmp)(const void*, const void*)) {//����δָ֪�붼��void*������
	int i = 0; int j = 0;
	int flag = 0;//������Ǹ������Ƿ�ԭ��Ϊ�����
	for (i = 0; i < len - 1; i++) {
		for (j = 0; j < len - 1 - i; j++) {
			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size)) {//��Ϊ��֪�������ָ����ʲô���͵����Խ���ת��Ϊchar*���͵�ָ�룬���䲽������Ϊ1��
				flag = 1;//����
				my_swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
			}
		}
		if (flag == 0) {//������ֱ������ѭ�� ��������
			break;
		}
	}
}