#include <iostream>
#include <vector>

using namespace std;

string divide(string quard);
string decode(string result[]);


int main(){
    int c;
    cin >> c;
    vector<string> res;
    while(c--){
       string quard;
       cin >> quard;
       res.push_back(divide(quard));
    }
    for(int i=0; i<res.size(); i++){
        cout << res[i] << endl;
    }
    return 0;
}

string divide(string quard){
    string result[5];
    if(quard.length()==1){
        return quard;
    }

    int cnt = 0;
    for(int i=0; i<5; i++){
        if(i != 0 && quard[cnt] == 'x'){
            result[i] = divide(quard.substr(cnt));
            cnt += result[i].length();
            continue;
        }
        result[i] = quard[cnt];
        cnt += result[i].length();
    }
    string temp = result[1];
    string temp2 = result[2];
    result[1] = result[3];
    result[2] = result[4];
    result[3] = temp;
    result[4] = temp2;
    return decode(result);
}

string decode(string result[]){
    string temp;
    for(int i=0; i<5; i++){
        temp += result[i];
    }
    return temp;
}