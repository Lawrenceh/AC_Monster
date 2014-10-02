// itoa
int aa = 30;
char c[8];
itoa(aa, c, 16);
cout << c << endl; // 1e

// sprintf
int aa = 30;
char c[8];
int l = sprintf(c, "%05X", aa);
cout << c << endl; // 0001E

// stringstream
int aa = 30;
stringstream ss;
ss << aa;
string s;
ss >> s;
cout << s << endl;

// boost/lexical_cast
int aa = 30;
string s = boost::lexical_cast<string>(aa);
cout << s << endl; // 30

/***************************************************/

// strtol
string s = "17";
char *end;
int i = static_cast<int>(strtol(s.c_str(), &end, 16));
cout << i << endl; // 23
int i = static_cast<int>(strtol(s.c_str(), &end, 10));
cout << i << endl; // 17

// sscanf
int i;
sscanf("17", "%D", &i);
cout << i << endl; // 17
sscanf("17", "%X", &i);
cout << i << endl; // 23
sscanf("0x17", "%X", &i);
cout << i << endl; // 23

// stringstream
// as above

// lexical_cast
// as above

