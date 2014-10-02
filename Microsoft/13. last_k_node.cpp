// go n - k steps first and then go k steps
// use two cursors
struct Node {
    int key;
    Node *next;
}

Node *lastK(Node *head, int k) {
    if (k < 0) error("K < 0");
    Node *p = head, *q = head;
    while (k > 0) {
        if (p->next != NULL) p = p->next;
        else return NULL;
        -- k;
    }
    while (p->next != NULL) {
        q = q->next;
        p = p->next
    }
    return q;
}
