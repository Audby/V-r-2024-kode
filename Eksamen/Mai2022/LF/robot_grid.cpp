#include "robot_grid.h"
#include <stdexcept>

// Task G1: drawing grid lines
//
// implement the code for drawing the lines of the robot grid. to
// solve this assignment, use the window.draw_line function to draw
// the lines and the following class-defined variables to determine the
// layout of the grid:
//
//
//  - x_pos and y_pos: the coordinates of the upper-left corner
// of the grid
//  - w_size and h_size: the width and height of the grid
//  - cell_width and cell_height: the width and height of a cell
void RobotGrid::draw_grid_lines()
{
  // BEGIN: G1
  //one solution: (several possible solutions)
  // Draw the vertical lines first
  for (int i = x_pos; i < x_pos + w_size + 1; i = i + cell_width) {
    window.draw_line({i, y_pos}, {i, y_pos + h_size});
  }
  for (int i = y_pos; i < y_pos + h_size + 1; i = i + cell_height) {
    window.draw_line({x_pos, i}, {x_pos + w_size, i});
  }
  
  //another solution:
  int curr_x_pos = x_pos;
  int curr_y_pos = y_pos;
  while(curr_x_pos <= (x_pos+w_size)){
    window.draw_line({curr_x_pos, y_pos}, {curr_x_pos, y_pos+h_size});
    curr_x_pos += cell_width;
  }
  while(curr_y_pos <= (y_pos+h_size)){
    window.draw_line({x_pos, curr_y_pos}, {x_pos+w_size, curr_y_pos});
    curr_y_pos += cell_height;
  }
  // END: G1
}

// Task G2: Get the center of a grid cell
//
// Write a function that, given the x and y coordinates of a
// grid cell, returns the on-screen coordinates of the center of that
// cell. For example, the center of the grid cell  (3, 3) could be located
// (300, 300) pixels from the top-left
// corner of the application window. You can calculate this
// using the same values that you used to solve Assignment  G1.
//
// |     |
// ---+-----+---
// |  x  |
// ---+-----+---
// |     |
//
// To illustrate, the sketch above shows a grid cell. This
// function should return the on-screen coordinates of the
// x.
Point RobotGrid::get_grid_cell_center_coord(int x, int y) const
{
  // BEGIN: G2
  int xp = x_pos + (cell_width * x) + (cell_width / 2);
  int yp = y_pos + (cell_height * y) + (cell_height / 2);
  return {xp, yp};
  
  //or:

  return {x_pos + x*cell_width + cell_width/2, y_pos + y*cell_height + cell_height/2};
  
  //other solutions are also possible
  // END: G2
}

// Task G3: Making a robot
//
// Implement the code for adding a new robot to the grid. You do
// this by making an instance of the Robot class (defined in
// robot.h) and adding it to the robots map. Keep in mind that
// robots is a map from string to unique_ptr&lt;Robot&gt; and
// therefore, you must use the make_unique function when
// instantiating the Robot class.
void RobotGrid::make_robot(string name, Point pos, Color color)
{
  check_name_available(name);
  check_coord_bounds(pos);
  check_coord_empty(pos, name, false);

  // BEGIN: G3
  //Many possible solutions. For instance:
  robots.insert({name,make_unique<Robot>(name, pos, color)});

  //or:
  robots.emplace(name, std::move(make_unique<Robot>(name, pos, color)));

  //or:
  robots[name] = make_unique<Robot>(name, pos, color);
  
  //or:
  auto r = make_unique<Robot>(name, pos, color);
  robots.insert({name, move(r)});
  
  // other solutions are also possible (but make sure that they actually work!)
  // END: G3
}

// Task G4: Drawing the robots
//
// Write the code for representing the robots on the grid. A robot
// is represented by a circle that is drawn within the boundaries of
// the grid cell where the robot is positioned. The circle is filled
// with the color of the robot and the name of the robot is written
// on top of the circle, starting from the left edge of, and
// vertically centered within, the bounding grid cell.
//
// To know where to place the circles representing robots, use the
// get_grid_cell_center_coord function that you implemented
// previously.
void RobotGrid::draw_robots()
{
  // BEGIN: G4
  for(const auto & r : robots){
    window.draw_circle(get_grid_cell_center_coord(r.second->pos),min(cell_height/2.0,cell_width/2.0), r.second->color);
    window.draw_text(get_grid_cell_edge_coord(r.second->pos),r.first);
  }

  //or:
  
  for (auto &[name, robot] : robots) {
    window.draw_circle(get_grid_cell_center_coord(robot->pos),
                       min(cell_width / 2, cell_height / 2) - 1, robot->color);
    window.draw_text(get_grid_cell_edge_coord(robot->pos), robot->name);
  }
  
  //or other working solutions
  // END: G4
}

// Task G5: Deleting a robot
//
// Implement the code for deleting a robot from the grid. Remember
// that the robots that are currently visible on the grid are members
// of the robots map.
void RobotGrid::delete_robot(string name)
{
  check_name_exists(name);

  // BEGIN: G5
  robots.erase(name);
  // END: G5
}

// Task G6: Move a robot
//
// Implement the code for moving a robot. Do this by changing the
// corresponding Robot class instance in the robots.
// map.
void RobotGrid::move_robot(string name, Point pos)
{
  check_name_exists(name);
  check_coord_bounds(pos);
  check_coord_empty(pos, name, true);

  // BEGIN: G6
  robots.at(name)->pos = pos;

  //or:
  
  robots[name]->pos = pos; //Not reccommended

  //other solutions are also possible
  // END: G6
}

// Task G7: Recolor a robot
//
// Implement the code for changing the color of a
// robot.
void RobotGrid::recolor_robot(string name, Color color)
{
  check_name_exists(name);

  // BEGIN: G7
  robots.at(name)->color = color;

  //or:
  
  robots[name]->color = color;

  //other solutions are also possible
  // END: G7
}

// Exercise
// Task G8: Clear the grid
//
// Implement the code for removing all robots from the
// grid.
void RobotGrid::clear_robots()
{
  // BEGIN: G8
  robots.clear();
  // END: G8
}

// Task G9: Rename a robot
//
// Implement the code for renaming a robot. Remember to also change
// the robot's key in the robots array! Thus, there is more to this
// than simply changing the name field of a Robot
// object.
void RobotGrid::rename_robot(string name, string new_name)
{
  check_name_exists(name);
  check_name_available(new_name);

  // BEGIN: G9
  Point pos = robots.at(name)->pos;
  Color col = robots.at(name)->color;
  delete_robot(name);
  make_robot(new_name, pos, col);

  //or:
  
  auto robot = move(robots[name]);
  robots.erase(name);
  robot->name = new_name;
  robots[new_name] = move(robot);
  
  //other solutions are also possible
  // END: G9
}

// Task G10: Checking coordinate bounds
//
// This function checks if the coordinates passed to the function
// as the point p are valid. Valid coordinates are $0 < x < cols$
// and $0 < y < rows$. If coordinates are not valid, the function
// should throw an exception with a descriptive error message.
void RobotGrid::check_coord_bounds(Point p) const
{
  // BEGIN: G10
  //type of exception thrown is not important, but invalid_argument or runtime_error probably make most sense in this case
  if(p.x < 0 || p.x >= cols){
    throw invalid_argument("x coordinate is out of bounds.");
  }
  else if(p.y < 0 || p.y >= rows){
    throw invalid_argument("y coordinate is out of bounds.");
  }

  //or:
  
  if ((p.x < 0 || p.x > cols) || (p.y < 0 || p.y > rows)) {
    throw invalid_argument("Coordinates are out of bounds");
  }
  //other solutions are also possible
  // END: G10
}

// Task G11: Check if robot name is available
//
// This function checks if the name is available for use by a
// robot. This is the case if the value of the parameter name is
// NOT a key in the robots map.
void RobotGrid::check_name_available(string name) const
{
  // BEGIN: G11
  //type of exception thrown is not important, but invalid_argument or runtime_error probably make most sense in this case
  if(robots.find(name) != robots.end()){
    throw invalid_argument("The robot name '" + name + "' is already in use.");
  }

  //or:
  
  if (robots.count(name) > 0) {
    throw invalid_argument("Robot named " + name + " already exists");
  }
  
  //other solutions are also possible
  // END: G11
}

// Task G12: Check if robot exists
//
// This function checks if there exists a robot named name. This
// is the case if the value of name is a key in the robots
// map.
void RobotGrid::check_name_exists(string name) const
{
  // BEGIN: G12
  //type of exception thrown is not important, but invalid_argument or runtime_error probably make most sense in this case
  if(robots.find(name) == robots.end()){
    throw invalid_argument("No robot named '" + name + "' exists.");
  }

  //or:
  
  if (robots.count(name) == 0) {
    throw invalid_argument("Robot named " + name + " does not exists");
  }
  
  //other solutions are also possible
  // END: G12
}

// Task G13: Check if a grid coordinate is empty
//
// This function checks if there is a robot in the grid cell
// corresponding to the coordinates given in the parameterp.  The
// parameter is_moving is set to true when the function is called
// as part of executing the move_robot instruction and false when
// the function is called as part of executing the make_robot
// instruction. name is the name of the robot that is being moved or
// created. The distinction between moving and creating is important
// because we allow a robot to be moved to itself. That is, the
// program
//
// make_robot bob 1 1 blue
// move_robot bob 1 1
//
// is valid whereas the program
//
// make_robot bob 1 1 blue
// make_robot alice 1 1 green
//
// is not.
//
// The function should throw an exception with a descriptive error
// message if a grid cell is already occupied by another robot. Keep
// the ``self move'' exception described above in
// mind.
void RobotGrid::check_coord_empty(Point p, string name, bool is_moving) const
{
  // BEGIN: G13
  //type of exception thrown is not important, but invalid_argument or runtime_error probably make most sense in this case
  for(const auto & r : robots){
    Point curr_pos = r.second->pos;
    if(curr_pos == p){
      if(name != r.first || !is_moving){
        throw invalid_argument("There is already a robot at this position.");
      }
    }
  }

  //or:
  
  for (auto &[k, v] : robots) {
    if (v->pos == p) {
      // We allow self moves to current position
      if (!(v->name == name && is_moving)) {
        throw invalid_argument("Robot " + v->name + " already occupies (" +
                     to_string(v->pos.x) + "," + to_string(v->pos.y) +
                     "). Pick another location for " + name + ".");
      }
    }
  }
  
  //other solutions are also possible
  // END: G13
}

//
// END OF ASSIGNMENTS
//

// Draws the grid lines and the robots
void RobotGrid::draw_universe()
{
  draw_grid_lines();
  draw_robots();
}

// Returns the center coordinate of a grid cell
Point RobotGrid::get_grid_cell_center_coord(Point pos) const
{
  auto [x, y] = pos;
  return get_grid_cell_center_coord(x, y);
}

Point RobotGrid::get_grid_cell_edge_coord(int x, int y) const
{
  int xp = x_pos + (cell_width * x);
  int yp = y_pos + (cell_height * y) + (cell_height / 2);
  return {xp, yp};
}

// Returns the edge coordinate of a grid cell
Point RobotGrid::get_grid_cell_edge_coord(Point pos) const
{
  auto [x, y] = pos;
  return get_grid_cell_edge_coord(x, y);
}

// Initializes the values of the grid
void RobotGrid::make_grid(int rows, int cols)
{
  if (rows == 0 || cols == 0) {
    throw invalid_argument("Arguments of make_grid must be greater than 0");
  }
  // Crashing have been observed for large grids
  if (rows > 100 || cols > 100) {
    throw invalid_argument("Arguments of make_grid must be less than 100");
  }

  this->rows = rows;
  this->cols = cols;
  //the four lines below were wrong in the original handout (mixing of cols and rows), but this error would not have been visible if all tested cases had grids of N*N (square)
  cell_width = target_w_size / cols; 
  cell_height = target_h_size / rows;
  w_size = cell_width * cols;
  h_size = cell_height * rows;

  clear_robots();
}

// Returns the parent application object
TracingApplication &RobotGrid::get_application()
{
  return application;
}

RobotGrid::RobotGrid(AnimationWindow &window, TracingApplication &application,
                     int x, int y, int w, int h, int rows = 1, int cols = 1)
    : window(window), application(application), x_pos(x), y_pos(y),
      target_w_size(w), target_h_size(h), w_size(w), h_size(h), rows(rows),
      cols(cols), cell_width(w_size / rows), cell_height(h_size / rows)
{
}
