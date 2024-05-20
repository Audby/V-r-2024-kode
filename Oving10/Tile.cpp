#include "Tile.h"



// For aa sette Tilelabel i henhold til state
const std::map<Cell, std::string> cellToSymbol{{Cell::closed, ""},
									 			{Cell::open, ""},
									 	  		{Cell::flagged, "|>"}};

Tile::Tile(TDT4102::Point pos, int size) : 
	Button({pos.x, pos.y}, 1.5*size, size, "") {
		setButtonColor(TDT4102::Color::silver);
	}

void Tile::open()
{
	if (getState() == Cell::closed) {
		setButtonColor(TDT4102::Color::white);
		Cell state = Cell::open;
		if (isMine) {
			setLabel("X");
			setLabelColor(TDT4102::Color::red);
		}
	}
}

void Tile::flag()
{
	if (getState() == Cell::flagged) {
		Cell state = Cell::closed;
		setLabel(cellToSymbol.at(Cell::closed));
	}
	else {
		Cell state = Cell::flagged;
		setLabel(cellToSymbol.at(Cell::flagged));
		setLabelColor(TDT4102::Color::black);
	}
}

bool Tile::getIsMine() {
	return isMine;
}

void Tile::setIsMine(bool newIsMine) {
	isMine = newIsMine;
}

void Tile::setAdjMines(int n) {
	setLabel(std::to_string(n));
	setLabelColor(minesToColor.at(n));
}

