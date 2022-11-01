#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {

  /* Enter your code here */
    Fireball* fireball = dynamic_cast<Fireball*>(spell);
    Frostbite* frostbite = dynamic_cast<Frostbite*>(spell);
    Waterbolt* waterbolt = dynamic_cast<Waterbolt*>(spell);
    Thunderstorm* thunderstorm = dynamic_cast<Thunderstorm*>(spell);
    
    if(fireball != nullptr) {
        fireball->revealFirepower();
    } else if(frostbite != nullptr) {
        frostbite->revealFrostpower();
    } else if(waterbolt != nullptr) {
        waterbolt->revealWaterpower();
    } else if(thunderstorm != nullptr) {
        thunderstorm->revealThunderpower();
    } else {
        string spellName = spell->revealScrollName();
        string spellJournal = SpellJournal::read();
        int spellNameSize = spellName.size();
        int spellJournalSize = spellJournal.size();
        int countMatrix[spellNameSize][spellJournalSize];
        for(int i = 0; i < spellNameSize; i++) {
            for(int j = 0; j < spellJournalSize; j++) {
                if(spellName[i] == spellJournal[j]) {
                    if(i != 0 && j != 0)
                        countMatrix[i][j] = countMatrix[i-1][j-1] + 1;
                    else {
                        countMatrix[i][j] = 1;
                    }
                } else {
                    if(i == 0) {
                        if(j == 0) {
                            countMatrix[i][j] = 0;
                        } else {
                            countMatrix[i][j] = countMatrix[i][j-1];
                        }
                    } else {
                        if(j == 0) {
                            countMatrix[i][j] = countMatrix[i-1][j];
                        } else {
                            countMatrix[i][j] = max(countMatrix[i][j-1], countMatrix[i-1][j]);
                        }
                    }
                }
                //cout << "[" << spellName[i] << ", " << spellJournal[j] << "]: [" << i << ", " << j << "]= " << countMatrix[i][j] << endl;
            }
        }
        cout << countMatrix[spellNameSize-1][spellJournalSize-1] << endl;
    }
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}