typedef struct Node {
    int data;
    Node *next;
}

void inverseList(Node *head) {
    if (head == NULL || head -> next == NULL) return;
    Node *cur, next, pre;
    pre = head;
    cur = head->next;

    while (cur->next != NULL) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    cur->next = pre;

}
