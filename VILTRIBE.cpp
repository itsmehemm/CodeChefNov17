/*
	@author: hemant_123
*/

#include<iostream>
using namespace std;
typedef long long int ll;
typedef long int l;
typedef unsigned long long int ull;

#ifdef _WIN32
#define gx getchar
#define px putchar
#define ps putchar(' ')
#define pn putchar('\n')
#define DEBUG 1
#else
#define gx getchar_unlocked
#define px putchar_unlocked
#define ps putchar_unlocked(' ')
#define pn putchar_unlocked('\n')
#define DEBUG 0
#endif

/* Read an integer */
void readint(int &n)
{
	int sign = 1;
	n = 0;
	char c = gx();
	while (c < '0' || c > '9')
	{
		if (c == '-') sign = -1;
		c = gx();
	}
	while (c >= '0' && c <= '9') n = (n << 3) + (n << 1) + c - '0', c = gx();  n = n * sign;
}

/* Read a long int */
void readl(l &n)
{
	int sign = 1;
	n = 0;
	char c = gx();
	while (c < '0' || c > '9')
	{
		if (c == '-')
			sign = -1;
		c = gx();
	}
	while (c >= '0' && c <= '9') n = (n << 3) + (n << 1) + c - '0', c = gx();  n = n * (l)(sign);
}
/* Read a long long int */
void readll(ll &n)
{
	int sign = 1;
	n = 0;
	char c = gx();
	while (c < '0' || c > '9')
	{
		if (c == '-')
			sign = -1;
		c = gx();
	}
	while (c >= '0' && c <= '9') n = (n << 3) + (n << 1) + c - '0', c = gx();  n = n * (ll)(sign);
}

/* Read a complete line */
int readline(char a[])
{
	char c = gx();
	while (c == ' ' || c == '\n') c = gx();
	int i = 0;
	while (c != '\n')a[i++] = c, c = gx();
	a[i] = 0;
	return i;
}

/* Read a single word */
int readstr(char a[])
{
	char c = gx();
	while (c == ' ' || c == '\n') c = gx();
	int i = 0;
	while (c != EOF && c != '\n' && c != ' ')a[i++] = c, c = gx();
	a[i] = 0;
	return i;
}

/* print an integer */
void writeint(int n)
{
	if (n<0)
	{
		n = -n;
		px('-');
	}
	int i = 10;
	char o[10];
	do { o[--i] = (n % 10) + '0'; n /= 10; } while (n);
	do { px(o[i]); } while (++i<10);
}

/* print long long int */
void writell(ll n)
{
	if (n<0LL)
	{
		n = -n;
		px('-');
	}
	int i = 21;
	char o[21];
	do { o[--i] = (n % 10LL) + '0'; n /= 10LL; } while (n);
	do { px(o[i]); } while (++i<21);
}

/* print string and line */
void writestr(const char a[])
{
	const char *p = a;
	while (*p)px(*p++);
}

/* program execution starts here */
int main()
{
	int t;
    readint(t);
    while (t--) {
        string s;
        char pre = '0';
        int count_A = 0;
        int count_B = 0;
        bool checker = false;
        int haunted = 0;
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '.') {
                checker = true;
                haunted += 1;
                continue;
            }
            if (checker && pre == s[i]) {
                if (pre == 'A') count_A += haunted;
                else count_B += haunted;
            }
            if (s[i] == 'A') {
                count_A += 1;
                pre = 'A';
                checker = false;
                haunted = 0;
                continue;
            }
            if (s[i] == 'B') {
                count_B += 1;
                pre = 'B';
                checker = false;
                haunted = 0;
                continue;
            }
        }
        writeint(count_A), ps, writeint(count_B), pn;
    }
	return 0;
}
