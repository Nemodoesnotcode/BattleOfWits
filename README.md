

# **Battle of Wits – Quiz Game 🎮🧠**



### **Group Members**



BCSF24M541 – Adan Irfan

BCSF24M546 – Nimra Khalid

BCSF24M547 – Arooj Fatima



---



📌 **Project Overview**



**Battle of Wits** is a console-based quiz game designed to test knowledge, track scores, store previous winners, and offer a fun interactive experience.

It includes features such as file handling, score saving, reviewing answers, resetting game data, and more.



This project demonstrates:



\* Modular programming

\* File handling (binary + text)

\* Input validation

\* Menu-based interaction

\* Game logic implementation



---



🧩 **Features**



✔ Add player names

✔ Load questions

✔ Ask questions with input validation

✔ Display correct/incorrect responses

✔ Store \& display scores

✔ Save and load data from files

✔ View previous winners

✔ Review answers

✔ Reset game data

✔ Clear screen / menu system



---



📘 **Function Descriptions**



1\. rules()



Displays the rules and instructions of the game to the players.



2\. takeNames()



Allows users to enter their names before the game begins.



3\. loadQuestions()



Loads questions from a file or internal database into the program.



4\. displayQuestion()



Shows the current question and its available options.



5\. getValidAnswer()



Ensures the player enters a valid option (A/B/C/D etc.).



6\. askQuestion()



Asks a question to a specific player and checks whether their answer is correct.

➡ Contains a checkCorrect step inside.



7\. showScores()



Displays the current scores of all players.



8\. showWinner()



Determines and displays the winner(s) based on scores.



9\. startQuiz()



Controls the overall quiz flow — questions, scoring, turn order.



10\. saveScores()



Saves player scores to a file for future reference.



11\. writeToFile()



Writes quiz data (e.g., scores, winners) to a \*\*binary file\*\*.



12\. readtoFile()



Reads previously saved data from a binary file.



13\. previousWinners()



Displays a list of players who have won past quizzes.



14\. reviewAnswers()



Allows players to review correct answers after the game.



15\. resetGame()



Clears scores and game state to start a fresh game.



16\. storeWinners()



Saves the name of the winner(s) in a dedicated storage file.



17\. startGame()



The main function that initializes the game, shows menu, and begins gameplay.



18\. askNQuestions()



Allows choosing how many questions to ask or handles question limits.



19\. showMenu()



Displays all menu options available to the user.



20\. clearScreen()



Clears the console screen (implementation depends on OS).



---



📂 **File Handling**



The project uses:



Binary files→ store scores \& winners (`writeToFile`, `readtofile`)

Text files → questions, logs, or history



---



🚀 **How to Run**



1\. Compile the program

2\. Run the executable

3\. Choose options through the menu

4\. Play the quiz and check your score!



---



🎖 **Future Improvements**



✨ Timer-based questions

✨ Difficulty levels

✨ Database-based storage

✨ Category-wise quizzes







