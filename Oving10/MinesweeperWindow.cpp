#include "MinesweeperWindow.h"
#include <iostream>
#include <random>

MinesweeperWindow::MinesweeperWindow(int x, int y, int width, int height, int mines, const string &title) : 
	// Initialiser medlemsvariabler, bruker konstruktoren til AnimationWindow-klassen
	AnimationWindow{x, y, width * cellSize, (height + 1) * cellSize, title},
	width{width}, height{height}, mines{mines}
{
	// Legg til alle tiles i vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			tiles.emplace_back(new Tile{ Point{j * cellSize, i * cellSize}, cellSize});
			tiles.back()->setCallback(std::bind(&MinesweeperWindow::cb_click, this));
			auto temp = tiles.back().get();
			add(*temp); 
		}
	}
	// Legg til miner paa tilfeldige posisjoner
	int placedMines = 0;
	while (placedMines < mines) {
		random_device rd;
		default_random_engine generator(rd());
		uniform_int_distribution<int> distribution(0,tiles.size()-1);
		int tilePosition = distribution(generator);
		auto& tile = tiles[tilePosition];
		if (!tile->getIsMine()) {
			tile->setIsMine(true);
			placedMines++;
		}
	}
}

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}
	return points;
}

void Tile::colorFromMines(int numMines) {
	set_label_color(minesToColor.at(numMines));
}

void MinesweeperWindow::openAdjacentTiles(Point xy) {
    vector<Point> adjacentPoints = this->adjacentPoints(xy);
    for (Point p : adjacentPoints) {
        auto& tile = at(p);
        if (tile->getState() == Cell::closed && !tile->getIsMine()) {
            tile->open();
            int numMines = countMines(this->adjacentPoints(p));
            if (numMines == 0) {
                openAdjacentTiles(p);
            } else {
                tile->setAdjMines(numMines);
            }
        }
    }
}

void MinesweeperWindow::openTile(Point xy) {
	auto& tile = at(xy);
	if (tile->getState() == Cell::closed) {
		tile->open();
	}
	if (!tile->getIsMine()) {
		const vector<Point> surroundingPoints = adjacentPoints(xy);
		int numMines = countMines(surroundingPoints);
		if (numMines > 0) {
			tile->setLabel(to_string(numMines));
			tile->colorFromMines(numMines);
		}
		else {
			openAdjacentTiles(xy);
		}
	}
	else {
		AnimationWindow window;
		window.draw_text(xy, "Lol");

	}
	
}

void MinesweeperWindow::flagTile(Point xy) {
	auto& tile = at(xy);
	if (tile->getState() == Cell::closed) {
		tile->flag();
	}
	else if (tile->getState() == Cell::flagged) {
		tile->flag();
	}
	
}

int MinesweeperWindow::countMines(vector<Point> coords) const {
	int numMines = 0;
	for (int i=0; i<coords.size(); i++) {
		auto& tile = at(coords[i]);
		if (tile->getIsMine()) {
			numMines++;
		}
	}
	return numMines;
}


//Kaller openTile ved venstreklikk og flagTile ved hoyreklikk
void MinesweeperWindow::cb_click() {
	
	Point xy{this->get_mouse_coordinates()};

	if (!inRange(xy)) {
		return;
	}
	if (this->is_left_mouse_button_down()) {
		openTile(xy);
	}
	else if(this->is_right_mouse_button_down()){
		flagTile(xy);
	}
}
