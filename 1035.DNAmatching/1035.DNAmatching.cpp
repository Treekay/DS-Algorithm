#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool match(string deo1, string deo2){
    if (deo1.size() != deo2.size()) return false;
    for (int index = 0; index < deo1.size(); index++){  
        switch(deo1[index]){
            case 'A':
                if (deo2[index] != 'T') return false;
                break;
            case 'T':
                if (deo2[index] != 'A') return false;
                break;
            case 'C':
                if (deo2[index] != 'G') return false;
                break;
            case 'G':
                if (deo2[index] != 'C') return false;
                break;
            default:
                return false;
        }
    }
    return true;
}

typedef struct {
    string dna;
    bool matched;
}acid;

int main(){
    int test_cases;
    cin >> test_cases;
    while (test_cases--){
        int num;
        cin >> num;
        vector<acid> acid_collect;
        int count(0);
        for (int index = 0; index < num; index++){
            acid newone;
            newone.matched = false;
            cin >> newone.dna;
            acid_collect.push_back(newone);
        }
        for (int index = 0; index < num; index++){
            for (int pointer = index + 1; pointer < num; pointer++){
                if (!acid_collect[index].matched &&
                    !acid_collect[pointer].matched &&
                    match(acid_collect[index].dna, acid_collect[pointer].dna)) {
                    count++;
                    acid_collect[index].matched = acid_collect[pointer].matched = true;
                    break;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}