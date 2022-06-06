#include <vector>
#include <iostream>
typedef long long ll;
#define fr(i,n) for(int i = 0; i <n; i++)
using namespace std;

void vivod(vector<vector<ll>> matr)
{
	fr(i, matr.size())
	{
		fr(j, matr.size())
			cout << matr[i][j] << ' ';
		cout << endl;
	}
}


int main()
{
	ll n;
	cout << "razmer" << endl;
	cin >> n;
	vector<vector<ll>> old(n);
	vector<vector<ll>> matr(n);
	vector<vector<ll>> vichet(n);
	cout << "matrica" << endl;
	fr(i, n)
	{
		vichet[i].resize(n);
		matr[i].resize(n);
		old[i].resize(n);
		fr(j, n)
		{
			cin >> matr[i][j];
			old[i][j] = matr[i][j];
		}
	}



	fr(i, n)
	{
		ll min = matr[i][0];
		fr(j, n)
			min = min < matr[i][j] ? min : matr[i][j];
		fr(j, n)
			matr[i][j] -= min;
	}
	ll rnol = 0;
	fr(j, n)
	{
		ll min = matr[0][j];
		fr(i, n)
			min = min < matr[i][j] ? min : matr[i][j];
		fr(i, n)
		{
			matr[i][j] -= min;
			if (matr[i][j] == 0) rnol++;
		}
	}

	while(true)
	{
		fr(i,n)
			fr(j,n)
				vichet[i][j] = 0;
		ll towin = 0;
		ll nol = rnol;
	while (nol)
	{
		bool f = true;
		fr(i, n)
		{
			ll tnol = 0;
			ll tj;
			fr(j, n)
			{
				if (matr[i][j] == 0 && vichet[i][j] == 0) { tnol++; tj = j; }
				if (tnol == 2) break;
				if (j == n - 1 && tnol)
				{
					vichet[i][tj] = 2;
					towin++;
					nol--;
					f = false;
					
					fr(k, n)
						if (matr[k][tj] == 0 && vichet[k][tj] == 0) { vichet[k][tj] = 1; nol--; }
				}
			}

		}

		fr(j, n)
		{
			ll tnol = 0;
			ll ti;
			fr(i, n)
			{
				if (matr[i][j] == 0 && vichet[i][j] == 0) { tnol++; ti = i; }
				if (tnol == 2) break;
				if (i == n - 1 && tnol)
				{
					vichet[ti][j] = 2;
					nol--;
					towin++;
					f = false;
					fr(k, n)
						if (matr[ti][k] == 0 && vichet[ti][k] == 0) { vichet[ti][k] = 1; nol--; }
				}
			}

		}
		
		if (f)
		{
			fr(i, n)
			{
				fr(j, n)
				{
					if (matr[i][j] == 0 && vichet[i][j] == 0)
					{
						vichet[i][j] = 2;
						towin++;
						nol--;
						f = false;
						fr(k, n)
							if (matr[k][j] == 0 && vichet[k][j] == 0) { vichet[k][j] = 1; nol--; }
						fr(k, n)
							if (matr[i][k] == 0 && vichet[i][k] == 0) { vichet[i][k] = 1; nol--; }
						goto m;
					}
				}

			}
		}
	m: nol = nol;
	}
	if (towin == n)
	{
		ll sumi = 0;
		fr(i, n)
			fr(j, n)
			if (vichet[i][j] == 2)
				sumi += old[i][j];
		cout <<endl<<endl<< sumi <<endl<< endl;
		break;
	}
	nol = rnol;

	fr(i, n)
		fr(j, n)
		vichet[i][j] = 0;

	while (nol)
	{
		ll mnol = 0;
		ll nnol = 0;
		ll ti;
		fr(i, n)
		{
			nnol = 0;
			fr(j, n)
				if (matr[i][j] == 0 && vichet[i][j] == 0) { nnol++; }
			if (nnol > mnol) { mnol = nnol; ti = i; }
		}
		fr(j, n)
		{
			vichet[ti][j]++;
		}
		nol -= mnol;
		if (!nol) break;

		mnol = 0;
		nnol = 0;
		ll tj;
		fr(j, n)
		{
			nnol = 0;
			fr(i, n)
				if (matr[i][j] == 0 && vichet[i][j] == 0) { nnol++; }
			if (nnol > mnol) { mnol = nnol; tj = j; }
		}
		fr(i, n)
		{
			vichet[i][tj]++;
		}
		nol -= mnol;
	}

	ll melt = LLONG_MAX;
	fr(i, n)
		fr(j, n)
		if (vichet[i][j] == 0 && matr[i][j] < melt) melt = matr[i][j];
	
	
	rnol = 0;
	fr(i, n)
		fr(j, n)
		{
			if (vichet[i][j] == 0) matr[i][j] -= melt;
				else if (vichet[i][j] == 2) matr[i][j] += melt;
			if (matr[i][j] == 0) rnol++;
		}



	


	}

	
	vivod(old);
	cout << endl;
	vivod(matr);
	cout << endl;
	vivod(vichet);
}

