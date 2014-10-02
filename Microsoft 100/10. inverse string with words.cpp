#include<iostream>
#include<vector>
#include<assert.h>
#include<cstring>
using namespace std;
 
void swap(char &a, char &b) {
    char tmp = b;
    b = a;
    a = tmp;
}
 
void swap_str(char* str, int start, int end) {
    assert(str!=NULL && start <= end);
    int low = start;
    int high = end;
    while (low < high)     {
        swap(str[low], str[high]);
        low++;
        high--;
    }
}
 
void reverse_word(char str[]) {
    int len = strlen(str);
 
    swap_str(str, 0, len-1);
 
    int s = 0;
    int e = 0;
    for (int i=0; i<len; i++)     {
        e = i;
        if (str[e] == ' ')         {
            swap_str(str, s, e-1);
            s = e + 1;
        }
    }
}
 
int main() {
    char str[] = "I am a student.";
    reverse_word(str);
    cout<<str<<endl;
    return 0;
}
