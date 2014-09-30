// method 1
int solve(int n)
{
    int i = 1;
    (n > 1) && (i = solve(n - 1) + n);
    return i;
}

// method 2
// static variable with initial value 1
class B {
    private:
        static int cnt;
};

int sum = 0;
int B::cnt = 1;

B : B() {
    sum += cnt;
    cnt ++;
}

void init(int n) {
    B b[n];
}

// method 3
// poly + !!
class A;
A* a[2];

class A {
    public:
        virtual int Sum(int n) { return 0;}
};

class B : public A {
    public:
        virtual int Sum(int n) { return a[!!n]->Sum(n-1) + n;}
};

int sol(int n) {
    A a;
    B b;
    a[0] = &a;
    a[1] = &b;

    int value = a[1]->sum(n);
    return value;
}
