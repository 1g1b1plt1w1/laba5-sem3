#include "ThroneInheritance.h"
using namespace std;

ostream& operator << (ostream& os, const vector<string>& str) {
    for (int i = 0; i < (int)str.size() - 1; i++)
        os << str[i] << " ";
    if (!str.empty())
        os << str.back();
    return os;
}

bool ThroneInheritance::name_tester(const string& n) {
    int sz = n.size();
    return (1 <= sz && sz <= 15);
}

void ThroneInheritance::dfs(const string& name, vector<string>& order) const {
    auto it = people.find(name);
    if (it == people.end()) return;

    const Person& p = it->second;

    if (p.aliveStatus)
        order.push_back(name);

    for (const string& childName : p.children)
        dfs(childName, order);
}

ThroneInheritance::ThroneInheritance(const string& kingName_) : kingName(kingName_) {
    if (!name_tester(kingName)) {
        throw out_of_range("Превышена длина имени короля.");
    }
    Person king;
    king.kingStatus = true;
    king.parent = "";
    people[kingName] = king;
}

ThroneInheritance::~ThroneInheritance() {
    delete[] curOrder;
}

void ThroneInheritance::birth(const string& parentName, const string& childName) {
    if (!name_tester(parentName) || !name_tester(childName)) {
        throw out_of_range("Превышена длина имени.");
    }

    auto it = people.find(parentName);
    if (it == people.end()) {
        throw invalid_argument("Не найден родитель.");
    }

    Person child;
    child.parent = parentName;
    people[childName] = child;
    it->second.children.push_back(childName);
}

void ThroneInheritance::death(const string& deadName) {
    auto it = people.find(deadName);
    if (it == people.end()) {
        throw invalid_argument("Не найдено имя умершего.");
    }
    it->second.aliveStatus = false;
}

vector<string> ThroneInheritance::getInheritanceOrder() {
    vector<string> order;
    dfs(kingName, order);

    delete[] curOrder;
    curSize = (int)order.size();
    curOrder = new string[curSize];

    for (int i = 0; i < curSize; ++i)
        curOrder[i] = order[i];

    return order;
}
