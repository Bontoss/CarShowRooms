package blackjack;

import java.util.Random;
import java.util.Scanner;

public class Game { // Game Class contain all functions of the game and how it Run.
    public Player[] players = new Player[4];
    Card[] Deck = new Card[52];
    static int Highscore = -1;
    int tie = 0;
    int winner;

    public void Generate_Deck() { // Function to add the Card_Deck to the game.
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                if (j >= 9)
                    Deck[(i * 13) + j] = new Card(i, j, 10);
                else
                    Deck[(i * 13) + j] = new Card(i, j, j + 1);
            }
        }
    }

    public Card Draw_Card() { // Function to draw a random card From Card_Deck.
        Random rand = new Random();
        int random = rand.nextInt(52);
        while (Deck[random] == null) {
            random = rand.nextInt(52);
        }
        Card Returned_Card = Deck[random];
        Deck[random] = null;
        return Returned_Card;
    }

    public void Set_Playersinfo() { // Function to take the name of players and give each one two Cards.
        Scanner input = new Scanner(System.in);
        for (int i = 0; i < 3; i++) {
            System.out.print("Enter The Name Of Player #" + (int) (i + 1) + ": ");
            players[i] = new Player();
            players[i].name = input.next();
            players[i].Add_Card(Draw_Card());
            players[i].Add_Card(Draw_Card());
        }
        players[3] = new Player();
        players[3].name = "Dealer";
        players[3].Add_Card(Draw_Card());
        players[3].Add_Card(Draw_Card());
    }

    public void Update_Highscore() { // Function to update the score of each player and get the HighScore.
        for (int i = 0; i < 3; i++) {
            if (players[i].score > 21)
                continue;
            else if (players[i].score > Highscore)
                Highscore = players[i].score;
        }
    }

    public void Play(GUI gui) { // Function that contain the game rules and how to play and win.
        Scanner input = new Scanner(System.in);
        /*
         * (players_Turn): taking card from Card_Deck and put it in the players hand
         * according to their descisions.
         */
        for (int i = 0; i < 3; i++) {
            do {
                System.out.print("Enter (1) For Hit And (2) For Stand : ");
                int Descision = input.nextInt();
                if (Descision == 1 && players[i].score < 21) {
                    players[i].Add_Card(Draw_Card());
                    gui.updatePlayerHand(players[i].Hand_Cards[players[i].counter - 1], i);
                } else {
                    Update_Highscore();
                    System.out.println(players[i].score);
                    break;
                }
            } while (true);
        }

        Update_Highscore();

        // (Dealers_Turn): always taking cards until he win or BUSTED.

        while (players[3].score < Highscore && players[3].score < 21) {
            players[3].Add_Card(Draw_Card());
            gui.updateDealerHand(players[3].Hand_Cards[players[3].counter - 1], Deck);
        }
        System.out.println(players[3].score);

        for (int i = 0; i < 3; i++) {
            if (players[i].score == Highscore) {
                tie++;
                winner = i;
            }
        }

        // Checking who Wins the Game.

        if (tie > 1 || Highscore == -1) {
            System.out.println("PUSH!");

        } else if (players[3].score == players[winner].score) {
            System.out.println("PUSH!");
        } else if (players[3].score > players[winner].score && players[3].score == 21) {
            System.out.println("######-BLACKJACK-#####");
            System.out.println(players[3].name + " Wins");

        } else if (players[3].score > players[winner].score && players[3].score < 21) {
            System.out.println(players[3].name + " Wins");

        } else if (players[winner].score == Highscore && Highscore == 21) {
            System.out.println("######-BLACKJACK-#####");
            System.out.println(players[winner].name + " Wins");

        } else if (players[winner].score == Highscore) {
            System.out.println(players[winner].name + " Wins");

        } else {
            return;
        }
    }
}