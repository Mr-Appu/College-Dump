# Design and analysis of algorithm - CIA2

This repository contains code for weight optimization of Neural Network using different optimization algorithms such as 
* Genetic Algorithm 
* Particle Swarm Optimization 
* Ant Colony Optimization

## Performance Matrix

| Optimization Algorithm      | Population/Particles/Ants | Generations/Iterations | Accuracy | F1 Score |
|-----------------------------|---------------------------|------------------------|----------|----------|
| Genetic Algorithm           | 10                        | 100                    | 94%      | 0.37     |
| Particle Swarm Optimization | 500                       | 50                     | 95%      | 0.68     |
| Ant Colony Optimization     | 10                        | 100                    | 92%      | 0.57     |

In conclusion, Particle Swarm Optimization gives better results than Genetic Algorithm and Ant Colony Optimization.

### Note
* Due to the high imbalance in the dataset, using the F1 score is necessary for evaluating the performance of the algorithms.
* Because there is no explicitly definable belief space for weight updates, the cultural algorithm essentially reduces to a genetic algorithm.
