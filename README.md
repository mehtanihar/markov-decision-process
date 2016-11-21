# markov-decision-process
Implemented an MDP solver in c++. 

Run ./planner.sh MDP_name to get the value function corresponding to each state.

The MDP format is as follows:

The input to your planner will be an MDP, provided as a text file. The
format of the file is be as follows.


Number of states

Number of actions

Reward function

Transition function

Discount factor


The number of states S and the number of actions A will be integers
greater than 0 and less than 100. Assume that the states are numbered
0, 1, ..., S - 1, and the actions numbered 0, 1, ..., A - 1. The
reward function will be provided over SA lines, each line containing S
entries. Each entry corresponds to R(s, a, s'), wherein state s,
action a, and state s' are being iterated in sequence from 0 to S - 1,
0 to A - 1, and 0 to S - 1, respectively. A similar scheme is adopted
for the transition function T. Each reward will lie between -1 and 1
(both included). The discount factor is a real number between 0
(included) and 1 (exluded).

OUTPUT

Given an MDP, the planner computes the optimal value function V* and
an optimal policy pi*. Its output format is as follows:

V*(0)	pi*(0)
V*(1)	pi*(1)
.
.
.
V*(S - 1)	pi*(S - 1)

This was my CS 747 Assignment 2 at IIT Bombay
