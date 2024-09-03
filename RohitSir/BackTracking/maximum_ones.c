#include <stdio.h>
#include <math.h>
int solve(int n,int m,int i,int j,int mat[n][m]){
        if(i >= n || j >= m) return 1e9;
        // if(j >= m) return 0;
        if(i == n-1 && j == m-1){
                return mat[i][j];
        }

        // Down
        int a = solve(n, m, i + 1, j, mat);
       	// Right
        int b = solve(n, m, i, j + 1, mat);
	int mini = 0;
	if(a > b){
		mini = b;
	}
	else{
		mini = a;
	}
	return mat[i][j] + maxi; 
}
/*
 * _ _ _ _
 * _ _ _ _
 * _ _ _ _ 
 * _ _ _ _
 * */
int main(){
        int n = 4;
        int m = 4;
       	int mat[4][4] = {
	{1,1,1,1},
	{1,0,0,1},
	{1,1,1,1},
	{0,0,0,0}};

	int ans = solve(n, m, 0 ,0, mat);
	printf("%d",ans);
	return 0;
}
