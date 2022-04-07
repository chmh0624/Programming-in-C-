#include <iostream>
#include <cmath>

int main()
{
	int T;
	std::cin >> T;
	while (T--)
	{
		int N, P;
		std::cin >> N >> P;
		int *arr = new int[N];
		for (int i=0; i<N; i++)
		{
			arr[i] = 0;
		}
		while (P--)
		{
			int h;
			std::cin >> h;
			for (int i=0; i<N; i++)
			{
				if ((i+1) % h == 0)
					arr[i] = 1;
			}
		}
		int ans = 0;
		for (int i=0; i<N; i++)
		{
			if (arr[i] == 1 && (i+1) % 7 != 6 && (i+1) % 7 != 0)
				ans ++;
		}
		std::cout << ans << std::endl;
	}    
}
