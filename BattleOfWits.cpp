//BATTLE OF WITS GAME
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;
//                                   GLOBAL VARIABLES
    string* question;
	string* optionA;
	string* optionB;
	string* optionC;
	string* optionD;
	char* correct;
	string player1,player2;
	int p1score=0,p2score=0;
	
//                                        GLOBAL FUNCTIONS

//show main menu
 void showMenu() {
 	cout<<"\n\n\n\n\n"<<endl;
    cout<<"==================== MAIN MENU ====================="<<endl;
    cout<<"|1. Start New Game                                 |"<<endl;
    cout<<"|2. View Winners Leaderboard                       |"<<endl;
    cout<<"|3. Exit                                           |"<<endl;
    cout<<"===================================================="<<endl;
}

//for printing rules
void rules()
{
	cout<<"==========================================RULES======================================================================================"<<endl;
	cout<<"| 1. This is a 2 player game                                                                                                         "<<endl;
	cout<<"| 2. This is a one round QUIZ                                                                                                        "<<endl;
	cout<<"| 3. You have to enter the number of questions you desire to solve in quiz                                                           "<<endl;
	cout<<"| 4. The questions will be given turn by turn. It means that Player 1 is given Question 1 \n | Player 2 is given Question 2 and so on"<<endl;
	cout<<"| 5. Each corect answers leads to +1 in your score                                                                                   "<<endl;
	cout<<"| 6.There is no negative marking for any wrong answer                                                                                "<<endl;
	cout<<"==========================================BEST OF LUCK==============================================================================="<<endl;
}

//taking names of players from user
void takenames(){
	cout<<"\nPlayer1 Name:";
	cin>>player1;
	cout<<"\nPlayer2 Name:";
	cin>>player2;
}
//loading questions from file
void loadQuestions(int nQuestions){

	 question=new string[nQuestions];
	 optionA=new string[nQuestions];
	 optionB=new string[nQuestions];
     optionC=new string[nQuestions];
     optionD=new string[nQuestions];
	 correct=new char[nQuestions];
	
	ifstream fin("questionbank.txt");
	
	for(int i=0;i<nQuestions;i++){
		getline(fin,question[i]);
		getline(fin,optionA[i]);
		getline(fin,optionB[i]);
		getline(fin,optionC[i]);
		getline(fin,optionD[i]);
		fin>>correct[i];
		fin.ignore();
	    fin.ignore();
	}
	
	
	cout<<nQuestions<<" Questions loaded successfully!"<<endl;
		fin.close();
}

//asking number of questions to ask
int asknQuestions(){
	int nQuestions;
	cout<<"\n Enter Number of questions to be asked: ";
	cin>>nQuestions;
	return nQuestions;
}	

//to display question
void displayQuestion(int i){
	cout<<"\nQuestion"<<(i+1)<<": ";
    cout<<question[i]<<"\n"
	    <<optionA[i]<<"\n"
	    <<optionB[i]<<"\n"
        <<optionC[i]<<"\n"
        <<optionD[i]<<endl;
}

//checking valid answer
char getValidanswer(){
	char ans;
	while(1){
	 cout<<"\nEnter Answer(A/B/C/D):";
	 cin>>ans;
	 ans=toupper(ans);      // for caseinsensitive
	 if(ans=='A'||ans=='B'||ans=='C'||ans=='D')
		 return ans;
	    
	 else
	     cout<<"Invalid Try Again!";      
    } 
}

//asking questions includes display question feature and checking correctness
void AskQuestion(int i,string playername){
	displayQuestion(i);
	char ans=getValidanswer();
	if(ans==toupper(correct[i])){
		cout<<"\nCorrect!\n";
		if(playername == player1)
            p1score++;
        else if(playername == player2)
            p2score++;
	    }
	else{
		cout<<"\nIncorrect Answer! Correct is "<<correct[i]<<endl;
	    }  
}

//handles the working of quiz using ask question function
void startQuiz(int nQuestions){
	int turn=1;
	cout<<"\n Quiz Started "<<endl;
	for(int i=0;i<nQuestions;i++){

		if(turn==1){
			cout<<'\n'<<player1<<"'s turn: "<<endl;
		    AskQuestion(i,player1);
	        turn=2;
		}
		else if(turn==2){
			cout<<'\n'<<player2<<"'s turn: "<<endl;
		    AskQuestion(i,player2);
	        turn=1;
		}
    }
}

//showing scores of players after the game
void showScores(){
	cout<<"\n-----Current Score-----\n";
	cout<<player1<<" --->"<<p1score<<endl;
	cout<<player2<<" --->"<<p2score<<endl;
}

//showing winner of the game or if the match is tie
void showWinner()
{
	if(p1score>p2score)
		 cout<<"\nWinner is "<<player1<<"\t"<<"Score: "<<p1score<<endl;
	if(p1score<p2score)
		 cout<<"\nWinner is "<<player2<<"\t"<<"Score: "<<p2score<<endl;
	if(p1score==p2score)
		cout<<"\n=======DRAW========"<<endl;

}

//writing score in binary file
void writetofile()
{
	ofstream fout("RecordScore.bin",ios::binary);
	fout.write((char*)&p1score,sizeof(p1score));
	fout.write((char*)&p2score,sizeof(p2score));
	//cout<<"File Write Successfully"<<endl;
	fout.close();
}

//reading score from binary file
 void readtofile(){
 	ifstream fin("RecordScore.bin",ios::binary);
 	fin.read((char*)&p1score,sizeof(p1score));
 	fin.read((char*)&p2score,sizeof(p2score));
 	//cout<<"\nfile read successfully!\n";
 	fin.close();
 }            
			    
//storing winner name and score
void storeWinner(string winnerName,int winnerScore){
	ofstream fout("winners.txt",ios::app);
	fout<<winnerName<<" --->"<<winnerScore<<endl;
	fout.close();
}

//showing leaderboard
void previousWinners() {
    ifstream fin("winners.txt");

    int count = 0;
    string line;
    while(getline(fin, line)) 
	count++;
    fin.clear();
    fin.seekg(0);

    if (count==0) {
        cout<<"\nNo winners recorded yet!\n";
        fin.close();
        return;
    }

    string names[count];
    int scores[count];

    // Read file into arrays
    int index = 0;
    while(getline(fin,line)) {
        stringstream ss(line);
        getline(ss,names[index],'-');
        ss.ignore(3); 
        ss>>scores[index];
        index++;
    }
    fin.close();

    // Sort arrays by score descending
    for (int i=0;i<count-1;i++) {
        for (int j =i+1;j<count;j++) {
            if (scores[j]>scores[i]) {
                swap(scores[i],scores[j]);
                swap(names[i],names[j]);
            }
        }
    }

    // Display leaderboard
    cout<<"\n----------- Winners Leaderboard (DESCENDING) -----------\n";
    int rank = 1, prevScore = -1;
      for(int i=0;i<count;i++){
         if(scores[i]!=prevScore) 
		     rank=i+1;
        cout<<rank<<". "<<names[i]<<" ---> "<<scores[i]<<endl;
         prevScore=scores[i];
}

}

//reset scores in case player wants to start another game(acting as cleanup)
void resetgame(){
	p1score=0;
	p2score=0;
	player1="";
	player2="";
	
}
void startgame(){
	while(1){
	 resetgame();
	 rules();
	 takenames();
	 //clearscreen();
	 int nQuestions=asknQuestions();
	 loadQuestions(nQuestions);
	 startQuiz(nQuestions);
	 showScores();
	 showWinner();
	 writetofile();
	readtofile();
	 if (p1score > p2score)
	     storeWinner(player1,p1score);
	 
	 else if (p2score > p1score)
	     storeWinner(player2,p2score);
	 
	     
	 delete[] question;
	 delete[] optionA;
	 delete[] optionB;
	 delete[] optionC;
	 delete[] optionD;
	 delete[] correct;     
	  
	  
	 char choice;
	 cout<<"\n Do you want to play the game again? (Y/N): ";
	 cin>>choice;
	 choice=toupper(choice);
	 
	 if (choice!='Y'){
         cout<<"\nThanks for playing! Exiting..."<<endl;
         break;
        }
    }
}
//for cmd
void clearscreen() {
#ifdef _WIN32
    system("cls");   // Windows
#else
    system("clear"); // Linux / macOS
#endif
}



int main() {
    char key;
    cout << "\n\nWelcome to BATTLE OF WITS!" << endl;

    while (true) {
        showMenu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                startgame();
                break;
            case 2:
                previousWinners();  // shows leaderboard
                break;
            case 3:
                cout << "GOODBYE!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}

