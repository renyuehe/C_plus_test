#include <iostream>
using namespace std;

const int width = 12;
const int height = 12;



void renderView(const int x = 0,const int y = 0,const int z = 0){
	
	string line = "一一一一一一一一一一一一"; 
	string chopsticks = "口"; 
	
	for(int i = 0; i < 12; i++)
	{
		for(int j = 0; j < 12; j++){

			if(i == x && j == y)
			{
				if(z == 1)
				{
					cout<<"黑"<<" ";
					continue;
				}
				else if(z == 2){
					cout<<"白"<<" ";
					continue;
				}
				else{
				}
			}
			cout<<chopsticks<<" ";
		}
		cout<<endl<<line<<endl;
	}
}






int main(){

	renderView(); 
	
	
	return 0;
}
