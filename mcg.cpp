#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(){

	ofstream myFileI ("out.txt");
	vector< vector<int> > vec;
	bool field[1000][1000] = {0};
	if( myFileI.is_open() )
        {
	cout<<"Ready"<<endl;
        }
	int iter = 1;
	cout<<"Length?"<<endl;
	int n;
	cin>>n;
        srand((unsigned)time(0));
		int number = 1;
		int last_x = 0, last_y = 0;
        vector <int> temp;
        while(number <= n){
		int random = (rand()%4)+1;
        int type = (rand()%2)+1;
                if(number == 1){
                    temp.push_back(last_x);
                    temp.push_back(last_y);
                    temp.push_back(type);
                    vec.push_back(temp);
                    temp.clear();
                    continue;
                }
				if(random == 1 && field[last_x][last_y+1] == 0){
					field[last_x][last_y+1] = 1;
					last_y += 1;
					number ++;
					temp.push_back(last_x);
					temp.push_back(last_y);
					temp.push_back(type);
				}
				if(random == 2 && field[last_x][last_y+1] == 0){
					field[last_x+1][last_y] = 1;
					last_x += 1;
					number ++;
					temp.push_back(last_x);
                    temp.push_back(last_y);
                    temp.push_back(type);
				}
				if(random == 3 && field[last_x][last_y+1] == 0){
					field[last_x][last_y-1] = 1;
					last_y -= 1;
					number ++;
					temp.push_back(last_x);
                    temp.push_back(last_y);
                    temp.push_back(type);
				}
				if(random == 4 && field[last_x][last_y+1] == 0){
					field[last_x-1][last_y] = 1;
					last_x -= 1;
					number ++;
					temp.push_back(last_x);
                    temp.push_back(last_y);
                    temp.push_back(type);
				}
			vec.push_back(temp);
            temp.clear();
			}
	for(int i=0;i<vec.size()-1;i++){
		for(int y=0;y<=vec[i].size()-1;y++){
		cout<< vec[i][y] << " ";
		}
        cout<<endl;
    }
	
	myFileI.close();
	return 0;
}
