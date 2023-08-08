#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define N 1000

struct edge
{
    int to, capacity, flow, rev_idx;
};

struct node
{
    int height, excess_flow;
    struct edge edges[N];
    int num_edges;
};

struct node nodes[N];
int queue[N], front, rear;

void add_edge(int from, int to, int capacity)
{
    int idx_from = nodes[from].num_edges;
    int idx_to = nodes[to].num_edges;
    nodes[from].edges[idx_from] = (struct edge){to, capacity, 0, idx_to};
    nodes[to].edges[idx_to] = (struct edge){from, 0, 0, idx_from};
    nodes[from].num_edges++;
    nodes[to].num_edges++;
}

// function to initialize the flow network
void initialize(int source, int sink) {
    for (int i = 0; i < N; i++) {
        nodes[i].height = 0;
        nodes[i].excess_flow = 0;
        nodes[i].num_edges = 0;
    }
    add_edge(source, sink, INT_MAX);
}

// function to push flow from one node to another
void push(struct edge *e, int node_idx) {
    int flow = e->capacity - e->flow;
    int push_flow = flow < nodes[node_idx].excess_flow ? flow : nodes[node_idx].excess_flow;
    e->flow += push_flow;
    nodes[node_idx].excess_flow -= push_flow;
    nodes[e->to].excess_flow += push_flow;
    nodes[e->to].edges[e->rev_idx].flow -= push_flow;
}

// function to relabel a node
void relabel(int node_idx) {
    int min_height = INT_MAX;
    for (int i = 0; i < nodes[node_idx].num_edges; i++) {
        struct edge *e = &nodes[node_idx].edges[i];
        if (e->capacity - e->flow > 0 && nodes[e->to].height < min_height) {
            min_height = nodes[e->to].height;
        }
    }
    nodes[node_idx].height = min_height + 1;
}

// function to perform the push-relabel algorithm
void push_relabel(int source, int sink) {
    // initialize the height and excess flow of the source node
    nodes[source].height = N;
    nodes[source].excess_flow = INT_MAX;

    // initialize the height of the remaining nodes to 0
    for (int i = 0; i < N; i++) {
        if (i != source) {
            nodes[i].height = 0;
        }
    }

    // initialize the flow of all edges to 0
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < nodes[i].num_edges; j++) {
            nodes[i].edges[j].flow = 0;
        }
    }

    // enqueue all nodes except the source and sink
    front = rear = 0;
    for (int i = 0; i < N; i++) {
        if (i != source && i != sink) {
            queue[rear++] =
