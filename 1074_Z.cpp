#include <iostream>

using namespace std;

int N;

int func(int n, int r, int c)
{
	if (n == 0) return 0;

	int half = 1 << (n-1);

	//1
	if (r < half && c < half) return func(n - 1, r, c);
	//2
	if (r < half && c >= half) return half * half + func(n - 1, r, c - half);
	//3
	if (r >= half && c < half) return 2 * half * half + func(n - 1, r - half, c);
	//4
	return 3 * half * half + func(n - 1, r - half, c - half);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int r = 0; int c = 0; cin >> N; cin >> r; cin >> c;
	cout<<func(N, r, c);
}
