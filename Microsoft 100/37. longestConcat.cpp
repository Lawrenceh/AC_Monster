#include<iostream>
#include<string>
using namespace std;

#define length 14

bool Isconnect(string str1,string str2) {
	if(str1.size()!=str2.size()) return false;
	int m=str1.size();
	for(int i=0;i<m-1;i++) {
		if(str1[i+1]!=str2[i])
			return false;
	}
	return true;
}

void Maxstring(string str[]) {
	int G[length][length]={0};

	for(int i=0;i<length;i++)
		for(int j=0;j<length;j++)
			if(Isconnect(str[i],str[j]))
				G[i][j]=1;

	for(int k=0;k<length;k++)
		for(int j=0;j<length;j++)
			for(int i=0;i<length;i++) {
				if(G[i][k]!=0&&G[k][j]!=0) {
					int dis=G[i][k]+G[k][j];
					if(dis>G[i][j]) G[i][j]=dis;
				}
			}

	for(int i=0;i<length;i++)
		if(G[i][i]>1) {
			cout<<"circle is deteted"<<endl;
			return;
		}

	int max=0;
	for(int i=0;i<length;i++)
		for(int j=0;j<length;j++) {
			if(G[i][j]>max)
				max=G[i][j];
		}
		cout<<"Max length is "<<max+str[0].size()<<endl;
}

int main() {
	string str[length]={
        "abcd",
		"bcde",
		"cdea",
		"deab",
		"eaba",
		"abab",
		"deac",
		"cdei",
		"bcdf",
		"cdfi",
		"dfic",
		"cdfk",
		"bcdg",
		"babc"};
		Maxstring(str);
}
