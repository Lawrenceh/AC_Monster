/**************************
 *  pHead is not the common 'head' here. It's the first element in the linked list.
 * ***********************/
#include <iostream>
#include <cstdlib>
using namespace std;

int n, m;

typedef struct Node {
    int num;
    struct Node *next;
} myNode;

void initRing(myNode *pHead){
    myNode *p = NULL, *prev = NULL;
    prev = pHead;
    for (int i = 2; i <= n; i ++) {
        p = new myNode; 
        p->num = i;
        prev->next = p;
        prev = p;
    }
    prev->next = pHead;
}

void startRing(myNode *pHead) {
    int cnt = n;
    myNode *prev = new myNode, *p = new myNode;
    p->next = pHead;
    while (cnt != 1) {
        for (int i = 0; i < m; i ++) {
            prev = p;
            p = p->next;
        }
        prev->next = p->next;
        cout << p->num << " -> ";
        delete p;
        p = prev;
        cnt --;
    }
    cout << p->num << "\nThe last one is: " << p->num << endl;
}


int main() {
    cin >> n >> m;
    myNode *pHead = new myNode;
    pHead->num = 1;
    pHead->next = NULL;
    initRing(pHead);
    startRing(pHead);
    return 0;
}
