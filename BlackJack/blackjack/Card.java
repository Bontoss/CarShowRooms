package blackjack;

public class Card { // Class Card Contain components of eash card(suit,rank,value).
    private final int suit, rank, value;

    public Card(int suit, int rank, int value) {
        this.suit = suit;
        this.rank = rank;
        this.value = value;
    }

    public Card(Card copy) {
        this.suit = copy.suit;
        this.rank = copy.rank;
        this.value = copy.value;
    }

    public int getSuit() {
        return suit;
    }

    public int getRank() {
        return rank;
    }

    public int getValue() {
        return value;
    }

}