#include <stdio.h>

void solve(int n,int m,int i,int j,char mat[n][m]){
	if(i >= n) return;
	if(j >= m) return;
	if(i == n-1 && j == m-1){
		printf("%c\n",mat[i][j]);
		return;
	}
	printf("%c ",mat[i][j]);
	// Down
	solve(n, m, i + 1, j, mat);
	// Right
	solve(n, m, i, j + 1, mat);
}
int main(){
	int n = 3;
	int m = 3;
	char mat[3][3] = {{'A','B','C'},{'D','E','F'},{'G','H','I'}};
	// we need to return all paths for 'A' to 'I'
	
	solve(n, m, 0 ,0, mat);
}
