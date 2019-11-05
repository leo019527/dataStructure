#include <iostream>
#include <vector>

using namespace std;

bool has(vector<int> *a, int x){
    for(int i=0;i<a->size();i++){
        if((*a)[i]==x){
            return true;
        }
    }
    return false;
}

/*
 * 将B列表无重复插入A列表
 */
void unionList(vector<int> *a,vector<int> b){
    int len_b = b.size();
    for(int i=0;i<len_b;i++){
        if(!has(a,b[i])){
            a->push_back(b[i]);
        }
    }
}

int main() {
    vector<int> a;
    vector<int> b;
    a.push_back(3);
    a.push_back(5);
    a.push_back(8);
    a.push_back(11);

    b.push_back(2);
    b.push_back(6);
    b.push_back(8);
    b.push_back(9);
    b.push_back(11);
    b.push_back(15);
    b.push_back(20);
    unionList(&a,b);
    for(int i=0;i<a.size();i++){
        cout << a[i] << ", ";
    }
    cout << endl;
    return 0;
}