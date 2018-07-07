#include <stdio.h>
#include <stdlib.h>

#define SIZE 	5

typedef struct Table {
	int *head;
	int length;
	int size;//unit:(int)
} table;

table initTable();
void showTable(table t);
table addElement(table t, int location, int element);
table removeElement(table t, int location);
table amendTable(table t, int element, int new_element);
int findElement(table t, int element);

int main(){
	int i;
    table t1=initTable();
    for (i=0; i<SIZE; i++) {
        t1.head[i]=i+1;
        t1.length++;
    }
    printf("原顺序表：\n");
    showTable(t1);
   
    printf("删除元素1:\n");
    t1=removeElement(t1, 1);
    showTable(t1);
   
    printf("在第2个位置插入元素5:\n");
    t1=addElement(t1, 2, 5);
    showTable(t1);
   
    printf("查找元素3的位置:\n");
    int add=findElement(t1, 3);
    printf("%d\n",add);
   
    printf("将元素3改为6:\n");
    t1=amendTable(t1, 3, 6);
    showTable(t1);
    
    return 0;
}

table initTable() 
{
	table t;
	t.head = (int*)malloc(SIZE*sizeof(int));
	if(!t.head) {
		printf("Failed malloc!\n");
		exit(0);
	}
	t.length = 0;
	t.size = SIZE;

	return t;
}

void showTable(table t)
{
	int i;

	for(i=0; i<t.length; i++) {
		printf("[%d] = %d\n", i+1, t.head[i]);
	}
}

table addElement(table t, int location, int element) 
{
	int i;

	if(location<1 || location>t.length+1) {
		printf("Error add location!\n");
		return t;
	}

	if(t.length == t.size) {
		t.head = (int*)realloc(t.head, t.size+1);
		if(!t.head) {
			printf("Failed realloc!\n");
			return t;
		}
		t.size++;
	}

	for(i=t.length; i>location-1; i--) {
		// printf(" i = %d\n", i);
		t.head[i] = t.head[i-1];
	}

	t.head[location-1] = element;
	t.length++;

	return t;
}

table removeElement(table t, int location)
{
	int i;

	if(location<1 || location>t.length) {
		printf("Error remove location!\n");
		return t;
	}

	for(i=location-1; i<t.length; i++) {
		t.head[i] = t.head[i+1];
	}

	t.length--;

	return t;
}

table amendTable(table t, int element, int new_element)
{
	int location = findElement(t, element);
	t.head[location-1] = new_element;

	return t;
}

int findElement(table t, int element)
{
	int location;
	int i;

	for(i=0; i<t.length; i++) {
		if(t.head[i] == element) {
			location = i+1;
			break;
		}
	}
	
	return location;
}