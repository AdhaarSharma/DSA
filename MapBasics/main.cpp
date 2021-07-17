#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
	map<string,int> marksMap;
    marksMap["Harry"] = 98;
    marksMap["Jack"] = 59;
    marksMap["Rohan"] = 2;
    marksMap.insert({{"Kozume",169},{"Kuroo",187}});
    map<string, int>::iterator iter;
    for(iter=marksMap.begin();iter!=marksMap.end();iter++){
        cout<<(*iter).first<<" "<<(*iter).second<<endl;
    }
    printf("hello world\n");
	return 0;
}
