#include "Raven_Weapon.h"

void  Raven_Weapon::InitializeFuzzyModulePrecision() {

	FuzzyVariable& DistanceToTarget = m_FuzzyModule.CreateFLV("DistanceToTarget");
	FzSet& Target_Close = DistanceToTarget.AddLeftShoulderSet("Target_Close", 0, 25, 150);
	FzSet& Target_Medium = DistanceToTarget.AddTriangularSet("Target_Medium", 25, 150, 300);
	FzSet& Target_Far = DistanceToTarget.AddRightShoulderSet("Target_Far", 150, 300, 1000);

	FuzzyVariable& Velocity = m_FuzzyModule.CreateFLV("Velocity");
	FzSet& Low_Velocity = Velocity.AddLeftShoulderSet("Low_Velocity", 0, 0.25, 0.5);
	FzSet& Medium_Velocity = Velocity.AddTriangularSet("Medium_Velocity", 0.25, 0.5, 0.75);
	FzSet& High_Velocity = Velocity.AddRightShoulderSet("High_Velocity", 0.5, 0.75, 2);

	FuzzyVariable& VisibleTime = m_FuzzyModule.CreateFLV("VisibleTime");
	FzSet& Low_VisibleTime = VisibleTime.AddTriangularSet("Low_VisibleTime", 0, 0, 1);
	FzSet& Medium_VisibleTime = VisibleTime.AddTriangularSet("Medium_VisibleTime", 0, 1, 3);
	FzSet& High_VisibleTime = VisibleTime.AddRightShoulderSet("High_VisibleTime", 2, 3, 1000);

	FuzzyVariable& Precision = m_FuzzyModule.CreateFLV("Precision");
	FzSet& High_Precision = Precision.AddRightShoulderSet("High_Precision", 0, pi/64, pi/32);
	FzSet& Medium_Precision = Precision.AddTriangularSet("Medium_Precision", pi/64, pi / 32, 3*pi/64);
	FzSet& Low_Precision = Precision.AddLeftShoulderSet("Low_Precision", pi / 32, 3 * pi / 64, pi/16);

	//Normal
	m_FuzzyModule.AddRule(FzAND(Target_Close, Low_Velocity, Low_VisibleTime), Medium_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Close, Low_Velocity, Medium_VisibleTime), High_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Close, Low_Velocity, High_VisibleTime), High_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Close, Medium_Velocity, Low_VisibleTime), Medium_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Close, Medium_Velocity, Medium_VisibleTime), High_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Close, Medium_Velocity, High_VisibleTime), High_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Close, High_Velocity, Low_VisibleTime), Medium_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Close, High_Velocity, Medium_VisibleTime), Medium_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Close, High_Velocity, High_VisibleTime), High_Precision);

	m_FuzzyModule.AddRule(FzAND(Target_Medium, Low_Velocity, Low_VisibleTime), Medium_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Medium, Low_Velocity, Medium_VisibleTime), Medium_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Medium, Low_Velocity, High_VisibleTime), High_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Medium, Medium_Velocity, Low_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Medium, Medium_Velocity, Medium_VisibleTime), Medium_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Medium, Medium_Velocity, High_VisibleTime), High_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Medium, High_Velocity, Low_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Medium, High_Velocity, Medium_VisibleTime), Medium_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Medium, High_Velocity, High_VisibleTime), Medium_Precision);

	m_FuzzyModule.AddRule(FzAND(Target_Far, Low_Velocity, Low_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Far, Low_Velocity, Medium_VisibleTime), Medium_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Far, Low_Velocity, High_VisibleTime), Medium_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Far, Medium_Velocity, Low_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Far, Medium_Velocity, Medium_VisibleTime), Medium_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Far, Medium_Velocity, High_VisibleTime), Medium_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Far, High_Velocity, Low_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Far, High_Velocity, Medium_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Far, High_Velocity, High_VisibleTime), Medium_Precision);

	//low precision
	/*m_FuzzyModule.AddRule(FzAND(Target_Close, Low_Velocity, Low_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Close, Low_Velocity, Medium_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Close, Low_Velocity, High_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Close, Medium_Velocity, Low_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Close, Medium_Velocity, Medium_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Close, Medium_Velocity, High_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Close, High_Velocity, Low_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Close, High_Velocity, Medium_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Close, High_Velocity, High_VisibleTime), Low_Precision);

	m_FuzzyModule.AddRule(FzAND(Target_Medium, Low_Velocity, Low_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Medium, Low_Velocity, Medium_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Medium, Low_Velocity, High_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Medium, Medium_Velocity, Low_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Medium, Medium_Velocity, Medium_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Medium, Medium_Velocity, High_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Medium, High_Velocity, Low_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Medium, High_Velocity, Medium_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Medium, High_Velocity, High_VisibleTime), Low_Precision);

	m_FuzzyModule.AddRule(FzAND(Target_Far, Low_Velocity, Low_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Far, Low_Velocity, Medium_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Far, Low_Velocity, High_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Far, Medium_Velocity, Low_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Far, Medium_Velocity, Medium_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Far, Medium_Velocity, High_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Far, High_Velocity, Low_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Far, High_Velocity, Medium_VisibleTime), Low_Precision);
	m_FuzzyModule.AddRule(FzAND(Target_Far, High_Velocity, High_VisibleTime), Low_Precision);*/


}

double Raven_Weapon::GetPrecision(double DistToTarget, double Velocity, double VisibleTime) {
	m_FuzzyModule.Fuzzify("DistanceToTarget", DistToTarget);

	m_FuzzyModule.Fuzzify("Velocity", Velocity);
	m_FuzzyModule.Fuzzify("VisibleTime", VisibleTime);

	m_dLastPrecisionScore = m_FuzzyModule.DeFuzzify("Precision", FuzzyModule::max_av)+1;
	return m_dLastPrecisionScore;
}


