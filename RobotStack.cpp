using namespace std;
class RobotStack{
	public:
		char b;
		char n;
		char k;
    	int C[100][100];
    	RobotStack(){
			for(int i = 0; i < n; i++)
		        for (int j = 0; j < b; j++)
		        	C[n][b] = 0;
    	}
		void printValues(){
			cout << "b: " << b << " n: " << n << " k: " << k << endl;
		}
		int dyn(){
	    	//Memoized functionality
	    	if(C[n][b] > 0){
	    		// print(C[n][b]);
	    		return C[n][b];
	    	}
	    	//Binomial Coefficient
		    for (int i = 0; i <= n; i++){
		        for (int j = 0; j <= min(i, b); j++){
	            	//Base Case
		            if (j == 0 || j == i || j+i-1==k)
		                C[i][j] = 1;
		            // else if(j == k)
		            // 	C[i+j-1][j] = C[i+j-1][j-1] + C[i+j-1][j];
		            else
		                C[i][j] = C[i-1][j-1] + C[i-1][j];
		        }
		    }
		    print(C[n][b]);
		    return C[n][b];
		}
		bool check(int temp){
			return true;
		}
		int min(int a, int b){
			if(a < b)
				return a;
			return b;
		}
		void print(int i){
			cout << i;
		}
};