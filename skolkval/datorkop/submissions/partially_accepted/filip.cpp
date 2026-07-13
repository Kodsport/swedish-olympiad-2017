
#include <iostream>

using namespace std;

#define MAX 1000;
int x, y, b, a, n;
int avr;

int max(int val1, int val2) {
	if (val1 > val2)
	{
		return val1;
	}
	else
	{
		return val2;
	}
}

int min(int val1, int val2) {
	if (val1 < val2)
	{
		return val1;
	}
	else
	{
		return val2;
	}
}

bool Possible(int tx, int ty) {
	int leftx = x - tx;
	int lefty = y - ty;
	int largest = tx * a + ty * b;
	for (int i = 0; i < n-1; i++)
	{
		if (leftx >= tx && lefty >= ty)
		{
			leftx -= tx;
			lefty -= ty;
		}
		else
		{
			if (leftx > lefty)
			{
				ty = 0;
				tx = min(leftx, 1+ ((largest-1) / a));
				for (int j = 1; j <= lefty; j++)
				{
					if (ty * b + tx * a > j * b + a*min(leftx,1 + (largest - j * b - 1)/a) || ty * b + tx * a < largest)
					{
						ty = j;
						tx = min(leftx,1 + ((largest - j * b - 1)/a));
					}
				}
			}
			else
			{
				tx = 0;
				ty = min(lefty, 1 + ((largest - 1) / b));
				for (int j = 1; j <= leftx; j++)
				{
					if (ty * b + tx * a > j * a + b * min(lefty, 1 + (largest - j * a - 1)/b) || ty * b + tx * a < largest)
					{
						tx = j;
						ty = min(lefty,1 + ((largest - j * a - 1) / b));
					}
				}
			}
			if (a * tx + b * ty >= largest)
			{
				largest = a * tx + b * ty;
				leftx -= tx;
				lefty -= ty;
			}
			else
			{
				return false;
			}
		}
	}
	return true;

}


int main() {
	cin >> x >> a >> y >> b >> n;
	avr = (x * a + y * b) / n;
	int out = 0;
	for (int i = 0; i <= x; i++)
	{
		for (int j = 0; j <= y; j++)
		{
			if (avr >= i * a + j * b && Possible(i,j))
			{
				out = max(out, i * a + j * b);
			}
		}
	}
	cout << out << endl;
	
	return 0;
}

