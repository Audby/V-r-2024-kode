#include "interpreter.h"
#include "robot_grid.h"
#include <FL/fl_ask.H>
#include <exception>
#include <functional>
#include <optional>
#include <sstream>
#include <string>

// Task S1: Color name mapping
//
// This function takes the name of a color as its argument and
// returns the corresponding Graph_lib color type. This function is
// needed to convert the color names given as strings in the
// instruction code to the internal color representation used by the
// graphics library. We provide the map color_map, defined in
// interpreter.h that contains all valid mappings between color
// names and color types. Your task in this assignment is to write a
// function that looks up the color_name in the color_map map
// and, if the map lookup fails, for example if color_name doesn't
// exist, the function should throw a descriptive error
// message.
Graph_lib::Color::Color_type Interpreter::get_color(string color_name)
{
  // BEGIN: S1
  //type of exception thrown is not important, but invalid_argument or runtime_error probably make most sense in this case
  if(color_map.find(color_name) == color_map.end()){
    throw invalid_argument("The color '" + color_name + "' is not a valid color in this universe.");
  }
  return color_map.at(color_name);
  //or:
  /*
  auto it = color_map.find(color_name);
  if (it == color_map.end()) {
    throw runtime_error("unknown color '" + color_name + "'");
  }
  return it->second;
  */
  //or:
  /*
  if (color_map.count(color_name)) {
    return color_map[color_name];
  } else {
    throw invalid_argument("Color " + color_name + " is undefined");
  }
  */
  //other solutions are also possible
  // END: S1
}

// Task S2: Instruction interpretation
//
// The interpreter function reads an instruction (refer to the table in
// the assignment PDF for a description) and calls the
// corresponding function in the RobotGrid class to perform the
// requested action for changing the universe
//
// This function is called once for every instruction in the program
// meaning that for the following control script
//
// make_robot foo 1 1 blue
// delete_robot bar
//
// this function is called twice where the instruction argument is
// an istringstream containing each line of the program. Thus,
// the evaluation of the control script above is equivalent to the
// following two calls to execute_instruction
//
// execute_instruction(istringstream("make_robot foo 1 1 blue"));
// execute_instruction(istringstream("delete_robot bar"));
void Interpreter::execute_instruction(istringstream instruction)
{
  // BEGIN: S2
  string instr;
  instruction >> instr;
  if (instr == "make_grid") {
    int rows;
    int cols;

    instruction >> rows;
    instruction >> cols;

    grid.make_grid(rows, cols);

  } else if (instr == "make_robot") {
    string robot_name;
    string robot_color;
    int x;
    int y;

    instruction >> robot_name >> x >> y >> robot_color;
    grid.make_robot(robot_name, {x, y}, get_color(robot_color));
  } else if (instr == "clear_robots") {
    grid.clear_robots();

  } else if (instr == "move_robot") {
    string robot_name;
    int x, y;

    instruction >> robot_name >> x >> y;
    grid.move_robot(robot_name, {x, y});

  } else if (instr == "recolor_robot") {
    string robot_name, robot_new_color;
    instruction >> robot_name >> robot_new_color;
    grid.recolor_robot(robot_name, get_color(robot_new_color));

  } else if (instr == "rename_robot") {
    string robot_name, robot_new_name;
    instruction >> robot_name >> robot_new_name;
    grid.rename_robot(robot_name, robot_new_name);

  } else if (instr == "delete_robot") {
    string robot_name;
    instruction >> robot_name;
    grid.delete_robot(robot_name);

  } else {
    throw string("Invalid command " + instr);
  }
  //other solutions are also possible
  // END: S2
}

// |
// | END OF ASSIGNMENTS
// |

// Wrapper around execute_command to deal with exception handling
bool Interpreter::do_execute_instruction(string instruction)
{
  grid.get_application().trace_execution(instruction);
  try {
    execute_instruction(istringstream(instruction));
    return true;
  } catch (const exception &e) {
    fl_alert("Caught exception:\n\n%s", e.what());
    return false;
  } catch (const string &e) {
    fl_alert("Caught exception:\n\n%s", e.c_str());
    return false;
  } catch (const char *&e) {
    fl_alert("Caught exception:\n\n%s", e);
    return false;
  } catch (...) {
    fl_alert("Caught unknown exception.");
    return false;
  }
}

// Returns an optional containing the next line of a program as a
// string unless the program has no more lines.
optional<string> Interpreter::get_next_instruction(istringstream &stream)
{
  for (;;) {
    if (stream.eof()) {
      return std::nullopt;
    } else {
      string res;
      getline(stream, res);
      // Trim string
      res = std::regex_replace(res, std::regex("^ +| +$|( ) +"), "$1");
      if (res == "") {
        continue;
      }
      return optional(res);
    }
  }
}

// Executes the commands of a program timed
void Interpreter::execute_steps(void *interpreter_ptr)
{
  Interpreter &interpreter = *(Interpreter *)interpreter_ptr;
  auto command = interpreter.get_next_instruction(interpreter.program_stream);

  if (command.has_value()) {
    if (interpreter.do_execute_instruction(command.value())) {
      Fl::repeat_timeout(interpreter.step_delay, &execute_steps,
                         interpreter_ptr);
    }
  } else {
    interpreter.grid.get_application().enable_gui();
  }
}

// Executes a complete program
void Interpreter::execute_program(string stream, double frame_rate)
{
  step_delay = 1.0 / frame_rate;
  program_stream = istringstream(stream);
  auto command = get_next_instruction(program_stream);
  if (command.has_value()) {
    if (do_execute_instruction(command.value())) {
      Fl::add_timeout(step_delay, &execute_steps, this);
    }
  } else {
    grid.get_application().enable_gui();
  }
}

Interpreter::Interpreter(RobotGrid &grid) : grid(grid)
{
}

