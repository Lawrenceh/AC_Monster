// Form a stack with progress

int check(int push[], int pop[], int n) {
    stack<int> s;
    int p1, p2;
    while (p2 < n) {
        while (s.empty() || s.top() != pop[p2]) {
            if (p1 < n) s.push(push[p1++]);
            else return 0;
            while (!s.empty() && s.top() == pop[p2]) {
                s.pop();
                p2 ++;
            }
        }
    }
    return 1;
}
