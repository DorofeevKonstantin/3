
class Logic // Controller
{
public:
	bool isWin() { return true; };
}; 

class Field // Model
{ 
public: 
	void setHero() {};
}; 

class Drawer // View
{
public: 
	void draw() {};
}; 

class Game // Facade - единая точка входа в систему
{
	Logic myLogic;
	Field myField;
	Drawer myDraw;

public:
	Logic& getLogic() { return myLogic; }
	Field& getField() { return myField; }
	Drawer& getDrawer() { return myDraw; }
	//...
};

int FacadeExample()
{
	Game game;
	if (game.getLogic().isWin())
		game.getDrawer().draw();
	return 0;
}