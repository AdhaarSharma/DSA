#include <iostream>

class Player{
    private:
    std::string name;
    int health;
    int xp;
  
    public:
    std::string get_name(){return name;}
    int get_health(){return health;}
    int get_xp(){return xp;}
    Player(std::string name = "None", int health = 0, int xp = 0);
    Player(const Player &source);
    ~Player(){std::cout<<"Destructor called for: "<<name;}
};

Player::Player(std::string name_val, int health_val, int xp_val)
    :name{name_val}, health{health_val}, xp{xp_val}{
        std::cout<<"Three arg constructor called for "+name<<std::endl;
    }
    
Player::Player(const Player &source)
    :name{source.name}, health{source.health}, xp{source.xp}{
        std::cout<<"Copy constructor called for:"+source.name<<std::endl;
    }
    
void display_player(Player p){
    std::cout<<"Name: "<<p.get_name()<<std::endl;
    std::cout<<"Health: "<<p.get_health()<<std::endl;
    std::cout<<"XP: "<<p.get_xp()<<std::endl;
}

int main()
{
	Player empty;
    Player anotherPlayer{empty};
    display_player(anotherPlayer);
}
