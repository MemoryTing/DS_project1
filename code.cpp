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
     
     char row , col;
     int r , c , i=0 , j , out=0;
     int temp[3];
     vector<int*> peak;
     fin.get(row);
     fin.get(col);
     r = row - '0';
     c = col - '0';
     int matrix[r][c];
     for(int i=0 ; i<r ; i++){
     	for(int j=0 ; j<c ; j++){
     		fin >> matrix[i][j];
		}
	 }
	 if(matrix[0][0] - matrix[0][1] > -1){
	 	if(matrix[0][0] - matrix[1][0] > -1){
	 		temp[0] = 0;
     		temp[1] = 0;
			out++;
     		peak.push_back(temp);
		}
	 }
	 for(j=1 ; j<c-1 ; j++){
	 	if(matrix[0][j] - matrix[0][j+1] > -1){
     		if(matrix[0][j] - matrix[0][j-1] > -1){
     			if(matrix[0][j] - matrix[1][j] > -1){
     				temp[0] = 0;
     				temp[1] = j;
					out++;
     				peak.push_back(temp);
     			}
			}
		}
	 }
	 if(matrix[0][c-1] - matrix[0][c-2] > -1){
	 	if(matrix[0][c-1] - matrix[1][c-1] > -1){
	 		temp[0] = 0;
     		temp[1] = c-1;
			out++;
     		peak.push_back(temp);
		}
	 }
     for (i=1 ; i<r-1 ; i++){
     	if(matrix[i][0] - matrix[i][1] > -1){
	 		if(matrix[i][0] - matrix[i+1][0] > -1){
	 			temp[0] = i;
     			temp[1] = 0;
				out++;
     			peak.push_back(temp);
			}
	 	}
     	for (j=1 ; j<c-1 ; j++){
     		if(matrix[i][j] - matrix[i+1][j] > -1){
     			if(matrix[i][j] - matrix[i][j+1] > -1){
     				if(matrix[i][j] - matrix[i-1][j] > -1){
     					if(matrix[i][j] - matrix[i][j-1] > -1){
     						temp[0] = i;
     						temp[1] = j;
							out++;
     						peak.push_back(temp);
     					}
					}
				}
			}
		}
		if(matrix[i][c-1] - matrix[i][c-2] > -1){
	 		if(matrix[i][c-1] - matrix[i+1][c-1] > -1){
	 			temp[0] = i;
     			temp[1] = c-1;
				out++;
     			peak.push_back(temp);
			}
	 	}
	 }
     if(matrix[r-1][0] - matrix[r-1][1] > -1){
	 	if(matrix[r-1][0] - matrix[r-2][0] > -1){
	 		temp[0] = r-1;
     		temp[1] = 0;
			out++;
     		peak.push_back(temp);
		}
	 }
	 for(j=1 ; j<c-1 ; j++){
	 	if(matrix[r-1][j] - matrix[r-1][j+1] > -1){
     		if(matrix[r-1][j] - matrix[r-1][j-1] > -1){
     			if(matrix[r-1][j] - matrix[r-2][j] > -1){
     				temp[0] = r-1;
     				temp[1] = j;
					out++;
     				peak.push_back(temp);
     			}
			}
		}
	 }
	 if(matrix[r-1][c-1] - matrix[r-1][c-2] > -1){
	 	if(matrix[r-1][c-1] - matrix[r-2][c-1] > -1){
	 		temp[0] = r-1;
     		temp[1] = c-1;
			out++;
     		peak.push_back(temp);
		}
	 }
	 fout << out << endl;
	 for(i=0 ; i<out ; i++) fout << peak[i] << endl;
     fin.close();
     fout.close();
     return 0;
}

