//============================================================================
// Name        : lab1.cpp
// Author      : Wiktor Jurek
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

void show(int **tab, int n,int L) {
	fstream file;
	file.open("out.txt", ios::out | ios::app);
	if(file.good() == true) {


		for(int i=0; i<n; i++) {

			for(int j=0; j<=L; j++) {
				if(tab[i][j] == 1) {
					file<<"T ";
					cout<<"T ";
				} else {
					file<<"N ";
					cout<<"N ";
				}

			}
			cout<<endl;
			file<<"\n";

		}
		file<<"\n";
		cout<<endl;
		file.close();
	}
}


int calcSum(int* A, int n) {
	int temp;
	temp=0;
	for(int i =0; i<n; i++) {
		temp+= A[i];
	}
	return temp;
}

bool partition(int n, int* A) {

	int sum;
	sum = calcSum(A,n);
	if(sum >55 || sum <0 || sum%2 == 1) {
		
		return false;
	} else {

		int L;
		L = sum /2;
//		inicjalizacjia pomocniczej tablicy podzia³ów
		int **part = new int* [n];
		for(int i=0; i<=L; i++) {
			part[i] = new int[L];
		}



		for(int i =0; i<=L; i++) {

			if(i==0) {
				part[0][i] =1;
			} else if(i == A[0]) {
				part[0][i] = 1;
			} else {
				part[0][i] =0;
			}
//			cout<<part[0][i]<<" i:"<<i<<endl;
		}


		for(int i=1; i<n; i++) {
			for(int j=0; j<=L; j++) {

				part[i][j] = part[i-1][j];
				if(A[i] <=j && part[i-1][j-A[i]] ==1) {
					part[i][j] =1;
				}
			}
		}
		show(part,n,L);
		cout<<endl;
		if(part[n-1][L] ==1) {
			return true;
		} else {

			return false;
		}

	}

}

int main() {
	int n, sum, L;
	cout<<"Wprowadz rozmiar zbioru [0-10]"<<endl<<"n=";
	cin>>n;
	//tablica zawierajaca zbiór
	if(n<=10 && n>=0) {
		int* A = new int[n];
		cout<<"Wprowadz wartosci zbioru :"<<endl;
		for(int i =0; i<n; i++) {
			cout<<"["<<i<<"] = ";
			cin>>A[i];
		}

		if(partition(n,A) ==true)  {

			cout<<"Problem decyzyjny PARTITION ma pozytywne rozwiazanie dla danego zbioru"<<endl;

		} else {
			cout<<"Problem decyzyjny PARTITION nie ma pozytywnego rozwiazania dla danego zbioru";
		}
	} else {
		cout<<"Przekroczono rozmiar zbioru";
	}




	return 0;
}

