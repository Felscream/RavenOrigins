#pragma once
#include <iostream>
#include "NeuralNetwork/neuralNetworkTrainer.h"
#include "NeuralNetwork/TrainingDataReader.h"
int mainTraining(std::string path, BPN::Network* nn);