#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char color;  // R, B, Y, G
    int number;  // 1-9
} Card;

int is_valid_color(char color) {
    return (color == 'R' || color == 'B' || color == 'Y' || color == 'G');
}

int is_valid_number(int number) {
    return (number >= 1 && number <= 9);
}

int input_card(Card* card) {
    char color;
    int number;

    if (scanf(" %c %d", &color, &number) != 2) {
        while (getchar() != '\n');
        return 0;
    }

    if (!is_valid_color(color)) {
        return 0;
    }

    if (!is_valid_number(number)) {
        return 0;
    }

    card->color = color;
    card->number = number;
    return 1;
}

void sort_cards_by_number(Card cards[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (cards[j].number > cards[j + 1].number) {
                Card temp = cards[j];
                cards[j] = cards[j + 1];
                cards[j + 1] = temp;
            }
        }
    }
}

int is_consecutive(int numbers[], int n) {
    int sorted[5];
    int temp;

    for (int i = 0; i < n; i++) {
        sorted[i] = numbers[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sorted[j] > sorted[j + 1]) {
                temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        if (sorted[i] != sorted[i - 1] + 1) {
            return 0;
        }
    }

    return 1;
}

int is_same_color(Card cards[], int n) {
    char first_color = cards[0].color;
    for (int i = 1; i < n; i++) {
        if (cards[i].color != first_color) {
            return 0;
        }
    }
    return 1;
}

void count_numbers(Card cards[], int n, int count[]) {
    for (int i = 0; i < 10; i++) count[i] = 0;
    for (int i = 0; i < n; i++) {
        count[cards[i].number]++;
    }
}

int calculate_score(Card cards[]) {
    int numbers[5];
    int count[10];
    int max_number = 0;

    for (int i = 0; i < 5; i++) {
        numbers[i] = cards[i].number;
        if (cards[i].number > max_number) {
            max_number = cards[i].number;
        }
    }

    count_numbers(cards, 5, count);

    if (is_same_color(cards, 5) && is_consecutive(numbers, 5)) { //로얄플
        return max_number + 900;
    }

    for (int i = 1; i <= 9; i++) {
        if (count[i] == 4) {
            return i + 800;
        }
    }

    int three_num = 0, two_num = 0;
    for (int i = 1; i <= 9; i++) {
        if (count[i] == 3) three_num = i;
        else if (count[i] == 2) two_num = i;
    }
    if (three_num > 0 && two_num > 0) {
        return three_num * 10 + two_num + 700;
    }

    if (is_same_color(cards, 5)) {
        return max_number + 600;
    }

    if (is_consecutive(numbers, 5)) {
        return max_number + 500;
    }

    for (int i = 1; i <= 9; i++) {
        if (count[i] == 3) {
            return i + 400;
        }
    }

    int first_pair = 0, second_pair = 0;
    for (int i = 1; i <= 9; i++) {
        if (count[i] == 2) {
            if (first_pair == 0) first_pair = i;
            else second_pair = i;
        }
    }
    if (first_pair > 0 && second_pair > 0) {
        int larger = (first_pair > second_pair) ? first_pair : second_pair;
        int smaller = (first_pair > second_pair) ? second_pair : first_pair;
        return larger * 10 + smaller + 300;
    }

    for (int i = 1; i <= 9; i++) {
        if (count[i] == 2) {
            return i + 200;
        }
    }

    return max_number + 100;
}

int main() {
    Card cards[5];
    int i;

    for (i = 0; i < 5; i++) {
        input_card(&cards[i]);
    }

    int score = calculate_score(cards);
    printf("%d", score);

    return 0;
}