#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

bool f(int x, int y){
    return x > y;
}

void vectorDemo(){
    vector<int> A = {11,2,3,14};
    cout<<A[1]<<endl;
    sort(A.begin(), A.end()); //Sorting in O(NlogNbool present = binary_search(A.begin(), A.end(), 4); //false)
    bool present = binary_search(A.begin(), A.end(), 3); //O(logN) true
    present = binary_search(A.begin(), A.end(), 4); //false
	
    A.push_back(100);
    present = binary_search(A.begin(), A.end(), 100); //true
    
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
   // 
    A.push_back(123);
    
    // 2,3,11,14,100,100,100,100,100,123
    
    //vector<int>::iterator it = lower_bound(A.begin(), A.end(), 100); // >=
    auto it = lower_bound(A.begin(), A.end(), 100);
    //vector<int>::iterator it2 = upper_bound(A.begin(), A.end(), 100); // >
    auto it2 = upper_bound(A.begin(), A.end(), 100);
    
    cout<< *it << " " << *it2 <<endl;
    cout<<it2-it<<endl; //O(1), 5
    
    sort(A.begin(), A.end(), f);
    
    //vector<int>::iterator it3;
    
    //for(it3=A.begin(); it3!=A.end(); it3++){
    for(int x:A){    
    //    cout<<*it3<<" ";
        cout<< x << " ";
    }
    cout<<endl;
    
    for(int &x:A){ //by reference
        x++;
    }
    for(int x:A){    
        cout<< x << " ";
    }
    cout<<endl;
}

void setDemo(){
    // logN Insertion Deletion
    set<int> S;
    S.insert(2);
    S.insert(1);
    S.insert(-10);
    S.insert(-1);
    
    for(int x:S){
        cout<<x<<" ";
    }
    cout<<endl;
    //-10 -1 1 2
    auto it = S.find(-1);
    if(it == S.end()){
        cout<<"not present\n";
    }
    else{
        cout<<"present\n";
        cout<<*it<<endl;
    }
    auto it2 = S.upper_bound(-1);
    auto it3 = S.upper_bound(0);
    cout<<*it2<<" "<<*it3<<endl;
    auto it4 = S.upper_bound(2);
    if(it4 == S.end()){
        cout<<"Oops! Sorry, element not found."<<endl; 
    }
}

void mapDemo(){
    //logN insertion deletion
    map<int, int> A;
    A[1] = 100;
    A[2] = -1;
    A[3] = 200;
    A[100000232] = 1;
    
    map<char, int> cnt;
    string x = "adhaar sharma";
    
    for(char c: x){
        cnt[c]++;
    }
    cout<<cnt['a']<<" "<<cnt['z']<<endl;
}

void PowerOfStl(){
    // [x,y]
    /*add [2,3]
      add[10,20]
      add[30,400]
      add[401,450]
      give me the interval of 401*/
    set<pair<int,int>> S;
    S.insert({401,450});
    S.insert({2,3});
    S.insert({10,20});
    S.insert({30,400});
    
    int point = 50;
    auto it = S.upper_bound({point,INT_MAX});
    if(it == S.begin()){
        cout<<"The given point is not lying in any interval"<<endl;
        return;
    }
    it--;
    pair<int,int> current = *it;
    if(current.first <= point && point <= current.second){
        cout<<"yes its present: "<<current.first<<" "<<current.second<<endl;
    }
    else{
        cout<<"The given point is not lying in any interval."<<endl;
    }
    it=S.end();
    cout<<(*it).first<<endl;
    cout<<(*it).second<<endl;
    it--;
    cout<<(*it).first<<endl;
    cout<<(*it).second<<endl;
}

int main(){
    
    //C++ STL
    //vectorDemo();
    //setDemo();
    PowerOfStl();
    
}
