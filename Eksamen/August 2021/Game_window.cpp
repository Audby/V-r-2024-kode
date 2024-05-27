#include "Game_window.h"


// The game window spawns at the center of the screen
Game_window::Game_window(int board_size,
                         int win_value,
                         int tile_size,
                         const std::string& title)
	: AnimationWindow(this->width() / 2 - board_size * tile_size / 2,  
			 this->height() / 2 - board_size * tile_size / 2,
             board_size * tile_size,
             board_size * tile_size,
             title),
	  game{board_size},
	  board_size{board_size},
	  tile_s{tile_size},
	  quitBtn{TDT4102::Point{width()-tile_size*4, height()/2-tile_size}, (unsigned)tile_size*2, (unsigned)tile_size/2, "Quit" },
	  resetBtn{TDT4102::Point{width()-tile_size*2, height()/2-tile_size}, (unsigned)tile_size*2, (unsigned)tile_size/2, "Reset"}
{
	// Default font for the graphics in this window
	// fl_font(cell_font, font_size);

	// const TDT4102::Point board_tl{width() / 2 - board_size / 2 * tile_size,
	//                      height() / 2 - board_size / 2 * tile_size};

	const TDT4102::Point board_tl{width() / 2 - board_size * tile_size / 2,
	                     height() / 2 - board_size * tile_size / 2};

	// board_sizeXboard_size board
	for (int y = 0; y < board_size; ++y) {
		graphical_tiles.emplace_back();
		for (int x = 0; x < board_size; ++x) {
			TDT4102::Point pos{board_tl.x + x * tile_size, board_tl.y + tile_size * y};
			graphical_tiles.back()
				.emplace_back(std::make_unique<Tile>(pos, tile_size, win_value))
				->attach_to(*this);
		}
	}
	add(quitBtn);
	add(resetBtn);
	quitBtn.setVisible(false);
	resetBtn.setVisible(false);
	quitBtn.setCallback(std::bind(&Game_window::cb_quit, this));
	resetBtn.setCallback(std::bind(&Game_window::cb_reset, this));
	update();
}

void Game_window::run() {
    while(!should_close()) {
        handleInput();
    }
}

void Game_window::reset()
{
	game.new_game();
	run();
	
}

void Game_window::reset_or_quit(const std::string& text)
{
	hide_tiles();
	quitBtn.setVisible(true);
	resetBtn.setVisible(true);
	draw_text(TDT4102::Point{0, height()/2 - tile_s*2}, text);
 
}

void Game_window::update_tiles()
{
	try {
		for (int y = 0; y < board_size; ++y) {
			for (int x = 0; x < board_size; ++x) {
				update_tile(x, y, game.value(x, y));
			}
		}
	} catch (std::out_of_range& e) {
		std::string error =
			"[Debug] We tried to read outside the playing board:\n" +
			std::string{e.what()};
	}
}
void Game_window::update()
{
	update_tiles();
	check_status();
	next_frame();
}

void Game_window::debug_update() { update_tiles(); }

void Game_window::check_status()
{
	if (game.win()) {
		reset_or_quit("Congratulations, you won the game!");
	} else if (game.game_over()) {
		reset_or_quit("Game over!");
	}
}

void Game_window::update_tile(int x, int y, int value)
{
	auto&& rect = graphical_tiles[y][x];
	rect->set_value(value);
}

// Capture key presses and pass to action functions
void Game_window::handleInput()
{
	if (is_key_down(KeyboardKey::UP)) {
		game.move(Direction::up);
	
	}
	if (is_key_down(KeyboardKey::RIGHT)) {
		game.move(Direction::right);
	
	}
	if (is_key_down(KeyboardKey::DOWN)) {
		game.move(Direction::down);

	}
	if (is_key_down(KeyboardKey::LEFT)) {
		game.move(Direction::left);

	}
	update();

	// For convenience
	// Reset window
	if (is_key_down(KeyboardKey::R)) {
		reset();
	}

	// All tiles = 2
	if (is_key_down(KeyboardKey::D)) {
		insert_two_tiles();
	}

	// Tiles in increasing values
	if(is_key_down(KeyboardKey::I)){
		insert_increasing_tiles();
	}
	
	if(is_key_down(KeyboardKey::H)){
		hide_tiles();
	}

	// Tiles for testing push and merge
	if(is_key_down(KeyboardKey::P)) {
		insert_push_merge_tiles();
	}	

	if(is_key_down(KeyboardKey::T)) {
		debug_transpose_tiles();
	}

	if (is_key_down(KeyboardKey::F)) {
		debug_flip_tiles();
	}

	// Quit
	if (is_key_down(KeyboardKey::Q)) {
		close();
	}
	
}

void Game_window::insert_two_tiles()
{
	game.debug_all_twos();
	debug_update();
};

void Game_window::insert_increasing_tiles()
{
	game.debug_increasing();
	debug_update();
};

void Game_window::insert_push_merge_tiles()
{
	game.debug_push_merge();
	debug_update();
}

void Game_window::debug_transpose_tiles()
{
	game.debug_transpose();
	debug_update();
};
void Game_window::debug_flip_tiles()
{
	game.debug_flip();
	debug_update();
};

void Game_window::hide_tiles() {
	for (auto& v : graphical_tiles) {
		for (auto& t : v) {
			t->hide();
		}
	}
}

void Game_window::cb_quit() {
	close();
}

void Game_window::cb_reset() {
	reset();
}