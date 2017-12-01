//-------------------------------------------------------------------------
// Simple back-propagation neural network example
// 2017 - Bobby Anguelov
// MIT license: https://opensource.org/licenses/MIT
//https://takinginitiative.wordpress.com/2008/04/23/basic-neural-network-tutorial-c-implementation-and-source-code/
//-------------------------------------------------------------------------


#include "mainTraining.h"

#if _MSC_VER
#pragma warning(push, 0)
#pragma warning(disable: 4702)
#endif

#include "cmdParser.h"

#if _MSC_VER
#pragma warning(pop)
#endif

#include <direct.h>
#define GetCurrentDir _getcwd

std::string GetCurrentWorkingDir(void) {
	char buff[FILENAME_MAX];
	GetCurrentDir(buff, FILENAME_MAX);
	std::string current_working_dir(buff);
	return current_working_dir;
}

//-------------------------------------------------------------------------

int mainTraining(std::string path, BPN::Network* nn)
{
	
	std::string trainingDataPath = path;
	uint32_t const numInputs = 11;
	uint32_t const numHidden = 11;
	uint32_t const numOutputs = 1;

	BPN::TrainingDataReader dataReader(trainingDataPath, numHidden, numOutputs);
	if (!dataReader.ReadData())
	{
		return 0;
	}

	//// Create neural network
	/*BPN::Network::Settings networkSettings{ numInputs, numHidden, numOutputs };
	BPN::Network nn(networkSettings);*/

	// Create neural network trainer
	BPN::NetworkTrainer::Settings trainerSettings;
	trainerSettings.m_learningRate = 0.001;
	trainerSettings.m_momentum = 0.9;
	trainerSettings.m_useBatchLearning = false;
	trainerSettings.m_maxEpochs = 400;
	trainerSettings.m_desiredAccuracy = 65;

	BPN::NetworkTrainer trainer(trainerSettings, nn);
	trainer.Train(dataReader.GetTrainingData());

	

    return 1;
}
