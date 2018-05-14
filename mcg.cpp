#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(){

        int n;
        cin>>n;
		int field[1000][1000] = {0};
		srand((unsigned)time(0));
		field[500][500] = 1;
		int number = 2;
		int last_x = 500, last_y = 500;
		float av_x = 500, av_y = 500;
        vector < vector<int> > baze;
        vector <int> temp;
		while(number <= n){
			int random = (rand()%4)+1;
            int type = (rand()%2)+1;
			if(random == 1 && field[last_x][last_y+1] == 0){
				field[last_x][last_y+1] = number;
				last_y += 1;
				number ++;
                temp.push_back(last_x);
                temp.push_back(last_y);
                temp.push_back(type);
//				continue;
			}
			if(random == 2 && field[last_x+1][last_y] == 0){
				field[last_x+1][last_y] = number;
				last_x += 1;
				number ++;
//				continue;
			}
			if(random == 3 && field[last_x][last_y-1] == 0){
				field[last_x][last_y-1] = number;
				last_y -= 1;
				number ++;
//				continue;
			}
			if(random == 4 && field[last_x-1][last_y] == 0){
				field[last_x-1][last_y] = number;
				last_x -= 1;
				number ++;
//				continue;
			}
            baze.push_back(temp);
            temp.clear();
		}

/*		for(int y=490;y<=510;y++){
			for(int i=490;i<510;i++){
				cout<<field[i][y]<<" ";
			}
			cout<<endl;
		}
*/
        for(int y=0;y<baze.size();y++){
			for(int i=0;i<baze[y].size();i++){
				cout<<baze[y][i]-500<<" ";
			}
			cout<<endl;
		}
    
	return 0;
}
