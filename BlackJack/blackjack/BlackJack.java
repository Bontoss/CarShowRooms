package blackjack;

public class BlackJack { // BlackJack Class contain main function that runs the whole Game.

    static Game game = new Game();

    public static void main(String[] args) {

        GUI gui = new GUI();

        game.Generate_Deck();
        game.Set_Playersinfo();

        gui.runGUI(game.Deck,
                game.players[0].getHand(),
                game.players[1].getHand(),
                game.players[2].getHand(),
                game.players[3].getHand());

        game.Play(gui);
    }
}