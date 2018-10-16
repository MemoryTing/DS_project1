#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

 int main(int argc , char *argv[])
 {
     ifstream fin;
     ofstream fout;
     
     string in_com , out_com;
     in_com = "./";
     in_com += argv[1];
     out_com = in_com;
     in_com += "/matrix.data";
     out_com += "/final.peak";
     fin.open(in_com);
     fout.open(out_com);
     
     int r , c , i=0 , j , out=0;
     int temp[3];
     vector<int> peak;
     fin >> r >> c;
     int matrix[r][c];
     for(int i=0 ; i<r ; i++){
     	for(int j=0 ; j<c ; j++){
     		fin >> matrix[i][j];
		}
	 }
	 
	 if(matrix[0][0] - matrix[0][1] > -1){
	 	if(matrix[0][0] - matrix[1][0] > -1){
			out++;
     		peak.push_back(0);
     		peak.push_back(0);
		}
	 }
	 for(j=1 ; j<c-1 ; j++){
	 	if(matrix[0][j] - matrix[0][j+1] > -1){
     		if(matrix[0][j] - matrix[0][j-1] > -1){
     			if(matrix[0][j] - matrix[1][j] > -1){
					out++;
     				peak.push_back(i);
     				peak.push_back(j);
     			}
			}
		}
	 }
	 if(matrix[0][c-1] - matrix[0][c-2] > -1){
	 	if(matrix[0][c-1] - matrix[1][c-1] > -1){
			out++;
     		peak.push_back(0);
     		peak.push_back(c-1);
		}
	 }
     for (i=1 ; i<r-1 ; i++){
     	if(matrix[i][0] - matrix[i][1] > -1){
	 		if(matrix[i][0] - matrix[i+1][0] > -1){
				out++;
     			peak.push_back(i);
     			peak.push_back(0);
			}
	 	}
     	for (j=1 ; j<c-1 ; j++){
     		if(matrix[i][j] - matrix[i+1][j] > -1){
     			if(matrix[i][j] - matrix[i][j+1] > -1){
     				if(matrix[i][j] - matrix[i-1][j] > -1){
     					if(matrix[i][j] - matrix[i][j-1] > -1){
							out++;
     						peak.push_back(i);
     						peak.push_back(j);
     					}
					}
				}
			}
		}
		if(matrix[i][c-1] - matrix[i][c-2] > -1){
	 		if(matrix[i][c-1] - matrix[i+1][c-1] > -1){
				out++;
     			peak.push_back(i);
     			peak.push_back(c-1);
			}
	 	}
	 }
     if(matrix[r-1][0] - matrix[r-1][1] > -1){
	 	if(matrix[r-1][0] - matrix[r-2][0] > -1){
			out++;
     		peak.push_back(r-1);
     		peak.push_back(0);
		}
	 }
	 for(j=1 ; j<c-1 ; j++){
	 	if(matrix[r-1][j] - matrix[r-1][j+1] > -1){
     		if(matrix[r-1][j] - matrix[r-1][j-1] > -1){
     			if(matrix[r-1][j] - matrix[r-2][j] > -1){
					out++;
     				peak.push_back(r-1);
     				peak.push_back(j);
     			}
			}
		}
	 }
	 if(matrix[r-1][c-1] - matrix[r-1][c-2] > -1){
	 	if(matrix[r-1][c-1] - matrix[r-2][c-1] > -1){
			out++;
     		peak.push_back(r-1);
     		peak.push_back(c-1);
		}
	 }
	 fout << out << endl;
	 for(i=0 ; i<out*2 ; i++) {
	 	fout << peak[i] << ' ';
	 	i++;
		fout << peak[i] << endl;
	 }
     fin.close();
     fout.close();
     return 0;
}

