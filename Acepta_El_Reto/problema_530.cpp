
#include <bits/stdc++.h>
using namespace std;

int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

char m[120][120];

void floodFill(bool v[][120], int x, int y, int maxX, int maxY, int &cont) {

	if(x < 0 || x >= maxX || y < 0 || y >= maxY || v[x][y] || m[x][y] != 'X')
		return;

	v[x][y] = true;
	cont+=1;

	for(int i = 0; i < 4; i++){
		int tx = x + dr[i];
		int ty = y + dc[i];
		floodFill(v, tx, ty, maxX, maxY, cont);
	}
	return;
}

bool floodFill2(bool v[][120], int x, int y, int maxX, int maxY) {

	if(x < 0 || x >= maxX || y < 0 || y >= maxY || v[x][y] || m[x][y] != '.')
		return false;

	v[x][y] = true;
	m[x][y] = '$';

	bool ret = false;
	if(x == 0 || y == 0 || x == maxX-1 || y == maxY-1 || x == maxX/2 || y == maxY/2)
		ret = true;

	for(int i = 0; i < 4; i++){
		int tx = x + dr[i];
		int ty = y + dc[i];
		ret |= floodFill2(v, tx, ty, maxX, maxY);
	}

	return ret;
} 

bool check (int x, int y, int cont, int aX, int bX){

	bool sim = true;
	int a = 0, b = y-1, c = 0, d = x-1;
	int i = 0;
	while(i < x && sim){
		int j = 0;
		while (j < y && sim){
			sim &= m[i][a+j] == m[i][b-j];
			j++;
		}
		i++;
	}

	i = 0;
	while (i < y && sim){
		int j = 0;
		while(j < x && sim){
			sim &= m[c + j][i] == m[d - j][i];
			j++;
		}

		i++;
	}

	bool v[120][120];
	memset(v, false, sizeof(v));
	int xfound = 0;

	floodFill(v, aX, bX, x, y, xfound);
	bool bordes = true;
	for(int h = 0; h < x; h++){
		for(int k = 0; k < y; k++){
			if(m[h][k] == '.'){
				memset(v, false, sizeof(v));
				bordes &= floodFill2(v, h, k, x, y);
			}
		}
	}

	return sim && cont == xfound && bordes;
}

int main(){
	
	int x, y;
	int cont;
	int a, b;

	while(cin >> y >> x){
		cont = 0;

		for (int i = 0; i < x; i++){
			for(int j = 0; j < y; j++){
				cin >> m[i][j];
				if (m[i][j] == 'X'){ 
					cont++;
					a = i;
					b = j;
				}
			}
		}
		if(cont == 0)
			cout << "TRAMPOSO\n";
		else 
			cout << (check(x, y, cont, a, b) ? "CORRECTO\n" : "TRAMPOSO\n"); 

	}

	return 0;
}
