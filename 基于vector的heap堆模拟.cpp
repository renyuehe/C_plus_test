using namespace std; 
#include <iostream>
#include <vector>


template<class T>
class Myheap{
private:
	std::vector<T> vec;
	int size;		//Ԫ������ 
	int capacity;	//�����ѵĴ�С 
	
	
public:
	Myheap(T data[], int len):size(0), capacity(len){
		vec.resize(capacity);
		for(int i = 0; i < len; i++){
			push(data[i]);
		}
	}
	//�ն� 
	Myheap(int capacity){
		vec.resize(capacity);
	} 
	~Myheap();
	
	bool push(T data){
		if(full()){
			throw("The heap is full !!\n");
			return false;
		}
		else
		{
			vec[size] = data;
			++size;
			floating(size);
			//����ǰλ�õ����ݽ����ж��ϸ�(�����λ�ô�1��ʼ�㣬����0)
			//����Ϊ�˸��������������ҽ���λ��
			//��ǰ�ڵ�: i   ����: 2i  �ҽ��: 2i+1
			return true;
		}
	}
	
	bool pop(int index){
		if(empty()){
			throw("This is an empty heap!!\n");
			return false;
		}
		vec[index] = vec[size-1];
		--size;
		sink(index+1);
		return true;
	}
	
	void print(){
		for(int i = 0; i < size; i++){
			cout<<vec[i]<<" ";
		}
		cout<<endl;
		return;
	}
	bool full(){
		if(size >= capacity){
			return true;
		}
		return false;
	}
	bool empty(){
		return size == 0;
	}

	void swap(int i, int j){
		T temp = vec[i];
		vec[i] = vec[j];
		vec[j] = temp;
		return;
	}

	void sink(int index){
		int i = index;
		while(i*2 <= size){
			//����ڵ�Ƚ� 
			if(vec[i-1] < vec[i*2 -1]){
				swap(i-1, i*2-1);
			}	
			//���ҽڵ�Ƚ�
			else if(i*2 + 1 <= size && vec[i-1] < vec[i*2]){
				swap(i-1, i*2);
				i = i*2 + 1;
			} 
			else{
				break;
			}
		}
	}
	
	void floating(int index){
		if(size == 1){
			return;
		}
		for(int i = index; i > 0; i * 0.5){
			//����ѵ��ϸ�
			if(vec[i-1] > vec[i*0.5 - 1])
			{
				swap(i-1, i*0.5-1);
			}
			else{
				break;
			}
		}
		return;
	} 
};

int main(){
	int buffer[10] = {0,1,2,3,4,5,6,7,8,9};
	Myheap<int> *heap = new Myheap<int>(buffer, 10);
	
	heap->print();
	heap->pop(0);
	heap->print();
	
	heap->push(10);
	heap->print();
	
	return 0;
}

