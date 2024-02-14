#include "masterVisual.h"
#include "utilities.h"
#include "std_lib_facilities.h"
#include "spill.h"

constexpr int wordsize = 4;

void playMastermindVisual() {
	MastermindWindow mwin{900, 20, winW, winH, wordsize, "Mastermind"};
	string code = randomizeString(wordsize, 'A', 'F');
	string guess = "";
	cout << code << endl;

	guess = mwin.getInput(wordsize, 'A', 'F');

	int attempts = 0;
	while (attempts < 10)
	{
		int correct = checkCharactersAndPosition(code, guess);
		int correct2 = checkCharacters(code, guess);
		mwin.addGuess(code, guess, 'A');
		mwin.setCodeHidden(false);
		mwin.addFeedback(correct, correct2);
		if (correct == wordsize)
		{
			cout << "Gratulerer, du klarte det!" << endl;
			break;
		}
		attempts += 1;
		guess = mwin.getInput(wordsize, 'A', 'F');
	}
	cout << "Du har brukt opp alle forsøkene dine." << endl;
	cout << "Riktig kode var: " << code << endl;

	char playAgain;
	cout << "Vil du spille igjen? (j/n): ";
	cin >> playAgain;
	if (playAgain == 'j')
	{
		playMastermindVisual();
	}
	else
	{
		cout << "Takk for at du spilte!" << endl;
	}
}

/*I denne deloppgaven skal du implementere tilbakemeldingsdelen av mastermind-spillet, dvs.
de sorte og hvite sirklene i høyre del av figuren. Implementer funksjonen addFeedback().
Den skal legge til en Feedback i vektoren feedbacks. Feedback er en struct som holder
variablene correctPosition og correctCharacter. Parameterne er vinduet, antall korrekte
plasseringer og antall korrekte bokstaver med feil posisjon.*/

void addGuess(MastermindWindow &mwin, const string code, const char startLetter)
{
	Guess newGuess;
	newGuess.code = code;
	newGuess.startLetter = startLetter;
	mwin.guesses.push_back(newGuess);
}

void addFeedback(MastermindWindow &mwin, const int correctPosition, const int correctCharacter)
{
	Feedback newFeedback;
	newFeedback.correctPosition = correctPosition;
	newFeedback.correctCharacter = correctCharacter;
	mwin.feedbacks.push_back(newFeedback);
}

void MastermindWindow::drawCodeHider()
{
	if (code_hidden) {
		draw_rectangle(Point{padX, 3 * padY}, winW - size * padX, padY, Color::black);
	}
}

MastermindWindow::MastermindWindow(int x, int y, int w, int h, int size, const string &title) 
: AnimationWindow(x, y, w, h, title),
guessBtn{{upperLeftCornerBtn.x, upperLeftCornerBtn.y}, btnW, btnH, "Add"},
guess{{upperLeftCornerInBox.x, upperLeftCornerInBox.y}, inBoxW, inBoxH, ""},
size(size)
{
	add(guess);
	add(guessBtn);
	guessBtn.setCallback(std::bind(&MastermindWindow::cb_guess, this));
};

void MastermindWindow::drawGuessesAndFeedbacks()
{
	std::map<int, Color> colorConverter{
		{1, Color::red},
		{2, Color::green},
		{3, Color::yellow},
		{4, Color::blue},
		{5, Color::blue_violet},
		{6, Color::dark_cyan}};

	for (int guessIndex = 0; guessIndex < static_cast<int>(guesses.size()); guessIndex++)
	{
		// Implementer funksjonalitet slik at det vises fargede rektangler i grafikkvinduet
		// Tegn gjettet som ligger på plassen guessIndex i vektoren guesses.
		for (int i = 0; i < size; i++)
		{
    		auto& guess = mwin.guesses[i];
    		for (int j = 0; j < guess.code.size(); ++j) {
				char letter = guess.code[j];
				int colorIndex = letter - 'A' + 1; 
				Color color = colorConverter.at(colorIndex);
				int xPos = padX * (j+1);
				int yPos = padY * (i+2); 
				draw_rectangle({xPos, yPos}, padX, padY, color);
    }
}

		}
	draw_circle({xPos, yPos}, radCircle, indicatorColor);
	}

	for (int feedbackIndex = 0; feedbackIndex < static_cast<int>(feedbacks.size()); feedbackIndex++)
	{
		// Implementer feedback

		for (int i = 0; i < size; i++)
		{
			// Tegn sirkler ved hjelp av draw_circle().

		}
	}


string MastermindWindow::wait_for_guess()
{

	while (!button_pressed && !should_close())
	{
		drawGuessesAndFeedbacks();
		// Burde tegnes sist siden den skal ligge på toppen
		drawCodeHider();

		next_frame();
	}
	button_pressed = false;

	string newGuess = guess.getText();
	guess.setText("");

	return newGuess;
}

string MastermindWindow::getInput(unsigned int n, char lower, char upper)
{
	bool validInput = false;
	string guess;
	while (!validInput && !should_close())
	{
		guess.clear();
		string input = wait_for_guess();
		if (input.size() == n)
		{
			for (unsigned int i = 0; i < n; i++)
			{
				char ch = input.at(i);
				if (isalpha(ch) && toupper(ch) <= upper && lower <= toupper(ch))
				{
					guess += toupper(ch);
				}
				else
					break;
			}
		}
		if (guess.size() == n)
		{
			validInput = true;
		}
		else
		{
			cout << "Invalid input guess again" << endl;
		}
	}
	return guess;
}

void MastermindWindow::setCodeHidden(bool hidden) {
	code_hidden = hidden;
}
