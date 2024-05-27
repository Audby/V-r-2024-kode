#include "Game.h"

Game::Game(int board_size, int win_value)
	: board_size(board_size),
	  board(board_size * board_size),
	  win_value{win_value}
{
	new_game();
}

// TASK
int Game::index(int x, int y) const
{
	// BEGIN: G1
	return x + y*board_size;
	// END: G1
}

// TASK
int Game::at(int x, int y) const
{
	// BEGIN: G2
	if (x < 0 || x > board_size || y < 0 || y > board_size) {
		throw std::runtime_error("Coordinates out of range");
	}
	return board[index(x,y)];

	// END: G2
};

// TASK
int& Game::at(int x, int y)
{
	// BEGIN: G3
	if (x < 0 || x > board_size || y < 0 || y > board_size) {
		throw std::runtime_error("Coordinates out of range");
	}
	return board[index(x,y)];
	// END: G3
}

// TASK
void Game::new_game()
{
	// BEGIN: G4
	for (auto &b : board) {
		this->board[b] = 0;
	}
	// END: G4
	place_new_2();
	place_new_2();
}

// TASK
// Prerequisites: board does have a free 0-spot
void Game::place_new_2()
{
	// BEGIN: G5
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_int_distribution<int> distribution(0, board_size * board_size-1);
	int number = distribution(generator);
	while (board[number] == 2) {
		int number = distribution(generator);
	}
	board[number] = 2;
	// END: G5
}

// TASK
void Game::flip()
{
	// BEGIN: G6
	int placeHolder = 0;
	double checkMiddle = board_size / 2;
	for (int i = 0; i<board_size; ++i) {
		for (int j = 0; j < checkMiddle; ++j) {
			placeHolder = board[index(i,j)];
			board[index(i,j)] = board[index(i,board_size- 1 - j)]; 
			board[index(i,board_size- 1 - j)] = placeHolder;
		}
		
	}
	// END: G6
}

// TASK
void Game::transpose()
{
	// BEGIN: G7
	for (int i = 0; i<board_size; ++i) {
		for (int j = i; j < board_size; ++j) {
			std::swap(at(i,j), at(j,i));
		}
	}
	// END: G7
}

// TASK
void Game::push_right()
{
	// BEGIN: G8
	std::vector<int> values;
	for (int y = 0; y<board_size; ++y) {
		for (int x = 0; x < board_size; ++x) {
			int current_value = board[index(x,y)];
			if (value != 0) {
				values.push_back(current_value);
			}
		}
		int numZeros = board_size - values.size();
		for (int i = 0; i < numZeros; ++i) {
			values.insert(values.begin(),0);
		}

		for (int x = 0; x < board_size; ++x) {
			at(x,y) = values[x];
		}
		}
	
	// END: G8
}

// TASK
void Game::merge_right()
{
	// BEGIN: G9
	for (int y = 0; y < board_size; ++y) {
		for (int x = 1; x < board_size; ++x) {
			int current = board[index(board_size - x, y)];
			int next = board[index(board_size-x -1, y)];
			if (current == next) {
				current = 2* current;
				next = 0;
			}
		}
	}
	// END: G9
}

// TASK
void Game::move_right()
{
	// BEGIN: G10
	push_right();
	merge_right();
	push_right();
	// END: G10
}

// TASK
void Game::move_down()
{
	// BEGIN: G11
	transpose();
	move_right();
	transpose();
	// END: G11
}

// TASK
void Game::move_left()
{
	// BEGIN: G12
	flip();
	move_right();
	flip();
	// END: G12
}

// TASK
void Game::move_up()
{
	// BEGIN: G13
	flip();
	transpose();
	move_right();
	transpose();
	flip();
	// END: G13
}

// TASK
bool Game::free_spots() const
{
	// BEGIN: G14
	for (int y = 0; y < board_size; ++y) {
		for (int x = 0; x < board_size; ++x) {
			if (board[index(x,y)] == 0) {
				return true;
			}
		}
	}
	return false;
	// END: G14
}

// TASK
void Game::tick()
{
	// BEGIN: G15
	if (moved && free_spots()) {
		place_new_2();
	}
	// END: G15
}

// TASK
bool Game::win() const
{
	// BEGIN: G16
	for (auto b : board) {
		if (b == win_value) {
			return true;
		}
	}
	return false;
	// END: G16
}

// TASK
// Prerequisites: all tiles are non-zero
bool Game::legal_moves() const
{
	// BEGIN: G17
	for (int y = 0; y < board_size; ++y) {
		for (int x = 0; x < board_size; ++x) {
			if (at(x,y) == at(x+1, y)) {
				return true;
			}
		}
	}

	for (int x = 0; x < board_size; ++x) {
		for (int y = 0; y < board_size; ++y) {
			if (at(x,y) == at(x, y+1)) {
				return true;
			}
		}
	}
	return false;
	// END: G17
}



/**** Provided code ****/

// API version of tile value - const external interface
int Game::value(int x, int y) const { return at(x, y); }

// This function keeps track of changes to the board
// and calls the move function requested by the player
void Game::move(Direction direction)
{
	// We have not moved any tiles yet
	moved = false;

	// Keep the old board matrix for comparison
	std::vector<int> old_board{board};

	if (status() == Status::playing) {
		switch (direction) {
		case Direction::up:
			move_up();
			break;
		case Direction::right:
			move_right();
			break;
		case Direction::down:
			move_down();
			break;
		case Direction::left:
			move_left();
			break;
		}
	}

	// Did we move anything?
	if (board != old_board) {
		moved = true;
	}

	tick();
}

// We use this to figure out if a game
// is won, game over or if the player still
// can play legal moves
Game::Status Game::status() const
{
	if (win()) {
		return Status::win;
	}

	if (free_spots() || legal_moves()) {
		return Status::playing;
	}

	return Status::game_over;
}

bool Game::game_over() const { return status() == Status::game_over; }

std::ostream& operator<<(std::ostream& os, const Game& g)
{
	for (int i = 0; i < g.board_size; ++i) {
		for (int j = 0; j < g.board_size; ++j) {
			std::cout << g.at(j, i) << " ";
		}
		std::cout << '\n';
	}

	return os;
}

// Debug methods - debug API
void Game::debug_all_twos()
{
	static const std::array<int, 16> debug_board_all_twos{
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};

	std::copy(debug_board_all_twos.begin(),
	          debug_board_all_twos.end(),
	          board.begin());
	tick();
}

void Game::debug_increasing()
{
	static const std::array<int, 16> debug_board_increasing{
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

	std::copy(debug_board_increasing.begin(),
	          debug_board_increasing.end(),
	          board.begin());
	tick();
}

void Game::debug_push_merge()
{
	// clang-format off
	static const std::array<int, 16> debug_board_push_merge{
		2,0,2,0,
		0,2,2,4,
		0,2,2,2,
		8,8,8,8
	};
	// clang-format on

	std::copy(debug_board_push_merge.begin(),
	          debug_board_push_merge.end(),
	          board.begin());
	tick();
}

void Game::debug_flip() { flip(); }
void Game::debug_transpose() { transpose(); }
