// 扫描交换：依次比较每一对相邻元素，如有必要，交换之。若整趟扫描都没有进行交换，则排序完成；否则，再做一趟扫描交换

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *x, int *y){
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void bubbleSort(int A[], int n){
	for(bool sorted=false; sorted=!sorted;n--){ // 逐趟扫描交换，直至完全有序
		for(int i=1; i<n; i++){ //自左向右，逐对检查A[0, n)内各项元素
			if(A[i-1] > A[i]){ //若逆序，则
				swap(&(A[i-1]), &(A[i])); //令其互换，同时
				sorted = false; //清除全局有序标志。若想退出最外层for，则上一次循环中该行不能执行，也就是sorted还是true
			}
		}

	}
}

int main()
{
	int A[5] = {10, 20, 23, 12, 1};
	bubbleSort(A, 5);
	for(int i=0; i<4; i++){
		printf("%d, ", A[i]);
	}
	printf("%d\n", A[4]);
	return 0;
}