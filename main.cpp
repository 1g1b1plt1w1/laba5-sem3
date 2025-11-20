#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "ThroneInheritance.h"
using namespace std;


int main() {
    try{
        ThroneInheritance t("king"); // order: king
        t.birth("king", "andy"); // order: king > andy;
        t.birth("king", "bob"); // order: king > andy > bob;
        t.birth("king", "catherine"); // order: king > andy > bob > Catherine;
        t.birth("andy", "matthew"); // order: king > andy > matthew > bob >Catherine;
        t.birth("bob", "alex"); // order: king > andy > matthew > bob > alex >Catherine;
        t.birth("bob", "asha"); // order: king > andy > matthew > bob > alex >asha > Catherine;
        cout << t.getInheritanceOrder() << endl; // return ["king", "andy", "matthew", "bob","alex", "asha", "catherine"];
        t.death("bob"); // order: king > andy > matthew > bob > alex > asha >Catherine;
        cout << t.getInheritanceOrder() << endl; // return ["king", "andy", "matthew", "alex","asha", "catherine"].
    }
    catch(const exception& e){
        cerr << "Ошибка! " << e.what();
    }
}
