#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const string head = "head";
const string body = "body";
const string hand = "hand";
const string legs = "legs";
const string line = "---------------------------------";
const string infile = "armors2.txt";

const double equip = 52.5;
const double weapon_and_shield_weight = 8;
const double rings_weight = (0.3 + 0.7 + 1.5 + 0.8);
const double added_weight = weapon_and_shield_weight + rings_weight;

struct Armor {
    string type;
    string name;
    
    double weight;
    double physical;
    double strike;
    double slash;
    double thrust;
    double magic;
    double fire;
    double lightning;
    double dark;
    double bleed;
    double poison;
    double frost;
    double curse;
    double poise;
    
    Armor(stringstream& ss) {
        ss >> type >> name >> weight >> physical >> strike >> slash >> thrust >> magic >> fire >> lightning >> dark >> bleed >> poison >> frost >> curse >> poise;
    }
    
    double average() {
        return (physical+strike+slash+thrust) / 4.0;
    }
};

struct Set {
    Armor* head;
    Armor* body;
    Armor* hand;
    Armor* legs;
    
    Set(Armor* head_, Armor* body_, Armor* hand_, Armor* legs_) {
        head = head_;
        body = body_;
        hand = hand_;
        legs = legs_;
    }
    
    void print() {
        cout << "Set: " << head->name << ", " << body->name << ", " << hand->name << ", " << legs->name << endl;
        cout << "weight: " << weight() << endl;
        cout << "physical: " << physical() << endl;
        cout << "strike: " << strike() << endl;
        cout << "slash: " << slash() << endl;
        cout << "thrust: " << thrust() << endl;
        cout << "physicalAvg: " << avg() << endl;
        cout << "magic: " << magic() << endl;
        cout << "fire: " << fire() << endl;
        cout << "lightning: " << lightning() << endl;
        cout << "dark: " << dark() << endl;
        cout << "bleed: " << bleed() << endl;
        cout << "poison: " << poison() << endl;
        cout << "frost: " << frost() << endl;
        cout << "curse: " << curse() << endl;
        cout << "poise: " << poise() << endl;
        cout << line << endl;
    }
    
    double weight() const {
        return added_weight + head->weight + body->weight + hand->weight + legs->weight;
    }
    
    double physical() const {
        return head->physical + body->physical + hand->physical + legs->physical;
    }
    
    double strike() const {
        return head->strike + body->strike + hand->strike + legs->strike;
    }
    
    double slash() const {
        return head->slash + body->slash + hand->slash + legs->slash;
    }
    
    double thrust() const {
        return head->thrust + body->thrust + hand->thrust + legs->thrust;
    }
    
    double avg() const {
        return head->average() + body->average() + hand->average() + legs->average();
    }
    
    double magic() const {
        return head->magic + body->magic + hand->magic + legs->magic;
    }
    
    double fire() const {
        return head->fire + body->fire + hand->fire + legs->fire;
    }
    
    double lightning() const {
        return head->lightning + body->lightning + hand->lightning + legs->lightning;
    }
    
    double dark() const {
        return head->dark + body->dark + hand->dark + legs->dark;
    }
    
    double bleed() const {
        return head->bleed + body->bleed + hand->bleed + legs->bleed;
    }
    
    double poison() const {
        return head->poison + body->poison + hand->poison + legs->poison;
    }
    
    double frost() const {
        return head->frost + body->frost + hand->frost + legs->frost;
    }
    
    double curse() const {
        return head->curse + body->curse + hand->curse + legs->curse;
    }
    
    double poise() const {
        return head->poise + body->poise + hand->poise + legs->poise;
    }
};

bool compare_physical(const Set& s1, const Set& s2) {return s1.physical() < s2.physical();}
bool compare_strike(const Set& s1, const Set& s2) {return s1.strike() < s2.strike();}
bool compare_slash(const Set& s1, const Set& s2) {return s1.slash() < s2.slash();}
bool compare_thrust(const Set& s1, const Set& s2) {return s1.thrust() < s2.thrust();}
bool compare_avg(const Set& s1, const Set& s2) {return s1.avg() < s2.avg();}
bool compare_magic(const Set& s1, const Set& s2) {return s1.magic() < s2.magic();}
bool compare_fire(const Set& s1, const Set& s2) {return s1.fire() < s2.fire();}
bool compare_lightning(const Set& s1, const Set& s2) {return s1.lightning() < s2.lightning();}
bool compare_dark(const Set& s1, const Set& s2) {return s1.dark() < s2.dark();}
bool compare_bleed(const Set& s1, const Set& s2) {return s1.bleed() < s2.bleed();}
bool compare_poison(const Set& s1, const Set& s2) {return s1.poison() < s2.poison();}
bool compare_frost(const Set& s1, const Set& s2) {return s1.frost() < s2.frost();}
bool compare_curse(const Set& s1, const Set& s2) {return s1.curse() < s2.curse();}
bool compare_poise(const Set& s1, const Set& s2) {return s1.poise() < s2.poise();}

vector<Armor> head_v;
vector<Armor> body_v;
vector<Armor> hand_v;
vector<Armor> legs_v;
vector<Set> sets;

int main(int argc, const char * argv[]) {
    ifstream is(infile);
    string line;
    while(getline(is, line)) {
        if(line != "break" and line.at(0) != line.at(1)) {
            stringstream ss(line);
            Armor a(ss);
            if (a.type == head) {
                head_v.push_back(a);
            }
            else if (a.type == body) {
                body_v.push_back(a);
            }
            else if (a.type == hand) {
                hand_v.push_back(a);
            }
            else if (a.type == legs) {
                legs_v.push_back(a);
            }
            else {
                cout << "bad line: `" << line << "`" << endl;
                return 0;
            }
        }
    }
    
    
    for(auto head_it = head_v.begin(); head_it != head_v.end(); ++head_it) {
        for(auto body_it = body_v.begin(); body_it != body_v.end(); ++body_it) {
            for(auto hand_it = hand_v.begin(); hand_it != hand_v.end(); ++hand_it) {
                for(auto legs_it = legs_v.begin(); legs_it != legs_v.end(); ++legs_it) {
                    Set set(&(*head_it), &(*body_it), &(*hand_it), &(*legs_it));
                    if ((set.weight() / equip) <= .70 and body_it->name != "Sellsword_Armor") {
                        sets.push_back(set);
                    }
                }
            }
        }
    }
    
    cout << line << endl;
    auto best_magic = max_element(sets.begin(), sets.end(), compare_magic);
    cout << "MAGIC:" << endl;
    best_magic->print();
    
    auto best_fire = max_element(sets.begin(), sets.end(), compare_fire);
    cout << "FIRE:" << endl;
    best_fire->print();
    
    auto best_lightning = max_element(sets.begin(), sets.end(), compare_lightning);
    cout << "LIGHTNING:" << endl;
    best_lightning->print();
    
    auto best_dark = max_element(sets.begin(), sets.end(), compare_dark);
    cout << "DARK:" << endl;
    best_dark->print();
    
    auto best_bleed = max_element(sets.begin(), sets.end(), compare_bleed);
    cout << "BLEED:" << endl;
    best_bleed->print();
    
    auto best_poison = max_element(sets.begin(), sets.end(), compare_poison);
    cout << "POISON:" << endl;
    best_poison->print();
    
    auto best_frost = max_element(sets.begin(), sets.end(), compare_frost);
    cout << "FROST:" << endl;
    best_frost->print();
    
    auto best_curse = max_element(sets.begin(), sets.end(), compare_curse);
    cout << "CURSE:" << endl;
    best_curse->print();
    
    auto best_poise = max_element(sets.begin(), sets.end(), compare_poise);
    cout << "POISE:" << endl;
    best_poise->print();
    
    auto best_physical = max_element(sets.begin(), sets.end(), compare_physical);
    cout << "PHYSICAL:" << endl;
    best_physical->print();
    
    auto best_strike = max_element(sets.begin(), sets.end(), compare_strike);
    cout << "STRIKE:" << endl;
    best_strike->print();
    
    auto best_slash = max_element(sets.begin(), sets.end(), compare_slash);
    cout << "SLASH:" << endl;
    best_slash->print();
    
    auto best_thrust = max_element(sets.begin(), sets.end(), compare_thrust);
    cout << "THRUST:" << endl;
    best_thrust->print();
    
    auto best_avg = max_element(sets.begin(), sets.end(), compare_avg);
    cout << "AVG. PHYSICAL:" << endl;
    best_avg->print();
}
