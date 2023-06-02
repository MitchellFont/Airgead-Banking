/*
Mitchell Fontaine
CS-210
06/01/2023
Airgead Banking Application
*/

#include "Bank.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Banking class definition

// Accessors and Mutators
void Bank::SetInitialInvestment(double totInitialInvestment) {
	m_totalAmount = totInitialInvestment;
}
void Bank::SetMonthlyDeposit(double totMonthlyDeposit) {
	m_monthlyDeposit = totMonthlyDeposit;
}
void Bank::SetInterestRate(double totAnnualInterest) {
	m_yearlyTotalInterest = totAnnualInterest;
}
void Bank::SetNumberOfYears(int totNumberOfYears) {
	m_numberOfYears = totNumberOfYears;
}
double Bank::GetInitialInvestment() const {
	return m_totalAmount;
}
double Bank::GetMonthlyDeposit() const {
	return m_monthlyDeposit;
}
double Bank::GetInterestRate() const {
	return m_yearlyTotalInterest;
}
int Bank::GetNumberOfYears() const {
	return m_numberOfYears;
}

// Funciton to calculate and outout balance without a monthly deposit
double Bank::calcBalanceWithoutMonthlyDeposit(double totInitialInvestment, double totAnnualInterest, int totNumberOfYears) {
	m_totalAmount = totInitialInvestment;

	// Display table heading
	cout << endl << "     Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << std::string(66, '=') << endl;
	cout << "Year          Year End Balance          Year End Earned Interest" << endl;
	cout << std::string(66, '-') << endl;

	// Calculate yearly interest and year-end total
	for (int i = 0; i < totNumberOfYears; i++) {
		m_interestAmount = m_totalAmount * (totAnnualInterest / 100);
		m_totalAmount = m_totalAmount + m_interestAmount;
		cout << " " << left << setw(5) << (i + 1) << "\t\t$" << fixed << setprecision(2) << m_totalAmount << "\t\t\t\t$" << m_interestAmount << endl;
	}

	return m_totalAmount;
}

// Funciton to calculate and outout balance with a monthly deposit
double Bank::balanceWithMonthlyDeposit(double totInitialInvestment, double totMonthlyDeposit, double totAnnualInterest, int totNumberOfYears) {
	m_totalAmount = totInitialInvestment;

	// Display table heading
	cout << endl << "     Balance and Interest With Additional Monthly Deposits" << endl;
	cout << std::string(66, '=') << endl;
	cout << "Year          Year End Balance          Year End Earned Interest" << endl;
	cout << std::string(66, '-') << endl;

	// Calculate yearly interest and year-end total
	for (int i = 0; i < totNumberOfYears; i++) {
		m_yearlyTotalInterest = 0;

		for (int j = 0; j < 12; j++) {
			m_interestAmount = (m_totalAmount + totMonthlyDeposit) * ((totAnnualInterest / 100.00) / 12.00);
			m_yearlyTotalInterest = m_yearlyTotalInterest + m_interestAmount;
			m_totalAmount = m_totalAmount + totMonthlyDeposit + m_interestAmount;
		}

		cout << " " << left << setw(5) << (i + 1) << "\t\t$" << fixed << setprecision(2) << m_totalAmount << "\t\t\t\t$" << m_yearlyTotalInterest << endl;
	}

	return m_totalAmount;
}