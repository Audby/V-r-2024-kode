#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "bouncingBall.h"
#include <map>

constexpr Point BOUNCE_WINDOW_TOP_LEFT{50, 50};
constexpr int BOUNCE_WINDOW_WIDTH{800}; 
constexpr int BOUNCE_WINDOW_HEIGHT{500};

struct Config {
    int color_up = 1;
    int color_down = 2;
    int velocity = 5;

    friend ostream& operator<<(ostream& os, const Config& cfg);
};

map<int, string> colorMap {
    {1, "Rød"},
    {2, "Grønn"},
    {3, "Blå"},
    {4, "Gul"}
};

string getColor(int colorCode) {
    return colorMap[colorCode];
}

istream& operator>>(istream& is, Config& cfg) {
    is >> cfg.color_up >> cfg.color_down >> cfg.velocity;
    return is;
}

ostream& operator<<(ostream& os, const Config& cfg) {
    os << "Color Up: " << cfg.color_up
    << ", Color Down: " << cfg.color_down 
    << ", Velocity: " << cfg.velocity;
    return os;
}

void loadConfigurations(const string& filename) {
    ifstream configFile(filename);
    if (!configFile) {
        cerr << "Kunne ikke åpne fila" << endl;
        return;
    }
    Config slowConfig, fastConfig;
    configFile >> slowConfig >> fastConfig;

    cout << "Treg konfigurasjon: " << slowConfig << endl;
    cout << "Rask konfigurasjon: " << fastConfig << endl;

    configFile.close();
}

Config slowConfig{1,2,5};
Config fastConfig{3,4,10};

void bouncingBall() {
    AnimationWindow window{BOUNCE_WINDOW_TOP_LEFT.x, BOUNCE_WINDOW_TOP_LEFT.y, 
                           BOUNCE_WINDOW_WIDTH, BOUNCE_WINDOW_HEIGHT, "Bouncing ball"};
    
    const int radius{30};
    int alpha{1};
    int velocity{2};
    Color colour_up{Color::blue};
    Color colour_down{Color::blue};
    int x{0};
    int y{360};
    int increment_x{0};
    int increment_y{0};
    int count_bounce_top{0};
    int count_bounce_bottom{0};
    int count_num_passes{0};

    // read from configuration file
    loadConfigurations("konfigurasjon.txt");

    // initialise the run
    Config currentConfig = slowConfig;

    increment_y = velocity * sin(alpha);

    Config farge;

    while (!window.should_close()) {
        // determine increments based on the velocity
        increment_x = velocity * cos(alpha);

        // movement i x-direction
        if ((increment_x + x) > window.width()) {
            // reached right side - wrap around to the leftmost
            x = 0;
            // increment counter which counts number of full left-to-right passes
            count_num_passes++;
            // alternate between slow and fast configuration every fifth pass
            if (count_num_passes % 5 == 0) {
                // change configuration
                // update both velcity and colors
                currentConfig = (currentConfig.velocity == slowConfig.velocity) ? fastConfig : slowConfig;
                velocity = currentConfig.velocity;
                string colour_up = getColor(currentConfig.color_up);
                string colour_down = getColor(currentConfig.color_down);
            }
        } else {
            // moving rightwards
            x += increment_x;
        }

        y += increment_y;

        if (y >= window.height() - radius || y <= radius) {
            increment_y = -increment_y;
        }
        
        string colorName;
        if (increment_y > 0) {
            colorName = getColor(currentConfig.color_down); // Ballen beveger seg nedover
        } else {
            colorName = getColor(currentConfig.color_up); // Ballen beveger seg oppover
        }

        Color ballColor;
        if (colorName == "Rød") {
            ballColor = Color::red;
        } else if (colorName == "Grønn") {
            ballColor = Color::green;
        } else if (colorName == "Blå") {
            ballColor = Color::blue;
        } else if (colorName == "Gul") {
            ballColor = Color::yellow;
        } else {
            ballColor = Color::black; // Standardfarge hvis ingen match
        }

        // movement i y-direction
        /*
        if (((count_bounce_top + count_bounce_bottom) % 2) == 0) {
            // move upwards
            if (y < 0) {
                y += increment_y;
            }
        */

        Point position {x, y};
        window.draw_circle(position, radius, ballColor);
        window.next_frame();

    }
}

