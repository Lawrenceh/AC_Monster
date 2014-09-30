#include <stdio.h>

typedef struct Node {
    int val;
	Node *next;
} Node, *pNode;


bool isLoop(pNode pHead) {
	pNode fast = pHead;
	pNode slow = pHead;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) {
			break;
		}
	}

	if (fast == NULL || fast->next == NULL)
		return false;
	else
		return true;
}

int loopLength(pNode pHead) {
	if (isLoop(pHead) == false)
		return 0;
	pNode fast = pHead;
	pNode slow = pHead;
	int length = 0;
	bool begin = false;
	bool agian = false;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow && agian == true)
			break;
		if (fast == slow && agian == false) {			
			begin = true;
			agian = true;
		}
		if(begin == true)
			++length;
	}
	return length;
}

Node* findLoopEntrance(pNode pHead) {
	pNode fast = pHead;
	pNode slow = pHead;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) {
			break;
		}
	}
	if (fast == NULL || fast->next == NULL)
		return NULL;
	slow = pHead;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
