using namespace std;
class RobotStack{
	public:
		int b;
		int n;
		int k;
    	int arr[100][100];
    	RobotStack(){
			for(int i = 0; i < n; i++)
		        for (int j = 0; j < b; j++)
		        	arr[n][b] = -1;
    	}
		void printValues(){
			cout << "b: " << b << " n: " << n << " k: " << k << endl;
			cout << "Result: ";
		}

		int choose(int n, int b) {
		    if(b == 0) {
				return 1;
			}
		    return (n * choose(n - 1, b - 1)) / b;
		}

		int dyn(int n, int b, int k) {
			int total = 0;
			if(n == 0) {
				return total + 1;
			}else {
				for(int i = b; i >= 0; i -= k) {
					for(int j = 0; j <= k; j++) {
						if(j == i) {
							total += choose(n + i - 1, i);
						}
						else if(j == 1) {
							total += choose(n, i);
						}
					}
				}
				return dyn(n - 1, b, k) + total;
			}
		}
};