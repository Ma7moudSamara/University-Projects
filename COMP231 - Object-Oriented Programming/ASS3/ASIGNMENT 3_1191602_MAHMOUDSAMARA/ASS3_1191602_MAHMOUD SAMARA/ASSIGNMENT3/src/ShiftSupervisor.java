// ASSIGNMENT 3        1191602        MAHMOUD SAMARA     COMP231      DR.HAFEZ BARGHOUTHI          SEC2

import java.util.Date;

// Definning the sub class that is ShiftSupervisor that extends from  the super class Employee

public class ShiftSupervisor extends Employee {
	private double MonthlySalary;
	private double MonthlyBonus; // monthly production bonus we will use it to know and print the monthly
									// bonus that a shift supervisor has earned.
	private int NumOfProductsMade; // Products made we will use it to know Number of products that produced by team
									// that supervised by the shift supervisor.
	private int NumOfTargetProducts; // TargetProducts we will use it to know Number of products must produced under
										// supervision by the shift supervisor.

	// No-argument constructor it includes the default values about for the
	// variables.

	public ShiftSupervisor() {
		super();
		// default values for the different variables
		MonthlySalary = 0.0;
		MonthlyBonus = 0.0;
		NumOfProductsMade = 0;
		NumOfTargetProducts = 0;
	}

	// Constructing a ShiftSupervisor object that has the same name as the class
	// itself and it has several methods in different types and it is constructor
	// with arguments it includes different attributes also it extends some
	// informations from Employee class.

	public ShiftSupervisor(String EmpName, String EmpNumber, Date EmpHire_Date, Address EmpAddress,
			double monthly_salary, double monthly_bonus, int NumOfProductsMade, int NumOfTargetProducts) {
		// Calling the super class.
		super(EmpName, EmpNumber, EmpHire_Date, EmpAddress);
		this.MonthlySalary = monthly_salary;
		this.MonthlyBonus = monthly_bonus;
		this.NumOfProductsMade = NumOfProductsMade;
		this.NumOfTargetProducts = NumOfTargetProducts;
	}

	public double getMonthlySalary() { // declare a method it's called MonthlySalary and it's kind is double and it
										// returns MonthlySalary.
		return MonthlySalary;
	}

	public void setMonthlySalary(double monthlySalary) { // declare a method it's called MonthlySalary and it sets a new
															// MonthlySalary for the new given or the new chosen
															// Supervisor.
		this.MonthlySalary = monthlySalary;
	}

	public double getMonthlyBonus() { // declare a method it's called MonthlyBonus and it's kind is double and it
										// returns MonthlyBonus.
		return MonthlyBonus;
	}

	public void setMonthlyBonus(double monthlyBonus) { // declare a method it's called MonthlyBonus and it sets a new
														// MonthlyBonus for the new given or the new chosen Supervisor.
		MonthlyBonus = monthlyBonus;
	}

	public int getNumOfProductsMade() { // declare a method it's called NumOfProductsMade and it's kind is int and it
										// returns NumOfProductsMade.
		return NumOfProductsMade;
	}

	public void setNumOfProductsMade(int numOfProductsMade) { // declare a method it's called NumOfProductsMade and it
																// sets a new NumOfProductsMade for the new given or the
																// new chosen Supervisor.
		NumOfProductsMade = numOfProductsMade;
	}

	public int getNumOfTargetProducts() { // declare a method it's called NumOfTargetProducts and it's kind is int and
											// it returns NumOfTargetProducts.
		return NumOfTargetProducts;
	}

	public void setNumOfTargetProducts(int numOfTargetProducts) { // declare a method it's called NumOfTargetProducts
																	// and it sets a new NumOfTargetProducts for the new
																	// given or the new chosen Supervisor.
		NumOfTargetProducts = numOfTargetProducts;
	}

	// getTotalSalary() method should calculate the total salary based on the
	// following: If shift supervisor employee teams produce the required number of
	// products or more, then can earn the monthly bonus.
	public double getTotalSalary() {

		double Total_Salary = 0.0;

		// The if statememnt to check that all inputs eneterd right because any wrong
		// input leads to calculate a wrong total salary for the ShiftSupervisor and if
		// all inputs wright it will calculate the salary depend on the products made
		// and products must produce to know if we will add the bonus or not

		if ((MonthlySalary > 0) && (MonthlyBonus > 0) && (NumOfProductsMade > 0) && (NumOfTargetProducts > 0)
				&& (NumOfProductsMade >= NumOfTargetProducts)) {
			Total_Salary = MonthlySalary + MonthlyBonus;
		}
		// if statement to calculate the total salary if products made less than
		// products must produce then there is no bonus.

		if ((MonthlySalary > 0) && (MonthlyBonus > 0) && (NumOfProductsMade > 0) && (NumOfTargetProducts > 0)
				&& (NumOfProductsMade < NumOfTargetProducts)) {
			Total_Salary = MonthlySalary;
		}
		return Total_Salary;
	}

	// This is an extra method by this method it can calculate the amount of the
	// financial advance that the shift supervisor can take if he want
	public double getFinancialSalaryAdvance() {

		double FinancialAdvance = 0;

		if (MonthlySalary > 0) {
			FinancialAdvance = FinancialAdvance + (MonthlySalary * 70 / 100); // i supposed that the shift supervisor
																				// can take financal advance 70 percent
																				// of the monthly salary as a factory do
																				// in Palestine it's name is NAPCO and
																				// this percent different from factory
																				// to other and it's not from the
																				// total salary because the monthly
																				// bonus is not constant.
		}
		return FinancialAdvance;
	}

	// this method calculate the amount of the repayment that the supervisor will
	// pay every month for 1 year to repay the financial if he take it.

	public double getRepaymentOfFinancialSalary() {
		double Repayment = 0;
		Repayment = getFinancialSalaryAdvance() / 12; // i supposed that the shift supervisor will repay the financial
														// in
														// one year ( 12 months).

		return Repayment;
	}

	// Overrides toString() method to return shift supervisor employee information
	@Override
	public String toString() {
		// we need if statement for the MonthlySalary and MonthlyBonus and
		// NumOfProductsMade and NumOfTargetProduct because they have special condition
		// so any wrong enter from the user then the program must print error message
		// depend on the error and sometimes the salary will change depend on that and
		// in situations it will equal 0.0

		if ((MonthlySalary > 0) && (MonthlyBonus > 0) && (NumOfProductsMade > 0) && (NumOfTargetProducts > 0))
			return super.toString()
					+ "\n********** The Shift Supervisor **********\n\nThe Monthly Salary for the Supervisor is :"
					+ MonthlySalary + "\nThe Monthly bonus from the productions if happened for the Supervisor is :"
					+ MonthlyBonus + "\nThe Number of products that the shift supervisor and his team produced is :"
					+ NumOfProductsMade
					+ "\nThe Number of Products that the shift Supervisor and his team must make and produce is :"
					+ NumOfTargetProducts + "\nThe Total Salary for the Shift Supervisor is :" + getTotalSalary()
					+ "$\nThe amount of the Financial Salary that the Supervisor can take if he want is :"
					+ getFinancialSalaryAdvance()
					+ " $\nThe amount of the repayment that the supervisor will pay every month for 1 year to repay the financial if he take it is =  "
					+ getRepaymentOfFinancialSalary() + " $";

		if ((MonthlySalary > 0) && (MonthlyBonus > 0) && (NumOfProductsMade > 0) && (NumOfTargetProducts < 0))
			return super.toString()
					+ "\n********** The Shift Supervisor **********\n\nThe Monthly Salary for the Supervisor is :"
					+ MonthlySalary + "\n\nThe Monthly bonus from the productions if happened for the Supervisor is :"
					+ MonthlyBonus + "\n\nThe Number of products that the shift supervisor and his team produced is :"
					+ NumOfProductsMade
					+ "\n\nThe Number of Products that the shift Supervisor and his team must make and produce is :       Error .......... Because the entered Number of target products is negative and this can't happen"
					+ "\n\nThe Total Salary for the Shift Supervisor is :" + getTotalSalary()
					+ " $           <<<< Because there is a wrong input is entered please check the inputs again to calculate the Total Salary>>>>"
					+ "\n\nThe amount of the Financial Salary that the Supervisor can take if he want is :"
					+ getFinancialSalaryAdvance()
					+ " $\n\nThe amount of the repayment that the supervisor will pay every month for 1 year to repay the financial if he take it is =  "
					+ getRepaymentOfFinancialSalary() + " $";

		if ((MonthlySalary > 0) && (MonthlyBonus > 0) && (NumOfProductsMade < 0) && (NumOfTargetProducts > 0))
			return super.toString()
					+ "\n********** The Shift Supervisor **********\n\nThe Monthly Salary for the Supervisor is :"
					+ MonthlySalary + "\n\nThe Monthly bonus from the productions if happened for the Supervisor is :"
					+ MonthlyBonus
					+ "\n\nThe Number of products that the shift supervisor and his team produced is :         Error .......... Because the entered Number of products are made is negative and this can't happen"
					+ "\n\nThe Number of Products that the shift Supervisor and his team must make and produce is :"
					+ NumOfTargetProducts + "\n\nThe Total Salary for the Shift Supervisor is :" + getTotalSalary()
					+ " $           <<<< Because there is a wrong input is entered please check the inputs again to calculate the Total Salary>>>>"
					+ "\n\nThe amount of the Financial Salary that the Supervisor can take if he want is :"
					+ getFinancialSalaryAdvance()
					+ " $\n\nThe amount of the repayment that the supervisor will pay every month for 1 year to repay the financial if he take it is =  "
					+ getRepaymentOfFinancialSalary() + " $";

		if ((MonthlySalary > 0) && (MonthlyBonus > 0) && (NumOfProductsMade < 0) && (NumOfTargetProducts < 0))
			return super.toString()
					+ "\n********** The Shift Supervisor **********\n\nThe Monthly Salary for the Supervisor is :"
					+ MonthlySalary + "\nThe Monthly bonus from the productions if happened for the Supervisor is :"
					+ MonthlyBonus
					+ "\n\nThe Number of products that the shift supervisor and his team produced is :      Error .......... Because the entered Number of products are made is negative and this can't happen"
					+ "\n\nThe Number of Products that the shift Supervisor and his team must make and produce is :         Error .......... Because the entered Number of target products is negative and this can't happen"
					+ "\n\nThe Total Salary for the Shift Supervisor is :" + getTotalSalary()
					+ " $           <<<< Because there is a wrong input is entered please check the inputs again to calculate the Total Salary>>>>"
					+ "\n\nThe amount of the Financial Salary that the Supervisor can take if he want is :"
					+ getFinancialSalaryAdvance()
					+ " $\n\nThe amount of the repayment that the supervisor will pay every month for 1 year to repay the financial if he take it is =  "
					+ getRepaymentOfFinancialSalary() + " $";

		if ((MonthlySalary > 0) && (MonthlyBonus < 0) && (NumOfProductsMade > 0) && (NumOfTargetProducts > 0))
			return super.toString()
					+ "\n********** The Shift Supervisor **********\n\nThe Monthly Salary for the Supervisor is :"
					+ MonthlySalary
					+ "\n\nThe Monthly bonus from the productions if happened for the Supervisor is :         Error .......... Because the entered Monthly Bonus is negative and this can't happen"
					+ "\nThe Number of products that the shift supervisor and his team produced is :"
					+ NumOfProductsMade
					+ "\nThe Number of Products that the shift Supervisor and his team must make and produce is :"
					+ NumOfTargetProducts + "\nThe Total Salary for the Shift Supervisor is :" + getTotalSalary()
					+ " $           <<<< Because there is a wrong input is entered please check the inputs again to calculate the Total Salary>>>>"
					+ "\nThe amount of the Financial Salary that the Supervisor can take if he want is :"
					+ getFinancialSalaryAdvance()
					+ " $\nThe amount of the repayment that the supervisor will pay every month for 1 year to repay the financial if he take it is =  "
					+ getRepaymentOfFinancialSalary() + " $";

		if ((MonthlySalary > 0) && (MonthlyBonus < 0) && (NumOfProductsMade > 0) && (NumOfTargetProducts < 0))
			return super.toString()
					+ "\n********** The Shift Supervisor **********\n\nThe Monthly Salary for the Supervisor is :"
					+ MonthlySalary
					+ "\n\nThe Monthly bonus from the productions if happened for the Supervisor is :       Error .......... Because the entered Monthly Bonus is negative and this can't happen"
					+ "\nThe Number of products that the shift supervisor and his team produced is :"
					+ NumOfProductsMade
					+ "\n\nThe Number of Products that the shift Supervisor and his team must make and produce is :         Error .......... Because the entered Number of target products is negative and this can't happen"
					+ "\nThe Total Salary for the Shift Supervisor is :" + getTotalSalary()
					+ " $           <<<< Because there is a wrong input is entered please check the inputs again to calculate the Total Salary>>>>"
					+ "\nThe amount of the Financial Salary that the Supervisor can take if he want is :"
					+ getFinancialSalaryAdvance()
					+ " $\nThe amount of the repayment that the supervisor will pay every month for 1 year to repay the financial if he take it is =  "
					+ getRepaymentOfFinancialSalary() + " $";

		if ((MonthlySalary > 0) && (MonthlyBonus < 0) && (NumOfProductsMade < 0) && (NumOfTargetProducts > 0))
			return super.toString()
					+ "\n********** The Shift Supervisor **********\n\nThe Monthly Salary for the Supervisor is :"
					+ MonthlySalary
					+ "\n\nThe Monthly bonus from the productions if happened for the Supervisor is :          Error .......... Because the entered Monthly Bonus is negative and this can't happen"
					+ "\n\nThe Number of products that the shift supervisor and his team produced is :         Error .......... Because the entered Number of products are made is negative and this can't happen"
					+ "\n\nThe Number of Products that the shift Supervisor and his team must make and produce is :"
					+ NumOfTargetProducts + "\n\nThe Total Salary for the Shift Supervisor is :" + getTotalSalary()
					+ " $           <<<< Because there is a wrong input is entered please check the inputs again to calculate the Total Salary>>>>"
					+ "\n\nThe amount of the Financial Salary that the Supervisor can take if he want is :"
					+ getFinancialSalaryAdvance()
					+ " $\n\nThe amount of the repayment that the supervisor will pay every month for 1 year to repay the financial if he take it is =  "
					+ getRepaymentOfFinancialSalary() + " $";

		if ((MonthlySalary > 0) && (MonthlyBonus < 0) && (NumOfProductsMade < 0) && (NumOfTargetProducts < 0))
			return super.toString()
					+ "\n********** The Shift Supervisor **********\n\nThe Monthly Salary for the Supervisor is :"
					+ MonthlySalary
					+ "\n\nThe Monthly bonus from the productions if happened for the Supervisor is :          Error .......... Because the entered Monthly Bonus is negative and this can't happen"
					+ "\n\nThe Number of products that the shift supervisor and his team produced is :           Error .......... Because the entered Number of products are made is negative and this can't happen"
					+ "\n\nThe Number of Products that the shift Supervisor and his team must make and produce is :         Error .......... Because the entered Number of target products is negative and this can't happen"
					+ "\n\nThe Total Salary for the Shift Supervisor is :" + getTotalSalary()
					+ " $           <<<< Because there is a wrong input is entered please check the inputs again to calculate the Total Salary>>>>"
					+ "\n\nThe amount of the Financial Salary that the Supervisor can take if he want is :"
					+ getFinancialSalaryAdvance()
					+ " $\n\nThe amount of the repayment that the supervisor will pay every month for 1 year to repay the financial if he take it is =  "
					+ getRepaymentOfFinancialSalary() + " $";

		// when monthly salary less than 0 of course will print Error message also in
		// this case the financialsalary and it's repayment must change and also print
		// error to tell user to check the monthly bonus again .

		if ((MonthlySalary < 0) && (MonthlyBonus > 0) && (NumOfProductsMade > 0) && (NumOfTargetProducts > 0))
			return super.toString()
					+ "\n********** The Shift Supervisor **********\n\nThe Monthly Salary for the Supervisor is : Error ......... The entered Monthly Salary is wrong because it's negative and this can't happen"
					+ "\n\nThe Monthly bonus from the productions if happened for the Supervisor is :" + MonthlyBonus
					+ "\n\nThe Number of products that the shift supervisor and his team produced is :"
					+ NumOfProductsMade
					+ "\n\nThe Number of Products that the shift Supervisor and his team must make and produce is :"
					+ NumOfTargetProducts + "\n\nThe Total Salary for the Shift Supervisor is :" + getTotalSalary()
					+ " $           <<<< Because there is a wrong input is entered please check the inputs again to calculate the Total Salary>>>>"
					+ "\n\nThe amount of the Financial Salary that the Supervisor can take if he want is :"
					+ getFinancialSalaryAdvance()
					+ " $          <<<< Becase the entered monthly salary is wrong please check it again\n\nThe amount of the repayment that the supervisor will pay every month for 1 year to repay the financial if he take it is =  "
					+ getRepaymentOfFinancialSalary()
					+ " $        <<<< Becase the entered monthly salary is wrong please check it again";

		// when monthly salary less than 0 of course will print Error message also in
		// this case the financialsalary and it's repayment must change and also print
		// error to tell user to check the monthly bonus again .

		if ((MonthlySalary < 0) && (MonthlyBonus > 0) && (NumOfProductsMade > 0) && (NumOfTargetProducts < 0))
			return super.toString()
					+ "\n********** The Shift Supervisor **********\n\nThe Monthly Salary for the Supervisor is :          Error ......... The entered Monthly Salary is wrong because it's negative and this can't happen"
					+ "\n\nThe Monthly bonus from the productions if happened for the Supervisor is :" + MonthlyBonus
					+ "\n\nThe Number of products that the shift supervisor and his team produced is :"
					+ NumOfProductsMade
					+ "\n\nThe Number of Products that the shift Supervisor and his team must make and produce is :         Error .......... Because the entered Number of target products is negative and this can't happen"
					+ "\n\nThe Total Salary for the Shift Supervisor is :" + getTotalSalary()
					+ " $           <<<< Because there is a wrong input is entered please check the inputs again to calculate the Total Salary>>>>"
					+ "\n\nThe amount of the Financial Salary that the Supervisor can take if he want is :"
					+ getFinancialSalaryAdvance()
					+ " $          <<<< Becase the entered monthly salary is wrong please check it again\n\nThe amount of the repayment that the supervisor will pay every month for 1 year to repay the financial if he take it is =  "
					+ getRepaymentOfFinancialSalary()
					+ " $         <<<< Becase the entered monthly salary is wrong please check it again";

		// when monthly salary less than 0 of course will print Error message also in
		// this case the financialsalary and it's repayment must change and also print
		// error to tell user to check the monthly bonus again .

		if ((MonthlySalary < 0) && (MonthlyBonus > 0) && (NumOfProductsMade < 0) && (NumOfTargetProducts > 0))
			return super.toString()
					+ "\n********** The Shift Supervisor **********\n\nThe Monthly Salary for the Supervisor is :         Error ......... The entered Monthly Salary is wrong because it's negative and this can't happen"
					+ "\n\nThe Monthly bonus from the productions if happened for the Supervisor is :" + MonthlyBonus
					+ "\n\nThe Number of products that the shift supervisor and his team produced is :          Error .......... Because the entered Number of products are made is negative and this can't happen"
					+ "\n\nThe Number of Products that the shift Supervisor and his team must make and produce is :"
					+ NumOfTargetProducts + "\n\nThe Total Salary for the Shift Supervisor is :" + getTotalSalary()
					+ " $           <<<< Because there is a wrong input is entered please check the inputs again to calculate the Total Salary>>>>"
					+ "\n\nThe amount of the Financial Salary that the Supervisor can take if he want is :"
					+ getFinancialSalaryAdvance()
					+ " $      <<<< Becase the entered monthly salary is wrong please check it again\n\nThe amount of the repayment that the supervisor will pay every month for 1 year to repay the financial if he take it is =  "
					+ getRepaymentOfFinancialSalary()
					+ " $          <<<< Becase the entered monthly salary is wrong please check it again";

		// when monthly salary less than 0 of course will print Error message also in
		// this case the financialsalary and it's repayment must change and also print
		// error to tell user to check the monthly bonus again .

		if ((MonthlySalary < 0) && (MonthlyBonus > 0) && (NumOfProductsMade < 0) && (NumOfTargetProducts < 0))
			return super.toString()
					+ "\n********** The Shift Supervisor **********\n\nThe Monthly Salary for the Supervisor is :            Error ......... The entered Monthly Salary is wrong because it's negative and this can't happen\nThe Monthly bonus from the productions if happened for the Supervisor is :"
					+ MonthlyBonus
					+ "\n\nThe Number of products that the shift supervisor and his team produced is :          Error .......... Because the entered Number of products are made is negative and this can't happen"
					+ "\n\nThe Number of Products that the shift Supervisor and his team must make and produce is :           Error .......... Because the entered Number of products are made is negative and this can't happen"
					+ "\n\nThe Total Salary for the Shift Supervisor is :" + getTotalSalary()
					+ " $           <<<< Because there is a wrong input is entered please check the inputs again to calculate the Total Salary>>>>"
					+ "\n\nThe amount of the Financial Salary that the Supervisor can take if he want is :"
					+ getFinancialSalaryAdvance()
					+ " $        <<<< Becase the entered monthly salary is wrong please check it again\n\nThe amount of the repayment that the supervisor will pay every month for 1 year to repay the financial if he take it is =  "
					+ getRepaymentOfFinancialSalary()
					+ " $       <<<< Becase the entered monthly salary is wrong please check it again";

		// when monthly salary less than 0 of course will print Error message also in
		// this case the financialsalary and it's repayment must change and also print
		// error to tell user to check the monthly bonus again .

		if ((MonthlySalary < 0) && (MonthlyBonus < 0) && (NumOfProductsMade > 0) && (NumOfTargetProducts > 0))
			return super.toString()
					+ "\n********** The Shift Supervisor **********\n\nThe Monthly Salary for the Supervisor is :           Error ......... The entered Monthly Salary is wrong because it's negative and this can't happen"
					+ "\n\nThe Monthly bonus from the productions if happened for the Supervisor is :         Error .......... Because the entered Monthly Bonus is negative and this can't happen"
					+ "\n\nThe Number of products that the shift supervisor and his team produced is :"
					+ NumOfProductsMade
					+ "\n\nThe Number of Products that the shift Supervisor and his team must make and produce is :"
					+ NumOfTargetProducts + "\n\nThe Total Salary for the Shift Supervisor is :" + getTotalSalary()
					+ " $           <<<< Because there is a wrong input is entered please check the inputs again to calculate the Total Salary>>>>"
					+ "\n\nThe amount of the Financial Salary that the Supervisor can take if he want is :"
					+ getFinancialSalaryAdvance()
					+ " $        <<<< Becase the entered monthly salary is wrong please check it again\n\nThe amount of the repayment that the supervisor will pay every month for 1 year to repay the financial if he take it is =  "
					+ getRepaymentOfFinancialSalary()
					+ " $       <<<< Becase the entered monthly salary is wrong please check it again";

		// when monthly salary less than 0 of course will print Error message also in
		// this case the financialsalary and it's repayment must change and also print
		// error to tell user to check the monthly bonus again .

		if ((MonthlySalary < 0) && (MonthlyBonus < 0) && (NumOfProductsMade > 0) && (NumOfTargetProducts < 0))
			return super.toString()
					+ "\n********** The Shift Supervisor **********\n\nThe Monthly Salary for the Supervisor is :           Error ......... The entered Monthly Salary is wrong because it's negative and this can't happen"
					+ "\n\nThe Monthly bonus from the productions if happened for the Supervisor is :              Error .......... Because the entered Monthly Bonus is negative and this can't happen"
					+ "\nThe Number of products that the shift supervisor and his team produced is :"
					+ NumOfProductsMade
					+ "\n\nThe Number of Products that the shift Supervisor and his team must make and produce is :          Error .......... Because the entered Number of target products is negative and this can't happen"
					+ "\n\nThe Total Salary for the Shift Supervisor is :" + getTotalSalary()
					+ " $           <<<< Because there is a wrong input is entered please check the inputs again to calculate the Total Salary>>>>"
					+ "\n\nThe amount of the Financial Salary that the Supervisor can take if he want is :"
					+ getFinancialSalaryAdvance()
					+ " $      <<<< Becase the entered monthly salary is wrong please check it again\n\nThe amount of the repayment that the supervisor will pay every month for 1 year to repay the financial if he take it is =  "
					+ getRepaymentOfFinancialSalary()
					+ " $      <<<< Becase the entered monthly salary is wrong please check it again";

		// when monthly salary less than 0 of course will print Error message also in
		// this case the financialsalary and it's repayment must change and also print
		// error to tell user to check the monthly bonus again .

		if ((MonthlySalary < 0) && (MonthlyBonus < 0) && (NumOfProductsMade < 0) && (NumOfTargetProducts > 0))
			return super.toString()
					+ "\n********** The Shift Supervisor **********\n\nThe Monthly Salary for the Supervisor is :           Error ......... The entered Monthly Salary is wrong because it's negative and this can't happen"
					+ "\n\nThe Monthly bonus from the productions if happened for the Supervisor is :          Error .......... Because the entered Monthly Bonus is negative and this can't happen"
					+ "\n\nThe Number of products that the shift supervisor and his team produced is :          Error .......... Because the entered Number of products are made is negative and this can't happen"
					+ "\n\nThe Number of Products that the shift Supervisor and his team must make and produce is :"
					+ NumOfTargetProducts + "\n\nThe Total Salary for the Shift Supervisor is :" + getTotalSalary()
					+ " $           <<<< Because there is a wrong input is entered please check the inputs again to calculate the Total Salary>>>>"
					+ "\n\nThe amount of the Financial Salary that the Supervisor can take if he want is :"
					+ getFinancialSalaryAdvance()
					+ " $        <<<< Becase the entered monthly salary is wrong please check it again\n\nThe amount of the repayment that the supervisor will pay every month for 1 year to repay the financial if he take it is =  "
					+ getRepaymentOfFinancialSalary()
					+ " $     <<<< Becase the entered monthly salary is wrong please check it again";

		return super.toString()
				+ "\n********** The Shift Supervisor **********\n\nThe Monthly Salary for the Supervisor is : Error ......... The entered Monthly Salary is wrong because it's negative and this can't happen"
				+ "\n\nThe Monthly bonus from the productions if happened for the Supervisor is :Error .......... Because the entered Monthly Bonus is negative and this can't happen"
				+ "\n\nThe Number of products that the shift supervisor and his team produced is :Error .......... Because the entered Number of products are made is negative and this can't happen"
				+ "\n\nThe Number of Products that the shift Supervisor and his team must make and produce is :Error .......... Because the entered Number of target products is negative and this can't happen"
				+ "\n\nThe Total Salary for the Shift Supervisor is :" + getTotalSalary()
				+ " $           <<<< Because there is a wrong input is entered please check the inputs again to calculate the Total Salary>>>>"
				+ "\n\nThe amount of the Financial Salary that the Supervisor can take if he want is :"
				+ getFinancialSalaryAdvance()
				+ " $     <<<< Becase the entered monthly salary is wrong please check it again"
				+ "\n\nThe amount of the repayment that the supervisor will pay every month for 1 year to repay the financial if he take it is =  "
				+ getRepaymentOfFinancialSalary()
				+ " $      <<<< Becase the entered monthly salary is wrong please check it again";

	}

}
