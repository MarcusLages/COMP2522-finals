//
// Created by AyeshaA on 2024-12-01.
//
#include <stdio.h>

#define true    1
#define false   0

#define MIN_SCORE 0
#define MAX_SCORE 500

// Function Prototypes
int isValidScore(int score);
int detectCheating(int scores[], int size);
void updateScore(int *score, int delta);
int calculateAverage(int scores[], int size);
int findMaxScore(int scores[], int size);
int findMinScore(int scores[], int size);
void resetScores(int scores[], int size);
int countValidScores(int scores[], int size);

int main() {
    // Example usage of functions
    int score = 450;
    int scores[] = {100, 200, 300, 400, 450};
    int size = sizeof(scores) / sizeof(scores[0]);

    // Check if a score is valid
    if (isValidScore(score)) {
        printf("Valid score\n");
    } else {
        printf("Invalid score\n");
    }

    // Detect cheating in scores array
    if (detectCheating(scores, size)) {
        printf("Cheating detected\n");
    } else {
        printf("No cheating detected\n");
    }

    // Update the score
    updateScore(&score, 200);
    printf("Updated score: %d\n", score);

    // Calculate average score
    int average = calculateAverage(scores, size);
    printf("Average score: %d\n", average);

    // Find the maximum score
    int maxScore = findMaxScore(scores, size);
    printf("Max score: %d\n", maxScore);

    //  Find the minimum score
    int minScore = findMinScore(scores, size);
    printf("Min score: %d\n", minScore);

    // Reset all scores to zero
    resetScores(scores, size);
    printf("Scores after reset: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", scores[i]);
    }
    printf("\n");

    // Count valid scores
    int validCount = countValidScores(scores, size);
    printf("Number of valid scores: %d\n", validCount);

    return 0;
}

// Question 1: Write a function to check if a score is valid
int isValidScore(int score) {
    return score >= MIN_SCORE && score <= MAX_SCORE;
}

// Question 2: Write a function to detect cheating in scores array
int detectCheating(int scores[], int size) {
    for(int i = 0; i < size; i++) {
        if(!isValidScore(scores[i]))
            return true;
    }

    return false;
}

// Question 3: Write a function to update the score
void updateScore(int *score, int delta) {
    if(score == NULL) return;

    (*score) += delta;

    if(*score < MIN_SCORE)
        *score = MIN_SCORE;
    else if(*score > MAX_SCORE)
        *score = MAX_SCORE;
}

// Question 4: Write a function to calculate average score
int calculateAverage(int scores[], int size) {
    int sum = 0, count = 0;

    for(int i =  0  ; i < size; i++) {
        sum += scores[i];
        count++;
    }

    if(count == 0) return 0;

    return sum / count;
}

// Question 5: Complete the missing line of code to find the maximum score in the array.
int findMaxScore(int scores[], int size) {
    int max = scores[0];
    for (int i = 1; i < size; i++) {
        if (scores[i] > max) {
            max = scores[i];
        }
    }
    return max;
}

// Question 6: Complete the missing line of code to find the minimum score in the array. Look at function findMinScore.
int findMinScore(int scores[], int size) {
    int min = scores[0];
    for (int i = 1; i < size; i++) {
        if (scores[i] < min) {
           min = scores[i];
        }
    }
    return min;
}

// Question 7: Complete the missing line of code to reset all scores to zero.
void resetScores(int scores[], int size) {
    for (int i = 0; i < size; i++) {
        scores[i] = 0;
    }
}

// Question 8: Complete the missing line of code to count the number of valid scores in the array.
int countValidScores(int scores[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (isValidScore(scores[i])) {
            count++;
        }
    }
    return count;
}