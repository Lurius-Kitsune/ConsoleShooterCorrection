#include "Main.h"
#include "GameWar.h"
int main()
{
    
    //ShapeExcercice();

    /// Mon jeu Thomas vs Marguerite Apocalypse

    /*
    - Une arme: tire, recharge, a des munition (si à cours, ont la jette si ont veut)
    - Ont peut rammasser des munition quand on tue (augmente le magazine)
    le magazine a un maximl (800 munition max); 
    - Un soldat : à DES ARMES, peut ramasser des armes, fuir, recharger, 
    - L'ia : fait des actinon aléatoire quand c'est à son tours, 
     a des chance de loot une arme quand il fuit/meurt


    Déroulement :

    Tour par tour ? Choix de l'action, le tour prend fin quand tu tire, 
    jette l'arme ou fuit.

    On considère que l'ennemi est vaincu quand il fuit ou meurt
    */

    Weapon** _weapons = new Weapon * [1]
    {
        new Weapon("Salimata", 100, 2, 10, 300)
    };

    GameWar _game = GameWar(RainbowString("Thomas"), 100.00f, new Weapon(RainbowString("Thomatos"), 1, 1, 100, 2), _weapons, 1);
	_game.LaunchGame();
    //delete _soldier;
    return EXIT_SUCCESS;
}

void HeritageDecouvert()
{
    //Animal _animal;
    Dog* _dog = new Dog("TrouDuc", 100.0f, 20.0);
    SickDog* _sickDog = new SickDog("Deldu", 3, 100.0f, 20.0, "BOB");

    //_animal.Sleep();
    _sickDog->Sleep(); // Masquage !

    _dog->Bark();
    _sickDog->Bark(); // Demasquagee !

    //_animal.Introduce();
    _dog->Introduce();
    _sickDog->Introduce();


    delete _dog;
    delete _sickDog;
}

void TestShape(Shape* _shape)
{
    Square* _square = dynamic_cast<Square*>(_shape);
    // Dynamic cast -> convertit classe poly en classe fille
    if (_square)
    {
        _square->Bob();
    }
}

void ShapeExcercice()
{
    Square _square = Square(3.00f, PURPLE);
    Rectangle _rectangle = Rectangle(5.00f, 12.00f, YELLOW);
    Circle _circle = Circle(6.00f, RED);

    struct ShapeData
    {
        string name;
        Shape* shape; // pointeur pour les mettre a la "meme taille"
    };

    ShapeData _shapesData[] =
    {
        {"Carrée" , new Square(3.00f, PURPLE)},
        {"Rectangle", new Rectangle(5.00f, 12.00f, YELLOW)},
        {"Cercle", new Circle(6.00f, RED)}
    };

    const u_int _shapesDataCount = sizeof(_shapesData) / sizeof(ShapeData);

    for (u_int _i = 0; _i < _shapesDataCount; _i++)
    {
        const ShapeData& _shapeData = _shapesData[_i];
        _shapeData.shape->Introduce(_shapeData.name);

        TestShape(_shapeData.shape);

        delete _shapeData.shape;
    }

    //delete _color;
}
