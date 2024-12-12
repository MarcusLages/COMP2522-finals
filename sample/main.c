//#include <stdio.h>
//
//// Question 1
//int isValidScore(int score) {
//    return score >= 0 && score <= 100;
//}
//
//// Question 2
//int detectAnomalies(int scores[], int size) {
//    for(int i = 0; i < size; i++) {
//        if(!isValidScore(scores[i]))
//            return 1;
//    }
//
//    return 1;
//}
//
//// Question 3
//void updateScore(int *score, int delta) {
//    if(score == NULL) return;
//
//    (*score) += delta;
//
//    if(*score < 0)
//        *score = 0;
//    else if(*score > 100)
//        *score = 100;
//}
//
//// Question 4
//int calculateAverage(int scores[], int size) {
//    int sum = 0, count = 0;
//
//    for(int i =  0; i < size; i++) {
//        sum += scores[i];
//        count++;
//    }
//
//    if(count == 0) return 0;
//
//    return sum / count;
//
//}
//
//// Question 5
//int findMaxScore(int scores[], int size) {
//    int max = scores[0];
//
//    for (int i = 1; i < size; i++) {
//        if(max < scores[i])
//            max = scores[i];
//    }
//    return max;
//}
//
//// Question 6
//int findMinScore(int scores[], int size) {
//    int min = scores[0];
//
//    for (int i = 1; i < size; i++) {
//        if(min > scores[i])
//            min = scores[i];
//    }
//    return min;
//}
//
//// Question 7
//void resetScores(int scores[], int size) {
//    for (int i = 0; i < size; i++)
//        scores[i] = 0;
//}
//
//// Question 8
//int countValidScores(int scores[], int size) {
//    int count = 0;
//
//    for (int i = 0; i < size; i++) {
//        if(isValidScore(scores[i]))
//            count++;
//    }
//    return count;
//}
//
//int main() {
//    int scores[] = {85, 90, 78, 88, 92};
//    int size = sizeof(scores) / sizeof(scores[0]);
//
//    printf("Original scores: ");
//    for (int i = 0; i < size; i++) {
//        printf("%d ", scores[i]);
//    }
//    printf("\n");
//
//    // Question 1: Test isValidScore
//    int testScore = 90;
//    if (isValidScore(testScore)) {
//        printf("Score %d is valid.\n", testScore);
//    } else {
//        printf("Score %d is invalid.\n", testScore);
//    }
//
//    // Question 2: Test detectAnomalies
//    if (detectAnomalies(scores, size)) {
//        printf("Anomalies detected in the scores.\n");
//    } else {
//        printf("No anomalies detected in the scores.\n");
//    }
//
//    // Question 4: Test calculateAverage
//    int average = calculateAverage(scores, size);
//    printf("The average score is: %d\n", average);
//
//    // Question 5: Test findMaxScore
//    int maxScore = findMaxScore(scores, size);
//    printf("The maximum score is: %d\n", maxScore);
//
//    // Question 6: Test findMinScore
//    int minScore = findMinScore(scores, size);
//    printf("The minimum score is: %d\n", minScore);
//
//    // Question 7: Test resetScores
//    resetScores(scores, size);
//    printf("Scores after reset: ");
//    for (int i = 0; i < size; i++) {
//        printf("%d ", scores[i]);
//    }
//    printf("\n");
//
//    // Resetting scores to original for further testing
//    int originalScores[] = {85, 90, 78, 88, 92, -5, 105};
//    for (int i = 0; i < size; i++) {
//        scores[i] = originalScores[i];
//    }
//
//    // Question 8: Test countValidScores
//    int validCount = countValidScores(scores, size);
//    printf("Number of valid scores: %d\n", validCount);
//
//    return 0;
//}