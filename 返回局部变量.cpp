class ReturnAnObject {
public:
	int arr[10];
	int num;
};
 
 
ReturnAnObject returnAnObjectFunc() {
	ReturnAnObject obj;
	obj.num = 0x12345678;
	for (int i = 0; i < 10; i++) {
		obj.arr[i] = i + 3;
	}
	return obj;
}
 
 
int main() {
	ReturnAnObject obj;
	obj = returnAnObjectFunc();
	return 0;
}

