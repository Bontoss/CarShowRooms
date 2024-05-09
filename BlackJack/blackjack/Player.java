package blackjack;

public class Player { // Player Class contain player details and the cards he have.
    String name;
    int score = 0;
    Card[] Hand_Cards = new Card[11];
    int counter = 0;

    public void Add_Card(Card card) { // Function to add cards to the player and increase its score to him.
        if (this.counter < 11) {
            Hand_Cards[this.counter] = card;
            this.score += card.getValue();
            this.counter++;
        }
    }

    public Card[] getHand() {
        return this.Hand_Cards;
    }
}