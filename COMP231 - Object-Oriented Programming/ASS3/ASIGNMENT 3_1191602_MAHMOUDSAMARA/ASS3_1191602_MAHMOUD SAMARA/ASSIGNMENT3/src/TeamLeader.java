
// ASSIGNMENT 3        1191602        MAHMOUD SAMARA     COMP231      DR.HAFEZ BARGHOUTHI          SEC2

import java.util.Date;

// Definning the sub class that is TeamLeader that extends from  the super class ProductionWorker
public class TeamLeader extends ProductionWorker {
	private double MonthlyBonus; // monthly production bonus we will use it to know and print the monthly bonus
									// that the worker has earned.
	private double RequiredTrainingHours; // RequiredTrainingHours we will use it to know Number of
											// RequiredTrainingHours the worker must do per month.
	private double TrainingHoursAttended; // TrainingHoursAttended we will use it to know Number of hours that the
											// worker has done.

	// No-argument constructor it includes the default values about for the
	// variables.
	public TeamLeader() {
		super();
		// default values for the different variables
		MonthlyBonus = 0.0;
		RequiredTrainingHours = 0.0;
		TrainingHoursAttended = 0.0;
	}

	// Constructing a TeamLeader object that has the same name as the class
	// itself and it has several methods in different types and it is constructor
	// with arguments it includes different attributes also it extends some
	// informations from ProductionWorker class.
	public TeamLeader(String EmpName, String EmpNumber, Date EmpHire_Date, Address EmpAddress, int Shift,
			double PayRate, double NumHoursInMonth, double monthlyBonus, double RequiredTrainingHours,
			double TrainingHoursAttended) {

		// Calling the super class.
		super(EmpName, EmpNumber, EmpHire_Date, EmpAddress, Shift, PayRate, NumHoursInMonth);
		this.MonthlyBonus = monthlyBonus;
		this.RequiredTrainingHours = RequiredTrainingHours;
		this.TrainingHoursAttended = TrainingHoursAttended;
	}

	public double getMonthlyBonus() { // declare a method it's called MonthlyBonus and it's kind is double and it
										// returns MonthlyBonus.
		return MonthlyBonus;
	}

	public void setMonthlyBonus(double monthlyBonus) { // declare a method it's called MonthlyBonus and it sets a new
														// MonthlyBonus for the new given or the new chosen Employee.
		MonthlyBonus = monthlyBonus;
	}

	public double getRequiredTrainingHours() { // declare a method it's called RequiredTrainingHour and it's kind is
												// double and it returns RequiredTrainingHour.
		return RequiredTrainingHours;
	}

	public void setRequiredTrainingHours(double requiredTrainingHours) { // declare a method it's called
																			// RequiredTrainingHours and it sets a new
																			// RequiredTrainingHours for the new given
																			// or the new chosen Employee.
		RequiredTrainingHours = requiredTrainingHours;
	}

	public double getTrainingHoursAttended() { // declare a method it's called TrainingHoursAttended and it's kind is
												// double and it returns TrainingHoursAttended.
		return TrainingHoursAttended;
	}

	public void setTrainingHoursAttended(double trainingHoursAttended) { // declare a method it's called
																			// TrainingHoursAttended and it sets a new
																			// TrainingHoursAttended for the new given
																			// or the new chosen Employee.
		TrainingHoursAttended = trainingHoursAttended;
	}

	// getTotalSalary() method should calculate the total salary for team leader and
	// it's equal Hours and payed rate + bonus when bonus equal 0 for wrong input it
	// will return just Hours and payed rate or 0 depend on the cases because
	// sometimes also total salary it equal 0 because wrong input.

	@Override
	public double getTotalSalary() {
		double ExtraBonus = 0;

		// if statement to check at first all inputs enetered right if yes it will
		// calculate the salary if no it will return 0 because there is a wrong input

		if ((MonthlyBonus > 0) && (RequiredTrainingHours > 0) && (TrainingHoursAttended > 0)
				&& (super.getTotalSalary() > 0)) {

			double BonusIfAchieved = MonthlyBonus * (double) TrainingHoursAttended / RequiredTrainingHours;
			ExtraBonus = super.getTotalSalary() + BonusIfAchieved;
		}
		return ExtraBonus;
	}

	// This method calculate the amount of money that the Team Leader pay for Saving
	// fund and of course at the end of his work he can get them back for him and it

	public double getMoneyForSavingsFund() {
		double SavingsFund = 0;

		if ((MonthlyBonus > 0) && (RequiredTrainingHours > 0) && (TrainingHoursAttended > 0)
				&& (super.getTotalSalary() > 0)) {

			SavingsFund = getTotalSalary() * 5 / 100;
		}
		return SavingsFund;
	}

	// In this extra method we will know how many the Employee will get the final
	// salary after taking the money for Saving fund .
	public double getFinalMoney() {

		double FinalSalary = 0.0;

		if (getTotalSalary() > 0) {

			FinalSalary = getTotalSalary() - getMoneyForSavingsFund();
		}
		return FinalSalary;
	}

	// Overrides toString() method to it's SuperClass
	@Override
	public String toString() {

		// we need several if statements for the MonthlyBonus and RequiredTrainingHours
		// and TrainingHoursAttended because they have special condition and different
		// situaions so any wrong enter from the user then the program must print error
		// message depend on the error and sometimes the salary will change depend on
		// that and in situations it will equal 0.0

		if ((MonthlyBonus > 0) && (RequiredTrainingHours > 0) && (TrainingHoursAttended > 0))
			return super.toString() + "\n\n********** The Team Leader **********\n\nThe TeamLeader monthly bonus is ="
					+ MonthlyBonus + "\nThe Requaired training hours is =" + RequiredTrainingHours
					+ "\nThe Number of hours that Attended is =" + TrainingHoursAttended
					+ "\nThe Total Salary for the Team Leader to take is :" + getTotalSalary()
					+ " $\nThe Price that the Employee have to pay for the Saving Fund is :" + getMoneyForSavingsFund()
					+ " $\nThe Final Salary for the Team Leader to get after taking the money for the Saving Fund is :"
					+ getFinalMoney() + " $";

		if ((MonthlyBonus > 0) && (RequiredTrainingHours > 0) && (TrainingHoursAttended < 0))
			return super.toString() + "\n\n********** The Team Leader **********\n\nThe TeamLeader monthly bonus is ="
					+ MonthlyBonus + "\nThe Requaired training hours is : " + RequiredTrainingHours
					+ "\n The Number of hours that Attended is = Error ...... The entered number of hours attended is wrong because the number can't be negative , please check your input."
					+ "\nThe Total Salary for the Team Leader to take is :" + getTotalSalary()
					+ " $      <<<< Error ....... The total salary doesn't calculated right because there is a wrong input entered in the informations of the Team Leader , please check them>>>>.\nThe Price that the Employee have to pay for the Saving Fund is :"
					+ getMoneyForSavingsFund()
					+ " $         <<<<Error ....... Because the total salary from Team Leader Informations or From Worker Informations is calculated wrong please check the Total Salary Calculation to Print Right Numbers.\nThe Final Salary for the Team Leader to get after taking the money for the Saving Fund is :"
					+ getFinalMoney()
					+ " $         <<<<Error ....... Because the total salary from Team Leader Informations or From Worker Informations is calculated wrong please check the Total Salary Calculation to Print Right Numbers.";

		if ((MonthlyBonus > 0) && (RequiredTrainingHours < 0) && (TrainingHoursAttended > 0))
			return super.toString() + "\n\n********** The Team Leader **********\n\nThe TeamLeader monthly bonus is ="
					+ MonthlyBonus
					+ "\nThe Requaired training hours is : Error ...... The entered number of Requaired hours training is wrong because the number can't be negative , please check your input."
					+ "\n The Number of hours that Attended is =" + TrainingHoursAttended
					+ "\nThe Total Salary for the Team Leader to take is :" + getTotalSalary()
					+ " $      <<<< Error ....... The total salary doesn't calculated right because there is a wrong input entered in the informations of the Team Leader , please check them>>>>.\nThe Price that the Employee have to pay for the Saving Fund is :"
					+ getMoneyForSavingsFund()
					+ " $         <<<<Error ....... Because the total salary from Team Leader Informations or From Worker Informations is calculated wrong please check the Total Salary Calculation to Print Right Numbers.\nThe Final Salary for the Team Leader to get after taking the money for the Saving Fund is :"
					+ getFinalMoney()
					+ " $         <<<<Error ....... Because the total salary from Team Leader Informations or From Worker Informations is calculated wrong please check the Total Salary Calculation to Print Right Numbers.";

		if ((MonthlyBonus > 0) && (RequiredTrainingHours < 0) && (TrainingHoursAttended < 0))
			return super.toString() + "\n\n********** The Team Leader **********\n\nThe TeamLeader monthly bonus is ="
					+ MonthlyBonus
					+ "\nThe Requaired training hours is : Error ...... The entered number of Requaired hours training is wrong because the number can't be negative , please check your input."
					+ "\n The Number of hours that Attended is = Error ...... The entered number of hours attended is wrong because the number can't be negative , please check your input"
					+ "\nThe Total Salary for the Team Leader to take is :" + getTotalSalary()
					+ " $      <<<< Error ....... The total salary doesn't calculated right because there is a wrong input entered in the informations of the Team Leader , please check them>>>>.\nThe Price that the Employee have to pay for the Saving Fund is :"
					+ getMoneyForSavingsFund()
					+ " $         <<<<Error ....... Because the total salary from Team Leader Informations or From Worker Informations is calculated wrong please check the Total Salary Calculation to Print Right Numbers.\nThe Final Salary for the Team Leader to get after taking the money for the Saving Fund is :"
					+ getFinalMoney()
					+ " $         <<<<Error ....... Because the total salary from Team Leader Informations or From Worker Informations is calculated wrong please check the Total Salary Calculation to Print Right Numbers.";

		if ((MonthlyBonus < 0) && (RequiredTrainingHours > 0) && (TrainingHoursAttended > 0))
			return super.toString()
					+ "\n\n********** The Team Leader **********\n\nThe TeamLeader monthly bonus is = Error ........ The number that you entered for monthly bonus is wrong the number can't be negative , please check your input"
					+ "\nThe Requaired training hours is : " + RequiredTrainingHours
					+ "\n The Number of hours that Attended is =" + TrainingHoursAttended
					+ "\nThe Total Salary for the Team Leader to take is :" + getTotalSalary()
					+ " $      <<<< Error ....... The total salary doesn't calculated right because there is a wrong input entered in the informations of the Team Leader , please check them>>>>.\nThe Price that the Employee have to pay for the Saving Fund is :"
					+ getMoneyForSavingsFund()
					+ " $         <<<<Error ....... Because the total salary from Team Leader Informations or From Worker Informations is calculated wrong please check the Total Salary Calculation to Print Right Numbers.\nThe Final Salary for the Team Leader to get after taking the money for the Saving Fund is :"
					+ getFinalMoney()
					+ " $         <<<<Error ....... Because the total salary from Team Leader Informations or From Worker Informations is calculated wrong please check the Total Salary Calculation to Print Right Numbers.";

		if ((MonthlyBonus < 0) && (RequiredTrainingHours > 0) && (TrainingHoursAttended < 0))
			return super.toString()
					+ "\n\n********** The Team Leader **********\n\nThe TeamLeader monthly bonus is = Error ........ The number that you entered for monthly bonus is wrong the number can't be negative , please check your input"
					+ "\nThe Requaired training hours is : " + RequiredTrainingHours
					+ "\n The Number of hours that Attended is = Error ...... The entered number of hours attended is wrong because the number can't be negative , please check your input"
					+ "\nThe Total Salary for the Team Leader to take is :" + getTotalSalary()
					+ " $      <<<< Error ....... The total salary doesn't calculated right because there is a wrong input entered in the informations of the Team Leader , please check them>>>>.\nThe Price that the Employee have to pay for the Saving Fund is :"
					+ getMoneyForSavingsFund()
					+ " $         <<<<Error ....... Because the total salary from Team Leader Informations or From Worker Informations is calculated wrong please check the Total Salary Calculation to Print Right Numbers.\nThe Final Salary for the Team Leader to get after taking the money for the Saving Fund is :"
					+ getFinalMoney()
					+ " $         <<<<Error ....... Because the total salary from Team Leader Informations or From Worker Informations is calculated wrong please check the Total Salary Calculation to Print Right Numbers.";

		if ((MonthlyBonus < 0) && (RequiredTrainingHours < 0) && (TrainingHoursAttended > 0))
			return super.toString()
					+ "\n\n********** The Team Leader **********\n\nThe TeamLeader monthly bonus is = Error ........ The number that you entered for monthly bonus is wrong the number can't be negative , please check your input"
					+ "\nThe Requaired training hours is = Error ...... The entered number of Requaired hours training is wrong because the number can't be negative , please check your input."
					+ "\nThe Number of hours that Attended is = " + TrainingHoursAttended
					+ "\nThe Total Salary for the Team Leader to take is :" + getTotalSalary()
					+ " $      <<<< Error ....... The total salary doesn't calculated right because there is a wrong input entered in the informations of the Team Leader , please check them>>>>.\nThe Price that the Employee have to pay for the Saving Fund is :"
					+ getMoneyForSavingsFund()
					+ " $         <<<<Error ....... Because the total salary from Team Leader Informations or From Worker Informations is calculated wrong please check the Total Salary Calculation to Print Right Numbers.\nThe Final Salary for the Team Leader to get after taking the money for the Saving Fund is :"
					+ getFinalMoney()
					+ " $         <<<<Error ....... Because the total salary from Team Leader Informations or From Worker Informations is calculated wrong please check the Total Salary Calculation to Print Right Numbers.";

		return super.toString()
				+ "\n\n********** The Team Leader **********\n\nThe TeamLeader monthly bonus is = Error ........ The number that you entered for monthly bonus is wrong the number can't be negative , please check your input"
				+ "\nThe Requaired training hours is : Error ...... The entered number of Requaired hours training is wrong because the number can't be negative , please check your input."
				+ "\n The Number of hours that Attended is =Error ...... The entered number of hours attended is wrong because the number can't be negative , please check your input"
				+ "\nThe Total Salary for the Team Leader to take is :" + getTotalSalary()
				+ " $      Error ....... The total salary doesn't calculated right because there is a wrong input entered in the informations of the Team Leader , please check them>>>>.\nThe Price that the Employee have to pay for the Saving Fund is :"
				+ getMoneyForSavingsFund()
				+ " $         <<<<Error ....... Because the total salary from Team Leader Informations or From Worker Informations is calculated wrong please check the Total Salary Calculation to Print Right Numbers.\nThe Final Salary for the Team Leader to get after taking the money for the Saving Fund is :"
				+ getFinalMoney()
				+ " $         <<<<Error ....... Because the total salary from Team Leader Informations or From Worker Informations is calculated wrong please check the Total Salary Calculation to Print Right Numbers.";
	}

}
