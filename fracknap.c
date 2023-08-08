#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
    double ratio;
};

int compare(const void *a, const void *b) {
    return (((struct Item *)b)->ratio - ((struct Item *)a)->ratio);
}

void fractionalKnapsack(int n, int capacity, struct Item items[]) {
    int currentCapacity = 0;
    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    qsort(items, n, sizeof(struct Item), compare);

    for (int i = 0; i < n; i++) {
        if (currentCapacity + items[i].weight <= capacity) {
            currentCapacity += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remaining = capacity - currentCapacity;
            totalValue += items[i].ratio * remaining;
            break;
        }
    }

    printf("Total value of items in the knapsack: %lf\n", totalValue);
}

int main() {
    int n = 4;
    printf("Here the program is fed with 4 items\n");
    int capacity = 50;
    printf("The maximum capacity is 50\n");
    struct Item items[] = {{20, 40}, {120, 20}, {120, 30}, {110, 10}};
    printf("The items fed into the program have (weight,value) as {20, 40}, {120, 20}, {120, 30}, {110, 10} respectively\n");
    fractionalKnapsack(n, capacity, items);

    return 0;
}
