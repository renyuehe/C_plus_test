//模拟 connect 和 accept  函数之间的通讯

 #include <iostream>
 using namespace std;
 
// struct sockaddr *addr
// socklen_t
 
// int accpet(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

//TCP 报文段： TCP header  +  data
//header 
// 源端口  0-16  目的端口 16-31
// 序号 sqquence number 0-32
// 确认号 
// 偏移 保留 flags 窗口 
// 校验和 紧急指针
// 可变部分 

//data 
 
 int accept(){
 	
 }
 
// int conncet(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
 int connect(){
 	
 } 
 
 
 
 int main(){
 	
 }
