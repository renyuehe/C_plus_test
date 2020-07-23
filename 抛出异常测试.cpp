//异常处理
#include <iostream>
using namespace std;

int division(int x, int y){
	if(y == 0){
		throw 0;
		throw "Division by zero condition!";
	}
}

int main(){

	int m, n;
	cin >> m >> n;
	try {
		cout << division(m, n) << endl;
	}
	//exception 是标准异常，不是普通的异常 
	catch(exception e){
		cout << "eception err" << endl;
	}
	catch(int &error){
		cerr << "divasion by " << error << endl;
	}
	catch(const char * msg){
		cerr << msg <<endl;
	}
//	catch(...){
//		cerr <<"other type error"<<endl;
//	}
	
	return 0;
} 
