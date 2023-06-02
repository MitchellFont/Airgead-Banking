/*
Mitchell Fontaine
CS-210
06/01/2023
Airgead Banking Application
*/

#pragma once
#ifndef BANK_H
#define BANK_H

// Bank class, functions, and variable declarations
class Bank {
public:
	void SetInitialInvestment(double totInitialInvestment);
	void SetMonthlyDeposit(double totMonthlyDeposit);
	void SetInterestRate(double totAnnualInterest);
	void SetNumberOfYears(int totNumberOfYears);
	double GetInitialInvestment() const;
	double GetMonthlyDeposit() const;
	double GetInterestRate() const;
	int GetNumberOfYears() const;
	double calcBalanceWithoutMonthlyDeposit(double totInitialInvestment, double totAnnualInterest, int totNumberOfYears);
	double balanceWithMonthlyDeposit(double totInitialInvestment, double totMonthlyDeposit, double totAnnualInterest, int totNumberOfYears);
	
	// private variable declarations 
private:
	double m_totalAmount;
	double m_interestAmount;
	double m_yearlyTotalInterest;
	double m_monthlyDeposit;
	double m_numberOfYears;
};

#endif