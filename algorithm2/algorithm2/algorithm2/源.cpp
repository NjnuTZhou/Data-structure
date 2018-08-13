#include<stdio.h>
#include<stdlib.h>
//有序线性链表的合并
struct node {
	int data;
	struct node* next;
};

int main() {

	struct node* head1 = (struct node*)malloc(sizeof(struct node));
	head1->next = NULL;
	for (int i = 0; i < 10; i++) {
		struct node *a = (struct node*)malloc(sizeof(struct node));
		a->data = 9-i;
		a->next = head1->next;
		head1->next = a;
		
	}

	struct node* head2 = (struct node*)malloc(sizeof(struct node));
	head2->next = NULL;
	for (int i = 0; i < 6; i++) {
		struct node* b = (struct node *)malloc(sizeof(struct node));
		b->data = 11 - i;
		b->next = head2->next;
		head2->next = b;
	}

	struct node*p1 = head1->next;
	struct node*p2 = head2->next;

	while (p1) {
		printf("%d,", p1->data);
		p1 = p1->next;
	}
	printf("\n");
	while (p2) {
		printf("%d,", p2->data);
		p2 = p2->next;
	}
	printf("\n");
	p1 = head1->next;
	p2 = head2->next;

	struct node* head3= (struct node *)malloc(sizeof(struct node));
	struct node* p3 = (struct node *)malloc(sizeof(struct node));
	p3->next = NULL;
	head3 = p3;
	while (p1&&p2) {
		if (p1->data <= p2->data) {
			p3->next = p1;
			p1 = p1->next;
		}
		else if(p1->data>p2->data) {
			p3->next = p2;
			p2 = p2->next;
		}
		p3 = p3->next;
	}
	if (!p1) {
		while (p2) {
			p3->next = p2;
			p2 = p2->next;
			p3 = p3->next;
		}
	}
	else if (!p2) {
		while (p1) {
			p3->next = p1;
			p1 = p1->next;
			p3 = p3->next;
		}
	}
	p3 = head3->next;
	while (p3) {
		printf("%d,", p3->data);
		p3 = p3->next;
	}
	return 0;
}