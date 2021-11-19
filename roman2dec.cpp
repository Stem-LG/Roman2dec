#include<iostream>

using std::cout ,std::cin ,std::string ,std::endl;

int value(char s){
    switch(s){
            case 'M': return 1000;
            case 'D': return 500;
            case 'C': return 100;
            case 'L': return 50;
            case 'X': return 10;
            case 'V': return 5;
            case 'I': return 1;
        }
    return -1;
}

bool check(string rom){
    for(auto chr : rom){
        if(value(chr) == -1){
            return false;
        }
    }
    return true;
}

int main(){

    string rom;

    cout<<"please enter a roman number: ";
    do{
        cin>>rom;
        if(check(rom)){
            break;
        }else{
            cout<<"Entered number is incorrect, please try again: ";
        }
    } while (true);
    
    int result = 0;

    for(int i=0;i<rom.size();i++){
            int v1 = value(rom[i]);
            if(i+1 < rom.size()){
                int v2 = value(rom[i+1]);
                if(v1>=v2){
                    result+=v1;
                }else{
                    result = result - v1 + v2;
                    i++;
                }
            }else{
                result+=v1;
            }
    }
    cout<<"result: "<<result<<endl;

    
    
    return 0;
}