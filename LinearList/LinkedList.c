#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SIZE 	5

typedef struct Link {
	int element;
	struct Link *next;
} link;

link *initLink();
void showLink(link *head);
void showNode(link *node);
link *addElement(link *head, int location, int element);
link *removeElement(link *head, int element);
link *amendLink(link *head, int element, int new_element);
link *findLastNode(link *head, int element);

int main()
{
	link *ret;
	link *mylink = initLink();
	showLink(mylink);

	printf("addElement 11@3\n");
	ret = addElement(mylink, 3, 11);
	showLink(mylink);

	printf("findLastNode 3:\n");
	ret = findLastNode(mylink, 3);
	showNode(ret);

	printf("removeElement 5\n");
	ret = removeElement(mylink, 5);
	showLink(mylink);

	printf("amendLink 11->6\n");
	ret = amendLink(mylink, 11, 6);
	showLink(mylink);

	return 0;
}

link* initLink()
{
	int i;
	link *head = (link *)malloc(sizeof(link));
	link *temp = head;

	for(i=1; i<=5; i++)
	{
		link *node = (link *)malloc(sizeof(link));
		node->element = i;
		node->next = NULL;
		temp->next = node;
		temp = node;
	}

	return head;
}

void showLink(link *head)
{
	link *temp_node = head;

	while(temp_node->next) {
		printf("%d\n", temp_node->next->element);
		temp_node = temp_node->next;
	}
}

void showNode(link *node)
{
	printf("%d\n", node->element);
}

link* addElement(link *head, int location, int element)
{
	link *node, *new_node;
	int i;

	node = head;
	for(i=0; i<location-1; i++) {
		node = node->next;
	}
	
	new_node = (link *)malloc(sizeof(link));
	new_node->element = element;
	new_node->next = node->next;

	node->next = new_node;

	return head;
}

link* removeElement(link *head, int element)
{
	link *last_node = findLastNode(head, element);
	link *node = last_node->next;
	last_node->next = node->next;
	free(node);

	return head;
}

link* amendLink(link *head, int element, int new_element)
{
	link *node = findLastNode(head, element)->next;
	node->element = new_element;

	return head;
}

link* findLastNode(link *head, int element)
{
	link *temp_node = head;

	while(temp_node->next) {
		if(temp_node->next->element == element)
			break;
		temp_node = temp_node->next;
	}

	return temp_node;
}