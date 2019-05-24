#include <iostream>
#include <sstream>
#include <vector>

#include <fstream>
#include <string>

#define rep(i,a,b)  for(int i=a;i<b;i++)
#define max(a,b) a>b?a:b
#define changeInput std::ifstream in("test2.txt"); \
    std::streambuf *cinbuf = std::cin.rdbuf(); \
    std::cin.rdbuf(in.rdbuf()); \
    std::string line; 
#define changeOutput std::ifstream out("out.txt"); \
    std::streambuf *cinbuf = std::cout.rdbuf(); \
    std::cout.rdbuf(out.rdbuf()); \
    std::string line; 
using namespace std;
std::vector<vector <int>> v;
vector<vector<int>> top(vector<vector<int>> v){
    if(v.size() == 0) return v;
     vector<int> i = v.front();
     for(vector<int>::iterator it=i.begin();it<i.end();it++){ 
        cout<<*it<<" ";
     }
     v.erase(v.begin());
     return v;
}
vector<vector<int>> right(vector<vector<int>> v){
    if(v.size() == 0) return v;
     rep(i,0,v.size()){
        //int n = v[i].pop_back();
        cout<<v[i][v[i].size()-1]<<" ";
        v[i].pop_back();
     }
     return v;
}
vector<vector<int>> bottom(vector<vector<int>> v){
    if(v.size() == 0) return v;
     vector<int> i = v.back();
     for(vector<int>::reverse_iterator it=i.rbegin();it!=i.rend();it++){
        cout<<*it<<" ";
     }
     v.pop_back();
     return v;
}
vector<vector<int>> left(vector<vector<int>> v){
    
    if(v.size()==0) return v;
    //for(vector<vector<int>>::iterator it=v.begin();it!=v.end();it++){
    rep(i,0,v.size()){
        vector<int> c = v[i];
        cout<<c[0]<<" ";
        c.erase(c.begin());
        v[i] = c;
    }
    return v;
}
int main(){
    changeInput;
	int i,j;
    
    cin>>i;
    while(i--){
        vector <int> a;
        while(1){
            cin>>j;
            a.push_back(j);
            if (cin.get() == '\n') break;
        }
        v.push_back(a);
        a.clear();

    }
    cout<<"\n vector is ...";
    while(v.size()){
        v = top(v);
        v = right(v);
        v = bottom(v);
        v = left(v);
    }
    
        // rep(i,0,v.size()){
        //     rep(j,0,v[i].size()){
        //         cout<<"\n a["<<i<<"]["<<j<<"]="<<v[i][j];
        //     }
        // }
    
    /*cout<<" got "<<i;
    getline(cin,line);
    cout<<" line i got is "<<line;*/
    /*while(std::getline(std::cin, line))  //input from the file in.txt
    {
        std::cout << line << "\n";   //output to the file out.txt
    }*/
	/*int i=0,j=0,N;
	int a=1,b=2,c=3,d=4;
	string temp;
	cin>>T;
	while(T--){
		cin>>temp;
		row.push_back(temp);

	}*/
}