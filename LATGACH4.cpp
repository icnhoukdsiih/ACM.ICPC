// PREPARING ACM.ICPC 2018
// LATGACH4 - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
//--------------------------------------------------
#include <iostream>
using namespace std;
const long long mod = 111539786;
int t, n; 
// Ta có  	f[i]		= 0 * f[i - 1] + 1 * f[i]
//		f[i + 1]	= 1 * f[i - 1] + 1 * f[i]
// Suy ra [f[i], f[i + 1]] = [0, 1; 1, 1] * [f[i - 1], f[i]]
//		  [f[i], f[i + 1]] = [0, 1; 1, 1] ^ i * [f[0], f[1]]
long long a[2][2]={{0,1},{1,1}}, res[2][2]; //Mảng a lưu ma trận ban đầu, res là ma trận tính a^n
//Tính a^k lưu vào res
void powMatrix(int k) {
	//Nếu k = 1 thì trả về ma trận ban đầu
	if (k == 1) {
		res[0][0] = 0;
		res[0][1] = 1;
		res[1][0] = 1;
		res[1][1] = 1;
		return;
	}
	powMatrix(k / 2); //Chia để trị, tính a ^ (k / 2) lưu vào res
	long long b[2][2] = {0};
	//Tính res * res lưu vào b là kết quả ==> a ^ ((k / 2) * 2)
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int c = 0; c < 2; c++)
				b[i][j] = (b[i][j] + res[i][c] * res[c][j]) % mod;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++) {
			//Nếu k lẻ thì nhân ma trận b cho ma trận a ban đầu ==> a ^ k, lưu kết quả vào res
			if (k % 2 == 1) { 
				res[i][j] = 0;
				for (int c = 0; c < 2; c++)
					res[i][j] = (res[i][j] + b[i][c] * a[c][j]) % mod;
			}
			else res[i][j] = b[i][j]; //Ngược lại gán kết quả b cho res
		}
}
int main() {
	cin >> t;
	for (int test = 0; test < t; test++) {
		cin >> n;
		powMatrix(n); //Tính a ^ n lưu vào res
		cout << (res[0][0] + res[0][1]) % mod << endl; //Vì [0, 1; 1, 1] ^ n * [f[0] = 1; f[1] = 1] = [f[n]; f[n + 1]]
	}
	return 0;
}
