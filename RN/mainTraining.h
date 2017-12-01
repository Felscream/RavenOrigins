#pragma once
#include <iostream>
#include "NeuralNetwork/neuralNetworkTrainer.h"
#include "NeuralNetwork/TrainingDataReader.h"
BPN::Network* mainTraining(std::string path, uint32_t in, uint32_t hidden, uint32_t out);